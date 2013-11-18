/* Automatically generated from Squeak on #(4 March 2003 4:22:28 am) */

#include "sq.h"

/* memory access macros */
#define byteAt(i) (*((unsigned char *) (i)))
#define byteAtput(i, val) (*((unsigned char *) (i)) = val)
#define longAt(i) (*((int *) (i)))
#define longAtput(i, val) (*((int *) (i)) = val)

int printCallStack(void);
void error(char *s);
void error(char *s) {
	/* Print an error message and exit. */
	static int printingStack = false;

	printf("\n%s\n\n", s);
	if (!printingStack) {
		/* flag prevents recursive error when trying to print a broken stack */
		printingStack = true;
		printCallStack();
	}
//	exit(-1);
	ioExit();
}

/*** Variables ***/
int activeContext;
int allocationCount;
int allocationsBetweenGCs;
int argumentCount;
int atCache[65];
int child;
int compEnd;
int compStart;
int (*compilerHooks[16])();
int compilerInitialized;
int deferDisplayUpdates;
int displayBits;
int endOfMemory;
int externalPrimitiveTable[4097];
int extraVMMemory;
int falseObj;
int field;
int freeBlock;
int freeContexts;
int freeLargeContexts;
int fullScreenFlag;
int fwdTableLast;
int fwdTableNext;
int growHeadroom;
int instructionPointer;
struct VirtualMachine* interpreterProxy;
const char *interpreterVersion = "Squeak3.4 of 1 March 2003 [latest update: #5170]";
int interruptCheckCounter;
int interruptCheckCounterFeedBackReset;
int interruptChecksEveryNms;
int interruptKeycode;
int interruptPending;
int lastHash;
int lastTick;
int lkupClass;
int lowSpaceThreshold;
unsigned char* memory;
int memoryLimit;
int messageSelector;
int method;
int methodCache[4097];
int methodClass;
int newMethod;
int newNativeMethod;
int nextPollTick;
int nextWakeupTick;
int nilObj;
char* obsoleteIndexedPrimitiveTable[][3] = {
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "BitBltPlugin", "primitiveCopyBits", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "BitBltPlugin", "primitiveDrawLoop", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "JoystickTabletPlugin", "primitiveReadJoystick", NULL },
{ "BitBltPlugin", "primitiveWarpBits", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "FilePlugin", "primitiveFileAtEnd", NULL },
{ "FilePlugin", "primitiveFileClose", NULL },
{ "FilePlugin", "primitiveFileGetPosition", NULL },
{ "FilePlugin", "primitiveFileOpen", NULL },
{ "FilePlugin", "primitiveFileRead", NULL },
{ "FilePlugin", "primitiveFileSetPosition", NULL },
{ "FilePlugin", "primitiveFileDelete", NULL },
{ "FilePlugin", "primitiveFileSize", NULL },
{ "FilePlugin", "primitiveFileWrite", NULL },
{ "FilePlugin", "primitiveFileRename", NULL },
{ "FilePlugin", "primitiveDirectoryCreate", NULL },
{ "FilePlugin", "primitiveDirectoryDelimitor", NULL },
{ "FilePlugin", "primitiveDirectoryLookup", NULL },
{ "FilePlugin", "primitiveDirectoryDelete", NULL },
{ "FilePlugin", "primitiveDirectoryGetMacTypeAndCreator", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "FilePlugin", "primitiveDirectorySetMacTypeAndCreator", NULL },
{ "SoundPlugin", "primitiveSoundStart", NULL },
{ "SoundPlugin", "primitiveSoundStartWithSemaphore", NULL },
{ "SoundPlugin", "primitiveSoundStop", NULL },
{ "SoundPlugin", "primitiveSoundAvailableSpace", NULL },
{ "SoundPlugin", "primitiveSoundPlaySamples", NULL },
{ "SoundPlugin", "primitiveSoundPlaySilence", NULL },
{ "SoundGenerationPlugin", "primitiveWaveTableSoundMix", NULL },
{ "SoundGenerationPlugin", "primitiveFMSoundMix", NULL },
{ "SoundGenerationPlugin", "primitivePluckedSoundMix", NULL },
{ "SoundGenerationPlugin", "primitiveSampledSoundMix", NULL },
{ "SoundGenerationPlugin", "primitiveMixFMSound", NULL },
{ "SoundGenerationPlugin", "primitiveMixPluckedSound", NULL },
{ "SoundGenerationPlugin", "primitiveOldSampledSoundMix", NULL },
{ "SoundGenerationPlugin", "primitiveApplyReverb", NULL },
{ "SoundGenerationPlugin", "primitiveMixLoopedSampledSound", NULL },
{ "SoundGenerationPlugin", "primitiveMixSampledSound", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "SoundPlugin", "primitiveSoundInsertSamples", NULL },
{ "SoundPlugin", "primitiveSoundStartRecording", NULL },
{ "SoundPlugin", "primitiveSoundStopRecording", NULL },
{ "SoundPlugin", "primitiveSoundGetRecordingSampleRate", NULL },
{ "SoundPlugin", "primitiveSoundRecordSamples", NULL },
{ "SoundPlugin", "primitiveSoundSetRecordLevel", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "SocketPlugin", "primitiveInitializeNetwork", NULL },
{ "SocketPlugin", "primitiveResolverStartNameLookup", NULL },
{ "SocketPlugin", "primitiveResolverNameLookupResult", NULL },
{ "SocketPlugin", "primitiveResolverStartAddressLookup", NULL },
{ "SocketPlugin", "primitiveResolverAddressLookupResult", NULL },
{ "SocketPlugin", "primitiveResolverAbortLookup", NULL },
{ "SocketPlugin", "primitiveResolverLocalAddress", NULL },
{ "SocketPlugin", "primitiveResolverStatus", NULL },
{ "SocketPlugin", "primitiveResolverError", NULL },
{ "SocketPlugin", "primitiveSocketCreate", NULL },
{ "SocketPlugin", "primitiveSocketDestroy", NULL },
{ "SocketPlugin", "primitiveSocketConnectionStatus", NULL },
{ "SocketPlugin", "primitiveSocketError", NULL },
{ "SocketPlugin", "primitiveSocketLocalAddress", NULL },
{ "SocketPlugin", "primitiveSocketLocalPort", NULL },
{ "SocketPlugin", "primitiveSocketRemoteAddress", NULL },
{ "SocketPlugin", "primitiveSocketRemotePort", NULL },
{ "SocketPlugin", "primitiveSocketConnectToPort", NULL },
{ "SocketPlugin", "primitiveSocketListenWithOrWithoutBacklog", NULL },
{ "SocketPlugin", "primitiveSocketCloseConnection", NULL },
{ "SocketPlugin", "primitiveSocketAbortConnection", NULL },
{ "SocketPlugin", "primitiveSocketReceiveDataBufCount", NULL },
{ "SocketPlugin", "primitiveSocketReceiveDataAvailable", NULL },
{ "SocketPlugin", "primitiveSocketSendDataBufCount", NULL },
{ "SocketPlugin", "primitiveSocketSendDone", NULL },
{ "SocketPlugin", "primitiveSocketAccept", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "MiscPrimitivePlugin", "primitiveDecompressFromByteArray", NULL },
{ "MiscPrimitivePlugin", "primitiveCompareString", NULL },
{ "MiscPrimitivePlugin", "primitiveConvert8BitSigned", NULL },
{ "MiscPrimitivePlugin", "primitiveCompressToByteArray", NULL },
{ "SerialPlugin", "primitiveSerialPortOpen", NULL },
{ "SerialPlugin", "primitiveSerialPortClose", NULL },
{ "SerialPlugin", "primitiveSerialPortWrite", NULL },
{ "SerialPlugin", "primitiveSerialPortRead", NULL },
{ NULL, NULL, NULL },
{ "MiscPrimitivePlugin", "primitiveTranslateStringWithTable", NULL },
{ "MiscPrimitivePlugin", "primitiveFindFirstInString", NULL },
{ "MiscPrimitivePlugin", "primitiveIndexOfAsciiInString", NULL },
{ "MiscPrimitivePlugin", "primitiveFindSubstring", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "MIDIPlugin", "primitiveMIDIClosePort", NULL },
{ "MIDIPlugin", "primitiveMIDIGetClock", NULL },
{ "MIDIPlugin", "primitiveMIDIGetPortCount", NULL },
{ "MIDIPlugin", "primitiveMIDIGetPortDirectionality", NULL },
{ "MIDIPlugin", "primitiveMIDIGetPortName", NULL },
{ "MIDIPlugin", "primitiveMIDIOpenPort", NULL },
{ "MIDIPlugin", "primitiveMIDIParameterGetOrSet", NULL },
{ "MIDIPlugin", "primitiveMIDIRead", NULL },
{ "MIDIPlugin", "primitiveMIDIWrite", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileClose", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileOpen", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileReadResult", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileReadStart", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileWriteResult", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileWriteStart", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "JoystickTabletPlugin", "primitiveGetTabletParameters", NULL },
{ "JoystickTabletPlugin", "primitiveReadTablet", NULL },
{ "ADPCMCodecPlugin", "primitiveDecodeMono", NULL },
{ "ADPCMCodecPlugin", "primitiveDecodeStereo", NULL },
{ "ADPCMCodecPlugin", "primitiveEncodeMono", NULL },
{ "ADPCMCodecPlugin", "primitiveEncodeStereo", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL }
};
const char* obsoleteNamedPrimitiveTable[][3] = {
{ "gePrimitiveMergeFillFrom", "B2DPlugin", "primitiveMergeFillFrom" },
{ "gePrimitiveSetClipRect", "B2DPlugin", "primitiveSetClipRect" },
{ "gePrimitiveDoProfileStats", "B2DPlugin", "primitiveDoProfileStats" },
{ "gePrimitiveAddCompressedShape", "B2DPlugin", "primitiveAddCompressedShape" },
{ "gePrimitiveFinishedProcessing", "B2DPlugin", "primitiveFinishedProcessing" },
{ "gePrimitiveGetBezierStats", "B2DPlugin", "primitiveGetBezierStats" },
{ "gePrimitiveSetDepth", "B2DPlugin", "primitiveSetDepth" },
{ "gePrimitiveAbortProcessing", "B2DPlugin", "primitiveAbortProcessing" },
{ "gePrimitiveGetTimes", "B2DPlugin", "primitiveGetTimes" },
{ "gePrimitiveNextActiveEdgeEntry", "B2DPlugin", "primitiveNextActiveEdgeEntry" },
{ "gePrimitiveAddBezier", "B2DPlugin", "primitiveAddBezier" },
{ "gePrimitiveRenderScanline", "B2DPlugin", "primitiveRenderScanline" },
{ "gePrimitiveAddBezierShape", "B2DPlugin", "primitiveAddBezierShape" },
{ "gePrimitiveAddLine", "B2DPlugin", "primitiveAddLine" },
{ "gePrimitiveRenderImage", "B2DPlugin", "primitiveRenderImage" },
{ "gePrimitiveGetAALevel", "B2DPlugin", "primitiveGetAALevel" },
{ "gePrimitiveRegisterExternalEdge", "B2DPlugin", "primitiveRegisterExternalEdge" },
{ "gePrimitiveInitializeBuffer", "B2DPlugin", "primitiveInitializeBuffer" },
{ "gePrimitiveAddRect", "B2DPlugin", "primitiveAddRect" },
{ "gePrimitiveInitializeProcessing", "B2DPlugin", "primitiveInitializeProcessing" },
{ "gePrimitiveAddBitmapFill", "B2DPlugin", "primitiveAddBitmapFill" },
{ "gePrimitiveGetClipRect", "B2DPlugin", "primitiveGetClipRect" },
{ "gePrimitiveGetFailureReason", "B2DPlugin", "primitiveGetFailureReason" },
{ "gePrimitiveNextGlobalEdgeEntry", "B2DPlugin", "primitiveNextGlobalEdgeEntry" },
{ "gePrimitiveNextFillEntry", "B2DPlugin", "primitiveNextFillEntry" },
{ "gePrimitiveSetColorTransform", "B2DPlugin", "primitiveSetColorTransform" },
{ "gePrimitiveDisplaySpanBuffer", "B2DPlugin", "primitiveDisplaySpanBuffer" },
{ "gePrimitiveGetOffset", "B2DPlugin", "primitiveGetOffset" },
{ "gePrimitiveAddPolygon", "B2DPlugin", "primitiveAddPolygon" },
{ "gePrimitiveNeedsFlush", "B2DPlugin", "primitiveNeedsFlush" },
{ "gePrimitiveAddOval", "B2DPlugin", "primitiveAddOval" },
{ "gePrimitiveSetAALevel", "B2DPlugin", "primitiveSetAALevel" },
{ "gePrimitiveCopyBuffer", "B2DPlugin", "primitiveCopyBuffer" },
{ "gePrimitiveAddActiveEdgeEntry", "B2DPlugin", "primitiveAddActiveEdgeEntry" },
{ "gePrimitiveGetCounts", "B2DPlugin", "primitiveGetCounts" },
{ "gePrimitiveSetOffset", "B2DPlugin", "primitiveSetOffset" },
{ "gePrimitiveAddGradientFill", "B2DPlugin", "primitiveAddGradientFill" },
{ "gePrimitiveChangedActiveEdgeEntry", "B2DPlugin", "primitiveChangedActiveEdgeEntry" },
{ "gePrimitiveRegisterExternalFill", "B2DPlugin", "primitiveRegisterExternalFill" },
{ "gePrimitiveGetDepth", "B2DPlugin", "primitiveGetDepth" },
{ "gePrimitiveSetEdgeTransform", "B2DPlugin", "primitiveSetEdgeTransform" },
{ "gePrimitiveNeedsFlushPut", "B2DPlugin", "primitiveNeedsFlushPut" },
{ "primitiveFloatArrayAt", "FloatArrayPlugin", "primitiveAt" },
{ "primitiveFloatArrayMulFloatArray", "FloatArrayPlugin", "primitiveMulFloatArray" },
{ "primitiveFloatArrayAddScalar", "FloatArrayPlugin", "primitiveAddScalar" },
{ "primitiveFloatArrayDivFloatArray", "FloatArrayPlugin", "primitiveDivFloatArray" },
{ "primitiveFloatArrayDivScalar", "FloatArrayPlugin", "primitiveDivScalar" },
{ "primitiveFloatArrayHash", "FloatArrayPlugin", "primitiveHashArray" },
{ "primitiveFloatArrayAtPut", "FloatArrayPlugin", "primitiveAtPut" },
{ "primitiveFloatArrayMulScalar", "FloatArrayPlugin", "primitiveMulScalar" },
{ "primitiveFloatArrayAddFloatArray", "FloatArrayPlugin", "primitiveAddFloatArray" },
{ "primitiveFloatArraySubScalar", "FloatArrayPlugin", "primitiveSubScalar" },
{ "primitiveFloatArraySubFloatArray", "FloatArrayPlugin", "primitiveSubFloatArray" },
{ "primitiveFloatArrayEqual", "FloatArrayPlugin", "primitiveEqual" },
{ "primitiveFloatArrayDotProduct", "FloatArrayPlugin", "primitiveDotProduct" },
{ "m23PrimitiveInvertRectInto", "Matrix2x3Plugin", "primitiveInvertRectInto" },
{ "m23PrimitiveTransformPoint", "Matrix2x3Plugin", "primitiveTransformPoint" },
{ "m23PrimitiveIsPureTranslation", "Matrix2x3Plugin", "primitiveIsPureTranslation" },
{ "m23PrimitiveComposeMatrix", "Matrix2x3Plugin", "primitiveComposeMatrix" },
{ "m23PrimitiveTransformRectInto", "Matrix2x3Plugin", "primitiveTransformRectInto" },
{ "m23PrimitiveIsIdentity", "Matrix2x3Plugin", "primitiveIsIdentity" },
{ "m23PrimitiveInvertPoint", "Matrix2x3Plugin", "primitiveInvertPoint" },
{ "primitiveDeflateBlock", "ZipPlugin", "primitiveDeflateBlock" },
{ "primitiveDeflateUpdateHashTable", "ZipPlugin", "primitiveDeflateUpdateHashTable" },
{ "primitiveUpdateGZipCrc32", "ZipPlugin", "primitiveUpdateGZipCrc32" },
{ "primitiveInflateDecompressBlock", "ZipPlugin", "primitiveInflateDecompressBlock" },
{ "primitiveZipSendBlock", "ZipPlugin", "primitiveZipSendBlock" },
{ "primitiveFFTTransformData", "FFTPlugin", "primitiveFFTTransformData" },
{ "primitiveFFTScaleData", "FFTPlugin", "primitiveFFTScaleData" },
{ "primitiveFFTPermuteData", "FFTPlugin", "primitiveFFTPermuteData" },
{ NULL, NULL, NULL }
};
int parentField;
int pendingFinalizationSignals;
int primitiveIndex;
int receiver;
int receiverClass;
int reclaimableContextCount;
int remapBuffer[26];
int remapBufferCount;
int rootTable[2501];
int rootTableCount;
int savedWindowSize;
int semaphoresToSignalA[501];
int semaphoresToSignalB[501];
int semaphoresToSignalCountA;
int semaphoresToSignalCountB;
int semaphoresUseBufferA;
int showSurfaceFn;
int shrinkThreshold;
int signalLowSpace;
int specialObjectsOop;
int stackPointer;
int statFullGCMSecs;
int statFullGCs;
int statIncrGCMSecs;
int statIncrGCs;
int statRootTableOverflows;
int statTenures;
int successFlag;
int tenuringThreshold;
int theHomeContext;
int totalObjectCount;
int trueObj;
int youngStart;

/*** Function Prototypes ***/
int accessibleObjectAfter(int oop);
int addNewMethodToCache(void);
int allYoungand(int array1, int array2);
int allocateChunk(int byteSize);
int allocateOrRecycleContext(int needsLarge);
int argumentCountOf(int methodPointer);
void * arrayValueOf(int arrayOop);
int asciiOfCharacter(int characterObj);
int balancedStackafterPrimitivewithArgs(int delta, int primIdx, int nArgs);
int beRootIfOld(int oop);
int becomewith(int array1, int array2);
int becomewithtwoWay(int array1, int array2, int twoWayFlag);
int booleanValueOf(int obj);
int byteSizeOf(int oop);
int byteSwapByteObjectsFromto(int startOop, int stopAddr);
int byteSwapped(int w);
int characterForAscii(int ascii);
int characterTable(void);
int checkForInterrupts(void);
int checkImageVersionFromstartingAt(sqImageFile f, squeakFileOffsetType imageOffset);
int checkedIntegerValueOf(int intOop);
int checkedLongAt(int byteAddress);
int classArray(void);
int classBitmap(void);
int classByteArray(void);
int classCharacter(void);
int classExternalAddress(void);
int classExternalData(void);
int classExternalFunction(void);
int classExternalLibrary(void);
int classExternalStructure(void);
int classFloat(void);
int classLargeNegativeInteger(void);
int classLargePositiveInteger(void);
int classNameOfIs(int aClass, char *className);
int classPoint(void);
int classSemaphore(void);
int classSmallInteger(void);
int classString(void);
int cleanUpContexts(void);
int clone(int oop);
int commonAt(int stringy);
int commonAtPut(int stringy);
int commonVariableatcacheIndex(int rcvr, int index, int atIx);
int compare31or32Bitsequal(int obj1, int obj2);
int compilerCreateActualMessagestoringArgs(int aMessage, int argArray);
int compilerFlushCache(int aCompiledMethod);
int compilerMapFromto(int memStart, int memEnd);
int compilerMark(void);
int compilerPostGC(void);
int compilerPostSnapshot(void);
int compilerPreGC(int fullGCFlag);
int compilerPreSnapshot(void);
int compilerProcessChange(void);
int compilerProcessChangeto(int oldProc, int newProc);
int compilerTranslateMethod(void);
int containOnlyOopsand(int array1, int array2);
int contexthasSender(int thisCntx, int aContext);
int copyBits(void);
int copyBitsFromtoat(int x0, int x1, int y);
int copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(int oop, int segmentWordArray, int lastSeg, int stopAddr, int oopPtr, int hdrPtr);
int createActualMessageTo(int aClass);
int displayBitsOfLeftTopRightBottom(int aForm, int l, int t, int r, int b);
int displayObject(void);
int doPrimitiveDivby(int rcvr, int arg);
int doPrimitiveModby(int rcvr, int arg);
int extraHeaderBytes(int oopOrChunk);
int failed(void);
int falseObject(void);
void * fetchArrayofObject(int fieldIndex, int objectPointer);
int fetchClassOf(int oop);
int fetchClassOfNonInt(int oop);
double fetchFloatofObject(int fieldIndex, int objectPointer);
int fetchIntegerofObject(int fieldIndex, int objectPointer);
int fetchPointerofObject(int fieldIndex, int oop);
int fetchStackPointerOf(int aContext);
int fetchWordofObject(int fieldIndex, int oop);
int finalizeReference(int oop);
int findClassOfMethodforReceiver(int meth, int rcvr);
int findNewMethodInClass(int class);
int findObsoleteNamedPrimitivelength(char * functionName, int functionLength);
int findSelectorOfMethodforReceiver(int meth, int rcvr);
int firstAccessibleObject(void);
void * firstFixedField(int oop);
void * firstIndexableField(int oop);
int floatObjectOf(double aFloat);
double floatValueOf(int oop);
int flushExternalPrimitives(void);
int fullDisplayUpdate(void);
int fullGC(void);
int fwdTableInit(int blkSize);
int fwdTableSize(int blkSize);
int getCurrentBytecode(void);
int getLongFromFileswap(sqImageFile f, int swapFlag);
int imageSegmentVersion(void);
int incCompBody(void);
int includesBehaviorThatOf(int aClass, int aSuperclass);
int incrementalGC(void);
int initCompilerHooks(void);
int initializeMemoryFirstFree(int firstFree);
int initializeObjectMemory(int bytesToShift);
int installinAtCacheatstring(int rcvr, int *cache, int atIx, int stringy);
int instantiateClassindexableSize(int classPointer, int size);
int instantiateContextsizeInBytes(int classPointer, int sizeInBytes);
int instantiateSmallClasssizeInBytesfill(int classPointer, int sizeInBytes, int fillValue);
int integerObjectOf(int value);
int integerValueOf(int objectPointer);
int interpret(void);
int isKindOf(int oop, char *className);
int isMemberOf(int oop, char *className);
int isBytes(int oop);
int isContextHeader(int aHeader);
int isFloatObject(int oop);
int isHandlerMarked(int aContext);
int isInMemory(int address);
int isIndexable(int oop);
int isIntegerObject(int objectPointer);
int isIntegerValue(int intValue);
int isPointers(int oop);
int isUnwindMarked(int aContext);
int isWeak(int oop);
int isWords(int oop);
int isWordsOrBytes(int oop);
int lastPointerOf(int oop);
int lengthOf(int oop);
int literalofMethod(int offset, int methodPointer);
int literalCountOf(int methodPointer);
int loadBitBltFrom(int bb);
double loadFloatOrIntFrom(int floatOrInt);
int loadInitialContext(void);
int lookupMethodInClass(int class);
int lowestFreeAfter(int chunk);
int makePointwithxValueyValue(int xValue, int yValue);
int mapPointersInObjectsFromto(int memStart, int memEnd);
int markAndTrace(int oop);
int markAndTraceInterpreterOops(void);
int markPhase(void);
int methodArgumentCount(void);
int methodPrimitiveIndex(void);
#pragma export on
EXPORT(int) moduleUnloaded(char * aModuleName);
#pragma export off
int nilObject(void);
int nonWeakFieldsOf(int oop);
int noteAsRootheaderLoc(int oop, int headerLoc);
int nullCompilerHook(void);
int objectAfter(int oop);
int okayFields(int oop);
int okayOop(int oop);
int oopFromChunk(int chunk);
int oopHasOKclass(int oop);
int oopHasOkayClass(int oop);
int pop(int nItems);
int popthenPush(int nItems, int oop);
double popFloat(void);
int popRemappableOop(void);
int popStack(void);
int positive32BitIntegerFor(int integerValue);
int positive32BitValueOf(int oop);
int positive64BitIntegerFor(squeakInt64 integerValue);
squeakInt64 positive64BitValueOf(int oop);
int possibleRootStoreIntovalue(int oop, int valueObj);
int prepareForwardingTableForBecomingwithtwoWay(int array1, int array2, int twoWayFlag);
int primitiveAdd(void);
int primitiveArctan(void);
int primitiveArrayBecome(void);
int primitiveArrayBecomeOneWay(void);
int primitiveAsFloat(void);
int primitiveAsOop(void);
int primitiveAt(void);
int primitiveAtEnd(void);
int primitiveAtPut(void);
int primitiveBeCursor(void);
int primitiveBeDisplay(void);
int primitiveBeep(void);
int primitiveBitAnd(void);
int primitiveBitOr(void);
int primitiveBitShift(void);
int primitiveBitXor(void);
int primitiveBlockCopy(void);
int primitiveBytesLeft(void);
int primitiveCalloutToFFI(void);
int primitiveChangeClass(void);
int primitiveClass(void);
int primitiveClipboardText(void);
int primitiveClone(void);
int primitiveConstantFill(void);
int primitiveDeferDisplayUpdates(void);
#pragma export on
EXPORT(int) primitiveDisablePowerManager(void);
#pragma export off
int primitiveDiv(void);
int primitiveDivide(void);
int primitiveDoPrimitiveWithArgs(void);
int primitiveEqual(void);
int primitiveEquivalent(void);
int primitiveExitToDebugger(void);
int primitiveExp(void);
int primitiveExponent(void);
int primitiveExternalCall(void);
int primitiveFail(void);
int primitiveFindHandlerContext(void);
int primitiveFindNextUnwindContext(void);
int primitiveFloatAdd(void);
int primitiveFloatAddtoArg(int rcvrOop, int argOop);
int primitiveFloatDivide(void);
int primitiveFloatDividebyArg(int rcvrOop, int argOop);
int primitiveFloatEqual(void);
int primitiveFloatEqualtoArg(int rcvrOop, int argOop);
int primitiveFloatGreaterthanArg(int rcvrOop, int argOop);
int primitiveFloatGreaterOrEqual(void);
int primitiveFloatGreaterThan(void);
int primitiveFloatLessthanArg(int rcvrOop, int argOop);
int primitiveFloatLessOrEqual(void);
int primitiveFloatLessThan(void);
int primitiveFloatMultiply(void);
int primitiveFloatMultiplybyArg(int rcvrOop, int argOop);
int primitiveFloatNotEqual(void);
int primitiveFloatSubtract(void);
int primitiveFloatSubtractfromArg(int rcvrOop, int argOop);
int primitiveFlushCache(void);
int primitiveFlushCacheByMethod(void);
int primitiveFlushCacheSelective(void);
int primitiveFlushExternalPrimitives(void);
int primitiveForceDisplayUpdate(void);
int primitiveFormPrint(void);
int primitiveFractionalPart(void);
int primitiveFullGC(void);
int primitiveGetAttribute(void);
int primitiveGetNextEvent(void);
int primitiveGreaterOrEqual(void);
int primitiveGreaterThan(void);
int primitiveImageName(void);
int primitiveIncrementalGC(void);
int primitiveIndexOf(int methodPointer);
int primitiveInputSemaphore(void);
int primitiveInputWord(void);
int primitiveInstVarAt(void);
int primitiveInstVarAtPut(void);
int primitiveInstVarsPutFromStack(void);
int primitiveIntegerAt(void);
int primitiveIntegerAtPut(void);
int primitiveInterruptSemaphore(void);
int primitiveKbdNext(void);
int primitiveKbdPeek(void);
int primitiveLessOrEqual(void);
int primitiveLessThan(void);
int primitiveListBuiltinModule(void);
int primitiveListExternalModule(void);
int primitiveLoadImageSegment(void);
int primitiveLoadInstVar(void);
int primitiveLogN(void);
int primitiveLowSpaceSemaphore(void);
int primitiveMakePoint(void);
int primitiveMethod(void);
int primitiveMillisecondClock(void);
int primitiveMod(void);
int primitiveMouseButtons(void);
int primitiveMousePoint(void);
int primitiveMultiply(void);
int primitiveNew(void);
int primitiveNewMethod(void);
int primitiveNewWithArg(void);
int primitiveNext(void);
int primitiveNextInstance(void);
int primitiveNextObject(void);
int primitiveNextPut(void);
int primitiveNoop(void);
int primitiveNotEqual(void);
int primitiveObjectAt(void);
int primitiveObjectAtPut(void);
int primitiveObjectPointsTo(void);
int primitiveObsoleteIndexedPrimitive(void);
int primitivePerform(void);
int primitivePerformAt(int lookupClass);
int primitivePerformInSuperclass(void);
int primitivePerformWithArgs(void);
int primitivePointX(void);
int primitivePointY(void);
int primitivePushFalse(void);
int primitivePushMinusOne(void);
int primitivePushNil(void);
int primitivePushOne(void);
int primitivePushSelf(void);
int primitivePushTrue(void);
int primitivePushTwo(void);
int primitivePushZero(void);
int primitiveQuit(void);
int primitiveQuo(void);
int primitiveRelinquishProcessor(void);
int primitiveResponse(void);
int primitiveResume(void);
int primitiveScanCharacters(void);
#pragma export on
EXPORT(int) primitiveScreenDepth(void);
#pragma export off
int primitiveScreenSize(void);
int primitiveSecondsClock(void);
int primitiveSetDisplayMode(void);
int primitiveSetFullScreen(void);
int primitiveSetInterruptKey(void);
int primitiveShortAt(void);
int primitiveShortAtPut(void);
int primitiveShowDisplayRect(void);
int primitiveSignal(void);
int primitiveSignalAtBytesLeft(void);
int primitiveSignalAtMilliseconds(void);
int primitiveSine(void);
int primitiveSize(void);
int primitiveSnapshot(void);
int primitiveSnapshotEmbedded(void);
int primitiveSomeInstance(void);
int primitiveSomeObject(void);
int primitiveSpecialObjectsOop(void);
int primitiveSquareRoot(void);
int primitiveStoreImageSegment(void);
int primitiveStoreStackp(void);
int primitiveStringAt(void);
int primitiveStringAtPut(void);
int primitiveStringReplace(void);
int primitiveSubtract(void);
int primitiveSuspend(void);
int primitiveTerminateTo(void);
int primitiveTestDisplayDepth(void);
int primitiveTimesTwoPower(void);
int primitiveTruncated(void);
int primitiveUnloadModule(void);
int primitiveVMParameter(void);
int primitiveVMPath(void);
int primitiveValue(void);
int primitiveValueWithArgs(void);
int primitiveWait(void);
int print(char *s);
int printAllStacks(void);
int printCallStack(void);
int printCallStackOf(int aContext);
int printNameOfClasscount(int classOop, int cnt);
int printNum(int n);
int printStringOf(int oop);
int printUnbalancedStack(int primIdx);
int printUnbalancedStackFromNamedPrimitive(void);
int push(int object);
int pushBool(int trueOrFalse);
int pushFloat(double f);
int pushInteger(int integerValue);
int pushRemappableOop(int oop);
int putLongtoFile(int n, sqImageFile f);
int readImageFromFileHeapSizeStartingAt(sqImageFile f, int desiredHeapSize, squeakFileOffsetType imageOffset);
int readableFormat(int imageVersion);
int remap(int oop);
int removeFirstLinkOfList(int aList);
int restoreHeadersFromtofromandtofrom(int firstIn, int lastIn, int hdrBaseIn, int firstOut, int lastOut, int hdrBaseOut);
int resume(int aProcess);
int reverseDisplayFromto(int startIndex, int endIndex);
int rewriteMethodCacheSelclassprimIndex(int selector, int class, int localPrimIndex);
int setCompilerInitialized(int newFlag);
int showDisplayBitsLeftTopRightBottom(int aForm, int l, int t, int r, int b);
int signalSemaphoreWithIndex(int index);
int signed32BitIntegerFor(int integerValue);
int signed32BitValueOf(int oop);
int signed64BitIntegerFor(squeakInt64 integerValue);
squeakInt64 signed64BitValueOf(int oop);
int sizeBitsOf(int oop);
int sizeOfSTArrayFromCPrimitive(void *cPtr);
int slotSizeOf(int oop);
int splObj(int index);
int stObjectat(int array, int index);
int stObjectatput(int array, int index, int value);
int stSizeOf(int oop);
double stackFloatValue(int offset);
int stackIntegerValue(int offset);
int stackObjectValue(int offset);
int stackValue(int offset);
int startOfMemory(void);
int storeIntegerofObjectwithValue(int fieldIndex, int objectPointer, int integerValue);
int storePointerofObjectwithValue(int fieldIndex, int oop, int valuePointer);
int success(int successValue);
int sufficientSpaceAfterGC(int minFree);
int superclassOf(int classPointer);
int sweepPhase(void);
int synchronousSignal(int aSemaphore);
int transferTo(int aProc);
int trueObject(void);
int verifyCleanHeaders(void);
int wakeHighestPriority(void);
int writeImageFile(int imageBytes);
int writeImageFileIO(int imageBytes);


/*	Return the accessible object following the given object or free chunk in the heap. Return nil when heap is exhausted. */

int accessibleObjectAfter(int oop) {
    int obj;
    int sz;
    int extra;
    int header;
    int extra1;
    int type;
    int sz1;
    int extra2;
    int header1;
    int extra11;
    int type1;

	/* begin objectAfter: */
	;
	if (((longAt(oop)) & 3) == 2) {
		sz1 = (longAt(oop)) & 4294967292U;
	} else {
		/* begin sizeBitsOf: */
		header1 = longAt(oop);
		if ((header1 & 3) == 0) {
			sz1 = (longAt(oop - 8)) & 4294967292U;
			goto l2;
		} else {
			sz1 = header1 & 252;
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
	}
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type1 = (longAt(oop + sz1)) & 3;
	if (type1 > 1) {
		extra11 = 0;
	} else {
		if (type1 == 1) {
			extra11 = 4;
		} else {
			extra11 = 8;
		}
	}
	extra2 = extra11;
	obj = (oop + sz1) + extra2;
	while (obj < endOfMemory) {
		if (!(((longAt(obj)) & 3) == 2)) {
			return obj;
		}
		/* begin objectAfter: */
		;
		if (((longAt(obj)) & 3) == 2) {
			sz = (longAt(obj)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & 3) == 0) {
				sz = (longAt(obj - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type = (longAt(obj + sz)) & 3;
		if (type > 1) {
			extra1 = 0;
		} else {
			if (type == 1) {
				extra1 = 4;
			} else {
				extra1 = 8;
			}
		}
		extra = extra1;
		obj = (obj + sz) + extra;
	}
	return null;
}


/*	Add the given entry to the method cache.
	The policy is as follows:
		Look for an empty entry anywhere in the reprobe chain.
		If found, install the new entry there.
		If not found, then install the new entry at the first probe position
			and delete the entries in the rest of the reprobe chain.
		This has two useful purposes:
			If there is active contention over the first slot, the second
				or third will likely be free for reentry after ejection.
			Also, flushing is good when reprobe chains are getting full. */

int addNewMethodToCache(void) {
    int hash;
    int probe;
    int p;

	compilerInitialized && (compilerTranslateMethod());

	/* drop low-order zeros from addresses */

	hash = messageSelector ^ lkupClass;
	for (p = 0; p <= (3 - 1); p += 1) {
		probe = (((unsigned) hash) >> p) & 4088;
		if ((methodCache[probe + 1]) == 0) {
			methodCache[probe + 1] = messageSelector;
			methodCache[probe + 2] = lkupClass;
			methodCache[probe + 3] = newMethod;
			methodCache[probe + 4] = primitiveIndex;
			methodCache[probe + 5] = newNativeMethod;
			return null;
		}
	}

	/* first probe */

	probe = hash & 4088;
	methodCache[probe + 1] = messageSelector;
	methodCache[probe + 2] = lkupClass;
	methodCache[probe + 3] = newMethod;
	methodCache[probe + 4] = primitiveIndex;
	methodCache[probe + 5] = newNativeMethod;
	for (p = 1; p <= (3 - 1); p += 1) {
		probe = (((unsigned) hash) >> p) & 4088;
		methodCache[probe + 1] = 0;
	}
}


/*	Return true if all the oops in both arrays, and the arrays themselves, are in the young object space. */

int allYoungand(int array1, int array2) {
    int fieldOffset;
    int header;
    int fmt;
    int methodHeader;
    int sz;
    int header1;
    int type;

	if (array1 < youngStart) {
		return 0;
	}
	if (array2 < youngStart) {
		return 0;
	}
	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((unsigned) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && (isContextHeader(header))) {
			fieldOffset = (6 + (fetchStackPointerOf(array1))) * 4;
			goto l1;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & 252) == 0) {
			type = 0;
			goto l2;
		} else {
			if ((header1 & 126976) == 0) {
				type = 1;
				goto l2;
			} else {
				type = 3;
				goto l2;
			}
		}
	l2:	/* end rightType: */;
		if (type == 0) {
			sz = (longAt(array1 - 8)) & 4294967292U;
			goto l3;
		} else {
			sz = header1 & 252;
			goto l3;
		}
	l3:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - 4;
		goto l1;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l1;
	}
	methodHeader = longAt(array1 + 4);
	fieldOffset = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
l1:	/* end lastPointerOf: */;
	while (fieldOffset >= 4) {
		if ((longAt(array1 + fieldOffset)) < youngStart) {
			return 0;
		}
		if ((longAt(array2 + fieldOffset)) < youngStart) {
			return 0;
		}
		fieldOffset -= 4;
	}
	return 1;
}


/*	Allocate a chunk of the given size. Sender must be sure that the requested size includes enough space for the header word(s). */
/*	Details: To limit the time per incremental GC, do one every so many allocations. */

int allocateChunk(int byteSize) {
    int enoughSpace;
    int newChunk;
    int newFreeSize;
    int minFree;

	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + byteSize) + 4;
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;

		/* disable additional interrupts until lowSpaceThreshold is reset by image */

		lowSpaceThreshold = 0;
		interruptCheckCounter = 0;
	}
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) < (((unsigned ) (byteSize + 4)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & 4294967292U) - byteSize;
	newChunk = freeBlock;

	/* Assume: client will initialize object header of free chunk, so following is not needed: */
	/* self setSizeOfFree: newChunk to: byteSize. */

	freeBlock += byteSize;
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & 4294967292U) | 2);
	allocationCount += 1;
	return newChunk;
}


/*	Return a recycled context or a newly allocated one if none is available for recycling. */

int allocateOrRecycleContext(int needsLarge) {
    int cntxt;

	if (needsLarge == 0) {
		if (freeContexts != 1) {
			cntxt = freeContexts;
			freeContexts = longAt(((((char *) cntxt)) + 4) + (0 << 2));
			return cntxt;
		}
	} else {
		if (freeLargeContexts != 1) {
			cntxt = freeLargeContexts;
			freeLargeContexts = longAt(((((char *) cntxt)) + 4) + (0 << 2));
			return cntxt;
		}
	}
	if (needsLarge == 0) {
		cntxt = instantiateContextsizeInBytes(longAt(((((char *) specialObjectsOop)) + 4) + (10 << 2)), 92);
	} else {
		cntxt = instantiateContextsizeInBytes(longAt(((((char *) specialObjectsOop)) + 4) + (10 << 2)), 252);
	}
	longAtput(((((char *) cntxt)) + 4) + (4 << 2), nilObj);
	return cntxt;
}

int argumentCountOf(int methodPointer) {
	return (((unsigned) (longAt(((((char *) methodPointer)) + 4) + (0 << 2)))) >> 25) & 15;
}


/*	Return the address of first indexable field of resulting array object, or fail if the instance variable does not contain an indexable bytes or words object. */
/*	Note: May be called by translated primitive code. */

void * arrayValueOf(int arrayOop) {
	if ((!((arrayOop & 1))) && (isWordsOrBytes(arrayOop))) {
		return (void *) (arrayOop + 4);
	}
	/* begin primitiveFail */
	successFlag = 0;
}


/*	Returns an integer object */

int asciiOfCharacter(int characterObj) {
    int cl;
    int ccIndex;

	/* begin assertClassOf:is: */
	if ((characterObj & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(characterObj))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(characterObj - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (19 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		return longAt(((((char *) characterObj)) + 4) + (0 << 2));
	} else {
		return 1;
	}
}


/*	Return true if the stack is still balanced after executing primitive primIndex with nArgs args. Delta is 'stackPointer - activeContext' which is a relative measure for the stack pointer (so we don't have to relocate it during the primitive) */

int balancedStackafterPrimitivewithArgs(int delta, int primIdx, int nArgs) {
	if ((primIdx >= 81) && (primIdx <= 88)) {
		return 1;
	}
	if (successFlag) {
		return ((stackPointer - activeContext) + (nArgs * 4)) == delta;
	}
	return (stackPointer - activeContext) == delta;
}


/*	If this object is old, mark it as a root (because a new object may be stored into it) */

int beRootIfOld(int oop) {
    int header;

	if ((oop < youngStart) && (!((oop & 1)))) {
		/* begin noteAsRoot:headerLoc: */
		header = longAt(oop);
		if ((header & 1073741824) == 0) {
			if (rootTableCount < 2500) {
				rootTableCount += 1;
				rootTable[rootTableCount] = oop;
				longAtput(oop, header | 1073741824);
			}
		}
	}
}

int becomewith(int array1, int array2) {
	return becomewithtwoWay(array1, array2, 1);
}


/*	All references to each object in array1 are swapped with all references to the corresponding object in array2. That is, all pointers to one object are replaced with with pointers to the other. The arguments must be arrays of the same length. Returns true if the primitive succeeds. */
/*	Implementation: Uses forwarding blocks to update references as done in compaction. */

int becomewithtwoWay(int array1, int array2, int twoWayFlag) {
    int oop1;
    int oop2;
    int hdr1;
    int hdr2;
    int fieldOffset;
    int fwdBlock;
    int fwdHeader;
    int fwdBlock1;
    int fwdHeader1;
    int oop11;
    int oop21;
    int hdr11;
    int fwdBlock2;
    int hdr21;
    int fwdBlock11;
    int fwdHeader2;
    int header;
    int fmt;
    int methodHeader;
    int sz;
    int header1;
    int type;

	if (!((fetchClassOf(array1)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2))))) {
		return 0;
	}
	if (!((fetchClassOf(array2)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2))))) {
		return 0;
	}
	if (!((lastPointerOf(array1)) == (lastPointerOf(array2)))) {
		return 0;
	}
	if (!(containOnlyOopsand(array1, array2))) {
		return 0;
	}
	if (!(prepareForwardingTableForBecomingwithtwoWay(array1, array2, twoWayFlag))) {
		return 0;
	}
	if (allYoungand(array1, array2)) {
		mapPointersInObjectsFromto(youngStart, endOfMemory);
	} else {
		mapPointersInObjectsFromto(startOfMemory(), endOfMemory);
	}
	if (twoWayFlag) {
		/* begin restoreHeadersAfterBecoming:with: */
		/* begin lastPointerOf: */
		header = longAt(array1);
		fmt = (((unsigned) header) >> 8) & 15;
		if (fmt <= 4) {
			if ((fmt == 3) && (isContextHeader(header))) {
				fieldOffset = (6 + (fetchStackPointerOf(array1))) * 4;
				goto l3;
			}
			/* begin sizeBitsOfSafe: */
			header1 = longAt(array1);
			/* begin rightType: */
			if ((header1 & 252) == 0) {
				type = 0;
				goto l1;
			} else {
				if ((header1 & 126976) == 0) {
					type = 1;
					goto l1;
				} else {
					type = 3;
					goto l1;
				}
			}
		l1:	/* end rightType: */;
			if (type == 0) {
				sz = (longAt(array1 - 8)) & 4294967292U;
				goto l2;
			} else {
				sz = header1 & 252;
				goto l2;
			}
		l2:	/* end sizeBitsOfSafe: */;
			fieldOffset = sz - 4;
			goto l3;
		}
		if (fmt < 12) {
			fieldOffset = 0;
			goto l3;
		}
		methodHeader = longAt(array1 + 4);
		fieldOffset = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
	l3:	/* end lastPointerOf: */;
		while (fieldOffset >= 4) {
			oop1 = longAt(array1 + fieldOffset);
			oop2 = longAt(array2 + fieldOffset);
			/* begin restoreHeaderOf: */
			fwdHeader = longAt(oop1);
			fwdBlock = (fwdHeader & 2147483644) << 1;
			;
			longAtput(oop1, longAt(fwdBlock + 4));
			/* begin restoreHeaderOf: */
			fwdHeader1 = longAt(oop2);
			fwdBlock1 = (fwdHeader1 & 2147483644) << 1;
			;
			longAtput(oop2, longAt(fwdBlock1 + 4));
			hdr1 = longAt(oop1);
			hdr2 = longAt(oop2);
			longAtput(oop1, (hdr1 & 3758227455U) | (hdr2 & 536739840));
			longAtput(oop2, (hdr2 & 3758227455U) | (hdr1 & 536739840));
			fieldOffset -= 4;
		}
	} else {
		/* begin restoreHeadersAfterForwardBecome */
		fwdBlock2 = ((endOfMemory + 4) + 7) & 4294967288U;
		fwdBlock2 += 16;
		while (fwdBlock2 <= fwdTableNext) {
			oop11 = longAt(fwdBlock2 + 8);
			oop21 = longAt(fwdBlock2);
			/* begin restoreHeaderOf: */
			fwdHeader2 = longAt(oop11);
			fwdBlock11 = (fwdHeader2 & 2147483644) << 1;
			;
			longAtput(oop11, longAt(fwdBlock11 + 4));
			hdr11 = longAt(oop11);
			hdr21 = longAt(oop21);
			longAtput(oop21, (hdr21 & 3758227455U) | (hdr11 & 536739840));
			fwdBlock2 += 16;
		}
	}
	initializeMemoryFirstFree(freeBlock);
	return 1;
}

int booleanValueOf(int obj) {
	if (obj == trueObj) {
		return 1;
	}
	if (obj == falseObj) {
		return 0;
	}
	successFlag = 0;
	return null;
}

int byteSizeOf(int oop) {
    int slots;
    int header;
    int sz;

	if ((oop & 1)) {
		return 0;
	}
	/* begin slotSizeOf: */
	if ((oop & 1)) {
		slots = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		slots = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		slots = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
	slots = null;
l2:	/* end lengthOf: */;
l1:	/* end slotSizeOf: */;
	if (((((unsigned) (longAt(oop))) >> 8) & 15) >= 8) {
		return slots;
	} else {
		return slots * 4;
	}
}


/*	Byte-swap the words of all bytes objects in a range of the image, including Strings, ByteArrays, and CompiledMethods. This returns these objects to their original byte ordering after blindly byte-swapping the entire image. For compiled methods, byte-swap only their bytecodes part. */

int byteSwapByteObjectsFromto(int startOop, int stopAddr) {
    int oop;
    int wordAddr;
    int fmt;
    int methodHeader;
    int stopAddr1;
    int addr;
    int sz;
    int extra;
    int header;
    int extra1;
    int type;

	oop = startOop;
	while (oop < stopAddr) {
		if (!(((longAt(oop)) & 3) == 2)) {
			fmt = (((unsigned) (longAt(oop))) >> 8) & 15;
			if (fmt >= 8) {
				wordAddr = oop + 4;
				if (fmt >= 12) {
					methodHeader = longAt(oop + 4);
					wordAddr = (wordAddr + 4) + (((((unsigned) methodHeader) >> 10) & 255) * 4);
				}
				/* begin reverseBytesFrom:to: */
				stopAddr1 = oop + (sizeBitsOf(oop));
				addr = wordAddr;
				while (addr < stopAddr1) {
					longAtput(addr, ((((((unsigned) (longAt(addr)) >> 24)) & 255) + ((((unsigned) (longAt(addr)) >> 8)) & 65280)) + ((((unsigned) (longAt(addr)) << 8)) & 16711680)) + ((((unsigned) (longAt(addr)) << 24)) & 4278190080U));
					addr += 4;
				}
			}
		}
		/* begin objectAfter: */
		;
		if (((longAt(oop)) & 3) == 2) {
			sz = (longAt(oop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & 3) == 0) {
				sz = (longAt(oop - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type = (longAt(oop + sz)) & 3;
		if (type > 1) {
			extra1 = 0;
		} else {
			if (type == 1) {
				extra1 = 4;
			} else {
				extra1 = 8;
			}
		}
		extra = extra1;
		oop = (oop + sz) + extra;
	}
}


/*	Return the given integer with its bytes in the reverse order. */

int byteSwapped(int w) {
	return ((((((unsigned) w >> 24)) & 255) + ((((unsigned) w >> 8)) & 65280)) + ((((unsigned) w << 8)) & 16711680)) + ((((unsigned) w << 24)) & 4278190080U);
}


/*	Arg must lie in range 0-255! */

int characterForAscii(int ascii) {
	return longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (24 << 2))))) + 4) + (ascii << 2));
}

int characterTable(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (24 << 2));
}


/*	Check for possible interrupts and handle one if necessary. */

int checkForInterrupts(void) {
    int now;
    int sema;
    int xArray;
    int i;
    int sema1;
    int index;
    int xSize;
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int sp;
    int sz;
    int classFormat;
    int class;
    int ccIndex;

	now = (ioMSecs()) & 536870911;
	if (now < lastTick) {
		nextPollTick = now + (nextPollTick - lastTick);
		if (nextWakeupTick != 0) {
			nextWakeupTick = now + (nextWakeupTick - lastTick);
		}
	}
	if ((now - lastTick) < interruptChecksEveryNms) {
		interruptCheckCounterFeedBackReset += 10;
	} else {
		if (interruptCheckCounterFeedBackReset <= 1000) {
			interruptCheckCounterFeedBackReset = 1000;
		} else {
			interruptCheckCounterFeedBackReset -= 12;
		}
	}

	/* reset the interrupt check counter */

	interruptCheckCounter = interruptCheckCounterFeedBackReset;

	/* used to detect millisecond clock wrapping */

	lastTick = now;
	if (signalLowSpace) {

		/* reset flag */

		signalLowSpace = 0;
		sema = longAt(((((char *) specialObjectsOop)) + 4) + (17 << 2));
		if (!(sema == nilObj)) {
			synchronousSignal(sema);
		}
	}
	if (now >= nextPollTick) {
		ioProcessEvents();
		nextPollTick = now + 500;
	}
	if (interruptPending) {

		/* reset interrupt flag */

		interruptPending = 0;
		sema = longAt(((((char *) specialObjectsOop)) + 4) + (30 << 2));
		if (!(sema == nilObj)) {
			synchronousSignal(sema);
		}
	}
	if ((nextWakeupTick != 0) && (now >= nextWakeupTick)) {

		/* reset timer interrupt */

		nextWakeupTick = 0;
		sema = longAt(((((char *) specialObjectsOop)) + 4) + (29 << 2));
		if (!(sema == nilObj)) {
			synchronousSignal(sema);
		}
	}
	if (pendingFinalizationSignals > 0) {
		sema = longAt(((((char *) specialObjectsOop)) + 4) + (41 << 2));
		if ((fetchClassOf(sema)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
			synchronousSignal(sema);
		}
		pendingFinalizationSignals = 0;
	}
	if ((semaphoresToSignalCountA > 0) || (semaphoresToSignalCountB > 0)) {
		/* begin signalExternalSemaphores */
		semaphoresUseBufferA = !semaphoresUseBufferA;
		xArray = longAt(((((char *) specialObjectsOop)) + 4) + (38 << 2));
		/* begin stSizeOf: */
		hdr = longAt(xArray);
		fmt = (((unsigned) hdr) >> 8) & 15;
		/* begin lengthOf:baseHeader:format: */
		if ((hdr & 3) == 0) {
			sz = (longAt(xArray - 8)) & 4294967292U;
		} else {
			sz = hdr & 252;
		}
		if (fmt < 8) {
			totalLength = ((unsigned) (sz - 4)) >> 2;
			goto l1;
		} else {
			totalLength = (sz - 4) - (fmt & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l2;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l2;
		}
		/* begin fetchClassOf: */
		if ((xArray & 1)) {
			class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l3;
		}
		ccIndex = (((unsigned) (longAt(xArray))) >> 12) & 31;
		if (ccIndex == 0) {
			class = (longAt(xArray - 4)) & 4294967292U;
			goto l3;
		} else {
			class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
			goto l3;
		}
	l3:	/* end fetchClassOf: */;
		classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
		fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
	l2:	/* end fixedFieldsOf:format:length: */;
		if ((fmt == 3) && (isContextHeader(hdr))) {
			/* begin fetchStackPointerOf: */
			sp = longAt(((((char *) xArray)) + 4) + (2 << 2));
			if (!((sp & 1))) {
				xSize = 0;
				goto l4;
			}
			xSize = (sp >> 1);
			goto l4;
		} else {
			xSize = totalLength - fixedFields;
			goto l4;
		}
	l4:	/* end stSizeOf: */;
		if (semaphoresUseBufferA) {
			for (i = 1; i <= semaphoresToSignalCountB; i += 1) {
				index = semaphoresToSignalB[i];
				if (index <= xSize) {
					sema1 = longAt(((((char *) xArray)) + 4) + ((index - 1) << 2));
					if ((fetchClassOf(sema1)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
						synchronousSignal(sema1);
					}
				}
			}
			semaphoresToSignalCountB = 0;
		} else {
			for (i = 1; i <= semaphoresToSignalCountA; i += 1) {
				index = semaphoresToSignalA[i];
				if (index <= xSize) {
					sema1 = longAt(((((char *) xArray)) + 4) + ((index - 1) << 2));
					if ((fetchClassOf(sema1)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
						synchronousSignal(sema1);
					}
				}
			}
			semaphoresToSignalCountA = 0;
		}
	}
}


/*	Read and verify the image file version number and return true if the the given image file needs to be byte-swapped. As a side effect, position the file stream just after the version number of the image header. This code prints a warning and does a hard-exit if it cannot find a valid version number. */
/*	This code is based on C code by Ian Piumarta. */

int checkImageVersionFromstartingAt(sqImageFile f, squeakFileOffsetType imageOffset) {
    int version;
    int firstVersion;

	sqImageFileSeek(f, imageOffset);
	version = firstVersion = getLongFromFileswap(f, 0);
	if (version == 6502) {
		return 0;
	}
	sqImageFileSeek(f, imageOffset);
	version = getLongFromFileswap(f, 1);
	if (version == 6502) {
		return 1;
	}
	if (imageOffset == 0) {
		sqImageFileSeek(f, 512);
		version = getLongFromFileswap(f, 0);
		if (version == 6502) {
			return 0;
		}
		sqImageFileSeek(f, 512);
		version = getLongFromFileswap(f, 1);
		if (version == 6502) {
			return 1;
		}
	}
	print("This interpreter (vers. ");
	printNum(6502);
	print(" cannot read image file (vers. ");
	printNum(firstVersion);
	/* begin cr */
	printf("\n");
	print("Hit CR to quit");
//	getchar();
	ioExit();
}


/*	Note: May be called by translated primitive code. */

int checkedIntegerValueOf(int intOop) {
	if ((intOop & 1)) {
		return (intOop >> 1);
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
}


/*	Assumes zero-based array indexing. For testing in Smalltalk, this method should be overridden in a subclass. */

int checkedLongAt(int byteAddress) {
	/* begin checkAddress: */
	if (byteAddress < (startOfMemory())) {
		error("bad address: negative");
	}
	if (byteAddress >= memoryLimit) {
		error("bad address: past end of heap");
	}
	/* begin checkAddress: */
	if ((byteAddress + 3) < (startOfMemory())) {
		error("bad address: negative");
	}
	if ((byteAddress + 3) >= memoryLimit) {
		error("bad address: past end of heap");
	}
	return longAt(byteAddress);
}

int classArray(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2));
}

int classBitmap(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2));
}

int classByteArray(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (26 << 2));
}

int classCharacter(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (19 << 2));
}

int classExternalAddress(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (43 << 2));
}

int classExternalData(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (45 << 2));
}

int classExternalFunction(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (46 << 2));
}

int classExternalLibrary(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (47 << 2));
}

int classExternalStructure(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (44 << 2));
}

int classFloat(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2));
}

int classLargeNegativeInteger(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (42 << 2));
}

int classLargePositiveInteger(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2));
}


/*	Check if aClass' name is className */

int classNameOfIs(int aClass, char *className) {
    int length;
    int i;
    int name;
    char *srcName;
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int sp;
    int sz;
    int classFormat;
    int class;
    int ccIndex;

	if ((lengthOf(aClass)) <= 6) {
		return 0;
	}
	name = longAt(((((char *) aClass)) + 4) + (6 << 2));
	if (!(((((unsigned) (longAt(name))) >> 8) & 15) >= 8)) {
		return 0;
	}
	/* begin stSizeOf: */
	hdr = longAt(name);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(name - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l1;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l2;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l2;
	}
	/* begin fetchClassOf: */
	if ((name & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(name))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(name - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l2:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) name)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l4;
		}
		length = (sp >> 1);
		goto l4;
	} else {
		length = totalLength - fixedFields;
		goto l4;
	}
l4:	/* end stSizeOf: */;
	srcName = ((char *) (arrayValueOf(name)));
	for (i = 0; i <= (length - 1); i += 1) {
		if (!((srcName[i]) == (className[i]))) {
			return 0;
		}
	}
	return (className[length]) == 0;
}

int classPoint(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2));
}

int classSemaphore(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2));
}

int classSmallInteger(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
}

int classString(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2));
}


/*	Sweep memory, nilling out all fields of contexts above the stack pointer. */

int cleanUpContexts(void) {
    int header;
    int i;
    int oop;
    int fmt;
    int sz;
    int header1;
    int chunk;
    int extra;
    int extra1;
    int type;
    int sz1;
    int extra2;
    int header2;
    int extra11;
    int type1;

	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	oop = chunk + extra;
	while (oop < endOfMemory) {
		if (!(((longAt(oop)) & 3) == 2)) {
			header = longAt(oop);
			fmt = (((unsigned) header) >> 8) & 15;
			if ((fmt == 3) && (isContextHeader(header))) {
				/* begin sizeBitsOf: */
				header1 = longAt(oop);
				if ((header1 & 3) == 0) {
					sz = (longAt(oop - 8)) & 4294967292U;
					goto l1;
				} else {
					sz = header1 & 252;
					goto l1;
				}
			l1:	/* end sizeBitsOf: */;
				for (i = ((lastPointerOf(oop)) + 4); i <= (sz - 4); i += 4) {
					longAtput(oop + i, nilObj);
				}
			}
		}
		/* begin objectAfter: */
		;
		if (((longAt(oop)) & 3) == 2) {
			sz1 = (longAt(oop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header2 = longAt(oop);
			if ((header2 & 3) == 0) {
				sz1 = (longAt(oop - 8)) & 4294967292U;
				goto l2;
			} else {
				sz1 = header2 & 252;
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(oop + sz1)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		oop = (oop + sz1) + extra2;
	}
}


/*	Return a shallow copy of the given object. */
/*	Assume: Oop is a real object, not a small integer. */

int clone(int oop) {
    int extraHdrBytes;
    int fromIndex;
    int toIndex;
    int header;
    int newOop;
    int newChunk;
    int hash;
    int lastFrom;
    int bytes;
    int remappedOop;
    int oop1;
    int extra;
    int type;
    int header1;
    int enoughSpace;
    int newChunk1;
    int newFreeSize;
    int minFree;

	/* begin extraHeaderBytes: */
	type = (longAt(oop)) & 3;
	if (type > 1) {
		extra = 0;
	} else {
		if (type == 1) {
			extra = 4;
		} else {
			extra = 8;
		}
	}
	extraHdrBytes = extra;
	/* begin sizeBitsOf: */
	header1 = longAt(oop);
	if ((header1 & 3) == 0) {
		bytes = (longAt(oop - 8)) & 4294967292U;
		goto l1;
	} else {
		bytes = header1 & 252;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;

	/* allocate space for the copy, remapping oop in case of a GC */

	bytes += extraHdrBytes;
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = oop;
	/* begin allocateChunk: */
	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + bytes) + 4;
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
		enoughSpace = 1;
		goto l2;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l2;
	}
l2:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;
		lowSpaceThreshold = 0;
		interruptCheckCounter = 0;
	}
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) < (((unsigned ) (bytes + 4)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & 4294967292U) - bytes;
	newChunk1 = freeBlock;
	freeBlock += bytes;
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & 4294967292U) | 2);
	allocationCount += 1;
	newChunk = newChunk1;
	/* begin popRemappableOop */
	oop1 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	remappedOop = oop1;

	/* loop below uses pre-increment */

	toIndex = newChunk - 4;
	fromIndex = (remappedOop - extraHdrBytes) - 4;
	lastFrom = fromIndex + bytes;
	while (fromIndex < lastFrom) {
		longAtput(toIndex += 4, longAt(fromIndex += 4));
	}

	/* convert from chunk to oop */
	/* fix base header: compute new hash and clear Mark and Root bits */

	newOop = newChunk + extraHdrBytes;
	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;

	/* use old ccIndex, format, size, and header-type fields */

	header = (longAt(newOop)) & 131071;
	header = header | ((hash << 17) & 536739840);
	longAtput(newOop, header);
	return newOop;
}


/*	This code is called if the receiver responds primitively to at:.
	If this is so, it will be installed in the atCache so that subsequent calls of at:
	or next may be handled immediately in bytecode primitive routines. */

int commonAt(int stringy) {
    int result;
    int atIx;
    int rcvr;
    int index;
    int sp;
    int sp1;


	/* Sets successFlag */

	index = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	rcvr = longAt(stackPointer - (1 * 4));
	if (!(successFlag && (!((rcvr & 1))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((messageSelector == (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((16 * 2) << 2)))) && (lkupClass == (fetchClassOfNonInt(rcvr)))) {

		/* Index into atCache = 4N, for N = 0 ... 7 */

		atIx = rcvr & 28;
		if (!((atCache[atIx + 1]) == rcvr)) {
			installinAtCacheatstring(rcvr, atCache, atIx, stringy);
		}
		if (successFlag) {
			result = commonVariableatcacheIndex(rcvr, index, atIx);
		}
		if (successFlag) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * 4), result);
			stackPointer = sp;
			return null;
		}
	}
	successFlag = 1;
	result = stObjectat(rcvr, index);
	if (successFlag) {
		if (stringy) {
			result = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (24 << 2))))) + 4) + (((result >> 1)) << 2));
		}
		/* begin pop:thenPush: */
		longAtput(sp1 = stackPointer - ((2 - 1) * 4), result);
		stackPointer = sp1;
		return null;
	}
}


/*	This code is called if the receiver responds primitively to at:Put:.
	If this is so, it will be installed in the atPutCache so that subsequent calls of at:
	or  next may be handled immediately in bytecode primitive routines. */

int commonAtPut(int stringy) {
    int atIx;
    int value;
    int rcvr;
    int index;
    int fixedFields;
    int fmt;
    int valToPut;
    int stSize;
    int sp;
    int sp1;

	value = longAt(stackPointer - (0 * 4));

	/* Sets successFlag */

	index = positive32BitValueOf(longAt(stackPointer - (1 * 4)));
	rcvr = longAt(stackPointer - (2 * 4));
	if (!(successFlag && (!((rcvr & 1))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((messageSelector == (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((17 * 2) << 2)))) && (lkupClass == (fetchClassOfNonInt(rcvr)))) {

		/* Index into atPutCache */

		atIx = (rcvr & 28) + 32;
		if (!((atCache[atIx + 1]) == rcvr)) {
			installinAtCacheatstring(rcvr, atCache, atIx, stringy);
		}
		if (successFlag) {
			/* begin commonVariable:at:put:cacheIndex: */
			stSize = atCache[atIx + 2];
			if (((((unsigned ) index)) >= 1) && ((((unsigned ) index)) <= (((unsigned ) stSize)))) {
				fmt = atCache[atIx + 3];
				if (fmt <= 4) {
					fixedFields = atCache[atIx + 4];
					/* begin storePointer:ofObject:withValue: */
					if (rcvr < youngStart) {
						possibleRootStoreIntovalue(rcvr, value);
					}
					longAtput(((((char *) rcvr)) + 4) + (((index + fixedFields) - 1) << 2), value);
					goto l1;
				}
				if (fmt < 8) {
					valToPut = positive32BitValueOf(value);
					if (successFlag) {
						longAtput(((((char *) rcvr)) + 4) + ((index - 1) << 2), valToPut);
					}
					goto l1;
				}
				if (fmt >= 16) {
					valToPut = asciiOfCharacter(value);
					if (!(successFlag)) {
						goto l1;
					}
				} else {
					valToPut = value;
				}
				if ((valToPut & 1)) {
					valToPut = (valToPut >> 1);
					if (!((valToPut >= 0) && (valToPut <= 255))) {
						/* begin primitiveFail */
						successFlag = 0;
						goto l1;
					}
					byteAtput(((((char *) rcvr)) + 4) + (index - 1), valToPut);
					goto l1;
				}
			}
			/* begin primitiveFail */
			successFlag = 0;
		l1:	/* end commonVariable:at:put:cacheIndex: */;
		}
		if (successFlag) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((3 - 1) * 4), value);
			stackPointer = sp;
			return null;
		}
	}
	successFlag = 1;
	if (stringy) {
		stObjectatput(rcvr, index, asciiOfCharacter(value));
	} else {
		stObjectatput(rcvr, index, value);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp1 = stackPointer - ((3 - 1) * 4), value);
		stackPointer = sp1;
		return null;
	}
}


/*	This code assumes the reciever has been identified at location atIx in the atCache. */

int commonVariableatcacheIndex(int rcvr, int index, int atIx) {
    int fixedFields;
    int result;
    int fmt;
    int stSize;

	stSize = atCache[atIx + 2];
	if (((((unsigned ) index)) >= 1) && ((((unsigned ) index)) <= (((unsigned ) stSize)))) {
		fmt = atCache[atIx + 3];
		if (fmt <= 4) {
			fixedFields = atCache[atIx + 4];
			return longAt(((((char *) rcvr)) + 4) + (((index + fixedFields) - 1) << 2));
		}
		if (fmt < 8) {
			result = longAt(((((char *) rcvr)) + 4) + ((index - 1) << 2));
			result = positive32BitIntegerFor(result);
			return result;
		}
		if (fmt >= 16) {
			return longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (24 << 2))))) + 4) + ((byteAt(((((char *) rcvr)) + 4) + (index - 1))) << 2));
		} else {
			return (((byteAt(((((char *) rcvr)) + 4) + (index - 1))) << 1) | 1);
		}
	}
	/* begin primitiveFail */
	successFlag = 0;
}


/*	May set success to false */
/*	First compare two ST integers... */

int compare31or32Bitsequal(int obj1, int obj2) {
	if (((obj1 & 1)) && ((obj2 & 1))) {
		return obj1 == obj2;
	}
	return (positive32BitValueOf(obj1)) == (positive32BitValueOf(obj2));
}

int compilerCreateActualMessagestoringArgs(int aMessage, int argArray) {
	return compilerHooks[14](aMessage, argArray);
}

int compilerFlushCache(int aCompiledMethod) {
	return compilerHooks[2](aCompiledMethod);
}

int compilerMapFromto(int memStart, int memEnd) {
	return compilerHooks[4](memStart, memEnd);
}

int compilerMark(void) {
	return compilerHooks[9]();
}

int compilerPostGC(void) {
	return compilerHooks[5]();
}

int compilerPostSnapshot(void) {
	return compilerHooks[8]();
}

int compilerPreGC(int fullGCFlag) {
	return compilerHooks[3](fullGCFlag);
}

int compilerPreSnapshot(void) {
	return compilerHooks[7]();
}

int compilerProcessChange(void) {
	return compilerHooks[6]();
}

int compilerProcessChangeto(int oldProc, int newProc) {
	return compilerHooks[6](oldProc, newProc);
}

int compilerTranslateMethod(void) {
	return compilerHooks[1]();
}


/*	Return true if neither array contains a small integer. You can't become: integers! */

int containOnlyOopsand(int array1, int array2) {
    int fieldOffset;
    int header;
    int fmt;
    int methodHeader;
    int sz;
    int header1;
    int type;

	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((unsigned) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && (isContextHeader(header))) {
			fieldOffset = (6 + (fetchStackPointerOf(array1))) * 4;
			goto l1;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & 252) == 0) {
			type = 0;
			goto l2;
		} else {
			if ((header1 & 126976) == 0) {
				type = 1;
				goto l2;
			} else {
				type = 3;
				goto l2;
			}
		}
	l2:	/* end rightType: */;
		if (type == 0) {
			sz = (longAt(array1 - 8)) & 4294967292U;
			goto l3;
		} else {
			sz = header1 & 252;
			goto l3;
		}
	l3:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - 4;
		goto l1;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l1;
	}
	methodHeader = longAt(array1 + 4);
	fieldOffset = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
l1:	/* end lastPointerOf: */;
	while (fieldOffset >= 4) {
		if (((longAt(array1 + fieldOffset)) & 1)) {
			return 0;
		}
		if (((longAt(array2 + fieldOffset)) & 1)) {
			return 0;
		}
		fieldOffset -= 4;
	}
	return 1;
}


/*	Does thisCntx have aContext in its sender chain? */

int contexthasSender(int thisCntx, int aContext) {
    int s;
    int nilOop;

	if (thisCntx == aContext) {
		return 0;
	}
	nilOop = nilObj;
	s = longAt(((((char *) thisCntx)) + 4) + (0 << 2));
	while (!(s == nilOop)) {
		if (s == aContext) {
			return 1;
		}
		s = longAt(((((char *) s)) + 4) + (0 << 2));
	}
	return 0;
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin_copyBits
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

int copyBits(void) {
    int fn;

	fn = ioLoadFunctionFrom("copyBits", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	return  ((int (*) (void)) fn)();
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin_copyBitsFrom:to:at:
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

int copyBitsFromtoat(int x0, int x1, int y) {
    int fn;

	fn = ioLoadFunctionFrom("copyBitsFromtoat", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	return  ((int (*) (int, int, int)) fn)(x0, x1, y);
}


/*	Copy this object into the segment beginning at lastSeg.
	Install a forwarding pointer, and save oop and header.
	Fail if out of space.  Return the next segmentAddr if successful. */
/*	Copy the object... */

int copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(int oop, int segmentWordArray, int lastSeg, int stopAddr, int oopPtr, int hdrPtr) {
    int bodySize;
    int hdrAddr;
    int extraSize;
    int out;
    int lastIn;
    int in;
    int extra;
    int type;
    int header;

	if (!(successFlag)) {
		return lastSeg;
	}
	/* begin extraHeaderBytes: */
	type = (longAt(oop)) & 3;
	if (type > 1) {
		extra = 0;
	} else {
		if (type == 1) {
			extra = 4;
		} else {
			extra = 8;
		}
	}
	extraSize = extra;
	/* begin sizeBitsOf: */
	header = longAt(oop);
	if ((header & 3) == 0) {
		bodySize = (longAt(oop - 8)) & 4294967292U;
		goto l1;
	} else {
		bodySize = header & 252;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	if (((lastSeg + extraSize) + bodySize) >= stopAddr) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin transfer:from:to: */
	in = (oop - extraSize) - 4;
	lastIn = in + ((((int) (extraSize + bodySize) >> 2)) * 4);
	out = (lastSeg + 4) - 4;
	while (in < lastIn) {
		longAtput(out += 4, longAt(in += 4));
	}
	hdrAddr = (lastSeg + 4) + extraSize;
	longAtput(hdrAddr, (longAt(hdrAddr)) & (3221225471U - 2147483648U));
	/* begin forward:to:savingOopAt:andHeaderAt: */
	longAtput(oopPtr, oop);
	longAtput(hdrPtr, longAt(oop));
	longAtput(oop, (((lastSeg + 4) + extraSize) - segmentWordArray) + 2);
	return (lastSeg + extraSize) + bodySize;
}


/*	Bundle up the selector, arguments and lookupClass into a Message object.
	In the process it pops the arguments off the stack, and pushes the message object.
	This can then be presented as the argument of e.g. #doesNotUnderstand:.
	ikp 11/20/1999 03:59 -- added hook for external runtime compilers. */
/*	remap lookupClass in case GC happens during allocation */

int createActualMessageTo(int aClass) {
    int argumentArray;
    int message;
    int lookupClass;
    int out;
    int lastIn;
    int in;
    int sp;
    int oop;
    int oop1;
    int valuePointer;

	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = aClass;

	/* remap argumentArray in case GC happens during allocation */

	argumentArray = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)), argumentCount);
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = argumentArray;
	message = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (15 << 2)), 0);
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	argumentArray = oop;
	/* begin popRemappableOop */
	oop1 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	lookupClass = oop1;
	beRootIfOld(argumentArray);
	if (compilerInitialized) {
		compilerCreateActualMessagestoringArgs(message, argumentArray);
	} else {
		/* begin transfer:from:to: */
		in = (stackPointer - ((argumentCount - 1) * 4)) - 4;
		lastIn = in + (argumentCount * 4);
		out = (argumentArray + 4) - 4;
		while (in < lastIn) {
			longAtput(out += 4, longAt(in += 4));
		}
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((argumentCount - 1) * 4), message);
		stackPointer = sp;
	}
	argumentCount = 1;
	/* begin storePointer:ofObject:withValue: */
	valuePointer = messageSelector;
	if (message < youngStart) {
		possibleRootStoreIntovalue(message, valuePointer);
	}
	longAtput(((((char *) message)) + 4) + (0 << 2), valuePointer);
	/* begin storePointer:ofObject:withValue: */
	if (message < youngStart) {
		possibleRootStoreIntovalue(message, argumentArray);
	}
	longAtput(((((char *) message)) + 4) + (1 << 2), argumentArray);
	if ((lastPointerOf(message)) >= ((2 * 4) + 4)) {
		/* begin storePointer:ofObject:withValue: */
		if (message < youngStart) {
			possibleRootStoreIntovalue(message, lookupClass);
		}
		longAtput(((((char *) message)) + 4) + (2 << 2), lookupClass);
	}
}


/*	Repaint the portion of the Smalltalk screen bounded by the affected rectangle. Used to synchronize the screen after a Bitblt to the Smalltalk Display object. */

int displayBitsOfLeftTopRightBottom(int aForm, int l, int t, int r, int b) {
    int left;
    int dispBitsIndex;
    int top;
    int d;
    int surfaceHandle;
    int dispBits;
    int w;
    int right;
    int displayObj;
    int h;
    int bottom;
    int successValue;

	displayObj = longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
	if (!(aForm == displayObj)) {
		return null;
	}
	/* begin success: */
	successValue = (((((unsigned) (longAt(displayObj))) >> 8) & 15) <= 4) && ((lengthOf(displayObj)) >= 4);
	successFlag = successValue && successFlag;
	if (successFlag) {
		dispBits = longAt(((((char *) displayObj)) + 4) + (0 << 2));
		w = fetchIntegerofObject(1, displayObj);
		h = fetchIntegerofObject(2, displayObj);
		d = fetchIntegerofObject(3, displayObj);
	}
	if (l < 0) {
		left = 0;
	} else {
		left = l;
	}
	if (r > w) {
		right = w;
	} else {
		right = r;
	}
	if (t < 0) {
		top = 0;
	} else {
		top = t;
	}
	if (b > h) {
		bottom = h;
	} else {
		bottom = b;
	}
	if (!((left <= right) && (top <= bottom))) {
		return null;
	}
	if (successFlag) {
		if ((dispBits & 1)) {
			surfaceHandle = (dispBits >> 1);
			if (showSurfaceFn == 0) {
				showSurfaceFn = ioLoadFunctionFrom("ioShowSurface", "SurfacePlugin");
				if (showSurfaceFn == 0) {
					/* begin success: */
					successFlag = 0 && successFlag;
					return null;
				}
			}
			((int (*) (int, int, int, int, int))showSurfaceFn)(surfaceHandle, left, top, right-left, bottom-top);
		} else {

			/* index in memory byte array */

			dispBitsIndex = dispBits + 4;
			ioShowDisplay(dispBitsIndex, w, h, d, left, right, top, bottom);
		}
	}
}

int displayObject(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
}


/*	Rounds negative results towards negative infinity, rather than zero. */

int doPrimitiveDivby(int rcvr, int arg) {
    int posArg;
    int posRcvr;
    int result;
    int integerArg;
    int integerRcvr;

	if (((rcvr & arg) & 1) != 0) {
		integerRcvr = (rcvr >> 1);
		integerArg = (arg >> 1);
		/* begin success: */
		successFlag = (integerArg != 0) && successFlag;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (!(successFlag)) {
		return 1;
	}
	if (integerRcvr > 0) {
		if (integerArg > 0) {
			result = integerRcvr / integerArg;
		} else {
			posArg = 0 - integerArg;
			result = 0 - ((integerRcvr + (posArg - 1)) / posArg);
		}
	} else {
		posRcvr = 0 - integerRcvr;
		if (integerArg > 0) {
			result = 0 - ((posRcvr + (integerArg - 1)) / integerArg);
		} else {
			posArg = 0 - integerArg;
			result = posRcvr / posArg;
		}
	}
	/* begin success: */
	successFlag = ((result ^ (result << 1)) >= 0) && successFlag;
	return result;
}

int doPrimitiveModby(int rcvr, int arg) {
    int integerResult;
    int integerArg;
    int integerRcvr;

	if (((rcvr & arg) & 1) != 0) {
		integerRcvr = (rcvr >> 1);
		integerArg = (arg >> 1);
		/* begin success: */
		successFlag = (integerArg != 0) && successFlag;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (!(successFlag)) {
		return 1;
	}

	/* ensure that the result has the same sign as the integerArg */

	integerResult = integerRcvr % integerArg;
	if (integerArg < 0) {
		if (integerResult > 0) {
			integerResult += integerArg;
		}
	} else {
		if (integerResult < 0) {
			integerResult += integerArg;
		}
	}
	/* begin success: */
	successFlag = ((integerResult ^ (integerResult << 1)) >= 0) && successFlag;
	return integerResult;
}


/*	Return the number of extra bytes used by the given object's header. */
/*	Warning: This method should not be used during marking, when the header type bits of an object may be incorrect. */

int extraHeaderBytes(int oopOrChunk) {
    int extra;
    int type;

	type = (longAt(oopOrChunk)) & 3;
	if (type > 1) {
		extra = 0;
	} else {
		if (type == 1) {
			extra = 4;
		} else {
			extra = 8;
		}
	}
	return extra;
}

int failed(void) {
	return !successFlag;
}

int falseObject(void) {
	return falseObj;
}


/*	Fetch the instance variable at the given index of the given object. Return the address of first indexable field of resulting array object, or fail if the instance variable does not contain an indexable bytes or words object. */
/*	Note: May be called by translated primitive code. */

void * fetchArrayofObject(int fieldIndex, int objectPointer) {
    int arrayOop;

	arrayOop = longAt(((((char *) objectPointer)) + 4) + (fieldIndex << 2));
	return arrayValueOf(arrayOop);
}

int fetchClassOf(int oop) {
    int ccIndex;

	if ((oop & 1)) {
		return longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		return (longAt(oop - 4)) & 4294967292U;
	} else {
		return longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
}

int fetchClassOfNonInt(int oop) {
    int ccIndex;

	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		return (longAt(oop - 4)) & 4294967292U;
	} else {
		return longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
}


/*	Fetch the instance variable at the given index of the given object. Return the C double precision floating point value of that instance variable, or fail if it is not a Float. */
/*	Note: May be called by translated primitive code. */

double fetchFloatofObject(int fieldIndex, int objectPointer) {
    int floatOop;

	floatOop = longAt(((((char *) objectPointer)) + 4) + (fieldIndex << 2));
	return floatValueOf(floatOop);
}


/*	Note: May be called by translated primitive code. */

int fetchIntegerofObject(int fieldIndex, int objectPointer) {
    int intOop;

	intOop = longAt(((((char *) objectPointer)) + 4) + (fieldIndex << 2));
	if ((intOop & 1)) {
		return (intOop >> 1);
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
}

int fetchPointerofObject(int fieldIndex, int oop) {
	return longAt(((((char *) oop)) + 4) + (fieldIndex << 2));
}


/*	Return the stackPointer of a Context or BlockContext. */

int fetchStackPointerOf(int aContext) {
    int sp;

	sp = longAt(((((char *) aContext)) + 4) + (2 << 2));
	if (!((sp & 1))) {
		return 0;
	}
	return (sp >> 1);
}

int fetchWordofObject(int fieldIndex, int oop) {
	return longAt(((((char *) oop)) + 4) + (fieldIndex << 2));
}


/*	During sweep phase we have encountered a weak reference. Check if
	its object has gone away (or is about to) and if so, signal a semaphore. */
/*	Do *not* inline this in sweepPhase - it is quite an unlikely case to run into a weak reference */

int finalizeReference(int oop) {
    int weakOop;
    int chunk;
    int firstField;
    int i;
    int oopGone;
    int lastField;
    int extra;
    int header;
    int fmt;
    int methodHeader;
    int sz;
    int header1;
    int type;
    int extra1;
    int type1;

	firstField = 4 + ((nonWeakFieldsOf(oop)) << 2);
	/* begin lastPointerOf: */
	header = longAt(oop);
	fmt = (((unsigned) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && (isContextHeader(header))) {
			lastField = (6 + (fetchStackPointerOf(oop))) * 4;
			goto l1;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(oop);
		/* begin rightType: */
		if ((header1 & 252) == 0) {
			type = 0;
			goto l2;
		} else {
			if ((header1 & 126976) == 0) {
				type = 1;
				goto l2;
			} else {
				type = 3;
				goto l2;
			}
		}
	l2:	/* end rightType: */;
		if (type == 0) {
			sz = (longAt(oop - 8)) & 4294967292U;
			goto l3;
		} else {
			sz = header1 & 252;
			goto l3;
		}
	l3:	/* end sizeBitsOfSafe: */;
		lastField = sz - 4;
		goto l1;
	}
	if (fmt < 12) {
		lastField = 0;
		goto l1;
	}
	methodHeader = longAt(oop + 4);
	lastField = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
l1:	/* end lastPointerOf: */;
	for (i = firstField; i <= lastField; i += 4) {
		weakOop = longAt(oop + i);
		if (!((weakOop == nilObj) || ((weakOop & 1)))) {
			if (weakOop < oop) {
				/* begin chunkFromOop: */
				/* begin extraHeaderBytes: */
				type1 = (longAt(weakOop)) & 3;
				if (type1 > 1) {
					extra1 = 0;
				} else {
					if (type1 == 1) {
						extra1 = 4;
					} else {
						extra1 = 8;
					}
				}
				extra = extra1;
				chunk = weakOop - extra;
				oopGone = ((longAt(chunk)) & 3) == 2;
			} else {
				oopGone = ((longAt(weakOop)) & 2147483648U) == 0;
			}
			if (oopGone) {
				longAtput(oop + i, nilObj);
				/* begin signalFinalization: */
				interruptCheckCounter = 0;
				pendingFinalizationSignals += 1;
			}
		}
	}
}

int findClassOfMethodforReceiver(int meth, int rcvr) {
    int classDict;
    int classDictSize;
    int i;
    int done;
    int methodArray;
    int currClass;
    int sz;
    int header;
    int ccIndex;
    int ccIndex1;

	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		currClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l2;
	}
	ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currClass = (longAt(rcvr - 4)) & 4294967292U;
		goto l2;
	} else {
		currClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	done = 0;
	while (!(done)) {
		classDict = longAt(((((char *) currClass)) + 4) + (1 << 2));
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(classDict);
		if ((header & 3) == 0) {
			sz = (longAt(classDict - 8)) & 4294967292U;
			goto l1;
		} else {
			sz = header & 252;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		classDictSize = ((unsigned) (sz - 4)) >> 2;
		methodArray = longAt(((((char *) classDict)) + 4) + (1 << 2));
		i = 0;
		while (i < (classDictSize - 2)) {
			if (meth == (longAt(((((char *) methodArray)) + 4) + (i << 2)))) {
				return currClass;
			}
			i += 1;
		}
		currClass = longAt(((((char *) currClass)) + 4) + (0 << 2));
		done = currClass == nilObj;
	}
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		return longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
	}
	ccIndex1 = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex1 == 0) {
		return (longAt(rcvr - 4)) & 4294967292U;
	} else {
		return longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
	}
	return null;
}


/*	Find the compiled method to be run when the current messageSelector is sent to the given class, setting the values of 'newMethod' and 'primitiveIndex'. */

int findNewMethodInClass(int class) {
    int ok;
    int hash;
    int probe;

	/* begin lookupInMethodCacheSel:class: */
	hash = messageSelector ^ class;
	probe = hash & 4088;
	if (((methodCache[probe + 1]) == messageSelector) && ((methodCache[probe + 2]) == class)) {
		newMethod = methodCache[probe + 3];
		primitiveIndex = methodCache[probe + 4];
		newNativeMethod = methodCache[probe + 5];
		ok = 1;
		goto l1;
	}
	probe = (((unsigned) hash) >> 1) & 4088;
	if (((methodCache[probe + 1]) == messageSelector) && ((methodCache[probe + 2]) == class)) {
		newMethod = methodCache[probe + 3];
		primitiveIndex = methodCache[probe + 4];
		newNativeMethod = methodCache[probe + 5];
		ok = 1;
		goto l1;
	}
	probe = (((unsigned) hash) >> 2) & 4088;
	if (((methodCache[probe + 1]) == messageSelector) && ((methodCache[probe + 2]) == class)) {
		newMethod = methodCache[probe + 3];
		primitiveIndex = methodCache[probe + 4];
		newNativeMethod = methodCache[probe + 5];
		ok = 1;
		goto l1;
	}
	ok = 0;
l1:	/* end lookupInMethodCacheSel:class: */;
	if (!(ok)) {
		lookupMethodInClass(class);
		lkupClass = class;
		addNewMethodToCache();
	}
}


/*	Search the obsolete named primitive table for the given function.
	Return the index if it's found, -1 otherwise. */

int findObsoleteNamedPrimitivelength(char * functionName, int functionLength) {
    const char * entry;
    int index;
    int chIndex;

	index = 0;
	while (1) {
		entry = (obsoleteNamedPrimitiveTable[index])[0];
		if (entry == null) {
			return -1;
		}
		chIndex = 0;
		while (((entry[chIndex]) == (functionName[chIndex])) && (chIndex < functionLength)) {
			chIndex += 1;
		}
		if ((chIndex == functionLength) && ((entry[chIndex]) == 0)) {
			return index;
		}
		index += 1;
	}
}

int findSelectorOfMethodforReceiver(int meth, int rcvr) {
    int classDict;
    int classDictSize;
    int i;
    int done;
    int methodArray;
    int currClass;
    int sz;
    int header;
    int ccIndex;

	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		currClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l2;
	}
	ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currClass = (longAt(rcvr - 4)) & 4294967292U;
		goto l2;
	} else {
		currClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	done = 0;
	while (!(done)) {
		classDict = longAt(((((char *) currClass)) + 4) + (1 << 2));
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(classDict);
		if ((header & 3) == 0) {
			sz = (longAt(classDict - 8)) & 4294967292U;
			goto l1;
		} else {
			sz = header & 252;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		classDictSize = ((unsigned) (sz - 4)) >> 2;
		methodArray = longAt(((((char *) classDict)) + 4) + (1 << 2));
		i = 0;
		while (i <= (classDictSize - 2)) {
			if (meth == (longAt(((((char *) methodArray)) + 4) + (i << 2)))) {
				return longAt(((((char *) classDict)) + 4) + ((i + 2) << 2));
			}
			i += 1;
		}
		currClass = longAt(((((char *) currClass)) + 4) + (0 << 2));
		done = currClass == nilObj;
	}
	return longAt(((((char *) specialObjectsOop)) + 4) + (20 << 2));
}


/*	Return the first accessible object in the heap. */

int firstAccessibleObject(void) {
    int obj;
    int chunk;
    int extra;
    int extra1;
    int type;
    int sz;
    int extra2;
    int header;
    int extra11;
    int type1;

	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	obj = chunk + extra;
	while (obj < endOfMemory) {
		if (!(((longAt(obj)) & 3) == 2)) {
			return obj;
		}
		/* begin objectAfter: */
		;
		if (((longAt(obj)) & 3) == 2) {
			sz = (longAt(obj)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & 3) == 0) {
				sz = (longAt(obj - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(obj + sz)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		obj = (obj + sz) + extra2;
	}
	error("heap is empty");
}

void * firstFixedField(int oop) {
	return ((void *) (oop + 4));
}

void * firstIndexableField(int oop) {
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int sz;
    int classFormat;
    int class;
    int ccIndex;

	hdr = longAt(oop);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l1;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l2;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l2;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l2:	/* end fixedFieldsOf:format:length: */;
	if (fmt < 8) {
		return ((void *) ((oop + 4) + (fixedFields << 2)));
	} else {
		return ((void *) ((oop + 4) + fixedFields));
	}
}

int floatObjectOf(double aFloat) {
    int newFloatObj;

	newFloatObj = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)), 12, 0);
	storeFloatAtfrom(newFloatObj + 4, aFloat);
	return newFloatObj;
}


/*	Fetch the instance variable at the given index of the given object. Return the C double precision floating point value of that instance variable, or fail if it is not a Float. */
/*	Note: May be called by translated primitive code. */

double floatValueOf(int oop) {
    double result;
    int cl;
    int ccIndex;

	/* begin assertClassOf:is: */
	if ((oop & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		;
		fetchFloatAtinto(oop + 4, result);
	} else {
		result = 0.0;
	}
	return result;
}


/*	Flush the references to external functions from plugin primitives.
	This will force a reload of those primitives when accessed next.
	Note: We must flush the method cache here so that any failed
	primitives are looked up again. */

int flushExternalPrimitives(void) {
    int oop;
    int fmt;
    int primIdx;
    int chunk;
    int extra;
    int i;
    int i1;
    int i2;
    int primBits;
    int extra1;
    int type;
    int sz;
    int extra2;
    int header;
    int extra11;
    int type1;
    int lit;

	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	oop = chunk + extra;
	while (oop < endOfMemory) {
		if (!(((longAt(oop)) & 3) == 2)) {
			fmt = (((unsigned) (longAt(oop))) >> 8) & 15;
			if (fmt >= 12) {
				/* begin primitiveIndexOf: */
				primBits = (((unsigned) (longAt(((((char *) oop)) + 4) + (0 << 2)))) >> 1) & 805306879;
				if (primBits > 511) {
					primIdx = (primBits & 511) + (((unsigned) primBits) >> 19);
					goto l1;
				} else {
					primIdx = primBits;
					goto l1;
				}
			l1:	/* end primitiveIndexOf: */;
				if (primIdx == 117) {
					/* begin flushExternalPrimitiveOf: */
					if (!(((((unsigned) (longAt(((((char *) oop)) + 4) + (0 << 2)))) >> 10) & 255) > 0)) {
						goto l3;
					}
					lit = longAt(((((char *) oop)) + 4) + ((0 + 1) << 2));
					if (!(((fetchClassOf(lit)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))) && ((lengthOf(lit)) == 4))) {
						goto l3;
					}
					/* begin storeInteger:ofObject:withValue: */
					if ((0 ^ (0 << 1)) >= 0) {
						longAtput(((((char *) lit)) + 4) + (2 << 2), ((0 << 1) | 1));
					} else {
						/* begin primitiveFail */
						successFlag = 0;
					}
					/* begin storeInteger:ofObject:withValue: */
					if ((0 ^ (0 << 1)) >= 0) {
						longAtput(((((char *) lit)) + 4) + (3 << 2), ((0 << 1) | 1));
					} else {
						/* begin primitiveFail */
						successFlag = 0;
					}
				l3:	/* end flushExternalPrimitiveOf: */;
				}
			}
		}
		/* begin objectAfter: */
		;
		if (((longAt(oop)) & 3) == 2) {
			sz = (longAt(oop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & 3) == 0) {
				sz = (longAt(oop - 8)) & 4294967292U;
				goto l2;
			} else {
				sz = header & 252;
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(oop + sz)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		oop = (oop + sz) + extra2;
	}
	/* begin flushMethodCache */
	for (i = 1; i <= 4096; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= 64; i += 1) {
		atCache[i] = 0;
	}
	/* begin flushObsoleteIndexedPrimitives */
	for (i1 = 1; i1 <= 700; i1 += 1) {
		(obsoleteIndexedPrimitiveTable[i1])[2] = null;
	}
	/* begin flushExternalPrimitiveTable */
	for (i2 = 0; i2 <= (4096 - 1); i2 += 1) {
		externalPrimitiveTable[i2] = 0;
	}
}


/*	Repaint the entire smalltalk screen, ignoring the affected rectangle. Used when the Smalltalk window is brought to the front or uncovered. */

int fullDisplayUpdate(void) {
    int w;
    int displayObj;
    int h;

	displayObj = longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
	if ((((((unsigned) (longAt(displayObj))) >> 8) & 15) <= 4) && ((lengthOf(displayObj)) >= 4)) {
		w = fetchIntegerofObject(1, displayObj);
		h = fetchIntegerofObject(2, displayObj);
		displayBitsOfLeftTopRightBottom(displayObj, 0, 0, w, h);
		ioForceDisplayUpdate();
	}
}


/*	Do a mark/sweep garbage collection of the entire object memory. Free inaccessible objects but do not move them. */

int fullGC(void) {
    int startTime;
    int i;
    int oop;
    int sz;
    int delta;
    int limit;
    int delta1;
    int limit1;

	;
	/* begin preGCAction: */
	if (compilerInitialized) {
		compilerPreGC(1);
	} else {
		/* begin storeContextRegisters: */
		longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
		longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
	}
	startTime = ioMicroMSecs();
	/* begin clearRootsTable */
	for (i = 1; i <= rootTableCount; i += 1) {
		oop = rootTable[i];
		longAtput(oop, (longAt(oop)) & 3221225471U);
		rootTable[i] = 0;
	}
	rootTableCount = 0;

	/* process all of memory */

	youngStart = startOfMemory();
	markPhase();
	totalObjectCount = sweepPhase();
	/* begin fullCompaction */
	compStart = lowestFreeAfter(startOfMemory());
	if (compStart == freeBlock) {
		initializeMemoryFirstFree(freeBlock);
		goto l1;
	}
	if ((sz = fwdTableSize(8)) < totalObjectCount) {
		/* begin growObjectMemory: */
		delta = ((totalObjectCount - sz) + 10000) * 8;
		limit = sqGrowMemoryBy(memoryLimit, delta);
		if (!(limit == memoryLimit)) {
			memoryLimit = limit - 24;
			initializeMemoryFirstFree(freeBlock);
		}
	}
	while (compStart < freeBlock) {
		compStart = incCompBody();
	}
l1:	/* end fullCompaction */;
	allocationCount = 0;
	statFullGCs += 1;
	statFullGCMSecs += (ioMicroMSecs()) - startTime;

	/* reset the young object boundary */

	youngStart = freeBlock;
	/* begin postGCAction */
	if (compilerInitialized) {
		compilerPostGC();
	} else {
		if (activeContext < youngStart) {
			beRootIfOld(activeContext);
		}
		if (theHomeContext < youngStart) {
			beRootIfOld(theHomeContext);
		}
	}
	if (((longAt(freeBlock)) & 4294967292U) > shrinkThreshold) {
		/* begin shrinkObjectMemory: */
		delta1 = ((longAt(freeBlock)) & 4294967292U) - growHeadroom;
		limit1 = sqShrinkMemoryBy(memoryLimit, delta1);
		if (!(limit1 == memoryLimit)) {
			memoryLimit = limit1 - 24;
			initializeMemoryFirstFree(freeBlock);
		}
	}
	;
}


/*	Set the limits for a table of two- or three-word forwarding blocks above the last used oop. The pointer fwdTableNext moves up to fwdTableLast. Used for compaction of memory and become-ing objects. Returns the number of forwarding blocks available. */

int fwdTableInit(int blkSize) {
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (4 & 4294967292U) | 2);

	/* make a fake free chunk at endOfMemory for use as a sentinal in memory scans */

	endOfMemory = freeBlock + 4;
	/* begin setSizeOfFree:to: */
	longAtput(endOfMemory, (4 & 4294967292U) | 2);
	fwdTableNext = ((endOfMemory + 4) + 7) & 4294967288U;

	/* last forwarding table entry */
	/* return the number of forwarding blocks available */

	fwdTableLast = memoryLimit - blkSize;
	return (fwdTableLast - fwdTableNext) / blkSize;
}


/*	Estimate the number of forwarding blocks available for compaction */

int fwdTableSize(int blkSize) {
    int eom;
    int fwdLast;
    int fwdFirst;


	/* use all memory free between freeBlock and memoryLimit for forwarding table */
	/* Note: Forward blocks must be quadword aligned. */

	eom = freeBlock + 4;
	fwdFirst = ((eom + 4) + 7) & 4294967288U;

	/* last forwarding table entry */
	/* return the number of forwarding blocks available */

	fwdLast = memoryLimit - blkSize;
	return (fwdLast - fwdFirst) / blkSize;
}


/*	currentBytecode will be private to the main dispatch loop in the generated code. This method allows the currentBytecode to be retrieved from global variables. */

int getCurrentBytecode(void) {
	return byteAt(instructionPointer);
}


/*	Return the next 4-byte word of the given file, byte-swapped according to the given flag. */

int getLongFromFileswap(sqImageFile f, int swapFlag) {
    int w;

	sqImageFileRead(&w, sizeof(char), 4, f);
	if (swapFlag) {
		return ((((((unsigned) w >> 24)) & 255) + ((((unsigned) w >> 8)) & 65280)) + ((((unsigned) w << 8)) & 16711680)) + ((((unsigned) w << 24)) & 4278190080U);
	} else {
		return w;
	}
}


/*	a more complex version that tells both the word reversal and the endianness of the machine it came from.  Low half of word is 6502.  Top byte is top byte of #doesNotUnderstand: on this machine. ($d on the Mac or $s on the PC) */

int imageSegmentVersion(void) {
    int wholeWord;


	/* first data word, 'does'  */

	wholeWord = longAt((longAt(((((char *) specialObjectsOop)) + 4) + (20 << 2))) + 4);
	return 6502 | (wholeWord & 4278190080U);
}


/*	Move objects to consolidate free space into one big chunk. Return the newly created free chunk. */

int incCompBody(void) {
    int bytesFreed;
    int newOop;
    int oop;
    int fwdBlock;
    int bytesFreed1;
    int extra;
    int originalHeaderType;
    int originalHeader;
    int chunk;
    int extra1;
    int extra2;
    int type;
    int extra3;
    int type1;
    int header;
    int w;
    int newOop1;
    int newFreeChunk;
    int oop1;
    int lastWord;
    int sz;
    int fwdBlock1;
    int firstWord;
    int next;
    int bytesToMove;
    int header1;
    int chunk2;
    int extra4;
    int chunk1;
    int extra11;
    int extra21;
    int type2;
    int extra31;
    int type11;
    int header2;
    int sz2;
    int fwdBlock2;
    int realHeader;
    int extra5;
    int extra12;
    int type3;
    int sz1;
    int extra22;
    int header11;
    int extra111;
    int type12;
    int header3;
    int sz3;
    int fwdBlock3;
    int realHeader1;
    int extra6;
    int extra13;
    int type4;
    int sz11;
    int extra23;
    int header12;
    int extra112;
    int type13;

	fwdTableInit(8);
	/* begin incCompMakeFwd */
	bytesFreed1 = 0;
	/* begin oopFromChunk: */
	chunk = compStart;
	/* begin extraHeaderBytes: */
	type1 = (longAt(chunk)) & 3;
	if (type1 > 1) {
		extra3 = 0;
	} else {
		if (type1 == 1) {
			extra3 = 4;
		} else {
			extra3 = 8;
		}
	}
	extra1 = extra3;
	oop = chunk + extra1;
	while (oop < endOfMemory) {
		if (((longAt(oop)) & 3) == 2) {
			bytesFreed1 += (longAt(oop)) & 4294967292U;
		} else {
			/* begin fwdBlockGet: */
			fwdTableNext += 8;
			if (fwdTableNext <= fwdTableLast) {
				fwdBlock = fwdTableNext;
				goto l1;
			} else {
				fwdBlock = null;
				goto l1;
			}
		l1:	/* end fwdBlockGet: */;
			if (fwdBlock == null) {
				/* begin chunkFromOop: */
				/* begin extraHeaderBytes: */
				type = (longAt(oop)) & 3;
				if (type > 1) {
					extra2 = 0;
				} else {
					if (type == 1) {
						extra2 = 4;
					} else {
						extra2 = 8;
					}
				}
				extra = extra2;
				compEnd = oop - extra;
				bytesFreed = bytesFreed1;
				goto l2;
			}
			newOop = oop - bytesFreed1;
			/* begin initForwardBlock:mapping:to:withBackPtr: */
			originalHeader = longAt(oop);
			;
			originalHeaderType = originalHeader & 3;
			longAtput(fwdBlock, newOop);
			longAtput(fwdBlock + 4, originalHeader);
			;
			longAtput(oop, (((unsigned) fwdBlock) >> 1) | (2147483648U | originalHeaderType));
		}
		/* begin objectAfterWhileForwarding: */
		header2 = longAt(oop);
		if ((header2 & 2147483648U) == 0) {
			/* begin objectAfter: */
			;
			if (((longAt(oop)) & 3) == 2) {
				sz1 = (longAt(oop)) & 4294967292U;
			} else {
				/* begin sizeBitsOf: */
				header11 = longAt(oop);
				if ((header11 & 3) == 0) {
					sz1 = (longAt(oop - 8)) & 4294967292U;
					goto l4;
				} else {
					sz1 = header11 & 252;
					goto l4;
				}
			l4:	/* end sizeBitsOf: */;
			}
			/* begin oopFromChunk: */
			/* begin extraHeaderBytes: */
			type12 = (longAt(oop + sz1)) & 3;
			if (type12 > 1) {
				extra111 = 0;
			} else {
				if (type12 == 1) {
					extra111 = 4;
				} else {
					extra111 = 8;
				}
			}
			extra22 = extra111;
			oop = (oop + sz1) + extra22;
			goto l5;
		}
		fwdBlock2 = (header2 & 2147483644) << 1;
		;
		realHeader = longAt(fwdBlock2 + 4);
		if ((realHeader & 3) == 0) {
			sz2 = (longAt(oop - 8)) & 4294967292U;
		} else {
			sz2 = realHeader & 252;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type3 = (longAt(oop + sz2)) & 3;
		if (type3 > 1) {
			extra12 = 0;
		} else {
			if (type3 == 1) {
				extra12 = 4;
			} else {
				extra12 = 8;
			}
		}
		extra5 = extra12;
		oop = (oop + sz2) + extra5;
	l5:	/* end objectAfterWhileForwarding: */;
	}
	compEnd = endOfMemory;
	bytesFreed = bytesFreed1;
l2:	/* end incCompMakeFwd */;
	mapPointersInObjectsFromto(youngStart, endOfMemory);
	/* begin incCompMove: */
	newOop1 = null;
	/* begin oopFromChunk: */
	chunk1 = compStart;
	/* begin extraHeaderBytes: */
	type11 = (longAt(chunk1)) & 3;
	if (type11 > 1) {
		extra31 = 0;
	} else {
		if (type11 == 1) {
			extra31 = 4;
		} else {
			extra31 = 8;
		}
	}
	extra11 = extra31;
	oop1 = chunk1 + extra11;
	while (oop1 < compEnd) {
		/* begin objectAfterWhileForwarding: */
		header3 = longAt(oop1);
		if ((header3 & 2147483648U) == 0) {
			/* begin objectAfter: */
			;
			if (((longAt(oop1)) & 3) == 2) {
				sz11 = (longAt(oop1)) & 4294967292U;
			} else {
				/* begin sizeBitsOf: */
				header12 = longAt(oop1);
				if ((header12 & 3) == 0) {
					sz11 = (longAt(oop1 - 8)) & 4294967292U;
					goto l6;
				} else {
					sz11 = header12 & 252;
					goto l6;
				}
			l6:	/* end sizeBitsOf: */;
			}
			/* begin oopFromChunk: */
			/* begin extraHeaderBytes: */
			type13 = (longAt(oop1 + sz11)) & 3;
			if (type13 > 1) {
				extra112 = 0;
			} else {
				if (type13 == 1) {
					extra112 = 4;
				} else {
					extra112 = 8;
				}
			}
			extra23 = extra112;
			next = (oop1 + sz11) + extra23;
			goto l7;
		}
		fwdBlock3 = (header3 & 2147483644) << 1;
		;
		realHeader1 = longAt(fwdBlock3 + 4);
		if ((realHeader1 & 3) == 0) {
			sz3 = (longAt(oop1 - 8)) & 4294967292U;
		} else {
			sz3 = realHeader1 & 252;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type4 = (longAt(oop1 + sz3)) & 3;
		if (type4 > 1) {
			extra13 = 0;
		} else {
			if (type4 == 1) {
				extra13 = 4;
			} else {
				extra13 = 8;
			}
		}
		extra6 = extra13;
		next = (oop1 + sz3) + extra6;
	l7:	/* end objectAfterWhileForwarding: */;
		if (!(((longAt(oop1)) & 3) == 2)) {
			fwdBlock1 = ((longAt(oop1)) & 2147483644) << 1;
			;
			newOop1 = longAt(fwdBlock1);
			header = longAt(fwdBlock1 + 4);
			longAtput(oop1, header);
			bytesToMove = oop1 - newOop1;
			/* begin sizeBitsOf: */
			header1 = longAt(oop1);
			if ((header1 & 3) == 0) {
				sz = (longAt(oop1 - 8)) & 4294967292U;
				goto l3;
			} else {
				sz = header1 & 252;
				goto l3;
			}
		l3:	/* end sizeBitsOf: */;
			firstWord = oop1 - (extraHeaderBytes(oop1));
			lastWord = (oop1 + sz) - 4;
			for (w = firstWord; w <= lastWord; w += 4) {
				longAtput(w - bytesToMove, longAt(w));
			}
		}
		oop1 = next;
	}
	if (newOop1 == null) {
		/* begin oopFromChunk: */
		chunk2 = compStart;
		/* begin extraHeaderBytes: */
		type2 = (longAt(chunk2)) & 3;
		if (type2 > 1) {
			extra21 = 0;
		} else {
			if (type2 == 1) {
				extra21 = 4;
			} else {
				extra21 = 8;
			}
		}
		extra4 = extra21;
		oop1 = chunk2 + extra4;
		if ((((longAt(oop1)) & 3) == 2) && ((objectAfter(oop1)) == (oopFromChunk(compEnd)))) {
			newFreeChunk = oop1;
		} else {
			newFreeChunk = freeBlock;
		}
	} else {
		newFreeChunk = newOop1 + (sizeBitsOf(newOop1));
		/* begin setSizeOfFree:to: */
		longAtput(newFreeChunk, (bytesFreed & 4294967292U) | 2);
	}
	;
	if ((objectAfter(newFreeChunk)) == endOfMemory) {
		initializeMemoryFirstFree(newFreeChunk);
	} else {
		initializeMemoryFirstFree(freeBlock);
	}
	return newFreeChunk;
}


/*	Return the equivalent of 
		aClass includesBehavior: aSuperclass.
	Note: written for efficiency and better inlining (only 1 temp) */

int includesBehaviorThatOf(int aClass, int aSuperclass) {
    int theClass;

	if (((theClass = aClass) == aSuperclass) || (aSuperclass == nilObj)) {
		return 1;
	}
	do {
		if ((theClass = longAt(((((char *) theClass)) + 4) + (0 << 2))) == aSuperclass) {
			return 1;
		}
	} while(theClass != nilObj);
	return 0;
}


/*	Do a mark/sweep garbage collection of just the young object area of object memory (i.e., objects above youngStart), using the root table to identify objects containing pointers to young objects from the old object area. */

int incrementalGC(void) {
    int startTime;
    int survivorCount;
    int i;
    int oop;
    int delta;
    int limit;
    int header;
    int oop1;
    int badRoot;
    int fieldOop;
    int fieldAddr;
    int chunk;
    int extra;
    int extra1;
    int type;
    int sz;
    int extra2;
    int header1;
    int extra11;
    int type1;

	if (rootTableCount >= 2500) {
		statRootTableOverflows += 1;
		return fullGC();
	}
	;
	;
	/* begin preGCAction: */
	if (compilerInitialized) {
		compilerPreGC(0);
	} else {
		/* begin storeContextRegisters: */
		longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
		longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
	}
	startTime = ioMicroMSecs();
	markPhase();
	survivorCount = sweepPhase();
	/* begin incrementalCompaction */
	if (compStart == freeBlock) {
		initializeMemoryFirstFree(freeBlock);
	} else {
		incCompBody();
	}
	allocationCount = 0;
	statIncrGCs += 1;
	statIncrGCMSecs += (ioMicroMSecs()) - startTime;
	if (survivorCount > tenuringThreshold) {
		statTenures += 1;
		/* begin clearRootsTable */
		for (i = 1; i <= rootTableCount; i += 1) {
			oop = rootTable[i];
			longAtput(oop, (longAt(oop)) & 3221225471U);
			rootTable[i] = 0;
		}
		rootTableCount = 0;
		youngStart = freeBlock;
	}
	/* begin postGCAction */
	if (compilerInitialized) {
		compilerPostGC();
	} else {
		if (activeContext < youngStart) {
			beRootIfOld(activeContext);
		}
		if (theHomeContext < youngStart) {
			beRootIfOld(theHomeContext);
		}
	}
	if (((longAt(freeBlock)) & 4294967292U) > shrinkThreshold) {
		/* begin shrinkObjectMemory: */
		delta = ((longAt(freeBlock)) & 4294967292U) - growHeadroom;
		limit = sqShrinkMemoryBy(memoryLimit, delta);
		if (!(limit == memoryLimit)) {
			memoryLimit = limit - 24;
			initializeMemoryFirstFree(freeBlock);
		}
	}
	;
}


/*	Initialize hooks for the 'null compiler' */

int initCompilerHooks(void) {
	compilerHooks[1]= nullCompilerHook;
	compilerHooks[2]= nullCompilerHook;
	compilerHooks[3]= nullCompilerHook;
	compilerHooks[4]= nullCompilerHook;
	compilerHooks[5]= nullCompilerHook;
	compilerHooks[6]= nullCompilerHook;
	compilerHooks[7]= nullCompilerHook;
	compilerHooks[8]= nullCompilerHook;
	compilerHooks[9]= nullCompilerHook;
	compilerHooks[10]= nullCompilerHook;
	compilerHooks[11]= nullCompilerHook;
	compilerHooks[12]= nullCompilerHook;
	compilerHooks[13]= nullCompilerHook;
	compilerHooks[14]= nullCompilerHook;
	compilerInitialized = 0;
}


/*	Initialize endOfMemory to the top of oop storage space, reserving some space for forwarding blocks, and create the freeBlock from which space is allocated. Also create a fake free chunk at endOfMemory to act as a sentinal for memory scans. */
/*	Note: The amount of space reserved for forwarding blocks should be chosen to ensure that incremental compactions can usually be done in a single pass. However, there should be enough forwarding blocks so a full compaction can be done in a reasonable number of passes, say ten. (A full compaction requires N object-moving passes, where N = number of non-garbage objects / number of forwarding blocks).
di 11/18/2000 Re totalObjectCount: Provide a margin of one byte per object to be used for forwarding pointers at GC time.  Since fwd blocks are 8 bytes, this means an absolute worst case of 8 passes to compact memory.  In most cases it will be adequate to do compaction in a single pass. */
/*	reserve space for forwarding blocks */

int initializeMemoryFirstFree(int firstFree) {
    int fwdBlockBytes;

	fwdBlockBytes = totalObjectCount & 4294967292U;
	if (!((memoryLimit - fwdBlockBytes) >= (firstFree + 4))) {
		fwdBlockBytes = memoryLimit - (firstFree + 4);
	}
	endOfMemory = memoryLimit - fwdBlockBytes;
	freeBlock = firstFree;
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, ((endOfMemory - firstFree) & 4294967292U) | 2);
	/* begin setSizeOfFree:to: */
	longAtput(endOfMemory, (4 & 4294967292U) | 2);
	;
}


/*	Initialize object memory variables at startup time. Assume endOfMemory is initially set (by the image-reading code) to the end of the last object in the image. Initialization redefines endOfMemory to be the end of the object allocation area based on the total available memory, but reserving some space for forwarding blocks. */
/*	Assume: image reader initializes the following variables:
		memory
		endOfMemory
		memoryLimit
		specialObjectsOop
		lastHash
	 */
/*	di 11/18/2000 fix slow full GC */

int initializeObjectMemory(int bytesToShift) {
    int header;
    int oop;
    int totalObjects;
    int chunk;
    int extra;
    int fieldOop;
    int newClassOop;
    int fieldAddr;
    int classHeader;
    int extra1;
    int type;
    int sz;
    int extra2;
    int header1;
    int extra11;
    int type1;


	/* image may be at a different address; adjust oops for new location */

	youngStart = endOfMemory;
	/* begin adjustAllOopsBy: */
	totalObjects = 0;
	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	oop = chunk + extra;
	while (oop < endOfMemory) {
		if (!(((longAt(oop)) & 3) == 2)) {
			totalObjects += 1;
			header = longAt(oop);
			longAtput(oop, header & 3221225471U);
			/* begin adjustFieldsAndClassOf:by: */
			fieldAddr = oop + (lastPointerOf(oop));
			while (fieldAddr > oop) {
				fieldOop = longAt(fieldAddr);
				if (!((fieldOop & 1))) {
					longAtput(fieldAddr, fieldOop + bytesToShift);
				}
				fieldAddr -= 4;
			}
			if (((longAt(oop)) & 3) != 3) {
				classHeader = longAt(oop - 4);
				newClassOop = (classHeader & 4294967292U) + bytesToShift;
				longAtput(oop - 4, newClassOop | (classHeader & 3));
			}
		}
		/* begin objectAfter: */
		;
		if (((longAt(oop)) & 3) == 2) {
			sz = (longAt(oop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(oop);
			if ((header1 & 3) == 0) {
				sz = (longAt(oop - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header1 & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(oop + sz)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		oop = (oop + sz) + extra2;
	}
	totalObjectCount = totalObjects;
	initializeMemoryFirstFree(endOfMemory);

	/* heavily used special objects */

	specialObjectsOop += bytesToShift;
	nilObj = longAt(((((char *) specialObjectsOop)) + 4) + (0 << 2));
	falseObj = longAt(((((char *) specialObjectsOop)) + 4) + (1 << 2));
	trueObj = longAt(((((char *) specialObjectsOop)) + 4) + (2 << 2));
	rootTableCount = 0;
	child = 0;
	field = 0;
	parentField = 0;
	freeContexts = 1;
	freeLargeContexts = 1;
	allocationCount = 0;
	lowSpaceThreshold = 0;
	signalLowSpace = 0;
	compStart = 0;
	compEnd = 0;
	fwdTableNext = 0;
	fwdTableLast = 0;
	remapBufferCount = 0;

	/* do incremental GC after this many allocations */

	allocationsBetweenGCs = 4000;

	/* tenure all suriving objects if count is over this threshold */

	tenuringThreshold = 2000;

	/* four megabyte of headroom when growing */

	growHeadroom = (4 * 1024) * 1024;

	/* eight megabyte of free space before shrinking */
	/* garbage collection statistics */

	shrinkThreshold = (8 * 1024) * 1024;
	statFullGCs = 0;
	statFullGCMSecs = 0;
	statIncrGCs = 0;
	statIncrGCMSecs = 0;
	statTenures = 0;
	statRootTableOverflows = 0;
	displayBits = 0;
}


/*	Install the oop of this object in the given cache (at or atPut), along with
	its size, format and fixedSize */

int installinAtCacheatstring(int rcvr, int *cache, int atIx, int stringy) {
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int sz;
    int classFormat;
    int class;
    int ccIndex;

	hdr = longAt(rcvr);
	fmt = (((unsigned) hdr) >> 8) & 15;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(rcvr - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l1;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l2;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l2;
	}
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(rcvr - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l2:	/* end fixedFieldsOf:format:length: */;
	cache[atIx + 1] = rcvr;
	if (stringy) {
		cache[atIx + 3] = (fmt + 16);
	} else {
		cache[atIx + 3] = fmt;
	}
	cache[atIx + 4] = fixedFields;
	cache[atIx + 2] = (totalLength - fixedFields);
}


/*	
	NOTE: This method supports the backward-compatible split instSize field of the
	class format word.  The sizeHiBits will go away and other shifts change by 2
	when the split fields get merged in an (incompatible) image change.
 */

int instantiateClassindexableSize(int classPointer, int size) {
    int byteSize;
    int newObj;
    int fillWord;
    int hash;
    int format;
    int sizeHiBits;
    int binc;
    int header1;
    int hdrSize;
    int header2;
    int header3;
    int cClass;
    int inc;
    int remappedClassOop;
    int newObj1;
    int end;
    int i;
    int oop;
    int enoughSpace;
    int newChunk;
    int newFreeSize;
    int minFree;

	;
	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;

	/* Low 2 bits are 0 */

	header1 = (longAt(((((char *) classPointer)) + 4) + (2 << 2))) - 1;
	sizeHiBits = ((unsigned) (header1 & 393216)) >> 9;
	header1 = (header1 & 131071) | ((hash << 17) & 536739840);
	header2 = classPointer;
	header3 = 0;

	/* compact class field from format word */

	cClass = header1 & 126976;

	/* size in bytes -- low 2 bits are 0 */

	byteSize = (header1 & 252) + sizeHiBits;
	format = (((unsigned) header1) >> 8) & 15;
	if (format < 8) {
		inc = size * 4;
	} else {

		/* round up */

		inc = (size + 3) & 4294967292U;

		/* odd bytes */
		/* low bits of byte size go in format field */

		binc = 3 - ((size + 3) & 3);
		header1 = header1 | (binc << 8);
	}
	if ((byteSize + inc) > 255) {
		header3 = byteSize + inc;
		header1 -= byteSize & 255;
	} else {
		header1 += inc;
	}
	byteSize += inc;
	if (header3 > 0) {
		hdrSize = 3;
	} else {
		if (cClass == 0) {
			hdrSize = 2;
		} else {
			hdrSize = 1;
		}
	}
	if (format <= 4) {
		fillWord = nilObj;
	} else {
		fillWord = 0;
	}
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		remapBuffer[remapBufferCount += 1] = header2;
	}
	/* begin allocateChunk: */
	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + (byteSize + ((hdrSize - 1) * 4))) + 4;
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;
		lowSpaceThreshold = 0;
		interruptCheckCounter = 0;
	}
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) < (((unsigned ) ((byteSize + ((hdrSize - 1) * 4)) + 4)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & 4294967292U) - (byteSize + ((hdrSize - 1) * 4));
	newChunk = freeBlock;
	freeBlock += byteSize + ((hdrSize - 1) * 4);
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & 4294967292U) | 2);
	allocationCount += 1;
	newObj1 = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = remapBuffer[remapBufferCount];
		remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj1, header3 | 0);
		longAtput(newObj1 + 4, remappedClassOop | 0);
		longAtput(newObj1 + 8, header1 | 0);
		newObj1 += 8;
	}
	if (hdrSize == 2) {
		longAtput(newObj1, remappedClassOop | 1);
		longAtput(newObj1 + 4, header1 | 1);
		newObj1 += 4;
	}
	if (hdrSize == 1) {
		longAtput(newObj1, header1 | 3);
	}
		end = newObj1 + byteSize;
	i = newObj1 + 4;
	while (i < end) {
		longAtput(i, fillWord);
		i += 4;
	}
;
	;
	newObj = newObj1;
	return newObj;
}


/*	This version of instantiateClass assumes that the total object size is under 256 bytes, the limit for objects with only one or two header words. Note that the size is specified in bytes and should include four bytes for the base header word. */

int instantiateContextsizeInBytes(int classPointer, int sizeInBytes) {
    int hash;
    int header1;
    int hdrSize;
    int header2;
    int remappedClassOop;
    int newObj;
    int end;
    int i;
    int oop;
    int enoughSpace;
    int newChunk;
    int newFreeSize;
    int minFree;

	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;
	header1 = ((hash << 17) & 536739840) | ((longAt(((((char *) classPointer)) + 4) + (2 << 2))) - 1);
	header1 += sizeInBytes - (header1 & 252);
	header2 = classPointer;
	if ((header1 & 126976) == 0) {
		hdrSize = 2;
	} else {
		hdrSize = 1;
	}
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		remapBuffer[remapBufferCount += 1] = header2;
	}
	/* begin allocateChunk: */
	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + (sizeInBytes + ((hdrSize - 1) * 4))) + 4;
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;
		lowSpaceThreshold = 0;
		interruptCheckCounter = 0;
	}
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) < (((unsigned ) ((sizeInBytes + ((hdrSize - 1) * 4)) + 4)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & 4294967292U) - (sizeInBytes + ((hdrSize - 1) * 4));
	newChunk = freeBlock;
	freeBlock += sizeInBytes + ((hdrSize - 1) * 4);
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & 4294967292U) | 2);
	allocationCount += 1;
	newObj = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = remapBuffer[remapBufferCount];
		remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj, 0 | 0);
		longAtput(newObj + 4, remappedClassOop | 0);
		longAtput(newObj + 8, header1 | 0);
		newObj += 8;
	}
	if (hdrSize == 2) {
		longAtput(newObj, remappedClassOop | 1);
		longAtput(newObj + 4, header1 | 1);
		newObj += 4;
	}
	if (hdrSize == 1) {
		longAtput(newObj, header1 | 3);
	}
	;
	;
	return newObj;
}


/*	This version of instantiateClass assumes that the total object size is under 256 bytes, the limit for objects with only one or two header words. Note that the size is specified in bytes and should include four bytes for the base header word. */

int instantiateSmallClasssizeInBytesfill(int classPointer, int sizeInBytes, int fillValue) {
    int hash;
    int header1;
    int hdrSize;
    int header2;
    int remappedClassOop;
    int newObj;
    int end;
    int i;
    int oop;
    int enoughSpace;
    int newChunk;
    int newFreeSize;
    int minFree;

	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;
	header1 = ((hash << 17) & 536739840) | ((longAt(((((char *) classPointer)) + 4) + (2 << 2))) - 1);
	header1 += sizeInBytes - (header1 & 252);
	header2 = classPointer;
	if ((header1 & 126976) == 0) {
		hdrSize = 2;
	} else {
		hdrSize = 1;
	}
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		remapBuffer[remapBufferCount += 1] = header2;
	}
	/* begin allocateChunk: */
	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + (sizeInBytes + ((hdrSize - 1) * 4))) + 4;
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;
		lowSpaceThreshold = 0;
		interruptCheckCounter = 0;
	}
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) < (((unsigned ) ((sizeInBytes + ((hdrSize - 1) * 4)) + 4)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & 4294967292U) - (sizeInBytes + ((hdrSize - 1) * 4));
	newChunk = freeBlock;
	freeBlock += sizeInBytes + ((hdrSize - 1) * 4);
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & 4294967292U) | 2);
	allocationCount += 1;
	newObj = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = remapBuffer[remapBufferCount];
		remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj, 0 | 0);
		longAtput(newObj + 4, remappedClassOop | 0);
		longAtput(newObj + 8, header1 | 0);
		newObj += 8;
	}
	if (hdrSize == 2) {
		longAtput(newObj, remappedClassOop | 1);
		longAtput(newObj + 4, header1 | 1);
		newObj += 4;
	}
	if (hdrSize == 1) {
		longAtput(newObj, header1 | 3);
	}
		end = newObj + sizeInBytes;
	i = newObj + 4;
	while (i < end) {
		longAtput(i, fillValue);
		i += 4;
	}
;
	;
	return newObj;
}

int integerObjectOf(int value) {
	if (value < 0) {
		return ((2147483648U + value) << 1) + 1;
	} else {
		return (value << 1) + 1;
	}
}


/*	Translator produces 'objectPointer >> 1' */

int integerValueOf(int objectPointer) {
	if ((objectPointer & 2147483648U) != 0) {
		return ((((unsigned) (objectPointer & 2147483647U)) >> 1) - 1073741823) - 1;
	} else {
		return ((unsigned) objectPointer) >> 1;
	}
}


/*	This is the main interpreter loop. It normally loops forever, fetching and executing bytecodes. When running in the context of a browser plugin VM, however, it must return control to the browser periodically. This should done only when the state of the currently running Squeak thread is safely stored in the object heap. Since this is the case at the moment that a check for interrupts is performed, that is when we return to the browser if it is time to do so. Interrupt checks happen quite frequently. */
/*	record entry time when running as a browser plug-in */

int interpret(void) {
    int localHomeContext;
    char* localSP;
    char* localIP;
    int currentBytecode;
    int t1;
    int t2;
    int t3;
    int t4;
    int t5;
    int t6;
    int t7;
    int t8;
    int t9;
    int t10;
    int t11;
    int t12;
    int t13;
    int t14;
    int t15;
    int t16;
    int t17;
    int t18;
    int t19;
    int t20;
    int t21;
    int t22;
    int t23;
    int t24;
    int t25;
    int t26;
    int t27;
    int t28;
    int t29;
    int t30;
    int t31;
    int t32;
    int t33;
    int t34;
    int t35;
    int t36;
    int t37;
    int t38;
    int t39;
    int t40;
    int t41;
    int t42;
    int t43;
    int t44;
    int t45;
    int t46;
    int t47;
    int t48;
    int t49;

	;
	/* begin internalizeIPandSP */
	localIP = ((char *) instructionPointer);
	localSP = ((char *) stackPointer);
	localHomeContext = theHomeContext;
	/* begin fetchNextBytecode */
	currentBytecode = byteAt(++localIP);
	while (1) {
		switch (currentBytecode) {
		case 0:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((0 & 15) << 2)));
			break;
		case 1:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((1 & 15) << 2)));
			break;
		case 2:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((2 & 15) << 2)));
			break;
		case 3:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((3 & 15) << 2)));
			break;
		case 4:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((4 & 15) << 2)));
			break;
		case 5:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((5 & 15) << 2)));
			break;
		case 6:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((6 & 15) << 2)));
			break;
		case 7:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((7 & 15) << 2)));
			break;
		case 8:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((8 & 15) << 2)));
			break;
		case 9:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((9 & 15) << 2)));
			break;
		case 10:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((10 & 15) << 2)));
			break;
		case 11:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((11 & 15) << 2)));
			break;
		case 12:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((12 & 15) << 2)));
			break;
		case 13:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((13 & 15) << 2)));
			break;
		case 14:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((14 & 15) << 2)));
			break;
		case 15:
			/* pushReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushReceiverVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + ((15 & 15) << 2)));
			break;
		case 16:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((16 & 15) + 6) << 2)));
			break;
		case 17:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((17 & 15) + 6) << 2)));
			break;
		case 18:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((18 & 15) + 6) << 2)));
			break;
		case 19:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((19 & 15) + 6) << 2)));
			break;
		case 20:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((20 & 15) + 6) << 2)));
			break;
		case 21:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((21 & 15) + 6) << 2)));
			break;
		case 22:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((22 & 15) + 6) << 2)));
			break;
		case 23:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((23 & 15) + 6) << 2)));
			break;
		case 24:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((24 & 15) + 6) << 2)));
			break;
		case 25:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((25 & 15) + 6) << 2)));
			break;
		case 26:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((26 & 15) + 6) << 2)));
			break;
		case 27:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((27 & 15) + 6) << 2)));
			break;
		case 28:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((28 & 15) + 6) << 2)));
			break;
		case 29:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((29 & 15) + 6) << 2)));
			break;
		case 30:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((30 & 15) + 6) << 2)));
			break;
		case 31:
			/* pushTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushTemporaryVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + (((31 & 15) + 6) << 2)));
			break;
		case 32:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((32 & 31) + 1) << 2)));
			break;
		case 33:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((33 & 31) + 1) << 2)));
			break;
		case 34:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((34 & 31) + 1) << 2)));
			break;
		case 35:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((35 & 31) + 1) << 2)));
			break;
		case 36:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((36 & 31) + 1) << 2)));
			break;
		case 37:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((37 & 31) + 1) << 2)));
			break;
		case 38:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((38 & 31) + 1) << 2)));
			break;
		case 39:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((39 & 31) + 1) << 2)));
			break;
		case 40:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((40 & 31) + 1) << 2)));
			break;
		case 41:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((41 & 31) + 1) << 2)));
			break;
		case 42:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((42 & 31) + 1) << 2)));
			break;
		case 43:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((43 & 31) + 1) << 2)));
			break;
		case 44:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((44 & 31) + 1) << 2)));
			break;
		case 45:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((45 & 31) + 1) << 2)));
			break;
		case 46:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((46 & 31) + 1) << 2)));
			break;
		case 47:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((47 & 31) + 1) << 2)));
			break;
		case 48:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((48 & 31) + 1) << 2)));
			break;
		case 49:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((49 & 31) + 1) << 2)));
			break;
		case 50:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((50 & 31) + 1) << 2)));
			break;
		case 51:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((51 & 31) + 1) << 2)));
			break;
		case 52:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((52 & 31) + 1) << 2)));
			break;
		case 53:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((53 & 31) + 1) << 2)));
			break;
		case 54:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((54 & 31) + 1) << 2)));
			break;
		case 55:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((55 & 31) + 1) << 2)));
			break;
		case 56:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((56 & 31) + 1) << 2)));
			break;
		case 57:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((57 & 31) + 1) << 2)));
			break;
		case 58:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((58 & 31) + 1) << 2)));
			break;
		case 59:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((59 & 31) + 1) << 2)));
			break;
		case 60:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((60 & 31) + 1) << 2)));
			break;
		case 61:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((61 & 31) + 1) << 2)));
			break;
		case 62:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((62 & 31) + 1) << 2)));
			break;
		case 63:
			/* pushLiteralConstantBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralConstant: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) method)) + 4) + (((63 & 31) + 1) << 2)));
			break;
		case 64:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((64 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 65:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((65 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 66:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((66 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 67:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((67 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 68:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((68 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 69:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((69 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 70:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((70 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 71:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((71 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 72:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((72 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 73:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((73 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 74:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((74 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 75:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((75 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 76:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((76 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 77:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((77 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 78:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((78 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 79:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((79 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 80:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((80 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 81:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((81 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 82:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((82 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 83:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((83 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 84:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((84 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 85:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((85 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 86:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((86 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 87:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((87 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 88:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((88 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 89:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((89 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 90:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((90 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 91:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((91 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 92:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((92 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 93:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((93 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 94:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((94 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 95:
			/* pushLiteralVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin pushLiteralVariable: */
			/* begin internalPush: */
			longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + (((95 & 31) + 1) << 2))))) + 4) + (1 << 2)));
			break;
		case 96:
			/* storeAndPopReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = receiver;
			t1 = longAt(localSP);
			if (t2 < youngStart) {
				possibleRootStoreIntovalue(t2, t1);
			}
			longAtput(((((char *) t2)) + 4) + ((96 & 7) << 2), t1);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 97:
			/* storeAndPopReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = receiver;
			t1 = longAt(localSP);
			if (t2 < youngStart) {
				possibleRootStoreIntovalue(t2, t1);
			}
			longAtput(((((char *) t2)) + 4) + ((97 & 7) << 2), t1);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 98:
			/* storeAndPopReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = receiver;
			t1 = longAt(localSP);
			if (t2 < youngStart) {
				possibleRootStoreIntovalue(t2, t1);
			}
			longAtput(((((char *) t2)) + 4) + ((98 & 7) << 2), t1);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 99:
			/* storeAndPopReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = receiver;
			t1 = longAt(localSP);
			if (t2 < youngStart) {
				possibleRootStoreIntovalue(t2, t1);
			}
			longAtput(((((char *) t2)) + 4) + ((99 & 7) << 2), t1);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 100:
			/* storeAndPopReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = receiver;
			t1 = longAt(localSP);
			if (t2 < youngStart) {
				possibleRootStoreIntovalue(t2, t1);
			}
			longAtput(((((char *) t2)) + 4) + ((100 & 7) << 2), t1);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 101:
			/* storeAndPopReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = receiver;
			t1 = longAt(localSP);
			if (t2 < youngStart) {
				possibleRootStoreIntovalue(t2, t1);
			}
			longAtput(((((char *) t2)) + 4) + ((101 & 7) << 2), t1);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 102:
			/* storeAndPopReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = receiver;
			t1 = longAt(localSP);
			if (t2 < youngStart) {
				possibleRootStoreIntovalue(t2, t1);
			}
			longAtput(((((char *) t2)) + 4) + ((102 & 7) << 2), t1);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 103:
			/* storeAndPopReceiverVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = receiver;
			t1 = longAt(localSP);
			if (t2 < youngStart) {
				possibleRootStoreIntovalue(t2, t1);
			}
			longAtput(((((char *) t2)) + 4) + ((103 & 7) << 2), t1);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 104:
			/* storeAndPopTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			longAtput(((((char *) localHomeContext)) + 4) + (((104 & 7) + 6) << 2), longAt(localSP));
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 105:
			/* storeAndPopTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			longAtput(((((char *) localHomeContext)) + 4) + (((105 & 7) + 6) << 2), longAt(localSP));
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 106:
			/* storeAndPopTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			longAtput(((((char *) localHomeContext)) + 4) + (((106 & 7) + 6) << 2), longAt(localSP));
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 107:
			/* storeAndPopTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			longAtput(((((char *) localHomeContext)) + 4) + (((107 & 7) + 6) << 2), longAt(localSP));
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 108:
			/* storeAndPopTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			longAtput(((((char *) localHomeContext)) + 4) + (((108 & 7) + 6) << 2), longAt(localSP));
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 109:
			/* storeAndPopTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			longAtput(((((char *) localHomeContext)) + 4) + (((109 & 7) + 6) << 2), longAt(localSP));
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 110:
			/* storeAndPopTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			longAtput(((((char *) localHomeContext)) + 4) + (((110 & 7) + 6) << 2), longAt(localSP));
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 111:
			/* storeAndPopTemporaryVariableBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			longAtput(((((char *) localHomeContext)) + 4) + (((111 & 7) + 6) << 2), longAt(localSP));
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 112:
			/* pushReceiverBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, receiver);
			break;
		case 113:
			/* pushConstantTrueBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, trueObj);
			break;
		case 114:
			/* pushConstantFalseBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, falseObj);
			break;
		case 115:
			/* pushConstantNilBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, nilObj);
			break;
		case 116:
			/* pushConstantMinusOneBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, 4294967295U);
			break;
		case 117:
			/* pushConstantZeroBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, 1);
			break;
		case 118:
			/* pushConstantOneBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, 3);
			break;
		case 119:
			/* pushConstantTwoBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, 5);
			break;
		case 120:
			/* returnReceiver */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = receiver;
			/* begin returnValue:to: */
		commonReturn:	/*  */;
			t5 = nilObj;
			t4 = activeContext;
			if ((t2 == t5) || ((longAt(((((char *) t2)) + 4) + (1 << 2))) == t5)) {
				/* begin internalCannotReturn: */
				/* begin internalPush: */
				longAtput(localSP += 4, activeContext);
				/* begin internalPush: */
				longAtput(localSP += 4, t1);
				messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (21 << 2));
				argumentCount = 1;
				/* begin normalSend */
				goto commonSend;
			l4:	/* end fetchClassOf: */;
			l2:	/* end lookupInMethodCacheSel:class: */;
			l3:	/* end internalExecuteNewMethod */;
			}
			t4 = longAt(((((char *) activeContext)) + 4) + (0 << 2));
			while (!(t4 == t2)) {
				if (t4 == nilObj) {
					/* begin internalCannotReturn: */
					/* begin internalPush: */
					longAtput(localSP += 4, activeContext);
					/* begin internalPush: */
					longAtput(localSP += 4, t1);
					messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (21 << 2));
					argumentCount = 1;
					/* begin normalSend */
					goto commonSend;
				l5:	/* end fetchClassOf: */;
				l6:	/* end lookupInMethodCacheSel:class: */;
				l7:	/* end internalExecuteNewMethod */;
				}
				if (isUnwindMarked(t4)) {
					/* begin internalAboutToReturn:through: */
					/* begin internalPush: */
					longAtput(localSP += 4, activeContext);
					/* begin internalPush: */
					longAtput(localSP += 4, t1);
					/* begin internalPush: */
					longAtput(localSP += 4, t4);
					messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (48 << 2));
					argumentCount = 2;
					/* begin normalSend */
					goto commonSend;
				l8:	/* end fetchClassOf: */;
				l9:	/* end lookupInMethodCacheSel:class: */;
				l10:	/* end internalExecuteNewMethod */;
				}
				t4 = longAt(((((char *) t4)) + 4) + (0 << 2));
			}
			t4 = activeContext;
			while (!(t4 == t2)) {
				t3 = longAt(((((char *) t4)) + 4) + (0 << 2));
				longAtput(((((char *) t4)) + 4) + (0 << 2), t5);
				longAtput(((((char *) t4)) + 4) + (1 << 2), t5);
				if (reclaimableContextCount > 0) {
					reclaimableContextCount -= 1;
					/* begin recycleContextIfPossible: */
					if (t4 >= youngStart) {
						t6 = longAt(t4);
						if (((((unsigned) t6) >> 12) & 31) == 14) {
							if ((t6 & 252) == 92) {
								longAtput(((((char *) t4)) + 4) + (0 << 2), freeContexts);
								freeContexts = t4;
							}
							if ((t6 & 252) == 252) {
								longAtput(((((char *) t4)) + 4) + (0 << 2), freeLargeContexts);
								freeLargeContexts = t4;
							}
						}
					}
				}
				t4 = t3;
			}
			activeContext = t4;
			if (t4 < youngStart) {
				beRootIfOld(t4);
			}
			/* begin internalFetchContextRegisters: */
			t7 = longAt(((((char *) t4)) + 4) + (3 << 2));
			if ((t7 & 1)) {
				t7 = longAt(((((char *) t4)) + 4) + (5 << 2));
				if (t7 < youngStart) {
					beRootIfOld(t7);
				}
			} else {
				t7 = t4;
			}
			localHomeContext = t7;
			receiver = longAt(((((char *) t7)) + 4) + (5 << 2));
			method = longAt(((((char *) t7)) + 4) + (3 << 2));
			t7 = ((longAt(((((char *) t4)) + 4) + (1 << 2))) >> 1);
			localIP = ((char *) (((method + t7) + 4) - 2));
			t7 = ((longAt(((((char *) t4)) + 4) + (2 << 2))) >> 1);
			localSP = ((char *) ((t4 + 4) + (((6 + t7) - 1) * 4)));
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			longAtput(localSP += 4, t1);
		l1:	/* end returnValue:to: */;
			break;
		case 121:
			/* returnTrue */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = trueObj;
			/* begin returnValue:to: */
			goto commonReturn;
		l11:	/* end returnValue:to: */;
			break;
		case 122:
			/* returnFalse */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = falseObj;
			/* begin returnValue:to: */
			goto commonReturn;
		l21:	/* end returnValue:to: */;
			break;
		case 123:
			/* returnNil */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = nilObj;
			/* begin returnValue:to: */
			goto commonReturn;
		l31:	/* end returnValue:to: */;
			break;
		case 124:
			/* returnTopFromMethod */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = longAt(localSP);
			/* begin returnValue:to: */
			goto commonReturn;
		l41:	/* end returnValue:to: */;
			break;
		case 125:
			/* returnTopFromBlock */
			t2 = longAt(((((char *) activeContext)) + 4) + (0 << 2));
			t1 = longAt(localSP);
			/* begin returnValue:to: */
			goto commonReturn;
		l51:	/* end returnValue:to: */;
			break;
		case 126:
		case 127:
			/* unknownBytecode */
			error("Unknown bytecode");
			break;
		case 128:
			/* extendedPushBytecode */
			t1 = byteAt(++localIP);
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = (((unsigned) t1) >> 6) & 3;
			t3 = t1 & 63;
			if (t2 == 0) {
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + (t3 << 2)));
				goto l61;
			}
			if (t2 == 1) {
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + ((t3 + 6) << 2)));
				goto l61;
			}
			if (t2 == 2) {
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) method)) + 4) + ((t3 + 1) << 2)));
				goto l61;
			}
			if (t2 == 3) {
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + ((t3 + 1) << 2))))) + 4) + (1 << 2)));
				goto l61;
			}
		l61:	/* end case */;
			break;
		case 129:
			/* extendedStoreBytecode */
			t2 = byteAt(++localIP);
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t3 = (((unsigned) t2) >> 6) & 3;
			t4 = t2 & 63;
			if (t3 == 0) {
				/* begin storePointer:ofObject:withValue: */
				t5 = receiver;
				t6 = longAt(localSP);
				if (t5 < youngStart) {
					possibleRootStoreIntovalue(t5, t6);
				}
				longAtput(((((char *) t5)) + 4) + (t4 << 2), t6);
				goto l62;
			}
			if (t3 == 1) {
				longAtput(((((char *) localHomeContext)) + 4) + ((t4 + 6) << 2), longAt(localSP));
				goto l62;
			}
			if (t3 == 2) {
				error("illegal store");
			}
			if (t3 == 3) {
				t1 = longAt(((((char *) method)) + 4) + ((t4 + 1) << 2));
				/* begin storePointer:ofObject:withValue: */
				t7 = longAt(localSP);
				if (t1 < youngStart) {
					possibleRootStoreIntovalue(t1, t7);
				}
				longAtput(((((char *) t1)) + 4) + (1 << 2), t7);
				goto l62;
			}
		l62:	/* end case */;
			break;
		case 130:
			/* extendedStoreAndPopBytecode */
			/* begin extendedStoreBytecode */
			t2 = byteAt(++localIP);
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t3 = (((unsigned) t2) >> 6) & 3;
			t4 = t2 & 63;
			if (t3 == 0) {
				/* begin storePointer:ofObject:withValue: */
				t5 = receiver;
				t6 = longAt(localSP);
				if (t5 < youngStart) {
					possibleRootStoreIntovalue(t5, t6);
				}
				longAtput(((((char *) t5)) + 4) + (t4 << 2), t6);
				goto l63;
			}
			if (t3 == 1) {
				longAtput(((((char *) localHomeContext)) + 4) + ((t4 + 6) << 2), longAt(localSP));
				goto l63;
			}
			if (t3 == 2) {
				error("illegal store");
			}
			if (t3 == 3) {
				t1 = longAt(((((char *) method)) + 4) + ((t4 + 1) << 2));
				/* begin storePointer:ofObject:withValue: */
				t7 = longAt(localSP);
				if (t1 < youngStart) {
					possibleRootStoreIntovalue(t1, t7);
				}
				longAtput(((((char *) t1)) + 4) + (1 << 2), t7);
				goto l63;
			}
		l63:	/* end extendedStoreBytecode */;
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 131:
			/* singleExtendedSendBytecode */
			t1 = byteAt(++localIP);
			messageSelector = longAt(((((char *) method)) + 4) + (((t1 & 31) + 1) << 2));
			argumentCount = ((unsigned) t1) >> 5;
			/* begin normalSend */
		commonSend:	/*  */;
			t2 = longAt(localSP - (argumentCount * 4));
			/* begin fetchClassOf: */
			if ((t2 & 1)) {
				lkupClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
				goto l64;
			}
			t3 = (((unsigned) (longAt(t2))) >> 12) & 31;
			if (t3 == 0) {
				lkupClass = (longAt(t2 - 4)) & 4294967292U;
				goto l64;
			} else {
				lkupClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t3 - 1) << 2));
				goto l64;
			}
		l64:	/* end fetchClassOf: */;
			receiverClass = lkupClass;
		commonLookup:	/*  */;
			/* begin lookupInMethodCacheSel:class: */
			t5 = messageSelector ^ lkupClass;
			t6 = t5 & 4088;
			if (((methodCache[t6 + 1]) == messageSelector) && ((methodCache[t6 + 2]) == lkupClass)) {
				newMethod = methodCache[t6 + 3];
				primitiveIndex = methodCache[t6 + 4];
				newNativeMethod = methodCache[t6 + 5];
				t4 = 1;
				goto l65;
			}
			t6 = (((unsigned) t5) >> 1) & 4088;
			if (((methodCache[t6 + 1]) == messageSelector) && ((methodCache[t6 + 2]) == lkupClass)) {
				newMethod = methodCache[t6 + 3];
				primitiveIndex = methodCache[t6 + 4];
				newNativeMethod = methodCache[t6 + 5];
				t4 = 1;
				goto l65;
			}
			t6 = (((unsigned) t5) >> 2) & 4088;
			if (((methodCache[t6 + 1]) == messageSelector) && ((methodCache[t6 + 2]) == lkupClass)) {
				newMethod = methodCache[t6 + 3];
				primitiveIndex = methodCache[t6 + 4];
				newNativeMethod = methodCache[t6 + 5];
				t4 = 1;
				goto l65;
			}
			t4 = 0;
		l65:	/* end lookupInMethodCacheSel:class: */;
			if (!(t4)) {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				lookupMethodInClass(lkupClass);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				addNewMethodToCache();
			}
			/* begin internalExecuteNewMethod */
			t7 = primitiveIndex;
			if (t7 > 0) {
				if ((t7 > 255) && (t7 < 520)) {
					if (t7 >= 264) {
						/* begin internalPop:thenPush: */
						t8 = longAt(((((char *) (longAt(localSP)))) + 4) + ((t7 - 264) << 2));
						longAtput(localSP -= (1 - 1) * 4, t8);
						goto l66;
					} else {
						if (t7 == 256) {
							goto l66;
						}
						if (t7 == 257) {
							/* begin internalPop:thenPush: */
							longAtput(localSP -= (1 - 1) * 4, trueObj);
							goto l66;
						}
						if (t7 == 258) {
							/* begin internalPop:thenPush: */
							longAtput(localSP -= (1 - 1) * 4, falseObj);
							goto l66;
						}
						if (t7 == 259) {
							/* begin internalPop:thenPush: */
							longAtput(localSP -= (1 - 1) * 4, nilObj);
							goto l66;
						}
						/* begin internalPop:thenPush: */
						longAtput(localSP -= (1 - 1) * 4, (((t7 - 261) << 1) | 1));
						goto l66;
					}
				} else {
					/* begin externalizeIPandSP */
					instructionPointer = ((int) localIP);
					stackPointer = ((int) localSP);
					theHomeContext = localHomeContext;
					primitiveResponse();
					/* begin internalizeIPandSP */
					localIP = ((char *) instructionPointer);
					localSP = ((char *) stackPointer);
					localHomeContext = theHomeContext;
					if (successFlag) {
						;
						goto l66;
					}
				}
			}
			/* begin internalActivateNewMethod */
			t13 = longAt(((((char *) newMethod)) + 4) + (0 << 2));
			t10 = t13 & 262144;
			if ((t10 == 0) && (freeContexts != 1)) {
				t12 = freeContexts;
				freeContexts = longAt(((((char *) t12)) + 4) + (0 << 2));
			} else {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				t12 = allocateOrRecycleContext(t10);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
			}
			t14 = (((unsigned) t13) >> 19) & 63;
			longAtput(((((char *) t12)) + 4) + (0 << 2), activeContext);
			longAtput(((((char *) t12)) + 4) + (1 << 2), (((((1 + ((((unsigned) t13) >> 10) & 255)) * 4) + 1) << 1) | 1));
			longAtput(((((char *) t12)) + 4) + (2 << 2), ((t14 << 1) | 1));
			longAtput(((((char *) t12)) + 4) + (3 << 2), newMethod);
			t11 = argumentCount;
			for (t9 = 0; t9 <= t11; t9 += 1) {
				longAtput(((((char *) t12)) + 4) + ((5 + t9) << 2), longAt(localSP - ((t11 - t9) * 4)));
			}
			t13 = nilObj;
			for (t9 = (t11 + 1); t9 <= t14; t9 += 1) {
				longAtput(((((char *) t12)) + 4) + ((5 + t9) << 2), t13);
			}
			/* begin internalPop: */
			localSP -= (t11 + 1) * 4;
			reclaimableContextCount += 1;
			/* begin internalNewActiveContext: */
			/* begin internalStoreContextRegisters: */
			longAtput(((((char *) activeContext)) + 4) + (1 << 2), (((((((int) localIP )) + 2) - (method + 4)) << 1) | 1));
			longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((((int) localSP )) - (activeContext + 4))) >> 2) - 6) + 1) << 1) | 1));
			if (t12 < youngStart) {
				beRootIfOld(t12);
			}
			activeContext = t12;
			/* begin internalFetchContextRegisters: */
			t15 = longAt(((((char *) t12)) + 4) + (3 << 2));
			if ((t15 & 1)) {
				t15 = longAt(((((char *) t12)) + 4) + (5 << 2));
				if (t15 < youngStart) {
					beRootIfOld(t15);
				}
			} else {
				t15 = t12;
			}
			localHomeContext = t15;
			receiver = longAt(((((char *) t15)) + 4) + (5 << 2));
			method = longAt(((((char *) t15)) + 4) + (3 << 2));
			t15 = ((longAt(((((char *) t12)) + 4) + (1 << 2))) >> 1);
			localIP = ((char *) (((method + t15) + 4) - 2));
			t15 = ((longAt(((((char *) t12)) + 4) + (2 << 2))) >> 1);
			localSP = ((char *) ((t12 + 4) + (((6 + t15) - 1) * 4)));
			/* begin internalQuickCheckForInterrupts */
			if ((interruptCheckCounter -= 1) <= 0) {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				checkForInterrupts();
				;
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
			}
		l66:	/* end internalExecuteNewMethod */;
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			break;
		case 132:
			/* doubleExtendedDoAnythingBytecode */
			t4 = byteAt(++localIP);
			t1 = byteAt(++localIP);
			t2 = ((unsigned) t4) >> 5;
			if (t2 == 0) {
				messageSelector = longAt(((((char *) method)) + 4) + ((t1 + 1) << 2));
				argumentCount = t4 & 31;
				/* begin normalSend */
				goto commonSend;
			l71:	/* end fetchClassOf: */;
			l72:	/* end lookupInMethodCacheSel:class: */;
			l73:	/* end internalExecuteNewMethod */;
			}
			if (t2 == 1) {
				messageSelector = longAt(((((char *) method)) + 4) + ((t1 + 1) << 2));
				argumentCount = t4 & 31;
				/* begin superclassSend */
				goto commonSupersend;
			l68:	/* end fetchClassOf: */;
			l69:	/* end lookupInMethodCacheSel:class: */;
			l70:	/* end internalExecuteNewMethod */;
			}
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			if (t2 == 2) {
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + (t1 << 2)));
				goto l67;
			}
			if (t2 == 3) {
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) method)) + 4) + ((t1 + 1) << 2)));
				goto l67;
			}
			if (t2 == 4) {
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + ((t1 + 1) << 2))))) + 4) + (1 << 2)));
				goto l67;
			}
			if (t2 == 5) {
				t3 = longAt(localSP);
				/* begin storePointer:ofObject:withValue: */
				t5 = receiver;
				if (t5 < youngStart) {
					possibleRootStoreIntovalue(t5, t3);
				}
				longAtput(((((char *) t5)) + 4) + (t1 << 2), t3);
				goto l67;
			}
			if (t2 == 6) {
				t3 = longAt(localSP);
				/* begin internalPop: */
				localSP -= 1 * 4;
				/* begin storePointer:ofObject:withValue: */
				t6 = receiver;
				if (t6 < youngStart) {
					possibleRootStoreIntovalue(t6, t3);
				}
				longAtput(((((char *) t6)) + 4) + (t1 << 2), t3);
				goto l67;
			}
			if (t2 == 7) {
				t3 = longAt(localSP);
				/* begin storePointer:ofObject:withValue: */
				t7 = longAt(((((char *) method)) + 4) + ((t1 + 1) << 2));
				if (t7 < youngStart) {
					possibleRootStoreIntovalue(t7, t3);
				}
				longAtput(((((char *) t7)) + 4) + (1 << 2), t3);
				goto l67;
			}
		l67:	/* end case */;
			break;
		case 133:
			/* singleExtendedSuperBytecode */
			t1 = byteAt(++localIP);
			messageSelector = longAt(((((char *) method)) + 4) + (((t1 & 31) + 1) << 2));
			argumentCount = ((unsigned) t1) >> 5;
			/* begin superclassSend */
		commonSupersend:	/*  */;
			/* begin superclassOf: */
			t3 = longAt(((((char *) (longAt(((((char *) method)) + 4) + (((((((unsigned) (longAt(((((char *) method)) + 4) + (0 << 2)))) >> 10) & 255) - 1) + 1) << 2))))) + 4) + (1 << 2));
			lkupClass = longAt(((((char *) t3)) + 4) + (0 << 2));
			t2 = longAt(localSP - (argumentCount * 4));
			/* begin fetchClassOf: */
			if ((t2 & 1)) {
				receiverClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
				goto l74;
			}
			t4 = (((unsigned) (longAt(t2))) >> 12) & 31;
			if (t4 == 0) {
				receiverClass = (longAt(t2 - 4)) & 4294967292U;
				goto l74;
			} else {
				receiverClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t4 - 1) << 2));
				goto l74;
			}
		l74:	/* end fetchClassOf: */;
			goto commonLookup;
		l75:	/* end lookupInMethodCacheSel:class: */;
		l76:	/* end internalExecuteNewMethod */;
			break;
		case 134:
			/* secondExtendedSendBytecode */
			t1 = byteAt(++localIP);
			messageSelector = longAt(((((char *) method)) + 4) + (((t1 & 63) + 1) << 2));
			argumentCount = ((unsigned) t1) >> 6;
			/* begin normalSend */
			goto commonSend;
		l77:	/* end fetchClassOf: */;
		l78:	/* end lookupInMethodCacheSel:class: */;
		l79:	/* end internalExecuteNewMethod */;
			break;
		case 135:
			/* popStackBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPop: */
			localSP -= 1 * 4;
			break;
		case 136:
			/* duplicateTopBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			/* begin internalPush: */
			t1 = longAt(localSP);
			longAtput(localSP += 4, t1);
			break;
		case 137:
			/* pushActiveContextBytecode */
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			reclaimableContextCount = 0;
			/* begin internalPush: */
			longAtput(localSP += 4, activeContext);
			break;
		case 138:
		case 139:
		case 140:
		case 141:
		case 142:
		case 143:
			/* experimentalBytecode */
			t8 = longAt(((((char *) localHomeContext)) + 4) + (((currentBytecode - 138) + 6) << 2));
			t6 = byteAt(localIP + 1);
			t1 = byteAt(localIP + 2);
			t7 = byteAt(localIP + 3);
			if ((t8 & 1)) {
				t2 = (t8 >> 1);
			} else {
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				/* begin internalPush: */
				longAtput(localSP += 4, t8);
				goto l80;
			}
			if (t6 < 32) {
				t4 = longAt(((((char *) localHomeContext)) + 4) + (((t6 & 15) + 6) << 2));
				if ((t4 & 1)) {
					t4 = (t4 >> 1);
				} else {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					/* begin internalPush: */
					longAtput(localSP += 4, t8);
					goto l80;
				}
			} else {
				if (t6 > 64) {
					t4 = 1;
				} else {
					t4 = longAt(((((char *) method)) + 4) + (((t6 & 31) + 1) << 2));
					if ((t4 & 1)) {
						t4 = (t4 >> 1);
					} else {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						/* begin internalPush: */
						longAtput(localSP += 4, t8);
						goto l80;
					}
				}
			}
			if (t1 < 178) {
				t3 = t2 + t4;
				if ((t3 ^ (t3 << 1)) >= 0) {
					if ((t7 > 103) && (t7 < 112)) {
						localIP += 3;
						longAtput(((((char *) localHomeContext)) + 4) + (((t7 & 7) + 6) << 2), ((t3 << 1) | 1));
					} else {
						localIP += 2;
						/* begin internalPush: */
						longAtput(localSP += 4, ((t3 << 1) | 1));
					}
				} else {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					/* begin internalPush: */
					longAtput(localSP += 4, t8);
					goto l80;
				}
			} else {
				t5 = byteAt(localIP + 4);
				if (t2 <= t4) {
					localIP = (localIP + 3) + 1;
				} else {
					localIP = ((localIP + 3) + 1) + t5;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
			}
		l80:	/* end case */;
			break;
		case 144:
			/* shortUnconditionalJump */
			/* begin jump: */
			t1 = (144 & 7) + 1;
			localIP = (localIP + t1) + 1;
			currentBytecode = byteAt(localIP);
			break;
		case 145:
			/* shortUnconditionalJump */
			/* begin jump: */
			t1 = (145 & 7) + 1;
			localIP = (localIP + t1) + 1;
			currentBytecode = byteAt(localIP);
			break;
		case 146:
			/* shortUnconditionalJump */
			/* begin jump: */
			t1 = (146 & 7) + 1;
			localIP = (localIP + t1) + 1;
			currentBytecode = byteAt(localIP);
			break;
		case 147:
			/* shortUnconditionalJump */
			/* begin jump: */
			t1 = (147 & 7) + 1;
			localIP = (localIP + t1) + 1;
			currentBytecode = byteAt(localIP);
			break;
		case 148:
			/* shortUnconditionalJump */
			/* begin jump: */
			t1 = (148 & 7) + 1;
			localIP = (localIP + t1) + 1;
			currentBytecode = byteAt(localIP);
			break;
		case 149:
			/* shortUnconditionalJump */
			/* begin jump: */
			t1 = (149 & 7) + 1;
			localIP = (localIP + t1) + 1;
			currentBytecode = byteAt(localIP);
			break;
		case 150:
			/* shortUnconditionalJump */
			/* begin jump: */
			t1 = (150 & 7) + 1;
			localIP = (localIP + t1) + 1;
			currentBytecode = byteAt(localIP);
			break;
		case 151:
			/* shortUnconditionalJump */
			/* begin jump: */
			t1 = (151 & 7) + 1;
			localIP = (localIP + t1) + 1;
			currentBytecode = byteAt(localIP);
			break;
		case 152:
		case 153:
		case 154:
		case 155:
		case 156:
		case 157:
		case 158:
		case 159:
			/* shortConditionalJump */
			/* begin jumplfFalseBy: */
			t1 = (currentBytecode & 7) + 1;
			t2 = longAt(localSP);
			if (t2 == falseObj) {
				/* begin jump: */
				localIP = (localIP + t1) + 1;
				currentBytecode = byteAt(localIP);
			} else {
				if (!(t2 == trueObj)) {
					messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (25 << 2));
					argumentCount = 0;
					/* begin normalSend */
					goto commonSend;
				l82:	/* end fetchClassOf: */;
				l83:	/* end lookupInMethodCacheSel:class: */;
				l84:	/* end internalExecuteNewMethod */;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
			}
			/* begin internalPop: */
			localSP -= 1 * 4;
		l81:	/* end jumplfFalseBy: */;
			break;
		case 160:
		case 161:
		case 162:
		case 163:
		case 164:
		case 165:
		case 166:
		case 167:
			/* longUnconditionalJump */
			t1 = (((currentBytecode & 7) - 4) * 256) + (byteAt(++localIP));
			localIP += t1;
			if (t1 < 0) {
				/* begin internalQuickCheckForInterrupts */
				if ((interruptCheckCounter -= 1) <= 0) {
					/* begin externalizeIPandSP */
					instructionPointer = ((int) localIP);
					stackPointer = ((int) localSP);
					theHomeContext = localHomeContext;
					checkForInterrupts();
					;
					/* begin internalizeIPandSP */
					localIP = ((char *) instructionPointer);
					localSP = ((char *) stackPointer);
					localHomeContext = theHomeContext;
				}
			}
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			break;
		case 168:
		case 169:
		case 170:
		case 171:
			/* longJumpIfTrue */
			/* begin jumplfTrueBy: */
			t1 = ((currentBytecode & 3) * 256) + (byteAt(++localIP));
			t2 = longAt(localSP);
			if (t2 == trueObj) {
				/* begin jump: */
				localIP = (localIP + t1) + 1;
				currentBytecode = byteAt(localIP);
			} else {
				if (!(t2 == falseObj)) {
					messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (25 << 2));
					argumentCount = 0;
					/* begin normalSend */
					goto commonSend;
				l86:	/* end fetchClassOf: */;
				l87:	/* end lookupInMethodCacheSel:class: */;
				l88:	/* end internalExecuteNewMethod */;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
			}
			/* begin internalPop: */
			localSP -= 1 * 4;
		l85:	/* end jumplfTrueBy: */;
			break;
		case 172:
		case 173:
		case 174:
		case 175:
			/* longJumpIfFalse */
			/* begin jumplfFalseBy: */
			t1 = ((currentBytecode & 3) * 256) + (byteAt(++localIP));
			t2 = longAt(localSP);
			if (t2 == falseObj) {
				/* begin jump: */
				localIP = (localIP + t1) + 1;
				currentBytecode = byteAt(localIP);
			} else {
				if (!(t2 == trueObj)) {
					messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (25 << 2));
					argumentCount = 0;
					/* begin normalSend */
					goto commonSend;
				l90:	/* end fetchClassOf: */;
				l91:	/* end lookupInMethodCacheSel:class: */;
				l92:	/* end internalExecuteNewMethod */;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
			}
			/* begin internalPop: */
			localSP -= 1 * 4;
		l89:	/* end jumplfFalseBy: */;
			break;
		case 176:
			/* bytecodePrimAdd */
			t2 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t2 & t3) & 1) != 0) {
				t1 = ((t2 >> 1)) + ((t3 >> 1));
				if ((t1 ^ (t1 << 1)) >= 0) {
					/* begin internalPop:thenPush: */
					longAtput(localSP -= (2 - 1) * 4, ((t1 << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l93;
				}
			} else {
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveFloatAddtoArg(t2, t3);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l93;
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((0 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l94:	/* end fetchClassOf: */;
		l95:	/* end lookupInMethodCacheSel:class: */;
		l96:	/* end internalExecuteNewMethod */;
		l93:	/* end case */;
			break;
		case 177:
			/* bytecodePrimSubtract */
			t2 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t2 & t3) & 1) != 0) {
				t1 = ((t2 >> 1)) - ((t3 >> 1));
				if ((t1 ^ (t1 << 1)) >= 0) {
					/* begin internalPop:thenPush: */
					longAtput(localSP -= (2 - 1) * 4, ((t1 << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l97;
				}
			} else {
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveFloatSubtractfromArg(t2, t3);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l97;
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((1 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l98:	/* end fetchClassOf: */;
		l99:	/* end lookupInMethodCacheSel:class: */;
		l100:	/* end internalExecuteNewMethod */;
		l97:	/* end case */;
			break;
		case 178:
			/* bytecodePrimLessThan */
			t1 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t1 & t3) & 1) != 0) {
				;
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t1 < t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l101;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l101;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t1 < t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l101;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l101;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t1 < t3) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l101;
			}
			successFlag = 1;
			t2 = primitiveFloatLessthanArg(t1, t3);
			if (successFlag) {
				/* begin booleanCheat: */
				t8 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t8 < 160) && (t8 > 151)) {
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l101;
					} else {
						/* begin jump: */
						localIP = (localIP + (t8 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l101;
					}
				}
				if (t8 == 172) {
					t9 = byteAt(++localIP);
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l101;
					} else {
						/* begin jump: */
						localIP = (localIP + t9) + 1;
						currentBytecode = byteAt(localIP);
						goto l101;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t2) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l101;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((2 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l102:	/* end fetchClassOf: */;
		l103:	/* end lookupInMethodCacheSel:class: */;
		l104:	/* end internalExecuteNewMethod */;
		l101:	/* end case */;
			break;
		case 179:
			/* bytecodePrimGreaterThan */
			t1 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t1 & t3) & 1) != 0) {
				;
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t1 > t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l105;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l105;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t1 > t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l105;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l105;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t1 > t3) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l105;
			}
			successFlag = 1;
			t2 = primitiveFloatGreaterthanArg(t1, t3);
			if (successFlag) {
				/* begin booleanCheat: */
				t8 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t8 < 160) && (t8 > 151)) {
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l105;
					} else {
						/* begin jump: */
						localIP = (localIP + (t8 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l105;
					}
				}
				if (t8 == 172) {
					t9 = byteAt(++localIP);
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l105;
					} else {
						/* begin jump: */
						localIP = (localIP + t9) + 1;
						currentBytecode = byteAt(localIP);
						goto l105;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t2) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l105;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((3 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l106:	/* end fetchClassOf: */;
		l107:	/* end lookupInMethodCacheSel:class: */;
		l108:	/* end internalExecuteNewMethod */;
		l105:	/* end case */;
			break;
		case 180:
			/* bytecodePrimLessOrEqual */
			t1 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t1 & t3) & 1) != 0) {
				;
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t1 <= t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l109;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l109;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t1 <= t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l109;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l109;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t1 <= t3) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l109;
			}
			successFlag = 1;
			t2 = primitiveFloatGreaterthanArg(t1, t3);
			if (successFlag) {
				/* begin booleanCheat: */
				t8 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t8 < 160) && (t8 > 151)) {
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l109;
					} else {
						/* begin jump: */
						localIP = (localIP + (t8 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l109;
					}
				}
				if (t8 == 172) {
					t9 = byteAt(++localIP);
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l109;
					} else {
						/* begin jump: */
						localIP = (localIP + t9) + 1;
						currentBytecode = byteAt(localIP);
						goto l109;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (!t2) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l109;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((4 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l110:	/* end fetchClassOf: */;
		l111:	/* end lookupInMethodCacheSel:class: */;
		l112:	/* end internalExecuteNewMethod */;
		l109:	/* end case */;
			break;
		case 181:
			/* bytecodePrimGreaterOrEqual */
			t1 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t1 & t3) & 1) != 0) {
				;
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t1 >= t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l113;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l113;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t1 >= t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l113;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l113;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t1 >= t3) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l113;
			}
			successFlag = 1;
			t2 = primitiveFloatLessthanArg(t1, t3);
			if (successFlag) {
				/* begin booleanCheat: */
				t8 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t8 < 160) && (t8 > 151)) {
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l113;
					} else {
						/* begin jump: */
						localIP = (localIP + (t8 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l113;
					}
				}
				if (t8 == 172) {
					t9 = byteAt(++localIP);
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l113;
					} else {
						/* begin jump: */
						localIP = (localIP + t9) + 1;
						currentBytecode = byteAt(localIP);
						goto l113;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (!t2) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l113;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((5 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l114:	/* end fetchClassOf: */;
		l115:	/* end lookupInMethodCacheSel:class: */;
		l116:	/* end internalExecuteNewMethod */;
		l113:	/* end case */;
			break;
		case 182:
			/* bytecodePrimEqual */
			t1 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t1 & t3) & 1) != 0) {
				/* begin booleanCheat: */
				t4 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t4 < 160) && (t4 > 151)) {
					if (t1 == t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l117;
					} else {
						/* begin jump: */
						localIP = (localIP + (t4 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l117;
					}
				}
				if (t4 == 172) {
					t5 = byteAt(++localIP);
					if (t1 == t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l117;
					} else {
						/* begin jump: */
						localIP = (localIP + t5) + 1;
						currentBytecode = byteAt(localIP);
						goto l117;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t1 == t3) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l117;
			}
			successFlag = 1;
			t2 = primitiveFloatEqualtoArg(t1, t3);
			if (successFlag) {
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l117;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l117;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l117;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l117;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t2) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l117;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((6 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l118:	/* end fetchClassOf: */;
		l119:	/* end lookupInMethodCacheSel:class: */;
		l120:	/* end internalExecuteNewMethod */;
		l117:	/* end case */;
			break;
		case 183:
			/* bytecodePrimNotEqual */
			t1 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t1 & t3) & 1) != 0) {
				/* begin booleanCheat: */
				t4 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t4 < 160) && (t4 > 151)) {
					if (t1 != t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l121;
					} else {
						/* begin jump: */
						localIP = (localIP + (t4 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l121;
					}
				}
				if (t4 == 172) {
					t5 = byteAt(++localIP);
					if (t1 != t3) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l121;
					} else {
						/* begin jump: */
						localIP = (localIP + t5) + 1;
						currentBytecode = byteAt(localIP);
						goto l121;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t1 != t3) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l121;
			}
			successFlag = 1;
			t2 = primitiveFloatEqualtoArg(t1, t3);
			if (successFlag) {
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l121;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l121;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l121;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l121;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (!t2) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l121;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((7 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l122:	/* end fetchClassOf: */;
		l123:	/* end lookupInMethodCacheSel:class: */;
		l124:	/* end internalExecuteNewMethod */;
		l121:	/* end case */;
			break;
		case 184:
			/* bytecodePrimMultiply */
			t2 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t2 & t3) & 1) != 0) {
				t2 = (t2 >> 1);
				t3 = (t3 >> 1);
				t1 = t2 * t3;
				if (((t3 == 0) || ((t1 / t3) == t2)) && ((t1 ^ (t1 << 1)) >= 0)) {
					/* begin internalPop:thenPush: */
					longAtput(localSP -= (2 - 1) * 4, ((t1 << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l125;
				}
			} else {
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveFloatMultiplybyArg(t2, t3);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l125;
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((8 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l126:	/* end fetchClassOf: */;
		l127:	/* end lookupInMethodCacheSel:class: */;
		l128:	/* end internalExecuteNewMethod */;
		l125:	/* end case */;
			break;
		case 185:
			/* bytecodePrimDivide */
			t2 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (0 * 4));
			if (((t2 & t3) & 1) != 0) {
				t2 = (t2 >> 1);
				t3 = (t3 >> 1);
				if ((t3 != 0) && ((t2 % t3) == 0)) {
					t1 = t2 / t3;
					if ((t1 ^ (t1 << 1)) >= 0) {
						/* begin internalPop:thenPush: */
						longAtput(localSP -= (2 - 1) * 4, ((t1 << 1) | 1));
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l129;
					}
				}
			} else {
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveFloatDividebyArg(t2, t3);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l129;
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((9 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l130:	/* end fetchClassOf: */;
		l131:	/* end lookupInMethodCacheSel:class: */;
		l132:	/* end internalExecuteNewMethod */;
		l129:	/* end case */;
			break;
		case 186:
			/* bytecodePrimMod */
			successFlag = 1;
			t1 = doPrimitiveModby(longAt(localSP - (1 * 4)), longAt(localSP - (0 * 4)));
			if (successFlag) {
				/* begin internalPop:thenPush: */
				longAtput(localSP -= (2 - 1) * 4, ((t1 << 1) | 1));
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				goto l133;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((10 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l134:	/* end fetchClassOf: */;
		l135:	/* end lookupInMethodCacheSel:class: */;
		l136:	/* end internalExecuteNewMethod */;
		l133:	/* end case */;
			break;
		case 187:
			/* bytecodePrimMakePoint */
			successFlag = 1;
			/* begin externalizeIPandSP */
			instructionPointer = ((int) localIP);
			stackPointer = ((int) localSP);
			theHomeContext = localHomeContext;
			primitiveMakePoint();
			/* begin internalizeIPandSP */
			localIP = ((char *) instructionPointer);
			localSP = ((char *) stackPointer);
			localHomeContext = theHomeContext;
			if (successFlag) {
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				goto l137;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((11 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l138:	/* end fetchClassOf: */;
		l139:	/* end lookupInMethodCacheSel:class: */;
		l140:	/* end internalExecuteNewMethod */;
		l137:	/* end case */;
			break;
		case 188:
			/* bytecodePrimBitShift */
			successFlag = 1;
			/* begin externalizeIPandSP */
			instructionPointer = ((int) localIP);
			stackPointer = ((int) localSP);
			theHomeContext = localHomeContext;
			primitiveBitShift();
			/* begin internalizeIPandSP */
			localIP = ((char *) instructionPointer);
			localSP = ((char *) stackPointer);
			localHomeContext = theHomeContext;
			if (successFlag) {
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				goto l141;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((12 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l142:	/* end fetchClassOf: */;
		l143:	/* end lookupInMethodCacheSel:class: */;
		l144:	/* end internalExecuteNewMethod */;
		l141:	/* end case */;
			break;
		case 189:
			/* bytecodePrimDiv */
			successFlag = 1;
			t1 = doPrimitiveDivby(longAt(localSP - (1 * 4)), longAt(localSP - (0 * 4)));
			if (successFlag) {
				/* begin internalPop:thenPush: */
				longAtput(localSP -= (2 - 1) * 4, ((t1 << 1) | 1));
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				goto l145;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((13 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l146:	/* end fetchClassOf: */;
		l147:	/* end lookupInMethodCacheSel:class: */;
		l148:	/* end internalExecuteNewMethod */;
		l145:	/* end case */;
			break;
		case 190:
			/* bytecodePrimBitAnd */
			successFlag = 1;
			/* begin externalizeIPandSP */
			instructionPointer = ((int) localIP);
			stackPointer = ((int) localSP);
			theHomeContext = localHomeContext;
			/* begin primitiveBitAnd */
			/* begin popPos32BitInteger */
			/* begin popStack */
			t6 = longAt(stackPointer);
			stackPointer -= 4;
			t5 = t6;
			t1 = positive32BitValueOf(t5);
			/* begin popPos32BitInteger */
			/* begin popStack */
			t8 = longAt(stackPointer);
			stackPointer -= 4;
			t7 = t8;
			t2 = positive32BitValueOf(t7);
			if (successFlag) {
				/* begin push: */
				t3 = positive32BitIntegerFor(t2 & t1);
				longAtput(t4 = stackPointer + 4, t3);
				stackPointer = t4;
			} else {
				/* begin unPop: */
				stackPointer += 2 * 4;
			}
			/* begin internalizeIPandSP */
			localIP = ((char *) instructionPointer);
			localSP = ((char *) stackPointer);
			localHomeContext = theHomeContext;
			if (successFlag) {
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				goto l149;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((14 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l150:	/* end fetchClassOf: */;
		l151:	/* end lookupInMethodCacheSel:class: */;
		l152:	/* end internalExecuteNewMethod */;
		l149:	/* end case */;
			break;
		case 191:
			/* bytecodePrimBitOr */
			successFlag = 1;
			/* begin externalizeIPandSP */
			instructionPointer = ((int) localIP);
			stackPointer = ((int) localSP);
			theHomeContext = localHomeContext;
			/* begin primitiveBitOr */
			/* begin popPos32BitInteger */
			/* begin popStack */
			t6 = longAt(stackPointer);
			stackPointer -= 4;
			t5 = t6;
			t1 = positive32BitValueOf(t5);
			/* begin popPos32BitInteger */
			/* begin popStack */
			t8 = longAt(stackPointer);
			stackPointer -= 4;
			t7 = t8;
			t2 = positive32BitValueOf(t7);
			if (successFlag) {
				/* begin push: */
				t3 = positive32BitIntegerFor(t2 | t1);
				longAtput(t4 = stackPointer + 4, t3);
				stackPointer = t4;
			} else {
				/* begin unPop: */
				stackPointer += 2 * 4;
			}
			/* begin internalizeIPandSP */
			localIP = ((char *) instructionPointer);
			localSP = ((char *) stackPointer);
			localHomeContext = theHomeContext;
			if (successFlag) {
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				goto l153;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((15 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l154:	/* end fetchClassOf: */;
		l155:	/* end lookupInMethodCacheSel:class: */;
		l156:	/* end internalExecuteNewMethod */;
		l153:	/* end case */;
			break;
		case 192:
			/* bytecodePrimAt */
			t4 = longAt(localSP);
			t3 = longAt(localSP - (1 * 4));
			successFlag = (!((t3 & 1))) && ((t4 & 1));
			if (successFlag) {
				t2 = t3 & 28;
				if ((atCache[t2 + 1]) == t3) {
					/* begin commonVariableInternal:at:cacheIndex: */
					t8 = atCache[t2 + 2];
					if (((((unsigned ) ((t4 >> 1)))) >= 1) && ((((unsigned ) ((t4 >> 1)))) <= (((unsigned ) t8)))) {
						t7 = atCache[t2 + 3];
						if (t7 <= 4) {
							t5 = atCache[t2 + 4];
							t1 = longAt(((((char *) t3)) + 4) + (((((t4 >> 1)) + t5) - 1) << 2));
							goto l158;
						}
						if (t7 < 8) {
							t6 = longAt(((((char *) t3)) + 4) + ((((t4 >> 1)) - 1) << 2));
							/* begin externalizeIPandSP */
							instructionPointer = ((int) localIP);
							stackPointer = ((int) localSP);
							theHomeContext = localHomeContext;
							t6 = positive32BitIntegerFor(t6);
							/* begin internalizeIPandSP */
							localIP = ((char *) instructionPointer);
							localSP = ((char *) stackPointer);
							localHomeContext = theHomeContext;
							t1 = t6;
							goto l158;
						}
						if (t7 >= 16) {
							t1 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (24 << 2))))) + 4) + ((byteAt(((((char *) t3)) + 4) + (((t4 >> 1)) - 1))) << 2));
							goto l158;
						} else {
							t1 = (((byteAt(((((char *) t3)) + 4) + (((t4 >> 1)) - 1))) << 1) | 1);
							goto l158;
						}
					}
					/* begin primitiveFail */
					successFlag = 0;
				l158:	/* end commonVariableInternal:at:cacheIndex: */;
					if (successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						/* begin internalPop:thenPush: */
						longAtput(localSP -= (2 - 1) * 4, t1);
						goto l157;
					}
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((16 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l159:	/* end fetchClassOf: */;
		l160:	/* end lookupInMethodCacheSel:class: */;
		l161:	/* end internalExecuteNewMethod */;
		l157:	/* end case */;
			break;
		case 193:
			/* bytecodePrimAtPut */
			t2 = longAt(localSP);
			t4 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (2 * 4));
			successFlag = (!((t3 & 1))) && ((t4 & 1));
			if (successFlag) {
				t1 = (t3 & 28) + 32;
				if ((atCache[t1 + 1]) == t3) {
					/* begin commonVariable:at:put:cacheIndex: */
					t8 = atCache[t1 + 2];
					if (((((unsigned ) ((t4 >> 1)))) >= 1) && ((((unsigned ) ((t4 >> 1)))) <= (((unsigned ) t8)))) {
						t6 = atCache[t1 + 3];
						if (t6 <= 4) {
							t5 = atCache[t1 + 4];
							/* begin storePointer:ofObject:withValue: */
							if (t3 < youngStart) {
								possibleRootStoreIntovalue(t3, t2);
							}
							longAtput(((((char *) t3)) + 4) + (((((t4 >> 1)) + t5) - 1) << 2), t2);
							goto l163;
						}
						if (t6 < 8) {
							t7 = positive32BitValueOf(t2);
							if (successFlag) {
								longAtput(((((char *) t3)) + 4) + ((((t4 >> 1)) - 1) << 2), t7);
							}
							goto l163;
						}
						if (t6 >= 16) {
							t7 = asciiOfCharacter(t2);
							if (!(successFlag)) {
								goto l163;
							}
						} else {
							t7 = t2;
						}
						if ((t7 & 1)) {
							t7 = (t7 >> 1);
							if (!((t7 >= 0) && (t7 <= 255))) {
								/* begin primitiveFail */
								successFlag = 0;
								goto l163;
							}
							byteAtput(((((char *) t3)) + 4) + (((t4 >> 1)) - 1), t7);
							goto l163;
						}
					}
					/* begin primitiveFail */
					successFlag = 0;
				l163:	/* end commonVariable:at:put:cacheIndex: */;
					if (successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						/* begin internalPop:thenPush: */
						longAtput(localSP -= (3 - 1) * 4, t2);
						goto l162;
					}
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((17 * 2) << 2));
			argumentCount = 2;
			/* begin normalSend */
			goto commonSend;
		l164:	/* end fetchClassOf: */;
		l165:	/* end lookupInMethodCacheSel:class: */;
		l166:	/* end internalExecuteNewMethod */;
		l162:	/* end case */;
			break;
		case 194:
			/* bytecodePrimSize */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((18 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l167:	/* end fetchClassOf: */;
		l168:	/* end lookupInMethodCacheSel:class: */;
		l169:	/* end internalExecuteNewMethod */;
			break;
		case 195:
			/* bytecodePrimNext */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((19 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l170:	/* end fetchClassOf: */;
		l171:	/* end lookupInMethodCacheSel:class: */;
		l172:	/* end internalExecuteNewMethod */;
			break;
		case 196:
			/* bytecodePrimNextPut */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((20 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l173:	/* end fetchClassOf: */;
		l174:	/* end lookupInMethodCacheSel:class: */;
		l175:	/* end internalExecuteNewMethod */;
			break;
		case 197:
			/* bytecodePrimAtEnd */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((21 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l176:	/* end fetchClassOf: */;
		l177:	/* end lookupInMethodCacheSel:class: */;
		l178:	/* end internalExecuteNewMethod */;
			break;
		case 198:
			/* bytecodePrimEquivalent */
			t1 = longAt(localSP - (1 * 4));
			t2 = longAt(localSP - (0 * 4));
			/* begin booleanCheat: */
			t3 = byteAt(++localIP);
			/* begin internalPop: */
			localSP -= 2 * 4;
			if ((t3 < 160) && (t3 > 151)) {
				if (t1 == t2) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l179;
				} else {
					/* begin jump: */
					localIP = (localIP + (t3 - 151)) + 1;
					currentBytecode = byteAt(localIP);
					goto l179;
				}
			}
			if (t3 == 172) {
				t4 = byteAt(++localIP);
				if (t1 == t2) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l179;
				} else {
					/* begin jump: */
					localIP = (localIP + t4) + 1;
					currentBytecode = byteAt(localIP);
					goto l179;
				}
			}
			localIP -= 1;
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			if (t1 == t2) {
				/* begin internalPush: */
				longAtput(localSP += 4, trueObj);
			} else {
				/* begin internalPush: */
				longAtput(localSP += 4, falseObj);
			}
		l179:	/* end booleanCheat: */;
			break;
		case 199:
			/* bytecodePrimClass */
			t1 = longAt(localSP);
			/* begin internalPop:thenPush: */
			/* begin fetchClassOf: */
			if ((t1 & 1)) {
				t2 = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
				goto l180;
			}
			t3 = (((unsigned) (longAt(t1))) >> 12) & 31;
			if (t3 == 0) {
				t2 = (longAt(t1 - 4)) & 4294967292U;
				goto l180;
			} else {
				t2 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t3 - 1) << 2));
				goto l180;
			}
		l180:	/* end fetchClassOf: */;
			longAtput(localSP -= (1 - 1) * 4, t2);
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			break;
		case 200:
			/* bytecodePrimBlockCopy */
			t2 = longAt(localSP - (1 * 4));
			successFlag = 1;
			t1 = longAt(t2);
			/* begin success: */
			/* begin isContextHeader: */
			t4 = (((unsigned) t1) >> 12) & 31;
			t3 = (t4 == 13) || ((t4 == 14) || (t4 == 4));
			successFlag = t3 && successFlag;
			if (successFlag) {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveBlockCopy();
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
			}
			if (!(successFlag)) {
				messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((24 * 2) << 2));
				argumentCount = 1;
				/* begin normalSend */
				goto commonSend;
			l182:	/* end fetchClassOf: */;
			l183:	/* end lookupInMethodCacheSel:class: */;
			l184:	/* end internalExecuteNewMethod */;
			}
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
		l181:	/* end case */;
			break;
		case 201:
			/* bytecodePrimValue */
			t1 = longAt(localSP);
			successFlag = 1;
			argumentCount = 0;
			/* begin assertClassOf:is: */
			if ((t1 & 1)) {
				successFlag = 0;
				goto l186;
			}
			t3 = (((unsigned) (longAt(t1))) >> 12) & 31;
			if (t3 == 0) {
				t2 = (longAt(t1 - 4)) & 4294967292U;
			} else {
				t2 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t3 - 1) << 2));
			}
			/* begin success: */
			successFlag = (t2 == (longAt(((((char *) specialObjectsOop)) + 4) + (11 << 2)))) && successFlag;
		l186:	/* end assertClassOf:is: */;
			if (successFlag) {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveValue();
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
			}
			if (!(successFlag)) {
				messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((25 * 2) << 2));
				argumentCount = 0;
				/* begin normalSend */
				goto commonSend;
			l187:	/* end fetchClassOf: */;
			l188:	/* end lookupInMethodCacheSel:class: */;
			l189:	/* end internalExecuteNewMethod */;
			}
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
		l185:	/* end case */;
			break;
		case 202:
			/* bytecodePrimValueWithArg */
			t1 = longAt(localSP - (1 * 4));
			successFlag = 1;
			argumentCount = 1;
			/* begin assertClassOf:is: */
			if ((t1 & 1)) {
				successFlag = 0;
				goto l191;
			}
			t3 = (((unsigned) (longAt(t1))) >> 12) & 31;
			if (t3 == 0) {
				t2 = (longAt(t1 - 4)) & 4294967292U;
			} else {
				t2 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t3 - 1) << 2));
			}
			/* begin success: */
			successFlag = (t2 == (longAt(((((char *) specialObjectsOop)) + 4) + (11 << 2)))) && successFlag;
		l191:	/* end assertClassOf:is: */;
			if (successFlag) {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveValue();
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
			}
			if (!(successFlag)) {
				messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((26 * 2) << 2));
				argumentCount = 1;
				/* begin normalSend */
				goto commonSend;
			l192:	/* end fetchClassOf: */;
			l193:	/* end lookupInMethodCacheSel:class: */;
			l194:	/* end internalExecuteNewMethod */;
			}
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
		l190:	/* end case */;
			break;
		case 203:
			/* bytecodePrimDo */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((27 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l195:	/* end fetchClassOf: */;
		l196:	/* end lookupInMethodCacheSel:class: */;
		l197:	/* end internalExecuteNewMethod */;
			break;
		case 204:
			/* bytecodePrimNew */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((28 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l198:	/* end fetchClassOf: */;
		l199:	/* end lookupInMethodCacheSel:class: */;
		l200:	/* end internalExecuteNewMethod */;
			break;
		case 205:
			/* bytecodePrimNewWithArg */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((29 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l201:	/* end fetchClassOf: */;
		l202:	/* end lookupInMethodCacheSel:class: */;
		l203:	/* end internalExecuteNewMethod */;
			break;
		case 206:
			/* bytecodePrimPointX */
			successFlag = 1;
			/* begin externalizeIPandSP */
			instructionPointer = ((int) localIP);
			stackPointer = ((int) localSP);
			theHomeContext = localHomeContext;
			primitivePointX();
			/* begin internalizeIPandSP */
			localIP = ((char *) instructionPointer);
			localSP = ((char *) stackPointer);
			localHomeContext = theHomeContext;
			if (successFlag) {
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				goto l204;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((30 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l205:	/* end fetchClassOf: */;
		l206:	/* end lookupInMethodCacheSel:class: */;
		l207:	/* end internalExecuteNewMethod */;
		l204:	/* end case */;
			break;
		case 207:
			/* bytecodePrimPointY */
			successFlag = 1;
			/* begin externalizeIPandSP */
			instructionPointer = ((int) localIP);
			stackPointer = ((int) localSP);
			theHomeContext = localHomeContext;
			primitivePointY();
			/* begin internalizeIPandSP */
			localIP = ((char *) instructionPointer);
			localSP = ((char *) stackPointer);
			localHomeContext = theHomeContext;
			if (successFlag) {
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				goto l208;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((31 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l209:	/* end fetchClassOf: */;
		l210:	/* end lookupInMethodCacheSel:class: */;
		l211:	/* end internalExecuteNewMethod */;
		l208:	/* end case */;
			break;
		case 208:
		case 209:
		case 210:
		case 211:
		case 212:
		case 213:
		case 214:
		case 215:
		case 216:
		case 217:
		case 218:
		case 219:
		case 220:
		case 221:
		case 222:
		case 223:
		case 224:
		case 225:
		case 226:
		case 227:
		case 228:
		case 229:
		case 230:
		case 231:
		case 232:
		case 233:
		case 234:
		case 235:
		case 236:
		case 237:
		case 238:
		case 239:
		case 240:
		case 241:
		case 242:
		case 243:
		case 244:
		case 245:
		case 246:
		case 247:
		case 248:
		case 249:
		case 250:
		case 251:
		case 252:
		case 253:
		case 254:
		case 255:
			/* sendLiteralSelectorBytecode */
			messageSelector = longAt(((((char *) method)) + 4) + (((currentBytecode & 15) + 1) << 2));
			argumentCount = ((((unsigned) currentBytecode) >> 4) & 3) - 1;
			/* begin normalSend */
			goto commonSend;
		l212:	/* end fetchClassOf: */;
		l213:	/* end lookupInMethodCacheSel:class: */;
		l214:	/* end internalExecuteNewMethod */;
			break;
		}
	}

	/* undo the pre-increment of IP before returning */

	localIP -= 1;
	/* begin externalizeIPandSP */
	instructionPointer = ((int) localIP);
	stackPointer = ((int) localSP);
	theHomeContext = localHomeContext;
}


/*	Support for external primitives. */

int isKindOf(int oop, char *className) {
    int oopClass;
    int ccIndex;

	/* begin fetchClassOf: */
	if ((oop & 1)) {
		oopClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		oopClass = (longAt(oop - 4)) & 4294967292U;
		goto l1;
	} else {
		oopClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	while (!(oopClass == nilObj)) {
		if (classNameOfIs(oopClass, className)) {
			return 1;
		}
		oopClass = longAt(((((char *) oopClass)) + 4) + (0 << 2));
	}
	return 0;
}


/*	Support for external primitives */

int isMemberOf(int oop, char *className) {
    int oopClass;
    int ccIndex;

	/* begin fetchClassOf: */
	if ((oop & 1)) {
		oopClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		oopClass = (longAt(oop - 4)) & 4294967292U;
		goto l1;
	} else {
		oopClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	return classNameOfIs(oopClass, className);
}


/*	Answer true if the argument contains indexable bytes. See comment in formatOf: */
/*	Note: Includes CompiledMethods. */

int isBytes(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) >= 8;
}

int isContextHeader(int aHeader) {
    int ccIndex;

	ccIndex = (((unsigned) aHeader) >> 12) & 31;
	return (ccIndex == 13) || ((ccIndex == 14) || (ccIndex == 4));
}

int isFloatObject(int oop) {
	return (fetchClassOf(oop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)));
}


/*	Is this a MethodContext whose meth has a primitive number of 199? */
/*	NB: the use of a primitive number for marking the method is pretty grungy, but it is simple to use for a test sytem, not too expensive and we don't actually have the two spare method header bits we need. We can probably obtain them when the method format is changed.
	NB 2: actually, the jitter will probably implement the prim to actually mark the volatile frame by changing the return function pointer. */

int isHandlerMarked(int aContext) {
    int header;
    int pIndex;
    int meth;
    int primBits;

	header = longAt(aContext);
	if (!(((((unsigned) header) >> 12) & 31) == 14)) {
		return 0;
	}
	meth = longAt(((((char *) aContext)) + 4) + (3 << 2));
	/* begin primitiveIndexOf: */
	primBits = (((unsigned) (longAt(((((char *) meth)) + 4) + (0 << 2)))) >> 1) & 805306879;
	if (primBits > 511) {
		pIndex = (primBits & 511) + (((unsigned) primBits) >> 19);
		goto l1;
	} else {
		pIndex = primBits;
		goto l1;
	}
l1:	/* end primitiveIndexOf: */;
	return pIndex == 199;
}


/*	Return true if the given address is in ST object memory */

int isInMemory(int address) {
	return (address >= (startOfMemory())) && (address < endOfMemory);
}

int isIndexable(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) >= 2;
}

int isIntegerObject(int objectPointer) {
	return (objectPointer & 1) > 0;
}


/*	Return true if the given value can be represented as a Smalltalk integer value. */
/*	Details: This trick is from Tim Rowledge. Use a shift and XOR to set the sign bit if and only if the top two bits of the given value are the same, then test the sign bit. Note that the top two bits are equal for exactly those integers in the range that can be represented in 31-bits. */

int isIntegerValue(int intValue) {
	return (intValue ^ (intValue << 1)) >= 0;
}


/*	Answer true if the argument has only fields that can hold oops. See comment in formatOf: */

int isPointers(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) <= 4;
}


/*	Is this a MethodContext whose meth has a primitive number of 198? */
/*	NB: the use of a primitive number for marking the method is pretty grungy, but it is simple to use for a test sytem, not too expensive and we don't actually have the two spare method header bits we need. We can probably obtain them when the method format is changed
	NB 2: actually, the jitter will probably implement the prim to actually mark the volatile frame by changing the return function pointer. */

int isUnwindMarked(int aContext) {
    int header;
    int pIndex;
    int meth;
    int primBits;

	header = longAt(aContext);
	if (!(((((unsigned) header) >> 12) & 31) == 14)) {
		return 0;
	}
	meth = longAt(((((char *) aContext)) + 4) + (3 << 2));
	/* begin primitiveIndexOf: */
	primBits = (((unsigned) (longAt(((((char *) meth)) + 4) + (0 << 2)))) >> 1) & 805306879;
	if (primBits > 511) {
		pIndex = (primBits & 511) + (((unsigned) primBits) >> 19);
		goto l1;
	} else {
		pIndex = primBits;
		goto l1;
	}
l1:	/* end primitiveIndexOf: */;
	return pIndex == 198;
}


/*	Answer true if the argument has only weak fields that can hold oops. See comment in formatOf: */

int isWeak(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) == 4;
}


/*	Answer true if the argument contains only indexable words (no oops). See comment in formatOf: */

int isWords(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) == 6;
}


/*	Answer true if the contains only indexable words or bytes (no oops). See comment in formatOf: */
/*	Note: Excludes CompiledMethods. */

int isWordsOrBytes(int oop) {
    int fmt;

	fmt = (((unsigned) (longAt(oop))) >> 8) & 15;
	return (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
}


/*	Return the byte offset of the last pointer field of the given object. Works with CompiledMethods, as well as ordinary objects. Can be used even when the type bits are not correct. */

int lastPointerOf(int oop) {
    int header;
    int fmt;
    int methodHeader;
    int sz;
    int header1;
    int type;

	header = longAt(oop);
	fmt = (((unsigned) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && (isContextHeader(header))) {
			return (6 + (fetchStackPointerOf(oop))) * 4;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(oop);
		/* begin rightType: */
		if ((header1 & 252) == 0) {
			type = 0;
			goto l1;
		} else {
			if ((header1 & 126976) == 0) {
				type = 1;
				goto l1;
			} else {
				type = 3;
				goto l1;
			}
		}
	l1:	/* end rightType: */;
		if (type == 0) {
			sz = (longAt(oop - 8)) & 4294967292U;
			goto l2;
		} else {
			sz = header1 & 252;
			goto l2;
		}
	l2:	/* end sizeBitsOfSafe: */;
		return sz - 4;
	}
	if (fmt < 12) {
		return 0;
	}
	methodHeader = longAt(oop + 4);
	return (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
}


/*	Return the number of indexable bytes or words in the given object. Assume the argument is not an integer. For a CompiledMethod, the size of the method header (in bytes) should be subtracted from the result. */

int lengthOf(int oop) {
    int header;
    int sz;

	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		return ((unsigned) (sz - 4)) >> 2;
	} else {
		return (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
	}
	return null;
}

int literalofMethod(int offset, int methodPointer) {
	return longAt(((((char *) methodPointer)) + 4) + ((offset + 1) << 2));
}

int literalCountOf(int methodPointer) {
	return (((unsigned) (longAt(((((char *) methodPointer)) + 4) + (0 << 2)))) >> 10) & 255;
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin_loadBitBltFrom
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

int loadBitBltFrom(int bb) {
    int fn;

	fn = ioLoadFunctionFrom("loadBitBltFrom", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	return  ((int (*) (int)) fn)(bb);
}


/*	If floatOrInt is an integer, then convert it to a C double float and return it.
	If it is a Float, then load its value and return it.
	Otherwise fail -- ie return with successFlag set to false. */

double loadFloatOrIntFrom(int floatOrInt) {
	if ((floatOrInt & 1)) {
		return ((double) (floatOrInt >> 1));
	}
	if ((fetchClassOfNonInt(floatOrInt)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))) {
		return floatValueOf(floatOrInt);
	}
	successFlag = 0;
}

int loadInitialContext(void) {
    int proc;
    int sched;
    int activeCntx;
    int tmp;

	sched = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2));
	proc = longAt(((((char *) sched)) + 4) + (1 << 2));
	activeContext = longAt(((((char *) proc)) + 4) + (1 << 2));
	if (activeContext < youngStart) {
		beRootIfOld(activeContext);
	}
	/* begin fetchContextRegisters: */
	activeCntx = activeContext;
	tmp = longAt(((((char *) activeCntx)) + 4) + (3 << 2));
	if ((tmp & 1)) {
		tmp = longAt(((((char *) activeCntx)) + 4) + (5 << 2));
		if (tmp < youngStart) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx;
	}
	theHomeContext = tmp;
	receiver = longAt(((((char *) tmp)) + 4) + (5 << 2));
	method = longAt(((((char *) tmp)) + 4) + (3 << 2));
	tmp = ((longAt(((((char *) activeCntx)) + 4) + (1 << 2))) >> 1);
	instructionPointer = ((method + tmp) + 4) - 2;
	tmp = ((longAt(((((char *) activeCntx)) + 4) + (2 << 2))) >> 1);
	stackPointer = (activeCntx + 4) + (((6 + tmp) - 1) * 4);
	reclaimableContextCount = 0;
}

int lookupMethodInClass(int class) {
    int currentClass;
    int rclass;
    int found;
    int dictionary;
    int oop;
    int oop1;
    int length;
    int methodArray;
    int wrapAround;
    int mask;
    int nextSelector;
    int index;
    int sz;
    int primBits;
    int header;

	currentClass = class;
	while (currentClass != nilObj) {
		dictionary = longAt(((((char *) currentClass)) + 4) + (1 << 2));
		if (dictionary == nilObj) {
			/* begin pushRemappableOop: */
			remapBuffer[remapBufferCount += 1] = currentClass;
			createActualMessageTo(class);
			/* begin popRemappableOop */
			oop = remapBuffer[remapBufferCount];
			remapBufferCount -= 1;
			currentClass = oop;
			messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (34 << 2));
			return lookupMethodInClass(longAt(((((char *) currentClass)) + 4) + (0 << 2)));
		}
		/* begin lookupMethodInDictionary: */
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(dictionary);
		if ((header & 3) == 0) {
			sz = (longAt(dictionary - 8)) & 4294967292U;
			goto l2;
		} else {
			sz = header & 252;
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
		length = ((unsigned) (sz - 4)) >> 2;
		mask = (length - 2) - 1;
		if ((messageSelector & 1)) {
			index = (mask & ((messageSelector >> 1))) + 2;
		} else {
			index = (mask & ((((unsigned) (longAt(messageSelector))) >> 17) & 4095)) + 2;
		}
		wrapAround = 0;
		while (1) {
			nextSelector = longAt(((((char *) dictionary)) + 4) + (index << 2));
			if (nextSelector == nilObj) {
				found = 0;
				goto l3;
			}
			if (nextSelector == messageSelector) {
				methodArray = longAt(((((char *) dictionary)) + 4) + (1 << 2));
				newMethod = longAt(((((char *) methodArray)) + 4) + ((index - 2) << 2));
				/* begin primitiveIndexOf: */
				primBits = (((unsigned) (longAt(((((char *) newMethod)) + 4) + (0 << 2)))) >> 1) & 805306879;
				if (primBits > 511) {
					primitiveIndex = (primBits & 511) + (((unsigned) primBits) >> 19);
					goto l1;
				} else {
					primitiveIndex = primBits;
					goto l1;
				}
			l1:	/* end primitiveIndexOf: */;
				if (primitiveIndex > 700) {
					primitiveIndex = 0;
				}
				found = 1;
				goto l3;
			}
			index += 1;
			if (index == length) {
				if (wrapAround) {
					found = 0;
					goto l3;
				}
				wrapAround = 1;
				index = 2;
			}
		}
	l3:	/* end lookupMethodInDictionary: */;
		if (found) {
			return methodClass = currentClass;
		}
		currentClass = longAt(((((char *) currentClass)) + 4) + (0 << 2));
	}
	if (messageSelector == (longAt(((((char *) specialObjectsOop)) + 4) + (20 << 2)))) {
		error("Recursive not understood error encountered");
	}
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = class;
	createActualMessageTo(class);
	/* begin popRemappableOop */
	oop1 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	rclass = oop1;
	messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (20 << 2));
	return lookupMethodInClass(rclass);
}


/*	Return the first free block after the given chunk in memory. */

int lowestFreeAfter(int chunk) {
    int oopHeader;
    int oop;
    int oopHeaderType;
    int oopSize;
    int extra;
    int extra1;
    int extra2;
    int type;
    int extra3;
    int type1;

	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type1 = (longAt(chunk)) & 3;
	if (type1 > 1) {
		extra3 = 0;
	} else {
		if (type1 == 1) {
			extra3 = 4;
		} else {
			extra3 = 8;
		}
	}
	extra1 = extra3;
	oop = chunk + extra1;
	while (oop < endOfMemory) {
		oopHeader = longAt(oop);
		oopHeaderType = oopHeader & 3;
		if (oopHeaderType == 2) {
			return oop;
		} else {
			if (oopHeaderType == 0) {
				oopSize = (longAt(oop - 8)) & 4294967292U;
			} else {
				oopSize = oopHeader & 252;
			}
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type = (longAt(oop + oopSize)) & 3;
		if (type > 1) {
			extra2 = 0;
		} else {
			if (type == 1) {
				extra2 = 4;
			} else {
				extra2 = 8;
			}
		}
		extra = extra2;
		oop = (oop + oopSize) + extra;
	}
	error("expected to find at least one free object");
}

int makePointwithxValueyValue(int xValue, int yValue) {
    int pointResult;

	pointResult = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
	/* begin storePointer:ofObject:withValue: */
	if (pointResult < youngStart) {
		possibleRootStoreIntovalue(pointResult, ((xValue << 1) | 1));
	}
	longAtput(((((char *) pointResult)) + 4) + (0 << 2), ((xValue << 1) | 1));
	/* begin storePointer:ofObject:withValue: */
	if (pointResult < youngStart) {
		possibleRootStoreIntovalue(pointResult, ((yValue << 1) | 1));
	}
	longAtput(((((char *) pointResult)) + 4) + (1 << 2), ((yValue << 1) | 1));
	return pointResult;
}


/*	Use the forwarding table to update the pointers of all non-free objects in the given range of memory. Also remap pointers in root objects which may contains pointers into the given memory range, and don't forget to flush the method cache based on the range */

int mapPointersInObjectsFromto(int memStart, int memEnd) {
    int i;
    int oop;
    int i1;
    int oop1;
    int i2;
    int probe;
    int extra;
    int extra1;
    int type;
    int header;
    int sz;
    int fwdBlock;
    int realHeader;
    int extra3;
    int extra12;
    int type2;
    int sz1;
    int extra2;
    int header1;
    int extra11;
    int type1;
    int newOop;
    int fieldOop;
    int fwdBlock4;
    int fieldOffset;
    int header5;
    int fwdBlock1;
    int header12;
    int header2;
    int header3;
    int fmt;
    int methodHeader;
    int size;
    int fwdBlock2;
    int newClassHeader;
    int classOop;
    int newClassOop;
    int fwdBlock3;
    int classHeader;
    int header4;
    int fwdBlock11;
    int header11;
    int header21;
    int newOop1;
    int fieldOop1;
    int fwdBlock5;
    int fieldOffset1;
    int header6;
    int fwdBlock12;
    int header13;
    int header22;
    int header31;
    int fmt1;
    int methodHeader1;
    int size1;
    int fwdBlock21;
    int newClassHeader1;
    int classOop1;
    int newClassOop1;
    int fwdBlock31;
    int classHeader1;
    int header41;
    int fwdBlock111;
    int header111;
    int header211;

	/* begin compilerMapHookFrom:to: */
	if (compilerInitialized) {
		compilerMapFromto(memStart, memEnd);
	}
	/* begin mapInterpreterOops */
	nilObj = remap(nilObj);
	falseObj = remap(falseObj);
	trueObj = remap(trueObj);
	specialObjectsOop = remap(specialObjectsOop);
	if (!(compilerInitialized)) {
		stackPointer -= activeContext;
		activeContext = remap(activeContext);
		stackPointer += activeContext;
		theHomeContext = remap(theHomeContext);
	}
	instructionPointer -= method;
	method = remap(method);
	instructionPointer += method;
	receiver = remap(receiver);
	messageSelector = remap(messageSelector);
	newMethod = remap(newMethod);
	methodClass = remap(methodClass);
	lkupClass = remap(lkupClass);
	receiverClass = remap(receiverClass);
	for (i1 = 1; i1 <= remapBufferCount; i1 += 1) {
		oop1 = remapBuffer[i1];
		if (!((oop1 & 1))) {
			remapBuffer[i1] = (remap(oop1));
		}
	}
	/* begin flushMethodCacheFrom:to: */
	probe = 0;
	for (i2 = 1; i2 <= 512; i2 += 1) {
		if (!((methodCache[probe + 1]) == 0)) {
			if ((((((methodCache[probe + 1]) >= memStart) && ((methodCache[probe + 1]) < memEnd)) || (((methodCache[probe + 2]) >= memStart) && ((methodCache[probe + 2]) < memEnd))) || (((methodCache[probe + 3]) >= memStart) && ((methodCache[probe + 3]) < memEnd))) || (((methodCache[probe + 5]) >= memStart) && ((methodCache[probe + 5]) < memEnd))) {
				methodCache[probe + 1] = 0;
			}
		}
		probe += 8;
	}
	for (i2 = 1; i2 <= 64; i2 += 1) {
		atCache[i2] = 0;
	}
	for (i = 1; i <= rootTableCount; i += 1) {
		oop = rootTable[i];
		if ((oop < memStart) || (oop >= memEnd)) {
			/* begin remapFieldsAndClassOf: */
			/* begin lastPointerWhileForwarding: */
			header3 = longAt(oop);
			if ((header3 & 2147483648U) != 0) {
				fwdBlock2 = (header3 & 2147483644) << 1;
				;
				header3 = longAt(fwdBlock2 + 4);
			}
			fmt = (((unsigned) header3) >> 8) & 15;
			if (fmt <= 4) {
				if ((fmt == 3) && (isContextHeader(header3))) {
					fieldOffset = (6 + (fetchStackPointerOf(oop))) * 4;
					goto l3;
				}
				if ((header3 & 3) == 0) {
					size = (longAt(oop - 8)) & 4294967292U;
				} else {
					size = header3 & 252;
				}
				fieldOffset = size - 4;
				goto l3;
			}
			if (fmt < 12) {
				fieldOffset = 0;
				goto l3;
			}
			methodHeader = longAt(oop + 4);
			fieldOffset = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
		l3:	/* end lastPointerWhileForwarding: */;
			while (fieldOffset >= 4) {
				fieldOop = longAt(oop + fieldOffset);
				if (((fieldOop & 1) == 0) && (((longAt(fieldOop)) & 2147483648U) != 0)) {
					fwdBlock4 = ((longAt(fieldOop)) & 2147483644) << 1;
					;
					newOop = longAt(fwdBlock4);
					longAtput(oop + fieldOffset, newOop);
					if ((oop < youngStart) && (newOop >= youngStart)) {
						/* begin beRootWhileForwarding: */
						header5 = longAt(oop);
						if ((header5 & 2147483648U) != 0) {
							fwdBlock1 = (header5 & 2147483644) << 1;
							;
							/* begin noteAsRoot:headerLoc: */
							header12 = longAt(fwdBlock1 + 4);
							if ((header12 & 1073741824) == 0) {
								if (rootTableCount < 2500) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(fwdBlock1 + 4, header12 | 1073741824);
								}
							}
						} else {
							/* begin noteAsRoot:headerLoc: */
							header2 = longAt(oop);
							if ((header2 & 1073741824) == 0) {
								if (rootTableCount < 2500) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(oop, header2 | 1073741824);
								}
							}
						}
					}
				}
				fieldOffset -= 4;
			}
			/* begin remapClassOf: */
			if (((longAt(oop)) & 3) == 3) {
				goto l4;
			}
			classHeader = longAt(oop - 4);
			classOop = classHeader & 4294967292U;
			if (((classOop & 1) == 0) && (((longAt(classOop)) & 2147483648U) != 0)) {
				fwdBlock3 = ((longAt(classOop)) & 2147483644) << 1;
				;
				newClassOop = longAt(fwdBlock3);
				newClassHeader = newClassOop | (classHeader & 3);
				longAtput(oop - 4, newClassHeader);
				if ((oop < youngStart) && (newClassOop >= youngStart)) {
					/* begin beRootWhileForwarding: */
					header4 = longAt(oop);
					if ((header4 & 2147483648U) != 0) {
						fwdBlock11 = (header4 & 2147483644) << 1;
						;
						/* begin noteAsRoot:headerLoc: */
						header11 = longAt(fwdBlock11 + 4);
						if ((header11 & 1073741824) == 0) {
							if (rootTableCount < 2500) {
								rootTableCount += 1;
								rootTable[rootTableCount] = oop;
								longAtput(fwdBlock11 + 4, header11 | 1073741824);
							}
						}
					} else {
						/* begin noteAsRoot:headerLoc: */
						header21 = longAt(oop);
						if ((header21 & 1073741824) == 0) {
							if (rootTableCount < 2500) {
								rootTableCount += 1;
								rootTable[rootTableCount] = oop;
								longAtput(oop, header21 | 1073741824);
							}
						}
					}
				}
			}
		l4:	/* end remapClassOf: */;
		}
	}
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type = (longAt(memStart)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	oop = memStart + extra;
	while (oop < memEnd) {
		if (!(((longAt(oop)) & 3) == 2)) {
			/* begin remapFieldsAndClassOf: */
			/* begin lastPointerWhileForwarding: */
			header31 = longAt(oop);
			if ((header31 & 2147483648U) != 0) {
				fwdBlock21 = (header31 & 2147483644) << 1;
				;
				header31 = longAt(fwdBlock21 + 4);
			}
			fmt1 = (((unsigned) header31) >> 8) & 15;
			if (fmt1 <= 4) {
				if ((fmt1 == 3) && (isContextHeader(header31))) {
					fieldOffset1 = (6 + (fetchStackPointerOf(oop))) * 4;
					goto l5;
				}
				if ((header31 & 3) == 0) {
					size1 = (longAt(oop - 8)) & 4294967292U;
				} else {
					size1 = header31 & 252;
				}
				fieldOffset1 = size1 - 4;
				goto l5;
			}
			if (fmt1 < 12) {
				fieldOffset1 = 0;
				goto l5;
			}
			methodHeader1 = longAt(oop + 4);
			fieldOffset1 = (((((unsigned) methodHeader1) >> 10) & 255) * 4) + 4;
		l5:	/* end lastPointerWhileForwarding: */;
			while (fieldOffset1 >= 4) {
				fieldOop1 = longAt(oop + fieldOffset1);
				if (((fieldOop1 & 1) == 0) && (((longAt(fieldOop1)) & 2147483648U) != 0)) {
					fwdBlock5 = ((longAt(fieldOop1)) & 2147483644) << 1;
					;
					newOop1 = longAt(fwdBlock5);
					longAtput(oop + fieldOffset1, newOop1);
					if ((oop < youngStart) && (newOop1 >= youngStart)) {
						/* begin beRootWhileForwarding: */
						header6 = longAt(oop);
						if ((header6 & 2147483648U) != 0) {
							fwdBlock12 = (header6 & 2147483644) << 1;
							;
							/* begin noteAsRoot:headerLoc: */
							header13 = longAt(fwdBlock12 + 4);
							if ((header13 & 1073741824) == 0) {
								if (rootTableCount < 2500) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(fwdBlock12 + 4, header13 | 1073741824);
								}
							}
						} else {
							/* begin noteAsRoot:headerLoc: */
							header22 = longAt(oop);
							if ((header22 & 1073741824) == 0) {
								if (rootTableCount < 2500) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(oop, header22 | 1073741824);
								}
							}
						}
					}
				}
				fieldOffset1 -= 4;
			}
			/* begin remapClassOf: */
			if (((longAt(oop)) & 3) == 3) {
				goto l6;
			}
			classHeader1 = longAt(oop - 4);
			classOop1 = classHeader1 & 4294967292U;
			if (((classOop1 & 1) == 0) && (((longAt(classOop1)) & 2147483648U) != 0)) {
				fwdBlock31 = ((longAt(classOop1)) & 2147483644) << 1;
				;
				newClassOop1 = longAt(fwdBlock31);
				newClassHeader1 = newClassOop1 | (classHeader1 & 3);
				longAtput(oop - 4, newClassHeader1);
				if ((oop < youngStart) && (newClassOop1 >= youngStart)) {
					/* begin beRootWhileForwarding: */
					header41 = longAt(oop);
					if ((header41 & 2147483648U) != 0) {
						fwdBlock111 = (header41 & 2147483644) << 1;
						;
						/* begin noteAsRoot:headerLoc: */
						header111 = longAt(fwdBlock111 + 4);
						if ((header111 & 1073741824) == 0) {
							if (rootTableCount < 2500) {
								rootTableCount += 1;
								rootTable[rootTableCount] = oop;
								longAtput(fwdBlock111 + 4, header111 | 1073741824);
							}
						}
					} else {
						/* begin noteAsRoot:headerLoc: */
						header211 = longAt(oop);
						if ((header211 & 1073741824) == 0) {
							if (rootTableCount < 2500) {
								rootTableCount += 1;
								rootTable[rootTableCount] = oop;
								longAtput(oop, header211 | 1073741824);
							}
						}
					}
				}
			}
		l6:	/* end remapClassOf: */;
		}
		/* begin objectAfterWhileForwarding: */
		header = longAt(oop);
		if ((header & 2147483648U) == 0) {
			/* begin objectAfter: */
			;
			if (((longAt(oop)) & 3) == 2) {
				sz1 = (longAt(oop)) & 4294967292U;
			} else {
				/* begin sizeBitsOf: */
				header1 = longAt(oop);
				if ((header1 & 3) == 0) {
					sz1 = (longAt(oop - 8)) & 4294967292U;
					goto l1;
				} else {
					sz1 = header1 & 252;
					goto l1;
				}
			l1:	/* end sizeBitsOf: */;
			}
			/* begin oopFromChunk: */
			/* begin extraHeaderBytes: */
			type1 = (longAt(oop + sz1)) & 3;
			if (type1 > 1) {
				extra11 = 0;
			} else {
				if (type1 == 1) {
					extra11 = 4;
				} else {
					extra11 = 8;
				}
			}
			extra2 = extra11;
			oop = (oop + sz1) + extra2;
			goto l2;
		}
		fwdBlock = (header & 2147483644) << 1;
		;
		realHeader = longAt(fwdBlock + 4);
		if ((realHeader & 3) == 0) {
			sz = (longAt(oop - 8)) & 4294967292U;
		} else {
			sz = realHeader & 252;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type2 = (longAt(oop + sz)) & 3;
		if (type2 > 1) {
			extra12 = 0;
		} else {
			if (type2 == 1) {
				extra12 = 4;
			} else {
				extra12 = 8;
			}
		}
		extra3 = extra12;
		oop = (oop + sz) + extra3;
	l2:	/* end objectAfterWhileForwarding: */;
	}
}


/*	Mark all objects reachable from the given one.
	Trace from the given object even if it is old.
	Do not trace if it is already marked.
	Mark it only if it is a young object. */
/*	Tracer state variables:
		child		object being examined
		field		next field of child to examine
		parentField	field where child was stored in its referencing object */

int markAndTrace(int oop) {
    int header;
    int action;
    int lastFieldOffset;
    int typeBits;
    int childType;
    int header1;
    int type;
    int header2;
    int fmt;
    int methodHeader;
    int sz;
    int header3;
    int type1;
    int header4;
    int oop1;
    int lastFieldOffset1;
    int header21;
    int fmt1;
    int methodHeader1;
    int sz1;
    int header11;
    int type2;

	header = longAt(oop);
	if (!((header & 2147483648U) == 0)) {
		return 0;
	}
	header = (header & 4294967292U) | 2;
	if (oop >= youngStart) {
		header = header | 2147483648U;
	}
	longAtput(oop, header);
	parentField = 3;
	child = oop;
	/* begin lastPointerOf: */
	header2 = longAt(oop);
	fmt = (((unsigned) header2) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && (isContextHeader(header2))) {
			lastFieldOffset = (6 + (fetchStackPointerOf(oop))) * 4;
			goto l6;
		}
		/* begin sizeBitsOfSafe: */
		header3 = longAt(oop);
		/* begin rightType: */
		if ((header3 & 252) == 0) {
			type1 = 0;
			goto l7;
		} else {
			if ((header3 & 126976) == 0) {
				type1 = 1;
				goto l7;
			} else {
				type1 = 3;
				goto l7;
			}
		}
	l7:	/* end rightType: */;
		if (type1 == 0) {
			sz = (longAt(oop - 8)) & 4294967292U;
			goto l8;
		} else {
			sz = header3 & 252;
			goto l8;
		}
	l8:	/* end sizeBitsOfSafe: */;
		lastFieldOffset = sz - 4;
		goto l6;
	}
	if (fmt < 12) {
		lastFieldOffset = 0;
		goto l6;
	}
	methodHeader = longAt(oop + 4);
	lastFieldOffset = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
l6:	/* end lastPointerOf: */;
	field = oop + lastFieldOffset;

	/* run the tracer state machine until all objects reachable from oop are marked */

	action = 1;
	while (!(action == 4)) {
		if (action == 1) {
			/* begin startField */
			child = longAt(field);
			typeBits = child & 3;
			if ((typeBits & 1) == 1) {
				field -= 4;
				action = 1;
				goto l1;
			}
			if (typeBits == 0) {
				longAtput(field, parentField);
				parentField = field;
				action = 2;
				goto l1;
			}
			if (typeBits == 2) {
				if ((child & 126976) != 0) {
					child = child & 4294967292U;
					/* begin rightType: */
					if ((child & 252) == 0) {
						childType = 0;
						goto l2;
					} else {
						if ((child & 126976) == 0) {
							childType = 1;
							goto l2;
						} else {
							childType = 3;
							goto l2;
						}
					}
				l2:	/* end rightType: */;
					longAtput(field, child | childType);
					action = 3;
					goto l1;
				} else {
					child = longAt(field - 4);
					child = child & 4294967292U;
					longAtput(field - 4, parentField);
					parentField = (field - 4) | 1;
					action = 2;
					goto l1;
				}
			}
		l1:	/* end startField */;
		}
		if (action == 2) {
			/* begin startObj */
			oop1 = child;
			if (oop1 < youngStart) {
				field = oop1;
				action = 3;
				goto l12;
			}
			header4 = longAt(oop1);
			if ((header4 & 2147483648U) == 0) {
				if (((((unsigned) (longAt(oop1))) >> 8) & 15) == 4) {
					lastFieldOffset1 = (nonWeakFieldsOf(oop1)) << 2;
				} else {
					/* begin lastPointerOf: */
					header21 = longAt(oop1);
					fmt1 = (((unsigned) header21) >> 8) & 15;
					if (fmt1 <= 4) {
						if ((fmt1 == 3) && (isContextHeader(header21))) {
							lastFieldOffset1 = (6 + (fetchStackPointerOf(oop1))) * 4;
							goto l11;
						}
						/* begin sizeBitsOfSafe: */
						header11 = longAt(oop1);
						/* begin rightType: */
						if ((header11 & 252) == 0) {
							type2 = 0;
							goto l9;
						} else {
							if ((header11 & 126976) == 0) {
								type2 = 1;
								goto l9;
							} else {
								type2 = 3;
								goto l9;
							}
						}
					l9:	/* end rightType: */;
						if (type2 == 0) {
							sz1 = (longAt(oop1 - 8)) & 4294967292U;
							goto l10;
						} else {
							sz1 = header11 & 252;
							goto l10;
						}
					l10:	/* end sizeBitsOfSafe: */;
						lastFieldOffset1 = sz1 - 4;
						goto l11;
					}
					if (fmt1 < 12) {
						lastFieldOffset1 = 0;
						goto l11;
					}
					methodHeader1 = longAt(oop1 + 4);
					lastFieldOffset1 = (((((unsigned) methodHeader1) >> 10) & 255) * 4) + 4;
				l11:	/* end lastPointerOf: */;
				}
				header4 = header4 & 4294967292U;
				header4 = (header4 | 2147483648U) | 2;
				longAtput(oop1, header4);
				field = oop1 + lastFieldOffset1;
				action = 1;
				goto l12;
			} else {
				field = oop1;
				action = 3;
				goto l12;
			}
		l12:	/* end startObj */;
		}
		if (action == 3) {
			/* begin upward */
			if ((parentField & 1) == 1) {
				if (parentField == 3) {
					header1 = (longAt(field)) & 4294967292U;
					/* begin rightType: */
					if ((header1 & 252) == 0) {
						type = 0;
						goto l3;
					} else {
						if ((header1 & 126976) == 0) {
							type = 1;
							goto l3;
						} else {
							type = 3;
							goto l3;
						}
					}
				l3:	/* end rightType: */;
					longAtput(field, header1 + type);
					action = 4;
					goto l5;
				} else {
					child = field;
					field = parentField - 1;
					parentField = longAt(field);
					header1 = longAt(field + 4);
					/* begin rightType: */
					if ((header1 & 252) == 0) {
						type = 0;
						goto l4;
					} else {
						if ((header1 & 126976) == 0) {
							type = 1;
							goto l4;
						} else {
							type = 3;
							goto l4;
						}
					}
				l4:	/* end rightType: */;
					longAtput(field, child + type);
					field += 4;
					header1 = header1 & 4294967292U;
					longAtput(field, header1 + type);
					action = 3;
					goto l5;
				}
			} else {
				child = field;
				field = parentField;
				parentField = longAt(field);
				longAtput(field, child);
				field -= 4;
				action = 1;
				goto l5;
			}
		l5:	/* end upward */;
		}
	}
}


/*	Mark and trace all oops in the interpreter's state. */
/*	Assume: All traced variables contain valid oops. */

int markAndTraceInterpreterOops(void) {
    int i;
    int oop;

	/* begin compilerMarkHook */
	if (compilerInitialized) {
		compilerMark();
	}
	markAndTrace(specialObjectsOop);
	if (compilerInitialized) {
		markAndTrace(receiver);
		markAndTrace(method);
	} else {
		markAndTrace(activeContext);
	}
	markAndTrace(messageSelector);
	markAndTrace(newMethod);
	markAndTrace(methodClass);
	markAndTrace(lkupClass);
	markAndTrace(receiverClass);
	for (i = 1; i <= remapBufferCount; i += 1) {
		oop = remapBuffer[i];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
	}
}


/*	Mark phase of the mark and sweep garbage collector. Set the mark bits of all reachable objects. Free chunks are untouched by this process. */
/*	Assume: All non-free objects are initially unmarked. Root objects were unmarked when they were made roots. (Make sure this stays true!!). */

int markPhase(void) {
    int i;
    int oop;

	freeContexts = 1;

	/* trace the interpreter's objects, including the active stack and special objects array */

	freeLargeContexts = 1;
	markAndTraceInterpreterOops();
	for (i = 1; i <= rootTableCount; i += 1) {
		oop = rootTable[i];
		markAndTrace(oop);
	}
}

int methodArgumentCount(void) {
	return argumentCount;
}

int methodPrimitiveIndex(void) {
	return primitiveIndex;
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

EXPORT(int) moduleUnloaded(char * aModuleName) {
	if ((strcmp(aModuleName, "SurfacePlugin")) == 0) {
		showSurfaceFn = 0;
	}
}


/*	For access from BitBlt module */

int nilObject(void) {
	return nilObj;
}


/*	Return the number of non-weak fields in oop (i.e. the number of fixed fields).
	Note: The following is copied from fixedFieldsOf:format:length: since we do know
	the format of the oop (e.g. format = 4) and thus don't need the length. */

int nonWeakFieldsOf(int oop) {
    int classFormat;
    int class;
    int ccIndex;

	if (!(((((unsigned) (longAt(oop))) >> 8) & 15) == 4)) {
		error("Called fixedFieldsOfWeak: with a non-weak oop");
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - 4)) & 4294967292U;
		goto l1;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	return (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
}


/*	Record that the given oop in the old object area points to an object in the young area.
	HeaderLoc is usually = oop, but may be an addr in a forwarding block. */

int noteAsRootheaderLoc(int oop, int headerLoc) {
    int header;

	header = longAt(headerLoc);
	if ((header & 1073741824) == 0) {
		if (rootTableCount < 2500) {
			rootTableCount += 1;
			rootTable[rootTableCount] = oop;
			longAtput(headerLoc, header | 1073741824);
		}
	}
}


/*	This should never be called: either the compiler is uninitialised (in which case the hooks should never be reached) or the compiler initialisation should have replaced all the hook with their external implementations. */

int nullCompilerHook(void) {
	error("uninitialised compiler hook called");
	return 0;
}


/*	Return the object or free chunk immediately following the given object or free chunk in memory. Return endOfMemory when enumeration is complete. */

int objectAfter(int oop) {
    int sz;
    int extra;
    int header;
    int extra1;
    int type;

	;
	if (((longAt(oop)) & 3) == 2) {
		sz = (longAt(oop)) & 4294967292U;
	} else {
		/* begin sizeBitsOf: */
		header = longAt(oop);
		if ((header & 3) == 0) {
			sz = (longAt(oop - 8)) & 4294967292U;
			goto l1;
		} else {
			sz = header & 252;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
	}
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type = (longAt(oop + sz)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	return (oop + sz) + extra;
}


/*	If this is a pointers object, check that its fields are all okay oops. */

int okayFields(int oop) {
    int i;
    int fieldOop;
    int c;
    int ccIndex;

	if ((oop == null) || (oop == 0)) {
		return 1;
	}
	if ((oop & 1)) {
		return 1;
	}
	okayOop(oop);
	oopHasOkayClass(oop);
	if (!(((((unsigned) (longAt(oop))) >> 8) & 15) <= 4)) {
		return 1;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		c = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		c = (longAt(oop - 4)) & 4294967292U;
		goto l1;
	} else {
		c = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if ((c == (longAt(((((char *) specialObjectsOop)) + 4) + (10 << 2)))) || (c == (longAt(((((char *) specialObjectsOop)) + 4) + (11 << 2))))) {
		i = (6 + (fetchStackPointerOf(oop))) - 1;
	} else {
		i = (lengthOf(oop)) - 1;
	}
	while (i >= 0) {
		fieldOop = longAt(((((char *) oop)) + 4) + (i << 2));
		if (!((fieldOop & 1))) {
			okayOop(fieldOop);
			oopHasOkayClass(fieldOop);
		}
		i -= 1;
	}
}


/*	Verify that the given oop is legitimate. Check address, header, and size but not class. */
/*	address and size checks */

int okayOop(int oop) {
    int fmt;
    int sz;
    int type;
    int header;

	if ((oop & 1)) {
		return 1;
	}
	if (!((0 < oop) && (oop < endOfMemory))) {
		error("oop is not a valid address");
	}
	if (!((oop % 4) == 0)) {
		error("oop is not a word-aligned address");
	}
	/* begin sizeBitsOf: */
	header = longAt(oop);
	if ((header & 3) == 0) {
		sz = (longAt(oop - 8)) & 4294967292U;
		goto l1;
	} else {
		sz = header & 252;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	if (!((oop + sz) < endOfMemory)) {
		error("oop size would make it extend beyond the end of memory");
	}
	type = (longAt(oop)) & 3;
	if (type == 2) {
		error("oop is a free chunk, not an object");
	}
	if (type == 3) {
		if (((((unsigned) (longAt(oop))) >> 12) & 31) == 0) {
			error("cannot have zero compact class field in a short header");
		}
	}
	if (type == 1) {
		if (!((oop >= 4) && (((longAt(oop - 4)) & 3) == type))) {
			error("class header word has wrong type");
		}
	}
	if (type == 0) {
		if (!((oop >= 8) && ((((longAt(oop - 8)) & 3) == type) && (((longAt(oop - 4)) & 3) == type)))) {
			error("class header word has wrong type");
		}
	}
	fmt = (((unsigned) (longAt(oop))) >> 8) & 15;
	if ((fmt == 5) || (fmt == 7)) {
		error("oop has an unknown format type");
	}
	if (!(((longAt(oop)) & 536870912) == 0)) {
		error("unused header bit 30 is set; should be zero");
	}
	if ((((longAt(oop)) & 1073741824) == 1) && (oop >= youngStart)) {
		error("root bit is set in a young object");
	}
	return 1;
}


/*	Compute the oop of this chunk by adding its extra header bytes. */

int oopFromChunk(int chunk) {
    int extra;
    int extra1;
    int type;

	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	return chunk + extra;
}


/*	Similar to oopHasOkayClass:, except that it only returns true or false. */

int oopHasOKclass(int oop) {
    int behaviorFormatBits;
    int oopFormatBits;
    int oopClass;
    int formatMask;
    int ccIndex;

	if ((oop & 1)) {
		return 1;
	}
	if (!((0 < oop) && (oop < endOfMemory))) {
		return 0;
	}
	if (!((oop % 4) == 0)) {
		return 0;
	}
	if (!((oop + (sizeBitsOf(oop))) < endOfMemory)) {
		return 0;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		oopClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		oopClass = (longAt(oop - 4)) & 4294967292U;
		goto l1;
	} else {
		oopClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if ((oopClass & 1)) {
		return 0;
	}
	if (!((0 < oopClass) && (oopClass < endOfMemory))) {
		return 0;
	}
	if (!((oopClass % 4) == 0)) {
		return 0;
	}
	if (!((oopClass + (sizeBitsOf(oopClass))) < endOfMemory)) {
		return 0;
	}
	if (!((((((unsigned) (longAt(oopClass))) >> 8) & 15) <= 4) && ((lengthOf(oopClass)) >= 3))) {
		return 0;
	}
	if (((((unsigned) (longAt(oop))) >> 8) & 15) >= 8) {

		/* ignore extra bytes size bits */

		formatMask = 3072;
	} else {
		formatMask = 3840;
	}
	behaviorFormatBits = ((longAt(((((char *) oopClass)) + 4) + (2 << 2))) - 1) & formatMask;
	oopFormatBits = (longAt(oop)) & formatMask;
	if (!(behaviorFormatBits == oopFormatBits)) {
		return 0;
	}
	return 1;
}


/*	Attempt to verify that the given oop has a reasonable behavior. The class must be a valid, non-integer oop and must not be nilObj. It must be a pointers object with three or more fields. Finally, the instance specification field of the behavior must match that of the instance. */

int oopHasOkayClass(int oop) {
    int behaviorFormatBits;
    int oopFormatBits;
    int oopClass;
    int formatMask;
    int ccIndex;

	okayOop(oop);
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		oopClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		oopClass = (longAt(oop - 4)) & 4294967292U;
		goto l1;
	} else {
		oopClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if ((oopClass & 1)) {
		error("a SmallInteger is not a valid class or behavior");
	}
	okayOop(oopClass);
	if (!((((((unsigned) (longAt(oopClass))) >> 8) & 15) <= 4) && ((lengthOf(oopClass)) >= 3))) {
		error("a class (behavior) must be a pointers object of size >= 3");
	}
	if (((((unsigned) (longAt(oop))) >> 8) & 15) >= 8) {

		/* ignore extra bytes size bits */

		formatMask = 3072;
	} else {
		formatMask = 3840;
	}
	behaviorFormatBits = ((longAt(((((char *) oopClass)) + 4) + (2 << 2))) - 1) & formatMask;
	oopFormatBits = (longAt(oop)) & formatMask;
	if (!(behaviorFormatBits == oopFormatBits)) {
		error("object and its class (behavior) formats differ");
	}
	return 1;
}


/*	Note: May be called by translated primitive code. */

int pop(int nItems) {
	stackPointer -= nItems * 4;
}

int popthenPush(int nItems, int oop) {
    int sp;

	longAtput(sp = stackPointer - ((nItems - 1) * 4), oop);
	stackPointer = sp;
}


/*	Note: May be called by translated primitive code. */

double popFloat(void) {
    double result;
    int top;
    int top1;
    int cl;
    int ccIndex;

	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	top = top1;
	/* begin assertClassOf:is: */
	if ((top & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(top))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(top - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		;
		fetchFloatAtinto(top + 4, result);
	}
	return result;
}


/*	Pop and return the possibly remapped object from the remap buffer. */

int popRemappableOop(void) {
    int oop;

	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	return oop;
}

int popStack(void) {
    int top;

	top = longAt(stackPointer);
	stackPointer -= 4;
	return top;
}


/*	Note - integerValue is interpreted as POSITIVE, eg, as the result of
		Bitmap>at:, or integer>bitAnd:. */

int positive32BitIntegerFor(int integerValue) {
    int newLargeInteger;

	if ((integerValue >= 0) && ((integerValue ^ (integerValue << 1)) >= 0)) {
		return ((integerValue << 1) | 1);
	}
	newLargeInteger = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2)), 8, 0);
	byteAtput(((((char *) newLargeInteger)) + 4) + 3, (((unsigned) integerValue) >> 24) & 255);
	byteAtput(((((char *) newLargeInteger)) + 4) + 2, (((unsigned) integerValue) >> 16) & 255);
	byteAtput(((((char *) newLargeInteger)) + 4) + 1, (((unsigned) integerValue) >> 8) & 255);
	byteAtput(((((char *) newLargeInteger)) + 4) + 0, integerValue & 255);
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a four-byte LargePositiveInteger. */

int positive32BitValueOf(int oop) {
    int value;
    int sz;
    int header;
    int sz1;
    int cl;
    int ccIndex;

	if ((oop & 1)) {
		value = (oop >> 1);
		if (value < 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		return value;
	}
	/* begin assertClassOf:is: */
	if ((oop & 1)) {
		successFlag = 0;
		goto l2;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2)))) && successFlag;
l2:	/* end assertClassOf:is: */;
	if (successFlag) {
		/* begin lengthOf: */
		header = longAt(oop);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz1 = (longAt(oop - 8)) & 4294967292U;
		} else {
			sz1 = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			sz = ((unsigned) (sz1 - 4)) >> 2;
			goto l1;
		} else {
			sz = (sz1 - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l1;
		}
		sz = null;
	l1:	/* end lengthOf: */;
		if (!(sz == 4)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	if (successFlag) {
		return (((byteAt(((((char *) oop)) + 4) + 0)) + ((byteAt(((((char *) oop)) + 4) + 1)) << 8)) + ((byteAt(((((char *) oop)) + 4) + 2)) << 16)) + ((byteAt(((((char *) oop)) + 4) + 3)) << 24);
	}
}


/*	Note - integerValue is interpreted as POSITIVE, eg, as the result of
		Bitmap>at:, or integer>bitAnd:. */

int positive64BitIntegerFor(squeakInt64 integerValue) {
    int i;
    int check;
    int value;
    int newLargeInteger;

	if ((sizeof(integerValue)) == 4) {
		return positive32BitIntegerFor(integerValue);
	}
	check = integerValue >> 32;
	if (check == 0) {
		return positive32BitIntegerFor(integerValue);
	}
	newLargeInteger = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2)), 12, 0);
	for (i = 0; i <= 7; i += 1) {
		value = ( integerValue >> (i * 8)) & 255;
		byteAtput(((((char *) newLargeInteger)) + 4) + i, value);
	}
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a eight-byte LargePositiveInteger. */

squeakInt64 positive64BitValueOf(int oop) {
    int i;
    squeakInt64 value;
    int szsqueakInt64;
    int sz;
    int cl;
    int ccIndex;
    int header;
    int sz1;

	if ((oop & 1)) {
		value = (oop >> 1);
		if (value < 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		return value;
	}
	/* begin assertClassOf:is: */
	if ((oop & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	szsqueakInt64 = sizeof(squeakInt64);
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz1 = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz1 = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		sz = ((unsigned) (sz1 - 4)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	if (sz > szsqueakInt64) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = 0;
	for (i = 0; i <= (sz - 1); i += 1) {
		value += (((squeakInt64) (byteAt(((((char *) oop)) + 4) + i)))) << (i * 8);
	}
	return value;
}


/*	oop is an old object.  If valueObj is young, mark the object as a root. */

int possibleRootStoreIntovalue(int oop, int valueObj) {
    int header;

	if ((valueObj >= youngStart) && (!((valueObj & 1)))) {
		/* begin noteAsRoot:headerLoc: */
		header = longAt(oop);
		if ((header & 1073741824) == 0) {
			if (rootTableCount < 2500) {
				rootTableCount += 1;
				rootTable[rootTableCount] = oop;
				longAtput(oop, header | 1073741824);
			}
		}
	}
}


/*	Ensure that there are enough forwarding blocks to accomodate this become, then prepare forwarding blocks for the pointer swap. Return true if successful. */
/*	Details: Doing a GC might generate enough space for forwarding blocks if we're short. However, this is an uncommon enough case that it is better handled by primitive fail code at the Smalltalk level. */

int prepareForwardingTableForBecomingwithtwoWay(int array1, int array2, int twoWayFlag) {
    int entriesAvailable;
    int fwdBlkSize;
    int entriesNeeded;
    int oop1;
    int oop2;
    int fwdBlock;
    int fieldOffset;
    int originalHeaderType;
    int originalHeader;
    int originalHeaderType1;
    int originalHeader1;
    int header;
    int fmt;
    int methodHeader;
    int sz;
    int header1;
    int type;


	/* need enough entries for all oops */

	entriesNeeded = ((int) (lastPointerOf(array1)) >> 2);
	if (twoWayFlag) {
		entriesNeeded = entriesNeeded * 2;

		/* Note: Forward blocks must be quadword aligned. */

		fwdBlkSize = 8;
	} else {

		/* Note: Forward blocks must be quadword aligned. */

		fwdBlkSize = 16;
	}
	entriesAvailable = fwdTableInit(fwdBlkSize);
	if (entriesAvailable < entriesNeeded) {
		initializeMemoryFirstFree(freeBlock);
		return 0;
	}
	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((unsigned) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && (isContextHeader(header))) {
			fieldOffset = (6 + (fetchStackPointerOf(array1))) * 4;
			goto l3;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & 252) == 0) {
			type = 0;
			goto l4;
		} else {
			if ((header1 & 126976) == 0) {
				type = 1;
				goto l4;
			} else {
				type = 3;
				goto l4;
			}
		}
	l4:	/* end rightType: */;
		if (type == 0) {
			sz = (longAt(array1 - 8)) & 4294967292U;
			goto l5;
		} else {
			sz = header1 & 252;
			goto l5;
		}
	l5:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - 4;
		goto l3;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l3;
	}
	methodHeader = longAt(array1 + 4);
	fieldOffset = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
l3:	/* end lastPointerOf: */;
	while (fieldOffset >= 4) {
		oop1 = longAt(array1 + fieldOffset);
		oop2 = longAt(array2 + fieldOffset);
		/* begin fwdBlockGet: */
		fwdTableNext += fwdBlkSize;
		if (fwdTableNext <= fwdTableLast) {
			fwdBlock = fwdTableNext;
			goto l2;
		} else {
			fwdBlock = null;
			goto l2;
		}
	l2:	/* end fwdBlockGet: */;
		/* begin initForwardBlock:mapping:to:withBackPtr: */
		originalHeader1 = longAt(oop1);
		;
		originalHeaderType1 = originalHeader1 & 3;
		longAtput(fwdBlock, oop2);
		longAtput(fwdBlock + 4, originalHeader1);
		if (!twoWayFlag) {
			longAtput(fwdBlock + 8, oop1);
		}
		longAtput(oop1, (((unsigned) fwdBlock) >> 1) | (2147483648U | originalHeaderType1));
		if (twoWayFlag) {
			/* begin fwdBlockGet: */
			fwdTableNext += fwdBlkSize;
			if (fwdTableNext <= fwdTableLast) {
				fwdBlock = fwdTableNext;
				goto l1;
			} else {
				fwdBlock = null;
				goto l1;
			}
		l1:	/* end fwdBlockGet: */;
			/* begin initForwardBlock:mapping:to:withBackPtr: */
			originalHeader = longAt(oop2);
			;
			originalHeaderType = originalHeader & 3;
			longAtput(fwdBlock, oop1);
			longAtput(fwdBlock + 4, originalHeader);
			if (!twoWayFlag) {
				longAtput(fwdBlock + 8, oop2);
			}
			longAtput(oop2, (((unsigned) fwdBlock) >> 1) | (2147483648U | originalHeaderType));
		}
		fieldOffset -= 4;
	}
	return 1;
}

int primitiveAdd(void) {
    int integerResult;
    int sp;

	/* begin pop2AndPushIntegerIfOK: */
	integerResult = (stackIntegerValue(1)) + (stackIntegerValue(0));
	if (successFlag) {
		if ((integerResult ^ (integerResult << 1)) >= 0) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * 4), ((integerResult << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}

int primitiveArctan(void) {
    double rcvr;

	rcvr = popFloat();
	if (successFlag) {
		pushFloat(atan(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	We must flush the method cache here, to eliminate stale references
	to mutated classes and/or selectors. */

int primitiveArrayBecome(void) {
    int rcvr;
    int arg;
    int successValue;

	arg = longAt(stackPointer);
	rcvr = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successValue = becomewithtwoWay(rcvr, arg, 1);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}


/*	We must flush the method cache here, to eliminate stale references
	to mutated classes and/or selectors. */

int primitiveArrayBecomeOneWay(void) {
    int rcvr;
    int arg;
    int successValue;

	arg = longAt(stackPointer);
	rcvr = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successValue = becomewithtwoWay(rcvr, arg, 0);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveAsFloat(void) {
    int arg;
    int integerPointer;
    int top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		arg = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		arg = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	if (successFlag) {
		pushFloat(((double) arg));
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}

int primitiveAsOop(void) {
    int thisReceiver;
    int sp;
    int top;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	thisReceiver = top;
	/* begin success: */
	successFlag = (!((thisReceiver & 1))) && successFlag;
	if (successFlag) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((((((unsigned) (longAt(thisReceiver))) >> 17) & 4095) << 1) | 1));
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}

int primitiveAt(void) {
	commonAt(0);
}

int primitiveAtEnd(void) {
    int limit;
    int stream;
    int index;
    int sp;
    int sp1;
    int top;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	stream = top;
	successFlag = (((((unsigned) (longAt(stream))) >> 8) & 15) <= 4) && ((lengthOf(stream)) >= (2 + 1));
	if (successFlag) {
		index = fetchIntegerofObject(1, stream);
		limit = fetchIntegerofObject(2, stream);
	}
	if (successFlag) {
		/* begin pushBool: */
		if (index >= limit) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}

int primitiveAtPut(void) {
	commonAtPut(0);
}


/*	Set the cursor to the given shape. The Mac only supports 16x16 pixel cursors. Cursor offsets are handled by Smalltalk. */

int primitiveBeCursor(void) {
    int maskBitsIndex;
    int cursorObj;
    int maskObj;
    int i;
    int bitsObj;
    int ourCursor;
    int extentX;
    int offsetY;
    int depth;
    int cursorBitsIndex;
    int offsetObj;
    int offsetX;
    int extentY;
    int successValue;
    int successValue1;
    int successValue2;
    int successValue3;
    int successValue4;
    int successValue5;
    int successValue6;
    int successValue7;
    int successValue8;

	if (argumentCount == 0) {
		cursorObj = longAt(stackPointer);
		maskBitsIndex = null;
	}
	if (argumentCount == 1) {
		cursorObj = longAt(stackPointer - (1 * 4));
		maskObj = longAt(stackPointer);
	}
	/* begin success: */
	successFlag = (argumentCount < 2) && successFlag;
	/* begin success: */
	successValue7 = (((((unsigned) (longAt(cursorObj))) >> 8) & 15) <= 4) && ((lengthOf(cursorObj)) >= 5);
	successFlag = successValue7 && successFlag;
	if (successFlag) {
		bitsObj = longAt(((((char *) cursorObj)) + 4) + (0 << 2));
		extentX = fetchIntegerofObject(1, cursorObj);
		extentY = fetchIntegerofObject(2, cursorObj);
		depth = fetchIntegerofObject(3, cursorObj);
		offsetObj = longAt(((((char *) cursorObj)) + 4) + (4 << 2));
	}
	/* begin success: */
	successValue8 = (((((unsigned) (longAt(offsetObj))) >> 8) & 15) <= 4) && ((lengthOf(offsetObj)) >= 2);
	successFlag = successValue8 && successFlag;
	if (successFlag) {
		offsetX = fetchIntegerofObject(0, offsetObj);
		offsetY = fetchIntegerofObject(1, offsetObj);
		/* begin success: */
		successValue = (extentX == 16) && ((extentY == 16) && (depth == 1));
		successFlag = successValue && successFlag;
		/* begin success: */
		successValue1 = (offsetX >= -16) && (offsetX <= 0);
		successFlag = successValue1 && successFlag;
		/* begin success: */
		successValue2 = (offsetY >= -16) && (offsetY <= 0);
		successFlag = successValue2 && successFlag;
		/* begin success: */
		successValue3 = (((((unsigned) (longAt(bitsObj))) >> 8) & 15) == 6) && ((lengthOf(bitsObj)) == 16);
		successFlag = successValue3 && successFlag;
		cursorBitsIndex = bitsObj + 4;
		;
	}
	if (argumentCount == 1) {
		/* begin success: */
		successValue6 = (((((unsigned) (longAt(maskObj))) >> 8) & 15) <= 4) && ((lengthOf(maskObj)) >= 5);
		successFlag = successValue6 && successFlag;
		if (successFlag) {
			bitsObj = longAt(((((char *) maskObj)) + 4) + (0 << 2));
			extentX = fetchIntegerofObject(1, maskObj);
			extentY = fetchIntegerofObject(2, maskObj);
			depth = fetchIntegerofObject(3, maskObj);
		}
		if (successFlag) {
			/* begin success: */
			successValue4 = (extentX == 16) && ((extentY == 16) && (depth == 1));
			successFlag = successValue4 && successFlag;
			/* begin success: */
			successValue5 = (((((unsigned) (longAt(bitsObj))) >> 8) & 15) == 6) && ((lengthOf(bitsObj)) == 16);
			successFlag = successValue5 && successFlag;
			maskBitsIndex = bitsObj + 4;
		}
	}
	if (successFlag) {
		if (argumentCount == 0) {
			ioSetCursor(cursorBitsIndex, offsetX, offsetY);
		} else {
			ioSetCursorWithMask(cursorBitsIndex, maskBitsIndex, offsetX, offsetY);
		}
		/* begin pop: */
		stackPointer -= argumentCount * 4;
	}
}


/*	Record the system Display object. */

int primitiveBeDisplay(void) {
    int rcvr;
    int oop;
    int successValue;

	rcvr = longAt(stackPointer);
	/* begin success: */
	successValue = (((((unsigned) (longAt(rcvr))) >> 8) & 15) <= 4) && ((lengthOf(rcvr)) >= 4);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin storePointer:ofObject:withValue: */
		oop = specialObjectsOop;
		if (oop < youngStart) {
			possibleRootStoreIntovalue(oop, rcvr);
		}
		longAtput(((((char *) oop)) + 4) + (14 << 2), rcvr);
	}
}

int primitiveBeep(void) {
	ioBeep();
}

int primitiveBitAnd(void) {
    int integerArgument;
    int integerReceiver;
    int object;
    int sp;
    int top;
    int top1;
    int top2;
    int top11;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	top = top1;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top11 = longAt(stackPointer);
	stackPointer -= 4;
	top2 = top11;
	integerReceiver = positive32BitValueOf(top2);
	if (successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver & integerArgument);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveBitOr(void) {
    int integerArgument;
    int integerReceiver;
    int object;
    int sp;
    int top;
    int top1;
    int top2;
    int top11;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	top = top1;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top11 = longAt(stackPointer);
	stackPointer -= 4;
	top2 = top11;
	integerReceiver = positive32BitValueOf(top2);
	if (successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver | integerArgument);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveBitShift(void) {
    int shifted;
    int integerArgument;
    int integerReceiver;
    int integerPointer;
    int object;
    int sp;
    int top;
    int top2;
    int top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		integerArgument = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	top2 = top1;
	integerReceiver = positive32BitValueOf(top2);
	if (successFlag) {
		if (integerArgument >= 0) {
			/* begin success: */
			successFlag = (integerArgument <= 31) && successFlag;
			shifted = integerReceiver << integerArgument;
			/* begin success: */
			successFlag = ((((unsigned) shifted) >> integerArgument) == integerReceiver) && successFlag;
		} else {
			/* begin success: */
			successFlag = (integerArgument >= -31) && successFlag;
			shifted = ((integerArgument < 0) ? ((unsigned) integerReceiver >> -integerArgument) : ((unsigned) integerReceiver << integerArgument));
		}
	}
	if (successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(shifted);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveBitXor(void) {
    int integerArgument;
    int integerReceiver;
    int object;
    int sp;
    int top;
    int top1;
    int top2;
    int top11;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	top = top1;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top11 = longAt(stackPointer);
	stackPointer -= 4;
	top2 = top11;
	integerReceiver = positive32BitValueOf(top2);
	if (successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver ^ integerArgument);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveBlockCopy(void) {
    int methodContext;
    int context;
    int contextSize;
    int newContext;
    int initialIP;
    int header;
    int oop;
    int sp;

	context = longAt(stackPointer - (1 * 4));
	if (((longAt(((((char *) context)) + 4) + (3 << 2))) & 1)) {
		methodContext = longAt(((((char *) context)) + 4) + (5 << 2));
	} else {
		methodContext = context;
	}
	/* begin sizeBitsOf: */
	header = longAt(methodContext);
	if ((header & 3) == 0) {
		contextSize = (longAt(methodContext - 8)) & 4294967292U;
		goto l1;
	} else {
		contextSize = header & 252;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;

	/* context is no longer needed and is not preserved across allocation */
	/* remap methodContext in case GC happens during allocation */

	context = null;
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = methodContext;
	newContext = instantiateContextsizeInBytes(longAt(((((char *) specialObjectsOop)) + 4) + (11 << 2)), contextSize);
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	methodContext = oop;

	/* Was instructionPointer + 3, but now it's greater by 
		methodOop + 4 (headerSize) and less by 1 due to preIncrement */
	/* Assume: have just allocated a new context; it must be young.
	 Thus, can use uncheck stores. See the comment in fetchContextRegisters. */

	initialIP = (((instructionPointer - method) << 1) | 1);
	longAtput(((((char *) newContext)) + 4) + (4 << 2), initialIP);
	longAtput(((((char *) newContext)) + 4) + (1 << 2), initialIP);
	/* begin storeStackPointerValue:inContext: */
	longAtput(((((char *) newContext)) + 4) + (2 << 2), ((0 << 1) | 1));
	longAtput(((((char *) newContext)) + 4) + (3 << 2), longAt(stackPointer - (0 * 4)));
	longAtput(((((char *) newContext)) + 4) + (5 << 2), methodContext);
	longAtput(((((char *) newContext)) + 4) + (0 << 2), nilObj);
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((2 - 1) * 4), newContext);
	stackPointer = sp;
}


/*	Reports bytes available at this moment. For more meaningful results, calls to this primitive should be preceeded by a full or incremental garbage collection. */

int primitiveBytesLeft(void) {
    int aBool;
    int sp;
    int integerValue;
    int sp1;

	if (argumentCount == 0) {
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((((longAt(freeBlock)) & 4294967292U) << 1) | 1));
		stackPointer = sp;
		return null;
	}
	if (argumentCount == 1) {
		/* begin booleanValueOf: */
		if ((longAt(stackPointer)) == trueObj) {
			aBool = 1;
			goto l1;
		}
		if ((longAt(stackPointer)) == falseObj) {
			aBool = 0;
			goto l1;
		}
		successFlag = 0;
		aBool = null;
	l1:	/* end booleanValueOf: */;
		if (!(successFlag)) {
			return null;
		}
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushInteger: */
		integerValue = ((longAt(freeBlock)) & 4294967292U) + (sqMemoryExtraBytesLeft(aBool));
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, ((integerValue << 1) | 1));
		stackPointer = sp1;
		return null;
	}
	/* begin primitiveFail */
	successFlag = 0;
	return null;
}


/*	Perform a function call to a foreign function.
	Only invoked from method containing explicit external call spec.
	Due to this we use the pluggable prim mechanism explicitly here
	(the first literal of any FFI spec'ed method is an ExternalFunction
	and not an array as used in the pluggable primitive mechanism). */

int primitiveCalloutToFFI(void) {
    static char *moduleName = "SqueakFFIPrims";
    static char *functionName = "primitiveCallout";
    static int function = 0;

	if (function == 0) {
		function = ioLoadExternalFunctionOfLengthFromModuleOfLength(((int) functionName), 16, ((int) moduleName), 14);
		if (function == 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	return ((int (*) (void)) function) ();
}


/*	Primitive. Change the class of the receiver into the class of the argument given that the format of the receiver matches the format of the argument's class. Fail if receiver or argument are SmallIntegers, or the receiver is an instance of a compact class and the argument isn't, or when the argument's class is compact and the receiver isn't, or when the format of the receiver is different from the format of the argument's class, or when the arguments class is fixed and the receiver's size differs from the size that an instance of the argument's class should have. */

int primitiveChangeClass(void) {
    int byteSize;
    int classHdr;
    int rcvrFormat;
    int rcvr;
    int sizeHiBits;
    int argClass;
    int argFormat;
    int ccIndex;
    int arg;
    int oop;
    int oop1;
    int i;
    int ccIndex1;

	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		arg = null;
		goto l1;
	}
	arg = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop1;
l2:	/* end stackObjectValue: */;
	if (!(successFlag)) {
		return null;
	}
	/* begin fetchClassOf: */
	if ((arg & 1)) {
		argClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex1 = (((unsigned) (longAt(arg))) >> 12) & 31;
	if (ccIndex1 == 0) {
		argClass = (longAt(arg - 4)) & 4294967292U;
		goto l3;
	} else {
		argClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;

	/* Low 2 bits are 0 */
	/* Compute the size of instances of the class (used for fixed field classes only) */

	classHdr = (longAt(((((char *) argClass)) + 4) + (2 << 2))) - 1;
	sizeHiBits = ((unsigned) (classHdr & 393216)) >> 9;
	classHdr = classHdr & 131071;

	/* size in bytes -- low 2 bits are 0 */
	/* Check the receiver's format against that of the class */

	byteSize = (classHdr & 252) + sizeHiBits;
	argFormat = (((unsigned) classHdr) >> 8) & 15;
	rcvrFormat = (((unsigned) (longAt(rcvr))) >> 8) & 15;
	if (!(argFormat == rcvrFormat)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if (argFormat < 2) {
		if (!((byteSize - 4) == (byteSizeOf(rcvr)))) {
			/* begin success: */
			successFlag = 0 && successFlag;
			return null;
		}
	}
	if (((longAt(rcvr)) & 3) == 3) {
		ccIndex = classHdr & 126976;
		if (ccIndex == 0) {
			/* begin success: */
			successFlag = 0 && successFlag;
			return null;
		}
		longAtput(rcvr, ((longAt(rcvr)) & (~126976)) | ccIndex);
	} else {
		longAtput(rcvr - 4, argClass | ((longAt(rcvr)) & 3));
		if (rcvr < youngStart) {
			possibleRootStoreIntovalue(rcvr, argClass);
		}
	}
	/* begin flushMethodCache */
	for (i = 1; i <= 4096; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= 64; i += 1) {
		atCache[i] = 0;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveClass(void) {
    int instance;
    int top;
    int object;
    int sp;
    int ccIndex;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	instance = top;
	/* begin push: */
	/* begin fetchClassOf: */
	if ((instance & 1)) {
		object = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(instance))) >> 12) & 31;
	if (ccIndex == 0) {
		object = (longAt(instance - 4)) & 4294967292U;
		goto l1;
	} else {
		object = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
}


/*	When called with a single string argument, post the string to the clipboard. When called with zero arguments, return a string containing the current clipboard contents. */

int primitiveClipboardText(void) {
    int s;
    int sz;
    int sp;
    int cl;
    int ccIndex;
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int sp1;
    int sz1;
    int classFormat;
    int class;
    int ccIndex1;

	if (argumentCount == 1) {
		s = longAt(stackPointer);
		/* begin assertClassOf:is: */
		if ((s & 1)) {
			successFlag = 0;
			goto l1;
		}
		ccIndex = (((unsigned) (longAt(s))) >> 12) & 31;
		if (ccIndex == 0) {
			cl = (longAt(s - 4)) & 4294967292U;
		} else {
			cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		}
		/* begin success: */
		successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)))) && successFlag;
	l1:	/* end assertClassOf:is: */;
		if (successFlag) {
			/* begin stSizeOf: */
			hdr = longAt(s);
			fmt = (((unsigned) hdr) >> 8) & 15;
			/* begin lengthOf:baseHeader:format: */
			if ((hdr & 3) == 0) {
				sz1 = (longAt(s - 8)) & 4294967292U;
			} else {
				sz1 = hdr & 252;
			}
			if (fmt < 8) {
				totalLength = ((unsigned) (sz1 - 4)) >> 2;
				goto l4;
			} else {
				totalLength = (sz1 - 4) - (fmt & 3);
				goto l4;
			}
		l4:	/* end lengthOf:baseHeader:format: */;
			/* begin fixedFieldsOf:format:length: */
			if ((fmt > 4) || (fmt == 2)) {
				fixedFields = 0;
				goto l2;
			}
			if (fmt < 2) {
				fixedFields = totalLength;
				goto l2;
			}
			/* begin fetchClassOf: */
			if ((s & 1)) {
				class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
				goto l3;
			}
			ccIndex1 = (((unsigned) (longAt(s))) >> 12) & 31;
			if (ccIndex1 == 0) {
				class = (longAt(s - 4)) & 4294967292U;
				goto l3;
			} else {
				class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
				goto l3;
			}
		l3:	/* end fetchClassOf: */;
			classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
			fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
		l2:	/* end fixedFieldsOf:format:length: */;
			if ((fmt == 3) && (isContextHeader(hdr))) {
				/* begin fetchStackPointerOf: */
				sp1 = longAt(((((char *) s)) + 4) + (2 << 2));
				if (!((sp1 & 1))) {
					sz = 0;
					goto l5;
				}
				sz = (sp1 >> 1);
				goto l5;
			} else {
				sz = totalLength - fixedFields;
				goto l5;
			}
		l5:	/* end stSizeOf: */;
			clipboardWriteFromAt(sz, s + 4, 0);
			/* begin pop: */
			stackPointer -= 1 * 4;
		}
	} else {
		sz = clipboardSize();
		s = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), sz);
		clipboardReadIntoAt(sz, s + 4, 0);
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, s);
		stackPointer = sp;
	}
}


/*	Return a shallow copy of the receiver. */

int primitiveClone(void) {
    int newCopy;
    int sp;

	newCopy = clone(longAt(stackPointer));
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((1 - 1) * 4), newCopy);
	stackPointer = sp;
}


/*	Fill the receiver, which must be an indexable bytes or words objects, with the given integer value. */

int primitiveConstantFill(void) {
    int rcvrIsBytes;
    int fillValue;
    int i;
    int end;
    int rcvr;
    int successValue;
    int successValue1;
    int fmt;

	fillValue = positive32BitValueOf(longAt(stackPointer));
	rcvr = longAt(stackPointer - (1 * 4));
	/* begin success: */
	/* begin isWordsOrBytes: */
	fmt = (((unsigned) (longAt(rcvr))) >> 8) & 15;
	successValue1 = (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
	successFlag = successValue1 && successFlag;
	rcvrIsBytes = ((((unsigned) (longAt(rcvr))) >> 8) & 15) >= 8;
	if (rcvrIsBytes) {
		/* begin success: */
		successValue = (fillValue >= 0) && (fillValue <= 255);
		successFlag = successValue && successFlag;
	}
	if (successFlag) {
		end = rcvr + (sizeBitsOf(rcvr));
		i = rcvr + 4;
		if (rcvrIsBytes) {
			while (i < end) {
				byteAtput(i, fillValue);
				i += 1;
			}
		} else {
			while (i < end) {
				longAtput(i, fillValue);
				i += 4;
			}
		}
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}


/*	Set or clear the flag that controls whether modifications of the Display object are propagated to the underlying platform's screen. */

int primitiveDeferDisplayUpdates(void) {
    int flag;

	flag = longAt(stackPointer);
	if (flag == trueObj) {
		deferDisplayUpdates = 1;
	} else {
		if (flag == falseObj) {
			deferDisplayUpdates = 0;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}


/*	Pass in a non-negative value to disable the architectures powermanager if any, zero to enable */

EXPORT(int) primitiveDisablePowerManager(void) {
    int integer;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		integer = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integer = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		ioDisablePowerManager(integer);
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveDiv(void) {
    int quotient;
    int sp;

	quotient = doPrimitiveDivby(longAt(stackPointer - (1 * 4)), longAt(stackPointer - (0 * 4)));
	/* begin pop2AndPushIntegerIfOK: */
	if (successFlag) {
		if ((quotient ^ (quotient << 1)) >= 0) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * 4), ((quotient << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}

int primitiveDivide(void) {
    int integerArgument;
    int integerReceiver;
    int integerPointer;
    int integerPointer1;
    int sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		integerReceiver = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerReceiver = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (0 * 4));
	if ((integerPointer1 & 1)) {
		integerArgument = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArgument = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	if ((integerArgument != 0) && ((integerReceiver % integerArgument) == 0)) {
		/* begin pop2AndPushIntegerIfOK: */
		if (successFlag) {
			if (((integerReceiver / integerArgument) ^ ((integerReceiver / integerArgument) << 1)) >= 0) {
				/* begin pop:thenPush: */
				longAtput(sp = stackPointer - ((2 - 1) * 4), (((integerReceiver / integerArgument) << 1) | 1));
				stackPointer = sp;
			} else {
				successFlag = 0;
			}
		}
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
}

int primitiveDoPrimitiveWithArgs(void) {
    int argumentArray;
    int arraySize;
    int cntxSize;
    int primIdx;
    int index;
    int sp;
    int sp1;
    int sp2;
    int sz;
    int objectPointer;
    int sz1;
    int integerPointer;
    int oop;
    int header;
    int header1;
    int cl;
    int ccIndex;

	argumentArray = longAt(stackPointer);
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(argumentArray);
	if ((header & 3) == 0) {
		sz = (longAt(argumentArray - 8)) & 4294967292U;
		goto l2;
	} else {
		sz = header & 252;
		goto l2;
	}
l2:	/* end sizeBitsOf: */;
	arraySize = ((unsigned) (sz - 4)) >> 2;
	/* begin fetchWordLengthOf: */
	objectPointer = activeContext;
	/* begin sizeBitsOf: */
	header1 = longAt(objectPointer);
	if ((header1 & 3) == 0) {
		sz1 = (longAt(objectPointer - 8)) & 4294967292U;
		goto l3;
	} else {
		sz1 = header1 & 252;
		goto l3;
	}
l3:	/* end sizeBitsOf: */;
	cntxSize = ((unsigned) (sz1 - 4)) >> 2;
	/* begin success: */
	successFlag = (((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) + arraySize) < cntxSize) && successFlag;
	/* begin assertClassOf:is: */
	if ((argumentArray & 1)) {
		successFlag = 0;
		goto l4;
	}
	ccIndex = (((unsigned) (longAt(argumentArray))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(argumentArray - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))) && successFlag;
l4:	/* end assertClassOf:is: */;
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		primIdx = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		primIdx = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop: */
	stackPointer -= 2 * 4;
	primitiveIndex = primIdx;
	argumentCount = arraySize;
	index = 1;
	while (index <= argumentCount) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, longAt(((((char *) argumentArray)) + 4) + ((index - 1) << 2)));
		stackPointer = sp;
		index += 1;
	}
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = argumentArray;
	lkupClass = nilObj;
	primitiveResponse();
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	argumentArray = oop;
	if (!(successFlag)) {
		/* begin pop: */
		stackPointer -= arraySize * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, ((primIdx << 1) | 1));
		stackPointer = sp1;
		/* begin push: */
		longAtput(sp2 = stackPointer + 4, argumentArray);
		stackPointer = sp2;
		argumentCount = 2;
	}
}

int primitiveEqual(void) {
    int result;
    int integerArgument;
    int integerReceiver;
    int top;
    int top1;
    int sp;
    int sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerArgument = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerReceiver = top1;
	/* begin compare31or32Bits:equal: */
	if (((integerReceiver & 1)) && ((integerArgument & 1))) {
		result = integerReceiver == integerArgument;
		goto l1;
	}
	result = (positive32BitValueOf(integerReceiver)) == (positive32BitValueOf(integerArgument));
l1:	/* end compare31or32Bits:equal: */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (result) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveEquivalent(void) {
    int otherObject;
    int thisObject;
    int top;
    int top1;
    int sp;
    int sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	otherObject = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	thisObject = top1;
	/* begin pushBool: */
	if (thisObject == otherObject) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	}
}

int primitiveExitToDebugger(void) {
	error("Exit to debugger at user request");
}


/*	Computes E raised to the receiver power. */

int primitiveExp(void) {
    double rcvr;

	rcvr = popFloat();
	if (successFlag) {
		pushFloat(exp(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	Exponent part of this float. */

int primitiveExponent(void) {
    double frac;
    double rcvr;
    int pwr;
    int sp;

	rcvr = popFloat();
	if (successFlag) {
		frac = frexp(rcvr, &pwr);
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, (((pwr - 1) << 1) | 1));
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	Call an external primitive. The external primitive methods contain as first literal an array consisting of:
		* The module name (String | Symbol)
		* The function name (String | Symbol)
		* The session ID (SmallInteger) [OBSOLETE]
		* The function index (Integer) in the externalPrimitiveTable
	For fast failures the primitive index of any method where the external prim is not found is rewritten in the method cache with zero. This allows for ultra fast responses as long as the method stays in the cache.
	The fast failure response relies on lkupClass being properly set. This is done in #addToMethodCacheSel:class:method:primIndex: to compensate for execution of methods that are looked up in a superclass (such as in primitivePerformAt).
	With the latest modifications (e.g., actually flushing the function addresses from the VM), the session ID is obsolete. But for backward compatibility it is still kept around. Also, a failed lookup is reported specially. If a method has been looked up and not been found, the function address is stored as -1 (e.g., the SmallInteger -1 to distinguish from 16rFFFFFFFF which may be returned from the lookup).
	It is absolutely okay to remove the rewrite if we run into any problems later on. It has an approximate speed difference of 30% per failed primitive call which may be noticable but if, for any reasons, we run into problems (like with J3) we can always remove the rewrite.
	 */

int primitiveExternalCall(void) {
    int moduleLength;
    int delta;
    int lit;
    int moduleName;
    int index;
    int functionName;
    int addr;
    int functionLength;
    int nArgs;
    int header;
    int sz;
    int i;
    int successValue;
    int header1;
    int sz1;

	;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(((((char *) newMethod)) + 4) + (0 << 2)))) >> 10) & 255) > 0) && successFlag;
	if (!(successFlag)) {
		return null;
	}

	/* Check if it's an array of length 4 */

	lit = longAt(((((char *) newMethod)) + 4) + ((0 + 1) << 2));
	/* begin success: */
	successValue = ((fetchClassOf(lit)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))) && ((lengthOf(lit)) == 4);
	successFlag = successValue && successFlag;
	if (!(successFlag)) {
		return null;
	}
	index = longAt(((((char *) lit)) + 4) + (3 << 2));
	if (!((index & 1))) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}

	/* Check if we have already looked up the function and failed. */

	index = (index >> 1);
	if (index < 0) {
		rewriteMethodCacheSelclassprimIndex(messageSelector, lkupClass, 0);
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if ((index > 0) && (index <= 4096)) {
		addr = externalPrimitiveTable[index - 1];
		if (addr != 0) {
			 ((int (*) (void)) addr) ();
			;
			return null;
		}
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if ((0 ^ (0 << 1)) >= 0) {
		longAtput(((((char *) lit)) + 4) + (2 << 2), ((0 << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if ((0 ^ (0 << 1)) >= 0) {
		longAtput(((((char *) lit)) + 4) + (3 << 2), ((0 << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	moduleName = longAt(((((char *) lit)) + 4) + (0 << 2));
	if (moduleName == nilObj) {
		moduleLength = 0;
	} else {
		/* begin success: */
		successFlag = (((((unsigned) (longAt(moduleName))) >> 8) & 15) >= 8) && successFlag;
		/* begin lengthOf: */
		header = longAt(moduleName);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(moduleName - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			moduleLength = ((unsigned) (sz - 4)) >> 2;
			goto l1;
		} else {
			moduleLength = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l1;
		}
		moduleLength = null;
	l1:	/* end lengthOf: */;
	}
	functionName = longAt(((((char *) lit)) + 4) + (1 << 2));
	/* begin success: */
	successFlag = (((((unsigned) (longAt(functionName))) >> 8) & 15) >= 8) && successFlag;
	/* begin lengthOf: */
	header1 = longAt(functionName);
	/* begin lengthOf:baseHeader:format: */
	if ((header1 & 3) == 0) {
		sz1 = (longAt(functionName - 8)) & 4294967292U;
	} else {
		sz1 = header1 & 252;
	}
	if (((((unsigned) header1) >> 8) & 15) < 8) {
		functionLength = ((unsigned) (sz1 - 4)) >> 2;
		goto l3;
	} else {
		functionLength = (sz1 - 4) - (((((unsigned) header1) >> 8) & 15) & 3);
		goto l3;
	}
	functionLength = null;
l3:	/* end lengthOf: */;
	if (!(successFlag)) {
		return null;
	}

	/* Addr ~= 0 indicates we have a compat match later */

	addr = 0;
	if (moduleLength == 0) {

		/* The returned value is the index into the obsolete primitive table.
		If the index is found, use the 'C-style' version of the lookup. */

		index = findObsoleteNamedPrimitivelength(((char *) (functionName + 4)), functionLength);
		if (!(index < 0)) {
			addr = ioLoadFunctionFrom(((char*) ((obsoleteNamedPrimitiveTable[index])[2])), ((char*) ((obsoleteNamedPrimitiveTable[index])[1])));
		}
	}
	if (addr == 0) {
		addr = ioLoadExternalFunctionOfLengthFromModuleOfLength(functionName + 4, functionLength, moduleName + 4, moduleLength);
	}
	if (addr == 0) {
		index = -1;
	} else {
		/* begin addToExternalPrimitiveTable: */
		for (i = 0; i <= (4096 - 1); i += 1) {
			if ((externalPrimitiveTable[i]) == 0) {
				externalPrimitiveTable[i] = addr;
				index = i + 1;
				goto l2;
			}
		}
		index = 0;
	l2:	/* end addToExternalPrimitiveTable: */;
	}
	/* begin success: */
	successFlag = (index >= 0) && successFlag;
	/* begin storePointer:ofObject:withValue: */
	if (lit < youngStart) {
		possibleRootStoreIntovalue(lit, ((index << 1) | 1));
	}
	longAtput(((((char *) lit)) + 4) + (3 << 2), ((index << 1) | 1));
	if (successFlag && (addr != 0)) {
		 ((int (*) (void)) addr) ();
		;
	} else {
		rewriteMethodCacheSelclassprimIndex(messageSelector, lkupClass, 0);
	}
}

int primitiveFail(void) {
	successFlag = 0;
}


/*	Primitive. Search up the context stack for the next method context marked for exception handling starting at the receiver. Return nil if none found */

int primitiveFindHandlerContext(void) {
    int thisCntx;
    int nilOop;
    int sp;
    int top;
    int sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	thisCntx = top;
	nilOop = nilObj;
	do {
		if (isHandlerMarked(thisCntx)) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, thisCntx);
			stackPointer = sp;
			return null;
		}
		thisCntx = longAt(((((char *) thisCntx)) + 4) + (0 << 2));
	} while(!(thisCntx == nilOop));
	/* begin push: */
	longAtput(sp1 = stackPointer + 4, nilObj);
	stackPointer = sp1;
	return null;
}


/*	Primitive. Search up the context stack for the next method context marked for unwind handling from the receiver up to but not including the argument. Return nil if none found. */

int primitiveFindNextUnwindContext(void) {
    int aContext;
    int thisCntx;
    int nilOop;
    int sp;
    int top;
    int oop;
    int sp1;
    int top1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	aContext = top;
	/* begin fetchPointer:ofObject: */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	oop = top1;
	thisCntx = longAt(((((char *) oop)) + 4) + (0 << 2));
	nilOop = nilObj;
	while (!((thisCntx == aContext) || (thisCntx == nilOop))) {
		if (isUnwindMarked(thisCntx)) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, thisCntx);
			stackPointer = sp;
			return null;
		}
		thisCntx = longAt(((((char *) thisCntx)) + 4) + (0 << 2));
	}
	/* begin push: */
	longAtput(sp1 = stackPointer + 4, nilOop);
	stackPointer = sp1;
	return null;
}

int primitiveFloatAdd(void) {
	return primitiveFloatAddtoArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
}

int primitiveFloatAddtoArg(int rcvrOop, int argOop) {
    double rcvr;
    double arg;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		pushFloat(rcvr + arg);
	}
}

int primitiveFloatDivide(void) {
	return primitiveFloatDividebyArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
}

int primitiveFloatDividebyArg(int rcvrOop, int argOop) {
    double rcvr;
    double arg;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		/* begin success: */
		successFlag = (arg != 0.0) && successFlag;
		if (successFlag) {
			/* begin pop: */
			stackPointer -= 2 * 4;
			pushFloat(rcvr / arg);
		}
	}
}

int primitiveFloatEqual(void) {
    int bool;
    int sp;
    int sp1;

	bool = primitiveFloatEqualtoArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (bool) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	}
}

int primitiveFloatEqualtoArg(int rcvrOop, int argOop) {
    double rcvr;
    double arg;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		return rcvr == arg;
	}
}

int primitiveFloatGreaterthanArg(int rcvrOop, int argOop) {
    double rcvr;
    double arg;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		return rcvr > arg;
	}
}

int primitiveFloatGreaterOrEqual(void) {
    int bool;
    int sp;
    int sp1;

	bool = primitiveFloatLessthanArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (!bool) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	}
}

int primitiveFloatGreaterThan(void) {
    int bool;
    int sp;
    int sp1;

	bool = primitiveFloatGreaterthanArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (bool) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	}
}

int primitiveFloatLessthanArg(int rcvrOop, int argOop) {
    double rcvr;
    double arg;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		return rcvr < arg;
	}
}

int primitiveFloatLessOrEqual(void) {
    int bool;
    int sp;
    int sp1;

	bool = primitiveFloatGreaterthanArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (!bool) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	}
}

int primitiveFloatLessThan(void) {
    int bool;
    int sp;
    int sp1;

	bool = primitiveFloatLessthanArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (bool) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	}
}

int primitiveFloatMultiply(void) {
	return primitiveFloatMultiplybyArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
}

int primitiveFloatMultiplybyArg(int rcvrOop, int argOop) {
    double rcvr;
    double arg;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		pushFloat(rcvr * arg);
	}
}

int primitiveFloatNotEqual(void) {
    int bool;
    int sp;
    int sp1;

	bool = primitiveFloatEqualtoArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (!bool) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	}
}

int primitiveFloatSubtract(void) {
	return primitiveFloatSubtractfromArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
}

int primitiveFloatSubtractfromArg(int rcvrOop, int argOop) {
    double rcvr;
    double arg;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		pushFloat(rcvr - arg);
	}
}


/*	Clear the method lookup cache. This must be done after every programming change. */

int primitiveFlushCache(void) {
    int i;

	/* begin flushMethodCache */
	for (i = 1; i <= 4096; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= 64; i += 1) {
		atCache[i] = 0;
	}
	/* begin compilerFlushCacheHook: */
	if (compilerInitialized) {
		compilerFlushCache(null);
	}
}


/*	The receiver is a compiledMethod.  Clear all entries in the method lookup cache that refer to this method, presumably because it has been redefined, overridden or removed. */

int primitiveFlushCacheByMethod(void) {
    int i;
    int probe;
    int oldMethod;

	oldMethod = longAt(stackPointer);
	probe = 0;
	for (i = 1; i <= 512; i += 1) {
		if ((methodCache[probe + 3]) == oldMethod) {
			methodCache[probe + 1] = 0;
		}
		probe += 8;
	}
	/* begin compilerFlushCacheHook: */
	if (compilerInitialized) {
		compilerFlushCache(oldMethod);
	}
}


/*	The receiver is a message selector.  Clear all entries in the method lookup cache with this selector, presumably because an associated method has been redefined. */

int primitiveFlushCacheSelective(void) {
    int i;
    int probe;
    int selector;

	selector = longAt(stackPointer);
	probe = 0;
	for (i = 1; i <= 512; i += 1) {
		if ((methodCache[probe + 1]) == selector) {
			methodCache[probe + 1] = 0;
		}
		probe += 8;
	}
}


/*	Primitive. Flush all the existing external primitives in the image thus forcing a reload on next invokation. */

int primitiveFlushExternalPrimitives(void) {
	return flushExternalPrimitives();
}


/*	On some platforms, this primitive forces enqueued display updates to be processed immediately. On others, it does nothing. */

int primitiveForceDisplayUpdate(void) {
	ioForceDisplayUpdate();
}


/*	On platforms that support it, this primitive prints the receiver, assumed to be a Form, to the default printer. */

int primitiveFormPrint(void) {
    int landscapeFlag;
    int depth;
    int w;
    int pixelsPerWord;
    int wordsPerLine;
    int h;
    int bitsArraySize;
    double vScale;
    int ok;
    int rcvr;
    double hScale;
    int bitsArray;
    int header;
    int fmt;
    int sz;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer)) == trueObj) {
		landscapeFlag = 1;
		goto l2;
	}
	if ((longAt(stackPointer)) == falseObj) {
		landscapeFlag = 0;
		goto l2;
	}
	successFlag = 0;
	landscapeFlag = null;
l2:	/* end booleanValueOf: */;
	vScale = floatValueOf(longAt(stackPointer - (1 * 4)));
	hScale = floatValueOf(longAt(stackPointer - (2 * 4)));
	rcvr = longAt(stackPointer - (3 * 4));
	if ((rcvr & 1)) {
		/* begin success: */
		successFlag = 0 && successFlag;
	}
	if (successFlag) {
		if (!((((((unsigned) (longAt(rcvr))) >> 8) & 15) <= 4) && ((lengthOf(rcvr)) >= 4))) {
			/* begin success: */
			successFlag = 0 && successFlag;
		}
	}
	if (successFlag) {
		bitsArray = longAt(((((char *) rcvr)) + 4) + (0 << 2));
		w = fetchIntegerofObject(1, rcvr);
		h = fetchIntegerofObject(2, rcvr);
		depth = fetchIntegerofObject(3, rcvr);
		if (!((w > 0) && (h > 0))) {
			/* begin success: */
			successFlag = 0 && successFlag;
		}
		pixelsPerWord = 32 / depth;
		wordsPerLine = (w + (pixelsPerWord - 1)) / pixelsPerWord;
		if ((!((rcvr & 1))) && (isWordsOrBytes(bitsArray))) {
			/* begin byteLengthOf: */
			header = longAt(bitsArray);
			if ((header & 3) == 0) {
				sz = (longAt(bitsArray - 8)) & 4294967292U;
			} else {
				sz = header & 252;
			}
			fmt = (((unsigned) header) >> 8) & 15;
			if (fmt < 8) {
				bitsArraySize = sz - 4;
				goto l1;
			} else {
				bitsArraySize = (sz - 4) - (fmt & 3);
				goto l1;
			}
		l1:	/* end byteLengthOf: */;
			/* begin success: */
			successFlag = (bitsArraySize == ((wordsPerLine * h) * 4)) && successFlag;
		} else {
			/* begin success: */
			successFlag = 0 && successFlag;
		}
	}
	if (successFlag) {
		ok = ioFormPrint(bitsArray + 4, w, h, depth, hScale, vScale, landscapeFlag);
		/* begin success: */
		successFlag = ok && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
	}
}

int primitiveFractionalPart(void) {
    double frac;
    double trunc;
    double rcvr;

	rcvr = popFloat();
	if (successFlag) {
		frac = modf(rcvr, &trunc);
		pushFloat(frac);
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	Do a quick, incremental garbage collection and return the number of bytes available (including swap space if dynamic memory management is supported). */

int primitiveFullGC(void) {
    int integerValue;
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	incrementalGC();
	fullGC();
	/* begin pushInteger: */
	integerValue = ((longAt(freeBlock)) & 4294967292U) + (sqMemoryExtraBytesLeft(1));
	/* begin push: */
	longAtput(sp = stackPointer + 4, ((integerValue << 1) | 1));
	stackPointer = sp;
}


/*	Fetch the system attribute with the given integer ID. The result is a string, which will be empty if the attribute is not defined. */

int primitiveGetAttribute(void) {
    int attr;
    int s;
    int sz;
    int sp;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		attr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		attr = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		sz = attributeSize(attr);
	}
	if (successFlag) {
		s = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), sz);
		getAttributeIntoLength(attr, s + 4, sz);
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, s);
		stackPointer = sp;
	}
}


/*	Primitive. Return the next input event from the OS event queue. */

int primitiveGetNextEvent(void) {
    int evtBuf[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int i;
    int value;
    int arg;
    int oop;

	;
	arg = longAt(stackPointer - (0 * 4));
	if (!(((fetchClassOf(arg)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))) && ((slotSizeOf(arg)) == 8))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	ioGetNextEvent(((sqInputEvent*) evtBuf));
	if (!(successFlag)) {
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (((evtBuf[0]) ^ ((evtBuf[0]) << 1)) >= 0) {
		longAtput(((((char *) arg)) + 4) + (0 << 2), (((evtBuf[0]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (!(successFlag)) {
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if ((((evtBuf[1]) & 536870911) ^ (((evtBuf[1]) & 536870911) << 1)) >= 0) {
		longAtput(((((char *) arg)) + 4) + (1 << 2), ((((evtBuf[1]) & 536870911) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (!(successFlag)) {
		return null;
	}
	for (i = 2; i <= 7; i += 1) {
		value = evtBuf[i];
		if ((value ^ (value << 1)) >= 0) {
			/* begin storeInteger:ofObject:withValue: */
			if ((value ^ (value << 1)) >= 0) {
				longAtput(((((char *) arg)) + 4) + (i << 2), ((value << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
		} else {
			/* begin pushRemappableOop: */
			remapBuffer[remapBufferCount += 1] = arg;
			value = positive32BitIntegerFor(value);
			/* begin popRemappableOop */
			oop = remapBuffer[remapBufferCount];
			remapBufferCount -= 1;
			arg = oop;
			/* begin storePointer:ofObject:withValue: */
			if (arg < youngStart) {
				possibleRootStoreIntovalue(arg, value);
			}
			longAtput(((((char *) arg)) + 4) + (i << 2), value);
		}
	}
	if (!(successFlag)) {
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

int primitiveGreaterOrEqual(void) {
    int integerArgument;
    int integerReceiver;
    int integerPointer;
    int integerPointer1;
    int top;
    int top1;
    int sp;
    int sp1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		integerArgument = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer1 = top1;
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		successFlag = 0;
		integerReceiver = 1;
		goto l2;
	}
l2:	/* end popInteger */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (integerReceiver >= integerArgument) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveGreaterThan(void) {
    int integerArgument;
    int integerReceiver;
    int integerPointer;
    int integerPointer1;
    int top;
    int top1;
    int sp;
    int sp1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		integerArgument = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer1 = top1;
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		successFlag = 0;
		integerReceiver = 1;
		goto l2;
	}
l2:	/* end popInteger */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (integerReceiver > integerArgument) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}


/*	When called with a single string argument, record the string as the current image file name. When called with zero arguments, return a string containing the current image file name. */

int primitiveImageName(void) {
    int okToRename;
    int s;
    int sCRIfn;
    int sz;
    int sp;
    int cl;
    int ccIndex;
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int sp1;
    int sz1;
    int classFormat;
    int class;
    int ccIndex1;

	if (argumentCount == 1) {
		sCRIfn = ioLoadFunctionFrom("secCanRenameImage", "SecurityPlugin");
		if (sCRIfn != 0) {
			okToRename =  ((int (*) (void)) sCRIfn)();
			if (!(okToRename)) {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
		}
		s = longAt(stackPointer);
		/* begin assertClassOf:is: */
		if ((s & 1)) {
			successFlag = 0;
			goto l1;
		}
		ccIndex = (((unsigned) (longAt(s))) >> 12) & 31;
		if (ccIndex == 0) {
			cl = (longAt(s - 4)) & 4294967292U;
		} else {
			cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		}
		/* begin success: */
		successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)))) && successFlag;
	l1:	/* end assertClassOf:is: */;
		if (successFlag) {
			/* begin stSizeOf: */
			hdr = longAt(s);
			fmt = (((unsigned) hdr) >> 8) & 15;
			/* begin lengthOf:baseHeader:format: */
			if ((hdr & 3) == 0) {
				sz1 = (longAt(s - 8)) & 4294967292U;
			} else {
				sz1 = hdr & 252;
			}
			if (fmt < 8) {
				totalLength = ((unsigned) (sz1 - 4)) >> 2;
				goto l4;
			} else {
				totalLength = (sz1 - 4) - (fmt & 3);
				goto l4;
			}
		l4:	/* end lengthOf:baseHeader:format: */;
			/* begin fixedFieldsOf:format:length: */
			if ((fmt > 4) || (fmt == 2)) {
				fixedFields = 0;
				goto l2;
			}
			if (fmt < 2) {
				fixedFields = totalLength;
				goto l2;
			}
			/* begin fetchClassOf: */
			if ((s & 1)) {
				class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
				goto l3;
			}
			ccIndex1 = (((unsigned) (longAt(s))) >> 12) & 31;
			if (ccIndex1 == 0) {
				class = (longAt(s - 4)) & 4294967292U;
				goto l3;
			} else {
				class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
				goto l3;
			}
		l3:	/* end fetchClassOf: */;
			classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
			fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
		l2:	/* end fixedFieldsOf:format:length: */;
			if ((fmt == 3) && (isContextHeader(hdr))) {
				/* begin fetchStackPointerOf: */
				sp1 = longAt(((((char *) s)) + 4) + (2 << 2));
				if (!((sp1 & 1))) {
					sz = 0;
					goto l5;
				}
				sz = (sp1 >> 1);
				goto l5;
			} else {
				sz = totalLength - fixedFields;
				goto l5;
			}
		l5:	/* end stSizeOf: */;
			imageNamePutLength(s + 4, sz);
			/* begin pop: */
			stackPointer -= 1 * 4;
		}
	} else {
		sz = imageNameSize();
		s = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), sz);
		imageNameGetLength(s + 4, sz);
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, s);
		stackPointer = sp;
	}
}


/*	Do a quick, incremental garbage collection and return the number of bytes immediately available. (Note: more space may be made available by doing a full garbage collection. */

int primitiveIncrementalGC(void) {
    int integerValue;
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	incrementalGC();
	/* begin pushInteger: */
	integerValue = ((longAt(freeBlock)) & 4294967292U) + (sqMemoryExtraBytesLeft(0));
	/* begin push: */
	longAtput(sp = stackPointer + 4, ((integerValue << 1) | 1));
	stackPointer = sp;
}


/*	Note: We now have 11 bits of primitive index, but they are in two places
	for temporary backward compatibility.  The time to unpack is negligible,
	since the reconstituted full index is stored in the method cache. */

int primitiveIndexOf(int methodPointer) {
    int primBits;

	primBits = (((unsigned) (longAt(((((char *) methodPointer)) + 4) + (0 << 2)))) >> 1) & 805306879;
	if (primBits > 511) {
		return (primBits & 511) + (((unsigned) primBits) >> 19);
	} else {
		return primBits;
	}
}


/*	Register the input semaphore. If the argument is not a Semaphore, unregister the current input semaphore. */

int primitiveInputSemaphore(void) {
    int arg;
    int oop;
    int oop1;
    int valuePointer;
    int top;

	arg = longAt(stackPointer - (0 * 4));
	if ((arg & 1)) {
		ioSetInputSemaphore((arg >> 1));
		if (successFlag) {
			/* begin pop: */
			stackPointer -= 1 * 4;
		}
		return null;
	}
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	arg = top;
	if ((fetchClassOf(arg)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
		/* begin storePointer:ofObject:withValue: */
		oop = specialObjectsOop;
		if (oop < youngStart) {
			possibleRootStoreIntovalue(oop, arg);
		}
		longAtput(((((char *) oop)) + 4) + (22 << 2), arg);
	} else {
		/* begin storePointer:ofObject:withValue: */
		oop1 = specialObjectsOop;
		valuePointer = nilObj;
		if (oop1 < youngStart) {
			possibleRootStoreIntovalue(oop1, valuePointer);
		}
		longAtput(((((char *) oop1)) + 4) + (22 << 2), valuePointer);
	}
}


/*	Return an integer indicating the reason for the most recent input interrupt. */

int primitiveInputWord(void) {
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, ((0 << 1) | 1));
	stackPointer = sp;
}

int primitiveInstVarAt(void) {
    int hdr;
    int totalLength;
    int fixedFields;
    int value;
    int fmt;
    int rcvr;
    int index;
    int sp;
    int integerPointer;
    int top;
    int top1;
    int sz;
    int classFormat;
    int class;
    int ccIndex;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l2;
	} else {
		successFlag = 0;
		index = 1;
		goto l2;
	}
l2:	/* end popInteger */;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	rcvr = top1;
	if (successFlag) {
		hdr = longAt(rcvr);
		fmt = (((unsigned) hdr) >> 8) & 15;
		/* begin lengthOf:baseHeader:format: */
		if ((hdr & 3) == 0) {
			sz = (longAt(rcvr - 8)) & 4294967292U;
		} else {
			sz = hdr & 252;
		}
		if (fmt < 8) {
			totalLength = ((unsigned) (sz - 4)) >> 2;
			goto l3;
		} else {
			totalLength = (sz - 4) - (fmt & 3);
			goto l3;
		}
	l3:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l4;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l4;
		}
		/* begin fetchClassOf: */
		if ((rcvr & 1)) {
			class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l5;
		}
		ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
		if (ccIndex == 0) {
			class = (longAt(rcvr - 4)) & 4294967292U;
			goto l5;
		} else {
			class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
			goto l5;
		}
	l5:	/* end fetchClassOf: */;
		classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
		fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
	l4:	/* end fixedFieldsOf:format:length: */;
		if (!((index >= 1) && (index <= fixedFields))) {
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin subscript:with:format: */
		if (fmt <= 4) {
			value = longAt(((((char *) rcvr)) + 4) + ((index - 1) << 2));
			goto l1;
		}
		if (fmt < 8) {
			value = positive32BitIntegerFor(longAt(((((char *) rcvr)) + 4) + ((index - 1) << 2)));
			goto l1;
		} else {
			value = (((byteAt(((((char *) rcvr)) + 4) + (index - 1))) << 1) | 1);
			goto l1;
		}
	l1:	/* end subscript:with:format: */;
	}
	if (successFlag) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, value);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveInstVarAtPut(void) {
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int rcvr;
    int index;
    int newValue;
    int sp;
    int top;
    int integerPointer;
    int top1;
    int top2;
    int sz;
    int classFormat;
    int class;
    int valueToStore;
    int ccIndex;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	newValue = top;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top1;
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		index = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popStack */
	top2 = longAt(stackPointer);
	stackPointer -= 4;
	rcvr = top2;
	if (successFlag) {
		hdr = longAt(rcvr);
		fmt = (((unsigned) hdr) >> 8) & 15;
		/* begin lengthOf:baseHeader:format: */
		if ((hdr & 3) == 0) {
			sz = (longAt(rcvr - 8)) & 4294967292U;
		} else {
			sz = hdr & 252;
		}
		if (fmt < 8) {
			totalLength = ((unsigned) (sz - 4)) >> 2;
			goto l2;
		} else {
			totalLength = (sz - 4) - (fmt & 3);
			goto l2;
		}
	l2:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l3;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l3;
		}
		/* begin fetchClassOf: */
		if ((rcvr & 1)) {
			class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l4;
		}
		ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
		if (ccIndex == 0) {
			class = (longAt(rcvr - 4)) & 4294967292U;
			goto l4;
		} else {
			class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
			goto l4;
		}
	l4:	/* end fetchClassOf: */;
		classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
		fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
	l3:	/* end fixedFieldsOf:format:length: */;
		if (!((index >= 1) && (index <= fixedFields))) {
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin subscript:with:storing:format: */
		if (fmt <= 4) {
			/* begin storePointer:ofObject:withValue: */
			if (rcvr < youngStart) {
				possibleRootStoreIntovalue(rcvr, newValue);
			}
			longAtput(((((char *) rcvr)) + 4) + ((index - 1) << 2), newValue);
		} else {
			if (fmt < 8) {
				valueToStore = positive32BitValueOf(newValue);
				if (successFlag) {
					longAtput(((((char *) rcvr)) + 4) + ((index - 1) << 2), valueToStore);
				}
			} else {
				if (!((newValue & 1))) {
					successFlag = 0;
				}
				valueToStore = (newValue >> 1);
				if (!((valueToStore >= 0) && (valueToStore <= 255))) {
					successFlag = 0;
				}
				if (successFlag) {
					byteAtput(((((char *) rcvr)) + 4) + (index - 1), valueToStore);
				}
			}
		}
	}
	if (successFlag) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, newValue);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 3 * 4;
	}
}


/*	Note:  this primitive has been decommissioned.  It is only here for short-term compatibility with an internal 2.3beta-d image that used this.  It did not save much time and it complicated several things.  Plus Jitter will do it right anyway. */

int primitiveInstVarsPutFromStack(void) {
    int i;
    int offsetBits;
    int rcvr;


	/* Mark dirty so stores below can be unchecked */

	rcvr = longAt(stackPointer - (argumentCount * 4));
	if (rcvr < youngStart) {
		beRootIfOld(rcvr);
	}
	for (i = 0; i <= (argumentCount - 1); i += 1) {
		if ((i & 3) == 0) {
			offsetBits = positive32BitValueOf(longAt(((((char *) newMethod)) + 4) + (((((int) i >> 2)) + 1) << 2)));
		}
		longAtput(((((char *) rcvr)) + 4) + ((offsetBits & 255) << 2), longAt(stackPointer - (i * 4)));
		offsetBits = ((unsigned) offsetBits) >> 8;
	}
	/* begin pop: */
	stackPointer -= argumentCount * 4;
}


/*	Return the 32bit signed integer contents of a words receiver */

int primitiveIntegerAt(void) {
    int value;
    int rcvr;
    int sz;
    int index;
    int addr;
    int sp;
    int object;
    int sp1;
    int integerPointer;
    int successValue;
    int header;
    int sz1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	rcvr = longAt(stackPointer - (1 * 4));
	if ((rcvr & 1)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if (!(((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	/* begin lengthOf: */
	header = longAt(rcvr);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz1 = (longAt(rcvr - 8)) & 4294967292U;
	} else {
		sz1 = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		sz = ((unsigned) (sz1 - 4)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	/* begin success: */
	successValue = (index >= 1) && (index <= sz);
	successFlag = successValue && successFlag;
	if (successFlag) {

		/* for zero indexing */

		addr = ((rcvr + 4) - 4) + (index * 4);
		value = *((int *) addr);
		/* begin pop: */
		stackPointer -= 2 * 4;
		if ((value ^ (value << 1)) >= 0) {
			/* begin pushInteger: */
			/* begin push: */
			longAtput(sp = stackPointer + 4, ((value << 1) | 1));
			stackPointer = sp;
		} else {
			/* begin push: */
			object = signed32BitIntegerFor(value);
			longAtput(sp1 = stackPointer + 4, object);
			stackPointer = sp1;
		}
	}
}


/*	Return the 32bit signed integer contents of a words receiver */

int primitiveIntegerAtPut(void) {
    int value;
    int rcvr;
    int sz;
    int index;
    int addr;
    int valueOop;
    int sp;
    int integerPointer;
    int header;
    int sz1;

	valueOop = longAt(stackPointer - (0 * 4));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	rcvr = longAt(stackPointer - (2 * 4));
	if ((rcvr & 1)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if (!(((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	/* begin lengthOf: */
	header = longAt(rcvr);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz1 = (longAt(rcvr - 8)) & 4294967292U;
	} else {
		sz1 = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		sz = ((unsigned) (sz1 - 4)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	if (!((index >= 1) && (index <= sz))) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if ((valueOop & 1)) {
		value = (valueOop >> 1);
	} else {
		value = signed32BitValueOf(valueOop);
	}
	if (successFlag) {

		/* for zero indexing */

		addr = ((rcvr + 4) - 4) + (index * 4);
		value = *((int *) addr) = value;
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((3 - 1) * 4), valueOop);
		stackPointer = sp;
	}
}


/*	Register the user interrupt semaphore. If the argument is not a Semaphore, unregister the current interrupt semaphore. */

int primitiveInterruptSemaphore(void) {
    int arg;
    int oop;
    int oop1;
    int valuePointer;
    int top;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	arg = top;
	if ((fetchClassOf(arg)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
		/* begin storePointer:ofObject:withValue: */
		oop = specialObjectsOop;
		if (oop < youngStart) {
			possibleRootStoreIntovalue(oop, arg);
		}
		longAtput(((((char *) oop)) + 4) + (30 << 2), arg);
	} else {
		/* begin storePointer:ofObject:withValue: */
		oop1 = specialObjectsOop;
		valuePointer = nilObj;
		if (oop1 < youngStart) {
			possibleRootStoreIntovalue(oop1, valuePointer);
		}
		longAtput(((((char *) oop1)) + 4) + (30 << 2), valuePointer);
	}
}


/*	Return the next keycode and remove it from the input buffer. The low byte is the 8-bit ISO character. The next four bits are the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

int primitiveKbdNext(void) {
    int keystrokeWord;
    int sp;
    int sp1;

	/* begin pop: */
	stackPointer -= 1 * 4;
	keystrokeWord = ioGetKeystroke();
	if (keystrokeWord >= 0) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((keystrokeWord << 1) | 1));
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, nilObj);
		stackPointer = sp1;
	}
}


/*	Return the next keycode and without removing it from the input buffer. The low byte is the 8-bit ISO character. The next four bits are the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

int primitiveKbdPeek(void) {
    int keystrokeWord;
    int sp;
    int sp1;

	/* begin pop: */
	stackPointer -= 1 * 4;
	keystrokeWord = ioPeekKeystroke();
	if (keystrokeWord >= 0) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((keystrokeWord << 1) | 1));
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, nilObj);
		stackPointer = sp1;
	}
}

int primitiveLessOrEqual(void) {
    int integerArgument;
    int integerReceiver;
    int integerPointer;
    int integerPointer1;
    int top;
    int top1;
    int sp;
    int sp1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		integerArgument = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer1 = top1;
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		successFlag = 0;
		integerReceiver = 1;
		goto l2;
	}
l2:	/* end popInteger */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (integerReceiver <= integerArgument) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveLessThan(void) {
    int integerArgument;
    int integerReceiver;
    int integerPointer;
    int integerPointer1;
    int top;
    int top1;
    int sp;
    int sp1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		integerArgument = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer1 = top1;
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		successFlag = 0;
		integerReceiver = 1;
		goto l2;
	}
l2:	/* end popInteger */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (integerReceiver < integerArgument) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}


/*	Primitive. Return the n-th builtin module name. */

int primitiveListBuiltinModule(void) {
    int length;
    int i;
    char * moduleName;
    int nameOop;
    int index;
    int sp;
    int integerPointer;
    int sp1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (index <= 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	moduleName = ioListBuiltinModule(index);
	if (moduleName == null) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, nilObj);
		stackPointer = sp;
		return null;
	}
	length = strlen(moduleName);
	nameOop = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), length);
	for (i = 0; i <= (length - 1); i += 1) {
		byteAtput(((((char *) nameOop)) + 4) + i, moduleName[i]);
	}
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin push: */
	longAtput(sp1 = stackPointer + 4, nameOop);
	stackPointer = sp1;
}


/*	Primitive. Return the n-th loaded external module name. */

int primitiveListExternalModule(void) {
    int length;
    int i;
    char * moduleName;
    int nameOop;
    int index;
    int sp;
    int integerPointer;
    int sp1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (index <= 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	moduleName = ioListLoadedModule(index);
	if (moduleName == null) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, nilObj);
		stackPointer = sp;
		return null;
	}
	length = strlen(moduleName);
	nameOop = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), length);
	for (i = 0; i <= (length - 1); i += 1) {
		byteAtput(((((char *) nameOop)) + 4) + i, moduleName[i]);
	}
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin push: */
	longAtput(sp1 = stackPointer + 4, nameOop);
	stackPointer = sp1;
}


/*	This primitive is called from Squeak as...
		<imageSegment> loadSegmentFrom: aWordArray outPointers: anArray. */
/*	This primitive will load a binary image segment created by primitiveStoreImageSegment.  It expects the outPointer array to be of the proper size, and the wordArray to be well formed.  It will return as its value the original array of roots, and the erstwhile segmentWordArray will have been truncated to a size of zero.  If this primitive should fail, the segmentWordArray will, sadly, have been reduced to an unrecognizable and unusable jumble.  But what more could you have done with it anyway? */

int primitiveLoadImageSegment(void) {
    int header;
    int outPointerArray;
    int fieldPtr;
    int mapOop;
    int fieldOop;
    int segOop;
    int lastOut;
    int endSeg;
    int doingClass;
    int data;
    int hdrTypeBits;
    int outPtr;
    int lastPtr;
    int extraSize;
    int segmentWordArray;
    int addr;
    int addr1;
    int extra;
    int extra1;
    int type;
    int extra2;
    int extra11;
    int type1;
    int extra3;
    int extra12;
    int type2;
    int extra4;
    int type3;
    int oop;
    int sp;
    int sz;
    int extra5;
    int header1;
    int extra13;
    int type4;
    int sz1;
    int extra6;
    int header2;
    int extra14;
    int type5;
    int extra7;
    int extra15;
    int type6;

	;
	outPointerArray = longAt(stackPointer - (0 * 4));
	lastOut = outPointerArray + (lastPointerOf(outPointerArray));
	segmentWordArray = longAt(stackPointer - (1 * 4));

	/* Essential type checks */

	endSeg = (segmentWordArray + (sizeBitsOf(segmentWordArray))) - 4;
	if (!((((((unsigned) (longAt(outPointerArray))) >> 8) & 15) == 2) && (((((unsigned) (longAt(segmentWordArray))) >> 8) & 15) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	data = longAt(segmentWordArray + 4);
	if (!((data & 65535) == 6502)) {
		/* begin reverseBytesFrom:to: */
		addr1 = segmentWordArray + 4;
		while (addr1 < (endSeg + 4)) {
			longAtput(addr1, ((((((unsigned) (longAt(addr1)) >> 24)) & 255) + ((((unsigned) (longAt(addr1)) >> 8)) & 65280)) + ((((unsigned) (longAt(addr1)) << 8)) & 16711680)) + ((((unsigned) (longAt(addr1)) << 24)) & 4278190080U));
			addr1 += 4;
		}
		data = longAt(segmentWordArray + 4);
		if (!((data & 65535) == 6502)) {
			/* begin reverseBytesFrom:to: */
			addr = segmentWordArray + 4;
			while (addr < (endSeg + 4)) {
				longAtput(addr, ((((((unsigned) (longAt(addr)) >> 24)) & 255) + ((((unsigned) (longAt(addr)) >> 8)) & 65280)) + ((((unsigned) (longAt(addr)) << 8)) & 16711680)) + ((((unsigned) (longAt(addr)) << 24)) & 4278190080U));
				addr += 4;
			}
			;
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	if (!(data == (imageSegmentVersion()))) {
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type = (longAt((segmentWordArray + 4) + 4)) & 3;
		if (type > 1) {
			extra1 = 0;
		} else {
			if (type == 1) {
				extra1 = 4;
			} else {
				extra1 = 8;
			}
		}
		extra = extra1;
		segOop = ((segmentWordArray + 4) + 4) + extra;
		byteSwapByteObjectsFromto(segOop, endSeg + 4);
	}
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type1 = (longAt((segmentWordArray + 4) + 4)) & 3;
	if (type1 > 1) {
		extra11 = 0;
	} else {
		if (type1 == 1) {
			extra11 = 4;
		} else {
			extra11 = 8;
		}
	}
	extra2 = extra11;
	segOop = ((segmentWordArray + 4) + 4) + extra2;
	while (segOop <= endSeg) {
		if (((longAt(segOop)) & 3) <= 1) {
			fieldPtr = segOop - 4;
			doingClass = 1;
		} else {
			fieldPtr = segOop + 4;
			doingClass = 0;
		}

		/* last field */

		lastPtr = segOop + (lastPointerOf(segOop));
		if (lastPtr > endSeg) {
			;
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		while (!(fieldPtr > lastPtr)) {
			fieldOop = longAt(fieldPtr);
			if (doingClass) {
				hdrTypeBits = (longAt(fieldPtr)) & 3;
				fieldOop -= hdrTypeBits;
			}
			if ((fieldOop & 1)) {
				fieldPtr += 4;
			} else {
				if (!((fieldOop & 3) == 0)) {
					/* begin primitiveFail */
					successFlag = 0;
					return null;
				}
				if ((fieldOop & 2147483648U) == 0) {
					mapOop = fieldOop + segmentWordArray;
				} else {
					outPtr = outPointerArray + (fieldOop & 2147483647U);
					if (outPtr > lastOut) {
						/* begin primitiveFail */
						successFlag = 0;
						return null;
					}
					mapOop = longAt(outPtr);
				}
				if (doingClass) {
					longAtput(fieldPtr, mapOop + hdrTypeBits);
					fieldPtr += 8;
					doingClass = 0;
				} else {
					longAtput(fieldPtr, mapOop);
					fieldPtr += 4;
				}
				if (segOop < youngStart) {
					possibleRootStoreIntovalue(segOop, mapOop);
				}
			}
		}
		/* begin objectAfter: */
		;
		if (((longAt(segOop)) & 3) == 2) {
			sz = (longAt(segOop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(segOop);
			if ((header1 & 3) == 0) {
				sz = (longAt(segOop - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header1 & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type4 = (longAt(segOop + sz)) & 3;
		if (type4 > 1) {
			extra13 = 0;
		} else {
			if (type4 == 1) {
				extra13 = 4;
			} else {
				extra13 = 8;
			}
		}
		extra5 = extra13;
		segOop = (segOop + sz) + extra5;
	}
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type2 = (longAt((segmentWordArray + 4) + 4)) & 3;
	if (type2 > 1) {
		extra12 = 0;
	} else {
		if (type2 == 1) {
			extra12 = 4;
		} else {
			extra12 = 8;
		}
	}
	extra3 = extra12;
	segOop = ((segmentWordArray + 4) + 4) + extra3;
	while (segOop <= endSeg) {
		if (!(oopHasOKclass(segOop))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}

		/* first field */

		fieldPtr = segOop + 4;

		/* last field */
		/* Go through all oops, remapping them... */

		lastPtr = segOop + (lastPointerOf(segOop));
		while (!(fieldPtr > lastPtr)) {
			fieldOop = longAt(fieldPtr);
			if (!(oopHasOKclass(fieldOop))) {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
			fieldPtr += 4;
		}
		/* begin objectAfter: */
		;
		if (((longAt(segOop)) & 3) == 2) {
			sz1 = (longAt(segOop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header2 = longAt(segOop);
			if ((header2 & 3) == 0) {
				sz1 = (longAt(segOop - 8)) & 4294967292U;
				goto l2;
			} else {
				sz1 = header2 & 252;
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type5 = (longAt(segOop + sz1)) & 3;
		if (type5 > 1) {
			extra14 = 0;
		} else {
			if (type5 == 1) {
				extra14 = 4;
			} else {
				extra14 = 8;
			}
		}
		extra6 = extra14;
		segOop = (segOop + sz1) + extra6;
	}
	/* begin extraHeaderBytes: */
	type3 = (longAt(segmentWordArray)) & 3;
	if (type3 > 1) {
		extra4 = 0;
	} else {
		if (type3 == 1) {
			extra4 = 4;
		} else {
			extra4 = 8;
		}
	}
	extraSize = extra4;
	hdrTypeBits = (longAt(segmentWordArray)) & 3;
	if (extraSize == 8) {
		longAtput(segmentWordArray - extraSize, (4 + 4) + hdrTypeBits);
	} else {
		header = longAt(segmentWordArray);
		longAtput(segmentWordArray, ((header - (header & 252)) + 4) + 4);
	}
	;
	/* begin pop:thenPush: */
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type6 = (longAt((segmentWordArray + 4) + 4)) & 3;
	if (type6 > 1) {
		extra15 = 0;
	} else {
		if (type6 == 1) {
			extra15 = 4;
		} else {
			extra15 = 8;
		}
	}
	extra7 = extra15;
	oop = ((segmentWordArray + 4) + 4) + extra7;
	longAtput(sp = stackPointer - ((3 - 1) * 4), oop);
	stackPointer = sp;
}

int primitiveLoadInstVar(void) {
    int thisReceiver;
    int top;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	thisReceiver = top;
	/* begin push: */
	longAtput(sp = stackPointer + 4, longAt(((((char *) thisReceiver)) + 4) + ((primitiveIndex - 264) << 2)));
	stackPointer = sp;
}


/*	Natural log. */

int primitiveLogN(void) {
    double rcvr;

	rcvr = popFloat();
	if (successFlag) {
		pushFloat(log(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	Register the low-space semaphore. If the argument is not a Semaphore, unregister the current low-space Semaphore. */

int primitiveLowSpaceSemaphore(void) {
    int arg;
    int oop;
    int oop1;
    int valuePointer;
    int top;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	arg = top;
	if ((fetchClassOf(arg)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
		/* begin storePointer:ofObject:withValue: */
		oop = specialObjectsOop;
		if (oop < youngStart) {
			possibleRootStoreIntovalue(oop, arg);
		}
		longAtput(((((char *) oop)) + 4) + (17 << 2), arg);
	} else {
		/* begin storePointer:ofObject:withValue: */
		oop1 = specialObjectsOop;
		valuePointer = nilObj;
		if (oop1 < youngStart) {
			possibleRootStoreIntovalue(oop1, valuePointer);
		}
		longAtput(((((char *) oop1)) + 4) + (17 << 2), valuePointer);
	}
}

int primitiveMakePoint(void) {
    int pt;
    int argument;
    int rcvr;
    int valuePointer;
    int valuePointer1;
    int valuePointer2;
    int sp;
    int pointResult;
    int pointResult1;
    int pointResult2;

	argument = longAt(stackPointer - (0 * 4));
	rcvr = longAt(stackPointer - (1 * 4));
	if ((rcvr & 1)) {
		if ((argument & 1)) {
			/* begin makePointwithxValue:yValue: */
			pointResult = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
			/* begin storePointer:ofObject:withValue: */
			if (pointResult < youngStart) {
				possibleRootStoreIntovalue(pointResult, ((((rcvr >> 1)) << 1) | 1));
			}
			longAtput(((((char *) pointResult)) + 4) + (0 << 2), ((((rcvr >> 1)) << 1) | 1));
			/* begin storePointer:ofObject:withValue: */
			if (pointResult < youngStart) {
				possibleRootStoreIntovalue(pointResult, ((((argument >> 1)) << 1) | 1));
			}
			longAtput(((((char *) pointResult)) + 4) + (1 << 2), ((((argument >> 1)) << 1) | 1));
			pt = pointResult;
		} else {
			/* begin makePointwithxValue:yValue: */
			pointResult1 = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
			/* begin storePointer:ofObject:withValue: */
			if (pointResult1 < youngStart) {
				possibleRootStoreIntovalue(pointResult1, ((((rcvr >> 1)) << 1) | 1));
			}
			longAtput(((((char *) pointResult1)) + 4) + (0 << 2), ((((rcvr >> 1)) << 1) | 1));
			/* begin storePointer:ofObject:withValue: */
			if (pointResult1 < youngStart) {
				possibleRootStoreIntovalue(pointResult1, ((0 << 1) | 1));
			}
			longAtput(((((char *) pointResult1)) + 4) + (1 << 2), ((0 << 1) | 1));
			pt = pointResult1;
			/* begin storePointer:ofObject:withValue: */
			valuePointer = longAt(stackPointer - (0 * 4));
			if (pt < youngStart) {
				possibleRootStoreIntovalue(pt, valuePointer);
			}
			longAtput(((((char *) pt)) + 4) + (1 << 2), valuePointer);
		}
	} else {
		if (!((fetchClassOf(rcvr)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2))))) {
			/* begin success: */
			successFlag = 0 && successFlag;
			return null;
		}
		/* begin makePointwithxValue:yValue: */
		pointResult2 = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
		/* begin storePointer:ofObject:withValue: */
		if (pointResult2 < youngStart) {
			possibleRootStoreIntovalue(pointResult2, ((0 << 1) | 1));
		}
		longAtput(((((char *) pointResult2)) + 4) + (0 << 2), ((0 << 1) | 1));
		/* begin storePointer:ofObject:withValue: */
		if (pointResult2 < youngStart) {
			possibleRootStoreIntovalue(pointResult2, ((0 << 1) | 1));
		}
		longAtput(((((char *) pointResult2)) + 4) + (1 << 2), ((0 << 1) | 1));
		pt = pointResult2;
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = longAt(stackPointer - (1 * 4));
		if (pt < youngStart) {
			possibleRootStoreIntovalue(pt, valuePointer1);
		}
		longAtput(((((char *) pt)) + 4) + (0 << 2), valuePointer1);
		/* begin storePointer:ofObject:withValue: */
		valuePointer2 = longAt(stackPointer - (0 * 4));
		if (pt < youngStart) {
			possibleRootStoreIntovalue(pt, valuePointer2);
		}
		longAtput(((((char *) pt)) + 4) + (1 << 2), valuePointer2);
	}
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, pt);
	stackPointer = sp;
}


/*	Return the method an external primitive was defined in */

int primitiveMethod(void) {
	return newMethod;
}


/*	Return the value of the millisecond clock as an integer. Note that the millisecond clock wraps around periodically. On some platforms it can wrap daily. The range is limited to SmallInteger maxVal / 2 to allow delays of up to that length without overflowing a SmallInteger. */

int primitiveMillisecondClock(void) {
    int object;
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin push: */
	object = ((((ioMSecs()) & 536870911) << 1) | 1);
	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
}

int primitiveMod(void) {
    int mod;
    int sp;

	mod = doPrimitiveModby(longAt(stackPointer - (1 * 4)), longAt(stackPointer - (0 * 4)));
	/* begin pop2AndPushIntegerIfOK: */
	if (successFlag) {
		if ((mod ^ (mod << 1)) >= 0) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * 4), ((mod << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}


/*	Return the mouse button state. The low three bits encode the state of the <red><yellow><blue> mouse buttons. The next four bits encode the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

int primitiveMouseButtons(void) {
    int buttonWord;
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	buttonWord = ioGetButtonState();
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, ((buttonWord << 1) | 1));
	stackPointer = sp;
}


/*	Return a Point indicating current position of the mouse. Note that mouse coordinates may be negative if the mouse moves above or to the left of the top-left corner of the Smalltalk window. */

int primitiveMousePoint(void) {
    int x;
    int y;
    int pointWord;
    int object;
    int sp;
    int pointResult;

	/* begin pop: */
	stackPointer -= 1 * 4;
	pointWord = ioMousePoint();
	/* begin signExtend16: */
	if ((((((unsigned) pointWord) >> 16) & 65535) & 32768) == 0) {
		x = (((unsigned) pointWord) >> 16) & 65535;
		goto l1;
	} else {
		x = ((((unsigned) pointWord) >> 16) & 65535) - 65536;
		goto l1;
	}
l1:	/* end signExtend16: */;
	/* begin signExtend16: */
	if (((pointWord & 65535) & 32768) == 0) {
		y = pointWord & 65535;
		goto l2;
	} else {
		y = (pointWord & 65535) - 65536;
		goto l2;
	}
l2:	/* end signExtend16: */;
	/* begin push: */
	/* begin makePointwithxValue:yValue: */
	pointResult = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
	/* begin storePointer:ofObject:withValue: */
	if (pointResult < youngStart) {
		possibleRootStoreIntovalue(pointResult, ((x << 1) | 1));
	}
	longAtput(((((char *) pointResult)) + 4) + (0 << 2), ((x << 1) | 1));
	/* begin storePointer:ofObject:withValue: */
	if (pointResult < youngStart) {
		possibleRootStoreIntovalue(pointResult, ((y << 1) | 1));
	}
	longAtput(((((char *) pointResult)) + 4) + (1 << 2), ((y << 1) | 1));
	object = pointResult;
	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
}

int primitiveMultiply(void) {
    int integerResult;
    int integerArg;
    int integerRcvr;
    int integerPointer;
    int integerPointer1;
    int sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		integerRcvr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerRcvr = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (0 * 4));
	if ((integerPointer1 & 1)) {
		integerArg = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArg = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	if (successFlag) {

		/* check for C overflow by seeing if computation is reversible */

		integerResult = integerRcvr * integerArg;
		if ((integerArg == 0) || ((integerResult / integerArg) == integerRcvr)) {
			/* begin pop2AndPushIntegerIfOK: */
			if (successFlag) {
				if ((integerResult ^ (integerResult << 1)) >= 0) {
					/* begin pop:thenPush: */
					longAtput(sp = stackPointer - ((2 - 1) * 4), ((integerResult << 1) | 1));
					stackPointer = sp;
				} else {
					successFlag = 0;
				}
			}
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
	}
}


/*	Allocate a new fixed-size instance. Fail if the allocation would leave less than lowSpaceThreshold bytes free. */

int primitiveNew(void) {
    int spaceOkay;
    int class;
    int object;
    int sp;
    int format;
    int okay;
    int minFree;
    int minFree1;


	/* The following may cause GC! */

	class = longAt(stackPointer - (0 * 4));
	/* begin sufficientSpaceToInstantiate:indexableSize: */
	format = (((unsigned) ((longAt(((((char *) class)) + 4) + (2 << 2))) - 1)) >> 8) & 15;
	if (((((unsigned ) 0)) > 0) && (format < 2)) {
		spaceOkay = 0;
		goto l3;
	}
	if (format < 8) {
		/* begin sufficientSpaceToAllocate: */
		minFree = (lowSpaceThreshold + (2500 + (0 * 4))) + 4;
		if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
			okay = 1;
			goto l1;
		} else {
			okay = sufficientSpaceAfterGC(minFree);
			goto l1;
		}
	l1:	/* end sufficientSpaceToAllocate: */;
	} else {
		/* begin sufficientSpaceToAllocate: */
		minFree1 = (lowSpaceThreshold + (2500 + 0)) + 4;
		if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree1))) {
			okay = 1;
			goto l2;
		} else {
			okay = sufficientSpaceAfterGC(minFree1);
			goto l2;
		}
	l2:	/* end sufficientSpaceToAllocate: */;
	}
	spaceOkay = okay;
l3:	/* end sufficientSpaceToInstantiate:indexableSize: */;
	/* begin success: */
	successFlag = spaceOkay && successFlag;
	if (successFlag) {
		/* begin push: */
		object = instantiateClassindexableSize(popStack(), 0);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	}
}

int primitiveNewMethod(void) {
    int header;
    int literalCount;
    int i;
    int theMethod;
    int class;
    int bytecodeCount;
    int size;
    int valuePointer;
    int top;
    int integerPointer;
    int top1;
    int top2;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	header = top;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top1;
	if ((integerPointer & 1)) {
		bytecodeCount = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		bytecodeCount = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin success: */
	successFlag = ((header & 1)) && successFlag;
	if (!(successFlag)) {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
	/* begin popStack */
	top2 = longAt(stackPointer);
	stackPointer -= 4;
	class = top2;
	size = ((((((unsigned) header) >> 10) & 255) + 1) * 4) + bytecodeCount;
	theMethod = instantiateClassindexableSize(class, size);
	/* begin storePointer:ofObject:withValue: */
	if (theMethod < youngStart) {
		possibleRootStoreIntovalue(theMethod, header);
	}
	longAtput(((((char *) theMethod)) + 4) + (0 << 2), header);
	literalCount = (((unsigned) header) >> 10) & 255;
	for (i = 1; i <= literalCount; i += 1) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = nilObj;
		if (theMethod < youngStart) {
			possibleRootStoreIntovalue(theMethod, valuePointer);
		}
		longAtput(((((char *) theMethod)) + 4) + (i << 2), valuePointer);
	}
	/* begin push: */
	longAtput(sp = stackPointer + 4, theMethod);
	stackPointer = sp;
}


/*	Allocate a new indexable instance. Fail if the allocation would leave less than lowSpaceThreshold bytes free. */

int primitiveNewWithArg(void) {
    int spaceOkay;
    int class;
    int size;
    int oop;
    int sp;
    int format;
    int okay;
    int minFree;
    int minFree1;

	size = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	class = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successFlag = (size >= 0) && successFlag;
	if (successFlag) {
		/* begin sufficientSpaceToInstantiate:indexableSize: */
		format = (((unsigned) ((longAt(((((char *) class)) + 4) + (2 << 2))) - 1)) >> 8) & 15;
		if (((((unsigned ) size)) > 0) && (format < 2)) {
			spaceOkay = 0;
			goto l3;
		}
		if (format < 8) {
			/* begin sufficientSpaceToAllocate: */
			minFree = (lowSpaceThreshold + (2500 + (size * 4))) + 4;
			if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
				okay = 1;
				goto l1;
			} else {
				okay = sufficientSpaceAfterGC(minFree);
				goto l1;
			}
		l1:	/* end sufficientSpaceToAllocate: */;
		} else {
			/* begin sufficientSpaceToAllocate: */
			minFree1 = (lowSpaceThreshold + (2500 + size)) + 4;
			if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree1))) {
				okay = 1;
				goto l2;
			} else {
				okay = sufficientSpaceAfterGC(minFree1);
				goto l2;
			}
		l2:	/* end sufficientSpaceToAllocate: */;
		}
		spaceOkay = okay;
	l3:	/* end sufficientSpaceToInstantiate:indexableSize: */;
		/* begin success: */
		successFlag = spaceOkay && successFlag;
		class = longAt(stackPointer - (1 * 4));
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = instantiateClassindexableSize(class, size);
		longAtput(sp = stackPointer - ((2 - 1) * 4), oop);
		stackPointer = sp;
	}
}


/*	PrimitiveNext will succeed only if the stream's array is in the atCache.
	Otherwise failure will lead to proper message lookup of at: and
	subsequent installation in the cache if appropriate. */

int primitiveNext(void) {
    int array;
    int limit;
    int result;
    int atIx;
    int stream;
    int index;
    int sp;

	stream = longAt(stackPointer);
	if (!((((((unsigned) (longAt(stream))) >> 8) & 15) <= 4) && ((lengthOf(stream)) >= (2 + 1)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	array = longAt(((((char *) stream)) + 4) + (0 << 2));
	index = fetchIntegerofObject(1, stream);
	limit = fetchIntegerofObject(2, stream);
	atIx = array & 28;
	if (!((index < limit) && ((atCache[atIx + 1]) == array))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	index += 1;

	/* Above may cause GC, so can't use stream, array etc. below it */

	result = commonVariableatcacheIndex(array, index, atIx);
	if (successFlag) {
		stream = longAt(stackPointer);
		/* begin storeInteger:ofObject:withValue: */
		if ((index ^ (index << 1)) >= 0) {
			longAtput(((((char *) stream)) + 4) + (1 << 2), ((index << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((1 - 1) * 4), result);
		stackPointer = sp;
		return null;
	}
}

int primitiveNextInstance(void) {
    int instance;
    int object;
    int top;
    int thisClass;
    int classPointer;
    int thisObj;
    int sp;
    int ccIndex;
    int ccIndex1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	object = top;
	/* begin instanceAfter: */
	/* begin fetchClassOf: */
	if ((object & 1)) {
		classPointer = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex1 = (((unsigned) (longAt(object))) >> 12) & 31;
	if (ccIndex1 == 0) {
		classPointer = (longAt(object - 4)) & 4294967292U;
		goto l3;
	} else {
		classPointer = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	thisObj = accessibleObjectAfter(object);
	while (!(thisObj == null)) {
		/* begin fetchClassOf: */
		if ((thisObj & 1)) {
			thisClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l2;
		}
		ccIndex = (((unsigned) (longAt(thisObj))) >> 12) & 31;
		if (ccIndex == 0) {
			thisClass = (longAt(thisObj - 4)) & 4294967292U;
			goto l2;
		} else {
			thisClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
			goto l2;
		}
	l2:	/* end fetchClassOf: */;
		if (thisClass == classPointer) {
			instance = thisObj;
			goto l1;
		}
		thisObj = accessibleObjectAfter(thisObj);
	}
	instance = nilObj;
l1:	/* end instanceAfter: */;
	if (instance == nilObj) {
		/* begin unPop: */
		stackPointer += 1 * 4;
		/* begin primitiveFail */
		successFlag = 0;
	} else {
		/* begin push: */
		longAtput(sp = stackPointer + 4, instance);
		stackPointer = sp;
	}
}


/*	Return the object following the receiver in the heap. Return the SmallInteger zero when there are no more objects. */

int primitiveNextObject(void) {
    int instance;
    int object;
    int top;
    int sp;
    int sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	object = top;
	instance = accessibleObjectAfter(object);
	if (instance == null) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((0 << 1) | 1));
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, instance);
		stackPointer = sp1;
	}
}


/*	PrimitiveNextPut will succeed only if the stream's array is in the atPutCache.
	Otherwise failure will lead to proper message lookup of at:put: and
	subsequent installation in the cache if appropriate. */

int primitiveNextPut(void) {
    int array;
    int limit;
    int atIx;
    int value;
    int stream;
    int index;
    int sp;
    int fixedFields;
    int fmt;
    int valToPut;
    int stSize;

	value = longAt(stackPointer);
	stream = longAt(stackPointer - (1 * 4));
	if (!((((((unsigned) (longAt(stream))) >> 8) & 15) <= 4) && ((lengthOf(stream)) >= (2 + 1)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	array = longAt(((((char *) stream)) + 4) + (0 << 2));
	index = fetchIntegerofObject(1, stream);
	limit = fetchIntegerofObject(2, stream);
	atIx = (array & 28) + 32;
	if (!((index < limit) && ((atCache[atIx + 1]) == array))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	index += 1;
	/* begin commonVariable:at:put:cacheIndex: */
	stSize = atCache[atIx + 2];
	if (((((unsigned ) index)) >= 1) && ((((unsigned ) index)) <= (((unsigned ) stSize)))) {
		fmt = atCache[atIx + 3];
		if (fmt <= 4) {
			fixedFields = atCache[atIx + 4];
			/* begin storePointer:ofObject:withValue: */
			if (array < youngStart) {
				possibleRootStoreIntovalue(array, value);
			}
			longAtput(((((char *) array)) + 4) + (((index + fixedFields) - 1) << 2), value);
			goto l1;
		}
		if (fmt < 8) {
			valToPut = positive32BitValueOf(value);
			if (successFlag) {
				longAtput(((((char *) array)) + 4) + ((index - 1) << 2), valToPut);
			}
			goto l1;
		}
		if (fmt >= 16) {
			valToPut = asciiOfCharacter(value);
			if (!(successFlag)) {
				goto l1;
			}
		} else {
			valToPut = value;
		}
		if ((valToPut & 1)) {
			valToPut = (valToPut >> 1);
			if (!((valToPut >= 0) && (valToPut <= 255))) {
				/* begin primitiveFail */
				successFlag = 0;
				goto l1;
			}
			byteAtput(((((char *) array)) + 4) + (index - 1), valToPut);
			goto l1;
		}
	}
	/* begin primitiveFail */
	successFlag = 0;
l1:	/* end commonVariable:at:put:cacheIndex: */;
	if (successFlag) {
		/* begin storeInteger:ofObject:withValue: */
		if ((index ^ (index << 1)) >= 0) {
			longAtput(((((char *) stream)) + 4) + (1 << 2), ((index << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((2 - 1) * 4), value);
		stackPointer = sp;
		return null;
	}
}


/*	A placeholder for primitives that haven't been implemented or are being withdrawn gradually. Just absorbs any arguments and returns the receiver. */

int primitiveNoop(void) {
	/* begin pop: */
	stackPointer -= argumentCount * 4;
}

int primitiveNotEqual(void) {
    int result;
    int integerArgument;
    int integerReceiver;
    int top;
    int top1;
    int sp;
    int sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerArgument = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerReceiver = top1;
	result = !(compare31or32Bitsequal(integerReceiver, integerArgument));
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (result) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}


/*	Defined for CompiledMethods only */

int primitiveObjectAt(void) {
    int index;
    int thisReceiver;
    int sp;
    int integerPointer;
    int top;
    int top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		index = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	thisReceiver = top1;
	/* begin success: */
	successFlag = (index > 0) && successFlag;
	/* begin success: */
	successFlag = (index <= (((((unsigned) (longAt(((((char *) thisReceiver)) + 4) + (0 << 2)))) >> 10) & 255) + 1)) && successFlag;
	if (successFlag) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, longAt(((((char *) thisReceiver)) + 4) + ((index - 1) << 2)));
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}


/*	Defined for CompiledMethods only */

int primitiveObjectAtPut(void) {
    int index;
    int thisReceiver;
    int newValue;
    int sp;
    int top;
    int integerPointer;
    int top1;
    int top2;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	newValue = top;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top1;
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		index = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popStack */
	top2 = longAt(stackPointer);
	stackPointer -= 4;
	thisReceiver = top2;
	/* begin success: */
	successFlag = (index > 0) && successFlag;
	/* begin success: */
	successFlag = (index <= (((((unsigned) (longAt(((((char *) thisReceiver)) + 4) + (0 << 2)))) >> 10) & 255) + 1)) && successFlag;
	if (successFlag) {
		/* begin storePointer:ofObject:withValue: */
		if (thisReceiver < youngStart) {
			possibleRootStoreIntovalue(thisReceiver, newValue);
		}
		longAtput(((((char *) thisReceiver)) + 4) + ((index - 1) << 2), newValue);
		/* begin push: */
		longAtput(sp = stackPointer + 4, newValue);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 3 * 4;
	}
}

int primitiveObjectPointsTo(void) {
    int i;
    int lastField;
    int thang;
    int rcvr;
    int top;
    int top1;
    int sp;
    int sp1;
    int sp2;
    int sp3;
    int sp4;
    int sp5;
    int header;
    int fmt;
    int methodHeader;
    int sz;
    int header1;
    int type;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	thang = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	rcvr = top1;
	if ((rcvr & 1)) {
		/* begin pushBool: */
				/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
;
		return null;
	}
	/* begin lastPointerOf: */
	header = longAt(rcvr);
	fmt = (((unsigned) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && (isContextHeader(header))) {
			lastField = (6 + (fetchStackPointerOf(rcvr))) * 4;
			goto l1;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(rcvr);
		/* begin rightType: */
		if ((header1 & 252) == 0) {
			type = 0;
			goto l2;
		} else {
			if ((header1 & 126976) == 0) {
				type = 1;
				goto l2;
			} else {
				type = 3;
				goto l2;
			}
		}
	l2:	/* end rightType: */;
		if (type == 0) {
			sz = (longAt(rcvr - 8)) & 4294967292U;
			goto l3;
		} else {
			sz = header1 & 252;
			goto l3;
		}
	l3:	/* end sizeBitsOfSafe: */;
		lastField = sz - 4;
		goto l1;
	}
	if (fmt < 12) {
		lastField = 0;
		goto l1;
	}
	methodHeader = longAt(rcvr + 4);
	lastField = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
l1:	/* end lastPointerOf: */;
	for (i = 4; i <= lastField; i += 4) {
		if ((longAt(rcvr + i)) == thang) {
			/* begin pushBool: */
						/* begin push: */
			longAtput(sp2 = stackPointer + 4, trueObj);
			stackPointer = sp2;
;
			return null;
		}
	}
	/* begin pushBool: */
		/* begin push: */
	longAtput(sp5 = stackPointer + 4, falseObj);
	stackPointer = sp5;
;
}


/*	Primitive. Invoke an obsolete indexed primitive. */

int primitiveObsoleteIndexedPrimitive(void) {
    int functionAddress;
    char *functionName;
    char *pluginName;

	functionAddress = ((int) ((obsoleteIndexedPrimitiveTable[primitiveIndex])[2]));
	if (!(functionAddress == null)) {
		return ((int (*) (void))functionAddress)();
	}
	pluginName = (obsoleteIndexedPrimitiveTable[primitiveIndex])[0];
	functionName = (obsoleteIndexedPrimitiveTable[primitiveIndex])[1];
	if ((pluginName == null) && (functionName == null)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	functionAddress = ioLoadFunctionFrom(functionName, pluginName);
	if (!(functionAddress == 0)) {
		(obsoleteIndexedPrimitiveTable[primitiveIndex])[2] = (((char*) functionAddress));
		return ((int (*) (void))functionAddress)();
	}
	/* begin primitiveFail */
	successFlag = 0;
	return null;
}

int primitivePerform(void) {
    int performMethod;
    int selectorIndex;
    int lookupClass;
    int i;
    int performSelector;
    int newReceiver;
    int fieldIndex;
    int oop;
    int valuePointer;
    int oop1;
    int valuePointer1;
    int fromIndex;
    int toIndex;
    int lastFrom;
    int successValue;
    int ccIndex;
    int i1;
    int newContext;
    int methodHeader;
    int nilOop;
    int initialIP;
    int tempCount;
    int tmp;

	performSelector = messageSelector;
	performMethod = newMethod;
	messageSelector = longAt(stackPointer - ((argumentCount - 1) * 4));

	/* NOTE: the following lookup may fail and be converted to #doesNotUnderstand:,
		so we must adjust argumentCount and slide args now, so that would work. */
	/* Slide arguments down over selector */

	newReceiver = longAt(stackPointer - (argumentCount * 4));
	argumentCount -= 1;
	selectorIndex = (((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - argumentCount;
	/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
	fromIndex = activeContext + ((selectorIndex + 1) * 4);
	toIndex = activeContext + (selectorIndex * 4);
	lastFrom = fromIndex + (argumentCount * 4);
	while (fromIndex < lastFrom) {
		fromIndex += 4;
		toIndex += 4;
		longAtput(toIndex, longAt(fromIndex));
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin fetchClassOf: */
	if ((newReceiver & 1)) {
		lookupClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l2;
	}
	ccIndex = (((unsigned) (longAt(newReceiver))) >> 12) & 31;
	if (ccIndex == 0) {
		lookupClass = (longAt(newReceiver - 4)) & 4294967292U;
		goto l2;
	} else {
		lookupClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	findNewMethodInClass(lookupClass);
	/* begin success: */
	successValue = ((((unsigned) (longAt(((((char *) newMethod)) + 4) + (0 << 2)))) >> 25) & 15) == argumentCount;
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin executeNewMethod */
		if (primitiveIndex > 0) {
			primitiveResponse();
			if (successFlag) {
				goto l1;
			}
		}
		/* begin activateNewMethod */
		methodHeader = longAt(((((char *) newMethod)) + 4) + (0 << 2));
		newContext = allocateOrRecycleContext(methodHeader & 262144);
		initialIP = ((1 + ((((unsigned) methodHeader) >> 10) & 255)) * 4) + 1;
		tempCount = (((unsigned) methodHeader) >> 19) & 63;
		longAtput(((((char *) newContext)) + 4) + (0 << 2), activeContext);
		longAtput(((((char *) newContext)) + 4) + (1 << 2), ((initialIP << 1) | 1));
		longAtput(((((char *) newContext)) + 4) + (2 << 2), ((tempCount << 1) | 1));
		longAtput(((((char *) newContext)) + 4) + (3 << 2), newMethod);
		for (i1 = 0; i1 <= argumentCount; i1 += 1) {
			longAtput(((((char *) newContext)) + 4) + ((5 + i1) << 2), longAt(stackPointer - ((argumentCount - i1) * 4)));
		}
		nilOop = nilObj;
		for (i1 = (argumentCount + 1); i1 <= tempCount; i1 += 1) {
			longAtput(((((char *) newContext)) + 4) + ((5 + i1) << 2), nilOop);
		}
		/* begin pop: */
		stackPointer -= (argumentCount + 1) * 4;
		reclaimableContextCount += 1;
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
		longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
		if (newContext < youngStart) {
			beRootIfOld(newContext);
		}
		activeContext = newContext;
		/* begin fetchContextRegisters: */
		tmp = longAt(((((char *) newContext)) + 4) + (3 << 2));
		if ((tmp & 1)) {
			tmp = longAt(((((char *) newContext)) + 4) + (5 << 2));
			if (tmp < youngStart) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = newContext;
		}
		theHomeContext = tmp;
		receiver = longAt(((((char *) tmp)) + 4) + (5 << 2));
		method = longAt(((((char *) tmp)) + 4) + (3 << 2));
		tmp = ((longAt(((((char *) newContext)) + 4) + (1 << 2))) >> 1);
		instructionPointer = ((method + tmp) + 4) - 2;
		tmp = ((longAt(((((char *) newContext)) + 4) + (2 << 2))) >> 1);
		stackPointer = (newContext + 4) + (((6 + tmp) - 1) * 4);
		/* begin quickCheckForInterrupts */
		if ((interruptCheckCounter -= 1) <= 0) {
			checkForInterrupts();
		}
	l1:	/* end executeNewMethod */;
		successFlag = 1;
	} else {
		for (i = 1; i <= argumentCount; i += 1) {
			/* begin storePointer:ofObject:withValue: */
			fieldIndex = ((argumentCount - i) + 1) + selectorIndex;
			oop = activeContext;
			valuePointer = longAt(((((char *) activeContext)) + 4) + (((argumentCount - i) + selectorIndex) << 2));
			if (oop < youngStart) {
				possibleRootStoreIntovalue(oop, valuePointer);
			}
			longAtput(((((char *) oop)) + 4) + (fieldIndex << 2), valuePointer);
		}
		/* begin unPop: */
		stackPointer += 1 * 4;
		/* begin storePointer:ofObject:withValue: */
		oop1 = activeContext;
		valuePointer1 = messageSelector;
		if (oop1 < youngStart) {
			possibleRootStoreIntovalue(oop1, valuePointer1);
		}
		longAtput(((((char *) oop1)) + 4) + (selectorIndex << 2), valuePointer1);
		argumentCount += 1;
		newMethod = performMethod;
		messageSelector = performSelector;
	}
}


/*	Common routine used by perform:withArgs: and perform:withArgs:inSuperclass: */
/*	NOTE:  The case of doesNotUnderstand: is not a failure to perform.
	The only failures are arg types and consistency of argumentCount. */

int primitivePerformAt(int lookupClass) {
    int argumentArray;
    int performMethod;
    int arraySize;
    int performSelector;
    int cntxSize;
    int index;
    int performArgCount;
    int sz;
    int objectPointer;
    int sz1;
    int sp;
    int sp1;
    int sp2;
    int top;
    int top1;
    int header;
    int header1;
    int cl;
    int ccIndex;
    int i;
    int newContext;
    int methodHeader;
    int nilOop;
    int initialIP;
    int tempCount;
    int tmp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	argumentArray = top;
	/* begin assertClassOf:is: */
	if ((argumentArray & 1)) {
		successFlag = 0;
		goto l4;
	}
	ccIndex = (((unsigned) (longAt(argumentArray))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(argumentArray - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))) && successFlag;
l4:	/* end assertClassOf:is: */;
	if (successFlag) {
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(argumentArray);
		if ((header & 3) == 0) {
			sz = (longAt(argumentArray - 8)) & 4294967292U;
			goto l2;
		} else {
			sz = header & 252;
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
		arraySize = ((unsigned) (sz - 4)) >> 2;
		/* begin fetchWordLengthOf: */
		objectPointer = activeContext;
		/* begin sizeBitsOf: */
		header1 = longAt(objectPointer);
		if ((header1 & 3) == 0) {
			sz1 = (longAt(objectPointer - 8)) & 4294967292U;
			goto l3;
		} else {
			sz1 = header1 & 252;
			goto l3;
		}
	l3:	/* end sizeBitsOf: */;
		cntxSize = ((unsigned) (sz1 - 4)) >> 2;
		/* begin success: */
		successFlag = (((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) + arraySize) < cntxSize) && successFlag;
	}
	if (!(successFlag)) {
		/* begin unPop: */
		stackPointer += 1 * 4;
		return null;
	}
	performSelector = messageSelector;
	performMethod = newMethod;
	performArgCount = argumentCount;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	messageSelector = top1;
	index = 1;
	while (index <= arraySize) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, longAt(((((char *) argumentArray)) + 4) + ((index - 1) << 2)));
		stackPointer = sp;
		index += 1;
	}
	argumentCount = arraySize;
	findNewMethodInClass(lookupClass);
	/* begin success: */
	successFlag = (((((unsigned) (longAt(((((char *) newMethod)) + 4) + (0 << 2)))) >> 25) & 15) == argumentCount) && successFlag;
	if (successFlag) {
		/* begin executeNewMethod */
		if (primitiveIndex > 0) {
			primitiveResponse();
			if (successFlag) {
				goto l1;
			}
		}
		/* begin activateNewMethod */
		methodHeader = longAt(((((char *) newMethod)) + 4) + (0 << 2));
		newContext = allocateOrRecycleContext(methodHeader & 262144);
		initialIP = ((1 + ((((unsigned) methodHeader) >> 10) & 255)) * 4) + 1;
		tempCount = (((unsigned) methodHeader) >> 19) & 63;
		longAtput(((((char *) newContext)) + 4) + (0 << 2), activeContext);
		longAtput(((((char *) newContext)) + 4) + (1 << 2), ((initialIP << 1) | 1));
		longAtput(((((char *) newContext)) + 4) + (2 << 2), ((tempCount << 1) | 1));
		longAtput(((((char *) newContext)) + 4) + (3 << 2), newMethod);
		for (i = 0; i <= argumentCount; i += 1) {
			longAtput(((((char *) newContext)) + 4) + ((5 + i) << 2), longAt(stackPointer - ((argumentCount - i) * 4)));
		}
		nilOop = nilObj;
		for (i = (argumentCount + 1); i <= tempCount; i += 1) {
			longAtput(((((char *) newContext)) + 4) + ((5 + i) << 2), nilOop);
		}
		/* begin pop: */
		stackPointer -= (argumentCount + 1) * 4;
		reclaimableContextCount += 1;
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
		longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
		if (newContext < youngStart) {
			beRootIfOld(newContext);
		}
		activeContext = newContext;
		/* begin fetchContextRegisters: */
		tmp = longAt(((((char *) newContext)) + 4) + (3 << 2));
		if ((tmp & 1)) {
			tmp = longAt(((((char *) newContext)) + 4) + (5 << 2));
			if (tmp < youngStart) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = newContext;
		}
		theHomeContext = tmp;
		receiver = longAt(((((char *) tmp)) + 4) + (5 << 2));
		method = longAt(((((char *) tmp)) + 4) + (3 << 2));
		tmp = ((longAt(((((char *) newContext)) + 4) + (1 << 2))) >> 1);
		instructionPointer = ((method + tmp) + 4) - 2;
		tmp = ((longAt(((((char *) newContext)) + 4) + (2 << 2))) >> 1);
		stackPointer = (newContext + 4) + (((6 + tmp) - 1) * 4);
		/* begin quickCheckForInterrupts */
		if ((interruptCheckCounter -= 1) <= 0) {
			checkForInterrupts();
		}
	l1:	/* end executeNewMethod */;
		successFlag = 1;
	} else {
		/* begin pop: */
		stackPointer -= argumentCount * 4;
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, messageSelector);
		stackPointer = sp1;
		/* begin push: */
		longAtput(sp2 = stackPointer + 4, argumentArray);
		stackPointer = sp2;
		messageSelector = performSelector;
		newMethod = performMethod;
		argumentCount = performArgCount;
	}
}

int primitivePerformInSuperclass(void) {
    int currentClass;
    int lookupClass;
    int rcvr;
    int sp;
    int top;
    int ccIndex;

	lookupClass = longAt(stackPointer);
	rcvr = longAt(stackPointer - (argumentCount * 4));
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		currentClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currentClass = (longAt(rcvr - 4)) & 4294967292U;
		goto l1;
	} else {
		currentClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	while (currentClass != lookupClass) {
		currentClass = longAt(((((char *) currentClass)) + 4) + (0 << 2));
		if (currentClass == nilObj) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	primitivePerformAt(lookupClass);
	if (!(successFlag)) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, lookupClass);
		stackPointer = sp;
	}
}

int primitivePerformWithArgs(void) {
    int lookupClass;
    int rcvr;
    int ccIndex;

	rcvr = longAt(stackPointer - (argumentCount * 4));
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		lookupClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		lookupClass = (longAt(rcvr - 4)) & 4294967292U;
		goto l1;
	} else {
		lookupClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	primitivePerformAt(lookupClass);
}

int primitivePointX(void) {
    int rcvr;
    int sp;
    int top;
    int cl;
    int ccIndex;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	rcvr = top;
	/* begin assertClassOf:is: */
	if ((rcvr & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(rcvr - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, longAt(((((char *) rcvr)) + 4) + (0 << 2)));
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}

int primitivePointY(void) {
    int rcvr;
    int sp;
    int top;
    int cl;
    int ccIndex;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	rcvr = top;
	/* begin assertClassOf:is: */
	if ((rcvr & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(rcvr - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, longAt(((((char *) rcvr)) + 4) + (1 << 2)));
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}

int primitivePushFalse(void) {
    int top;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, falseObj);
	stackPointer = sp;
}

int primitivePushMinusOne(void) {
    int top;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, 4294967295U);
	stackPointer = sp;
}

int primitivePushNil(void) {
    int top;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, nilObj);
	stackPointer = sp;
}

int primitivePushOne(void) {
    int top;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, 3);
	stackPointer = sp;
}


/*		no-op, really...
	thisReceiver _ self popStack.
	self push: thisReceiver
 */

int primitivePushSelf(void) {
}

int primitivePushTrue(void) {
    int top;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, trueObj);
	stackPointer = sp;
}

int primitivePushTwo(void) {
    int top;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, 5);
	stackPointer = sp;
}

int primitivePushZero(void) {
    int top;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, 1);
	stackPointer = sp;
}

int primitiveQuit(void) {
	ioExit();
}


/*	Rounds negative results towards zero. */

int primitiveQuo(void) {
    int integerResult;
    int integerArg;
    int integerRcvr;
    int integerPointer;
    int integerPointer1;
    int sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		integerRcvr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerRcvr = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (0 * 4));
	if ((integerPointer1 & 1)) {
		integerArg = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArg = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin success: */
	successFlag = (integerArg != 0) && successFlag;
	if (successFlag) {
		if (integerRcvr > 0) {
			if (integerArg > 0) {
				integerResult = integerRcvr / integerArg;
			} else {
				integerResult = 0 - (integerRcvr / (0 - integerArg));
			}
		} else {
			if (integerArg > 0) {
				integerResult = 0 - ((0 - integerRcvr) / integerArg);
			} else {
				integerResult = (0 - integerRcvr) / (0 - integerArg);
			}
		}
	}
	/* begin pop2AndPushIntegerIfOK: */
	if (successFlag) {
		if ((integerResult ^ (integerResult << 1)) >= 0) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * 4), ((integerResult << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}


/*	Relinquish the processor for up to the given number of microseconds. The exact behavior of this primitive is platform dependent. */

int primitiveRelinquishProcessor(void) {
    int microSecs;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		microSecs = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		microSecs = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		ioRelinquishProcessorForMicroseconds(microSecs);
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}


/*	Details: Since primitives can run for a long time, we must check to see if it is time to process a timer interrupt. However, on the Mac, the high-resolution millisecond clock is expensive to poll. Thus, we use a fast, low-resolution (1/60th second) clock to determine if the primitive took enough time to justify polling the high-resolution clock. Seems Byzantine, but Bob Arning showed that the performance of primitive-intensive code decreased substantially if there was another process waiting on a Delay.
	One other detail: If the primitive fails, we want to postpone the timer interrupt until just after the primitive failure code has been entered. This is accomplished by setting the interrupt check counter to zero, thus triggering a check for interrupts when activating the method containing the primitive. */

int primitiveResponse(void) {
    int timerPending;
    int delta;
    int primIdx;
    int startTime;
    int nArgs;

	timerPending = nextWakeupTick != 0;
	if (timerPending) {
		startTime = ioLowResMSecs();
	}
	;
	successFlag = 1;
	switch (primitiveIndex) {
	case 0:
		primitiveFail();
		break;
	case 1:
		primitiveAdd();
		break;
	case 2:
		primitiveSubtract();
		break;
	case 3:
		primitiveLessThan();
		break;
	case 4:
		primitiveGreaterThan();
		break;
	case 5:
		primitiveLessOrEqual();
		break;
	case 6:
		primitiveGreaterOrEqual();
		break;
	case 7:
		primitiveEqual();
		break;
	case 8:
		primitiveNotEqual();
		break;
	case 9:
		primitiveMultiply();
		break;
	case 10:
		primitiveDivide();
		break;
	case 11:
		primitiveMod();
		break;
	case 12:
		primitiveDiv();
		break;
	case 13:
		primitiveQuo();
		break;
	case 14:
		primitiveBitAnd();
		break;
	case 15:
		primitiveBitOr();
		break;
	case 16:
		primitiveBitXor();
		break;
	case 17:
		primitiveBitShift();
		break;
	case 18:
		primitiveMakePoint();
		break;
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 38:
	case 39:
		primitiveFail();
		break;
	case 40:
		primitiveAsFloat();
		break;
	case 41:
		primitiveFloatAddtoArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
		break;
	case 42:
		primitiveFloatSubtractfromArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
		break;
	case 43:
		primitiveFloatLessThan();
		break;
	case 44:
		primitiveFloatGreaterThan();
		break;
	case 45:
		primitiveFloatLessOrEqual();
		break;
	case 46:
		primitiveFloatGreaterOrEqual();
		break;
	case 47:
		primitiveFloatEqual();
		break;
	case 48:
		primitiveFloatNotEqual();
		break;
	case 49:
		primitiveFloatMultiplybyArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
		break;
	case 50:
		primitiveFloatDividebyArg(longAt(stackPointer - (1 * 4)), longAt(stackPointer));
		break;
	case 51:
		primitiveTruncated();
		break;
	case 52:
		primitiveFractionalPart();
		break;
	case 53:
		primitiveExponent();
		break;
	case 54:
		primitiveTimesTwoPower();
		break;
	case 55:
		primitiveSquareRoot();
		break;
	case 56:
		primitiveSine();
		break;
	case 57:
		primitiveArctan();
		break;
	case 58:
		primitiveLogN();
		break;
	case 59:
		primitiveExp();
		break;
	case 60:
		primitiveAt();
		break;
	case 61:
		primitiveAtPut();
		break;
	case 62:
		primitiveSize();
		break;
	case 63:
		primitiveStringAt();
		break;
	case 64:
		primitiveStringAtPut();
		break;
	case 65:
		primitiveNext();
		break;
	case 66:
		primitiveNextPut();
		break;
	case 67:
		primitiveAtEnd();
		break;
	case 68:
		primitiveObjectAt();
		break;
	case 69:
		primitiveObjectAtPut();
		break;
	case 70:
		primitiveNew();
		break;
	case 71:
		primitiveNewWithArg();
		break;
	case 72:
		primitiveArrayBecomeOneWay();
		break;
	case 73:
		primitiveInstVarAt();
		break;
	case 74:
		primitiveInstVarAtPut();
		break;
	case 75:
		primitiveAsOop();
		break;
	case 76:
		primitiveStoreStackp();
		break;
	case 77:
		primitiveSomeInstance();
		break;
	case 78:
		primitiveNextInstance();
		break;
	case 79:
		primitiveNewMethod();
		break;
	case 80:
		primitiveBlockCopy();
		break;
	case 81:
		primitiveValue();
		break;
	case 82:
		primitiveValueWithArgs();
		break;
	case 83:
		primitivePerform();
		break;
	case 84:
		primitivePerformWithArgs();
		break;
	case 85:
		primitiveSignal();
		break;
	case 86:
		primitiveWait();
		break;
	case 87:
		primitiveResume();
		break;
	case 88:
		primitiveSuspend();
		break;
	case 89:
		primitiveFlushCache();
		break;
	case 90:
		primitiveMousePoint();
		break;
	case 91:
		primitiveTestDisplayDepth();
		break;
	case 92:
		primitiveSetDisplayMode();
		break;
	case 93:
		primitiveInputSemaphore();
		break;
	case 94:
		primitiveGetNextEvent();
		break;
	case 95:
		primitiveInputWord();
		break;
	case 96:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 97:
		primitiveSnapshot();
		break;
	case 98:
		primitiveStoreImageSegment();
		break;
	case 99:
		primitiveLoadImageSegment();
		break;
	case 100:
		primitivePerformInSuperclass();
		break;
	case 101:
		primitiveBeCursor();
		break;
	case 102:
		primitiveBeDisplay();
		break;
	case 103:
		primitiveScanCharacters();
		break;
	case 104:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 105:
		primitiveStringReplace();
		break;
	case 106:
		primitiveScreenSize();
		break;
	case 107:
		primitiveMouseButtons();
		break;
	case 108:
		primitiveKbdNext();
		break;
	case 109:
		primitiveKbdPeek();
		break;
	case 110:
		primitiveEquivalent();
		break;
	case 111:
		primitiveClass();
		break;
	case 112:
		primitiveBytesLeft();
		break;
	case 113:
		primitiveQuit();
		break;
	case 114:
		primitiveExitToDebugger();
		break;
	case 115:
		primitiveChangeClass();
		break;
	case 116:
		primitiveFlushCacheByMethod();
		break;
	case 117:
		primitiveExternalCall();
		break;
	case 118:
		primitiveDoPrimitiveWithArgs();
		break;
	case 119:
		primitiveFlushCacheSelective();
		break;
	case 120:
		primitiveCalloutToFFI();
		break;
	case 121:
		primitiveImageName();
		break;
	case 122:
		primitiveNoop();
		break;
	case 123:
		primitiveValue();
		break;
	case 124:
		primitiveLowSpaceSemaphore();
		break;
	case 125:
		primitiveSignalAtBytesLeft();
		break;
	case 126:
		primitiveDeferDisplayUpdates();
		break;
	case 127:
		primitiveShowDisplayRect();
		break;
	case 128:
		primitiveArrayBecome();
		break;
	case 129:
		primitiveSpecialObjectsOop();
		break;
	case 130:
		primitiveFullGC();
		break;
	case 131:
		primitiveIncrementalGC();
		break;
	case 132:
		primitiveObjectPointsTo();
		break;
	case 133:
		primitiveSetInterruptKey();
		break;
	case 134:
		primitiveInterruptSemaphore();
		break;
	case 135:
		primitiveMillisecondClock();
		break;
	case 136:
		primitiveSignalAtMilliseconds();
		break;
	case 137:
		primitiveSecondsClock();
		break;
	case 138:
		primitiveSomeObject();
		break;
	case 139:
		primitiveNextObject();
		break;
	case 140:
		primitiveBeep();
		break;
	case 141:
		primitiveClipboardText();
		break;
	case 142:
		primitiveVMPath();
		break;
	case 143:
		primitiveShortAt();
		break;
	case 144:
		primitiveShortAtPut();
		break;
	case 145:
		primitiveConstantFill();
		break;
	case 146:
	case 147:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 148:
		primitiveClone();
		break;
	case 149:
		primitiveGetAttribute();
		break;
	case 150:
	case 151:
	case 152:
	case 153:
	case 154:
	case 155:
	case 156:
	case 157:
	case 158:
	case 159:
	case 160:
	case 161:
	case 162:
	case 163:
	case 164:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 165:
		primitiveIntegerAt();
		break;
	case 166:
		primitiveIntegerAtPut();
		break;
	case 167:
	case 168:
		primitiveFail();
		break;
	case 169:
	case 170:
	case 171:
	case 172:
	case 173:
	case 174:
	case 175:
	case 176:
	case 177:
	case 178:
	case 179:
	case 180:
	case 181:
	case 182:
	case 183:
	case 184:
	case 185:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 186:
	case 187:
	case 188:
		primitiveFail();
		break;
	case 189:
	case 190:
	case 191:
	case 192:
	case 193:
	case 194:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 195:
		primitiveFindNextUnwindContext();
		break;
	case 196:
		primitiveTerminateTo();
		break;
	case 197:
		primitiveFindHandlerContext();
		break;
	case 198:
		primitiveFail();
		break;
	case 199:
		primitiveFail();
		break;
	case 200:
	case 201:
	case 202:
	case 203:
	case 204:
	case 205:
	case 206:
	case 207:
	case 208:
	case 209:
	case 210:
	case 211:
	case 212:
	case 213:
	case 214:
	case 215:
	case 216:
	case 217:
	case 218:
	case 219:
	case 220:
	case 221:
	case 222:
	case 223:
	case 224:
	case 225:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 226:
	case 227:
	case 228:
	case 229:
		primitiveFail();
		break;
	case 230:
		primitiveRelinquishProcessor();
		break;
	case 231:
		primitiveForceDisplayUpdate();
		break;
	case 232:
		primitiveFormPrint();
		break;
	case 233:
		primitiveSetFullScreen();
		break;
	case 234:
	case 235:
	case 236:
	case 237:
	case 238:
	case 239:
	case 240:
	case 241:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 242:
		primitiveFail();
		break;
	case 243:
	case 244:
	case 245:
	case 246:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 247:
		primitiveSnapshotEmbedded();
		break;
	case 248:
	case 249:
		primitiveFail();
		break;
	case 250:
		clearProfile();
		break;
	case 251:
		dumpProfile();
		break;
	case 252:
		startProfiling();
		break;
	case 253:
		stopProfiling();
		break;
	case 254:
		primitiveVMParameter();
		break;
	case 255:
		primitiveInstVarsPutFromStack();
		break;
	case 256:
		primitivePushSelf();
		break;
	case 257:
		primitivePushTrue();
		break;
	case 258:
		primitivePushFalse();
		break;
	case 259:
		primitivePushNil();
		break;
	case 260:
		primitivePushMinusOne();
		break;
	case 261:
		primitivePushZero();
		break;
	case 262:
		primitivePushOne();
		break;
	case 263:
		primitivePushTwo();
		break;
	case 264:
	case 265:
	case 266:
	case 267:
	case 268:
	case 269:
	case 270:
	case 271:
	case 272:
	case 273:
	case 274:
	case 275:
	case 276:
	case 277:
	case 278:
	case 279:
	case 280:
	case 281:
	case 282:
	case 283:
	case 284:
	case 285:
	case 286:
	case 287:
	case 288:
	case 289:
	case 290:
	case 291:
	case 292:
	case 293:
	case 294:
	case 295:
	case 296:
	case 297:
	case 298:
	case 299:
	case 300:
	case 301:
	case 302:
	case 303:
	case 304:
	case 305:
	case 306:
	case 307:
	case 308:
	case 309:
	case 310:
	case 311:
	case 312:
	case 313:
	case 314:
	case 315:
	case 316:
	case 317:
	case 318:
	case 319:
	case 320:
	case 321:
	case 322:
	case 323:
	case 324:
	case 325:
	case 326:
	case 327:
	case 328:
	case 329:
	case 330:
	case 331:
	case 332:
	case 333:
	case 334:
	case 335:
	case 336:
	case 337:
	case 338:
	case 339:
	case 340:
	case 341:
	case 342:
	case 343:
	case 344:
	case 345:
	case 346:
	case 347:
	case 348:
	case 349:
	case 350:
	case 351:
	case 352:
	case 353:
	case 354:
	case 355:
	case 356:
	case 357:
	case 358:
	case 359:
	case 360:
	case 361:
	case 362:
	case 363:
	case 364:
	case 365:
	case 366:
	case 367:
	case 368:
	case 369:
	case 370:
	case 371:
	case 372:
	case 373:
	case 374:
	case 375:
	case 376:
	case 377:
	case 378:
	case 379:
	case 380:
	case 381:
	case 382:
	case 383:
	case 384:
	case 385:
	case 386:
	case 387:
	case 388:
	case 389:
	case 390:
	case 391:
	case 392:
	case 393:
	case 394:
	case 395:
	case 396:
	case 397:
	case 398:
	case 399:
	case 400:
	case 401:
	case 402:
	case 403:
	case 404:
	case 405:
	case 406:
	case 407:
	case 408:
	case 409:
	case 410:
	case 411:
	case 412:
	case 413:
	case 414:
	case 415:
	case 416:
	case 417:
	case 418:
	case 419:
	case 420:
	case 421:
	case 422:
	case 423:
	case 424:
	case 425:
	case 426:
	case 427:
	case 428:
	case 429:
	case 430:
	case 431:
	case 432:
	case 433:
	case 434:
	case 435:
	case 436:
	case 437:
	case 438:
	case 439:
	case 440:
	case 441:
	case 442:
	case 443:
	case 444:
	case 445:
	case 446:
	case 447:
	case 448:
	case 449:
	case 450:
	case 451:
	case 452:
	case 453:
	case 454:
	case 455:
	case 456:
	case 457:
	case 458:
	case 459:
	case 460:
	case 461:
	case 462:
	case 463:
	case 464:
	case 465:
	case 466:
	case 467:
	case 468:
	case 469:
	case 470:
	case 471:
	case 472:
	case 473:
	case 474:
	case 475:
	case 476:
	case 477:
	case 478:
	case 479:
	case 480:
	case 481:
	case 482:
	case 483:
	case 484:
	case 485:
	case 486:
	case 487:
	case 488:
	case 489:
	case 490:
	case 491:
	case 492:
	case 493:
	case 494:
	case 495:
	case 496:
	case 497:
	case 498:
	case 499:
	case 500:
	case 501:
	case 502:
	case 503:
	case 504:
	case 505:
	case 506:
	case 507:
	case 508:
	case 509:
	case 510:
	case 511:
	case 512:
	case 513:
	case 514:
	case 515:
	case 516:
	case 517:
	case 518:
	case 519:
		primitiveLoadInstVar();
		break;
	case 520:
	case 521:
	case 522:
	case 523:
	case 524:
	case 525:
	case 526:
	case 527:
	case 528:
	case 529:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 530:
	case 531:
	case 532:
	case 533:
	case 534:
	case 535:
	case 536:
	case 537:
	case 538:
	case 539:
		primitiveFail();
		break;
	case 540:
	case 541:
	case 542:
	case 543:
	case 544:
	case 545:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 546:
	case 547:
		primitiveFail();
		break;
	case 548:
	case 549:
	case 550:
	case 551:
	case 552:
	case 553:
		primitiveObsoleteIndexedPrimitive();
		break;
	case 554:
	case 555:
	case 556:
	case 557:
	case 558:
	case 559:
	case 560:
	case 561:
	case 562:
	case 563:
	case 564:
	case 565:
	case 566:
	case 567:
	case 568:
	case 569:
		primitiveFail();
		break;
	case 570:
		flushExternalPrimitives();
		break;
	case 571:
		primitiveUnloadModule();
		break;
	case 572:
		primitiveListBuiltinModule();
		break;
	case 573:
		primitiveListExternalModule();
		break;
	case 574:
	case 575:
	case 576:
	case 577:
	case 578:
	case 579:
	case 580:
	case 581:
	case 582:
	case 583:
	case 584:
	case 585:
	case 586:
	case 587:
	case 588:
	case 589:
	case 590:
	case 591:
	case 592:
	case 593:
	case 594:
	case 595:
	case 596:
	case 597:
	case 598:
	case 599:
	case 600:
	case 601:
	case 602:
	case 603:
	case 604:
	case 605:
	case 606:
	case 607:
	case 608:
	case 609:
	case 610:
	case 611:
	case 612:
	case 613:
	case 614:
	case 615:
	case 616:
	case 617:
	case 618:
	case 619:
	case 620:
	case 621:
	case 622:
	case 623:
	case 624:
	case 625:
	case 626:
	case 627:
	case 628:
	case 629:
	case 630:
	case 631:
	case 632:
	case 633:
	case 634:
	case 635:
	case 636:
	case 637:
	case 638:
	case 639:
	case 640:
	case 641:
	case 642:
	case 643:
	case 644:
	case 645:
	case 646:
	case 647:
	case 648:
	case 649:
	case 650:
	case 651:
	case 652:
	case 653:
	case 654:
	case 655:
	case 656:
	case 657:
	case 658:
	case 659:
	case 660:
	case 661:
	case 662:
	case 663:
	case 664:
	case 665:
	case 666:
	case 667:
	case 668:
	case 669:
	case 670:
	case 671:
	case 672:
	case 673:
	case 674:
	case 675:
	case 676:
	case 677:
	case 678:
	case 679:
	case 680:
	case 681:
	case 682:
	case 683:
	case 684:
	case 685:
	case 686:
	case 687:
	case 688:
	case 689:
	case 690:
	case 691:
	case 692:
	case 693:
	case 694:
	case 695:
	case 696:
	case 697:
	case 698:
	case 699:
	case 700:
		primitiveFail();
		break;
	}
	;
	if (timerPending) {
		if ((ioLowResMSecs()) != startTime) {
			if (((ioMSecs()) & 536870911) >= nextWakeupTick) {
				if (successFlag) {
					checkForInterrupts();
				} else {
					interruptCheckCounter = 0;
				}
			}
		}
	}
	return successFlag;
}

int primitiveResume(void) {
    int proc;


	/* rcvr */
	/* self success: ((self fetchClassOf: proc) = (self splObj: ClassProcess)). */

	proc = longAt(stackPointer);
	if (successFlag) {
		resume(proc);
	}
}


/*	Invoke the character scanner primitive. */

int primitiveScanCharacters(void) {
    int maxGlyph;
    int nextDestX;
    int sourceString;
    int glyphIndex;
    int sourceX;
    int scanLastIndex;
    int scanXTable;
    int stops;
    int scanDestX;
    int scanStopIndex;
    int scanMap;
    int scanRightX;
    int kernDelta;
    int rcvr;
    int stopReason;
    int nilOop;
    int scanStartIndex;
    int ascii;
    int sourceX2;
    int sp;
    int sp1;
    int integerPointer;
    int oop;
    int integerPointer1;
    int oop1;
    int integerPointer2;
    int integerPointer3;
    int oop2;
    int sp2;

	if (!(argumentCount == 6)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		kernDelta = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		kernDelta = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		stops = null;
		goto l2;
	}
	stops = oop;
l2:	/* end stackObjectValue: */;
	if (!((fetchClassOf(stops)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(stops)) >= 258)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		scanRightX = (integerPointer1 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		scanRightX = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (3 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		sourceString = null;
		goto l4;
	}
	sourceString = oop1;
l4:	/* end stackObjectValue: */;
	if (!(((((unsigned) (longAt(sourceString))) >> 8) & 15) >= 8)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (4 * 4));
	if ((integerPointer2 & 1)) {
		scanStopIndex = (integerPointer2 >> 1);
		goto l5;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		scanStopIndex = 0;
		goto l5;
	}
l5:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(stackPointer - (5 * 4));
	if ((integerPointer3 & 1)) {
		scanStartIndex = (integerPointer3 >> 1);
		goto l6;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		scanStartIndex = 0;
		goto l6;
	}
l6:	/* end stackIntegerValue: */;
	if (!((scanStartIndex > 0) && ((scanStopIndex > 0) && (scanStopIndex <= (byteSizeOf(sourceString)))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (6 * 4));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l7;
	}
	rcvr = oop2;
l7:	/* end stackObjectValue: */;
	if (!((((((unsigned) (longAt(rcvr))) >> 8) & 15) <= 4) && ((slotSizeOf(rcvr)) >= 4))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	scanDestX = fetchIntegerofObject(0, rcvr);
	scanLastIndex = fetchIntegerofObject(1, rcvr);
	scanXTable = longAt(((((char *) rcvr)) + 4) + (2 << 2));
	scanMap = longAt(((((char *) rcvr)) + 4) + (3 << 2));
	if (!(((fetchClassOf(scanXTable)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))) && ((fetchClassOf(scanMap)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(scanMap)) == 256)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!successFlag) {
		return null;
	}

	/* Okay, here we go. We have eliminated nearly all failure conditions,
	to optimize the inner fetches. */

	maxGlyph = (slotSizeOf(scanXTable)) - 2;
	scanLastIndex = scanStartIndex;
	nilOop = nilObj;
	while (scanLastIndex <= scanStopIndex) {

		/* Known to be okay since stops size >= 258 */

		ascii = byteAt(((((char *) sourceString)) + 4) + (scanLastIndex - 1));
		if (!((stopReason = longAt(((((char *) stops)) + 4) + (ascii << 2))) == nilOop)) {
			if (!((scanDestX ^ (scanDestX << 1)) >= 0)) {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
			/* begin storeInteger:ofObject:withValue: */
			if ((scanDestX ^ (scanDestX << 1)) >= 0) {
				longAtput(((((char *) rcvr)) + 4) + (0 << 2), ((scanDestX << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			/* begin storeInteger:ofObject:withValue: */
			if ((scanLastIndex ^ (scanLastIndex << 1)) >= 0) {
				longAtput(((((char *) rcvr)) + 4) + (1 << 2), ((scanLastIndex << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			/* begin pop: */
			stackPointer -= 7 * 4;
			/* begin push: */
			longAtput(sp = stackPointer + 4, stopReason);
			stackPointer = sp;
			return null;
		}
		glyphIndex = fetchIntegerofObject(ascii, scanMap);
		if ((!successFlag) || ((glyphIndex < 0) || (glyphIndex > maxGlyph))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		sourceX = fetchIntegerofObject(glyphIndex, scanXTable);

		/* Above may fail if non-integer entries in scanXTable */

		sourceX2 = fetchIntegerofObject(glyphIndex + 1, scanXTable);
		if (!successFlag) {
			return null;
		}
		nextDestX = (scanDestX + sourceX2) - sourceX;
		if (nextDestX > scanRightX) {
			if (!((scanDestX ^ (scanDestX << 1)) >= 0)) {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
			/* begin storeInteger:ofObject:withValue: */
			if ((scanDestX ^ (scanDestX << 1)) >= 0) {
				longAtput(((((char *) rcvr)) + 4) + (0 << 2), ((scanDestX << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			/* begin storeInteger:ofObject:withValue: */
			if ((scanLastIndex ^ (scanLastIndex << 1)) >= 0) {
				longAtput(((((char *) rcvr)) + 4) + (1 << 2), ((scanLastIndex << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			/* begin pop: */
			stackPointer -= 7 * 4;
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, longAt(((((char *) stops)) + 4) + ((258 - 1) << 2)));
			stackPointer = sp1;
			return null;
		}
		scanDestX = nextDestX + kernDelta;
		scanLastIndex += 1;
	}
	if (!((scanDestX ^ (scanDestX << 1)) >= 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if ((scanDestX ^ (scanDestX << 1)) >= 0) {
		longAtput(((((char *) rcvr)) + 4) + (0 << 2), ((scanDestX << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if ((scanStopIndex ^ (scanStopIndex << 1)) >= 0) {
		longAtput(((((char *) rcvr)) + 4) + (1 << 2), ((scanStopIndex << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin pop: */
	stackPointer -= 7 * 4;
	/* begin push: */
	longAtput(sp2 = stackPointer + 4, longAt(((((char *) stops)) + 4) + ((257 - 1) << 2)));
	stackPointer = sp2;
	return null;
}


/*	Return a SmallInteger indicating the current depth of the OS screen */

EXPORT(int) primitiveScreenDepth(void) {
    int depth;
    int sp;

	depth = ioScreenDepth();
	if ((!successFlag) || (depth <= 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, ((depth << 1) | 1));
	stackPointer = sp;
}


/*	Return a point indicating the current size of the Smalltalk window. */

int primitiveScreenSize(void) {
    int pointWord;
    int object;
    int sp;
    int pointResult;

	/* begin pop: */
	stackPointer -= 1 * 4;
	pointWord = ioScreenSize();
	/* begin push: */
	/* begin makePointwithxValue:yValue: */
	pointResult = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
	/* begin storePointer:ofObject:withValue: */
	if (pointResult < youngStart) {
		possibleRootStoreIntovalue(pointResult, ((((((unsigned) pointWord) >> 16) & 65535) << 1) | 1));
	}
	longAtput(((((char *) pointResult)) + 4) + (0 << 2), ((((((unsigned) pointWord) >> 16) & 65535) << 1) | 1));
	/* begin storePointer:ofObject:withValue: */
	if (pointResult < youngStart) {
		possibleRootStoreIntovalue(pointResult, (((pointWord & 65535) << 1) | 1));
	}
	longAtput(((((char *) pointResult)) + 4) + (1 << 2), (((pointWord & 65535) << 1) | 1));
	object = pointResult;
	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
}


/*	Return the number of seconds since January 1, 1901 as an integer. */

int primitiveSecondsClock(void) {
    int object;
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin push: */
	object = positive32BitIntegerFor(ioSeconds());
	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
}


/*	Set to OS to the requested display mode.
	See also DisplayScreen setDisplayDepth:extent:fullscreen: */

int primitiveSetDisplayMode(void) {
    int d;
    int w;
    int h;
    int okay;
    int fsFlag;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int sp;
    int sp1;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (0 * 4))) == trueObj) {
		fsFlag = 1;
		goto l1;
	}
	if ((longAt(stackPointer - (0 * 4))) == falseObj) {
		fsFlag = 0;
		goto l1;
	}
	successFlag = 0;
	fsFlag = null;
l1:	/* end booleanValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		h = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		h = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		w = (integerPointer1 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		w = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (3 * 4));
	if ((integerPointer2 & 1)) {
		d = (integerPointer2 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		d = 0;
		goto l4;
	}
l4:	/* end stackIntegerValue: */;
	if (successFlag) {
		okay = ioSetDisplayMode(w, h, d, fsFlag);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		/* begin pushBool: */
		if (okay) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	}
}


/*	On platforms that support it, set full-screen mode to the value of the boolean argument. */

int primitiveSetFullScreen(void) {
    int argOop;

	argOop = longAt(stackPointer);
	if (argOop == trueObj) {
		ioSetFullScreen(1);
	} else {
		if (argOop == falseObj) {
			ioSetFullScreen(0);
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}


/*	Set the user interrupt keycode. The keycode is an integer whose encoding is described in the comment for primitiveKbdNext. */

int primitiveSetInterruptKey(void) {
    int keycode;
    int integerPointer;
    int top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		keycode = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		keycode = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	if (successFlag) {
		interruptKeycode = keycode;
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	Treat the receiver, which can be indexible by either bytes or words, as an array of signed 16-bit values. Return the contents of the given index. Note that the index specifies the i-th 16-bit entry, not the i-th byte or word. */

int primitiveShortAt(void) {
    int value;
    int rcvr;
    int sz;
    int index;
    int addr;
    int integerPointer;
    int successValue;
    int successValue1;
    int sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	rcvr = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successValue = (!((rcvr & 1))) && (isWordsOrBytes(rcvr));
	successFlag = successValue && successFlag;
	if (!(successFlag)) {
		return null;
	}

	/* number of 16-bit fields */

	sz = ((int) ((sizeBitsOf(rcvr)) - 4) >> 1);
	/* begin success: */
	successValue1 = (index >= 1) && (index <= sz);
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		addr = (rcvr + 4) + (2 * (index - 1));
		value = *((short int *) addr);
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((value << 1) | 1));
		stackPointer = sp;
	}
}


/*	Treat the receiver, which can be indexible by either bytes or words, as an array of signed 16-bit values. Set the contents of the given index to the given value. Note that the index specifies the i-th 16-bit entry, not the i-th byte or word. */

int primitiveShortAtPut(void) {
    int value;
    int rcvr;
    int sz;
    int index;
    int addr;
    int integerPointer;
    int integerPointer1;
    int successValue;
    int successValue1;
    int successValue2;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		value = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		value = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		index = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	rcvr = longAt(stackPointer - (2 * 4));
	/* begin success: */
	successValue = (!((rcvr & 1))) && (isWordsOrBytes(rcvr));
	successFlag = successValue && successFlag;
	if (!(successFlag)) {
		return null;
	}

	/* number of 16-bit fields */

	sz = ((int) ((sizeBitsOf(rcvr)) - 4) >> 1);
	/* begin success: */
	successValue1 = (index >= 1) && (index <= sz);
	successFlag = successValue1 && successFlag;
	/* begin success: */
	successValue2 = (value >= -32768) && (value <= 32767);
	successFlag = successValue2 && successFlag;
	if (successFlag) {
		addr = (rcvr + 4) + (2 * (index - 1));
		*((short int *) addr) = value;
		/* begin pop: */
		stackPointer -= 2 * 4;
	}
}


/*	Force the given rectangular section of the Display to be copied to the screen. */

int primitiveShowDisplayRect(void) {
    int left;
    int top;
    int right;
    int bottom;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int integerPointer3;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		bottom = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		bottom = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		top = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		top = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (2 * 4));
	if ((integerPointer2 & 1)) {
		right = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		right = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(stackPointer - (3 * 4));
	if ((integerPointer3 & 1)) {
		left = (integerPointer3 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		left = 0;
		goto l4;
	}
l4:	/* end stackIntegerValue: */;
	displayBitsOfLeftTopRightBottom(longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2)), left, top, right, bottom);
	if (successFlag) {
		ioForceDisplayUpdate();
		/* begin pop: */
		stackPointer -= 4 * 4;
	}
}

int primitiveSignal(void) {
    int sema;
    int cl;
    int ccIndex;


	/* rcvr */

	sema = longAt(stackPointer);
	/* begin assertClassOf:is: */
	if ((sema & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(sema))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(sema - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		synchronousSignal(sema);
	}
}


/*	Set the low-water mark for free space. When the free space falls below this level, the new and new: primitives fail and system attempts to allocate space (e.g., to create a method context) cause the low-space semaphore (if one is registered) to be signalled. */

int primitiveSignalAtBytesLeft(void) {
    int bytes;
    int integerPointer;
    int top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		bytes = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		bytes = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	if (successFlag) {
		lowSpaceThreshold = bytes;
	} else {
		lowSpaceThreshold = 0;
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	Cause the time semaphore, if one has been registered, to be signalled when the millisecond clock is greater than or equal to the given tick value. A tick value of zero turns off timer interrupts. */

int primitiveSignalAtMilliseconds(void) {
    int sema;
    int tick;
    int oop;
    int oop1;
    int valuePointer;
    int integerPointer;
    int top;
    int top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		tick = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		tick = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	sema = top1;
	if (successFlag) {
		if ((fetchClassOf(sema)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
			/* begin storePointer:ofObject:withValue: */
			oop = specialObjectsOop;
			if (oop < youngStart) {
				possibleRootStoreIntovalue(oop, sema);
			}
			longAtput(((((char *) oop)) + 4) + (29 << 2), sema);
			nextWakeupTick = tick;
		} else {
			/* begin storePointer:ofObject:withValue: */
			oop1 = specialObjectsOop;
			valuePointer = nilObj;
			if (oop1 < youngStart) {
				possibleRootStoreIntovalue(oop1, valuePointer);
			}
			longAtput(((((char *) oop1)) + 4) + (29 << 2), valuePointer);
			nextWakeupTick = 0;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveSine(void) {
    double rcvr;

	rcvr = popFloat();
	if (successFlag) {
		pushFloat(sin(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}

int primitiveSize(void) {
    int rcvr;
    int sz;
    int oop;
    int sp;
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int sp1;
    int sz1;
    int classFormat;
    int class;
    int ccIndex;

	rcvr = longAt(stackPointer);
	if ((rcvr & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (((((unsigned) (longAt(rcvr))) >> 8) & 15) < 2) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stSizeOf: */
	hdr = longAt(rcvr);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz1 = (longAt(rcvr - 8)) & 4294967292U;
	} else {
		sz1 = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz1 - 4)) >> 2;
		goto l1;
	} else {
		totalLength = (sz1 - 4) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l2;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l2;
	}
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(rcvr - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l2:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp1 = longAt(((((char *) rcvr)) + 4) + (2 << 2));
		if (!((sp1 & 1))) {
			sz = 0;
			goto l4;
		}
		sz = (sp1 >> 1);
		goto l4;
	} else {
		sz = totalLength - fixedFields;
		goto l4;
	}
l4:	/* end stSizeOf: */;
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = positive32BitIntegerFor(sz);
		longAtput(sp = stackPointer - ((1 - 1) * 4), oop);
		stackPointer = sp;
	}
}


/*	update state of active context */

int primitiveSnapshot(void) {
    int rcvr;
    int dataSize;
    int activeProc;
    int top;
    int sp;
    int sp1;
    int sp2;
    int valuePointer;

	if (compilerInitialized) {
		compilerPreSnapshot();
	} else {
		/* begin storeContextRegisters: */
		longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
		longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
	}
	activeProc = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (1 << 2));
	/* begin storePointer:ofObject:withValue: */
	valuePointer = activeContext;
	if (activeProc < youngStart) {
		possibleRootStoreIntovalue(activeProc, valuePointer);
	}
	longAtput(((((char *) activeProc)) + 4) + (1 << 2), valuePointer);
	cleanUpContexts();
	incrementalGC();
	fullGC();

	/* Assume: all objects are below the start of the free block */

	dataSize = freeBlock - (startOfMemory());
	if (successFlag) {
		/* begin popStack */
		top = longAt(stackPointer);
		stackPointer -= 4;
		rcvr = top;
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
		writeImageFile(dataSize);
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
	if (successFlag) {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp2 = stackPointer + 4, rcvr);
		stackPointer = sp2;
	}
	if (compilerInitialized) {
		compilerPostSnapshot();
	}
}

int primitiveSnapshotEmbedded(void) {
    int rcvr;
    int dataSize;
    int activeProc;
    int top;
    int sp;
    int sp1;
    int sp2;
    int valuePointer;

	/* begin compilerPreSnapshotHook */
	if (compilerInitialized) {
		compilerPreSnapshot();
	}
	/* begin storeContextRegisters: */
	longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
	longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
	activeProc = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (1 << 2));
	/* begin storePointer:ofObject:withValue: */
	valuePointer = activeContext;
	if (activeProc < youngStart) {
		possibleRootStoreIntovalue(activeProc, valuePointer);
	}
	longAtput(((((char *) activeProc)) + 4) + (1 << 2), valuePointer);
	cleanUpContexts();
	incrementalGC();
	fullGC();

	/* Assume: all objects are below the start of the free block */

	dataSize = freeBlock - (startOfMemory());
	if (successFlag) {
		/* begin popStack */
		top = longAt(stackPointer);
		stackPointer -= 4;
		rcvr = top;
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
		/* begin writeImageFileEmbedded: */
		writeImageFileIO(dataSize);
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
	if (successFlag) {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp2 = stackPointer + 4, rcvr);
		stackPointer = sp2;
	}
	/* begin compilerPostSnapshotHook */
	if (compilerInitialized) {
		compilerPostSnapshot();
	}
}

int primitiveSomeInstance(void) {
    int instance;
    int class;
    int top;
    int thisClass;
    int thisObj;
    int sp;
    int ccIndex;
    int obj;
    int chunk;
    int extra;
    int extra1;
    int type;
    int sz;
    int extra2;
    int header;
    int extra11;
    int type1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	class = top;
	/* begin initialInstanceOf: */
	/* begin firstAccessibleObject */
	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	obj = chunk + extra;
	while (obj < endOfMemory) {
		if (!(((longAt(obj)) & 3) == 2)) {
			thisObj = obj;
			goto l4;
		}
		/* begin objectAfter: */
		;
		if (((longAt(obj)) & 3) == 2) {
			sz = (longAt(obj)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & 3) == 0) {
				sz = (longAt(obj - 8)) & 4294967292U;
				goto l3;
			} else {
				sz = header & 252;
				goto l3;
			}
		l3:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(obj + sz)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		obj = (obj + sz) + extra2;
	}
	error("heap is empty");
l4:	/* end firstAccessibleObject */;
	while (!(thisObj == null)) {
		/* begin fetchClassOf: */
		if ((thisObj & 1)) {
			thisClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l2;
		}
		ccIndex = (((unsigned) (longAt(thisObj))) >> 12) & 31;
		if (ccIndex == 0) {
			thisClass = (longAt(thisObj - 4)) & 4294967292U;
			goto l2;
		} else {
			thisClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
			goto l2;
		}
	l2:	/* end fetchClassOf: */;
		if (thisClass == class) {
			instance = thisObj;
			goto l1;
		}
		thisObj = accessibleObjectAfter(thisObj);
	}
	instance = nilObj;
l1:	/* end initialInstanceOf: */;
	if (instance == nilObj) {
		/* begin unPop: */
		stackPointer += 1 * 4;
		/* begin primitiveFail */
		successFlag = 0;
	} else {
		/* begin push: */
		longAtput(sp = stackPointer + 4, instance);
		stackPointer = sp;
	}
}


/*	Return the first object in the heap. */

int primitiveSomeObject(void) {
    int object;
    int sp;
    int obj;
    int chunk;
    int extra;
    int extra1;
    int type;
    int sz;
    int extra2;
    int header;
    int extra11;
    int type1;

	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin push: */
	/* begin firstAccessibleObject */
	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	obj = chunk + extra;
	while (obj < endOfMemory) {
		if (!(((longAt(obj)) & 3) == 2)) {
			object = obj;
			goto l2;
		}
		/* begin objectAfter: */
		;
		if (((longAt(obj)) & 3) == 2) {
			sz = (longAt(obj)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & 3) == 0) {
				sz = (longAt(obj - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(obj + sz)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		obj = (obj + sz) + extra2;
	}
	error("heap is empty");
l2:	/* end firstAccessibleObject */;
	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
}


/*	Return the oop of the SpecialObjectsArray. */

int primitiveSpecialObjectsOop(void) {
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, specialObjectsOop);
	stackPointer = sp;
}

int primitiveSquareRoot(void) {
    double rcvr;

	rcvr = popFloat();
	/* begin success: */
	successFlag = (rcvr >= 0.0) && successFlag;
	if (successFlag) {
		pushFloat(sqrt(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	This primitive is called from Squeak as...
		<imageSegment> storeSegmentFor: arrayOfRoots into: aWordArray outPointers: anArray. */
/*	This primitive will store a binary image segment (in the same format as the Squeak image file) of the receiver and every object in its proper tree of subParts (ie, that is not refered to from anywhere else outside the tree).  All pointers from within the tree to objects outside the tree will be copied into the array of outpointers.  In their place in the image segment will be an oop equal to the offset in the outPointer array (the first would be 4). but with the high bit set. */
/*	The primitive expects the array and wordArray to be more than adequately long.  In this case it returns normally, and truncates the two arrays to exactly the right size.  To simplify truncation, both incoming arrays are required to be 256 bytes or more long (ie with 3-word headers).  If either array is too small, the primitive will fail, but in no other case.

During operation of the primitive, it is necessary to convert from both internal and external oops to their mapped values.  To make this fast, the headers of the original objects in question are replaced by the mapped values (and this is noted by adding the forbidden XX header type).  Tables are kept of both kinds of oops, as well as of the original headers for restoration.

To be specific, there are two similar two-part tables, the outpointer array, and one in the upper fifth of the segmentWordArray.  Each grows oops from the bottom up, and preserved headers from halfway up.

In case of either success or failure, the headers must be restored.  In the event of primitive failure, the table of outpointers must also be nilled out (since the garbage in the high half will not have been discarded. */

int primitiveStoreImageSegment(void) {
    int header;
    int outPointerArray;
    int lastSeg;
    int fieldPtr;
    int mapOop;
    int arrayOfRoots;
    int fieldOop;
    int segOop;
    int lastOut;
    int savedYoungStart;
    int endSeg;
    int firstIn;
    int doingClass;
    int hdrBaseOut;
    int firstOut;
    int lastIn;
    int hdrTypeBits;
    int versionOffset;
    int lastPtr;
    int extraSize;
    int hdrBaseIn;
    int segmentWordArray;
    int i;
    int lastAddr;
    int i1;
    int lastAddr1;
    int i2;
    int lastAddr2;
    int i3;
    int lastAddr3;
    int extra;
    int extra1;
    int type;
    int out;
    int lastIn1;
    int in;
    int out1;
    int lastIn2;
    int in1;
    int sz;
    int extra2;
    int header1;
    int extra11;
    int type1;
    int extra3;
    int type2;

	outPointerArray = longAt(stackPointer - (0 * 4));
	segmentWordArray = longAt(stackPointer - (1 * 4));

	/* Essential type checks */

	arrayOfRoots = longAt(stackPointer - (2 * 4));
	if (!((((((unsigned) (longAt(arrayOfRoots))) >> 8) & 15) == 2) && ((((((unsigned) (longAt(outPointerArray))) >> 8) & 15) == 2) && (((((unsigned) (longAt(segmentWordArray))) >> 8) & 15) == 6)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((((longAt(outPointerArray)) & 3) == 0) && (((longAt(segmentWordArray)) & 3) == 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	;
	firstOut = outPointerArray + 4;
	lastOut = firstOut - 4;

	/* top half */

	hdrBaseOut = outPointerArray + ((((int) (lastPointerOf(outPointerArray)) >> 3)) * 4);
	lastSeg = segmentWordArray;

	/* Write a version number for byte order and version check */

	endSeg = (segmentWordArray + (sizeBitsOf(segmentWordArray))) - 4;
	versionOffset = 4;
	lastSeg += versionOffset;
	if (lastSeg > endSeg) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	longAtput(lastSeg, imageSegmentVersion());

	/* Take 1/8 of seg */

	firstIn = endSeg - ((((int) (sizeBitsOf(segmentWordArray)) >> 5)) * 4);
	lastIn = firstIn - 4;

	/* top half */
	/* First mark the rootArray and all root objects. */

	hdrBaseIn = firstIn + ((((int) (sizeBitsOf(segmentWordArray)) >> 6)) * 4);
	longAtput(arrayOfRoots, (longAt(arrayOfRoots)) | 2147483648U);
	lastPtr = arrayOfRoots + (lastPointerOf(arrayOfRoots));
	fieldPtr = arrayOfRoots + 4;
	while (fieldPtr <= lastPtr) {
		fieldOop = longAt(fieldPtr);
		if (!((fieldOop & 1))) {
			longAtput(fieldOop, (longAt(fieldOop)) | 2147483648U);
		}
		fieldPtr += 4;
	}
	savedYoungStart = youngStart;

	/* process all of memory */
	/* clear the recycled context lists */

	youngStart = startOfMemory();
	freeContexts = 1;
	freeLargeContexts = 1;
	markAndTraceInterpreterOops();

	/* Finally unmark the rootArray and all root objects. */

	youngStart = savedYoungStart;
	longAtput(arrayOfRoots, (longAt(arrayOfRoots)) & 2147483647U);
	fieldPtr = arrayOfRoots + 4;
	while (fieldPtr <= lastPtr) {
		fieldOop = longAt(fieldPtr);
		if (!((fieldOop & 1))) {
			longAtput(fieldOop, (longAt(fieldOop)) & 2147483647U);
		}
		fieldPtr += 4;
	}
	lastIn += 4;
	if (lastIn >= hdrBaseIn) {
		successFlag = 0;
	}
	lastSeg = copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(arrayOfRoots, segmentWordArray, lastSeg, firstIn, lastIn, hdrBaseIn + (lastIn - firstIn));
	if (!(successFlag)) {
		lastIn -= 4;
		restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
		/* begin primitiveFailAfterCleanup: */
		lastAddr = outPointerArray + (lastPointerOf(outPointerArray));
		i = outPointerArray + 4;
		while (i <= lastAddr) {
			longAtput(i, nilObj);
			i += 4;
		}
		;
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type2 = (longAt((segmentWordArray + versionOffset) + 4)) & 3;
	if (type2 > 1) {
		extra3 = 0;
	} else {
		if (type2 == 1) {
			extra3 = 4;
		} else {
			extra3 = 8;
		}
	}
	extra = extra3;
	segOop = ((segmentWordArray + versionOffset) + 4) + extra;
	while (segOop <= lastSeg) {
		if (((longAt(segOop)) & 3) <= 1) {
			fieldPtr = segOop - 4;
			doingClass = 1;
		} else {
			fieldPtr = segOop + 4;
			doingClass = 0;
		}

		/* last field */
		/* Go through all oops, remapping them... */

		lastPtr = segOop + (lastPointerOf(segOop));
		while (!(fieldPtr > lastPtr)) {
			fieldOop = longAt(fieldPtr);
			if (doingClass) {
				hdrTypeBits = fieldOop & 3;
				fieldOop -= hdrTypeBits;
			}
			if ((fieldOop & 1)) {
				fieldPtr += 4;
			} else {
				header = longAt(fieldOop);
				if ((header & 3) == 2) {
					mapOop = header & 4294967292U;
				} else {
					if (((longAt(fieldOop)) & 2147483648U) == 0) {
						lastIn += 4;
						if (lastIn >= hdrBaseIn) {
							successFlag = 0;
						}
						lastSeg = copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(fieldOop, segmentWordArray, lastSeg, firstIn, lastIn, hdrBaseIn + (lastIn - firstIn));
						if (!(successFlag)) {
							lastIn -= 4;
							restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
							/* begin primitiveFailAfterCleanup: */
							lastAddr1 = outPointerArray + (lastPointerOf(outPointerArray));
							i1 = outPointerArray + 4;
							while (i1 <= lastAddr1) {
								longAtput(i1, nilObj);
								i1 += 4;
							}
							;
							/* begin primitiveFail */
							successFlag = 0;
							return null;
						}
						mapOop = (longAt(fieldOop)) & 4294967292U;
					} else {
						lastOut += 4;
						if (lastOut >= hdrBaseOut) {
							lastOut -= 4;
							restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
							/* begin primitiveFailAfterCleanup: */
							lastAddr2 = outPointerArray + (lastPointerOf(outPointerArray));
							i2 = outPointerArray + 4;
							while (i2 <= lastAddr2) {
								longAtput(i2, nilObj);
								i2 += 4;
							}
							;
							/* begin primitiveFail */
							successFlag = 0;
							return null;
						}
						mapOop = (lastOut - outPointerArray) | 2147483648U;
						/* begin forward:to:savingOopAt:andHeaderAt: */
						longAtput(lastOut, fieldOop);
						longAtput(hdrBaseOut + (lastOut - firstOut), longAt(fieldOop));
						longAtput(fieldOop, mapOop + 2);
					}
				}
				if (doingClass) {
					longAtput(fieldPtr, mapOop + hdrTypeBits);
					fieldPtr += 8;
					doingClass = 0;
				} else {
					longAtput(fieldPtr, mapOop);
					fieldPtr += 4;
				}
			}
		}
		/* begin objectAfter: */
		;
		if (((longAt(segOop)) & 3) == 2) {
			sz = (longAt(segOop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(segOop);
			if ((header1 & 3) == 0) {
				sz = (longAt(segOop - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header1 & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(segOop + sz)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		segOop = (segOop + sz) + extra2;
	}
	restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
	if ((((outPointerArray + (lastPointerOf(outPointerArray))) - lastOut) < 12) || ((endSeg - lastSeg) < 12)) {
		/* begin primitiveFailAfterCleanup: */
		lastAddr3 = outPointerArray + (lastPointerOf(outPointerArray));
		i3 = outPointerArray + 4;
		while (i3 <= lastAddr3) {
			longAtput(i3, nilObj);
			i3 += 4;
		}
		;
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin extraHeaderBytes: */
	type = (longAt(segmentWordArray)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extraSize = extra1;

	/* Copy the 3-word wordArray header to establish a free chunk. */

	hdrTypeBits = (longAt(segmentWordArray)) & 3;
	/* begin transfer:from:to: */
	in = (segmentWordArray - extraSize) - 4;
	lastIn1 = in + (3 * 4);
	out = (lastOut + 4) - 4;
	while (in < lastIn1) {
		longAtput(out += 4, longAt(in += 4));
	}
	longAtput(lastOut + 4, (((outPointerArray + (lastPointerOf(outPointerArray))) - lastOut) - extraSize) + hdrTypeBits);
	longAtput(outPointerArray - extraSize, ((lastOut - firstOut) + 8) + hdrTypeBits);
	beRootIfOld(outPointerArray);
	/* begin transfer:from:to: */
	in1 = (segmentWordArray - extraSize) - 4;
	lastIn2 = in1 + (3 * 4);
	out1 = (lastSeg + 4) - 4;
	while (in1 < lastIn2) {
		longAtput(out1 += 4, longAt(in1 += 4));
	}
	longAtput(segmentWordArray - extraSize, ((lastSeg - segmentWordArray) + 4) + hdrTypeBits);
	longAtput(lastSeg + 4, ((endSeg - lastSeg) - extraSize) + hdrTypeBits);
	;
	/* begin pop: */
	stackPointer -= 3 * 4;
}


/*	Atomic store into context stackPointer.
	Also ensures that any newly accessible cells are initialized to nil */

int primitiveStoreStackp(void) {
    int stackp;
    int ctxt;
    int i;
    int newStackp;
    int valuePointer;
    int integerPointer;
    int sp;

	ctxt = longAt(stackPointer - (1 * 4));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		newStackp = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		newStackp = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin success: */
	successFlag = (newStackp >= 0) && successFlag;
	/* begin success: */
	successFlag = (newStackp <= ((((int) (252 - 4) >> 2)) - 6)) && successFlag;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin fetchStackPointerOf: */
	sp = longAt(((((char *) ctxt)) + 4) + (2 << 2));
	if (!((sp & 1))) {
		stackp = 0;
		goto l2;
	}
	stackp = (sp >> 1);
l2:	/* end fetchStackPointerOf: */;
	if (newStackp > stackp) {
		for (i = (stackp + 1); i <= newStackp; i += 1) {
			/* begin storePointer:ofObject:withValue: */
			valuePointer = nilObj;
			if (ctxt < youngStart) {
				possibleRootStoreIntovalue(ctxt, valuePointer);
			}
			longAtput(((((char *) ctxt)) + 4) + (((i + 6) - 1) << 2), valuePointer);
		}
	}
	/* begin storeStackPointerValue:inContext: */
	longAtput(((((char *) ctxt)) + 4) + (2 << 2), ((newStackp << 1) | 1));
	/* begin pop: */
	stackPointer -= 1 * 4;
}

int primitiveStringAt(void) {
	commonAt(1);
}

int primitiveStringAtPut(void) {
	commonAtPut(1);
}


/*	
<array> primReplaceFrom: start to: stop with: replacement startingAt: repStart 
	<primitive: 105>
 */

int primitiveStringReplace(void) {
    int hdr;
    int totalLength;
    int replFmt;
    int replInstSize;
    int array;
    int arrayInstSize;
    int i;
    int arrayFmt;
    int start;
    int stop;
    int srcIndex;
    int repl;
    int replStart;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int sz;
    int classFormat;
    int class;
    int sz1;
    int classFormat1;
    int class1;
    int ccIndex;
    int ccIndex1;

	array = longAt(stackPointer - (4 * 4));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (3 * 4));
	if ((integerPointer & 1)) {
		start = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		start = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		stop = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		stop = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	repl = longAt(stackPointer - (1 * 4));
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (0 * 4));
	if ((integerPointer2 & 1)) {
		replStart = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		replStart = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((repl & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	hdr = longAt(array);
	arrayFmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(array - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (arrayFmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l4;
	} else {
		totalLength = (sz - 4) - (arrayFmt & 3);
		goto l4;
	}
l4:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((arrayFmt > 4) || (arrayFmt == 2)) {
		arrayInstSize = 0;
		goto l5;
	}
	if (arrayFmt < 2) {
		arrayInstSize = totalLength;
		goto l5;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l8;
	}
	ccIndex = (((unsigned) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - 4)) & 4294967292U;
		goto l8;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l8;
	}
l8:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	arrayInstSize = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l5:	/* end fixedFieldsOf:format:length: */;
	if (!((start >= 1) && ((start <= stop) && ((stop + arrayInstSize) <= totalLength)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	hdr = longAt(repl);
	replFmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz1 = (longAt(repl - 8)) & 4294967292U;
	} else {
		sz1 = hdr & 252;
	}
	if (replFmt < 8) {
		totalLength = ((unsigned) (sz1 - 4)) >> 2;
		goto l6;
	} else {
		totalLength = (sz1 - 4) - (replFmt & 3);
		goto l6;
	}
l6:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((replFmt > 4) || (replFmt == 2)) {
		replInstSize = 0;
		goto l7;
	}
	if (replFmt < 2) {
		replInstSize = totalLength;
		goto l7;
	}
	/* begin fetchClassOf: */
	if ((repl & 1)) {
		class1 = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l9;
	}
	ccIndex1 = (((unsigned) (longAt(repl))) >> 12) & 31;
	if (ccIndex1 == 0) {
		class1 = (longAt(repl - 4)) & 4294967292U;
		goto l9;
	} else {
		class1 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
		goto l9;
	}
l9:	/* end fetchClassOf: */;
	classFormat1 = (longAt(((((char *) class1)) + 4) + (2 << 2))) - 1;
	replInstSize = (((((unsigned) classFormat1) >> 11) & 192) + ((((unsigned) classFormat1) >> 2) & 63)) - 1;
l7:	/* end fixedFieldsOf:format:length: */;
	if (!((replStart >= 1) && ((((stop - start) + replStart) + replInstSize) <= totalLength))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (arrayFmt < 8) {
		if (!(arrayFmt == replFmt)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	} else {
		if (!((arrayFmt & 12) == (replFmt & 12))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}

	/*  - 1 for 0-based access */

	srcIndex = (replStart + replInstSize) - 1;
	if (arrayFmt < 4) {
		for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
			/* begin storePointer:ofObject:withValue: */
			if (array < youngStart) {
				possibleRootStoreIntovalue(array, longAt(((((char *) repl)) + 4) + (srcIndex << 2)));
			}
			longAtput(((((char *) array)) + 4) + (i << 2), longAt(((((char *) repl)) + 4) + (srcIndex << 2)));
			srcIndex += 1;
		}
	} else {
		if (arrayFmt < 8) {
			for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
				longAtput(((((char *) array)) + 4) + (i << 2), longAt(((((char *) repl)) + 4) + (srcIndex << 2)));
				srcIndex += 1;
			}
		} else {
			for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
				byteAtput(((((char *) array)) + 4) + i, byteAt(((((char *) repl)) + 4) + srcIndex));
				srcIndex += 1;
			}
		}
	}
	/* begin pop: */
	stackPointer -= 4 * 4;
}

int primitiveSubtract(void) {
    int integerResult;
    int sp;

	/* begin pop2AndPushIntegerIfOK: */
	integerResult = (stackIntegerValue(1)) - (stackIntegerValue(0));
	if (successFlag) {
		if ((integerResult ^ (integerResult << 1)) >= 0) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * 4), ((integerResult << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}

int primitiveSuspend(void) {
    int activeProc;
    int sp;

	activeProc = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (1 << 2));
	/* begin success: */
	successFlag = ((longAt(stackPointer)) == activeProc) && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, nilObj);
		stackPointer = sp;
		transferTo(wakeHighestPriority());
	}
}


/*	Primitive. Terminate up the context stack from the receiver up to but not including the argument, if previousContext is on my Context stack. Make previousContext my sender. This prim has to shadow the code in ContextPart>terminateTo: to be correct */

int primitiveTerminateTo(void) {
    int aContext;
    int thisCntx;
    int currentCntx;
    int nilOop;
    int nextCntx;
    int top;
    int top1;
    int sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	aContext = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	thisCntx = top1;
	if (contexthasSender(thisCntx, aContext)) {
		nilOop = nilObj;
		currentCntx = longAt(((((char *) thisCntx)) + 4) + (0 << 2));
		while (!(currentCntx == aContext)) {
			nextCntx = longAt(((((char *) currentCntx)) + 4) + (0 << 2));
			/* begin storePointer:ofObject:withValue: */
			if (currentCntx < youngStart) {
				possibleRootStoreIntovalue(currentCntx, nilOop);
			}
			longAtput(((((char *) currentCntx)) + 4) + (0 << 2), nilOop);
			currentCntx = nextCntx;
		}
	}
	/* begin storePointer:ofObject:withValue: */
	if (thisCntx < youngStart) {
		possibleRootStoreIntovalue(thisCntx, aContext);
	}
	longAtput(((((char *) thisCntx)) + 4) + (0 << 2), aContext);
	/* begin push: */
	longAtput(sp = stackPointer + 4, thisCntx);
	stackPointer = sp;
	return null;
}


/*	Return true if the host OS does support the given display depth. */

int primitiveTestDisplayDepth(void) {
    int bitsPerPixel;
    int okay;
    int integerPointer;
    int sp;
    int sp1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		bitsPerPixel = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		bitsPerPixel = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		okay = ioHasDisplayDepth(bitsPerPixel);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (okay) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
	}
}

int primitiveTimesTwoPower(void) {
    double rcvr;
    int arg;
    int integerPointer;
    int top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top;
	if ((integerPointer & 1)) {
		arg = (integerPointer >> 1);
		goto l1;
	} else {
		successFlag = 0;
		arg = 1;
		goto l1;
	}
l1:	/* end popInteger */;
	rcvr = popFloat();
	if (successFlag) {
		pushFloat(ldexp(rcvr, arg));
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveTruncated(void) {
    double frac;
    double trunc;
    double rcvr;
    int integerValue;
    int sp;

	rcvr = popFloat();
	if (successFlag) {
		frac = modf(rcvr, &trunc);
		success((-1073741824.0 <= trunc) && (trunc <= 1073741823.0));
	}
	if (successFlag) {
		pushInteger((int) trunc);
	} else {
		/* begin unPop: */
		stackPointer += 1 * 4;
	}
}


/*	Primitive. Unload the module with the given name. */
/*	Reloading of the module will happen *later* automatically, when a 
	function from it is called. This is ensured by invalidating current sessionID. */

int primitiveUnloadModule(void) {
    int moduleName;

	if (!(argumentCount == 1)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	moduleName = longAt(stackPointer - (0 * 4));
	if ((moduleName & 1)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if (!(((((unsigned) (longAt(moduleName))) >> 8) & 15) >= 8)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if (!(ioUnloadModuleOfLength(((int) (firstIndexableField(moduleName))), byteSizeOf(moduleName)))) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	flushExternalPrimitives();
	/* begin pop: */
	stackPointer -= 1 * 4;
}


/*	Behaviour depends on argument count:
		0 args:	return an Array of VM parameter values;
		1 arg:	return the indicated VM parameter;
		2 args:	set the VM indicated parameter.
	VM parameters are numbered as follows:
		1	end of old-space (0-based, read-only)
		2	end of young-space (read-only)
		3	end of memory (read-only)
		4	allocationCount (read-only)
		5	allocations between GCs (read-write)
		6	survivor count tenuring threshold (read-write)
		7	full GCs since startup (read-only)
		8	total milliseconds in full GCs since startup (read-only)
		9	incremental GCs since startup (read-only)
		10	total milliseconds in incremental GCs since startup (read-only)
		11	tenures of surving objects since startup (read-only)
		12-20 specific to the translating VM
		21	root table size (read-only)
		22	root table overflows since startup (read-only)
		23	bytes of extra memory to reserve for VM buffers, plugins, etc.

		24	memory headroom when growing object memory (rw)
		25	memory threshold above which shrinking object memory (rw)

	Note: Thanks to Ian Piumarta for this primitive. */

int primitiveVMParameter(void) {
    int i;
    int result;
    int mem;
    int index;
    int paramsArraySize;
    int arg;
    int sp;
    int sp1;
    int sp2;

	mem = ((int) memory);
	;
	if (argumentCount == 0) {
		paramsArraySize = 25;
		result = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)), paramsArraySize);
		for (i = 0; i <= (paramsArraySize - 1); i += 1) {
			longAtput(((((char *) result)) + 4) + (i << 2), ((0 << 1) | 1));
		}
		longAtput(((((char *) result)) + 4) + (0 << 2), (((youngStart - mem) << 1) | 1));
		longAtput(((((char *) result)) + 4) + (1 << 2), (((freeBlock - mem) << 1) | 1));
		longAtput(((((char *) result)) + 4) + (2 << 2), (((endOfMemory - mem) << 1) | 1));
		longAtput(((((char *) result)) + 4) + (3 << 2), ((allocationCount << 1) | 1));
		longAtput(((((char *) result)) + 4) + (4 << 2), ((allocationsBetweenGCs << 1) | 1));
		longAtput(((((char *) result)) + 4) + (5 << 2), ((tenuringThreshold << 1) | 1));
		longAtput(((((char *) result)) + 4) + (6 << 2), ((statFullGCs << 1) | 1));
		longAtput(((((char *) result)) + 4) + (7 << 2), ((statFullGCMSecs << 1) | 1));
		longAtput(((((char *) result)) + 4) + (8 << 2), ((statIncrGCs << 1) | 1));
		longAtput(((((char *) result)) + 4) + (9 << 2), ((statIncrGCMSecs << 1) | 1));
		longAtput(((((char *) result)) + 4) + (10 << 2), ((statTenures << 1) | 1));
		longAtput(((((char *) result)) + 4) + (20 << 2), ((rootTableCount << 1) | 1));
		longAtput(((((char *) result)) + 4) + (21 << 2), ((statRootTableOverflows << 1) | 1));
		longAtput(((((char *) result)) + 4) + (22 << 2), ((extraVMMemory << 1) | 1));
		longAtput(((((char *) result)) + 4) + (23 << 2), ((shrinkThreshold << 1) | 1));
		longAtput(((((char *) result)) + 4) + (24 << 2), ((growHeadroom << 1) | 1));
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((1 - 1) * 4), result);
		stackPointer = sp;
		return null;
	}
	arg = longAt(stackPointer);
	if (!((arg & 1))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	arg = (arg >> 1);
	if (argumentCount == 1) {
		if ((arg < 1) || (arg > 25)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		if (arg == 1) {
			result = youngStart - mem;
		}
		if (arg == 2) {
			result = freeBlock - mem;
		}
		if (arg == 3) {
			result = endOfMemory - mem;
		}
		if (arg == 4) {
			result = allocationCount;
		}
		if (arg == 5) {
			result = allocationsBetweenGCs;
		}
		if (arg == 6) {
			result = tenuringThreshold;
		}
		if (arg == 7) {
			result = statFullGCs;
		}
		if (arg == 8) {
			result = statFullGCMSecs;
		}
		if (arg == 9) {
			result = statIncrGCs;
		}
		if (arg == 10) {
			result = statIncrGCMSecs;
		}
		if (arg == 11) {
			result = statTenures;
		}
		if ((arg >= 12) && (arg <= 20)) {
			result = 0;
		}
		if (arg == 21) {
			result = rootTableCount;
		}
		if (arg == 22) {
			result = statRootTableOverflows;
		}
		if (arg == 23) {
			result = extraVMMemory;
		}
		if (arg == 24) {
			result = shrinkThreshold;
		}
		if (arg == 25) {
			result = growHeadroom;
		}
		/* begin pop:thenPush: */
		longAtput(sp1 = stackPointer - ((2 - 1) * 4), ((result << 1) | 1));
		stackPointer = sp1;
		return null;
	}
	if (!(argumentCount == 2)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	index = longAt(stackPointer - (1 * 4));
	if (!((index & 1))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	index = (index >> 1);
	if (index <= 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	successFlag = 0;
	if (index == 5) {
		result = allocationsBetweenGCs;
		allocationsBetweenGCs = arg;
		successFlag = 1;
	}
	if (index == 6) {
		result = tenuringThreshold;
		tenuringThreshold = arg;
		successFlag = 1;
	}
	if (index == 23) {
		result = extraVMMemory;
		extraVMMemory = arg;
		successFlag = 1;
	}
	if (index == 24) {
		result = shrinkThreshold;
		if (arg > 0) {
			shrinkThreshold = arg;
			successFlag = 1;
		}
	}
	if (index == 25) {
		result = growHeadroom;
		if (arg > 0) {
			growHeadroom = arg;
			successFlag = 1;
		}
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp2 = stackPointer - ((3 - 1) * 4), ((result << 1) | 1));
		stackPointer = sp2;
		return null;
	}
	/* begin primitiveFail */
	successFlag = 0;
}


/*	Return a string containing the path name of VM's directory. */

int primitiveVMPath(void) {
    int s;
    int sz;
    int sp;

	sz = vmPathSize();
	s = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), sz);
	vmPathGetLength(s + 4, sz);
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, s);
	stackPointer = sp;
}

int primitiveValue(void) {
    int blockArgumentCount;
    int blockContext;
    int initialIP;
    int fromIndex;
    int toIndex;
    int lastFrom;
    int successValue;
    int tmp;
    int localArgCount;

	blockContext = longAt(stackPointer - (argumentCount * 4));
	/* begin argumentCountOfBlock: */
	localArgCount = longAt(((((char *) blockContext)) + 4) + (3 << 2));
	if ((localArgCount & 1)) {
		blockArgumentCount = (localArgCount >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		blockArgumentCount = 0;
		goto l1;
	}
l1:	/* end argumentCountOfBlock: */;
	/* begin success: */
	successValue = (argumentCount == blockArgumentCount) && ((longAt(((((char *) blockContext)) + 4) + (0 << 2))) == nilObj);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
		fromIndex = activeContext + ((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - argumentCount) + 1) * 4);
		toIndex = blockContext + (6 * 4);
		lastFrom = fromIndex + (argumentCount * 4);
		while (fromIndex < lastFrom) {
			fromIndex += 4;
			toIndex += 4;
			longAtput(toIndex, longAt(fromIndex));
		}
		/* begin pop: */
		stackPointer -= (argumentCount + 1) * 4;
		initialIP = longAt(((((char *) blockContext)) + 4) + (4 << 2));
		longAtput(((((char *) blockContext)) + 4) + (1 << 2), initialIP);
		/* begin storeStackPointerValue:inContext: */
		longAtput(((((char *) blockContext)) + 4) + (2 << 2), ((argumentCount << 1) | 1));
		longAtput(((((char *) blockContext)) + 4) + (0 << 2), activeContext);
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
		longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
		if (blockContext < youngStart) {
			beRootIfOld(blockContext);
		}
		activeContext = blockContext;
		/* begin fetchContextRegisters: */
		tmp = longAt(((((char *) blockContext)) + 4) + (3 << 2));
		if ((tmp & 1)) {
			tmp = longAt(((((char *) blockContext)) + 4) + (5 << 2));
			if (tmp < youngStart) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = blockContext;
		}
		theHomeContext = tmp;
		receiver = longAt(((((char *) tmp)) + 4) + (5 << 2));
		method = longAt(((((char *) tmp)) + 4) + (3 << 2));
		tmp = ((longAt(((((char *) blockContext)) + 4) + (1 << 2))) >> 1);
		instructionPointer = ((method + tmp) + 4) - 2;
		tmp = ((longAt(((((char *) blockContext)) + 4) + (2 << 2))) >> 1);
		stackPointer = (blockContext + 4) + (((6 + tmp) - 1) * 4);
	}
}

int primitiveValueWithArgs(void) {
    int argumentArray;
    int blockArgumentCount;
    int arrayArgumentCount;
    int blockContext;
    int initialIP;
    int sz;
    int successValue;
    int fromIndex;
    int toIndex;
    int lastFrom;
    int top;
    int top1;
    int header;
    int tmp;
    int localArgCount;
    int cl;
    int ccIndex;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	argumentArray = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	blockContext = top1;
	/* begin argumentCountOfBlock: */
	localArgCount = longAt(((((char *) blockContext)) + 4) + (3 << 2));
	if ((localArgCount & 1)) {
		blockArgumentCount = (localArgCount >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		blockArgumentCount = 0;
		goto l2;
	}
l2:	/* end argumentCountOfBlock: */;
	/* begin assertClassOf:is: */
	if ((argumentArray & 1)) {
		successFlag = 0;
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(argumentArray))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(argumentArray - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))) && successFlag;
l3:	/* end assertClassOf:is: */;
	if (successFlag) {
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(argumentArray);
		if ((header & 3) == 0) {
			sz = (longAt(argumentArray - 8)) & 4294967292U;
			goto l1;
		} else {
			sz = header & 252;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		arrayArgumentCount = ((unsigned) (sz - 4)) >> 2;
		/* begin success: */
		successValue = (arrayArgumentCount == blockArgumentCount) && ((longAt(((((char *) blockContext)) + 4) + (0 << 2))) == nilObj);
		successFlag = successValue && successFlag;
	}
	if (successFlag) {
		/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
		fromIndex = argumentArray + (0 * 4);
		toIndex = blockContext + (6 * 4);
		lastFrom = fromIndex + (arrayArgumentCount * 4);
		while (fromIndex < lastFrom) {
			fromIndex += 4;
			toIndex += 4;
			longAtput(toIndex, longAt(fromIndex));
		}
		initialIP = longAt(((((char *) blockContext)) + 4) + (4 << 2));
		longAtput(((((char *) blockContext)) + 4) + (1 << 2), initialIP);
		/* begin storeStackPointerValue:inContext: */
		longAtput(((((char *) blockContext)) + 4) + (2 << 2), ((arrayArgumentCount << 1) | 1));
		longAtput(((((char *) blockContext)) + 4) + (0 << 2), activeContext);
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
		longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
		if (blockContext < youngStart) {
			beRootIfOld(blockContext);
		}
		activeContext = blockContext;
		/* begin fetchContextRegisters: */
		tmp = longAt(((((char *) blockContext)) + 4) + (3 << 2));
		if ((tmp & 1)) {
			tmp = longAt(((((char *) blockContext)) + 4) + (5 << 2));
			if (tmp < youngStart) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = blockContext;
		}
		theHomeContext = tmp;
		receiver = longAt(((((char *) tmp)) + 4) + (5 << 2));
		method = longAt(((((char *) tmp)) + 4) + (3 << 2));
		tmp = ((longAt(((((char *) blockContext)) + 4) + (1 << 2))) >> 1);
		instructionPointer = ((method + tmp) + 4) - 2;
		tmp = ((longAt(((((char *) blockContext)) + 4) + (2 << 2))) >> 1);
		stackPointer = (blockContext + 4) + (((6 + tmp) - 1) * 4);
	} else {
		/* begin unPop: */
		stackPointer += 2 * 4;
	}
}

int primitiveWait(void) {
    int excessSignals;
    int sema;
    int activeProc;
    int lastLink;
    int cl;
    int ccIndex;


	/* rcvr */

	sema = longAt(stackPointer);
	/* begin assertClassOf:is: */
	if ((sema & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(sema))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(sema - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		excessSignals = fetchIntegerofObject(2, sema);
		if (excessSignals > 0) {
			/* begin storeInteger:ofObject:withValue: */
			if (((excessSignals - 1) ^ ((excessSignals - 1) << 1)) >= 0) {
				longAtput(((((char *) sema)) + 4) + (2 << 2), (((excessSignals - 1) << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
		} else {
			activeProc = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (1 << 2));
			/* begin addLastLink:toList: */
			if ((longAt(((((char *) sema)) + 4) + (0 << 2))) == nilObj) {
				/* begin storePointer:ofObject:withValue: */
				if (sema < youngStart) {
					possibleRootStoreIntovalue(sema, activeProc);
				}
				longAtput(((((char *) sema)) + 4) + (0 << 2), activeProc);
			} else {
				lastLink = longAt(((((char *) sema)) + 4) + (1 << 2));
				/* begin storePointer:ofObject:withValue: */
				if (lastLink < youngStart) {
					possibleRootStoreIntovalue(lastLink, activeProc);
				}
				longAtput(((((char *) lastLink)) + 4) + (0 << 2), activeProc);
			}
			/* begin storePointer:ofObject:withValue: */
			if (sema < youngStart) {
				possibleRootStoreIntovalue(sema, activeProc);
			}
			longAtput(((((char *) sema)) + 4) + (1 << 2), activeProc);
			/* begin storePointer:ofObject:withValue: */
			if (activeProc < youngStart) {
				possibleRootStoreIntovalue(activeProc, sema);
			}
			longAtput(((((char *) activeProc)) + 4) + (3 << 2), sema);
			transferTo(wakeHighestPriority());
		}
	}
}


/*	For testing in Smalltalk, this method should be overridden in a subclass. */

int print(char *s) {
	printf("%s", s);
}


/*	Print all the stacks of all running processes, including those that are currently suspended. */

int printAllStacks(void) {
    int proc;
    int oop;
    int ctx;
    int sz;
    int extra;
    int header;
    int extra1;
    int type;
    int chunk;
    int extra2;
    int extra11;
    int type1;

	proc = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (1 << 2));
	printNameOfClasscount(fetchClassOf(proc), 5);
	/* begin cr */
	printf("\n");
	printCallStackOf(activeContext);
	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type1 = (longAt(chunk)) & 3;
	if (type1 > 1) {
		extra11 = 0;
	} else {
		if (type1 == 1) {
			extra11 = 4;
		} else {
			extra11 = 8;
		}
	}
	extra2 = extra11;
	oop = chunk + extra2;
	while (oop < endOfMemory) {
		if ((fetchClassOf(oop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
			/* begin cr */
			printf("\n");
			proc = longAt(((((char *) oop)) + 4) + (0 << 2));
			while (!(proc == nilObj)) {
				printNameOfClasscount(fetchClassOf(proc), 5);
				/* begin cr */
				printf("\n");
				ctx = longAt(((((char *) proc)) + 4) + (1 << 2));
				if (!(ctx == nilObj)) {
					printCallStackOf(ctx);
				}
				proc = longAt(((((char *) proc)) + 4) + (0 << 2));
			}
		}
		/* begin objectAfter: */
		;
		if (((longAt(oop)) & 3) == 2) {
			sz = (longAt(oop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & 3) == 0) {
				sz = (longAt(oop - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type = (longAt(oop + sz)) & 3;
		if (type > 1) {
			extra1 = 0;
		} else {
			if (type == 1) {
				extra1 = 4;
			} else {
				extra1 = 8;
			}
		}
		extra = extra1;
		oop = (oop + sz) + extra;
	}
}

int printCallStack(void) {
	return printCallStackOf(activeContext);
}

int printCallStackOf(int aContext) {
    int home;
    int ctxt;
    int methClass;
    int methodSel;
    int classDict;
    int classDictSize;
    int i;
    int done;
    int methodArray;
    int currClass;
    int sz;
    int header;
    int ccIndex;
    int ccIndex1;
    int classDict1;
    int classDictSize1;
    int i1;
    int done1;
    int methodArray1;
    int currClass1;
    int sz1;
    int header1;
    int ccIndex2;

	ctxt = aContext;
	while (!(ctxt == nilObj)) {
		if ((fetchClassOf(ctxt)) == (longAt(((((char *) specialObjectsOop)) + 4) + (11 << 2)))) {
			home = longAt(((((char *) ctxt)) + 4) + (5 << 2));
		} else {
			home = ctxt;
		}
		/* begin findClassOfMethod:forReceiver: */
		/* begin fetchClassOf: */
		if (((longAt(((((char *) home)) + 4) + (5 << 2))) & 1)) {
			currClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l2;
		}
		ccIndex = (((unsigned) (longAt(longAt(((((char *) home)) + 4) + (5 << 2))))) >> 12) & 31;
		if (ccIndex == 0) {
			currClass = (longAt((longAt(((((char *) home)) + 4) + (5 << 2))) - 4)) & 4294967292U;
			goto l2;
		} else {
			currClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
			goto l2;
		}
	l2:	/* end fetchClassOf: */;
		done = 0;
		while (!(done)) {
			classDict = longAt(((((char *) currClass)) + 4) + (1 << 2));
			/* begin fetchWordLengthOf: */
			/* begin sizeBitsOf: */
			header = longAt(classDict);
			if ((header & 3) == 0) {
				sz = (longAt(classDict - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
			classDictSize = ((unsigned) (sz - 4)) >> 2;
			methodArray = longAt(((((char *) classDict)) + 4) + (1 << 2));
			i = 0;
			while (i < (classDictSize - 2)) {
				if ((longAt(((((char *) home)) + 4) + (3 << 2))) == (longAt(((((char *) methodArray)) + 4) + (i << 2)))) {
					methClass = currClass;
					goto l3;
				}
				i += 1;
			}
			currClass = longAt(((((char *) currClass)) + 4) + (0 << 2));
			done = currClass == nilObj;
		}
		/* begin fetchClassOf: */
		if (((longAt(((((char *) home)) + 4) + (5 << 2))) & 1)) {
			methClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l3;
		}
		ccIndex1 = (((unsigned) (longAt(longAt(((((char *) home)) + 4) + (5 << 2))))) >> 12) & 31;
		if (ccIndex1 == 0) {
			methClass = (longAt((longAt(((((char *) home)) + 4) + (5 << 2))) - 4)) & 4294967292U;
			goto l3;
		} else {
			methClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
			goto l3;
		}
		methClass = null;
	l3:	/* end findClassOfMethod:forReceiver: */;
		/* begin findSelectorOfMethod:forReceiver: */
		/* begin fetchClassOf: */
		if (((longAt(((((char *) home)) + 4) + (5 << 2))) & 1)) {
			currClass1 = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l5;
		}
		ccIndex2 = (((unsigned) (longAt(longAt(((((char *) home)) + 4) + (5 << 2))))) >> 12) & 31;
		if (ccIndex2 == 0) {
			currClass1 = (longAt((longAt(((((char *) home)) + 4) + (5 << 2))) - 4)) & 4294967292U;
			goto l5;
		} else {
			currClass1 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex2 - 1) << 2));
			goto l5;
		}
	l5:	/* end fetchClassOf: */;
		done1 = 0;
		while (!(done1)) {
			classDict1 = longAt(((((char *) currClass1)) + 4) + (1 << 2));
			/* begin fetchWordLengthOf: */
			/* begin sizeBitsOf: */
			header1 = longAt(classDict1);
			if ((header1 & 3) == 0) {
				sz1 = (longAt(classDict1 - 8)) & 4294967292U;
				goto l4;
			} else {
				sz1 = header1 & 252;
				goto l4;
			}
		l4:	/* end sizeBitsOf: */;
			classDictSize1 = ((unsigned) (sz1 - 4)) >> 2;
			methodArray1 = longAt(((((char *) classDict1)) + 4) + (1 << 2));
			i1 = 0;
			while (i1 <= (classDictSize1 - 2)) {
				if ((longAt(((((char *) home)) + 4) + (3 << 2))) == (longAt(((((char *) methodArray1)) + 4) + (i1 << 2)))) {
					methodSel = longAt(((((char *) classDict1)) + 4) + ((i1 + 2) << 2));
					goto l6;
				}
				i1 += 1;
			}
			currClass1 = longAt(((((char *) currClass1)) + 4) + (0 << 2));
			done1 = currClass1 == nilObj;
		}
		methodSel = longAt(((((char *) specialObjectsOop)) + 4) + (20 << 2));
	l6:	/* end findSelectorOfMethod:forReceiver: */;
		printNum(ctxt);
		print(" ");
		if (!(ctxt == home)) {
			print("[] in ");
		}
		printNameOfClasscount(methClass, 5);
		print(">");
		printStringOf(methodSel);
		/* begin cr */
		printf("\n");
		ctxt = longAt(((((char *) ctxt)) + 4) + (0 << 2));
	}
}


/*	Details: The count argument is used to avoid a possible infinite recursion if classOop is a corrupted object. */

int printNameOfClasscount(int classOop, int cnt) {
	if (cnt <= 0) {
		return print("bad class");
	}
	if ((sizeBitsOf(classOop)) == 28) {
		printNameOfClasscount(longAt(((((char *) classOop)) + 4) + (5 << 2)), cnt - 1);
		print(" class");
	} else {
		printStringOf(longAt(((((char *) classOop)) + 4) + (6 << 2)));
	}
}


/*	For testing in Smalltalk, this method should be overridden in a subclass. */

int printNum(int n) {
	printf("%ld", (long) n);
}

int printStringOf(int oop) {
    int i;
    int cnt;
    int fmt;

	if ((oop & 1)) {
		return null;
	}
	fmt = (((unsigned) (longAt(oop))) >> 8) & 15;
	if (fmt < 8) {
		return null;
	}
	cnt = ((100 < (lengthOf(oop))) ? 100 : (lengthOf(oop)));
	i = 0;
	while (i < cnt) {
		/* begin printChar: */
//		putchar(byteAt(((((char *) oop)) + 4) + i));
		printf("%c", byteAt(((((char *) oop)) + 4) + i));
		i += 1;
	}
}

int printUnbalancedStack(int primIdx) {
	print("Stack unbalanced after ");
	if (successFlag) {
		print("successful primitive ");
	} else {
		print("failed primitive ");
	}
	printNum(primIdx);
	/* begin cr */
	printf("\n");
}

int printUnbalancedStackFromNamedPrimitive(void) {
    int lit;

	print("Stack unbalanced after ");
	if (successFlag) {
		print("successful ");
	} else {
		print("failed ");
	}
	lit = longAt(((((char *) newMethod)) + 4) + ((0 + 1) << 2));
	printStringOf(longAt(((((char *) lit)) + 4) + (1 << 2)));
	print(" in ");
	printStringOf(longAt(((((char *) lit)) + 4) + (0 << 2)));
	/* begin cr */
	printf("\n");
}

int push(int object) {
    int sp;

	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
}

int pushBool(int trueOrFalse) {
    int sp;
    int sp1;

	if (trueOrFalse) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	}
}

int pushFloat(double f) {
    int object;
    int sp;

	/* begin push: */
	object = floatObjectOf(f);
	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
}

int pushInteger(int integerValue) {
    int sp;

	/* begin push: */
	longAtput(sp = stackPointer + 4, ((integerValue << 1) | 1));
	stackPointer = sp;
}


/*	Record the given object in a the remap buffer. Objects in this buffer are remapped when a compaction occurs. This facility is used by the interpreter to ensure that objects in temporary variables are properly remapped. */

int pushRemappableOop(int oop) {
	remapBuffer[remapBufferCount += 1] = oop;
}


/*	Append the given 4-byte long word to the given file in this platforms 'natural' byte order. (Bytes will be swapped, if necessary, when the image is read on a different platform.) Set successFlag to false if the write fails. */

int putLongtoFile(int n, sqImageFile f) {
    int wordsWritten;

	wordsWritten = sqImageFileWrite(&n, sizeof(int), 1, f);
	/* begin success: */
	successFlag = (wordsWritten == 1) && successFlag;
}


/*	Read an image from the given file stream, allocating the given amount of memory to its object heap. Fail if the image has an unknown format or requires more than the given amount of memory. */
/*	Details: This method detects when the image was stored on a machine with the opposite byte ordering from this machine and swaps the bytes automatically. Furthermore, it allows the header information to start 512 bytes into the file, since some file transfer programs for the Macintosh apparently prepend a Mac-specific header of this size. Note that this same 512 bytes of prefix area could also be used to store an exec command on Unix systems, allowing one to launch Smalltalk by invoking the image name as a command. */
/*	This code is based on C code by Ian Piumarta and Smalltalk code by Tim Rowledge. Many thanks to both of you!! */

int readImageFromFileHeapSizeStartingAt(sqImageFile f, int desiredHeapSize, squeakFileOffsetType imageOffset) {
    int memStart;
    int heapSize;
    int swapBytes;
    int bytesRead;
    int oldBaseAddr;
    int headerSize;
    int minimumMemory;
    squeakFileOffsetType headerStart;
    int bytesToShift;
    size_t dataSize;
    int i;
    int startAddr;
    int addr;
    int proc;
    int sched;
    int activeCntx;
    int tmp;

	swapBytes = checkImageVersionFromstartingAt(f, imageOffset);

	/* record header start position */

	headerStart = (sqImageFilePosition(f)) - 4;
	headerSize = getLongFromFileswap(f, swapBytes);
	dataSize = getLongFromFileswap(f, swapBytes);
	oldBaseAddr = getLongFromFileswap(f, swapBytes);
	specialObjectsOop = getLongFromFileswap(f, swapBytes);
	lastHash = getLongFromFileswap(f, swapBytes);
	savedWindowSize = getLongFromFileswap(f, swapBytes);
	fullScreenFlag = getLongFromFileswap(f, swapBytes);
	extraVMMemory = getLongFromFileswap(f, swapBytes);
	if (lastHash == 0) {
		lastHash = 999;
	}
	heapSize = reserveExtraCHeapBytes(desiredHeapSize, extraVMMemory);

	/* need at least 100K of breathing room */

	minimumMemory = dataSize + 100000;
	if (heapSize < minimumMemory) {
				error("Insufficient memory for this image");
;
	}
	memory = (unsigned char *) sqAllocateMemory(minimumMemory, heapSize);
	if (memory == null) {
				error("Failed to allocate memory for the heap");
;
	}
	memStart = startOfMemory();

	/* decrease memoryLimit a tad for safety */

	memoryLimit = (memStart + heapSize) - 24;

	/* position file after the header */

	endOfMemory = memStart + dataSize;
	sqImageFileSeek(f, headerStart + headerSize);
	bytesRead = sqImageFileRead(memory, sizeof(unsigned char), dataSize, f);
	if (bytesRead != dataSize) {
				error("Read failed or premature end of image file");
;
	}
	if (swapBytes) {
		/* begin reverseBytesInImage */
		/* begin reverseBytesFrom:to: */
		startAddr = startOfMemory();
		addr = startAddr;
		while (addr < endOfMemory) {
			longAtput(addr, ((((((unsigned) (longAt(addr)) >> 24)) & 255) + ((((unsigned) (longAt(addr)) >> 8)) & 65280)) + ((((unsigned) (longAt(addr)) << 8)) & 16711680)) + ((((unsigned) (longAt(addr)) << 24)) & 4278190080U));
			addr += 4;
		}
		/* begin byteSwapByteObjects */
		byteSwapByteObjectsFromto(oopFromChunk(startOfMemory()), endOfMemory);
	}
	bytesToShift = memStart - oldBaseAddr;
	/* begin initializeInterpreter: */
	interpreterProxy = sqGetInterpreterProxy();
	initializeObjectMemory(bytesToShift);
	initCompilerHooks();
	flushExternalPrimitives();
	activeContext = nilObj;
	theHomeContext = nilObj;
	method = nilObj;
	receiver = nilObj;
	messageSelector = nilObj;
	newMethod = nilObj;
	methodClass = nilObj;
	lkupClass = nilObj;
	receiverClass = nilObj;
	newNativeMethod = nilObj;
	/* begin flushMethodCache */
	for (i = 1; i <= 4096; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= 64; i += 1) {
		atCache[i] = 0;
	}
	/* begin loadInitialContext */
	sched = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2));
	proc = longAt(((((char *) sched)) + 4) + (1 << 2));
	activeContext = longAt(((((char *) proc)) + 4) + (1 << 2));
	if (activeContext < youngStart) {
		beRootIfOld(activeContext);
	}
	/* begin fetchContextRegisters: */
	activeCntx = activeContext;
	tmp = longAt(((((char *) activeCntx)) + 4) + (3 << 2));
	if ((tmp & 1)) {
		tmp = longAt(((((char *) activeCntx)) + 4) + (5 << 2));
		if (tmp < youngStart) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx;
	}
	theHomeContext = tmp;
	receiver = longAt(((((char *) tmp)) + 4) + (5 << 2));
	method = longAt(((((char *) tmp)) + 4) + (3 << 2));
	tmp = ((longAt(((((char *) activeCntx)) + 4) + (1 << 2))) >> 1);
	instructionPointer = ((method + tmp) + 4) - 2;
	tmp = ((longAt(((((char *) activeCntx)) + 4) + (2 << 2))) >> 1);
	stackPointer = (activeCntx + 4) + (((6 + tmp) - 1) * 4);
	reclaimableContextCount = 0;
	interruptCheckCounter = 0;
	interruptCheckCounterFeedBackReset = 1000;
	interruptChecksEveryNms = 3;
	nextPollTick = 0;
	nextWakeupTick = 0;
	lastTick = 0;
	interruptKeycode = 2094;
	interruptPending = 0;
	semaphoresUseBufferA = 1;
	semaphoresToSignalCountA = 0;
	semaphoresToSignalCountB = 0;
	deferDisplayUpdates = 0;
	pendingFinalizationSignals = 0;
	return dataSize;
}


/*	Anwer true if images of the given format are readable by this interpreter. Allows a virtual machine to accept selected older image formats. */

int readableFormat(int imageVersion) {
	return imageVersion == 6502;
}


/*	Map the given oop to its new value during a compaction or become: operation. If it has no forwarding table entry, return the oop itself. */

int remap(int oop) {
    int fwdBlock;

	if (((oop & 1) == 0) && (((longAt(oop)) & 2147483648U) != 0)) {
		fwdBlock = ((longAt(oop)) & 2147483644) << 1;
		;
		return longAt(fwdBlock);
	}
	return oop;
}


/*	Remove the first process from the given linked list. */

int removeFirstLinkOfList(int aList) {
    int last;
    int first;
    int next;
    int valuePointer;
    int valuePointer1;
    int valuePointer2;

	first = longAt(((((char *) aList)) + 4) + (0 << 2));
	last = longAt(((((char *) aList)) + 4) + (1 << 2));
	if (first == last) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = nilObj;
		if (aList < youngStart) {
			possibleRootStoreIntovalue(aList, valuePointer);
		}
		longAtput(((((char *) aList)) + 4) + (0 << 2), valuePointer);
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = nilObj;
		if (aList < youngStart) {
			possibleRootStoreIntovalue(aList, valuePointer1);
		}
		longAtput(((((char *) aList)) + 4) + (1 << 2), valuePointer1);
	} else {
		next = longAt(((((char *) first)) + 4) + (0 << 2));
		/* begin storePointer:ofObject:withValue: */
		if (aList < youngStart) {
			possibleRootStoreIntovalue(aList, next);
		}
		longAtput(((((char *) aList)) + 4) + (0 << 2), next);
	}
	/* begin storePointer:ofObject:withValue: */
	valuePointer2 = nilObj;
	if (first < youngStart) {
		possibleRootStoreIntovalue(first, valuePointer2);
	}
	longAtput(((((char *) first)) + 4) + (0 << 2), valuePointer2);
	return first;
}


/*	Restore headers smashed by forwarding links */

int restoreHeadersFromtofromandtofrom(int firstIn, int lastIn, int hdrBaseIn, int firstOut, int lastOut, int hdrBaseOut) {
    int header;
    int oop;
    int tablePtr;
    int chunk;
    int extra;
    int extra1;
    int type;
    int sz;
    int extra2;
    int header1;
    int extra11;
    int type1;

	tablePtr = firstIn;
	while (tablePtr <= lastIn) {
		oop = longAt(tablePtr);
		header = longAt(hdrBaseIn + (tablePtr - firstIn));
		longAtput(oop, header);
		tablePtr += 4;
	}
	tablePtr = firstOut;
	while (tablePtr <= lastOut) {
		oop = longAt(tablePtr);
		header = longAt(hdrBaseOut + (tablePtr - firstOut));
		longAtput(oop, header);
		tablePtr += 4;
	}
	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	oop = chunk + extra;
	while (oop < endOfMemory) {
		if (!(((longAt(oop)) & 3) == 2)) {
			longAtput(oop, (longAt(oop)) & 2147483647U);
		}
		/* begin objectAfter: */
		;
		if (((longAt(oop)) & 3) == 2) {
			sz = (longAt(oop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(oop);
			if ((header1 & 3) == 0) {
				sz = (longAt(oop - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header1 & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(oop + sz)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		oop = (oop + sz) + extra2;
	}
}

int resume(int aProcess) {
    int newPriority;
    int activeProc;
    int activePriority;
    int priority;
    int processList;
    int processLists;
    int lastLink;
    int priority1;
    int processList1;
    int processLists1;
    int lastLink1;

	activeProc = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (1 << 2));
	activePriority = ((longAt(((((char *) activeProc)) + 4) + (2 << 2))) >> 1);
	newPriority = ((longAt(((((char *) aProcess)) + 4) + (2 << 2))) >> 1);
	if (newPriority > activePriority) {
		/* begin putToSleep: */
		priority = ((longAt(((((char *) activeProc)) + 4) + (2 << 2))) >> 1);
		processLists = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (0 << 2));
		processList = longAt(((((char *) processLists)) + 4) + ((priority - 1) << 2));
		/* begin addLastLink:toList: */
		if ((longAt(((((char *) processList)) + 4) + (0 << 2))) == nilObj) {
			/* begin storePointer:ofObject:withValue: */
			if (processList < youngStart) {
				possibleRootStoreIntovalue(processList, activeProc);
			}
			longAtput(((((char *) processList)) + 4) + (0 << 2), activeProc);
		} else {
			lastLink = longAt(((((char *) processList)) + 4) + (1 << 2));
			/* begin storePointer:ofObject:withValue: */
			if (lastLink < youngStart) {
				possibleRootStoreIntovalue(lastLink, activeProc);
			}
			longAtput(((((char *) lastLink)) + 4) + (0 << 2), activeProc);
		}
		/* begin storePointer:ofObject:withValue: */
		if (processList < youngStart) {
			possibleRootStoreIntovalue(processList, activeProc);
		}
		longAtput(((((char *) processList)) + 4) + (1 << 2), activeProc);
		/* begin storePointer:ofObject:withValue: */
		if (activeProc < youngStart) {
			possibleRootStoreIntovalue(activeProc, processList);
		}
		longAtput(((((char *) activeProc)) + 4) + (3 << 2), processList);
		transferTo(aProcess);
	} else {
		/* begin putToSleep: */
		priority1 = ((longAt(((((char *) aProcess)) + 4) + (2 << 2))) >> 1);
		processLists1 = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (0 << 2));
		processList1 = longAt(((((char *) processLists1)) + 4) + ((priority1 - 1) << 2));
		/* begin addLastLink:toList: */
		if ((longAt(((((char *) processList1)) + 4) + (0 << 2))) == nilObj) {
			/* begin storePointer:ofObject:withValue: */
			if (processList1 < youngStart) {
				possibleRootStoreIntovalue(processList1, aProcess);
			}
			longAtput(((((char *) processList1)) + 4) + (0 << 2), aProcess);
		} else {
			lastLink1 = longAt(((((char *) processList1)) + 4) + (1 << 2));
			/* begin storePointer:ofObject:withValue: */
			if (lastLink1 < youngStart) {
				possibleRootStoreIntovalue(lastLink1, aProcess);
			}
			longAtput(((((char *) lastLink1)) + 4) + (0 << 2), aProcess);
		}
		/* begin storePointer:ofObject:withValue: */
		if (processList1 < youngStart) {
			possibleRootStoreIntovalue(processList1, aProcess);
		}
		longAtput(((((char *) processList1)) + 4) + (1 << 2), aProcess);
		/* begin storePointer:ofObject:withValue: */
		if (aProcess < youngStart) {
			possibleRootStoreIntovalue(aProcess, processList1);
		}
		longAtput(((((char *) aProcess)) + 4) + (3 << 2), processList1);
	}
}


/*	Reverse the given range of Display words (at different bit depths, this will reverse different numbers of pixels). Used to give feedback during VM activities such as garbage collection when debugging. It is assumed that the given word range falls entirely within the first line of the Display. */

int reverseDisplayFromto(int startIndex, int endIndex) {
    int ptr;
    int reversed;
    int dispBitsPtr;
    int w;
    int displayObj;

	displayObj = longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
	if (!((((((unsigned) (longAt(displayObj))) >> 8) & 15) <= 4) && ((lengthOf(displayObj)) >= 4))) {
		return null;
	}
	w = fetchIntegerofObject(1, displayObj);
	dispBitsPtr = longAt(((((char *) displayObj)) + 4) + (0 << 2));
	if ((dispBitsPtr & 1)) {
		return null;
	}
	dispBitsPtr += 4;
	for (ptr = (dispBitsPtr + (startIndex * 4)); ptr <= (dispBitsPtr + (endIndex * 4)); ptr += 4) {
		reversed = (longAt(ptr)) ^ 4294967295U;
		longAtput(ptr, reversed);
	}
	displayBitsOfLeftTopRightBottom(displayObj, 0, 0, w, 1);
	ioForceDisplayUpdate();
}


/*	Rewrite an existing entry in the method cache with a new primitive   
	index. */

int rewriteMethodCacheSelclassprimIndex(int selector, int class, int localPrimIndex) {
    int hash;
    int probe;
    int p;

	hash = selector ^ class;
	for (p = 0; p <= (3 - 1); p += 1) {
		probe = (((unsigned) hash) >> p) & 4088;
		if (((methodCache[probe + 1]) == selector) && ((methodCache[probe + 2]) == class)) {
			methodCache[probe + 4] = localPrimIndex;
			return null;
		}
	}
}

int setCompilerInitialized(int newFlag) {
    int oldFlag;

	oldFlag = compilerInitialized;
	compilerInitialized = newFlag;
	return oldFlag;
}


/*	Repaint the portion of the Smalltalk screen bounded by the affected rectangle. Used to synchronize the screen after a Bitblt to the Smalltalk Display object. */

int showDisplayBitsLeftTopRightBottom(int aForm, int l, int t, int r, int b) {
	if (deferDisplayUpdates) {
		return null;
	}
	displayBitsOfLeftTopRightBottom(aForm, l, t, r, b);
}


/*	Record the given semaphore index in the double buffer semaphores array to be signaled at the next convenient moment. Set the interruptCheckCounter to zero to force a real interrupt check as soon as possible. */

int signalSemaphoreWithIndex(int index) {
	if (index <= 0) {
		return null;
	}
	if (semaphoresUseBufferA) {
		if (semaphoresToSignalCountA < 500) {
			semaphoresToSignalCountA += 1;
			semaphoresToSignalA[semaphoresToSignalCountA] = index;
		}
	} else {
		if (semaphoresToSignalCountB < 500) {
			semaphoresToSignalCountB += 1;
			semaphoresToSignalB[semaphoresToSignalCountB] = index;
		}
	}
	interruptCheckCounter = 0;
}


/*	Return a full 32 bit integer object for the given integer value */

int signed32BitIntegerFor(int integerValue) {
    int value;
    int largeClass;
    int newLargeInteger;

	if ((integerValue ^ (integerValue << 1)) >= 0) {
		return ((integerValue << 1) | 1);
	}
	if (integerValue < 0) {
		largeClass = longAt(((((char *) specialObjectsOop)) + 4) + (42 << 2));
		value = 0 - integerValue;
	} else {
		largeClass = longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2));
		value = integerValue;
	}
	newLargeInteger = instantiateClassindexableSize(largeClass, 4);
	byteAtput(((((char *) newLargeInteger)) + 4) + 3, (((unsigned) value) >> 24) & 255);
	byteAtput(((((char *) newLargeInteger)) + 4) + 2, (((unsigned) value) >> 16) & 255);
	byteAtput(((((char *) newLargeInteger)) + 4) + 1, (((unsigned) value) >> 8) & 255);
	byteAtput(((((char *) newLargeInteger)) + 4) + 0, value & 255);
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a four-byte LargeInteger. */

int signed32BitValueOf(int oop) {
    int value;
    int negative;
    int sz;
    int largeClass;
    int ccIndex;
    int header;
    int sz1;

	if ((oop & 1)) {
		return (oop >> 1);
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		largeClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		largeClass = (longAt(oop - 4)) & 4294967292U;
		goto l1;
	} else {
		largeClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if (largeClass == (longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2)))) {
		negative = 0;
	} else {
		if (largeClass == (longAt(((((char *) specialObjectsOop)) + 4) + (42 << 2)))) {
			negative = 1;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz1 = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz1 = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		sz = ((unsigned) (sz1 - 4)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	if (!(sz == 4)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = (((byteAt(((((char *) oop)) + 4) + 0)) + ((byteAt(((((char *) oop)) + 4) + 1)) << 8)) + ((byteAt(((((char *) oop)) + 4) + 2)) << 16)) + ((byteAt(((((char *) oop)) + 4) + 3)) << 24);
	if (negative) {
		return 0 - value;
	} else {
		return value;
	}
}


/*	Return a Large Integer object for the given integer value */

int signed64BitIntegerFor(squeakInt64 integerValue) {
    int i;
    int check;
    squeakInt64 value;
    int intValue;
    int largeClass;
    int newLargeInteger;

	if (integerValue < 0) {
		largeClass = longAt(((((char *) specialObjectsOop)) + 4) + (42 << 2));
		value = 0 - integerValue;
	} else {
		largeClass = longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2));
		value = integerValue;
	}
	if ((sizeof(value)) == 4) {
		return signed32BitIntegerFor(integerValue);
	}
	check = value >> 32;
	if (check == 0) {
		return signed32BitIntegerFor(integerValue);
	}
	newLargeInteger = instantiateSmallClasssizeInBytesfill(largeClass, 12, 0);
	for (i = 0; i <= 7; i += 1) {
		intValue = ( value >> (i * 8)) & 255;
		byteAtput(((((char *) newLargeInteger)) + 4) + i, intValue);
	}
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a eight-byte LargeInteger. */

squeakInt64 signed64BitValueOf(int oop) {
    int i;
    squeakInt64 value;
    int szsqueakInt64;
    int negative;
    int sz;
    int largeClass;
    int ccIndex;
    int header;
    int sz1;

	if ((oop & 1)) {
		return ((squeakInt64) ((oop >> 1)));
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		largeClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		largeClass = (longAt(oop - 4)) & 4294967292U;
		goto l1;
	} else {
		largeClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if (largeClass == (longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2)))) {
		negative = 0;
	} else {
		if (largeClass == (longAt(((((char *) specialObjectsOop)) + 4) + (42 << 2)))) {
			negative = 1;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	szsqueakInt64 = sizeof(squeakInt64);
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz1 = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz1 = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		sz = ((unsigned) (sz1 - 4)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	if (sz > szsqueakInt64) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = 0;
	for (i = 0; i <= (sz - 1); i += 1) {
		value += (((squeakInt64) (byteAt(((((char *) oop)) + 4) + i)))) << (i * 8);
	}
	if (negative) {
		return 0 - value;
	} else {
		return value;
	}
}


/*	Answer the number of bytes in the given object, including its base header, rounded up to an integral number of words. */
/*	Note: byte indexable objects need to have low bits subtracted from this size. */

int sizeBitsOf(int oop) {
    int header;

	header = longAt(oop);
	if ((header & 3) == 0) {
		return (longAt(oop - 8)) & 4294967292U;
	} else {
		return header & 252;
	}
}


/*	Return the number of indexable fields of the given object. This method is to be called from an automatically generated C primitive. The argument is assumed to be a pointer to the first indexable field of a words or bytes object; the object header start 4 bytes before that. */
/*	Note: Only called by translated primitive code. */

int sizeOfSTArrayFromCPrimitive(void *cPtr) {
    int oop;
    int header;
    int sz;

	oop = ((int) cPtr) - 4;
	if (!(isWordsOrBytes(oop))) {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		return ((unsigned) (sz - 4)) >> 2;
	} else {
		return (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
	}
	return null;
}


/*	Returns the number of slots in the receiver.
	If the receiver is a byte object, return the number of bytes.
	Otherwise return the number of words. */

int slotSizeOf(int oop) {
    int header;
    int sz;

	if ((oop & 1)) {
		return 0;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		return ((unsigned) (sz - 4)) >> 2;
	} else {
		return (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
	}
	return null;
}


/*	Return one of the objects in the SpecialObjectsArray */

int splObj(int index) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (index << 2));
}


/*	Return what ST would return for <obj> at: index. */

int stObjectat(int array, int index) {
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int stSize;
    int sp;
    int sz;
    int classFormat;
    int class;
    int ccIndex;

	hdr = longAt(array);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(array - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l3;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l3;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l4;
	}
	ccIndex = (((unsigned) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - 4)) & 4294967292U;
		goto l4;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l4;
	}
l4:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l3:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) array)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			stSize = 0;
			goto l1;
		}
		stSize = (sp >> 1);
	l1:	/* end fetchStackPointerOf: */;
	} else {
		stSize = totalLength - fixedFields;
	}
	if (((((unsigned ) index)) >= 1) && ((((unsigned ) index)) <= (((unsigned ) stSize)))) {
		/* begin subscript:with:format: */
		if (fmt <= 4) {
			return longAt(((((char *) array)) + 4) + (((index + fixedFields) - 1) << 2));
		}
		if (fmt < 8) {
			return positive32BitIntegerFor(longAt(((((char *) array)) + 4) + (((index + fixedFields) - 1) << 2)));
		} else {
			return (((byteAt(((((char *) array)) + 4) + ((index + fixedFields) - 1))) << 1) | 1);
		}
		return null;
	} else {
		successFlag = 0;
		return 0;
	}
}


/*	Do what ST would return for <obj> at: index put: value. */

int stObjectatput(int array, int index, int value) {
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int stSize;
    int sp;
    int sz;
    int classFormat;
    int class;
    int valueToStore;
    int ccIndex;

	hdr = longAt(array);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(array - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l3;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l3;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l4;
	}
	ccIndex = (((unsigned) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - 4)) & 4294967292U;
		goto l4;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l4;
	}
l4:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l3:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) array)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			stSize = 0;
			goto l1;
		}
		stSize = (sp >> 1);
	l1:	/* end fetchStackPointerOf: */;
	} else {
		stSize = totalLength - fixedFields;
	}
	if (((((unsigned ) index)) >= 1) && ((((unsigned ) index)) <= (((unsigned ) stSize)))) {
		/* begin subscript:with:storing:format: */
		if (fmt <= 4) {
			/* begin storePointer:ofObject:withValue: */
			if (array < youngStart) {
				possibleRootStoreIntovalue(array, value);
			}
			longAtput(((((char *) array)) + 4) + (((index + fixedFields) - 1) << 2), value);
		} else {
			if (fmt < 8) {
				valueToStore = positive32BitValueOf(value);
				if (successFlag) {
					longAtput(((((char *) array)) + 4) + (((index + fixedFields) - 1) << 2), valueToStore);
				}
			} else {
				if (!((value & 1))) {
					successFlag = 0;
				}
				valueToStore = (value >> 1);
				if (!((valueToStore >= 0) && (valueToStore <= 255))) {
					successFlag = 0;
				}
				if (successFlag) {
					byteAtput(((((char *) array)) + 4) + ((index + fixedFields) - 1), valueToStore);
				}
			}
		}
	} else {
		successFlag = 0;
	}
}


/*	Return the number of indexable fields in the given object. (i.e., what Smalltalk would return for <obj> size). */
/*	Note: Assume oop is not a SmallInteger! */

int stSizeOf(int oop) {
    int hdr;
    int totalLength;
    int fixedFields;
    int fmt;
    int sp;
    int sz;
    int classFormat;
    int class;
    int ccIndex;

	hdr = longAt(oop);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l1;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l2;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l2;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l2:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) oop)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			return 0;
		}
		return (sp >> 1);
	} else {
		return totalLength - fixedFields;
	}
}


/*	Note: May be called by translated primitive code. */

double stackFloatValue(int offset) {
    double result;
    int floatPointer;

	floatPointer = longAt(stackPointer - (offset * 4));
	if (!((fetchClassOf(floatPointer)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return 0.0;
	}
	;
	fetchFloatAtinto(floatPointer + 4, result);
	return result;
}

int stackIntegerValue(int offset) {
    int integerPointer;

	integerPointer = longAt(stackPointer - (offset * 4));
	if ((integerPointer & 1)) {
		return (integerPointer >> 1);
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
}


/*	Ensures that the given object is a real object, not a SmallInteger. */

int stackObjectValue(int offset) {
    int oop;

	oop = longAt(stackPointer - (offset * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	return oop;
}

int stackValue(int offset) {
	return longAt(stackPointer - (offset * 4));
}


/*	Return the start of object memory. */

int startOfMemory(void) {
	return (int) memory;
}


/*	Note: May be called by translated primitive code. */

int storeIntegerofObjectwithValue(int fieldIndex, int objectPointer, int integerValue) {
	if ((integerValue ^ (integerValue << 1)) >= 0) {
		longAtput(((((char *) objectPointer)) + 4) + (fieldIndex << 2), ((integerValue << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
}


/*	Note must check here for stores of young objects into old ones. */

int storePointerofObjectwithValue(int fieldIndex, int oop, int valuePointer) {
	if (oop < youngStart) {
		possibleRootStoreIntovalue(oop, valuePointer);
	}
	return longAtput(((((char *) oop)) + 4) + (fieldIndex << 2), valuePointer);
}

int success(int successValue) {
	successFlag = successValue && successFlag;
}


/*	Return true if there is enough free space after doing a garbage collection. If not, signal that space is low. */

int sufficientSpaceAfterGC(int minFree) {
    int growSize;
    int limit;

	incrementalGC();
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) < (((unsigned ) minFree))) {
		if (signalLowSpace) {
			return 0;
		}
		fullGC();
		if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= ((((unsigned ) minFree)) + 15000)) {
			return 1;
		}
		growSize = (minFree - ((longAt(freeBlock)) & 4294967292U)) + growHeadroom;
		/* begin growObjectMemory: */
		limit = sqGrowMemoryBy(memoryLimit, growSize);
		if (!(limit == memoryLimit)) {
			memoryLimit = limit - 24;
			initializeMemoryFirstFree(freeBlock);
		}
		if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= ((((unsigned ) minFree)) + 15000)) {
			return 1;
		}
		return 0;
	}
	return 1;
}

int superclassOf(int classPointer) {
	return longAt(((((char *) classPointer)) + 4) + (0 << 2));
}


/*	Sweep memory from youngStart through the end of memory. Free all inaccessible objects and coalesce adjacent free chunks. Clear the mark bits of accessible objects. Compute the starting point for the first pass of incremental compaction (compStart). Return the number of surviving objects. */
/*	Details: Each time a non-free object is encountered, decrement the number of available forward table entries. If all entries are spoken for (i.e., entriesAvailable reaches zero), set compStart to the last free chunk before that object or, if there is no free chunk before the given object, the first free chunk after it. Thus, at the end of the sweep phase, compStart through compEnd spans the highest collection of non-free objects that can be accomodated by the forwarding table. This information is used by the first pass of incremental compaction to ensure that space is initially freed at the end of memory. Note that there should always be at least one free chunk--the one at the end of the heap. */

int sweepPhase(void) {
    int oopHeader;
    int hdrBytes;
    int entriesAvailable;
    int survivors;
    int firstFree;
    int freeChunk;
    int oop;
    int oopHeaderType;
    int oopSize;
    int freeChunkSize;
    int extra;
    int extra1;
    int type;
    int extra2;
    int extra11;
    int type1;

	entriesAvailable = fwdTableInit(8);
	survivors = 0;
	freeChunk = null;

	/* will be updated later */

	firstFree = null;
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type1 = (longAt(youngStart)) & 3;
	if (type1 > 1) {
		extra11 = 0;
	} else {
		if (type1 == 1) {
			extra11 = 4;
		} else {
			extra11 = 8;
		}
	}
	extra2 = extra11;
	oop = youngStart + extra2;
	while (oop < endOfMemory) {
		oopHeader = longAt(oop);
		oopHeaderType = oopHeader & 3;
		if (oopHeaderType == 3) {
			oopSize = oopHeader & 252;
			hdrBytes = 0;
		} else {
			if (oopHeaderType == 1) {
				oopSize = oopHeader & 252;
				hdrBytes = 4;
			} else {
				if (oopHeaderType == 0) {
					oopSize = (longAt(oop - 8)) & 4294967292U;
					hdrBytes = 8;
				} else {
					oopSize = oopHeader & 4294967292U;
					hdrBytes = 0;
				}
			}
		}
		if ((oopHeader & 2147483648U) == 0) {
			longAtput(oop - hdrBytes, 2);
			if (freeChunk != null) {
				freeChunkSize = (freeChunkSize + oopSize) + hdrBytes;
			} else {

				/* chunk may start 4 or 8 bytes before oop */

				freeChunk = oop - hdrBytes;

				/* adjust size for possible extra header bytes */

				freeChunkSize = oopSize + (oop - freeChunk);
				if (firstFree == null) {
					firstFree = freeChunk;
				}
			}
		} else {
			longAtput(oop, oopHeader & 2147483647U);
			if (((((unsigned) (longAt(oop))) >> 8) & 15) == 4) {
				finalizeReference(oop);
			}
			if (entriesAvailable > 0) {
				entriesAvailable -= 1;
			} else {
				firstFree = freeChunk;
			}
			if (freeChunk != null) {
				longAtput(freeChunk, (freeChunkSize & 4294967292U) | 2);
			}
			freeChunk = null;
			survivors += 1;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type = (longAt(oop + oopSize)) & 3;
		if (type > 1) {
			extra1 = 0;
		} else {
			if (type == 1) {
				extra1 = 4;
			} else {
				extra1 = 8;
			}
		}
		extra = extra1;
		oop = (oop + oopSize) + extra;
	}
	if (freeChunk != null) {
		longAtput(freeChunk, (freeChunkSize & 4294967292U) | 2);
	}
	if (!(oop == endOfMemory)) {
		error("sweep failed to find exact end of memory");
	}
	if (firstFree == null) {
		error("expected to find at least one free object");
	} else {
		compStart = firstFree;
	}
	if (!(displayBits == 0)) {
		oopHeader = longAt(displayBits);
		longAtput(displayBits, oopHeader & 2147483647U);
	}
	return survivors;
}


/*	Signal the given semaphore from within the interpreter. */

int synchronousSignal(int aSemaphore) {
    int excessSignals;

	if ((longAt(((((char *) aSemaphore)) + 4) + (0 << 2))) == nilObj) {
		excessSignals = fetchIntegerofObject(2, aSemaphore);
		/* begin storeInteger:ofObject:withValue: */
		if (((excessSignals + 1) ^ ((excessSignals + 1) << 1)) >= 0) {
			longAtput(((((char *) aSemaphore)) + 4) + (2 << 2), (((excessSignals + 1) << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
	} else {
		resume(removeFirstLinkOfList(aSemaphore));
	}
}


/*	Record a process to be awoken on the next interpreter cycle.
	ikp 11/24/1999 06:07 -- added hook for external runtime compiler */

int transferTo(int aProc) {
    int newProc;
    int oldProc;
    int sched;
    int valuePointer;
    int tmp;
    int valuePointer1;

	newProc = aProc;
	sched = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2));
	oldProc = longAt(((((char *) sched)) + 4) + (1 << 2));
	/* begin storePointer:ofObject:withValue: */
	if (sched < youngStart) {
		possibleRootStoreIntovalue(sched, newProc);
	}
	longAtput(((((char *) sched)) + 4) + (1 << 2), newProc);
	if (compilerInitialized) {
		compilerProcessChangeto(oldProc, newProc);
	} else {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = activeContext;
		if (oldProc < youngStart) {
			possibleRootStoreIntovalue(oldProc, valuePointer);
		}
		longAtput(((((char *) oldProc)) + 4) + (1 << 2), valuePointer);
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		longAtput(((((char *) activeContext)) + 4) + (1 << 2), ((((instructionPointer - method) - (4 - 2)) << 1) | 1));
		longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((stackPointer - activeContext) - 4)) >> 2) - 6) + 1) << 1) | 1));
		if ((longAt(((((char *) newProc)) + 4) + (1 << 2))) < youngStart) {
			beRootIfOld(longAt(((((char *) newProc)) + 4) + (1 << 2)));
		}
		activeContext = longAt(((((char *) newProc)) + 4) + (1 << 2));
		/* begin fetchContextRegisters: */
		tmp = longAt(((((char *) (longAt(((((char *) newProc)) + 4) + (1 << 2))))) + 4) + (3 << 2));
		if ((tmp & 1)) {
			tmp = longAt(((((char *) (longAt(((((char *) newProc)) + 4) + (1 << 2))))) + 4) + (5 << 2));
			if (tmp < youngStart) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = longAt(((((char *) newProc)) + 4) + (1 << 2));
		}
		theHomeContext = tmp;
		receiver = longAt(((((char *) tmp)) + 4) + (5 << 2));
		method = longAt(((((char *) tmp)) + 4) + (3 << 2));
		tmp = ((longAt(((((char *) (longAt(((((char *) newProc)) + 4) + (1 << 2))))) + 4) + (1 << 2))) >> 1);
		instructionPointer = ((method + tmp) + 4) - 2;
		tmp = ((longAt(((((char *) (longAt(((((char *) newProc)) + 4) + (1 << 2))))) + 4) + (2 << 2))) >> 1);
		stackPointer = ((longAt(((((char *) newProc)) + 4) + (1 << 2))) + 4) + (((6 + tmp) - 1) * 4);
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = nilObj;
		if (newProc < youngStart) {
			possibleRootStoreIntovalue(newProc, valuePointer1);
		}
		longAtput(((((char *) newProc)) + 4) + (1 << 2), valuePointer1);
	}
	reclaimableContextCount = 0;
}

int trueObject(void) {
	return trueObj;
}

int verifyCleanHeaders(void) {
    int oop;
    int chunk;
    int extra;
    int extra1;
    int type;
    int sz;
    int extra2;
    int header;
    int extra11;
    int type1;

	/* begin oopFromChunk: */
	chunk = startOfMemory();
	/* begin extraHeaderBytes: */
	type = (longAt(chunk)) & 3;
	if (type > 1) {
		extra1 = 0;
	} else {
		if (type == 1) {
			extra1 = 4;
		} else {
			extra1 = 8;
		}
	}
	extra = extra1;
	oop = chunk + extra;
	while (oop < endOfMemory) {
		if (((longAt(oop)) & 3) == 2) {
			if (!((objectAfter(oop)) == endOfMemory)) {
				error("Invalid obj with HeaderTypeBits = Free.");
			}
		} else {
			if (!(((longAt(oop)) & 2147483648U) == 0)) {
				error("Invalid obj with MarkBit set.");
			}
		}
		/* begin objectAfter: */
		;
		if (((longAt(oop)) & 3) == 2) {
			sz = (longAt(oop)) & 4294967292U;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & 3) == 0) {
				sz = (longAt(oop - 8)) & 4294967292U;
				goto l1;
			} else {
				sz = header & 252;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		/* begin oopFromChunk: */
		/* begin extraHeaderBytes: */
		type1 = (longAt(oop + sz)) & 3;
		if (type1 > 1) {
			extra11 = 0;
		} else {
			if (type1 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra2 = extra11;
		oop = (oop + sz) + extra2;
	}
}


/*	Return the highest priority process that is ready to run. */
/*	Note: It is a fatal VM error if there is no runnable process. */

int wakeHighestPriority(void) {
    int schedLists;
    int processList;
    int p;
    int sz;
    int header;

	schedLists = longAt(((((char *) (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2))))) + 4) + (0 << 2));
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(schedLists);
	if ((header & 3) == 0) {
		sz = (longAt(schedLists - 8)) & 4294967292U;
		goto l1;
	} else {
		sz = header & 252;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	p = ((unsigned) (sz - 4)) >> 2;

	/* index of last indexable field */

	p -= 1;
	processList = longAt(((((char *) schedLists)) + 4) + (p << 2));
	while ((longAt(((((char *) processList)) + 4) + (0 << 2))) == nilObj) {
		p -= 1;
		if (p < 0) {
			error("scheduler could not find a runnable process");
		}
		processList = longAt(((((char *) schedLists)) + 4) + (p << 2));
	}
	return removeFirstLinkOfList(processList);
}

int writeImageFile(int imageBytes) {
    int fn;

	writeImageFileIO(imageBytes);
	fn = ioLoadFunctionFrom("setMacFileTypeAndCreator", "FilePlugin");
	if (!(fn == 0)) {
		((int (*) (char*, char*, char*)) fn) (imageName, "STim", "FAST");
	}
}

int writeImageFileIO(int imageBytes) {
    int i;
    int okToWrite;
    int sCWIfn;
    int headerSize;
    sqImageFile f;
    squeakFileOffsetType headerStart;
    int bytesWritten;

	sCWIfn = ioLoadFunctionFrom("secCanWriteImage", "SecurityPlugin");
	if (sCWIfn != 0) {
		okToWrite =  ((int (*) (void)) sCWIfn)();
		if (!(okToWrite)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	headerStart = 0;

	/* header size in bytes; do not change! */

	headerSize = 64;
	f = sqImageFileOpen(imageName, "wb");
	if (f == null) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	headerStart = sqImageFileStartLocation(f,imageName,headerSize+imageBytes);
	/* Note: on Unix systems one could put an exec command here, padded to 512 bytes */;
	sqImageFileSeek(f, headerStart);
	putLongtoFile(6502, f);
	putLongtoFile(headerSize, f);
	putLongtoFile(imageBytes, f);
	putLongtoFile(startOfMemory(), f);
	putLongtoFile(specialObjectsOop, f);
	putLongtoFile(lastHash, f);
	putLongtoFile(ioScreenSize(), f);
	putLongtoFile(fullScreenFlag, f);
	putLongtoFile(extraVMMemory, f);
	for (i = 1; i <= 7; i += 1) {
		putLongtoFile(0, f);
	}
	if (!(successFlag)) {
		sqImageFileClose(f);
		return null;
	}
	sqImageFileSeek(f, headerStart + headerSize);
	bytesWritten = sqImageFileWrite(memory, sizeof(unsigned char), imageBytes, f);
	/* begin success: */
	successFlag = (bytesWritten == imageBytes) && successFlag;
	sqImageFileClose(f);
}


void* vm_exports[][3] = {
	{"", "moduleUnloaded", (void*)moduleUnloaded},
	{"", "primitiveDisablePowerManager", (void*)primitiveDisablePowerManager},
	{"", "primitiveScreenDepth", (void*)primitiveScreenDepth},
	{NULL, NULL, NULL}
};
