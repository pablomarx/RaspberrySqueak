#include "sq.h"
#include "sqRpiDisplay.h"

#include "framebuffer.h"
#include "types.h"
#include "barrier.h"

#define BytesPerComponent (ScreenDepth / 8)

int ioScreenSize(void) {
	return (fb_x << 16) | (fb_y & 0xFFFF);  /* w is high 16 bits; h is low 16 bits */
}

/*** Display stubs ***/
unsigned char underCursorData[16 * 16 * BytesPerComponent];
int lastCursorX, lastCursorY;

struct SqCursor  {
	unsigned char size, depth, y, x;
	unsigned short data[16], mask[16];
};

struct SqCursor SqueakCursor;

void hideCursor(void) {
	int bytesPerComponent = BytesPerComponent; //depth/8;
	int bytesPerRow = bytesPerComponent * fb_x;
	int rowLength = SqueakCursor.size * bytesPerComponent;

	for (int y=0; y<SqueakCursor.size; y++) {
		int row = (lastCursorY + y) * bytesPerRow;
		int col = lastCursorX * bytesPerComponent;
		unsigned char *oldScreen = &underCursorData[y * rowLength];
		memcpy((unsigned char *)screenbase + row + col, oldScreen, rowLength);
	}
}

void showCursor(void) {
	int bytesPerComponent = BytesPerComponent; //depth/8;
	int bytesPerRow = bytesPerComponent * fb_x;
	int rowLength = SqueakCursor.size * bytesPerComponent;
	
	for (int y=0; y<SqueakCursor.size; y++) {
		int row = (lastCursorY + y) * bytesPerRow;
		int col = lastCursorX * bytesPerComponent;

		unsigned char *rowData = (unsigned char *)screenbase + row + col;
		unsigned char *oldScreen = &underCursorData[y * rowLength];
		memcpy(oldScreen, rowData, rowLength);
		for (int x=SqueakCursor.size; x>0; x--) {
			int cursor = SqueakCursor.data[y] & 1<<x;
			if (cursor) {
				if (bytesPerComponent > 3) {
					*rowData++ = 0xff;
				}
				if (bytesPerComponent > 2) {
					*rowData++ = 0x00;
				}
				*rowData++ = 0x00;
				*rowData++ = 0x00;
			}
			else {
				rowData+=bytesPerComponent;
			}
		}
	}
}

void moveCursor(int x, int y) {
	if (x == lastCursorX && y == lastCursorY) {
		return;
	}
	hideCursor();
	lastCursorX = x;
	lastCursorY = y;
	showCursor();
}

int ioSetCursor(int cursorBitsIndex, int offsetX, int offsetY) {
	return ioSetCursorWithMask(cursorBitsIndex, 0, offsetX, offsetY);	
}

int ioSetCursorWithMask(int cursorBitsIndex, int cursorMaskIndex, int offsetX, int offsetY) 
{
	//printf("%s cursorBitsIndex=%i, cursorMaskIndex=%i, offsetX=%i, offsetY=%i\n", __PRETTY_FUNCTION__, cursorBitsIndex, cursorMaskIndex, offsetX, offsetY);

	hideCursor();

	/* Set the 16x16 cursor bitmap. If cursorMaskIndex is nil, then make the mask the same as
	   the cursor bitmap. If not, then mask and cursor bits combined determine how cursor is
	   displayed:
			mask	cursor	effect
			 0		  0		transparent (underlying pixel shows through)
			 1		  1		opaque black
			 1		  0		opaque white
			 0		  1		invert the underlying pixel
	*/
	SqueakCursor.size = 16;
	SqueakCursor.depth = 1;
	SqueakCursor.x = -offsetX;
	SqueakCursor.y = -offsetY; 
	
	for (int i = 0; i < SqueakCursor.size; i++) {
        SqueakCursor.data[i] = (checkedLongAt(cursorBitsIndex + (4 * i)) >> 16) & 0xFFFF;

		if (cursorMaskIndex == 0) {
			SqueakCursor.mask[i] = SqueakCursor.data[i];
		}
		else {
	        SqueakCursor.mask[i] = (checkedLongAt(cursorMaskIndex + (4 * i)) >> 16) & 0xFFFF;
		}
	}

	showCursor();
	return true;
}
	
int ioSetDisplayMode(int width, int height, int depth, int fullscreenFlag) {
	printf("%s width=%i, height=%i, depth=%i, fullscreenFlag=%i\n", __PRETTY_FUNCTION__, width, height, depth, fullscreenFlag);
	return 0;
}

int ioSetFullScreen(int fullScreen) {
	printf("%s fullScreen=%i\n", __PRETTY_FUNCTION__, fullScreen);
	return 0;
}

int ioScreenDepth(void) {
	return ScreenDepth;
}

int ioHasDisplayDepth(int depth) {
	if (depth == ScreenDepth) {
		return true;
	}
	return false;
}

int ioShowDisplay(
	int dispBitsIndex, int width, int height, int depth,
	int affectedL, int affectedR, int affectedT, int affectedB) 
{
  if(affectedR <= affectedL || affectedT >= affectedB) {
    return 1;
	}

	bool clippedCursor = false;
	if ((lastCursorX >= affectedL || lastCursorX + SqueakCursor.size >= affectedL) && (lastCursorX <= affectedR || lastCursorX + SqueakCursor.size <= affectedR) &&
		(lastCursorY >= affectedT || lastCursorY + SqueakCursor.size >= affectedT) && (lastCursorY <= affectedB || lastCursorY + SqueakCursor.size <= affectedB))
	{
		clippedCursor = true;
	}
	
	if (clippedCursor == true) {
		hideCursor();
	}
	
	int bytesPerComponent = depth/8;
	int rowLength = (affectedR - affectedL) * bytesPerComponent;

	int x,y;
	int sourceRow, sourceCol;
	int destRow, destCol;

	for (y = affectedT; y < affectedB; y++) {
		destRow = y * bytesPerComponent * fb_x;
		destCol = affectedL * bytesPerComponent;
		
		sourceRow = y * bytesPerComponent * width;
		sourceCol = affectedL * bytesPerComponent;
#if 1
		if (bytesPerComponent == 4) {
			uint32_t *toData = (uint32_t*)(screenbase + destRow + destCol);
			uint32_t *fromData = (uint32_t *)(dispBitsIndex + sourceRow + sourceCol);
			for (x = affectedL; x<affectedR; x++) {
				*toData = 
					0xff << 24 |  // alpha
					(((*fromData      ) & 0xff) << 16) |  // blue
					(((*fromData >>  8) & 0xff) <<  8) |  // green
					(((*fromData >> 16) & 0xff)      ) ;  // red
				toData++,fromData++;
			}
		}
		else if (bytesPerComponent == 2) {
			uint16_t *toData = (uint16_t*)(screenbase + destRow + destCol);
			uint16_t *fromData = (uint16_t *)(dispBitsIndex + sourceRow + sourceCol);

			// Use 16 bits to store each pixel:
			// the first 5 bit representing the intensity of the red channel
			// the next 6 bits representing the intensity of the green channel and
			// the final 5 bits representing the intensity of the blue channel.	
			for (x = affectedL; x<affectedR; x++) {
				*toData = 
					(((((*fromData & 0x7C00) >> 10) << 3) >> 3) << 11) |  // Red
					(((((*fromData & 0x3E0)  >>  5) << 3) >> 2) <<  5) |  // Green
					(((((*fromData & 0x1F)        ) << 3) >> 3) <<  0);   // Blue

				toData++,fromData++;
			}
		}
#else
		memcpy((unsigned char *)screenbase + row + col, (unsigned char *)dispBitsIndex + row + col, rowLength);
#endif
	}
	
	if (clippedCursor == true) {
		showCursor();
	}
	dmb();
	success(true);
}

int ioForceDisplayUpdate(void) {
	return true;
}

int ioFormPrint(int bitsAddr, int width, int height, int depth, double hScale, double vScale, int landscapeFlag) {
	/* experimental: print a form with the given bitmap, width, height, and depth at
	   the given horizontal and vertical scales in the given orientation */

	printf("%s\n", __PRETTY_FUNCTION__);
	success(false);  
}
