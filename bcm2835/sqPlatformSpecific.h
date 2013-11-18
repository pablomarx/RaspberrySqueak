/* replace the image file manipulation macros with functions */
#undef sqImageFile
#undef sqImageFileClose
#undef sqImageFileOpen
#undef sqImageFilePosition
#undef sqImageFileRead
#undef sqImageFileSeek
#undef sqImageFileWrite
#undef sqAllocateMemory


typedef struct _rpiImageFile {
	unsigned char *base;
	int length;
	unsigned char *current;
} rpiImageFile;

#define sqImageFile rpiImageFile *

void        sqImageFileClose(sqImageFile f);
sqImageFile sqImageFileOpen(char *fileName, char *mode);
int         sqImageFilePosition(sqImageFile f);
int         sqImageFileRead(void *ptr, int elementSize, int count, sqImageFile f);
void        sqImageFileSeek(sqImageFile f, int pos);
int         sqImageFileWrite(void *ptr, int elementSize, int count, sqImageFile f);
void *      sqAllocateMemory(int minHeapSize, int desiredHeapSize);

#undef ioMSecs
#undef ioLowResMSecs
#undef ioMicroMSecs

