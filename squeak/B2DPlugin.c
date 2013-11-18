/* Automatically generated from Squeak on #(4 March 2003 4:22:42 am) */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

/* memory access macros */
#define byteAt(i) (*((unsigned char *) (i)))
#define byteAtput(i, val) (*((unsigned char *) (i)) = val)
#define longAt(i) (*((int *) (i)))
#define longAtput(i, val) (*((int *) (i)) = val)


/*** Variables ***/
static int* aetBuffer;
static char bbPluginName[256] = "BitBltPlugin";
static int copyBitsFn;
static int dispatchReturnValue;
static int dispatchedValue;
static int doProfileStats = 0;
static int engine;
static int engineStopped;
static int formArray;
static int geProfileTime;
static int* getBuffer;

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static int loadBBFn;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"B2DPlugin 4 March 2003 (i)"
#else
	"B2DPlugin 4 March 2003 (e)"
#endif
;
static int* objBuffer;
static int objUsed;
static unsigned int* spanBuffer;
static int* workBuffer;

/*** Function Prototypes ***/
static int aaColorMaskGet(void);
static int aaColorMaskPut(int value);
static int aaColorShiftGet(void);
static int aaColorShiftPut(int value);
static int aaFirstPixelFromto(int leftX, int rightX);
static int aaHalfPixelGet(void);
static int aaHalfPixelPut(int value);
static int aaLastPixelFromto(int leftX, int rightX);
static int aaLevelGet(void);
static int aaLevelPut(int value);
static int aaScanMaskGet(void);
static int aaScanMaskPut(int value);
static int aaShiftGet(void);
static int aaShiftPut(int value);
static int absoluteSquared8Dot24(int value);
static int accurateLengthOfwith(int deltaX, int deltaY);
static int addEdgeToGET(int edge);
static int adjustAALevel(void);
static int adjustWideBezierLeftwidthoffsetendX(int bezier, int lineWidth, int lineOffset, int endX);
static int adjustWideBezierRightwidthoffsetendX(int bezier, int lineWidth, int lineOffset, int endX);
static int adjustWideLineafterSteppingFromto(int line, int lastX, int nextX);
static int aetStartGet(void);
static int aetStartPut(int value);
static int aetUsedGet(void);
static int aetUsedPut(int value);
static int allocateAETEntry(int nSlots);
static int allocateBezier(void);
static int allocateBezierStackEntry(void);
static int allocateBitmapFillcolormap(int cmSize, int *cmBits);
static int allocateGETEntry(int nSlots);
static int allocateGradientFillrampWidthisRadial(int *ramp, int rampWidth, int isRadial);
static int allocateLine(void);
static int allocateObjEntry(int nSlots);
static int allocateStackEntry(int nSlots);
static int allocateStackFillEntry(void);
static int allocateWideBezier(void);
static int allocateWideLine(void);
static int areEdgeFillsValid(int edge);
static int assureValuebetweenand(int val1, int val2, int val3);
static int bezierEndXOf(int bezier);
static int bezierEndXOfput(int bezier, int value);
static int bezierEndYOf(int bezier);
static int bezierEndYOfput(int bezier, int value);
static int bezierFinalXOf(int bezier);
static int bezierFinalXOfput(int bezier, int value);
static int * bezierUpdateDataOf(int bezier);
static int bezierViaXOf(int bezier);
static int bezierViaXOfput(int bezier, int value);
static int bezierViaYOf(int bezier);
static int bezierViaYOfput(int bezier, int value);
static int bitmapCmSizeOf(int bmFill);
static int bitmapCmSizeOfput(int bmFill, int value);
static int bitmapDepthOf(int bmFill);
static int bitmapDepthOfput(int bmFill, int value);
static int bitmapHeightOf(int bmFill);
static int bitmapHeightOfput(int bmFill, int value);
static int bitmapRasterOf(int bmFill);
static int bitmapRasterOfput(int bmFill, int value);
static int bitmapSizeOf(int bmFill);
static int bitmapSizeOfput(int bmFill, int value);
static int bitmapTileFlagOf(int bmFill);
static int bitmapTileFlagOfput(int bmFill, int value);
static int bitmapValuebitsatXy(int bmFill, int bits, int xp, int yp);
static int bitmapWidthOf(int bmFill);
static int bitmapWidthOfput(int bmFill, int value);
static int bzEndX(int index);
static int bzEndXput(int index, int value);
static int bzEndY(int index);
static int bzEndYput(int index, int value);
static int bzStartX(int index);
static int bzStartXput(int index, int value);
static int bzStartY(int index);
static int bzStartYput(int index, int value);
static int bzViaX(int index);
static int bzViaXput(int index, int value);
static int bzViaY(int index);
static int bzViaYput(int index, int value);
static int checkCompressedFillIndexListmaxsegments(int fillList, int maxIndex, int nSegs);
static int checkCompressedFills(int indexList);
static int checkCompressedLineWidthssegments(int lineWidthList, int nSegments);
static int checkCompressedPointssegments(int points, int nSegments);
static int checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(int points, int nSegments, int leftFills, int rightFills, int lineWidths, int lineFills, int fillIndexList);
static int checkedAddBezierToGET(int bezier);
static int checkedAddEdgeToGET(int edge);
static int checkedAddLineToGET(int line);
static double * circleCosTable(void);
static double * circleSinTable(void);
static int clampValuemax(int value, int maxValue);
static int clearSpanBuffer(void);
static int clearSpanBufferGet(void);
static int clearSpanBufferPut(int value);
static int clipMaxXGet(void);
static int clipMaxXPut(int value);
static int clipMaxYGet(void);
static int clipMaxYPut(int value);
static int clipMinXGet(void);
static int clipMinXPut(int value);
static int clipMinYGet(void);
static int clipMinYPut(int value);
static float * colorTransform(void);
static int * colormapOf(int bmFill);
static int computeBeziersplitAt(int index, double param);
static int computeBezierSplitAtHalf(int index);
static int computeFinalWideBezierValueswidth(int bezier, int lineWidth);
static int computeSqrt(int length2);
static int copyBitsFromtoat(int x0, int x1, int yValue);
static int createGlobalEdgeTable(void);
static int currentYGet(void);
static int currentYPut(int value);
static int currentZGet(void);
static int currentZPut(int value);
static int destOffsetXGet(void);
static int destOffsetXPut(int value);
static int destOffsetYGet(void);
static int destOffsetYPut(int value);
static int displaySpanBufferAt(int y);
static int drawWideEdgefrom(int edge, int leftX);
static int edgeFillsInvalidate(int edge);
static int edgeFillsValidate(int edge);
static int edgeLeftFillOf(int edge);
static int edgeLeftFillOfput(int edge, int value);
static int edgeNumLinesOf(int edge);
static int edgeNumLinesOfput(int edge, int value);
static int edgeRightFillOf(int edge);
static int edgeRightFillOfput(int edge, int value);
static float * edgeTransform(void);
static int edgeTypeOf(int edge);
static int edgeXValueOf(int edge);
static int edgeXValueOfput(int edge, int value);
static int edgeYValueOf(int edge);
static int edgeYValueOfput(int edge, int value);
static int edgeZValueOf(int edge);
static int edgeZValueOfput(int edge, int value);
static int errorWrongIndex(void);
static int estimatedLengthOfwith(int deltaX, int deltaY);
static int fillAllFromto(int leftX, int rightX);
static int fillBitmapSpan(void);
static int fillBitmapSpanfromto(int *bits, int leftX, int rightX);
static int fillBitmapSpanfromtoat(int bmFill, int leftX, int rightX, int yValue);
static int fillBitmapSpanAAfromtoat(int bmFill, int leftX, int rightX, int yValue);
static int fillColorSpanfromto(int pixelValue32, int leftX, int rightX);
static int fillColorSpanAAx0x1(int pixelValue32, int leftX, int rightX);
static int fillDirectionXOf(int fill);
static int fillDirectionXOfput(int fill, int value);
static int fillDirectionYOf(int fill);
static int fillDirectionYOfput(int fill, int value);
static int fillLinearGradient(void);
static int fillLinearGradientfromtoat(int fill, int leftX, int rightX, int yValue);
static int fillLinearGradientAArampdsdsXfromto(int fill, int *ramp, int deltaS, int dsX, int leftX, int rightX);
static int fillMaxXGet(void);
static int fillMaxXPut(int value);
static int fillMaxYGet(void);
static int fillMaxYPut(int value);
static int fillMinXGet(void);
static int fillMinXPut(int value);
static int fillMinYGet(void);
static int fillMinYPut(int value);
static int fillNormalXOf(int fill);
static int fillNormalXOfput(int fill, int value);
static int fillNormalYOf(int fill);
static int fillNormalYOfput(int fill, int value);
static int fillOffsetXGet(void);
static int fillOffsetXPut(int value);
static int fillOffsetYGet(void);
static int fillOffsetYPut(int value);
static int fillOriginXOf(int fill);
static int fillOriginXOfput(int fill, int value);
static int fillOriginYOf(int fill);
static int fillOriginYOfput(int fill, int value);
static int fillRadialDecreasingrampdeltaSTdsXdtXfromto(int fill, int ramp, int deltaST, int dsX, int dtX, int leftX, int rightX);
static int fillRadialDecreasingAArampdeltaSTdsXdtXfromto(int fill, int *ramp,  int *deltaST, int dsX, int dtX, int leftX, int rightX);
static int fillRadialGradient(void);
static int fillRadialGradientfromtoat(int fill, int leftX, int rightX, int yValue);
static int fillRadialIncreasingrampdeltaSTdsXdtXfromto(int fill, int ramp, int deltaST, int dsX, int dtX, int leftX, int rightX);
static int fillRadialIncreasingAArampdeltaSTdsXdtXfromto(int fill, int *ramp,  int *deltaST, int dsX, int dtX, int leftX, int rightX);
static int fillSortsbefore(int fillEntry1, int fillEntry2);
static int fillSpanfromto(int fill, int leftX, int rightX);
static int fillSpanfromtomax(int fill, int leftX, int rightX, int maxRightX);
static int fillTypeOf(int fill);
static int findNextAETEdgeFrom(int leftEdge);
static int findNextExternalEntryFromGET(void);
static int findNextExternalFillFromAET(void);
static int findNextExternalUpdateFromAET(void);
static int findStackFilldepth(int fillIndex, int depth);
static int finishedProcessing(void);
static int firstPointListGet(void);
static int firstPointListPut(int value);
static int freeStackFillEntry(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static int getSortsbefore(int edge1, int edge2);
static int getStartGet(void);
static int getStartPut(int value);
static int getUsedGet(void);
static int getUsedPut(int value);
static int gradientRampLengthOf(int fill);
static int gradientRampLengthOfput(int fill, int value);
static int * gradientRampOf(int fill);
static int halt(void);
static int hasColorTransform(void);
static int hasColorTransformGet(void);
static int hasColorTransformPut(int value);
static int hasEdgeTransform(void);
static int hasEdgeTransformGet(void);
static int hasEdgeTransformPut(int value);
static int hideFilldepth(int fillIndex, int depth);
static int incrementPointby(int *point, int delta);
static int incrementStatby(int statIndex, int value);
static int indexForInsertingIntoAET(int edge);
static int initColorTransform(void);
static int initEdgeTransform(void);
#pragma export on
EXPORT(int) initialiseModule(void);
#pragma export off
static int initializeGETProcessing(void);
static int insertEdgeIntoAET(int edge);
static int insertToAETbeforeIndex(int edge, int index);
static int isBezier(int bezier);
static int isEdge(int edge);
static int isFill(int fill);
static int isFillColor(int fill);
static int isFillOkay(int fill);
static int isLine(int line);
static int isObject(int obj);
static int isRealFill(int fill);
static int isStackEntry(int entry);
static int isStackIndex(int index);
static int isWide(int object);
static int isWideBezier(int bezier);
static int isWideLine(int line);
static int lastExportedEdgeGet(void);
static int lastExportedEdgePut(int value);
static int lastExportedFillGet(void);
static int lastExportedFillPut(int value);
static int lastExportedLeftXGet(void);
static int lastExportedLeftXPut(int value);
static int lastExportedRightXGet(void);
static int lastExportedRightXPut(int value);
static int lineEndXOf(int line);
static int lineEndXOfput(int line, int value);
static int lineEndYOf(int line);
static int lineEndYOfput(int line, int value);
static int lineErrorAdjDownOf(int line);
static int lineErrorAdjDownOfput(int line, int value);
static int lineErrorAdjUpOf(int line);
static int lineErrorAdjUpOfput(int line, int value);
static int lineErrorOf(int line);
static int lineErrorOfput(int line, int value);
static int lineXDirectionOf(int line);
static int lineXDirectionOfput(int line, int value);
static int lineXIncrementOf(int line);
static int lineXIncrementOfput(int line, int value);
static int lineYDirectionOf(int line);
static int lineYDirectionOfput(int line, int value);
static int loadAndSubdivideBezierFromviatoisWide(int *point1, int *point2, int *point3, int wideFlag);
static int loadArrayPolygonnPointsfilllineWidthlineFill(int points, int nPoints, int fillIndex, int lineWidth, int lineFill);
static int loadArrayShapenSegmentsfilllineWidthlineFill(int points, int nSegments, int fillIndex, int lineWidth, int lineFill);
static int loadArrayTransformFromintolength(int transformOop, float *destPtr, int n);
static int loadBeziersegmentleftFillrightFilloffset(int bezier, int index, int leftFillIndex, int rightFillIndex, int yOffset);
static int loadBitBltFrom(int bbObj);
static int loadBitmapFillcolormaptilefromalongnormalxIndex(int formOop, int cmOop, int tileFlag, int *point1, int *point2, int *point3, int xIndex);
static int * loadBitsFrom(int bmFill);
static int loadColorTransformFrom(int transformOop);
static int loadCompressedSegmentfromshortleftFillrightFilllineWidthlineColor(int segmentIndex, int points, int pointsShort, int leftFill, int rightFill, int lineWidth, int lineFill);
static int loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(int *points, int nSegments, int *leftFills, int *rightFills, int *lineWidths, int *lineFills, int *fillIndexList, int pointsShort);
static int loadEdgeStateFrom(int edgeOop);
static int loadEdgeTransformFrom(int transformOop);
static int loadFillOrientationfromalongnormalwidthheight(int fill, int *point1, int *point2, int *point3, int fillWidth, int fillHeight);
static int loadFormsFrom(int arrayOop);
static int loadGradientFillfromalongnormalisRadial(int rampOop, int *point1, int *point2, int *point3, int isRadial);
static int loadLinefromtooffsetleftFillrightFill(int line, int *point1, int *point2, int yOffset, int leftFill, int rightFill);
static int loadOvallineFillleftFillrightFill(int lineWidth, int lineFill, int leftFill, int rightFill);
static int loadOvalSegmentwhcxcy(int seg, int w, int h, int cx, int cy);
static int loadPointfrom(int *pointArray, int pointOop);
static int loadPointIntAtfrom(int index, int intArray);
static short loadPointShortAtfrom(int index, int shortArray);
static int loadPolygonnPointsfilllineWidthlineFillpointsShort(int *points, int nPoints, int fillIndex, int lineWidth, int lineFill, int isShort);
static int loadRectanglelineFillleftFillrightFill(int lineWidth, int lineFill, int leftFill, int rightFill);
static int loadRenderingState(void);
static int loadShapenSegmentsfilllineWidthlineFillpointsShort(int *points, int nSegments, int fillIndex, int lineWidth, int lineFill, int pointsShort);
static int loadSpanBufferFrom(int spanOop);
static int loadTransformFromintolength(int transformOop, float *destPtr, int n);
static int loadWideBezierlineFillleftFillrightFilln(int lineWidth, int lineFill, int leftFill, int rightFill, int nSegments);
static int loadWideLinefromtolineFillleftFillrightFill(int lineWidth, int *p1, int *p2, int lineFill, int leftFill, int rightFill);
static int loadWordTransformFromintolength(int transformOop, float *destPtr, int n);
static int loadWorkBufferFrom(int wbOop);
static int magicNumberGet(void);
static int magicNumberPut(int value);
static int makeRectFromPoints(void);
static int makeUnsignedFrom(int someIntegerValue);
#pragma export on
EXPORT(int) moduleUnloaded(char * aModuleName);
#pragma export off
static int moveAETEntryFromedgex(int index, int edge, int xValue);
static int msg(char *s);
static int needAvailableSpace(int nSlots);
static int needsFlush(void);
static int needsFlushGet(void);
static int needsFlushPut(int value);
static int objat(int object, int index);
static int objatput(int object, int index, int value);
static int objStartGet(void);
static int objStartPut(int value);
static int objUsedGet(void);
static int objUsedPut(int value);
static int objectHeaderOf(int obj);
static int objectIndexOf(int obj);
static int objectIndexOfput(int obj, int value);
static int objectLengthOf(int obj);
static int objectLengthOfput(int obj, int value);
static int objectTypeOf(int obj);
static int objectTypeOfput(int obj, int value);
static int offsetFromWidth(int lineWidth);
static int * point1Get(void);
static int * point2Get(void);
static int * point3Get(void);
static int * point4Get(void);
static int postDisplayAction(void);
#pragma export on
EXPORT(int) primitiveAbortProcessing(void);
EXPORT(int) primitiveAddActiveEdgeEntry(void);
EXPORT(int) primitiveAddBezier(void);
EXPORT(int) primitiveAddBezierShape(void);
EXPORT(int) primitiveAddBitmapFill(void);
EXPORT(int) primitiveAddCompressedShape(void);
EXPORT(int) primitiveAddGradientFill(void);
EXPORT(int) primitiveAddLine(void);
EXPORT(int) primitiveAddOval(void);
EXPORT(int) primitiveAddPolygon(void);
EXPORT(int) primitiveAddRect(void);
EXPORT(int) primitiveChangedActiveEdgeEntry(void);
EXPORT(int) primitiveCopyBuffer(void);
EXPORT(int) primitiveDisplaySpanBuffer(void);
EXPORT(int) primitiveDoProfileStats(void);
EXPORT(int) primitiveFinishedProcessing(void);
EXPORT(int) primitiveGetAALevel(void);
EXPORT(int) primitiveGetBezierStats(void);
EXPORT(int) primitiveGetClipRect(void);
EXPORT(int) primitiveGetCounts(void);
EXPORT(int) primitiveGetDepth(void);
EXPORT(int) primitiveGetFailureReason(void);
EXPORT(int) primitiveGetOffset(void);
EXPORT(int) primitiveGetTimes(void);
EXPORT(int) primitiveInitializeBuffer(void);
EXPORT(int) primitiveInitializeProcessing(void);
EXPORT(int) primitiveMergeFillFrom(void);
EXPORT(int) primitiveNeedsFlush(void);
EXPORT(int) primitiveNeedsFlushPut(void);
EXPORT(int) primitiveNextActiveEdgeEntry(void);
EXPORT(int) primitiveNextFillEntry(void);
EXPORT(int) primitiveNextGlobalEdgeEntry(void);
EXPORT(int) primitiveRegisterExternalEdge(void);
EXPORT(int) primitiveRegisterExternalFill(void);
EXPORT(int) primitiveRenderImage(void);
EXPORT(int) primitiveRenderScanline(void);
EXPORT(int) primitiveSetAALevel(void);
EXPORT(int) primitiveSetBitBltPlugin(void);
EXPORT(int) primitiveSetClipRect(void);
EXPORT(int) primitiveSetColorTransform(void);
EXPORT(int) primitiveSetDepth(void);
EXPORT(int) primitiveSetEdgeTransform(void);
EXPORT(int) primitiveSetOffset(void);
#pragma export off
static int proceedRenderingImage(void);
static int proceedRenderingScanline(void);
static int quickLoadEngineFrom(int engineOop);
static int quickLoadEngineFromrequiredState(int oop, int requiredState);
static int quickLoadEngineFromrequiredStateor(int oop, int requiredState, int alternativeState);
static int quickRemoveInvalidFillsAt(int leftX);
static int quickSortGlobalEdgeTablefromto(int *array, int i, int j);
static int * rShiftTable(void);
static int removeFirstAETEntry(void);
static int repeatValuemax(int delta, int maxValue);
static int resetGraphicsEngineStats(void);
static int resortFirstAETEntry(void);
static int returnWideBezierFill(void);
static int returnWideBezierWidth(void);
static int returnWideLineFill(void);
static int returnWideLineWidth(void);
static int setAALevel(int level);
#pragma export on
EXPORT(int) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off
static int shortRunLengthAtfrom(int i, int runArray);
static int shortRunValueAtfrom(int i, int runArray);
static int showFilldepthrightX(int fillIndex, int depth, int rightX);
static int * smallSqrtTable(void);
static int sortGlobalEdgeTable(void);
static int spanEndAAGet(void);
static int spanEndAAPut(int value);
static int spanEndGet(void);
static int spanEndPut(int value);
static int spanSizeGet(void);
static int spanSizePut(int value);
static int spanStartGet(void);
static int spanStartPut(int value);
static int squaredLengthOfwith(int deltaX, int deltaY);
static int stackFillDepth(int index);
static int stackFillDepthput(int index, int value);
static int stackFillEntryLength(void);
static int stackFillRightX(int index);
static int stackFillRightXput(int index, int value);
static int stackFillSize(void);
static int stackFillValue(int index);
static int stackFillValueput(int index, int value);
static int stateGet(void);
static int statePut(int value);
static int stepToFirstBezier(void);
static int stepToFirstBezierInat(int bezier, int yValue);
static int stepToFirstLine(void);
static int stepToFirstLineInat(int line, int yValue);
static int stepToFirstWideBezier(void);
static int stepToFirstWideBezierInat(int bezier, int yValue);
static int stepToFirstWideLine(void);
static int stepToFirstWideLineInat(int line, int yValue);
static int stepToNextBezier(void);
static int stepToNextBezierForwardat(int updateData, int yValue);
static int stepToNextBezierInat(int bezier, int yValue);
static int stepToNextLine(void);
static int stepToNextLineInat(int line, int yValue);
static int stepToNextWideBezier(void);
static int stepToNextWideBezierInat(int bezier, int yValue);
static int stepToNextWideLine(void);
static int stepToNextWideLineInat(int line, int yValue);
static int stopBecauseOf(int stopReason);
static int stopReasonGet(void);
static int stopReasonPut(int value);
static int storeEdgeStateFrominto(int edge, int edgeOop);
static int storeEngineStateInto(int oop);
static int storeFillStateInto(int fillOop);
static int storeRenderingState(void);
static int storeStopStateIntoEdgefill(int edgeOop, int fillOop);
static int subdivideBezier(int index);
static int subdivideBezierFrom(int index);
static int subdivideToBeMonotoninX(int base, int doTestX);
static int subdivideToBeMonotonInX(int index);
static int subdivideToBeMonotonInY(int index);
static int toggleFilldepthrightX(int fillIndex, int depth, int rightX);
static int toggleFillsOf(int edge);
static int toggleWideFillOf(int edge);
static int topDepth(void);
static int topFill(void);
static int topFillDepth(void);
static int topFillDepthPut(int value);
static int topFillRightX(void);
static int topFillRightXPut(int value);
static int topFillValue(void);
static int topFillValuePut(int value);
static int topRightX(void);
static int transformColor(int fillIndex);
static int transformPoint(int *point);
static int transformPointinto(int srcPoint, int dstPoint);
static int transformPointXyinto(double xValue, double yValue, int *dstPoint);
static int transformPoints(int n);
static int transformWidth(int w);
static int uncheckedTransformColor(int fillIndex);
static int wbSizeGet(void);
static int wbSizePut(int value);
static int wbStackClear(void);
static int wbStackPop(int nItems);
static int wbStackPush(int nItems);
static int wbStackSize(void);
static int wbStackValue(int index);
static int wbStackValueput(int index, int value);
static int wbTopGet(void);
static int wbTopPut(int value);
static int wideBezierEntryOf(int line);
static int wideBezierEntryOfput(int line, int value);
static int wideBezierExitOf(int line);
static int wideBezierExitOfput(int line, int value);
static int wideBezierExtentOf(int bezier);
static int wideBezierExtentOfput(int bezier, int value);
static int wideBezierFillOf(int bezier);
static int wideBezierFillOfput(int bezier, int value);
static int * wideBezierUpdateDataOf(int bezier);
static int wideBezierWidthOf(int line);
static int wideBezierWidthOfput(int line, int value);
static int wideLineEntryOf(int line);
static int wideLineEntryOfput(int line, int value);
static int wideLineExitOf(int line);
static int wideLineExitOfput(int line, int value);
static int wideLineExtentOf(int line);
static int wideLineExtentOfput(int line, int value);
static int wideLineFillOf(int line);
static int wideLineFillOfput(int line, int value);
static int wideLineWidthOf(int line);
static int wideLineWidthOfput(int line, int value);

static int aaColorMaskGet(void) {
	return workBuffer[51];
}

static int aaColorMaskPut(int value) {
	return workBuffer[51] = value;
}

static int aaColorShiftGet(void) {
	return workBuffer[50];
}

static int aaColorShiftPut(int value) {
	return workBuffer[50] = value;
}


/*	Common function to compute the first full pixel for AA drawing */

static int aaFirstPixelFromto(int leftX, int rightX) {
    int firstPixel;

	firstPixel = ((leftX + (workBuffer[48])) - 1) & (~((workBuffer[48]) - 1));
	if (firstPixel > rightX) {
		return rightX;
	} else {
		return firstPixel;
	}
}

static int aaHalfPixelGet(void) {
	return workBuffer[53];
}

static int aaHalfPixelPut(int value) {
	return workBuffer[53] = value;
}


/*	Common function to compute the last full pixel for AA drawing */

static int aaLastPixelFromto(int leftX, int rightX) {
	return (rightX - 1) & (~((workBuffer[48]) - 1));
}

static int aaLevelGet(void) {
	return workBuffer[48];
}

static int aaLevelPut(int value) {
	return workBuffer[48] = value;
}

static int aaScanMaskGet(void) {
	return workBuffer[52];
}

static int aaScanMaskPut(int value) {
	return workBuffer[52] = value;
}

static int aaShiftGet(void) {
	return workBuffer[49];
}

static int aaShiftPut(int value) {
	return workBuffer[49] = value;
}


/*	Compute the squared value of a 8.24 number with 0.0 <= value < 1.0,
	e.g., compute (value * value) bitShift: -24 */

static int absoluteSquared8Dot24(int value) {
    int word1;
    int word2;

	word1 = value & 65535;
	word2 = (((unsigned) value >> 16)) & 255;
	return ((unsigned) (((((unsigned) (((unsigned) (word1 * word1))) >> 16)) + ((word1 * word2) * 2)) + (((unsigned) (word2 * word2) << 16))) >> 8);
}


/*	Return the accurate length of the vector described by deltaX and deltaY */

static int accurateLengthOfwith(int deltaX, int deltaY) {
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

static int addEdgeToGET(int edge) {
	if (!(allocateGETEntry(1))) {
		return 0;
	}
	getBuffer[workBuffer[12]] = edge;
	workBuffer[12] = ((workBuffer[12]) + 1);
}


/*	NOTE: 	This method is (hopefully) obsolete due to unrolling 
				the fill loops to deal with full pixels. */
/*	Adjust the span buffers values by the appropriate color offset for anti-aliasing.
	We do this by replicating the top bits of each color in the lower bits. The idea is that we can scale each color value uniquely from 0 to 255 and thus fill the entire range of colors. */

static int adjustAALevel(void) {
    int adjustShift;
    int x0;
    int x1;
    int pixelValue;
    int adjustMask;

	adjustShift = 8 - (workBuffer[50]);
	adjustMask = ~(workBuffer[51]);
	x0 = ((unsigned) (workBuffer[32])) >> (workBuffer[49]);
	x1 = ((unsigned) (workBuffer[34])) >> (workBuffer[49]);
	while (x0 < x1) {
		pixelValue = spanBuffer[x0];
		spanBuffer[x0] = (pixelValue | ((((unsigned) pixelValue) >> adjustShift) & adjustMask));
		x0 += 1;
	}
}


/*	Adjust the wide bezier curve (dx < 0) to start/end at the right point */

static int adjustWideBezierLeftwidthoffsetendX(int bezier, int lineWidth, int lineOffset, int endX) {
    int lastX;
    int lastY;

	((objBuffer + bezier) + 10)[0] = ((((objBuffer + bezier) + 10)[0]) - (lineOffset * 256));
	lastX = ((objBuffer + bezier) + 22)[0];
	((objBuffer + bezier) + 22)[0] = (lastX + ((lineWidth - lineOffset) * 256));
	lastY = ((objBuffer + bezier) + 22)[1];
	((objBuffer + bezier) + 22)[1] = (lastY + (lineWidth * 256));
	objBuffer[bezier + 21] = (endX - lineOffset);
}


/*	Adjust the wide bezier curve (dx >= 0) to start/end at the right point */

static int adjustWideBezierRightwidthoffsetendX(int bezier, int lineWidth, int lineOffset, int endX) {
    int lastX;
    int lastY;

	((objBuffer + bezier) + 10)[0] = ((((objBuffer + bezier) + 10)[0]) + (lineOffset * 256));
	lastX = ((objBuffer + bezier) + 22)[0];
	((objBuffer + bezier) + 22)[0] = (lastX - ((lineWidth - lineOffset) * 256));

	/* Set lineWidth pixels down */

	lastY = ((objBuffer + bezier) + 22)[1];
	((objBuffer + bezier) + 22)[1] = (lastY + (lineWidth * 256));
	objBuffer[bezier + 21] = ((endX - lineOffset) + lineWidth);
}


/*	Adjust the wide line after it has been stepped from lastX to nextX.
	Special adjustments of line width and start position are made here
	to simulate a rectangular brush */

static int adjustWideLineafterSteppingFromto(int line, int lastX, int nextX) {
    int lineOffset;
    int lineWidth;
    int xDir;
    int baseWidth;
    int yExit;
    int deltaX;
    int yEntry;

	yEntry = objBuffer[line + 18];
	yExit = objBuffer[line + 19];
	baseWidth = objBuffer[line + 20];
	lineOffset = ((int) baseWidth >> 1);
	lineWidth = objBuffer[line + 17];
	xDir = objBuffer[line + 10];

	/* Adjust the start of the line to fill an entire rectangle */

	deltaX = nextX - lastX;
	if (yEntry < baseWidth) {
		if (xDir < 0) {

			/* effectively adding */

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

			/* effectively subtracting */

			lineWidth += objBuffer[line + 12];
			objBuffer[line + 4] = lastX;
		}
	}
	if ((yExit + lineOffset) > 0) {
		if (xDir < 0) {

			/* effectively subtracting */

			lineWidth += deltaX;
			objBuffer[line + 4] = lastX;
		} else {
			lineWidth -= deltaX;
		}
	}
	objBuffer[line + 17] = lineWidth;
}

static int aetStartGet(void) {
	return workBuffer[13];
}

static int aetStartPut(int value) {
	return workBuffer[13] = value;
}

static int aetUsedGet(void) {
	return workBuffer[14];
}

static int aetUsedPut(int value) {
	return workBuffer[14] = value;
}


/*	Allocate n slots in the active edge table */

static int allocateAETEntry(int nSlots) {
	/* begin needAvailableSpace: */
	if (((((128 + objUsed) + (workBuffer[12])) + (workBuffer[14])) + nSlots) > (workBuffer[10])) {
		/* begin stopBecauseOf: */
		workBuffer[64] = 1;
		engineStopped = 1;
		return 0;
	}
	return 1;
}

static int allocateBezier(void) {
    int bezier;

	if (!(allocateObjEntry(16))) {
		return 0;
	}
	bezier = objUsed;
	objUsed = bezier + 16;
	objBuffer[bezier + 0] = 6;
	objBuffer[bezier + 2] = 0;
	objBuffer[bezier + 1] = 16;
	return bezier;
}

static int allocateBezierStackEntry(void) {
	/* begin wbStackPush: */
	if (!(needAvailableSpace(6))) {
		goto l1;
	}
	workBuffer[10] = ((workBuffer[10]) - 6);
l1:	/* end wbStackPush: */;
	return (workBuffer[1]) - (workBuffer[10]);
}

static int allocateBitmapFillcolormap(int cmSize, int *cmBits) {
    int fillSize;
    int fill;
    int *cm;
    int i;

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


/*	Allocate n slots in the global edge table */

static int allocateGETEntry(int nSlots) {
    int dstIndex;
    int i;
    int srcIndex;

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

static int allocateGradientFillrampWidthisRadial(int *ramp, int rampWidth, int isRadial) {
    int fillSize;
    int fill;
    int *rampPtr;
    int i;

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

static int allocateLine(void) {
    int line;

	if (!(allocateObjEntry(16))) {
		return 0;
	}
	line = objUsed;
	objUsed = line + 16;
	objBuffer[line + 0] = 4;
	objBuffer[line + 2] = 0;
	objBuffer[line + 1] = 16;
	return line;
}


/*	Allocate n slots in the object buffer */

static int allocateObjEntry(int nSlots) {
    int dstIndex;
    int i;
    int srcIndex;

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


/*	AET and Stack allocation are symmetric */

static int allocateStackEntry(int nSlots) {
	/* begin needAvailableSpace: */
	if (((((128 + objUsed) + (workBuffer[12])) + (workBuffer[14])) + nSlots) > (workBuffer[10])) {
		/* begin stopBecauseOf: */
		workBuffer[64] = 1;
		engineStopped = 1;
		return 0;
	}
	return 1;
}

static int allocateStackFillEntry(void) {
	/* begin wbStackPush: */
	if (!(needAvailableSpace(3))) {
		return 0;
	}
	workBuffer[10] = ((workBuffer[10]) - 3);
	return 1;
}

static int allocateWideBezier(void) {
    int bezier;

	if (!(allocateObjEntry(28))) {
		return 0;
	}
	bezier = objUsed;
	objUsed = bezier + 28;
	objBuffer[bezier + 0] = 7;
	objBuffer[bezier + 2] = 0;
	objBuffer[bezier + 1] = 28;
	return bezier;
}

static int allocateWideLine(void) {
    int line;

	if (!(allocateObjEntry(21))) {
		return 0;
	}
	line = objUsed;
	objUsed = line + 21;
	objBuffer[line + 0] = 5;
	objBuffer[line + 2] = 0;
	objBuffer[line + 1] = 21;
	return line;
}

static int areEdgeFillsValid(int edge) {
	return ((objBuffer[edge + 0]) & 65536) == 0;
}


/*	Make sure that val1 is between val2 and val3. */

static int assureValuebetweenand(int val1, int val2, int val3) {
	if (val2 > val3) {
		if (val1 > val2) {
			return val2;
		}
		if (val1 < val3) {
			return val3;
		}
	} else {
		if (val1 < val2) {
			return val2;
		}
		if (val1 > val3) {
			return val3;
		}
	}
	return val1;
}

static int bezierEndXOf(int bezier) {
	return objBuffer[bezier + 14];
}

static int bezierEndXOfput(int bezier, int value) {
	return objBuffer[bezier + 14] = value;
}

static int bezierEndYOf(int bezier) {
	return objBuffer[bezier + 15];
}

static int bezierEndYOfput(int bezier, int value) {
	return objBuffer[bezier + 15] = value;
}

static int bezierFinalXOf(int bezier) {
	return objBuffer[bezier + 21];
}

static int bezierFinalXOfput(int bezier, int value) {
	return objBuffer[bezier + 21] = value;
}

static int * bezierUpdateDataOf(int bezier) {
	return (objBuffer + bezier) + 10;
}

static int bezierViaXOf(int bezier) {
	return objBuffer[bezier + 12];
}

static int bezierViaXOfput(int bezier, int value) {
	return objBuffer[bezier + 12] = value;
}

static int bezierViaYOf(int bezier) {
	return objBuffer[bezier + 13];
}

static int bezierViaYOfput(int bezier, int value) {
	return objBuffer[bezier + 13] = value;
}

static int bitmapCmSizeOf(int bmFill) {
	return objBuffer[bmFill + 15];
}

static int bitmapCmSizeOfput(int bmFill, int value) {
	return objBuffer[bmFill + 15] = value;
}

static int bitmapDepthOf(int bmFill) {
	return objBuffer[bmFill + 12];
}

static int bitmapDepthOfput(int bmFill, int value) {
	return objBuffer[bmFill + 12] = value;
}

static int bitmapHeightOf(int bmFill) {
	return objBuffer[bmFill + 11];
}

static int bitmapHeightOfput(int bmFill, int value) {
	return objBuffer[bmFill + 11] = value;
}

static int bitmapRasterOf(int bmFill) {
	return objBuffer[bmFill + 14];
}

static int bitmapRasterOfput(int bmFill, int value) {
	return objBuffer[bmFill + 14] = value;
}

static int bitmapSizeOf(int bmFill) {
	return objBuffer[bmFill + 13];
}

static int bitmapSizeOfput(int bmFill, int value) {
	return objBuffer[bmFill + 13] = value;
}

static int bitmapTileFlagOf(int bmFill) {
	return objBuffer[bmFill + 16];
}

static int bitmapTileFlagOfput(int bmFill, int value) {
	return objBuffer[bmFill + 16] = value;
}

static int bitmapValuebitsatXy(int bmFill, int bits, int xp, int yp) {
    int g;
    int cMask;
    int bmDepth;
    int rShift;
    int r;
    int bmRaster;
    int value;
    int b;
    int a;

	bmDepth = objBuffer[bmFill + 12];
	bmRaster = objBuffer[bmFill + 14];
	if (bmDepth == 32) {
		value = (((int*) bits))[(bmRaster * yp) + xp];
		if ((value != 0) && ((value & 4278190080U) == 0)) {
			value = value | 4278190080U;
		}
		return uncheckedTransformColor(value);
	}
	rShift = (rShiftTable())[bmDepth];

	/* cMask - mask out the pixel from the word */

	value = (((int*) bits))[(bmRaster * yp) + (((unsigned) xp) >> rShift)];

	/* rShift - shift value to move the pixel in the word to the lowest bit position */

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
	return uncheckedTransformColor(value);
}

static int bitmapWidthOf(int bmFill) {
	return objBuffer[bmFill + 10];
}

static int bitmapWidthOfput(int bmFill, int value) {
	return objBuffer[bmFill + 10] = value;
}

static int bzEndX(int index) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)];
}

static int bzEndXput(int index, int value) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)] = value;
}

static int bzEndY(int index) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)];
}

static int bzEndYput(int index, int value) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)] = value;
}

static int bzStartX(int index) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)];
}

static int bzStartXput(int index, int value) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)] = value;
}

static int bzStartY(int index) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)];
}

static int bzStartYput(int index, int value) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)] = value;
}

static int bzViaX(int index) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)];
}

static int bzViaXput(int index, int value) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)] = value;
}

static int bzViaY(int index) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)];
}

static int bzViaYput(int index, int value) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)] = value;
}


/*	Check the fill indexes in the run-length encoded fillList */

static int checkCompressedFillIndexListmaxsegments(int fillList, int maxIndex, int nSegs) {
    int length;
    int *fillPtr;
    int i;
    int runValue;
    int nFills;
    int runLength;

	length = interpreterProxy->slotSizeOf(fillList);
	fillPtr = interpreterProxy->firstIndexableField(fillList);
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


/*	Check if the indexList (containing fill handles) is okay. */

static int checkCompressedFills(int indexList) {
    int length;
    int *fillPtr;
    int i;
    int fillIndex;

	if (!(interpreterProxy->isWords(indexList))) {
		return 0;
	}
	length = interpreterProxy->slotSizeOf(indexList);
	fillPtr = interpreterProxy->firstIndexableField(indexList);
	for (i = 1; i <= length; i += 1) {

		/* Make sure the fill is okay */

		fillIndex = fillPtr[0];
		if (!(isFillOkay(fillIndex))) {
			return 0;
		}
		fillPtr += 1;
	}
	return 1;
}


/*	Check the run-length encoded lineWidthList matches nSegments */

static int checkCompressedLineWidthssegments(int lineWidthList, int nSegments) {
    int runLength;
    int length;
    int *ptr;
    int nItems;
    int i;

	length = interpreterProxy->slotSizeOf(lineWidthList);
	ptr = interpreterProxy->firstIndexableField(lineWidthList);
	nItems = 0;
	for (i = 0; i <= (length - 1); i += 1) {
		runLength = ((unsigned) ((((int *) ptr))[i]) >> 16);
		nItems += runLength;
	}
	return nItems == nSegments;
}


/*	Check if the given point array can be handled by the engine. */

static int checkCompressedPointssegments(int points, int nSegments) {
    int pSize;

	if (!(interpreterProxy->isWords(points))) {
		return 0;
	}

	/* The points must be either in PointArray format or ShortPointArray format.
	Also, we currently handle only quadratic segments (e.g., 3 points each) and thus either
		pSize = nSegments * 3,		for ShortPointArrays or,
		pSize = nSegments * 6,		for PointArrays */

	pSize = interpreterProxy->slotSizeOf(points);
	if (!((pSize == (nSegments * 3)) || (pSize == (nSegments * 6)))) {
		return 0;
	}
	return 1;
}


/*	Check if the given shape can be handled by the engine. 
	Since there are a number of requirements this is an extra method. */

static int checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(int points, int nSegments, int leftFills, int rightFills, int lineWidths, int lineFills, int fillIndexList) {
    int maxFillIndex;

	if (!(checkCompressedPointssegments(points, nSegments))) {
		return 0;
	}
	if (!(checkCompressedFills(fillIndexList))) {
		return 0;
	}
	maxFillIndex = interpreterProxy->slotSizeOf(fillIndexList);
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


/*	Add the bezier to the global edge table if it intersects the clipping region */

static int checkedAddBezierToGET(int bezier) {
    int lineWidth;

	if ((((objBuffer[bezier + 0]) & 65535) & 1) != 0) {
		lineWidth = objBuffer[bezier + 20];
	} else {
		lineWidth = 0;
	}
	if (((objBuffer[bezier + 15]) + lineWidth) < (workBuffer[38])) {
		return 0;
	}
	if ((((objBuffer[bezier + 4]) - lineWidth) >= (workBuffer[37])) && (((objBuffer[bezier + 14]) - lineWidth) >= (workBuffer[37]))) {
		return 0;
	}
	addEdgeToGET(bezier);
}


/*	Add the edge to the global edge table.
	For known edge types, check if the edge intersects the visible region */

static int checkedAddEdgeToGET(int edge) {
    int lineWidth;
    int lineWidth1;

	if ((((objBuffer[edge + 0]) & 65535) & 254) == 4) {
		/* begin checkedAddLineToGET: */
		if ((((objBuffer[edge + 0]) & 65535) & 1) != 0) {
			lineWidth = objBuffer[edge + 20];
		} else {
			lineWidth = 0;
		}
		if (((objBuffer[edge + 15]) + lineWidth) < (workBuffer[38])) {
			return 0;
		}
		if ((((objBuffer[edge + 4]) - lineWidth) >= (workBuffer[37])) && (((objBuffer[edge + 14]) - lineWidth) >= (workBuffer[37]))) {
			return 0;
		}
		addEdgeToGET(edge);
		return null;
	}
	if ((((objBuffer[edge + 0]) & 65535) & 254) == 6) {
		/* begin checkedAddBezierToGET: */
		if ((((objBuffer[edge + 0]) & 65535) & 1) != 0) {
			lineWidth1 = objBuffer[edge + 20];
		} else {
			lineWidth1 = 0;
		}
		if (((objBuffer[edge + 15]) + lineWidth1) < (workBuffer[38])) {
			return 0;
		}
		if ((((objBuffer[edge + 4]) - lineWidth1) >= (workBuffer[37])) && (((objBuffer[edge + 14]) - lineWidth1) >= (workBuffer[37]))) {
			return 0;
		}
		addEdgeToGET(edge);
		return null;
	}
	addEdgeToGET(edge);
}


/*	Add the line to the global edge table if it intersects the clipping region */

static int checkedAddLineToGET(int line) {
    int lineWidth;

	if ((((objBuffer[line + 0]) & 65535) & 1) != 0) {
		lineWidth = objBuffer[line + 20];
	} else {
		lineWidth = 0;
	}
	if (((objBuffer[line + 15]) + lineWidth) < (workBuffer[38])) {
		return 0;
	}
	if ((((objBuffer[line + 4]) - lineWidth) >= (workBuffer[37])) && (((objBuffer[line + 14]) - lineWidth) >= (workBuffer[37]))) {
		return 0;
	}
	addEdgeToGET(line);
}

static double * circleCosTable(void) {
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

static double * circleSinTable(void) {
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

static int clampValuemax(int value, int maxValue) {
	if (value < 0) {
		return 0;
	} else {
		if (value >= maxValue) {
			return maxValue - 1;
		} else {
			return value;
		}
	}
}


/*	Clear the current span buffer.
	The span buffer is only cleared in the area that has been used by the previous scan line. */

static int clearSpanBuffer(void) {
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

static int clearSpanBufferGet(void) {
	return workBuffer[69];
}

static int clearSpanBufferPut(int value) {
	return workBuffer[69] = value;
}

static int clipMaxXGet(void) {
	return workBuffer[43];
}

static int clipMaxXPut(int value) {
	return workBuffer[43] = value;
}

static int clipMaxYGet(void) {
	return workBuffer[45];
}

static int clipMaxYPut(int value) {
	return workBuffer[45] = value;
}

static int clipMinXGet(void) {
	return workBuffer[42];
}

static int clipMinXPut(int value) {
	return workBuffer[42] = value;
}

static int clipMinYGet(void) {
	return workBuffer[44];
}

static int clipMinYPut(int value) {
	return workBuffer[44] = value;
}

static float * colorTransform(void) {
	return ((float *) (workBuffer + 24));
}

static int * colormapOf(int bmFill) {
	return (objBuffer + bmFill) + 18;
}


/*	Split the bezier curve at the given parametric value.
	Note: Since this method is only invoked to make non-monoton
		beziers monoton we must check for the resulting y values
		to be *really* between the start and end value. */

static int computeBeziersplitAt(int index, double param) {
    int rightViaX;
    int rightViaY;
    int endX;
    int sharedX;
    int endY;
    int sharedY;
    int newIndex;
    int startX;
    int startY;
    int viaX;
    int leftViaX;
    int viaY;
    int leftViaY;

	leftViaX = startX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 0)];
	leftViaY = startY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)];
	rightViaX = viaX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 2)];
	rightViaY = viaY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 3)];
	endX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 4)];

	/* Compute intermediate points */

	endY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)];
	sharedX = leftViaX += ((int) ((((double) (viaX - startX) )) * param) );
	sharedY = leftViaY += ((int) ((((double) (viaY - startY) )) * param) );
	rightViaX += ((int) ((((double) (endX - viaX) )) * param) );

	/* Compute new shared point */

	rightViaY += ((int) ((((double) (endY - viaY) )) * param) );
	sharedX += ((int) ((((double) (rightViaX - leftViaX) )) * param) );

	/* Check the new via points */

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


/*	Split the bezier curve at 0.5. */

static int computeBezierSplitAtHalf(int index) {
    int rightViaX;
    int rightViaY;
    int endX;
    int sharedX;
    int endY;
    int sharedY;
    int newIndex;
    int startX;
    int startY;
    int viaX;
    int leftViaX;
    int leftViaY;
    int viaY;

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

	/* Compute intermediate points */

	endY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 5)];
	leftViaX += ((int) (viaX - startX) >> 1);
	leftViaY += ((int) (viaY - startY) >> 1);
	sharedX = rightViaX += ((int) (endX - viaX) >> 1);

	/* Compute new shared point */

	sharedY = rightViaY += ((int) (endY - viaY) >> 1);
	sharedX += ((int) (leftViaX - rightViaX) >> 1);

	/* Store the first part back */

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


/*	Get both values from the two boundaries of the given bezier 
	and compute the actual position/width of the line */

static int computeFinalWideBezierValueswidth(int bezier, int lineWidth) {
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

static int computeSqrt(int length2) {
	if (length2 < 32) {
		return (smallSqrtTable())[length2];
	} else {
		return ((int) ((sqrt(((double) length2 ))) + 0.5) );
	}
}

static int copyBitsFromtoat(int x0, int x1, int yValue) {
	if (copyBitsFn == 0) {
		if (!(initialiseModule())) {
			return 0;
		}
	}
	return  ((int (*) (int, int, int)) copyBitsFn)(x0, x1, yValue);
}


/*	Create the global edge table */

static int createGlobalEdgeTable(void) {
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
						goto l2;
					}
					if ((((objBuffer[object + 4]) - lineWidth) >= (workBuffer[37])) && (((objBuffer[object + 14]) - lineWidth) >= (workBuffer[37]))) {
						goto l2;
					}
					addEdgeToGET(object);
				l2:	/* end checkedAddLineToGET: */;
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
						goto l3;
					}
					if ((((objBuffer[object + 4]) - lineWidth1) >= (workBuffer[37])) && (((objBuffer[object + 14]) - lineWidth1) >= (workBuffer[37]))) {
						goto l3;
					}
					addEdgeToGET(object);
				l3:	/* end checkedAddBezierToGET: */;
					goto l1;
				}
				addEdgeToGET(object);
			l1:	/* end checkedAddEdgeToGET: */;
			}
		}
		object += objBuffer[object + 1];
	}
}

static int currentYGet(void) {
	return workBuffer[88];
}

static int currentYPut(int value) {
	return workBuffer[88] = value;
}

static int currentZGet(void) {
	return workBuffer[113];
}

static int currentZPut(int value) {
	return workBuffer[113] = value;
}

static int destOffsetXGet(void) {
	return workBuffer[46];
}

static int destOffsetXPut(int value) {
	return workBuffer[46] = value;
}

static int destOffsetYGet(void) {
	return workBuffer[47];
}

static int destOffsetYPut(int value) {
	return workBuffer[47] = value;
}


/*	Display the span buffer at the current scan line. */

static int displaySpanBufferAt(int y) {
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
	copyBitsFromtoat(targetX0, targetX1, targetY);
}


/*	Draw the given edge starting from leftX with the edge's fill.
	Return the end value of the drawing operation. */

static int drawWideEdgefrom(int edge, int leftX) {
    int fill;
    int lineWidth;
    int rightX;
    int type;

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
		return leftX;
	}
	rightX = leftX + lineWidth;
	fillSpanfromto(fill, leftX, rightX);
	return rightX;
}

static int edgeFillsInvalidate(int edge) {
	return objBuffer[edge + 0] = (((objBuffer[edge + 0]) & 65535) | 65536);
}

static int edgeFillsValidate(int edge) {
	return objBuffer[edge + 0] = (((objBuffer[edge + 0]) & 65535) & (~65536));
}

static int edgeLeftFillOf(int edge) {
	return objBuffer[edge + 8];
}

static int edgeLeftFillOfput(int edge, int value) {
	return objBuffer[edge + 8] = value;
}

static int edgeNumLinesOf(int edge) {
	return objBuffer[edge + 7];
}

static int edgeNumLinesOfput(int edge, int value) {
	return objBuffer[edge + 7] = value;
}

static int edgeRightFillOf(int edge) {
	return objBuffer[edge + 9];
}

static int edgeRightFillOfput(int edge, int value) {
	return objBuffer[edge + 9] = value;
}

static float * edgeTransform(void) {
	return ((float *) (workBuffer + 18));
}


/*	Return the edge type (e.g., witout the wide edge flag) */

static int edgeTypeOf(int edge) {
	return ((unsigned) ((objBuffer[edge + 0]) & 65535)) >> 1;
}

static int edgeXValueOf(int edge) {
	return objBuffer[edge + 4];
}

static int edgeXValueOfput(int edge, int value) {
	return objBuffer[edge + 4] = value;
}

static int edgeYValueOf(int edge) {
	return objBuffer[edge + 5];
}

static int edgeYValueOfput(int edge, int value) {
	return objBuffer[edge + 5] = value;
}

static int edgeZValueOf(int edge) {
	return objBuffer[edge + 6];
}

static int edgeZValueOfput(int edge, int value) {
	return objBuffer[edge + 6] = value;
}


/*	Ignore dispatch errors when translating to C
	(since we have no entry point for #error in the VM proxy) */

static int errorWrongIndex(void) {
	;
}


/*	Estimate the length of the vector described by deltaX and deltaY.
	This method may be extremely inaccurate - use it only
	if you know exactly that this doesn't matter. Otherwise
	use #accurateLengthOf:width: */

static int estimatedLengthOfwith(int deltaX, int deltaY) {
    int absDy;
    int absDx;

	if (deltaX >= 0) {
		absDx = deltaX;
	} else {
		absDx = 0 - deltaX;
	}
	if (deltaY >= 0) {
		absDy = deltaY;
	} else {
		absDy = 0 - deltaY;
	}
	if (absDx > absDy) {
		return absDx + (((int) absDy >> 1));
	} else {
		return absDy + (((int) absDx >> 1));
	}
}


/*	Fill the span buffer from leftX to rightX with the given fill. */

static int fillAllFromto(int leftX, int rightX) {
    int startX;
    int fill;
    int stopX;
    int someIntegerValue;
    int someIntegerValue1;

	/* begin topFill */
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		fill = 0;
		goto l5;
	} else {
		fill = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
		goto l5;
	}
l5:	/* end topFill */;
	startX = leftX;
	/* begin topRightX */
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		stopX = 999999999;
		goto l3;
	} else {
		stopX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
		goto l3;
	}
l3:	/* end topRightX */;
	while (stopX < rightX) {
		/* begin makeUnsignedFrom: */
		/* begin topFill */
		if (((workBuffer[1]) - (workBuffer[10])) == 0) {
			someIntegerValue = 0;
			goto l4;
		} else {
			someIntegerValue = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
			goto l4;
		}
	l4:	/* end topFill */;
		fill = someIntegerValue;
		if (!(fill == 0)) {
			if (fillSpanfromto(fill, startX, stopX)) {
				return 1;
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
			goto l2;
		} else {
			stopX = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
			goto l2;
		}
	l2:	/* end topRightX */;
	}
	/* begin makeUnsignedFrom: */
	/* begin topFill */
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		someIntegerValue1 = 0;
		goto l6;
	} else {
		someIntegerValue1 = workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
		goto l6;
	}
l6:	/* end topFill */;
	fill = someIntegerValue1;
	if (!(fill == 0)) {
		return fillSpanfromto(fill, startX, rightX);
	}
	return 0;
}

static int fillBitmapSpan(void) {
	return fillBitmapSpanfromtoat(workBuffer[66], workBuffer[67], workBuffer[68], workBuffer[88]);
}


/*	Fill the span buffer between leftEdge and rightEdge using the given bits.
	Note: We always start from zero - this avoids using huge bitmap buffers if the bitmap is to be displayed at the very far right hand side and also gives us a chance of using certain bitmaps (e.g., those with depth 32) directly. */

static int fillBitmapSpanfromto(int *bits, int leftX, int rightX) {
    int colorMask;
    int x;
    int x0;
    int x1;
    int fillValue;
    int bitX;
    int colorShift;
    int baseShift;

	x0 = leftX;
	x1 = rightX;

	/* Hack for pre-increment */

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

static int fillBitmapSpanfromtoat(int bmFill, int leftX, int rightX, int yValue) {
    int *bits;
    int ds;
    int dt;
    int x;
    int x1;
    int dtX;
    int fillValue;
    int yp;
    int tileFlag;
    int deltaX;
    int dsX;
    int deltaY;
    int xp;
    int bmWidth;
    int bmHeight;
    int newDelta;
    int newDelta1;
    int g;
    int cMask;
    int bmDepth;
    int rShift;
    int r;
    int bmRaster;
    int value;
    int b;
    int a;

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

static int fillBitmapSpanAAfromtoat(int bmFill, int leftX, int rightX, int yValue) {
    int *bits;
    int ds;
    int idx;
    int firstPixel;
    int dt;
    int x;
    int cShift;
    int dtX;
    int fillValue;
    int cMask;
    int yp;
    int tileFlag;
    int aaLevel;
    int deltaX;
    int lastPixel;
    int dsX;
    int deltaY;
    int xp;
    int bmWidth;
    int bmHeight;
    int baseShift;
    int newDelta;
    int newDelta1;
    int newDelta2;
    int newDelta3;
    int newDelta4;
    int newDelta5;
    int firstPixel1;
    int g;
    int cMask1;
    int bmDepth;
    int rShift;
    int r;
    int bmRaster;
    int value;
    int b;
    int a;
    int g1;
    int cMask2;
    int bmDepth1;
    int rShift1;
    int r1;
    int bmRaster1;
    int value1;
    int b1;
    int a1;
    int g2;
    int cMask3;
    int bmDepth2;
    int rShift2;
    int r2;
    int bmRaster2;
    int value2;
    int b2;
    int a2;

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


/*	Fill the span buffer between leftEdge and rightEdge with the given pixel value. */

static int fillColorSpanfromto(int pixelValue32, int leftX, int rightX) {
    int x0;
    int x1;

	if (!((workBuffer[48]) == 1)) {
		return fillColorSpanAAx0x1(pixelValue32, leftX, rightX);
	}
	x0 = leftX;

	/* Unroll the inner loop four times, since we're only storing data. */

	x1 = rightX;
	while ((x0 + 4) < x1) {
		spanBuffer[x0] = pixelValue32;
		spanBuffer[x0 + 1] = pixelValue32;
		spanBuffer[x0 + 2] = pixelValue32;
		spanBuffer[x0 + 3] = pixelValue32;
		x0 += 4;
	}
	while (x0 < x1) {
		spanBuffer[x0] = pixelValue32;
		x0 += 1;
	}
}


/*	This is the inner loop for solid color fills with anti-aliasing.
	This loop has been unrolled for speed and quality into three parts:
		a) copy all pixels that fall into the first full pixel.
		b) copy aaLevel pixels between the first and the last full pixel
		c) copy all pixels that fall in the last full pixel */

static int fillColorSpanAAx0x1(int pixelValue32, int leftX, int rightX) {
    int firstPixel;
    int idx;
    int colorMask;
    int x;
    int pv32;
    int aaLevel;
    int lastPixel;
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

	/* Part a: Deal with the first n sub-pixels */

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

static int fillDirectionXOf(int fill) {
	return objBuffer[fill + 6];
}

static int fillDirectionXOfput(int fill, int value) {
	return objBuffer[fill + 6] = value;
}

static int fillDirectionYOf(int fill) {
	return objBuffer[fill + 7];
}

static int fillDirectionYOfput(int fill, int value) {
	return objBuffer[fill + 7] = value;
}

static int fillLinearGradient(void) {
	return fillLinearGradientfromtoat(workBuffer[66], workBuffer[67], workBuffer[68], workBuffer[88]);
}


/*	Draw a linear gradient fill. */

static int fillLinearGradientfromtoat(int fill, int leftX, int rightX, int yValue) {
    int ds;
    int x;
    int x0;
    int x1;
    int *ramp;
    int rampSize;
    int dsX;
    int rampIndex;
    int x01;
    int x11;
    int x02;
    int x12;

	ramp = (objBuffer + fill) + 12;
	rampSize = objBuffer[fill + 10];
	dsX = objBuffer[fill + 6];
	ds = ((leftX - (objBuffer[fill + 4])) * dsX) + ((yValue - (objBuffer[fill + 5])) * (objBuffer[fill + 7]));
	x = x0 = leftX;

	/* Note: The inner loop has been divided into three parts for speed */
	/* Part one: Fill everything outside the left boundary */

	x1 = rightX;
	while ((((rampIndex = ((int) ds >> 16)) < 0) || (rampIndex >= rampSize)) && (x < x1)) {
		x += 1;
		ds += dsX;
	}
	if (x > x0) {
		if (rampIndex < 0) {
			rampIndex = 0;
		}
		if (rampIndex >= rampSize) {
			rampIndex = rampSize - 1;
		}
		/* begin fillColorSpan:from:to: */
		if (!((workBuffer[48]) == 1)) {
			fillColorSpanAAx0x1(ramp[rampIndex], x0, x);
			goto l1;
		}
		x01 = x0;
		x11 = x;
		while ((x01 + 4) < x11) {
			spanBuffer[x01] = (ramp[rampIndex]);
			spanBuffer[x01 + 1] = (ramp[rampIndex]);
			spanBuffer[x01 + 2] = (ramp[rampIndex]);
			spanBuffer[x01 + 3] = (ramp[rampIndex]);
			x01 += 4;
		}
		while (x01 < x11) {
			spanBuffer[x01] = (ramp[rampIndex]);
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


/*	This is the AA version of linear gradient filling. */

static int fillLinearGradientAArampdsdsXfromto(int fill, int *ramp, int deltaS, int dsX, int leftX, int rightX) {
    int firstPixel;
    int ds;
    int idx;
    int colorMask;
    int x;
    int rampValue;
    int aaLevel;
    int rampSize;
    int lastPixel;
    int colorShift;
    int baseShift;
    int rampIndex;
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

	/* Deal with the first n sub-pixels */

	lastPixel = (rightX - 1) & (~((workBuffer[48]) - 1));
	colorMask = workBuffer[51];
	colorShift = workBuffer[50];
	while ((x < firstPixel) && ((rampIndex < rampSize) && (rampIndex >= 0))) {
		rampValue = (((int *) ramp))[rampIndex];

		/* Copy as many pixels as possible */

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

		/* Copy as many pixels as possible */

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

		/* Copy as many pixels as possible */

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

static int fillMaxXGet(void) {
	return workBuffer[37];
}

static int fillMaxXPut(int value) {
	return workBuffer[37] = value;
}

static int fillMaxYGet(void) {
	return workBuffer[39];
}

static int fillMaxYPut(int value) {
	return workBuffer[39] = value;
}

static int fillMinXGet(void) {
	return workBuffer[36];
}

static int fillMinXPut(int value) {
	return workBuffer[36] = value;
}

static int fillMinYGet(void) {
	return workBuffer[38];
}

static int fillMinYPut(int value) {
	return workBuffer[38] = value;
}

static int fillNormalXOf(int fill) {
	return objBuffer[fill + 8];
}

static int fillNormalXOfput(int fill, int value) {
	return objBuffer[fill + 8] = value;
}

static int fillNormalYOf(int fill) {
	return objBuffer[fill + 9];
}

static int fillNormalYOfput(int fill, int value) {
	return objBuffer[fill + 9] = value;
}

static int fillOffsetXGet(void) {
	return workBuffer[40];
}

static int fillOffsetXPut(int value) {
	return workBuffer[40] = value;
}

static int fillOffsetYGet(void) {
	return workBuffer[41];
}

static int fillOffsetYPut(int value) {
	return workBuffer[41] = value;
}

static int fillOriginXOf(int fill) {
	return objBuffer[fill + 4];
}

static int fillOriginXOfput(int fill, int value) {
	return objBuffer[fill + 4] = value;
}

static int fillOriginYOf(int fill) {
	return objBuffer[fill + 5];
}

static int fillOriginYOfput(int fill, int value) {
	return objBuffer[fill + 5] = value;
}


/*	Part 2a) Compute the decreasing part of the ramp */

static int fillRadialDecreasingrampdeltaSTdsXdtXfromto(int fill, int ramp, int deltaST, int dsX, int dtX, int leftX, int rightX) {
    int ds;
    int dt;
    int x;
    int x1;
    int rampValue;
    int length2;
    int nextLength;
    int rampIndex;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	rampIndex = accurateLengthOfwith(((int) ds >> 16), ((int) dt >> 16));
	rampValue = (((int *) ramp))[rampIndex];
	length2 = (rampIndex - 1) * (rampIndex - 1);
	x = leftX;
	x1 = rightX;
	if (x1 > (objBuffer[fill + 4])) {
		x1 = objBuffer[fill + 4];
	}
	while (x < x1) {
		while ((x < x1) && ((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) >= length2)) {
			spanBuffer[x] = rampValue;
			x += 1;
			ds += dsX;
			dt += dtX;
		}
		nextLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
		while (nextLength < length2) {
			rampIndex -= 1;
			rampValue = (((int *) ramp))[rampIndex];
			length2 = (rampIndex - 1) * (rampIndex - 1);
		}
	}
	(((int *) deltaST))[0] = ds;
	(((int *) deltaST))[1] = dt;
	return x;
}


/*	Part 2a) Compute the decreasing part of the ramp */

static int fillRadialDecreasingAArampdeltaSTdsXdtXfromto(int fill, int *ramp,  int *deltaST, int dsX, int dtX, int leftX, int rightX) {
    int firstPixel;
    int ds;
    int dt;
    int x;
    int colorMask;
    int x1;
    int rampValue;
    int index;
    int aaLevel;
    int lastPixel;
    int length2;
    int nextLength;
    int colorShift;
    int rampIndex;
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

	/* Deal with the first n sub-pixels */

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

static int fillRadialGradient(void) {
	return fillRadialGradientfromtoat(workBuffer[66], workBuffer[67], workBuffer[68], workBuffer[88]);
}


/*	Draw a radial gradient fill. */

static int fillRadialGradientfromtoat(int fill, int leftX, int rightX, int yValue) {
    int ds;
    int dt;
    int x;
    int x1;
    int dtX;
    int *ramp;
    int rampSize;
    int length2;
    int deltaX;
    int dsX;
    int deltaY;
    int *deltaST;
    int x0;
    int x11;
    int ds1;
    int dt1;
    int x2;
    int x12;
    int rampValue;
    int length21;
    int nextLength;
    int rampIndex;
    int ds2;
    int dt2;
    int x3;
    int x13;
    int rampValue1;
    int lastLength;
    int rampSize1;
    int length22;
    int nextLength1;
    int rampIndex1;
    int x01;
    int x14;

	ramp = (objBuffer + fill) + 12;
	rampSize = objBuffer[fill + 10];
	deltaX = leftX - (objBuffer[fill + 4]);
	deltaY = yValue - (objBuffer[fill + 5]);
	dsX = objBuffer[fill + 6];
	dtX = objBuffer[fill + 8];
	ds = (deltaX * dsX) + (deltaY * (objBuffer[fill + 7]));
	dt = (deltaX * dtX) + (deltaY * (objBuffer[fill + 9]));
	x = leftX;

	/* Note: The inner loop has been divided into three parts for speed */
	/* Part one: Fill everything outside the left boundary */

	x1 = rightX;

	/* This is the upper bound */

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
			ds1 = (((int*) deltaST))[0];
			dt1 = (((int*) deltaST))[1];
			rampIndex = accurateLengthOfwith(((int) ds1 >> 16), ((int) dt1 >> 16));
			rampValue = (((int *) ramp))[rampIndex];
			length21 = (rampIndex - 1) * (rampIndex - 1);
			x2 = x;
			x12 = x1;
			if (x12 > (objBuffer[fill + 4])) {
				x12 = objBuffer[fill + 4];
			}
			while (x2 < x12) {
				while ((x2 < x12) && ((((((int) ds1 >> 16)) * (((int) ds1 >> 16))) + ((((int) dt1 >> 16)) * (((int) dt1 >> 16)))) >= length21)) {
					spanBuffer[x2] = rampValue;
					x2 += 1;
					ds1 += dsX;
					dt1 += dtX;
				}
				nextLength = ((((int) ds1 >> 16)) * (((int) ds1 >> 16))) + ((((int) dt1 >> 16)) * (((int) dt1 >> 16)));
				while (nextLength < length21) {
					rampIndex -= 1;
					rampValue = (((int *) ramp))[rampIndex];
					length21 = (rampIndex - 1) * (rampIndex - 1);
				}
			}
			(((int *) deltaST))[0] = ds1;
			(((int *) deltaST))[1] = dt1;
			x = x2;
		} else {
			x = fillRadialDecreasingAArampdeltaSTdsXdtXfromto(fill, ramp, deltaST, dsX, dtX, x, x1);
		}
	}
	if (x < x1) {
		if ((workBuffer[48]) == 1) {
			/* begin fillRadialIncreasing:ramp:deltaST:dsX:dtX:from:to: */
			ds2 = (((int*) deltaST))[0];
			dt2 = (((int*) deltaST))[1];
			rampIndex1 = accurateLengthOfwith(((int) ds2 >> 16), ((int) dt2 >> 16));
			rampValue1 = (((int *) ramp))[rampIndex1];
			rampSize1 = objBuffer[fill + 10];
			length22 = (rampSize1 - 1) * (rampSize1 - 1);
			nextLength1 = (rampIndex1 + 1) * (rampIndex1 + 1);
			lastLength = ((((int) ds2 >> 16)) * (((int) ds2 >> 16))) + ((((int) dt2 >> 16)) * (((int) dt2 >> 16)));
			x3 = x;
			x13 = x1;
			while ((x3 < x13) && (lastLength < length22)) {
				while ((x3 < x13) && ((((((int) ds2 >> 16)) * (((int) ds2 >> 16))) + ((((int) dt2 >> 16)) * (((int) dt2 >> 16)))) <= nextLength1)) {
					spanBuffer[x3] = rampValue1;
					x3 += 1;
					ds2 += dsX;
					dt2 += dtX;
				}
				lastLength = ((((int) ds2 >> 16)) * (((int) ds2 >> 16))) + ((((int) dt2 >> 16)) * (((int) dt2 >> 16)));
				while (lastLength > nextLength1) {
					rampIndex1 += 1;
					rampValue1 = (((int *) ramp))[rampIndex1];
					nextLength1 = (rampIndex1 + 1) * (rampIndex1 + 1);
				}
			}
			(((int *) deltaST))[0] = ds2;
			(((int *) deltaST))[1] = dt2;
			x = x3;
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
		x14 = rightX;
		while ((x01 + 4) < x14) {
			spanBuffer[x01] = (ramp[rampSize - 1]);
			spanBuffer[x01 + 1] = (ramp[rampSize - 1]);
			spanBuffer[x01 + 2] = (ramp[rampSize - 1]);
			spanBuffer[x01 + 3] = (ramp[rampSize - 1]);
			x01 += 4;
		}
		while (x01 < x14) {
			spanBuffer[x01] = (ramp[rampSize - 1]);
			x01 += 1;
		}
	l2:	/* end fillColorSpan:from:to: */;
	}
}


/*	Part 2b) Compute the increasing part of the ramp */

static int fillRadialIncreasingrampdeltaSTdsXdtXfromto(int fill, int ramp, int deltaST, int dsX, int dtX, int leftX, int rightX) {
    int ds;
    int dt;
    int x;
    int x1;
    int rampValue;
    int lastLength;
    int rampSize;
    int length2;
    int nextLength;
    int rampIndex;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	rampIndex = accurateLengthOfwith(((int) ds >> 16), ((int) dt >> 16));
	rampValue = (((int *) ramp))[rampIndex];
	rampSize = objBuffer[fill + 10];

	/* This is the upper bound */

	length2 = (rampSize - 1) * (rampSize - 1);
	nextLength = (rampIndex + 1) * (rampIndex + 1);
	lastLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
	x = leftX;
	x1 = rightX;
	while ((x < x1) && (lastLength < length2)) {
		while ((x < x1) && ((((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)))) <= nextLength)) {
			spanBuffer[x] = rampValue;
			x += 1;
			ds += dsX;
			dt += dtX;
		}
		lastLength = ((((int) ds >> 16)) * (((int) ds >> 16))) + ((((int) dt >> 16)) * (((int) dt >> 16)));
		while (lastLength > nextLength) {
			rampIndex += 1;
			rampValue = (((int *) ramp))[rampIndex];
			nextLength = (rampIndex + 1) * (rampIndex + 1);
		}
	}
	(((int *) deltaST))[0] = ds;
	(((int *) deltaST))[1] = dt;
	return x;
}


/*	Part 2b) Compute the increasing part of the ramp */

static int fillRadialIncreasingAArampdeltaSTdsXdtXfromto(int fill, int *ramp,  int *deltaST, int dsX, int dtX, int leftX, int rightX) {
    int firstPixel;
    int ds;
    int dt;
    int x;
    int colorMask;
    int rampValue;
    int index;
    int lastLength;
    int aaLevel;
    int rampSize;
    int length2;
    int lastPixel;
    int nextLength;
    int colorShift;
    int rampIndex;
    int baseShift;
    int firstPixel1;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	aaLevel = workBuffer[48];
	baseShift = workBuffer[49];
	rampIndex = accurateLengthOfwith(((int) ds >> 16), ((int) dt >> 16));
	rampSize = objBuffer[fill + 10];

	/* This is the upper bound */

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

	/* Deal with the first n subPixels */

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


/*	Return true if fillEntry1 should be drawn before fillEntry2 */

static int fillSortsbefore(int fillEntry1, int fillEntry2) {
    int diff;

	diff = (workBuffer[(workBuffer[10]) + (fillEntry1 + 1)]) - (workBuffer[(workBuffer[10]) + (fillEntry2 + 1)]);
	if (!(diff == 0)) {
		return diff > 0;
	}
	return (((unsigned) (workBuffer[(workBuffer[10]) + fillEntry1]))) < (((unsigned) (workBuffer[(workBuffer[10]) + fillEntry2])));
}


/*	Fill the span buffer from leftX to rightX with the given fill.
	Clip before performing any operations. Return true if the fill must
	be handled by some Smalltalk code. */

static int fillSpanfromto(int fill, int leftX, int rightX) {
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


/*	Fill the span buffer from leftX to rightX with the given fill.
	Clip before performing any operations. Return true if the fill must
	be handled by some Smalltalk code. */

static int fillSpanfromtomax(int fill, int leftX, int rightX, int maxRightX) {
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
	if (maxRightX < x1) {
		x1 = maxRightX;
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

static int fillTypeOf(int fill) {
	return ((unsigned) (((objBuffer[fill + 0]) & 65535) & 65280)) >> 8;
}

static int findNextAETEdgeFrom(int leftEdge) {
    int depth;
    int rightEdge;

	depth = objBuffer[leftEdge + 6];
	while ((workBuffer[13]) < (workBuffer[14])) {
		rightEdge = aetBuffer[workBuffer[13]];
		if ((objBuffer[rightEdge + 6]) >= depth) {
			return rightEdge;
		}
		workBuffer[13] = ((workBuffer[13]) + 1);
	}
	return null;
}


/*	Check the global edge table for any entries that cannot be handled by the engine itself.
	If there are any, return true. Otherwise, initialize the the edge and add it to the AET */

static int findNextExternalEntryFromGET(void) {
    int edge;
    int type;
    int yValue;


	/* As long as we have entries in the GET */

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


/*	Scan the active edge table. If there is any fill that cannot be handled by the engine itself,  return true. Otherwise handle the fills and return false. */
/*	self currentYGet >= 680 ifTrue:[
self printAET.
self halt.
]. */

static int findNextExternalFillFromAET(void) {
    int leftEdge;
    int leftX;
    int rightEdge;
    int rightX;
    int startX;
    int fill;
    int stopX;
    int someIntegerValue;
    int someIntegerValue1;
    int rightX1;
    int startX1;
    int fill1;
    int stopX1;
    int someIntegerValue2;
    int someIntegerValue11;

	leftX = rightX = workBuffer[37];
	while ((workBuffer[13]) < (workBuffer[14])) {

		/* TODO: We should check if leftX from last operation 
			is  greater than leftX from next edge.
			Currently, we rely here on spanEndAA
			from the span buffer fill. */

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


/*	Check the active edge table for any entries that cannot be handled by the engine itself.
	If there are any, return true. Otherwise, step the the edge to the next y value. */

static int findNextExternalUpdateFromAET(void) {
    int edge;
    int count;
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

static int findStackFilldepth(int fillIndex, int depth) {
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


/*	Return true if processing is finished */

static int finishedProcessing(void) {
	return (workBuffer[2]) == 8;
}

static int firstPointListGet(void) {
	return workBuffer[70];
}

static int firstPointListPut(int value) {
	return workBuffer[70] = value;
}

static int freeStackFillEntry(void) {
	/* begin wbStackPop: */
	workBuffer[10] = ((workBuffer[10]) + 3);
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}


/*	Return true if the edge at index i should sort before the edge at index j. */

static int getSortsbefore(int edge1, int edge2) {
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

static int getStartGet(void) {
	return workBuffer[11];
}

static int getStartPut(int value) {
	return workBuffer[11] = value;
}

static int getUsedGet(void) {
	return workBuffer[12];
}

static int getUsedPut(int value) {
	return workBuffer[12] = value;
}

static int gradientRampLengthOf(int fill) {
	return objBuffer[fill + 10];
}

static int gradientRampLengthOfput(int fill, int value) {
	return objBuffer[fill + 10] = value;
}

static int * gradientRampOf(int fill) {
	return (objBuffer + fill) + 12;
}

static int halt(void) {
	;
}

static int hasColorTransform(void) {
	return (workBuffer[17]) != 0;
}

static int hasColorTransformGet(void) {
	return workBuffer[17];
}

static int hasColorTransformPut(int value) {
	return workBuffer[17] = value;
}

static int hasEdgeTransform(void) {
	return (workBuffer[16]) != 0;
}

static int hasEdgeTransformGet(void) {
	return workBuffer[16];
}

static int hasEdgeTransformPut(int value) {
	return workBuffer[16] = value;
}


/*	Make the fill style with the given index invisible */

static int hideFilldepth(int fillIndex, int depth) {
    int newTopIndex;
    int newDepth;
    int newTop;
    int newRightX;
    int index;

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

static int incrementPointby(int *point, int delta) {
	point[0] = ((point[0]) + delta);
	point[1] = ((point[1]) + delta);
}

static int incrementStatby(int statIndex, int value) {
	return workBuffer[statIndex] = ((workBuffer[statIndex]) + value);
}


/*	Find insertion point for the given edge in the AET */

static int indexForInsertingIntoAET(int edge) {
    int initialX;
    int index;

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

static int initColorTransform(void) {
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

static int initEdgeTransform(void) {
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

EXPORT(int) initialiseModule(void) {
	loadBBFn = interpreterProxy->ioLoadFunctionFrom("loadBitBltFrom", bbPluginName);
	copyBitsFn = interpreterProxy->ioLoadFunctionFrom("copyBitsFromtoat", bbPluginName);
	return (loadBBFn != 0) && (copyBitsFn != 0);
}


/*	Initialization stuff that needs to be done before any processing can take place. */

static int initializeGETProcessing(void) {
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

	/* Create the global edge table */

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


/*	Insert the edge with the given index from the global edge table into the active edge table.
	The edge has already been stepped to the initial yValue -- thus remainingLines and rasterX
	are both set. */

static int insertEdgeIntoAET(int edge) {
    int index;

	if ((objBuffer[edge + 7]) <= 0) {
		return null;
	}

	/* And insert edge */

	index = indexForInsertingIntoAET(edge);
	insertToAETbeforeIndex(edge, index);
}


/*	Insert the given edge into the AET. */

static int insertToAETbeforeIndex(int edge, int index) {
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

static int isBezier(int bezier) {
	return (((objBuffer[bezier + 0]) & 65535) & 254) == 6;
}

static int isEdge(int edge) {
    int type;

	type = (objBuffer[edge + 0]) & 65535;
	if (type > 255) {
		return 0;
	}
	return (((objBuffer[edge + 0]) & 65535) & 255) != 0;
}

static int isFill(int fill) {
	return ((fill & 4278190080U) != 0) || ((((objBuffer[fill + 0]) & 65535) & 65280) != 0);
}

static int isFillColor(int fill) {
	return (fill & 4278190080U) != 0;
}

static int isFillOkay(int fill) {
	return (fill == 0) || (((fill & 4278190080U) != 0) || (((fill >= 0) && (fill < objUsed)) && (((fill & 4278190080U) != 0) || ((((objBuffer[fill + 0]) & 65535) & 65280) != 0))));
}

static int isLine(int line) {
	return (((objBuffer[line + 0]) & 65535) & 254) == 4;
}

static int isObject(int obj) {
	return (obj >= 0) && (obj < objUsed);
}

static int isRealFill(int fill) {
	return (((objBuffer[fill + 0]) & 65535) & 65280) != 0;
}

static int isStackEntry(int entry) {
	return (entry >= (workBuffer[10])) && (entry < (workBuffer[1]));
}

static int isStackIndex(int index) {
	return (index >= 0) && (index < ((workBuffer[1]) - (workBuffer[10])));
}

static int isWide(int object) {
	return (((objBuffer[object + 0]) & 65535) & 1) != 0;
}

static int isWideBezier(int bezier) {
	return ((((objBuffer[bezier + 0]) & 65535) & 254) == 6) && ((((objBuffer[bezier + 0]) & 65535) & 1) != 0);
}

static int isWideLine(int line) {
	return ((((objBuffer[line + 0]) & 65535) & 254) == 4) && ((((objBuffer[line + 0]) & 65535) & 1) != 0);
}

static int lastExportedEdgeGet(void) {
	return workBuffer[65];
}

static int lastExportedEdgePut(int value) {
	return workBuffer[65] = value;
}

static int lastExportedFillGet(void) {
	return workBuffer[66];
}

static int lastExportedFillPut(int value) {
	return workBuffer[66] = value;
}

static int lastExportedLeftXGet(void) {
	return workBuffer[67];
}

static int lastExportedLeftXPut(int value) {
	return workBuffer[67] = value;
}

static int lastExportedRightXGet(void) {
	return workBuffer[68];
}

static int lastExportedRightXPut(int value) {
	return workBuffer[68] = value;
}

static int lineEndXOf(int line) {
	return objBuffer[line + 14];
}

static int lineEndXOfput(int line, int value) {
	return objBuffer[line + 14] = value;
}

static int lineEndYOf(int line) {
	return objBuffer[line + 15];
}

static int lineEndYOfput(int line, int value) {
	return objBuffer[line + 15] = value;
}

static int lineErrorAdjDownOf(int line) {
	return objBuffer[line + 15];
}

static int lineErrorAdjDownOfput(int line, int value) {
	return objBuffer[line + 15] = value;
}

static int lineErrorAdjUpOf(int line) {
	return objBuffer[line + 14];
}

static int lineErrorAdjUpOfput(int line, int value) {
	return objBuffer[line + 14] = value;
}

static int lineErrorOf(int line) {
	return objBuffer[line + 13];
}

static int lineErrorOfput(int line, int value) {
	return objBuffer[line + 13] = value;
}

static int lineXDirectionOf(int line) {
	return objBuffer[line + 10];
}

static int lineXDirectionOfput(int line, int value) {
	return objBuffer[line + 10] = value;
}

static int lineXIncrementOf(int line) {
	return objBuffer[line + 12];
}

static int lineXIncrementOfput(int line, int value) {
	return objBuffer[line + 12] = value;
}

static int lineYDirectionOf(int line) {
	return objBuffer[line + 11];
}

static int lineYDirectionOfput(int line, int value) {
	return objBuffer[line + 11] = value;
}


/*	Load and subdivide the bezier curve from point1/point2/point3.
	If wideFlag is set then make sure the curve is monoton in X. */

static int loadAndSubdivideBezierFromviatoisWide(int *point1, int *point2, int *point3, int wideFlag) {
    int index2;
    int index;
    int index1;
    int bz1;
    int bz2;

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

static int loadArrayPolygonnPointsfilllineWidthlineFill(int points, int nPoints, int fillIndex, int lineWidth, int lineFill) {
    int x0;
    int x1;
    int i;
    int y0;
    int y1;

	loadPointfrom(((int *) (workBuffer + 80)), interpreterProxy->fetchPointerofObject(0, points));
	if (interpreterProxy->failed()) {
		return null;
	}
	x0 = (((int *) (workBuffer + 80)))[0];
	y0 = (((int *) (workBuffer + 80)))[1];
	for (i = 1; i <= (nPoints - 1); i += 1) {
		loadPointfrom(((int *) (workBuffer + 80)), interpreterProxy->fetchPointerofObject(i, points));
		if (interpreterProxy->failed()) {
			return null;
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
			return null;
		}
		x0 = x1;
		y0 = y1;
	}
}

static int loadArrayShapenSegmentsfilllineWidthlineFill(int points, int nSegments, int fillIndex, int lineWidth, int lineFill) {
    int x0;
    int segs;
    int x1;
    int x2;
    int i;
    int pointOop;
    int y0;
    int y1;
    int y2;

	for (i = 0; i <= (nSegments - 1); i += 1) {
		pointOop = interpreterProxy->fetchPointerofObject(i * 3, points);
		loadPointfrom(((int *) (workBuffer + 80)), pointOop);
		pointOop = interpreterProxy->fetchPointerofObject((i * 3) + 1, points);
		loadPointfrom(((int *) (workBuffer + 82)), pointOop);
		pointOop = interpreterProxy->fetchPointerofObject((i * 3) + 2, points);
		loadPointfrom(((int *) (workBuffer + 84)), pointOop);
		if (interpreterProxy->failed()) {
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

		/* Check if we can use a line */

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


/*	Load a transformation from the given array. */

static int loadArrayTransformFromintolength(int transformOop, float *destPtr, int n) {
    int value;
    int i;

	for (i = 0; i <= (n - 1); i += 1) {
		value = interpreterProxy->fetchPointerofObject(i, transformOop);
		if (!(((value & 1)) || (interpreterProxy->isFloatObject(value)))) {
			return interpreterProxy->primitiveFail();
		}
		if ((value & 1)) {
			destPtr[i] = (((float) (((double) ((value >> 1)) ))));
		} else {
			destPtr[i] = (((float) (interpreterProxy->floatValueOf(value))));
		}
	}
}


/*	Initialize the bezier segment stored on the stack */

static int loadBeziersegmentleftFillrightFilloffset(int bezier, int index, int leftFillIndex, int rightFillIndex, int yOffset) {
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

static int loadBitBltFrom(int bbObj) {
	if (loadBBFn == 0) {
		if (!(initialiseModule())) {
			return 0;
		}
	}
	return ((int (*) (int))loadBBFn)(bbObj);
}


/*	Load the bitmap fill. */

static int loadBitmapFillcolormaptilefromalongnormalxIndex(int formOop, int cmOop, int tileFlag, int *point1, int *point2, int *point3, int xIndex) {
    int ppw;
    int bmBitsSize;
    int *cmBits;
    int bmDepth;
    int bmBits;
    int cmSize;
    int bmWidth;
    int bmFill;
    int bmHeight;
    int bmRaster;

	if (cmOop == (interpreterProxy->nilObject())) {
		cmSize = 0;
		cmBits = null;
	} else {
		if (!((interpreterProxy->fetchClassOf(cmOop)) == (interpreterProxy->classBitmap()))) {
			return interpreterProxy->primitiveFail();
		}
		cmSize = interpreterProxy->slotSizeOf(cmOop);
		cmBits = interpreterProxy->firstIndexableField(cmOop);
	}
	if ((formOop & 1)) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isPointers(formOop))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(formOop)) < 5) {
		return interpreterProxy->primitiveFail();
	}
	bmBits = interpreterProxy->fetchPointerofObject(0, formOop);
	if (!((interpreterProxy->fetchClassOf(bmBits)) == (interpreterProxy->classBitmap()))) {
		return interpreterProxy->primitiveFail();
	}
	bmBitsSize = interpreterProxy->slotSizeOf(bmBits);
	bmWidth = interpreterProxy->fetchIntegerofObject(1, formOop);
	bmHeight = interpreterProxy->fetchIntegerofObject(2, formOop);
	bmDepth = interpreterProxy->fetchIntegerofObject(3, formOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!((bmWidth >= 0) && (bmHeight >= 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((((((bmDepth == 32) || (bmDepth == 8)) || (bmDepth == 16)) || (bmDepth == 1)) || (bmDepth == 2)) || (bmDepth == 4))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((cmSize == 0) || (cmSize == (1 << bmDepth)))) {
		return interpreterProxy->primitiveFail();
	}
	ppw = 32 / bmDepth;
	bmRaster = (bmWidth + (ppw - 1)) / ppw;
	if (!(bmBitsSize == (bmRaster * bmHeight))) {
		return interpreterProxy->primitiveFail();
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


/*	Note: Assumes that the contents of formArray has been checked before */

static int * loadBitsFrom(int bmFill) {
    int formOop;
    int xIndex;
    int bitsLen;
    int bitsOop;

	xIndex = objBuffer[bmFill + 2];
	if (xIndex > (interpreterProxy->slotSizeOf(formArray))) {
		return null;
	}
	formOop = interpreterProxy->fetchPointerofObject(xIndex, formArray);
	bitsOop = interpreterProxy->fetchPointerofObject(0, formOop);
	bitsLen = interpreterProxy->slotSizeOf(bitsOop);
	if (!(bitsLen == (objBuffer[bmFill + 13]))) {
		return null;
	}
	return interpreterProxy->firstIndexableField(bitsOop);
}


/*	Load a 2x3 transformation matrix from the given oop.
	Return true if the matrix is not nil, false otherwise */

static int loadColorTransformFrom(int transformOop) {
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


/*	Load the compressed segment identified by segment index */

static int loadCompressedSegmentfromshortleftFillrightFilllineWidthlineColor(int segmentIndex, int points, int pointsShort, int leftFill, int rightFill, int lineWidth, int lineFill) {
    int x0;
    int segs;
    int x1;
    int x2;
    int index;
    int y0;
    int y1;
    int y2;

	if ((leftFill == rightFill) && ((lineWidth == 0) || (lineFill == 0))) {
		return null;
	}

	/* 3 points with x/y each */

	index = segmentIndex * 6;
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
			return null;
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
		return loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), lineFill, leftFill, rightFill);
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
		return null;
	}
	loadWideBezierlineFillleftFillrightFilln(lineWidth, lineFill, leftFill, rightFill, segs);
}


/*	Load a compressed shape into the engine.
		WARNING: THIS METHOD NEEDS THE FULL FRAME SIZE!!!!
	 */

static int loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(int *points, int nSegments, int *leftFills, int *rightFills, int *lineWidths, int *lineFills, int *fillIndexList, int pointsShort) {
    int widthRun;
    int rightLength;
    int rightRun;
    int i;
    int rightValue;
    int leftValue;
    int widthValue;
    int lineFillLength;
    int lineFillRun;
    int leftLength;
    int leftRun;
    int widthLength;
    int lineFillValue;
    int x0;
    int segs;
    int x1;
    int x2;
    int index;
    int y0;
    int y1;
    int y2;

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

static int loadEdgeStateFrom(int edgeOop) {
    int edge;
    int value;
    int value1;
    int value2;
    int value3;

	edge = workBuffer[65];
	if ((interpreterProxy->slotSizeOf(edgeOop)) < 6) {
		return interpreterProxy->primitiveFail();
	}
	/* begin edgeXValueOf:put: */
	value = interpreterProxy->fetchIntegerofObject(1, edgeOop);
	objBuffer[edge + 4] = value;
	/* begin edgeYValueOf:put: */
	value2 = interpreterProxy->fetchIntegerofObject(2, edgeOop);
	objBuffer[edge + 5] = value2;
	/* begin edgeZValueOf:put: */
	value3 = interpreterProxy->fetchIntegerofObject(3, edgeOop);
	objBuffer[edge + 6] = value3;
	/* begin edgeNumLinesOf:put: */
	value1 = interpreterProxy->fetchIntegerofObject(4, edgeOop);
	objBuffer[edge + 7] = value1;
	return edge;
}


/*	Load a 2x3 transformation matrix from the given oop.
	Return true if the matrix is not nil, false otherwise */

static int loadEdgeTransformFrom(int transformOop) {
    float *transform;
    int okay;

	workBuffer[16] = 0;
	transform = ((float *) (workBuffer + 18));
	okay = loadTransformFromintolength(transformOop, transform, 6);
	if (interpreterProxy->failed()) {
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


/*	Transform the points */

static int loadFillOrientationfromalongnormalwidthheight(int fill, int *point1, int *point2, int *point3, int fillWidth, int fillHeight) {
    int dirY;
    int dtX;
    int dtY;
    int nrmX;
    int nrmY;
    int dtLength2;
    int dsX;
    int dsLength2;
    int dsY;
    int dirX;

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

	/* Compute the scale from direction/normal into ramp size */

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


/*	Check all the forms from arrayOop. */

static int loadFormsFrom(int arrayOop) {
    int ppw;
    int bmBitsSize;
    int i;
    int bmDepth;
    int formOop;
    int bmBits;
    int bmWidth;
    int bmHeight;
    int bmRaster;

	if (!((interpreterProxy->fetchClassOf(arrayOop)) == (interpreterProxy->classArray()))) {
		return 0;
	}
	formArray = arrayOop;
	for (i = 0; i <= ((interpreterProxy->slotSizeOf(formArray)) - 1); i += 1) {
		formOop = interpreterProxy->fetchPointerofObject(i, formArray);
		if ((formOop & 1)) {
			return 0;
		}
		if (!(interpreterProxy->isPointers(formOop))) {
			return 0;
		}
		if ((interpreterProxy->slotSizeOf(formOop)) < 5) {
			return 0;
		}
		bmBits = interpreterProxy->fetchPointerofObject(0, formOop);
		if (!((interpreterProxy->fetchClassOf(bmBits)) == (interpreterProxy->classBitmap()))) {
			return 0;
		}
		bmBitsSize = interpreterProxy->slotSizeOf(bmBits);
		bmWidth = interpreterProxy->fetchIntegerofObject(1, formOop);
		bmHeight = interpreterProxy->fetchIntegerofObject(2, formOop);
		bmDepth = interpreterProxy->fetchIntegerofObject(3, formOop);
		if (interpreterProxy->failed()) {
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


/*	Load the gradient fill as defined by the color ramp. */

static int loadGradientFillfromalongnormalisRadial(int rampOop, int *point1, int *point2, int *point3, int isRadial) {
    int fill;
    int rampWidth;

	if (!((interpreterProxy->fetchClassOf(rampOop)) == (interpreterProxy->classBitmap()))) {
		return interpreterProxy->primitiveFail();
	}
	rampWidth = interpreterProxy->slotSizeOf(rampOop);
	fill = allocateGradientFillrampWidthisRadial(interpreterProxy->firstIndexableField(rampOop), rampWidth, isRadial);
	if (engineStopped) {
		return null;
	}
	loadFillOrientationfromalongnormalwidthheight(fill, point1, point2, point3, rampWidth, rampWidth);
	return fill;
}


/*	Load the line defined by point1 and point2. */

static int loadLinefromtooffsetleftFillrightFill(int line, int *point1, int *point2, int yOffset, int leftFill, int rightFill) {
    int *p1;
    int *p2;
    int yDir;

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


/*	Load a rectangular oval currently defined by point1/point2 */

static int loadOvallineFillleftFillrightFill(int lineWidth, int lineFill, int leftFill, int rightFill) {
    int w;
    int h;
    int i;
    int nSegments;
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

static int loadOvalSegmentwhcxcy(int seg, int w, int h, int cx, int cy) {
    int x0;
    int x1;
    int x2;
    int y0;
    int y1;
    int y2;

	x0 = ((int) ((((circleCosTable())[(seg * 2) + 0]) * (((double) w ))) + cx) );
	y0 = ((int) ((((circleSinTable())[(seg * 2) + 0]) * (((double) h ))) + cy) );
	(((int *) (workBuffer + 80)))[0] = x0;
	(((int *) (workBuffer + 80)))[1] = y0;
	x2 = ((int) ((((circleCosTable())[(seg * 2) + 2]) * (((double) w ))) + cx) );
	y2 = ((int) ((((circleSinTable())[(seg * 2) + 2]) * (((double) h ))) + cy) );
	(((int *) (workBuffer + 84)))[0] = x2;
	(((int *) (workBuffer + 84)))[1] = y2;
	x1 = ((int) ((((circleCosTable())[(seg * 2) + 1]) * (((double) w ))) + cx) );

	/* NOTE: The intermediate point is the point ON the curve
	and not yet the control point (which is OFF the curve) */

	y1 = ((int) ((((circleSinTable())[(seg * 2) + 1]) * (((double) h ))) + cy) );
	x1 = (x1 * 2) - (((int) (x0 + x2) >> 1));
	y1 = (y1 * 2) - (((int) (y0 + y2) >> 1));
	(((int *) (workBuffer + 82)))[0] = x1;
	(((int *) (workBuffer + 82)))[1] = y1;
}


/*	Load the contents of pointOop into pointArray */

static int loadPointfrom(int *pointArray, int pointOop) {
    int value;

	if (!((interpreterProxy->fetchClassOf(pointOop)) == (interpreterProxy->classPoint()))) {
		return interpreterProxy->primitiveFail();
	}
	value = interpreterProxy->fetchPointerofObject(0, pointOop);
	if (!(((value & 1)) || (interpreterProxy->isFloatObject(value)))) {
		return interpreterProxy->primitiveFail();
	}
	if ((value & 1)) {
		pointArray[0] = ((value >> 1));
	} else {
		pointArray[0] = (((int) (interpreterProxy->floatValueOf(value)) ));
	}
	value = interpreterProxy->fetchPointerofObject(1, pointOop);
	if (!(((value & 1)) || (interpreterProxy->isFloatObject(value)))) {
		return interpreterProxy->primitiveFail();
	}
	if ((value & 1)) {
		pointArray[1] = ((value >> 1));
	} else {
		pointArray[1] = (((int) (interpreterProxy->floatValueOf(value)) ));
	}
}


/*	Load the int value from the given index in intArray */

static int loadPointIntAtfrom(int index, int intArray) {
	return (((int *) intArray))[index];
}


/*	Load the short value from the given index in shortArray */

static short loadPointShortAtfrom(int index, int shortArray) {
	return (((short *) shortArray))[index];
}

static int loadPolygonnPointsfilllineWidthlineFillpointsShort(int *points, int nPoints, int fillIndex, int lineWidth, int lineFill, int isShort) {
    int x0;
    int x1;
    int i;
    int y0;
    int y1;

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


/*	Load a rectangle currently defined by point1-point4 */

static int loadRectanglelineFillleftFillrightFill(int lineWidth, int lineFill, int leftFill, int rightFill) {
	loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), lineFill, leftFill, rightFill);
	loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), lineFill, leftFill, rightFill);
	loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 84)), ((int *) (workBuffer + 86)), lineFill, leftFill, rightFill);
	loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + 86)), ((int *) (workBuffer + 80)), lineFill, leftFill, rightFill);
}


/*	Load the entire state from the interpreter for the rendering primitives */

static int loadRenderingState(void) {
    int edgeOop;
    int state;
    int fillOop;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	fillOop = interpreterProxy->stackObjectValue(0);
	edgeOop = interpreterProxy->stackObjectValue(1);
	engine = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return 0;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return 0;
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(1, engine)))) {
		return 0;
	}
	if (!(loadBitBltFrom(interpreterProxy->fetchPointerofObject(2, engine)))) {
		return 0;
	}
	if (!(loadFormsFrom(interpreterProxy->fetchPointerofObject(3, engine)))) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(edgeOop)) < 6) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(fillOop)) < 6) {
		return 0;
	}
	state = workBuffer[2];
	if ((state == 2) || ((state == 4) || (state == 7))) {
		return 0;
	}
	return 1;
}

static int loadShapenSegmentsfilllineWidthlineFillpointsShort(int *points, int nSegments, int fillIndex, int lineWidth, int lineFill, int pointsShort) {
    int i;
    int x0;
    int segs;
    int x1;
    int x2;
    int index;
    int y0;
    int y1;
    int y2;

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


/*	Load the span buffer from the given oop. */

static int loadSpanBufferFrom(int spanOop) {
    int value;

	if (!((interpreterProxy->fetchClassOf(spanOop)) == (interpreterProxy->classBitmap()))) {
		return 0;
	}

	/* Leave last entry unused to avoid complications */

	spanBuffer = interpreterProxy->firstIndexableField(spanOop);
	/* begin spanSizePut: */
	value = (interpreterProxy->slotSizeOf(spanOop)) - 1;
	workBuffer[33] = value;
	return 1;
}


/*	Load a transformation from transformOop into the float array
	defined by destPtr. The transformation is assumed to be either
	an array or a FloatArray of length n. */

static int loadTransformFromintolength(int transformOop, float *destPtr, int n) {
	if (transformOop == (interpreterProxy->nilObject())) {
		return 0;
	}
	if ((transformOop & 1)) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->slotSizeOf(transformOop)) == n)) {
		return interpreterProxy->primitiveFail();
	}
	if (interpreterProxy->isWords(transformOop)) {
		loadWordTransformFromintolength(transformOop, destPtr, n);
	} else {
		loadArrayTransformFromintolength(transformOop, destPtr, n);
	}
	return 1;
}


/*	Load the (possibly wide) bezier from the segments currently on the bezier stack. */

static int loadWideBezierlineFillleftFillrightFilln(int lineWidth, int lineFill, int leftFill, int rightFill, int nSegments) {
    int index;
    int bezier;
    int wide;
    int offset;
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
				goto l2;
			}
			bezier2 = objUsed;
			objUsed = bezier2 + 28;
			objBuffer[bezier2 + 0] = 7;
			objBuffer[bezier2 + 2] = 0;
			objBuffer[bezier2 + 1] = 28;
			bezier = bezier2;
		l2:	/* end allocateWideBezier */;
		} else {
			/* begin allocateBezier */
			if (!(allocateObjEntry(16))) {
				bezier = 0;
				goto l1;
			}
			bezier1 = objUsed;
			objUsed = bezier1 + 16;
			objBuffer[bezier1 + 0] = 6;
			objBuffer[bezier1 + 2] = 0;
			objBuffer[bezier1 + 1] = 16;
			bezier = bezier1;
		l1:	/* end allocateBezier */;
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


/*	Load a (possibly wide) line defined by the points p1 and p2 */

static int loadWideLinefromtolineFillleftFillrightFill(int lineWidth, int *p1, int *p2, int lineFill, int leftFill, int rightFill) {
    int line;
    int offset;
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


/*	Load a float array transformation from the given oop */

static int loadWordTransformFromintolength(int transformOop, float *destPtr, int n) {
    float *srcPtr;
    int i;

	srcPtr = ((float *) (interpreterProxy->firstIndexableField(transformOop)));
	for (i = 0; i <= (n - 1); i += 1) {
		destPtr[i] = (srcPtr[i]);
	}
}


/*	Load the working buffer from the given oop */

static int loadWorkBufferFrom(int wbOop) {
	if ((wbOop & 1)) {
		return 0;
	}
	if (!(interpreterProxy->isWords(wbOop))) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(wbOop)) < 256) {
		return 0;
	}
	workBuffer = interpreterProxy->firstIndexableField(wbOop);
	if (!((workBuffer[0]) == 1097753705)) {
		return 0;
	}
	if (!((workBuffer[1]) == (interpreterProxy->slotSizeOf(wbOop)))) {
		return 0;
	}
	if (!((workBuffer[8]) == 128)) {
		return 0;
	}
	objBuffer = workBuffer + (workBuffer[8]);
	getBuffer = objBuffer + (workBuffer[9]);

	/* Make sure we don't exceed the work buffer */

	aetBuffer = getBuffer + (workBuffer[12]);
	if ((((128 + (workBuffer[9])) + (workBuffer[12])) + (workBuffer[14])) > (workBuffer[1])) {
		return 0;
	}
	return 1;
}

static int magicNumberGet(void) {
	return workBuffer[0];
}

static int magicNumberPut(int value) {
	return workBuffer[0] = value;
}

static int makeRectFromPoints(void) {
	(((int *) (workBuffer + 82)))[0] = ((((int *) (workBuffer + 84)))[0]);
	(((int *) (workBuffer + 82)))[1] = ((((int *) (workBuffer + 80)))[1]);
	(((int *) (workBuffer + 86)))[0] = ((((int *) (workBuffer + 80)))[0]);
	(((int *) (workBuffer + 86)))[1] = ((((int *) (workBuffer + 84)))[1]);
}

static int makeUnsignedFrom(int someIntegerValue) {
	return someIntegerValue;
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

EXPORT(int) moduleUnloaded(char * aModuleName) {
	if ((strcmp(aModuleName, bbPluginName)) == 0) {
		loadBBFn = 0;
		copyBitsFn = 0;
	}
}


/*	The entry at index is not in the right position of the AET. 
	Move it to the left until the position is okay. */

static int moveAETEntryFromedgex(int index, int edge, int xValue) {
    int newIndex;

	newIndex = index;
	while ((newIndex > 0) && ((objBuffer[(aetBuffer[newIndex - 1]) + 4]) > xValue)) {
		aetBuffer[newIndex] = (aetBuffer[newIndex - 1]);
		newIndex -= 1;
	}
	aetBuffer[newIndex] = edge;
}

static int msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Check if we have n slots available */

static int needAvailableSpace(int nSlots) {
	if (((((128 + objUsed) + (workBuffer[12])) + (workBuffer[14])) + nSlots) > (workBuffer[10])) {
		/* begin stopBecauseOf: */
		workBuffer[64] = 1;
		engineStopped = 1;
		return 0;
	}
	return 1;
}

static int needsFlush(void) {
	return (workBuffer[63]) != 0;
}

static int needsFlushGet(void) {
	return workBuffer[63];
}

static int needsFlushPut(int value) {
	return workBuffer[63] = value;
}

static int objat(int object, int index) {
	return objBuffer[object + index];
}

static int objatput(int object, int index, int value) {
	return objBuffer[object + index] = value;
}

static int objStartGet(void) {
	return workBuffer[8];
}

static int objStartPut(int value) {
	return workBuffer[8] = value;
}

static int objUsedGet(void) {
	return workBuffer[9];
}

static int objUsedPut(int value) {
	return workBuffer[9] = value;
}

static int objectHeaderOf(int obj) {
	return objBuffer[obj + 0];
}

static int objectIndexOf(int obj) {
	return objBuffer[obj + 2];
}

static int objectIndexOfput(int obj, int value) {
	return objBuffer[obj + 2] = value;
}

static int objectLengthOf(int obj) {
	return objBuffer[obj + 1];
}

static int objectLengthOfput(int obj, int value) {
	return objBuffer[obj + 1] = value;
}

static int objectTypeOf(int obj) {
	return (objBuffer[obj + 0]) & 65535;
}

static int objectTypeOfput(int obj, int value) {
	return objBuffer[obj + 0] = value;
}


/*	Common function so that we don't compute that wrong in any place
	and can easily find all the places where we deal with one-pixel offsets. */

static int offsetFromWidth(int lineWidth) {
	return ((int) lineWidth >> 1);
}

static int * point1Get(void) {
	return ((int *) (workBuffer + 80));
}

static int * point2Get(void) {
	return ((int *) (workBuffer + 82));
}

static int * point3Get(void) {
	return ((int *) (workBuffer + 84));
}

static int * point4Get(void) {
	return ((int *) (workBuffer + 86));
}


/*	We have just blitted a scan line to the screen.
	Do whatever seems to be a good idea here. */
/*	Note: In the future we may check the time needed for this scan line and interrupt processing to give the Smalltalk code a chance to run at a certain time. */

static int postDisplayAction(void) {
	if (((workBuffer[11]) >= (workBuffer[12])) && ((workBuffer[14]) == 0)) {
		workBuffer[2] = 8;
	}
	if ((workBuffer[88]) >= (workBuffer[39])) {
		workBuffer[2] = 8;
	}
}

EXPORT(int) primitiveAbortProcessing(void) {
	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	workBuffer[2] = 8;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
}


/*	Note: No need to load either bitBlt or spanBuffer */

EXPORT(int) primitiveAddActiveEdgeEntry(void) {
    int edge;
    int edgeOop;
    int value;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	edgeOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 2))) {
		return interpreterProxy->primitiveFail();
	}
	edge = loadEdgeStateFrom(edgeOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(needAvailableSpace(1))) {
		return interpreterProxy->primitiveFail();
	}
	if ((objBuffer[edge + 7]) > 0) {
		insertEdgeIntoAET(edge);
	}
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	workBuffer[2] = 1;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	interpreterProxy->pop(1);
	if (doProfileStats) {
		workBuffer[97] = ((workBuffer[97]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[96] = ((workBuffer[96]) + value);
	}
}

EXPORT(int) primitiveAddBezier(void) {
    int endOop;
    int leftFill;
    int viaOop;
    int startOop;
    int rightFill;
    int nSegments;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	rightFill = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	leftFill = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(1));
	viaOop = interpreterProxy->stackObjectValue(2);
	endOop = interpreterProxy->stackObjectValue(3);
	startOop = interpreterProxy->stackObjectValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((isFillOkay(leftFill)) && (isFillOkay(rightFill)))) {
		return interpreterProxy->primitiveFail();
	}
	if ((leftFill == rightFill) && 0) {
		return interpreterProxy->pop(6);
	}
	loadPointfrom(((int *) (workBuffer + 80)), startOop);
	loadPointfrom(((int *) (workBuffer + 82)), viaOop);
	loadPointfrom(((int *) (workBuffer + 84)), endOop);
	if (interpreterProxy->failed()) {
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
		goto l1;
	}
l1:	/* end needAvailableSpace: */;
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
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(5);
	}
}

EXPORT(int) primitiveAddBezierShape(void) {
    int points;
    int length;
    int lineWidth;
    int lineFill;
    int isArray;
    int fillIndex;
    int segSize;
    int nSegments;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	lineFill = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	lineWidth = interpreterProxy->stackIntegerValue(1);
	fillIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(2));
	nSegments = interpreterProxy->stackIntegerValue(3);
	points = interpreterProxy->stackObjectValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), 0))) {
		return interpreterProxy->primitiveFail();
	}
	length = interpreterProxy->slotSizeOf(points);
	if (interpreterProxy->isWords(points)) {

		/* Either PointArray or ShortPointArray */

		isArray = 0;
		if (!((length == (nSegments * 3)) || (length == (nSegments * 6)))) {
			return interpreterProxy->primitiveFail();
		}
	} else {
		if (!((interpreterProxy->fetchClassOf(points)) == (interpreterProxy->classArray()))) {
			return interpreterProxy->primitiveFail();
		}
		if (!(length == (nSegments * 3))) {
			return interpreterProxy->primitiveFail();
		}
		isArray = 1;
	}
	if ((lineWidth == 0) || (lineFill == 0)) {
		segSize = 16;
	} else {
		segSize = 21;
	}
	if (!(needAvailableSpace(segSize * nSegments))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((isFillOkay(lineFill)) && (isFillOkay(fillIndex)))) {
		return interpreterProxy->primitiveFail();
	}
	lineFill = transformColor(lineFill);
	fillIndex = transformColor(fillIndex);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (((lineFill == 0) || (lineWidth == 0)) && (fillIndex == 0)) {
		return interpreterProxy->pop(5);
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
		loadShapenSegmentsfilllineWidthlineFillpointsShort(interpreterProxy->firstIndexableField(points), nSegments, fillIndex, lineWidth, lineFill, (nSegments * 3) == length);
	}
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(5);
	}
}

EXPORT(int) primitiveAddBitmapFill(void) {
    int tileFlag;
    int formOop;
    int xIndex;
    int nrmOop;
    int fill;
    int cmOop;
    int originOop;
    int dirOop;

	if (!((interpreterProxy->methodArgumentCount()) == 7)) {
		return interpreterProxy->primitiveFail();
	}
	xIndex = interpreterProxy->stackIntegerValue(0);
	if (xIndex <= 0) {
		return interpreterProxy->primitiveFail();
	}
	nrmOop = interpreterProxy->stackObjectValue(1);
	dirOop = interpreterProxy->stackObjectValue(2);
	originOop = interpreterProxy->stackObjectValue(3);
	tileFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(4));
	if (tileFlag) {
		tileFlag = 1;
	} else {
		tileFlag = 0;
	}
	cmOop = interpreterProxy->stackObjectValue(5);
	formOop = interpreterProxy->stackObjectValue(6);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(7), 0))) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + 80)), originOop);
	loadPointfrom(((int *) (workBuffer + 82)), dirOop);
	loadPointfrom(((int *) (workBuffer + 84)), nrmOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	fill = loadBitmapFillcolormaptilefromalongnormalxIndex(formOop, cmOop, tileFlag, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), xIndex - 1);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(8);
		interpreterProxy->push(interpreterProxy->positive32BitIntegerFor(fill));
	}
}

EXPORT(int) primitiveAddCompressedShape(void) {
    int lineWidths;
    int leftFills;
    int points;
    int lineFills;
    int fillIndexList;
    int pointsShort;
    int rightFills;
    int nSegments;

	if (!((interpreterProxy->methodArgumentCount()) == 7)) {
		return interpreterProxy->primitiveFail();
	}
	fillIndexList = interpreterProxy->stackObjectValue(0);
	lineFills = interpreterProxy->stackObjectValue(1);
	lineWidths = interpreterProxy->stackObjectValue(2);
	rightFills = interpreterProxy->stackObjectValue(3);
	leftFills = interpreterProxy->stackObjectValue(4);
	nSegments = interpreterProxy->stackIntegerValue(5);
	points = interpreterProxy->stackObjectValue(6);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(7), 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(points, nSegments, leftFills, rightFills, lineWidths, lineFills, fillIndexList))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(needAvailableSpace((((16 < 16) ? 16 : 16)) * nSegments))) {
		return interpreterProxy->primitiveFail();
	}

	/* Then actually load the compressed shape */

	pointsShort = (interpreterProxy->slotSizeOf(points)) == (nSegments * 3);
	loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(interpreterProxy->firstIndexableField(points), nSegments, interpreterProxy->firstIndexableField(leftFills), interpreterProxy->firstIndexableField(rightFills), interpreterProxy->firstIndexableField(lineWidths), interpreterProxy->firstIndexableField(lineFills), interpreterProxy->firstIndexableField(fillIndexList), pointsShort);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(7);
	}
}

EXPORT(int) primitiveAddGradientFill(void) {
    int rampOop;
    int nrmOop;
    int fill;
    int isRadial;
    int originOop;
    int dirOop;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	isRadial = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	nrmOop = interpreterProxy->stackValue(1);
	dirOop = interpreterProxy->stackValue(2);
	originOop = interpreterProxy->stackValue(3);
	rampOop = interpreterProxy->stackValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), 0))) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + 80)), originOop);
	loadPointfrom(((int *) (workBuffer + 82)), dirOop);
	loadPointfrom(((int *) (workBuffer + 84)), nrmOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	fill = loadGradientFillfromalongnormalisRadial(rampOop, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), ((int *) (workBuffer + 84)), isRadial);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(6);
		interpreterProxy->push(interpreterProxy->positive32BitIntegerFor(fill));
	}
}

EXPORT(int) primitiveAddLine(void) {
    int endOop;
    int leftFill;
    int startOop;
    int rightFill;

	if (!((interpreterProxy->methodArgumentCount()) == 4)) {
		return interpreterProxy->primitiveFail();
	}
	rightFill = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	leftFill = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(1));
	endOop = interpreterProxy->stackObjectValue(2);
	startOop = interpreterProxy->stackObjectValue(3);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(4), 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((isFillOkay(leftFill)) && (isFillOkay(rightFill)))) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + 80)), startOop);
	loadPointfrom(((int *) (workBuffer + 82)), endOop);
	if (interpreterProxy->failed()) {
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
		return interpreterProxy->primitiveFail();
	}
	loadWideLinefromtolineFillleftFillrightFill(0, ((int *) (workBuffer + 80)), ((int *) (workBuffer + 82)), 0, leftFill, rightFill);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(4);
	}
}

EXPORT(int) primitiveAddOval(void) {
    int endOop;
    int borderWidth;
    int borderIndex;
    int startOop;
    int fillIndex;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	borderIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	borderWidth = interpreterProxy->stackIntegerValue(1);
	fillIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(2));
	endOop = interpreterProxy->stackObjectValue(3);
	startOop = interpreterProxy->stackObjectValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((isFillOkay(borderIndex)) && (isFillOkay(fillIndex)))) {
		return interpreterProxy->primitiveFail();
	}
	fillIndex = transformColor(fillIndex);
	borderIndex = transformColor(borderIndex);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if ((fillIndex == 0) && ((borderIndex == 0) || (borderWidth <= 0))) {
		return interpreterProxy->pop(5);
	}
	if (!(needAvailableSpace(16 * 16))) {
		return interpreterProxy->primitiveFail();
	}
	if ((borderWidth > 0) && (borderIndex != 0)) {
		borderWidth = transformWidth(borderWidth);
	} else {
		borderWidth = 0;
	}
	loadPointfrom(((int *) (workBuffer + 80)), startOop);
	loadPointfrom(((int *) (workBuffer + 82)), endOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	loadOvallineFillleftFillrightFill(borderWidth, borderIndex, 0, fillIndex);
	if (engineStopped) {
		/* begin wbStackClear */
		workBuffer[10] = (workBuffer[1]);
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(5);
	}
}

EXPORT(int) primitiveAddPolygon(void) {
    int points;
    int length;
    int lineWidth;
    int lineFill;
    int nPoints;
    int fillIndex;
    int isArray;
    int segSize;
    int x0;
    int x1;
    int i;
    int y0;
    int y1;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	lineFill = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	lineWidth = interpreterProxy->stackIntegerValue(1);
	fillIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(2));
	nPoints = interpreterProxy->stackIntegerValue(3);
	points = interpreterProxy->stackObjectValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), 0))) {
		return interpreterProxy->primitiveFail();
	}
	length = interpreterProxy->slotSizeOf(points);
	if (interpreterProxy->isWords(points)) {

		/* Either PointArray or ShortPointArray */

		isArray = 0;
		if (!((length == nPoints) || ((nPoints * 2) == length))) {
			return interpreterProxy->primitiveFail();
		}
	} else {
		if (!((interpreterProxy->fetchClassOf(points)) == (interpreterProxy->classArray()))) {
			return interpreterProxy->primitiveFail();
		}
		if (!(length == nPoints)) {
			return interpreterProxy->primitiveFail();
		}
		isArray = 1;
	}
	if ((lineWidth == 0) || (lineFill == 0)) {
		segSize = 16;
	} else {
		segSize = 21;
	}
	if (!(needAvailableSpace(segSize * nPoints))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((isFillOkay(lineFill)) && (isFillOkay(fillIndex)))) {
		return interpreterProxy->primitiveFail();
	}
	lineFill = transformColor(lineFill);
	fillIndex = transformColor(fillIndex);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (((lineFill == 0) || (lineWidth == 0)) && (fillIndex == 0)) {
		return interpreterProxy->pop(6);
	}
	if (!(lineWidth == 0)) {
		lineWidth = transformWidth(lineWidth);
	}
	if (isArray) {
		/* begin loadArrayPolygon:nPoints:fill:lineWidth:lineFill: */
		loadPointfrom(((int *) (workBuffer + 80)), interpreterProxy->fetchPointerofObject(0, points));
		if (interpreterProxy->failed()) {
			goto l1;
		}
		x0 = (((int *) (workBuffer + 80)))[0];
		y0 = (((int *) (workBuffer + 80)))[1];
		for (i = 1; i <= (nPoints - 1); i += 1) {
			loadPointfrom(((int *) (workBuffer + 80)), interpreterProxy->fetchPointerofObject(i, points));
			if (interpreterProxy->failed()) {
				goto l1;
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
				goto l1;
			}
			x0 = x1;
			y0 = y1;
		}
	l1:	/* end loadArrayPolygon:nPoints:fill:lineWidth:lineFill: */;
	} else {
		loadPolygonnPointsfilllineWidthlineFillpointsShort(interpreterProxy->firstIndexableField(points), nPoints, fillIndex, lineWidth, lineFill, nPoints == length);
	}
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(5);
	}
}

EXPORT(int) primitiveAddRect(void) {
    int endOop;
    int borderWidth;
    int borderIndex;
    int startOop;
    int fillIndex;

	if (!((interpreterProxy->methodArgumentCount()) == 5)) {
		return interpreterProxy->primitiveFail();
	}
	borderIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	borderWidth = interpreterProxy->stackIntegerValue(1);
	fillIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(2));
	endOop = interpreterProxy->stackObjectValue(3);
	startOop = interpreterProxy->stackObjectValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((isFillOkay(borderIndex)) && (isFillOkay(fillIndex)))) {
		return interpreterProxy->primitiveFail();
	}
	borderIndex = transformColor(borderIndex);
	fillIndex = transformColor(fillIndex);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if ((fillIndex == 0) && ((borderIndex == 0) || (borderWidth == 0))) {
		return interpreterProxy->pop(5);
	}
	if (!(needAvailableSpace(4 * 16))) {
		return interpreterProxy->primitiveFail();
	}
	if ((borderWidth > 0) && (borderIndex != 0)) {
		borderWidth = transformWidth(borderWidth);
	} else {
		borderWidth = 0;
	}
	loadPointfrom(((int *) (workBuffer + 80)), startOop);
	loadPointfrom(((int *) (workBuffer + 84)), endOop);
	if (interpreterProxy->failed()) {
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
	if (!(interpreterProxy->failed())) {
		workBuffer[63] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(5);
	}
}


/*	Note: No need to load either bitBlt or spanBuffer */

EXPORT(int) primitiveChangedActiveEdgeEntry(void) {
    int edge;
    int edgeOop;
    int value;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	edgeOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 7))) {
		return interpreterProxy->primitiveFail();
	}
	edge = loadEdgeStateFrom(edgeOop);
	if (interpreterProxy->failed()) {
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
	interpreterProxy->pop(1);
	if (doProfileStats) {
		workBuffer[107] = ((workBuffer[107]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[106] = ((workBuffer[106]) + value);
	}
}

EXPORT(int) primitiveCopyBuffer(void) {
    int diff;
    int buf1;
    int buf2;
    int * src;
    int * dst;
    int i;

	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	buf2 = interpreterProxy->stackObjectValue(0);
	buf1 = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(loadWorkBufferFrom(buf1))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->fetchClassOf(buf1)) == (interpreterProxy->fetchClassOf(buf2)))) {
		return interpreterProxy->primitiveFail();
	}
	diff = (interpreterProxy->slotSizeOf(buf2)) - (interpreterProxy->slotSizeOf(buf1));
	if (diff < 0) {
		return interpreterProxy->primitiveFail();
	}
	src = workBuffer;
	dst = interpreterProxy->firstIndexableField(buf2);
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
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
}


/*	Note: Must load bitBlt and spanBuffer */

EXPORT(int) primitiveDisplaySpanBuffer(void) {
    int value;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 5))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(1, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadBitBltFrom(interpreterProxy->fetchPointerofObject(2, engine)))) {
		return interpreterProxy->primitiveFail();
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
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[102] = ((workBuffer[102]) + value);
	}
}


/*	Turn on/off profiling. Return the old value of the flag. */

EXPORT(int) primitiveDoProfileStats(void) {
    int oldValue;
    int newValue;

	oldValue = doProfileStats;
	newValue = interpreterProxy->stackObjectValue(0);
	newValue = interpreterProxy->booleanValueOf(newValue);
	if (!(interpreterProxy->failed())) {
		doProfileStats = newValue;
		interpreterProxy->pop(2);
		interpreterProxy->pushBool(oldValue);
	}
}

EXPORT(int) primitiveFinishedProcessing(void) {
    int finished;
    int value;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	finished = (workBuffer[2]) == 8;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(finished);
	if (doProfileStats) {
		workBuffer[93] = ((workBuffer[93]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[92] = ((workBuffer[92]) + value);
	}
}

EXPORT(int) primitiveGetAALevel(void) {
	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(workBuffer[48]);
}

EXPORT(int) primitiveGetBezierStats(void) {
    int *stats;
    int statOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	statOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isWords(statOop))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(statOop)) < 4) {
		return interpreterProxy->primitiveFail();
	}
	stats = interpreterProxy->firstIndexableField(statOop);
	stats[0] = ((stats[0]) + (workBuffer[108]));
	stats[1] = ((stats[1]) + (workBuffer[109]));
	stats[2] = ((stats[2]) + (workBuffer[110]));
	stats[3] = ((stats[3]) + (workBuffer[111]));
	interpreterProxy->pop(1);
}

EXPORT(int) primitiveGetClipRect(void) {
    int pointOop;
    int rectOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	rectOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isPointers(rectOop))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(rectOop)) < 2) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pushRemappableOop(rectOop);
	pointOop = interpreterProxy->makePointwithxValueyValue(workBuffer[42], workBuffer[44]);
	rectOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, rectOop, pointOop);
	interpreterProxy->pushRemappableOop(rectOop);
	pointOop = interpreterProxy->makePointwithxValueyValue(workBuffer[43], workBuffer[45]);
	rectOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(1, rectOop, pointOop);
	interpreterProxy->pop(2);
	interpreterProxy->push(rectOop);
}

EXPORT(int) primitiveGetCounts(void) {
    int *stats;
    int statOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	statOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isWords(statOop))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(statOop)) < 9) {
		return interpreterProxy->primitiveFail();
	}
	stats = interpreterProxy->firstIndexableField(statOop);
	stats[0] = ((stats[0]) + (workBuffer[91]));
	stats[1] = ((stats[1]) + (workBuffer[93]));
	stats[2] = ((stats[2]) + (workBuffer[95]));
	stats[3] = ((stats[3]) + (workBuffer[97]));
	stats[4] = ((stats[4]) + (workBuffer[99]));
	stats[5] = ((stats[5]) + (workBuffer[101]));
	stats[6] = ((stats[6]) + (workBuffer[103]));
	stats[7] = ((stats[7]) + (workBuffer[105]));
	stats[8] = ((stats[8]) + (workBuffer[107]));
	interpreterProxy->pop(1);
}

EXPORT(int) primitiveGetDepth(void) {
	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(workBuffer[113]);
}


/*	Return the reason why the last operation failed. */

EXPORT(int) primitiveGetFailureReason(void) {
	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if ((engine & 1)) {
		return 0;
	}
	if (!(interpreterProxy->isPointers(engine))) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(engine)) < 12) {
		return 0;
	}
	if (!(loadWorkBufferFrom(interpreterProxy->fetchPointerofObject(0, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(workBuffer[64]);
}

EXPORT(int) primitiveGetOffset(void) {
    int pointOop;

	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	pointOop = interpreterProxy->makePointwithxValueyValue(workBuffer[46], workBuffer[47]);
	interpreterProxy->pop(1);
	interpreterProxy->push(pointOop);
}

EXPORT(int) primitiveGetTimes(void) {
    int *stats;
    int statOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	statOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isWords(statOop))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(statOop)) < 9) {
		return interpreterProxy->primitiveFail();
	}
	stats = interpreterProxy->firstIndexableField(statOop);
	stats[0] = ((stats[0]) + (workBuffer[90]));
	stats[1] = ((stats[1]) + (workBuffer[92]));
	stats[2] = ((stats[2]) + (workBuffer[94]));
	stats[3] = ((stats[3]) + (workBuffer[96]));
	stats[4] = ((stats[4]) + (workBuffer[98]));
	stats[5] = ((stats[5]) + (workBuffer[100]));
	stats[6] = ((stats[6]) + (workBuffer[102]));
	stats[7] = ((stats[7]) + (workBuffer[104]));
	stats[8] = ((stats[8]) + (workBuffer[106]));
	interpreterProxy->pop(1);
}

EXPORT(int) primitiveInitializeBuffer(void) {
    int size;
    int wbOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	wbOop = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(wbOop))) {
		return interpreterProxy->primitiveFail();
	}
	if ((size = interpreterProxy->slotSizeOf(wbOop)) < 256) {
		return interpreterProxy->primitiveFail();
	}
	workBuffer = interpreterProxy->firstIndexableField(wbOop);
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
	interpreterProxy->pop(2);
	interpreterProxy->push(wbOop);
}


/*	Note: No need to load bitBlt but must load spanBuffer */

EXPORT(int) primitiveInitializeProcessing(void) {
    int value;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(1, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	initializeGETProcessing();
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	workBuffer[2] = 1;
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
	}
	if (doProfileStats) {
		workBuffer[91] = ((workBuffer[91]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[90] = ((workBuffer[90]) + value);
	}
}


/*	Note: No need to load bitBlt but must load spanBuffer */

EXPORT(int) primitiveMergeFillFrom(void) {
    int bitsOop;
    int value;
    int fillOop;
    int value1;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	fillOop = interpreterProxy->stackObjectValue(0);
	bitsOop = interpreterProxy->stackObjectValue(1);
	engine = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 4))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(1, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->fetchClassOf(bitsOop)) == (interpreterProxy->classBitmap()))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(fillOop)) < 6) {
		return interpreterProxy->primitiveFail();
	}
	value = interpreterProxy->fetchIntegerofObject(0, fillOop);
	if (!((objBuffer[(workBuffer[66]) + 2]) == value)) {
		return interpreterProxy->primitiveFail();
	}
	value = interpreterProxy->fetchIntegerofObject(1, fillOop);
	if (!((workBuffer[67]) == value)) {
		return interpreterProxy->primitiveFail();
	}
	value = interpreterProxy->fetchIntegerofObject(2, fillOop);
	if (!((workBuffer[68]) == value)) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(bitsOop)) < ((workBuffer[68]) - (workBuffer[67]))) {
		return interpreterProxy->primitiveFail();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	fillBitmapSpanfromto(interpreterProxy->firstIndexableField(bitsOop), workBuffer[67], workBuffer[68]);
	workBuffer[2] = 3;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	interpreterProxy->pop(2);
	if (doProfileStats) {
		workBuffer[101] = ((workBuffer[101]) + 1);
		/* begin incrementStat:by: */
		value1 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[100] = ((workBuffer[100]) + value1);
	}
}

EXPORT(int) primitiveNeedsFlush(void) {
    int needFlush;

	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	engine = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	needFlush = (workBuffer[63]) != 0;
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(needFlush);
}

EXPORT(int) primitiveNeedsFlushPut(void) {
    int needFlush;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	needFlush = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	needFlush = interpreterProxy->booleanValueOf(needFlush);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFrom(engine))) {
		return interpreterProxy->primitiveFail();
	}
	if (needFlush == 1) {
		workBuffer[63] = 1;
	} else {
		workBuffer[63] = 0;
	}
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	interpreterProxy->pop(1);
}


/*	Note: No need to load either bitBlt or spanBuffer */

EXPORT(int) primitiveNextActiveEdgeEntry(void) {
    int edge;
    int edgeOop;
    int hasEdge;
    int value;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	edgeOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredStateor(engine, 6, 8))) {
		return interpreterProxy->primitiveFail();
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
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	interpreterProxy->pop(2);
	interpreterProxy->pushBool(!hasEdge);
	if (doProfileStats) {
		workBuffer[105] = ((workBuffer[105]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[104] = ((workBuffer[104]) + value);
	}
}


/*	Note: No need to load bitBlt but must load spanBuffer */

EXPORT(int) primitiveNextFillEntry(void) {
    int hasFill;
    int fillOop;
    int value;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	fillOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 3))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(1, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadFormsFrom(interpreterProxy->fetchPointerofObject(3, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((workBuffer[69]) == 0)) {
		if (((workBuffer[88]) & (workBuffer[52])) == 0) {
			clearSpanBuffer();
		}
		workBuffer[69] = 0;
	}
	hasFill = findNextExternalFillFromAET();
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (hasFill) {
		storeFillStateInto(fillOop);
	}
	if (!(interpreterProxy->failed())) {
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
		interpreterProxy->pop(2);
		interpreterProxy->pushBool(!hasFill);
		if (doProfileStats) {
			workBuffer[99] = ((workBuffer[99]) + 1);
			/* begin incrementStat:by: */
			value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[98] = ((workBuffer[98]) + value);
		}
	}
}


/*	Note: No need to load either bitBlt or spanBuffer */

EXPORT(int) primitiveNextGlobalEdgeEntry(void) {
    int edge;
    int edgeOop;
    int hasEdge;
    int value;

	if (doProfileStats) {
		geProfileTime = interpreterProxy->ioMicroMSecs();
	}
	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	edgeOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 1))) {
		return interpreterProxy->primitiveFail();
	}
	hasEdge = findNextExternalEntryFromGET();
	if (hasEdge) {
		edge = getBuffer[workBuffer[11]];
		storeEdgeStateFrominto(edge, edgeOop);
		workBuffer[11] = ((workBuffer[11]) + 1);
	}
	if (interpreterProxy->failed()) {
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
	interpreterProxy->pop(2);
	interpreterProxy->pushBool(!hasEdge);
	if (doProfileStats) {
		workBuffer[95] = ((workBuffer[95]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[94] = ((workBuffer[94]) + value);
	}
}

EXPORT(int) primitiveRegisterExternalEdge(void) {
    int index;
    int edge;
    int rightFillIndex;
    int initialY;
    int initialX;
    int leftFillIndex;
    int initialZ;
    int value;
    int value1;

	if (!((interpreterProxy->methodArgumentCount()) == 6)) {
		return interpreterProxy->primitiveFail();
	}
	rightFillIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	leftFillIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(1));
	initialZ = interpreterProxy->stackIntegerValue(2);
	initialY = interpreterProxy->stackIntegerValue(3);
	initialX = interpreterProxy->stackIntegerValue(4);
	index = interpreterProxy->stackIntegerValue(5);
	engine = interpreterProxy->stackObjectValue(6);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(allocateObjEntry(10))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(isFillOkay(leftFillIndex))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(isFillOkay(rightFillIndex))) {
		return interpreterProxy->primitiveFail();
	}
	edge = objUsed;

	/* Install type and length */

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
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(6);
	}
}

EXPORT(int) primitiveRegisterExternalFill(void) {
    int fill;
    int index;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	index = interpreterProxy->stackIntegerValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	fill = 0;
	while (fill == 0) {
		if (!(allocateObjEntry(10))) {
			return interpreterProxy->primitiveFail();
		}
		fill = objUsed;

		/* Install type and length */

		objUsed = fill + 4;
		objBuffer[fill + 0] = 256;
		objBuffer[fill + 1] = 4;
		objBuffer[fill + 2] = index;
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(fill);
	}
}


/*	Start/Proceed rendering the entire image */

EXPORT(int) primitiveRenderImage(void) {
	if (!(loadRenderingState())) {
		return interpreterProxy->primitiveFail();
	}
	proceedRenderingScanline();
	if (engineStopped) {
		return storeRenderingState();
	}
	proceedRenderingImage();
	storeRenderingState();
}


/*	Start rendering the entire image */

EXPORT(int) primitiveRenderScanline(void) {
	if (!(loadRenderingState())) {
		return interpreterProxy->primitiveFail();
	}
	proceedRenderingScanline();
	storeRenderingState();
}

EXPORT(int) primitiveSetAALevel(void) {
    int level;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	level = interpreterProxy->stackIntegerValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	setAALevel(level);
	/* begin storeEngineStateInto: */
	workBuffer[9] = objUsed;
	interpreterProxy->pop(1);
}


/*	Primitive. Set the BitBlt plugin to use. */

EXPORT(int) primitiveSetBitBltPlugin(void) {
    int length;
    char *ptr;
    int pluginName;
    int i;
    int needReload;


	/* Must be string to work */

	pluginName = interpreterProxy->stackValue(0);
	if (!(interpreterProxy->isBytes(pluginName))) {
		return interpreterProxy->primitiveFail();
	}
	length = interpreterProxy->byteSizeOf(pluginName);
	if (length >= 256) {
		return interpreterProxy->primitiveFail();
	}
	ptr = interpreterProxy->firstIndexableField(pluginName);
	needReload = 0;
	for (i = 0; i <= (length - 1); i += 1) {
		if (!((bbPluginName[i]) == (ptr[i]))) {
			bbPluginName[i] = (ptr[i]);
			needReload = 1;
		}
	}
	if (!((bbPluginName[length]) == 0)) {
		bbPluginName[length] = 0;
		needReload = 1;
	}
	if (needReload) {
		if (!(initialiseModule())) {
			return interpreterProxy->primitiveFail();
		}
	}
	interpreterProxy->pop(1);
}

EXPORT(int) primitiveSetClipRect(void) {
    int rectOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	rectOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isPointers(rectOop))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(rectOop)) < 2) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + 80)), interpreterProxy->fetchPointerofObject(0, rectOop));
	loadPointfrom(((int *) (workBuffer + 82)), interpreterProxy->fetchPointerofObject(1, rectOop));
	if (!(interpreterProxy->failed())) {
		workBuffer[42] = ((((int *) (workBuffer + 80)))[0]);
		workBuffer[44] = ((((int *) (workBuffer + 80)))[1]);
		workBuffer[43] = ((((int *) (workBuffer + 82)))[0]);
		workBuffer[45] = ((((int *) (workBuffer + 82)))[1]);
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(1);
	}
}

EXPORT(int) primitiveSetColorTransform(void) {
    int transformOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	transformOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	loadColorTransformFrom(transformOop);
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(1);
	}
}

EXPORT(int) primitiveSetDepth(void) {
    int depth;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	depth = interpreterProxy->stackIntegerValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	workBuffer[113] = depth;
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(1);
	}
}

EXPORT(int) primitiveSetEdgeTransform(void) {
    int transformOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	transformOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	loadEdgeTransformFrom(transformOop);
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(1);
	}
}

EXPORT(int) primitiveSetOffset(void) {
    int pointOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	pointOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, 0))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->fetchClassOf(pointOop)) == (interpreterProxy->classPoint()))) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + 80)), pointOop);
	if (!(interpreterProxy->failed())) {
		workBuffer[46] = ((((int *) (workBuffer + 80)))[0]);
		workBuffer[47] = ((((int *) (workBuffer + 80)))[1]);
		/* begin storeEngineStateInto: */
		workBuffer[9] = objUsed;
		interpreterProxy->pop(1);
	}
}


/*	This is the main rendering entry */

static int proceedRenderingImage(void) {
    int external;
    int value;
    int value1;
    int value2;
    int value3;

	while (!((workBuffer[2]) == 8)) {
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		external = findNextExternalEntryFromGET();
		if (doProfileStats) {
			workBuffer[95] = ((workBuffer[95]) + 1);
			/* begin incrementStat:by: */
			value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
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
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		if (((workBuffer[69]) != 0) && (((workBuffer[88]) & (workBuffer[52])) == 0)) {
			clearSpanBuffer();
		}
		workBuffer[69] = 0;
		external = findNextExternalFillFromAET();
		if (doProfileStats) {
			workBuffer[99] = ((workBuffer[99]) + 1);
			/* begin incrementStat:by: */
			value1 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
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
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		if (((workBuffer[88]) & (workBuffer[52])) == (workBuffer[52])) {
			displaySpanBufferAt(workBuffer[88]);
			postDisplayAction();
		}
		if (doProfileStats) {
			workBuffer[103] = ((workBuffer[103]) + 1);
			/* begin incrementStat:by: */
			value2 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
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
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		external = findNextExternalUpdateFromAET();
		if (doProfileStats) {
			workBuffer[105] = ((workBuffer[105]) + 1);
			/* begin incrementStat:by: */
			value3 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
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


/*	Proceed rendering the current scan line.
	This method may be called after some Smalltalk code has been executed inbetween. */
/*	This is the main rendering entry */

static int proceedRenderingScanline(void) {
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
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		external = findNextExternalEntryFromGET();
		if (doProfileStats) {
			workBuffer[95] = ((workBuffer[95]) + 1);
			/* begin incrementStat:by: */
			value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
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
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		if (((workBuffer[69]) != 0) && (((workBuffer[88]) & (workBuffer[52])) == 0)) {
			clearSpanBuffer();
		}
		workBuffer[69] = 0;
		external = findNextExternalFillFromAET();
		if (doProfileStats) {
			workBuffer[99] = ((workBuffer[99]) + 1);
			/* begin incrementStat:by: */
			value1 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
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
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		if (((workBuffer[88]) & (workBuffer[52])) == (workBuffer[52])) {
			displaySpanBufferAt(workBuffer[88]);
			postDisplayAction();
		}
		if (doProfileStats) {
			workBuffer[103] = ((workBuffer[103]) + 1);
			/* begin incrementStat:by: */
			value2 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
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
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		external = findNextExternalUpdateFromAET();
		if (doProfileStats) {
			workBuffer[105] = ((workBuffer[105]) + 1);
			/* begin incrementStat:by: */
			value3 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
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


/*	Load the minimal required state from the engineOop, e.g., just the work buffer. */

static int quickLoadEngineFrom(int engineOop) {
	if (interpreterProxy->failed()) {
		return 0;
	}
	if ((engineOop & 1)) {
		return 0;
	}
	if (!(interpreterProxy->isPointers(engineOop))) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(engineOop)) < 12) {
		return 0;
	}
	engine = engineOop;
	if (!(loadWorkBufferFrom(interpreterProxy->fetchPointerofObject(0, engineOop)))) {
		return 0;
	}
	workBuffer[64] = 0;
	objUsed = workBuffer[9];
	engineStopped = 0;
	return 1;
}

static int quickLoadEngineFromrequiredState(int oop, int requiredState) {
	if (!(quickLoadEngineFrom(oop))) {
		return 0;
	}
	if ((workBuffer[2]) == requiredState) {
		return 1;
	}
	workBuffer[64] = 2;
	return 0;
}

static int quickLoadEngineFromrequiredStateor(int oop, int requiredState, int alternativeState) {
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


/*	Remove any top fills if they have become invalid. */

static int quickRemoveInvalidFillsAt(int leftX) {
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		return null;
	}
	while ((topRightX()) <= leftX) {
		hideFilldepth(topFill(), topDepth());
		if (((workBuffer[1]) - (workBuffer[10])) == 0) {
			return null;
		}
	}
}


/*	Sort elements i through j of self to be nondescending according to
	sortBlock. */
/*	Note: The original loop has been heavily re-written for C translation */

static int quickSortGlobalEdgeTablefromto(int *array, int i, int j) {
    int before;
    int k;
    int l;
    int di;
    int ij;
    int dj;
    int n;
    int tmp;
    int tt;
    int again;
    int dij;

	if ((n = (j + 1) - i) <= 1) {
		return 0;
	}
	di = array[i];
	dj = array[j];

	/* i.e., should di precede dj? */

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

	/* ij is the midpoint of i and j. */

	ij = ((int) (i + j) >> 1);

	/* Sort di,dij,dj.  Make dij be their median. */

	dij = array[ij];

	/* i.e. should di precede dij? */

	before = getSortsbefore(di, dij);
	if (before) {

		/* i.e., should dij precede dj? */

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

static int * rShiftTable(void) {
    static int theTable[17] =
		{0, 5, 4, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1};

	return theTable;
}

static int removeFirstAETEntry(void) {
    int index;

	index = workBuffer[13];
	workBuffer[14] = ((workBuffer[14]) - 1);
	while (index < (workBuffer[14])) {
		aetBuffer[index] = (aetBuffer[index + 1]);
		index += 1;
	}
}

static int repeatValuemax(int delta, int maxValue) {
    int newDelta;

	newDelta = delta;
	while (newDelta < 0) {
		newDelta += maxValue;
	}
	while (newDelta >= maxValue) {
		newDelta -= maxValue;
	}
	return newDelta;
}

static int resetGraphicsEngineStats(void) {
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

static int resortFirstAETEntry(void) {
    int edge;
    int leftEdge;
    int xValue;

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

static int returnWideBezierFill(void) {
	return dispatchReturnValue = objBuffer[dispatchedValue + 16];
}

static int returnWideBezierWidth(void) {
	return dispatchReturnValue = objBuffer[dispatchedValue + 17];
}


/*	Return the fill of the (wide) line - this method is called from a case. */

static int returnWideLineFill(void) {
	return dispatchReturnValue = objBuffer[dispatchedValue + 16];
}


/*	Return the width of the (wide) line - this method is called from a case. */

static int returnWideLineWidth(void) {
	return dispatchReturnValue = objBuffer[dispatchedValue + 17];
}


/*	Set the anti-aliasing level. Three levels are supported:
		1 - No antialiasing
		2 - 2x2 unweighted anti-aliasing
		4 - 4x4 unweighted anti-aliasing.
	 */

static int setAALevel(int level) {
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


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(int) setInterpreter(struct VirtualMachine* anInterpreter) {
    int ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}


/*	Return the run-length value from the given ShortRunArray. */

static int shortRunLengthAtfrom(int i, int runArray) {
	return ((unsigned) ((((int *) runArray))[i]) >> 16);
}


/*	Return the run-length value from the given ShortRunArray.
	Note: We don't need any coercion to short/int here, since
	we deal basically only with unsigned values. */

static int shortRunValueAtfrom(int i, int runArray) {
	return ((((int *) runArray))[i]) & 65535;
}

static int showFilldepthrightX(int fillIndex, int depth, int rightX) {
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

static int * smallSqrtTable(void) {
    static int theTable[32] = 
	{0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6};

	return theTable;
}


/*	Sort the entire global edge table */

static int sortGlobalEdgeTable(void) {
	quickSortGlobalEdgeTablefromto(getBuffer, 0, (workBuffer[12]) - 1);
}

static int spanEndAAGet(void) {
	return workBuffer[35];
}

static int spanEndAAPut(int value) {
	return workBuffer[35] = value;
}

static int spanEndGet(void) {
	return workBuffer[34];
}

static int spanEndPut(int value) {
	return workBuffer[34] = value;
}

static int spanSizeGet(void) {
	return workBuffer[33];
}

static int spanSizePut(int value) {
	return workBuffer[33] = value;
}

static int spanStartGet(void) {
	return workBuffer[32];
}

static int spanStartPut(int value) {
	return workBuffer[32] = value;
}

static int squaredLengthOfwith(int deltaX, int deltaY) {
	return (deltaX * deltaX) + (deltaY * deltaY);
}

static int stackFillDepth(int index) {
	return workBuffer[(workBuffer[10]) + (index + 1)];
}

static int stackFillDepthput(int index, int value) {
	return workBuffer[(workBuffer[10]) + (index + 1)] = value;
}

static int stackFillEntryLength(void) {
	return 3;
}

static int stackFillRightX(int index) {
	return workBuffer[(workBuffer[10]) + (index + 2)];
}

static int stackFillRightXput(int index, int value) {
	return workBuffer[(workBuffer[10]) + (index + 2)] = value;
}

static int stackFillSize(void) {
	return (workBuffer[1]) - (workBuffer[10]);
}

static int stackFillValue(int index) {
	return workBuffer[(workBuffer[10]) + index];
}

static int stackFillValueput(int index, int value) {
	return workBuffer[(workBuffer[10]) + index] = value;
}

static int stateGet(void) {
	return workBuffer[2];
}

static int statePut(int value) {
	return workBuffer[2] = value;
}


/*	Initialize the current entry in the GET by stepping to the current scan line */

static int stepToFirstBezier(void) {
	return stepToFirstBezierInat(getBuffer[workBuffer[11]], workBuffer[88]);
}


/*	Initialize the bezier at yValue.
	TODO: Check if reducing maxSteps from 2*deltaY to deltaY 
		brings a *significant* performance improvement.
		In theory this should make for double step performance
		but will cost in quality. Might be that the AA stuff will
		compensate for this - but I'm not really sure. */

static int stepToFirstBezierInat(int bezier, int yValue) {
    int squaredStepSize;
    int *updateData;
    int fwY1;
    int fwY2;
    int endX;
    int endY;
    int fwX1;
    int fwDDx;
    int fwX2;
    int fwDDy;
    int fwDx;
    int startX;
    int startY;
    int fwDy;
    int maxSteps;
    int scaledStepSize;
    int deltaY;
    int viaX;
    int viaY;
    int xValue;
    int minY;
    int fwDx1;
    int fwDy1;
    int lastX;
    int lastY;
    int word1;
    int word2;

	if ((!((((objBuffer[bezier + 0]) & 65535) & 1) != 0)) && (yValue >= (objBuffer[bezier + 15]))) {
		return objBuffer[bezier + 7] = 0;
	}
	startX = objBuffer[bezier + 4];
	startY = objBuffer[bezier + 5];
	viaX = objBuffer[bezier + 12];
	viaY = objBuffer[bezier + 13];
	endX = objBuffer[bezier + 14];
	endY = objBuffer[bezier + 15];

	/* Initialize integer forward differencing */

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

	/* Store the values */

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


/*	Initialize the current entry in the GET by stepping to the current scan line */

static int stepToFirstLine(void) {
	return stepToFirstLineInat(getBuffer[workBuffer[11]], workBuffer[88]);
}


/*	Initialize the line at yValue */

static int stepToFirstLineInat(int line, int yValue) {
    int error;
    int xDir;
    int i;
    int errorAdjUp;
    int startY;
    int widthX;
    int deltaX;
    int deltaY;
    int xInc;
    int x;
    int err;

	if ((!((((objBuffer[line + 0]) & 65535) & 1) != 0)) && (yValue >= (objBuffer[line + 15]))) {
		return objBuffer[line + 7] = 0;
	}
	deltaX = (objBuffer[line + 14]) - (objBuffer[line + 4]);

	/* Check if edge goes left to right */

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

		/* No error for horizontal edges */

		error = 0;

		/* Encodes width and direction */

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


/*	Initialize the current entry in the GET by stepping to the current scan line */

static int stepToFirstWideBezier(void) {
	return stepToFirstWideBezierInat(getBuffer[workBuffer[11]], workBuffer[88]);
}


/*	Initialize the bezier at yValue */

static int stepToFirstWideBezierInat(int bezier, int yValue) {
    int lineOffset;
    int nLines;
    int lineWidth;
    int xDir;
    int i;
    int endX;
    int yExit;
    int startY;
    int yEntry;

	lineWidth = objBuffer[bezier + 20];

	/* Compute the incremental values of the bezier */

	lineOffset = ((int) lineWidth >> 1);
	endX = objBuffer[bezier + 14];
	startY = objBuffer[bezier + 5];
	stepToFirstBezierInat(bezier, startY);

	/* Copy the incremental update data */

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

	/* turned on at lineOffset */

	yEntry = 0;

	/* turned off at zero */

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


/*	Initialize the current entry in the GET by stepping to the current scan line */

static int stepToFirstWideLine(void) {
	return stepToFirstWideLineInat(getBuffer[workBuffer[11]], workBuffer[88]);
}


/*	Initialize the wide line at yValue. */

static int stepToFirstWideLineInat(int line, int yValue) {
    int lineOffset;
    int nLines;
    int lineWidth;
    int xDir;
    int i;
    int yExit;
    int startX;
    int startY;
    int yEntry;
    int lineOffset1;
    int yExit1;
    int nextX;
    int lineWidth1;
    int lastX;
    int yEntry1;
    int x;
    int err;

	lineWidth = objBuffer[line + 20];

	/* Compute the incremental values of the line */

	lineOffset = ((int) lineWidth >> 1);
	startX = objBuffer[line + 4];
	startY = objBuffer[line + 5];
	stepToFirstLineInat(line, startY);
	nLines = objBuffer[line + 7];

	/* Adjust the line to start at the correct X position */

	xDir = objBuffer[line + 10];
	objBuffer[line + 4] = (startX - lineOffset);
	objBuffer[line + 7] = (nLines + lineWidth);
	if (xDir > 0) {
		objBuffer[line + 17] = ((objBuffer[line + 12]) + lineWidth);
	} else {
		objBuffer[line + 17] = (lineWidth - (objBuffer[line + 12]));
		objBuffer[line + 4] = ((objBuffer[line + 4]) + (objBuffer[line + 12]));
	}

	/* turned on at lineOffset */

	yEntry = 0;

	/* turned off at zero */

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


/*	Process the current entry in the AET by stepping to the next scan line */

static int stepToNextBezier(void) {
    int xValue;
    int minY;
    int fwDx;
    int fwDy;
    int lastX;
    int lastY;

	/* begin stepToNextBezierIn:at: */
	/* begin stepToNextBezierForward:at: */
	lastX = (((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[0];
	lastY = (((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[1];
	fwDx = (((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[2];
	fwDy = (((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[3];
	minY = (workBuffer[88]) * 256;
	while ((minY > lastY) && (fwDy >= 0)) {
		lastX += ((int) (fwDx + 32768) >> 16);
		lastY += ((int) (fwDy + 32768) >> 16);
		fwDx += (((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[4];
		fwDy += (((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[5];
	}
	(((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[0] = lastX;
	(((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[1] = lastY;
	(((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[2] = fwDx;
	(((int*) ((objBuffer + (aetBuffer[workBuffer[13]])) + 10)))[3] = fwDy;
	xValue = ((int) lastX >> 8);
	objBuffer[(aetBuffer[workBuffer[13]]) + 4] = xValue;
	return null;
}


/*	Incrementally step to the next scan line in the given bezier update data.
	Note: This method has been written so that inlining works, e.g.,
		not declaring updateData as 'int*' but casting it on every use. */

static int stepToNextBezierForwardat(int updateData, int yValue) {
    int minY;
    int fwDx;
    int fwDy;
    int lastX;
    int lastY;

	lastX = (((int*) updateData))[0];
	lastY = (((int*) updateData))[1];
	fwDx = (((int*) updateData))[2];
	fwDy = (((int*) updateData))[3];

	/* Step as long as we haven't yet reached minY and also
	as long as fwDy is greater than zero thus stepping down.
	Note: The test for fwDy should not be necessary in theory
		but is a good insurance in practice. */

	minY = yValue * 256;
	while ((minY > lastY) && (fwDy >= 0)) {
		lastX += ((int) (fwDx + 32768) >> 16);
		lastY += ((int) (fwDy + 32768) >> 16);
		fwDx += (((int*) updateData))[4];
		fwDy += (((int*) updateData))[5];
	}
	(((int*) updateData))[0] = lastX;
	(((int*) updateData))[1] = lastY;
	(((int*) updateData))[2] = fwDx;
	(((int*) updateData))[3] = fwDy;
	return ((int) lastX >> 8);
}


/*	Incrementally step to the next scan line in the given bezier */

static int stepToNextBezierInat(int bezier, int yValue) {
    int xValue;
    int minY;
    int fwDx;
    int fwDy;
    int lastX;
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


/*	Process the current entry in the AET by stepping to the next scan line */

static int stepToNextLine(void) {
    int x;
    int err;

	/* begin stepToNextLineIn:at: */
	x = (objBuffer[(aetBuffer[workBuffer[13]]) + 4]) + (objBuffer[(aetBuffer[workBuffer[13]]) + 12]);
	err = (objBuffer[(aetBuffer[workBuffer[13]]) + 13]) + (objBuffer[(aetBuffer[workBuffer[13]]) + 14]);
	if (err > 0) {
		x += objBuffer[(aetBuffer[workBuffer[13]]) + 10];
		err -= objBuffer[(aetBuffer[workBuffer[13]]) + 15];
	}
	objBuffer[(aetBuffer[workBuffer[13]]) + 13] = err;
	objBuffer[(aetBuffer[workBuffer[13]]) + 4] = x;
	return null;
}


/*	Incrementally step to the next scan line in the given line */

static int stepToNextLineInat(int line, int yValue) {
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


/*	Initialize the current entry in the GET by stepping to the current scan line */

static int stepToNextWideBezier(void) {
	stepToNextWideBezierInat(aetBuffer[workBuffer[13]], workBuffer[88]);
}


/*	Incrementally step to the next scan line in the given wide bezier */

static int stepToNextWideBezierInat(int bezier, int yValue) {
    int lineOffset;
    int yExit;
    int lineWidth;
    int yEntry;
    int minY;
    int fwDx;
    int fwDy;
    int lastX;
    int lastY;
    int minY1;
    int fwDx1;
    int fwDy1;
    int lastX1;
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


/*	Process the current entry in the AET by stepping to the next scan line */

static int stepToNextWideLine(void) {
    int line;
    int yValue;
    int lineOffset;
    int yExit;
    int nextX;
    int lineWidth;
    int lastX;
    int yEntry;
    int x;
    int err;

	/* begin stepToNextWideLineIn:at: */
	line = aetBuffer[workBuffer[13]];
	yValue = workBuffer[88];
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
	return null;
}


/*	Incrementally step to the next scan line in the given wide line */

static int stepToNextWideLineInat(int line, int yValue) {
    int lineOffset;
    int yExit;
    int nextX;
    int lineWidth;
    int lastX;
    int yEntry;
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

	/* Check for special start/end adjustments */

	nextX = objBuffer[line + 4];
	if ((yEntry <= lineWidth) || ((yExit + lineOffset) >= 0)) {
		adjustWideLineafterSteppingFromto(line, lastX, nextX);
	}
}

static int stopBecauseOf(int stopReason) {
	workBuffer[64] = stopReason;
	engineStopped = 1;
}

static int stopReasonGet(void) {
	return workBuffer[64];
}

static int stopReasonPut(int value) {
	return workBuffer[64] = value;
}

static int storeEdgeStateFrominto(int edge, int edgeOop) {
	if ((interpreterProxy->slotSizeOf(edgeOop)) < 6) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->storeIntegerofObjectwithValue(0, edgeOop, objBuffer[edge + 2]);
	interpreterProxy->storeIntegerofObjectwithValue(1, edgeOop, objBuffer[edge + 4]);
	interpreterProxy->storeIntegerofObjectwithValue(2, edgeOop, workBuffer[88]);
	interpreterProxy->storeIntegerofObjectwithValue(3, edgeOop, objBuffer[edge + 6]);
	interpreterProxy->storeIntegerofObjectwithValue(4, edgeOop, objBuffer[edge + 7]);
	workBuffer[65] = edge;
}

static int storeEngineStateInto(int oop) {
	workBuffer[9] = objUsed;
}

static int storeFillStateInto(int fillOop) {
    int leftX;
    int rightX;
    int fillIndex;

	fillIndex = workBuffer[66];
	leftX = workBuffer[67];
	rightX = workBuffer[68];
	if ((interpreterProxy->slotSizeOf(fillOop)) < 6) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->storeIntegerofObjectwithValue(0, fillOop, objBuffer[fillIndex + 2]);
	interpreterProxy->storeIntegerofObjectwithValue(1, fillOop, leftX);
	interpreterProxy->storeIntegerofObjectwithValue(2, fillOop, rightX);
	interpreterProxy->storeIntegerofObjectwithValue(3, fillOop, workBuffer[88]);
}

static int storeRenderingState(void) {
    int edgeOop;
    int fillOop;
    int edge;
    int reason;

	if (interpreterProxy->failed()) {
		return null;
	}
	if (engineStopped) {
		/* begin storeStopStateIntoEdge:fill: */
		edgeOop = interpreterProxy->stackObjectValue(1);
		fillOop = interpreterProxy->stackObjectValue(0);
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
	interpreterProxy->pop(3);
	interpreterProxy->pushInteger(workBuffer[64]);
}

static int storeStopStateIntoEdgefill(int edgeOop, int fillOop) {
    int edge;
    int reason;

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


/*	Subdivide the given bezier curve if necessary */

static int subdivideBezier(int index) {
    int startX;
    int startY;
    int deltaX;
    int deltaY;
    int endX;
    int endY;

	startY = workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - index) + 1)];

	/* If the receiver is horizontal, don't do anything */

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


/*	Recursively subdivide the curve on the bezier stack. */

static int subdivideBezierFrom(int index) {
    int index1;
    int otherIndex;
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


/*	Check if the given bezier curve is monoton in Y, and, if desired in X. 
	If not, subdivide it */

static int subdivideToBeMonotoninX(int base, int doTestX) {
    int base2;
    int index1;
    int index2;

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


/*	Check if the given bezier curve is monoton in X. If not, subdivide it */

static int subdivideToBeMonotonInX(int index) {
    int dx1;
    int dx2;
    int num;
    int startX;
    int denom;
    int viaX;
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


/*	Check if the given bezier curve is monoton in Y. If not, subdivide it */

static int subdivideToBeMonotonInY(int index) {
    int endY;
    int dy1;
    int num;
    int dy2;
    int startY;
    int denom;
    int viaY;

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


/*	Make the fill style with the given index either visible or invisible */

static int toggleFilldepthrightX(int fillIndex, int depth, int rightX) {
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

static int toggleFillsOf(int edge) {
    int depth;
    int fillIndex;
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

static int toggleWideFillOf(int edge) {
    int depth;
    int fill;
    int lineWidth;
    int rightX;
    int type;
    int index;
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

	/* So lines sort before interior fills */

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

static int topDepth(void) {
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		return -1;
	} else {
		return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)];
	}
}

static int topFill(void) {
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		return 0;
	} else {
		return workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
	}
}

static int topFillDepth(void) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)];
}

static int topFillDepthPut(int value) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 1)] = value;
}

static int topFillRightX(void) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
}

static int topFillRightXPut(int value) {
	return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)] = value;
}

static int topFillValue(void) {
	return workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)];
}

static int topFillValuePut(int value) {
	return workBuffer[(workBuffer[10]) + (((workBuffer[1]) - (workBuffer[10])) - 3)] = value;
}

static int topRightX(void) {
	if (((workBuffer[1]) - (workBuffer[10])) == 0) {
		return 999999999;
	} else {
		return workBuffer[(workBuffer[10]) + ((((workBuffer[1]) - (workBuffer[10])) - 3) + 2)];
	}
}

static int transformColor(int fillIndex) {
    float *transform;
    int g;
    int r;
    int b;
    int a;
    double alphaScale;

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


/*	Transform the given point. If haveMatrix is true then use the current transformation. */

static int transformPoint(int *point) {
	if ((workBuffer[16]) != 0) {
		/* begin transformPoint:into: */
		transformPointXyinto(((double) ((((int *) point))[0]) ), ((double) ((((int *) point))[1]) ), ((int *) point));
	} else {
		point[0] = (((point[0]) + (workBuffer[46])) * (workBuffer[48]));
		point[1] = (((point[1]) + (workBuffer[47])) * (workBuffer[48]));
	}
}


/*	Transform srcPoint into dstPoint by using the currently loaded matrix */
/*	Note: This method has been rewritten so that inlining works (e.g., removing
	the declarations and adding argument coercions at the appropriate points) */

static int transformPointinto(int srcPoint, int dstPoint) {
	transformPointXyinto(((double) ((((int *) srcPoint))[0]) ), ((double) ((((int *) srcPoint))[1]) ), ((int *) dstPoint));
}


/*	Transform srcPoint into dstPoint by using the currently loaded matrix */
/*	Note: This should be rewritten so that inlining works (e.g., removing
	the declarations and adding argument coercions at the appropriate points) */

static int transformPointXyinto(double xValue, double yValue, int *dstPoint) {
    float *transform;
    int x;
    int y;

	transform = ((float *) (workBuffer + 18));
	x = ((int) (((((transform[0]) * xValue) + ((transform[1]) * yValue)) + (transform[2])) * (((double) (workBuffer[48]) ))) );
	y = ((int) (((((transform[3]) * xValue) + ((transform[4]) * yValue)) + (transform[5])) * (((double) (workBuffer[48]) ))) );
	dstPoint[0] = x;
	dstPoint[1] = y;
}


/*	Transform n (n=1,2,3) points.
	If haveMatrix is true then the matrix contains the actual transformation. */

static int transformPoints(int n) {
	if (n > 0) {
		transformPoint(((int *) (workBuffer + 80)));
	}
	if (n > 1) {
		transformPoint(((int *) (workBuffer + 82)));
	}
	if (n > 2) {
		transformPoint(((int *) (workBuffer + 84)));
	}
	if (n > 3) {
		transformPoint(((int *) (workBuffer + 86)));
	}
}


/*	Transform the given width */

static int transformWidth(int w) {
    double deltaX;
    double deltaY;
    int dstWidth2;
    int dstWidth;

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
	dstWidth = ((int) ((((int) (sqrt((deltaX * deltaX) + (deltaY * deltaY))) )) + 128) >> 8);
	deltaX = ((double) (((((int *) (workBuffer + 84)))[0]) - ((((int *) (workBuffer + 80)))[0])) );
	deltaY = ((double) (((((int *) (workBuffer + 84)))[1]) - ((((int *) (workBuffer + 80)))[1])) );
	dstWidth2 = ((int) ((((int) (sqrt((deltaX * deltaX) + (deltaY * deltaY))) )) + 128) >> 8);
	if (dstWidth2 < dstWidth) {
		dstWidth = dstWidth2;
	}
	if (dstWidth == 0) {
		return 1;
	} else {
		return dstWidth;
	}
}

static int uncheckedTransformColor(int fillIndex) {
    float *transform;
    int g;
    int r;
    int b;
    int a;

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

static int wbSizeGet(void) {
	return workBuffer[1];
}

static int wbSizePut(int value) {
	return workBuffer[1] = value;
}

static int wbStackClear(void) {
	workBuffer[10] = (workBuffer[1]);
}

static int wbStackPop(int nItems) {
	workBuffer[10] = ((workBuffer[10]) + nItems);
}

static int wbStackPush(int nItems) {
	if (!(needAvailableSpace(nItems))) {
		return 0;
	}
	workBuffer[10] = ((workBuffer[10]) - nItems);
	return 1;
}

static int wbStackSize(void) {
	return (workBuffer[1]) - (workBuffer[10]);
}

static int wbStackValue(int index) {
	return workBuffer[(workBuffer[10]) + index];
}

static int wbStackValueput(int index, int value) {
	return workBuffer[(workBuffer[10]) + index] = value;
}

static int wbTopGet(void) {
	return workBuffer[10];
}

static int wbTopPut(int value) {
	return workBuffer[10] = value;
}

static int wideBezierEntryOf(int line) {
	return objBuffer[line + 18];
}

static int wideBezierEntryOfput(int line, int value) {
	return objBuffer[line + 18] = value;
}

static int wideBezierExitOf(int line) {
	return objBuffer[line + 19];
}

static int wideBezierExitOfput(int line, int value) {
	return objBuffer[line + 19] = value;
}

static int wideBezierExtentOf(int bezier) {
	return objBuffer[bezier + 20];
}

static int wideBezierExtentOfput(int bezier, int value) {
	return objBuffer[bezier + 20] = value;
}

static int wideBezierFillOf(int bezier) {
	return objBuffer[bezier + 16];
}

static int wideBezierFillOfput(int bezier, int value) {
	return objBuffer[bezier + 16] = value;
}

static int * wideBezierUpdateDataOf(int bezier) {
	return (objBuffer + bezier) + 22;
}

static int wideBezierWidthOf(int line) {
	return objBuffer[line + 17];
}

static int wideBezierWidthOfput(int line, int value) {
	return objBuffer[line + 17] = value;
}

static int wideLineEntryOf(int line) {
	return objBuffer[line + 18];
}

static int wideLineEntryOfput(int line, int value) {
	return objBuffer[line + 18] = value;
}

static int wideLineExitOf(int line) {
	return objBuffer[line + 19];
}

static int wideLineExitOfput(int line, int value) {
	return objBuffer[line + 19] = value;
}

static int wideLineExtentOf(int line) {
	return objBuffer[line + 20];
}

static int wideLineExtentOfput(int line, int value) {
	return objBuffer[line + 20] = value;
}

static int wideLineFillOf(int line) {
	return objBuffer[line + 16];
}

static int wideLineFillOfput(int line, int value) {
	return objBuffer[line + 16] = value;
}

static int wideLineWidthOf(int line) {
	return objBuffer[line + 17];
}

static int wideLineWidthOfput(int line, int value) {
	return objBuffer[line + 17] = value;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* B2DPlugin_exports[][3] = {
	{"B2DPlugin", "primitiveSetColorTransform", (void*)primitiveSetColorTransform},
	{"B2DPlugin", "primitiveDisplaySpanBuffer", (void*)primitiveDisplaySpanBuffer},
	{"B2DPlugin", "primitiveSetBitBltPlugin", (void*)primitiveSetBitBltPlugin},
	{"B2DPlugin", "primitiveSetEdgeTransform", (void*)primitiveSetEdgeTransform},
	{"B2DPlugin", "primitiveNextFillEntry", (void*)primitiveNextFillEntry},
	{"B2DPlugin", "primitiveAddActiveEdgeEntry", (void*)primitiveAddActiveEdgeEntry},
	{"B2DPlugin", "primitiveRenderImage", (void*)primitiveRenderImage},
	{"B2DPlugin", "primitiveInitializeProcessing", (void*)primitiveInitializeProcessing},
	{"B2DPlugin", "primitiveAddBitmapFill", (void*)primitiveAddBitmapFill},
	{"B2DPlugin", "primitiveNextActiveEdgeEntry", (void*)primitiveNextActiveEdgeEntry},
	{"B2DPlugin", "primitiveAddRect", (void*)primitiveAddRect},
	{"B2DPlugin", "primitiveChangedActiveEdgeEntry", (void*)primitiveChangedActiveEdgeEntry},
	{"B2DPlugin", "primitiveSetAALevel", (void*)primitiveSetAALevel},
	{"B2DPlugin", "primitiveFinishedProcessing", (void*)primitiveFinishedProcessing},
	{"B2DPlugin", "primitiveGetOffset", (void*)primitiveGetOffset},
	{"B2DPlugin", "primitiveSetDepth", (void*)primitiveSetDepth},
	{"B2DPlugin", "primitiveAddBezier", (void*)primitiveAddBezier},
	{"B2DPlugin", "primitiveGetCounts", (void*)primitiveGetCounts},
	{"B2DPlugin", "primitiveGetTimes", (void*)primitiveGetTimes},
	{"B2DPlugin", "primitiveNeedsFlushPut", (void*)primitiveNeedsFlushPut},
	{"B2DPlugin", "primitiveGetFailureReason", (void*)primitiveGetFailureReason},
	{"B2DPlugin", "primitiveGetDepth", (void*)primitiveGetDepth},
	{"B2DPlugin", "primitiveGetAALevel", (void*)primitiveGetAALevel},
	{"B2DPlugin", "primitiveGetBezierStats", (void*)primitiveGetBezierStats},
	{"B2DPlugin", "primitiveAbortProcessing", (void*)primitiveAbortProcessing},
	{"B2DPlugin", "primitiveAddPolygon", (void*)primitiveAddPolygon},
	{"B2DPlugin", "primitiveAddGradientFill", (void*)primitiveAddGradientFill},
	{"B2DPlugin", "primitiveSetOffset", (void*)primitiveSetOffset},
	{"B2DPlugin", "initialiseModule", (void*)initialiseModule},
	{"B2DPlugin", "primitiveMergeFillFrom", (void*)primitiveMergeFillFrom},
	{"B2DPlugin", "primitiveAddLine", (void*)primitiveAddLine},
	{"B2DPlugin", "getModuleName", (void*)getModuleName},
	{"B2DPlugin", "setInterpreter", (void*)setInterpreter},
	{"B2DPlugin", "primitiveSetClipRect", (void*)primitiveSetClipRect},
	{"B2DPlugin", "primitiveDoProfileStats", (void*)primitiveDoProfileStats},
	{"B2DPlugin", "primitiveInitializeBuffer", (void*)primitiveInitializeBuffer},
	{"B2DPlugin", "primitiveRegisterExternalEdge", (void*)primitiveRegisterExternalEdge},
	{"B2DPlugin", "primitiveGetClipRect", (void*)primitiveGetClipRect},
	{"B2DPlugin", "primitiveRegisterExternalFill", (void*)primitiveRegisterExternalFill},
	{"B2DPlugin", "primitiveAddOval", (void*)primitiveAddOval},
	{"B2DPlugin", "primitiveNeedsFlush", (void*)primitiveNeedsFlush},
	{"B2DPlugin", "primitiveAddCompressedShape", (void*)primitiveAddCompressedShape},
	{"B2DPlugin", "primitiveNextGlobalEdgeEntry", (void*)primitiveNextGlobalEdgeEntry},
	{"B2DPlugin", "primitiveCopyBuffer", (void*)primitiveCopyBuffer},
	{"B2DPlugin", "primitiveAddBezierShape", (void*)primitiveAddBezierShape},
	{"B2DPlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"B2DPlugin", "primitiveRenderScanline", (void*)primitiveRenderScanline},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

