#include "sq.h"
#include "FilePlugin.h"

void *os_exports[][3]=
{
	{ 0, 0, 0 },
};

#define STUBBED_OUT { /*printf("%s\n", __PRETTY_FUNCTION__);*/ /*success(false);*/ return 0; }


int ioDisablePowerManager(int disableIfNonZero) { return true; }
int ioSetInputSemaphore(int semaIndex) STUBBED_OUT
int ioFindExternalFunctionIn(char *lookupName, int moduleHandle) {
//	printf("%s lookupName=%s\n", __PRETTY_FUNCTION__, lookupName);
	return 0;
}
int ioLoadModule(char *pluginName) {
//	printf("%s pluginName=%s\n", __PRETTY_FUNCTION__, pluginName);
	return 0;
}
int ioFreeModule(int moduleHandle) STUBBED_OUT


/*** Profiling Stubs ***/

int clearProfile(void)														STUBBED_OUT
int dumpProfile(void)														STUBBED_OUT
int startProfiling(void)													STUBBED_OUT
int stopProfiling(void)														STUBBED_OUT


/*** Clipboard Stubs ***/
int clipboardReadIntoAt(int count, int byteArrayIndex, int startIndex)      STUBBED_OUT
int clipboardSize(void)                                                     STUBBED_OUT
int clipboardWriteFromAt(int count, int byteArrayIndex, int startIndex)     STUBBED_OUT

/* file i/o */
int sqFileAtEnd(SQFile *f) STUBBED_OUT
int sqFileClose(SQFile *f) STUBBED_OUT
int sqFileDeleteNameSize(int sqFileNameIndex, int sqFileNameSize) STUBBED_OUT
squeakFileOffsetType sqFileGetPosition(SQFile *f) STUBBED_OUT
int sqFileInit(void) { return true; }
int sqFileShutdown(void) STUBBED_OUT
int sqFileOpen(SQFile *f, int sqFileNameIndex, int sqFileNameSize, int writeFlag) STUBBED_OUT
size_t sqFileReadIntoAt(SQFile *f, size_t count, int byteArrayIndex, size_t startIndex) STUBBED_OUT
int sqFileRenameOldSizeNewSize(int oldNameIndex, int oldNameSize, int newNameIndex, int newNameSize) STUBBED_OUT
int sqFileSetPosition(SQFile *f, squeakFileOffsetType position) STUBBED_OUT
squeakFileOffsetType sqFileSize(SQFile *f) STUBBED_OUT
int sqFileValid(SQFile *f) STUBBED_OUT
size_t sqFileWriteFromAt(SQFile *f, size_t count, int byteArrayIndex, size_t startIndex) STUBBED_OUT
int sqFileFlush(SQFile *f) STUBBED_OUT
int sqFileTruncate(SQFile *f,squeakFileOffsetType offset) STUBBED_OUT
int sqFileThisSession(void) STUBBED_OUT

/* directories */
int dir_Delimitor(void) {
	return '/';
}
int dir_Create(char *pathString, int pathStringLength) STUBBED_OUT
int dir_Delete(char *pathString, int pathStringLength) STUBBED_OUT
int dir_Lookup(char *pathString, int pathStringLength, int index,
        /* outputs: */
        char *name, int *nameLength, int *creationDate, int *modificationDate,
        int *isDirectory, squeakFileOffsetType *sizeIfFile)            STUBBED_OUT

int dir_PathToWorkingDir(char *pathName, int pathNameMax) STUBBED_OUT
int dir_SetMacFileTypeAndCreator(char *filename, int filenameSize, char *fType, char *fCreator) STUBBED_OUT
int dir_GetMacFileTypeAndCreator(char *filename, int filenameSize, char *fType, char *fCreator) STUBBED_OUT

/* security stubs */
int ioCanConnectToPort(int netAddr, int port) STUBBED_OUT
int ioCanCreatePathOfSize(char* pathString, int pathStringLength) STUBBED_OUT
int ioCanCreateSocketOfType(int netType, int socketType) STUBBED_OUT
int ioCanDeleteFileOfSize(char* pathString, int pathStringLength) STUBBED_OUT
int ioCanDeletePathOfSize(char* pathString, int pathStringLength) STUBBED_OUT
int ioCanGetFileTypeOfSize(char* pathString, int pathStringLength) STUBBED_OUT
int ioCanListPathOfSize(char* pathString, int pathStringLength) STUBBED_OUT
int ioCanListenOnPort(int s, int port) STUBBED_OUT
int ioCanOpenAsyncFileOfSizeWritable(char* pathString, int pathStringLength, int writeFlag) STUBBED_OUT
int ioCanOpenFileOfSizeWritable(char* pathString, int pathStringLength, int writeFlag) STUBBED_OUT
int ioCanRenameFileOfSize(char* pathString, int pathStringLength) STUBBED_OUT
int ioCanRenameImage(void) STUBBED_OUT
int ioCanSetFileTypeOfSize(char* pathString, int pathStringLength) STUBBED_OUT
int ioCanWriteImage(void) STUBBED_OUT
int ioDisableFileAccess(void) STUBBED_OUT
int ioDisableImageWrite(void) STUBBED_OUT
int ioDisableSocketAccess() STUBBED_OUT
char *ioGetSecureUserDirectory(void) STUBBED_OUT
char *ioGetUntrustedUserDirectory(void) STUBBED_OUT
int ioHasFileAccess(void) STUBBED_OUT
int ioHasSocketAccess() STUBBED_OUT
int ioInitSecurity(void) { return true; }
