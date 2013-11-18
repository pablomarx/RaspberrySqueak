#include "sq.h"

/*** Variables -- image and path names ***/
#define IMAGE_NAME_SIZE 300
char imageName[IMAGE_NAME_SIZE + 1];  /* full path to image */

#define SHORTIMAGE_NAME_SIZE 100
char shortImageName[SHORTIMAGE_NAME_SIZE + 1];  /* just the image file name */

#define VMPATH_SIZE 300
char vmPath[VMPATH_SIZE + 1];  /* full path to interpreter's directory */


/*** VM Home Directory Path ***/

int vmPathSize(void) {
	return strlen(vmPath);
}

int vmPathGetLength(int sqVMPathIndex, int length) {
	char *stVMPath = (char *) sqVMPathIndex;
	int count, i;

	count = strlen(vmPath);
	count = (length < count) ? length : count;

	/* copy the file name into the Squeak string */
	for (i = 0; i < count; i++) {
		stVMPath[i] = vmPath[i];
	}
	return count;
}

/*** Image File Operations ***/

void sqImageFileClose(sqImageFile f) {
	printf("%s\n", __PRETTY_FUNCTION__);
	f->current = f->base;
}

sqImageFile sqImageFileOpen(char *fileName, char *mode) {
	printf("%s %s %s\n", __PRETTY_FUNCTION__, fileName, mode);
	sqImageFile file = (sqImageFile)malloc(sizeof(sqImageFile));
	return file;
}

int sqImageFilePosition(sqImageFile f) {
	printf("%s\n", __PRETTY_FUNCTION__);
	return f->current - f->base;
}

int sqImageFileRead(void *ptr, int elementSize, int count, sqImageFile f) {
	memcpy(ptr, f->current, count * elementSize);
	f->current += count * elementSize;
	return count;
}

void sqImageFileSeek(sqImageFile f, int pos) {
	f->current = f->base + pos;
}

int sqImageFileWrite(void *ptr, int elementSize, int count, sqImageFile f) {
	//printf("%s elementSize=%i, count=%i\n", __PRETTY_FUNCTION__, elementSize, count);
	return 0;
}

/*** Image File Naming ***/

int imageNameSize(void) {
	return strlen(imageName);
}

int imageNameGetLength(int sqImageNameIndex, int length) {
	char *sqImageName = (char *) sqImageNameIndex;
	int count, i;

	count = strlen(imageName);
	count = (length < count) ? length : count;

	/* copy the file name into the Squeak string */
	for (i = 0; i < count; i++) {
		sqImageName[i] = imageName[i];
	}
	return count;
}

int imageNamePutLength(int sqImageNameIndex, int length) {
	char *sqImageName = (char *) sqImageNameIndex;
	int count, i, ch, j;
	int lastColonIndex = -1;

	count = (IMAGE_NAME_SIZE < length) ? IMAGE_NAME_SIZE : length;

	/* copy the file name into a null-terminated C string */
	for (i = 0; i < count; i++) {
		ch = imageName[i] = sqImageName[i];
		if (ch == ':') {
			lastColonIndex = i;
		}
	}
	imageName[count] = 0;

	/* copy short image name into a null-terminated C string */
	for (i = lastColonIndex + 1, j = 0; i < count; i++, j++) {
		shortImageName[j] = imageName[i];
	}
	shortImageName[j] = 0;

	return count;
}
