#include "sq.h"

#define STUBBED_OUT { /*printf("%s\n", __PRETTY_FUNCTION__);*/ success(false); }

void	sqSocketAcceptFromRecvBytesSendBytesSemaID(
	SocketPtr s, SocketPtr serverSocket,
	int recvBufSize, int sendBufSize, int semaIndex)                        STUBBED_OUT

void	sqSocketListenOnPortBacklogSize(
	SocketPtr s, int port, int backlogSize)                                 STUBBED_OUT


/*** File stubs ***/
int sqFileAtEnd(SQFile *f) STUBBED_OUT
int sqFileClose(SQFile *f) STUBBED_OUT
int sqFileDeleteNameSize(int sqFileNameIndex, int sqFileNameSize) STUBBED_OUT
int sqFileGetPosition(SQFile *f) STUBBED_OUT
int sqFileInit(void) STUBBED_OUT
int sqFileOpen(SQFile *f, int sqFileNameIndex, int sqFileNameSize, int writeFlag) STUBBED_OUT
int sqFileReadIntoAt(SQFile *f, int count, int byteArrayIndex, int startIndex) STUBBED_OUT
int sqFileRenameOldSizeNewSize(int oldNameIndex, int oldNameSize, int newNameIndex, int newNameSize) STUBBED_OUT
int sqFileSetPosition(SQFile *f, int position) STUBBED_OUT
int sqFileSize(SQFile *f) STUBBED_OUT
int sqFileWriteFromAt(SQFile *f, int count, int byteArrayIndex, int startIndex) STUBBED_OUT

/*** Directory Stubs ***/

int dir_Delete(char *pathString, int pathStringLength)                      STUBBED_OUT
int dir_Create(char *pathString, int pathStringLength)						STUBBED_OUT
int dir_Lookup(char *pathString, int pathStringLength, int index,
  char *name, int *nameLength, int *creationDate, int *modificationDate,
  int *isDirectory, int *sizeIfFile)										STUBBED_OUT
int dir_SetMacFileTypeAndCreator(char *filename, int filenameSize,
  char *fType, char *fCreator)												STUBBED_OUT

/*** Joystick Stubs ***/

int joystickRead(int stickIndex)											STUBBED_OUT

/*** MIDI Stubs ***/

int sqMIDIClosePort(int portNum)											STUBBED_OUT
int sqMIDIGetClock(void)													STUBBED_OUT
int sqMIDIGetPortCount(void)												STUBBED_OUT
int sqMIDIGetPortDirectionality(int portNum)								STUBBED_OUT
int sqMIDIGetPortName(int portNum, int namePtr, int length)					STUBBED_OUT
int sqMIDIOpenPort(int portNum, int readSemaIndex, int interfaceClockRate)	STUBBED_OUT
int sqMIDIParameter(int whichParameter, int modify, int newValue)			STUBBED_OUT
int sqMIDIPortReadInto(int portNum, int count, int bufferPtr)				STUBBED_OUT
int sqMIDIPortWriteFromAt(int portNum, int count, int bufferPtr, int time)	STUBBED_OUT

/*** Networking Stubs ***/

int sqNetworkInit(int resolverSemaIndex)									STUBBED_OUT
void sqNetworkShutdown(void)												STUBBED_OUT
void sqResolverAbort(void)													STUBBED_OUT
void sqResolverAddrLookupResult(char *nameForAddress, int nameSize)			STUBBED_OUT
int sqResolverAddrLookupResultSize(void)									STUBBED_OUT
int sqResolverError(void)													STUBBED_OUT
int sqResolverLocalAddress(void)											STUBBED_OUT
int sqResolverNameLookupResult(void)										STUBBED_OUT
void sqResolverStartAddrLookup(int address)									STUBBED_OUT
void sqResolverStartNameLookup(char *hostName, int nameSize)				STUBBED_OUT
int sqResolverStatus(void)													STUBBED_OUT
void sqSocketAbortConnection(SocketPtr s)									STUBBED_OUT
void sqSocketCloseConnection(SocketPtr s)									STUBBED_OUT
int sqSocketConnectionStatus(SocketPtr s)									STUBBED_OUT
void sqSocketConnectToPort(SocketPtr s, int addr, int port)					STUBBED_OUT
void sqSocketCreateNetTypeSocketTypeRecvBytesSendBytesSemaID(
  SocketPtr s, int netType, int socketType,
  int recvBufSize, int sendBufSize, int semaIndex)							STUBBED_OUT
void sqSocketDestroy(SocketPtr s)											STUBBED_OUT
int sqSocketError(SocketPtr s)												STUBBED_OUT
void sqSocketListenOnPort(SocketPtr s, int port)							STUBBED_OUT
int sqSocketLocalAddress(SocketPtr s)										STUBBED_OUT
int sqSocketLocalPort(SocketPtr s)											STUBBED_OUT
int sqSocketReceiveDataAvailable(SocketPtr s)								STUBBED_OUT
int sqSocketReceiveDataBufCount(SocketPtr s, int buf, int bufSize)			STUBBED_OUT
int sqSocketRemoteAddress(SocketPtr s)										STUBBED_OUT
int sqSocketRemotePort(SocketPtr s)											STUBBED_OUT
int sqSocketSendDataBufCount(SocketPtr s, int buf, int bufSize)				STUBBED_OUT
int sqSocketSendDone(SocketPtr s)											STUBBED_OUT

/*** Profiling Stubs ***/

int clearProfile(void)														STUBBED_OUT
int dumpProfile(void)														STUBBED_OUT
int startProfiling(void)													STUBBED_OUT
int stopProfiling(void)														STUBBED_OUT

/*** Serial Port Functions Stubs ***/

int serialPortClose(int portNum)											STUBBED_OUT
int serialPortOpen(
  int portNum, int baudRate, int stopBitsType,
  int parityType, int dataBits, int inFlowCtrl, int outFlowCtrl,
  int xOnChar, int xOffChar)												STUBBED_OUT
int serialPortReadInto(int portNum, int count, int bufferPtr)				STUBBED_OUT
int serialPortWriteFrom(int portNum, int count, int bufferPtr)				STUBBED_OUT

/*** Sound Output Stubs ***/

int snd_AvailableSpace(void)												STUBBED_OUT
int snd_PlaySamplesFromAtLength(
  int frameCount, int arrayIndex, int startIndex)							STUBBED_OUT
int snd_InsertSamplesFromLeadTime(
  int frameCount, int srcBufPtr, int samplesOfLeadTime)						STUBBED_OUT
int snd_PlaySilence(void)													STUBBED_OUT
int snd_Start(int frameCount, int samplesPerSec, int stereo, int semaIndex)	STUBBED_OUT
int snd_Stop(void)															STUBBED_OUT

/*** Sound Input Stubs ***/

int snd_SetRecordLevel(int level)											STUBBED_OUT
int snd_StartRecording(int desiredSamplesPerSec, int stereo, int semaIndex)	STUBBED_OUT
int snd_StopRecording(void)													STUBBED_OUT
double snd_GetRecordingSampleRate(void)										STUBBED_OUT
int snd_RecordSamplesIntoAtLength(
  int buf, int startSliceIndex, int bufferSizeInBytes)						STUBBED_OUT

/*** Sound Synthesis Primitives Stubs ***/

int primFMSoundmixSampleCountintostartingAtleftVolrightVol(void)			STUBBED_OUT
int primLoopedSampledSoundmixSampleCountintostartingAtleftVolrightVol(void)	STUBBED_OUT
int primPluckedSoundmixSampleCountintostartingAtleftVolrightVol(void)		STUBBED_OUT
int primReverbSoundapplyReverbTostartingAtcount(void)						STUBBED_OUT
int primSampledSoundmixSampleCountintostartingAtleftVolrightVol(void)		STUBBED_OUT

/*** Old Sound Synthesis Primitives Stubs ***/

int primFMSoundmixSampleCountintostartingAtpan(void)						STUBBED_OUT
int primPluckedSoundmixSampleCountintostartingAtpan(void)					STUBBED_OUT
int primSampledSoundmixSampleCountintostartingAtpan(void)					STUBBED_OUT
int primWaveTableSoundmixSampleCountintostartingAtpan(void)					STUBBED_OUT

/*** Experimental Asynchronous File I/O ***/

int asyncFileClose(AsyncFile *f)											STUBBED_OUT
int asyncFileOpen(
  AsyncFile *f, int fileNamePtr, int fileNameSize,
  int writeFlag, int semaIndex)												STUBBED_OUT
int asyncFileRecordSize()													STUBBED_OUT
int asyncFileReadResult(AsyncFile *f, int bufferPtr, int bufferSize)		STUBBED_OUT
int asyncFileReadStart(AsyncFile *f, int fPosition, int count)				STUBBED_OUT
int asyncFileWriteResult(AsyncFile *f)										STUBBED_OUT
int asyncFileWriteStart(
  AsyncFile *f, int fPosition, int bufferPtr, int bufferSize)				STUBBED_OUT

/*** Clipboard Stubs ***/
int clipboardReadIntoAt(int count, int byteArrayIndex, int startIndex)      STUBBED_OUT
int clipboardSize(void)                                                     STUBBED_OUT
int clipboardWriteFromAt(int count, int byteArrayIndex, int startIndex)     STUBBED_OUT


/*** Tablet/joystick (?) stubs ***/
int tabletRead(int cursorIndex, int result[])                               STUBBED_OUT
int tabletResultSize(void)                                                  STUBBED_OUT
int tabletGetParameters(int cursorIndex, int result[])                      STUBBED_OUT

/*** FFI (?) stubs ***/
int ioLoadExternalFunctionOfLengthFromModuleOfLength(
	int functionNameIndex, int functionNameLength, 
	int moduleNameIndex, int moduleNameLength)                              STUBBED_OUT

/*** Sound primitive stubs ***/
int oldprimSampledSoundmixSampleCountintostartingAtleftVolrightVol(void)    STUBBED_OUT
int primADPCMCodecprivateDecodeMono(void)                                   STUBBED_OUT
int primADPCMCodecprivateDecodeStereo(void)                                 STUBBED_OUT
int primADPCMCodecprivateEncodeMono(void)                                   STUBBED_OUT
int primADPCMCodecprivateEncodeStereo(void)                                 STUBBED_OUT
