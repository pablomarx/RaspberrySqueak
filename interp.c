/* Automatically generated from Squeak on (18 October 1999 5:00:14 pm ) */

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
	//exit(-1);
	ioExit();
}

/*** Variables ***/
int activeContext;
int *aetBuffer;
int affectedB;
int affectedL;
int affectedR;
int affectedT;
int allocationCount;
int allocationsBetweenGCs;
int argumentCount;
int atCache[65];
int bbH;
int bbW;
int bitBltOop;
int bitCount;
int child;
int clipHeight;
int clipWidth;
int clipX;
int clipY;
int cmBitsPerColor;
int colorMap;
int combinationRule;
int compEnd;
int compStart;
int (*compilerHooks[11])();
int compilerInitialized;
int deferDisplayUpdates;
int destBits;
int destDelta;
int destForm;
int destIndex;
int destMask;
int destPixSize;
int destRaster;
int destX;
int destY;
int dispatchReturnValue;
int dispatchedValue;
int displayBits;
const int ditherMatrix4x4[16] = {
0,	8,	2,	10,
12,	4,	14,	6,
3,	11,	1,	9,
15,	7,	13,	5
};
const int ditherThresholds16[8] = { 0, 2, 4, 6, 8, 12, 14, 16 };
const int ditherValues16[32] = {
0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30
};
int doProfileStats = 0;
int dx;
int dy;
int endOfMemory;
int engine;
int engineStopped;
int extraVMMemory;
int falseObj;
int fftSize;
int field;
int formArray;
int freeBlock;
int freeContexts;
int fullScreenFlag;
int fwdTableLast;
int fwdTableNext;
int geProfileTime;
int *getBuffer;
int hDir;
int halftoneBase;
int halftoneForm;
int halftoneHeight;
int height;
float *imagData;
int imagDataSize;
int instructionPointer;
int interpreterProxy;
int interruptCheckCounter;
int interruptKeycode;
int interruptPending;
int lastHash;
int lastTick;
int lkupClass;
int lowSpaceThreshold;
double m23ArgX;
double m23ArgY;
double m23ResultX;
double m23ResultY;
int mask1;
int mask2;
int maskTable[33] = {
0, 1, 3, 0, 15, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 65535,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1
};
unsigned char *memory;
int memoryLimit;
int messageSelector;
int method;
int methodCache[2049];
int nWords;
int newMethod;
int nextPollTick;
int nextWakeupTick;
int nilObj;
int noHalftone;
int noSource;
int nu;
int *objBuffer;
int objUsed;
int opTable[36];
int parentField;
int pendingFinalizationSignals;
unsigned int *permTable;
int permTableSize;
int pixPerWord;
int preload;
int primitiveIndex;
float *realData;
int realDataSize;
int receiver;
int reclaimableContextCount;
int remapBuffer[26];
int remapBufferCount;
int rootTable[2501];
int rootTableCount;
int savedWindowSize;
int scanDisplayFlag;
int scanRightX;
int scanStart;
int scanStop;
int scanStopArray;
int scanString;
int scanXTable;
int semaphoresToSignal[26];
int semaphoresToSignalCount;
int signalLowSpace;
float *sinTable;
int sinTableSize;
int skew;
int sourceAlpha;
int sourceBits;
int sourceDelta;
int sourceForm;
int sourceIndex;
int sourcePixSize;
int sourceRaster;
int sourceX;
int sourceY;
unsigned int *spanBuffer;
int specialObjectsOop;
int srcBitIndex;
int srcHeight;
int srcWidth;
int stackPointer;
int statFullGCMSecs;
int statFullGCs;
int statIncrGCMSecs;
int statIncrGCs;
int statRootTableOverflows;
int statTenures;
int stopCode;
int successFlag;
int sx;
int sy;
int tenuringThreshold;
int theHomeContext;
int trueObj;
int vDir;
int width;
int *workBuffer;
int youngStart;

/*** Function Prototypes ***/
int OLDrgbDiffwith(int sourceWord, int destinationWord);
int OLDtallyIntoMapwith(int sourceWord, int destinationWord);
int accessibleObjectAfter(int oop);
int accurateLengthOfwith(int deltaX, int deltaY);
int addEdgeToGET(int edge);
int addToMethodCacheSelclassmethodprimIndex(int selector, int class, int meth, int primIndex);
int addWordwith(int sourceWord, int destinationWord);
int adjustWideBezierLeftwidthoffsetendX(int bezier, int lineWidth, int lineOffset, int endX);
int adjustWideBezierRightwidthoffsetendX(int bezier, int lineWidth, int lineOffset, int endX);
int adjustWideLineafterSteppingFromto(int line, int lastX, int nextX);
int allYoungand(int array1, int array2);
int allocateBitmapFillcolormap(int cmSize, int *cmBits);
int allocateGETEntry(int nSlots);
int allocateGradientFillrampWidthisRadial(int *ramp, int rampWidth, int isRadial);
int allocateObjEntry(int nSlots);
int alphaBlendwith(int sourceWord, int destinationWord);
int alphaBlendConstwith(int sourceWord, int destinationWord);
int alphaBlendConstwithpaintMode(int sourceWord, int destinationWord, int paintMode);
int alphaBlendScaledwith(int sourceWord, int destinationWord);
int alphaPaintConstwith(int sourceWord, int destinationWord);
int alphaSourceBlendBits16(void);
int alphaSourceBlendBits32(void);
int alphaSourceBlendBits8(void);
int argumentCountOf(int methodPointer);
void * arrayValueOf(int arrayOop);
int asciiDirectoryDelimiter(void);
int asciiOfCharacter(int characterObj);
AsyncFile * asyncFileValueOf(int oop);
int beRootIfOld(int oop);
int becomewith(int array1, int array2);
int becomewithtwoWay(int array1, int array2, int twoWayFlag);
int bitAndwith(int sourceWord, int destinationWord);
int bitAndInvertwith(int sourceWord, int destinationWord);
int bitInvertAndwith(int sourceWord, int destinationWord);
int bitInvertAndInvertwith(int sourceWord, int destinationWord);
int bitInvertDestinationwith(int sourceWord, int destinationWord);
int bitInvertOrwith(int sourceWord, int destinationWord);
int bitInvertOrInvertwith(int sourceWord, int destinationWord);
int bitInvertSourcewith(int sourceWord, int destinationWord);
int bitInvertXorwith(int sourceWord, int destinationWord);
int bitOrwith(int sourceWord, int destinationWord);
int bitOrInvertwith(int sourceWord, int destinationWord);
int bitXorwith(int sourceWord, int destinationWord);
int booleanValueOf(int obj);
int byteLengthOf(int oop);
int byteSizeOf(int oop);
int byteSwapped(int w);
int bytecodeActivateNewMethod(void);
int characterTable(void);
int checkCompressedFillIndexListmaxsegments(int fillList, int maxIndex, int nSegs);
int checkCompressedFills(int indexList);
int checkCompressedLineWidthssegments(int lineWidthList, int nSegments);
int checkCompressedPointssegments(int points, int nSegments);
int checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(int points, int nSegments, int leftFills, int rightFills, int lineWidths, int lineFills, int fillIndexList);
int checkForInterrupts(void);
int checkImageVersionFromstartingAt(sqImageFile f, int imageOffset);
int checkedIntegerValueOf(int intOop);
int checkedLongAt(int byteAddress);
double * circleCosTable(void);
double * circleSinTable(void);
int classArray(void);
int classBitmap(void);
int classByteArray(void);
int classCharacter(void);
int classFloat(void);
int classLargePositiveInteger(void);
int classNameOfIs(int aClass, char *className);
int classPoint(void);
int classSemaphore(void);
int classSmallInteger(void);
int classString(void);
int clearSpanBuffer(void);
int clearWordwith(int source, int destination);
int clipRange(void);
int clone(int oop);
int commonAt(int stringy);
int commonAtPut(int stringy);
int commonVariableatcacheIndex(int rcvr, int index, int atIx);
int compare31or32Bitsequal(int obj1, int obj2);
int compilerActivateMethod(void);
int compilerFlushCache(int aCompiledMethod);
int compilerMapFromto(int memStart, int memEnd);
int compilerMark(void);
int compilerPostGC(void);
int compilerPostSnapshot(void);
int compilerPreGC(int fullGCFlag);
int compilerPreSnapshot(void);
int compilerProcessChange(void);
int computeBeziersplitAt(int index, double param);
int computeBezierSplitAtHalf(int index);
int computeFinalWideBezierValueswidth(int bezier, int lineWidth);
int containOnlyOopsand(int array1, int array2);
int copyBits(void);
int copyBitsFromtoat(int startX, int stopX, int yValue);
int copyLoop(void);
int copyLoopNoSource(void);
int copyLoopPixMap(void);
int copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(int oop, int segmentWordArray, int lastSeg, int stopAddr, int oopPtr, int hdrPtr);
int createActualMessageTo(int aClass);
int createGlobalEdgeTable(void);
unsigned int * default8To32Table(void);
int deltaFromtonSteps(int x1, int x2, int n);
int destMaskAndPointerInit(void);
int destinationWordwith(int sourceWord, int destinationWord);
int displayObject(void);
int displaySpanBufferAt(int y);
int doPrimitiveDivby(int rcvr, int arg);
int doPrimitiveModby(int rcvr, int arg);
int errorWrongIndex(void);
int extraHeaderBytes(int oopOrChunk);
int failed(void);
int falseObject(void);
void * fetchArrayofObject(int fieldIndex, int objectPointer);
int fetchClassOf(int oop);
int fetchClassOfNonInt(int oop);
double fetchFloatofObject(int fieldIndex, int objectPointer);
int fetchIntegerofObject(int fieldIndex, int objectPointer);
int fetchIntegerOrTruncFloatofObject(int fieldIndex, int objectPointer);
int fetchPointerofObject(int fieldIndex, int oop);
int fetchStackPointerOf(int aContext);
int fetchWordofObject(int fieldIndex, int oop);
int fetchWordLengthOf(int objectPointer);
int fileRecordSize(void);
SQFile * fileValueOf(int objectPointer);
int fillBitmapSpanfromto(int *bits, int leftX, int rightX);
int fillBitmapSpanfromtoat(int bmFill, int leftX, int rightX, int yValue);
int fillBitmapSpanAAfromtoat(int bmFill, int leftX, int rightX, int yValue);
int fillColorSpanAAx0x1(int pixelValue32, int leftX, int rightX);
int fillLinearGradientfromtoat(int fill, int leftX, int rightX, int yValue);
int fillLinearGradientAArampdsdsXfromto(int fill, int *ramp, int deltaS, int dsX, int leftX, int rightX);
int fillRadialDecreasingAArampdeltaSTdsXdtXfromto(int fill, int *ramp,  int *deltaST, int dsX, int dtX, int leftX, int rightX);
int fillRadialGradientfromtoat(int fill, int leftX, int rightX, int yValue);
int fillRadialIncreasingAArampdeltaSTdsXdtXfromto(int fill, int *ramp,  int *deltaST, int dsX, int dtX, int leftX, int rightX);
int fillSortsbefore(int fillEntry1, int fillEntry2);
int fillSpanfromto(int fill, int leftX, int rightX);
int finalizeReference(int oop);
int findNewMethodInClass(int class);
int findNextExternalEntryFromGET(void);
int findNextExternalFillFromAET(void);
int findNextExternalUpdateFromAET(void);
int findStackFilldepth(int fillIndex, int depth);
void * firstFixedField(int oop);
void * firstIndexableField(int oop);
int floatObjectOf(double aFloat);
double floatValueOf(int oop);
int fullDisplayUpdate(void);
int fullGC(void);
int fwdTableInit(int blkSize);
#pragma export on
EXPORT(int) gePrimitiveAbortProcessing(void);
EXPORT(int) gePrimitiveAddActiveEdgeEntry(void);
EXPORT(int) gePrimitiveAddBezier(void);
EXPORT(int) gePrimitiveAddBezierShape(void);
EXPORT(int) gePrimitiveAddBitmapFill(void);
EXPORT(int) gePrimitiveAddCompressedShape(void);
EXPORT(int) gePrimitiveAddGradientFill(void);
EXPORT(int) gePrimitiveAddLine(void);
EXPORT(int) gePrimitiveAddOval(void);
EXPORT(int) gePrimitiveAddPolygon(void);
EXPORT(int) gePrimitiveAddRect(void);
EXPORT(int) gePrimitiveChangedActiveEdgeEntry(void);
EXPORT(int) gePrimitiveCopyBuffer(void);
EXPORT(int) gePrimitiveDisplaySpanBuffer(void);
EXPORT(int) gePrimitiveDoProfileStats(void);
EXPORT(int) gePrimitiveFinishedProcessing(void);
EXPORT(int) gePrimitiveGetAALevel(void);
EXPORT(int) gePrimitiveGetBezierStats(void);
EXPORT(int) gePrimitiveGetClipRect(void);
EXPORT(int) gePrimitiveGetCounts(void);
EXPORT(int) gePrimitiveGetDepth(void);
EXPORT(int) gePrimitiveGetFailureReason(void);
EXPORT(int) gePrimitiveGetOffset(void);
EXPORT(int) gePrimitiveGetTimes(void);
EXPORT(int) gePrimitiveInitializeBuffer(void);
EXPORT(int) gePrimitiveInitializeProcessing(void);
EXPORT(int) gePrimitiveMergeFillFrom(void);
EXPORT(int) gePrimitiveNeedsFlush(void);
EXPORT(int) gePrimitiveNeedsFlushPut(void);
EXPORT(int) gePrimitiveNextActiveEdgeEntry(void);
EXPORT(int) gePrimitiveNextFillEntry(void);
EXPORT(int) gePrimitiveNextGlobalEdgeEntry(void);
EXPORT(int) gePrimitiveRegisterExternalEdge(void);
EXPORT(int) gePrimitiveRegisterExternalFill(void);
EXPORT(int) gePrimitiveRenderImage(void);
EXPORT(int) gePrimitiveRenderScanline(void);
EXPORT(int) gePrimitiveSetAALevel(void);
EXPORT(int) gePrimitiveSetClipRect(void);
EXPORT(int) gePrimitiveSetColorTransform(void);
EXPORT(int) gePrimitiveSetDepth(void);
EXPORT(int) gePrimitiveSetEdgeTransform(void);
EXPORT(int) gePrimitiveSetOffset(void);
#pragma export off
int getCurrentBytecode(void);
int getLongFromFileswap(sqImageFile f, int swapFlag);
int getSortsbefore(int edge1, int edge2);
int hideFilldepth(int fillIndex, int depth);
int incCompBody(void);
int incrementalGC(void);
int indexForInsertingIntoAET(int edge);
int initBBOpTable(void);
int initColorTransform(void);
int initCompilerHooks(void);
int initEdgeTransform(void);
int initializeGETProcessing(void);
int initializeMemoryFirstFree(int firstFree);
int initializeObjectMemory(int bytesToShift);
int insertEdgeIntoAET(int edge);
int insertToAETbeforeIndex(int edge, int index);
int installinAtCacheatstring(int rcvr, int *cache, int atIx, int stringy);
int instantiateClassindexableSize(int classPointer, int size);
int instantiateContextsizeInBytes(int classPointer, int sizeInBytes);
int instantiateSmallClasssizeInBytesfill(int classPointer, int sizeInBytes, int fillValue);
int intToNetAddress(int addr);
int integerObjectOf(int value);
int integerValueOf(int objectPointer);
int interpret(void);
int isKindOf(int oop, char *className);
int isMemberOf(int oop, char *className);
int isBytes(int oop);
int isContextHeader(int aHeader);
int isEdge(int edge);
int isFillOkay(int fill);
int isFloatObject(int oop);
int isIndexable(int oop);
int isIntegerObject(int objectPointer);
int isIntegerValue(int intValue);
int isPointers(int oop);
int isWeak(int oop);
int isWords(int oop);
int isWordsOrBytes(int oop);
int lastPointerOf(int oop);
int lengthOf(int oop);
int literalofMethod(int offset, int methodPointer);
int literalCountOf(int methodPointer);
int loadAndSubdivideBezierFromviatoisWide(int *point1, int *point2, int *point3, int wideFlag);
int loadArgumentPoint(int point);
int loadArrayShapenSegmentsfilllineWidthlineFill(int points, int nSegments, int fillIndex, int lineWidth, int lineFill);
int loadArrayTransformFromintolength(int transformOop, float *destPtr, int n);
int loadBeziersegmentleftFillrightFilloffset(int bezier, int index, int leftFillIndex, int rightFillIndex, int yOffset);
int loadBitBltFrom(int bbObj);
int loadBitmapFillcolormaptilefromalongnormalxIndex(int formOop, int cmOop, int tileFlag, int *point1, int *point2, int *point3, int xIndex);
int * loadBitsFrom(int bmFill);
int loadColorTransformFrom(int transformOop);
int loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(int *points, int nSegments, int *leftFills, int *rightFills, int *lineWidths, int *lineFills, int *fillIndexList, int pointsShort);
int loadEdgeStateFrom(int edgeOop);
int loadEdgeTransformFrom(int transformOop);
int loadFFTFrom(int fftOop);
int loadFillOrientationfromalongnormalwidthheight(int fill, int *point1, int *point2, int *point3, int fillWidth, int fillHeight);
double loadFloatOrIntFrom(int floatOrInt);
int loadFormsFrom(int arrayOop);
int loadGradientFillfromalongnormalisRadial(int rampOop, int *point1, int *point2, int *point3, int isRadial);
int loadLinefromtooffsetleftFillrightFill(int line, int *point1, int *point2, int yOffset, int leftFill, int rightFill);
int loadOvallineFillleftFillrightFill(int lineWidth, int lineFill, int leftFill, int rightFill);
int loadOvalSegmentwhcxcy(int seg, int w, int h, int cx, int cy);
int loadPointfrom(int *pointArray, int pointOop);
int loadPolygonnPointsfilllineWidthlineFillpointsShort(int *points, int nPoints, int fillIndex, int lineWidth, int lineFill, int isShort);
int loadRenderingState(void);
int loadScannerFromstartstopstringrightXstopArraydisplayFlag(int bbObj, int start, int stop, int string, int rightX, int stopArray, int displayFlag);
int loadShapenSegmentsfilllineWidthlineFillpointsShort(int *points, int nSegments, int fillIndex, int lineWidth, int lineFill, int pointsShort);
int loadSpanBufferFrom(int spanOop);
int loadTransformFromintolength(int transformOop, float *destPtr, int n);
int loadWideBezierlineFillleftFillrightFilln(int lineWidth, int lineFill, int leftFill, int rightFill, int nSegments);
int loadWideLinefromtolineFillleftFillrightFill(int lineWidth, int *p1, int *p2, int lineFill, int leftFill, int rightFill);
int loadWordTransformFromintolength(int transformOop, float *destPtr, int n);
int loadWorkBufferFrom(int wbOop);
int lookupMethodInClass(int class);
int lowestFreeAfter(int chunk);
#pragma export on
EXPORT(int) m23PrimitiveComposeMatrix(void);
EXPORT(int) m23PrimitiveInvertPoint(void);
EXPORT(int) m23PrimitiveInvertRectInto(void);
EXPORT(int) m23PrimitiveIsIdentity(void);
EXPORT(int) m23PrimitiveIsPureTranslation(void);
EXPORT(int) m23PrimitiveTransformPoint(void);
EXPORT(int) m23PrimitiveTransformRectInto(void);
#pragma export off
int makeDirEntryNamesizecreateDatemodDateisDirfileSize(char *entryName, int entryNameSize, int createDate, int modifiedDate, int dirFlag, int fileSize);
int makePointwithxValueyValue(int xValue, int yValue);
int mapPointersInObjectsFromto(int memStart, int memEnd);
int markAndTrace(int oop);
int markPhase(void);
int matrix2x3ComposeMatrixwithinto(const float *m1, const float *m2, float *m3);
int matrix2x3InvertPoint(float *m);
int matrix2x3TransformPoint(float *m);
int mergewith(int sourceWord, int destinationWord);
int methodArgumentCount(void);
int methodPrimitiveIndex(void);
int moveAETEntryFromedgex(int index, int edge, int xValue);
int needAvailableSpace(int nSlots);
int netAddressToInt(int oop);
int nilObject(void);
int nonWeakFieldsOf(int oop);
int nullCompilerHook(void);
int objectAfter(int oop);
int okayFields(int oop);
int okayOop(int oop);
int oopFromChunk(int chunk);
int oopHasOKclass(int oop);
int oopHasOkayClass(int oop);
int partitionedANDtonBitsnPartitions(int word1, int word2, int nBits, int nParts);
int partitionedAddtonBitsnPartitions(int word1, int word2, int nBits, int nParts);
int partitionedMaxwithnBitsnPartitions(int word1, int word2, int nBits, int nParts);
int partitionedMinwithnBitsnPartitions(int word1, int word2, int nBits, int nParts);
int partitionedSubfromnBitsnPartitions(int word1, int word2, int nBits, int nParts);
int permuteData(void);
int pickSourcePixelssrcMaskdestMask(int nPix, int sourcePixMask, int destPixMask);
int pickSourcePixelsNullMapsrcMaskdestMask(int nPix, int sourcePixMask, int destPixMask);
int pickSourcePixelsRGBnullMapsrcMaskdestMask(int nPix, int nullMap, int sourcePixMask, int destPixMask);
int pixMaskwith(int sourceWord, int destinationWord);
int pixPaintwith(int sourceWord, int destinationWord);
int pop(int nItems);
int popthenPush(int nItems, int oop);
double popFloat(void);
int popRemappableOop(void);
int popStack(void);
int positive32BitIntegerFor(int integerValue);
int positive32BitValueOf(int oop);
int possibleRootStoreIntovalue(int oop, int valueObj);
int postDisplayAction(void);
int prepareForwardingTableForBecomingwithtwoWay(int array1, int array2, int twoWayFlag);
int primitiveAdd(void);
int primitiveArctan(void);
int primitiveArrayBecome(void);
int primitiveArrayBecomeOneWay(void);
int primitiveAsFloat(void);
int primitiveAsOop(void);
int primitiveAsyncFileClose(void);
int primitiveAsyncFileOpen(void);
int primitiveAsyncFileReadResult(void);
int primitiveAsyncFileReadStart(void);
int primitiveAsyncFileWriteResult(void);
int primitiveAsyncFileWriteStart(void);
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
int primitiveClass(void);
int primitiveClipboardText(void);
int primitiveClone(void);
int primitiveConstantFill(void);
int primitiveCopyBits(void);
int primitiveDeferDisplayUpdates(void);
int primitiveDirectoryCreate(void);
int primitiveDirectoryDelete(void);
int primitiveDirectoryDelimitor(void);
int primitiveDirectoryLookup(void);
int primitiveDirectorySetMacTypeAndCreator(void);
int primitiveDiv(void);
int primitiveDivide(void);
int primitiveDoPrimitiveWithArgs(void);
int primitiveDrawLoop(void);
int primitiveEqual(void);
int primitiveEquivalent(void);
int primitiveExitToDebugger(void);
int primitiveExp(void);
int primitiveExponent(void);
int primitiveExternalCall(void);
#pragma export on
EXPORT(int) primitiveFFTPermuteData(void);
EXPORT(int) primitiveFFTScaleData(void);
EXPORT(int) primitiveFFTTransformData(void);
#pragma export off
int primitiveFail(void);
int primitiveFileAtEnd(void);
int primitiveFileClose(void);
int primitiveFileDelete(void);
int primitiveFileGetPosition(void);
int primitiveFileOpen(void);
int primitiveFileRead(void);
int primitiveFileRename(void);
int primitiveFileSetPosition(void);
int primitiveFileSize(void);
int primitiveFileWrite(void);
int primitiveFloatAddtoArg(int rcvrOop, int argOop);
#pragma export on
EXPORT(int) primitiveFloatArrayAddFloatArray(void);
EXPORT(int) primitiveFloatArrayAddScalar(void);
EXPORT(int) primitiveFloatArrayAt(void);
EXPORT(int) primitiveFloatArrayAtPut(void);
EXPORT(int) primitiveFloatArrayDivFloatArray(void);
EXPORT(int) primitiveFloatArrayDivScalar(void);
EXPORT(int) primitiveFloatArrayEqual(void);
EXPORT(int) primitiveFloatArrayHash(void);
EXPORT(int) primitiveFloatArrayMulFloatArray(void);
EXPORT(int) primitiveFloatArrayMulScalar(void);
EXPORT(int) primitiveFloatArraySubFloatArray(void);
EXPORT(int) primitiveFloatArraySubScalar(void);
#pragma export off
int primitiveFloatDividebyArg(int rcvrOop, int argOop);
int primitiveFloatEqual(void);
int primitiveFloatEqualtoArg(int rcvrOop, int argOop);
int primitiveFloatGreaterthanArg(int rcvrOop, int argOop);
int primitiveFloatGreaterOrEqual(void);
int primitiveFloatGreaterThan(void);
int primitiveFloatLessthanArg(int rcvrOop, int argOop);
int primitiveFloatLessOrEqual(void);
int primitiveFloatLessThan(void);
int primitiveFloatMultiplybyArg(int rcvrOop, int argOop);
int primitiveFloatNotEqual(void);
int primitiveFloatSubtractfromArg(int rcvrOop, int argOop);
int primitiveFlushCache(void);
int primitiveFlushCacheByMethod(void);
int primitiveFlushCacheSelective(void);
int primitiveForceDisplayUpdate(void);
int primitiveFormPrint(void);
int primitiveFractionalPart(void);
int primitiveFullGC(void);
int primitiveGetAttribute(void);
int primitiveGetTabletParameters(void);
int primitiveGreaterOrEqual(void);
int primitiveGreaterThan(void);
int primitiveImageName(void);
int primitiveIncrementalGC(void);
int primitiveIndexOf(int methodPointer);
int primitiveInitializeNetwork(void);
int primitiveInputSemaphore(void);
int primitiveInputWord(void);
int primitiveInstVarAt(void);
int primitiveInstVarAtPut(void);
int primitiveInstVarsPutFromStack(void);
int primitiveInterruptSemaphore(void);
int primitiveKbdNext(void);
int primitiveKbdPeek(void);
int primitiveLessOrEqual(void);
int primitiveLessThan(void);
int primitiveLoadImageSegment(void);
int primitiveLoadInstVar(void);
int primitiveLogN(void);
int primitiveLowSpaceSemaphore(void);
int primitiveMIDIClosePort(void);
int primitiveMIDIGetClock(void);
int primitiveMIDIGetPortCount(void);
int primitiveMIDIGetPortDirectionality(void);
int primitiveMIDIGetPortName(void);
int primitiveMIDIOpenPort(void);
int primitiveMIDIParameterGetOrSet(void);
int primitiveMIDIRead(void);
int primitiveMIDIWrite(void);
int primitiveMakePoint(void);
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
int primitiveReadJoystick(void);
int primitiveReadTablet(void);
int primitiveRelinquishProcessor(void);
int primitiveResolverAbortLookup(void);
int primitiveResolverAddressLookupResult(void);
int primitiveResolverError(void);
int primitiveResolverLocalAddress(void);
int primitiveResolverNameLookupResult(void);
int primitiveResolverStartAddressLookup(void);
int primitiveResolverStartNameLookup(void);
int primitiveResolverStatus(void);
int primitiveResponse(void);
int primitiveResume(void);
int primitiveScanCharacters(void);
int primitiveScreenSize(void);
int primitiveSecondsClock(void);
int primitiveSerialPortClose(void);
int primitiveSerialPortOpen(void);
int primitiveSerialPortRead(void);
int primitiveSerialPortWrite(void);
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
int primitiveSocketAbortConnection(void);
int primitiveSocketAccept(void);
int primitiveSocketCloseConnection(void);
int primitiveSocketConnectToPort(void);
int primitiveSocketConnectionStatus(void);
int primitiveSocketCreate(void);
int primitiveSocketDestroy(void);
int primitiveSocketError(void);
int primitiveSocketListenOnPort(void);
int primitiveSocketLocalAddress(void);
int primitiveSocketLocalPort(void);
int primitiveSocketReceiveDataAvailable(void);
int primitiveSocketReceiveDataBufCount(void);
int primitiveSocketRemoteAddress(void);
int primitiveSocketRemotePort(void);
int primitiveSocketSendDataBufCount(void);
int primitiveSocketSendDone(void);
int primitiveSomeInstance(void);
int primitiveSomeObject(void);
int primitiveSoundAvailableSpace(void);
int primitiveSoundGetRecordingSampleRate(void);
int primitiveSoundInsertSamples(void);
int primitiveSoundPlaySamples(void);
int primitiveSoundPlaySilence(void);
int primitiveSoundRecordSamples(void);
int primitiveSoundSetRecordLevel(void);
int primitiveSoundStart(void);
int primitiveSoundStartRecording(void);
int primitiveSoundStartWithSemaphore(void);
int primitiveSoundStop(void);
int primitiveSoundStopRecording(void);
int primitiveSpecialObjectsOop(void);
int primitiveSquareRoot(void);
int primitiveStoreImageSegment(void);
int primitiveStoreStackp(void);
int primitiveStringAt(void);
int primitiveStringAtPut(void);
int primitiveStringReplace(void);
int primitiveSubtract(void);
int primitiveSuspend(void);
int primitiveTestDisplayDepth(void);
int primitiveTimesTwoPower(void);
int primitiveTruncated(void);
int primitiveVMParameter(void);
int primitiveVMPath(void);
int primitiveValue(void);
int primitiveValueWithArgs(void);
int primitiveWait(void);
int primitiveWarpBits(void);
int print(char *s);
int printCallStack(void);
int printNameOfClasscount(int classOop, int cnt);
int printNum(int n);
int printStringOf(int oop);
int proceedRenderingImage(void);
int proceedRenderingScanline(void);
int push(int object);
int pushBool(int trueOrFalse);
int pushFloat(double f);
int pushInteger(int integerValue);
int pushRemappableOop(int oop);
int putLongtoFile(int n, sqImageFile f);
int quickLoadEngineFrom(int engineOop);
int quickLoadEngineFromrequiredState(int oop, int requiredState);
int quickLoadEngineFromrequiredStateor(int oop, int requiredState, int alternativeState);
int quickSortGlobalEdgeTablefromto(int *array, int i, int j);
int * rShiftTable(void);
int readImageFromFileHeapSizeStartingAt(sqImageFile f, int desiredHeapSize, int imageOffset);
int readableFormat(int imageVersion);
int remap(int oop);
int removeFirstAETEntry(void);
int removeFirstLinkOfList(int aList);
int resetGraphicsEngineStats(void);
int resortFirstAETEntry(void);
int restoreHeadersFromtofromandtofrom(int firstIn, int lastIn, int hdrBaseIn, int firstOut, int lastOut, int hdrBaseOut);
int resume(int aProcess);
int reverseDisplayFromto(int startIndex, int endIndex);
int rgbAddwith(int sourceWord, int destinationWord);
int rgbDiffwith(int sourceWord, int destinationWord);
int rgbMaxwith(int sourceWord, int destinationWord);
int rgbMinwith(int sourceWord, int destinationWord);
int rgbMinInvertwith(int wordToInvert, int destinationWord);
int rgbSubwith(int sourceWord, int destinationWord);
int roundAndStoreResultRectx0y0x1y1(int dstOop, double x0, double y0, double x1, double y1);
int scaleData(void);
int setAALevel(int level);
int setCompilerInitialized(int newFlag);
#pragma export on
EXPORT(int) setInterpreter(int anInterpreter);
#pragma export off
int showDisplayBits(void);
int showDisplayBitsLeftTopRightBottom(int aForm, int affectedRectL, int affectedRectT, int affectedRectR, int affectedRectB);
int showFilldepthrightX(int fillIndex, int depth, int rightX);
int signalSemaphoreWithIndex(int index);
int sizeBitsOf(int oop);
int sizeOfSTArrayFromCPrimitive(void *cPtr);
int slotSizeOf(int oop);
int * smallSqrtTable(void);
int smoothPixatXfyfdxhdyhdxvdyvpixPerWordpixelMasksourceMap(int n, int xf, int yf, int dxh, int dyh, int dxv, int dyv, int srcPixPerWord, int sourcePixMask, int sourceMap);
int socketRecordSize(void);
SQSocket * socketValueOf(int socketOop);
int sourcePixAtXypixPerWord(int x, int y, int srcPixPerWord);
int sourceWordwith(int sourceWord, int destinationWord);
int splObj(int index);
int stObjectat(int array, int index);
int stObjectatput(int array, int index, int value);
int stSizeOf(int oop);
double stackFloatValue(int offset);
int stackIntegerValue(int offset);
int stackObjectValue(int offset);
int stackValue(int offset);
int startOfMemory(void);
int stepToFirstBezierInat(int bezier, int yValue);
int stepToFirstLineInat(int line, int yValue);
int stepToFirstWideBezierInat(int bezier, int yValue);
int stepToFirstWideLineInat(int line, int yValue);
int stepToNextBezierInat(int bezier, int yValue);
int stepToNextLineInat(int line, int yValue);
int stepToNextWideBezier(void);
int stepToNextWideBezierInat(int bezier, int yValue);
int stepToNextWideLineInat(int line, int yValue);
int storeEdgeStateFrominto(int edge, int edgeOop);
int storeFillStateInto(int fillOop);
int storeIntegerofObjectwithValue(int fieldIndex, int objectPointer, int integerValue);
int storePointerofObjectwithValue(int fieldIndex, int oop, int valuePointer);
int storeRenderingState(void);
int subWordwith(int sourceWord, int destinationWord);
int subdivideBezier(int index);
int subdivideBezierFrom(int index);
int subdivideToBeMonotoninX(int base, int doTestX);
int subdivideToBeMonotonInX(int index);
int subdivideToBeMonotonInY(int index);
int success(int successValue);
int sufficientSpaceAfterGC(int minFree);
int superclassOf(int classPointer);
int sweepPhase(void);
int synchronousSignal(int aSemaphore);
int tallyIntoMapwith(int sourceWord, int destinationWord);
int toggleFilldepthrightX(int fillIndex, int depth, int rightX);
int toggleFillsOf(int edge);
int toggleWideFillOf(int edge);
int topDepth(void);
int topFill(void);
int topRightX(void);
int transferTo(int aProc);
int transformColor(int fillIndex);
int transformForward(int forward);
int transformPoint(int *point);
int transformPointXyinto(double xValue, double yValue, int *dstPoint);
int transformWidth(int w);
int trueObject(void);
int uncheckedTransformColor(int fillIndex);
int verifyCleanHeaders(void);
int wakeHighestPriority(void);
int warpSourcePixelsxDeltahyDeltahxDeltavyDeltavsmoothingsourceMap(int nPix, int xDeltah, int yDeltah, int xDeltav, int yDeltav, int n, int sourceMapOop);
int wbStackPush(int nItems);
int writeImageFile(int imageBytes);

int OLDrgbDiffwith(int sourceWord, int destinationWord) {
    int diff;
    int pixMask;

	if (destPixSize < 16) {
		diff = sourceWord ^ destinationWord;
		pixMask = maskTable[destPixSize];
		while (!(diff == 0)) {
			if ((diff & pixMask) != 0) {
				bitCount += 1;
			}
			diff = ((unsigned) diff) >> destPixSize;
		}
		return destinationWord;
	}
	if (destPixSize == 16) {
		diff = partitionedSubfromnBitsnPartitions(sourceWord, destinationWord, 5, 3);
		bitCount = ((bitCount + (diff & 31)) + ((((unsigned) diff) >> 5) & 31)) + ((((unsigned) diff) >> 10) & 31);
		diff = partitionedSubfromnBitsnPartitions(((unsigned) sourceWord) >> 16, ((unsigned) destinationWord) >> 16, 5, 3);
		bitCount = ((bitCount + (diff & 31)) + ((((unsigned) diff) >> 5) & 31)) + ((((unsigned) diff) >> 10) & 31);
	} else {
		diff = partitionedSubfromnBitsnPartitions(sourceWord, destinationWord, 8, 3);
		bitCount = ((bitCount + (diff & 255)) + ((((unsigned) diff) >> 8) & 255)) + ((((unsigned) diff) >> 16) & 255);
	}
	return destinationWord;
}

int OLDtallyIntoMapwith(int sourceWord, int destinationWord) {
    int mapIndex;
    int pixMask;
    int shiftWord;
    int i;
    int mask;
    int srcPix;
    int destPix;
    int d;
    int mask3;
    int srcPix1;
    int destPix1;
    int d1;
    int mask4;
    int srcPix2;
    int destPix2;
    int d2;

	if (colorMap == nilObj) {
		return destinationWord;
	}
	if (destPixSize < 16) {
		pixMask = maskTable[destPixSize];
		shiftWord = destinationWord;
		for (i = 1; i <= pixPerWord; i += 1) {
			mapIndex = shiftWord & pixMask;
			longAtput(((((char *) colorMap)) + 4) + (mapIndex << 2), (longAt(((((char *) colorMap)) + 4) + (mapIndex << 2))) + 1);
			shiftWord = ((unsigned) shiftWord) >> destPixSize;
		}
		return destinationWord;
	}
	if (destPixSize == 16) {
		/* begin rgbMap:from:to: */
		if ((d = cmBitsPerColor - 5) > 0) {
			mask = (1 << 5) - 1;
			srcPix = (destinationWord & 65535) << d;
			mask = mask << d;
			destPix = srcPix & mask;
			mask = mask << cmBitsPerColor;
			srcPix = srcPix << d;
			mapIndex = (destPix + (srcPix & mask)) + ((srcPix << d) & (mask << cmBitsPerColor));
			goto l1;
		} else {
			if (d == 0) {
				if (5 == 5) {
					mapIndex = (destinationWord & 65535) & 32767;
					goto l1;
				}
				if (5 == 8) {
					mapIndex = (destinationWord & 65535) & 16777215;
					goto l1;
				}
				mapIndex = destinationWord & 65535;
				goto l1;
			}
			if ((destinationWord & 65535) == 0) {
				mapIndex = destinationWord & 65535;
				goto l1;
			}
			d = 5 - cmBitsPerColor;
			mask = (1 << cmBitsPerColor) - 1;
			srcPix = ((unsigned) (destinationWord & 65535)) >> d;
			destPix = srcPix & mask;
			mask = mask << cmBitsPerColor;
			srcPix = ((unsigned) srcPix) >> d;
			destPix = (destPix + (srcPix & mask)) + ((((unsigned) srcPix) >> d) & (mask << cmBitsPerColor));
			if (destPix == 0) {
				mapIndex = 1;
				goto l1;
			}
			mapIndex = destPix;
			goto l1;
		}
	l1:	/* end rgbMap:from:to: */;
		longAtput(((((char *) colorMap)) + 4) + (mapIndex << 2), (longAt(((((char *) colorMap)) + 4) + (mapIndex << 2))) + 1);
		/* begin rgbMap:from:to: */
		if ((d1 = cmBitsPerColor - 5) > 0) {
			mask3 = (1 << 5) - 1;
			srcPix1 = (((unsigned) destinationWord) >> 16) << d1;
			mask3 = mask3 << d1;
			destPix1 = srcPix1 & mask3;
			mask3 = mask3 << cmBitsPerColor;
			srcPix1 = srcPix1 << d1;
			mapIndex = (destPix1 + (srcPix1 & mask3)) + ((srcPix1 << d1) & (mask3 << cmBitsPerColor));
			goto l2;
		} else {
			if (d1 == 0) {
				if (5 == 5) {
					mapIndex = (((unsigned) destinationWord) >> 16) & 32767;
					goto l2;
				}
				if (5 == 8) {
					mapIndex = (((unsigned) destinationWord) >> 16) & 16777215;
					goto l2;
				}
				mapIndex = ((unsigned) destinationWord) >> 16;
				goto l2;
			}
			if ((((unsigned) destinationWord) >> 16) == 0) {
				mapIndex = ((unsigned) destinationWord) >> 16;
				goto l2;
			}
			d1 = 5 - cmBitsPerColor;
			mask3 = (1 << cmBitsPerColor) - 1;
			srcPix1 = ((unsigned) (((unsigned) destinationWord) >> 16)) >> d1;
			destPix1 = srcPix1 & mask3;
			mask3 = mask3 << cmBitsPerColor;
			srcPix1 = ((unsigned) srcPix1) >> d1;
			destPix1 = (destPix1 + (srcPix1 & mask3)) + ((((unsigned) srcPix1) >> d1) & (mask3 << cmBitsPerColor));
			if (destPix1 == 0) {
				mapIndex = 1;
				goto l2;
			}
			mapIndex = destPix1;
			goto l2;
		}
	l2:	/* end rgbMap:from:to: */;
		longAtput(((((char *) colorMap)) + 4) + (mapIndex << 2), (longAt(((((char *) colorMap)) + 4) + (mapIndex << 2))) + 1);
	} else {
		/* begin rgbMap:from:to: */
		if ((d2 = cmBitsPerColor - 8) > 0) {
			mask4 = (1 << 8) - 1;
			srcPix2 = destinationWord << d2;
			mask4 = mask4 << d2;
			destPix2 = srcPix2 & mask4;
			mask4 = mask4 << cmBitsPerColor;
			srcPix2 = srcPix2 << d2;
			mapIndex = (destPix2 + (srcPix2 & mask4)) + ((srcPix2 << d2) & (mask4 << cmBitsPerColor));
			goto l3;
		} else {
			if (d2 == 0) {
				if (8 == 5) {
					mapIndex = destinationWord & 32767;
					goto l3;
				}
				if (8 == 8) {
					mapIndex = destinationWord & 16777215;
					goto l3;
				}
				mapIndex = destinationWord;
				goto l3;
			}
			if (destinationWord == 0) {
				mapIndex = destinationWord;
				goto l3;
			}
			d2 = 8 - cmBitsPerColor;
			mask4 = (1 << cmBitsPerColor) - 1;
			srcPix2 = ((unsigned) destinationWord) >> d2;
			destPix2 = srcPix2 & mask4;
			mask4 = mask4 << cmBitsPerColor;
			srcPix2 = ((unsigned) srcPix2) >> d2;
			destPix2 = (destPix2 + (srcPix2 & mask4)) + ((((unsigned) srcPix2) >> d2) & (mask4 << cmBitsPerColor));
			if (destPix2 == 0) {
				mapIndex = 1;
				goto l3;
			}
			mapIndex = destPix2;
			goto l3;
		}
	l3:	/* end rgbMap:from:to: */;
		longAtput(((((char *) colorMap)) + 4) + (mapIndex << 2), (longAt(((((char *) colorMap)) + 4) + (mapIndex << 2))) + 1);
	}
	return destinationWord;
}

int accessibleObjectAfter(int oop) {
    int obj;
    int sz;
    int extra;
    int header;
    int type;
    int extra1;
    int sz1;
    int extra2;
    int header1;
    int type1;
    int extra11;

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

int accurateLengthOfwith(int deltaX, int deltaY) {
    int length2;

	if (deltaX == 0) {
		if (deltaY < 0) {
			return 0 - deltaY;
		} else {
			return deltaY;
		}
	}
	if (deltaY == 0) {
		if (deltaX < 0) {
			return 0 - deltaX;
		} else {
			return deltaX;
		}
	}
	length2 = (deltaX * deltaX) + (deltaY * deltaY);
	/* begin computeSqrt: */
	if (length2 < 32) {
		return (smallSqrtTable())[length2];
	} else {
		return ((int) ((sqrt(((double) length2 ))) + 0.5) );
	}
	return null;
}

int addEdgeToGET(int edge) {
	if (!(allocateGETEntry(1))) {
		return 0;
	}
	getBuffer[workBuffer[12]] = edge;
	workBuffer[12] = ((workBuffer[12]) + 1);
}

int addToMethodCacheSelclassmethodprimIndex(int selector, int class, int meth, int primIndex) {
    int probe;
    int p;
    int hash;

	hash = selector ^ class;
	for (p = 0; p <= (3 - 1); p += 1) {
		probe = (((unsigned) hash) >> p) & 2044;
		if ((methodCache[probe + 1]) == 0) {
			methodCache[probe + 1] = selector;
			methodCache[probe + 2] = class;
			methodCache[probe + 3] = meth;
			methodCache[probe + 4] = primIndex;
			return null;
		}
	}
	probe = hash & 2044;
	methodCache[probe + 1] = selector;
	methodCache[probe + 2] = class;
	methodCache[probe + 3] = meth;
	methodCache[probe + 4] = primIndex;
	for (p = 1; p <= (3 - 1); p += 1) {
		probe = (((unsigned) hash) >> p) & 2044;
		methodCache[probe + 1] = 0;
	}
}

int addWordwith(int sourceWord, int destinationWord) {
	return sourceWord + destinationWord;
}

int adjustWideBezierLeftwidthoffsetendX(int bezier, int lineWidth, int lineOffset, int endX) {
    int lastX;
    int lastY;

	((objBuffer + bezier) + 10)[0] = ((((objBuffer + bezier) + 10)[0]) - (lineOffset * 256));
	lastX = ((objBuffer + bezier) + 22)[0];
	((objBuffer + bezier) + 22)[0] = (lastX + ((lineWidth - lineOffset) * 256));
	lastY = ((objBuffer + bezier) + 22)[1];
	((objBuffer + bezier) + 22)[1] = (lastY + (lineWidth * 256));
	objBuffer[bezier + 21] = (endX - lineOffset);
}

int adjustWideBezierRightwidthoffsetendX(int bezier, int lineWidth, int lineOffset, int endX) {
    int lastX;
    int lastY;

	((objBuffer + bezier) + 10)[0] = ((((objBuffer + bezier) + 10)[0]) + (lineOffset * 256));
	lastX = ((objBuffer + bezier) + 22)[0];
	((objBuffer + bezier) + 22)[0] = (lastX - ((lineWidth - lineOffset) * 256));
	lastY = ((objBuffer + bezier) + 22)[1];
	((objBuffer + bezier) + 22)[1] = (lastY + (lineWidth * 256));
	objBuffer[bezier + 21] = ((endX - lineOffset) + lineWidth);
}

int adjustWideLineafterSteppingFromto(int line, int lastX, int nextX) {
    int baseWidth;
    int deltaX;
    int yExit;
    int yEntry;
    int lineOffset;
    int xDir;
    int lineWidth;

	yEntry = objBuffer[line + 18];
	yExit = objBuffer[line + 19];
	baseWidth = objBuffer[line + 20];
	lineOffset = ((int) baseWidth >> 1);
	lineWidth = objBuffer[line + 17];
	xDir = objBuffer[line + 10];
	deltaX = nextX - lastX;
	if (yEntry < baseWidth) {
		if (xDir < 0) {
			lineWidth -= deltaX;
		} else {
			lineWidth += deltaX;
			objBuffer[line + 4] = lastX;
		}
	}
	if ((yExit + lineOffset) == 0) {
		if (xDir > 0) {
			lineWidth -= objBuffer[line + 12];
		} else {
			lineWidth += objBuffer[line + 12];
			objBuffer[line + 4] = lastX;
		}
	}
	if ((yExit + lineOffset) > 0) {
		if (xDir < 0) {
			lineWidth += deltaX;
			objBuffer[line + 4] = lastX;
		} else {
			lineWidth -= deltaX;
		}
	}
	objBuffer[line + 17] = lineWidth;
}

int allYoungand(int array1, int array2) {
    int fieldOffset;
    int methodHeader;
    int sz;
    int fmt;
    int header;
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

int allocateBitmapFillcolormap(int cmSize, int *cmBits) {
    int fill;
    int *cm;
    int i;
    int fillSize;

	fillSize = 18 + cmSize;
	if (!(allocateObjEntry(fillSize))) {
		return 0;
	}
	fill = objUsed;
	objUsed = fill + fillSize;
	objBuffer[fill + 0] = 1024;
	objBuffer[fill + 2] = 0;
	objBuffer[fill + 1] = fillSize;
	cm = (objBuffer + fill) + 18;
	if ((workBuffer[17]) != 0) {
		for (i = 0; i <= (cmSize - 1); i += 1) {
			cm[i] = (transformColor(cmBits[i]));
		}
	} else {
		for (i = 0; i <= (cmSize - 1); i += 1) {
			cm[i] = (cmBits[i]);
		}
	}
	objBuffer[fill + 15] = cmSize;
	return fill;
}

int allocateGETEntry(int nSlots) {
    int i;
    int srcIndex;
    int dstIndex;

	if (!(needAvailableSpace(nSlots))) {
		return 0;
	}
	if (!((workBuffer[14]) == 0)) {
		srcIndex = workBuffer[14];
		dstIndex = (workBuffer[14]) + nSlots;
		for (i = 1; i <= (workBuffer[14]); i += 1) {
			aetBuffer[dstIndex -= 1] = (aetBuffer[srcIndex -= 1]);
		}
	}
	aetBuffer += nSlots;
	return 1;
}

int allocateGradientFillrampWidthisRadial(int *ramp, int rampWidth, int isRadial) {
    int fill;
    int i;
    int *rampPtr;
    int fillSize;

	fillSize = 12 + rampWidth;
	if (!(allocateObjEntry(fillSize))) {
		return 0;
	}
	fill = objUsed;
	objUsed = fill + fillSize;
	if (isRadial) {
		objBuffer[fill + 0] = 768;
	} else {
		objBuffer[fill + 0] = 512;
	}
	objBuffer[fill + 2] = 0;
	objBuffer[fill + 1] = fillSize;
	rampPtr = (objBuffer + fill) + 12;
	if ((workBuffer[17]) != 0) {
		for (i = 0; i <= (rampWidth - 1); i += 1) {
			rampPtr[i] = (transformColor(ramp[i]));
		}
	} else {
		for (i = 0; i <= (rampWidth - 1); i += 1) {
			rampPtr[i] = (ramp[i]);
		}
	}
	objBuffer[fill + 10] = rampWidth;
	return fill;
}

int allocateObjEntry(int nSlots) {
    int i;
    int srcIndex;
    int dstIndex;

	if (!(allocateGETEntry(nSlots))) {
		return 0;
	}
	if (!((workBuffer[12]) == 0)) {
		srcIndex = workBuffer[12];
		dstIndex = (workBuffer[12]) + nSlots;
		for (i = 1; i <= (workBuffer[12]); i += 1) {
			getBuffer[dstIndex -= 1] = (getBuffer[srcIndex -= 1]);
		}
	}
	getBuffer += nSlots;
	return 1;
}

int alphaBlendwith(int sourceWord, int destinationWord) {
    int shift;
    int alpha;
    int i;
    int blend;
    int unAlpha;
    int result;
    int colorMask;

	alpha = ((unsigned) sourceWord) >> 24;
	unAlpha = 255 - alpha;
	colorMask = 255;
	result = 0;
	for (i = 1; i <= 3; i += 1) {
		shift = (i - 1) * 8;
		blend = ((((((((unsigned) sourceWord) >> shift) & colorMask) * alpha) + (((((unsigned) destinationWord) >> shift) & colorMask) * unAlpha)) + 254) / 255) & colorMask;
		result = result | (blend << shift);
	}
	return result;
}

int alphaBlendConstwith(int sourceWord, int destinationWord) {
	return alphaBlendConstwithpaintMode(sourceWord, destinationWord, 0);
}

int alphaBlendConstwithpaintMode(int sourceWord, int destinationWord, int paintMode) {
    int j;
    int destPixVal;
    int pixMask;
    int destShifted;
    int sourceShifted;
    int sourcePixVal;
    int pixBlend;
    int shift;
    int blend;
    int maskShifted;
    int bitsPerColor;
    int i;
    int unAlpha;
    int result;
    int rgbMask;

	if (destPixSize < 16) {
		return destinationWord;
	}
	unAlpha = 255 - sourceAlpha;
	pixMask = maskTable[destPixSize];
	if (destPixSize == 16) {
		bitsPerColor = 5;
	} else {
		bitsPerColor = 8;
	}
	rgbMask = (1 << bitsPerColor) - 1;
	maskShifted = destMask;
	destShifted = destinationWord;
	sourceShifted = sourceWord;
	result = destinationWord;
	for (j = 1; j <= pixPerWord; j += 1) {
		sourcePixVal = sourceShifted & pixMask;
		if (!(((maskShifted & pixMask) == 0) || (paintMode && (sourcePixVal == 0)))) {
			destPixVal = destShifted & pixMask;
			pixBlend = 0;
			for (i = 1; i <= 3; i += 1) {
				shift = (i - 1) * bitsPerColor;
				blend = ((((((((unsigned) sourcePixVal) >> shift) & rgbMask) * sourceAlpha) + (((((unsigned) destPixVal) >> shift) & rgbMask) * unAlpha)) + 254) / 255) & rgbMask;
				pixBlend = pixBlend | (blend << shift);
			}
			if (destPixSize == 16) {
				result = (result & (~(pixMask << ((j - 1) * 16)))) | (pixBlend << ((j - 1) * 16));
			} else {
				result = pixBlend;
			}
		}
		maskShifted = ((unsigned) maskShifted) >> destPixSize;
		sourceShifted = ((unsigned) sourceShifted) >> destPixSize;
		destShifted = ((unsigned) destShifted) >> destPixSize;
	}
	return result;
}

int alphaBlendScaledwith(int sourceWord, int destinationWord) {
    int dstMask;
    int srcMask;
    int b;
    int a;
    int unAlpha;
    int g;
    int r;

	unAlpha = 255 - (((unsigned) sourceWord) >> 24);
	dstMask = destinationWord;
	srcMask = sourceWord;
	b = (((unsigned) ((dstMask & 255) * unAlpha)) >> 8) + (srcMask & 255);
	if (b > 255) {
		b = 255;
	}
	dstMask = ((unsigned) dstMask) >> 8;
	srcMask = ((unsigned) srcMask) >> 8;
	g = (((unsigned) ((dstMask & 255) * unAlpha)) >> 8) + (srcMask & 255);
	if (g > 255) {
		g = 255;
	}
	dstMask = ((unsigned) dstMask) >> 8;
	srcMask = ((unsigned) srcMask) >> 8;
	r = (((unsigned) ((dstMask & 255) * unAlpha)) >> 8) + (srcMask & 255);
	if (r > 255) {
		r = 255;
	}
	dstMask = ((unsigned) dstMask) >> 8;
	srcMask = ((unsigned) srcMask) >> 8;
	a = (((unsigned) ((dstMask & 255) * unAlpha)) >> 8) + (srcMask & 255);
	if (a > 255) {
		a = 255;
	}
	return (((((a << 8) + r) << 8) + g) << 8) + b;
}

int alphaPaintConstwith(int sourceWord, int destinationWord) {
	if (sourceWord == 0) {
		return destinationWord;
	}
	return alphaBlendConstwithpaintMode(sourceWord, destinationWord, 1);
}

int alphaSourceBlendBits16(void) {
    int deltaX;
    int deltaY;
    int srcIndex;
    int dstIndex;
    int sourceWord;
    int srcAlpha;
    int destWord;
    int srcY;
    int dstY;
    int dstMask;
    int srcShift;
    int ditherBase;
    int ditherIndex;
    int ditherThreshold;
    int pv;
    int value;
    int threshold;
    int out;
    int pv1;
    int value1;
    int threshold1;
    int out1;

	deltaY = bbH + 1;
	srcY = sy;
	dstY = dy;
	if ((dx & 1) == 0) {
		mask1 = 65535;
		srcShift = 16;
	} else {
		mask1 = 4294901760U;
		srcShift = 0;
	}
	while ((deltaY -= 1) != 0) {
		srcIndex = (sourceBits + 4) + (((srcY * sourceRaster) + sx) * 4);
		dstIndex = (destBits + 4) + (((dstY * destRaster) + (((int) dx >> 1))) * 4);
		ditherBase = (dstY & 3) * 4;
		ditherIndex = (sx & 3) - 1;
		deltaX = bbW + 1;
		dstMask = mask1;
		if (dstMask == 65535) {
			srcShift = 16;
		} else {
			srcShift = 0;
		}
		while ((deltaX -= 1) != 0) {
			ditherThreshold = ditherMatrix4x4[ditherBase + (ditherIndex = (ditherIndex + 1) & 3)];
			sourceWord = longAt(srcIndex);
			srcAlpha = ((unsigned) sourceWord) >> 24;
			if (srcAlpha == 255) {
				/* begin dither32To16:threshold: */
				pv = sourceWord & 255;
				threshold = ditherThresholds16[pv & 7];
				value = ditherValues16[((unsigned) pv >> 3)];
				if (ditherThreshold < threshold) {
					out = value + 1;
				} else {
					out = value;
				}
				pv = (((unsigned) sourceWord >> 8)) & 255;
				threshold = ditherThresholds16[pv & 7];
				value = ditherValues16[((unsigned) pv >> 3)];
				if (ditherThreshold < threshold) {
					out = out | (((unsigned) (value + 1) << 5));
				} else {
					out = out | (((unsigned) value << 5));
				}
				pv = (((unsigned) sourceWord >> 16)) & 255;
				threshold = ditherThresholds16[pv & 7];
				value = ditherValues16[((unsigned) pv >> 3)];
				if (ditherThreshold < threshold) {
					out = out | (((unsigned) (value + 1) << 10));
				} else {
					out = out | (((unsigned) value << 10));
				}
				sourceWord = out;
				if (sourceWord == 0) {
					sourceWord = 1;
				}
				sourceWord = sourceWord << srcShift;
				destWord = longAt(dstIndex);
				destWord = destWord & dstMask;
				longAtput(dstIndex, sourceWord | destWord);
			} else {
				if (srcAlpha == 0) {
					null;
				} else {
					destWord = longAt(dstIndex);
					destWord = destWord & (~dstMask);
					destWord = ((unsigned) destWord) >> srcShift;
					destWord = ((((unsigned) (destWord & 31744) << 9)) | (((unsigned) (destWord & 992) << 6))) | ((((unsigned) (destWord & 31) << 3)) | 4278190080U);
					sourceWord = alphaBlendScaledwith(sourceWord, destWord);
					/* begin dither32To16:threshold: */
					pv1 = sourceWord & 255;
					threshold1 = ditherThresholds16[pv1 & 7];
					value1 = ditherValues16[((unsigned) pv1 >> 3)];
					if (ditherThreshold < threshold1) {
						out1 = value1 + 1;
					} else {
						out1 = value1;
					}
					pv1 = (((unsigned) sourceWord >> 8)) & 255;
					threshold1 = ditherThresholds16[pv1 & 7];
					value1 = ditherValues16[((unsigned) pv1 >> 3)];
					if (ditherThreshold < threshold1) {
						out1 = out1 | (((unsigned) (value1 + 1) << 5));
					} else {
						out1 = out1 | (((unsigned) value1 << 5));
					}
					pv1 = (((unsigned) sourceWord >> 16)) & 255;
					threshold1 = ditherThresholds16[pv1 & 7];
					value1 = ditherValues16[((unsigned) pv1 >> 3)];
					if (ditherThreshold < threshold1) {
						out1 = out1 | (((unsigned) (value1 + 1) << 10));
					} else {
						out1 = out1 | (((unsigned) value1 << 10));
					}
					sourceWord = out1;
					if (sourceWord == 0) {
						sourceWord = 1;
					}
					sourceWord = sourceWord << srcShift;
					destWord = longAt(dstIndex);
					destWord = destWord & dstMask;
					longAtput(dstIndex, sourceWord | destWord);
				}
			}
			srcIndex += 4;
			if (srcShift == 0) {
				dstIndex += 4;
			}
			srcShift = srcShift ^ 16;
			dstMask = ~dstMask;
		}
		srcY += 1;
		dstY += 1;
	}
}

int alphaSourceBlendBits32(void) {
    register int deltaX;
    int deltaY;
    register int srcIndex;
    register int dstIndex;
    register int sourceWord;
    int srcAlpha;
    int destWord;
    int srcY;
    int dstY;

	deltaY = bbH + 1;
	srcY = sy;
	dstY = dy;
	while ((deltaY -= 1) != 0) {
		srcIndex = (sourceBits + 4) + (((srcY * sourceRaster) + sx) * 4);
		dstIndex = (destBits + 4) + (((dstY * destRaster) + dx) * 4);
		deltaX = bbW + 1;
		while ((deltaX -= 1) != 0) {
			sourceWord = longAt(srcIndex);
			srcAlpha = ((unsigned) sourceWord) >> 24;
			if (srcAlpha == 255) {
				longAtput(dstIndex, sourceWord);
				srcIndex += 4;
				dstIndex += 4;
				while (((deltaX -= 1) != 0) && ((((unsigned) (sourceWord = longAt(srcIndex))) >> 24) == 255)) {
					longAtput(dstIndex, sourceWord);
					srcIndex += 4;
					dstIndex += 4;
				}
				deltaX += 1;
			} else {
				if (srcAlpha == 0) {
					srcIndex += 4;
					dstIndex += 4;
					while (((deltaX -= 1) != 0) && ((((unsigned) (sourceWord = longAt(srcIndex))) >> 24) == 0)) {
						srcIndex += 4;
						dstIndex += 4;
					}
					deltaX += 1;
				} else {
					destWord = longAt(dstIndex);
					destWord = alphaBlendScaledwith(sourceWord, destWord);
					longAtput(dstIndex, destWord);
					srcIndex += 4;
					dstIndex += 4;
				}
			}
		}
		srcY += 1;
		dstY += 1;
	}
}

int alphaSourceBlendBits8(void) {
    int deltaX;
    int deltaY;
    int srcIndex;
    int dstIndex;
    int sourceWord;
    int srcAlpha;
    int destWord;
    int srcY;
    int dstY;
    int dstMask;
    int srcShift;
    int adjust;
    unsigned int *mappingTable;
    int mask;
    int srcPix;
    int destPix;
    int d;

	mappingTable = default8To32Table();
	deltaY = bbH + 1;
	srcY = sy;
	dstY = dy;
	mask1 = 24 - ((dx & 3) * 8);
	mask2 = 4294967295U ^ (255 << mask1);
	if ((dx & 1) == 0) {
		adjust = 0;
	} else {
		adjust = 522133279;
	}
	if ((dy & 1) == 0) {
		adjust = adjust ^ 522133279;
	}
	while ((deltaY -= 1) != 0) {
		adjust = adjust ^ 522133279;
		srcIndex = (sourceBits + 4) + (((srcY * sourceRaster) + sx) * 4);
		dstIndex = (destBits + 4) + (((dstY * destRaster) + (((int) dx >> 2))) * 4);
		deltaX = bbW + 1;
		srcShift = mask1;
		dstMask = mask2;
		while ((deltaX -= 1) != 0) {
			sourceWord = ((longAt(srcIndex)) & (~adjust)) + adjust;
			srcAlpha = ((unsigned) sourceWord) >> 24;
			if (srcAlpha > 31) {
				if (srcAlpha < 224) {
					destWord = longAt(dstIndex);
					destWord = destWord & (~dstMask);
					destWord = ((unsigned) destWord) >> srcShift;
					destWord = mappingTable[destWord];
					sourceWord = alphaBlendScaledwith(sourceWord, destWord);
				}
				/* begin rgbMap:from:to: */
				if ((d = cmBitsPerColor - 8) > 0) {
					mask = (1 << 8) - 1;
					srcPix = sourceWord << d;
					mask = mask << d;
					destPix = srcPix & mask;
					mask = mask << cmBitsPerColor;
					srcPix = srcPix << d;
					sourceWord = (destPix + (srcPix & mask)) + ((srcPix << d) & (mask << cmBitsPerColor));
					goto l1;
				} else {
					if (d == 0) {
						if (8 == 5) {
							sourceWord = sourceWord & 32767;
							goto l1;
						}
						if (8 == 8) {
							sourceWord = sourceWord & 16777215;
							goto l1;
						}
						sourceWord = sourceWord;
						goto l1;
					}
					if (sourceWord == 0) {
						sourceWord = sourceWord;
						goto l1;
					}
					d = 8 - cmBitsPerColor;
					mask = (1 << cmBitsPerColor) - 1;
					srcPix = ((unsigned) sourceWord) >> d;
					destPix = srcPix & mask;
					mask = mask << cmBitsPerColor;
					srcPix = ((unsigned) srcPix) >> d;
					destPix = (destPix + (srcPix & mask)) + ((((unsigned) srcPix) >> d) & (mask << cmBitsPerColor));
					if (destPix == 0) {
						sourceWord = 1;
						goto l1;
					}
					sourceWord = destPix;
					goto l1;
				}
			l1:	/* end rgbMap:from:to: */;
				sourceWord = longAt(((((char *) colorMap)) + 4) + (sourceWord << 2));
				sourceWord = sourceWord << srcShift;
				destWord = longAt(dstIndex);
				destWord = destWord & dstMask;
				longAtput(dstIndex, sourceWord | destWord);
			}
			srcIndex += 4;
			if (srcShift == 0) {
				dstIndex += 4;
				srcShift = 24;
				dstMask = 16777215;
			} else {
				srcShift -= 8;
				dstMask = (((unsigned) dstMask) >> 8) | 4278190080U;
			}
			adjust = adjust ^ 522133279;
		}
		srcY += 1;
		dstY += 1;
	}
}

int argumentCountOf(int methodPointer) {
	return (((unsigned) (longAt(((((char *) methodPointer)) + 4) + (0 << 2)))) >> 25) & 15;
}

void * arrayValueOf(int arrayOop) {
	if ((!((arrayOop & 1))) && (isWordsOrBytes(arrayOop))) {
		return (void *) (arrayOop + 4);
	}
	/* begin primitiveFail */
	successFlag = 0;
}

int asciiDirectoryDelimiter(void) {
	return dir_Delimitor();
}

int asciiOfCharacter(int characterObj) {
    int ccIndex;
    int cl;

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

AsyncFile * asyncFileValueOf(int oop) {
    int successValue;

	/* begin success: */
	successValue = (!((oop & 1))) && ((((((unsigned) (longAt(oop))) >> 8) & 15) >= 8) && ((lengthOf(oop)) == (sizeof(AsyncFile))));
	successFlag = successValue && successFlag;
	if (!(successFlag)) {
		return null;
	}
	return (AsyncFile *) (oop + 4);
}

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

int becomewithtwoWay(int array1, int array2, int twoWayFlag) {
    int fieldOffset;
    int oop1;
    int oop2;
    int hdr1;
    int hdr2;
    int fwdBlock;
    int fwdHeader;
    int fwdBlock1;
    int fwdHeader1;
    int fwdBlock2;
    int oop11;
    int oop21;
    int hdr11;
    int hdr21;
    int methodHeader;
    int sz;
    int fmt;
    int header;
    int fwdBlock3;
    int fwdHeader2;
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
			fwdBlock3 = (fwdHeader2 & 2147483644) << 1;
			;
			longAtput(oop11, longAt(fwdBlock3 + 4));
			hdr11 = longAt(oop11);
			hdr21 = longAt(oop21);
			longAtput(oop21, (hdr21 & 3758227455U) | (hdr11 & 536739840));
			fwdBlock2 += 16;
		}
	}
	initializeMemoryFirstFree(freeBlock);
	return 1;
}

int bitAndwith(int sourceWord, int destinationWord) {
	return sourceWord & destinationWord;
}

int bitAndInvertwith(int sourceWord, int destinationWord) {
	return sourceWord & (~destinationWord);
}

int bitInvertAndwith(int sourceWord, int destinationWord) {
	return (~sourceWord) & destinationWord;
}

int bitInvertAndInvertwith(int sourceWord, int destinationWord) {
	return (~sourceWord) & (~destinationWord);
}

int bitInvertDestinationwith(int sourceWord, int destinationWord) {
	return ~destinationWord;
}

int bitInvertOrwith(int sourceWord, int destinationWord) {
	return (~sourceWord) | destinationWord;
}

int bitInvertOrInvertwith(int sourceWord, int destinationWord) {
	return (~sourceWord) | (~destinationWord);
}

int bitInvertSourcewith(int sourceWord, int destinationWord) {
	return ~sourceWord;
}

int bitInvertXorwith(int sourceWord, int destinationWord) {
	return (~sourceWord) ^ destinationWord;
}

int bitOrwith(int sourceWord, int destinationWord) {
	return sourceWord | destinationWord;
}

int bitOrInvertwith(int sourceWord, int destinationWord) {
	return sourceWord | (~destinationWord);
}

int bitXorwith(int sourceWord, int destinationWord) {
	return sourceWord ^ destinationWord;
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

int byteLengthOf(int oop) {
    int sz;
    int header;
    int fmt;

	header = longAt(oop);
	if ((header & 3) == 0) {
		sz = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	fmt = (((unsigned) header) >> 8) & 15;
	if (fmt < 8) {
		return sz - 4;
	} else {
		return (sz - 4) - (fmt & 3);
	}
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
l2:	/* end lengthOf:baseHeader:format: */;
l1:	/* end slotSizeOf: */;
	if (((((unsigned) (longAt(oop))) >> 8) & 15) >= 8) {
		return slots;
	} else {
		return slots * 4;
	}
}

int byteSwapped(int w) {
	return ((((((unsigned) w >> 24)) & 255) + ((((unsigned) w >> 8)) & 65280)) + ((((unsigned) w << 8)) & 16711680)) + ((((unsigned) w << 24)) & 4278190080U);
}

int bytecodeActivateNewMethod(void) {
    int methodHeader;
    int i;
    int nilOop;
    int tempCount;
    int newContext;
    int initialIP;
    int cntxt;
    int tmp;

	methodHeader = longAt(((((char *) newMethod)) + 4) + (0 << 2));
	/* begin allocateOrRecycleContext */
	if (freeContexts != 1) {
		cntxt = freeContexts;
		freeContexts = longAt(((((char *) cntxt)) + 4) + (0 << 2));
		newContext = cntxt;
		goto l1;
	}
	cntxt = instantiateContextsizeInBytes(longAt(((((char *) specialObjectsOop)) + 4) + (10 << 2)), 156);
	longAtput(((((char *) cntxt)) + 4) + (4 << 2), nilObj);
	newContext = cntxt;
l1:	/* end allocateOrRecycleContext */;
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
}

int characterTable(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (24 << 2));
}

int checkCompressedFillIndexListmaxsegments(int fillList, int maxIndex, int nSegs) {
    int i;
    int length;
    int *fillPtr;
    int runLength;
    int runValue;
    int nFills;
    int header;
    int sz;

	/* begin slotSizeOf: */
	if ((fillList & 1)) {
		length = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(fillList);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(fillList - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		length = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		length = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
l1:	/* end slotSizeOf: */;
	fillPtr = firstIndexableField(fillList);
	nFills = 0;
	for (i = 0; i <= (length - 1); i += 1) {
		runLength = ((unsigned) ((((int *) fillPtr))[i]) >> 16);
		runValue = ((((int *) fillPtr))[0]) & 65535;
		if (!((runValue >= 0) && (runValue <= maxIndex))) {
			return 0;
		}
		nFills += runLength;
	}
	return nFills == nSegs;
}

int checkCompressedFills(int indexList) {
    int fillIndex;
    int i;
    int *fillPtr;
    int length;
    int header;
    int sz;

	if (!(((((unsigned) (longAt(indexList))) >> 8) & 15) == 6)) {
		return 0;
	}
	/* begin slotSizeOf: */
	if ((indexList & 1)) {
		length = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(indexList);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(indexList - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		length = ((unsigned) (sz - 4)) >> 2;
		goto l1;
	} else {
		length = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l1;
	}
	length = null;
l1:	/* end slotSizeOf: */;
	fillPtr = firstIndexableField(indexList);
	for (i = 1; i <= length; i += 1) {
		fillIndex = fillPtr[0];
		if (!(isFillOkay(fillIndex))) {
			return 0;
		}
		fillPtr += 1;
	}
	return 1;
}

int checkCompressedLineWidthssegments(int lineWidthList, int nSegments) {
    int *ptr;
    int i;
    int length;
    int runLength;
    int nItems;
    int header;
    int sz;

	/* begin slotSizeOf: */
	if ((lineWidthList & 1)) {
		length = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(lineWidthList);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(lineWidthList - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		length = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		length = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
l1:	/* end slotSizeOf: */;
	ptr = firstIndexableField(lineWidthList);
	nItems = 0;
	for (i = 0; i <= (length - 1); i += 1) {
		runLength = ((unsigned) ((((int *) ptr))[i]) >> 16);
		nItems += runLength;
	}
	return nItems == nSegments;
}

int checkCompressedPointssegments(int points, int nSegments) {
    int pSize;
    int header;
    int sz;

	if (!(((((unsigned) (longAt(points))) >> 8) & 15) == 6)) {
		return 0;
	}
	/* begin slotSizeOf: */
	if ((points & 1)) {
		pSize = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(points);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(points - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		pSize = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		pSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
l1:	/* end slotSizeOf: */;
	if (!((pSize == (nSegments * 3)) || (pSize == (nSegments * 6)))) {
		return 0;
	}
	return 1;
}

int checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(int points, int nSegments, int leftFills, int rightFills, int lineWidths, int lineFills, int fillIndexList) {
    int maxFillIndex;
    int header;
    int sz;

	if (!(checkCompressedPointssegments(points, nSegments))) {
		return 0;
	}
	if (!(checkCompressedFills(fillIndexList))) {
		return 0;
	}
	/* begin slotSizeOf: */
	if ((fillIndexList & 1)) {
		maxFillIndex = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(fillIndexList);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(fillIndexList - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		maxFillIndex = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		maxFillIndex = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
l1:	/* end slotSizeOf: */;
	if (!(checkCompressedFillIndexListmaxsegments(leftFills, maxFillIndex, nSegments))) {
		return 0;
	}
	if (!(checkCompressedFillIndexListmaxsegments(rightFills, maxFillIndex, nSegments))) {
		return 0;
	}
	if (!(checkCompressedFillIndexListmaxsegments(lineFills, maxFillIndex, nSegments))) {
		return 0;
	}
	if (!(checkCompressedLineWidthssegments(lineWidths, nSegments))) {
		return 0;
	}
	return 1;
}

int checkForInterrupts(void) {
    int sema;
    int now;
    int sema1;
    int i;
    int xArray;
    int index;
    int xSize;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

	interruptCheckCounter = 1000;
	now = (ioMSecs()) & 536870911;
	if (now < lastTick) {
		nextPollTick = now + (nextPollTick - lastTick);
		if (nextWakeupTick != 0) {
			nextWakeupTick = now + (nextWakeupTick - lastTick);
		}
	}
	lastTick = now;
	if (signalLowSpace) {
		signalLowSpace = 0;
		sema = longAt(((((char *) specialObjectsOop)) + 4) + (17 << 2));
		if (!(sema == nilObj)) {
			synchronousSignal(sema);
		}
	}
	if (now >= nextPollTick) {
		ioProcessEvents();
		nextPollTick = now + 100;
	}
	if (interruptPending) {
		interruptPending = 0;
		sema = longAt(((((char *) specialObjectsOop)) + 4) + (30 << 2));
		if (!(sema == nilObj)) {
			synchronousSignal(sema);
		}
	}
	if ((nextWakeupTick != 0) && (now >= nextWakeupTick)) {
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
	if (semaphoresToSignalCount > 0) {
		/* begin signalExternalSemaphores */
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
			goto l2;
		} else {
			totalLength = (sz - 4) - (fmt & 3);
			goto l2;
		}
	l2:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l1;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l1;
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
	l1:	/* end fixedFieldsOf:format:length: */;
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
		for (i = 1; i <= semaphoresToSignalCount; i += 1) {
			index = semaphoresToSignal[i];
			if ((index > 0) && (index <= xSize)) {
				sema1 = longAt(((((char *) xArray)) + 4) + ((index - 1) << 2));
				if ((fetchClassOf(sema1)) == (longAt(((((char *) specialObjectsOop)) + 4) + (18 << 2)))) {
					synchronousSignal(sema1);
				}
			}
		}
		semaphoresToSignalCount = 0;
	}
}

int checkImageVersionFromstartingAt(sqImageFile f, int imageOffset) {
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

int checkedIntegerValueOf(int intOop) {
	if ((intOop & 1)) {
		return (intOop >> 1);
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
}

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

double * circleCosTable(void) {
    static double theTable[33] =
		{1.0, 0.98078528040323, 0.923879532511287, 0.831469612302545,
		0.7071067811865475, 0.555570233019602, 0.38268343236509, 0.1950903220161286,
		0.0, -0.1950903220161283, -0.3826834323650896, -0.555570233019602,
		-0.707106781186547, -0.831469612302545, -0.9238795325112865, -0.98078528040323,
		-1.0, -0.98078528040323, -0.923879532511287, -0.831469612302545,
		-0.707106781186548, -0.555570233019602, -0.3826834323650903, -0.1950903220161287,
		0.0, 0.1950903220161282, 0.38268343236509, 0.555570233019602,
		0.707106781186547, 0.831469612302545, 0.9238795325112865, 0.98078528040323,
		1.0 };

	return theTable;
}

double * circleSinTable(void) {
    static double theTable[33] =
		{0.0, 0.1950903220161282, 0.3826834323650897, 0.555570233019602,
		0.707106781186547, 0.831469612302545, 0.923879532511287, 0.98078528040323,
		1.0, 0.98078528040323, 0.923879532511287, 0.831469612302545,
		0.7071067811865475, 0.555570233019602, 0.38268343236509, 0.1950903220161286,
		0.0, -0.1950903220161283, -0.3826834323650896, -0.555570233019602,
		-0.707106781186547, -0.831469612302545, -0.9238795325112865, -0.98078528040323,
		-1.0, -0.98078528040323, -0.923879532511287, -0.831469612302545,
		-0.707106781186548, -0.555570233019602, -0.3826834323650903, -0.1950903220161287,
		 0.0 };

	return theTable;
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

int classFloat(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2));
}

int classLargePositiveInteger(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (13 << 2));
}

int classNameOfIs(int aClass, char *className) {
    char *srcName;
    int i;
    int name;
    int length;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
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
		goto l2;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l1;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l1;
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
l1:	/* end fixedFieldsOf:format:length: */;
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

int clearSpanBuffer(void) {
    int x0;
    int x1;

	x0 = ((unsigned) (workBuffer[32])) >> (workBuffer[49]);
	x1 = (((unsigned) (workBuffer[34])) >> (workBuffer[49])) + 1;
	if (x0 < 0) {
		x0 = 0;
	}
	if (x1 > (workBuffer[33])) {
		x1 = workBuffer[33];
	}
	while (x0 < x1) {
		spanBuffer[x0] = 0;
		x0 += 1;
	}
	workBuffer[32] = (workBuffer[33]);
	workBuffer[34] = 0;
}

int clearWordwith(int source, int destination) {
	return 0;
}

int clipRange(void) {
	if (destX >= clipX) {
		sx = sourceX;
		dx = destX;
		bbW = width;
	} else {
		sx = sourceX + (clipX - destX);
		bbW = width - (clipX - destX);
		dx = clipX;
	}
	if ((dx + bbW) > (clipX + clipWidth)) {
		bbW -= (dx + bbW) - (clipX + clipWidth);
	}
	if (destY >= clipY) {
		sy = sourceY;
		dy = destY;
		bbH = height;
	} else {
		sy = (sourceY + clipY) - destY;
		bbH = height - (clipY - destY);
		dy = clipY;
	}
	if ((dy + bbH) > (clipY + clipHeight)) {
		bbH -= (dy + bbH) - (clipY + clipHeight);
	}
	if (noSource) {
		return null;
	}
	if (sx < 0) {
		dx -= sx;
		bbW += sx;
		sx = 0;
	}
	if ((sx + bbW) > srcWidth) {
		bbW -= (sx + bbW) - srcWidth;
	}
	if (sy < 0) {
		dy -= sy;
		bbH += sy;
		sy = 0;
	}
	if ((sy + bbH) > srcHeight) {
		bbH -= (sy + bbH) - srcHeight;
	}
}

int clone(int oop) {
    int hash;
    int fromIndex;
    int lastFrom;
    int bytes;
    int extraHdrBytes;
    int remappedOop;
    int toIndex;
    int newOop;
    int newChunk;
    int header;
    int oop1;
    int type;
    int extra;
    int header1;
    int newFreeSize;
    int enoughSpace;
    int newChunk1;
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
	toIndex = newChunk - 4;
	fromIndex = (remappedOop - extraHdrBytes) - 4;
	lastFrom = fromIndex + bytes;
	while (fromIndex < lastFrom) {
		longAtput(toIndex += 4, longAt(fromIndex += 4));
	}
	newOop = newChunk + extraHdrBytes;
	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;
	header = (longAt(newOop)) & 131071;
	header = header | ((hash << 17) & 536739840);
	longAtput(newOop, header);
	return newOop;
}

int commonAt(int stringy) {
    int index;
    int rcvr;
    int atIx;
    int result;
    int sp;
    int sp1;

	index = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	rcvr = longAt(stackPointer - (1 * 4));
	if (!(successFlag && (!((rcvr & 1))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((messageSelector == (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((16 * 2) << 2)))) && (lkupClass == (fetchClassOfNonInt(rcvr)))) {
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

int commonAtPut(int stringy) {
    int value;
    int index;
    int rcvr;
    int atIx;
    int stSize;
    int valToPut;
    int fmt;
    int fixedFields;
    int sp;
    int sp1;

	value = longAt(stackPointer - (0 * 4));
	index = positive32BitValueOf(longAt(stackPointer - (1 * 4)));
	rcvr = longAt(stackPointer - (2 * 4));
	if (!(successFlag && (!((rcvr & 1))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((messageSelector == (longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((17 * 2) << 2)))) && (lkupClass == (fetchClassOfNonInt(rcvr)))) {
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
					byteAtput(((((char *) rcvr)) + 4) + (index - 1), (valToPut >> 1));
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

int commonVariableatcacheIndex(int rcvr, int index, int atIx) {
    int stSize;
    int fmt;
    int fixedFields;
    int result;

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

int compare31or32Bitsequal(int obj1, int obj2) {
	if (((obj1 & 1)) && ((obj2 & 1))) {
		return obj1 == obj2;
	}
	return (positive32BitValueOf(obj1)) == (positive32BitValueOf(obj2));
}

int compilerActivateMethod(void) {
	return compilerHooks[1]();
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

int computeBeziersplitAt(int index, double param) {
    int viaX;
    int viaY;
    int sharedX;
    int sharedY;
    int startX;
    int startY;
    int leftViaX;
    int leftViaY;
    int rightViaX;
    int rightViaY;
    int endX;
    int endY;
    int newIndex;

	leftViaX = startX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)];
	leftViaY = startY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)];
	rightViaX = viaX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)];
	rightViaY = viaY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)];
	endX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)];
	endY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)];
	sharedX = leftViaX += ((int) ((((double) (viaX - startX) )) * param) );
	sharedY = leftViaY += ((int) ((((double) (viaY - startY) )) * param) );
	rightViaX += ((int) ((((double) (endX - viaX) )) * param) );
	rightViaY += ((int) ((((double) (endY - viaY) )) * param) );
	sharedX += ((int) ((((double) (rightViaX - leftViaX) )) * param) );
	sharedY += ((int) ((((double) (rightViaY - leftViaY) )) * param) );
	/* begin assureValue:between:and: */
	if (startY > sharedY) {
		if (leftViaY > startY) {
			leftViaY = startY;
			goto l1;
		}
		if (leftViaY < sharedY) {
			leftViaY = sharedY;
			goto l1;
		}
	} else {
		if (leftViaY < startY) {
			leftViaY = startY;
			goto l1;
		}
		if (leftViaY > sharedY) {
			leftViaY = sharedY;
			goto l1;
		}
	}
	leftViaY = leftViaY;
l1:	/* end assureValue:between:and: */;
	/* begin assureValue:between:and: */
	if (sharedY > endY) {
		if (rightViaY > sharedY) {
			rightViaY = sharedY;
			goto l2;
		}
		if (rightViaY < endY) {
			rightViaY = endY;
			goto l2;
		}
	} else {
		if (rightViaY < sharedY) {
			rightViaY = sharedY;
			goto l2;
		}
		if (rightViaY > endY) {
			rightViaY = endY;
			goto l2;
		}
	}
	rightViaY = rightViaY;
l2:	/* end assureValue:between:and: */;
	/* begin allocateBezierStackEntry */
	/* begin wbStackPush: */
	if (!(needAvailableSpace(6))) {
		goto l3;
	}
	workBuffer[10] = ((workBuffer[10]) - 6);
l3:	/* end wbStackPush: */;
	newIndex = (workBuffer[1]) - (workBuffer[10]);
	if (engineStopped) {
		return 0;
	}
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)] = leftViaX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)] = leftViaY;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)] = sharedX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)] = sharedY;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 0)] = sharedX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 1)] = sharedY;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 2)] = rightViaX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 3)] = rightViaY;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 4)] = endX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 5)] = endY;
	return newIndex;
}

int computeBezierSplitAtHalf(int index) {
    int viaX;
    int viaY;
    int sharedX;
    int sharedY;
    int startX;
    int startY;
    int leftViaX;
    int leftViaY;
    int rightViaX;
    int rightViaY;
    int endX;
    int endY;
    int newIndex;

	/* begin allocateBezierStackEntry */
	/* begin wbStackPush: */
	if (!(needAvailableSpace(6))) {
		goto l1;
	}
	workBuffer[10] = ((workBuffer[10]) - 6);
l1:	/* end wbStackPush: */;
	newIndex = (workBuffer[1]) - (workBuffer[10]);
	if (engineStopped) {
		return 0;
	}
	leftViaX = startX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)];
	leftViaY = startY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)];
	rightViaX = viaX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)];
	rightViaY = viaY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)];
	endX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)];
	endY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)];
	leftViaX += ((int) (viaX - startX) >> 1);
	leftViaY += ((int) (viaY - startY) >> 1);
	sharedX = rightViaX += ((int) (endX - viaX) >> 1);
	sharedY = rightViaY += ((int) (endY - viaY) >> 1);
	sharedX += ((int) (leftViaX - rightViaX) >> 1);
	sharedY += ((int) (leftViaY - rightViaY) >> 1);
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)] = leftViaX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)] = leftViaY;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)] = sharedX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)] = sharedY;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 0)] = sharedX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 1)] = sharedY;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 2)] = rightViaX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 3)] = rightViaY;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 4)] = endX;
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - newIndex) + 5)] = endY;
	return newIndex;
}

int computeFinalWideBezierValueswidth(int bezier, int lineWidth) {
    int leftX;
    int rightX;
    int temp;

	leftX = ((int) (((objBuffer + bezier) + 10)[0]) >> 8);
	rightX = ((int) (((objBuffer + bezier) + 22)[0]) >> 8);
	if (leftX > rightX) {
		temp = leftX;
		leftX = rightX;
		rightX = temp;
	}
	objBuffer[bezier + 4] = leftX;
	if ((rightX - leftX) > lineWidth) {
		objBuffer[bezier + 17] = (rightX - leftX);
	} else {
		objBuffer[bezier + 17] = lineWidth;
	}
}

int containOnlyOopsand(int array1, int array2) {
    int fieldOffset;
    int methodHeader;
    int sz;
    int fmt;
    int header;
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

int copyBits(void) {
    int done;
    int integerPointer;
    int dWid;
    int sxLowBits;
    int dxLowBits;
    int pixPerM1;
    int t;
    int sp;

	clipRange();
	if ((bbW <= 0) || (bbH <= 0)) {
		affectedL = affectedR = affectedT = affectedB = 0;
		return null;
	}
	/* begin tryCopyingBitsQuickly */
	if (noSource) {
		done = 0;
		goto l2;
	}
	if (!(combinationRule == 34)) {
		done = 0;
		goto l2;
	}
	if (!(sourcePixSize == 32)) {
		done = 0;
		goto l2;
	}
	if (sourceForm == destForm) {
		done = 0;
		goto l2;
	}
	if (destPixSize < 8) {
		done = 0;
		goto l2;
	}
	if ((destPixSize == 8) && (colorMap == nilObj)) {
		done = 0;
		goto l2;
	}
	if (destPixSize == 32) {
		alphaSourceBlendBits32();
	}
	if (destPixSize == 16) {
		alphaSourceBlendBits16();
	}
	if (destPixSize == 8) {
		alphaSourceBlendBits8();
	}
	affectedL = dx;
	affectedR = dx + bbW;
	affectedT = dy;
	affectedB = dy + bbH;
	done = 1;
l2:	/* end tryCopyingBitsQuickly */;
	if (done) {
		return null;
	}
	destMaskAndPointerInit();
	bitCount = 0;
	if ((combinationRule == 30) || (combinationRule == 31)) {
		if (argumentCount == 1) {
			/* begin stackIntegerValue: */
			integerPointer = longAt(stackPointer - (0 * 4));
			if ((integerPointer & 1)) {
				sourceAlpha = (integerPointer >> 1);
				goto l1;
			} else {
				/* begin primitiveFail */
				successFlag = 0;
				sourceAlpha = 0;
				goto l1;
			}
		l1:	/* end stackIntegerValue: */;
			if ((!(!successFlag)) && ((sourceAlpha >= 0) && (sourceAlpha <= 255))) {
				/* begin pop: */
				stackPointer -= 1 * 4;
			} else {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	if (noSource) {
		copyLoopNoSource();
	} else {
		/* begin checkSourceOverlap */
		if ((sourceForm == destForm) && (dy >= sy)) {
			if (dy > sy) {
				vDir = -1;
				sy = (sy + bbH) - 1;
				dy = (dy + bbH) - 1;
			} else {
				if ((dy == sy) && (dx > sx)) {
					hDir = -1;
					sx = (sx + bbW) - 1;
					dx = (dx + bbW) - 1;
					if (nWords > 1) {
						t = mask1;
						mask1 = mask2;
						mask2 = t;
					}
				}
			}
			destIndex = (destBits + 4) + (((dy * destRaster) + (dx / pixPerWord)) * 4);
			destDelta = 4 * ((destRaster * vDir) - (nWords * hDir));
		}
		if ((sourcePixSize != destPixSize) || (colorMap != nilObj)) {
			copyLoopPixMap();
		} else {
			/* begin sourceSkewAndPointerInit */
			pixPerM1 = pixPerWord - 1;
			sxLowBits = sx & pixPerM1;
			dxLowBits = dx & pixPerM1;
			if (hDir > 0) {
				dWid = ((bbW < (pixPerWord - dxLowBits)) ? bbW : (pixPerWord - dxLowBits));
				preload = (sxLowBits + dWid) > pixPerM1;
			} else {
				dWid = ((bbW < (dxLowBits + 1)) ? bbW : (dxLowBits + 1));
				preload = ((sxLowBits - dWid) + 1) < 0;
			}
			skew = (sxLowBits - dxLowBits) * destPixSize;
			if (preload) {
				if (skew < 0) {
					skew += 32;
				} else {
					skew -= 32;
				}
			}
			sourceIndex = (sourceBits + 4) + (((sy * sourceRaster) + (sx / (32 / sourcePixSize))) * 4);
			sourceDelta = 4 * ((sourceRaster * vDir) - (nWords * hDir));
			if (preload) {
				sourceDelta -= 4 * hDir;
			}
			copyLoop();
		}
	}
	if ((combinationRule == 22) || (combinationRule == 32)) {
		affectedL = affectedR = affectedT = affectedB = 0;
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((bitCount << 1) | 1));
		stackPointer = sp;
		return null;
	}
	if (hDir > 0) {
		affectedL = dx;
		affectedR = dx + bbW;
	} else {
		affectedL = (dx - bbW) + 1;
		affectedR = dx + 1;
	}
	if (vDir > 0) {
		affectedT = dy;
		affectedB = dy + bbH;
	} else {
		affectedT = (dy - bbH) + 1;
		affectedB = dy + 1;
	}
}

int copyBitsFromtoat(int startX, int stopX, int yValue) {
	destX = startX;
	destY = yValue;
	sourceX = startX;
	width = stopX - startX;
	copyBits();
}

int copyLoop(void) {
    int y;
    int prevWord;
    int skewWord;
    int mergeWord;
    int hInc;
    int skewMask;
    int (*mergeFnwith)(int, int);
    int i;
    int thisWord;
    int word;
    int halftoneWord;
    int notSkewMask;
    int unskew;

	mergeFnwith = ((int (*)(int, int)) (opTable[combinationRule + 1]));
	mergeFnwith;
	hInc = hDir * 4;
	if (skew == -32) {
		skew = unskew = skewMask = 0;
	} else {
		if (skew < 0) {
			unskew = skew + 32;
			skewMask = 4294967295U << (0 - skew);
		} else {
			if (skew == 0) {
				unskew = 0;
				skewMask = 4294967295U;
			} else {
				unskew = skew - 32;
				skewMask = ((unsigned) 4294967295U) >> skew;
			}
		}
	}
	notSkewMask = ~skewMask;
	if (noHalftone) {
		halftoneWord = 4294967295U;
		halftoneHeight = 0;
	} else {
		halftoneWord = longAt(halftoneBase);
	}
	y = dy;
	for (i = 1; i <= bbH; i += 1) {
		if (halftoneHeight > 1) {
			halftoneWord = longAt(halftoneBase + ((y % halftoneHeight) * 4));
			y += vDir;
		}
		if (preload) {
			prevWord = longAt(sourceIndex);
			sourceIndex += hInc;
		} else {
			prevWord = 0;
		}
		destMask = mask1;
		thisWord = longAt(sourceIndex);
		sourceIndex += hInc;
		skewWord = (((unskew < 0) ? ((unsigned) (prevWord & notSkewMask) >> -unskew) : ((unsigned) (prevWord & notSkewMask) << unskew))) | (((skew < 0) ? ((unsigned) (thisWord & skewMask) >> -skew) : ((unsigned) (thisWord & skewMask) << skew)));
		prevWord = thisWord;
		mergeWord = mergeFnwith(skewWord & halftoneWord, longAt(destIndex));
		longAtput(destIndex, (destMask & mergeWord) | ((~destMask) & (longAt(destIndex))));
		destIndex += hInc;
		destMask = 4294967295U;
		if (combinationRule == 3) {
			if (noHalftone && (notSkewMask == 0)) {
				for (word = 2; word <= (nWords - 1); word += 1) {
					thisWord = longAt(sourceIndex);
					sourceIndex += hInc;
					longAtput(destIndex, thisWord);
					destIndex += hInc;
				}
			} else {
				for (word = 2; word <= (nWords - 1); word += 1) {
					thisWord = longAt(sourceIndex);
					sourceIndex += hInc;
					skewWord = (((unskew < 0) ? ((unsigned) (prevWord & notSkewMask) >> -unskew) : ((unsigned) (prevWord & notSkewMask) << unskew))) | (((skew < 0) ? ((unsigned) (thisWord & skewMask) >> -skew) : ((unsigned) (thisWord & skewMask) << skew)));
					prevWord = thisWord;
					longAtput(destIndex, skewWord & halftoneWord);
					destIndex += hInc;
				}
			}
		} else {
			for (word = 2; word <= (nWords - 1); word += 1) {
				thisWord = longAt(sourceIndex);
				sourceIndex += hInc;
				skewWord = (((unskew < 0) ? ((unsigned) (prevWord & notSkewMask) >> -unskew) : ((unsigned) (prevWord & notSkewMask) << unskew))) | (((skew < 0) ? ((unsigned) (thisWord & skewMask) >> -skew) : ((unsigned) (thisWord & skewMask) << skew)));
				prevWord = thisWord;
				mergeWord = mergeFnwith(skewWord & halftoneWord, longAt(destIndex));
				longAtput(destIndex, mergeWord);
				destIndex += hInc;
			}
		}
		if (nWords > 1) {
			destMask = mask2;
			thisWord = longAt(sourceIndex);
			sourceIndex += hInc;
			skewWord = (((unskew < 0) ? ((unsigned) (prevWord & notSkewMask) >> -unskew) : ((unsigned) (prevWord & notSkewMask) << unskew))) | (((skew < 0) ? ((unsigned) (thisWord & skewMask) >> -skew) : ((unsigned) (thisWord & skewMask) << skew)));
			mergeWord = mergeFnwith(skewWord & halftoneWord, longAt(destIndex));
			longAtput(destIndex, (destMask & mergeWord) | ((~destMask) & (longAt(destIndex))));
			destIndex += hInc;
		}
		sourceIndex += sourceDelta;
		destIndex += destDelta;
	}
}

int copyLoopNoSource(void) {
    int mergeWord;
    int (*mergeFnwith)(int, int);
    int i;
    int word;
    int halftoneWord;

	mergeFnwith = ((int (*)(int, int)) (opTable[combinationRule + 1]));
	mergeFnwith;
	for (i = 1; i <= bbH; i += 1) {
		if (noHalftone) {
			halftoneWord = 4294967295U;
		} else {
			halftoneWord = longAt(halftoneBase + ((((dy + i) - 1) % halftoneHeight) * 4));
		}
		destMask = mask1;
		mergeWord = mergeFnwith(halftoneWord, longAt(destIndex));
		longAtput(destIndex, (destMask & mergeWord) | ((~destMask) & (longAt(destIndex))));
		destIndex += 4;
		destMask = 4294967295U;
		if (combinationRule == 3) {
			for (word = 2; word <= (nWords - 1); word += 1) {
				longAtput(destIndex, halftoneWord);
				destIndex += 4;
			}
		} else {
			for (word = 2; word <= (nWords - 1); word += 1) {
				mergeWord = mergeFnwith(halftoneWord, longAt(destIndex));
				longAtput(destIndex, mergeWord);
				destIndex += 4;
			}
		}
		if (nWords > 1) {
			destMask = mask2;
			mergeWord = mergeFnwith(halftoneWord, longAt(destIndex));
			longAtput(destIndex, (destMask & mergeWord) | ((~destMask) & (longAt(destIndex))));
			destIndex += 4;
		}
		destIndex += destDelta;
	}
}

int copyLoopPixMap(void) {
    int skewWord;
    int mergeWord;
    int srcPixPerWord;
    int scrStartBits;
    int nSourceIncs;
    int startBits;
    int sourcePixMask;
    int endBits;
    int destPixMask;
    int halftoneWord;
    int nullMap;
    int (*mergeFnwith)(int, int);
    int i;
    int word;
    int nPix;
    int nPix1;

	mergeFnwith = ((int (*)(int, int)) (opTable[combinationRule + 1]));
	mergeFnwith;
	srcPixPerWord = 32 / sourcePixSize;
	sourcePixMask = maskTable[sourcePixSize];
	destPixMask = maskTable[destPixSize];
	nullMap = colorMap == nilObj;
	sourceIndex = (sourceBits + 4) + (((sy * sourceRaster) + (sx / srcPixPerWord)) * 4);
	scrStartBits = srcPixPerWord - (sx & (srcPixPerWord - 1));
	if (bbW < scrStartBits) {
		nSourceIncs = 0;
	} else {
		nSourceIncs = ((bbW - scrStartBits) / srcPixPerWord) + 1;
	}
	sourceDelta = (sourceRaster - nSourceIncs) * 4;
	startBits = pixPerWord - (dx & (pixPerWord - 1));
	endBits = (((dx + bbW) - 1) & (pixPerWord - 1)) + 1;
	for (i = 1; i <= bbH; i += 1) {
		if (noHalftone) {
			halftoneWord = 4294967295U;
		} else {
			halftoneWord = longAt(halftoneBase + ((((dy + i) - 1) % halftoneHeight) * 4));
		}
		srcBitIndex = (sx & (srcPixPerWord - 1)) * sourcePixSize;
		destMask = mask1;
		if (bbW < startBits) {
			/* begin pickSourcePixels:nullMap:srcMask:destMask: */
			nPix = bbW;
			if (sourcePixSize >= 16) {
				skewWord = pickSourcePixelsRGBnullMapsrcMaskdestMask(nPix, nullMap, sourcePixMask, destPixMask);
				goto l1;
			}
			if (nullMap) {
				skewWord = pickSourcePixelsNullMapsrcMaskdestMask(nPix, sourcePixMask, destPixMask);
				goto l1;
			}
			skewWord = pickSourcePixelssrcMaskdestMask(nPix, sourcePixMask, destPixMask);
		l1:	/* end pickSourcePixels:nullMap:srcMask:destMask: */;
			skewWord = ((((startBits - bbW) * destPixSize) < 0) ? ((unsigned) skewWord >> -((startBits - bbW) * destPixSize)) : ((unsigned) skewWord << ((startBits - bbW) * destPixSize)));
		} else {
			/* begin pickSourcePixels:nullMap:srcMask:destMask: */
			if (sourcePixSize >= 16) {
				skewWord = pickSourcePixelsRGBnullMapsrcMaskdestMask(startBits, nullMap, sourcePixMask, destPixMask);
				goto l2;
			}
			if (nullMap) {
				skewWord = pickSourcePixelsNullMapsrcMaskdestMask(startBits, sourcePixMask, destPixMask);
				goto l2;
			}
			skewWord = pickSourcePixelssrcMaskdestMask(startBits, sourcePixMask, destPixMask);
		l2:	/* end pickSourcePixels:nullMap:srcMask:destMask: */;
		}
		for (word = 1; word <= nWords; word += 1) {
			mergeWord = mergeFnwith(skewWord & halftoneWord, (longAt(destIndex)) & destMask);
			longAtput(destIndex, (destMask & mergeWord) | ((~destMask) & (longAt(destIndex))));
			destIndex += 4;
			if (word >= (nWords - 1)) {
				if (!(word == nWords)) {
					destMask = mask2;
					/* begin pickSourcePixels:nullMap:srcMask:destMask: */
					if (sourcePixSize >= 16) {
						skewWord = pickSourcePixelsRGBnullMapsrcMaskdestMask(endBits, nullMap, sourcePixMask, destPixMask);
						goto l3;
					}
					if (nullMap) {
						skewWord = pickSourcePixelsNullMapsrcMaskdestMask(endBits, sourcePixMask, destPixMask);
						goto l3;
					}
					skewWord = pickSourcePixelssrcMaskdestMask(endBits, sourcePixMask, destPixMask);
				l3:	/* end pickSourcePixels:nullMap:srcMask:destMask: */;
					skewWord = ((((pixPerWord - endBits) * destPixSize) < 0) ? ((unsigned) skewWord >> -((pixPerWord - endBits) * destPixSize)) : ((unsigned) skewWord << ((pixPerWord - endBits) * destPixSize)));
				}
			} else {
				destMask = 4294967295U;
				/* begin pickSourcePixels:nullMap:srcMask:destMask: */
				nPix1 = pixPerWord;
				if (sourcePixSize >= 16) {
					skewWord = pickSourcePixelsRGBnullMapsrcMaskdestMask(nPix1, nullMap, sourcePixMask, destPixMask);
					goto l4;
				}
				if (nullMap) {
					skewWord = pickSourcePixelsNullMapsrcMaskdestMask(nPix1, sourcePixMask, destPixMask);
					goto l4;
				}
				skewWord = pickSourcePixelssrcMaskdestMask(nPix1, sourcePixMask, destPixMask);
			l4:	/* end pickSourcePixels:nullMap:srcMask:destMask: */;
			}
		}
		sourceIndex += sourceDelta;
		destIndex += destDelta;
	}
}

int copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(int oop, int segmentWordArray, int lastSeg, int stopAddr, int oopPtr, int hdrPtr) {
    int hdrAddr;
    int bodySize;
    int extraSize;
    int lastIn;
    int in;
    int out;
    int type;
    int extra;
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

int createActualMessageTo(int aClass) {
    int argumentArray;
    int message;
    int lookupClass;
    int oop;
    int oop1;
    int lastIn;
    int in;
    int out;
    int valuePointer;
    int sp;

	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = aClass;
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
	/* begin transfer:from:to: */
	in = (stackPointer - ((argumentCount - 1) * 4)) - 4;
	lastIn = in + (argumentCount * 4);
	out = (argumentArray + 4) - 4;
	while (in < lastIn) {
		longAtput(out += 4, longAt(in += 4));
	}
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
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((argumentCount - 1) * 4), message);
	stackPointer = sp;
	argumentCount = 1;
}

int createGlobalEdgeTable(void) {
    int end;
    int object;
    int lineWidth;
    int lineWidth1;

	object = 0;
	end = objUsed;
	while (object < end) {
		if (isEdge(object)) {
			if (!((objBuffer[object + 5]) >= (workBuffer[39]))) {
				/* begin checkedAddEdgeToGET: */
				if ((((objBuffer[object + 0]) & 65535) & 254) == 4) {
					/* begin checkedAddLineToGET: */
					if ((((objBuffer[object + 0]) & 65535) & 1) != 0) {
						lineWidth = objBuffer[object + 20];
					} else {
						lineWidth = 0;
					}
					if (((objBuffer[object + 15]) + lineWidth) < (workBuffer[38])) {
						goto l1;
					}
					if ((((objBuffer[object + 4]) - lineWidth) >= (workBuffer[37])) && (((objBuffer[object + 14]) - lineWidth) >= (workBuffer[37]))) {
						goto l1;
					}
					addEdgeToGET(object);
					goto l1;
				}
				if ((((objBuffer[object + 0]) & 65535) & 254) == 6) {
					/* begin checkedAddBezierToGET: */
					if ((((objBuffer[object + 0]) & 65535) & 1) != 0) {
						lineWidth1 = objBuffer[object + 20];
					} else {
						lineWidth1 = 0;
					}
					if (((objBuffer[object + 15]) + lineWidth1) < (workBuffer[38])) {
						goto l1;
					}
					if ((((objBuffer[object + 4]) - lineWidth1) >= (workBuffer[37])) && (((objBuffer[object + 14]) - lineWidth1) >= (workBuffer[37]))) {
						goto l1;
					}
					addEdgeToGET(object);
					goto l1;
				}
				addEdgeToGET(object);
			l1:	/* end checkedAddEdgeToGET: */;
			}
		}
		object += objBuffer[object + 1];
	}
}

unsigned int * default8To32Table(void) {
    static unsigned int theTable[256] = { 
0x0, 0xFF000001, 0xFFFFFFFF, 0xFF808080, 0xFFFF0000, 0xFF00FF00, 0xFF0000FF, 0xFF00FFFF, 
0xFFFFFF00, 0xFFFF00FF, 0xFF202020, 0xFF404040, 0xFF606060, 0xFF9F9F9F, 0xFFBFBFBF, 0xFFDFDFDF, 
0xFF080808, 0xFF101010, 0xFF181818, 0xFF282828, 0xFF303030, 0xFF383838, 0xFF484848, 0xFF505050, 
0xFF585858, 0xFF686868, 0xFF707070, 0xFF787878, 0xFF878787, 0xFF8F8F8F, 0xFF979797, 0xFFA7A7A7, 
0xFFAFAFAF, 0xFFB7B7B7, 0xFFC7C7C7, 0xFFCFCFCF, 0xFFD7D7D7, 0xFFE7E7E7, 0xFFEFEFEF, 0xFFF7F7F7, 
0xFF000001, 0xFF003300, 0xFF006600, 0xFF009900, 0xFF00CC00, 0xFF00FF00, 0xFF000033, 0xFF003333, 
0xFF006633, 0xFF009933, 0xFF00CC33, 0xFF00FF33, 0xFF000066, 0xFF003366, 0xFF006666, 0xFF009966, 
0xFF00CC66, 0xFF00FF66, 0xFF000099, 0xFF003399, 0xFF006699, 0xFF009999, 0xFF00CC99, 0xFF00FF99, 
0xFF0000CC, 0xFF0033CC, 0xFF0066CC, 0xFF0099CC, 0xFF00CCCC, 0xFF00FFCC, 0xFF0000FF, 0xFF0033FF, 
0xFF0066FF, 0xFF0099FF, 0xFF00CCFF, 0xFF00FFFF, 0xFF330000, 0xFF333300, 0xFF336600, 0xFF339900, 
0xFF33CC00, 0xFF33FF00, 0xFF330033, 0xFF333333, 0xFF336633, 0xFF339933, 0xFF33CC33, 0xFF33FF33, 
0xFF330066, 0xFF333366, 0xFF336666, 0xFF339966, 0xFF33CC66, 0xFF33FF66, 0xFF330099, 0xFF333399, 
0xFF336699, 0xFF339999, 0xFF33CC99, 0xFF33FF99, 0xFF3300CC, 0xFF3333CC, 0xFF3366CC, 0xFF3399CC, 
0xFF33CCCC, 0xFF33FFCC, 0xFF3300FF, 0xFF3333FF, 0xFF3366FF, 0xFF3399FF, 0xFF33CCFF, 0xFF33FFFF, 
0xFF660000, 0xFF663300, 0xFF666600, 0xFF669900, 0xFF66CC00, 0xFF66FF00, 0xFF660033, 0xFF663333, 
0xFF666633, 0xFF669933, 0xFF66CC33, 0xFF66FF33, 0xFF660066, 0xFF663366, 0xFF666666, 0xFF669966, 
0xFF66CC66, 0xFF66FF66, 0xFF660099, 0xFF663399, 0xFF666699, 0xFF669999, 0xFF66CC99, 0xFF66FF99, 
0xFF6600CC, 0xFF6633CC, 0xFF6666CC, 0xFF6699CC, 0xFF66CCCC, 0xFF66FFCC, 0xFF6600FF, 0xFF6633FF, 
0xFF6666FF, 0xFF6699FF, 0xFF66CCFF, 0xFF66FFFF, 0xFF990000, 0xFF993300, 0xFF996600, 0xFF999900, 
0xFF99CC00, 0xFF99FF00, 0xFF990033, 0xFF993333, 0xFF996633, 0xFF999933, 0xFF99CC33, 0xFF99FF33, 
0xFF990066, 0xFF993366, 0xFF996666, 0xFF999966, 0xFF99CC66, 0xFF99FF66, 0xFF990099, 0xFF993399, 
0xFF996699, 0xFF999999, 0xFF99CC99, 0xFF99FF99, 0xFF9900CC, 0xFF9933CC, 0xFF9966CC, 0xFF9999CC, 
0xFF99CCCC, 0xFF99FFCC, 0xFF9900FF, 0xFF9933FF, 0xFF9966FF, 0xFF9999FF, 0xFF99CCFF, 0xFF99FFFF, 
0xFFCC0000, 0xFFCC3300, 0xFFCC6600, 0xFFCC9900, 0xFFCCCC00, 0xFFCCFF00, 0xFFCC0033, 0xFFCC3333, 
0xFFCC6633, 0xFFCC9933, 0xFFCCCC33, 0xFFCCFF33, 0xFFCC0066, 0xFFCC3366, 0xFFCC6666, 0xFFCC9966, 
0xFFCCCC66, 0xFFCCFF66, 0xFFCC0099, 0xFFCC3399, 0xFFCC6699, 0xFFCC9999, 0xFFCCCC99, 0xFFCCFF99, 
0xFFCC00CC, 0xFFCC33CC, 0xFFCC66CC, 0xFFCC99CC, 0xFFCCCCCC, 0xFFCCFFCC, 0xFFCC00FF, 0xFFCC33FF, 
0xFFCC66FF, 0xFFCC99FF, 0xFFCCCCFF, 0xFFCCFFFF, 0xFFFF0000, 0xFFFF3300, 0xFFFF6600, 0xFFFF9900, 
0xFFFFCC00, 0xFFFFFF00, 0xFFFF0033, 0xFFFF3333, 0xFFFF6633, 0xFFFF9933, 0xFFFFCC33, 0xFFFFFF33, 
0xFFFF0066, 0xFFFF3366, 0xFFFF6666, 0xFFFF9966, 0xFFFFCC66, 0xFFFFFF66, 0xFFFF0099, 0xFFFF3399, 
0xFFFF6699, 0xFFFF9999, 0xFFFFCC99, 0xFFFFFF99, 0xFFFF00CC, 0xFFFF33CC, 0xFFFF66CC, 0xFFFF99CC, 
0xFFFFCCCC, 0xFFFFFFCC, 0xFFFF00FF, 0xFFFF33FF, 0xFFFF66FF, 0xFFFF99FF, 0xFFFFCCFF, 0xFFFFFFFF};;

	return theTable;
}

int deltaFromtonSteps(int x1, int x2, int n) {
	if (x2 > x1) {
		return (((x2 - x1) + 16384) / (n + 1)) + 1;
	} else {
		if (x2 == x1) {
			return 0;
		}
		return 0 - ((((x1 - x2) + 16384) / (n + 1)) + 1);
	}
}

int destMaskAndPointerInit(void) {
    int startBits;
    int endBits;
    int pixPerM1;

	pixPerM1 = pixPerWord - 1;
	startBits = pixPerWord - (dx & pixPerM1);
	mask1 = ((unsigned) 4294967295U) >> (32 - (startBits * destPixSize));
	endBits = (((dx + bbW) - 1) & pixPerM1) + 1;
	mask2 = 4294967295U << (32 - (endBits * destPixSize));
	if (bbW < startBits) {
		mask1 = mask1 & mask2;
		mask2 = 0;
		nWords = 1;
	} else {
		nWords = (((bbW - startBits) + pixPerM1) / pixPerWord) + 1;
	}
	hDir = vDir = 1;
	destIndex = (destBits + 4) + (((dy * destRaster) + (dx / pixPerWord)) * 4);
	destDelta = 4 * ((destRaster * vDir) - (nWords * hDir));
}

int destinationWordwith(int sourceWord, int destinationWord) {
	return destinationWord;
}

int displayObject(void) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
}

int displaySpanBufferAt(int y) {
    int targetY;
    int targetX0;
    int targetX1;

	targetX0 = ((unsigned) (workBuffer[32])) >> (workBuffer[49]);
	if (targetX0 < (workBuffer[42])) {
		targetX0 = workBuffer[42];
	}
	targetX1 = ((unsigned) (((workBuffer[34]) + (workBuffer[48])) - 1)) >> (workBuffer[49]);
	if (targetX1 > (workBuffer[43])) {
		targetX1 = workBuffer[43];
	}
	targetY = ((unsigned) y) >> (workBuffer[49]);
	if ((targetY < (workBuffer[44])) || ((targetY >= (workBuffer[45])) || ((targetX1 < (workBuffer[42])) || (targetX0 >= (workBuffer[43]))))) {
		return 0;
	}
	/* begin copyBitsFrom:to:at: */
	destX = targetX0;
	destY = targetY;
	sourceX = targetX0;
	width = targetX1 - targetX0;
	copyBits();
	showDisplayBits();
}

int doPrimitiveDivby(int rcvr, int arg) {
    int posArg;
    int posRcvr;
    int result;
    int integerRcvr;
    int integerArg;

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
    int integerRcvr;
    int integerArg;

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

int errorWrongIndex(void) {
	error("BalloonEngine: Fatal dispatch error");
}

int extraHeaderBytes(int oopOrChunk) {
    int type;
    int extra;

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

double fetchFloatofObject(int fieldIndex, int objectPointer) {
    int floatOop;

	floatOop = longAt(((((char *) objectPointer)) + 4) + (fieldIndex << 2));
	return floatValueOf(floatOop);
}

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

int fetchIntegerOrTruncFloatofObject(int fieldIndex, int objectPointer) {
    double trunc;
    double frac;
    double floatVal;
    int intOrFloat;
    int ccIndex;
    int cl;

	intOrFloat = longAt(((((char *) objectPointer)) + 4) + (fieldIndex << 2));
	if ((intOrFloat & 1)) {
		return (intOrFloat >> 1);
	}
	/* begin assertClassOf:is: */
	if ((intOrFloat & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((unsigned) (longAt(intOrFloat))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(intOrFloat - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		;
		fetchFloatAtinto(intOrFloat + 4, floatVal);
		frac = modf(floatVal, &trunc);
		success((-2147483648.0 <= trunc) && (trunc <= 2147483647.0));
	}
	if (successFlag) {
		return ((int) trunc);
	} else {
		return 0;
	}
}

int fetchPointerofObject(int fieldIndex, int oop) {
	return longAt(((((char *) oop)) + 4) + (fieldIndex << 2));
}

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

int fetchWordLengthOf(int objectPointer) {
    int sz;
    int header;

	/* begin sizeBitsOf: */
	header = longAt(objectPointer);
	if ((header & 3) == 0) {
		sz = (longAt(objectPointer - 8)) & 4294967292U;
		goto l1;
	} else {
		sz = header & 252;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	return ((unsigned) (sz - 4)) >> 2;
}

int fileRecordSize(void) {
	return sizeof(SQFile);
}

SQFile * fileValueOf(int objectPointer) {
    int fileIndex;
    int successValue;

	/* begin success: */
	successValue = (((((unsigned) (longAt(objectPointer))) >> 8) & 15) >= 8) && ((lengthOf(objectPointer)) == (fileRecordSize()));
	successFlag = successValue && successFlag;
	if (successFlag) {
		fileIndex = objectPointer + 4;
		return (SQFile *) fileIndex;
	} else {
		return null;
	}
}

int fillBitmapSpanfromto(int *bits, int leftX, int rightX) {
    int bitX;
    int colorShift;
    int x0;
    int x1;
    int x;
    int colorMask;
    int fillValue;
    int baseShift;

	x0 = leftX;
	x1 = rightX;
	bitX = -1;
	if ((workBuffer[48]) == 1) {
		while (x0 < x1) {
			fillValue = (((int *) bits))[bitX += 1];
			spanBuffer[x0] = fillValue;
			x0 += 1;
		}
	} else {
		colorMask = workBuffer[51];
		colorShift = workBuffer[50];
		baseShift = workBuffer[49];
		while (x0 < x1) {
			x = ((unsigned) x0) >> baseShift;
			fillValue = (((int *) bits))[bitX += 1];
			fillValue = ((unsigned) (fillValue & colorMask)) >> colorShift;
			spanBuffer[x] = ((spanBuffer[x]) + fillValue);
			x0 += 1;
		}
	}
	if (x1 > (workBuffer[34])) {
		workBuffer[34] = x1;
	}
	if (x1 > (workBuffer[35])) {
		workBuffer[35] = x1;
	}
}

int fillBitmapSpanfromtoat(int bmFill, int leftX, int rightX, int yValue) {
    int *bits;
    int bmWidth;
    int deltaX;
    int deltaY;
    int yp;
    int ds;
    int dsX;
    int dtX;
    int dt;
    int xp;
    int x;
    int x1;
    int fillValue;
    int tileFlag;
    int bmHeight;
    int newDelta;
    int newDelta1;
    int bmDepth;
    int b;
    int value;
    int rShift;
    int g;
    int cMask;
    int a;
    int bmRaster;
    int r;

	if (!((workBuffer[48]) == 1)) {
		return fillBitmapSpanAAfromtoat(bmFill, leftX, rightX, yValue);
	}
	bits = loadBitsFrom(bmFill);
	if (bits == null) {
		return null;
	}
	bmWidth = objBuffer[bmFill + 10];
	bmHeight = objBuffer[bmFill + 11];
	tileFlag = (objBuffer[bmFill + 16]) == 1;
	deltaX = leftX - (objBuffer[bmFill + 4]);
	deltaY = yValue - (objBuffer[bmFill + 5]);
	dsX = objBuffer[bmFill + 6];
	dtX = objBuffer[bmFill + 8];
	ds = (deltaX * dsX) + (deltaY * (objBuffer[bmFill + 7]));
	dt = (deltaX * dtX) + (deltaY * (objBuffer[bmFill + 9]));
	x = leftX;
	x1 = rightX;
	while (x < x1) {
		if (tileFlag) {
			/* begin repeatValue:max: */
			newDelta = ds;
			while (newDelta < 0) {
				newDelta += bmWidth << 16;
			}
			while (newDelta >= (bmWidth << 16)) {
				newDelta -= bmWidth << 16;
			}
			ds = newDelta;
			/* begin repeatValue:max: */
			newDelta1 = dt;
			while (newDelta1 < 0) {
				newDelta1 += bmHeight << 16;
			}
			while (newDelta1 >= (bmHeight << 16)) {
				newDelta1 -= bmHeight << 16;
			}
			dt = newDelta1;
		}
		xp = ((int) ds >> 16);
		yp = ((int) dt >> 16);
		if (!(tileFlag)) {
			/* begin clampValue:max: */
			if (xp < 0) {
				xp = 0;
				goto l1;
			} else {
				if (xp >= bmWidth) {
					xp = bmWidth - 1;
					goto l1;
				} else {
					xp = xp;
					goto l1;
				}
			}
		l1:	/* end clampValue:max: */;
			/* begin clampValue:max: */
			if (yp < 0) {
				yp = 0;
				goto l2;
			} else {
				if (yp >= bmHeight) {
					yp = bmHeight - 1;
					goto l2;
				} else {
					yp = yp;
					goto l2;
				}
			}
		l2:	/* end clampValue:max: */;
		}
		if ((xp >= 0) && ((yp >= 0) && ((xp < bmWidth) && (yp < bmHeight)))) {
			/* begin bitmapValue:bits:atX:y: */
			bmDepth = objBuffer[bmFill + 12];
			bmRaster = objBuffer[bmFill + 14];
			if (bmDepth == 32) {
				value = (((int*) bits))[(bmRaster * yp) + xp];
				if ((value != 0) && ((value & 4278190080U) == 0)) {
					value = value | 4278190080U;
				}
				fillValue = uncheckedTransformColor(value);
				goto l3;
			}
			rShift = (rShiftTable())[bmDepth];
			value = (((int*) bits))[(bmRaster * yp) + (((unsigned) xp) >> rShift)];
			cMask = (1 << bmDepth) - 1;
			rShift = (32 - bmDepth) - ((xp & ((1 << rShift) - 1)) * bmDepth);
			value = (((unsigned) value) >> rShift) & cMask;
			if (bmDepth == 16) {
				if (!(value == 0)) {
					b = (value & 31) << 3;
					b += ((unsigned) b) >> 5;
					g = ((((unsigned) value) >> 5) & 31) << 3;
					g += ((unsigned) g) >> 5;
					r = ((((unsigned) value) >> 10) & 31) << 3;
					r += ((unsigned) r) >> 5;
					a = 255;
					value = ((b + (g << 8)) + (r << 16)) + (a << 24);
				}
			} else {
				if ((objBuffer[bmFill + 15]) == 0) {
					value = 0;
				} else {
					value = ((objBuffer + bmFill) + 18)[value];
				}
			}
			fillValue = uncheckedTransformColor(value);
		l3:	/* end bitmapValue:bits:atX:y: */;
			spanBuffer[x] = fillValue;
		}
		ds += dsX;
		dt += dtX;
		x += 1;
	}
}

int fillBitmapSpanAAfromtoat(int bmFill, int leftX, int rightX, int yValue) {
    int *bits;
    int bmWidth;
    int deltaX;
    int deltaY;
    int aaLevel;
    int yp;
    int ds;
    int dsX;
    int dtX;
    int dt;
    int idx;
    int cShift;
    int firstPixel;
    int xp;
    int lastPixel;
    int x;
    int cMask;
    int fillValue;
    int tileFlag;
    int bmHeight;
    int baseShift;
    int newDelta;
    int newDelta1;
    int newDelta2;
    int newDelta3;
    int newDelta4;
    int newDelta5;
    int firstPixel1;
    int bmDepth;
    int b;
    int value;
    int rShift;
    int g;
    int cMask1;
    int a;
    int bmRaster;
    int r;
    int bmDepth1;
    int b1;
    int value1;
    int rShift1;
    int g1;
    int cMask2;
    int a1;
    int bmRaster1;
    int r1;
    int bmDepth2;
    int b2;
    int value2;
    int rShift2;
    int g2;
    int cMask3;
    int a2;
    int bmRaster2;
    int r2;

	bits = loadBitsFrom(bmFill);
	if (bits == null) {
		return null;
	}
	bmWidth = objBuffer[bmFill + 10];
	bmHeight = objBuffer[bmFill + 11];
	tileFlag = (objBuffer[bmFill + 16]) == 1;
	deltaX = leftX - (objBuffer[bmFill + 4]);
	deltaY = yValue - (objBuffer[bmFill + 5]);
	dsX = objBuffer[bmFill + 6];
	dtX = objBuffer[bmFill + 8];
	ds = (deltaX * dsX) + (deltaY * (objBuffer[bmFill + 7]));
	dt = (deltaX * dtX) + (deltaY * (objBuffer[bmFill + 9]));
	aaLevel = workBuffer[48];
	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[48])) - 1) & (~((workBuffer[48]) - 1));
	if (firstPixel1 > rightX) {
		firstPixel = rightX;
		goto l7;
	} else {
		firstPixel = firstPixel1;
		goto l7;
	}
l7:	/* end aaFirstPixelFrom:to: */;
	lastPixel = (rightX - 1) & (~((workBuffer[48]) - 1));
	baseShift = workBuffer[49];
	cMask = workBuffer[51];
	cShift = workBuffer[50];
	x = leftX;
	while (x < firstPixel) {
		if (tileFlag) {
			/* begin repeatValue:max: */
			newDelta = ds;
			while (newDelta < 0) {
				newDelta += bmWidth << 16;
			}
			while (newDelta >= (bmWidth << 16)) {
				newDelta -= bmWidth << 16;
			}
			ds = newDelta;
			/* begin repeatValue:max: */
			newDelta1 = dt;
			while (newDelta1 < 0) {
				newDelta1 += bmHeight << 16;
			}
			while (newDelta1 >= (bmHeight << 16)) {
				newDelta1 -= bmHeight << 16;
			}
			dt = newDelta1;
		}
		xp = ((int) ds >> 16);
		yp = ((int) dt >> 16);
		if (!(tileFlag)) {
			/* begin clampValue:max: */
			if (xp < 0) {
				xp = 0;
				goto l1;
			} else {
				if (xp >= bmWidth) {
					xp = bmWidth - 1;
					goto l1;
				} else {
					xp = xp;
					goto l1;
				}
			}
		l1:	/* end clampValue:max: */;
			/* begin clampValue:max: */
			if (yp < 0) {
				yp = 0;
				goto l2;
			} else {
				if (yp >= bmHeight) {
					yp = bmHeight - 1;
					goto l2;
				} else {
					yp = yp;
					goto l2;
				}
			}
		l2:	/* end clampValue:max: */;
		}
		if ((xp >= 0) && ((yp >= 0) && ((xp < bmWidth) && (yp < bmHeight)))) {
			/* begin bitmapValue:bits:atX:y: */
			bmDepth = objBuffer[bmFill + 12];
			bmRaster = objBuffer[bmFill + 14];
			if (bmDepth == 32) {
				value = (((int*) bits))[(bmRaster * yp) + xp];
				if ((value != 0) && ((value & 4278190080U) == 0)) {
					value = value | 4278190080U;
				}
				fillValue = uncheckedTransformColor(value);
				goto l8;
			}
			rShift = (rShiftTable())[bmDepth];
			value = (((int*) bits))[(bmRaster * yp) + (((unsigned) xp) >> rShift)];
			cMask1 = (1 << bmDepth) - 1;
			rShift = (32 - bmDepth) - ((xp & ((1 << rShift) - 1)) * bmDepth);
			value = (((unsigned) value) >> rShift) & cMask1;
			if (bmDepth == 16) {
				if (!(value == 0)) {
					b = (value & 31) << 3;
					b += ((unsigned) b) >> 5;
					g = ((((unsigned) value) >> 5) & 31) << 3;
					g += ((unsigned) g) >> 5;
					r = ((((unsigned) value) >> 10) & 31) << 3;
					r += ((unsigned) r) >> 5;
					a = 255;
					value = ((b + (g << 8)) + (r << 16)) + (a << 24);
				}
			} else {
				if ((objBuffer[bmFill + 15]) == 0) {
					value = 0;
				} else {
					value = ((objBuffer + bmFill) + 18)[value];
				}
			}
			fillValue = uncheckedTransformColor(value);
		l8:	/* end bitmapValue:bits:atX:y: */;
			fillValue = ((unsigned) (fillValue & cMask)) >> cShift;
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + fillValue);
		}
		ds += dsX;
		dt += dtX;
		x += 1;
	}
	cMask = (((unsigned) (workBuffer[51])) >> (workBuffer[49])) | 4042322160U;
	cShift = workBuffer[49];
	while (x < lastPixel) {
		if (tileFlag) {
			/* begin repeatValue:max: */
			newDelta2 = ds;
			while (newDelta2 < 0) {
				newDelta2 += bmWidth << 16;
			}
			while (newDelta2 >= (bmWidth << 16)) {
				newDelta2 -= bmWidth << 16;
			}
			ds = newDelta2;
			/* begin repeatValue:max: */
			newDelta3 = dt;
			while (newDelta3 < 0) {
				newDelta3 += bmHeight << 16;
			}
			while (newDelta3 >= (bmHeight << 16)) {
				newDelta3 -= bmHeight << 16;
			}
			dt = newDelta3;
		}
		xp = ((int) ds >> 16);
		yp = ((int) dt >> 16);
		if (!(tileFlag)) {
			/* begin clampValue:max: */
			if (xp < 0) {
				xp = 0;
				goto l3;
			} else {
				if (xp >= bmWidth) {
					xp = bmWidth - 1;
					goto l3;
				} else {
					xp = xp;
					goto l3;
				}
			}
		l3:	/* end clampValue:max: */;
			/* begin clampValue:max: */
			if (yp < 0) {
				yp = 0;
				goto l4;
			} else {
				if (yp >= bmHeight) {
					yp = bmHeight - 1;
					goto l4;
				} else {
					yp = yp;
					goto l4;
				}
			}
		l4:	/* end clampValue:max: */;
		}
		if ((xp >= 0) && ((yp >= 0) && ((xp < bmWidth) && (yp < bmHeight)))) {
			/* begin bitmapValue:bits:atX:y: */
			bmDepth1 = objBuffer[bmFill + 12];
			bmRaster1 = objBuffer[bmFill + 14];
			if (bmDepth1 == 32) {
				value1 = (((int*) bits))[(bmRaster1 * yp) + xp];
				if ((value1 != 0) && ((value1 & 4278190080U) == 0)) {
					value1 = value1 | 4278190080U;
				}
				fillValue = uncheckedTransformColor(value1);
				goto l9;
			}
			rShift1 = (rShiftTable())[bmDepth1];
			value1 = (((int*) bits))[(bmRaster1 * yp) + (((unsigned) xp) >> rShift1)];
			cMask2 = (1 << bmDepth1) - 1;
			rShift1 = (32 - bmDepth1) - ((xp & ((1 << rShift1) - 1)) * bmDepth1);
			value1 = (((unsigned) value1) >> rShift1) & cMask2;
			if (bmDepth1 == 16) {
				if (!(value1 == 0)) {
					b1 = (value1 & 31) << 3;
					b1 += ((unsigned) b1) >> 5;
					g1 = ((((unsigned) value1) >> 5) & 31) << 3;
					g1 += ((unsigned) g1) >> 5;
					r1 = ((((unsigned) value1) >> 10) & 31) << 3;
					r1 += ((unsigned) r1) >> 5;
					a1 = 255;
					value1 = ((b1 + (g1 << 8)) + (r1 << 16)) + (a1 << 24);
				}
			} else {
				if ((objBuffer[bmFill + 15]) == 0) {
					value1 = 0;
				} else {
					value1 = ((objBuffer + bmFill) + 18)[value1];
				}
			}
			fillValue = uncheckedTransformColor(value1);
		l9:	/* end bitmapValue:bits:atX:y: */;
			fillValue = ((unsigned) (fillValue & cMask)) >> cShift;
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + fillValue);
		}
		ds += dsX << cShift;
		dt += dtX << cShift;
		x += aaLevel;
	}
	cMask = workBuffer[51];
	cShift = workBuffer[50];
	while (x < rightX) {
		if (tileFlag) {
			/* begin repeatValue:max: */
			newDelta4 = ds;
			while (newDelta4 < 0) {
				newDelta4 += bmWidth << 16;
			}
			while (newDelta4 >= (bmWidth << 16)) {
				newDelta4 -= bmWidth << 16;
			}
			ds = newDelta4;
			/* begin repeatValue:max: */
			newDelta5 = dt;
			while (newDelta5 < 0) {
				newDelta5 += bmHeight << 16;
			}
			while (newDelta5 >= (bmHeight << 16)) {
				newDelta5 -= bmHeight << 16;
			}
			dt = newDelta5;
		}
		xp = ((int) ds >> 16);
		yp = ((int) dt >> 16);
		if (!(tileFlag)) {
			/* begin clampValue:max: */
			if (xp < 0) {
				xp = 0;
				goto l5;
			} else {
				if (xp >= bmWidth) {
					xp = bmWidth - 1;
					goto l5;
				} else {
					xp = xp;
					goto l5;
				}
			}
		l5:	/* end clampValue:max: */;
			/* begin clampValue:max: */
			if (yp < 0) {
				yp = 0;
				goto l6;
			} else {
				if (yp >= bmHeight) {
					yp = bmHeight - 1;
					goto l6;
				} else {
					yp = yp;
					goto l6;
				}
			}
		l6:	/* end clampValue:max: */;
		}
		if ((xp >= 0) && ((yp >= 0) && ((xp < bmWidth) && (yp < bmHeight)))) {
			/* begin bitmapValue:bits:atX:y: */
			bmDepth2 = objBuffer[bmFill + 12];
			bmRaster2 = objBuffer[bmFill + 14];
			if (bmDepth2 == 32) {
				value2 = (((int*) bits))[(bmRaster2 * yp) + xp];
				if ((value2 != 0) && ((value2 & 4278190080U) == 0)) {
					value2 = value2 | 4278190080U;
				}
				fillValue = uncheckedTransformColor(value2);
				goto l10;
			}
			rShift2 = (rShiftTable())[bmDepth2];
			value2 = (((int*) bits))[(bmRaster2 * yp) + (((unsigned) xp) >> rShift2)];
			cMask3 = (1 << bmDepth2) - 1;
			rShift2 = (32 - bmDepth2) - ((xp & ((1 << rShift2) - 1)) * bmDepth2);
			value2 = (((unsigned) value2) >> rShift2) & cMask3;
			if (bmDepth2 == 16) {
				if (!(value2 == 0)) {
					b2 = (value2 & 31) << 3;
					b2 += ((unsigned) b2) >> 5;
					g2 = ((((unsigned) value2) >> 5) & 31) << 3;
					g2 += ((unsigned) g2) >> 5;
					r2 = ((((unsigned) value2) >> 10) & 31) << 3;
					r2 += ((unsigned) r2) >> 5;
					a2 = 255;
					value2 = ((b2 + (g2 << 8)) + (r2 << 16)) + (a2 << 24);
				}
			} else {
				if ((objBuffer[bmFill + 15]) == 0) {
					value2 = 0;
				} else {
					value2 = ((objBuffer + bmFill) + 18)[value2];
				}
			}
			fillValue = uncheckedTransformColor(value2);
		l10:	/* end bitmapValue:bits:atX:y: */;
			fillValue = ((unsigned) (fillValue & cMask)) >> cShift;
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + fillValue);
		}
		ds += dsX;
		dt += dtX;
		x += 1;
	}
}

int fillColorSpanAAx0x1(int pixelValue32, int leftX, int rightX) {
    int aaLevel;
    int idx;
    int pv32;
    int firstPixel;
    int lastPixel;
    int x;
    int colorMask;
    int baseShift;
    int firstPixel1;

	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[48])) - 1) & (~((workBuffer[48]) - 1));
	if (firstPixel1 > rightX) {
		firstPixel = rightX;
		goto l1;
	} else {
		firstPixel = firstPixel1;
		goto l1;
	}
l1:	/* end aaFirstPixelFrom:to: */;
	lastPixel = (rightX - 1) & (~((workBuffer[48]) - 1));
	aaLevel = workBuffer[48];
	baseShift = workBuffer[49];
	x = leftX;
	if (x < firstPixel) {
		pv32 = ((unsigned) (pixelValue32 & (workBuffer[51]))) >> (workBuffer[50]);
		while (x < firstPixel) {
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + pv32);
			x += 1;
		}
	}
	if (x < lastPixel) {
		colorMask = (((unsigned) (workBuffer[51])) >> (workBuffer[49])) | 4042322160U;
		pv32 = ((unsigned) (pixelValue32 & colorMask)) >> (workBuffer[49]);
		while (x < lastPixel) {
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + pv32);
			x += aaLevel;
		}
	}
	if (x < rightX) {
		pv32 = ((unsigned) (pixelValue32 & (workBuffer[51]))) >> (workBuffer[50]);
		while (x < rightX) {
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + pv32);
			x += 1;
		}
	}
}

int fillLinearGradientfromtoat(int fill, int leftX, int rightX, int yValue) {
    int ds;
    int dsX;
    int rampIndex;
    int *ramp;
    int x0;
    int x1;
    int x;
    int rampSize;
    int x01;
    int x11;
    int x02;
    int x12;

	ramp = (objBuffer + fill) + 12;
	rampSize = objBuffer[fill + 10];
	dsX = objBuffer[fill + 6];
	ds = ((leftX - (objBuffer[fill + 4])) * dsX) + ((yValue - (objBuffer[fill + 5])) * (objBuffer[fill + 7]));
	x = x0 = leftX;
	x1 = rightX;
	while (((rampIndex = ((int) ds >> 16)) < 0) && (x < x1)) {
		x += 1;
		ds += dsX;
	}
	if (x > x0) {
		/* begin fillColorSpan:from:to: */
		if (!((workBuffer[48]) == 1)) {
			fillColorSpanAAx0x1(ramp[0], x0, x);
			goto l1;
		}
		x01 = x0;
		x11 = x;
		while ((x01 + 4) < x11) {
			spanBuffer[x01] = (ramp[0]);
			spanBuffer[x01 + 1] = (ramp[0]);
			spanBuffer[x01 + 2] = (ramp[0]);
			spanBuffer[x01 + 3] = (ramp[0]);
			x01 += 4;
		}
		while (x01 < x11) {
			spanBuffer[x01] = (ramp[0]);
			x01 += 1;
		}
	l1:	/* end fillColorSpan:from:to: */;
	}
	if ((workBuffer[48]) == 1) {
		while ((((rampIndex = ((int) ds >> 16)) < rampSize) && (rampIndex >= 0)) && (x < x1)) {
			spanBuffer[x] = (ramp[rampIndex]);
			x += 1;
			ds += dsX;
		}
	} else {
		x = fillLinearGradientAArampdsdsXfromto(fill, ramp, ds, dsX, x, rightX);
	}
	if (x < x1) {
		if (rampIndex < 0) {
			rampIndex = 0;
		}
		if (rampIndex >= rampSize) {
			rampIndex = rampSize - 1;
		}
		/* begin fillColorSpan:from:to: */
		if (!((workBuffer[48]) == 1)) {
			fillColorSpanAAx0x1(ramp[rampIndex], x, x1);
			goto l2;
		}
		x02 = x;
		x12 = x1;
		while ((x02 + 4) < x12) {
			spanBuffer[x02] = (ramp[rampIndex]);
			spanBuffer[x02 + 1] = (ramp[rampIndex]);
			spanBuffer[x02 + 2] = (ramp[rampIndex]);
			spanBuffer[x02 + 3] = (ramp[rampIndex]);
			x02 += 4;
		}
		while (x02 < x12) {
			spanBuffer[x02] = (ramp[rampIndex]);
			x02 += 1;
		}
	l2:	/* end fillColorSpan:from:to: */;
	}
}

int fillLinearGradientAArampdsdsXfromto(int fill, int *ramp, int deltaS, int dsX, int leftX, int rightX) {
    int aaLevel;
    int ds;
    int idx;
    int rampIndex;
    int colorShift;
    int firstPixel;
    int lastPixel;
    int x;
    int colorMask;
    int rampValue;
    int rampSize;
    int baseShift;
    int firstPixel1;

	aaLevel = workBuffer[48];
	baseShift = workBuffer[49];
	rampSize = objBuffer[fill + 10];
	ds = deltaS;
	x = leftX;
	rampIndex = ((int) ds >> 16);
	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[48])) - 1) & (~((workBuffer[48]) - 1));
	if (firstPixel1 > rightX) {
		firstPixel = rightX;
		goto l1;
	} else {
		firstPixel = firstPixel1;
		goto l1;
	}
l1:	/* end aaFirstPixelFrom:to: */;
	lastPixel = (rightX - 1) & (~((workBuffer[48]) - 1));
	colorMask = workBuffer[51];
	colorShift = workBuffer[50];
	while ((x < firstPixel) && ((rampIndex < rampSize) && (rampIndex >= 0))) {
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while ((x < firstPixel) && ((((int) ds >> 16)) == rampIndex)) {
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + rampValue);
			x += 1;
			ds += dsX;
		}
		rampIndex = ((int) ds >> 16);
	}
	colorMask = (((unsigned) (workBuffer[51])) >> (workBuffer[49])) | 4042322160U;
	colorShift = workBuffer[49];
	while ((x < lastPixel) && ((rampIndex < rampSize) && (rampIndex >= 0))) {
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while ((x < lastPixel) && ((((int) ds >> 16)) == rampIndex)) {
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + rampValue);
			x += aaLevel;
			ds += dsX << colorShift;
		}
		rampIndex = ((int) ds >> 16);
	}
	colorMask = workBuffer[51];
	colorShift = workBuffer[50];
	while ((x < rightX) && ((rampIndex < rampSize) && (rampIndex >= 0))) {
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while ((x < rightX) && ((((int) ds >> 16)) == rampIndex)) {
			idx = ((unsigned) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + rampValue);
			x += 1;
			ds += dsX;
		}
		rampIndex = ((int) ds >> 16);
	}
	return x;
}

int fillRadialDecreasingAArampdeltaSTdsXdtXfromto(int fill, int *ramp,  int *deltaST, int dsX, int dtX, int leftX, int rightX) {
    int nextLength;
    int aaLevel;
    int ds;
    int dt;
    int rampIndex;
    int length2;
    int colorShift;
    int index;
    int firstPixel;
    int lastPixel;
    int x;
    int x1;
    int colorMask;
    int rampValue;
    int baseShift;
    int firstPixel1;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	aaLevel = workBuffer[48];
	baseShift = workBuffer[49];
	rampIndex = accurateLengthOfwith(((int) ds >> 16), ((int) dt >> 16));
	length2 = (rampIndex - 1) * (rampIndex - 1);
	x = leftX;
	x1 = objBuffer[fill + 4];
	if (x1 > rightX) {
		x1 = rightX;
	}
	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[48])) - 1) & (~((workBuffer[48]) - 1));
	if (firstPixel1 > x1) {
		firstPixel = x1;
		goto l1;
	} else {
		firstPixel = firstPixel1;
		goto l1;
	}
l1:	/* end aaFirstPixelFrom:to: */;
	lastPixel = (x1 - 1) & (~((workBuffer[48]) - 1));
	if (x < firstPixel) {
		colorMask = workBuffer[51];
		colorShift = workBuffer[50];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while (x < firstPixel) {
			while ((x < firstPixel) && ((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) >= length2)) {
				index = ((unsigned) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += 1;
				ds += dsX;
				dt += dtX;
			}
			nextLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
			while (nextLength < length2) {
				rampIndex -= 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
				length2 = (rampIndex - 1) * (rampIndex - 1);
			}
		}
	}
	if (x < lastPixel) {
		colorMask = (((unsigned) (workBuffer[51])) >> (workBuffer[49])) | 4042322160U;
		colorShift = workBuffer[49];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while (x < lastPixel) {
			while ((x < lastPixel) && ((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) >= length2)) {
				index = ((unsigned) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += aaLevel;
				ds += dsX << colorShift;
				dt += dtX << colorShift;
			}
			nextLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
			while (nextLength < length2) {
				rampIndex -= 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
				length2 = (rampIndex - 1) * (rampIndex - 1);
			}
		}
	}
	if (x < x1) {
		colorMask = workBuffer[51];
		colorShift = workBuffer[50];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while (x < x1) {
			while ((x < x1) && ((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) >= length2)) {
				index = ((unsigned) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += 1;
				ds += dsX;
				dt += dtX;
			}
			nextLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
			while (nextLength < length2) {
				rampIndex -= 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
				length2 = (rampIndex - 1) * (rampIndex - 1);
			}
		}
	}
	(((int *) deltaST))[0] = ds;
	(((int *) deltaST))[1] = dt;
	return x;
}

int fillRadialGradientfromtoat(int fill, int leftX, int rightX, int yValue) {
    int deltaX;
    int deltaY;
    int ds;
    int dsX;
    int dtX;
    int dt;
    int length2;
    int *ramp;
    int x;
    int x1;
    int rampSize;
    int *deltaST;
    int x0;
    int x11;
    int nextLength;
    int ds1;
    int dt1;
    int rampIndex;
    int length21;
    int x2;
    int x12;
    int rampValue;
    int lastLength;
    int rampSize1;
    int x01;
    int x13;
    int nextLength1;
    int ds2;
    int dt2;
    int rampIndex1;
    int length22;
    int x3;
    int x14;
    int rampValue1;

	ramp = (objBuffer + fill) + 12;
	rampSize = objBuffer[fill + 10];
	deltaX = leftX - (objBuffer[fill + 4]);
	deltaY = yValue - (objBuffer[fill + 5]);
	dsX = objBuffer[fill + 6];
	dtX = objBuffer[fill + 8];
	ds = (deltaX * dsX) + (deltaY * (objBuffer[fill + 7]));
	dt = (deltaX * dtX) + (deltaY * (objBuffer[fill + 9]));
	x = leftX;
	x1 = rightX;
	length2 = (rampSize - 1) * (rampSize - 1);
	while (((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) >= length2) && (x < x1)) {
		x += 1;
		ds += dsX;
		dt += dtX;
	}
	if (x > leftX) {
		/* begin fillColorSpan:from:to: */
		if (!((workBuffer[48]) == 1)) {
			fillColorSpanAAx0x1(ramp[rampSize - 1], leftX, x);
			goto l1;
		}
		x0 = leftX;
		x11 = x;
		while ((x0 + 4) < x11) {
			spanBuffer[x0] = (ramp[rampSize - 1]);
			spanBuffer[x0 + 1] = (ramp[rampSize - 1]);
			spanBuffer[x0 + 2] = (ramp[rampSize - 1]);
			spanBuffer[x0 + 3] = (ramp[rampSize - 1]);
			x0 += 4;
		}
		while (x0 < x11) {
			spanBuffer[x0] = (ramp[rampSize - 1]);
			x0 += 1;
		}
	l1:	/* end fillColorSpan:from:to: */;
	}
	deltaST = ((int *) (workBuffer + 80));
	deltaST[0] = ds;
	deltaST[1] = dt;
	if (x < (objBuffer[fill + 4])) {
		if ((workBuffer[48]) == 1) {
			/* begin fillRadialDecreasing:ramp:deltaST:dsX:dtX:from:to: */
			ds2 = (((int*) deltaST))[0];
			dt2 = (((int*) deltaST))[1];
			rampIndex1 = accurateLengthOfwith(((int) ds2 >> 16), ((int) dt2 >> 16));
			rampValue1 = (((int *) ramp))[rampIndex1];
			length22 = (rampIndex1 - 1) * (rampIndex1 - 1);
			x3 = x;
			x14 = x1;
			if (x14 > (objBuffer[fill + 4])) {
				x14 = objBuffer[fill + 4];
			}
			while (x3 < x14) {
				while ((x3 < x14) && ((((((int) ds2 >> 16)) * (((int) ds2 >> 16))) + ((((int) dt2 >> 16)) * (((int) dt2 >> 16)))) >= length22)) {
					spanBuffer[x3] = rampValue1;
					x3 += 1;
					ds2 += dsX;
					dt2 += dtX;
				}
				nextLength1 = ((((int) ds2 >> 16)) * (((int) ds2 >> 16))) + ((((int) dt2 >> 16)) * (((int) dt2 >> 16)));
				while (nextLength1 < length22) {
					rampIndex1 -= 1;
					rampValue1 = (((int *) ramp))[rampIndex1];
					length22 = (rampIndex1 - 1) * (rampIndex1 - 1);
				}
			}
			(((int *) deltaST))[0] = ds2;
			(((int *) deltaST))[1] = dt2;
			x = x3;
		} else {
			x = fillRadialDecreasingAArampdeltaSTdsXdtXfromto(fill, ramp, deltaST, dsX, dtX, x, x1);
		}
	}
	if (x < x1) {
		if ((workBuffer[48]) == 1) {
			/* begin fillRadialIncreasing:ramp:deltaST:dsX:dtX:from:to: */
			ds1 = (((int*) deltaST))[0];
			dt1 = (((int*) deltaST))[1];
			rampIndex = accurateLengthOfwith(((int) ds1 >> 16), ((int) dt1 >> 16));
			rampValue = (((int *) ramp))[rampIndex];
			rampSize1 = objBuffer[fill + 10];
			length21 = (rampSize1 - 1) * (rampSize1 - 1);
			nextLength = (rampIndex + 1) * (rampIndex + 1);
			lastLength = ((((int) ds1 >> 16)) * (((int) ds1 >> 16))) + ((((int) dt1 >> 16)) * (((int) dt1 >> 16)));
			x2 = x;
			x12 = x1;
			while ((x2 < x12) && (lastLength < length21)) {
				while ((x2 < x12) && ((((((int) ds1 >> 16)) * (((int) ds1 >> 16))) + ((((int) dt1 >> 16)) * (((int) dt1 >> 16)))) <= nextLength)) {
					spanBuffer[x2] = rampValue;
					x2 += 1;
					ds1 += dsX;
					dt1 += dtX;
				}
				lastLength = ((((int) ds1 >> 16)) * (((int) ds1 >> 16))) + ((((int) dt1 >> 16)) * (((int) dt1 >> 16)));
				while (lastLength > nextLength) {
					rampIndex += 1;
					rampValue = (((int *) ramp))[rampIndex];
					nextLength = (rampIndex + 1) * (rampIndex + 1);
				}
			}
			(((int *) deltaST))[0] = ds1;
			(((int *) deltaST))[1] = dt1;
			x = x2;
		} else {
			x = fillRadialIncreasingAArampdeltaSTdsXdtXfromto(fill, ramp, deltaST, dsX, dtX, x, x1);
		}
	}
	if (x < rightX) {
		/* begin fillColorSpan:from:to: */
		if (!((workBuffer[48]) == 1)) {
			fillColorSpanAAx0x1(ramp[rampSize - 1], x, rightX);
			goto l2;
		}
		x01 = x;
		x13 = rightX;
		while ((x01 + 4) < x13) {
			spanBuffer[x01] = (ramp[rampSize - 1]);
			spanBuffer[x01 + 1] = (ramp[rampSize - 1]);
			spanBuffer[x01 + 2] = (ramp[rampSize - 1]);
			spanBuffer[x01 + 3] = (ramp[rampSize - 1]);
			x01 += 4;
		}
		while (x01 < x13) {
			spanBuffer[x01] = (ramp[rampSize - 1]);
			x01 += 1;
		}
	l2:	/* end fillColorSpan:from:to: */;
	}
}

int fillRadialIncreasingAArampdeltaSTdsXdtXfromto(int fill, int *ramp,  int *deltaST, int dsX, int dtX, int leftX, int rightX) {
    int nextLength;
    int aaLevel;
    int ds;
    int dt;
    int rampIndex;
    int length2;
    int colorShift;
    int index;
    int firstPixel;
    int lastPixel;
    int x;
    int colorMask;
    int rampValue;
    int lastLength;
    int rampSize;
    int baseShift;
    int firstPixel1;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	aaLevel = workBuffer[48];
	baseShift = workBuffer[49];
	rampIndex = accurateLengthOfwith(((int) ds >> 16), ((int) dt >> 16));
	rampSize = objBuffer[fill + 10];
	length2 = (rampSize - 1) * (rampSize - 1);
	nextLength = (rampIndex + 1) * (rampIndex + 1);
	lastLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
	x = leftX;
	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[48])) - 1) & (~((workBuffer[48]) - 1));
	if (firstPixel1 > rightX) {
		firstPixel = rightX;
		goto l1;
	} else {
		firstPixel = firstPixel1;
		goto l1;
	}
l1:	/* end aaFirstPixelFrom:to: */;
	lastPixel = (rightX - 1) & (~((workBuffer[48]) - 1));
	if ((x < firstPixel) && (lastLength < length2)) {
		colorMask = workBuffer[51];
		colorShift = workBuffer[50];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while ((x < firstPixel) && (lastLength < length2)) {
			while ((x < firstPixel) && ((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) <= nextLength)) {
				index = ((unsigned) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += 1;
				ds += dsX;
				dt += dtX;
			}
			lastLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
			while (lastLength > nextLength) {
				rampIndex += 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
				nextLength = (rampIndex + 1) * (rampIndex + 1);
			}
		}
	}
	if ((x < lastPixel) && (lastLength < length2)) {
		colorMask = (((unsigned) (workBuffer[51])) >> (workBuffer[49])) | 4042322160U;
		colorShift = workBuffer[49];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while ((x < lastPixel) && (lastLength < length2)) {
			while ((x < lastPixel) && ((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) <= nextLength)) {
				index = ((unsigned) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += aaLevel;
				ds += dsX << colorShift;
				dt += dtX << colorShift;
			}
			lastLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
			while (lastLength > nextLength) {
				rampIndex += 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
				nextLength = (rampIndex + 1) * (rampIndex + 1);
			}
		}
	}
	if ((x < rightX) && (lastLength < length2)) {
		colorMask = workBuffer[51];
		colorShift = workBuffer[50];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
		while ((x < rightX) && (lastLength < length2)) {
			while ((x < rightX) && ((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) <= nextLength)) {
				index = ((unsigned) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += 1;
				ds += dsX;
				dt += dtX;
			}
			lastLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
			while (lastLength > nextLength) {
				rampIndex += 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((unsigned) (rampValue & colorMask)) >> colorShift;
				nextLength = (rampIndex + 1) * (rampIndex + 1);
			}
		}
	}
	(((int *) deltaST))[0] = ds;
	(((int *) deltaST))[1] = dt;
	return x;
}

int fillSortsbefore(int fillEntry1, int fillEntry2) {
    int diff;

	diff = (workBuffer[(workBuffer[10]) + (fillEntry1 + 1)]) - (workBuffer[(workBuffer[10]) + (fillEntry2 + 1)]);
	if (!(diff == 0)) {
		return diff > 0;
	}
	return (((unsigned) (workBuffer[(workBuffer[10]) + fillEntry1]))) < (((unsigned) (workBuffer[(workBuffer[10]) + fillEntry2])));
}

int fillSpanfromto(int fill, int leftX, int rightX) {
    int x0;
    int x1;
    int type;
    int x01;
    int x11;

	if (fill == 0) {
		return 0;
	}
	if (leftX < (workBuffer[35])) {
		x0 = workBuffer[35];
	} else {
		x0 = leftX;
	}
	if (rightX > ((workBuffer[33]) << (workBuffer[49]))) {
		x1 = (workBuffer[33]) << (workBuffer[49]);
	} else {
		x1 = rightX;
	}
	if (x0 < (workBuffer[36])) {
		x0 = workBuffer[36];
	}
	if (x1 > (workBuffer[37])) {
		x1 = workBuffer[37];
	}
	if (x0 < (workBuffer[32])) {
		workBuffer[32] = x0;
	}
	if (x1 > (workBuffer[34])) {
		workBuffer[34] = x1;
	}
	if (x1 > (workBuffer[35])) {
		workBuffer[35] = x1;
	}
	if (x0 >= x1) {
		return 0;
	}
	if ((fill & 4278190080U) != 0) {
		/* begin fillColorSpan:from:to: */
		if (!((workBuffer[48]) == 1)) {
			fillColorSpanAAx0x1(fill, x0, x1);
			goto l1;
		}
		x01 = x0;
		x11 = x1;
		while ((x01 + 4) < x11) {
			spanBuffer[x01] = fill;
			spanBuffer[x01 + 1] = fill;
			spanBuffer[x01 + 2] = fill;
			spanBuffer[x01 + 3] = fill;
			x01 += 4;
		}
		while (x01 < x11) {
			spanBuffer[x01] = fill;
			x01 += 1;
		}
	l1:	/* end fillColorSpan:from:to: */;
	} else {
		workBuffer[66] = fill;
		workBuffer[67] = x0;
		workBuffer[68] = x1;
		type = ((unsigned) (((objBuffer[fill + 0]) & 65535) & 65280)) >> 8;
		if (type <= 1) {
			return 1;
		}
		switch (type) {
		case 0:
		case 1:
			errorWrongIndex();
			break;
		case 2:
			fillLinearGradientfromtoat(workBuffer[66], workBuffer[67], workBuffer[68], workBuffer[88]);
			break;
		case 3:
			fillRadialGradientfromtoat(workBuffer[66], workBuffer[67], workBuffer[68], workBuffer[88]);
			break;
		case 4:
		case 5:
			fillBitmapSpanfromtoat(workBuffer[66], workBuffer[67], workBuffer[68], workBuffer[88]);
			break;
		}
	}
	return 0;
}

int finalizeReference(int oop) {
    int chunk;
    int oopGone;
    int firstField;
    int lastField;
    int i;
    int weakOop;
    int extra;
    int methodHeader;
    int sz;
    int fmt;
    int header;
    int header1;
    int type;
    int type1;
    int extra1;

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

int findNewMethodInClass(int class) {
    int ok;
    int probe;
    int hash;

	/* begin lookupInMethodCacheSel:class: */
	hash = messageSelector ^ class;
	probe = hash & 2044;
	if (((methodCache[probe + 1]) == messageSelector) && ((methodCache[probe + 2]) == class)) {
		newMethod = methodCache[probe + 3];
		primitiveIndex = methodCache[probe + 4];
		ok = 1;
		goto l1;
	}
	probe = (((unsigned) hash) >> 1) & 2044;
	if (((methodCache[probe + 1]) == messageSelector) && ((methodCache[probe + 2]) == class)) {
		newMethod = methodCache[probe + 3];
		primitiveIndex = methodCache[probe + 4];
		ok = 1;
		goto l1;
	}
	probe = (((unsigned) hash) >> 2) & 2044;
	if (((methodCache[probe + 1]) == messageSelector) && ((methodCache[probe + 2]) == class)) {
		newMethod = methodCache[probe + 3];
		primitiveIndex = methodCache[probe + 4];
		ok = 1;
		goto l1;
	}
	ok = 0;
l1:	/* end lookupInMethodCacheSel:class: */;
	if (!(ok)) {
		lookupMethodInClass(class);
		addToMethodCacheSelclassmethodprimIndex(messageSelector, class, newMethod, primitiveIndex);
	}
}

int findNextExternalEntryFromGET(void) {
    int edge;
    int yValue;
    int type;

	yValue = workBuffer[88];
	while ((workBuffer[11]) < (workBuffer[12])) {
		edge = getBuffer[workBuffer[11]];
		if ((objBuffer[edge + 5]) > yValue) {
			return 0;
		}
		type = (objBuffer[edge + 0]) & 65535;
		if ((type & 254) == 2) {
			return 1;
		}
		if (!(needAvailableSpace(1))) {
			return 0;
		}
		switch (type) {
		case 0:
		case 1:
		case 2:
		case 3:
			errorWrongIndex();
			break;
		case 4:
			stepToFirstLineInat(getBuffer[workBuffer[11]], workBuffer[88]);
			break;
		case 5:
			stepToFirstWideLineInat(getBuffer[workBuffer[11]], workBuffer[88]);
			break;
		case 6:
			stepToFirstBezierInat(getBuffer[workBuffer[11]], workBuffer[88]);
			break;
		case 7:
			stepToFirstWideBezierInat(getBuffer[workBuffer[11]], workBuffer[88]);
			break;
		}
		insertEdgeIntoAET(edge);
		workBuffer[11] = ((workBuffer[11]) + 1);
	}
	return 0;
}

int findNextExternalFillFromAET(void) {
    int leftEdge;
    int rightEdge;
    int leftX;
    int rightX;
    int fill;
    int stopX;
    int startX;
    int someIntegerValue;
    int someIntegerValue1;
    int rightX1;
    int fill1;
    int stopX1;
    int startX1;
    int someIntegerValue2;
    int someIntegerValue11;

	leftX = rightX = workBuffer[37];
	while ((workBuffer[13]) < (workBuffer[14])) {
		leftEdge = rightEdge = aetBuffer[workBuffer[13]];
		leftX = rightX = objBuffer[leftEdge + 4];
		if (leftX >= (workBuffer[37])) {
			return 0;
		}
		/* begin quickRemoveInvalidFillsAt: */
		if (((workBuffer[1]) - (workBuffer[10])) == 0) {
			goto l3;
		}
		while ((topRightX()) <= leftX) {
			hideFilldepth(topFill(), topDepth());
			if (((workBuffer[1]) - (workBuffer[10])) == 0) {
				goto l3;
			}
		}
	l3:	/* end quickRemoveInvalidFillsAt: */;
		if ((((objBuffer[leftEdge + 0]) & 65535) & 1) != 0) {
			toggleWideFillOf(leftEdge);
		}
		if (((objBuffer[leftEdge + 0]) & 65536) == 0) {
			toggleFillsOf(leftEdge);
			if (engineStopped) {
				return 0;
			}
		}
		workBuffer[13] = ((workBuffer[13]) + 1);
		if ((workBuffer[13]) < (workBuffer[14])) {
			rightEdge = aetBuffer[workBuffer[13]];
			rightX = objBuffer[rightEdge + 4];
			if (rightX >= (workBuffer[36])) {
				/* begin fillAllFrom:to: */
				/* begin topFill */
				if (((workBuffer[1]) - (workBuffer[10])) == 0) {
					fill = 0;
					goto l8;
				} else {
					fill = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
					goto l8;
				}
			l8:	/* end topFill */;
				startX = leftX;
				/* begin topRightX */
				if (((workBuffer[1]) - (workBuffer[10])) == 0) {
					stopX = 999999999;
					goto l9;
				} else {
					stopX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
					goto l9;
				}
			l9:	/* end topRightX */;
				while (stopX < rightX) {
					/* begin makeUnsignedFrom: */
					/* begin topFill */
					if (((workBuffer[1]) - (workBuffer[10])) == 0) {
						someIntegerValue = 0;
						goto l6;
					} else {
						someIntegerValue = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
						goto l6;
					}
				l6:	/* end topFill */;
					fill = someIntegerValue;
					if (!(fill == 0)) {
						if (fillSpanfromto(fill, startX, stopX)) {
							goto l2;
						}
					}
					/* begin quickRemoveInvalidFillsAt: */
					if (((workBuffer[1]) - (workBuffer[10])) == 0) {
						goto l1;
					}
					while ((topRightX()) <= stopX) {
						hideFilldepth(topFill(), topDepth());
						if (((workBuffer[1]) - (workBuffer[10])) == 0) {
							goto l1;
						}
					}
				l1:	/* end quickRemoveInvalidFillsAt: */;
					startX = stopX;
					/* begin topRightX */
					if (((workBuffer[1]) - (workBuffer[10])) == 0) {
						stopX = 999999999;
						goto l7;
					} else {
						stopX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
						goto l7;
					}
				l7:	/* end topRightX */;
				}
				/* begin makeUnsignedFrom: */
				/* begin topFill */
				if (((workBuffer[1]) - (workBuffer[10])) == 0) {
					someIntegerValue1 = 0;
					goto l10;
				} else {
					someIntegerValue1 = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
					goto l10;
				}
			l10:	/* end topFill */;
				fill = someIntegerValue1;
				if (!(fill == 0)) {
					fillSpanfromto(fill, startX, rightX);
					goto l2;
				}
			l2:	/* end fillAllFrom:to: */;
			}
		}
	}
	if (rightX < (workBuffer[37])) {
		/* begin fillAllFrom:to: */
		rightX1 = workBuffer[37];
		/* begin topFill */
		if (((workBuffer[1]) - (workBuffer[10])) == 0) {
			fill1 = 0;
			goto l13;
		} else {
			fill1 = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
			goto l13;
		}
	l13:	/* end topFill */;
		startX1 = rightX;
		/* begin topRightX */
		if (((workBuffer[1]) - (workBuffer[10])) == 0) {
			stopX1 = 999999999;
			goto l14;
		} else {
			stopX1 = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
			goto l14;
		}
	l14:	/* end topRightX */;
		while (stopX1 < rightX1) {
			/* begin makeUnsignedFrom: */
			/* begin topFill */
			if (((workBuffer[1]) - (workBuffer[10])) == 0) {
				someIntegerValue2 = 0;
				goto l11;
			} else {
				someIntegerValue2 = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
				goto l11;
			}
		l11:	/* end topFill */;
			fill1 = someIntegerValue2;
			if (!(fill1 == 0)) {
				if (fillSpanfromto(fill1, startX1, stopX1)) {
					goto l5;
				}
			}
			/* begin quickRemoveInvalidFillsAt: */
			if (((workBuffer[1]) - (workBuffer[10])) == 0) {
				goto l4;
			}
			while ((topRightX()) <= stopX1) {
				hideFilldepth(topFill(), topDepth());
				if (((workBuffer[1]) - (workBuffer[10])) == 0) {
					goto l4;
				}
			}
		l4:	/* end quickRemoveInvalidFillsAt: */;
			startX1 = stopX1;
			/* begin topRightX */
			if (((workBuffer[1]) - (workBuffer[10])) == 0) {
				stopX1 = 999999999;
				goto l12;
			} else {
				stopX1 = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
				goto l12;
			}
		l12:	/* end topRightX */;
		}
		/* begin makeUnsignedFrom: */
		/* begin topFill */
		if (((workBuffer[1]) - (workBuffer[10])) == 0) {
			someIntegerValue11 = 0;
			goto l15;
		} else {
			someIntegerValue11 = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
			goto l15;
		}
	l15:	/* end topFill */;
		fill1 = someIntegerValue11;
		if (!(fill1 == 0)) {
			fillSpanfromto(fill1, startX1, rightX1);
			goto l5;
		}
	l5:	/* end fillAllFrom:to: */;
	}
	return 0;
}

int findNextExternalUpdateFromAET(void) {
    int count;
    int edge;
    int type;

	while ((workBuffer[13]) < (workBuffer[14])) {
		edge = aetBuffer[workBuffer[13]];
		count = (objBuffer[edge + 7]) - 1;
		if (count == 0) {
			removeFirstAETEntry();
		} else {
			objBuffer[edge + 7] = count;
			type = (objBuffer[edge + 0]) & 65535;
			if ((type & 254) == 2) {
				return 1;
			}
			switch (type) {
			case 0:
			case 1:
			case 2:
			case 3:
				errorWrongIndex();
				break;
			case 4:
				stepToNextLineInat(aetBuffer[workBuffer[13]], workBuffer[88]);
				break;
			case 5:
				stepToNextWideLineInat(aetBuffer[workBuffer[13]], workBuffer[88]);
				break;
			case 6:
				stepToNextBezierInat(aetBuffer[workBuffer[13]], workBuffer[88]);
				break;
			case 7:
				stepToNextWideBezier();
				break;
			}
			resortFirstAETEntry();
			workBuffer[13] = ((workBuffer[13]) + 1);
		}
	}
	return 0;
}

int findStackFilldepth(int fillIndex, int depth) {
    int index;

	index = 0;
	while ((index < ((workBuffer[1]) - (workBuffer[10]))) && (((workBuffer[(workBuffer[10]) + index]) != fillIndex) || ((workBuffer[(workBuffer[10]) + (index + 1)]) != depth))) {
		index += 3;
	}
	if (index >= ((workBuffer[1]) - (workBuffer[10]))) {
		return -1;
	} else {
		return index;
	}
}

void * firstFixedField(int oop) {
	return ((void *) (oop + 4));
}

void * firstIndexableField(int oop) {
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
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

double floatValueOf(int oop) {
    double result;
    int ccIndex;
    int cl;

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

int fullDisplayUpdate(void) {
    int displayObj;
    int dispBits;
    int dispBitsIndex;
    int h;
    int w;
    int d;

	displayObj = longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
	if ((((((unsigned) (longAt(displayObj))) >> 8) & 15) <= 4) && ((lengthOf(displayObj)) >= 4)) {
		dispBits = longAt(((((char *) displayObj)) + 4) + (0 << 2));
		w = fetchIntegerofObject(1, displayObj);
		h = fetchIntegerofObject(2, displayObj);
		d = fetchIntegerofObject(3, displayObj);
		dispBitsIndex = dispBits + 4;
		ioShowDisplay(dispBitsIndex, w, h, d, 0, w, 0, h);
		ioForceDisplayUpdate();
	}
}

int fullGC(void) {
    int startTime;
    int oop;
    int i;

	;
	/* begin preGCAction: */
	/* begin compilerPreGCHook: */
	if (compilerInitialized) {
		compilerPreGC(1);
	}
	if (!(activeContext == nilObj)) {
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
	youngStart = startOfMemory();
	markPhase();
	sweepPhase();
	/* begin fullCompaction */
	compStart = lowestFreeAfter(startOfMemory());
	if (compStart == freeBlock) {
		initializeMemoryFirstFree(freeBlock);
		goto l1;
	}
	while (compStart < freeBlock) {
		compStart = incCompBody();
	}
l1:	/* end fullCompaction */;
	allocationCount = 0;
	statFullGCs += 1;
	statFullGCMSecs += (ioMicroMSecs()) - startTime;
	youngStart = freeBlock;
	/* begin postGCAction */
	/* begin compilerPostGCHook */
	if (compilerInitialized) {
		compilerPostGC();
	}
	if (activeContext < youngStart) {
		beRootIfOld(activeContext);
	}
	if (theHomeContext < youngStart) {
		beRootIfOld(theHomeContext);
	}
	;
}

int fwdTableInit(int blkSize) {
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (4 & 4294967292U) | 2);
	endOfMemory = freeBlock + 4;
	/* begin setSizeOfFree:to: */
	longAtput(endOfMemory, (4 & 4294967292U) | 2);
	fwdTableNext = ((endOfMemory + 4) + 7) & 4294967288U;
	fwdTableLast = memoryLimit - blkSize;
	return (fwdTableLast - fwdTableNext) / blkSize;
}

EXPORT(int) gePrimitiveAbortProcessing(void) {
    int oop;

	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	workBuffer[2] = 8;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
}

EXPORT(int) gePrimitiveAddActiveEdgeEntry(void) {
    int edgeOop;
    int edge;
    int value;
    int oop;
    int oop1;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		edgeOop = null;
		goto l1;
	}
	edgeOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 2))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	edge = loadEdgeStateFrom(edgeOop);
	if (!successFlag) {
		return null;
	}
	if (!(needAvailableSpace(1))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((objBuffer[edge + 7]) > 0) {
		insertEdgeIntoAET(edge);
	}
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	workBuffer[2] = 1;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 1 * 4;
	if (doProfileStats) {
		workBuffer[97] = ((workBuffer[97]) + 1);
		/* begin incrementStat:by: */
		value = (ioMicroMSecs()) - geProfileTime;
		workBuffer[96] = ((workBuffer[96]) + value);
	}
}

EXPORT(int) gePrimitiveAddBezier(void) {
    int nSegments;
    int leftFill;
    int rightFill;
    int viaOop;
    int startOop;
    int endOop;
    int oop;
    int oop1;
    int oop2;

	if (!(argumentCount == 5)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	rightFill = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	leftFill = positive32BitValueOf(longAt(stackPointer - (1 * 4)));
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (2 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		viaOop = null;
		goto l1;
	}
	viaOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (3 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		endOop = null;
		goto l2;
	}
	endOop = oop1;
l2:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (4 * 4));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		startOop = null;
		goto l3;
	}
	startOop = oop2;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(5), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((isFillOkay(leftFill)) && (isFillOkay(rightFill)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((leftFill == rightFill) && 0) {
		/* begin pop: */
		stackPointer -= 6 * 4;
		return null;
	}
	loadPointfrom(((int *) (workBuffer + 80)), startOop);
	loadPointfrom(((int *) (workBuffer + 82)), viaOop);
	loadPointfrom(((int *) (workBuffer + 84)), endOop);
	if (!successFlag) {
		return 0;
	}
	/* begin transformPoints: */
	if (3 > 0) {
		transformPoint(((int *) (workBuffer + 80)));
	}
	if (3 > 1) {
		transformPoint(((int *) (workBuffer + 82)));
	}
	if (3 > 2) {
		transformPoint(((int *) (workBuffer + 84)));
	}
	if (3 > 3) {
		transformPoint(((int *) (workBuffer + 86)));
	}
	nSegments = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), 0);
	/* begin needAvailableSpace: */
	if (((((128 + objUsed) + (workBuffer[12])) + (workBuffer[14])) + (nSegments * 16)) > (workBuffer[10])) {
		/* begin stopBecauseOf: */
		workBuffer[64] = 1;
		engineStopped = 1;
		goto l4;
	}
l4:	/* end needAvailableSpace: */;
	if (!(engineStopped)) {
		leftFill = transformColor(leftFill);
		rightFill = transformColor(rightFill);
	}
	if (!(engineStopped)) {
		loadWideBezierlineFillleftFillrightFilln(0, 0, leftFill, rightFill, nSegments);
	}
	if (engineStopped) {
		/* begin wbStackClear */
		workBuffer[10] = (workBuffer[1]);
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 5 * 4;
	}
}

EXPORT(int) gePrimitiveAddBezierShape(void) {
    int nSegments;
    int points;
    int isArray;
    int segSize;
    int fillIndex;
    int lineFill;
    int length;
    int lineWidth;
    int integerPointer;
    int integerPointer1;
    int oop;
    int header;
    int sz;

	if (!(argumentCount == 5)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	lineFill = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		lineWidth = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		lineWidth = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	fillIndex = positive32BitValueOf(longAt(stackPointer - (2 * 4)));
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (3 * 4));
	if ((integerPointer1 & 1)) {
		nSegments = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		nSegments = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (4 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		points = null;
		goto l3;
	}
	points = oop;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(5), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin slotSizeOf: */
	if ((points & 1)) {
		length = 0;
		goto l4;
	}
	/* begin lengthOf: */
	header = longAt(points);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(points - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		length = ((unsigned) (sz - 4)) >> 2;
		goto l4;
	} else {
		length = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l4;
	}
	length = null;
l4:	/* end slotSizeOf: */;
	if (((((unsigned) (longAt(points))) >> 8) & 15) == 6) {
		isArray = 0;
		if (!((length == (nSegments * 3)) || (length == (nSegments * 6)))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	} else {
		if (!((fetchClassOf(points)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2))))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		if (!(length == (nSegments * 3))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		isArray = 1;
	}
	if ((lineWidth == 0) || (lineFill == 0)) {
		segSize = 16;
	} else {
		segSize = 21;
	}
	if (!(needAvailableSpace(segSize * nSegments))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((isFillOkay(lineFill)) && (isFillOkay(fillIndex)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	lineFill = transformColor(lineFill);
	fillIndex = transformColor(fillIndex);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (((lineFill == 0) || (lineWidth == 0)) && (fillIndex == 0)) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		return null;
	}
	if (!(lineWidth == 0)) {
		lineWidth = transformWidth(lineWidth);
		if (lineWidth < 1) {
			lineWidth = 1;
		}
	}
	if (isArray) {
		loadArrayShapenSegmentsfilllineWidthlineFill(points, nSegments, fillIndex, lineWidth, lineFill);
	} else {
		loadShapenSegmentsfilllineWidthlineFillpointsShort(firstIndexableField(points), nSegments, fillIndex, lineWidth, lineFill, (nSegments * 3) == length);
	}
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 5 * 4;
	}
}

EXPORT(int) gePrimitiveAddBitmapFill(void) {
    int dirOop;
    int xIndex;
    int fill;
    int cmOop;
    int formOop;
    int originOop;
    int tileFlag;
    int nrmOop;
    int object;
    int sp;
    int integerPointer;
    int oop;
    int oop1;
    int oop2;
    int oop3;
    int oop4;

	if (!(argumentCount == 7)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		xIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		xIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (xIndex <= 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		nrmOop = null;
		goto l2;
	}
	nrmOop = oop;
l2:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (2 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		dirOop = null;
		goto l3;
	}
	dirOop = oop1;
l3:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (3 * 4));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		originOop = null;
		goto l4;
	}
	originOop = oop2;
l4:	/* end stackObjectValue: */;
	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (4 * 4))) == trueObj) {
		tileFlag = 1;
		goto l5;
	}
	if ((longAt(stackPointer - (4 * 4))) == falseObj) {
		tileFlag = 0;
		goto l5;
	}
	successFlag = 0;
	tileFlag = null;
l5:	/* end booleanValueOf: */;
	if (tileFlag) {
		tileFlag = 1;
	} else {
		tileFlag = 0;
	}
	/* begin stackObjectValue: */
	oop3 = longAt(stackPointer - (5 * 4));
	if ((oop3 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		cmOop = null;
		goto l6;
	}
	cmOop = oop3;
l6:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop4 = longAt(stackPointer - (6 * 4));
	if ((oop4 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		formOop = null;
		goto l7;
	}
	formOop = oop4;
l7:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(7), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadPointfrom(((int *) (workBuffer + 80)), originOop);
	loadPointfrom(((int *) (workBuffer + 82)), dirOop);
	loadPointfrom(((int *) (workBuffer + 84)), nrmOop);
	if (!successFlag) {
		return 0;
	}
	fill = loadBitmapFillcolormaptilefromalongnormalxIndex(formOop, cmOop, tileFlag, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), xIndex - 1);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 8 * 4;
		/* begin push: */
		object = positive32BitIntegerFor(fill);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	}
}

EXPORT(int) gePrimitiveAddCompressedShape(void) {
    int nSegments;
    int points;
    int pointsShort;
    int lineWidths;
    int lineFills;
    int rightFills;
    int leftFills;
    int fillIndexList;
    int oop;
    int oop1;
    int oop2;
    int oop3;
    int oop4;
    int integerPointer;
    int oop5;

	if (!(argumentCount == 7)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		fillIndexList = null;
		goto l1;
	}
	fillIndexList = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		lineFills = null;
		goto l2;
	}
	lineFills = oop1;
l2:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (2 * 4));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		lineWidths = null;
		goto l3;
	}
	lineWidths = oop2;
l3:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop3 = longAt(stackPointer - (3 * 4));
	if ((oop3 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rightFills = null;
		goto l4;
	}
	rightFills = oop3;
l4:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop4 = longAt(stackPointer - (4 * 4));
	if ((oop4 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		leftFills = null;
		goto l5;
	}
	leftFills = oop4;
l5:	/* end stackObjectValue: */;
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (5 * 4));
	if ((integerPointer & 1)) {
		nSegments = (integerPointer >> 1);
		goto l6;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		nSegments = 0;
		goto l6;
	}
l6:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop5 = longAt(stackPointer - (6 * 4));
	if ((oop5 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		points = null;
		goto l7;
	}
	points = oop5;
l7:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(7), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(points, nSegments, leftFills, rightFills, lineWidths, lineFills, fillIndexList))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(needAvailableSpace((((16 < 16) ? 16 : 16)) * nSegments))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	pointsShort = (slotSizeOf(points)) == (nSegments * 3);
	loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(firstIndexableField(points), nSegments, firstIndexableField(leftFills), firstIndexableField(rightFills), firstIndexableField(lineWidths), firstIndexableField(lineFills), firstIndexableField(fillIndexList), pointsShort);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 7 * 4;
	}
}

EXPORT(int) gePrimitiveAddGradientFill(void) {
    int nrmOop;
    int fill;
    int originOop;
    int rampOop;
    int dirOop;
    int isRadial;
    int object;
    int sp;

	if (!(argumentCount == 5)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (0 * 4))) == trueObj) {
		isRadial = 1;
		goto l1;
	}
	if ((longAt(stackPointer - (0 * 4))) == falseObj) {
		isRadial = 0;
		goto l1;
	}
	successFlag = 0;
	isRadial = null;
l1:	/* end booleanValueOf: */;
	nrmOop = longAt(stackPointer - (1 * 4));
	dirOop = longAt(stackPointer - (2 * 4));
	originOop = longAt(stackPointer - (3 * 4));
	rampOop = longAt(stackPointer - (4 * 4));
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(5), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadPointfrom(((int *) (workBuffer + 80)), originOop);
	loadPointfrom(((int *) (workBuffer + 82)), dirOop);
	loadPointfrom(((int *) (workBuffer + 84)), nrmOop);
	if (!successFlag) {
		return 0;
	}
	fill = loadGradientFillfromalongnormalisRadial(rampOop, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), isRadial);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 6 * 4;
		/* begin push: */
		object = positive32BitIntegerFor(fill);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	}
}

EXPORT(int) gePrimitiveAddLine(void) {
    int leftFill;
    int rightFill;
    int startOop;
    int endOop;
    int oop;
    int oop1;

	if (!(argumentCount == 4)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	rightFill = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	leftFill = positive32BitValueOf(longAt(stackPointer - (1 * 4)));
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (2 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		endOop = null;
		goto l1;
	}
	endOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (3 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		startOop = null;
		goto l2;
	}
	startOop = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(4), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((isFillOkay(leftFill)) && (isFillOkay(rightFill)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadPointfrom(((int *) (workBuffer + 80)), startOop);
	loadPointfrom(((int *) (workBuffer + 82)), endOop);
	if (!successFlag) {
		return 0;
	}
	/* begin transformPoints: */
	if (2 > 0) {
		transformPoint(((int *) (workBuffer + 80)));
	}
	if (2 > 1) {
		transformPoint(((int *) (workBuffer + 82)));
	}
	if (2 > 2) {
		transformPoint(((int *) (workBuffer + 84)));
	}
	if (2 > 3) {
		transformPoint(((int *) (workBuffer + 86)));
	}
	leftFill = transformColor(leftFill);
	rightFill = transformColor(rightFill);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadWideLinefromtolineFillleftFillrightFill(0, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), 0, leftFill, rightFill);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 4 * 4;
	}
}

EXPORT(int) gePrimitiveAddOval(void) {
    int fillIndex;
    int borderWidth;
    int startOop;
    int borderIndex;
    int endOop;
    int integerPointer;
    int oop;
    int oop1;

	if (!(argumentCount == 5)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	borderIndex = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		borderWidth = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		borderWidth = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	fillIndex = positive32BitValueOf(longAt(stackPointer - (2 * 4)));
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (3 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		endOop = null;
		goto l2;
	}
	endOop = oop;
l2:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (4 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		startOop = null;
		goto l3;
	}
	startOop = oop1;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(5), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((isFillOkay(borderIndex)) && (isFillOkay(fillIndex)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	fillIndex = transformColor(fillIndex);
	borderIndex = transformColor(borderIndex);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((fillIndex == 0) && ((borderIndex == 0) || (borderWidth <= 0))) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		return null;
	}
	if (!(needAvailableSpace(16 * 16))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((borderWidth > 0) && (borderIndex != 0)) {
		borderWidth = transformWidth(borderWidth);
	} else {
		borderWidth = 0;
	}
	loadPointfrom(((int *) (workBuffer + 80)), startOop);
	loadPointfrom(((int *) (workBuffer + 82)), endOop);
	if (!successFlag) {
		return 0;
	}
	loadOvallineFillleftFillrightFill(borderWidth, borderIndex, 0, fillIndex);
	if (engineStopped) {
		/* begin wbStackClear */
		workBuffer[10] = (workBuffer[1]);
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 5 * 4;
	}
}

EXPORT(int) gePrimitiveAddPolygon(void) {
    int nPoints;
    int points;
    int isArray;
    int segSize;
    int fillIndex;
    int lineFill;
    int length;
    int lineWidth;
    int integerPointer;
    int integerPointer1;
    int oop;
    int header;
    int y0;
    int y1;
    int i;
    int x0;
    int x1;
    int sz;

	if (!(argumentCount == 5)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	lineFill = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		lineWidth = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		lineWidth = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	fillIndex = positive32BitValueOf(longAt(stackPointer - (2 * 4)));
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (3 * 4));
	if ((integerPointer1 & 1)) {
		nPoints = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		nPoints = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (4 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		points = null;
		goto l3;
	}
	points = oop;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(5), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin slotSizeOf: */
	if ((points & 1)) {
		length = 0;
		goto l4;
	}
	/* begin lengthOf: */
	header = longAt(points);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(points - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		length = ((unsigned) (sz - 4)) >> 2;
		goto l6;
	} else {
		length = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l6;
	}
l6:	/* end lengthOf:baseHeader:format: */;
l4:	/* end slotSizeOf: */;
	if (((((unsigned) (longAt(points))) >> 8) & 15) == 6) {
		isArray = 0;
		if (!((length == nPoints) || ((nPoints * 2) == length))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	} else {
		if (!((fetchClassOf(points)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2))))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		if (!(length == nPoints)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		isArray = 1;
	}
	if ((lineWidth == 0) || (lineFill == 0)) {
		segSize = 16;
	} else {
		segSize = 21;
	}
	if (!(needAvailableSpace(segSize * nPoints))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((isFillOkay(lineFill)) && (isFillOkay(fillIndex)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	lineFill = transformColor(lineFill);
	fillIndex = transformColor(fillIndex);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (((lineFill == 0) || (lineWidth == 0)) && (fillIndex == 0)) {
		/* begin pop: */
		stackPointer -= 6 * 4;
		return null;
	}
	if (!(lineWidth == 0)) {
		lineWidth = transformWidth(lineWidth);
	}
	if (isArray) {
		/* begin loadArrayPolygon:nPoints:fill:lineWidth:lineFill: */
		loadPointfrom(((int *) (workBuffer + 80)), longAt(((((char *) points)) + 4) + (0 << 2)));
		if (!successFlag) {
			goto l5;
		}
		x0 = (((int *) (workBuffer + 80)))[0];
		y0 = (((int *) (workBuffer + 80)))[1];
		for (i = 1; i <= (nPoints - 1); i += 1) {
			loadPointfrom(((int *) (workBuffer + 80)), longAt(((((char *) points)) + 4) + (i << 2)));
			if (!successFlag) {
				goto l5;
			}
			x1 = (((int *) (workBuffer + 80)))[0];
			y1 = (((int *) (workBuffer + 80)))[1];
			(((int *) (workBuffer + 80)))[0] = x0;
			(((int *) (workBuffer + 80)))[1] = y0;
			(((int *) (workBuffer + 82)))[0] = x1;
			(((int *) (workBuffer + 82)))[1] = y1;
			/* begin transformPoints: */
			if (2 > 0) {
				transformPoint(((int *) (workBuffer + 80)));
			}
			if (2 > 1) {
				transformPoint(((int *) (workBuffer + 82)));
			}
			if (2 > 2) {
				transformPoint(((int *) (workBuffer + 84)));
			}
			if (2 > 3) {
				transformPoint(((int *) (workBuffer + 86)));
			}
			loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), lineFill, fillIndex, 0);
			if (engineStopped) {
				goto l5;
			}
			x0 = x1;
			y0 = y1;
		}
	l5:	/* end loadArrayPolygon:nPoints:fill:lineWidth:lineFill: */;
	} else {
		loadPolygonnPointsfilllineWidthlineFillpointsShort(firstIndexableField(points), nPoints, fillIndex, lineWidth, lineFill, nPoints == length);
	}
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 5 * 4;
	}
}

EXPORT(int) gePrimitiveAddRect(void) {
    int fillIndex;
    int borderWidth;
    int startOop;
    int borderIndex;
    int endOop;
    int integerPointer;
    int oop;
    int oop1;

	if (!(argumentCount == 5)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	borderIndex = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		borderWidth = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		borderWidth = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	fillIndex = positive32BitValueOf(longAt(stackPointer - (2 * 4)));
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (3 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		endOop = null;
		goto l2;
	}
	endOop = oop;
l2:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (4 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		startOop = null;
		goto l3;
	}
	startOop = oop1;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(stackObjectValue(5), 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((isFillOkay(borderIndex)) && (isFillOkay(fillIndex)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	borderIndex = transformColor(borderIndex);
	fillIndex = transformColor(fillIndex);
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((fillIndex == 0) && ((borderIndex == 0) || (borderWidth == 0))) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		return null;
	}
	if (!(needAvailableSpace(4 * 16))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((borderWidth > 0) && (borderIndex != 0)) {
		borderWidth = transformWidth(borderWidth);
	} else {
		borderWidth = 0;
	}
	loadPointfrom(((int *) (workBuffer + 80)), startOop);
	loadPointfrom(((int *) (workBuffer + 84)), endOop);
	if (!successFlag) {
		return null;
	}
	(((int *) (workBuffer + 82)))[0] = ((((int *) (workBuffer + 84)))[0]);
	(((int *) (workBuffer + 82)))[1] = ((((int *) (workBuffer + 80)))[1]);
	(((int *) (workBuffer + 86)))[0] = ((((int *) (workBuffer + 80)))[0]);
	(((int *) (workBuffer + 86)))[1] = ((((int *) (workBuffer + 84)))[1]);
	/* begin transformPoints: */
	if (4 > 0) {
		transformPoint(((int *) (workBuffer + 80)));
	}
	if (4 > 1) {
		transformPoint(((int *) (workBuffer + 82)));
	}
	if (4 > 2) {
		transformPoint(((int *) (workBuffer + 84)));
	}
	if (4 > 3) {
		transformPoint(((int *) (workBuffer + 86)));
	}
	/* begin loadRectangle:lineFill:leftFill:rightFill: */
	loadWideLinefromtolineFillleftFillrightFill(borderWidth, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), borderIndex, 0, fillIndex);
	loadWideLinefromtolineFillleftFillrightFill(borderWidth, ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), borderIndex, 0, fillIndex);
	loadWideLinefromtolineFillleftFillrightFill(borderWidth, ((int *) (workBuffer + 84)), ((int *) (workBuffer + 86)), borderIndex, 0, fillIndex);
	loadWideLinefromtolineFillleftFillrightFill(borderWidth, ((int *) (workBuffer + 86)), ((int *) (workBuffer + 80)), borderIndex, 0, fillIndex);
	if (!(!successFlag)) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 5 * 4;
	}
}

EXPORT(int) gePrimitiveChangedActiveEdgeEntry(void) {
    int edgeOop;
    int edge;
    int value;
    int oop;
    int oop1;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		edgeOop = null;
		goto l1;
	}
	edgeOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 7))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	edge = loadEdgeStateFrom(edgeOop);
	if (!successFlag) {
		return null;
	}
	if ((objBuffer[edge + 7]) == 0) {
		removeFirstAETEntry();
	} else {
		resortFirstAETEntry();
		workBuffer[13] = ((workBuffer[13]) + 1);
	}
	workBuffer[2] = 6;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 1 * 4;
	if (doProfileStats) {
		workBuffer[107] = ((workBuffer[107]) + 1);
		/* begin incrementStat:by: */
		value = (ioMicroMSecs()) - geProfileTime;
		workBuffer[106] = ((workBuffer[106]) + value);
	}
}

EXPORT(int) gePrimitiveCopyBuffer(void) {
    int i;
    int diff;
    int * src;
    int buf1;
    int buf2;
    int * dst;
    int oop;
    int oop1;

	if (!(argumentCount == 2)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		buf2 = null;
		goto l1;
	}
	buf2 = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		buf1 = null;
		goto l2;
	}
	buf1 = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(loadWorkBufferFrom(buf1))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((fetchClassOf(buf1)) == (fetchClassOf(buf2)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	diff = (slotSizeOf(buf2)) - (slotSizeOf(buf1));
	if (diff < 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	src = workBuffer;
	dst = firstIndexableField(buf2);
	for (i = 0; i <= ((workBuffer[10]) - 1); i += 1) {
		dst[i] = (src[i]);
	}
	dst[10] = ((workBuffer[10]) + diff);
	dst[1] = ((workBuffer[1]) + diff);
	src += workBuffer[10];
	dst = (dst + (workBuffer[10])) + diff;
	for (i = 0; i <= (((workBuffer[1]) - (workBuffer[10])) - 1); i += 1) {
		dst[i] = (src[i]);
	}
	if (!(loadWorkBufferFrom(buf2))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop: */
	stackPointer -= 2 * 4;
}

EXPORT(int) gePrimitiveDisplaySpanBuffer(void) {
    int value;
    int oop;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 5))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(loadSpanBufferFrom(longAt(((((char *) engine)) + 4) + (1 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(loadBitBltFrom(longAt(((((char *) engine)) + 4) + (2 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (((workBuffer[88]) & (workBuffer[52])) == (workBuffer[52])) {
		displaySpanBufferAt(workBuffer[88]);
		postDisplayAction();
	}
	if (!((workBuffer[2]) == 8)) {
		workBuffer[13] = 0;
		workBuffer[88] = ((workBuffer[88]) + 1);
		workBuffer[2] = 6;
	}
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	if (doProfileStats) {
		workBuffer[103] = ((workBuffer[103]) + 1);
		/* begin incrementStat:by: */
		value = (ioMicroMSecs()) - geProfileTime;
		workBuffer[102] = ((workBuffer[102]) + value);
	}
}

EXPORT(int) gePrimitiveDoProfileStats(void) {
    int newValue;
    int oldValue;
    int sp;
    int sp1;
    int oop;

	oldValue = doProfileStats;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		newValue = null;
		goto l1;
	}
	newValue = oop;
l1:	/* end stackObjectValue: */;
	/* begin booleanValueOf: */
	if (newValue == trueObj) {
		newValue = 1;
		goto l2;
	}
	if (newValue == falseObj) {
		newValue = 0;
		goto l2;
	}
	successFlag = 0;
	newValue = null;
l2:	/* end booleanValueOf: */;
	if (!(!successFlag)) {
		doProfileStats = newValue;
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (oldValue) {
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

EXPORT(int) gePrimitiveFinishedProcessing(void) {
    int finished;
    int value;
    int oop;
    int sp;
    int sp1;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	finished = (workBuffer[2]) == 8;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushBool: */
	if (finished) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	}
	if (doProfileStats) {
		workBuffer[93] = ((workBuffer[93]) + 1);
		/* begin incrementStat:by: */
		value = (ioMicroMSecs()) - geProfileTime;
		workBuffer[92] = ((workBuffer[92]) + value);
	}
}

EXPORT(int) gePrimitiveGetAALevel(void) {
    int oop;
    int sp;

	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, (((workBuffer[48]) << 1) | 1));
	stackPointer = sp;
}

EXPORT(int) gePrimitiveGetBezierStats(void) {
    int statOop;
    int *stats;
    int oop;
    int oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		statOop = null;
		goto l1;
	}
	statOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((unsigned) (longAt(statOop))) >> 8) & 15) == 6)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((slotSizeOf(statOop)) < 4) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	stats = firstIndexableField(statOop);
	stats[0] = ((stats[0]) + (workBuffer[108]));
	stats[1] = ((stats[1]) + (workBuffer[109]));
	stats[2] = ((stats[2]) + (workBuffer[110]));
	stats[3] = ((stats[3]) + (workBuffer[111]));
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) gePrimitiveGetClipRect(void) {
    int rectOop;
    int pointOop;
    int oop;
    int oop1;
    int oop2;
    int oop3;
    int sp;
    int xValue;
    int yValue;
    int pointResult;
    int xValue1;
    int yValue1;
    int pointResult1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rectOop = null;
		goto l1;
	}
	rectOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((unsigned) (longAt(rectOop))) >> 8) & 15) <= 4)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((slotSizeOf(rectOop)) < 2) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = rectOop;
	/* begin makePointwithxValue:yValue: */
	xValue = workBuffer[42];
	yValue = workBuffer[44];
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
	pointOop = pointResult;
	/* begin popRemappableOop */
	oop2 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	rectOop = oop2;
	/* begin storePointer:ofObject:withValue: */
	if (rectOop < youngStart) {
		possibleRootStoreIntovalue(rectOop, pointOop);
	}
	longAtput(((((char *) rectOop)) + 4) + (0 << 2), pointOop);
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = rectOop;
	/* begin makePointwithxValue:yValue: */
	xValue1 = workBuffer[43];
	yValue1 = workBuffer[45];
	pointResult1 = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
	/* begin storePointer:ofObject:withValue: */
	if (pointResult1 < youngStart) {
		possibleRootStoreIntovalue(pointResult1, ((xValue1 << 1) | 1));
	}
	longAtput(((((char *) pointResult1)) + 4) + (0 << 2), ((xValue1 << 1) | 1));
	/* begin storePointer:ofObject:withValue: */
	if (pointResult1 < youngStart) {
		possibleRootStoreIntovalue(pointResult1, ((yValue1 << 1) | 1));
	}
	longAtput(((((char *) pointResult1)) + 4) + (1 << 2), ((yValue1 << 1) | 1));
	pointOop = pointResult1;
	/* begin popRemappableOop */
	oop3 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	rectOop = oop3;
	/* begin storePointer:ofObject:withValue: */
	if (rectOop < youngStart) {
		possibleRootStoreIntovalue(rectOop, pointOop);
	}
	longAtput(((((char *) rectOop)) + 4) + (1 << 2), pointOop);
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, rectOop);
	stackPointer = sp;
}

EXPORT(int) gePrimitiveGetCounts(void) {
    int statOop;
    int *stats;
    int oop;
    int oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		statOop = null;
		goto l1;
	}
	statOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((unsigned) (longAt(statOop))) >> 8) & 15) == 6)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((slotSizeOf(statOop)) < 9) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	stats = firstIndexableField(statOop);
	stats[0] = ((stats[0]) + (workBuffer[91]));
	stats[1] = ((stats[1]) + (workBuffer[93]));
	stats[2] = ((stats[2]) + (workBuffer[95]));
	stats[3] = ((stats[3]) + (workBuffer[97]));
	stats[4] = ((stats[4]) + (workBuffer[99]));
	stats[5] = ((stats[5]) + (workBuffer[101]));
	stats[6] = ((stats[6]) + (workBuffer[103]));
	stats[7] = ((stats[7]) + (workBuffer[105]));
	stats[8] = ((stats[8]) + (workBuffer[107]));
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) gePrimitiveGetDepth(void) {
    int oop;
    int sp;

	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, (((workBuffer[113]) << 1) | 1));
	stackPointer = sp;
}

EXPORT(int) gePrimitiveGetFailureReason(void) {
    int oop;
    int sp;

	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if ((engine & 1)) {
		return 0;
	}
	if (!(((((unsigned) (longAt(engine))) >> 8) & 15) <= 4)) {
		return 0;
	}
	if ((slotSizeOf(engine)) < 12) {
		return 0;
	}
	if (!(loadWorkBufferFrom(longAt(((((char *) engine)) + 4) + (0 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, (((workBuffer[64]) << 1) | 1));
	stackPointer = sp;
}

EXPORT(int) gePrimitiveGetOffset(void) {
    int pointOop;
    int oop;
    int sp;
    int xValue;
    int yValue;
    int pointResult;

	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin makePointwithxValue:yValue: */
	xValue = workBuffer[46];
	yValue = workBuffer[47];
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
	pointOop = pointResult;
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, pointOop);
	stackPointer = sp;
}

EXPORT(int) gePrimitiveGetTimes(void) {
    int statOop;
    int *stats;
    int oop;
    int oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		statOop = null;
		goto l1;
	}
	statOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((unsigned) (longAt(statOop))) >> 8) & 15) == 6)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((slotSizeOf(statOop)) < 9) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	stats = firstIndexableField(statOop);
	stats[0] = ((stats[0]) + (workBuffer[90]));
	stats[1] = ((stats[1]) + (workBuffer[92]));
	stats[2] = ((stats[2]) + (workBuffer[94]));
	stats[3] = ((stats[3]) + (workBuffer[96]));
	stats[4] = ((stats[4]) + (workBuffer[98]));
	stats[5] = ((stats[5]) + (workBuffer[100]));
	stats[6] = ((stats[6]) + (workBuffer[102]));
	stats[7] = ((stats[7]) + (workBuffer[104]));
	stats[8] = ((stats[8]) + (workBuffer[106]));
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) gePrimitiveInitializeBuffer(void) {
    int size;
    int wbOop;
    int oop;
    int sp;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		wbOop = null;
		goto l1;
	}
	wbOop = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(((((unsigned) (longAt(wbOop))) >> 8) & 15) == 6)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((size = slotSizeOf(wbOop)) < 256) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	workBuffer = firstIndexableField(wbOop);
	objBuffer = workBuffer + 128;
	workBuffer[0] = 1097753705;
	workBuffer[1] = size;
	workBuffer[10] = size;
	workBuffer[2] = 0;
	workBuffer[8] = 128;
	workBuffer[9] = 4;
	objBuffer[0 + 0] = 256;
	objBuffer[0 + 1] = 4;
	objBuffer[0 + 2] = 0;
	workBuffer[11] = 0;
	workBuffer[12] = 0;
	workBuffer[13] = 0;
	workBuffer[14] = 0;
	workBuffer[64] = 0;
	workBuffer[63] = 0;
	workBuffer[42] = 0;
	workBuffer[43] = 0;
	workBuffer[44] = 0;
	workBuffer[45] = 0;
	workBuffer[113] = 0;
	resetGraphicsEngineStats();
	initEdgeTransform();
	initColorTransform();
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, wbOop);
	stackPointer = sp;
}

EXPORT(int) gePrimitiveInitializeProcessing(void) {
    int value;
    int oop;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(loadSpanBufferFrom(longAt(((((char *) engine)) + 4) + (1 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	initializeGETProcessing();
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	workBuffer[2] = 1;
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
	}
	if (doProfileStats) {
		workBuffer[91] = ((workBuffer[91]) + 1);
		/* begin incrementStat:by: */
		value = (ioMicroMSecs()) - geProfileTime;
		workBuffer[90] = ((workBuffer[90]) + value);
	}
}

EXPORT(int) gePrimitiveMergeFillFrom(void) {
    int bitsOop;
    int fillOop;
    int value;
    int value1;
    int oop;
    int oop1;
    int oop2;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 2)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		fillOop = null;
		goto l1;
	}
	fillOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		bitsOop = null;
		goto l2;
	}
	bitsOop = oop1;
l2:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (2 * 4));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l3;
	}
	engine = oop2;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 4))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(loadSpanBufferFrom(longAt(((((char *) engine)) + 4) + (1 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((fetchClassOf(bitsOop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((slotSizeOf(fillOop)) < 6) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = fetchIntegerofObject(0, fillOop);
	if (!((objBuffer[(workBuffer[66]) + 2]) == value)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = fetchIntegerofObject(1, fillOop);
	if (!((workBuffer[67]) == value)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = fetchIntegerofObject(2, fillOop);
	if (!((workBuffer[68]) == value)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((slotSizeOf(bitsOop)) < ((workBuffer[68]) - (workBuffer[67]))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!successFlag) {
		return null;
	}
	fillBitmapSpanfromto(firstIndexableField(bitsOop), workBuffer[67], workBuffer[68]);
	workBuffer[2] = 3;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 2 * 4;
	if (doProfileStats) {
		workBuffer[101] = ((workBuffer[101]) + 1);
		/* begin incrementStat:by: */
		value1 = (ioMicroMSecs()) - geProfileTime;
		workBuffer[100] = ((workBuffer[100]) + value1);
	}
}

EXPORT(int) gePrimitiveNeedsFlush(void) {
    int needFlush;
    int oop;
    int sp;
    int sp1;

	if (!(argumentCount == 0)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l1;
	}
	engine = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	needFlush = (workBuffer[63]) != 0;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushBool: */
	if (needFlush) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	}
}

EXPORT(int) gePrimitiveNeedsFlushPut(void) {
    int needFlush;
    int oop;
    int oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		needFlush = null;
		goto l1;
	}
	needFlush = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	/* begin booleanValueOf: */
	if (needFlush == trueObj) {
		needFlush = 1;
		goto l3;
	}
	if (needFlush == falseObj) {
		needFlush = 0;
		goto l3;
	}
	successFlag = 0;
	needFlush = null;
l3:	/* end booleanValueOf: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (needFlush == 1) {
		workBuffer[63] = 1;
	} else {
		workBuffer[63] = 0;
	}
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) gePrimitiveNextActiveEdgeEntry(void) {
    int edgeOop;
    int edge;
    int hasEdge;
    int value;
    int oop;
    int oop1;
    int sp;
    int sp1;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		edgeOop = null;
		goto l1;
	}
	edgeOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredStateor(engine, 6, 8))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	hasEdge = 0;
	if (!((workBuffer[2]) == 8)) {
		hasEdge = findNextExternalUpdateFromAET();
		if (hasEdge) {
			edge = aetBuffer[workBuffer[13]];
			storeEdgeStateFrominto(edge, edgeOop);
			workBuffer[2] = 7;
		} else {
			workBuffer[2] = 1;
		}
	}
	if (!successFlag) {
		return null;
	}
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin pushBool: */
	if (!hasEdge) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	}
	if (doProfileStats) {
		workBuffer[105] = ((workBuffer[105]) + 1);
		/* begin incrementStat:by: */
		value = (ioMicroMSecs()) - geProfileTime;
		workBuffer[104] = ((workBuffer[104]) + value);
	}
}

EXPORT(int) gePrimitiveNextFillEntry(void) {
    int fillOop;
    int hasFill;
    int value;
    int sp;
    int sp1;
    int oop;
    int oop1;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		fillOop = null;
		goto l1;
	}
	fillOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 3))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(loadSpanBufferFrom(longAt(((((char *) engine)) + 4) + (1 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(loadFormsFrom(longAt(((((char *) engine)) + 4) + (3 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((workBuffer[69]) == 0)) {
		if (((workBuffer[88]) & (workBuffer[52])) == 0) {
			clearSpanBuffer();
		}
		workBuffer[69] = 0;
	}
	hasFill = findNextExternalFillFromAET();
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (hasFill) {
		storeFillStateInto(fillOop);
	}
	if (!(!successFlag)) {
		if (hasFill) {
			workBuffer[2] = 4;
		} else {
			/* begin wbStackClear */
			workBuffer[10] = (workBuffer[1]);
			workBuffer[35] = 0;
			workBuffer[2] = 5;
		}
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (!hasFill) {
			/* begin push: */
			longAtput(sp = stackPointer + 4, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + 4, falseObj);
			stackPointer = sp1;
		}
		if (doProfileStats) {
			workBuffer[99] = ((workBuffer[99]) + 1);
			/* begin incrementStat:by: */
			value = (ioMicroMSecs()) - geProfileTime;
			workBuffer[98] = ((workBuffer[98]) + value);
		}
	}
}

EXPORT(int) gePrimitiveNextGlobalEdgeEntry(void) {
    int edgeOop;
    int edge;
    int hasEdge;
    int value;
    int oop;
    int oop1;
    int sp;
    int sp1;

	if (doProfileStats) {
		geProfileTime = ioMicroMSecs();
	}
	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		edgeOop = null;
		goto l1;
	}
	edgeOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 1))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	hasEdge = findNextExternalEntryFromGET();
	if (hasEdge) {
		edge = getBuffer[workBuffer[11]];
		storeEdgeStateFrominto(edge, edgeOop);
		workBuffer[11] = ((workBuffer[11]) + 1);
	}
	if (!successFlag) {
		return null;
	}
	if (hasEdge) {
		workBuffer[2] = 2;
	} else {
		workBuffer[2] = 3;
		workBuffer[69] = 1;
		workBuffer[13] = 0;
		/* begin wbStackClear */
		workBuffer[10] = (workBuffer[1]);
	}
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin pushBool: */
	if (!hasEdge) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	}
	if (doProfileStats) {
		workBuffer[95] = ((workBuffer[95]) + 1);
		/* begin incrementStat:by: */
		value = (ioMicroMSecs()) - geProfileTime;
		workBuffer[94] = ((workBuffer[94]) + value);
	}
}

EXPORT(int) gePrimitiveRegisterExternalEdge(void) {
    int index;
    int leftFillIndex;
    int rightFillIndex;
    int initialZ;
    int initialY;
    int initialX;
    int edge;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int integerPointer3;
    int oop;
    int value;
    int value1;

	if (!(argumentCount == 6)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	rightFillIndex = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	leftFillIndex = positive32BitValueOf(longAt(stackPointer - (1 * 4)));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (2 * 4));
	if ((integerPointer & 1)) {
		initialZ = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		initialZ = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (3 * 4));
	if ((integerPointer1 & 1)) {
		initialY = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		initialY = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (4 * 4));
	if ((integerPointer2 & 1)) {
		initialX = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		initialX = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(stackPointer - (5 * 4));
	if ((integerPointer3 & 1)) {
		index = (integerPointer3 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l4;
	}
l4:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (6 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l5;
	}
	engine = oop;
l5:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(allocateObjEntry(10))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(isFillOkay(leftFillIndex))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(isFillOkay(rightFillIndex))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	edge = objUsed;
	objUsed = edge + 10;
	objBuffer[edge + 0] = 2;
	objBuffer[edge + 1] = 10;
	objBuffer[edge + 2] = index;
	objBuffer[edge + 4] = initialX;
	objBuffer[edge + 5] = initialY;
	objBuffer[edge + 6] = initialZ;
	/* begin edgeLeftFillOf:put: */
	value = transformColor(leftFillIndex);
	objBuffer[edge + 8] = value;
	/* begin edgeRightFillOf:put: */
	value1 = transformColor(rightFillIndex);
	objBuffer[edge + 9] = value1;
	if (engineStopped) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 6 * 4;
	}
}

EXPORT(int) gePrimitiveRegisterExternalFill(void) {
    int index;
    int fill;
    int sp;
    int integerPointer;
    int oop;

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
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	fill = 0;
	while (fill == 0) {
		if (!(allocateObjEntry(10))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		fill = objUsed;
		objUsed = fill + 4;
		objBuffer[fill + 0] = 256;
		objBuffer[fill + 1] = 4;
		objBuffer[fill + 2] = index;
	}
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((fill << 1) | 1));
		stackPointer = sp;
	}
}

EXPORT(int) gePrimitiveRenderImage(void) {
	if (!(loadRenderingState())) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	proceedRenderingScanline();
	if (engineStopped) {
		return storeRenderingState();
	}
	proceedRenderingImage();
	storeRenderingState();
}

EXPORT(int) gePrimitiveRenderScanline(void) {
	if (!(loadRenderingState())) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	proceedRenderingScanline();
	storeRenderingState();
}

EXPORT(int) gePrimitiveSetAALevel(void) {
    int level;
    int integerPointer;
    int oop;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		level = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		level = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	setAALevel(level);
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) gePrimitiveSetClipRect(void) {
    int rectOop;
    int oop;
    int oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rectOop = null;
		goto l1;
	}
	rectOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((unsigned) (longAt(rectOop))) >> 8) & 15) <= 4)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((slotSizeOf(rectOop)) < 2) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadPointfrom(((int *) (workBuffer + 80)), longAt(((((char *) rectOop)) + 4) + (0 << 2)));
	loadPointfrom(((int *) (workBuffer + 82)), longAt(((((char *) rectOop)) + 4) + (1 << 2)));
	if (!(!successFlag)) {
		workBuffer[42] = ((((int *) (workBuffer + 80)))[0]);
		workBuffer[44] = ((((int *) (workBuffer + 80)))[1]);
		workBuffer[43] = ((((int *) (workBuffer + 82)))[0]);
		workBuffer[45] = ((((int *) (workBuffer + 82)))[1]);
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

EXPORT(int) gePrimitiveSetColorTransform(void) {
    int transformOop;
    int oop;
    int oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		transformOop = null;
		goto l1;
	}
	transformOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadColorTransformFrom(transformOop);
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

EXPORT(int) gePrimitiveSetDepth(void) {
    int depth;
    int integerPointer;
    int oop;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		depth = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		depth = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	workBuffer[113] = depth;
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

EXPORT(int) gePrimitiveSetEdgeTransform(void) {
    int transformOop;
    int oop;
    int oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		transformOop = null;
		goto l1;
	}
	transformOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadEdgeTransformFrom(transformOop);
	if (!(!successFlag)) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

EXPORT(int) gePrimitiveSetOffset(void) {
    int pointOop;
    int oop;
    int oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		pointOop = null;
		goto l1;
	}
	pointOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l2;
	}
	engine = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((fetchClassOf(pointOop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadPointfrom(((int *) (workBuffer + 80)), pointOop);
	if (!(!successFlag)) {
		workBuffer[46] = ((((int *) (workBuffer + 80)))[0]);
		workBuffer[47] = ((((int *) (workBuffer + 80)))[1]);
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int getCurrentBytecode(void) {
	return byteAt(instructionPointer);
}

int getLongFromFileswap(sqImageFile f, int swapFlag) {
    int w;

	sqImageFileRead(&w, sizeof(char), 4, f);
	if (swapFlag) {
		return ((((((unsigned) w >> 24)) & 255) + ((((unsigned) w >> 8)) & 65280)) + ((((unsigned) w << 8)) & 16711680)) + ((((unsigned) w << 24)) & 4278190080U);
	} else {
		return w;
	}
}

int getSortsbefore(int edge1, int edge2) {
    int diff;

	if (edge1 == edge2) {
		return 1;
	}
	diff = (objBuffer[edge1 + 5]) - (objBuffer[edge2 + 5]);
	if (!(diff == 0)) {
		return diff < 0;
	}
	diff = (objBuffer[edge1 + 4]) - (objBuffer[edge2 + 4]);
	return diff < 0;
}

int hideFilldepth(int fillIndex, int depth) {
    int index;
    int newDepth;
    int newRightX;
    int newTopIndex;
    int newTop;

	index = findStackFilldepth(fillIndex, depth);
	if (index == -1) {
		return 0;
	}
	if (index == 0) {
		/* begin freeStackFillEntry */
		/* begin wbStackPop: */
		workBuffer[10] = ((workBuffer[10]) + 3);
		return 1;
	}
	workBuffer[(workBuffer[10]) + index] = (workBuffer[(workBuffer[10]) + 0]);
	workBuffer[(workBuffer[10]) + (index + 1)] = (workBuffer[(workBuffer[10]) + (0 + 1)]);
	workBuffer[(workBuffer[10]) + (index + 2)] = (workBuffer[(workBuffer[10]) + (0 + 2)]);
	/* begin freeStackFillEntry */
	/* begin wbStackPop: */
	workBuffer[10] = ((workBuffer[10]) + 3);
	if (((workBuffer[1]) - (workBuffer[10])) <= 3) {
		return 1;
	}
	newTopIndex = 0;
	index = 3;
	while (index < ((workBuffer[1]) - (workBuffer[10]))) {
		if (fillSortsbefore(index, newTopIndex)) {
			newTopIndex = index;
		}
		index += 3;
	}
	if ((newTopIndex + 3) == ((workBuffer[1]) - (workBuffer[10]))) {
		return 1;
	}
	newTop = workBuffer[(workBuffer[10]) + newTopIndex];
	workBuffer[(workBuffer[10]) + newTopIndex] = (workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)]);
	workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)] = newTop;
	newDepth = workBuffer[(workBuffer[10]) + (newTopIndex + 1)];
	workBuffer[(workBuffer[10]) + (newTopIndex + 1)] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)]);
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)] = newDepth;
	newRightX = workBuffer[(workBuffer[10]) + (newTopIndex + 2)];
	workBuffer[(workBuffer[10]) + (newTopIndex + 2)] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)]);
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)] = newRightX;
	return 1;
}

int incCompBody(void) {
    int bytesFreed;
    int fwdBlock;
    int oop;
    int bytesFreed1;
    int newOop;
    int extra;
    int originalHeader;
    int originalHeaderType;
    int chunk;
    int extra1;
    int type;
    int extra2;
    int type1;
    int extra3;
    int newFreeChunk;
    int next;
    int bytesToMove;
    int w;
    int sz;
    int fwdBlock1;
    int oop1;
    int header;
    int firstWord;
    int lastWord;
    int newOop1;
    int chunk2;
    int extra4;
    int chunk1;
    int extra11;
    int header1;
    int type2;
    int extra21;
    int type11;
    int extra31;
    int sz2;
    int fwdBlock2;
    int realHeader;
    int header2;
    int extra5;
    int type3;
    int extra12;
    int sz1;
    int extra22;
    int header11;
    int type12;
    int extra111;
    int sz3;
    int fwdBlock3;
    int realHeader1;
    int header3;
    int extra6;
    int type4;
    int extra13;
    int sz11;
    int extra23;
    int header12;
    int type13;
    int extra112;

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

int incrementalGC(void) {
    int startTime;
    int survivorCount;
    int oop;
    int i;
    int fieldAddr;
    int oop1;
    int fieldOop;
    int header;
    int badRoot;
    int chunk;
    int extra;
    int type;
    int extra1;
    int sz;
    int extra2;
    int header1;
    int type1;
    int extra11;

	if (rootTableCount >= 2500) {
		statRootTableOverflows += 1;
		return fullGC();
	}
	;
	;
	/* begin preGCAction: */
	/* begin compilerPreGCHook: */
	if (compilerInitialized) {
		compilerPreGC(0);
	}
	if (!(activeContext == nilObj)) {
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
	/* begin compilerPostGCHook */
	if (compilerInitialized) {
		compilerPostGC();
	}
	if (activeContext < youngStart) {
		beRootIfOld(activeContext);
	}
	if (theHomeContext < youngStart) {
		beRootIfOld(theHomeContext);
	}
	;
}

int indexForInsertingIntoAET(int edge) {
    int index;
    int initialX;

	initialX = objBuffer[edge + 4];
	index = 0;
	while ((index < (workBuffer[14])) && ((objBuffer[(aetBuffer[index]) + 4]) < initialX)) {
		index += 1;
	}
	while ((index < (workBuffer[14])) && (((objBuffer[(aetBuffer[index]) + 4]) == initialX) && (getSortsbefore(aetBuffer[index], edge)))) {
		index += 1;
	}
	return index;
}

int initBBOpTable(void) {
	opTable[0+1] = (int)clearWordwith;
	opTable[1+1] = (int)bitAndwith;
	opTable[2+1] = (int)bitAndInvertwith;
	opTable[3+1] = (int)sourceWordwith;
	opTable[4+1] = (int)bitInvertAndwith;
	opTable[5+1] = (int)destinationWordwith;
	opTable[6+1] = (int)bitXorwith;
	opTable[7+1] = (int)bitOrwith;
	opTable[8+1] = (int)bitInvertAndInvertwith;
	opTable[9+1] = (int)bitInvertXorwith;
	opTable[10+1] = (int)bitInvertDestinationwith;
	opTable[11+1] = (int)bitOrInvertwith;
	opTable[12+1] = (int)bitInvertSourcewith;
	opTable[13+1] = (int)bitInvertOrwith;
	opTable[14+1] = (int)bitInvertOrInvertwith;
	opTable[15+1] = (int)destinationWordwith;
	opTable[16+1] = (int)destinationWordwith;
	opTable[17+1] = (int)destinationWordwith;
	opTable[18+1] = (int)addWordwith;
	opTable[19+1] = (int)subWordwith;
	opTable[20+1] = (int)rgbAddwith;
	opTable[21+1] = (int)rgbSubwith;
	opTable[22+1] = (int)OLDrgbDiffwith;
	opTable[23+1] = (int)OLDtallyIntoMapwith;
	opTable[24+1] = (int)alphaBlendwith;
	opTable[25+1] = (int)pixPaintwith;
	opTable[26+1] = (int)pixMaskwith;
	opTable[27+1] = (int)rgbMaxwith;
	opTable[28+1] = (int)rgbMinwith;
	opTable[29+1] = (int)rgbMinInvertwith;
	opTable[30+1] = (int)alphaBlendConstwith;
	opTable[31+1] = (int)alphaPaintConstwith;
	opTable[32+1] = (int)rgbDiffwith;
	opTable[33+1] = (int)tallyIntoMapwith;
	opTable[34+1] = (int)alphaBlendScaledwith;
}

int initColorTransform(void) {
    float *transform;

	transform = ((float *) (workBuffer + 24));
	transform[0] = (((float) 1.0));
	transform[1] = (((float) 0.0));
	transform[2] = (((float) 1.0));
	transform[3] = (((float) 0.0));
	transform[4] = (((float) 1.0));
	transform[5] = (((float) 0.0));
	transform[6] = (((float) 1.0));
	transform[7] = (((float) 0.0));
	workBuffer[17] = 0;
}

int initCompilerHooks(void) {
	compilerHooks[1]= nullCompilerHook;
	compilerHooks[2]= nullCompilerHook;
	compilerHooks[3]= nullCompilerHook;
	compilerHooks[4]= nullCompilerHook;
	compilerHooks[5]= nullCompilerHook;
	compilerHooks[6]= nullCompilerHook;
	compilerHooks[7]= nullCompilerHook;
	compilerHooks[8]= nullCompilerHook;
	compilerInitialized = 0;
}

int initEdgeTransform(void) {
    float *transform;

	transform = ((float *) (workBuffer + 18));
	transform[0] = (((float) 1.0));
	transform[1] = (((float) 0.0));
	transform[2] = (((float) 0.0));
	transform[3] = (((float) 0.0));
	transform[4] = (((float) 1.0));
	transform[5] = (((float) 0.0));
	workBuffer[16] = 0;
}

int initializeGETProcessing(void) {
	setAALevel(workBuffer[48]);
	if ((workBuffer[42]) < 0) {
		workBuffer[42] = 0;
	}
	if ((workBuffer[43]) > (workBuffer[33])) {
		workBuffer[43] = (workBuffer[33]);
	}
	workBuffer[36] = ((workBuffer[42]) << (workBuffer[49]));
	workBuffer[38] = ((workBuffer[44]) << (workBuffer[49]));
	workBuffer[37] = ((workBuffer[43]) << (workBuffer[49]));
	workBuffer[39] = ((workBuffer[45]) << (workBuffer[49]));
	workBuffer[12] = 0;
	workBuffer[14] = 0;
	getBuffer = aetBuffer = objBuffer + objUsed;
	createGlobalEdgeTable();
	if (engineStopped) {
		return null;
	}
	if ((workBuffer[12]) == 0) {
		workBuffer[88] = (workBuffer[39]);
		return 0;
	}
	/* begin sortGlobalEdgeTable */
	quickSortGlobalEdgeTablefromto(getBuffer, 0, (workBuffer[12]) - 1);
	workBuffer[88] = (objBuffer[(getBuffer[0]) + 5]);
	if ((workBuffer[88]) < (workBuffer[38])) {
		workBuffer[88] = (workBuffer[38]);
	}
	workBuffer[32] = 0;
	workBuffer[34] = (((workBuffer[33]) << (workBuffer[49])) - 1);
	clearSpanBuffer();
}

int initializeMemoryFirstFree(int firstFree) {
    int fwdBlockBytes;

	fwdBlockBytes = 16000;
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

int initializeObjectMemory(int bytesToShift) {
    int oop;
    int header;
    int newClassOop;
    int fieldAddr;
    int fieldOop;
    int classHeader;
    int chunk;
    int extra;
    int type;
    int extra1;
    int sz;
    int extra2;
    int header1;
    int type1;
    int extra11;

	youngStart = endOfMemory;
	initializeMemoryFirstFree(endOfMemory);
	/* begin adjustAllOopsBy: */
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
	specialObjectsOop += bytesToShift;
	nilObj = longAt(((((char *) specialObjectsOop)) + 4) + (0 << 2));
	falseObj = longAt(((((char *) specialObjectsOop)) + 4) + (1 << 2));
	trueObj = longAt(((((char *) specialObjectsOop)) + 4) + (2 << 2));
	rootTableCount = 0;
	child = 0;
	field = 0;
	parentField = 0;
	freeContexts = 1;
	allocationCount = 0;
	lowSpaceThreshold = 0;
	signalLowSpace = 0;
	compStart = 0;
	compEnd = 0;
	fwdTableNext = 0;
	fwdTableLast = 0;
	remapBufferCount = 0;
	allocationsBetweenGCs = 4000;
	tenuringThreshold = 2000;
	statFullGCs = 0;
	statFullGCMSecs = 0;
	statIncrGCs = 0;
	statIncrGCMSecs = 0;
	statTenures = 0;
	statRootTableOverflows = 0;
	displayBits = 0;
}

int insertEdgeIntoAET(int edge) {
    int index;

	if ((objBuffer[edge + 7]) <= 0) {
		return null;
	}
	index = indexForInsertingIntoAET(edge);
	insertToAETbeforeIndex(edge, index);
}

int insertToAETbeforeIndex(int edge, int index) {
    int i;

	if (!(needAvailableSpace(1))) {
		return null;
	}
	i = (workBuffer[14]) - 1;
	while (!(i < index)) {
		aetBuffer[i + 1] = (aetBuffer[i]);
		i -= 1;
	}
	aetBuffer[index] = edge;
	workBuffer[14] = ((workBuffer[14]) + 1);
}

int installinAtCacheatstring(int rcvr, int *cache, int atIx, int stringy) {
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int classFormat;
    int class;
    int sz;
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
		goto l2;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l1;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l1;
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
l1:	/* end fixedFieldsOf:format:length: */;
	cache[atIx + 1] = rcvr;
	if (stringy) {
		cache[atIx + 3] = (fmt + 16);
	} else {
		cache[atIx + 3] = fmt;
	}
	cache[atIx + 4] = fixedFields;
	cache[atIx + 2] = (totalLength - fixedFields);
}

int instantiateClassindexableSize(int classPointer, int size) {
    int sizeHiBits;
    int newObj;
    int binc;
    int hash;
    int header1;
    int header2;
    int header3;
    int hdrSize;
    int byteSize;
    int format;
    int inc;
    int cClass;
    int fillWord;
    int i;
    int newObj1;
    int remappedClassOop;
    int end;
    int oop;
    int newFreeSize;
    int enoughSpace;
    int newChunk;
    int minFree;

	;
	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;
	header1 = (longAt(((((char *) classPointer)) + 4) + (2 << 2))) - 1;
	sizeHiBits = ((unsigned) (header1 & 393216)) >> 9;
	header1 = (header1 & 131071) | ((hash << 17) & 536739840);
	header2 = classPointer;
	header3 = 0;
	cClass = header1 & 126976;
	byteSize = (header1 & 252) + sizeHiBits;
	format = (((unsigned) header1) >> 8) & 15;
	if (format < 8) {
		inc = size * 4;
	} else {
		inc = (size + 3) & 4294967292U;
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

int instantiateContextsizeInBytes(int classPointer, int sizeInBytes) {
    int header1;
    int header2;
    int hdrSize;
    int hash;
    int i;
    int newObj;
    int remappedClassOop;
    int end;
    int oop;
    int newFreeSize;
    int enoughSpace;
    int newChunk;
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

int instantiateSmallClasssizeInBytesfill(int classPointer, int sizeInBytes, int fillValue) {
    int header1;
    int header2;
    int hdrSize;
    int hash;
    int i;
    int newObj;
    int remappedClassOop;
    int end;
    int oop;
    int newFreeSize;
    int enoughSpace;
    int newChunk;
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

int intToNetAddress(int addr) {
    int netAddressOop;

	netAddressOop = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (26 << 2)), 8, 0);
	byteAtput(((((char *) netAddressOop)) + 4) + 0, (((unsigned) addr) >> 24) & 255);
	byteAtput(((((char *) netAddressOop)) + 4) + 1, (((unsigned) addr) >> 16) & 255);
	byteAtput(((((char *) netAddressOop)) + 4) + 2, (((unsigned) addr) >> 8) & 255);
	byteAtput(((((char *) netAddressOop)) + 4) + 3, addr & 255);
	return netAddressOop;
}

int integerObjectOf(int value) {
	if (value < 0) {
		return ((2147483648U + value) << 1) + 1;
	} else {
		return (value << 1) + 1;
	}
}

int integerValueOf(int objectPointer) {
	if ((objectPointer & 2147483648U) != 0) {
		return ((((unsigned) (objectPointer & 2147483647U)) >> 1) - 1073741823) - 1;
	} else {
		return ((unsigned) objectPointer) >> 1;
	}
}

int interpret(void) {
    int localHomeContext;
    char * localSP;
    char * localIP;
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
			t3 = nilObj;
			t4 = activeContext;
			if ((t2 == t3) || ((longAt(((((char *) t2)) + 4) + (1 << 2))) == t3)) {
				/* begin internalPush: */
				longAtput(localSP += 4, activeContext);
				/* begin internalPush: */
				longAtput(localSP += 4, t1);
				messageSelector = longAt(((((char *) specialObjectsOop)) + 4) + (21 << 2));
				argumentCount = 1;
				/* begin normalSend */
				goto commonSend;
			l1:	/* end fetchClassOf: */;
			l2:	/* end lookupInMethodCacheSel:class: */;
			l5:	/* end internalExecuteNewMethod */;
			}
			while (!(t4 == t2)) {
				t5 = longAt(((((char *) t4)) + 4) + (0 << 2));
				longAtput(((((char *) t4)) + 4) + (0 << 2), t3);
				longAtput(((((char *) t4)) + 4) + (1 << 2), t3);
				if (reclaimableContextCount > 0) {
					reclaimableContextCount -= 1;
					/* begin recycleContextIfPossible: */
					if ((t4 >= youngStart) && (((((unsigned) (longAt(t4))) >> 12) & 31) == 14)) {
						longAtput(((((char *) t4)) + 4) + (0 << 2), freeContexts);
						freeContexts = t4;
					}
				}
				t4 = t5;
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
		l3:	/* end returnValue:to: */;
			break;
		case 121:
			/* returnTrue */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = trueObj;
			/* begin returnValue:to: */
			goto commonReturn;
		l8:	/* end returnValue:to: */;
			break;
		case 122:
			/* returnFalse */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = falseObj;
			/* begin returnValue:to: */
			goto commonReturn;
		l13:	/* end returnValue:to: */;
			break;
		case 123:
			/* returnNil */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = nilObj;
			/* begin returnValue:to: */
			goto commonReturn;
		l18:	/* end returnValue:to: */;
			break;
		case 124:
			/* returnTopFromMethod */
			t2 = longAt(((((char *) localHomeContext)) + 4) + (0 << 2));
			t1 = longAt(localSP);
			/* begin returnValue:to: */
			goto commonReturn;
		l23:	/* end returnValue:to: */;
			break;
		case 125:
			/* returnTopFromBlock */
			t2 = longAt(((((char *) activeContext)) + 4) + (0 << 2));
			t1 = longAt(localSP);
			/* begin returnValue:to: */
			goto commonReturn;
		l28:	/* end returnValue:to: */;
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
				goto l31;
			}
			if (t2 == 1) {
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) localHomeContext)) + 4) + ((t3 + 6) << 2)));
				goto l31;
			}
			if (t2 == 2) {
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) method)) + 4) + ((t3 + 1) << 2)));
				goto l31;
			}
			if (t2 == 3) {
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + ((t3 + 1) << 2))))) + 4) + (1 << 2)));
				goto l31;
			}
		l31:	/* end case */;
			break;
		case 129:
			/* extendedStoreBytecode */
			t1 = byteAt(++localIP);
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = (((unsigned) t1) >> 6) & 3;
			t3 = t1 & 63;
			if (t2 == 0) {
				/* begin storePointer:ofObject:withValue: */
				t5 = receiver;
				t6 = longAt(localSP);
				if (t5 < youngStart) {
					possibleRootStoreIntovalue(t5, t6);
				}
				longAtput(((((char *) t5)) + 4) + (t3 << 2), t6);
				goto l32;
			}
			if (t2 == 1) {
				longAtput(((((char *) localHomeContext)) + 4) + ((t3 + 6) << 2), longAt(localSP));
				goto l32;
			}
			if (t2 == 2) {
				error("illegal store");
			}
			if (t2 == 3) {
				t4 = longAt(((((char *) method)) + 4) + ((t3 + 1) << 2));
				/* begin storePointer:ofObject:withValue: */
				t7 = longAt(localSP);
				if (t4 < youngStart) {
					possibleRootStoreIntovalue(t4, t7);
				}
				longAtput(((((char *) t4)) + 4) + (1 << 2), t7);
				goto l32;
			}
		l32:	/* end case */;
			break;
		case 130:
			/* extendedStoreAndPopBytecode */
			/* begin extendedStoreBytecode */
			t1 = byteAt(++localIP);
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			t2 = (((unsigned) t1) >> 6) & 3;
			t3 = t1 & 63;
			if (t2 == 0) {
				/* begin storePointer:ofObject:withValue: */
				t5 = receiver;
				t6 = longAt(localSP);
				if (t5 < youngStart) {
					possibleRootStoreIntovalue(t5, t6);
				}
				longAtput(((((char *) t5)) + 4) + (t3 << 2), t6);
				goto l33;
			}
			if (t2 == 1) {
				longAtput(((((char *) localHomeContext)) + 4) + ((t3 + 6) << 2), longAt(localSP));
				goto l33;
			}
			if (t2 == 2) {
				error("illegal store");
			}
			if (t2 == 3) {
				t4 = longAt(((((char *) method)) + 4) + ((t3 + 1) << 2));
				/* begin storePointer:ofObject:withValue: */
				t7 = longAt(localSP);
				if (t4 < youngStart) {
					possibleRootStoreIntovalue(t4, t7);
				}
				longAtput(((((char *) t4)) + 4) + (1 << 2), t7);
				goto l33;
			}
		l33:	/* end extendedStoreBytecode */;
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
				goto l35;
			}
			t6 = (((unsigned) (longAt(t2))) >> 12) & 31;
			if (t6 == 0) {
				lkupClass = (longAt(t2 - 4)) & 4294967292U;
				goto l35;
			} else {
				lkupClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t6 - 1) << 2));
				goto l35;
			}
		l35:	/* end fetchClassOf: */;
		commonLookup:	/*  */;
			/* begin lookupInMethodCacheSel:class: */
			t5 = messageSelector ^ lkupClass;
			t4 = t5 & 2044;
			if (((methodCache[t4 + 1]) == messageSelector) && ((methodCache[t4 + 2]) == lkupClass)) {
				newMethod = methodCache[t4 + 3];
				primitiveIndex = methodCache[t4 + 4];
				t3 = 1;
				goto l34;
			}
			t4 = (((unsigned) t5) >> 1) & 2044;
			if (((methodCache[t4 + 1]) == messageSelector) && ((methodCache[t4 + 2]) == lkupClass)) {
				newMethod = methodCache[t4 + 3];
				primitiveIndex = methodCache[t4 + 4];
				t3 = 1;
				goto l34;
			}
			t4 = (((unsigned) t5) >> 2) & 2044;
			if (((methodCache[t4 + 1]) == messageSelector) && ((methodCache[t4 + 2]) == lkupClass)) {
				newMethod = methodCache[t4 + 3];
				primitiveIndex = methodCache[t4 + 4];
				t3 = 1;
				goto l34;
			}
			t3 = 0;
		l34:	/* end lookupInMethodCacheSel:class: */;
			if (!(t3)) {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				lookupMethodInClass(lkupClass);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				addToMethodCacheSelclassmethodprimIndex(messageSelector, lkupClass, newMethod, primitiveIndex);
			}
			/* begin internalExecuteNewMethod */
			t7 = primitiveIndex;
			if (t7 > 0) {
				if ((t7 > 255) && (t7 < 520)) {
					if (t7 >= 264) {
						/* begin internalPop:thenPush: */
						t8 = longAt(((((char *) (longAt(localSP)))) + 4) + ((t7 - 264) << 2));
						longAtput(localSP -= (1 - 1) * 4, t8);
						goto l37;
					} else {
						if (t7 == 256) {
							goto l37;
						}
						if (t7 == 257) {
							/* begin internalPop:thenPush: */
							longAtput(localSP -= (1 - 1) * 4, trueObj);
							goto l37;
						}
						if (t7 == 258) {
							/* begin internalPop:thenPush: */
							longAtput(localSP -= (1 - 1) * 4, falseObj);
							goto l37;
						}
						if (t7 == 259) {
							/* begin internalPop:thenPush: */
							longAtput(localSP -= (1 - 1) * 4, nilObj);
							goto l37;
						}
						/* begin internalPop:thenPush: */
						longAtput(localSP -= (1 - 1) * 4, (((t7 - 261) << 1) | 1));
						goto l37;
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
						goto l37;
					}
				}
			}
			/* begin internalActivateNewMethod */
			if (compilerInitialized) {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				/* begin activateNewMethod */
				if (!(compilerInitialized && (compilerActivateMethod()))) {
					bytecodeActivateNewMethod();
				}
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
			} else {
				/* begin internalBytecodeActivateNewMethod */
				t11 = longAt(((((char *) newMethod)) + 4) + (0 << 2));
				if (freeContexts != 1) {
					t13 = freeContexts;
					freeContexts = longAt(((((char *) t13)) + 4) + (0 << 2));
				} else {
					/* begin externalizeIPandSP */
					instructionPointer = ((int) localIP);
					stackPointer = ((int) localSP);
					theHomeContext = localHomeContext;
					/* begin allocateOrRecycleContext */
					if (freeContexts != 1) {
						t15 = freeContexts;
						freeContexts = longAt(((((char *) t15)) + 4) + (0 << 2));
						t13 = t15;
						goto l36;
					}
					t15 = instantiateContextsizeInBytes(longAt(((((char *) specialObjectsOop)) + 4) + (10 << 2)), 156);
					longAtput(((((char *) t15)) + 4) + (4 << 2), nilObj);
					t13 = t15;
				l36:	/* end allocateOrRecycleContext */;
					/* begin internalizeIPandSP */
					localIP = ((char *) instructionPointer);
					localSP = ((char *) stackPointer);
					localHomeContext = theHomeContext;
				}
				t12 = (((unsigned) t11) >> 19) & 63;
				longAtput(((((char *) t13)) + 4) + (0 << 2), activeContext);
				longAtput(((((char *) t13)) + 4) + (1 << 2), (((((1 + ((((unsigned) t11) >> 10) & 255)) * 4) + 1) << 1) | 1));
				longAtput(((((char *) t13)) + 4) + (2 << 2), ((t12 << 1) | 1));
				longAtput(((((char *) t13)) + 4) + (3 << 2), newMethod);
				t9 = argumentCount;
				for (t10 = 0; t10 <= t9; t10 += 1) {
					longAtput(((((char *) t13)) + 4) + ((5 + t10) << 2), longAt(localSP - ((t9 - t10) * 4)));
				}
				t11 = nilObj;
				for (t10 = (t9 + 1); t10 <= t12; t10 += 1) {
					longAtput(((((char *) t13)) + 4) + ((5 + t10) << 2), t11);
				}
				/* begin internalPop: */
				localSP -= (t9 + 1) * 4;
				reclaimableContextCount += 1;
				/* begin internalNewActiveContext: */
				/* begin internalStoreContextRegisters: */
				longAtput(((((char *) activeContext)) + 4) + (1 << 2), (((((((int) localIP )) + 2) - (method + 4)) << 1) | 1));
				longAtput(((((char *) activeContext)) + 4) + (2 << 2), (((((((unsigned) ((((int) localSP )) - (activeContext + 4))) >> 2) - 6) + 1) << 1) | 1));
				if (t13 < youngStart) {
					beRootIfOld(t13);
				}
				activeContext = t13;
				/* begin internalFetchContextRegisters: */
				t14 = longAt(((((char *) t13)) + 4) + (3 << 2));
				if ((t14 & 1)) {
					t14 = longAt(((((char *) t13)) + 4) + (5 << 2));
					if (t14 < youngStart) {
						beRootIfOld(t14);
					}
				} else {
					t14 = t13;
				}
				localHomeContext = t14;
				receiver = longAt(((((char *) t14)) + 4) + (5 << 2));
				method = longAt(((((char *) t14)) + 4) + (3 << 2));
				t14 = ((longAt(((((char *) t13)) + 4) + (1 << 2))) >> 1);
				localIP = ((char *) (((method + t14) + 4) - 2));
				t14 = ((longAt(((((char *) t13)) + 4) + (2 << 2))) >> 1);
				localSP = ((char *) ((t13 + 4) + (((6 + t14) - 1) * 4)));
			}
			/* begin internalQuickCheckForInterrupts */
			if ((interruptCheckCounter -= 1) <= 0) {
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				checkForInterrupts();
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
			}
		l37:	/* end internalExecuteNewMethod */;
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			break;
		case 132:
			/* doubleExtendedDoAnythingBytecode */
			t1 = byteAt(++localIP);
			t2 = byteAt(++localIP);
			t4 = ((unsigned) t1) >> 5;
			if (t4 == 0) {
				messageSelector = longAt(((((char *) method)) + 4) + ((t2 + 1) << 2));
				argumentCount = t1 & 31;
				/* begin normalSend */
				goto commonSend;
			l40:	/* end fetchClassOf: */;
			l39:	/* end lookupInMethodCacheSel:class: */;
			l43:	/* end internalExecuteNewMethod */;
			}
			if (t4 == 1) {
				messageSelector = longAt(((((char *) method)) + 4) + ((t2 + 1) << 2));
				argumentCount = t1 & 31;
				/* begin superclassSend */
				goto commonSupersend;
			l41:	/* end lookupInMethodCacheSel:class: */;
			l45:	/* end internalExecuteNewMethod */;
			}
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			if (t4 == 2) {
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) receiver)) + 4) + (t2 << 2)));
				goto l38;
			}
			if (t4 == 3) {
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) method)) + 4) + ((t2 + 1) << 2)));
				goto l38;
			}
			if (t4 == 4) {
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtput(localSP += 4, longAt(((((char *) (longAt(((((char *) method)) + 4) + ((t2 + 1) << 2))))) + 4) + (1 << 2)));
				goto l38;
			}
			if (t4 == 5) {
				t3 = longAt(localSP);
				/* begin storePointer:ofObject:withValue: */
				t10 = receiver;
				if (t10 < youngStart) {
					possibleRootStoreIntovalue(t10, t3);
				}
				longAtput(((((char *) t10)) + 4) + (t2 << 2), t3);
				goto l38;
			}
			if (t4 == 6) {
				t3 = longAt(localSP);
				/* begin internalPop: */
				localSP -= 1 * 4;
				/* begin storePointer:ofObject:withValue: */
				t11 = receiver;
				if (t11 < youngStart) {
					possibleRootStoreIntovalue(t11, t3);
				}
				longAtput(((((char *) t11)) + 4) + (t2 << 2), t3);
				goto l38;
			}
			if (t4 == 7) {
				t3 = longAt(localSP);
				/* begin storePointer:ofObject:withValue: */
				t12 = longAt(((((char *) method)) + 4) + ((t2 + 1) << 2));
				if (t12 < youngStart) {
					possibleRootStoreIntovalue(t12, t3);
				}
				longAtput(((((char *) t12)) + 4) + (1 << 2), t3);
				goto l38;
			}
		l38:	/* end case */;
			break;
		case 133:
			/* singleExtendedSuperBytecode */
			t1 = byteAt(++localIP);
			messageSelector = longAt(((((char *) method)) + 4) + (((t1 & 31) + 1) << 2));
			argumentCount = ((unsigned) t1) >> 5;
			/* begin superclassSend */
		commonSupersend:	/*  */;
			/* begin superclassOf: */
			t2 = longAt(((((char *) (longAt(((((char *) method)) + 4) + (((((((unsigned) (longAt(((((char *) method)) + 4) + (0 << 2)))) >> 10) & 255) - 1) + 1) << 2))))) + 4) + (1 << 2));
			lkupClass = longAt(((((char *) t2)) + 4) + (0 << 2));
			goto commonLookup;
		l46:	/* end lookupInMethodCacheSel:class: */;
		l48:	/* end internalExecuteNewMethod */;
			break;
		case 134:
			/* secondExtendedSendBytecode */
			t1 = byteAt(++localIP);
			messageSelector = longAt(((((char *) method)) + 4) + (((t1 & 63) + 1) << 2));
			argumentCount = ((unsigned) t1) >> 6;
			/* begin normalSend */
			goto commonSend;
		l50:	/* end fetchClassOf: */;
		l49:	/* end lookupInMethodCacheSel:class: */;
		l52:	/* end internalExecuteNewMethod */;
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
			t3 = longAt(((((char *) localHomeContext)) + 4) + (((currentBytecode - 138) + 6) << 2));
			t4 = byteAt(localIP + 1);
			t5 = byteAt(localIP + 2);
			t6 = byteAt(localIP + 3);
			if ((t3 & 1)) {
				t1 = (t3 >> 1);
			} else {
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				/* begin internalPush: */
				longAtput(localSP += 4, t3);
				goto l53;
			}
			if (t4 < 32) {
				t2 = longAt(((((char *) localHomeContext)) + 4) + (((t4 & 15) + 6) << 2));
				if ((t2 & 1)) {
					t2 = (t2 >> 1);
				} else {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					/* begin internalPush: */
					longAtput(localSP += 4, t3);
					goto l53;
				}
			} else {
				if (t4 > 64) {
					t2 = 1;
				} else {
					t2 = longAt(((((char *) method)) + 4) + (((t4 & 31) + 1) << 2));
					if ((t2 & 1)) {
						t2 = (t2 >> 1);
					} else {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						/* begin internalPush: */
						longAtput(localSP += 4, t3);
						goto l53;
					}
				}
			}
			if (t5 < 178) {
				t8 = t1 + t2;
				if ((t8 ^ (t8 << 1)) >= 0) {
					if ((t6 > 103) && (t6 < 112)) {
						localIP += 3;
						longAtput(((((char *) localHomeContext)) + 4) + (((t6 & 7) + 6) << 2), ((t8 << 1) | 1));
					} else {
						localIP += 2;
						/* begin internalPush: */
						longAtput(localSP += 4, ((t8 << 1) | 1));
					}
				} else {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					/* begin internalPush: */
					longAtput(localSP += 4, t3);
					goto l53;
				}
			} else {
				t7 = byteAt(localIP + 4);
				if (t1 <= t2) {
					localIP = (localIP + 3) + 1;
				} else {
					localIP = ((localIP + 3) + 1) + t7;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
			}
		l53:	/* end case */;
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
				l54:	/* end fetchClassOf: */;
				l55:	/* end lookupInMethodCacheSel:class: */;
				l58:	/* end internalExecuteNewMethod */;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
			}
			/* begin internalPop: */
			localSP -= 1 * 4;
		l56:	/* end jumplfFalseBy: */;
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
				l60:	/* end fetchClassOf: */;
				l59:	/* end lookupInMethodCacheSel:class: */;
				l63:	/* end internalExecuteNewMethod */;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
			}
			/* begin internalPop: */
			localSP -= 1 * 4;
		l61:	/* end jumplfTrueBy: */;
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
				l64:	/* end fetchClassOf: */;
				l65:	/* end lookupInMethodCacheSel:class: */;
				l68:	/* end internalExecuteNewMethod */;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
			}
			/* begin internalPop: */
			localSP -= 1 * 4;
		l66:	/* end jumplfFalseBy: */;
			break;
		case 176:
			/* bytecodePrimAdd */
			t2 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t2 & t1) & 1) != 0) {
				t3 = ((t2 >> 1)) + ((t1 >> 1));
				if ((t3 ^ (t3 << 1)) >= 0) {
					/* begin internalPop:thenPush: */
					longAtput(localSP -= (2 - 1) * 4, ((t3 << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l69;
				}
			} else {
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveFloatAddtoArg(t2, t1);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l69;
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((0 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l71:	/* end fetchClassOf: */;
		l70:	/* end lookupInMethodCacheSel:class: */;
		l73:	/* end internalExecuteNewMethod */;
		l69:	/* end case */;
			break;
		case 177:
			/* bytecodePrimSubtract */
			t2 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t2 & t1) & 1) != 0) {
				t3 = ((t2 >> 1)) - ((t1 >> 1));
				if ((t3 ^ (t3 << 1)) >= 0) {
					/* begin internalPop:thenPush: */
					longAtput(localSP -= (2 - 1) * 4, ((t3 << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l74;
				}
			} else {
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveFloatSubtractfromArg(t2, t1);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l74;
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((1 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l76:	/* end fetchClassOf: */;
		l75:	/* end lookupInMethodCacheSel:class: */;
		l78:	/* end internalExecuteNewMethod */;
		l74:	/* end case */;
			break;
		case 178:
			/* bytecodePrimLessThan */
			t3 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t3 & t1) & 1) != 0) {
				;
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t3 < t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l79;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l79;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t3 < t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l79;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l79;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t3 < t1) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l79;
			}
			successFlag = 1;
			t2 = primitiveFloatLessthanArg(t3, t1);
			if (successFlag) {
				/* begin booleanCheat: */
				t8 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t8 < 160) && (t8 > 151)) {
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l79;
					} else {
						/* begin jump: */
						localIP = (localIP + (t8 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l79;
					}
				}
				if (t8 == 172) {
					t9 = byteAt(++localIP);
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l79;
					} else {
						/* begin jump: */
						localIP = (localIP + t9) + 1;
						currentBytecode = byteAt(localIP);
						goto l79;
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
				goto l79;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((2 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l81:	/* end fetchClassOf: */;
		l80:	/* end lookupInMethodCacheSel:class: */;
		l83:	/* end internalExecuteNewMethod */;
		l79:	/* end case */;
			break;
		case 179:
			/* bytecodePrimGreaterThan */
			t3 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t3 & t1) & 1) != 0) {
				;
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t3 > t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l84;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l84;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t3 > t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l84;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l84;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t3 > t1) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l84;
			}
			successFlag = 1;
			t2 = primitiveFloatGreaterthanArg(t3, t1);
			if (successFlag) {
				/* begin booleanCheat: */
				t8 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t8 < 160) && (t8 > 151)) {
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l84;
					} else {
						/* begin jump: */
						localIP = (localIP + (t8 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l84;
					}
				}
				if (t8 == 172) {
					t9 = byteAt(++localIP);
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l84;
					} else {
						/* begin jump: */
						localIP = (localIP + t9) + 1;
						currentBytecode = byteAt(localIP);
						goto l84;
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
				goto l84;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((3 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l86:	/* end fetchClassOf: */;
		l85:	/* end lookupInMethodCacheSel:class: */;
		l88:	/* end internalExecuteNewMethod */;
		l84:	/* end case */;
			break;
		case 180:
			/* bytecodePrimLessOrEqual */
			t3 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t3 & t1) & 1) != 0) {
				;
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t3 <= t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l89;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l89;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t3 <= t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l89;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l89;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t3 <= t1) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l89;
			}
			successFlag = 1;
			t2 = primitiveFloatGreaterthanArg(t3, t1);
			if (successFlag) {
				/* begin booleanCheat: */
				t8 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t8 < 160) && (t8 > 151)) {
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l89;
					} else {
						/* begin jump: */
						localIP = (localIP + (t8 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l89;
					}
				}
				if (t8 == 172) {
					t9 = byteAt(++localIP);
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l89;
					} else {
						/* begin jump: */
						localIP = (localIP + t9) + 1;
						currentBytecode = byteAt(localIP);
						goto l89;
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
				goto l89;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((4 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l91:	/* end fetchClassOf: */;
		l90:	/* end lookupInMethodCacheSel:class: */;
		l93:	/* end internalExecuteNewMethod */;
		l89:	/* end case */;
			break;
		case 181:
			/* bytecodePrimGreaterOrEqual */
			t3 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t3 & t1) & 1) != 0) {
				;
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t3 >= t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l94;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l94;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t3 >= t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l94;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l94;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t3 >= t1) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l94;
			}
			successFlag = 1;
			t2 = primitiveFloatLessthanArg(t3, t1);
			if (successFlag) {
				/* begin booleanCheat: */
				t8 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t8 < 160) && (t8 > 151)) {
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l94;
					} else {
						/* begin jump: */
						localIP = (localIP + (t8 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l94;
					}
				}
				if (t8 == 172) {
					t9 = byteAt(++localIP);
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l94;
					} else {
						/* begin jump: */
						localIP = (localIP + t9) + 1;
						currentBytecode = byteAt(localIP);
						goto l94;
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
				goto l94;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((5 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l96:	/* end fetchClassOf: */;
		l95:	/* end lookupInMethodCacheSel:class: */;
		l98:	/* end internalExecuteNewMethod */;
		l94:	/* end case */;
			break;
		case 182:
			/* bytecodePrimEqual */
			t3 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t3 & t1) & 1) != 0) {
				/* begin booleanCheat: */
				t4 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t4 < 160) && (t4 > 151)) {
					if (t3 == t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l99;
					} else {
						/* begin jump: */
						localIP = (localIP + (t4 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l99;
					}
				}
				if (t4 == 172) {
					t5 = byteAt(++localIP);
					if (t3 == t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l99;
					} else {
						/* begin jump: */
						localIP = (localIP + t5) + 1;
						currentBytecode = byteAt(localIP);
						goto l99;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t3 == t1) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l99;
			}
			successFlag = 1;
			t2 = primitiveFloatEqualtoArg(t3, t1);
			if (successFlag) {
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l99;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l99;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l99;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l99;
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
				goto l99;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((6 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l101:	/* end fetchClassOf: */;
		l100:	/* end lookupInMethodCacheSel:class: */;
		l103:	/* end internalExecuteNewMethod */;
		l99:	/* end case */;
			break;
		case 183:
			/* bytecodePrimNotEqual */
			t3 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t3 & t1) & 1) != 0) {
				/* begin booleanCheat: */
				t4 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t4 < 160) && (t4 > 151)) {
					if (t3 != t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l104;
					} else {
						/* begin jump: */
						localIP = (localIP + (t4 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l104;
					}
				}
				if (t4 == 172) {
					t5 = byteAt(++localIP);
					if (t3 != t1) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l104;
					} else {
						/* begin jump: */
						localIP = (localIP + t5) + 1;
						currentBytecode = byteAt(localIP);
						goto l104;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAt(++localIP);
				if (t3 != t1) {
					/* begin internalPush: */
					longAtput(localSP += 4, trueObj);
				} else {
					/* begin internalPush: */
					longAtput(localSP += 4, falseObj);
				}
				goto l104;
			}
			successFlag = 1;
			t2 = primitiveFloatEqualtoArg(t3, t1);
			if (successFlag) {
				/* begin booleanCheat: */
				t6 = byteAt(++localIP);
				/* begin internalPop: */
				localSP -= 2 * 4;
				if ((t6 < 160) && (t6 > 151)) {
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l104;
					} else {
						/* begin jump: */
						localIP = (localIP + (t6 - 151)) + 1;
						currentBytecode = byteAt(localIP);
						goto l104;
					}
				}
				if (t6 == 172) {
					t7 = byteAt(++localIP);
					if (!t2) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l104;
					} else {
						/* begin jump: */
						localIP = (localIP + t7) + 1;
						currentBytecode = byteAt(localIP);
						goto l104;
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
				goto l104;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((7 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l106:	/* end fetchClassOf: */;
		l105:	/* end lookupInMethodCacheSel:class: */;
		l108:	/* end internalExecuteNewMethod */;
		l104:	/* end case */;
			break;
		case 184:
			/* bytecodePrimMultiply */
			t2 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t2 & t1) & 1) != 0) {
				t2 = (t2 >> 1);
				t1 = (t1 >> 1);
				t3 = t2 * t1;
				if (((t1 == 0) || ((t3 / t1) == t2)) && ((t3 ^ (t3 << 1)) >= 0)) {
					/* begin internalPop:thenPush: */
					longAtput(localSP -= (2 - 1) * 4, ((t3 << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l109;
				}
			} else {
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveFloatMultiplybyArg(t2, t1);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l109;
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((8 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l111:	/* end fetchClassOf: */;
		l110:	/* end lookupInMethodCacheSel:class: */;
		l113:	/* end internalExecuteNewMethod */;
		l109:	/* end case */;
			break;
		case 185:
			/* bytecodePrimDivide */
			t2 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			if (((t2 & t1) & 1) != 0) {
				t2 = (t2 >> 1);
				t1 = (t1 >> 1);
				if ((t1 != 0) && ((t2 % t1) == 0)) {
					t3 = t2 / t1;
					if ((t3 ^ (t3 << 1)) >= 0) {
						/* begin internalPop:thenPush: */
						longAtput(localSP -= (2 - 1) * 4, ((t3 << 1) | 1));
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						goto l114;
					}
				}
			} else {
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = ((int) localIP);
				stackPointer = ((int) localSP);
				theHomeContext = localHomeContext;
				primitiveFloatDividebyArg(t2, t1);
				/* begin internalizeIPandSP */
				localIP = ((char *) instructionPointer);
				localSP = ((char *) stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l114;
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((9 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l116:	/* end fetchClassOf: */;
		l115:	/* end lookupInMethodCacheSel:class: */;
		l118:	/* end internalExecuteNewMethod */;
		l114:	/* end case */;
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
				goto l119;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((10 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l121:	/* end fetchClassOf: */;
		l120:	/* end lookupInMethodCacheSel:class: */;
		l123:	/* end internalExecuteNewMethod */;
		l119:	/* end case */;
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
				goto l124;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((11 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l126:	/* end fetchClassOf: */;
		l125:	/* end lookupInMethodCacheSel:class: */;
		l128:	/* end internalExecuteNewMethod */;
		l124:	/* end case */;
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
				goto l129;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((12 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l131:	/* end fetchClassOf: */;
		l130:	/* end lookupInMethodCacheSel:class: */;
		l133:	/* end internalExecuteNewMethod */;
		l129:	/* end case */;
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
				goto l134;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((13 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l136:	/* end fetchClassOf: */;
		l135:	/* end lookupInMethodCacheSel:class: */;
		l138:	/* end internalExecuteNewMethod */;
		l134:	/* end case */;
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
			t2 = positive32BitValueOf(t5);
			/* begin popPos32BitInteger */
			/* begin popStack */
			t8 = longAt(stackPointer);
			stackPointer -= 4;
			t7 = t8;
			t1 = positive32BitValueOf(t7);
			if (successFlag) {
				/* begin push: */
				t3 = positive32BitIntegerFor(t1 & t2);
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
				goto l139;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((14 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l141:	/* end fetchClassOf: */;
		l140:	/* end lookupInMethodCacheSel:class: */;
		l143:	/* end internalExecuteNewMethod */;
		l139:	/* end case */;
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
			t2 = positive32BitValueOf(t5);
			/* begin popPos32BitInteger */
			/* begin popStack */
			t8 = longAt(stackPointer);
			stackPointer -= 4;
			t7 = t8;
			t1 = positive32BitValueOf(t7);
			if (successFlag) {
				/* begin push: */
				t3 = positive32BitIntegerFor(t1 | t2);
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
				goto l144;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((15 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l146:	/* end fetchClassOf: */;
		l145:	/* end lookupInMethodCacheSel:class: */;
		l148:	/* end internalExecuteNewMethod */;
		l144:	/* end case */;
			break;
		case 192:
			/* bytecodePrimAt */
			t1 = longAt(localSP);
			t2 = longAt(localSP - (1 * 4));
			successFlag = (!((t2 & 1))) && ((t1 & 1));
			if (successFlag) {
				t4 = t2 & 28;
				if ((atCache[t4 + 1]) == t2) {
					/* begin commonVariableInternal:at:cacheIndex: */
					t10 = atCache[t4 + 2];
					if (((((unsigned ) ((t1 >> 1)))) >= 1) && ((((unsigned ) ((t1 >> 1)))) <= (((unsigned ) t10)))) {
						t11 = atCache[t4 + 3];
						if (t11 <= 4) {
							t12 = atCache[t4 + 4];
							t3 = longAt(((((char *) t2)) + 4) + (((((t1 >> 1)) + t12) - 1) << 2));
							goto l152;
						}
						if (t11 < 8) {
							t13 = longAt(((((char *) t2)) + 4) + ((((t1 >> 1)) - 1) << 2));
							/* begin externalizeIPandSP */
							instructionPointer = ((int) localIP);
							stackPointer = ((int) localSP);
							theHomeContext = localHomeContext;
							t13 = positive32BitIntegerFor(t13);
							/* begin internalizeIPandSP */
							localIP = ((char *) instructionPointer);
							localSP = ((char *) stackPointer);
							localHomeContext = theHomeContext;
							t3 = t13;
							goto l152;
						}
						if (t11 >= 16) {
							t3 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (24 << 2))))) + 4) + ((byteAt(((((char *) t2)) + 4) + (((t1 >> 1)) - 1))) << 2));
							goto l152;
						} else {
							t3 = (((byteAt(((((char *) t2)) + 4) + (((t1 >> 1)) - 1))) << 1) | 1);
							goto l152;
						}
					}
					/* begin primitiveFail */
					successFlag = 0;
				l152:	/* end commonVariableInternal:at:cacheIndex: */;
					if (successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						/* begin internalPop:thenPush: */
						longAtput(localSP -= (2 - 1) * 4, t3);
						goto l149;
					}
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((16 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l151:	/* end fetchClassOf: */;
		l150:	/* end lookupInMethodCacheSel:class: */;
		l154:	/* end internalExecuteNewMethod */;
		l149:	/* end case */;
			break;
		case 193:
			/* bytecodePrimAtPut */
			t1 = longAt(localSP);
			t2 = longAt(localSP - (1 * 4));
			t3 = longAt(localSP - (2 * 4));
			successFlag = (!((t3 & 1))) && ((t2 & 1));
			if (successFlag) {
				t4 = (t3 & 28) + 32;
				if ((atCache[t4 + 1]) == t3) {
					/* begin commonVariable:at:put:cacheIndex: */
					t5 = atCache[t4 + 2];
					if (((((unsigned ) ((t2 >> 1)))) >= 1) && ((((unsigned ) ((t2 >> 1)))) <= (((unsigned ) t5)))) {
						t7 = atCache[t4 + 3];
						if (t7 <= 4) {
							t8 = atCache[t4 + 4];
							/* begin storePointer:ofObject:withValue: */
							if (t3 < youngStart) {
								possibleRootStoreIntovalue(t3, t1);
							}
							longAtput(((((char *) t3)) + 4) + (((((t2 >> 1)) + t8) - 1) << 2), t1);
							goto l156;
						}
						if (t7 < 8) {
							t6 = positive32BitValueOf(t1);
							if (successFlag) {
								longAtput(((((char *) t3)) + 4) + ((((t2 >> 1)) - 1) << 2), t6);
							}
							goto l156;
						}
						if (t7 >= 16) {
							t6 = asciiOfCharacter(t1);
							if (!(successFlag)) {
								goto l156;
							}
						} else {
							t6 = t1;
						}
						if ((t6 & 1)) {
							byteAtput(((((char *) t3)) + 4) + (((t2 >> 1)) - 1), (t6 >> 1));
							goto l156;
						}
					}
					/* begin primitiveFail */
					successFlag = 0;
				l156:	/* end commonVariable:at:put:cacheIndex: */;
					if (successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAt(++localIP);
						/* begin internalPop:thenPush: */
						longAtput(localSP -= (3 - 1) * 4, t1);
						goto l155;
					}
				}
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((17 * 2) << 2));
			argumentCount = 2;
			/* begin normalSend */
			goto commonSend;
		l158:	/* end fetchClassOf: */;
		l157:	/* end lookupInMethodCacheSel:class: */;
		l160:	/* end internalExecuteNewMethod */;
		l155:	/* end case */;
			break;
		case 194:
			/* bytecodePrimSize */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((18 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l162:	/* end fetchClassOf: */;
		l161:	/* end lookupInMethodCacheSel:class: */;
		l164:	/* end internalExecuteNewMethod */;
			break;
		case 195:
			/* bytecodePrimNext */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((19 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l166:	/* end fetchClassOf: */;
		l165:	/* end lookupInMethodCacheSel:class: */;
		l168:	/* end internalExecuteNewMethod */;
			break;
		case 196:
			/* bytecodePrimNextPut */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((20 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l170:	/* end fetchClassOf: */;
		l169:	/* end lookupInMethodCacheSel:class: */;
		l172:	/* end internalExecuteNewMethod */;
			break;
		case 197:
			/* bytecodePrimAtEnd */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((21 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l174:	/* end fetchClassOf: */;
		l173:	/* end lookupInMethodCacheSel:class: */;
		l176:	/* end internalExecuteNewMethod */;
			break;
		case 198:
			/* bytecodePrimEquivalent */
			t2 = longAt(localSP - (1 * 4));
			t1 = longAt(localSP - (0 * 4));
			/* begin booleanCheat: */
			t3 = byteAt(++localIP);
			/* begin internalPop: */
			localSP -= 2 * 4;
			if ((t3 < 160) && (t3 > 151)) {
				if (t2 == t1) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l177;
				} else {
					/* begin jump: */
					localIP = (localIP + (t3 - 151)) + 1;
					currentBytecode = byteAt(localIP);
					goto l177;
				}
			}
			if (t3 == 172) {
				t4 = byteAt(++localIP);
				if (t2 == t1) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAt(++localIP);
					goto l177;
				} else {
					/* begin jump: */
					localIP = (localIP + t4) + 1;
					currentBytecode = byteAt(localIP);
					goto l177;
				}
			}
			localIP -= 1;
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
			if (t2 == t1) {
				/* begin internalPush: */
				longAtput(localSP += 4, trueObj);
			} else {
				/* begin internalPush: */
				longAtput(localSP += 4, falseObj);
			}
		l177:	/* end booleanCheat: */;
			break;
		case 199:
			/* bytecodePrimClass */
			t1 = longAt(localSP);
			/* begin internalPop:thenPush: */
			/* begin fetchClassOf: */
			if ((t1 & 1)) {
				t2 = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
				goto l178;
			}
			t3 = (((unsigned) (longAt(t1))) >> 12) & 31;
			if (t3 == 0) {
				t2 = (longAt(t1 - 4)) & 4294967292U;
				goto l178;
			} else {
				t2 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t3 - 1) << 2));
				goto l178;
			}
		l178:	/* end fetchClassOf: */;
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
			t9 = (((unsigned) t1) >> 12) & 31;
			t7 = (t9 == 13) || (t9 == 14);
			successFlag = t7 && successFlag;
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
			l181:	/* end fetchClassOf: */;
			l180:	/* end lookupInMethodCacheSel:class: */;
			l183:	/* end internalExecuteNewMethod */;
			}
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
		l179:	/* end case */;
			break;
		case 201:
			/* bytecodePrimValue */
			t1 = longAt(localSP);
			successFlag = 1;
			argumentCount = 0;
			/* begin assertClassOf:is: */
			if ((t1 & 1)) {
				successFlag = 0;
				goto l187;
			}
			t7 = (((unsigned) (longAt(t1))) >> 12) & 31;
			if (t7 == 0) {
				t8 = (longAt(t1 - 4)) & 4294967292U;
			} else {
				t8 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t7 - 1) << 2));
			}
			/* begin success: */
			successFlag = (t8 == (longAt(((((char *) specialObjectsOop)) + 4) + (11 << 2)))) && successFlag;
		l187:	/* end assertClassOf:is: */;
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
			l186:	/* end fetchClassOf: */;
			l185:	/* end lookupInMethodCacheSel:class: */;
			l189:	/* end internalExecuteNewMethod */;
			}
			/* begin fetchNextBytecode */
			currentBytecode = byteAt(++localIP);
		l184:	/* end case */;
			break;
		case 202:
			/* bytecodePrimValueWithArg */
			t1 = longAt(localSP - (1 * 4));
			successFlag = 1;
			argumentCount = 1;
			/* begin assertClassOf:is: */
			if ((t1 & 1)) {
				successFlag = 0;
				goto l193;
			}
			t7 = (((unsigned) (longAt(t1))) >> 12) & 31;
			if (t7 == 0) {
				t8 = (longAt(t1 - 4)) & 4294967292U;
			} else {
				t8 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((t7 - 1) << 2));
			}
			/* begin success: */
			successFlag = (t8 == (longAt(((((char *) specialObjectsOop)) + 4) + (11 << 2)))) && successFlag;
		l193:	/* end assertClassOf:is: */;
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
			l191:	/* end lookupInMethodCacheSel:class: */;
			l195:	/* end internalExecuteNewMethod */;
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
		l197:	/* end fetchClassOf: */;
		l196:	/* end lookupInMethodCacheSel:class: */;
		l199:	/* end internalExecuteNewMethod */;
			break;
		case 204:
			/* bytecodePrimNew */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((28 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l201:	/* end fetchClassOf: */;
		l200:	/* end lookupInMethodCacheSel:class: */;
		l203:	/* end internalExecuteNewMethod */;
			break;
		case 205:
			/* bytecodePrimNewWithArg */
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((29 * 2) << 2));
			argumentCount = 1;
			/* begin normalSend */
			goto commonSend;
		l205:	/* end fetchClassOf: */;
		l204:	/* end lookupInMethodCacheSel:class: */;
		l207:	/* end internalExecuteNewMethod */;
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
				goto l208;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((30 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l210:	/* end fetchClassOf: */;
		l209:	/* end lookupInMethodCacheSel:class: */;
		l212:	/* end internalExecuteNewMethod */;
		l208:	/* end case */;
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
				goto l213;
			}
			messageSelector = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (23 << 2))))) + 4) + ((31 * 2) << 2));
			argumentCount = 0;
			/* begin normalSend */
			goto commonSend;
		l215:	/* end fetchClassOf: */;
		l214:	/* end lookupInMethodCacheSel:class: */;
		l217:	/* end internalExecuteNewMethod */;
		l213:	/* end case */;
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
			/* begin literal: */
			t1 = currentBytecode & 15;
			messageSelector = longAt(((((char *) method)) + 4) + ((t1 + 1) << 2));
			argumentCount = ((((unsigned) currentBytecode) >> 4) & 3) - 1;
			/* begin normalSend */
			goto commonSend;
		l218:	/* end fetchClassOf: */;
		l219:	/* end lookupInMethodCacheSel:class: */;
		l221:	/* end internalExecuteNewMethod */;
			break;
		}
	}
	/* begin externalizeIPandSP */
	instructionPointer = ((int) localIP);
	stackPointer = ((int) localSP);
	theHomeContext = localHomeContext;
}

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

int isBytes(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) >= 8;
}

int isContextHeader(int aHeader) {
    int ccIndex;

	ccIndex = (((unsigned) aHeader) >> 12) & 31;
	return (ccIndex == 13) || (ccIndex == 14);
}

int isEdge(int edge) {
    int type;

	type = (objBuffer[edge + 0]) & 65535;
	if (type > 255) {
		return 0;
	}
	return (((objBuffer[edge + 0]) & 65535) & 255) != 0;
}

int isFillOkay(int fill) {
	return (fill == 0) || (((fill & 4278190080U) != 0) || (((fill >= 0) && (fill < objUsed)) && (((fill & 4278190080U) != 0) || ((((objBuffer[fill + 0]) & 65535) & 65280) != 0))));
}

int isFloatObject(int oop) {
	return (fetchClassOf(oop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)));
}

int isIndexable(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) >= 2;
}

int isIntegerObject(int objectPointer) {
	return (objectPointer & 1) > 0;
}

int isIntegerValue(int intValue) {
	return (intValue ^ (intValue << 1)) >= 0;
}

int isPointers(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) <= 4;
}

int isWeak(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) == 4;
}

int isWords(int oop) {
	return ((((unsigned) (longAt(oop))) >> 8) & 15) == 6;
}

int isWordsOrBytes(int oop) {
    int fmt;

	fmt = (((unsigned) (longAt(oop))) >> 8) & 15;
	return (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
}

int lastPointerOf(int oop) {
    int methodHeader;
    int sz;
    int fmt;
    int header;
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

int loadAndSubdivideBezierFromviatoisWide(int *point1, int *point2, int *point3, int wideFlag) {
    int bz1;
    int bz2;
    int index;
    int index2;
    int index1;

	/* begin allocateBezierStackEntry */
	/* begin wbStackPush: */
	if (!(needAvailableSpace(6))) {
		goto l1;
	}
	workBuffer[10] = ((workBuffer[10]) - 6);
l1:	/* end wbStackPush: */;
	bz1 = (workBuffer[1]) - (workBuffer[10]);
	if (engineStopped) {
		return 0;
	}
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - bz1) + 0)] = (point1[0]);
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - bz1) + 1)] = (point1[1]);
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - bz1) + 2)] = (point2[0]);
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - bz1) + 3)] = (point2[1]);
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - bz1) + 4)] = (point3[0]);
	workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - bz1) + 5)] = (point3[1]);
	index2 = bz2 = subdivideToBeMonotoninX(bz1, wideFlag);
	for (index = bz1; index <= bz2; index += 6) {
		index1 = subdivideBezierFrom(index);
		if (index1 > index2) {
			index2 = index1;
		}
		if (engineStopped) {
			return 0;
		}
	}
	return index2 / 6;
}

int loadArgumentPoint(int point) {
    int oop;
    int isInt;

	if (!successFlag) {
		return null;
	}
	if (!((fetchClassOf(point)) == (longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	oop = longAt(((((char *) point)) + 4) + (0 << 2));
	isInt = (oop & 1);
	if (!(isInt || ((fetchClassOf(oop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (isInt) {
		m23ArgX = (oop >> 1);
	} else {
		m23ArgX = floatValueOf(oop);
	}
	oop = longAt(((((char *) point)) + 4) + (1 << 2));
	isInt = (oop & 1);
	if (!(isInt || ((fetchClassOf(oop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (isInt) {
		m23ArgY = (oop >> 1);
	} else {
		m23ArgY = floatValueOf(oop);
	}
}

int loadArrayShapenSegmentsfilllineWidthlineFill(int points, int nSegments, int fillIndex, int lineWidth, int lineFill) {
    int segs;
    int pointOop;
    int y0;
    int y1;
    int y2;
    int i;
    int x0;
    int x1;
    int x2;

	for (i = 0; i <= (nSegments - 1); i += 1) {
		pointOop = longAt(((((char *) points)) + 4) + ((i * 3) << 2));
		loadPointfrom(((int *) (workBuffer + 80)), pointOop);
		pointOop = longAt(((((char *) points)) + 4) + (((i * 3) + 1) << 2));
		loadPointfrom(((int *) (workBuffer + 82)), pointOop);
		pointOop = longAt(((((char *) points)) + 4) + (((i * 3) + 2) << 2));
		loadPointfrom(((int *) (workBuffer + 84)), pointOop);
		if (!successFlag) {
			return null;
		}
		/* begin transformPoints: */
		if (3 > 0) {
			transformPoint(((int *) (workBuffer + 80)));
		}
		if (3 > 1) {
			transformPoint(((int *) (workBuffer + 82)));
		}
		if (3 > 2) {
			transformPoint(((int *) (workBuffer + 84)));
		}
		if (3 > 3) {
			transformPoint(((int *) (workBuffer + 86)));
		}
		x0 = (((int *) (workBuffer + 80)))[0];
		y0 = (((int *) (workBuffer + 80)))[1];
		x1 = (((int *) (workBuffer + 82)))[0];
		y1 = (((int *) (workBuffer + 82)))[1];
		x2 = (((int *) (workBuffer + 84)))[0];
		y2 = (((int *) (workBuffer + 84)))[1];
		if (((x0 == y0) && (x1 == y1)) || ((x1 == x2) && (y1 == y2))) {
			loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 84)), lineFill, fillIndex, 0);
		} else {
			segs = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), (lineWidth != 0) && (lineFill != 0));
			if (engineStopped) {
				return null;
			}
			loadWideBezierlineFillleftFillrightFilln(lineWidth, lineFill, fillIndex, 0, segs);
		}
		if (engineStopped) {
			return null;
		}
	}
}

int loadArrayTransformFromintolength(int transformOop, float *destPtr, int n) {
    int i;
    int value;

	for (i = 0; i <= (n - 1); i += 1) {
		value = longAt(((((char *) transformOop)) + 4) + (i << 2));
		if (!(((value & 1)) || ((fetchClassOf(value)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		if ((value & 1)) {
			destPtr[i] = (((float) (((double) ((value >> 1)) ))));
		} else {
			destPtr[i] = (((float) (floatValueOf(value))));
		}
	}
}

int loadBeziersegmentleftFillrightFilloffset(int bezier, int index, int leftFillIndex, int rightFillIndex, int yOffset) {
	if ((workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)]) >= (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)])) {
		objBuffer[bezier + 4] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)]);
		objBuffer[bezier + 5] = ((workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)]) - yOffset);
		objBuffer[bezier + 12] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)]);
		objBuffer[bezier + 13] = ((workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)]) - yOffset);
		objBuffer[bezier + 14] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)]);
		objBuffer[bezier + 15] = ((workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)]) - yOffset);
	} else {
		objBuffer[bezier + 4] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)]);
		objBuffer[bezier + 5] = ((workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)]) - yOffset);
		objBuffer[bezier + 12] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)]);
		objBuffer[bezier + 13] = ((workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)]) - yOffset);
		objBuffer[bezier + 14] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)]);
		objBuffer[bezier + 15] = ((workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)]) - yOffset);
	}
	objBuffer[bezier + 6] = (workBuffer[113]);
	objBuffer[bezier + 8] = leftFillIndex;
	objBuffer[bezier + 9] = rightFillIndex;
}

int loadBitBltFrom(int bbObj) {
    int destBitsSize;
    int destWidth;
    int destHeight;
    int sourceBitsSize;
    int sourcePixPerWord;
    int halftoneBits;
    int cmSize;
    int header;
    int sz;
    int header1;
    int sz1;

	bitBltOop = bbObj;
	combinationRule = fetchIntegerofObject(3, bitBltOop);
	if ((!successFlag) || ((combinationRule < 0) || (combinationRule > (36 - 2)))) {
		return 0;
	}
	if ((combinationRule >= 16) && (combinationRule <= 17)) {
		return 0;
	}
	sourceForm = longAt(((((char *) bitBltOop)) + 4) + (1 << 2));
	/* begin ignoreSourceOrHalftone: */
	if (sourceForm == nilObj) {
		noSource = 1;
		goto l3;
	}
	if (combinationRule == 0) {
		noSource = 1;
		goto l3;
	}
	if (combinationRule == 5) {
		noSource = 1;
		goto l3;
	}
	if (combinationRule == 10) {
		noSource = 1;
		goto l3;
	}
	if (combinationRule == 15) {
		noSource = 1;
		goto l3;
	}
	noSource = 0;
l3:	/* end ignoreSourceOrHalftone: */;
	halftoneForm = longAt(((((char *) bitBltOop)) + 4) + (2 << 2));
	/* begin ignoreSourceOrHalftone: */
	if (halftoneForm == nilObj) {
		noHalftone = 1;
		goto l4;
	}
	if (combinationRule == 0) {
		noHalftone = 1;
		goto l4;
	}
	if (combinationRule == 5) {
		noHalftone = 1;
		goto l4;
	}
	if (combinationRule == 10) {
		noHalftone = 1;
		goto l4;
	}
	if (combinationRule == 15) {
		noHalftone = 1;
		goto l4;
	}
	noHalftone = 0;
l4:	/* end ignoreSourceOrHalftone: */;
	destForm = longAt(((((char *) bitBltOop)) + 4) + (0 << 2));
	if (!((((((unsigned) (longAt(destForm))) >> 8) & 15) <= 4) && ((lengthOf(destForm)) >= 4))) {
		return 0;
	}
	destBits = longAt(((((char *) destForm)) + 4) + (0 << 2));
	destBitsSize = byteLengthOf(destBits);
	destWidth = fetchIntegerofObject(1, destForm);
	destHeight = fetchIntegerofObject(2, destForm);
	if (!((destWidth >= 0) && (destHeight >= 0))) {
		return 0;
	}
	destPixSize = fetchIntegerofObject(3, destForm);
	pixPerWord = 32 / destPixSize;
	destRaster = (destWidth + (pixPerWord - 1)) / pixPerWord;
	if (!((isWordsOrBytes(destBits)) && (destBitsSize == ((destRaster * destHeight) * 4)))) {
		return 0;
	}
	destX = fetchIntegerOrTruncFloatofObject(4, bitBltOop);
	destY = fetchIntegerOrTruncFloatofObject(5, bitBltOop);
	width = fetchIntegerOrTruncFloatofObject(6, bitBltOop);
	height = fetchIntegerOrTruncFloatofObject(7, bitBltOop);
	if (!successFlag) {
		return 0;
	}
	if (noSource) {
		sourceX = sourceY = 0;
	} else {
		if (!((((((unsigned) (longAt(sourceForm))) >> 8) & 15) <= 4) && ((lengthOf(sourceForm)) >= 4))) {
			return 0;
		}
		sourceBits = longAt(((((char *) sourceForm)) + 4) + (0 << 2));
		sourceBitsSize = byteLengthOf(sourceBits);
		srcWidth = fetchIntegerOrTruncFloatofObject(1, sourceForm);
		srcHeight = fetchIntegerOrTruncFloatofObject(2, sourceForm);
		if (!((srcWidth >= 0) && (srcHeight >= 0))) {
			return 0;
		}
		sourcePixSize = fetchIntegerofObject(3, sourceForm);
		sourcePixPerWord = 32 / sourcePixSize;
		sourceRaster = (srcWidth + (sourcePixPerWord - 1)) / sourcePixPerWord;
		if (!((isWordsOrBytes(sourceBits)) && (sourceBitsSize == ((sourceRaster * srcHeight) * 4)))) {
			return 0;
		}
		colorMap = longAt(((((char *) bitBltOop)) + 4) + (14 << 2));
		if (!(colorMap == nilObj)) {
			if (((((unsigned) (longAt(colorMap))) >> 8) & 15) == 6) {
				/* begin lengthOf: */
				header = longAt(colorMap);
				/* begin lengthOf:baseHeader:format: */
				if ((header & 3) == 0) {
					sz = (longAt(colorMap - 8)) & 4294967292U;
				} else {
					sz = header & 252;
				}
				if (((((unsigned) header) >> 8) & 15) < 8) {
					cmSize = ((unsigned) (sz - 4)) >> 2;
					goto l1;
				} else {
					cmSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
					goto l1;
				}
				cmSize = null;
			l1:	/* end lengthOf: */;
				cmBitsPerColor = 0;
				if (cmSize == 512) {
					cmBitsPerColor = 3;
				}
				if (cmSize == 4096) {
					cmBitsPerColor = 4;
				}
				if (cmSize == 32768) {
					cmBitsPerColor = 5;
				}
				if (primitiveIndex != 147) {
					if (sourcePixSize <= 8) {
						if (!(cmSize == (1 << sourcePixSize))) {
							return 0;
						}
					} else {
						if (cmBitsPerColor == 0) {
							return 0;
						}
					}
				}
			} else {
				return 0;
			}
		}
		sourceX = fetchIntegerOrTruncFloatofObject(8, bitBltOop);
		sourceY = fetchIntegerOrTruncFloatofObject(9, bitBltOop);
	}
	if (!(noHalftone)) {
		if ((((((unsigned) (longAt(halftoneForm))) >> 8) & 15) <= 4) && ((lengthOf(halftoneForm)) >= 4)) {
			halftoneBits = longAt(((((char *) halftoneForm)) + 4) + (0 << 2));
			halftoneHeight = fetchIntegerofObject(2, halftoneForm);
			if (!(((((unsigned) (longAt(halftoneBits))) >> 8) & 15) == 6)) {
				noHalftone = 1;
			}
		} else {
			if (!((!(((((unsigned) (longAt(halftoneForm))) >> 8) & 15) <= 4)) && (((((unsigned) (longAt(halftoneForm))) >> 8) & 15) == 6))) {
				return 0;
			}
			halftoneBits = halftoneForm;
			/* begin lengthOf: */
			header1 = longAt(halftoneBits);
			/* begin lengthOf:baseHeader:format: */
			if ((header1 & 3) == 0) {
				sz1 = (longAt(halftoneBits - 8)) & 4294967292U;
			} else {
				sz1 = header1 & 252;
			}
			if (((((unsigned) header1) >> 8) & 15) < 8) {
				halftoneHeight = ((unsigned) (sz1 - 4)) >> 2;
				goto l2;
			} else {
				halftoneHeight = (sz1 - 4) - (((((unsigned) header1) >> 8) & 15) & 3);
				goto l2;
			}
			halftoneHeight = null;
		l2:	/* end lengthOf: */;
		}
		halftoneBase = halftoneBits + 4;
	}
	clipX = fetchIntegerOrTruncFloatofObject(10, bitBltOop);
	clipY = fetchIntegerOrTruncFloatofObject(11, bitBltOop);
	clipWidth = fetchIntegerOrTruncFloatofObject(12, bitBltOop);
	clipHeight = fetchIntegerOrTruncFloatofObject(13, bitBltOop);
	if (!successFlag) {
		return 0;
	}
	if (clipX < 0) {
		clipWidth += clipX;
		clipX = 0;
	}
	if (clipY < 0) {
		clipHeight += clipY;
		clipY = 0;
	}
	if ((clipX + clipWidth) > destWidth) {
		clipWidth = destWidth - clipX;
	}
	if ((clipY + clipHeight) > destHeight) {
		clipHeight = destHeight - clipY;
	}
	return 1;
}

int loadBitmapFillcolormaptilefromalongnormalxIndex(int formOop, int cmOop, int tileFlag, int *point1, int *point2, int *point3, int xIndex) {
    int bmBits;
    int bmWidth;
    int bmDepth;
    int bmBitsSize;
    int ppw;
    int *cmBits;
    int cmSize;
    int bmRaster;
    int bmHeight;
    int bmFill;
    int header;
    int header1;
    int sz;
    int sz1;

	if (cmOop == nilObj) {
		cmSize = 0;
		cmBits = null;
	} else {
		if (!((fetchClassOf(cmOop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2))))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		/* begin slotSizeOf: */
		if ((cmOop & 1)) {
			cmSize = 0;
			goto l1;
		}
		/* begin lengthOf: */
		header = longAt(cmOop);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(cmOop - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			cmSize = ((unsigned) (sz - 4)) >> 2;
			goto l3;
		} else {
			cmSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l3;
		}
	l3:	/* end lengthOf:baseHeader:format: */;
	l1:	/* end slotSizeOf: */;
		cmBits = firstIndexableField(cmOop);
	}
	if ((formOop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((unsigned) (longAt(formOop))) >> 8) & 15) <= 4)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((slotSizeOf(formOop)) < 5) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	bmBits = longAt(((((char *) formOop)) + 4) + (0 << 2));
	if (!((fetchClassOf(bmBits)) == (longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin slotSizeOf: */
	if ((bmBits & 1)) {
		bmBitsSize = 0;
		goto l2;
	}
	/* begin lengthOf: */
	header1 = longAt(bmBits);
	/* begin lengthOf:baseHeader:format: */
	if ((header1 & 3) == 0) {
		sz1 = (longAt(bmBits - 8)) & 4294967292U;
	} else {
		sz1 = header1 & 252;
	}
	if (((((unsigned) header1) >> 8) & 15) < 8) {
		bmBitsSize = ((unsigned) (sz1 - 4)) >> 2;
		goto l4;
	} else {
		bmBitsSize = (sz1 - 4) - (((((unsigned) header1) >> 8) & 15) & 3);
		goto l4;
	}
l4:	/* end lengthOf:baseHeader:format: */;
l2:	/* end slotSizeOf: */;
	bmWidth = fetchIntegerofObject(1, formOop);
	bmHeight = fetchIntegerofObject(2, formOop);
	bmDepth = fetchIntegerofObject(3, formOop);
	if (!successFlag) {
		return null;
	}
	if (!((bmWidth >= 0) && (bmHeight >= 0))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((((((bmDepth == 32) || (bmDepth == 8)) || (bmDepth == 16)) || (bmDepth == 1)) || (bmDepth == 2)) || (bmDepth == 4))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((cmSize == 0) || (cmSize == (1 << bmDepth)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	ppw = 32 / bmDepth;
	bmRaster = (bmWidth + (ppw - 1)) / ppw;
	if (!(bmBitsSize == (bmRaster * bmHeight))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	bmFill = allocateBitmapFillcolormap(cmSize, cmBits);
	if (engineStopped) {
		return null;
	}
	objBuffer[bmFill + 10] = bmWidth;
	objBuffer[bmFill + 11] = bmHeight;
	objBuffer[bmFill + 12] = bmDepth;
	objBuffer[bmFill + 14] = bmRaster;
	objBuffer[bmFill + 13] = bmBitsSize;
	objBuffer[bmFill + 16] = tileFlag;
	objBuffer[bmFill + 2] = xIndex;
	loadFillOrientationfromalongnormalwidthheight(bmFill, point1, point2, point3, bmWidth, bmHeight);
	return bmFill;
}

int * loadBitsFrom(int bmFill) {
    int xIndex;
    int bitsOop;
    int formOop;
    int bitsLen;
    int header;
    int sz;

	xIndex = objBuffer[bmFill + 2];
	if (xIndex > (slotSizeOf(formArray))) {
		return null;
	}
	formOop = longAt(((((char *) formArray)) + 4) + (xIndex << 2));
	bitsOop = longAt(((((char *) formOop)) + 4) + (0 << 2));
	/* begin slotSizeOf: */
	if ((bitsOop & 1)) {
		bitsLen = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(bitsOop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(bitsOop - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		bitsLen = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		bitsLen = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
l1:	/* end slotSizeOf: */;
	if (!(bitsLen == (objBuffer[bmFill + 13]))) {
		return null;
	}
	return firstIndexableField(bitsOop);
}

int loadColorTransformFrom(int transformOop) {
    float *transform;
    int okay;

	transform = ((float *) (workBuffer + 24));
	workBuffer[17] = 0;
	okay = loadTransformFromintolength(transformOop, transform, 8);
	if (!(okay)) {
		return 0;
	}
	workBuffer[17] = 1;
	transform[1] = ((transform[1]) * (((float) 256.0)));
	transform[3] = ((transform[3]) * (((float) 256.0)));
	transform[5] = ((transform[5]) * (((float) 256.0)));
	transform[7] = ((transform[7]) * (((float) 256.0)));
	return okay;
}

int loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(int *points, int nSegments, int *leftFills, int *rightFills, int *lineWidths, int *lineFills, int *fillIndexList, int pointsShort) {
    int widthRun;
    int widthLength;
    int widthValue;
    int i;
    int leftRun;
    int rightRun;
    int leftLength;
    int rightLength;
    int lineFillRun;
    int lineFillLength;
    int leftValue;
    int rightValue;
    int lineFillValue;
    int segs;
    int y0;
    int y1;
    int y2;
    int index;
    int x0;
    int x1;
    int x2;

	if (nSegments == 0) {
		return 0;
	}
	leftRun = rightRun = widthRun = lineFillRun = -1;
	leftLength = rightLength = widthLength = lineFillLength = 1;
	leftValue = rightValue = widthValue = lineFillValue = 0;
	for (i = 1; i <= nSegments; i += 1) {
		if ((leftLength -= 1) <= 0) {
			leftRun += 1;
			leftLength = ((unsigned) ((((int *) leftFills))[leftRun]) >> 16);
			leftValue = ((((int *) leftFills))[leftRun]) & 65535;
			if (!(leftValue == 0)) {
				leftValue = fillIndexList[leftValue - 1];
				leftValue = transformColor(leftValue);
				if (engineStopped) {
					return null;
				}
			}
		}
		if ((rightLength -= 1) <= 0) {
			rightRun += 1;
			rightLength = ((unsigned) ((((int *) rightFills))[rightRun]) >> 16);
			rightValue = ((((int *) rightFills))[rightRun]) & 65535;
			if (!(rightValue == 0)) {
				rightValue = fillIndexList[rightValue - 1];
				rightValue = transformColor(rightValue);
			}
		}
		if ((widthLength -= 1) <= 0) {
			widthRun += 1;
			widthLength = ((unsigned) ((((int *) lineWidths))[widthRun]) >> 16);
			widthValue = ((((int *) lineWidths))[widthRun]) & 65535;
			if (!(widthValue == 0)) {
				widthValue = transformWidth(widthValue);
			}
		}
		if ((lineFillLength -= 1) <= 0) {
			lineFillRun += 1;
			lineFillLength = ((unsigned) ((((int *) lineFills))[lineFillRun]) >> 16);
			lineFillValue = ((((int *) lineFills))[lineFillRun]) & 65535;
			if (!(lineFillValue == 0)) {
				lineFillValue = fillIndexList[lineFillValue - 1];
			}
		}
		/* begin loadCompressedSegment:from:short:leftFill:rightFill:lineWidth:lineColor: */
		if ((leftValue == rightValue) && ((widthValue == 0) || (lineFillValue == 0))) {
			goto l1;
		}
		index = (i - 1) * 6;
		if (pointsShort) {
			x0 = (((short *) points))[index + 0];
			y0 = (((short *) points))[index + 1];
			x1 = (((short *) points))[index + 2];
			y1 = (((short *) points))[index + 3];
			x2 = (((short *) points))[index + 4];
			y2 = (((short *) points))[index + 5];
		} else {
			x0 = (((int *) points))[index + 0];
			y0 = (((int *) points))[index + 1];
			x1 = (((int *) points))[index + 2];
			y1 = (((int *) points))[index + 3];
			x2 = (((int *) points))[index + 4];
			y2 = (((int *) points))[index + 5];
		}
		if (((x0 == x1) && (y0 == y1)) || ((x1 == x2) && (y1 == y2))) {
			if ((x0 == x2) && (y0 == y2)) {
				goto l1;
			}
			(((int *) (workBuffer + 80)))[0] = x0;
			(((int *) (workBuffer + 80)))[1] = y0;
			(((int *) (workBuffer + 82)))[0] = x2;
			(((int *) (workBuffer + 82)))[1] = y2;
			/* begin transformPoints: */
			if (2 > 0) {
				transformPoint(((int *) (workBuffer + 80)));
			}
			if (2 > 1) {
				transformPoint(((int *) (workBuffer + 82)));
			}
			if (2 > 2) {
				transformPoint(((int *) (workBuffer + 84)));
			}
			if (2 > 3) {
				transformPoint(((int *) (workBuffer + 86)));
			}
			loadWideLinefromtolineFillleftFillrightFill(widthValue, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), lineFillValue, leftValue, rightValue);
			goto l1;
		}
		(((int *) (workBuffer + 80)))[0] = x0;
		(((int *) (workBuffer + 80)))[1] = y0;
		(((int *) (workBuffer + 82)))[0] = x1;
		(((int *) (workBuffer + 82)))[1] = y1;
		(((int *) (workBuffer + 84)))[0] = x2;
		(((int *) (workBuffer + 84)))[1] = y2;
		/* begin transformPoints: */
		if (3 > 0) {
			transformPoint(((int *) (workBuffer + 80)));
		}
		if (3 > 1) {
			transformPoint(((int *) (workBuffer + 82)));
		}
		if (3 > 2) {
			transformPoint(((int *) (workBuffer + 84)));
		}
		if (3 > 3) {
			transformPoint(((int *) (workBuffer + 86)));
		}
		segs = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), (widthValue != 0) && (lineFillValue != 0));
		if (engineStopped) {
			goto l1;
		}
		loadWideBezierlineFillleftFillrightFilln(widthValue, lineFillValue, leftValue, rightValue, segs);
	l1:	/* end loadCompressedSegment:from:short:leftFill:rightFill:lineWidth:lineColor: */;
		if (engineStopped) {
			return null;
		}
	}
}

int loadEdgeStateFrom(int edgeOop) {
    int edge;
    int value;
    int value1;
    int value2;
    int value3;

	edge = workBuffer[65];
	if ((slotSizeOf(edgeOop)) < 6) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin edgeXValueOf:put: */
	value2 = fetchIntegerofObject(1, edgeOop);
	objBuffer[edge + 4] = value2;
	/* begin edgeYValueOf:put: */
	value = fetchIntegerofObject(2, edgeOop);
	objBuffer[edge + 5] = value;
	/* begin edgeZValueOf:put: */
	value3 = fetchIntegerofObject(3, edgeOop);
	objBuffer[edge + 6] = value3;
	/* begin edgeNumLinesOf:put: */
	value1 = fetchIntegerofObject(4, edgeOop);
	objBuffer[edge + 7] = value1;
	return edge;
}

int loadEdgeTransformFrom(int transformOop) {
    float *transform;
    int okay;

	workBuffer[16] = 0;
	transform = ((float *) (workBuffer + 18));
	okay = loadTransformFromintolength(transformOop, transform, 6);
	if (!successFlag) {
		return null;
	}
	if (!(okay)) {
		return 0;
	}
	workBuffer[16] = 1;
	transform[2] = (((float) ((transform[2]) + (((double) (workBuffer[46]) )))));
	transform[5] = (((float) ((transform[5]) + (((double) (workBuffer[47]) )))));
	return 1;
}

int loadFFTFrom(int fftOop) {
    int oop;
    int successValue;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;
    int hdr1;
    int totalLength1;
    int fmt1;
    int fixedFields1;
    int sp1;
    int classFormat1;
    int class1;
    int sz1;
    int ccIndex1;
    int hdr2;
    int totalLength2;
    int fmt2;
    int fixedFields2;
    int sp2;
    int classFormat2;
    int class2;
    int sz2;
    int ccIndex2;
    int hdr3;
    int totalLength3;
    int fmt3;
    int fixedFields3;
    int sp3;
    int classFormat3;
    int class3;
    int sz3;
    int ccIndex3;

	/* begin success: */
	successValue = (slotSizeOf(fftOop)) >= 6;
	successFlag = successValue && successFlag;
	if (!successFlag) {
		return 0;
	}
	nu = fetchIntegerofObject(0, fftOop);
	fftSize = fetchIntegerofObject(1, fftOop);
	oop = longAt(((((char *) fftOop)) + 4) + (2 << 2));
	/* begin stSizeOf: */
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
		goto l2;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l1;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l1;
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
l1:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) oop)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			sinTableSize = 0;
			goto l4;
		}
		sinTableSize = (sp >> 1);
		goto l4;
	} else {
		sinTableSize = totalLength - fixedFields;
		goto l4;
	}
l4:	/* end stSizeOf: */;
	/* begin checkedFloatPtrOf: */
	/* begin success: */
	successFlag = (((((unsigned) (longAt(oop))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		sinTable = 0;
		goto l5;
	}
	sinTable = ((float *) (firstIndexableField(oop)));
l5:	/* end checkedFloatPtrOf: */;
	oop = longAt(((((char *) fftOop)) + 4) + (3 << 2));
	/* begin stSizeOf: */
	hdr1 = longAt(oop);
	fmt1 = (((unsigned) hdr1) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr1 & 3) == 0) {
		sz1 = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz1 = hdr1 & 252;
	}
	if (fmt1 < 8) {
		totalLength1 = ((unsigned) (sz1 - 4)) >> 2;
		goto l7;
	} else {
		totalLength1 = (sz1 - 4) - (fmt1 & 3);
		goto l7;
	}
l7:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt1 > 4) || (fmt1 == 2)) {
		fixedFields1 = 0;
		goto l6;
	}
	if (fmt1 < 2) {
		fixedFields1 = totalLength1;
		goto l6;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class1 = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l8;
	}
	ccIndex1 = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex1 == 0) {
		class1 = (longAt(oop - 4)) & 4294967292U;
		goto l8;
	} else {
		class1 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
		goto l8;
	}
l8:	/* end fetchClassOf: */;
	classFormat1 = (longAt(((((char *) class1)) + 4) + (2 << 2))) - 1;
	fixedFields1 = (((((unsigned) classFormat1) >> 11) & 192) + ((((unsigned) classFormat1) >> 2) & 63)) - 1;
l6:	/* end fixedFieldsOf:format:length: */;
	if ((fmt1 == 3) && (isContextHeader(hdr1))) {
		/* begin fetchStackPointerOf: */
		sp1 = longAt(((((char *) oop)) + 4) + (2 << 2));
		if (!((sp1 & 1))) {
			permTableSize = 0;
			goto l9;
		}
		permTableSize = (sp1 >> 1);
		goto l9;
	} else {
		permTableSize = totalLength1 - fixedFields1;
		goto l9;
	}
l9:	/* end stSizeOf: */;
	/* begin checkedWordPtrOf: */
	/* begin success: */
	successFlag = (((((unsigned) (longAt(oop))) >> 8) & 15) == 6) && successFlag;
	permTable = ((unsigned int *) (firstIndexableField(oop)));
	oop = longAt(((((char *) fftOop)) + 4) + (4 << 2));
	/* begin stSizeOf: */
	hdr2 = longAt(oop);
	fmt2 = (((unsigned) hdr2) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr2 & 3) == 0) {
		sz2 = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz2 = hdr2 & 252;
	}
	if (fmt2 < 8) {
		totalLength2 = ((unsigned) (sz2 - 4)) >> 2;
		goto l11;
	} else {
		totalLength2 = (sz2 - 4) - (fmt2 & 3);
		goto l11;
	}
l11:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt2 > 4) || (fmt2 == 2)) {
		fixedFields2 = 0;
		goto l10;
	}
	if (fmt2 < 2) {
		fixedFields2 = totalLength2;
		goto l10;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class2 = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l12;
	}
	ccIndex2 = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex2 == 0) {
		class2 = (longAt(oop - 4)) & 4294967292U;
		goto l12;
	} else {
		class2 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex2 - 1) << 2));
		goto l12;
	}
l12:	/* end fetchClassOf: */;
	classFormat2 = (longAt(((((char *) class2)) + 4) + (2 << 2))) - 1;
	fixedFields2 = (((((unsigned) classFormat2) >> 11) & 192) + ((((unsigned) classFormat2) >> 2) & 63)) - 1;
l10:	/* end fixedFieldsOf:format:length: */;
	if ((fmt2 == 3) && (isContextHeader(hdr2))) {
		/* begin fetchStackPointerOf: */
		sp2 = longAt(((((char *) oop)) + 4) + (2 << 2));
		if (!((sp2 & 1))) {
			realDataSize = 0;
			goto l13;
		}
		realDataSize = (sp2 >> 1);
		goto l13;
	} else {
		realDataSize = totalLength2 - fixedFields2;
		goto l13;
	}
l13:	/* end stSizeOf: */;
	/* begin checkedFloatPtrOf: */
	/* begin success: */
	successFlag = (((((unsigned) (longAt(oop))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		realData = 0;
		goto l14;
	}
	realData = ((float *) (firstIndexableField(oop)));
l14:	/* end checkedFloatPtrOf: */;
	oop = longAt(((((char *) fftOop)) + 4) + (5 << 2));
	/* begin stSizeOf: */
	hdr3 = longAt(oop);
	fmt3 = (((unsigned) hdr3) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr3 & 3) == 0) {
		sz3 = (longAt(oop - 8)) & 4294967292U;
	} else {
		sz3 = hdr3 & 252;
	}
	if (fmt3 < 8) {
		totalLength3 = ((unsigned) (sz3 - 4)) >> 2;
		goto l16;
	} else {
		totalLength3 = (sz3 - 4) - (fmt3 & 3);
		goto l16;
	}
l16:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt3 > 4) || (fmt3 == 2)) {
		fixedFields3 = 0;
		goto l15;
	}
	if (fmt3 < 2) {
		fixedFields3 = totalLength3;
		goto l15;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class3 = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l17;
	}
	ccIndex3 = (((unsigned) (longAt(oop))) >> 12) & 31;
	if (ccIndex3 == 0) {
		class3 = (longAt(oop - 4)) & 4294967292U;
		goto l17;
	} else {
		class3 = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex3 - 1) << 2));
		goto l17;
	}
l17:	/* end fetchClassOf: */;
	classFormat3 = (longAt(((((char *) class3)) + 4) + (2 << 2))) - 1;
	fixedFields3 = (((((unsigned) classFormat3) >> 11) & 192) + ((((unsigned) classFormat3) >> 2) & 63)) - 1;
l15:	/* end fixedFieldsOf:format:length: */;
	if ((fmt3 == 3) && (isContextHeader(hdr3))) {
		/* begin fetchStackPointerOf: */
		sp3 = longAt(((((char *) oop)) + 4) + (2 << 2));
		if (!((sp3 & 1))) {
			imagDataSize = 0;
			goto l18;
		}
		imagDataSize = (sp3 >> 1);
		goto l18;
	} else {
		imagDataSize = totalLength3 - fixedFields3;
		goto l18;
	}
l18:	/* end stSizeOf: */;
	/* begin checkedFloatPtrOf: */
	/* begin success: */
	successFlag = (((((unsigned) (longAt(oop))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		imagData = 0;
		goto l19;
	}
	imagData = ((float *) (firstIndexableField(oop)));
l19:	/* end checkedFloatPtrOf: */;
	/* begin success: */
	successFlag = ((((((1 << nu) == fftSize) && (((((int) fftSize >> 2)) + 1) == sinTableSize)) && (fftSize == realDataSize)) && (fftSize == imagDataSize)) && (realDataSize == imagDataSize)) && successFlag;
	return (!successFlag) == 0;
}

int loadFillOrientationfromalongnormalwidthheight(int fill, int *point1, int *point2, int *point3, int fillWidth, int fillHeight) {
    int dsLength2;
    int dtLength2;
    int dirX;
    int dirY;
    int dsX;
    int dsY;
    int dtX;
    int dtY;
    int nrmX;
    int nrmY;

	point2[0] = ((point2[0]) + (point1[0]));
	point2[1] = ((point2[1]) + (point1[1]));
	point3[0] = ((point3[0]) + (point1[0]));
	point3[1] = ((point3[1]) + (point1[1]));
	transformPoint(point1);
	transformPoint(point2);
	transformPoint(point3);
	dirX = (point2[0]) - (point1[0]);
	dirY = (point2[1]) - (point1[1]);
	nrmX = (point3[0]) - (point1[0]);
	nrmY = (point3[1]) - (point1[1]);
	dsLength2 = (dirX * dirX) + (dirY * dirY);
	if (dsLength2 > 0) {
		dsX = ((int) ((((((double) dirX )) * (((double) fillWidth ))) * 65536.0) / (((double) dsLength2 ))) );
		dsY = ((int) ((((((double) dirY )) * (((double) fillWidth ))) * 65536.0) / (((double) dsLength2 ))) );
	} else {
		dsX = 0;
		dsY = 0;
	}
	dtLength2 = (nrmX * nrmX) + (nrmY * nrmY);
	if (dtLength2 > 0) {
		dtX = ((int) ((((((double) nrmX )) * (((double) fillHeight ))) * 65536.0) / (((double) dtLength2 ))) );
		dtY = ((int) ((((((double) nrmY )) * (((double) fillHeight ))) * 65536.0) / (((double) dtLength2 ))) );
	} else {
		dtX = 0;
		dtY = 0;
	}
	objBuffer[fill + 4] = (point1[0]);
	objBuffer[fill + 5] = (point1[1]);
	objBuffer[fill + 6] = dsX;
	objBuffer[fill + 7] = dsY;
	objBuffer[fill + 8] = dtX;
	objBuffer[fill + 9] = dtY;
}

double loadFloatOrIntFrom(int floatOrInt) {
	if ((floatOrInt & 1)) {
		return ((double) (floatOrInt >> 1));
	}
	if ((fetchClassOfNonInt(floatOrInt)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))) {
		return floatValueOf(floatOrInt);
	}
	successFlag = 0;
}

int loadFormsFrom(int arrayOop) {
    int bmBits;
    int bmWidth;
    int bmDepth;
    int bmBitsSize;
    int ppw;
    int i;
    int formOop;
    int bmRaster;
    int bmHeight;
    int header;
    int sz;

	if (!((fetchClassOf(arrayOop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2))))) {
		return 0;
	}
	formArray = arrayOop;
	for (i = 0; i <= ((slotSizeOf(formArray)) - 1); i += 1) {
		formOop = longAt(((((char *) formArray)) + 4) + (i << 2));
		if ((formOop & 1)) {
			return 0;
		}
		if (!(((((unsigned) (longAt(formOop))) >> 8) & 15) <= 4)) {
			return 0;
		}
		if ((slotSizeOf(formOop)) < 5) {
			return 0;
		}
		bmBits = longAt(((((char *) formOop)) + 4) + (0 << 2));
		if (!((fetchClassOf(bmBits)) == (longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2))))) {
			return 0;
		}
		/* begin slotSizeOf: */
		if ((bmBits & 1)) {
			bmBitsSize = 0;
			goto l1;
		}
		/* begin lengthOf: */
		header = longAt(bmBits);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(bmBits - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			bmBitsSize = ((unsigned) (sz - 4)) >> 2;
			goto l2;
		} else {
			bmBitsSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l2;
		}
	l2:	/* end lengthOf:baseHeader:format: */;
	l1:	/* end slotSizeOf: */;
		bmWidth = fetchIntegerofObject(1, formOop);
		bmHeight = fetchIntegerofObject(2, formOop);
		bmDepth = fetchIntegerofObject(3, formOop);
		if (!successFlag) {
			return 0;
		}
		if (!((bmWidth >= 0) && (bmHeight >= 0))) {
			return 0;
		}
		ppw = 32 / bmDepth;
		bmRaster = (bmWidth + (ppw - 1)) / ppw;
		if (!(bmBitsSize == (bmRaster * bmHeight))) {
			return 0;
		}
	}
	return 1;
}

int loadGradientFillfromalongnormalisRadial(int rampOop, int *point1, int *point2, int *point3, int isRadial) {
    int fill;
    int rampWidth;
    int header;
    int sz;

	if (!((fetchClassOf(rampOop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin slotSizeOf: */
	if ((rampOop & 1)) {
		rampWidth = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(rampOop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(rampOop - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		rampWidth = ((unsigned) (sz - 4)) >> 2;
		goto l2;
	} else {
		rampWidth = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
l1:	/* end slotSizeOf: */;
	fill = allocateGradientFillrampWidthisRadial(firstIndexableField(rampOop), rampWidth, isRadial);
	if (engineStopped) {
		return null;
	}
	loadFillOrientationfromalongnormalwidthheight(fill, point1, point2, point3, rampWidth, rampWidth);
	return fill;
}

int loadLinefromtooffsetleftFillrightFill(int line, int *point1, int *point2, int yOffset, int leftFill, int rightFill) {
    int yDir;
    int *p2;
    int *p1;

	if ((point1[1]) <= (point2[1])) {
		p1 = point1;
		p2 = point2;
		yDir = 1;
	} else {
		p1 = point2;
		p2 = point1;
		yDir = -1;
	}
	objBuffer[line + 4] = (p1[0]);
	objBuffer[line + 5] = ((p1[1]) - yOffset);
	objBuffer[line + 6] = (workBuffer[113]);
	objBuffer[line + 8] = leftFill;
	objBuffer[line + 9] = rightFill;
	objBuffer[line + 14] = (p2[0]);
	objBuffer[line + 15] = ((p2[1]) - yOffset);
	objBuffer[line + 11] = yDir;
}

int loadOvallineFillleftFillrightFill(int lineWidth, int lineFill, int leftFill, int rightFill) {
    int nSegments;
    int h;
    int w;
    int i;
    int cx;
    int cy;

	w = ((int) (((((int *) (workBuffer + 82)))[0]) - ((((int *) (workBuffer + 80)))[0])) >> 1);
	h = ((int) (((((int *) (workBuffer + 82)))[1]) - ((((int *) (workBuffer + 80)))[1])) >> 1);
	cx = ((int) (((((int *) (workBuffer + 82)))[0]) + ((((int *) (workBuffer + 80)))[0])) >> 1);
	cy = ((int) (((((int *) (workBuffer + 82)))[1]) + ((((int *) (workBuffer + 80)))[1])) >> 1);
	for (i = 0; i <= 15; i += 1) {
		loadOvalSegmentwhcxcy(i, w, h, cx, cy);
		/* begin transformPoints: */
		if (3 > 0) {
			transformPoint(((int *) (workBuffer + 80)));
		}
		if (3 > 1) {
			transformPoint(((int *) (workBuffer + 82)));
		}
		if (3 > 2) {
			transformPoint(((int *) (workBuffer + 84)));
		}
		if (3 > 3) {
			transformPoint(((int *) (workBuffer + 86)));
		}
		nSegments = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), (lineWidth != 0) && (lineFill != 0));
		if (engineStopped) {
			return null;
		}
		loadWideBezierlineFillleftFillrightFilln(lineWidth, lineFill, leftFill, rightFill, nSegments);
		if (engineStopped) {
			return null;
		}
	}
}

int loadOvalSegmentwhcxcy(int seg, int w, int h, int cx, int cy) {
    int y0;
    int y2;
    int y1;
    int x0;
    int x2;
    int x1;

	x0 = ((int) ((((circleCosTable())[(seg * 2) + 0]) * (((double) w ))) + cx) );
	y0 = ((int) ((((circleSinTable())[(seg * 2) + 0]) * (((double) h ))) + cy) );
	(((int *) (workBuffer + 80)))[0] = x0;
	(((int *) (workBuffer + 80)))[1] = y0;
	x2 = ((int) ((((circleCosTable())[(seg * 2) + 2]) * (((double) w ))) + cx) );
	y2 = ((int) ((((circleSinTable())[(seg * 2) + 2]) * (((double) h ))) + cy) );
	(((int *) (workBuffer + 84)))[0] = x2;
	(((int *) (workBuffer + 84)))[1] = y2;
	x1 = ((int) ((((circleCosTable())[(seg * 2) + 1]) * (((double) w ))) + cx) );
	y1 = ((int) ((((circleSinTable())[(seg * 2) + 1]) * (((double) h ))) + cy) );
	x1 = (x1 * 2) - (((int) (x0 + x2) >> 1));
	y1 = (y1 * 2) - (((int) (y0 + y2) >> 1));
	(((int *) (workBuffer + 82)))[0] = x1;
	(((int *) (workBuffer + 82)))[1] = y1;
}

int loadPointfrom(int *pointArray, int pointOop) {
    int value;

	if (!((fetchClassOf(pointOop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = longAt(((((char *) pointOop)) + 4) + (0 << 2));
	if (!(((value & 1)) || ((fetchClassOf(value)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((value & 1)) {
		pointArray[0] = ((value >> 1));
	} else {
		pointArray[0] = (((int) (floatValueOf(value)) ));
	}
	value = longAt(((((char *) pointOop)) + 4) + (1 << 2));
	if (!(((value & 1)) || ((fetchClassOf(value)) == (longAt(((((char *) specialObjectsOop)) + 4) + (9 << 2)))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((value & 1)) {
		pointArray[1] = ((value >> 1));
	} else {
		pointArray[1] = (((int) (floatValueOf(value)) ));
	}
}

int loadPolygonnPointsfilllineWidthlineFillpointsShort(int *points, int nPoints, int fillIndex, int lineWidth, int lineFill, int isShort) {
    int y0;
    int y1;
    int i;
    int x0;
    int x1;

	if (isShort) {
		x0 = (((short *) points))[0];
		y0 = (((short *) points))[1];
	} else {
		x0 = (((int *) points))[0];
		y0 = (((int *) points))[1];
	}
	for (i = 1; i <= (nPoints - 1); i += 1) {
		if (isShort) {
			x1 = (((short *) points))[i * 2];
			y1 = (((short *) points))[(i * 2) + 1];
		} else {
			x1 = (((int *) points))[i * 2];
			y1 = (((int *) points))[(i * 2) + 1];
		}
		(((int *) (workBuffer + 80)))[0] = x0;
		(((int *) (workBuffer + 80)))[1] = y0;
		(((int *) (workBuffer + 82)))[0] = x1;
		(((int *) (workBuffer + 82)))[1] = y1;
		/* begin transformPoints: */
		if (2 > 0) {
			transformPoint(((int *) (workBuffer + 80)));
		}
		if (2 > 1) {
			transformPoint(((int *) (workBuffer + 82)));
		}
		if (2 > 2) {
			transformPoint(((int *) (workBuffer + 84)));
		}
		if (2 > 3) {
			transformPoint(((int *) (workBuffer + 86)));
		}
		loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), lineFill, fillIndex, 0);
		if (engineStopped) {
			return null;
		}
		x0 = x1;
		y0 = y1;
	}
}

int loadRenderingState(void) {
    int edgeOop;
    int fillOop;
    int state;
    int oop;
    int oop1;
    int oop2;

	if (!(argumentCount == 2)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		fillOop = null;
		goto l1;
	}
	fillOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		edgeOop = null;
		goto l2;
	}
	edgeOop = oop1;
l2:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (2 * 4));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		engine = null;
		goto l3;
	}
	engine = oop2;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		return 0;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return 0;
	}
	if (!(loadSpanBufferFrom(longAt(((((char *) engine)) + 4) + (1 << 2))))) {
		return 0;
	}
	if (!(loadBitBltFrom(longAt(((((char *) engine)) + 4) + (2 << 2))))) {
		return 0;
	}
	if (!(loadFormsFrom(longAt(((((char *) engine)) + 4) + (3 << 2))))) {
		return 0;
	}
	if ((slotSizeOf(edgeOop)) < 6) {
		return 0;
	}
	if ((slotSizeOf(fillOop)) < 6) {
		return 0;
	}
	state = workBuffer[2];
	if ((state == 2) || ((state == 4) || (state == 7))) {
		return 0;
	}
	return 1;
}

int loadScannerFromstartstopstringrightXstopArraydisplayFlag(int bbObj, int start, int stop, int string, int rightX, int stopArray, int displayFlag) {
    int successValue;
    int successValue1;
    int successValue2;

	scanStart = start;
	scanStop = stop;
	scanString = string;
	scanRightX = rightX;
	scanStopArray = stopArray;
	scanDisplayFlag = displayFlag;
	/* begin success: */
	successValue1 = (((((unsigned) (longAt(scanStopArray))) >> 8) & 15) <= 4) && ((lengthOf(scanStopArray)) >= 1);
	successFlag = successValue1 && successFlag;
	scanXTable = longAt(((((char *) bbObj)) + 4) + (16 << 2));
	/* begin success: */
	successValue2 = (((((unsigned) (longAt(scanXTable))) >> 8) & 15) <= 4) && ((lengthOf(scanXTable)) >= 1);
	successFlag = successValue2 && successFlag;
	/* begin storeInteger:ofObject:withValue: */
	if ((0 ^ (0 << 1)) >= 0) {
		longAtput(((((char *) bbObj)) + 4) + (6 << 2), ((0 << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if ((0 ^ (0 << 1)) >= 0) {
		longAtput(((((char *) bbObj)) + 4) + (8 << 2), ((0 << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (scanDisplayFlag) {
		/* begin success: */
		successValue = loadBitBltFrom(bbObj);
		successFlag = successValue && successFlag;
	} else {
		bitBltOop = bbObj;
		destX = fetchIntegerOrTruncFloatofObject(4, bbObj);
	}
	return !(!successFlag);
}

int loadShapenSegmentsfilllineWidthlineFillpointsShort(int *points, int nSegments, int fillIndex, int lineWidth, int lineFill, int pointsShort) {
    int i;
    int segs;
    int y0;
    int y1;
    int y2;
    int index;
    int x0;
    int x1;
    int x2;

	for (i = 1; i <= nSegments; i += 1) {
		/* begin loadCompressedSegment:from:short:leftFill:rightFill:lineWidth:lineColor: */
		if ((fillIndex == 0) && ((lineWidth == 0) || (lineFill == 0))) {
			goto l1;
		}
		index = (i - 1) * 6;
		if (pointsShort) {
			x0 = (((short *) points))[index + 0];
			y0 = (((short *) points))[index + 1];
			x1 = (((short *) points))[index + 2];
			y1 = (((short *) points))[index + 3];
			x2 = (((short *) points))[index + 4];
			y2 = (((short *) points))[index + 5];
		} else {
			x0 = (((int *) points))[index + 0];
			y0 = (((int *) points))[index + 1];
			x1 = (((int *) points))[index + 2];
			y1 = (((int *) points))[index + 3];
			x2 = (((int *) points))[index + 4];
			y2 = (((int *) points))[index + 5];
		}
		if (((x0 == x1) && (y0 == y1)) || ((x1 == x2) && (y1 == y2))) {
			if ((x0 == x2) && (y0 == y2)) {
				goto l1;
			}
			(((int *) (workBuffer + 80)))[0] = x0;
			(((int *) (workBuffer + 80)))[1] = y0;
			(((int *) (workBuffer + 82)))[0] = x2;
			(((int *) (workBuffer + 82)))[1] = y2;
			/* begin transformPoints: */
			if (2 > 0) {
				transformPoint(((int *) (workBuffer + 80)));
			}
			if (2 > 1) {
				transformPoint(((int *) (workBuffer + 82)));
			}
			if (2 > 2) {
				transformPoint(((int *) (workBuffer + 84)));
			}
			if (2 > 3) {
				transformPoint(((int *) (workBuffer + 86)));
			}
			loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), lineFill, fillIndex, 0);
			goto l1;
		}
		(((int *) (workBuffer + 80)))[0] = x0;
		(((int *) (workBuffer + 80)))[1] = y0;
		(((int *) (workBuffer + 82)))[0] = x1;
		(((int *) (workBuffer + 82)))[1] = y1;
		(((int *) (workBuffer + 84)))[0] = x2;
		(((int *) (workBuffer + 84)))[1] = y2;
		/* begin transformPoints: */
		if (3 > 0) {
			transformPoint(((int *) (workBuffer + 80)));
		}
		if (3 > 1) {
			transformPoint(((int *) (workBuffer + 82)));
		}
		if (3 > 2) {
			transformPoint(((int *) (workBuffer + 84)));
		}
		if (3 > 3) {
			transformPoint(((int *) (workBuffer + 86)));
		}
		segs = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), (lineWidth != 0) && (lineFill != 0));
		if (engineStopped) {
			goto l1;
		}
		loadWideBezierlineFillleftFillrightFilln(lineWidth, lineFill, fillIndex, 0, segs);
	l1:	/* end loadCompressedSegment:from:short:leftFill:rightFill:lineWidth:lineColor: */;
		if (engineStopped) {
			return null;
		}
	}
}

int loadSpanBufferFrom(int spanOop) {
    int value;

	if (!((fetchClassOf(spanOop)) == (longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2))))) {
		return 0;
	}
	spanBuffer = firstIndexableField(spanOop);
	/* begin spanSizePut: */
	value = (slotSizeOf(spanOop)) - 1;
	workBuffer[33] = value;
	return 1;
}

int loadTransformFromintolength(int transformOop, float *destPtr, int n) {
	if (transformOop == nilObj) {
		return 0;
	}
	if ((transformOop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(transformOop)) == n)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (((((unsigned) (longAt(transformOop))) >> 8) & 15) == 6) {
		loadWordTransformFromintolength(transformOop, destPtr, n);
	} else {
		loadArrayTransformFromintolength(transformOop, destPtr, n);
	}
	return 1;
}

int loadWideBezierlineFillleftFillrightFilln(int lineWidth, int lineFill, int leftFill, int rightFill, int nSegments) {
    int index;
    int offset;
    int wide;
    int bezier;
    int bezier1;
    int bezier2;

	if ((lineWidth == 0) || (lineFill == 0)) {
		wide = 0;
		offset = 0;
	} else {
		wide = 1;
		offset = ((int) lineWidth >> 1);
	}
	index = nSegments * 6;
	while (index > 0) {
		if (wide) {
			/* begin allocateWideBezier */
			if (!(allocateObjEntry(28))) {
				bezier = 0;
				goto l1;
			}
			bezier1 = objUsed;
			objUsed = bezier1 + 28;
			objBuffer[bezier1 + 0] = 7;
			objBuffer[bezier1 + 2] = 0;
			objBuffer[bezier1 + 1] = 28;
			bezier = bezier1;
		l1:	/* end allocateWideBezier */;
		} else {
			/* begin allocateBezier */
			if (!(allocateObjEntry(16))) {
				bezier = 0;
				goto l2;
			}
			bezier2 = objUsed;
			objUsed = bezier2 + 16;
			objBuffer[bezier2 + 0] = 6;
			objBuffer[bezier2 + 2] = 0;
			objBuffer[bezier2 + 1] = 16;
			bezier = bezier2;
		l2:	/* end allocateBezier */;
		}
		if (engineStopped) {
			return 0;
		}
		loadBeziersegmentleftFillrightFilloffset(bezier, index, leftFill, rightFill, offset);
		if (wide) {
			objBuffer[bezier + 16] = lineFill;
			objBuffer[bezier + 17] = lineWidth;
			objBuffer[bezier + 20] = lineWidth;
		}
		index -= 6;
	}
	/* begin wbStackClear */
	workBuffer[10] = (workBuffer[1]);
}

int loadWideLinefromtolineFillleftFillrightFill(int lineWidth, int *p1, int *p2, int lineFill, int leftFill, int rightFill) {
    int offset;
    int line;
    int line1;
    int line2;

	if ((lineWidth == 0) || (lineFill == 0)) {
		/* begin allocateLine */
		if (!(allocateObjEntry(16))) {
			line = 0;
			goto l1;
		}
		line1 = objUsed;
		objUsed = line1 + 16;
		objBuffer[line1 + 0] = 4;
		objBuffer[line1 + 2] = 0;
		objBuffer[line1 + 1] = 16;
		line = line1;
	l1:	/* end allocateLine */;
		offset = 0;
	} else {
		/* begin allocateWideLine */
		if (!(allocateObjEntry(21))) {
			line = 0;
			goto l2;
		}
		line2 = objUsed;
		objUsed = line2 + 21;
		objBuffer[line2 + 0] = 5;
		objBuffer[line2 + 2] = 0;
		objBuffer[line2 + 1] = 21;
		line = line2;
	l2:	/* end allocateWideLine */;
		offset = ((int) lineWidth >> 1);
	}
	if (engineStopped) {
		return 0;
	}
	loadLinefromtooffsetleftFillrightFill(line, p1, p2, offset, leftFill, rightFill);
	if ((((objBuffer[line + 0]) & 65535) & 1) != 0) {
		objBuffer[line + 16] = lineFill;
		objBuffer[line + 17] = lineWidth;
		objBuffer[line + 20] = lineWidth;
	}
}

int loadWordTransformFromintolength(int transformOop, float *destPtr, int n) {
    int i;
    float *srcPtr;

	srcPtr = ((float *) (firstIndexableField(transformOop)));
	for (i = 0; i <= (n - 1); i += 1) {
		destPtr[i] = (srcPtr[i]);
	}
}

int loadWorkBufferFrom(int wbOop) {
	if ((wbOop & 1)) {
		return 0;
	}
	if (!(((((unsigned) (longAt(wbOop))) >> 8) & 15) == 6)) {
		return 0;
	}
	if ((slotSizeOf(wbOop)) < 256) {
		return 0;
	}
	workBuffer = firstIndexableField(wbOop);
	if (!((workBuffer[0]) == 1097753705)) {
		return 0;
	}
	if (!((workBuffer[1]) == (slotSizeOf(wbOop)))) {
		return 0;
	}
	if (!((workBuffer[8]) == 128)) {
		return 0;
	}
	objBuffer = workBuffer + (workBuffer[8]);
	getBuffer = objBuffer + (workBuffer[9]);
	aetBuffer = getBuffer + (workBuffer[12]);
	if ((((128 + (workBuffer[9])) + (workBuffer[12])) + (workBuffer[14])) > (workBuffer[1])) {
		return 0;
	}
	return 1;
}

int lookupMethodInClass(int class) {
    int dictionary;
    int currentClass;
    int found;
    int rclass;
    int oop;
    int oop1;
    int methodArray;
    int mask;
    int wrapAround;
    int nextSelector;
    int index;
    int length;
    int primBits;
    int sz;
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
			return currentClass;
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

int lowestFreeAfter(int chunk) {
    int oopHeader;
    int oop;
    int oopHeaderType;
    int oopSize;
    int extra;
    int extra1;
    int type;
    int extra2;
    int type1;
    int extra3;

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

EXPORT(int) m23PrimitiveComposeMatrix(void) {
    int result;
    float * m1;
    float * m2;
    float * m3;
    int sp;
    int matrix;
    int matrix1;
    int matrix2;
    int oop;
    int oop1;

	/* begin loadArgumentMatrix: */
	matrix = result = stackObjectValue(0);
	if (!successFlag) {
		m3 = null;
		goto l1;
	}
	if (!((((((unsigned) (longAt(matrix))) >> 8) & 15) == 6) && ((slotSizeOf(matrix)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		m3 = null;
		goto l1;
	}
	m3 = ((float *) (firstIndexableField(matrix)));
l1:	/* end loadArgumentMatrix: */;
	/* begin loadArgumentMatrix: */
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix1 = null;
		goto l4;
	}
	matrix1 = oop;
l4:	/* end stackObjectValue: */;
	if (!successFlag) {
		m2 = null;
		goto l2;
	}
	if (!((((((unsigned) (longAt(matrix1))) >> 8) & 15) == 6) && ((slotSizeOf(matrix1)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		m2 = null;
		goto l2;
	}
	m2 = ((float *) (firstIndexableField(matrix1)));
l2:	/* end loadArgumentMatrix: */;
	/* begin loadArgumentMatrix: */
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (2 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix2 = null;
		goto l5;
	}
	matrix2 = oop1;
l5:	/* end stackObjectValue: */;
	if (!successFlag) {
		m1 = null;
		goto l3;
	}
	if (!((((((unsigned) (longAt(matrix2))) >> 8) & 15) == 6) && ((slotSizeOf(matrix2)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		m1 = null;
		goto l3;
	}
	m1 = ((float *) (firstIndexableField(matrix2)));
l3:	/* end loadArgumentMatrix: */;
	if (!successFlag) {
		return null;
	}
	matrix2x3ComposeMatrixwithinto(m1, m2, m3);
	/* begin pop: */
	stackPointer -= 3 * 4;
	/* begin push: */
	longAtput(sp = stackPointer + 4, result);
	stackPointer = sp;
}

EXPORT(int) m23PrimitiveInvertPoint(void) {
    float * matrix;
    int matrix1;
    int object;
    int sp;
    int xValue;
    int yValue;
    int pointResult;
    int oop;

	loadArgumentPoint(stackObjectValue(0));
	/* begin loadArgumentMatrix: */
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix1 = null;
		goto l3;
	}
	matrix1 = oop;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		matrix = null;
		goto l1;
	}
	if (!((((((unsigned) (longAt(matrix1))) >> 8) & 15) == 6) && ((slotSizeOf(matrix1)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix = null;
		goto l1;
	}
	matrix = ((float *) (firstIndexableField(matrix1)));
l1:	/* end loadArgumentMatrix: */;
	if (!successFlag) {
		return null;
	}
	matrix2x3InvertPoint(matrix);
	if (!(!successFlag)) {
		/* begin roundAndStoreResultPoint: */
		m23ResultX += 0.5;
		m23ResultY += 0.5;
		if (!((m23ResultX >= (((double) -1073741824 ))) && (m23ResultX <= (((double) 1073741823 ))))) {
			/* begin primitiveFail */
			successFlag = 0;
			goto l2;
		}
		if (!((m23ResultY >= (((double) -1073741824 ))) && (m23ResultX <= (((double) 1073741823 ))))) {
			/* begin primitiveFail */
			successFlag = 0;
			goto l2;
		}
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin push: */
		/* begin makePointwithxValue:yValue: */
		xValue = ((int) m23ResultX );
		yValue = ((int) m23ResultY );
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
		object = pointResult;
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	l2:	/* end roundAndStoreResultPoint: */;
	}
}

EXPORT(int) m23PrimitiveInvertRectInto(void) {
    double originX;
    double originY;
    float * matrix;
    double cornerX;
    double cornerY;
    double minX;
    int srcOop;
    int dstOop;
    double minY;
    double maxX;
    double maxY;
    int sp;
    int oop;
    int oop1;
    int matrix1;
    int oop2;

	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		dstOop = null;
		goto l1;
	}
	dstOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		srcOop = null;
		goto l2;
	}
	srcOop = oop1;
l2:	/* end stackObjectValue: */;
	/* begin loadArgumentMatrix: */
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (2 * 4));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix1 = null;
		goto l4;
	}
	matrix1 = oop2;
l4:	/* end stackObjectValue: */;
	if (!successFlag) {
		matrix = null;
		goto l3;
	}
	if (!((((((unsigned) (longAt(matrix1))) >> 8) & 15) == 6) && ((slotSizeOf(matrix1)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix = null;
		goto l3;
	}
	matrix = ((float *) (firstIndexableField(matrix1)));
l3:	/* end loadArgumentMatrix: */;
	if (!successFlag) {
		return null;
	}
	if (!((fetchClassOf(srcOop)) == (fetchClassOf(dstOop)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((unsigned) (longAt(srcOop))) >> 8) & 15) <= 4)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(srcOop)) == 2)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadArgumentPoint(longAt(((((char *) srcOop)) + 4) + (0 << 2)));
	if (!successFlag) {
		return null;
	}
	originX = m23ArgX;
	originY = m23ArgY;
	matrix2x3InvertPoint(matrix);
	minX = maxX = m23ResultX;
	minY = maxY = m23ResultY;
	loadArgumentPoint(longAt(((((char *) srcOop)) + 4) + (1 << 2)));
	if (!successFlag) {
		return null;
	}
	cornerX = m23ArgX;
	cornerY = m23ArgY;
	matrix2x3InvertPoint(matrix);
	minX = ((minX < m23ResultX) ? minX : m23ResultX);
	maxX = ((maxX < m23ResultX) ? m23ResultX : maxX);
	minY = ((minY < m23ResultY) ? minY : m23ResultY);
	maxY = ((maxY < m23ResultY) ? m23ResultY : maxY);
	m23ArgX = cornerX;
	m23ArgY = originY;
	matrix2x3InvertPoint(matrix);
	minX = ((minX < m23ResultX) ? minX : m23ResultX);
	maxX = ((maxX < m23ResultX) ? m23ResultX : maxX);
	minY = ((minY < m23ResultY) ? minY : m23ResultY);
	maxY = ((maxY < m23ResultY) ? m23ResultY : maxY);
	m23ArgX = originX;
	m23ArgY = cornerY;
	matrix2x3InvertPoint(matrix);
	minX = ((minX < m23ResultX) ? minX : m23ResultX);
	maxX = ((maxX < m23ResultX) ? m23ResultX : maxX);
	minY = ((minY < m23ResultY) ? minY : m23ResultY);
	maxY = ((maxY < m23ResultY) ? m23ResultY : maxY);
	if (!(!successFlag)) {
		dstOop = roundAndStoreResultRectx0y0x1y1(dstOop, minX, minY, maxX, maxY);
	}
	if (!(!successFlag)) {
		/* begin pop: */
		stackPointer -= 3 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, dstOop);
		stackPointer = sp;
	}
}

EXPORT(int) m23PrimitiveIsIdentity(void) {
    float * matrix;
    int sp;
    int sp1;
    int matrix1;
    int oop;

	/* begin loadArgumentMatrix: */
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix1 = null;
		goto l2;
	}
	matrix1 = oop;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		matrix = null;
		goto l1;
	}
	if (!((((((unsigned) (longAt(matrix1))) >> 8) & 15) == 6) && ((slotSizeOf(matrix1)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix = null;
		goto l1;
	}
	matrix = ((float *) (firstIndexableField(matrix1)));
l1:	/* end loadArgumentMatrix: */;
	if (!successFlag) {
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushBool: */
	if (((((((matrix[0]) == (((float) 1.0))) && ((matrix[1]) == (((float) 0.0)))) && ((matrix[2]) == (((float) 0.0)))) && ((matrix[3]) == (((float) 0.0)))) && ((matrix[4]) == (((float) 1.0)))) && ((matrix[5]) == (((float) 0.0)))) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	}
}

EXPORT(int) m23PrimitiveIsPureTranslation(void) {
    float * matrix;
    int sp;
    int sp1;
    int matrix1;
    int oop;

	/* begin loadArgumentMatrix: */
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix1 = null;
		goto l2;
	}
	matrix1 = oop;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		matrix = null;
		goto l1;
	}
	if (!((((((unsigned) (longAt(matrix1))) >> 8) & 15) == 6) && ((slotSizeOf(matrix1)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix = null;
		goto l1;
	}
	matrix = ((float *) (firstIndexableField(matrix1)));
l1:	/* end loadArgumentMatrix: */;
	if (!successFlag) {
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushBool: */
	if (((((matrix[0]) == (((float) 1.0))) && ((matrix[1]) == (((float) 0.0)))) && ((matrix[3]) == (((float) 0.0)))) && ((matrix[4]) == (((float) 1.0)))) {
		/* begin push: */
		longAtput(sp = stackPointer + 4, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
	}
}

EXPORT(int) m23PrimitiveTransformPoint(void) {
    float * matrix;
    int matrix1;
    int object;
    int sp;
    int xValue;
    int yValue;
    int pointResult;
    int oop;

	loadArgumentPoint(stackObjectValue(0));
	/* begin loadArgumentMatrix: */
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix1 = null;
		goto l3;
	}
	matrix1 = oop;
l3:	/* end stackObjectValue: */;
	if (!successFlag) {
		matrix = null;
		goto l1;
	}
	if (!((((((unsigned) (longAt(matrix1))) >> 8) & 15) == 6) && ((slotSizeOf(matrix1)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix = null;
		goto l1;
	}
	matrix = ((float *) (firstIndexableField(matrix1)));
l1:	/* end loadArgumentMatrix: */;
	if (!successFlag) {
		return null;
	}
	matrix2x3TransformPoint(matrix);
	/* begin roundAndStoreResultPoint: */
	m23ResultX += 0.5;
	m23ResultY += 0.5;
	if (!((m23ResultX >= (((double) -1073741824 ))) && (m23ResultX <= (((double) 1073741823 ))))) {
		/* begin primitiveFail */
		successFlag = 0;
		goto l2;
	}
	if (!((m23ResultY >= (((double) -1073741824 ))) && (m23ResultX <= (((double) 1073741823 ))))) {
		/* begin primitiveFail */
		successFlag = 0;
		goto l2;
	}
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin push: */
	/* begin makePointwithxValue:yValue: */
	xValue = ((int) m23ResultX );
	yValue = ((int) m23ResultY );
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
	object = pointResult;
	longAtput(sp = stackPointer + 4, object);
	stackPointer = sp;
l2:	/* end roundAndStoreResultPoint: */;
}

EXPORT(int) m23PrimitiveTransformRectInto(void) {
    double originX;
    double originY;
    float * matrix;
    double cornerX;
    double cornerY;
    double minX;
    int srcOop;
    int dstOop;
    double minY;
    double maxX;
    double maxY;
    int sp;
    int oop;
    int oop1;
    int matrix1;
    int oop2;

	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		dstOop = null;
		goto l1;
	}
	dstOop = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * 4));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		srcOop = null;
		goto l2;
	}
	srcOop = oop1;
l2:	/* end stackObjectValue: */;
	/* begin loadArgumentMatrix: */
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (2 * 4));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix1 = null;
		goto l4;
	}
	matrix1 = oop2;
l4:	/* end stackObjectValue: */;
	if (!successFlag) {
		matrix = null;
		goto l3;
	}
	if (!((((((unsigned) (longAt(matrix1))) >> 8) & 15) == 6) && ((slotSizeOf(matrix1)) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		matrix = null;
		goto l3;
	}
	matrix = ((float *) (firstIndexableField(matrix1)));
l3:	/* end loadArgumentMatrix: */;
	if (!successFlag) {
		return null;
	}
	if (!((fetchClassOf(srcOop)) == (fetchClassOf(dstOop)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((unsigned) (longAt(srcOop))) >> 8) & 15) <= 4)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(srcOop)) == 2)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	loadArgumentPoint(longAt(((((char *) srcOop)) + 4) + (0 << 2)));
	if (!successFlag) {
		return null;
	}
	originX = m23ArgX;
	originY = m23ArgY;
	matrix2x3TransformPoint(matrix);
	minX = maxX = m23ResultX;
	minY = maxY = m23ResultY;
	loadArgumentPoint(longAt(((((char *) srcOop)) + 4) + (1 << 2)));
	if (!successFlag) {
		return null;
	}
	cornerX = m23ArgX;
	cornerY = m23ArgY;
	matrix2x3TransformPoint(matrix);
	minX = ((minX < m23ResultX) ? minX : m23ResultX);
	maxX = ((maxX < m23ResultX) ? m23ResultX : maxX);
	minY = ((minY < m23ResultY) ? minY : m23ResultY);
	maxY = ((maxY < m23ResultY) ? m23ResultY : maxY);
	m23ArgX = cornerX;
	m23ArgY = originY;
	matrix2x3TransformPoint(matrix);
	minX = ((minX < m23ResultX) ? minX : m23ResultX);
	maxX = ((maxX < m23ResultX) ? m23ResultX : maxX);
	minY = ((minY < m23ResultY) ? minY : m23ResultY);
	maxY = ((maxY < m23ResultY) ? m23ResultY : maxY);
	m23ArgX = originX;
	m23ArgY = cornerY;
	matrix2x3TransformPoint(matrix);
	minX = ((minX < m23ResultX) ? minX : m23ResultX);
	maxX = ((maxX < m23ResultX) ? m23ResultX : maxX);
	minY = ((minY < m23ResultY) ? minY : m23ResultY);
	maxY = ((maxY < m23ResultY) ? m23ResultY : maxY);
	dstOop = roundAndStoreResultRectx0y0x1y1(dstOop, minX, minY, maxX, maxY);
	if (!(!successFlag)) {
		/* begin pop: */
		stackPointer -= 3 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, dstOop);
		stackPointer = sp;
	}
}

int makeDirEntryNamesizecreateDatemodDateisDirfileSize(char *entryName, int entryNameSize, int createDate, int modifiedDate, int dirFlag, int fileSize) {
    int modDateOop;
    int i;
    int nameString;
    int createDateOop;
    int results;
    int valuePointer;
    int valuePointer1;
    int oop;
    int oop1;
    int oop2;
    int oop3;
    int oop4;
    int oop5;
    int oop6;
    int oop7;

	/* begin pushRemappableOop: */
	oop = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)), 5);
	remapBuffer[remapBufferCount += 1] = oop;
	/* begin pushRemappableOop: */
	oop1 = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), entryNameSize);
	remapBuffer[remapBufferCount += 1] = oop1;
	/* begin pushRemappableOop: */
	oop2 = positive32BitIntegerFor(createDate);
	remapBuffer[remapBufferCount += 1] = oop2;
	/* begin pushRemappableOop: */
	oop3 = positive32BitIntegerFor(modifiedDate);
	remapBuffer[remapBufferCount += 1] = oop3;
	/* begin popRemappableOop */
	oop4 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	modDateOop = oop4;
	/* begin popRemappableOop */
	oop5 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	createDateOop = oop5;
	/* begin popRemappableOop */
	oop6 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	nameString = oop6;
	/* begin popRemappableOop */
	oop7 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	results = oop7;
	for (i = 0; i <= (entryNameSize - 1); i += 1) {
		byteAtput(((((char *) nameString)) + 4) + i, entryName[i]);
	}
	/* begin storePointer:ofObject:withValue: */
	if (results < youngStart) {
		possibleRootStoreIntovalue(results, nameString);
	}
	longAtput(((((char *) results)) + 4) + (0 << 2), nameString);
	/* begin storePointer:ofObject:withValue: */
	if (results < youngStart) {
		possibleRootStoreIntovalue(results, createDateOop);
	}
	longAtput(((((char *) results)) + 4) + (1 << 2), createDateOop);
	/* begin storePointer:ofObject:withValue: */
	if (results < youngStart) {
		possibleRootStoreIntovalue(results, modDateOop);
	}
	longAtput(((((char *) results)) + 4) + (2 << 2), modDateOop);
	if (dirFlag) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = trueObj;
		if (results < youngStart) {
			possibleRootStoreIntovalue(results, valuePointer);
		}
		longAtput(((((char *) results)) + 4) + (3 << 2), valuePointer);
	} else {
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = falseObj;
		if (results < youngStart) {
			possibleRootStoreIntovalue(results, valuePointer1);
		}
		longAtput(((((char *) results)) + 4) + (3 << 2), valuePointer1);
	}
	/* begin storePointer:ofObject:withValue: */
	if (results < youngStart) {
		possibleRootStoreIntovalue(results, ((fileSize << 1) | 1));
	}
	longAtput(((((char *) results)) + 4) + (4 << 2), ((fileSize << 1) | 1));
	return results;
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

int mapPointersInObjectsFromto(int memStart, int memEnd) {
    int oop;
    int i;
    int i2;
    int oop1;
    int i1;
    int extra;
    int type;
    int extra1;
    int fwdBlock;
    int fieldOffset;
    int fieldOop;
    int newOop;
    int fwdBlock1;
    int header;
    int header1;
    int header2;
    int methodHeader;
    int size;
    int fwdBlock2;
    int fmt;
    int header3;
    int newClassOop;
    int fwdBlock3;
    int classHeader;
    int classOop;
    int newClassHeader;
    int fwdBlock11;
    int header4;
    int header11;
    int header21;
    int fwdBlock4;
    int fieldOffset1;
    int fieldOop1;
    int newOop1;
    int fwdBlock12;
    int header5;
    int header12;
    int header22;
    int methodHeader1;
    int size1;
    int fwdBlock21;
    int fmt1;
    int header31;
    int newClassOop1;
    int fwdBlock31;
    int classHeader1;
    int classOop1;
    int newClassHeader1;
    int fwdBlock111;
    int header41;
    int header111;
    int header211;
    int sz;
    int fwdBlock5;
    int realHeader;
    int header6;
    int extra3;
    int type2;
    int extra12;
    int sz1;
    int extra2;
    int header13;
    int type1;
    int extra11;

	/* begin compilerMapHookFrom:to: */
	if (compilerInitialized) {
		compilerMapFromto(memStart, memEnd);
	}
	/* begin mapInterpreterOops */
	nilObj = remap(nilObj);
	falseObj = remap(falseObj);
	trueObj = remap(trueObj);
	specialObjectsOop = remap(specialObjectsOop);
	stackPointer -= activeContext;
	activeContext = remap(activeContext);
	stackPointer += activeContext;
	theHomeContext = remap(theHomeContext);
	instructionPointer -= method;
	method = remap(method);
	instructionPointer += method;
	receiver = remap(receiver);
	messageSelector = remap(messageSelector);
	newMethod = remap(newMethod);
	for (i2 = 1; i2 <= remapBufferCount; i2 += 1) {
		oop1 = remapBuffer[i2];
		if (!((oop1 & 1))) {
			remapBuffer[i2] = (remap(oop1));
		}
	}
	/* begin flushMethodCache */
	for (i1 = 1; i1 <= 2048; i1 += 1) {
		methodCache[i1] = 0;
	}
	for (i1 = 1; i1 <= 64; i1 += 1) {
		atCache[i1] = 0;
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
					goto l1;
				}
				if ((header3 & 3) == 0) {
					size = (longAt(oop - 8)) & 4294967292U;
				} else {
					size = header3 & 252;
				}
				fieldOffset = size - 4;
				goto l1;
			}
			if (fmt < 12) {
				fieldOffset = 0;
				goto l1;
			}
			methodHeader = longAt(oop + 4);
			fieldOffset = (((((unsigned) methodHeader) >> 10) & 255) * 4) + 4;
		l1:	/* end lastPointerWhileForwarding: */;
			while (fieldOffset >= 4) {
				fieldOop = longAt(oop + fieldOffset);
				if (((fieldOop & 1) == 0) && (((longAt(fieldOop)) & 2147483648U) != 0)) {
					fwdBlock = ((longAt(fieldOop)) & 2147483644) << 1;
					;
					newOop = longAt(fwdBlock);
					longAtput(oop + fieldOffset, newOop);
					if ((oop < youngStart) && (newOop >= youngStart)) {
						/* begin beRootWhileForwarding: */
						header = longAt(oop);
						if ((header & 2147483648U) != 0) {
							fwdBlock1 = (header & 2147483644) << 1;
							;
							/* begin noteAsRoot:headerLoc: */
							header1 = longAt(fwdBlock1 + 4);
							if ((header1 & 1073741824) == 0) {
								if (rootTableCount < 2500) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(fwdBlock1 + 4, header1 | 1073741824);
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
				goto l2;
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
		l2:	/* end remapClassOf: */;
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
					goto l3;
				}
				if ((header31 & 3) == 0) {
					size1 = (longAt(oop - 8)) & 4294967292U;
				} else {
					size1 = header31 & 252;
				}
				fieldOffset1 = size1 - 4;
				goto l3;
			}
			if (fmt1 < 12) {
				fieldOffset1 = 0;
				goto l3;
			}
			methodHeader1 = longAt(oop + 4);
			fieldOffset1 = (((((unsigned) methodHeader1) >> 10) & 255) * 4) + 4;
		l3:	/* end lastPointerWhileForwarding: */;
			while (fieldOffset1 >= 4) {
				fieldOop1 = longAt(oop + fieldOffset1);
				if (((fieldOop1 & 1) == 0) && (((longAt(fieldOop1)) & 2147483648U) != 0)) {
					fwdBlock4 = ((longAt(fieldOop1)) & 2147483644) << 1;
					;
					newOop1 = longAt(fwdBlock4);
					longAtput(oop + fieldOffset1, newOop1);
					if ((oop < youngStart) && (newOop1 >= youngStart)) {
						/* begin beRootWhileForwarding: */
						header5 = longAt(oop);
						if ((header5 & 2147483648U) != 0) {
							fwdBlock12 = (header5 & 2147483644) << 1;
							;
							/* begin noteAsRoot:headerLoc: */
							header12 = longAt(fwdBlock12 + 4);
							if ((header12 & 1073741824) == 0) {
								if (rootTableCount < 2500) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(fwdBlock12 + 4, header12 | 1073741824);
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
				goto l4;
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
		l4:	/* end remapClassOf: */;
		}
		/* begin objectAfterWhileForwarding: */
		header6 = longAt(oop);
		if ((header6 & 2147483648U) == 0) {
			/* begin objectAfter: */
			;
			if (((longAt(oop)) & 3) == 2) {
				sz1 = (longAt(oop)) & 4294967292U;
			} else {
				/* begin sizeBitsOf: */
				header13 = longAt(oop);
				if ((header13 & 3) == 0) {
					sz1 = (longAt(oop - 8)) & 4294967292U;
					goto l5;
				} else {
					sz1 = header13 & 252;
					goto l5;
				}
			l5:	/* end sizeBitsOf: */;
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
			goto l6;
		}
		fwdBlock5 = (header6 & 2147483644) << 1;
		;
		realHeader = longAt(fwdBlock5 + 4);
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
	l6:	/* end objectAfterWhileForwarding: */;
	}
}

int markAndTrace(int oop) {
    int action;
    int lastFieldOffset;
    int header;
    int typeBits;
    int childType;
    int header1;
    int type;
    int methodHeader;
    int sz;
    int fmt;
    int header2;
    int header3;
    int type1;
    int oop1;
    int lastFieldOffset1;
    int header4;
    int methodHeader1;
    int sz1;
    int fmt1;
    int header11;
    int header21;
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
						goto l3;
					} else {
						if ((child & 126976) == 0) {
							childType = 1;
							goto l3;
						} else {
							childType = 3;
							goto l3;
						}
					}
				l3:	/* end rightType: */;
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
					header11 = longAt(oop1);
					fmt1 = (((unsigned) header11) >> 8) & 15;
					if (fmt1 <= 4) {
						if ((fmt1 == 3) && (isContextHeader(header11))) {
							lastFieldOffset1 = (6 + (fetchStackPointerOf(oop1))) * 4;
							goto l9;
						}
						/* begin sizeBitsOfSafe: */
						header21 = longAt(oop1);
						/* begin rightType: */
						if ((header21 & 252) == 0) {
							type2 = 0;
							goto l10;
						} else {
							if ((header21 & 126976) == 0) {
								type2 = 1;
								goto l10;
							} else {
								type2 = 3;
								goto l10;
							}
						}
					l10:	/* end rightType: */;
						if (type2 == 0) {
							sz1 = (longAt(oop1 - 8)) & 4294967292U;
							goto l11;
						} else {
							sz1 = header21 & 252;
							goto l11;
						}
					l11:	/* end sizeBitsOfSafe: */;
						lastFieldOffset1 = sz1 - 4;
						goto l9;
					}
					if (fmt1 < 12) {
						lastFieldOffset1 = 0;
						goto l9;
					}
					methodHeader1 = longAt(oop1 + 4);
					lastFieldOffset1 = (((((unsigned) methodHeader1) >> 10) & 255) * 4) + 4;
				l9:	/* end lastPointerOf: */;
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
					longAtput(field, header1 + type);
					action = 4;
					goto l2;
				} else {
					child = field;
					field = parentField - 1;
					parentField = longAt(field);
					header1 = longAt(field + 4);
					/* begin rightType: */
					if ((header1 & 252) == 0) {
						type = 0;
						goto l5;
					} else {
						if ((header1 & 126976) == 0) {
							type = 1;
							goto l5;
						} else {
							type = 3;
							goto l5;
						}
					}
				l5:	/* end rightType: */;
					longAtput(field, child + type);
					field += 4;
					header1 = header1 & 4294967292U;
					longAtput(field, header1 + type);
					action = 3;
					goto l2;
				}
			} else {
				child = field;
				field = parentField;
				parentField = longAt(field);
				longAtput(field, child);
				field -= 4;
				action = 1;
				goto l2;
			}
		l2:	/* end upward */;
		}
	}
}

int markPhase(void) {
    int oop;
    int i;
    int i1;
    int oop1;

	freeContexts = 1;
	/* begin markAndTraceInterpreterOops */
	/* begin compilerMarkHook */
	if (compilerInitialized) {
		compilerMark();
	}
	markAndTrace(specialObjectsOop);
	markAndTrace(activeContext);
	markAndTrace(messageSelector);
	markAndTrace(newMethod);
	for (i1 = 1; i1 <= remapBufferCount; i1 += 1) {
		oop1 = remapBuffer[i1];
		if (!((oop1 & 1))) {
			markAndTrace(oop1);
		}
	}
	for (i = 1; i <= rootTableCount; i += 1) {
		oop = rootTable[i];
		markAndTrace(oop);
	}
}

int matrix2x3ComposeMatrixwithinto(const float *m1, const float *m2, float *m3) {
    double a21;
    double a22;
    double a23;
    double a11;
    double a12;
    double a13;

	a11 = ((m1[0]) * (m2[0])) + ((m1[1]) * (m2[3]));
	a12 = ((m1[0]) * (m2[1])) + ((m1[1]) * (m2[4]));
	a13 = (((m1[0]) * (m2[2])) + ((m1[1]) * (m2[5]))) + (m1[2]);
	a21 = ((m1[3]) * (m2[0])) + ((m1[4]) * (m2[3]));
	a22 = ((m1[3]) * (m2[1])) + ((m1[4]) * (m2[4]));
	a23 = (((m1[3]) * (m2[2])) + ((m1[4]) * (m2[5]))) + (m1[5]);
	m3[0] = (((float) a11));
	m3[1] = (((float) a12));
	m3[2] = (((float) a13));
	m3[3] = (((float) a21));
	m3[4] = (((float) a22));
	m3[5] = (((float) a23));
}

int matrix2x3InvertPoint(float *m) {
    double det;
    double y;
    double x;
    double detX;
    double detY;

	x = m23ArgX - (m[2]);
	y = m23ArgY - (m[5]);
	det = ((m[0]) * (m[4])) - ((m[1]) * (m[3]));
	if (det == 0.0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	det = 1.0 / det;
	detX = (x * (m[4])) - ((m[1]) * y);
	detY = ((m[0]) * y) - (x * (m[3]));
	m23ResultX = detX * det;
	m23ResultY = detY * det;
}

int matrix2x3TransformPoint(float *m) {
	m23ResultX = ((m23ArgX * (m[0])) + (m23ArgY * (m[1]))) + (m[2]);
	m23ResultY = ((m23ArgX * (m[3])) + (m23ArgY * (m[4]))) + (m[5]);
}

int mergewith(int sourceWord, int destinationWord) {
    int (*mergeFnwith)(int, int);

	mergeFnwith = ((int (*)(int, int)) (opTable[combinationRule + 1]));
	mergeFnwith;
	return mergeFnwith(sourceWord, destinationWord);
}

int methodArgumentCount(void) {
	return argumentCount;
}

int methodPrimitiveIndex(void) {
	return primitiveIndex;
}

int moveAETEntryFromedgex(int index, int edge, int xValue) {
    int newIndex;

	newIndex = index;
	while ((newIndex > 0) && ((objBuffer[(aetBuffer[newIndex - 1]) + 4]) > xValue)) {
		aetBuffer[newIndex] = (aetBuffer[newIndex - 1]);
		newIndex -= 1;
	}
	aetBuffer[newIndex] = edge;
}

int needAvailableSpace(int nSlots) {
	if (((((128 + objUsed) + (workBuffer[12])) + (workBuffer[14])) + nSlots) > (workBuffer[10])) {
		/* begin stopBecauseOf: */
		workBuffer[64] = 1;
		engineStopped = 1;
		return 0;
	}
	return 1;
}

int netAddressToInt(int oop) {
    int sz;
    int header;
    int sz1;
    int ccIndex;
    int cl;

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
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (26 << 2)))) && successFlag;
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
	l1:	/* end lengthOf:baseHeader:format: */;
		if (!(sz == 4)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	if (successFlag) {
		return (((byteAt(((((char *) oop)) + 4) + 3)) + ((byteAt(((((char *) oop)) + 4) + 2)) << 8)) + ((byteAt(((((char *) oop)) + 4) + 1)) << 16)) + ((byteAt(((((char *) oop)) + 4) + 0)) << 24);
	}
}

int nilObject(void) {
	return nilObj;
}

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

int nullCompilerHook(void) {
	error("uninitialised compiler hook called");
	return 0;
}

int objectAfter(int oop) {
    int sz;
    int extra;
    int header;
    int type;
    int extra1;

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

int okayFields(int oop) {
    int i;
    int fieldOop;

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
	i = (lengthOf(oop)) - 1;
	while (i >= 0) {
		fieldOop = longAt(((((char *) oop)) + 4) + (i << 2));
		if (!((fieldOop & 1))) {
			okayOop(fieldOop);
			oopHasOkayClass(fieldOop);
		}
		i -= 1;
	}
}

int okayOop(int oop) {
    int sz;
    int type;
    int fmt;
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

int oopFromChunk(int chunk) {
    int extra;
    int type;
    int extra1;

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

int oopHasOKclass(int oop) {
    int behaviorFormatBits;
    int oopClass;
    int formatMask;
    int oopFormatBits;
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

int oopHasOkayClass(int oop) {
    int behaviorFormatBits;
    int oopClass;
    int formatMask;
    int oopFormatBits;
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

int partitionedANDtonBitsnPartitions(int word1, int word2, int nBits, int nParts) {
    int mask;
    int i;
    int result;

	mask = maskTable[nBits];
	result = 0;
	for (i = 1; i <= nParts; i += 1) {
		if ((word1 & mask) == mask) {
			result = result | (word2 & mask);
		}
		mask = mask << nBits;
	}
	return result;
}

int partitionedAddtonBitsnPartitions(int word1, int word2, int nBits, int nParts) {
    int mask;
    int sum;
    int i;
    int result;

	mask = maskTable[nBits];
	result = 0;
	for (i = 1; i <= nParts; i += 1) {
		sum = (word1 & mask) + (word2 & mask);
		if (sum <= mask) {
			result = result | sum;
		} else {
			result = result | mask;
		}
		mask = mask << nBits;
	}
	return result;
}

int partitionedMaxwithnBitsnPartitions(int word1, int word2, int nBits, int nParts) {
    int mask;
    int i;
    int result;

	mask = maskTable[nBits];
	result = 0;
	for (i = 1; i <= nParts; i += 1) {
		result = result | ((((word2 & mask) < (word1 & mask)) ? (word1 & mask) : (word2 & mask)));
		mask = mask << nBits;
	}
	return result;
}

int partitionedMinwithnBitsnPartitions(int word1, int word2, int nBits, int nParts) {
    int mask;
    int i;
    int result;

	mask = maskTable[nBits];
	result = 0;
	for (i = 1; i <= nParts; i += 1) {
		result = result | ((((word2 & mask) < (word1 & mask)) ? (word2 & mask) : (word1 & mask)));
		mask = mask << nBits;
	}
	return result;
}

int partitionedSubfromnBitsnPartitions(int word1, int word2, int nBits, int nParts) {
    int mask;
    int i;
    int p1;
    int p2;
    int result;

	mask = maskTable[nBits];
	result = 0;
	for (i = 1; i <= nParts; i += 1) {
		p1 = word1 & mask;
		p2 = word2 & mask;
		if (p1 < p2) {
			result = result | (p2 - p1);
		} else {
			result = result | (p1 - p2);
		}
		mask = mask << nBits;
	}
	return result;
}

int permuteData(void) {
    int i;
    int a;
    int b;
    int end;
    float tmp;

	i = 0;
	end = permTableSize;
	while (i < end) {
		a = (permTable[i]) - 1;
		b = (permTable[i + 1]) - 1;
		if (!((a < realDataSize) && (b < realDataSize))) {
			/* begin success: */
			successFlag = 0 && successFlag;
			return null;
		}
		tmp = realData[a];
		realData[a] = (realData[b]);
		realData[b] = tmp;
		tmp = imagData[a];
		imagData[a] = (imagData[b]);
		imagData[b] = tmp;
		i += 2;
	}
}

int pickSourcePixelssrcMaskdestMask(int nPix, int sourcePixMask, int destPixMask) {
    int sourceWord;
    int destWord;
    int sourcePix;
    int destPix;
    int i;

	sourceWord = longAt(sourceIndex);
	destWord = 0;
	for (i = 1; i <= nPix; i += 1) {
		sourcePix = (((unsigned) sourceWord) >> ((32 - sourcePixSize) - srcBitIndex)) & sourcePixMask;
		destPix = (longAt(((((char *) colorMap)) + 4) + (sourcePix << 2))) & destPixMask;
		if (destPixSize == 32) {
			destWord = destPix;
		} else {
			destWord = (destWord << destPixSize) | destPix;
		}
		if ((srcBitIndex += sourcePixSize) > 31) {
			srcBitIndex -= 32;
			sourceIndex += 4;
			sourceWord = longAt(sourceIndex);
		}
	}
	return destWord;
}

int pickSourcePixelsNullMapsrcMaskdestMask(int nPix, int sourcePixMask, int destPixMask) {
    int sourceWord;
    int destWord;
    int sourcePix;
    int i;

	sourceWord = longAt(sourceIndex);
	destWord = 0;
	for (i = 1; i <= nPix; i += 1) {
		sourcePix = (((unsigned) sourceWord) >> ((32 - sourcePixSize) - srcBitIndex)) & sourcePixMask;
		if (destPixSize == 32) {
			destWord = sourcePix;
		} else {
			destWord = (destWord << destPixSize) | (sourcePix & destPixMask);
		}
		if ((srcBitIndex += sourcePixSize) > 31) {
			srcBitIndex -= 32;
			sourceIndex += 4;
			sourceWord = longAt(sourceIndex);
		}
	}
	return destWord;
}

int pickSourcePixelsRGBnullMapsrcMaskdestMask(int nPix, int nullMap, int sourcePixMask, int destPixMask) {
    int sourceWord;
    int destWord;
    int sourcePix;
    int destPix;
    int i;
    int mask;
    int srcPix;
    int destPix1;
    int d;
    int mask3;
    int srcPix1;
    int destPix2;
    int d1;
    int mask4;
    int srcPix2;
    int destPix3;
    int d2;
    int mask5;
    int srcPix3;
    int destPix4;
    int d3;

	sourceWord = longAt(sourceIndex);
	destWord = 0;
	for (i = 1; i <= nPix; i += 1) {
		sourcePix = (((unsigned) sourceWord) >> ((32 - sourcePixSize) - srcBitIndex)) & sourcePixMask;
		if (nullMap) {
			if (sourcePixSize == 16) {
				/* begin rgbMap:from:to: */
				if ((d = 8 - 5) > 0) {
					mask = (1 << 5) - 1;
					srcPix = sourcePix << d;
					mask = mask << d;
					destPix1 = srcPix & mask;
					mask = mask << 8;
					srcPix = srcPix << d;
					destPix = (destPix1 + (srcPix & mask)) + ((srcPix << d) & (mask << 8));
					goto l1;
				} else {
					if (d == 0) {
						if (5 == 5) {
							destPix = sourcePix & 32767;
							goto l1;
						}
						if (5 == 8) {
							destPix = sourcePix & 16777215;
							goto l1;
						}
						destPix = sourcePix;
						goto l1;
					}
					if (sourcePix == 0) {
						destPix = sourcePix;
						goto l1;
					}
					d = 5 - 8;
					mask = (1 << 8) - 1;
					srcPix = ((unsigned) sourcePix) >> d;
					destPix1 = srcPix & mask;
					mask = mask << 8;
					srcPix = ((unsigned) srcPix) >> d;
					destPix1 = (destPix1 + (srcPix & mask)) + ((((unsigned) srcPix) >> d) & (mask << 8));
					if (destPix1 == 0) {
						destPix = 1;
						goto l1;
					}
					destPix = destPix1;
					goto l1;
				}
			l1:	/* end rgbMap:from:to: */;
			} else {
				/* begin rgbMap:from:to: */
				if ((d1 = 5 - 8) > 0) {
					mask3 = (1 << 8) - 1;
					srcPix1 = sourcePix << d1;
					mask3 = mask3 << d1;
					destPix2 = srcPix1 & mask3;
					mask3 = mask3 << 5;
					srcPix1 = srcPix1 << d1;
					destPix = (destPix2 + (srcPix1 & mask3)) + ((srcPix1 << d1) & (mask3 << 5));
					goto l2;
				} else {
					if (d1 == 0) {
						if (8 == 5) {
							destPix = sourcePix & 32767;
							goto l2;
						}
						if (8 == 8) {
							destPix = sourcePix & 16777215;
							goto l2;
						}
						destPix = sourcePix;
						goto l2;
					}
					if (sourcePix == 0) {
						destPix = sourcePix;
						goto l2;
					}
					d1 = 8 - 5;
					mask3 = (1 << 5) - 1;
					srcPix1 = ((unsigned) sourcePix) >> d1;
					destPix2 = srcPix1 & mask3;
					mask3 = mask3 << 5;
					srcPix1 = ((unsigned) srcPix1) >> d1;
					destPix2 = (destPix2 + (srcPix1 & mask3)) + ((((unsigned) srcPix1) >> d1) & (mask3 << 5));
					if (destPix2 == 0) {
						destPix = 1;
						goto l2;
					}
					destPix = destPix2;
					goto l2;
				}
			l2:	/* end rgbMap:from:to: */;
			}
		} else {
			if (sourcePixSize == 16) {
				/* begin rgbMap:from:to: */
				if ((d2 = cmBitsPerColor - 5) > 0) {
					mask4 = (1 << 5) - 1;
					srcPix2 = sourcePix << d2;
					mask4 = mask4 << d2;
					destPix3 = srcPix2 & mask4;
					mask4 = mask4 << cmBitsPerColor;
					srcPix2 = srcPix2 << d2;
					sourcePix = (destPix3 + (srcPix2 & mask4)) + ((srcPix2 << d2) & (mask4 << cmBitsPerColor));
					goto l3;
				} else {
					if (d2 == 0) {
						if (5 == 5) {
							sourcePix = sourcePix & 32767;
							goto l3;
						}
						if (5 == 8) {
							sourcePix = sourcePix & 16777215;
							goto l3;
						}
						sourcePix = sourcePix;
						goto l3;
					}
					if (sourcePix == 0) {
						sourcePix = sourcePix;
						goto l3;
					}
					d2 = 5 - cmBitsPerColor;
					mask4 = (1 << cmBitsPerColor) - 1;
					srcPix2 = ((unsigned) sourcePix) >> d2;
					destPix3 = srcPix2 & mask4;
					mask4 = mask4 << cmBitsPerColor;
					srcPix2 = ((unsigned) srcPix2) >> d2;
					destPix3 = (destPix3 + (srcPix2 & mask4)) + ((((unsigned) srcPix2) >> d2) & (mask4 << cmBitsPerColor));
					if (destPix3 == 0) {
						sourcePix = 1;
						goto l3;
					}
					sourcePix = destPix3;
					goto l3;
				}
			l3:	/* end rgbMap:from:to: */;
			} else {
				/* begin rgbMap:from:to: */
				if ((d3 = cmBitsPerColor - 8) > 0) {
					mask5 = (1 << 8) - 1;
					srcPix3 = sourcePix << d3;
					mask5 = mask5 << d3;
					destPix4 = srcPix3 & mask5;
					mask5 = mask5 << cmBitsPerColor;
					srcPix3 = srcPix3 << d3;
					sourcePix = (destPix4 + (srcPix3 & mask5)) + ((srcPix3 << d3) & (mask5 << cmBitsPerColor));
					goto l4;
				} else {
					if (d3 == 0) {
						if (8 == 5) {
							sourcePix = sourcePix & 32767;
							goto l4;
						}
						if (8 == 8) {
							sourcePix = sourcePix & 16777215;
							goto l4;
						}
						sourcePix = sourcePix;
						goto l4;
					}
					if (sourcePix == 0) {
						sourcePix = sourcePix;
						goto l4;
					}
					d3 = 8 - cmBitsPerColor;
					mask5 = (1 << cmBitsPerColor) - 1;
					srcPix3 = ((unsigned) sourcePix) >> d3;
					destPix4 = srcPix3 & mask5;
					mask5 = mask5 << cmBitsPerColor;
					srcPix3 = ((unsigned) srcPix3) >> d3;
					destPix4 = (destPix4 + (srcPix3 & mask5)) + ((((unsigned) srcPix3) >> d3) & (mask5 << cmBitsPerColor));
					if (destPix4 == 0) {
						sourcePix = 1;
						goto l4;
					}
					sourcePix = destPix4;
					goto l4;
				}
			l4:	/* end rgbMap:from:to: */;
			}
			destPix = (longAt(((((char *) colorMap)) + 4) + (sourcePix << 2))) & destPixMask;
		}
		if (destPixSize == 32) {
			destWord = destPix;
		} else {
			destWord = (destWord << destPixSize) | destPix;
		}
		if ((srcBitIndex += sourcePixSize) > 31) {
			srcBitIndex -= 32;
			sourceIndex += 4;
			sourceWord = longAt(sourceIndex);
		}
	}
	return destWord;
}

int pixMaskwith(int sourceWord, int destinationWord) {
    int mask;
    int i;
    int result;

	/* begin partitionedAND:to:nBits:nPartitions: */
	mask = maskTable[destPixSize];
	result = 0;
	for (i = 1; i <= pixPerWord; i += 1) {
		if (((~sourceWord) & mask) == mask) {
			result = result | (destinationWord & mask);
		}
		mask = mask << destPixSize;
	}
	return result;
}

int pixPaintwith(int sourceWord, int destinationWord) {
	if (sourceWord == 0) {
		return destinationWord;
	}
	return sourceWord | (partitionedANDtonBitsnPartitions(~sourceWord, destinationWord, destPixSize, pixPerWord));
}

int pop(int nItems) {
	stackPointer -= nItems * 4;
}

int popthenPush(int nItems, int oop) {
    int sp;

	longAtput(sp = stackPointer - ((nItems - 1) * 4), oop);
	stackPointer = sp;
}

double popFloat(void) {
    int top;
    double result;
    int top1;
    int ccIndex;
    int cl;

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

int positive32BitValueOf(int oop) {
    int sz;
    int value;
    int header;
    int sz1;
    int ccIndex;
    int cl;

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
	l1:	/* end lengthOf:baseHeader:format: */;
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

int postDisplayAction(void) {
	if (((workBuffer[11]) >= (workBuffer[12])) && ((workBuffer[14]) == 0)) {
		workBuffer[2] = 8;
	}
	if ((workBuffer[88]) >= (workBuffer[39])) {
		workBuffer[2] = 8;
	}
}

int prepareForwardingTableForBecomingwithtwoWay(int array1, int array2, int twoWayFlag) {
    int entriesAvailable;
    int fwdBlock;
    int fieldOffset;
    int oop1;
    int oop2;
    int entriesNeeded;
    int fwdBlkSize;
    int originalHeader;
    int originalHeaderType;
    int originalHeader1;
    int originalHeaderType1;
    int methodHeader;
    int sz;
    int fmt;
    int header;
    int header1;
    int type;

	entriesNeeded = ((int) (lastPointerOf(array1)) >> 2);
	if (twoWayFlag) {
		entriesNeeded = entriesNeeded * 2;
		fwdBlkSize = 8;
	} else {
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

int primitiveArrayBecome(void) {
    int arg;
    int rcvr;
    int successValue;
    int i;

	arg = longAt(stackPointer);
	rcvr = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successValue = becomewithtwoWay(rcvr, arg, 1);
	successFlag = successValue && successFlag;
	/* begin flushMethodCache */
	for (i = 1; i <= 2048; i += 1) {
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

int primitiveArrayBecomeOneWay(void) {
    int arg;
    int rcvr;
    int successValue;
    int i;

	arg = longAt(stackPointer);
	rcvr = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successValue = becomewithtwoWay(rcvr, arg, 0);
	successFlag = successValue && successFlag;
	/* begin flushMethodCache */
	for (i = 1; i <= 2048; i += 1) {
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

int primitiveAsyncFileClose(void) {
    AsyncFile *f;

	f = asyncFileValueOf(longAt(stackPointer));
	if (successFlag) {
		asyncFileClose(f);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveAsyncFileOpen(void) {
    AsyncFile *f;
    int semaIndex;
    int writeFlag;
    int fileName;
    int fmt;
    int fileNameSize;
    int fOop;
    int sp;
    int integerPointer;
    int oop;
    int successValue;
    int header;
    int sz;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		semaIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		semaIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (1 * 4))) == trueObj) {
		writeFlag = 1;
		goto l2;
	}
	if ((longAt(stackPointer - (1 * 4))) == falseObj) {
		writeFlag = 0;
		goto l2;
	}
	successFlag = 0;
	writeFlag = null;
l2:	/* end booleanValueOf: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (2 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		fileName = null;
		goto l3;
	}
	fileName = oop;
l3:	/* end stackObjectValue: */;
	if (!(successFlag)) {
		return null;
	}
	fmt = (((unsigned) (longAt(fileName))) >> 8) & 15;
	/* begin success: */
	successValue = (fmt >= 8) && (fmt <= 11);
	successFlag = successValue && successFlag;
	/* begin lengthOf: */
	header = longAt(fileName);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(fileName - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		fileNameSize = ((unsigned) (sz - 4)) >> 2;
		goto l4;
	} else {
		fileNameSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l4;
	}
l4:	/* end lengthOf:baseHeader:format: */;
	if (successFlag) {
		fOop = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (26 << 2)), sizeof(AsyncFile));
		f = asyncFileValueOf(fOop);
	}
	if (successFlag) {
		asyncFileOpen(f, fileName + 4, fileNameSize, writeFlag, semaIndex);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 4 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, fOop);
		stackPointer = sp;
	}
}

int primitiveAsyncFileReadResult(void) {
    AsyncFile *f;
    int startIndex;
    int buffer;
    int bufferPtr;
    int bufferSize;
    int count;
    int fmt;
    int r;
    int sp;
    int integerPointer;
    int integerPointer1;
    int oop;
    int successValue;
    int header;
    int successValue1;
    int sz;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		startIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (2 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		buffer = null;
		goto l3;
	}
	buffer = oop;
l3:	/* end stackObjectValue: */;
	f = asyncFileValueOf(longAt(stackPointer - (3 * 4)));
	if (!(successFlag)) {
		return null;
	}
	fmt = (((unsigned) (longAt(buffer))) >> 8) & 15;
	/* begin success: */
	successValue = (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
	successFlag = successValue && successFlag;
	/* begin lengthOf: */
	header = longAt(buffer);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(buffer - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		bufferSize = ((unsigned) (sz - 4)) >> 2;
		goto l4;
	} else {
		bufferSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l4;
	}
l4:	/* end lengthOf:baseHeader:format: */;
	if (fmt == 6) {
		count = count * 4;
		startIndex = ((startIndex - 1) * 4) + 1;
		bufferSize = bufferSize * 4;
	}
	/* begin success: */
	successValue1 = (startIndex >= 1) && (((startIndex + count) - 1) <= bufferSize);
	successFlag = successValue1 && successFlag;
	bufferPtr = ((buffer + 4) + startIndex) - 1;
	if (successFlag) {
		r = asyncFileReadResult(f, bufferPtr, count);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((r << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveAsyncFileReadStart(void) {
    AsyncFile *f;
    int fPosition;
    int count;
    int integerPointer;
    int integerPointer1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		fPosition = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		fPosition = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	f = asyncFileValueOf(longAt(stackPointer - (2 * 4)));
	if (successFlag) {
		asyncFileReadStart(f, fPosition, count);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
	}
}

int primitiveAsyncFileWriteResult(void) {
    AsyncFile *f;
    int r;
    int sp;

	f = asyncFileValueOf(longAt(stackPointer));
	if (successFlag) {
		r = asyncFileWriteResult(f);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((r << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveAsyncFileWriteStart(void) {
    AsyncFile *f;
    int startIndex;
    int buffer;
    int bufferPtr;
    int bufferSize;
    int count;
    int fPosition;
    int fmt;
    int integerPointer;
    int integerPointer1;
    int oop;
    int integerPointer2;
    int successValue;
    int header;
    int successValue1;
    int sz;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		startIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (2 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		buffer = null;
		goto l3;
	}
	buffer = oop;
l3:	/* end stackObjectValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (3 * 4));
	if ((integerPointer2 & 1)) {
		fPosition = (integerPointer2 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		fPosition = 0;
		goto l4;
	}
l4:	/* end stackIntegerValue: */;
	f = asyncFileValueOf(longAt(stackPointer - (4 * 4)));
	if (!(successFlag)) {
		return null;
	}
	fmt = (((unsigned) (longAt(buffer))) >> 8) & 15;
	/* begin success: */
	successValue = (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
	successFlag = successValue && successFlag;
	/* begin lengthOf: */
	header = longAt(buffer);
	/* begin lengthOf:baseHeader:format: */
	if ((header & 3) == 0) {
		sz = (longAt(buffer - 8)) & 4294967292U;
	} else {
		sz = header & 252;
	}
	if (((((unsigned) header) >> 8) & 15) < 8) {
		bufferSize = ((unsigned) (sz - 4)) >> 2;
		goto l5;
	} else {
		bufferSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
		goto l5;
	}
l5:	/* end lengthOf:baseHeader:format: */;
	if (fmt == 6) {
		count = count * 4;
		startIndex = ((startIndex - 1) * 4) + 1;
		bufferSize = bufferSize * 4;
	}
	/* begin success: */
	successValue1 = (startIndex >= 1) && (((startIndex + count) - 1) <= bufferSize);
	successFlag = successValue1 && successFlag;
	bufferPtr = ((buffer + 4) + startIndex) - 1;
	if (successFlag) {
		asyncFileWriteStart(f, fPosition, bufferPtr, count);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
	}
}

int primitiveAt(void) {
	commonAt(0);
}

int primitiveAtEnd(void) {
    int stream;
    int index;
    int limit;
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

int primitiveBeCursor(void) {
    int maskObj;
    int maskBitsIndex;
    int depth;
    int i;
    int bitsObj;
    int extentX;
    int extentY;
    int cursorObj;
    int offsetObj;
    int offsetX;
    int offsetY;
    int cursorBitsIndex;
    int ourCursor;
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
    int integerReceiver;
    int integerArgument;
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
    int integerReceiver;
    int integerArgument;
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
    int integerReceiver;
    int integerArgument;
    int object;
    int sp;
    int integerPointer;
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
    int integerReceiver;
    int integerArgument;
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
    int newContext;
    int initialIP;
    int context;
    int contextSize;
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
	context = null;
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = methodContext;
	newContext = instantiateContextsizeInBytes(longAt(((((char *) specialObjectsOop)) + 4) + (11 << 2)), contextSize);
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	methodContext = oop;
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

int primitiveBytesLeft(void) {
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, ((((longAt(freeBlock)) & 4294967292U) << 1) | 1));
	stackPointer = sp;
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

int primitiveClipboardText(void) {
    int sz;
    int s;
    int sp;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp1;
    int classFormat;
    int class;
    int sz1;
    int ccIndex;
    int ccIndex1;
    int cl;

	if (argumentCount == 1) {
		s = longAt(stackPointer);
		/* begin assertClassOf:is: */
		if ((s & 1)) {
			successFlag = 0;
			goto l5;
		}
		ccIndex1 = (((unsigned) (longAt(s))) >> 12) & 31;
		if (ccIndex1 == 0) {
			cl = (longAt(s - 4)) & 4294967292U;
		} else {
			cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
		}
		/* begin success: */
		successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)))) && successFlag;
	l5:	/* end assertClassOf:is: */;
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
				goto l2;
			} else {
				totalLength = (sz1 - 4) - (fmt & 3);
				goto l2;
			}
		l2:	/* end lengthOf:baseHeader:format: */;
			/* begin fixedFieldsOf:format:length: */
			if ((fmt > 4) || (fmt == 2)) {
				fixedFields = 0;
				goto l1;
			}
			if (fmt < 2) {
				fixedFields = totalLength;
				goto l1;
			}
			/* begin fetchClassOf: */
			if ((s & 1)) {
				class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
				goto l3;
			}
			ccIndex = (((unsigned) (longAt(s))) >> 12) & 31;
			if (ccIndex == 0) {
				class = (longAt(s - 4)) & 4294967292U;
				goto l3;
			} else {
				class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
				goto l3;
			}
		l3:	/* end fetchClassOf: */;
			classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
			fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
		l1:	/* end fixedFieldsOf:format:length: */;
			if ((fmt == 3) && (isContextHeader(hdr))) {
				/* begin fetchStackPointerOf: */
				sp1 = longAt(((((char *) s)) + 4) + (2 << 2));
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

int primitiveClone(void) {
    int newCopy;
    int sp;

	newCopy = clone(longAt(stackPointer));
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((1 - 1) * 4), newCopy);
	stackPointer = sp;
}

int primitiveConstantFill(void) {
    int i;
    int end;
    int fillValue;
    int rcvr;
    int rcvrIsBytes;
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

int primitiveCopyBits(void) {
    int rcvr;
    int successValue;

	rcvr = longAt(stackPointer - (argumentCount * 4));
	/* begin success: */
	successValue = loadBitBltFrom(rcvr);
	successFlag = successValue && successFlag;
	if (successFlag) {
		copyBits();
		showDisplayBits();
	}
}

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

int primitiveDirectoryCreate(void) {
    int dirName;
    int dirNameIndex;
    int dirNameSize;
    int header;
    int sz;

	dirName = longAt(stackPointer);
	/* begin success: */
	successFlag = (((((unsigned) (longAt(dirName))) >> 8) & 15) >= 8) && successFlag;
	if (successFlag) {
		dirNameIndex = dirName + 4;
		/* begin lengthOf: */
		header = longAt(dirName);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(dirName - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			dirNameSize = ((unsigned) (sz - 4)) >> 2;
			goto l1;
		} else {
			dirNameSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
	}
	if (successFlag) {
		/* begin success: */
		successFlag = (dir_Create((char *) dirNameIndex, dirNameSize)) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveDirectoryDelete(void) {
    int dirName;
    int dirNameIndex;
    int dirNameSize;
    int header;
    int sz;

	dirName = longAt(stackPointer);
	/* begin success: */
	successFlag = (((((unsigned) (longAt(dirName))) >> 8) & 15) >= 8) && successFlag;
	if (successFlag) {
		dirNameIndex = dirName + 4;
		/* begin lengthOf: */
		header = longAt(dirName);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(dirName - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			dirNameSize = ((unsigned) (sz - 4)) >> 2;
			goto l1;
		} else {
			dirNameSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
	}
	if (successFlag) {
		/* begin success: */
		successFlag = (dir_Delete((char *) dirNameIndex, dirNameSize)) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveDirectoryDelimitor(void) {
    int ascii;
    int sp;
    int successValue;

	ascii = asciiDirectoryDelimiter();
	/* begin success: */
	successValue = (ascii >= 0) && (ascii <= 255);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (24 << 2))))) + 4) + (ascii << 2)));
		stackPointer = sp;
	}
}

int primitiveDirectoryLookup(void) {
    int dirFlag;
    int pathName;
    int pathNameIndex;
    int pathNameSize;
    int status;
    int modifiedDate;
    char entryName[256];
    int entryNameSize;
    int index;
    int createDate;
    int fileSize;
    int header;
    int sz;
    int sp;
    int object;
    int sp1;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	pathName = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successFlag = (((((unsigned) (longAt(pathName))) >> 8) & 15) >= 8) && successFlag;
	if (successFlag) {
		pathNameIndex = pathName + 4;
		/* begin lengthOf: */
		header = longAt(pathName);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(pathName - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			pathNameSize = ((unsigned) (sz - 4)) >> 2;
			goto l1;
		} else {
			pathNameSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l1;
		}
		pathNameSize = null;
	l1:	/* end lengthOf: */;
	}
	if (successFlag) {
		status = dir_Lookup(
				(char *) pathNameIndex, pathNameSize, index,
				entryName, &entryNameSize, &createDate, &modifiedDate,
				&dirFlag, &fileSize);
		if (status == 1) {
			/* begin pop: */
			stackPointer -= 3 * 4;
			/* begin push: */
			longAtput(sp = stackPointer + 4, nilObj);
			stackPointer = sp;
			return null;
		}
		if (status == 2) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
		/* begin push: */
		object = makeDirEntryNamesizecreateDatemodDateisDirfileSize(entryName, entryNameSize, createDate, modifiedDate, dirFlag, fileSize);
		longAtput(sp1 = stackPointer + 4, object);
		stackPointer = sp1;
	}
}

int primitiveDirectorySetMacTypeAndCreator(void) {
    int typeStringIndex;
    int typeString;
    int creatorString;
    int fileName;
    int creatorStringIndex;
    int fileNameIndex;
    int fileNameSize;
    int header;
    int sz;
    int successValue;
    int successValue1;

	creatorString = longAt(stackPointer);
	typeString = longAt(stackPointer - (1 * 4));
	fileName = longAt(stackPointer - (2 * 4));
	/* begin success: */
	successValue = (((((unsigned) (longAt(creatorString))) >> 8) & 15) >= 8) && ((lengthOf(creatorString)) == 4);
	successFlag = successValue && successFlag;
	/* begin success: */
	successValue1 = (((((unsigned) (longAt(typeString))) >> 8) & 15) >= 8) && ((lengthOf(typeString)) == 4);
	successFlag = successValue1 && successFlag;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(fileName))) >> 8) & 15) >= 8) && successFlag;
	if (successFlag) {
		creatorStringIndex = creatorString + 4;
		typeStringIndex = typeString + 4;
		fileNameIndex = fileName + 4;
		/* begin lengthOf: */
		header = longAt(fileName);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(fileName - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			fileNameSize = ((unsigned) (sz - 4)) >> 2;
			goto l1;
		} else {
			fileNameSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l1;
		}
		fileNameSize = null;
	l1:	/* end lengthOf: */;
	}
	if (successFlag) {
		/* begin success: */
		successFlag = (dir_SetMacFileTypeAndCreator(
				(char *) fileNameIndex, fileNameSize,
				(char *) typeStringIndex, (char *) creatorStringIndex)) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
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
    int integerReceiver;
    int integerArgument;
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
    int primIdx;
    int argumentArray;
    int arraySize;
    int index;
    int cntxSize;
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
    int ccIndex;
    int cl;

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

int primitiveDrawLoop(void) {
    int yDelta;
    int rcvr;
    int xDelta;
    int affL;
    int dx1;
    int dy1;
    int px;
    int py;
    int affR;
    int affT;
    int affB;
    int i;
    int P;
    int integerPointer;
    int integerPointer1;
    int successValue;

	rcvr = longAt(stackPointer - (2 * 4));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		xDelta = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		xDelta = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (0 * 4));
	if ((integerPointer1 & 1)) {
		yDelta = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		yDelta = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin success: */
	successValue = loadBitBltFrom(rcvr);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin drawLoopX:Y: */
		if (xDelta > 0) {
			dx1 = 1;
		} else {
			if (xDelta == 0) {
				dx1 = 0;
			} else {
				dx1 = -1;
			}
		}
		if (yDelta > 0) {
			dy1 = 1;
		} else {
			if (yDelta == 0) {
				dy1 = 0;
			} else {
				dy1 = -1;
			}
		}
		px = abs(yDelta);
		py = abs(xDelta);
		affL = affT = 9999;
		affR = affB = -9999;
		if (py > px) {
			P = ((int) py >> 1);
			for (i = 1; i <= py; i += 1) {
				destX += dx1;
				if ((P -= px) < 0) {
					destY += dy1;
					P += py;
				}
				if (i < py) {
					copyBits();
					if ((affectedL < affectedR) && (affectedT < affectedB)) {
						affL = ((affL < affectedL) ? affL : affectedL);
						affR = ((affR < affectedR) ? affectedR : affR);
						affT = ((affT < affectedT) ? affT : affectedT);
						affB = ((affB < affectedB) ? affectedB : affB);
						if (((affR - affL) * (affB - affT)) > 4000) {
							affectedL = affL;
							affectedR = affR;
							affectedT = affT;
							affectedB = affB;
							showDisplayBits();
							affL = affT = 9999;
							affR = affB = -9999;
						}
					}
				}
			}
		} else {
			P = ((int) px >> 1);
			for (i = 1; i <= px; i += 1) {
				destY += dy1;
				if ((P -= py) < 0) {
					destX += dx1;
					P += px;
				}
				if (i < px) {
					copyBits();
					if ((affectedL < affectedR) && (affectedT < affectedB)) {
						affL = ((affL < affectedL) ? affL : affectedL);
						affR = ((affR < affectedR) ? affectedR : affR);
						affT = ((affT < affectedT) ? affT : affectedT);
						affB = ((affB < affectedB) ? affectedB : affB);
						if (((affR - affL) * (affB - affT)) > 4000) {
							affectedL = affL;
							affectedR = affR;
							affectedT = affT;
							affectedB = affB;
							showDisplayBits();
							affL = affT = 9999;
							affR = affB = -9999;
						}
					}
				}
			}
		}
		affectedL = affL;
		affectedR = affR;
		affectedT = affT;
		affectedB = affB;
		/* begin storeInteger:ofObject:withValue: */
		if ((destX ^ (destX << 1)) >= 0) {
			longAtput(((((char *) bitBltOop)) + 4) + (4 << 2), ((destX << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
		/* begin storeInteger:ofObject:withValue: */
		if ((destY ^ (destY << 1)) >= 0) {
			longAtput(((((char *) bitBltOop)) + 4) + (5 << 2), ((destY << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
		showDisplayBits();
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
	}
}

int primitiveEqual(void) {
    int integerReceiver;
    int integerArgument;
    int result;
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
    int thisObject;
    int otherObject;
    int sp;
    int sp1;
    int top;
    int top1;

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

int primitiveExponent(void) {
    int pwr;
    double frac;
    double rcvr;
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

int primitiveExternalCall(void) {
    int addr;
    int moduleName;
    int moduleLength;
    int session;
    static int thisSession = 0;
    int lit;
    int functionAddress;
    int functionName;
    int functionLength;
    int header;
    int sz;
    int oop;
    int successValue;
    int header1;
    int sz1;

	if (thisSession == 0) {
		thisSession = (ioMicroMSecs()) & 536870911;
		if (thisSession == 0) {
			thisSession = 1;
		}
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(((((char *) newMethod)) + 4) + (0 << 2)))) >> 10) & 255) > 0) && successFlag;
	if (!(successFlag)) {
		return null;
	}
	lit = longAt(((((char *) newMethod)) + 4) + ((0 + 1) << 2));
	/* begin success: */
	successValue = ((fetchClassOf(lit)) == (longAt(((((char *) specialObjectsOop)) + 4) + (7 << 2)))) && ((lengthOf(lit)) == 4);
	successFlag = successValue && successFlag;
	if (!(successFlag)) {
		return null;
	}
	addr = positive32BitValueOf(longAt(((((char *) lit)) + 4) + (3 << 2)));
	session = fetchIntegerofObject(2, lit);
	if (successFlag && ((session == thisSession) && (addr != 0))) {
		return  ((int (*) (void)) addr) ();
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
		goto l2;
	} else {
		functionLength = (sz1 - 4) - (((((unsigned) header1) >> 8) & 15) & 3);
		goto l2;
	}
	functionLength = null;
l2:	/* end lengthOf: */;
	if (!(successFlag)) {
		return null;
	}
	addr = ioLoadExternalFunctionOfLengthFromModuleOfLength(functionName + 4, functionLength, moduleName + 4, moduleLength);
	/* begin success: */
	successFlag = (addr != 0) && successFlag;
	if (successFlag) {
		/* begin storeInteger:ofObject:withValue: */
		if ((thisSession ^ (thisSession << 1)) >= 0) {
			longAtput(((((char *) lit)) + 4) + (2 << 2), ((thisSession << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
		/* begin pushRemappableOop: */
		remapBuffer[remapBufferCount += 1] = lit;
		functionAddress = positive32BitIntegerFor(addr);
		/* begin popRemappableOop */
		oop = remapBuffer[remapBufferCount];
		remapBufferCount -= 1;
		lit = oop;
		/* begin storePointer:ofObject:withValue: */
		if (lit < youngStart) {
			possibleRootStoreIntovalue(lit, functionAddress);
		}
		longAtput(((((char *) lit)) + 4) + (3 << 2), functionAddress);
		if (successFlag && (addr != 0)) {
			 ((int (*) (void)) addr) ();
		}
	}
}

EXPORT(int) primitiveFFTPermuteData(void) {
    int rcvr;
    int oop;

	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l1;
	}
	rcvr = oop;
l1:	/* end stackObjectValue: */;
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	permuteData();
	if (!successFlag) {
		permuteData();
	}
}

EXPORT(int) primitiveFFTScaleData(void) {
    int rcvr;
    int oop;

	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l1;
	}
	rcvr = oop;
l1:	/* end stackObjectValue: */;
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	scaleData();
}

EXPORT(int) primitiveFFTTransformData(void) {
    int forward;
    int rcvr;
    int oop;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (0 * 4))) == trueObj) {
		forward = 1;
		goto l1;
	}
	if ((longAt(stackPointer - (0 * 4))) == falseObj) {
		forward = 0;
		goto l1;
	}
	successFlag = 0;
	forward = null;
l1:	/* end booleanValueOf: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop;
l2:	/* end stackObjectValue: */;
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	/* begin transformData: */
	permuteData();
	if (!successFlag) {
		permuteData();
		goto l3;
	}
	transformForward(forward);
	if (!(forward)) {
		scaleData();
	}
l3:	/* end transformData: */;
	if (!(!successFlag)) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveFail(void) {
	successFlag = 0;
}

int primitiveFileAtEnd(void) {
    int atEnd;
    SQFile *file;
    int sp;
    int sp1;

	file = fileValueOf(longAt(stackPointer));
	if (successFlag) {
		atEnd = sqFileAtEnd(file);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (atEnd) {
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

int primitiveFileClose(void) {
    SQFile *file;

	file = fileValueOf(longAt(stackPointer));
	if (successFlag) {
		sqFileClose(file);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveFileDelete(void) {
    int nameIndex;
    int namePointer;
    int nameSize;
    int header;
    int sz;

	namePointer = longAt(stackPointer);
	/* begin success: */
	successFlag = (((((unsigned) (longAt(namePointer))) >> 8) & 15) >= 8) && successFlag;
	if (successFlag) {
		nameIndex = namePointer + 4;
		/* begin lengthOf: */
		header = longAt(namePointer);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(namePointer - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			nameSize = ((unsigned) (sz - 4)) >> 2;
			goto l1;
		} else {
			nameSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l1;
		}
		nameSize = null;
	l1:	/* end lengthOf: */;
	}
	if (successFlag) {
		sqFileDeleteNameSize(nameIndex, nameSize);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveFileGetPosition(void) {
    int position;
    SQFile *file;
    int oop;
    int sp;

	file = fileValueOf(longAt(stackPointer));
	if (successFlag) {
		position = sqFileGetPosition(file);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = positive32BitIntegerFor(position);
		longAtput(sp = stackPointer - ((2 - 1) * 4), oop);
		stackPointer = sp;
	}
}

int primitiveFileOpen(void) {
    int writeFlag;
    int nameIndex;
    int namePointer;
    int nameSize;
    int filePointer;
    SQFile *file;
    int header;
    int sp;
    int sz;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer)) == trueObj) {
		writeFlag = 1;
		goto l1;
	}
	if ((longAt(stackPointer)) == falseObj) {
		writeFlag = 0;
		goto l1;
	}
	successFlag = 0;
	writeFlag = null;
l1:	/* end booleanValueOf: */;
	namePointer = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successFlag = (((((unsigned) (longAt(namePointer))) >> 8) & 15) >= 8) && successFlag;
	if (successFlag) {
		filePointer = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (26 << 2)), fileRecordSize());
		file = fileValueOf(filePointer);
		nameIndex = namePointer + 4;
		/* begin lengthOf: */
		header = longAt(namePointer);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(namePointer - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			nameSize = ((unsigned) (sz - 4)) >> 2;
			goto l2;
		} else {
			nameSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l2;
		}
	l2:	/* end lengthOf:baseHeader:format: */;
	}
	if (successFlag) {
		sqFileOpen(file, nameIndex, nameSize, writeFlag);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, filePointer);
		stackPointer = sp;
	}
}

int primitiveFileRead(void) {
    int array;
    int startIndex;
    int arrayIndex;
    int bytesRead;
    int byteSize;
    int count;
    SQFile *file;
    int sp;
    int integerPointer;
    int integerPointer1;
    int successValue;
    int successValue1;
    int fmt;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		startIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	array = longAt(stackPointer - (2 * 4));
	file = fileValueOf(longAt(stackPointer - (3 * 4)));
	/* begin success: */
	/* begin isWordsOrBytes: */
	fmt = (((unsigned) (longAt(array))) >> 8) & 15;
	successValue = (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
	successFlag = successValue && successFlag;
	if (((((unsigned) (longAt(array))) >> 8) & 15) == 6) {
		byteSize = 4;
	} else {
		byteSize = 1;
	}
	/* begin success: */
	successValue1 = (startIndex >= 1) && (((startIndex + count) - 1) <= (lengthOf(array)));
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		arrayIndex = array + 4;
		bytesRead = sqFileReadIntoAt(file, count * byteSize, arrayIndex, (startIndex - 1) * byteSize);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, (((bytesRead / byteSize) << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveFileRename(void) {
    int newNameIndex;
    int newNamePointer;
    int newNameSize;
    int oldNamePointer;
    int oldNameIndex;
    int oldNameSize;
    int header;
    int header1;
    int sz;
    int sz1;

	newNamePointer = longAt(stackPointer);
	oldNamePointer = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successFlag = (((((unsigned) (longAt(newNamePointer))) >> 8) & 15) >= 8) && successFlag;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(oldNamePointer))) >> 8) & 15) >= 8) && successFlag;
	if (successFlag) {
		newNameIndex = newNamePointer + 4;
		/* begin lengthOf: */
		header = longAt(newNamePointer);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(newNamePointer - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			newNameSize = ((unsigned) (sz - 4)) >> 2;
			goto l1;
		} else {
			newNameSize = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
		oldNameIndex = oldNamePointer + 4;
		/* begin lengthOf: */
		header1 = longAt(oldNamePointer);
		/* begin lengthOf:baseHeader:format: */
		if ((header1 & 3) == 0) {
			sz1 = (longAt(oldNamePointer - 8)) & 4294967292U;
		} else {
			sz1 = header1 & 252;
		}
		if (((((unsigned) header1) >> 8) & 15) < 8) {
			oldNameSize = ((unsigned) (sz1 - 4)) >> 2;
			goto l2;
		} else {
			oldNameSize = (sz1 - 4) - (((((unsigned) header1) >> 8) & 15) & 3);
			goto l2;
		}
	l2:	/* end lengthOf:baseHeader:format: */;
	}
	if (successFlag) {
		sqFileRenameOldSizeNewSize(oldNameIndex, oldNameSize, newNameIndex, newNameSize);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
	}
}

int primitiveFileSetPosition(void) {
    int newPosition;
    SQFile *file;

	newPosition = positive32BitValueOf(longAt(stackPointer - (0 * 4)));
	file = fileValueOf(longAt(stackPointer - (1 * 4)));
	if (successFlag) {
		sqFileSetPosition(file, newPosition);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
	}
}

int primitiveFileSize(void) {
    int size;
    SQFile *file;
    int oop;
    int sp;

	file = fileValueOf(longAt(stackPointer));
	if (successFlag) {
		size = sqFileSize(file);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = positive32BitIntegerFor(size);
		longAtput(sp = stackPointer - ((2 - 1) * 4), oop);
		stackPointer = sp;
	}
}

int primitiveFileWrite(void) {
    int array;
    int startIndex;
    int arrayIndex;
    int bytesWritten;
    int byteSize;
    int count;
    SQFile *file;
    int sp;
    int integerPointer;
    int integerPointer1;
    int successValue;
    int successValue1;
    int fmt;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		startIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	array = longAt(stackPointer - (2 * 4));
	file = fileValueOf(longAt(stackPointer - (3 * 4)));
	/* begin success: */
	/* begin isWordsOrBytes: */
	fmt = (((unsigned) (longAt(array))) >> 8) & 15;
	successValue = (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
	successFlag = successValue && successFlag;
	if (((((unsigned) (longAt(array))) >> 8) & 15) == 6) {
		byteSize = 4;
	} else {
		byteSize = 1;
	}
	/* begin success: */
	successValue1 = (startIndex >= 1) && (((startIndex + count) - 1) <= (lengthOf(array)));
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		arrayIndex = array + 4;
		bytesWritten = sqFileWriteFromAt(file, count * byteSize, arrayIndex, (startIndex - 1) * byteSize);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, (((bytesWritten / byteSize) << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveFloatAddtoArg(int rcvrOop, int argOop) {
    double arg;
    double rcvr;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		pushFloat(rcvr + arg);
	}
}

EXPORT(int) primitiveFloatArrayAddFloatArray(void) {
    int arg;
    int i;
    float *argPtr;
    int rcvr;
    float *rcvrPtr;
    int length;
    int oop;
    int oop1;
    int successValue;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

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
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(arg))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
	hdr = longAt(arg);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(arg - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l5;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l5;
	}
l5:	/* end lengthOf:baseHeader:format: */;
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
	if ((arg & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(arg))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(arg - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) arg)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l6;
		}
		length = (sp >> 1);
		goto l6;
	} else {
		length = totalLength - fixedFields;
		goto l6;
	}
l6:	/* end stSizeOf: */;
	/* begin success: */
	successValue = length == (stSizeOf(rcvr));
	successFlag = successValue && successFlag;
	if (!successFlag) {
		return null;
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) + (argPtr[i]));
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) primitiveFloatArrayAddScalar(void) {
    int i;
    double value;
    int rcvr;
    float *rcvrPtr;
    int length;
    int oop;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

	value = stackFloatValue(0);
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l1;
	}
	rcvr = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
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
		goto l4;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l4;
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
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) rcvr)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l5;
		}
		length = (sp >> 1);
		goto l5;
	} else {
		length = totalLength - fixedFields;
		goto l5;
	}
l5:	/* end stSizeOf: */;
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) + value);
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) primitiveFloatArrayAt(void) {
    float *floatPtr;
    double floatValue;
    int rcvr;
    int index;
    int integerPointer;
    int oop;
    int successValue;

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
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successValue = (index > 0) && (index <= (slotSizeOf(rcvr)));
	successFlag = successValue && successFlag;
	if (!successFlag) {
		return null;
	}
	floatPtr = firstIndexableField(rcvr);
	floatValue = ((double) (floatPtr[index - 1]) );
	/* begin pop: */
	stackPointer -= 2 * 4;
	pushFloat(floatValue);
}

EXPORT(int) primitiveFloatArrayAtPut(void) {
    float *floatPtr;
    double floatValue;
    int value;
    int rcvr;
    int index;
    int sp;
    int integerPointer;
    int oop;
    int successValue;

	value = longAt(stackPointer - (0 * 4));
	if ((value & 1)) {
		floatValue = ((double) ((value >> 1)) );
	} else {
		floatValue = floatValueOf(value);
	}
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
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (2 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successValue = (index > 0) && (index <= (slotSizeOf(rcvr)));
	successFlag = successValue && successFlag;
	if (!successFlag) {
		return null;
	}
	floatPtr = firstIndexableField(rcvr);
	floatPtr[index - 1] = (((float) floatValue));
	if (!(!successFlag)) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((3 - 1) * 4), value);
		stackPointer = sp;
	}
}

EXPORT(int) primitiveFloatArrayDivFloatArray(void) {
    int arg;
    int i;
    float *argPtr;
    int rcvr;
    float *rcvrPtr;
    int length;
    int oop;
    int oop1;
    int successValue;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

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
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(arg))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
	hdr = longAt(arg);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(arg - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l5;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l5;
	}
l5:	/* end lengthOf:baseHeader:format: */;
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
	if ((arg & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(arg))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(arg - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) arg)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l6;
		}
		length = (sp >> 1);
		goto l6;
	} else {
		length = totalLength - fixedFields;
		goto l6;
	}
l6:	/* end stSizeOf: */;
	/* begin success: */
	successValue = length == (stSizeOf(rcvr));
	successFlag = successValue && successFlag;
	if (!successFlag) {
		return null;
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		if ((longAt(argPtr + i)) == 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) / (argPtr[i]));
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) primitiveFloatArrayDivScalar(void) {
    int length;
    int i;
    double value;
    int rcvr;
    float *rcvrPtr;
    double inverse;
    int oop;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

	value = stackFloatValue(0);
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l1;
	}
	rcvr = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (value == 0.0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
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
		goto l4;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l4;
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
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) rcvr)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l5;
		}
		length = (sp >> 1);
		goto l5;
	} else {
		length = totalLength - fixedFields;
		goto l5;
	}
l5:	/* end stSizeOf: */;
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	inverse = 1.0 / value;
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) * inverse);
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) primitiveFloatArrayEqual(void) {
    int arg;
    int i;
    float *argPtr;
    int rcvr;
    float *rcvrPtr;
    int length;
    int sp;
    int sp1;
    int sp2;
    int sp11;
    int oop;
    int oop1;
    int sp3;
    int sp12;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp4;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

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
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(arg))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin pop: */
	stackPointer -= 2 * 4;
	/* begin stSizeOf: */
	hdr = longAt(arg);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(arg - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l5;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l5;
	}
l5:	/* end lengthOf:baseHeader:format: */;
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
	if ((arg & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(arg))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(arg - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp4 = longAt(((((char *) arg)) + 4) + (2 << 2));
		if (!((sp4 & 1))) {
			length = 0;
			goto l6;
		}
		length = (sp4 >> 1);
		goto l6;
	} else {
		length = totalLength - fixedFields;
		goto l6;
	}
l6:	/* end stSizeOf: */;
	if (!(length == (stSizeOf(rcvr)))) {
		/* begin pushBool: */
				/* begin push: */
		longAtput(sp1 = stackPointer + 4, falseObj);
		stackPointer = sp1;
;
		return null;
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		if (!((rcvrPtr[i]) == (argPtr[i]))) {
			/* begin pushBool: */
						/* begin push: */
			longAtput(sp11 = stackPointer + 4, falseObj);
			stackPointer = sp11;
;
			return null;
		}
	}
	/* begin pushBool: */
		/* begin push: */
	longAtput(sp3 = stackPointer + 4, trueObj);
	stackPointer = sp3;
;
	return null;
}

EXPORT(int) primitiveFloatArrayHash(void) {
    int result;
    int i;
    int rcvr;
    int *rcvrPtr;
    int length;
    int oop;
    int sp;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp1;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l1;
	}
	rcvr = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
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
		goto l4;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l4;
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
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp1 = longAt(((((char *) rcvr)) + 4) + (2 << 2));
		if (!((sp1 & 1))) {
			length = 0;
			goto l5;
		}
		length = (sp1 >> 1);
		goto l5;
	} else {
		length = totalLength - fixedFields;
		goto l5;
	}
l5:	/* end stSizeOf: */;
	rcvrPtr = ((int *) (firstIndexableField(rcvr)));
	result = 0;
	for (i = 0; i <= (length - 1); i += 1) {
		result += rcvrPtr[i];
		rcvrPtr += 4;
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, (((result & 536870911) << 1) | 1));
	stackPointer = sp;
	return null;
}

EXPORT(int) primitiveFloatArrayMulFloatArray(void) {
    int arg;
    int i;
    float *argPtr;
    int rcvr;
    float *rcvrPtr;
    int length;
    int oop;
    int oop1;
    int successValue;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

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
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(arg))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
	hdr = longAt(arg);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(arg - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l5;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l5;
	}
l5:	/* end lengthOf:baseHeader:format: */;
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
	if ((arg & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(arg))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(arg - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) arg)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l6;
		}
		length = (sp >> 1);
		goto l6;
	} else {
		length = totalLength - fixedFields;
		goto l6;
	}
l6:	/* end stSizeOf: */;
	/* begin success: */
	successValue = length == (stSizeOf(rcvr));
	successFlag = successValue && successFlag;
	if (!successFlag) {
		return null;
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) * (argPtr[i]));
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) primitiveFloatArrayMulScalar(void) {
    int i;
    double value;
    int rcvr;
    float *rcvrPtr;
    int length;
    int oop;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

	value = stackFloatValue(0);
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l1;
	}
	rcvr = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
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
		goto l4;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l4;
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
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) rcvr)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l5;
		}
		length = (sp >> 1);
		goto l5;
	} else {
		length = totalLength - fixedFields;
		goto l5;
	}
l5:	/* end stSizeOf: */;
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) * value);
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) primitiveFloatArraySubFloatArray(void) {
    int arg;
    int i;
    float *argPtr;
    int rcvr;
    float *rcvrPtr;
    int length;
    int oop;
    int oop1;
    int successValue;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

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
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(arg))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
	hdr = longAt(arg);
	fmt = (((unsigned) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & 3) == 0) {
		sz = (longAt(arg - 8)) & 4294967292U;
	} else {
		sz = hdr & 252;
	}
	if (fmt < 8) {
		totalLength = ((unsigned) (sz - 4)) >> 2;
		goto l5;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l5;
	}
l5:	/* end lengthOf:baseHeader:format: */;
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
	if ((arg & 1)) {
		class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
		goto l3;
	}
	ccIndex = (((unsigned) (longAt(arg))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(arg - 4)) & 4294967292U;
		goto l3;
	} else {
		class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
	fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) arg)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l6;
		}
		length = (sp >> 1);
		goto l6;
	} else {
		length = totalLength - fixedFields;
		goto l6;
	}
l6:	/* end stSizeOf: */;
	/* begin success: */
	successValue = length == (stSizeOf(rcvr));
	successFlag = successValue && successFlag;
	if (!successFlag) {
		return null;
	}
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	argPtr = ((float *) (firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) - (argPtr[i]));
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

EXPORT(int) primitiveFloatArraySubScalar(void) {
    int i;
    double value;
    int rcvr;
    float *rcvrPtr;
    int length;
    int oop;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
    int ccIndex;

	value = stackFloatValue(0);
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * 4));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l1;
	}
	rcvr = oop;
l1:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	/* begin success: */
	successFlag = (((((unsigned) (longAt(rcvr))) >> 8) & 15) == 6) && successFlag;
	if (!successFlag) {
		return null;
	}
	/* begin stSizeOf: */
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
		goto l4;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l4;
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
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && (isContextHeader(hdr))) {
		/* begin fetchStackPointerOf: */
		sp = longAt(((((char *) rcvr)) + 4) + (2 << 2));
		if (!((sp & 1))) {
			length = 0;
			goto l5;
		}
		length = (sp >> 1);
		goto l5;
	} else {
		length = totalLength - fixedFields;
		goto l5;
	}
l5:	/* end stSizeOf: */;
	rcvrPtr = ((float *) (firstIndexableField(rcvr)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((rcvrPtr[i]) - value);
	}
	/* begin pop: */
	stackPointer -= 1 * 4;
}

int primitiveFloatDividebyArg(int rcvrOop, int argOop) {
    double arg;
    double rcvr;

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
    double arg;
    double rcvr;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		return rcvr == arg;
	}
}

int primitiveFloatGreaterthanArg(int rcvrOop, int argOop) {
    double arg;
    double rcvr;

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
    double arg;
    double rcvr;

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

int primitiveFloatMultiplybyArg(int rcvrOop, int argOop) {
    double arg;
    double rcvr;

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

int primitiveFloatSubtractfromArg(int rcvrOop, int argOop) {
    double arg;
    double rcvr;

	rcvr = loadFloatOrIntFrom(rcvrOop);
	arg = loadFloatOrIntFrom(argOop);
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		pushFloat(rcvr - arg);
	}
}

int primitiveFlushCache(void) {
    int i;

	/* begin flushMethodCache */
	for (i = 1; i <= 2048; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= 64; i += 1) {
		atCache[i] = 0;
	}
}

int primitiveFlushCacheByMethod(void) {
    int probe;
    int i;
    int oldMethod;

	oldMethod = longAt(stackPointer);
	probe = 0;
	for (i = 1; i <= 512; i += 1) {
		if ((methodCache[probe + 3]) == oldMethod) {
			methodCache[probe + 1] = 0;
		}
		probe += 4;
	}
	/* begin compilerFlushCacheHook: */
	if (compilerInitialized) {
		compilerFlushCache(oldMethod);
	}
}

int primitiveFlushCacheSelective(void) {
    int probe;
    int selector;
    int i;

	selector = longAt(stackPointer);
	probe = 0;
	for (i = 1; i <= 512; i += 1) {
		if ((methodCache[probe + 1]) == selector) {
			methodCache[probe + 1] = 0;
		}
		probe += 4;
	}
}

int primitiveForceDisplayUpdate(void) {
	ioForceDisplayUpdate();
}

int primitiveFormPrint(void) {
    double vScale;
    int depth;
    int pixelsPerWord;
    int bitsArray;
    double hScale;
    int wordsPerLine;
    int h;
    int w;
    int bitsArraySize;
    int landscapeFlag;
    int rcvr;
    int ok;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer)) == trueObj) {
		landscapeFlag = 1;
		goto l1;
	}
	if ((longAt(stackPointer)) == falseObj) {
		landscapeFlag = 0;
		goto l1;
	}
	successFlag = 0;
	landscapeFlag = null;
l1:	/* end booleanValueOf: */;
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
			bitsArraySize = byteLengthOf(bitsArray);
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
    double trunc;
    double frac;
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

int primitiveFullGC(void) {
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	incrementalGC();
	fullGC();
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, ((((longAt(freeBlock)) & 4294967292U) << 1) | 1));
	stackPointer = sp;
}

int primitiveGetAttribute(void) {
    int attr;
    int sz;
    int s;
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

int primitiveGetTabletParameters(void) {
    int cursorIndex;
    int resultSize;
    int result;
    int sp;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		cursorIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		cursorIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		resultSize = tabletResultSize();
		result = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2)), resultSize);
		/* begin success: */
		successFlag = (tabletGetParameters(cursorIndex, (int *) (result + 4))) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, result);
		stackPointer = sp;
	}
}

int primitiveGreaterOrEqual(void) {
    int integerReceiver;
    int integerArgument;
    int integerPointer;
    int top;
    int integerPointer1;
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
    int integerReceiver;
    int integerArgument;
    int integerPointer;
    int top;
    int integerPointer1;
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

int primitiveImageName(void) {
    int sz;
    int s;
    int sp;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp1;
    int classFormat;
    int class;
    int sz1;
    int ccIndex;
    int ccIndex1;
    int cl;

	if (argumentCount == 1) {
		s = longAt(stackPointer);
		/* begin assertClassOf:is: */
		if ((s & 1)) {
			successFlag = 0;
			goto l5;
		}
		ccIndex1 = (((unsigned) (longAt(s))) >> 12) & 31;
		if (ccIndex1 == 0) {
			cl = (longAt(s - 4)) & 4294967292U;
		} else {
			cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
		}
		/* begin success: */
		successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)))) && successFlag;
	l5:	/* end assertClassOf:is: */;
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
				goto l2;
			} else {
				totalLength = (sz1 - 4) - (fmt & 3);
				goto l2;
			}
		l2:	/* end lengthOf:baseHeader:format: */;
			/* begin fixedFieldsOf:format:length: */
			if ((fmt > 4) || (fmt == 2)) {
				fixedFields = 0;
				goto l1;
			}
			if (fmt < 2) {
				fixedFields = totalLength;
				goto l1;
			}
			/* begin fetchClassOf: */
			if ((s & 1)) {
				class = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
				goto l3;
			}
			ccIndex = (((unsigned) (longAt(s))) >> 12) & 31;
			if (ccIndex == 0) {
				class = (longAt(s - 4)) & 4294967292U;
				goto l3;
			} else {
				class = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
				goto l3;
			}
		l3:	/* end fetchClassOf: */;
			classFormat = (longAt(((((char *) class)) + 4) + (2 << 2))) - 1;
			fixedFields = (((((unsigned) classFormat) >> 11) & 192) + ((((unsigned) classFormat) >> 2) & 63)) - 1;
		l1:	/* end fixedFieldsOf:format:length: */;
			if ((fmt == 3) && (isContextHeader(hdr))) {
				/* begin fetchStackPointerOf: */
				sp1 = longAt(((((char *) s)) + 4) + (2 << 2));
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

int primitiveIncrementalGC(void) {
    int sp;

	/* begin pop: */
	stackPointer -= 1 * 4;
	incrementalGC();
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, ((((longAt(freeBlock)) & 4294967292U) << 1) | 1));
	stackPointer = sp;
}

int primitiveIndexOf(int methodPointer) {
    int primBits;

	primBits = (((unsigned) (longAt(((((char *) methodPointer)) + 4) + (0 << 2)))) >> 1) & 805306879;
	if (primBits > 511) {
		return (primBits & 511) + (((unsigned) primBits) >> 19);
	} else {
		return primBits;
	}
}

int primitiveInitializeNetwork(void) {
    int err;
    int resolverSemaIndex;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		resolverSemaIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		resolverSemaIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		err = sqNetworkInit(resolverSemaIndex);
		/* begin success: */
		successFlag = (err == 0) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveInputSemaphore(void) {
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
    int value;
    int hdr;
    int totalLength;
    int index;
    int rcvr;
    int fmt;
    int fixedFields;
    int sp;
    int top;
    int sz;
    int classFormat;
    int class;
    int integerPointer;
    int top1;
    int ccIndex;

	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	integerPointer = top1;
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l4;
	} else {
		successFlag = 0;
		index = 1;
		goto l4;
	}
l4:	/* end popInteger */;
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	rcvr = top;
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
	l2:	/* end fixedFieldsOf:format:length: */;
		if (!((index >= 1) && (index <= fixedFields))) {
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin subscript:with:format: */
		if (fmt <= 4) {
			value = longAt(((((char *) rcvr)) + 4) + ((index - 1) << 2));
			goto l3;
		}
		if (fmt < 8) {
			value = positive32BitIntegerFor(longAt(((((char *) rcvr)) + 4) + ((index - 1) << 2)));
			goto l3;
		} else {
			value = (((byteAt(((((char *) rcvr)) + 4) + (index - 1))) << 1) | 1);
			goto l3;
		}
	l3:	/* end subscript:with:format: */;
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
    int newValue;
    int totalLength;
    int index;
    int rcvr;
    int fmt;
    int fixedFields;
    int classFormat;
    int class;
    int sp;
    int top;
    int integerPointer;
    int top1;
    int top2;
    int sz;
    int ccIndex;
    int valueToStore;

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
		goto l2;
	} else {
		successFlag = 0;
		index = 1;
		goto l2;
	}
l2:	/* end popInteger */;
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
			goto l3;
		} else {
			totalLength = (sz - 4) - (fmt & 3);
			goto l3;
		}
	l3:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l1;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l1;
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
	l1:	/* end fixedFieldsOf:format:length: */;
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

int primitiveInstVarsPutFromStack(void) {
    int i;
    int rcvr;
    int offsetBits;

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
		longAtput(sp1 = stackPointer + 4, ((keystrokeWord << 1) | 1));
		stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp = stackPointer + 4, nilObj);
		stackPointer = sp;
	}
}

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
		longAtput(sp1 = stackPointer + 4, ((keystrokeWord << 1) | 1));
		stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp = stackPointer + 4, nilObj);
		stackPointer = sp;
	}
}

int primitiveLessOrEqual(void) {
    int integerReceiver;
    int integerArgument;
    int integerPointer;
    int top;
    int integerPointer1;
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
    int integerReceiver;
    int integerArgument;
    int integerPointer;
    int top;
    int integerPointer1;
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

int primitiveLoadImageSegment(void) {
    int outPtr;
    int segmentWordArray;
    int segOop;
    int doingClass;
    int mapOop;
    int endSeg;
    int header;
    int hdrTypeBits;
    int extraSize;
    int outPointerArray;
    int fieldPtr;
    int fieldOop;
    int lastPtr;
    int lastOut;
    int addr;
    int addr1;
    int extra;
    int extra1;
    int type;
    int extra2;
    int oop;
    int sp;
    int sz;
    int extra3;
    int header1;
    int type1;
    int extra11;
    int sz1;
    int extra4;
    int header2;
    int type2;
    int extra12;
    int type3;
    int extra5;
    int type4;
    int extra6;
    int extra7;
    int type5;
    int extra13;

	;
	outPointerArray = longAt(stackPointer - (0 * 4));
	lastOut = outPointerArray + (lastPointerOf(outPointerArray));
	segmentWordArray = longAt(stackPointer - (1 * 4));
	endSeg = (segmentWordArray + (sizeBitsOf(segmentWordArray))) - 4;
	if (!((((((unsigned) (longAt(outPointerArray))) >> 8) & 15) == 2) && (((((unsigned) (longAt(segmentWordArray))) >> 8) & 15) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((longAt(segmentWordArray + 4)) == 6502)) {
		/* begin reverseBytesFrom:to: */
		addr1 = segmentWordArray + 4;
		while (addr1 < (endSeg + 4)) {
			longAtput(addr1, ((((((unsigned) (longAt(addr1)) >> 24)) & 255) + ((((unsigned) (longAt(addr1)) >> 8)) & 65280)) + ((((unsigned) (longAt(addr1)) << 8)) & 16711680)) + ((((unsigned) (longAt(addr1)) << 24)) & 4278190080U));
			addr1 += 4;
		}
		if (!((longAt(segmentWordArray + 4)) == 6502)) {
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
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type3 = (longAt((segmentWordArray + 4) + 4)) & 3;
	if (type3 > 1) {
		extra5 = 0;
	} else {
		if (type3 == 1) {
			extra5 = 4;
		} else {
			extra5 = 8;
		}
	}
	extra = extra5;
	segOop = ((segmentWordArray + 4) + 4) + extra;
	while (segOop <= endSeg) {
		if (((longAt(segOop)) & 3) <= 1) {
			fieldPtr = segOop - 4;
			doingClass = 1;
		} else {
			fieldPtr = segOop + 4;
			doingClass = 0;
		}
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
		extra3 = extra11;
		segOop = (segOop + sz) + extra3;
	}
	/* begin oopFromChunk: */
	/* begin extraHeaderBytes: */
	type4 = (longAt((segmentWordArray + 4) + 4)) & 3;
	if (type4 > 1) {
		extra6 = 0;
	} else {
		if (type4 == 1) {
			extra6 = 4;
		} else {
			extra6 = 8;
		}
	}
	extra1 = extra6;
	segOop = ((segmentWordArray + 4) + 4) + extra1;
	while (segOop <= endSeg) {
		if (!(oopHasOKclass(segOop))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		fieldPtr = segOop + 4;
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
		type2 = (longAt(segOop + sz1)) & 3;
		if (type2 > 1) {
			extra12 = 0;
		} else {
			if (type2 == 1) {
				extra12 = 4;
			} else {
				extra12 = 8;
			}
		}
		extra4 = extra12;
		segOop = (segOop + sz1) + extra4;
	}
	/* begin extraHeaderBytes: */
	type = (longAt(segmentWordArray)) & 3;
	if (type > 1) {
		extra2 = 0;
	} else {
		if (type == 1) {
			extra2 = 4;
		} else {
			extra2 = 8;
		}
	}
	extraSize = extra2;
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
	type5 = (longAt((segmentWordArray + 4) + 4)) & 3;
	if (type5 > 1) {
		extra13 = 0;
	} else {
		if (type5 == 1) {
			extra13 = 4;
		} else {
			extra13 = 8;
		}
	}
	extra7 = extra13;
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

int primitiveMIDIClosePort(void) {
    int portNum;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		portNum = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		sqMIDIClosePort(portNum);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveMIDIGetClock(void) {
    int clockValue;
    int sp;

	clockValue = (sqMIDIGetClock()) & 536870911;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((clockValue << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveMIDIGetPortCount(void) {
    int n;
    int sp;

	n = sqMIDIGetPortCount();
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((n << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveMIDIGetPortDirectionality(void) {
    int dir;
    int portNum;
    int integerPointer;
    int sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		portNum = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		dir = sqMIDIGetPortDirectionality(portNum);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((dir << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveMIDIGetPortName(void) {
    char portName[256];
    int portNum;
    int sz;
    int nameObj;
    int namePtr;
    int sp;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		portNum = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		sz = sqMIDIGetPortName(portNum, (int) &portName, 255);
	}
	if (successFlag) {
		nameObj = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), sz);
		namePtr = nameObj + 4;
		memcpy((char *) namePtr, portName, sz);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, nameObj);
		stackPointer = sp;
	}
}

int primitiveMIDIOpenPort(void) {
    int semaIndex;
    int portNum;
    int clockRate;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		clockRate = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		clockRate = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		semaIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		semaIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (2 * 4));
	if ((integerPointer2 & 1)) {
		portNum = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	if (successFlag) {
		sqMIDIOpenPort(portNum, semaIndex, clockRate);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
	}
}

int primitiveMIDIParameterGetOrSet(void) {
    int whichParameter;
    int newValue;
    int currentValue;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int sp;

	if (argumentCount == 1) {
		/* begin stackIntegerValue: */
		integerPointer = longAt(stackPointer - (0 * 4));
		if ((integerPointer & 1)) {
			whichParameter = (integerPointer >> 1);
			goto l1;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			whichParameter = 0;
			goto l1;
		}
	l1:	/* end stackIntegerValue: */;
		if (!(successFlag)) {
			return null;
		}
		currentValue = sqMIDIParameter(whichParameter, false, 0);
		if (successFlag) {
			/* begin pop: */
			stackPointer -= 2 * 4;
			/* begin pushInteger: */
			/* begin push: */
			longAtput(sp = stackPointer + 4, ((currentValue << 1) | 1));
			stackPointer = sp;
		}
		return null;
	}
	if (argumentCount == 2) {
		/* begin stackIntegerValue: */
		integerPointer1 = longAt(stackPointer - (0 * 4));
		if ((integerPointer1 & 1)) {
			newValue = (integerPointer1 >> 1);
			goto l2;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			newValue = 0;
			goto l2;
		}
	l2:	/* end stackIntegerValue: */;
		/* begin stackIntegerValue: */
		integerPointer2 = longAt(stackPointer - (1 * 4));
		if ((integerPointer2 & 1)) {
			whichParameter = (integerPointer2 >> 1);
			goto l3;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			whichParameter = 0;
			goto l3;
		}
	l3:	/* end stackIntegerValue: */;
		if (!(successFlag)) {
			return null;
		}
		sqMIDIParameter(whichParameter, true, newValue);
		if (successFlag) {
			/* begin pop: */
			stackPointer -= 2 * 4;
		}
		return null;
	}
	/* begin primitiveFail */
	successFlag = 0;
}

int primitiveMIDIRead(void) {
    int array;
    int portNum;
    int arrayLength;
    int bytesRead;
    int fmt;
    int header;
    int sp;
    int integerPointer;
    int successValue;
    int sz;

	array = longAt(stackPointer - (0 * 4));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		portNum = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	fmt = (((unsigned) (longAt(array))) >> 8) & 15;
	/* begin success: */
	successValue = (fmt >= 8) && (fmt <= 11);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin lengthOf: */
		header = longAt(array);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(array - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			arrayLength = ((unsigned) (sz - 4)) >> 2;
			goto l2;
		} else {
			arrayLength = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l2;
		}
	l2:	/* end lengthOf:baseHeader:format: */;
		bytesRead = sqMIDIPortReadInto(portNum, arrayLength, array + 4);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((bytesRead << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveMIDIWrite(void) {
    int array;
    int portNum;
    int arrayLength;
    int time;
    int bytesWritten;
    int fmt;
    int header;
    int sp;
    int integerPointer;
    int integerPointer1;
    int successValue;
    int sz;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		time = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		time = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	array = longAt(stackPointer - (1 * 4));
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		portNum = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	fmt = (((unsigned) (longAt(array))) >> 8) & 15;
	/* begin success: */
	successValue = (fmt >= 8) && (fmt <= 11);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin lengthOf: */
		header = longAt(array);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz = (longAt(array - 8)) & 4294967292U;
		} else {
			sz = header & 252;
		}
		if (((((unsigned) header) >> 8) & 15) < 8) {
			arrayLength = ((unsigned) (sz - 4)) >> 2;
			goto l3;
		} else {
			arrayLength = (sz - 4) - (((((unsigned) header) >> 8) & 15) & 3);
			goto l3;
		}
	l3:	/* end lengthOf:baseHeader:format: */;
		bytesWritten = sqMIDIPortWriteFromAt(portNum, arrayLength, array + 4, time);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 4 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((bytesWritten << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveMakePoint(void) {
    int argument;
    int pt;
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

int primitiveMousePoint(void) {
    int y;
    int pointWord;
    int x;
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
    int integerRcvr;
    int integerArg;
    int integerResult;
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

int primitiveNew(void) {
    int spaceOkay;
    int class;
    int object;
    int sp;
    int okay;
    int format;
    int minFree;
    int minFree1;

	class = longAt(stackPointer - (0 * 4));
	/* begin sufficientSpaceToInstantiate:indexableSize: */
	format = (((unsigned) ((longAt(((((char *) class)) + 4) + (2 << 2))) - 1)) >> 8) & 15;
	if (((((unsigned ) 0)) > 0) && (format < 2)) {
		spaceOkay = 0;
		goto l1;
	}
	if (format < 8) {
		/* begin sufficientSpaceToAllocate: */
		minFree = (lowSpaceThreshold + (2500 + (0 * 4))) + 4;
		if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
			okay = 1;
			goto l2;
		} else {
			okay = sufficientSpaceAfterGC(minFree);
			goto l2;
		}
	l2:	/* end sufficientSpaceToAllocate: */;
	} else {
		/* begin sufficientSpaceToAllocate: */
		minFree1 = (lowSpaceThreshold + (2500 + 0)) + 4;
		if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree1))) {
			okay = 1;
			goto l3;
		} else {
			okay = sufficientSpaceAfterGC(minFree1);
			goto l3;
		}
	l3:	/* end sufficientSpaceToAllocate: */;
	}
	spaceOkay = okay;
l1:	/* end sufficientSpaceToInstantiate:indexableSize: */;
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
    int size;
    int i;
    int header;
    int theMethod;
    int bytecodeCount;
    int class;
    int literalCount;
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

int primitiveNewWithArg(void) {
    int spaceOkay;
    int size;
    int class;
    int okay;
    int format;
    int oop;
    int sp;
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
			goto l1;
		}
		if (format < 8) {
			/* begin sufficientSpaceToAllocate: */
			minFree = (lowSpaceThreshold + (2500 + (size * 4))) + 4;
			if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree))) {
				okay = 1;
				goto l2;
			} else {
				okay = sufficientSpaceAfterGC(minFree);
				goto l2;
			}
		l2:	/* end sufficientSpaceToAllocate: */;
		} else {
			/* begin sufficientSpaceToAllocate: */
			minFree1 = (lowSpaceThreshold + (2500 + size)) + 4;
			if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) >= (((unsigned ) minFree1))) {
				okay = 1;
				goto l3;
			} else {
				okay = sufficientSpaceAfterGC(minFree1);
				goto l3;
			}
		l3:	/* end sufficientSpaceToAllocate: */;
		}
		spaceOkay = okay;
	l1:	/* end sufficientSpaceToInstantiate:indexableSize: */;
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

int primitiveNext(void) {
    int array;
    int stream;
    int index;
    int limit;
    int result;
    int atIx;
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
    int object;
    int instance;
    int sp;
    int top;
    int thisClass;
    int classPointer;
    int thisObj;
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

int primitiveNextObject(void) {
    int object;
    int instance;
    int sp;
    int top;
    int sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	object = top;
	instance = accessibleObjectAfter(object);
	if (instance == null) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp1 = stackPointer + 4, ((0 << 1) | 1));
		stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp = stackPointer + 4, instance);
		stackPointer = sp;
	}
}

int primitiveNextPut(void) {
    int array;
    int stream;
    int value;
    int index;
    int limit;
    int atIx;
    int sp;
    int stSize;
    int valToPut;
    int fmt;
    int fixedFields;

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
			byteAtput(((((char *) array)) + 4) + (index - 1), (valToPut >> 1));
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

int primitiveNoop(void) {
	/* begin pop: */
	stackPointer -= argumentCount * 4;
}

int primitiveNotEqual(void) {
    int integerReceiver;
    int integerArgument;
    int result;
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

int primitiveObjectAt(void) {
    int thisReceiver;
    int index;
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

int primitiveObjectAtPut(void) {
    int thisReceiver;
    int newValue;
    int index;
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
    int thang;
    int rcvr;
    int lastField;
    int top;
    int top1;
    int sp;
    int sp1;
    int sp2;
    int sp3;
    int sp4;
    int sp5;
    int methodHeader;
    int sz;
    int fmt;
    int header;
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

int primitivePerform(void) {
    int performSelector;
    int selectorIndex;
    int performMethod;
    int i;
    int newReceiver;
    int lookupClass;
    int fieldIndex;
    int oop;
    int valuePointer;
    int oop1;
    int valuePointer1;
    int toIndex;
    int fromIndex;
    int lastFrom;
    int ccIndex;

	performSelector = messageSelector;
	performMethod = newMethod;
	messageSelector = longAt(stackPointer - ((argumentCount - 1) * 4));
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
		if (!(compilerInitialized && (compilerActivateMethod()))) {
			bytecodeActivateNewMethod();
		}
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

int primitivePerformAt(int lookupClass) {
    int argumentArray;
    int performSelector;
    int arraySize;
    int performMethod;
    int performArgCount;
    int index;
    int cntxSize;
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
    int ccIndex;
    int cl;

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
			goto l1;
		} else {
			sz = header & 252;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		arraySize = ((unsigned) (sz - 4)) >> 2;
		/* begin fetchWordLengthOf: */
		objectPointer = activeContext;
		/* begin sizeBitsOf: */
		header1 = longAt(objectPointer);
		if ((header1 & 3) == 0) {
			sz1 = (longAt(objectPointer - 8)) & 4294967292U;
			goto l2;
		} else {
			sz1 = header1 & 252;
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
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
				goto l3;
			}
		}
		/* begin activateNewMethod */
		if (!(compilerInitialized && (compilerActivateMethod()))) {
			bytecodeActivateNewMethod();
		}
		/* begin quickCheckForInterrupts */
		if ((interruptCheckCounter -= 1) <= 0) {
			checkForInterrupts();
		}
	l3:	/* end executeNewMethod */;
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
    int lookupClass;
    int rcvr;
    int currentClass;
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
    int ccIndex;
    int cl;

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
    int ccIndex;
    int cl;

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

int primitiveQuo(void) {
    int integerRcvr;
    int integerArg;
    int integerResult;
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

int primitiveReadJoystick(void) {
    int index;
    int object;
    int sp;
    int integerPointer;

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
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin push: */
		object = positive32BitIntegerFor(joystickRead(index));
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	}
}

int primitiveReadTablet(void) {
    int cursorIndex;
    int resultSize;
    int result;
    int sp;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		cursorIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		cursorIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		resultSize = tabletResultSize();
		result = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (4 << 2)), resultSize);
		/* begin success: */
		successFlag = (tabletRead(cursorIndex, (int *) (result + 4))) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, result);
		stackPointer = sp;
	}
}

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

int primitiveResolverAbortLookup(void) {
	sqResolverAbort();
}

int primitiveResolverAddressLookupResult(void) {
    int sz;
    int s;
    int sp;

	sz = sqResolverAddrLookupResultSize();
	if (successFlag) {
		s = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)), sz);
		sqResolverAddrLookupResult(((char *) (s + 4)), sz);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((1 - 1) * 4), s);
		stackPointer = sp;
	}
}

int primitiveResolverError(void) {
    int err;
    int sp;

	err = sqResolverError();
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((1 - 1) * 4), ((err << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveResolverLocalAddress(void) {
    int addr;
    int oop;
    int sp;

	addr = sqResolverLocalAddress();
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = intToNetAddress(addr);
		longAtput(sp = stackPointer - ((1 - 1) * 4), oop);
		stackPointer = sp;
	}
}

int primitiveResolverNameLookupResult(void) {
    int addr;
    int oop;
    int sp;

	addr = sqResolverNameLookupResult();
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = intToNetAddress(addr);
		longAtput(sp = stackPointer - ((1 - 1) * 4), oop);
		stackPointer = sp;
	}
}

int primitiveResolverStartAddressLookup(void) {
    int addr;

	addr = netAddressToInt(longAt(stackPointer));
	if (successFlag) {
		sqResolverStartAddrLookup(addr);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveResolverStartNameLookup(void) {
    int sz;
    int name;
    int header;
    int sz1;
    int ccIndex;
    int cl;

	name = longAt(stackPointer);
	/* begin assertClassOf:is: */
	if ((name & 1)) {
		successFlag = 0;
		goto l2;
	}
	ccIndex = (((unsigned) (longAt(name))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(name - 4)) & 4294967292U;
	} else {
		cl = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex - 1) << 2));
	}
	/* begin success: */
	successFlag = (cl == (longAt(((((char *) specialObjectsOop)) + 4) + (6 << 2)))) && successFlag;
l2:	/* end assertClassOf:is: */;
	if (successFlag) {
		/* begin lengthOf: */
		header = longAt(name);
		/* begin lengthOf:baseHeader:format: */
		if ((header & 3) == 0) {
			sz1 = (longAt(name - 8)) & 4294967292U;
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
	l1:	/* end lengthOf:baseHeader:format: */;
		sqResolverStartNameLookup(((char *) (name + 4)), sz);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveResolverStatus(void) {
    int status;
    int sp;

	status = sqResolverStatus();
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((1 - 1) * 4), ((status << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveResponse(void) {
    int startTime;
    int timerPending;

	timerPending = nextWakeupTick != 0;
	if (timerPending) {
		startTime = ioLowResMSecs();
	}
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
		primitiveFail();
		break;
	case 95:
		primitiveInputWord();
		break;
	case 96:
		primitiveCopyBits();
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
		primitiveDrawLoop();
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
		primitiveFail();
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
		primitiveFail();
		break;
	case 121:
		primitiveImageName();
		break;
	case 122:
		primitiveNoop();
		break;
	case 123:
		primitiveFail();
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
		primitiveReadJoystick();
		break;
	case 147:
		primitiveWarpBits();
		break;
	case 148:
		primitiveClone();
		break;
	case 149:
		primitiveGetAttribute();
		break;
	case 150:
		primitiveFileAtEnd();
		break;
	case 151:
		primitiveFileClose();
		break;
	case 152:
		primitiveFileGetPosition();
		break;
	case 153:
		primitiveFileOpen();
		break;
	case 154:
		primitiveFileRead();
		break;
	case 155:
		primitiveFileSetPosition();
		break;
	case 156:
		primitiveFileDelete();
		break;
	case 157:
		primitiveFileSize();
		break;
	case 158:
		primitiveFileWrite();
		break;
	case 159:
		primitiveFileRename();
		break;
	case 160:
		primitiveDirectoryCreate();
		break;
	case 161:
		primitiveDirectoryDelimitor();
		break;
	case 162:
		primitiveDirectoryLookup();
		break;
	case 163:
		primitiveDirectoryDelete();
		break;
	case 164:
	case 165:
	case 166:
	case 167:
	case 168:
		primitiveFail();
		break;
	case 169:
		primitiveDirectorySetMacTypeAndCreator();
		break;
	case 170:
		primitiveSoundStart();
		break;
	case 171:
		primitiveSoundStartWithSemaphore();
		break;
	case 172:
		primitiveSoundStop();
		break;
	case 173:
		primitiveSoundAvailableSpace();
		break;
	case 174:
		primitiveSoundPlaySamples();
		break;
	case 175:
		primitiveSoundPlaySilence();
		break;
	case 176:
		primWaveTableSoundmixSampleCountintostartingAtpan();
		break;
	case 177:
		primFMSoundmixSampleCountintostartingAtpan();
		break;
	case 178:
		primPluckedSoundmixSampleCountintostartingAtpan();
		break;
	case 179:
		primSampledSoundmixSampleCountintostartingAtpan();
		break;
	case 180:
		primFMSoundmixSampleCountintostartingAtleftVolrightVol();
		break;
	case 181:
		primPluckedSoundmixSampleCountintostartingAtleftVolrightVol();
		break;
	case 182:
		oldprimSampledSoundmixSampleCountintostartingAtleftVolrightVol();
		break;
	case 183:
		primReverbSoundapplyReverbTostartingAtcount();
		break;
	case 184:
		primLoopedSampledSoundmixSampleCountintostartingAtleftVolrightVol();
		break;
	case 185:
		primSampledSoundmixSampleCountintostartingAtleftVolrightVol();
		break;
	case 186:
	case 187:
	case 188:
		primitiveFail();
		break;
	case 189:
		primitiveSoundInsertSamples();
		break;
	case 190:
		primitiveSoundStartRecording();
		break;
	case 191:
		primitiveSoundStopRecording();
		break;
	case 192:
		primitiveSoundGetRecordingSampleRate();
		break;
	case 193:
		primitiveSoundRecordSamples();
		break;
	case 194:
		primitiveSoundSetRecordLevel();
		break;
	case 195:
	case 196:
	case 197:
	case 198:
	case 199:
		primitiveFail();
		break;
	case 200:
		primitiveInitializeNetwork();
		break;
	case 201:
		primitiveResolverStartNameLookup();
		break;
	case 202:
		primitiveResolverNameLookupResult();
		break;
	case 203:
		primitiveResolverStartAddressLookup();
		break;
	case 204:
		primitiveResolverAddressLookupResult();
		break;
	case 205:
		primitiveResolverAbortLookup();
		break;
	case 206:
		primitiveResolverLocalAddress();
		break;
	case 207:
		primitiveResolverStatus();
		break;
	case 208:
		primitiveResolverError();
		break;
	case 209:
		primitiveSocketCreate();
		break;
	case 210:
		primitiveSocketDestroy();
		break;
	case 211:
		primitiveSocketConnectionStatus();
		break;
	case 212:
		primitiveSocketError();
		break;
	case 213:
		primitiveSocketLocalAddress();
		break;
	case 214:
		primitiveSocketLocalPort();
		break;
	case 215:
		primitiveSocketRemoteAddress();
		break;
	case 216:
		primitiveSocketRemotePort();
		break;
	case 217:
		primitiveSocketConnectToPort();
		break;
	case 218:
		primitiveSocketListenOnPort();
		break;
	case 219:
		primitiveSocketCloseConnection();
		break;
	case 220:
		primitiveSocketAbortConnection();
		break;
	case 221:
		primitiveSocketReceiveDataBufCount();
		break;
	case 222:
		primitiveSocketReceiveDataAvailable();
		break;
	case 223:
		primitiveSocketSendDataBufCount();
		break;
	case 224:
		primitiveSocketSendDone();
		break;
	case 225:
		primitiveSocketAccept();
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
		primBitmapdecompressfromByteArrayat();
		break;
	case 235:
		primStringcomparewithcollated();
		break;
	case 236:
		primSampledSoundconvert8bitSignedFromto16Bit();
		break;
	case 237:
		primBitmapcompresstoByteArray();
		break;
	case 238:
		primitiveSerialPortOpen();
		break;
	case 239:
		primitiveSerialPortClose();
		break;
	case 240:
		primitiveSerialPortWrite();
		break;
	case 241:
		primitiveSerialPortRead();
		break;
	case 242:
		primitiveFail();
		break;
	case 243:
		primStringtranslatefromtotable();
		break;
	case 244:
		primStringfindFirstInStringinSetstartingAt();
		break;
	case 245:
		primStringindexOfAsciiinStringstartingAt();
		break;
	case 246:
		primStringfindSubstringinstartingAtmatchTable();
		break;
	case 247:
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
		primitiveFail();
		break;
	case 521:
		primitiveMIDIClosePort();
		break;
	case 522:
		primitiveMIDIGetClock();
		break;
	case 523:
		primitiveMIDIGetPortCount();
		break;
	case 524:
		primitiveMIDIGetPortDirectionality();
		break;
	case 525:
		primitiveMIDIGetPortName();
		break;
	case 526:
		primitiveMIDIOpenPort();
		break;
	case 527:
		primitiveMIDIParameterGetOrSet();
		break;
	case 528:
		primitiveMIDIRead();
		break;
	case 529:
		primitiveMIDIWrite();
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
		primitiveAsyncFileClose();
		break;
	case 541:
		primitiveAsyncFileOpen();
		break;
	case 542:
		primitiveAsyncFileReadResult();
		break;
	case 543:
		primitiveAsyncFileReadStart();
		break;
	case 544:
		primitiveAsyncFileWriteResult();
		break;
	case 545:
		primitiveAsyncFileWriteStart();
		break;
	case 546:
	case 547:
		primitiveFail();
		break;
	case 548:
		primitiveGetTabletParameters();
		break;
	case 549:
		primitiveReadTablet();
		break;
	case 550:
		primADPCMCodecprivateDecodeMono();
		break;
	case 551:
		primADPCMCodecprivateDecodeStereo();
		break;
	case 552:
		primADPCMCodecprivateEncodeMono();
		break;
	case 553:
		primADPCMCodecprivateEncodeStereo();
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
	case 570:
	case 571:
	case 572:
	case 573:
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

	proc = longAt(stackPointer);
	if (successFlag) {
		resume(proc);
	}
}

int primitiveScanCharacters(void) {
    int stopArray;
    int displayFlag;
    int start;
    int stop;
    int string;
    int rcvr;
    int rightX;
    int sp;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int successValue;
    int sourceX2;
    int ascii;
    int top;
    int nextDestX;
    int charVal;
    int left;
    int lastIndex;
    int lastIndex1;

	rcvr = longAt(stackPointer - (6 * 4));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (5 * 4));
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
	integerPointer1 = longAt(stackPointer - (4 * 4));
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
	string = longAt(stackPointer - (3 * 4));
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (2 * 4));
	if ((integerPointer2 & 1)) {
		rightX = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		rightX = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	stopArray = longAt(stackPointer - (1 * 4));
	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (0 * 4))) == trueObj) {
		displayFlag = 1;
		goto l4;
	}
	if ((longAt(stackPointer - (0 * 4))) == falseObj) {
		displayFlag = 0;
		goto l4;
	}
	successFlag = 0;
	displayFlag = null;
l4:	/* end booleanValueOf: */;
	if (!(successFlag)) {
		return null;
	}
	/* begin success: */
	successValue = loadScannerFromstartstopstringrightXstopArraydisplayFlag(rcvr, start, stop, string, rightX, stopArray, displayFlag);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin scanCharacters */
		if (scanDisplayFlag) {
			clipRange();
			left = dx;
			top = dy;
		}
		lastIndex = scanStart;
		while (lastIndex <= scanStop) {
			charVal = stObjectat(scanString, lastIndex);
			ascii = (charVal >> 1);
			if (!successFlag) {
				goto l6;
			}
			stopCode = stObjectat(scanStopArray, ascii + 1);
			if (!successFlag) {
				goto l6;
			}
			if (!(stopCode == nilObj)) {
				/* begin returnAt:lastIndex:left:top: */
				stopCode = stObjectat(scanStopArray, ascii + 1);
				if (!successFlag) {
					goto l6;
				}
				/* begin storeInteger:ofObject:withValue: */
				if ((lastIndex ^ (lastIndex << 1)) >= 0) {
					longAtput(((((char *) bitBltOop)) + 4) + (15 << 2), ((lastIndex << 1) | 1));
				} else {
					/* begin primitiveFail */
					successFlag = 0;
				}
				if (scanDisplayFlag) {
					affectedL = left;
					affectedR = bbW + dx;
					affectedT = top;
					affectedB = bbH + dy;
				}
				goto l6;
			}
			sourceX = stObjectat(scanXTable, ascii + 1);
			sourceX2 = stObjectat(scanXTable, ascii + 2);
			if (!successFlag) {
				goto l6;
			}
			if (((sourceX & 1)) && ((sourceX2 & 1))) {
				sourceX = (sourceX >> 1);
				sourceX2 = (sourceX2 >> 1);
			} else {
				/* begin primitiveFail */
				successFlag = 0;
				goto l6;
			}
			nextDestX = destX + (width = sourceX2 - sourceX);
			if (nextDestX > scanRightX) {
				/* begin returnAt:lastIndex:left:top: */
				stopCode = stObjectat(scanStopArray, 258);
				if (!successFlag) {
					goto l6;
				}
				/* begin storeInteger:ofObject:withValue: */
				if ((lastIndex ^ (lastIndex << 1)) >= 0) {
					longAtput(((((char *) bitBltOop)) + 4) + (15 << 2), ((lastIndex << 1) | 1));
				} else {
					/* begin primitiveFail */
					successFlag = 0;
				}
				if (scanDisplayFlag) {
					affectedL = left;
					affectedR = bbW + dx;
					affectedT = top;
					affectedB = bbH + dy;
				}
				goto l6;
			}
			if (scanDisplayFlag) {
				copyBits();
			}
			destX = nextDestX;
			/* begin storeInteger:ofObject:withValue: */
			if ((destX ^ (destX << 1)) >= 0) {
				longAtput(((((char *) bitBltOop)) + 4) + (4 << 2), ((destX << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			lastIndex += 1;
		}
		/* begin returnAt:lastIndex:left:top: */
		lastIndex1 = scanStop;
		stopCode = stObjectat(scanStopArray, 257);
		if (!successFlag) {
			goto l5;
		}
		/* begin storeInteger:ofObject:withValue: */
		if ((lastIndex1 ^ (lastIndex1 << 1)) >= 0) {
			longAtput(((((char *) bitBltOop)) + 4) + (15 << 2), ((lastIndex1 << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
		if (scanDisplayFlag) {
			affectedL = left;
			affectedR = bbW + dx;
			affectedT = top;
			affectedB = bbH + dy;
		}
	l5:	/* end returnAt:lastIndex:left:top: */;
	l6:	/* end scanCharacters */;
	}
	if (successFlag) {
		if (displayFlag) {
			showDisplayBits();
		}
		/* begin pop: */
		stackPointer -= 7 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, stopCode);
		stackPointer = sp;
	}
}

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

int primitiveSerialPortClose(void) {
    int portNum;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		portNum = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		serialPortClose(portNum);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveSerialPortOpen(void) {
    int dataBits;
    int parityType;
    int stopBitsType;
    int portNum;
    int baudRate;
    int xOnChar;
    int xOffChar;
    int inFlowControl;
    int outFlowControl;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int integerPointer3;
    int integerPointer4;
    int integerPointer5;
    int integerPointer6;
    int integerPointer7;
    int integerPointer8;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		xOffChar = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		xOffChar = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		xOnChar = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		xOnChar = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (2 * 4));
	if ((integerPointer2 & 1)) {
		outFlowControl = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		outFlowControl = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(stackPointer - (3 * 4));
	if ((integerPointer3 & 1)) {
		inFlowControl = (integerPointer3 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		inFlowControl = 0;
		goto l4;
	}
l4:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer4 = longAt(stackPointer - (4 * 4));
	if ((integerPointer4 & 1)) {
		dataBits = (integerPointer4 >> 1);
		goto l5;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		dataBits = 0;
		goto l5;
	}
l5:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer5 = longAt(stackPointer - (5 * 4));
	if ((integerPointer5 & 1)) {
		parityType = (integerPointer5 >> 1);
		goto l6;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		parityType = 0;
		goto l6;
	}
l6:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer6 = longAt(stackPointer - (6 * 4));
	if ((integerPointer6 & 1)) {
		stopBitsType = (integerPointer6 >> 1);
		goto l7;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		stopBitsType = 0;
		goto l7;
	}
l7:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer7 = longAt(stackPointer - (7 * 4));
	if ((integerPointer7 & 1)) {
		baudRate = (integerPointer7 >> 1);
		goto l8;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		baudRate = 0;
		goto l8;
	}
l8:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer8 = longAt(stackPointer - (8 * 4));
	if ((integerPointer8 & 1)) {
		portNum = (integerPointer8 >> 1);
		goto l9;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l9;
	}
l9:	/* end stackIntegerValue: */;
	if (successFlag) {
		serialPortOpen(
			portNum, baudRate, stopBitsType, parityType, dataBits,
			inFlowControl, outFlowControl, xOnChar, xOffChar);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 9 * 4;
	}
}

int primitiveSerialPortRead(void) {
    int array;
    int startIndex;
    int portNum;
    int bytesRead;
    int count;
    int fmt;
    int sp;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int successValue;
    int successValue1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		startIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	array = longAt(stackPointer - (2 * 4));
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (3 * 4));
	if ((integerPointer2 & 1)) {
		portNum = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	fmt = (((unsigned) (longAt(array))) >> 8) & 15;
	/* begin success: */
	successValue = (fmt >= 8) && (fmt <= 11);
	successFlag = successValue && successFlag;
	/* begin success: */
	successValue1 = (startIndex >= 1) && (((startIndex + count) - 1) <= (lengthOf(array)));
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		bytesRead = serialPortReadInto(portNum, count, ((array + 4) + startIndex) - 1);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((bytesRead << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSerialPortWrite(void) {
    int array;
    int startIndex;
    int portNum;
    int bytesWritten;
    int count;
    int fmt;
    int sp;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int successValue;
    int successValue1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		startIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	array = longAt(stackPointer - (2 * 4));
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (3 * 4));
	if ((integerPointer2 & 1)) {
		portNum = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		portNum = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	fmt = (((unsigned) (longAt(array))) >> 8) & 15;
	/* begin success: */
	successValue = (fmt >= 8) && (fmt <= 11);
	successFlag = successValue && successFlag;
	/* begin success: */
	successValue1 = (startIndex >= 1) && (((startIndex + count) - 1) <= (lengthOf(array)));
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		bytesWritten = serialPortWriteFrom(portNum, count, ((array + 4) + startIndex) - 1);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((bytesWritten << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSetDisplayMode(void) {
    int h;
    int w;
    int d;
    int okay;
    int fsFlag;
    int sp;
    int sp1;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;

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

int primitiveShortAt(void) {
    int addr;
    int sz;
    int value;
    int index;
    int rcvr;
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

int primitiveShortAtPut(void) {
    int addr;
    int sz;
    int value;
    int index;
    int rcvr;
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

int primitiveShowDisplayRect(void) {
    int displayObj;
    int dispBits;
    int dispBitsPtr;
    int top;
    int bottom;
    int h;
    int w;
    int d;
    int right;
    int left;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int integerPointer3;
    int successValue;
    int successValue1;

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
	displayObj = longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
	/* begin success: */
	successValue = (((((unsigned) (longAt(displayObj))) >> 8) & 15) <= 4) && ((lengthOf(displayObj)) >= 4);
	successFlag = successValue && successFlag;
	if (successFlag) {
		dispBits = longAt(((((char *) displayObj)) + 4) + (0 << 2));
		w = fetchIntegerofObject(1, displayObj);
		h = fetchIntegerofObject(2, displayObj);
		d = fetchIntegerofObject(3, displayObj);
	}
	if (left < 0) {
		left = 0;
	}
	if (right > w) {
		right = w;
	}
	if (top < 0) {
		top = 0;
	}
	if (bottom > h) {
		bottom = h;
	}
	/* begin success: */
	successValue1 = (left <= right) && (top <= bottom);
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		dispBitsPtr = dispBits + 4;
		ioShowDisplay(dispBitsPtr, w, h, d, left, right, top, bottom);
		ioForceDisplayUpdate();
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 4 * 4;
	}
}

int primitiveSignal(void) {
    int sema;
    int ccIndex;
    int cl;

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
    int sz;
    int rcvr;
    int oop;
    int sp;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp1;
    int classFormat;
    int class;
    int sz1;
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
		goto l2;
	} else {
		totalLength = (sz1 - 4) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l1;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l1;
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
l1:	/* end fixedFieldsOf:format:length: */;
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

int primitiveSnapshot(void) {
    int activeProc;
    int dataSize;
    int rcvr;
    int top;
    int sp;
    int sp1;
    int sp2;
    int valuePointer;
    int sz;
    int i;
    int header;
    int oop;
    int fmt;
    int chunk;
    int extra;
    int header1;
    int type;
    int extra1;
    int sz1;
    int extra2;
    int header2;
    int type1;
    int extra11;

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
	/* begin cleanUpContexts */
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
	incrementalGC();
	fullGC();
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
	/* begin compilerPostSnapshotHook */
	if (compilerInitialized) {
		compilerPostSnapshot();
	}
}

int primitiveSocketAbortConnection(void) {
    SocketPtr s;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		sqSocketAbortConnection(s);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveSocketAccept(void) {
    int semaIndex;
    int socketOop;
    int sendBufSize;
    SocketPtr serverSocket;
    SocketPtr s;
    int recvBufSize;
    int sp;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		semaIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		semaIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		sendBufSize = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		sendBufSize = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (2 * 4));
	if ((integerPointer2 & 1)) {
		recvBufSize = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		recvBufSize = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	serverSocket = socketValueOf(longAt(stackPointer - (3 * 4)));
	if (successFlag) {
		socketOop = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (26 << 2)), socketRecordSize());
		s = socketValueOf(socketOop);
		sqSocketAcceptFromRecvBytesSendBytesSemaID(s, serverSocket, recvBufSize, sendBufSize, semaIndex);
		if (successFlag) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((5 - 1) * 4), socketOop);
			stackPointer = sp;
		}
	}
}

int primitiveSocketCloseConnection(void) {
    SocketPtr s;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		sqSocketCloseConnection(s);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveSocketConnectToPort(void) {
    int addr;
    int port;
    SocketPtr s;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		port = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		port = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	addr = netAddressToInt(longAt(stackPointer - (1 * 4)));
	s = socketValueOf(longAt(stackPointer - (2 * 4)));
	if (successFlag) {
		sqSocketConnectToPort(s, addr, port);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
	}
}

int primitiveSocketConnectionStatus(void) {
    int status;
    SocketPtr s;
    int sp;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		status = sqSocketConnectionStatus(s);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((2 - 1) * 4), ((status << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSocketCreate(void) {
    int semaIndex;
    int socketType;
    int sendBufSize;
    int socketOop;
    int netType;
    SocketPtr s;
    int recvBufSize;
    int sp;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;
    int integerPointer3;
    int integerPointer4;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		semaIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		semaIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		sendBufSize = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		sendBufSize = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (2 * 4));
	if ((integerPointer2 & 1)) {
		recvBufSize = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		recvBufSize = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(stackPointer - (3 * 4));
	if ((integerPointer3 & 1)) {
		socketType = (integerPointer3 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		socketType = 0;
		goto l4;
	}
l4:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer4 = longAt(stackPointer - (4 * 4));
	if ((integerPointer4 & 1)) {
		netType = (integerPointer4 >> 1);
		goto l5;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		netType = 0;
		goto l5;
	}
l5:	/* end stackIntegerValue: */;
	if (successFlag) {
		socketOop = instantiateClassindexableSize(longAt(((((char *) specialObjectsOop)) + 4) + (26 << 2)), socketRecordSize());
		s = socketValueOf(socketOop);
		sqSocketCreateNetTypeSocketTypeRecvBytesSendBytesSemaID(s, netType, socketType, recvBufSize, sendBufSize, semaIndex);
		if (successFlag) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((6 - 1) * 4), socketOop);
			stackPointer = sp;
		}
	}
}

int primitiveSocketDestroy(void) {
    SocketPtr s;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		sqSocketDestroy(s);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveSocketError(void) {
    int err;
    SocketPtr s;
    int sp;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		err = sqSocketError(s);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((2 - 1) * 4), ((err << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSocketListenOnPort(void) {
    int port;
    int backlog;
    SocketPtr s;
    int n;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;

	n = argumentCount;
	if ((n < 2) || (n > 3)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if (n == 3) {
		/* begin stackIntegerValue: */
		integerPointer = longAt(stackPointer - (0 * 4));
		if ((integerPointer & 1)) {
			backlog = (integerPointer >> 1);
			goto l1;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			backlog = 0;
			goto l1;
		}
	l1:	/* end stackIntegerValue: */;
		/* begin stackIntegerValue: */
		integerPointer1 = longAt(stackPointer - (1 * 4));
		if ((integerPointer1 & 1)) {
			port = (integerPointer1 >> 1);
			goto l2;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			port = 0;
			goto l2;
		}
	l2:	/* end stackIntegerValue: */;
		s = socketValueOf(longAt(stackPointer - (2 * 4)));
	} else {
		/* begin stackIntegerValue: */
		integerPointer2 = longAt(stackPointer - (0 * 4));
		if ((integerPointer2 & 1)) {
			port = (integerPointer2 >> 1);
			goto l3;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			port = 0;
			goto l3;
		}
	l3:	/* end stackIntegerValue: */;
		s = socketValueOf(longAt(stackPointer - (1 * 4)));
	}
	if (successFlag) {
		if (n == 2) {
			sqSocketListenOnPort(s, port);
		} else {
			sqSocketListenOnPortBacklogSize(s, port, backlog);
		}
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= n * 4;
	}
}

int primitiveSocketLocalAddress(void) {
    int addr;
    SocketPtr s;
    int oop;
    int sp;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		addr = sqSocketLocalAddress(s);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = intToNetAddress(addr);
		longAtput(sp = stackPointer - ((2 - 1) * 4), oop);
		stackPointer = sp;
	}
}

int primitiveSocketLocalPort(void) {
    int port;
    SocketPtr s;
    int sp;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		port = sqSocketLocalPort(s);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((2 - 1) * 4), ((port << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSocketReceiveDataAvailable(void) {
    int dataIsAvailable;
    SocketPtr s;
    int sp;
    int sp1;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		dataIsAvailable = sqSocketReceiveDataAvailable(s);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (dataIsAvailable) {
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

int primitiveSocketReceiveDataBufCount(void) {
    int array;
    int startIndex;
    int arrayBase;
    int bytesReceived;
    int bufStart;
    int byteSize;
    SocketPtr s;
    int count;
    int sp;
    int integerPointer;
    int integerPointer1;
    int successValue;
    int successValue1;
    int fmt;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		startIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	array = longAt(stackPointer - (2 * 4));
	s = socketValueOf(longAt(stackPointer - (3 * 4)));
	/* begin success: */
	/* begin isWordsOrBytes: */
	fmt = (((unsigned) (longAt(array))) >> 8) & 15;
	successValue = (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
	successFlag = successValue && successFlag;
	if (((((unsigned) (longAt(array))) >> 8) & 15) == 6) {
		byteSize = 4;
	} else {
		byteSize = 1;
	}
	/* begin success: */
	successValue1 = (startIndex >= 1) && ((count >= 0) && (((startIndex + count) - 1) <= (lengthOf(array))));
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		arrayBase = array + 4;
		bufStart = arrayBase + ((startIndex - 1) * byteSize);
		bytesReceived = sqSocketReceiveDataBufCount(s, bufStart, count * byteSize);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, (((bytesReceived / byteSize) << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSocketRemoteAddress(void) {
    int addr;
    SocketPtr s;
    int oop;
    int sp;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		addr = sqSocketRemoteAddress(s);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = intToNetAddress(addr);
		longAtput(sp = stackPointer - ((2 - 1) * 4), oop);
		stackPointer = sp;
	}
}

int primitiveSocketRemotePort(void) {
    int port;
    SocketPtr s;
    int sp;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		port = sqSocketRemotePort(s);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((2 - 1) * 4), ((port << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSocketSendDataBufCount(void) {
    int array;
    int startIndex;
    int arrayBase;
    int bytesSent;
    int bufStart;
    int byteSize;
    SocketPtr s;
    int count;
    int sp;
    int integerPointer;
    int integerPointer1;
    int successValue;
    int successValue1;
    int fmt;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		count = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		count = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * 4));
	if ((integerPointer1 & 1)) {
		startIndex = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	array = longAt(stackPointer - (2 * 4));
	s = socketValueOf(longAt(stackPointer - (3 * 4)));
	/* begin success: */
	/* begin isWordsOrBytes: */
	fmt = (((unsigned) (longAt(array))) >> 8) & 15;
	successValue = (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
	successFlag = successValue && successFlag;
	if (((((unsigned) (longAt(array))) >> 8) & 15) == 6) {
		byteSize = 4;
	} else {
		byteSize = 1;
	}
	/* begin success: */
	successValue1 = (startIndex >= 1) && ((count >= 0) && (((startIndex + count) - 1) <= (lengthOf(array))));
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		arrayBase = array + 4;
		bufStart = arrayBase + ((startIndex - 1) * byteSize);
		bytesSent = sqSocketSendDataBufCount(s, bufStart, count * byteSize);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * 4;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + 4, (((bytesSent / byteSize) << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSocketSendDone(void) {
    int done;
    SocketPtr s;
    int sp;
    int sp1;

	s = socketValueOf(longAt(stackPointer));
	if (successFlag) {
		done = sqSocketSendDone(s);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * 4;
		/* begin pushBool: */
		if (done) {
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

int primitiveSomeInstance(void) {
    int instance;
    int class;
    int sp;
    int top;
    int thisClass;
    int thisObj;
    int ccIndex;
    int obj;
    int chunk;
    int extra;
    int type;
    int extra1;
    int sz;
    int extra2;
    int header;
    int type1;
    int extra11;

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

int primitiveSomeObject(void) {
    int object;
    int sp;
    int obj;
    int chunk;
    int extra;
    int type;
    int extra1;
    int sz;
    int extra2;
    int header;
    int type1;
    int extra11;

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

int primitiveSoundAvailableSpace(void) {
    int frames;
    int object;
    int sp;

	frames = snd_AvailableSpace();
	/* begin success: */
	successFlag = (frames >= 0) && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin push: */
		object = positive32BitIntegerFor(frames);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	}
}

int primitiveSoundGetRecordingSampleRate(void) {
    double rate;

	rate = snd_GetRecordingSampleRate();
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
		pushFloat(rate);
	}
}

int primitiveSoundInsertSamples(void) {
    int buf;
    int leadTime;
    int frameCount;
    int framesPlayed;
    int object;
    int sp;
    int integerPointer;
    int integerPointer1;
    int successValue;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		leadTime = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		leadTime = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	buf = longAt(stackPointer - (1 * 4));
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		frameCount = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		frameCount = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(buf))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successValue = frameCount <= (lengthOf(buf));
	successFlag = successValue && successFlag;
	if (successFlag) {
		framesPlayed = snd_InsertSamplesFromLeadTime(frameCount, buf + 4, leadTime);
		/* begin success: */
		successFlag = (framesPlayed >= 0) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 4 * 4;
		/* begin push: */
		object = positive32BitIntegerFor(framesPlayed);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	}
}

int primitiveSoundPlaySamples(void) {
    int startIndex;
    int buf;
    int frameCount;
    int framesPlayed;
    int object;
    int sp;
    int integerPointer;
    int integerPointer1;
    int successValue;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		startIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	buf = longAt(stackPointer - (1 * 4));
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		frameCount = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		frameCount = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin success: */
	successFlag = (((((unsigned) (longAt(buf))) >> 8) & 15) == 6) && successFlag;
	/* begin success: */
	successValue = (startIndex >= 1) && (((startIndex + frameCount) - 1) <= (lengthOf(buf)));
	successFlag = successValue && successFlag;
	if (successFlag) {
		framesPlayed = snd_PlaySamplesFromAtLength(frameCount, buf + 4, startIndex - 1);
		/* begin success: */
		successFlag = (framesPlayed >= 0) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 4 * 4;
		/* begin push: */
		object = positive32BitIntegerFor(framesPlayed);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	}
}

int primitiveSoundPlaySilence(void) {
    int framesPlayed;
    int object;
    int sp;

	framesPlayed = snd_PlaySilence();
	/* begin success: */
	successFlag = (framesPlayed >= 0) && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
		/* begin push: */
		object = positive32BitIntegerFor(framesPlayed);
		longAtput(sp = stackPointer + 4, object);
		stackPointer = sp;
	}
}

int primitiveSoundRecordSamples(void) {
    int startWordIndex;
    int samplesRecorded;
    int bufSizeInBytes;
    int buf;
    int successValue;
    int sp;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		startWordIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		startWordIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	buf = longAt(stackPointer - (1 * 4));
	/* begin success: */
	successFlag = (((((unsigned) (longAt(buf))) >> 8) & 15) == 6) && successFlag;
	if (successFlag) {
		bufSizeInBytes = (lengthOf(buf)) * 4;
		/* begin success: */
		successValue = (startWordIndex >= 1) && (((startWordIndex - 1) * 2) < bufSizeInBytes);
		successFlag = successValue && successFlag;
	}
	if (successFlag) {
		samplesRecorded = snd_RecordSamplesIntoAtLength(buf + 4, startWordIndex - 1, bufSizeInBytes);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
		/* begin push: */
		longAtput(sp = stackPointer + 4, ((samplesRecorded << 1) | 1));
		stackPointer = sp;
	}
}

int primitiveSoundSetRecordLevel(void) {
    int level;
    int integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		level = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		level = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	if (successFlag) {
		snd_SetRecordLevel(level);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * 4;
	}
}

int primitiveSoundStart(void) {
    int stereoFlag;
    int samplesPerSec;
    int bufFrames;
    int integerPointer;
    int integerPointer1;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (0 * 4))) == trueObj) {
		stereoFlag = 1;
		goto l1;
	}
	if ((longAt(stackPointer - (0 * 4))) == falseObj) {
		stereoFlag = 0;
		goto l1;
	}
	successFlag = 0;
	stereoFlag = null;
l1:	/* end booleanValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * 4));
	if ((integerPointer & 1)) {
		samplesPerSec = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		samplesPerSec = 0;
		goto l2;
	}
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		bufFrames = (integerPointer1 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		bufFrames = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	if (successFlag) {
		/* begin success: */
		successFlag = (snd_Start(bufFrames, samplesPerSec, stereoFlag, 0)) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
	}
}

int primitiveSoundStartRecording(void) {
    int stereoFlag;
    int semaIndex;
    int desiredSamplesPerSec;
    int integerPointer;
    int integerPointer1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		semaIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		semaIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (1 * 4))) == trueObj) {
		stereoFlag = 1;
		goto l2;
	}
	if ((longAt(stackPointer - (1 * 4))) == falseObj) {
		stereoFlag = 0;
		goto l2;
	}
	successFlag = 0;
	stereoFlag = null;
l2:	/* end booleanValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		desiredSamplesPerSec = (integerPointer1 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		desiredSamplesPerSec = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	if (successFlag) {
		snd_StartRecording(desiredSamplesPerSec, stereoFlag, semaIndex);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * 4;
	}
}

int primitiveSoundStartWithSemaphore(void) {
    int stereoFlag;
    int semaIndex;
    int samplesPerSec;
    int bufFrames;
    int integerPointer;
    int integerPointer1;
    int integerPointer2;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * 4));
	if ((integerPointer & 1)) {
		semaIndex = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		semaIndex = 0;
		goto l1;
	}
l1:	/* end stackIntegerValue: */;
	/* begin booleanValueOf: */
	if ((longAt(stackPointer - (1 * 4))) == trueObj) {
		stereoFlag = 1;
		goto l2;
	}
	if ((longAt(stackPointer - (1 * 4))) == falseObj) {
		stereoFlag = 0;
		goto l2;
	}
	successFlag = 0;
	stereoFlag = null;
l2:	/* end booleanValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * 4));
	if ((integerPointer1 & 1)) {
		samplesPerSec = (integerPointer1 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		samplesPerSec = 0;
		goto l3;
	}
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (3 * 4));
	if ((integerPointer2 & 1)) {
		bufFrames = (integerPointer2 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		bufFrames = 0;
		goto l4;
	}
l4:	/* end stackIntegerValue: */;
	if (successFlag) {
		/* begin success: */
		successFlag = (snd_Start(bufFrames, samplesPerSec, stereoFlag, semaIndex)) && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 4 * 4;
	}
}

int primitiveSoundStop(void) {
	snd_Stop();
}

int primitiveSoundStopRecording(void) {
	snd_StopRecording();
}

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

int primitiveStoreImageSegment(void) {
    int firstOut;
    int segmentWordArray;
    int savedYoungStart;
    int segOop;
    int mapOop;
    int doingClass;
    int arrayOfRoots;
    int hdrBaseIn;
    int versionOffset;
    int endSeg;
    int header;
    int lastIn;
    int firstIn;
    int extraSize;
    int hdrTypeBits;
    int hdrBaseOut;
    int lastSeg;
    int outPointerArray;
    int lastOut;
    int fieldPtr;
    int fieldOop;
    int lastPtr;
    int i;
    int lastAddr;
    int i1;
    int lastAddr1;
    int i2;
    int lastAddr2;
    int i3;
    int lastAddr3;
    int extra;
    int lastIn1;
    int in;
    int out;
    int lastIn2;
    int in1;
    int out1;
    int type;
    int extra1;
    int type1;
    int extra2;
    int sz;
    int extra3;
    int header1;
    int type2;
    int extra11;

	outPointerArray = longAt(stackPointer - (0 * 4));
	segmentWordArray = longAt(stackPointer - (1 * 4));
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
	hdrBaseOut = outPointerArray + ((((int) (lastPointerOf(outPointerArray)) >> 3)) * 4);
	lastSeg = segmentWordArray;
	endSeg = (segmentWordArray + (sizeBitsOf(segmentWordArray))) - 4;
	versionOffset = 4;
	lastSeg += versionOffset;
	if (lastSeg > endSeg) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	longAtput(lastSeg, 6502);
	firstIn = endSeg - ((((int) (sizeBitsOf(segmentWordArray)) >> 5)) * 4);
	lastIn = firstIn - 4;
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
	youngStart = startOfMemory();
	markPhase();
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
	type = (longAt((segmentWordArray + versionOffset) + 4)) & 3;
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
	segOop = ((segmentWordArray + versionOffset) + 4) + extra;
	while (segOop <= lastSeg) {
		if (((longAt(segOop)) & 3) <= 1) {
			fieldPtr = segOop - 4;
			doingClass = 1;
		} else {
			fieldPtr = segOop + 4;
			doingClass = 0;
		}
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
		type2 = (longAt(segOop + sz)) & 3;
		if (type2 > 1) {
			extra11 = 0;
		} else {
			if (type2 == 1) {
				extra11 = 4;
			} else {
				extra11 = 8;
			}
		}
		extra3 = extra11;
		segOop = (segOop + sz) + extra3;
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
	type1 = (longAt(segmentWordArray)) & 3;
	if (type1 > 1) {
		extra2 = 0;
	} else {
		if (type1 == 1) {
			extra2 = 4;
		} else {
			extra2 = 8;
		}
	}
	extraSize = extra2;
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

int primitiveStoreStackp(void) {
    int stackp;
    int i;
    int newStackp;
    int ctxt;
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
	successFlag = (newStackp <= ((((int) (156 - 4) >> 2)) - 6)) && successFlag;
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

int primitiveStringReplace(void) {
    int array;
    int srcIndex;
    int start;
    int stop;
    int arrayFmt;
    int arrayInstSize;
    int i;
    int hdr;
    int totalLength;
    int repl;
    int replStart;
    int replFmt;
    int replInstSize;
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
    int arg;
    double rcvr;
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
    double trunc;
    double frac;
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

int primitiveVMParameter(void) {
    int mem;
    int arg;
    int paramsArraySize;
    int i;
    int index;
    int result;
    int sp;
    int sp1;
    int sp2;

	mem = ((int) memory);
	if (argumentCount == 0) {
		paramsArraySize = 23;
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
		if ((arg < 1) || (arg > 23)) {
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
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp2 = stackPointer - ((3 - 1) * 4), ((result << 1) | 1));
		stackPointer = sp2;
		return null;
	}
	/* begin primitiveFail */
	successFlag = 0;
}

int primitiveVMPath(void) {
    int sz;
    int s;
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
    int initialIP;
    int blockContext;
    int toIndex;
    int fromIndex;
    int lastFrom;
    int successValue;
    int tmp;
    int argCount;

	blockContext = longAt(stackPointer - (argumentCount * 4));
	/* begin argumentCountOfBlock: */
	argCount = longAt(((((char *) blockContext)) + 4) + (3 << 2));
	if ((argCount & 1)) {
		blockArgumentCount = (argCount >> 1);
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
    int arrayArgumentCount;
    int blockArgumentCount;
    int initialIP;
    int blockContext;
    int sz;
    int successValue;
    int toIndex;
    int fromIndex;
    int lastFrom;
    int top;
    int top1;
    int header;
    int tmp;
    int argCount;
    int ccIndex;
    int cl;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= 4;
	argumentArray = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= 4;
	blockContext = top1;
	/* begin argumentCountOfBlock: */
	argCount = longAt(((((char *) blockContext)) + 4) + (3 << 2));
	if ((argCount & 1)) {
		blockArgumentCount = (argCount >> 1);
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
    int sema;
    int activeProc;
    int excessSignals;
    int lastLink;
    int ccIndex;
    int cl;

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

int primitiveWarpBits(void) {
    int rcvr;
    int ns;
    int successValue;
    int skewWord;
    int mergeWord;
    int startBits;
    int yDelta;
    int smoothingCount;
    int sourceMapOop;
    int t;
    int nSteps;
    int i;
    int halftoneWord;
    int word;
    int deltaP12x;
    int deltaP12y;
    int deltaP43x;
    int deltaP43y;
    int pAx;
    int pAy;
    int xDelta;
    int pBx;
    int pBy;
    int integerPointer;

	rcvr = longAt(stackPointer - (argumentCount * 4));
	/* begin success: */
	successValue = loadBitBltFrom(rcvr);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin warpBits */
		ns = noSource;
		noSource = 1;
		clipRange();
		noSource = ns;
		if (noSource || ((bbW <= 0) || (bbH <= 0))) {
			affectedL = affectedR = affectedT = affectedB = 0;
			goto l1;
		}
		destMaskAndPointerInit();
		/* begin warpLoop */
		if (!((fetchWordLengthOf(bitBltOop)) >= (15 + 12))) {
			/* begin primitiveFail */
			successFlag = 0;
			goto l3;
		}
		nSteps = height - 1;
		if (nSteps <= 0) {
			nSteps = 1;
		}
		pAx = fetchIntegerOrTruncFloatofObject(15, bitBltOop);
		t = fetchIntegerOrTruncFloatofObject(15 + 3, bitBltOop);
		deltaP12x = deltaFromtonSteps(pAx, t, nSteps);
		if (deltaP12x < 0) {
			pAx = t - (nSteps * deltaP12x);
		}
		pAy = fetchIntegerOrTruncFloatofObject(15 + 1, bitBltOop);
		t = fetchIntegerOrTruncFloatofObject(15 + 4, bitBltOop);
		deltaP12y = deltaFromtonSteps(pAy, t, nSteps);
		if (deltaP12y < 0) {
			pAy = t - (nSteps * deltaP12y);
		}
		pBx = fetchIntegerOrTruncFloatofObject(15 + 9, bitBltOop);
		t = fetchIntegerOrTruncFloatofObject(15 + 6, bitBltOop);
		deltaP43x = deltaFromtonSteps(pBx, t, nSteps);
		if (deltaP43x < 0) {
			pBx = t - (nSteps * deltaP43x);
		}
		pBy = fetchIntegerOrTruncFloatofObject(15 + 10, bitBltOop);
		t = fetchIntegerOrTruncFloatofObject(15 + 7, bitBltOop);
		deltaP43y = deltaFromtonSteps(pBy, t, nSteps);
		if (deltaP43y < 0) {
			pBy = t - (nSteps * deltaP43y);
		}
		if (!successFlag) {
			goto l3;
		}
		if (argumentCount == 2) {
			/* begin stackIntegerValue: */
			integerPointer = longAt(stackPointer - (1 * 4));
			if ((integerPointer & 1)) {
				smoothingCount = (integerPointer >> 1);
				goto l2;
			} else {
				/* begin primitiveFail */
				successFlag = 0;
				smoothingCount = 0;
				goto l2;
			}
		l2:	/* end stackIntegerValue: */;
			sourceMapOop = longAt(stackPointer - (0 * 4));
			if (sourceMapOop == nilObj) {
				if (sourcePixSize < 16) {
					/* begin primitiveFail */
					successFlag = 0;
					goto l3;
				}
			} else {
				if ((fetchWordLengthOf(sourceMapOop)) < (1 << sourcePixSize)) {
					/* begin primitiveFail */
					successFlag = 0;
					goto l3;
				}
			}
		} else {
			smoothingCount = 1;
			sourceMapOop = nilObj;
		}
		startBits = pixPerWord - (dx & (pixPerWord - 1));
		nSteps = width - 1;
		if (nSteps <= 0) {
			nSteps = 1;
		}
		for (i = destY; i <= (clipY - 1); i += 1) {
			pAx += deltaP12x;
			pAy += deltaP12y;
			pBx += deltaP43x;
			pBy += deltaP43y;
		}
		for (i = 1; i <= bbH; i += 1) {
			xDelta = deltaFromtonSteps(pAx, pBx, nSteps);
			if (xDelta >= 0) {
				sx = pAx;
			} else {
				sx = pBx - (nSteps * xDelta);
			}
			yDelta = deltaFromtonSteps(pAy, pBy, nSteps);
			if (yDelta >= 0) {
				sy = pAy;
			} else {
				sy = pBy - (nSteps * yDelta);
			}
			for (word = destX; word <= (clipX - 1); word += 1) {
				sx += xDelta;
				sy += yDelta;
			}
			if (noHalftone) {
				halftoneWord = 4294967295U;
			} else {
				halftoneWord = longAt(halftoneBase + ((((dy + i) - 1) % halftoneHeight) * 4));
			}
			destMask = mask1;
			if (bbW < startBits) {
				skewWord = warpSourcePixelsxDeltahyDeltahxDeltavyDeltavsmoothingsourceMap(bbW, xDelta, yDelta, deltaP12x, deltaP12y, smoothingCount, sourceMapOop);
				skewWord = ((((startBits - bbW) * destPixSize) < 0) ? ((unsigned) skewWord >> -((startBits - bbW) * destPixSize)) : ((unsigned) skewWord << ((startBits - bbW) * destPixSize)));
			} else {
				skewWord = warpSourcePixelsxDeltahyDeltahxDeltavyDeltavsmoothingsourceMap(startBits, xDelta, yDelta, deltaP12x, deltaP12y, smoothingCount, sourceMapOop);
			}
			for (word = 1; word <= nWords; word += 1) {
				mergeWord = mergewith(skewWord & halftoneWord, (longAt(destIndex)) & destMask);
				longAtput(destIndex, (destMask & mergeWord) | ((~destMask) & (longAt(destIndex))));
				destIndex += 4;
				if (word >= (nWords - 1)) {
					if (!(word == nWords)) {
						destMask = mask2;
						skewWord = warpSourcePixelsxDeltahyDeltahxDeltavyDeltavsmoothingsourceMap(pixPerWord, xDelta, yDelta, deltaP12x, deltaP12y, smoothingCount, sourceMapOop);
					}
				} else {
					destMask = 4294967295U;
					skewWord = warpSourcePixelsxDeltahyDeltahxDeltavyDeltavsmoothingsourceMap(pixPerWord, xDelta, yDelta, deltaP12x, deltaP12y, smoothingCount, sourceMapOop);
				}
			}
			pAx += deltaP12x;
			pAy += deltaP12y;
			pBx += deltaP43x;
			pBy += deltaP43y;
			destIndex += destDelta;
		}
	l3:	/* end warpLoop */;
		if (hDir > 0) {
			affectedL = dx;
			affectedR = dx + bbW;
		} else {
			affectedL = (dx - bbW) + 1;
			affectedR = dx + 1;
		}
		if (vDir > 0) {
			affectedT = dy;
			affectedB = dy + bbH;
		} else {
			affectedT = (dy - bbH) + 1;
			affectedB = dy + 1;
		}
	l1:	/* end warpBits */;
		showDisplayBits();
	}
}

int print(char *s) {
	printf("%s", s);
}

int printCallStack(void) {
    int methodSel;
    int methodClass;
    int home;
    int ctxt;
    int methodArray;
    int done;
    int i;
    int classDict;
    int currClass;
    int classDictSize;
    int sz;
    int header;
    int ccIndex;
    int ccIndex1;
    int methodArray1;
    int done1;
    int i1;
    int classDict1;
    int currClass1;
    int classDictSize1;
    int sz1;
    int header1;
    int ccIndex2;

	ctxt = activeContext;
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
					methodClass = currClass;
					goto l3;
				}
				i += 1;
			}
			currClass = longAt(((((char *) currClass)) + 4) + (0 << 2));
			done = currClass == nilObj;
		}
		/* begin fetchClassOf: */
		if (((longAt(((((char *) home)) + 4) + (5 << 2))) & 1)) {
			methodClass = longAt(((((char *) specialObjectsOop)) + 4) + (5 << 2));
			goto l3;
		}
		ccIndex1 = (((unsigned) (longAt(longAt(((((char *) home)) + 4) + (5 << 2))))) >> 12) & 31;
		if (ccIndex1 == 0) {
			methodClass = (longAt((longAt(((((char *) home)) + 4) + (5 << 2))) - 4)) & 4294967292U;
			goto l3;
		} else {
			methodClass = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (28 << 2))))) + 4) + ((ccIndex1 - 1) << 2));
			goto l3;
		}
		methodClass = null;
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
		printNameOfClasscount(methodClass, 5);
		print(">");
		printStringOf(methodSel);
		/* begin cr */
		printf("\n");
		ctxt = longAt(((((char *) ctxt)) + 4) + (0 << 2));
	}
}

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

int printNum(int n) {
	printf("%ld", (long) n);
}

int printStringOf(int oop) {
    int i;
    int fmt;
    int cnt;

	fmt = (((unsigned) (longAt(oop))) >> 8) & 15;
	if (fmt < 8) {
		return null;
	}
	cnt = ((100 < (lengthOf(oop))) ? 100 : (lengthOf(oop)));
	i = 0;
	while (i < cnt) {
		/* begin printChar: */
		printf("%c", byteAt(((((char *) oop)) + 4) + i));
		i += 1;
	}
}

int proceedRenderingImage(void) {
    int external;
    int value;
    int value1;
    int value2;
    int value3;

	while (!((workBuffer[2]) == 8)) {
		if (doProfileStats) {
			geProfileTime = ioMicroMSecs();
		}
		external = findNextExternalEntryFromGET();
		if (doProfileStats) {
			workBuffer[95] = ((workBuffer[95]) + 1);
			/* begin incrementStat:by: */
			value = (ioMicroMSecs()) - geProfileTime;
			workBuffer[94] = ((workBuffer[94]) + value);
		}
		if (engineStopped) {
			return workBuffer[2] = 1;
		}
		if (external) {
			workBuffer[2] = 2;
			/* begin stopBecauseOf: */
			workBuffer[64] = 4;
			engineStopped = 1;
			return null;
		}
		workBuffer[13] = 0;
		/* begin wbStackClear */
		workBuffer[10] = (workBuffer[1]);
		workBuffer[69] = 1;
		if (doProfileStats) {
			geProfileTime = ioMicroMSecs();
		}
		if (((workBuffer[69]) != 0) && (((workBuffer[88]) & (workBuffer[52])) == 0)) {
			clearSpanBuffer();
		}
		workBuffer[69] = 0;
		external = findNextExternalFillFromAET();
		if (doProfileStats) {
			workBuffer[99] = ((workBuffer[99]) + 1);
			/* begin incrementStat:by: */
			value1 = (ioMicroMSecs()) - geProfileTime;
			workBuffer[98] = ((workBuffer[98]) + value1);
		}
		if (engineStopped) {
			return workBuffer[2] = 3;
		}
		if (external) {
			workBuffer[2] = 4;
			/* begin stopBecauseOf: */
			workBuffer[64] = 5;
			engineStopped = 1;
			return null;
		}
		/* begin wbStackClear */
		workBuffer[10] = (workBuffer[1]);
		workBuffer[35] = 0;
		if (doProfileStats) {
			geProfileTime = ioMicroMSecs();
		}
		if (((workBuffer[88]) & (workBuffer[52])) == (workBuffer[52])) {
			displaySpanBufferAt(workBuffer[88]);
			postDisplayAction();
		}
		if (doProfileStats) {
			workBuffer[103] = ((workBuffer[103]) + 1);
			/* begin incrementStat:by: */
			value2 = (ioMicroMSecs()) - geProfileTime;
			workBuffer[102] = ((workBuffer[102]) + value2);
		}
		if (engineStopped) {
			return workBuffer[2] = 5;
		}
		if ((workBuffer[2]) == 8) {
			return 0;
		}
		workBuffer[13] = 0;
		workBuffer[88] = ((workBuffer[88]) + 1);
		if (doProfileStats) {
			geProfileTime = ioMicroMSecs();
		}
		external = findNextExternalUpdateFromAET();
		if (doProfileStats) {
			workBuffer[105] = ((workBuffer[105]) + 1);
			/* begin incrementStat:by: */
			value3 = (ioMicroMSecs()) - geProfileTime;
			workBuffer[104] = ((workBuffer[104]) + value3);
		}
		if (engineStopped) {
			return workBuffer[2] = 6;
		}
		if (external) {
			workBuffer[2] = 7;
			/* begin stopBecauseOf: */
			workBuffer[64] = 6;
			engineStopped = 1;
			return null;
		}
	}
}

int proceedRenderingScanline(void) {
    int external;
    int state;
    int value;
    int value1;
    int value2;
    int value3;

	state = workBuffer[2];
	if (state == 0) {
		initializeGETProcessing();
		if (engineStopped) {
			return 0;
		}
		state = 1;
	}
	if (state == 1) {
		if (doProfileStats) {
			geProfileTime = ioMicroMSecs();
		}
		external = findNextExternalEntryFromGET();
		if (doProfileStats) {
			workBuffer[95] = ((workBuffer[95]) + 1);
			/* begin incrementStat:by: */
			value = (ioMicroMSecs()) - geProfileTime;
			workBuffer[94] = ((workBuffer[94]) + value);
		}
		if (engineStopped) {
			return workBuffer[2] = 1;
		}
		if (external) {
			workBuffer[2] = 2;
			/* begin stopBecauseOf: */
			workBuffer[64] = 4;
			engineStopped = 1;
			return null;
		}
		workBuffer[13] = 0;
		/* begin wbStackClear */
		workBuffer[10] = (workBuffer[1]);
		workBuffer[69] = 1;
		state = 3;
	}
	if (state == 3) {
		if (doProfileStats) {
			geProfileTime = ioMicroMSecs();
		}
		if (((workBuffer[69]) != 0) && (((workBuffer[88]) & (workBuffer[52])) == 0)) {
			clearSpanBuffer();
		}
		workBuffer[69] = 0;
		external = findNextExternalFillFromAET();
		if (doProfileStats) {
			workBuffer[99] = ((workBuffer[99]) + 1);
			/* begin incrementStat:by: */
			value1 = (ioMicroMSecs()) - geProfileTime;
			workBuffer[98] = ((workBuffer[98]) + value1);
		}
		if (engineStopped) {
			return workBuffer[2] = 3;
		}
		if (external) {
			workBuffer[2] = 4;
			/* begin stopBecauseOf: */
			workBuffer[64] = 5;
			engineStopped = 1;
			return null;
		}
		state = 5;
		/* begin wbStackClear */
		workBuffer[10] = (workBuffer[1]);
		workBuffer[35] = 0;
	}
	if (state == 5) {
		if (doProfileStats) {
			geProfileTime = ioMicroMSecs();
		}
		if (((workBuffer[88]) & (workBuffer[52])) == (workBuffer[52])) {
			displaySpanBufferAt(workBuffer[88]);
			postDisplayAction();
		}
		if (doProfileStats) {
			workBuffer[103] = ((workBuffer[103]) + 1);
			/* begin incrementStat:by: */
			value2 = (ioMicroMSecs()) - geProfileTime;
			workBuffer[102] = ((workBuffer[102]) + value2);
		}
		if (engineStopped) {
			return workBuffer[2] = 5;
		}
		if ((workBuffer[2]) == 8) {
			return 0;
		}
		state = 6;
		workBuffer[13] = 0;
		workBuffer[88] = ((workBuffer[88]) + 1);
	}
	if (state == 6) {
		if (doProfileStats) {
			geProfileTime = ioMicroMSecs();
		}
		external = findNextExternalUpdateFromAET();
		if (doProfileStats) {
			workBuffer[105] = ((workBuffer[105]) + 1);
			/* begin incrementStat:by: */
			value3 = (ioMicroMSecs()) - geProfileTime;
			workBuffer[104] = ((workBuffer[104]) + value3);
		}
		if (engineStopped) {
			return workBuffer[2] = 6;
		}
		if (external) {
			workBuffer[2] = 7;
			/* begin stopBecauseOf: */
			workBuffer[64] = 6;
			engineStopped = 1;
			return null;
		}
		workBuffer[2] = 1;
	}
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

int pushRemappableOop(int oop) {
	remapBuffer[remapBufferCount += 1] = oop;
}

int putLongtoFile(int n, sqImageFile f) {
    int wordsWritten;

	wordsWritten = sqImageFileWrite(&n, sizeof(int), 1, f);
	/* begin success: */
	successFlag = (wordsWritten == 1) && successFlag;
}

int quickLoadEngineFrom(int engineOop) {
	if (!successFlag) {
		return 0;
	}
	if ((engineOop & 1)) {
		return 0;
	}
	if (!(((((unsigned) (longAt(engineOop))) >> 8) & 15) <= 4)) {
		return 0;
	}
	if ((slotSizeOf(engineOop)) < 12) {
		return 0;
	}
	engine = engineOop;
	if (!(loadWorkBufferFrom(longAt(((((char *) engineOop)) + 4) + (0 << 2))))) {
		return 0;
	}
	workBuffer[64] = 0;
	objUsed = workBuffer[9];
	engineStopped = 0;
	return 1;
}

int quickLoadEngineFromrequiredState(int oop, int requiredState) {
	if (!(quickLoadEngineFrom(oop))) {
		return 0;
	}
	if ((workBuffer[2]) == requiredState) {
		return 1;
	}
	workBuffer[64] = 2;
	return 0;
}

int quickLoadEngineFromrequiredStateor(int oop, int requiredState, int alternativeState) {
	if (!(quickLoadEngineFrom(oop))) {
		return 0;
	}
	if ((workBuffer[2]) == requiredState) {
		return 1;
	}
	if ((workBuffer[2]) == alternativeState) {
		return 1;
	}
	workBuffer[64] = 2;
	return 0;
}

int quickSortGlobalEdgeTablefromto(int *array, int i, int j) {
    int l;
    int before;
    int di;
    int dij;
    int dj;
    int again;
    int ij;
    int k;
    int tmp;
    int n;
    int tt;

	if ((n = (j + 1) - i) <= 1) {
		return 0;
	}
	di = array[i];
	dj = array[j];
	before = getSortsbefore(di, dj);
	if (!(before)) {
		tmp = array[i];
		array[i] = (array[j]);
		array[j] = tmp;
		tt = di;
		di = dj;
		dj = tt;
	}
	if (n <= 2) {
		return 0;
	}
	ij = ((int) (i + j) >> 1);
	dij = array[ij];
	before = getSortsbefore(di, dij);
	if (before) {
		before = getSortsbefore(dij, dj);
		if (!(before)) {
			tmp = array[j];
			array[j] = (array[ij]);
			array[ij] = tmp;
			dij = dj;
		}
	} else {
		tmp = array[i];
		array[i] = (array[ij]);
		array[ij] = tmp;
		dij = di;
	}
	if (n <= 3) {
		return 0;
	}
	k = i;
	l = j;
	again = 1;
	while (again) {
		before = 1;
		while (before) {
			if (k <= (l -= 1)) {
				tmp = array[l];
				before = getSortsbefore(dij, tmp);
			} else {
				before = 0;
			}
		}
		before = 1;
		while (before) {
			if ((k += 1) <= l) {
				tmp = array[k];
				before = getSortsbefore(tmp, dij);
			} else {
				before = 0;
			}
		}
		again = k <= l;
		if (again) {
			tmp = array[k];
			array[k] = (array[l]);
			array[l] = tmp;
		}
	}
	quickSortGlobalEdgeTablefromto(array, i, l);
	quickSortGlobalEdgeTablefromto(array, k, j);
}

int * rShiftTable(void) {
    static int theTable[17] =
		{0, 5, 4, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1};

	return theTable;
}

int readImageFromFileHeapSizeStartingAt(sqImageFile f, int desiredHeapSize, int imageOffset) {
    int swapBytes;
    int dataSize;
    int minimumMemory;
    int memStart;
    int bytesRead;
    int bytesToShift;
    int headerStart;
    int heapSize;
    int headerSize;
    int oldBaseAddr;
    int startAddr;
    int addr;
    int i;
    int sched;
    int proc;
    int activeCntx;
    int tmp;
    int methodHeader;
    int wordAddr;
    int oop;
    int fmt;
    int stopAddr;
    int addr1;
    int chunk;
    int extra;
    int type;
    int extra1;
    int sz;
    int extra2;
    int header;
    int type1;
    int extra11;

	swapBytes = checkImageVersionFromstartingAt(f, imageOffset);
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
	minimumMemory = dataSize + 100000;
	if (heapSize < minimumMemory) {
		error("Insufficient memory for this image");
	}
	memory = (unsigned char *) sqAllocateMemory(minimumMemory, heapSize);
	if (memory == null) {
		error("Failed to allocate memory for the heap");
	}
	memStart = startOfMemory();
	memoryLimit = (memStart + heapSize) - 24;
	endOfMemory = memStart + dataSize;
	sqImageFileSeek(f, headerStart + headerSize);
	bytesRead = sqImageFileRead(memory, sizeof(unsigned char), dataSize, f);
	if (bytesRead != dataSize) {
		error("Read failed or premature end of image file");
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
				if (fmt >= 8) {
					wordAddr = oop + 4;
					if (fmt >= 12) {
						methodHeader = longAt(oop + 4);
						wordAddr = (wordAddr + 4) + (((((unsigned) methodHeader) >> 10) & 255) * 4);
					}
					/* begin reverseBytesFrom:to: */
					stopAddr = oop + (sizeBitsOf(oop));
					addr1 = wordAddr;
					while (addr1 < stopAddr) {
						longAtput(addr1, ((((((unsigned) (longAt(addr1)) >> 24)) & 255) + ((((unsigned) (longAt(addr1)) >> 8)) & 65280)) + ((((unsigned) (longAt(addr1)) << 8)) & 16711680)) + ((((unsigned) (longAt(addr1)) << 24)) & 4278190080U));
						addr1 += 4;
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
	bytesToShift = memStart - oldBaseAddr;
	/* begin initializeInterpreter: */
	initializeObjectMemory(bytesToShift);
	initBBOpTable();
	initCompilerHooks();
	activeContext = nilObj;
	theHomeContext = nilObj;
	method = nilObj;
	receiver = nilObj;
	messageSelector = nilObj;
	newMethod = nilObj;
	/* begin flushMethodCache */
	for (i = 1; i <= 2048; i += 1) {
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
	nextPollTick = 0;
	nextWakeupTick = 0;
	lastTick = 0;
	interruptKeycode = 2094;
	interruptPending = 0;
	semaphoresToSignalCount = 0;
	deferDisplayUpdates = 0;
	pendingFinalizationSignals = 0;
	return dataSize;
}

int readableFormat(int imageVersion) {
	return imageVersion == 6502;
}

int remap(int oop) {
    int fwdBlock;

	if (((oop & 1) == 0) && (((longAt(oop)) & 2147483648U) != 0)) {
		fwdBlock = ((longAt(oop)) & 2147483644) << 1;
		;
		return longAt(fwdBlock);
	}
	return oop;
}

int removeFirstAETEntry(void) {
    int index;

	index = workBuffer[13];
	workBuffer[14] = ((workBuffer[14]) - 1);
	while (index < (workBuffer[14])) {
		aetBuffer[index] = (aetBuffer[index + 1]);
		index += 1;
	}
}

int removeFirstLinkOfList(int aList) {
    int next;
    int first;
    int last;
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

int resetGraphicsEngineStats(void) {
	workBuffer[90] = 0;
	workBuffer[92] = 0;
	workBuffer[94] = 0;
	workBuffer[96] = 0;
	workBuffer[98] = 0;
	workBuffer[100] = 0;
	workBuffer[102] = 0;
	workBuffer[104] = 0;
	workBuffer[106] = 0;
	workBuffer[91] = 0;
	workBuffer[93] = 0;
	workBuffer[95] = 0;
	workBuffer[97] = 0;
	workBuffer[99] = 0;
	workBuffer[101] = 0;
	workBuffer[103] = 0;
	workBuffer[105] = 0;
	workBuffer[107] = 0;
	workBuffer[108] = 0;
	workBuffer[109] = 0;
	workBuffer[110] = 0;
	workBuffer[111] = 0;
}

int resortFirstAETEntry(void) {
    int leftEdge;
    int xValue;
    int edge;

	if ((workBuffer[13]) == 0) {
		return null;
	}
	edge = aetBuffer[workBuffer[13]];
	xValue = objBuffer[edge + 4];
	leftEdge = aetBuffer[(workBuffer[13]) - 1];
	if ((objBuffer[leftEdge + 4]) <= xValue) {
		return null;
	}
	moveAETEntryFromedgex(workBuffer[13], edge, xValue);
}

int restoreHeadersFromtofromandtofrom(int firstIn, int lastIn, int hdrBaseIn, int firstOut, int lastOut, int hdrBaseOut) {
    int header;
    int tablePtr;
    int oop;
    int chunk;
    int extra;
    int type;
    int extra1;
    int sz;
    int extra2;
    int header1;
    int type1;
    int extra11;

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
    int activeProc;
    int activePriority;
    int newPriority;
    int priority;
    int processLists;
    int processList;
    int lastLink;
    int priority1;
    int processLists1;
    int processList1;
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

int reverseDisplayFromto(int startIndex, int endIndex) {
    int displayObj;
    int dispBitsPtr;
    int ptr;
    int h;
    int w;
    int d;
    int reversed;

	displayObj = longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
	if (!((((((unsigned) (longAt(displayObj))) >> 8) & 15) <= 4) && ((lengthOf(displayObj)) >= 4))) {
		return null;
	}
	dispBitsPtr = (longAt(((((char *) displayObj)) + 4) + (0 << 2))) + 4;
	w = fetchIntegerofObject(1, displayObj);
	h = fetchIntegerofObject(2, displayObj);
	d = fetchIntegerofObject(3, displayObj);
	for (ptr = (dispBitsPtr + (startIndex * 4)); ptr <= (dispBitsPtr + (endIndex * 4)); ptr += 4) {
		reversed = (longAt(ptr)) ^ 4294967295U;
		longAtput(ptr, reversed);
	}
	ioShowDisplay(dispBitsPtr, w, h, d, 0, w, 0, 1);
	ioForceDisplayUpdate();
}

int rgbAddwith(int sourceWord, int destinationWord) {
	if (destPixSize < 16) {
		return partitionedAddtonBitsnPartitions(sourceWord, destinationWord, destPixSize, pixPerWord);
	}
	if (destPixSize == 16) {
		return (partitionedAddtonBitsnPartitions(sourceWord, destinationWord, 5, 3)) + ((partitionedAddtonBitsnPartitions(((unsigned) sourceWord) >> 16, ((unsigned) destinationWord) >> 16, 5, 3)) << 16);
	} else {
		return partitionedAddtonBitsnPartitions(sourceWord, destinationWord, 8, 3);
	}
}

int rgbDiffwith(int sourceWord, int destinationWord) {
    int destPixVal;
    int pixMask;
    int destShifted;
    int sourceShifted;
    int sourcePixVal;
    int diff;
    int bitsPerColor;
    int maskShifted;
    int i;
    int rgbMask;

	pixMask = maskTable[destPixSize];
	if (destPixSize == 16) {
		bitsPerColor = 5;
		rgbMask = 31;
	} else {
		bitsPerColor = 8;
		rgbMask = 255;
	}
	maskShifted = destMask;
	destShifted = destinationWord;
	sourceShifted = sourceWord;
	for (i = 1; i <= pixPerWord; i += 1) {
		if ((maskShifted & pixMask) > 0) {
			destPixVal = destShifted & pixMask;
			sourcePixVal = sourceShifted & pixMask;
			if (destPixSize < 16) {
				if (sourcePixVal == destPixVal) {
					diff = 0;
				} else {
					diff = 1;
				}
			} else {
				diff = partitionedSubfromnBitsnPartitions(sourcePixVal, destPixVal, bitsPerColor, 3);
				diff = ((diff & rgbMask) + ((((unsigned) diff) >> bitsPerColor) & rgbMask)) + ((((unsigned) (((unsigned) diff) >> bitsPerColor)) >> bitsPerColor) & rgbMask);
			}
			bitCount += diff;
		}
		maskShifted = ((unsigned) maskShifted) >> destPixSize;
		sourceShifted = ((unsigned) sourceShifted) >> destPixSize;
		destShifted = ((unsigned) destShifted) >> destPixSize;
	}
	return destinationWord;
}

int rgbMaxwith(int sourceWord, int destinationWord) {
    int mask;
    int i;
    int result;
    int mask3;
    int i1;
    int result1;

	if (destPixSize < 16) {
		/* begin partitionedMax:with:nBits:nPartitions: */
		mask = maskTable[destPixSize];
		result = 0;
		for (i = 1; i <= pixPerWord; i += 1) {
			result = result | ((((destinationWord & mask) < (sourceWord & mask)) ? (sourceWord & mask) : (destinationWord & mask)));
			mask = mask << destPixSize;
		}
		return result;
	}
	if (destPixSize == 16) {
		return (partitionedMaxwithnBitsnPartitions(sourceWord, destinationWord, 5, 3)) + ((partitionedMaxwithnBitsnPartitions(((unsigned) sourceWord) >> 16, ((unsigned) destinationWord) >> 16, 5, 3)) << 16);
	} else {
		/* begin partitionedMax:with:nBits:nPartitions: */
		mask3 = maskTable[8];
		result1 = 0;
		for (i1 = 1; i1 <= 3; i1 += 1) {
			result1 = result1 | ((((destinationWord & mask3) < (sourceWord & mask3)) ? (sourceWord & mask3) : (destinationWord & mask3)));
			mask3 = mask3 << 8;
		}
		return result1;
	}
}

int rgbMinwith(int sourceWord, int destinationWord) {
    int mask;
    int i;
    int result;
    int mask3;
    int i1;
    int result1;

	if (destPixSize < 16) {
		/* begin partitionedMin:with:nBits:nPartitions: */
		mask = maskTable[destPixSize];
		result = 0;
		for (i = 1; i <= pixPerWord; i += 1) {
			result = result | ((((destinationWord & mask) < (sourceWord & mask)) ? (destinationWord & mask) : (sourceWord & mask)));
			mask = mask << destPixSize;
		}
		return result;
	}
	if (destPixSize == 16) {
		return (partitionedMinwithnBitsnPartitions(sourceWord, destinationWord, 5, 3)) + ((partitionedMinwithnBitsnPartitions(((unsigned) sourceWord) >> 16, ((unsigned) destinationWord) >> 16, 5, 3)) << 16);
	} else {
		/* begin partitionedMin:with:nBits:nPartitions: */
		mask3 = maskTable[8];
		result1 = 0;
		for (i1 = 1; i1 <= 3; i1 += 1) {
			result1 = result1 | ((((destinationWord & mask3) < (sourceWord & mask3)) ? (destinationWord & mask3) : (sourceWord & mask3)));
			mask3 = mask3 << 8;
		}
		return result1;
	}
}

int rgbMinInvertwith(int wordToInvert, int destinationWord) {
    int sourceWord;
    int mask;
    int i;
    int result;
    int mask3;
    int i1;
    int result1;

	sourceWord = ~wordToInvert;
	if (destPixSize < 16) {
		/* begin partitionedMin:with:nBits:nPartitions: */
		mask = maskTable[destPixSize];
		result = 0;
		for (i = 1; i <= pixPerWord; i += 1) {
			result = result | ((((destinationWord & mask) < (sourceWord & mask)) ? (destinationWord & mask) : (sourceWord & mask)));
			mask = mask << destPixSize;
		}
		return result;
	}
	if (destPixSize == 16) {
		return (partitionedMinwithnBitsnPartitions(sourceWord, destinationWord, 5, 3)) + ((partitionedMinwithnBitsnPartitions(((unsigned) sourceWord) >> 16, ((unsigned) destinationWord) >> 16, 5, 3)) << 16);
	} else {
		/* begin partitionedMin:with:nBits:nPartitions: */
		mask3 = maskTable[8];
		result1 = 0;
		for (i1 = 1; i1 <= 3; i1 += 1) {
			result1 = result1 | ((((destinationWord & mask3) < (sourceWord & mask3)) ? (destinationWord & mask3) : (sourceWord & mask3)));
			mask3 = mask3 << 8;
		}
		return result1;
	}
}

int rgbSubwith(int sourceWord, int destinationWord) {
	if (destPixSize < 16) {
		return partitionedSubfromnBitsnPartitions(sourceWord, destinationWord, destPixSize, pixPerWord);
	}
	if (destPixSize == 16) {
		return (partitionedSubfromnBitsnPartitions(sourceWord, destinationWord, 5, 3)) + ((partitionedSubfromnBitsnPartitions(((unsigned) sourceWord) >> 16, ((unsigned) destinationWord) >> 16, 5, 3)) << 16);
	} else {
		return partitionedSubfromnBitsnPartitions(sourceWord, destinationWord, 8, 3);
	}
}

int roundAndStoreResultRectx0y0x1y1(int dstOop, double x0, double y0, double x1, double y1) {
    int originOop;
    double minX;
    double minY;
    int cornerOop;
    int rectOop;
    double maxX;
    double maxY;
    int oop;
    int oop1;
    int pointResult;
    int pointResult1;

	minX = x0 + 0.5;
	if (!((minX >= (((double) -1073741824 ))) && (m23ResultX <= (((double) 1073741823 ))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	maxX = x1 + 0.5;
	if (!((maxX >= (((double) -1073741824 ))) && (m23ResultX <= (((double) 1073741823 ))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	minY = y0 + 0.5;
	if (!((minY >= (((double) -1073741824 ))) && (m23ResultX <= (((double) 1073741823 ))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	maxY = y1 + 0.5;
	if (!((maxY >= (((double) -1073741824 ))) && (m23ResultX <= (((double) 1073741823 ))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = dstOop;
	/* begin makePointwithxValue:yValue: */
	pointResult = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
	/* begin storePointer:ofObject:withValue: */
	if (pointResult < youngStart) {
		possibleRootStoreIntovalue(pointResult, (((((int) minX )) << 1) | 1));
	}
	longAtput(((((char *) pointResult)) + 4) + (0 << 2), (((((int) minX )) << 1) | 1));
	/* begin storePointer:ofObject:withValue: */
	if (pointResult < youngStart) {
		possibleRootStoreIntovalue(pointResult, (((((int) minY )) << 1) | 1));
	}
	longAtput(((((char *) pointResult)) + 4) + (1 << 2), (((((int) minY )) << 1) | 1));
	originOop = pointResult;
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = originOop;
	/* begin makePointwithxValue:yValue: */
	pointResult1 = instantiateSmallClasssizeInBytesfill(longAt(((((char *) specialObjectsOop)) + 4) + (12 << 2)), 12, nilObj);
	/* begin storePointer:ofObject:withValue: */
	if (pointResult1 < youngStart) {
		possibleRootStoreIntovalue(pointResult1, (((((int) maxX )) << 1) | 1));
	}
	longAtput(((((char *) pointResult1)) + 4) + (0 << 2), (((((int) maxX )) << 1) | 1));
	/* begin storePointer:ofObject:withValue: */
	if (pointResult1 < youngStart) {
		possibleRootStoreIntovalue(pointResult1, (((((int) maxY )) << 1) | 1));
	}
	longAtput(((((char *) pointResult1)) + 4) + (1 << 2), (((((int) maxY )) << 1) | 1));
	cornerOop = pointResult1;
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	originOop = oop;
	/* begin popRemappableOop */
	oop1 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	rectOop = oop1;
	/* begin storePointer:ofObject:withValue: */
	if (rectOop < youngStart) {
		possibleRootStoreIntovalue(rectOop, originOop);
	}
	longAtput(((((char *) rectOop)) + 4) + (0 << 2), originOop);
	/* begin storePointer:ofObject:withValue: */
	if (rectOop < youngStart) {
		possibleRootStoreIntovalue(rectOop, cornerOop);
	}
	longAtput(((((char *) rectOop)) + 4) + (1 << 2), cornerOop);
	return rectOop;
}

int scaleData(void) {
    float realN;
    int i;

	if (fftSize <= 1) {
		return null;
	}
	realN = ((float) (1.0 / (((double) fftSize))));
	for (i = 0; i <= (fftSize - 1); i += 1) {
		realData[i] = ((realData[i]) * realN);
		imagData[i] = ((imagData[i]) * realN);
	}
}

int setAALevel(int level) {
    int aaLevel;

	if (level >= 4) {
		aaLevel = 4;
	}
	if ((level >= 2) && (level < 4)) {
		aaLevel = 2;
	}
	if (level < 2) {
		aaLevel = 1;
	}
	workBuffer[48] = aaLevel;
	if (aaLevel == 1) {
		workBuffer[49] = 0;
		workBuffer[51] = 4294967295U;
		workBuffer[52] = 0;
	}
	if (aaLevel == 2) {
		workBuffer[49] = 1;
		workBuffer[51] = 4244438268U;
		workBuffer[52] = 1;
	}
	if (aaLevel == 4) {
		workBuffer[49] = 2;
		workBuffer[51] = 4042322160U;
		workBuffer[52] = 3;
	}
	workBuffer[50] = ((workBuffer[49]) * 2);
	workBuffer[53] = (workBuffer[49]);
}

int setCompilerInitialized(int newFlag) {
    int oldFlag;

	oldFlag = compilerInitialized;
	compilerInitialized = newFlag;
	return oldFlag;
}

EXPORT(int) setInterpreter(int anInterpreter) {
	interpreterProxy = anInterpreter;
}

int showDisplayBits(void) {
    int displayObj;
    int dispBits;
    int affectedRectL;
    int affectedRectR;
    int affectedRectT;
    int affectedRectB;
    int dispBitsIndex;
    int h;
    int w;
    int d;
    int successValue;

	if (deferDisplayUpdates) {
		return null;
	}
	displayObj = longAt(((((char *) specialObjectsOop)) + 4) + (14 << 2));
	if (!(destForm == displayObj)) {
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
	if (successFlag) {
		affectedRectL = affectedL;
		affectedRectR = affectedR;
		affectedRectT = affectedT;
		affectedRectB = affectedB;
		dispBitsIndex = dispBits + 4;
		ioShowDisplay(dispBitsIndex, w, h, d, affectedRectL, affectedRectR, affectedRectT, affectedRectB);
	}
}

int showDisplayBitsLeftTopRightBottom(int aForm, int affectedRectL, int affectedRectT, int affectedRectR, int affectedRectB) {
    int displayObj;
    int dispBits;
    int dispBitsIndex;
    int h;
    int w;
    int d;
    int successValue;

	if (deferDisplayUpdates) {
		return null;
	}
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
	if (successFlag) {
		dispBitsIndex = dispBits + 4;
		ioShowDisplay(dispBitsIndex, w, h, d, affectedRectL, affectedRectR, affectedRectT, affectedRectB);
		ioForceDisplayUpdate();
	}
}

int showFilldepthrightX(int fillIndex, int depth, int rightX) {
	if (!(wbStackPush(3))) {
		return null;
	}
	workBuffer[(workBuffer[10]) + 0] = fillIndex;
	workBuffer[(workBuffer[10]) + (0 + 1)] = depth;
	workBuffer[(workBuffer[10]) + (0 + 2)] = rightX;
	if (((workBuffer[1]) - (workBuffer[10])) == 3) {
		return null;
	}
	if (fillSortsbefore(0, ((workBuffer[1]) - (workBuffer[10])) - 3)) {
		workBuffer[(workBuffer[10]) + 0] = (workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)]);
		workBuffer[(workBuffer[10]) + (0 + 1)] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)]);
		workBuffer[(workBuffer[10]) + (0 + 2)] = (workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)]);
		workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)] = fillIndex;
		workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)] = depth;
		workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)] = rightX;
	}
}

int signalSemaphoreWithIndex(int index) {
    int i;

	if (index <= 0) {
		return null;
	}
	interruptCheckCounter = 0;
	for (i = 1; i <= semaphoresToSignalCount; i += 1) {
		if ((semaphoresToSignal[i]) == index) {
			return null;
		}
	}
	if (semaphoresToSignalCount < 25) {
		semaphoresToSignalCount += 1;
		semaphoresToSignal[semaphoresToSignalCount] = index;
	}
}

int sizeBitsOf(int oop) {
    int header;

	header = longAt(oop);
	if ((header & 3) == 0) {
		return (longAt(oop - 8)) & 4294967292U;
	} else {
		return header & 252;
	}
}

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

int * smallSqrtTable(void) {
    static int theTable[32] = 
	{0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6};

	return theTable;
}

int smoothPixatXfyfdxhdyhdxvdyvpixPerWordpixelMasksourceMap(int n, int xf, int yf, int dxh, int dyh, int dxv, int dyv, int srcPixPerWord, int sourcePixMask, int sourceMap) {
    int j;
    int sourcePix;
    int b;
    int x;
    int y;
    int bitsPerColor;
    int nPix;
    int maxPix;
    int i;
    int d;
    int rgb;
    int g;
    int r;
    int mask;
    int srcPix;
    int destPix;
    int d1;

	r = g = b = 0;
	maxPix = n * n;
	x = xf;
	y = yf;
	nPix = 0;
	for (i = 0; i <= (n - 1); i += 1) {
		for (j = 0; j <= (n - 1); j += 1) {
			sourcePix = (sourcePixAtXypixPerWord(((unsigned) ((x + (dxh * i)) + (dxv * j))) >> 14, ((unsigned) ((y + (dyh * i)) + (dyv * j))) >> 14, srcPixPerWord)) & sourcePixMask;
			if (!((combinationRule == 25) && (sourcePix == 0))) {
				nPix += 1;
				if (sourcePixSize < 16) {
					rgb = (longAt(((((char *) sourceMap)) + 4) + (sourcePix << 2))) & 16777215;
				} else {
					if (sourcePixSize == 32) {
						rgb = sourcePix & 16777215;
					} else {
						/* begin rgbMap:from:to: */
						if ((d1 = 8 - 5) > 0) {
							mask = (1 << 5) - 1;
							srcPix = sourcePix << d1;
							mask = mask << d1;
							destPix = srcPix & mask;
							mask = mask << 8;
							srcPix = srcPix << d1;
							rgb = (destPix + (srcPix & mask)) + ((srcPix << d1) & (mask << 8));
							goto l1;
						} else {
							if (d1 == 0) {
								if (5 == 5) {
									rgb = sourcePix & 32767;
									goto l1;
								}
								if (5 == 8) {
									rgb = sourcePix & 16777215;
									goto l1;
								}
								rgb = sourcePix;
								goto l1;
							}
							if (sourcePix == 0) {
								rgb = sourcePix;
								goto l1;
							}
							d1 = 5 - 8;
							mask = (1 << 8) - 1;
							srcPix = ((unsigned) sourcePix) >> d1;
							destPix = srcPix & mask;
							mask = mask << 8;
							srcPix = ((unsigned) srcPix) >> d1;
							destPix = (destPix + (srcPix & mask)) + ((((unsigned) srcPix) >> d1) & (mask << 8));
							if (destPix == 0) {
								rgb = 1;
								goto l1;
							}
							rgb = destPix;
							goto l1;
						}
					l1:	/* end rgbMap:from:to: */;
					}
				}
				r += (((unsigned) rgb) >> 16) & 255;
				g += (((unsigned) rgb) >> 8) & 255;
				b += rgb & 255;
			}
		}
	}
	if ((nPix == 0) || ((combinationRule == 25) && (nPix < (((int) maxPix >> 1))))) {
		return 0;
	}
	if (colorMap != nilObj) {
		bitsPerColor = cmBitsPerColor;
	} else {
		if (destPixSize == 16) {
			bitsPerColor = 5;
		}
		if (destPixSize == 32) {
			bitsPerColor = 8;
		}
	}
	d = 8 - bitsPerColor;
	rgb = (((((unsigned) (r / nPix)) >> d) << (bitsPerColor * 2)) + ((((unsigned) (g / nPix)) >> d) << bitsPerColor)) + (((unsigned) (b / nPix)) >> d);
	if (rgb == 0) {
		if (((r + g) + b) > 0) {
			rgb = 1;
		}
	}
	if (colorMap != nilObj) {
		return longAt(((((char *) colorMap)) + 4) + (rgb << 2));
	} else {
		return rgb;
	}
}

int socketRecordSize(void) {
	return sizeof(SQSocket);
}

SQSocket * socketValueOf(int socketOop) {
    int socketIndex;
    int successValue;

	/* begin success: */
	successValue = (((((unsigned) (longAt(socketOop))) >> 8) & 15) >= 8) && ((lengthOf(socketOop)) == (socketRecordSize()));
	successFlag = successValue && successFlag;
	if (successFlag) {
		socketIndex = socketOop + 4;
		return (SQSocket *) socketIndex;
	} else {
		return null;
	}
}

int sourcePixAtXypixPerWord(int x, int y, int srcPixPerWord) {
    int sourceWord;
    int index;

	if ((x < 0) || (x >= srcWidth)) {
		return 0;
	}
	if ((y < 0) || (y >= srcHeight)) {
		return 0;
	}
	index = ((y * sourceRaster) + (x / srcPixPerWord)) * 4;
	sourceWord = longAt((sourceBits + 4) + index);
	return ((unsigned) sourceWord) >> ((32 - sourcePixSize) - ((x % srcPixPerWord) * sourcePixSize));
}

int sourceWordwith(int sourceWord, int destinationWord) {
	return sourceWord;
}

int splObj(int index) {
	return longAt(((((char *) specialObjectsOop)) + 4) + (index << 2));
}

int stObjectat(int array, int index) {
    int stSize;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
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
		goto l3;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l3;
	}
l3:	/* end lengthOf:baseHeader:format: */;
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
l2:	/* end fixedFieldsOf:format:length: */;
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

int stObjectatput(int array, int index, int value) {
    int stSize;
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int valueToStore;
    int sz;
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
		goto l3;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l3;
	}
l3:	/* end lengthOf:baseHeader:format: */;
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
l2:	/* end fixedFieldsOf:format:length: */;
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

int stSizeOf(int oop) {
    int hdr;
    int totalLength;
    int fmt;
    int fixedFields;
    int sp;
    int classFormat;
    int class;
    int sz;
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
		goto l2;
	} else {
		totalLength = (sz - 4) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l1;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l1;
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
l1:	/* end fixedFieldsOf:format:length: */;
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

int startOfMemory(void) {
	return (int) memory;
}

int stepToFirstBezierInat(int bezier, int yValue) {
    int fwDx;
    int fwDDx;
    int fwDy;
    int fwDDy;
    int viaX;
    int viaY;
    int deltaY;
    int fwX1;
    int fwX2;
    int fwY1;
    int fwY2;
    int maxSteps;
    int startX;
    int startY;
    int scaledStepSize;
    int squaredStepSize;
    int *updateData;
    int endX;
    int endY;
    int word1;
    int word2;
    int xValue;
    int fwDx1;
    int fwDy1;
    int lastX;
    int minY;
    int lastY;

	if ((!((((objBuffer[bezier + 0]) & 65535) & 1) != 0)) && (yValue >= (objBuffer[bezier + 15]))) {
		return objBuffer[bezier + 7] = 0;
	}
	startX = objBuffer[bezier + 4];
	startY = objBuffer[bezier + 5];
	viaX = objBuffer[bezier + 12];
	viaY = objBuffer[bezier + 13];
	endX = objBuffer[bezier + 14];
	endY = objBuffer[bezier + 15];
	deltaY = endY - startY;
	fwX1 = (viaX - startX) * 2;
	fwX2 = (startX + endX) - (viaX * 2);
	fwY1 = (viaY - startY) * 2;
	fwY2 = (startY + endY) - (viaY * 2);
	maxSteps = deltaY * 2;
	if (maxSteps < 2) {
		maxSteps = 2;
	}
	scaledStepSize = 16777216 / maxSteps;
	/* begin absoluteSquared8Dot24: */
	word1 = scaledStepSize & 65535;
	word2 = (((unsigned) scaledStepSize >> 16)) & 255;
	squaredStepSize = ((unsigned) (((((unsigned) (((unsigned) (word1 * word1))) >> 16)) + ((word1 * word2) * 2)) + (((unsigned) (word2 * word2) << 16))) >> 8);
	fwDx = fwX1 * scaledStepSize;
	fwDDx = (fwX2 * squaredStepSize) * 2;
	fwDx += ((int) fwDDx >> 1);
	fwDy = fwY1 * scaledStepSize;
	fwDDy = (fwY2 * squaredStepSize) * 2;
	fwDy += ((int) fwDDy >> 1);
	objBuffer[bezier + 7] = deltaY;
	updateData = (objBuffer + bezier) + 10;
	updateData[0] = (startX * 256);
	updateData[1] = (startY * 256);
	updateData[2] = fwDx;
	updateData[3] = fwDy;
	updateData[4] = fwDDx;
	updateData[5] = fwDDy;
	if (!((startY = objBuffer[bezier + 5]) == yValue)) {
		/* begin stepToNextBezierIn:at: */
		/* begin stepToNextBezierForward:at: */
		lastX = (((int*) ((objBuffer + bezier) + 10)))[0];
		lastY = (((int*) ((objBuffer + bezier) + 10)))[1];
		fwDx1 = (((int*) ((objBuffer + bezier) + 10)))[2];
		fwDy1 = (((int*) ((objBuffer + bezier) + 10)))[3];
		minY = yValue * 256;
		while ((minY > lastY) && (fwDy1 >= 0)) {
			lastX += ((int) (fwDx1 + 32768) >> 16);
			lastY += ((int) (fwDy1 + 32768) >> 16);
			fwDx1 += (((int*) ((objBuffer + bezier) + 10)))[4];
			fwDy1 += (((int*) ((objBuffer + bezier) + 10)))[5];
		}
		(((int*) ((objBuffer + bezier) + 10)))[0] = lastX;
		(((int*) ((objBuffer + bezier) + 10)))[1] = lastY;
		(((int*) ((objBuffer + bezier) + 10)))[2] = fwDx1;
		(((int*) ((objBuffer + bezier) + 10)))[3] = fwDy1;
		xValue = ((int) lastX >> 8);
		objBuffer[bezier + 4] = xValue;
		objBuffer[bezier + 7] = (deltaY - (yValue - startY));
	}
}

int stepToFirstLineInat(int line, int yValue) {
    int deltaX;
    int deltaY;
    int startY;
    int xDir;
    int xInc;
    int i;
    int errorAdjUp;
    int widthX;
    int error;
    int x;
    int err;

	if ((!((((objBuffer[line + 0]) & 65535) & 1) != 0)) && (yValue >= (objBuffer[line + 15]))) {
		return objBuffer[line + 7] = 0;
	}
	deltaX = (objBuffer[line + 14]) - (objBuffer[line + 4]);
	deltaY = (objBuffer[line + 15]) - (objBuffer[line + 5]);
	if (deltaX >= 0) {
		xDir = 1;
		widthX = deltaX;
		error = 0;
	} else {
		xDir = -1;
		widthX = 0 - deltaX;
		error = 1 - deltaY;
	}
	if (deltaY == 0) {
		error = 0;
		xInc = deltaX;
		errorAdjUp = 0;
	} else {
		if (deltaY > widthX) {
			xInc = 0;
			errorAdjUp = widthX;
		} else {
			xInc = (widthX / deltaY) * xDir;
			errorAdjUp = widthX % deltaY;
		}
	}
	objBuffer[line + 7] = deltaY;
	objBuffer[line + 10] = xDir;
	objBuffer[line + 12] = xInc;
	objBuffer[line + 13] = error;
	objBuffer[line + 14] = errorAdjUp;
	objBuffer[line + 15] = deltaY;
	if (!((startY = objBuffer[line + 5]) == yValue)) {
		for (i = startY; i <= (yValue - 1); i += 1) {
			/* begin stepToNextLineIn:at: */
			x = (objBuffer[line + 4]) + (objBuffer[line + 12]);
			err = (objBuffer[line + 13]) + (objBuffer[line + 14]);
			if (err > 0) {
				x += objBuffer[line + 10];
				err -= objBuffer[line + 15];
			}
			objBuffer[line + 13] = err;
			objBuffer[line + 4] = x;
		}
		objBuffer[line + 7] = (deltaY - (yValue - startY));
	}
}

int stepToFirstWideBezierInat(int bezier, int yValue) {
    int yExit;
    int yEntry;
    int startY;
    int lineOffset;
    int xDir;
    int i;
    int lineWidth;
    int endX;
    int nLines;

	lineWidth = objBuffer[bezier + 20];
	lineOffset = ((int) lineWidth >> 1);
	endX = objBuffer[bezier + 14];
	startY = objBuffer[bezier + 5];
	stepToFirstBezierInat(bezier, startY);
	nLines = objBuffer[bezier + 7];
	for (i = 0; i <= 5; i += 1) {
		((objBuffer + bezier) + 22)[i] = (((objBuffer + bezier) + 10)[i]);
	}
	xDir = ((objBuffer + bezier) + 10)[2];
	if (xDir == 0) {
		((objBuffer + bezier) + 10)[4];
	}
	if (xDir >= 0) {
		xDir = 1;
	} else {
		xDir = -1;
	}
	if (xDir < 0) {
		adjustWideBezierLeftwidthoffsetendX(bezier, lineWidth, lineOffset, endX);
	} else {
		adjustWideBezierRightwidthoffsetendX(bezier, lineWidth, lineOffset, endX);
	}
	if (nLines == 0) {
		((objBuffer + bezier) + 10)[0] = ((objBuffer[bezier + 21]) * 256);
	}
	objBuffer[bezier + 7] = (nLines + lineWidth);
	yEntry = 0;
	yExit = (0 - nLines) - lineOffset;
	objBuffer[bezier + 18] = yEntry;
	objBuffer[bezier + 19] = yExit;
	if ((yEntry >= lineOffset) && (yExit < 0)) {
		objBuffer[bezier + 0] = (((objBuffer[bezier + 0]) & 65535) & (~65536));
	} else {
		objBuffer[bezier + 0] = (((objBuffer[bezier + 0]) & 65535) | 65536);
	}
	computeFinalWideBezierValueswidth(bezier, lineWidth);
	if (!(startY == yValue)) {
		for (i = startY; i <= (yValue - 1); i += 1) {
			stepToNextWideBezierInat(bezier, i);
		}
		objBuffer[bezier + 7] = ((objBuffer[bezier + 7]) - (yValue - startY));
	}
}

int stepToFirstWideLineInat(int line, int yValue) {
    int yExit;
    int yEntry;
    int startY;
    int startX;
    int lineOffset;
    int xDir;
    int i;
    int lineWidth;
    int nLines;
    int nextX;
    int yExit1;
    int yEntry1;
    int lineOffset1;
    int lastX;
    int lineWidth1;
    int x;
    int err;

	lineWidth = objBuffer[line + 20];
	lineOffset = ((int) lineWidth >> 1);
	startX = objBuffer[line + 4];
	startY = objBuffer[line + 5];
	stepToFirstLineInat(line, startY);
	nLines = objBuffer[line + 7];
	xDir = objBuffer[line + 10];
	objBuffer[line + 4] = (startX - lineOffset);
	objBuffer[line + 7] = (nLines + lineWidth);
	if (xDir > 0) {
		objBuffer[line + 17] = ((objBuffer[line + 12]) + lineWidth);
	} else {
		objBuffer[line + 17] = (lineWidth - (objBuffer[line + 12]));
		objBuffer[line + 4] = ((objBuffer[line + 4]) + (objBuffer[line + 12]));
	}
	yEntry = 0;
	yExit = (0 - nLines) - lineOffset;
	objBuffer[line + 18] = yEntry;
	objBuffer[line + 19] = yExit;
	if ((yEntry >= lineOffset) && (yExit < 0)) {
		objBuffer[line + 0] = (((objBuffer[line + 0]) & 65535) & (~65536));
	} else {
		objBuffer[line + 0] = (((objBuffer[line + 0]) & 65535) | 65536);
	}
	if (!(startY == yValue)) {
		for (i = startY; i <= (yValue - 1); i += 1) {
			/* begin stepToNextWideLineIn:at: */
			yEntry1 = (objBuffer[line + 18]) + 1;
			yExit1 = (objBuffer[line + 19]) + 1;
			objBuffer[line + 18] = yEntry1;
			objBuffer[line + 19] = yExit1;
			lineWidth1 = objBuffer[line + 20];
			lineOffset1 = ((int) lineWidth1 >> 1);
			if (yEntry1 >= lineOffset1) {
				objBuffer[line + 0] = (((objBuffer[line + 0]) & 65535) & (~65536));
			}
			if (yExit1 >= 0) {
				objBuffer[line + 0] = (((objBuffer[line + 0]) & 65535) | 65536);
			}
			lastX = objBuffer[line + 4];
			/* begin stepToNextLineIn:at: */
			x = (objBuffer[line + 4]) + (objBuffer[line + 12]);
			err = (objBuffer[line + 13]) + (objBuffer[line + 14]);
			if (err > 0) {
				x += objBuffer[line + 10];
				err -= objBuffer[line + 15];
			}
			objBuffer[line + 13] = err;
			objBuffer[line + 4] = x;
			nextX = objBuffer[line + 4];
			if ((yEntry1 <= lineWidth1) || ((yExit1 + lineOffset1) >= 0)) {
				adjustWideLineafterSteppingFromto(line, lastX, nextX);
			}
		}
		objBuffer[line + 7] = ((objBuffer[line + 7]) - (yValue - startY));
	}
}

int stepToNextBezierInat(int bezier, int yValue) {
    int xValue;
    int fwDx;
    int fwDy;
    int lastX;
    int minY;
    int lastY;

	/* begin stepToNextBezierForward:at: */
	lastX = (((int*) ((objBuffer + bezier) + 10)))[0];
	lastY = (((int*) ((objBuffer + bezier) + 10)))[1];
	fwDx = (((int*) ((objBuffer + bezier) + 10)))[2];
	fwDy = (((int*) ((objBuffer + bezier) + 10)))[3];
	minY = yValue * 256;
	while ((minY > lastY) && (fwDy >= 0)) {
		lastX += ((int) (fwDx + 32768) >> 16);
		lastY += ((int) (fwDy + 32768) >> 16);
		fwDx += (((int*) ((objBuffer + bezier) + 10)))[4];
		fwDy += (((int*) ((objBuffer + bezier) + 10)))[5];
	}
	(((int*) ((objBuffer + bezier) + 10)))[0] = lastX;
	(((int*) ((objBuffer + bezier) + 10)))[1] = lastY;
	(((int*) ((objBuffer + bezier) + 10)))[2] = fwDx;
	(((int*) ((objBuffer + bezier) + 10)))[3] = fwDy;
	xValue = ((int) lastX >> 8);
	objBuffer[bezier + 4] = xValue;
}

int stepToNextLineInat(int line, int yValue) {
    int x;
    int err;

	x = (objBuffer[line + 4]) + (objBuffer[line + 12]);
	err = (objBuffer[line + 13]) + (objBuffer[line + 14]);
	if (err > 0) {
		x += objBuffer[line + 10];
		err -= objBuffer[line + 15];
	}
	objBuffer[line + 13] = err;
	objBuffer[line + 4] = x;
}

int stepToNextWideBezier(void) {
	stepToNextWideBezierInat(aetBuffer[workBuffer[13]], workBuffer[88]);
}

int stepToNextWideBezierInat(int bezier, int yValue) {
    int lineOffset;
    int yExit;
    int lineWidth;
    int yEntry;
    int fwDx;
    int fwDy;
    int lastX;
    int minY;
    int lastY;
    int fwDx1;
    int fwDy1;
    int lastX1;
    int minY1;
    int lastY1;

	lineWidth = objBuffer[bezier + 20];
	lineOffset = ((int) lineWidth >> 1);
	yEntry = (objBuffer[bezier + 18]) + 1;
	yExit = (objBuffer[bezier + 19]) + 1;
	objBuffer[bezier + 18] = yEntry;
	objBuffer[bezier + 19] = yExit;
	if (yEntry >= lineOffset) {
		objBuffer[bezier + 0] = (((objBuffer[bezier + 0]) & 65535) & (~65536));
	}
	if (yExit >= 0) {
		objBuffer[bezier + 0] = (((objBuffer[bezier + 0]) & 65535) | 65536);
	}
	if ((yExit + lineOffset) < 0) {
		/* begin stepToNextBezierForward:at: */
		lastX = (((int*) ((objBuffer + bezier) + 10)))[0];
		lastY = (((int*) ((objBuffer + bezier) + 10)))[1];
		fwDx = (((int*) ((objBuffer + bezier) + 10)))[2];
		fwDy = (((int*) ((objBuffer + bezier) + 10)))[3];
		minY = yValue * 256;
		while ((minY > lastY) && (fwDy >= 0)) {
			lastX += ((int) (fwDx + 32768) >> 16);
			lastY += ((int) (fwDy + 32768) >> 16);
			fwDx += (((int*) ((objBuffer + bezier) + 10)))[4];
			fwDy += (((int*) ((objBuffer + bezier) + 10)))[5];
		}
		(((int*) ((objBuffer + bezier) + 10)))[0] = lastX;
		(((int*) ((objBuffer + bezier) + 10)))[1] = lastY;
		(((int*) ((objBuffer + bezier) + 10)))[2] = fwDx;
		(((int*) ((objBuffer + bezier) + 10)))[3] = fwDy;
		((int) lastX >> 8);
	} else {
		((objBuffer + bezier) + 10)[0] = ((objBuffer[bezier + 21]) * 256);
	}
	/* begin stepToNextBezierForward:at: */
	lastX1 = (((int*) ((objBuffer + bezier) + 22)))[0];
	lastY1 = (((int*) ((objBuffer + bezier) + 22)))[1];
	fwDx1 = (((int*) ((objBuffer + bezier) + 22)))[2];
	fwDy1 = (((int*) ((objBuffer + bezier) + 22)))[3];
	minY1 = yValue * 256;
	while ((minY1 > lastY1) && (fwDy1 >= 0)) {
		lastX1 += ((int) (fwDx1 + 32768) >> 16);
		lastY1 += ((int) (fwDy1 + 32768) >> 16);
		fwDx1 += (((int*) ((objBuffer + bezier) + 22)))[4];
		fwDy1 += (((int*) ((objBuffer + bezier) + 22)))[5];
	}
	(((int*) ((objBuffer + bezier) + 22)))[0] = lastX1;
	(((int*) ((objBuffer + bezier) + 22)))[1] = lastY1;
	(((int*) ((objBuffer + bezier) + 22)))[2] = fwDx1;
	(((int*) ((objBuffer + bezier) + 22)))[3] = fwDy1;
	((int) lastX1 >> 8);
	computeFinalWideBezierValueswidth(bezier, lineWidth);
}

int stepToNextWideLineInat(int line, int yValue) {
    int nextX;
    int yExit;
    int yEntry;
    int lineOffset;
    int lastX;
    int lineWidth;
    int x;
    int err;

	yEntry = (objBuffer[line + 18]) + 1;
	yExit = (objBuffer[line + 19]) + 1;
	objBuffer[line + 18] = yEntry;
	objBuffer[line + 19] = yExit;
	lineWidth = objBuffer[line + 20];
	lineOffset = ((int) lineWidth >> 1);
	if (yEntry >= lineOffset) {
		objBuffer[line + 0] = (((objBuffer[line + 0]) & 65535) & (~65536));
	}
	if (yExit >= 0) {
		objBuffer[line + 0] = (((objBuffer[line + 0]) & 65535) | 65536);
	}
	lastX = objBuffer[line + 4];
	/* begin stepToNextLineIn:at: */
	x = (objBuffer[line + 4]) + (objBuffer[line + 12]);
	err = (objBuffer[line + 13]) + (objBuffer[line + 14]);
	if (err > 0) {
		x += objBuffer[line + 10];
		err -= objBuffer[line + 15];
	}
	objBuffer[line + 13] = err;
	objBuffer[line + 4] = x;
	nextX = objBuffer[line + 4];
	if ((yEntry <= lineWidth) || ((yExit + lineOffset) >= 0)) {
		adjustWideLineafterSteppingFromto(line, lastX, nextX);
	}
}

int storeEdgeStateFrominto(int edge, int edgeOop) {
	if ((slotSizeOf(edgeOop)) < 6) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (((objBuffer[edge + 2]) ^ ((objBuffer[edge + 2]) << 1)) >= 0) {
		longAtput(((((char *) edgeOop)) + 4) + (0 << 2), (((objBuffer[edge + 2]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (((objBuffer[edge + 4]) ^ ((objBuffer[edge + 4]) << 1)) >= 0) {
		longAtput(((((char *) edgeOop)) + 4) + (1 << 2), (((objBuffer[edge + 4]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (((workBuffer[88]) ^ ((workBuffer[88]) << 1)) >= 0) {
		longAtput(((((char *) edgeOop)) + 4) + (2 << 2), (((workBuffer[88]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (((objBuffer[edge + 6]) ^ ((objBuffer[edge + 6]) << 1)) >= 0) {
		longAtput(((((char *) edgeOop)) + 4) + (3 << 2), (((objBuffer[edge + 6]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (((objBuffer[edge + 7]) ^ ((objBuffer[edge + 7]) << 1)) >= 0) {
		longAtput(((((char *) edgeOop)) + 4) + (4 << 2), (((objBuffer[edge + 7]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	workBuffer[65] = edge;
}

int storeFillStateInto(int fillOop) {
    int fillIndex;
    int leftX;
    int rightX;

	fillIndex = workBuffer[66];
	leftX = workBuffer[67];
	rightX = workBuffer[68];
	if ((slotSizeOf(fillOop)) < 6) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (((objBuffer[fillIndex + 2]) ^ ((objBuffer[fillIndex + 2]) << 1)) >= 0) {
		longAtput(((((char *) fillOop)) + 4) + (0 << 2), (((objBuffer[fillIndex + 2]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if ((leftX ^ (leftX << 1)) >= 0) {
		longAtput(((((char *) fillOop)) + 4) + (1 << 2), ((leftX << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if ((rightX ^ (rightX << 1)) >= 0) {
		longAtput(((((char *) fillOop)) + 4) + (2 << 2), ((rightX << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (((workBuffer[88]) ^ ((workBuffer[88]) << 1)) >= 0) {
		longAtput(((((char *) fillOop)) + 4) + (3 << 2), (((workBuffer[88]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
}

int storeIntegerofObjectwithValue(int fieldIndex, int objectPointer, int integerValue) {
	if ((integerValue ^ (integerValue << 1)) >= 0) {
		longAtput(((((char *) objectPointer)) + 4) + (fieldIndex << 2), ((integerValue << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
}

int storePointerofObjectwithValue(int fieldIndex, int oop, int valuePointer) {
	if (oop < youngStart) {
		possibleRootStoreIntovalue(oop, valuePointer);
	}
	return longAtput(((((char *) oop)) + 4) + (fieldIndex << 2), valuePointer);
}

int storeRenderingState(void) {
    int edgeOop;
    int fillOop;
    int reason;
    int edge;
    int sp;
    int oop;
    int oop1;

	if (!successFlag) {
		return null;
	}
	if (engineStopped) {
		/* begin storeStopStateIntoEdge:fill: */
		/* begin stackObjectValue: */
		oop = longAt(stackPointer - (1 * 4));
		if ((oop & 1)) {
			/* begin primitiveFail */
			successFlag = 0;
			edgeOop = null;
			goto l1;
		}
		edgeOop = oop;
	l1:	/* end stackObjectValue: */;
		/* begin stackObjectValue: */
		oop1 = longAt(stackPointer - (0 * 4));
		if ((oop1 & 1)) {
			/* begin primitiveFail */
			successFlag = 0;
			fillOop = null;
			goto l2;
		}
		fillOop = oop1;
	l2:	/* end stackObjectValue: */;
		reason = workBuffer[64];
		if (reason == 4) {
			edge = getBuffer[workBuffer[11]];
			storeEdgeStateFrominto(edge, edgeOop);
			workBuffer[11] = ((workBuffer[11]) + 1);
		}
		if (reason == 5) {
			storeFillStateInto(fillOop);
		}
		if (reason == 6) {
			edge = aetBuffer[workBuffer[13]];
			storeEdgeStateFrominto(edge, edgeOop);
		}
	}
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	/* begin pop: */
	stackPointer -= 3 * 4;
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + 4, (((workBuffer[64]) << 1) | 1));
	stackPointer = sp;
}

int subWordwith(int sourceWord, int destinationWord) {
	return sourceWord - destinationWord;
}

int subdivideBezier(int index) {
    int deltaX;
    int deltaY;
    int endX;
    int endY;
    int startX;
    int startY;

	startY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)];
	endY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)];
	if (endY == startY) {
		return index;
	}
	deltaY = endY - startY;
	if (deltaY < 0) {
		deltaY = 0 - deltaY;
	}
	if (deltaY > 255) {
		workBuffer[109] = ((workBuffer[109]) + 1);
		return computeBezierSplitAtHalf(index);
	}
	startX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)];
	endX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)];
	deltaX = endX - startX;
	if (deltaX < 0) {
		deltaX = 0 - deltaX;
	}
	if ((deltaY * 32) < deltaX) {
		workBuffer[110] = ((workBuffer[110]) + 1);
		return computeBezierSplitAtHalf(index);
	}
	return index;
}

int subdivideBezierFrom(int index) {
    int otherIndex;
    int index1;
    int index2;

	otherIndex = subdivideBezier(index);
	if (!(otherIndex == index)) {
		index1 = subdivideBezierFrom(index);
		if (engineStopped) {
			return 0;
		}
		index2 = subdivideBezierFrom(otherIndex);
		if (engineStopped) {
			return 0;
		}
		if (index1 >= index2) {
			return index1;
		} else {
			return index2;
		}
	}
	return index;
}

int subdivideToBeMonotoninX(int base, int doTestX) {
    int index1;
    int index2;
    int base2;

	base2 = index1 = index2 = subdivideToBeMonotonInY(base);
	if (doTestX) {
		index1 = subdivideToBeMonotonInX(base);
	}
	if (index1 > index2) {
		index2 = index1;
	}
	if ((base != base2) && (doTestX)) {
		index1 = subdivideToBeMonotonInX(base2);
	}
	if (index1 > index2) {
		index2 = index1;
	}
	return index2;
}

int subdivideToBeMonotonInX(int index) {
    int num;
    int viaX;
    int denom;
    int startX;
    int dx1;
    int dx2;
    int endX;

	startX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)];
	viaX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)];
	endX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)];
	dx1 = viaX - startX;
	dx2 = endX - viaX;
	if ((dx1 * dx2) >= 0) {
		return index;
	}
	workBuffer[108] = ((workBuffer[108]) + 1);
	denom = dx2 - dx1;
	num = dx1;
	if (num < 0) {
		num = 0 - num;
	}
	if (denom < 0) {
		denom = 0 - denom;
	}
	return computeBeziersplitAt(index, (((double) num )) / (((double) denom )));
}

int subdivideToBeMonotonInY(int index) {
    int num;
    int viaY;
    int denom;
    int startY;
    int dy1;
    int dy2;
    int endY;

	startY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)];
	viaY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)];
	endY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)];
	dy1 = viaY - startY;
	dy2 = endY - viaY;
	if ((dy1 * dy2) >= 0) {
		return index;
	}
	workBuffer[108] = ((workBuffer[108]) + 1);
	denom = dy2 - dy1;
	num = dy1;
	if (num < 0) {
		num = 0 - num;
	}
	if (denom < 0) {
		denom = 0 - denom;
	}
	return computeBeziersplitAt(index, (((double) num )) / (((double) denom )));
}

int success(int successValue) {
	successFlag = successValue && successFlag;
}

int sufficientSpaceAfterGC(int minFree) {
	incrementalGC();
	if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) < (((unsigned ) minFree))) {
		if (signalLowSpace) {
			return 0;
		}
		fullGC();
		if ((((unsigned ) ((longAt(freeBlock)) & 4294967292U))) < ((((unsigned ) minFree)) + 15000)) {
			return 0;
		}
	}
	return 1;
}

int superclassOf(int classPointer) {
	return longAt(((((char *) classPointer)) + 4) + (0 << 2));
}

int sweepPhase(void) {
    int entriesAvailable;
    int survivors;
    int firstFree;
    int oopHeader;
    int oop;
    int freeChunk;
    int oopHeaderType;
    int hdrBytes;
    int oopSize;
    int freeChunkSize;
    int extra;
    int chunk;
    int extra1;
    int type;
    int extra2;
    int type1;
    int extra3;

	entriesAvailable = fwdTableInit(8);
	survivors = 0;
	freeChunk = null;
	firstFree = null;
	/* begin oopFromChunk: */
	chunk = youngStart;
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
				freeChunk = oop - hdrBytes;
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

int tallyIntoMapwith(int sourceWord, int destinationWord) {
    int pixVal;
    int mapIndex;
    int pixMask;
    int destShifted;
    int maskShifted;
    int i;
    int mask;
    int srcPix;
    int destPix;
    int d;
    int mask3;
    int srcPix1;
    int destPix1;
    int d1;

	if (colorMap == nilObj) {
		return destinationWord;
	}
	pixMask = maskTable[destPixSize];
	destShifted = destinationWord;
	maskShifted = destMask;
	for (i = 1; i <= pixPerWord; i += 1) {
		if (!((maskShifted & pixMask) == 0)) {
			pixVal = destShifted & pixMask;
			if (destPixSize < 16) {
				mapIndex = pixVal;
			} else {
				if (destPixSize == 16) {
					/* begin rgbMap:from:to: */
					if ((d = cmBitsPerColor - 5) > 0) {
						mask = (1 << 5) - 1;
						srcPix = pixVal << d;
						mask = mask << d;
						destPix = srcPix & mask;
						mask = mask << cmBitsPerColor;
						srcPix = srcPix << d;
						mapIndex = (destPix + (srcPix & mask)) + ((srcPix << d) & (mask << cmBitsPerColor));
						goto l1;
					} else {
						if (d == 0) {
							if (5 == 5) {
								mapIndex = pixVal & 32767;
								goto l1;
							}
							if (5 == 8) {
								mapIndex = pixVal & 16777215;
								goto l1;
							}
							mapIndex = pixVal;
							goto l1;
						}
						if (pixVal == 0) {
							mapIndex = pixVal;
							goto l1;
						}
						d = 5 - cmBitsPerColor;
						mask = (1 << cmBitsPerColor) - 1;
						srcPix = ((unsigned) pixVal) >> d;
						destPix = srcPix & mask;
						mask = mask << cmBitsPerColor;
						srcPix = ((unsigned) srcPix) >> d;
						destPix = (destPix + (srcPix & mask)) + ((((unsigned) srcPix) >> d) & (mask << cmBitsPerColor));
						if (destPix == 0) {
							mapIndex = 1;
							goto l1;
						}
						mapIndex = destPix;
						goto l1;
					}
				l1:	/* end rgbMap:from:to: */;
				} else {
					/* begin rgbMap:from:to: */
					if ((d1 = cmBitsPerColor - 8) > 0) {
						mask3 = (1 << 8) - 1;
						srcPix1 = pixVal << d1;
						mask3 = mask3 << d1;
						destPix1 = srcPix1 & mask3;
						mask3 = mask3 << cmBitsPerColor;
						srcPix1 = srcPix1 << d1;
						mapIndex = (destPix1 + (srcPix1 & mask3)) + ((srcPix1 << d1) & (mask3 << cmBitsPerColor));
						goto l2;
					} else {
						if (d1 == 0) {
							if (8 == 5) {
								mapIndex = pixVal & 32767;
								goto l2;
							}
							if (8 == 8) {
								mapIndex = pixVal & 16777215;
								goto l2;
							}
							mapIndex = pixVal;
							goto l2;
						}
						if (pixVal == 0) {
							mapIndex = pixVal;
							goto l2;
						}
						d1 = 8 - cmBitsPerColor;
						mask3 = (1 << cmBitsPerColor) - 1;
						srcPix1 = ((unsigned) pixVal) >> d1;
						destPix1 = srcPix1 & mask3;
						mask3 = mask3 << cmBitsPerColor;
						srcPix1 = ((unsigned) srcPix1) >> d1;
						destPix1 = (destPix1 + (srcPix1 & mask3)) + ((((unsigned) srcPix1) >> d1) & (mask3 << cmBitsPerColor));
						if (destPix1 == 0) {
							mapIndex = 1;
							goto l2;
						}
						mapIndex = destPix1;
						goto l2;
					}
				l2:	/* end rgbMap:from:to: */;
				}
			}
			longAtput(((((char *) colorMap)) + 4) + (mapIndex << 2), (longAt(((((char *) colorMap)) + 4) + (mapIndex << 2))) + 1);
		}
		maskShifted = ((unsigned) maskShifted) >> destPixSize;
		destShifted = ((unsigned) destShifted) >> destPixSize;
	}
	return destinationWord;
}

int toggleFilldepthrightX(int fillIndex, int depth, int rightX) {
    int hidden;

	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		if (wbStackPush(3)) {
			workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)] = fillIndex;
			workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)] = depth;
			workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)] = rightX;
		}
	} else {
		hidden = hideFilldepth(fillIndex, depth);
		if (!(hidden)) {
			showFilldepthrightX(fillIndex, depth, rightX);
		}
	}
}

int toggleFillsOf(int edge) {
    int fillIndex;
    int depth;
    int leftX;

	if (!(needAvailableSpace(3 * 2))) {
		return null;
	}
	depth = (objBuffer[edge + 6]) << 1;
	fillIndex = objBuffer[edge + 8];
	if (!(fillIndex == 0)) {
		toggleFilldepthrightX(fillIndex, depth, 999999999);
	}
	fillIndex = objBuffer[edge + 9];
	if (!(fillIndex == 0)) {
		toggleFilldepthrightX(fillIndex, depth, 999999999);
	}
	/* begin quickRemoveInvalidFillsAt: */
	leftX = objBuffer[edge + 4];
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		goto l1;
	}
	while ((topRightX()) <= leftX) {
		hideFilldepth(topFill(), topDepth());
		if (((workBuffer[1]) - (workBuffer[10])) == 0) {
			goto l1;
		}
	}
l1:	/* end quickRemoveInvalidFillsAt: */;
}

int toggleWideFillOf(int edge) {
    int fill;
    int index;
    int lineWidth;
    int rightX;
    int depth;
    int type;
    int leftX;

	type = ((unsigned) ((objBuffer[edge + 0]) & 65535)) >> 1;
	dispatchedValue = edge;
	switch (type) {
	case 0:
	case 1:
		errorWrongIndex();
		break;
	case 2:
		dispatchReturnValue = objBuffer[dispatchedValue + 17];
		break;
	case 3:
		dispatchReturnValue = objBuffer[dispatchedValue + 17];
		break;
	}
	lineWidth = dispatchReturnValue;
	switch (type) {
	case 0:
	case 1:
		errorWrongIndex();
		break;
	case 2:
		dispatchReturnValue = objBuffer[dispatchedValue + 16];
		break;
	case 3:
		dispatchReturnValue = objBuffer[dispatchedValue + 16];
		break;
	}
	fill = dispatchReturnValue;
	if (fill == 0) {
		return null;
	}
	if (!(needAvailableSpace(3))) {
		return null;
	}
	depth = ((objBuffer[edge + 6]) << 1) + 1;
	rightX = (objBuffer[edge + 4]) + lineWidth;
	index = findStackFilldepth(fill, depth);
	if (index == -1) {
		showFilldepthrightX(fill, depth, rightX);
	} else {
		if ((workBuffer[(workBuffer[10]) + (index + 2)]) < rightX) {
			workBuffer[(workBuffer[10]) + (index + 2)] = rightX;
		}
	}
	/* begin quickRemoveInvalidFillsAt: */
	leftX = objBuffer[edge + 4];
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		goto l1;
	}
	while ((topRightX()) <= leftX) {
		hideFilldepth(topFill(), topDepth());
		if (((workBuffer[1]) - (workBuffer[10])) == 0) {
			goto l1;
		}
	}
l1:	/* end quickRemoveInvalidFillsAt: */;
}

int topDepth(void) {
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		return -1;
	} else {
		return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)];
	}
}

int topFill(void) {
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		return 0;
	} else {
		return workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
	}
}

int topRightX(void) {
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		return 999999999;
	} else {
		return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
	}
}

int transferTo(int aProc) {
    int sched;
    int newProc;
    int oldProc;
    int oop;
    int valuePointer;
    int tmp;

	newProc = aProc;
	if (compilerInitialized) {
		/* begin pushRemappableOop: */
		remapBuffer[remapBufferCount += 1] = newProc;
		/* begin compilerProcessChangeHook */
		if (compilerInitialized) {
			compilerProcessChange();
		}
		/* begin popRemappableOop */
		oop = remapBuffer[remapBufferCount];
		remapBufferCount -= 1;
		newProc = oop;
	}
	sched = longAt(((((char *) (longAt(((((char *) specialObjectsOop)) + 4) + (3 << 2))))) + 4) + (1 << 2));
	oldProc = longAt(((((char *) sched)) + 4) + (1 << 2));
	/* begin storePointer:ofObject:withValue: */
	valuePointer = activeContext;
	if (oldProc < youngStart) {
		possibleRootStoreIntovalue(oldProc, valuePointer);
	}
	longAtput(((((char *) oldProc)) + 4) + (1 << 2), valuePointer);
	/* begin storePointer:ofObject:withValue: */
	if (sched < youngStart) {
		possibleRootStoreIntovalue(sched, newProc);
	}
	longAtput(((((char *) sched)) + 4) + (1 << 2), newProc);
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
	reclaimableContextCount = 0;
}

int transformColor(int fillIndex) {
    float *transform;
    int g;
    int b;
    int a;
    double alphaScale;
    int r;

	if (!((fillIndex == 0) || ((fillIndex & 4278190080U) != 0))) {
		return fillIndex;
	}
	b = fillIndex & 255;
	g = (((unsigned) fillIndex) >> 8) & 255;
	r = (((unsigned) fillIndex) >> 16) & 255;
	a = (((unsigned) fillIndex) >> 24) & 255;
	if ((workBuffer[17]) != 0) {
		transform = ((float *) (workBuffer + 24));
		alphaScale = ((a * (transform[6])) + (transform[7])) / a;
		r = ((int) (((r * (transform[0])) + (transform[1])) * alphaScale) );
		g = ((int) (((g * (transform[2])) + (transform[3])) * alphaScale) );
		b = ((int) (((b * (transform[4])) + (transform[5])) * alphaScale) );
		a = a * alphaScale;
		r = ((r < 0) ? 0 : r);
		r = ((r < 255) ? r : 255);
		g = ((g < 0) ? 0 : g);
		g = ((g < 255) ? g : 255);
		b = ((b < 0) ? 0 : b);
		b = ((b < 255) ? b : 255);
		a = ((a < 0) ? 0 : a);
		a = ((a < 255) ? a : 255);
	}
	if (a < 1) {
		return 0;
	}
	if ((a < 255) && ((workBuffer[63]) != 0)) {
		/* begin stopBecauseOf: */
		workBuffer[64] = 3;
		engineStopped = 1;
	}
	return ((b + (g << 8)) + (r << 16)) + (a << 24);
}

int transformForward(int forward) {
    int theta;
    int j;
    int lev;
    int level;
    int ii;
    float imagU;
    float imagT;
    int fftSize2;
    float realU;
    int ip;
    float realT;
    int i;
    int fftSize4;
    int fftScale;
    int lev1;

	fftSize2 = ((int) fftSize >> 1);
	fftSize4 = ((int) fftSize >> 2);
	for (level = 1; level <= nu; level += 1) {
		lev = ((level < 0) ? ((unsigned) 1 >> -level) : ((unsigned) 1 << level));
		lev1 = ((int) lev >> 1);
		fftScale = fftSize / lev;
		for (j = 1; j <= lev1; j += 1) {
			theta = (j - 1) * fftScale;
			if (theta < fftSize4) {
				realU = sinTable[(sinTableSize - theta) - 1];
				imagU = sinTable[theta];
			} else {
				realU = 0.0 - (sinTable[theta - fftSize4]);
				imagU = sinTable[fftSize2 - theta];
			}
			if (!(forward)) {
				imagU = 0.0 - imagU;
			}
			i = j;
			while (i <= fftSize) {
				ip = (i + lev1) - 1;
				ii = i - 1;
				realT = ((realData[ip]) * realU) - ((imagData[ip]) * imagU);
				imagT = ((realData[ip]) * imagU) + ((imagData[ip]) * realU);
				realData[ip] = ((realData[ii]) - realT);
				imagData[ip] = ((imagData[ii]) - imagT);
				realData[ii] = ((realData[ii]) + realT);
				imagData[ii] = ((imagData[ii]) + imagT);
				i += lev;
			}
		}
	}
}

int transformPoint(int *point) {
	if ((workBuffer[16]) != 0) {
		/* begin transformPoint:into: */
		transformPointXyinto(((double) ((((int *) point))[0]) ), ((double) ((((int *) point))[1]) ), ((int *) point));
	} else {
		point[0] = (((point[0]) + (workBuffer[46])) * (workBuffer[48]));
		point[1] = (((point[1]) + (workBuffer[47])) * (workBuffer[48]));
	}
}

int transformPointXyinto(double xValue, double yValue, int *dstPoint) {
    float *transform;
    int x;
    int y;

	transform = ((float *) (workBuffer + 18));
	x = ((int) (((((transform[0]) * xValue) + ((transform[1]) * yValue)) + (transform[2])) * (((double) (workBuffer[48]) ))) );
	y = ((int) (((((transform[3]) * xValue) + ((transform[4]) * yValue)) + (transform[5])) * (((double) (workBuffer[48]) ))) );
	dstPoint[0] = x;
	dstPoint[1] = y;
}

int transformWidth(int w) {
    double deltaX;
    double deltaY;
    int destWidth2;
    int destWidth;

	if (w == 0) {
		return 0;
	}
	(((int *) (workBuffer + 80)))[0] = 0;
	(((int *) (workBuffer + 80)))[1] = 0;
	(((int *) (workBuffer + 82)))[0] = (w * 256);
	(((int *) (workBuffer + 82)))[1] = 0;
	(((int *) (workBuffer + 84)))[0] = 0;
	(((int *) (workBuffer + 84)))[1] = (w * 256);
	/* begin transformPoints: */
	if (3 > 0) {
		transformPoint(((int *) (workBuffer + 80)));
	}
	if (3 > 1) {
		transformPoint(((int *) (workBuffer + 82)));
	}
	if (3 > 2) {
		transformPoint(((int *) (workBuffer + 84)));
	}
	if (3 > 3) {
		transformPoint(((int *) (workBuffer + 86)));
	}
	deltaX = ((double) (((((int *) (workBuffer + 82)))[0]) - ((((int *) (workBuffer + 80)))[0])) );
	deltaY = ((double) (((((int *) (workBuffer + 82)))[1]) - ((((int *) (workBuffer + 80)))[1])) );
	destWidth = ((int) ((((int) (sqrt((deltaX * deltaX) + (deltaY * deltaY))) )) + 128) >> 8);
	deltaX = ((double) (((((int *) (workBuffer + 84)))[0]) - ((((int *) (workBuffer + 80)))[0])) );
	deltaY = ((double) (((((int *) (workBuffer + 84)))[1]) - ((((int *) (workBuffer + 80)))[1])) );
	destWidth2 = ((int) ((((int) (sqrt((deltaX * deltaX) + (deltaY * deltaY))) )) + 128) >> 8);
	if (destWidth2 < destWidth) {
		destWidth = destWidth2;
	}
	if (destWidth == 0) {
		return 1;
	} else {
		return destWidth;
	}
}

int trueObject(void) {
	return trueObj;
}

int uncheckedTransformColor(int fillIndex) {
    float *transform;
    int g;
    int b;
    int a;
    int r;

	if (!((workBuffer[17]) != 0)) {
		return fillIndex;
	}
	b = fillIndex & 255;
	g = (((unsigned) fillIndex) >> 8) & 255;
	r = (((unsigned) fillIndex) >> 16) & 255;
	a = (((unsigned) fillIndex) >> 24) & 255;
	transform = ((float *) (workBuffer + 24));
	r = ((int) ((r * (transform[0])) + (transform[1])) );
	g = ((int) ((g * (transform[2])) + (transform[3])) );
	b = ((int) ((b * (transform[4])) + (transform[5])) );
	a = ((int) ((a * (transform[6])) + (transform[7])) );
	r = ((r < 0) ? 0 : r);
	r = ((r < 255) ? r : 255);
	g = ((g < 0) ? 0 : g);
	g = ((g < 255) ? g : 255);
	b = ((b < 0) ? 0 : b);
	b = ((b < 255) ? b : 255);
	a = ((a < 0) ? 0 : a);
	a = ((a < 255) ? a : 255);
	if (a < 16) {
		return 0;
	}
	return ((b + (g << 8)) + (r << 16)) + (a << 24);
}

int verifyCleanHeaders(void) {
    int oop;
    int chunk;
    int extra;
    int type;
    int extra1;
    int sz;
    int extra2;
    int header;
    int type1;
    int extra11;

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

int warpSourcePixelsxDeltahyDeltahxDeltavyDeltavsmoothingsourceMap(int nPix, int xDeltah, int yDeltah, int xDeltav, int yDeltav, int n, int sourceMapOop) {
    int destWord;
    int sourcePix;
    int sourcePixMask;
    int destPixMask;
    int srcPixPerWord;
    int destPix;
    int i;
    int mask;
    int srcPix;
    int destPix1;
    int d;
    int mask3;
    int srcPix1;
    int destPix2;
    int d1;
    int mask4;
    int srcPix2;
    int destPix3;
    int d2;
    int mask5;
    int srcPix3;
    int destPix4;
    int d3;

	sourcePixMask = maskTable[sourcePixSize];
	destPixMask = maskTable[destPixSize];
	srcPixPerWord = 32 / sourcePixSize;
	destWord = 0;
	for (i = 1; i <= nPix; i += 1) {
		if (n > 1) {
			destPix = (smoothPixatXfyfdxhdyhdxvdyvpixPerWordpixelMasksourceMap(n, sx, sy, xDeltah / n, yDeltah / n, xDeltav / n, yDeltav / n, srcPixPerWord, sourcePixMask, sourceMapOop)) & destPixMask;
		} else {
			sourcePix = (sourcePixAtXypixPerWord(((unsigned) sx) >> 14, ((unsigned) sy) >> 14, srcPixPerWord)) & sourcePixMask;
			if (colorMap == nilObj) {
				if (destPixSize == sourcePixSize) {
					destPix = sourcePix;
				} else {
					if (sourcePixSize >= 16) {
						if (sourcePixSize == 16) {
							/* begin rgbMap:from:to: */
							if ((d = 8 - 5) > 0) {
								mask = (1 << 5) - 1;
								srcPix = sourcePix << d;
								mask = mask << d;
								destPix1 = srcPix & mask;
								mask = mask << 8;
								srcPix = srcPix << d;
								destPix = (destPix1 + (srcPix & mask)) + ((srcPix << d) & (mask << 8));
								goto l1;
							} else {
								if (d == 0) {
									if (5 == 5) {
										destPix = sourcePix & 32767;
										goto l1;
									}
									if (5 == 8) {
										destPix = sourcePix & 16777215;
										goto l1;
									}
									destPix = sourcePix;
									goto l1;
								}
								if (sourcePix == 0) {
									destPix = sourcePix;
									goto l1;
								}
								d = 5 - 8;
								mask = (1 << 8) - 1;
								srcPix = ((unsigned) sourcePix) >> d;
								destPix1 = srcPix & mask;
								mask = mask << 8;
								srcPix = ((unsigned) srcPix) >> d;
								destPix1 = (destPix1 + (srcPix & mask)) + ((((unsigned) srcPix) >> d) & (mask << 8));
								if (destPix1 == 0) {
									destPix = 1;
									goto l1;
								}
								destPix = destPix1;
								goto l1;
							}
						l1:	/* end rgbMap:from:to: */;
						} else {
							/* begin rgbMap:from:to: */
							if ((d1 = 5 - 8) > 0) {
								mask3 = (1 << 8) - 1;
								srcPix1 = sourcePix << d1;
								mask3 = mask3 << d1;
								destPix2 = srcPix1 & mask3;
								mask3 = mask3 << 5;
								srcPix1 = srcPix1 << d1;
								destPix = (destPix2 + (srcPix1 & mask3)) + ((srcPix1 << d1) & (mask3 << 5));
								goto l2;
							} else {
								if (d1 == 0) {
									if (8 == 5) {
										destPix = sourcePix & 32767;
										goto l2;
									}
									if (8 == 8) {
										destPix = sourcePix & 16777215;
										goto l2;
									}
									destPix = sourcePix;
									goto l2;
								}
								if (sourcePix == 0) {
									destPix = sourcePix;
									goto l2;
								}
								d1 = 8 - 5;
								mask3 = (1 << 5) - 1;
								srcPix1 = ((unsigned) sourcePix) >> d1;
								destPix2 = srcPix1 & mask3;
								mask3 = mask3 << 5;
								srcPix1 = ((unsigned) srcPix1) >> d1;
								destPix2 = (destPix2 + (srcPix1 & mask3)) + ((((unsigned) srcPix1) >> d1) & (mask3 << 5));
								if (destPix2 == 0) {
									destPix = 1;
									goto l2;
								}
								destPix = destPix2;
								goto l2;
							}
						l2:	/* end rgbMap:from:to: */;
						}
					} else {
						destPix = sourcePix & destPixMask;
					}
				}
			} else {
				if (sourcePixSize >= 16) {
					if (sourcePixSize == 16) {
						/* begin rgbMap:from:to: */
						if ((d2 = cmBitsPerColor - 5) > 0) {
							mask4 = (1 << 5) - 1;
							srcPix2 = sourcePix << d2;
							mask4 = mask4 << d2;
							destPix3 = srcPix2 & mask4;
							mask4 = mask4 << cmBitsPerColor;
							srcPix2 = srcPix2 << d2;
							sourcePix = (destPix3 + (srcPix2 & mask4)) + ((srcPix2 << d2) & (mask4 << cmBitsPerColor));
							goto l3;
						} else {
							if (d2 == 0) {
								if (5 == 5) {
									sourcePix = sourcePix & 32767;
									goto l3;
								}
								if (5 == 8) {
									sourcePix = sourcePix & 16777215;
									goto l3;
								}
								sourcePix = sourcePix;
								goto l3;
							}
							if (sourcePix == 0) {
								sourcePix = sourcePix;
								goto l3;
							}
							d2 = 5 - cmBitsPerColor;
							mask4 = (1 << cmBitsPerColor) - 1;
							srcPix2 = ((unsigned) sourcePix) >> d2;
							destPix3 = srcPix2 & mask4;
							mask4 = mask4 << cmBitsPerColor;
							srcPix2 = ((unsigned) srcPix2) >> d2;
							destPix3 = (destPix3 + (srcPix2 & mask4)) + ((((unsigned) srcPix2) >> d2) & (mask4 << cmBitsPerColor));
							if (destPix3 == 0) {
								sourcePix = 1;
								goto l3;
							}
							sourcePix = destPix3;
							goto l3;
						}
					l3:	/* end rgbMap:from:to: */;
					} else {
						/* begin rgbMap:from:to: */
						if ((d3 = cmBitsPerColor - 8) > 0) {
							mask5 = (1 << 8) - 1;
							srcPix3 = sourcePix << d3;
							mask5 = mask5 << d3;
							destPix4 = srcPix3 & mask5;
							mask5 = mask5 << cmBitsPerColor;
							srcPix3 = srcPix3 << d3;
							sourcePix = (destPix4 + (srcPix3 & mask5)) + ((srcPix3 << d3) & (mask5 << cmBitsPerColor));
							goto l4;
						} else {
							if (d3 == 0) {
								if (8 == 5) {
									sourcePix = sourcePix & 32767;
									goto l4;
								}
								if (8 == 8) {
									sourcePix = sourcePix & 16777215;
									goto l4;
								}
								sourcePix = sourcePix;
								goto l4;
							}
							if (sourcePix == 0) {
								sourcePix = sourcePix;
								goto l4;
							}
							d3 = 8 - cmBitsPerColor;
							mask5 = (1 << cmBitsPerColor) - 1;
							srcPix3 = ((unsigned) sourcePix) >> d3;
							destPix4 = srcPix3 & mask5;
							mask5 = mask5 << cmBitsPerColor;
							srcPix3 = ((unsigned) srcPix3) >> d3;
							destPix4 = (destPix4 + (srcPix3 & mask5)) + ((((unsigned) srcPix3) >> d3) & (mask5 << cmBitsPerColor));
							if (destPix4 == 0) {
								sourcePix = 1;
								goto l4;
							}
							sourcePix = destPix4;
							goto l4;
						}
					l4:	/* end rgbMap:from:to: */;
					}
				}
				destPix = (longAt(((((char *) colorMap)) + 4) + (sourcePix << 2))) & destPixMask;
			}
		}
		if (destPixSize == 32) {
			destWord = destPix;
		} else {
			destWord = (destWord << destPixSize) | destPix;
		}
		sx += xDeltah;
		sy += yDeltah;
	}
	return destWord;
}

int wbStackPush(int nItems) {
	if (!(needAvailableSpace(nItems))) {
		return 0;
	}
	workBuffer[10] = ((workBuffer[10]) - nItems);
	return 1;
}

int writeImageFile(int imageBytes) {
    sqImageFile f;
    int i;
    int bytesWritten;
    int headerStart;
    int headerSize;

	headerStart = 0;
	headerSize = 64;
	f = sqImageFileOpen(imageName, "wb");
	if (f == null) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
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
	dir_SetMacFileTypeAndCreator(imageName, strlen(imageName), "STim", "FAST");
}
