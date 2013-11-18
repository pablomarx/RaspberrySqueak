#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sqConfig.h"
#include "sqVirtualMachine.h"

#define true 1
#define false 0
#define null 0  /* using "null" because nil is predefined in Think C */

/* pluggable primitives macros */
/* Note: All pluggable primitives are defined as
	EXPORT(int) somePrimitive(void)
   If the platform requires special declaration modifiers
   the EXPORT macro can be redefined
*/
#define EXPORT(returnType) returnType

/* image save/restore macros */
/* Note: The image file save and restore code uses these macros; they
   can be redefined in sqPlatformSpecific.h if desired. These default
   versions are defined in terms of the ANSI Standard C libraries.
*/
#define sqImageFile FILE *
#define sqImageFileClose(f)                  fclose(f)
#define sqImageFileOpen(fileName, mode)      fopen(fileName, mode)
#define sqImageFilePosition(f)               ftell(f)
#define sqImageFileRead(ptr, sz, count, f)   fread(ptr, sz, count, f)
#define sqImageFileSeek(f, pos)              fseek(f, pos, SEEK_SET)
#define sqImageFileWrite(ptr, sz, count, f)  fwrite(ptr, sz, count, f)
#define sqAllocateMemory(minHeapSize, desiredHeapSize)   malloc(desiredHeapSize)

/* platform-dependent float conversion macros */
/* Note: Second argument must be a variable name, not an expression! */
/* Note: Floats in image are always in PowerPC word order; change
   these macros to swap words if necessary. This costs no extra and
   obviates sometimes having to word-swap floats when reading an image.
*/
#if defined(DOUBLE_WORD_ALIGNMENT) || defined(DOUBLE_WORD_ORDER)
# ifdef DOUBLE_WORD_ORDER
/* word-based copy with swapping for non-PowerPC order */
#   define storeFloatAtfrom(i, floatVarName) \
	*((int *) (i) + 0) = *((int *) &(floatVarName) + 1); \
	*((int *) (i) + 1) = *((int *) &(floatVarName) + 0);
#   define fetchFloatAtinto(i, floatVarName) \
	*((int *) &(floatVarName) + 0) = *((int *) (i) + 1); \
	*((int *) &(floatVarName) + 1) = *((int *) (i) + 0);
# else /*!DOUBLE_WORD_ORDER*/
/* word-based copy for machines with alignment restrictions */
#   define storeFloatAtfrom(i, floatVarName) \
	*((int *) (i) + 0) = *((int *) &(floatVarName) + 0); \
	*((int *) (i) + 1) = *((int *) &(floatVarName) + 1);
#   define fetchFloatAtinto(i, floatVarName) \
	*((int *) &(floatVarName) + 0) = *((int *) (i) + 0); \
	*((int *) &(floatVarName) + 1) = *((int *) (i) + 1);
# endif /*!DOUBLE_WORD_ORDER*/
#else /*!(DOUBLE_WORD_ORDER||DOUBLE_WORD_ALIGNMENT)*/
/* for machines that allow doubles to be on any word boundary */
# define storeFloatAtfrom(i, floatVarName) \
	*((double *) (i)) = (floatVarName);
# define fetchFloatAtinto(i, floatVarName) \
	(floatVarName) = *((double *) (i));
#endif

/* platform-dependent memory size adjustment macro */
/* Note: This macro can be redefined to allows platforms with a
   fixed application memory partition (notably, the Macintosh)
   to reserve extra C heap memory for special applications that need
   it (e.g., for a 3D graphics library). Since most platforms can
   extend their application memory partition at run time if needed,
   this macro is defined as a noop here and redefined if necessary
   in sqPlatformSpecific.h.
*/

#define reserveExtraCHeapBytes(origHeapSize, bytesToReserve) origHeapSize

/* platform-dependent millisecond clock macros */
/* Note: The Squeak VM uses three different clocks functions for
   timing. The primary one, ioMSecs(), is used to implement Delay
   and Time millisecondClockValue. The resolution of this clock
   determines the resolution of these basic timing functions. For
   doing real-time control of music and MIDI, a clock with resolution
   down to one millisecond is preferred, but a coarser clock (say,
   1/60th second) can be used in a pinch. The VM calls a different
   clock function, ioLowResMSecs(), in order to detect long-running
   primitives. This function must be inexpensive to call because when
   a Delay is active it is polled twice per primitive call. On several
   platforms (Mac, Win32), the high-resolution system clock used in
   ioMSecs() would incur enough overhead in this case to slow down the
   the VM significantly. Thus, a cheaper clock with low resolution is
   used to implement ioLowResMSecs() on these platforms. Finally, the
   function ioMicroMSecs() is used only to collect timing statistics
   for the garbage collector and other VM facilities. (The function
   name is meant to suggest that the function is based on a clock
   with microsecond accuracy, even though the times it returns are
   in units of milliseconds.) This clock must have enough precision to
   provide accurate timings, and normally isn't called frequently
   enough to slow down the VM. Thus, it can use a more expensive clock
   that ioMSecs(). By default, all three clock functions are defined
   here as macros based on the standard C library function clock().
   Any of these macros can be overridden in sqPlatformSpecific.h.
*/

int ioMSecs(void);
int ioLowResMSecs(void);
int ioMicroMSecs(void);

#define ioMSecs()		((1000 * clock()) / CLOCKS_PER_SEC)
#define ioLowResMSecs()	((1000 * clock()) / CLOCKS_PER_SEC)
#define ioMicroMSecs()	((1000 * clock()) / CLOCKS_PER_SEC)

/* this include file may redefine earlier definitions and macros: */
#include "sqPlatformSpecific.h"

/* squeak file record; see sqFilePrims.c for details */
typedef struct {
	FILE	*file;
	int		sessionID;
	int		writable;
	int		fileSize;
	int		lastOp;  /* 0 = uncommitted, 1 = read, 2 = write */
} SQFile;

/* file i/o */
int sqFileAtEnd(SQFile *f);
int sqFileClose(SQFile *f);
int sqFileDeleteNameSize(int sqFileNameIndex, int sqFileNameSize);
int sqFileGetPosition(SQFile *f);
int sqFileInit(void);
int sqFileOpen(SQFile *f, int sqFileNameIndex, int sqFileNameSize, int writeFlag);
int sqFileReadIntoAt(SQFile *f, int count, int byteArrayIndex, int startIndex);
int sqFileRenameOldSizeNewSize(int oldNameIndex, int oldNameSize, int newNameIndex, int newNameSize);
int sqFileSetPosition(SQFile *f, int position);
int sqFileSize(SQFile *f);
int sqFileValid(SQFile *f);
int sqFileWriteFromAt(SQFile *f, int count, int byteArrayIndex, int startIndex);

/* directories */
int dir_Create(char *pathString, int pathStringLength);
int dir_Delete(char *pathString, int pathStringLength);
int dir_Delimitor(void);
int dir_Lookup(char *pathString, int pathStringLength, int index,
	/* outputs: */
	char *name, int *nameLength, int *creationDate, int *modificationDate,
	int *isDirectory, int *sizeIfFile);
int dir_PathToWorkingDir(char *pathName, int pathNameMax);
int dir_SetMacFileTypeAndCreator(char *filename, int filenameSize, char *fType, char *fCreator);

/* interpreter entry points */
void error(char *s);
int checkedByteAt(int byteAddress);
int checkedByteAtput(int byteAddress, int byte);
int checkedLongAt(int byteAddress);
int checkedLongAtput(int byteAddress, int a32BitInteger);
int fullDisplayUpdate(void);
int initializeInterpreter(int bytesToShift);
int interpret(void);
int primitiveFail(void);
int signalSemaphoreWithIndex(int index);
int success(int);

/* display, mouse, keyboard, time i/o */
int ioBeep(void);
int ioExit(void);
int ioForceDisplayUpdate(void);
int ioFormPrint(
	int bitsAddr, int width, int height, int depth,
	double hScale, double vScale, int landscapeFlag);
int ioSetFullScreen(int fullScreen);
int ioGetButtonState(void);
int ioGetKeystroke(void);
int ioMousePoint(void);
int ioPeekKeystroke(void);
int ioProcessEvents(void);
int ioRelinquishProcessorForMicroseconds(int microSeconds);
int ioScreenSize(void);
int ioSeconds(void);
int ioSetCursor(int cursorBitsIndex, int offsetX, int offsetY);
int ioSetCursorWithMask(int cursorBitsIndex, int cursorMaskIndex, int offsetX, int offsetY);
int ioShowDisplay(
	int dispBitsIndex, int width, int height, int depth,
	int affectedL, int affectedR, int affectedT, int affectedB);
int ioHasDisplayDepth(int depth);
int ioSetDisplayMode(int width, int height, int depth, int fullscreenFlag);

/* image file and VM path names */
extern char imageName[];
int imageNameGetLength(int sqImageNameIndex, int length);
int imageNamePutLength(int sqImageNameIndex, int length);
int imageNameSize(void);
int vmPathSize(void);
int vmPathGetLength(int sqVMPathIndex, int length);

/* save/restore */
/* Read the image from the given file starting at the given image offset */
int readImageFromFileHeapSizeStartingAt(sqImageFile f, int desiredHeapSize, int imageOffset);
/* NOTE: The following is obsolete - it is only provided for compatibility */
#define readImageFromFileHeapSize(f, s) readImageFromFileHeapSizeStartingAt(f,s,0)

/* clipboard (cut/copy/paste) */
int clipboardSize(void);
int clipboardReadIntoAt(int count, int byteArrayIndex, int startIndex);
int clipboardWriteFromAt(int count, int byteArrayIndex, int startIndex);

/* sound output */
int snd_AvailableSpace(void);
int snd_InsertSamplesFromLeadTime(int frameCount, int srcBufPtr, int samplesOfLeadTime);
int snd_PlaySamplesFromAtLength(int frameCount, int arrayIndex, int startIndex);
int snd_PlaySilence(void);
int snd_Start(int frameCount, int samplesPerSec, int stereo, int semaIndex);
int snd_Stop(void);

/* sound input */
int snd_SetRecordLevel(int level);
int snd_StartRecording(int desiredSamplesPerSec, int stereo, int semaIndex);
int snd_StopRecording(void);
double snd_GetRecordingSampleRate(void);
int snd_RecordSamplesIntoAtLength(int buf, int startSliceIndex, int bufferSizeInBytes);

/* joystick support */
int joystickInit(void);
int joystickRead(int stickIndex);

/* browser plug-in support */
int plugInAllowAccessToFilePath(char *pathString, int pathStringLength);
int plugInInit(char *imageName);
int plugInShutdown(void);
int plugInInterpretCycles(int cycleCount);

/* interpreter entry points needed by compiled primitives */
void * arrayValueOf(int arrayOop);
int checkedIntegerValueOf(int intOop);
void * fetchArrayofObject(int fieldIndex, int objectPointer);
double fetchFloatofObject(int fieldIndex, int objectPointer);
int fetchIntegerofObject(int fieldIndex, int objectPointer);
double floatValueOf(int floatOop);
int pop(int nItems);
int pushInteger(int integerValue);
int sizeOfSTArrayFromCPrimitive(void *cPtr);
int storeIntegerofObjectwithValue(int fieldIndex, int objectPointer, int integerValue);

/* sound generation primitives (old, for backward compatibility) */
int primWaveTableSoundmixSampleCountintostartingAtpan(void);
int primFMSoundmixSampleCountintostartingAtpan(void);
int primPluckedSoundmixSampleCountintostartingAtpan(void);
int primSampledSoundmixSampleCountintostartingAtpan(void);
int oldprimSampledSoundmixSampleCountintostartingAtleftVolrightVol(void);

/* sound generation primitives */
int primFMSoundmixSampleCountintostartingAtleftVolrightVol(void);
int primLoopedSampledSoundmixSampleCountintostartingAtleftVolrightVol(void);
int primPluckedSoundmixSampleCountintostartingAtleftVolrightVol(void);
int primReverbSoundapplyReverbTostartingAtcount(void);
int primSampledSoundmixSampleCountintostartingAtleftVolrightVol(void);

/* squeak socket record; see sqMacNetwork.c for details */
typedef struct {
	int		sessionID;
	int		socketType;  /* 0 = TCP, 1 = UDP */
	void	*privateSocketPtr;
}  SQSocket, *SocketPtr;

/* networking primitives */
int		sqNetworkInit(int resolverSemaIndex);
void	sqNetworkShutdown(void);
void	sqResolverAbort(void);
void	sqResolverAddrLookupResult(char *nameForAddress, int nameSize);
int		sqResolverAddrLookupResultSize(void);
int		sqResolverError(void);
int		sqResolverLocalAddress(void);
int		sqResolverNameLookupResult(void);
void	sqResolverStartAddrLookup(int address);
void	sqResolverStartNameLookup(char *hostName, int nameSize);
int		sqResolverStatus(void);
void	sqSocketAbortConnection(SocketPtr s);
void	sqSocketCloseConnection(SocketPtr s);
int		sqSocketConnectionStatus(SocketPtr s);
void	sqSocketConnectToPort(SocketPtr s, int addr, int port);
void	sqSocketCreateNetTypeSocketTypeRecvBytesSendBytesSemaID(
			SocketPtr s, int netType, int socketType,
			int recvBufSize, int sendBufSize, int semaIndex);
void	sqSocketDestroy(SocketPtr s);
int		sqSocketError(SocketPtr s);
void	sqSocketListenOnPort(SocketPtr s, int port);
int		sqSocketLocalAddress(SocketPtr s);
int		sqSocketLocalPort(SocketPtr s);
int		sqSocketReceiveDataAvailable(SocketPtr s);
int		sqSocketReceiveDataBufCount(SocketPtr s, int buf, int bufSize);
int		sqSocketRemoteAddress(SocketPtr s);
int		sqSocketRemotePort(SocketPtr s);
int		sqSocketSendDataBufCount(SocketPtr s, int buf, int bufSize);
int		sqSocketSendDone(SocketPtr s);
/* 	ar 7/16/1999: New primitives for accept().
	Note: If accept() calls are not supported simply make the calls fail
	and the old connection style will be used */
void	sqSocketListenOnPortBacklogSize(SocketPtr s, int port, int backlogSize);
void	sqSocketAcceptFromRecvBytesSendBytesSemaID(
			SocketPtr s, SocketPtr serverSocket,
			int recvBufSize, int sendBufSize, int semaIndex);

/* profiling */
int clearProfile(void);
int dumpProfile(void);
int startProfiling(void);
int stopProfiling(void);

/* system attributes */
int attributeSize(int id);
int getAttributeIntoLength(int id, int byteArrayIndex, int length);

/* miscellaneous primitives */
int primBitmapcompresstoByteArray(void);
int primBitmapdecompressfromByteArrayat(void);
int primSampledSoundconvert8bitSignedFromto16Bit(void);
int primStringcomparewithcollated(void);
int primStringfindFirstInStringinSetstartingAt(void);
int primStringfindSubstringinstartingAtmatchTable(void);
int primStringindexOfAsciiinStringstartingAt(void);
int primStringtranslatefromtotable(void);

/* serial port primitives */
int serialPortClose(int portNum);
int serialPortOpen(
  int portNum, int baudRate, int stopBitsType, int parityType, int dataBits,
  int inFlowCtrl, int outFlowCtrl, int xOnChar, int xOffChar);
int serialPortReadInto(int portNum, int count, int bufferPtr);
int serialPortWriteFrom(int portNum, int count, int bufferPtr);

/* MIDI primitives */
int sqMIDIGetClock(void);
int sqMIDIGetPortCount(void);
int sqMIDIGetPortDirectionality(int portNum);
int sqMIDIGetPortName(int portNum, int namePtr, int length);
int sqMIDIClosePort(int portNum);
int sqMIDIOpenPort(int portNum, int readSemaIndex, int interfaceClockRate);
int sqMIDIParameter(int whichParameter, int modify, int newValue);
int sqMIDIPortReadInto(int portNum, int count, int bufferPtr);
int sqMIDIPortWriteFromAt(int portNum, int count, int bufferPtr, int time);

/*** Experimental Asynchronous File I/O ***/
typedef struct {
	int			sessionID;
	void		*state;
} AsyncFile;

int asyncFileClose(AsyncFile *f);
int asyncFileOpen(AsyncFile *f, int fileNamePtr, int fileNameSize, int writeFlag, int semaIndex);
int asyncFileRecordSize();
int asyncFileReadResult(AsyncFile *f, int bufferPtr, int bufferSize);
int asyncFileReadStart(AsyncFile *f, int fPosition, int count);
int asyncFileWriteResult(AsyncFile *f);
int asyncFileWriteStart(AsyncFile *f, int fPosition, int bufferPtr, int bufferSize);

/*** pluggable primitive support ***/
int ioLoadExternalFunctionOfLengthFromModuleOfLength(
  int functionNameIndex, int functionNameLength,
  int moduleNameIndex, int moduleNameLength);

/*** sound compression primitives ***/
int primADPCMCodecprivateDecodeMono(void);
int primADPCMCodecprivateDecodeStereo(void);
int primADPCMCodecprivateEncodeMono(void);
int primADPCMCodecprivateEncodeStereo(void);

/*** tablet support ***/
int tabletGetParameters(int cursorIndex, int result[]);
int tabletRead(int cursorIndex, int result[]);
int tabletResultSize(void);
