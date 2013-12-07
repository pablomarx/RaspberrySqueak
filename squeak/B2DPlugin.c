/* Automatically generated from Squeak on an Array(10 April 2008 1:42:36 pm)
by VMMaker 3.8b6
 */

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

#include "sqMemoryAccess.h"


/*** Constants ***/
#define BEBalloonEngineSize 12
#define BEBitBltIndex 2
#define BEFormsIndex 3
#define BESpanIndex 1
#define BEWorkBufferIndex 0
#define ETBalloonEdgeDataSize 6
#define ETIndexIndex 0
#define ETLinesIndex 4
#define ETXValueIndex 1
#define ETYValueIndex 2
#define ETZValueIndex 3
#define FTBalloonFillDataSize 6
#define FTIndexIndex 0
#define FTMaxXIndex 2
#define FTMinXIndex 1
#define FTYValueIndex 3
#define GBBaseSize 16
#define GBBitmapDepth 12
#define GBBitmapHeight 11
#define GBBitmapRaster 14
#define GBBitmapSize 13
#define GBBitmapWidth 10
#define GBColormapOffset 18
#define GBColormapSize 15
#define GBEndX 14
#define GBEndY 15
#define GBFinalX 21
#define GBMBaseSize 18
#define GBTileFlag 16
#define GBUpdateDDX 4
#define GBUpdateDDY 5
#define GBUpdateDX 2
#define GBUpdateDY 3
#define GBUpdateData 10
#define GBUpdateX 0
#define GBUpdateY 1
#define GBViaX 12
#define GBViaY 13
#define GBWideEntry 18
#define GBWideExit 19
#define GBWideExtent 20
#define GBWideFill 16
#define GBWideSize 28
#define GBWideUpdateData 22
#define GBWideWidth 17
#define GEBaseEdgeSize 10
#define GEBaseFillSize 4
#define GEEdgeFillsInvalid 65536
#define GEFillIndexLeft 8
#define GEFillIndexRight 9
#define GENumLines 7
#define GEObjectIndex 2
#define GEObjectLength 1
#define GEObjectType 0
#define GEPrimitiveBezier 6
#define GEPrimitiveClippedBitmapFill 1024
#define GEPrimitiveEdge 2
#define GEPrimitiveEdgeMask 255
#define GEPrimitiveFill 256
#define GEPrimitiveFillMask 65280
#define GEPrimitiveLine 4
#define GEPrimitiveLinearGradientFill 512
#define GEPrimitiveRadialGradientFill 768
#define GEPrimitiveTypeMask 65535
#define GEPrimitiveWide 1
#define GEPrimitiveWideBezier 7
#define GEPrimitiveWideLine 5
#define GEPrimitiveWideMask 254
#define GEStateAddingFromGET 1
#define GEStateBlitBuffer 5
#define GEStateCompleted 8
#define GEStateScanningAET 3
#define GEStateUnlocked 0
#define GEStateUpdateEdges 6
#define GEStateWaitingChange 7
#define GEStateWaitingForEdge 2
#define GEStateWaitingForFill 4
#define GEXValue 4
#define GEYValue 5
#define GEZValue 6
#define GErrorAETEntry 6
#define GErrorBadState 2
#define GErrorFillEntry 5
#define GErrorGETEntry 4
#define GErrorNeedFlush 3
#define GErrorNoMoreSpace 1
#define GFDirectionX 6
#define GFDirectionY 7
#define GFNormalX 8
#define GFNormalY 9
#define GFOriginX 4
#define GFOriginY 5
#define GFRampLength 10
#define GFRampOffset 12
#define GGBaseSize 12
#define GLBaseSize 16
#define GLEndX 14
#define GLEndY 15
#define GLError 13
#define GLErrorAdjDown 15
#define GLErrorAdjUp 14
#define GLWideEntry 18
#define GLWideExit 19
#define GLWideExtent 20
#define GLWideFill 16
#define GLWideSize 21
#define GLWideWidth 17
#define GLXDirection 10
#define GLXIncrement 12
#define GLYDirection 11
#define GWAAColorMask 51
#define GWAAColorShift 50
#define GWAAHalfPixel 53
#define GWAALevel 48
#define GWAAScanMask 52
#define GWAAShift 49
#define GWAETStart 13
#define GWAETUsed 14
#define GWBezierHeightSubdivisions 109
#define GWBezierLineConversions 111
#define GWBezierMonotonSubdivisions 108
#define GWBezierOverflowSubdivisions 110
#define GWBufferTop 10
#define GWClearSpanBuffer 69
#define GWClipMaxX 43
#define GWClipMaxY 45
#define GWClipMinX 42
#define GWClipMinY 44
#define GWColorTransform 24
#define GWCountAddAETEntry 97
#define GWCountChangeAETEntry 107
#define GWCountDisplaySpan 103
#define GWCountFinishTest 93
#define GWCountInitializing 91
#define GWCountMergeFill 101
#define GWCountNextAETEntry 105
#define GWCountNextFillEntry 99
#define GWCountNextGETEntry 95
#define GWCurrentY 88
#define GWCurrentZ 113
#define GWDestOffsetX 46
#define GWDestOffsetY 47
#define GWEdgeTransform 18
#define GWFillMaxX 37
#define GWFillMaxY 39
#define GWFillMinX 36
#define GWFillMinY 38
#define GWFillOffsetX 40
#define GWFillOffsetY 41
#define GWGETStart 11
#define GWGETUsed 12
#define GWHasColorTransform 17
#define GWHasEdgeTransform 16
#define GWHeaderSize 128
#define GWLastExportedEdge 65
#define GWLastExportedFill 66
#define GWLastExportedLeftX 67
#define GWLastExportedRightX 68
#define GWMagicIndex 0
#define GWMagicNumber 1097753705
#define GWMinimalSize 256
#define GWNeedsFlush 63
#define GWObjStart 8
#define GWObjUsed 9
#define GWPoint1 80
#define GWPoint2 82
#define GWPoint3 84
#define GWPoint4 86
#define GWPointListFirst 70
#define GWSize 1
#define GWSpanEnd 34
#define GWSpanEndAA 35
#define GWSpanSize 33
#define GWSpanStart 32
#define GWState 2
#define GWStopReason 64
#define GWTimeAddAETEntry 96
#define GWTimeChangeAETEntry 106
#define GWTimeDisplaySpan 102
#define GWTimeFinishTest 92
#define GWTimeInitializing 90
#define GWTimeMergeFill 100
#define GWTimeNextAETEntry 104
#define GWTimeNextFillEntry 98
#define GWTimeNextGETEntry 94

/*** Function Prototypes ***/
static sqInt aaColorMaskGet(void);
static sqInt aaColorMaskPut(sqInt value);
static sqInt aaColorShiftGet(void);
static sqInt aaColorShiftPut(sqInt value);
static sqInt aaFirstPixelFromto(sqInt leftX, sqInt rightX);
static sqInt aaHalfPixelGet(void);
static sqInt aaHalfPixelPut(sqInt value);
static sqInt aaLastPixelFromto(sqInt leftX, sqInt rightX);
static sqInt aaLevelGet(void);
static sqInt aaLevelPut(sqInt value);
static sqInt aaScanMaskGet(void);
static sqInt aaScanMaskPut(sqInt value);
static sqInt aaShiftGet(void);
static sqInt aaShiftPut(sqInt value);
static sqInt absoluteSquared8Dot24(sqInt value);
static sqInt accurateLengthOfwith(sqInt deltaX, sqInt deltaY);
static sqInt addEdgeToGET(sqInt edge);
static sqInt adjustAALevel(void);
static sqInt adjustWideBezierLeftwidthoffsetendX(sqInt bezier, sqInt lineWidth, sqInt lineOffset, sqInt endX);
static sqInt adjustWideBezierRightwidthoffsetendX(sqInt bezier, sqInt lineWidth, sqInt lineOffset, sqInt endX);
static sqInt adjustWideLineafterSteppingFromto(sqInt line, sqInt lastX, sqInt nextX);
static sqInt aetStartGet(void);
static sqInt aetStartPut(sqInt value);
static sqInt aetUsedGet(void);
static sqInt aetUsedPut(sqInt value);
static sqInt allocateAETEntry(sqInt nSlots);
static sqInt allocateBezier(void);
static sqInt allocateBezierStackEntry(void);
static sqInt allocateBitmapFillcolormap(sqInt cmSize, int * cmBits);
static sqInt allocateGETEntry(sqInt nSlots);
static sqInt allocateGradientFillrampWidthisRadial(int * ramp, sqInt rampWidth, sqInt isRadial);
static sqInt allocateLine(void);
static sqInt allocateObjEntry(sqInt nSlots);
static sqInt allocateStackEntry(sqInt nSlots);
static sqInt allocateStackFillEntry(void);
static sqInt allocateWideBezier(void);
static sqInt allocateWideLine(void);
static sqInt areEdgeFillsValid(sqInt edge);
static sqInt assureValuebetweenand(sqInt val1, sqInt val2, sqInt val3);
static sqInt bezierEndXOf(sqInt bezier);
static sqInt bezierEndXOfput(sqInt bezier, sqInt value);
static sqInt bezierEndYOf(sqInt bezier);
static sqInt bezierEndYOfput(sqInt bezier, sqInt value);
static sqInt bezierFinalXOf(sqInt bezier);
static sqInt bezierFinalXOfput(sqInt bezier, sqInt value);
static int * bezierUpdateDataOf(sqInt bezier);
static sqInt bezierViaXOf(sqInt bezier);
static sqInt bezierViaXOfput(sqInt bezier, sqInt value);
static sqInt bezierViaYOf(sqInt bezier);
static sqInt bezierViaYOfput(sqInt bezier, sqInt value);
static sqInt bitmapCmSizeOf(sqInt bmFill);
static sqInt bitmapCmSizeOfput(sqInt bmFill, sqInt value);
static sqInt bitmapDepthOf(sqInt bmFill);
static sqInt bitmapDepthOfput(sqInt bmFill, sqInt value);
static sqInt bitmapHeightOf(sqInt bmFill);
static sqInt bitmapHeightOfput(sqInt bmFill, sqInt value);
static sqInt bitmapRasterOf(sqInt bmFill);
static sqInt bitmapRasterOfput(sqInt bmFill, sqInt value);
static sqInt bitmapSizeOf(sqInt bmFill);
static sqInt bitmapSizeOfput(sqInt bmFill, sqInt value);
static sqInt bitmapTileFlagOf(sqInt bmFill);
static sqInt bitmapTileFlagOfput(sqInt bmFill, sqInt value);
static sqInt bitmapValuebitsatXy(sqInt bmFill, sqInt bits, sqInt xp, sqInt yp);
static sqInt bitmapWidthOf(sqInt bmFill);
static sqInt bitmapWidthOfput(sqInt bmFill, sqInt value);
static sqInt bzEndX(sqInt index);
static sqInt bzEndXput(sqInt index, sqInt value);
static sqInt bzEndY(sqInt index);
static sqInt bzEndYput(sqInt index, sqInt value);
static sqInt bzStartX(sqInt index);
static sqInt bzStartXput(sqInt index, sqInt value);
static sqInt bzStartY(sqInt index);
static sqInt bzStartYput(sqInt index, sqInt value);
static sqInt bzViaX(sqInt index);
static sqInt bzViaXput(sqInt index, sqInt value);
static sqInt bzViaY(sqInt index);
static sqInt bzViaYput(sqInt index, sqInt value);
static sqInt checkCompressedFillIndexListmaxsegments(sqInt fillList, sqInt maxIndex, sqInt nSegs);
static sqInt checkCompressedFills(sqInt indexList);
static sqInt checkCompressedLineWidthssegments(sqInt lineWidthList, sqInt nSegments);
static sqInt checkCompressedPointssegments(sqInt points, sqInt nSegments);
static sqInt checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(sqInt points, sqInt nSegments, sqInt leftFills, sqInt rightFills, sqInt lineWidths, sqInt lineFills, sqInt fillIndexList);
static sqInt checkedAddBezierToGET(sqInt bezier);
static sqInt checkedAddEdgeToGET(sqInt edge);
static sqInt checkedAddLineToGET(sqInt line);
static double * circleCosTable(void);
static double * circleSinTable(void);
static sqInt clampValuemax(sqInt value, sqInt maxValue);
static sqInt clearSpanBuffer(void);
static sqInt clearSpanBufferGet(void);
static sqInt clearSpanBufferPut(sqInt value);
static sqInt clipMaxXGet(void);
static sqInt clipMaxXPut(sqInt value);
static sqInt clipMaxYGet(void);
static sqInt clipMaxYPut(sqInt value);
static sqInt clipMinXGet(void);
static sqInt clipMinXPut(sqInt value);
static sqInt clipMinYGet(void);
static sqInt clipMinYPut(sqInt value);
static float * colorTransform(void);
static int * colormapOf(sqInt bmFill);
static sqInt computeBeziersplitAt(sqInt index, double  param);
static sqInt computeBezierSplitAtHalf(sqInt index);
static sqInt computeFinalWideBezierValueswidth(sqInt bezier, sqInt lineWidth);
static sqInt computeSqrt(sqInt length2);
static sqInt copyBitsFromtoat(sqInt x0, sqInt x1, sqInt yValue);
static sqInt createGlobalEdgeTable(void);
static sqInt currentYGet(void);
static sqInt currentYPut(sqInt value);
static sqInt currentZGet(void);
static sqInt currentZPut(sqInt value);
static sqInt destOffsetXGet(void);
static sqInt destOffsetXPut(sqInt value);
static sqInt destOffsetYGet(void);
static sqInt destOffsetYPut(sqInt value);
static sqInt displaySpanBufferAt(sqInt y);
static sqInt drawWideEdgefrom(sqInt edge, sqInt leftX);
static sqInt edgeFillsInvalidate(sqInt edge);
static sqInt edgeFillsValidate(sqInt edge);
static sqInt edgeLeftFillOf(sqInt edge);
static sqInt edgeLeftFillOfput(sqInt edge, sqInt value);
static sqInt edgeNumLinesOf(sqInt edge);
static sqInt edgeNumLinesOfput(sqInt edge, sqInt value);
static sqInt edgeRightFillOf(sqInt edge);
static sqInt edgeRightFillOfput(sqInt edge, sqInt value);
static float * edgeTransform(void);
static sqInt edgeTypeOf(sqInt edge);
static sqInt edgeXValueOf(sqInt edge);
static sqInt edgeXValueOfput(sqInt edge, sqInt value);
static sqInt edgeYValueOf(sqInt edge);
static sqInt edgeYValueOfput(sqInt edge, sqInt value);
static sqInt edgeZValueOf(sqInt edge);
static sqInt edgeZValueOfput(sqInt edge, sqInt value);
static sqInt errorWrongIndex(void);
static sqInt estimatedLengthOfwith(sqInt deltaX, sqInt deltaY);
static sqInt fillAllFromto(sqInt leftX, sqInt rightX);
static sqInt fillBitmapSpan(void);
static sqInt fillBitmapSpanfromto(int * bits, sqInt leftX, sqInt rightX);
static sqInt fillBitmapSpanfromtoat(sqInt bmFill, sqInt leftX, sqInt rightX, sqInt yValue);
static sqInt fillBitmapSpanAAfromtoat(sqInt bmFill, sqInt leftX, sqInt rightX, sqInt yValue);
static sqInt fillColorSpanfromto(sqInt pixelValue32, sqInt leftX, sqInt rightX);
static sqInt fillColorSpanAAx0x1(sqInt pixelValue32, sqInt leftX, sqInt rightX);
static sqInt fillDirectionXOf(sqInt fill);
static sqInt fillDirectionXOfput(sqInt fill, sqInt value);
static sqInt fillDirectionYOf(sqInt fill);
static sqInt fillDirectionYOfput(sqInt fill, sqInt value);
static sqInt fillLinearGradient(void);
static sqInt fillLinearGradientfromtoat(sqInt fill, sqInt leftX, sqInt rightX, sqInt yValue);
static sqInt fillLinearGradientAArampdsdsXfromto(sqInt fill, int * ramp, sqInt deltaS, sqInt dsX, sqInt leftX, sqInt rightX);
static sqInt fillMaxXGet(void);
static sqInt fillMaxXPut(sqInt value);
static sqInt fillMaxYGet(void);
static sqInt fillMaxYPut(sqInt value);
static sqInt fillMinXGet(void);
static sqInt fillMinXPut(sqInt value);
static sqInt fillMinYGet(void);
static sqInt fillMinYPut(sqInt value);
static sqInt fillNormalXOf(sqInt fill);
static sqInt fillNormalXOfput(sqInt fill, sqInt value);
static sqInt fillNormalYOf(sqInt fill);
static sqInt fillNormalYOfput(sqInt fill, sqInt value);
static sqInt fillOffsetXGet(void);
static sqInt fillOffsetXPut(sqInt value);
static sqInt fillOffsetYGet(void);
static sqInt fillOffsetYPut(sqInt value);
static sqInt fillOriginXOf(sqInt fill);
static sqInt fillOriginXOfput(sqInt fill, sqInt value);
static sqInt fillOriginYOf(sqInt fill);
static sqInt fillOriginYOfput(sqInt fill, sqInt value);
static sqInt fillRadialDecreasingrampdeltaSTdsXdtXfromto(sqInt fill, sqInt ramp, sqInt deltaST, sqInt dsX, sqInt dtX, sqInt leftX, sqInt rightX);
static sqInt fillRadialDecreasingAArampdeltaSTdsXdtXfromto(sqInt fill, int * ramp,  int * deltaST, sqInt dsX, sqInt dtX, sqInt leftX, sqInt rightX);
static sqInt fillRadialGradient(void);
static sqInt fillRadialGradientfromtoat(sqInt fill, sqInt leftX, sqInt rightX, sqInt yValue);
static sqInt fillRadialIncreasingrampdeltaSTdsXdtXfromto(sqInt fill, sqInt ramp, sqInt deltaST, sqInt dsX, sqInt dtX, sqInt leftX, sqInt rightX);
static sqInt fillRadialIncreasingAArampdeltaSTdsXdtXfromto(sqInt fill, int * ramp,  int * deltaST, sqInt dsX, sqInt dtX, sqInt leftX, sqInt rightX);
static sqInt fillSortsbefore(sqInt fillEntry1, sqInt fillEntry2);
static sqInt fillSpanfromto(unsigned int fill, sqInt leftX, sqInt rightX);
static sqInt fillTypeOf(sqInt fill);
static sqInt findNextAETEdgeFrom(sqInt leftEdge);
static sqInt findNextExternalEntryFromGET(void);
static sqInt findNextExternalFillFromAET(void);
static sqInt findNextExternalUpdateFromAET(void);
static sqInt findStackFilldepth(sqInt fillIndex, sqInt depth);
static sqInt finishedProcessing(void);
static sqInt firstPointListGet(void);
static sqInt firstPointListPut(sqInt value);
static sqInt freeStackFillEntry(void);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt getSortsbefore(sqInt edge1, sqInt edge2);
static sqInt getStartGet(void);
static sqInt getStartPut(sqInt value);
static sqInt getUsedGet(void);
static sqInt getUsedPut(sqInt value);
static sqInt gradientRampLengthOf(sqInt fill);
static sqInt gradientRampLengthOfput(sqInt fill, sqInt value);
static int * gradientRampOf(sqInt fill);
static sqInt halt(void);
static sqInt hasColorTransform(void);
static sqInt hasColorTransformGet(void);
static sqInt hasColorTransformPut(sqInt value);
static sqInt hasEdgeTransform(void);
static sqInt hasEdgeTransformGet(void);
static sqInt hasEdgeTransformPut(sqInt value);
static sqInt hideFilldepth(sqInt fillIndex, sqInt depth);
static sqInt incrementPointby(int * point, sqInt delta);
static sqInt incrementStatby(sqInt statIndex, sqInt value);
static sqInt indexForInsertingIntoAET(sqInt edge);
static sqInt initColorTransform(void);
static sqInt initEdgeTransform(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
#pragma export off
static sqInt initializeGETProcessing(void);
static sqInt insertEdgeIntoAET(sqInt edge);
static sqInt insertToAETbeforeIndex(sqInt edge, sqInt index);
static sqInt isBezier(sqInt bezier);
static sqInt isEdge(sqInt edge);
static sqInt isFill(sqInt fill);
static sqInt isFillColor(sqInt fill);
static sqInt isFillOkay(sqInt fill);
static sqInt isLine(sqInt line);
static sqInt isObject(sqInt obj);
static sqInt isRealFill(sqInt fill);
static sqInt isStackEntry(sqInt entry);
static sqInt isStackIndex(sqInt index);
static sqInt isWide(sqInt object);
static sqInt isWideBezier(sqInt bezier);
static sqInt isWideLine(sqInt line);
static sqInt lastExportedEdgeGet(void);
static sqInt lastExportedEdgePut(sqInt value);
static sqInt lastExportedFillGet(void);
static sqInt lastExportedFillPut(sqInt value);
static sqInt lastExportedLeftXGet(void);
static sqInt lastExportedLeftXPut(sqInt value);
static sqInt lastExportedRightXGet(void);
static sqInt lastExportedRightXPut(sqInt value);
static sqInt lineEndXOf(sqInt line);
static sqInt lineEndXOfput(sqInt line, sqInt value);
static sqInt lineEndYOf(sqInt line);
static sqInt lineEndYOfput(sqInt line, sqInt value);
static sqInt lineErrorAdjDownOf(sqInt line);
static sqInt lineErrorAdjDownOfput(sqInt line, sqInt value);
static sqInt lineErrorAdjUpOf(sqInt line);
static sqInt lineErrorAdjUpOfput(sqInt line, sqInt value);
static sqInt lineErrorOf(sqInt line);
static sqInt lineErrorOfput(sqInt line, sqInt value);
static sqInt lineXDirectionOf(sqInt line);
static sqInt lineXDirectionOfput(sqInt line, sqInt value);
static sqInt lineXIncrementOf(sqInt line);
static sqInt lineXIncrementOfput(sqInt line, sqInt value);
static sqInt lineYDirectionOf(sqInt line);
static sqInt lineYDirectionOfput(sqInt line, sqInt value);
static sqInt loadAndSubdivideBezierFromviatoisWide(int * point1, int * point2, int * point3, sqInt wideFlag);
static sqInt loadArrayPolygonnPointsfilllineWidthlineFill(sqInt points, sqInt nPoints, sqInt fillIndex, sqInt lineWidth, sqInt lineFill);
static sqInt loadArrayShapenSegmentsfilllineWidthlineFill(sqInt points, sqInt nSegments, sqInt fillIndex, sqInt lineWidth, sqInt lineFill);
static sqInt loadArrayTransformFromintolength(sqInt transformOop, float * destPtr, sqInt n);
static sqInt loadBeziersegmentleftFillrightFilloffset(sqInt bezier, sqInt index, sqInt leftFillIndex, sqInt rightFillIndex, sqInt yOffset);
static sqInt loadBitBltFrom(sqInt bbObj);
static sqInt loadBitmapFillcolormaptilefromalongnormalxIndex(sqInt formOop, sqInt cmOop, sqInt tileFlag, int * point1, int * point2, int * point3, sqInt xIndex);
static int * loadBitsFrom(sqInt bmFill);
static sqInt loadColorTransformFrom(sqInt transformOop);
static sqInt loadCompressedSegmentfromshortleftFillrightFilllineWidthlineColor(sqInt segmentIndex, sqInt points, sqInt pointsShort, sqInt leftFill, sqInt rightFill, sqInt lineWidth, sqInt lineFill);
static sqInt loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(int * points, sqInt nSegments, int * leftFills, int * rightFills, int * lineWidths, int * lineFills, int * fillIndexList, sqInt pointsShort);
static sqInt loadEdgeStateFrom(sqInt edgeOop);
static sqInt loadEdgeTransformFrom(sqInt transformOop);
static sqInt loadFillOrientationfromalongnormalwidthheight(sqInt fill, int * point1, int * point2, int * point3, sqInt fillWidth, sqInt fillHeight);
static sqInt loadFormsFrom(sqInt arrayOop);
static sqInt loadGradientFillfromalongnormalisRadial(sqInt rampOop, int * point1, int * point2, int * point3, sqInt isRadial);
static sqInt loadLinefromtooffsetleftFillrightFill(sqInt line, int * point1, int * point2, sqInt yOffset, sqInt leftFill, sqInt rightFill);
static sqInt loadOvallineFillleftFillrightFill(sqInt lineWidth, sqInt lineFill, sqInt leftFill, sqInt rightFill);
static sqInt loadOvalSegmentwhcxcy(sqInt seg, sqInt w, sqInt h, sqInt cx, sqInt cy);
static sqInt loadPointfrom(int * pointArray, sqInt pointOop);
static sqInt loadPointIntAtfrom(sqInt index, sqInt intArray);
static short loadPointShortAtfrom(sqInt index, sqInt shortArray);
static sqInt loadPolygonnPointsfilllineWidthlineFillpointsShort(int * points, sqInt nPoints, sqInt fillIndex, sqInt lineWidth, sqInt lineFill, sqInt isShort);
static sqInt loadRectanglelineFillleftFillrightFill(sqInt lineWidth, sqInt lineFill, sqInt leftFill, sqInt rightFill);
static sqInt loadRenderingState(void);
static sqInt loadShapenSegmentsfilllineWidthlineFillpointsShort(int * points, sqInt nSegments, sqInt fillIndex, sqInt lineWidth, sqInt lineFill, sqInt pointsShort);
static sqInt loadSpanBufferFrom(sqInt spanOop);
static sqInt loadTransformFromintolength(sqInt transformOop, float * destPtr, sqInt n);
static sqInt loadWideBezierlineFillleftFillrightFilln(sqInt lineWidth, sqInt lineFill, sqInt leftFill, sqInt rightFill, sqInt nSegments);
static sqInt loadWideLinefromtolineFillleftFillrightFill(sqInt lineWidth, int * p1, int * p2, sqInt lineFill, sqInt leftFill, sqInt rightFill);
static sqInt loadWordTransformFromintolength(sqInt transformOop, float * destPtr, sqInt n);
static sqInt loadWorkBufferFrom(sqInt wbOop);
static sqInt magicNumberGet(void);
static sqInt magicNumberPut(sqInt value);
static sqInt makeRectFromPoints(void);
static sqInt makeUnsignedFrom(sqInt someIntegerValue);
#pragma export on
EXPORT(sqInt) moduleUnloaded(char * aModuleName);
#pragma export off
static sqInt moveAETEntryFromedgex(sqInt index, sqInt edge, sqInt xValue);
static sqInt msg(char * s);
static sqInt needAvailableSpace(sqInt nSlots);
static sqInt needsFlush(void);
static sqInt needsFlushGet(void);
static sqInt needsFlushPut(sqInt value);
static sqInt objat(sqInt object, sqInt index);
static sqInt objatput(sqInt object, sqInt index, sqInt value);
static sqInt objStartGet(void);
static sqInt objStartPut(sqInt value);
static sqInt objUsedGet(void);
static sqInt objUsedPut(sqInt value);
static sqInt objectHeaderOf(sqInt obj);
static sqInt objectIndexOf(sqInt obj);
static sqInt objectIndexOfput(sqInt obj, sqInt value);
static sqInt objectLengthOf(sqInt obj);
static sqInt objectLengthOfput(sqInt obj, sqInt value);
static sqInt objectTypeOf(sqInt obj);
static sqInt objectTypeOfput(sqInt obj, sqInt value);
static sqInt offsetFromWidth(sqInt lineWidth);
static int * point1Get(void);
static int * point2Get(void);
static int * point3Get(void);
static int * point4Get(void);
static sqInt postDisplayAction(void);
#pragma export on
EXPORT(sqInt) primitiveAbortProcessing(void);
EXPORT(sqInt) primitiveAddActiveEdgeEntry(void);
EXPORT(sqInt) primitiveAddBezier(void);
EXPORT(sqInt) primitiveAddBezierShape(void);
EXPORT(sqInt) primitiveAddBitmapFill(void);
EXPORT(sqInt) primitiveAddCompressedShape(void);
EXPORT(sqInt) primitiveAddGradientFill(void);
EXPORT(sqInt) primitiveAddLine(void);
EXPORT(sqInt) primitiveAddOval(void);
EXPORT(sqInt) primitiveAddPolygon(void);
EXPORT(sqInt) primitiveAddRect(void);
EXPORT(sqInt) primitiveChangedActiveEdgeEntry(void);
EXPORT(sqInt) primitiveCopyBuffer(void);
EXPORT(sqInt) primitiveDisplaySpanBuffer(void);
EXPORT(sqInt) primitiveDoProfileStats(void);
EXPORT(sqInt) primitiveFinishedProcessing(void);
EXPORT(sqInt) primitiveGetAALevel(void);
EXPORT(sqInt) primitiveGetBezierStats(void);
EXPORT(sqInt) primitiveGetClipRect(void);
EXPORT(sqInt) primitiveGetCounts(void);
EXPORT(sqInt) primitiveGetDepth(void);
EXPORT(sqInt) primitiveGetFailureReason(void);
EXPORT(sqInt) primitiveGetOffset(void);
EXPORT(sqInt) primitiveGetTimes(void);
EXPORT(sqInt) primitiveInitializeBuffer(void);
EXPORT(sqInt) primitiveInitializeProcessing(void);
EXPORT(sqInt) primitiveMergeFillFrom(void);
EXPORT(sqInt) primitiveNeedsFlush(void);
EXPORT(sqInt) primitiveNeedsFlushPut(void);
EXPORT(sqInt) primitiveNextActiveEdgeEntry(void);
EXPORT(sqInt) primitiveNextFillEntry(void);
EXPORT(sqInt) primitiveNextGlobalEdgeEntry(void);
EXPORT(sqInt) primitiveRegisterExternalEdge(void);
EXPORT(sqInt) primitiveRegisterExternalFill(void);
EXPORT(sqInt) primitiveRenderImage(void);
EXPORT(sqInt) primitiveRenderScanline(void);
EXPORT(sqInt) primitiveSetAALevel(void);
EXPORT(sqInt) primitiveSetBitBltPlugin(void);
EXPORT(sqInt) primitiveSetClipRect(void);
EXPORT(sqInt) primitiveSetColorTransform(void);
EXPORT(sqInt) primitiveSetDepth(void);
EXPORT(sqInt) primitiveSetEdgeTransform(void);
EXPORT(sqInt) primitiveSetOffset(void);
#pragma export off
static sqInt proceedRenderingImage(void);
static sqInt proceedRenderingScanline(void);
static sqInt quickLoadEngineFrom(sqInt engineOop);
static sqInt quickLoadEngineFromrequiredState(sqInt oop, sqInt requiredState);
static sqInt quickLoadEngineFromrequiredStateor(sqInt oop, sqInt requiredState, sqInt alternativeState);
static sqInt quickRemoveInvalidFillsAt(sqInt leftX);
static sqInt quickSortGlobalEdgeTablefromto(int * array, sqInt i, sqInt j);
static int * rShiftTable(void);
static sqInt removeFirstAETEntry(void);
static sqInt repeatValuemax(sqInt delta, sqInt maxValue);
static sqInt resetGraphicsEngineStats(void);
static sqInt resortFirstAETEntry(void);
static sqInt returnWideBezierFill(void);
static sqInt returnWideBezierWidth(void);
static sqInt returnWideLineFill(void);
static sqInt returnWideLineWidth(void);
static sqInt setAALevel(sqInt level);
#pragma export on
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off
static sqInt shortRunLengthAtfrom(sqInt i, sqInt runArray);
static sqInt shortRunValueAtfrom(sqInt i, sqInt runArray);
static sqInt showFilldepthrightX(sqInt fillIndex, sqInt depth, sqInt rightX);
static int * smallSqrtTable(void);
static sqInt sortGlobalEdgeTable(void);
static sqInt spanEndAAGet(void);
static sqInt spanEndAAPut(sqInt value);
static sqInt spanEndGet(void);
static sqInt spanEndPut(sqInt value);
static sqInt spanSizeGet(void);
static sqInt spanSizePut(sqInt value);
static sqInt spanStartGet(void);
static sqInt spanStartPut(sqInt value);
static sqInt squaredLengthOfwith(sqInt deltaX, sqInt deltaY);
static sqInt stackFillDepth(sqInt index);
static sqInt stackFillDepthput(sqInt index, sqInt value);
static sqInt stackFillEntryLength(void);
static sqInt stackFillRightX(sqInt index);
static sqInt stackFillRightXput(sqInt index, sqInt value);
static sqInt stackFillSize(void);
static sqInt stackFillValue(sqInt index);
static sqInt stackFillValueput(sqInt index, sqInt value);
static sqInt stateGet(void);
static sqInt statePut(sqInt value);
static sqInt stepToFirstBezier(void);
static sqInt stepToFirstBezierInat(sqInt bezier, sqInt yValue);
static sqInt stepToFirstLine(void);
static sqInt stepToFirstLineInat(sqInt line, sqInt yValue);
static sqInt stepToFirstWideBezier(void);
static sqInt stepToFirstWideBezierInat(sqInt bezier, sqInt yValue);
static sqInt stepToFirstWideLine(void);
static sqInt stepToFirstWideLineInat(sqInt line, sqInt yValue);
static sqInt stepToNextBezier(void);
static sqInt stepToNextBezierForwardat(sqInt updateData, sqInt yValue);
static sqInt stepToNextBezierInat(sqInt bezier, sqInt yValue);
static sqInt stepToNextLine(void);
static sqInt stepToNextLineInat(sqInt line, sqInt yValue);
static sqInt stepToNextWideBezier(void);
static sqInt stepToNextWideBezierInat(sqInt bezier, sqInt yValue);
static sqInt stepToNextWideLine(void);
static sqInt stepToNextWideLineInat(sqInt line, sqInt yValue);
static sqInt stopBecauseOf(sqInt stopReason);
static sqInt stopReasonGet(void);
static sqInt stopReasonPut(sqInt value);
static sqInt storeEdgeStateFrominto(sqInt edge, sqInt edgeOop);
static sqInt storeEngineStateInto(sqInt oop);
static sqInt storeFillStateInto(sqInt fillOop);
static sqInt storeRenderingState(void);
static sqInt storeStopStateIntoEdgefill(sqInt edgeOop, sqInt fillOop);
static sqInt subdivideBezier(sqInt index);
static sqInt subdivideBezierFrom(sqInt index);
static sqInt subdivideToBeMonotoninX(sqInt base, sqInt doTestX);
static sqInt subdivideToBeMonotonInX(sqInt index);
static sqInt subdivideToBeMonotonInY(sqInt index);
static sqInt toggleFilldepthrightX(sqInt fillIndex, sqInt depth, sqInt rightX);
static sqInt toggleFillsOf(sqInt edge);
static sqInt toggleWideFillOf(sqInt edge);
static sqInt topDepth(void);
static sqInt topFill(void);
static sqInt topFillDepth(void);
static sqInt topFillDepthPut(sqInt value);
static sqInt topFillRightX(void);
static sqInt topFillRightXPut(sqInt value);
static sqInt topFillValue(void);
static sqInt topFillValuePut(sqInt value);
static sqInt topRightX(void);
static sqInt transformColor(sqInt fillIndex);
static sqInt transformPoint(int * point);
static sqInt transformPointinto(sqInt srcPoint, sqInt dstPoint);
static sqInt transformPointXyinto(double  xValue, double  yValue, int * dstPoint);
static sqInt transformPoints(sqInt n);
static sqInt transformWidth(sqInt w);
static sqInt uncheckedTransformColor(sqInt fillIndex);
static sqInt wbSizeGet(void);
static sqInt wbSizePut(sqInt value);
static sqInt wbStackClear(void);
static sqInt wbStackPop(sqInt nItems);
static sqInt wbStackPush(sqInt nItems);
static sqInt wbStackSize(void);
static sqInt wbStackValue(sqInt index);
static sqInt wbStackValueput(sqInt index, sqInt value);
static sqInt wbTopGet(void);
static sqInt wbTopPut(sqInt value);
static sqInt wideBezierEntryOf(sqInt line);
static sqInt wideBezierEntryOfput(sqInt line, sqInt value);
static sqInt wideBezierExitOf(sqInt line);
static sqInt wideBezierExitOfput(sqInt line, sqInt value);
static sqInt wideBezierExtentOf(sqInt bezier);
static sqInt wideBezierExtentOfput(sqInt bezier, sqInt value);
static sqInt wideBezierFillOf(sqInt bezier);
static sqInt wideBezierFillOfput(sqInt bezier, sqInt value);
static int * wideBezierUpdateDataOf(sqInt bezier);
static sqInt wideBezierWidthOf(sqInt line);
static sqInt wideBezierWidthOfput(sqInt line, sqInt value);
static sqInt wideLineEntryOf(sqInt line);
static sqInt wideLineEntryOfput(sqInt line, sqInt value);
static sqInt wideLineExitOf(sqInt line);
static sqInt wideLineExitOfput(sqInt line, sqInt value);
static sqInt wideLineExtentOf(sqInt line);
static sqInt wideLineExtentOfput(sqInt line, sqInt value);
static sqInt wideLineFillOf(sqInt line);
static sqInt wideLineFillOfput(sqInt line, sqInt value);
static sqInt wideLineWidthOf(sqInt line);
static sqInt wideLineWidthOfput(sqInt line, sqInt value);
static sqInt workBufferPut(sqInt wbOop);
/*** Variables ***/
static int* aetBuffer;
static char bbPluginName[256] = "BitBltPlugin";
static void * copyBitsFn;
static sqInt dispatchReturnValue;
static sqInt dispatchedValue;
static int doProfileStats = 0;
static sqInt engine;
static sqInt engineStopped;
static sqInt formArray;
static sqInt geProfileTime;
static int* getBuffer;

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static void * loadBBFn;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"B2DPlugin 10 April 2008 (i)"
#else
	"B2DPlugin 10 April 2008 (e)"
#endif
;
static int* objBuffer;
static sqInt objUsed;
static unsigned int* spanBuffer;
static int* workBuffer;


static sqInt aaColorMaskGet(void) {
	return workBuffer[GWAAColorMask];
}

static sqInt aaColorMaskPut(sqInt value) {
	return workBuffer[GWAAColorMask] = value;
}

static sqInt aaColorShiftGet(void) {
	return workBuffer[GWAAColorShift];
}

static sqInt aaColorShiftPut(sqInt value) {
	return workBuffer[GWAAColorShift] = value;
}


/*	Common function to compute the first full pixel for AA drawing */

static sqInt aaFirstPixelFromto(sqInt leftX, sqInt rightX) {
    sqInt firstPixel;

	firstPixel = ((leftX + (workBuffer[GWAALevel])) - 1) & (~((workBuffer[GWAALevel]) - 1));
	if (firstPixel > rightX) {
		return rightX;
	} else {
		return firstPixel;
	}
}

static sqInt aaHalfPixelGet(void) {
	return workBuffer[GWAAHalfPixel];
}

static sqInt aaHalfPixelPut(sqInt value) {
	return workBuffer[GWAAHalfPixel] = value;
}


/*	Common function to compute the last full pixel for AA drawing */

static sqInt aaLastPixelFromto(sqInt leftX, sqInt rightX) {
	return (rightX - 1) & (~((workBuffer[GWAALevel]) - 1));
}

static sqInt aaLevelGet(void) {
	return workBuffer[GWAALevel];
}

static sqInt aaLevelPut(sqInt value) {
	return workBuffer[GWAALevel] = value;
}

static sqInt aaScanMaskGet(void) {
	return workBuffer[GWAAScanMask];
}

static sqInt aaScanMaskPut(sqInt value) {
	return workBuffer[GWAAScanMask] = value;
}

static sqInt aaShiftGet(void) {
	return workBuffer[GWAAShift];
}

static sqInt aaShiftPut(sqInt value) {
	return workBuffer[GWAAShift] = value;
}


/*	Compute the squared value of a 8.24 number with 0.0 <= value < 1.0,
	e.g., compute (value * value) bitShift: -24 */

static sqInt absoluteSquared8Dot24(sqInt value) {
    sqInt word2;
    sqInt word1;

	word1 = value & 65535;
	word2 = (((usqInt) value >> 16)) & 255;
	return ((usqInt) (((((usqInt) (((unsigned) (word1 * word1))) >> 16)) + ((word1 * word2) * 2)) + (((usqInt) (word2 * word2) << 16))) >> 8);
}


/*	Return the accurate length of the vector described by deltaX and deltaY */

static sqInt accurateLengthOfwith(sqInt deltaX, sqInt deltaY) {
    sqInt length2;

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
		return ((sqInt) ((sqrt(((double) length2 ))) + 0.5) );
	}
	return null;
}

static sqInt addEdgeToGET(sqInt edge) {
	if (!(allocateGETEntry(1))) {
		return 0;
	}
	getBuffer[workBuffer[GWGETUsed]] = edge;
	workBuffer[GWGETUsed] = ((workBuffer[GWGETUsed]) + 1);
}


/*	NOTE: 	This method is (hopefully) obsolete due to unrolling 
				the fill loops to deal with full pixels. */
/*	Adjust the span buffers values by the appropriate color offset for anti-aliasing.
	We do this by replicating the top bits of each color in the lower bits. The idea is that we can scale each color value uniquely from 0 to 255 and thus fill the entire range of colors. */

static sqInt adjustAALevel(void) {
    sqInt pixelValue;
    sqInt x1;
    sqInt adjustShift;
    sqInt adjustMask;
    sqInt x0;

	adjustShift = 8 - (workBuffer[GWAAColorShift]);
	adjustMask = ~(workBuffer[GWAAColorMask]);
	x0 = ((usqInt) (workBuffer[GWSpanStart])) >> (workBuffer[GWAAShift]);
	x1 = ((usqInt) (workBuffer[GWSpanEnd])) >> (workBuffer[GWAAShift]);
	while (x0 < x1) {
		pixelValue = spanBuffer[x0];
		spanBuffer[x0] = (pixelValue | ((((usqInt) pixelValue) >> adjustShift) & adjustMask));
		x0 += 1;
	}
}


/*	Adjust the wide bezier curve (dx < 0) to start/end at the right point */

static sqInt adjustWideBezierLeftwidthoffsetendX(sqInt bezier, sqInt lineWidth, sqInt lineOffset, sqInt endX) {
    sqInt lastX;
    sqInt lastY;

	((objBuffer + bezier) + GBUpdateData)[GBUpdateX] = ((((objBuffer + bezier) + GBUpdateData)[GBUpdateX]) - (lineOffset * 256));
	lastX = ((objBuffer + bezier) + GBWideUpdateData)[GBUpdateX];
	((objBuffer + bezier) + GBWideUpdateData)[GBUpdateX] = (lastX + ((lineWidth - lineOffset) * 256));
	lastY = ((objBuffer + bezier) + GBWideUpdateData)[GBUpdateY];
	((objBuffer + bezier) + GBWideUpdateData)[GBUpdateY] = (lastY + (lineWidth * 256));
	objBuffer[bezier + GBFinalX] = (endX - lineOffset);
}


/*	Adjust the wide bezier curve (dx >= 0) to start/end at the right point */

static sqInt adjustWideBezierRightwidthoffsetendX(sqInt bezier, sqInt lineWidth, sqInt lineOffset, sqInt endX) {
    sqInt lastX;
    sqInt lastY;

	((objBuffer + bezier) + GBUpdateData)[GBUpdateX] = ((((objBuffer + bezier) + GBUpdateData)[GBUpdateX]) + (lineOffset * 256));
	lastX = ((objBuffer + bezier) + GBWideUpdateData)[GBUpdateX];
	((objBuffer + bezier) + GBWideUpdateData)[GBUpdateX] = (lastX - ((lineWidth - lineOffset) * 256));

	/* Set lineWidth pixels down */

	lastY = ((objBuffer + bezier) + GBWideUpdateData)[GBUpdateY];
	((objBuffer + bezier) + GBWideUpdateData)[GBUpdateY] = (lastY + (lineWidth * 256));
	objBuffer[bezier + GBFinalX] = ((endX - lineOffset) + lineWidth);
}


/*	Adjust the wide line after it has been stepped from lastX to nextX.
	Special adjustments of line width and start position are made here
	to simulate a rectangular brush */

static sqInt adjustWideLineafterSteppingFromto(sqInt line, sqInt lastX, sqInt nextX) {
    sqInt yEntry;
    sqInt lineOffset;
    sqInt lineWidth;
    sqInt xDir;
    sqInt deltaX;
    sqInt baseWidth;
    sqInt yExit;

	yEntry = objBuffer[line + GLWideEntry];
	yExit = objBuffer[line + GLWideExit];
	baseWidth = objBuffer[line + GLWideExtent];
	lineOffset = ((sqInt) baseWidth >> 1);
	lineWidth = objBuffer[line + GLWideWidth];
	xDir = objBuffer[line + GLXDirection];

	/* Adjust the start of the line to fill an entire rectangle */

	deltaX = nextX - lastX;
	if (yEntry < baseWidth) {
		if (xDir < 0) {

			/* effectively adding */

			lineWidth -= deltaX;
		} else {
			lineWidth += deltaX;
			objBuffer[line + GEXValue] = lastX;
		}
	}
	if ((yExit + lineOffset) == 0) {
		if (xDir > 0) {
			lineWidth -= objBuffer[line + GLXIncrement];
		} else {

			/* effectively subtracting */

			lineWidth += objBuffer[line + GLXIncrement];
			objBuffer[line + GEXValue] = lastX;
		}
	}
	if ((yExit + lineOffset) > 0) {
		if (xDir < 0) {

			/* effectively subtracting */

			lineWidth += deltaX;
			objBuffer[line + GEXValue] = lastX;
		} else {
			lineWidth -= deltaX;
		}
	}
	objBuffer[line + GLWideWidth] = lineWidth;
}

static sqInt aetStartGet(void) {
	return workBuffer[GWAETStart];
}

static sqInt aetStartPut(sqInt value) {
	return workBuffer[GWAETStart] = value;
}

static sqInt aetUsedGet(void) {
	return workBuffer[GWAETUsed];
}

static sqInt aetUsedPut(sqInt value) {
	return workBuffer[GWAETUsed] = value;
}


/*	Allocate n slots in the active edge table */

static sqInt allocateAETEntry(sqInt nSlots) {
	/* begin needAvailableSpace: */
	if (((((GWHeaderSize + objUsed) + (workBuffer[GWGETUsed])) + (workBuffer[GWAETUsed])) + nSlots) > (workBuffer[GWBufferTop])) {
		/* begin stopBecauseOf: */
		workBuffer[GWStopReason] = GErrorNoMoreSpace;
		engineStopped = 1;
		return 0;
	}
	return 1;
}

static sqInt allocateBezier(void) {
    sqInt bezier;

	if (!(allocateObjEntry(GBBaseSize))) {
		return 0;
	}
	bezier = objUsed;
	objUsed = bezier + GBBaseSize;
	objBuffer[bezier + GEObjectType] = GEPrimitiveBezier;
	objBuffer[bezier + GEObjectIndex] = 0;
	objBuffer[bezier + GEObjectLength] = GBBaseSize;
	return bezier;
}

static sqInt allocateBezierStackEntry(void) {
	/* begin wbStackPush: */
	if (!(needAvailableSpace(6))) {
		goto l1;
	}
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) - 6);
l1:	/* end wbStackPush: */;
	return (workBuffer[GWSize]) - (workBuffer[GWBufferTop]);
}

static sqInt allocateBitmapFillcolormap(sqInt cmSize, int * cmBits) {
    sqInt i;
    sqInt fill;
    int * cm;
    sqInt fillSize;

	fillSize = GBMBaseSize + cmSize;
	if (!(allocateObjEntry(fillSize))) {
		return 0;
	}
	fill = objUsed;
	objUsed = fill + fillSize;
	objBuffer[fill + GEObjectType] = GEPrimitiveClippedBitmapFill;
	objBuffer[fill + GEObjectIndex] = 0;
	objBuffer[fill + GEObjectLength] = fillSize;
	cm = (objBuffer + fill) + GBColormapOffset;
	if ((workBuffer[GWHasColorTransform]) != 0) {
		for (i = 0; i <= (cmSize - 1); i += 1) {
			cm[i] = (transformColor(cmBits[i]));
		}
	} else {
		for (i = 0; i <= (cmSize - 1); i += 1) {
			cm[i] = (cmBits[i]);
		}
	}
	objBuffer[fill + GBColormapSize] = cmSize;
	return fill;
}


/*	Allocate n slots in the global edge table */

static sqInt allocateGETEntry(sqInt nSlots) {
    sqInt dstIndex;
    sqInt i;
    sqInt srcIndex;

	if (!(needAvailableSpace(nSlots))) {
		return 0;
	}
	if (!((workBuffer[GWAETUsed]) == 0)) {
		srcIndex = workBuffer[GWAETUsed];
		dstIndex = (workBuffer[GWAETUsed]) + nSlots;
		for (i = 1; i <= (workBuffer[GWAETUsed]); i += 1) {
			aetBuffer[dstIndex -= 1] = (aetBuffer[srcIndex -= 1]);
		}
	}
	aetBuffer += nSlots;
	return 1;
}

static sqInt allocateGradientFillrampWidthisRadial(int * ramp, sqInt rampWidth, sqInt isRadial) {
    sqInt fillSize;
    sqInt i;
    int * rampPtr;
    sqInt fill;

	fillSize = GGBaseSize + rampWidth;
	if (!(allocateObjEntry(fillSize))) {
		return 0;
	}
	fill = objUsed;
	objUsed = fill + fillSize;
	if (isRadial) {
		objBuffer[fill + GEObjectType] = GEPrimitiveRadialGradientFill;
	} else {
		objBuffer[fill + GEObjectType] = GEPrimitiveLinearGradientFill;
	}
	objBuffer[fill + GEObjectIndex] = 0;
	objBuffer[fill + GEObjectLength] = fillSize;
	rampPtr = (objBuffer + fill) + GFRampOffset;
	if ((workBuffer[GWHasColorTransform]) != 0) {
		for (i = 0; i <= (rampWidth - 1); i += 1) {
			rampPtr[i] = (transformColor(ramp[i]));
		}
	} else {
		for (i = 0; i <= (rampWidth - 1); i += 1) {
			rampPtr[i] = (ramp[i]);
		}
	}
	objBuffer[fill + GFRampLength] = rampWidth;
	return fill;
}

static sqInt allocateLine(void) {
    sqInt line;

	if (!(allocateObjEntry(GLBaseSize))) {
		return 0;
	}
	line = objUsed;
	objUsed = line + GLBaseSize;
	objBuffer[line + GEObjectType] = GEPrimitiveLine;
	objBuffer[line + GEObjectIndex] = 0;
	objBuffer[line + GEObjectLength] = GLBaseSize;
	return line;
}


/*	Allocate n slots in the object buffer */

static sqInt allocateObjEntry(sqInt nSlots) {
    sqInt dstIndex;
    sqInt i;
    sqInt srcIndex;

	if (!(allocateGETEntry(nSlots))) {
		return 0;
	}
	if (!((workBuffer[GWGETUsed]) == 0)) {
		srcIndex = workBuffer[GWGETUsed];
		dstIndex = (workBuffer[GWGETUsed]) + nSlots;
		for (i = 1; i <= (workBuffer[GWGETUsed]); i += 1) {
			getBuffer[dstIndex -= 1] = (getBuffer[srcIndex -= 1]);
		}
	}
	getBuffer += nSlots;
	return 1;
}


/*	AET and Stack allocation are symmetric */

static sqInt allocateStackEntry(sqInt nSlots) {
	/* begin needAvailableSpace: */
	if (((((GWHeaderSize + objUsed) + (workBuffer[GWGETUsed])) + (workBuffer[GWAETUsed])) + nSlots) > (workBuffer[GWBufferTop])) {
		/* begin stopBecauseOf: */
		workBuffer[GWStopReason] = GErrorNoMoreSpace;
		engineStopped = 1;
		return 0;
	}
	return 1;
}

static sqInt allocateStackFillEntry(void) {
	/* begin wbStackPush: */
	if (!(needAvailableSpace(3))) {
		return 0;
	}
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) - 3);
	return 1;
}

static sqInt allocateWideBezier(void) {
    sqInt bezier;

	if (!(allocateObjEntry(GBWideSize))) {
		return 0;
	}
	bezier = objUsed;
	objUsed = bezier + GBWideSize;
	objBuffer[bezier + GEObjectType] = GEPrimitiveWideBezier;
	objBuffer[bezier + GEObjectIndex] = 0;
	objBuffer[bezier + GEObjectLength] = GBWideSize;
	return bezier;
}

static sqInt allocateWideLine(void) {
    sqInt line;

	if (!(allocateObjEntry(GLWideSize))) {
		return 0;
	}
	line = objUsed;
	objUsed = line + GLWideSize;
	objBuffer[line + GEObjectType] = GEPrimitiveWideLine;
	objBuffer[line + GEObjectIndex] = 0;
	objBuffer[line + GEObjectLength] = GLWideSize;
	return line;
}

static sqInt areEdgeFillsValid(sqInt edge) {
	return ((objBuffer[edge + GEObjectType]) & GEEdgeFillsInvalid) == 0;
}


/*	Make sure that val1 is between val2 and val3. */

static sqInt assureValuebetweenand(sqInt val1, sqInt val2, sqInt val3) {
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

static sqInt bezierEndXOf(sqInt bezier) {
	return objBuffer[bezier + GBEndX];
}

static sqInt bezierEndXOfput(sqInt bezier, sqInt value) {
	return objBuffer[bezier + GBEndX] = value;
}

static sqInt bezierEndYOf(sqInt bezier) {
	return objBuffer[bezier + GBEndY];
}

static sqInt bezierEndYOfput(sqInt bezier, sqInt value) {
	return objBuffer[bezier + GBEndY] = value;
}

static sqInt bezierFinalXOf(sqInt bezier) {
	return objBuffer[bezier + GBFinalX];
}

static sqInt bezierFinalXOfput(sqInt bezier, sqInt value) {
	return objBuffer[bezier + GBFinalX] = value;
}

static int * bezierUpdateDataOf(sqInt bezier) {
	return (objBuffer + bezier) + GBUpdateData;
}

static sqInt bezierViaXOf(sqInt bezier) {
	return objBuffer[bezier + GBViaX];
}

static sqInt bezierViaXOfput(sqInt bezier, sqInt value) {
	return objBuffer[bezier + GBViaX] = value;
}

static sqInt bezierViaYOf(sqInt bezier) {
	return objBuffer[bezier + GBViaY];
}

static sqInt bezierViaYOfput(sqInt bezier, sqInt value) {
	return objBuffer[bezier + GBViaY] = value;
}

static sqInt bitmapCmSizeOf(sqInt bmFill) {
	return objBuffer[bmFill + GBColormapSize];
}

static sqInt bitmapCmSizeOfput(sqInt bmFill, sqInt value) {
	return objBuffer[bmFill + GBColormapSize] = value;
}

static sqInt bitmapDepthOf(sqInt bmFill) {
	return objBuffer[bmFill + GBBitmapDepth];
}

static sqInt bitmapDepthOfput(sqInt bmFill, sqInt value) {
	return objBuffer[bmFill + GBBitmapDepth] = value;
}

static sqInt bitmapHeightOf(sqInt bmFill) {
	return objBuffer[bmFill + GBBitmapHeight];
}

static sqInt bitmapHeightOfput(sqInt bmFill, sqInt value) {
	return objBuffer[bmFill + GBBitmapHeight] = value;
}

static sqInt bitmapRasterOf(sqInt bmFill) {
	return objBuffer[bmFill + GBBitmapRaster];
}

static sqInt bitmapRasterOfput(sqInt bmFill, sqInt value) {
	return objBuffer[bmFill + GBBitmapRaster] = value;
}

static sqInt bitmapSizeOf(sqInt bmFill) {
	return objBuffer[bmFill + GBBitmapSize];
}

static sqInt bitmapSizeOfput(sqInt bmFill, sqInt value) {
	return objBuffer[bmFill + GBBitmapSize] = value;
}

static sqInt bitmapTileFlagOf(sqInt bmFill) {
	return objBuffer[bmFill + GBTileFlag];
}

static sqInt bitmapTileFlagOfput(sqInt bmFill, sqInt value) {
	return objBuffer[bmFill + GBTileFlag] = value;
}

static sqInt bitmapValuebitsatXy(sqInt bmFill, sqInt bits, sqInt xp, sqInt yp) {
    sqInt bmDepth;
    sqInt a;
    sqInt cMask;
    sqInt bmRaster;
    sqInt g;
    sqInt b;
    sqInt value;
    sqInt rShift;
    sqInt r;

	bmDepth = objBuffer[bmFill + GBBitmapDepth];
	bmRaster = objBuffer[bmFill + GBBitmapRaster];
	if (bmDepth == 32) {
		value = (((int*) bits))[(bmRaster * yp) + xp];
		if ((value != 0) && ((value & 4278190080U) == 0)) {
			value = value | 4278190080U;
		}
		return uncheckedTransformColor(value);
	}
	rShift = (rShiftTable())[bmDepth];

	/* cMask - mask out the pixel from the word */

	value = (((int*) bits))[(bmRaster * yp) + (((usqInt) xp) >> rShift)];

	/* rShift - shift value to move the pixel in the word to the lowest bit position */

	cMask = (1 << bmDepth) - 1;
	rShift = (32 - bmDepth) - ((xp & ((1 << rShift) - 1)) * bmDepth);
	value = (((usqInt) value) >> rShift) & cMask;
	if (bmDepth == 16) {
		if (!(value == 0)) {
			b = (value & 31) << 3;
			b += ((usqInt) b) >> 5;
			g = ((((usqInt) value) >> 5) & 31) << 3;
			g += ((usqInt) g) >> 5;
			r = ((((usqInt) value) >> 10) & 31) << 3;
			r += ((usqInt) r) >> 5;
			a = 255;
			value = ((b + (g << 8)) + (r << 16)) + (a << 24);
		}
	} else {
		if ((objBuffer[bmFill + GBColormapSize]) == 0) {
			value = 0;
		} else {
			value = ((objBuffer + bmFill) + GBColormapOffset)[value];
		}
	}
	return uncheckedTransformColor(value);
}

static sqInt bitmapWidthOf(sqInt bmFill) {
	return objBuffer[bmFill + GBBitmapWidth];
}

static sqInt bitmapWidthOfput(sqInt bmFill, sqInt value) {
	return objBuffer[bmFill + GBBitmapWidth] = value;
}

static sqInt bzEndX(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)];
}

static sqInt bzEndXput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)] = value;
}

static sqInt bzEndY(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)];
}

static sqInt bzEndYput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)] = value;
}

static sqInt bzStartX(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 0)];
}

static sqInt bzStartXput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 0)] = value;
}

static sqInt bzStartY(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)];
}

static sqInt bzStartYput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)] = value;
}

static sqInt bzViaX(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)];
}

static sqInt bzViaXput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)] = value;
}

static sqInt bzViaY(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)];
}

static sqInt bzViaYput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)] = value;
}


/*	Check the fill indexes in the run-length encoded fillList */

static sqInt checkCompressedFillIndexListmaxsegments(sqInt fillList, sqInt maxIndex, sqInt nSegs) {
    sqInt length;
    int * fillPtr;
    sqInt i;
    sqInt runValue;
    sqInt nFills;
    sqInt runLength;

	length = interpreterProxy->slotSizeOf(fillList);
	fillPtr = interpreterProxy->firstIndexableField(fillList);
	nFills = 0;
	for (i = 0; i <= (length - 1); i += 1) {
		runLength = ((usqInt) ((((int *) fillPtr))[i]) >> 16);
		runValue = ((((int *) fillPtr))[i]) & 65535;
		if (!((runValue >= 0) && (runValue <= maxIndex))) {
			return 0;
		}
		nFills += runLength;
	}
	return nFills == nSegs;
}


/*	Check if the indexList (containing fill handles) is okay. */

static sqInt checkCompressedFills(sqInt indexList) {
    int * fillPtr;
    sqInt length;
    sqInt i;
    sqInt fillIndex;

	if (!(interpreterProxy->isWords(indexList))) {
		return 0;
	}
	length = interpreterProxy->slotSizeOf(indexList);
	fillPtr = interpreterProxy->firstIndexableField(indexList);
	for (i = 0; i <= (length - 1); i += 1) {

		/* Make sure the fill is okay */

		fillIndex = fillPtr[i];
		if (!(isFillOkay(fillIndex))) {
			return 0;
		}
	}
	return 1;
}


/*	Check the run-length encoded lineWidthList matches nSegments */

static sqInt checkCompressedLineWidthssegments(sqInt lineWidthList, sqInt nSegments) {
    int * ptr;
    sqInt length;
    sqInt i;
    sqInt nItems;
    sqInt runLength;

	length = interpreterProxy->slotSizeOf(lineWidthList);
	ptr = interpreterProxy->firstIndexableField(lineWidthList);
	nItems = 0;
	for (i = 0; i <= (length - 1); i += 1) {
		runLength = ((usqInt) ((((int *) ptr))[i]) >> 16);
		nItems += runLength;
	}
	return nItems == nSegments;
}


/*	Check if the given point array can be handled by the engine. */

static sqInt checkCompressedPointssegments(sqInt points, sqInt nSegments) {
    sqInt pSize;

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

static sqInt checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(sqInt points, sqInt nSegments, sqInt leftFills, sqInt rightFills, sqInt lineWidths, sqInt lineFills, sqInt fillIndexList) {
    sqInt maxFillIndex;

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

static sqInt checkedAddBezierToGET(sqInt bezier) {
    sqInt lineWidth;

	if ((((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0) {
		lineWidth = objBuffer[bezier + GBWideExtent];
	} else {
		lineWidth = 0;
	}
	if (((objBuffer[bezier + GBEndY]) + lineWidth) < (workBuffer[GWFillMinY])) {
		return 0;
	}
	if ((((objBuffer[bezier + GEXValue]) - lineWidth) >= (workBuffer[GWFillMaxX])) && (((objBuffer[bezier + GBEndX]) - lineWidth) >= (workBuffer[GWFillMaxX]))) {
		return 0;
	}
	addEdgeToGET(bezier);
}


/*	Add the edge to the global edge table.
	For known edge types, check if the edge intersects the visible region */

static sqInt checkedAddEdgeToGET(sqInt edge) {
    sqInt lineWidth;
    sqInt lineWidth1;

	if ((((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWideMask) == GEPrimitiveLine) {
		/* begin checkedAddLineToGET: */
		if ((((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0) {
			lineWidth = objBuffer[edge + GLWideExtent];
		} else {
			lineWidth = 0;
		}
		if (((objBuffer[edge + GLEndY]) + lineWidth) < (workBuffer[GWFillMinY])) {
			return 0;
		}
		if ((((objBuffer[edge + GEXValue]) - lineWidth) >= (workBuffer[GWFillMaxX])) && (((objBuffer[edge + GLEndX]) - lineWidth) >= (workBuffer[GWFillMaxX]))) {
			return 0;
		}
		addEdgeToGET(edge);
		return null;
	}
	if ((((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWideMask) == GEPrimitiveBezier) {
		/* begin checkedAddBezierToGET: */
		if ((((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0) {
			lineWidth1 = objBuffer[edge + GBWideExtent];
		} else {
			lineWidth1 = 0;
		}
		if (((objBuffer[edge + GBEndY]) + lineWidth1) < (workBuffer[GWFillMinY])) {
			return 0;
		}
		if ((((objBuffer[edge + GEXValue]) - lineWidth1) >= (workBuffer[GWFillMaxX])) && (((objBuffer[edge + GBEndX]) - lineWidth1) >= (workBuffer[GWFillMaxX]))) {
			return 0;
		}
		addEdgeToGET(edge);
		return null;
	}
	addEdgeToGET(edge);
}


/*	Add the line to the global edge table if it intersects the clipping region */

static sqInt checkedAddLineToGET(sqInt line) {
    sqInt lineWidth;

	if ((((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0) {
		lineWidth = objBuffer[line + GLWideExtent];
	} else {
		lineWidth = 0;
	}
	if (((objBuffer[line + GLEndY]) + lineWidth) < (workBuffer[GWFillMinY])) {
		return 0;
	}
	if ((((objBuffer[line + GEXValue]) - lineWidth) >= (workBuffer[GWFillMaxX])) && (((objBuffer[line + GLEndX]) - lineWidth) >= (workBuffer[GWFillMaxX]))) {
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

static sqInt clampValuemax(sqInt value, sqInt maxValue) {
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

static sqInt clearSpanBuffer(void) {
    sqInt x1;
    sqInt x0;

	x0 = ((usqInt) (workBuffer[GWSpanStart])) >> (workBuffer[GWAAShift]);
	x1 = (((usqInt) (workBuffer[GWSpanEnd])) >> (workBuffer[GWAAShift])) + 1;
	if (x0 < 0) {
		x0 = 0;
	}
	if (x1 > (workBuffer[GWSpanSize])) {
		x1 = workBuffer[GWSpanSize];
	}
	while (x0 < x1) {
		spanBuffer[x0] = 0;
		x0 += 1;
	}
	workBuffer[GWSpanStart] = (workBuffer[GWSpanSize]);
	workBuffer[GWSpanEnd] = 0;
}

static sqInt clearSpanBufferGet(void) {
	return workBuffer[GWClearSpanBuffer];
}

static sqInt clearSpanBufferPut(sqInt value) {
	return workBuffer[GWClearSpanBuffer] = value;
}

static sqInt clipMaxXGet(void) {
	return workBuffer[GWClipMaxX];
}

static sqInt clipMaxXPut(sqInt value) {
	return workBuffer[GWClipMaxX] = value;
}

static sqInt clipMaxYGet(void) {
	return workBuffer[GWClipMaxY];
}

static sqInt clipMaxYPut(sqInt value) {
	return workBuffer[GWClipMaxY] = value;
}

static sqInt clipMinXGet(void) {
	return workBuffer[GWClipMinX];
}

static sqInt clipMinXPut(sqInt value) {
	return workBuffer[GWClipMinX] = value;
}

static sqInt clipMinYGet(void) {
	return workBuffer[GWClipMinY];
}

static sqInt clipMinYPut(sqInt value) {
	return workBuffer[GWClipMinY] = value;
}

static float * colorTransform(void) {
	return ((float *) (workBuffer + GWColorTransform));
}

static int * colormapOf(sqInt bmFill) {
	return (objBuffer + bmFill) + GBColormapOffset;
}


/*	Split the bezier curve at the given parametric value.
	Note: Since this method is only invoked to make non-monoton
		beziers monoton we must check for the resulting y values
		to be *really* between the start and end value. */

static sqInt computeBeziersplitAt(sqInt index, double  param) {
    sqInt endX;
    sqInt sharedY;
    sqInt leftViaY;
    sqInt rightViaX;
    sqInt viaY;
    sqInt startX;
    sqInt endY;
    sqInt rightViaY;
    sqInt sharedX;
    sqInt newIndex;
    sqInt startY;
    sqInt leftViaX;
    sqInt viaX;

	leftViaX = startX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 0)];
	leftViaY = startY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)];
	rightViaX = viaX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)];
	rightViaY = viaY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)];
	endX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)];

	/* Compute intermediate points */

	endY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)];
	sharedX = leftViaX += ((sqInt) ((((double) (viaX - startX) )) * param) );
	sharedY = leftViaY += ((sqInt) ((((double) (viaY - startY) )) * param) );
	rightViaX += ((sqInt) ((((double) (endX - viaX) )) * param) );

	/* Compute new shared point */

	rightViaY += ((sqInt) ((((double) (endY - viaY) )) * param) );
	sharedX += ((sqInt) ((((double) (rightViaX - leftViaX) )) * param) );

	/* Check the new via points */

	sharedY += ((sqInt) ((((double) (rightViaY - leftViaY) )) * param) );
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
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) - 6);
l3:	/* end wbStackPush: */;
	newIndex = (workBuffer[GWSize]) - (workBuffer[GWBufferTop]);
	if (engineStopped) {
		return 0;
	}
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)] = leftViaX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)] = leftViaY;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)] = sharedX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)] = sharedY;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 0)] = sharedX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 1)] = sharedY;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 2)] = rightViaX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 3)] = rightViaY;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 4)] = endX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 5)] = endY;
	return newIndex;
}


/*	Split the bezier curve at 0.5. */

static sqInt computeBezierSplitAtHalf(sqInt index) {
    sqInt endX;
    sqInt sharedY;
    sqInt leftViaY;
    sqInt rightViaX;
    sqInt viaY;
    sqInt startX;
    sqInt endY;
    sqInt rightViaY;
    sqInt sharedX;
    sqInt newIndex;
    sqInt startY;
    sqInt leftViaX;
    sqInt viaX;

	/* begin allocateBezierStackEntry */
	/* begin wbStackPush: */
	if (!(needAvailableSpace(6))) {
		goto l1;
	}
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) - 6);
l1:	/* end wbStackPush: */;
	newIndex = (workBuffer[GWSize]) - (workBuffer[GWBufferTop]);
	if (engineStopped) {
		return 0;
	}
	leftViaX = startX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 0)];
	leftViaY = startY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)];
	rightViaX = viaX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)];
	rightViaY = viaY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)];
	endX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)];

	/* Compute intermediate points */

	endY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)];
	leftViaX += ((sqInt) (viaX - startX) >> 1);
	leftViaY += ((sqInt) (viaY - startY) >> 1);
	sharedX = rightViaX += ((sqInt) (endX - viaX) >> 1);

	/* Compute new shared point */

	sharedY = rightViaY += ((sqInt) (endY - viaY) >> 1);
	sharedX += ((sqInt) (leftViaX - rightViaX) >> 1);

	/* Store the first part back */

	sharedY += ((sqInt) (leftViaY - rightViaY) >> 1);
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)] = leftViaX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)] = leftViaY;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)] = sharedX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)] = sharedY;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 0)] = sharedX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 1)] = sharedY;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 2)] = rightViaX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 3)] = rightViaY;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 4)] = endX;
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - newIndex) + 5)] = endY;
	return newIndex;
}


/*	Get both values from the two boundaries of the given bezier 
	and compute the actual position/width of the line */

static sqInt computeFinalWideBezierValueswidth(sqInt bezier, sqInt lineWidth) {
    sqInt leftX;
    sqInt rightX;
    sqInt temp;

	leftX = ((sqInt) (((objBuffer + bezier) + GBUpdateData)[GBUpdateX]) >> 8);
	rightX = ((sqInt) (((objBuffer + bezier) + GBWideUpdateData)[GBUpdateX]) >> 8);
	if (leftX > rightX) {
		temp = leftX;
		leftX = rightX;
		rightX = temp;
	}
	objBuffer[bezier + GEXValue] = leftX;
	if ((rightX - leftX) > lineWidth) {
		objBuffer[bezier + GBWideWidth] = (rightX - leftX);
	} else {
		objBuffer[bezier + GBWideWidth] = lineWidth;
	}
}

static sqInt computeSqrt(sqInt length2) {
	if (length2 < 32) {
		return (smallSqrtTable())[length2];
	} else {
		return ((sqInt) ((sqrt(((double) length2 ))) + 0.5) );
	}
}

static sqInt copyBitsFromtoat(sqInt x0, sqInt x1, sqInt yValue) {
	if (copyBitsFn == 0) {
		if (!(initialiseModule())) {
			return 0;
		}
	}
	return ((sqInt (*)(sqInt, sqInt, sqInt))copyBitsFn)(x0, x1, yValue);
}


/*	Create the global edge table */

static sqInt createGlobalEdgeTable(void) {
    sqInt object;
    sqInt end;
    sqInt lineWidth;
    sqInt lineWidth1;

	object = 0;
	end = objUsed;
	while (object < end) {
		if (isEdge(object)) {
			if (!((objBuffer[object + GEYValue]) >= (workBuffer[GWFillMaxY]))) {
				/* begin checkedAddEdgeToGET: */
				if ((((objBuffer[object + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWideMask) == GEPrimitiveLine) {
					/* begin checkedAddLineToGET: */
					if ((((objBuffer[object + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0) {
						lineWidth = objBuffer[object + GLWideExtent];
					} else {
						lineWidth = 0;
					}
					if (((objBuffer[object + GLEndY]) + lineWidth) < (workBuffer[GWFillMinY])) {
						goto l2;
					}
					if ((((objBuffer[object + GEXValue]) - lineWidth) >= (workBuffer[GWFillMaxX])) && (((objBuffer[object + GLEndX]) - lineWidth) >= (workBuffer[GWFillMaxX]))) {
						goto l2;
					}
					addEdgeToGET(object);
				l2:	/* end checkedAddLineToGET: */;
					goto l1;
				}
				if ((((objBuffer[object + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWideMask) == GEPrimitiveBezier) {
					/* begin checkedAddBezierToGET: */
					if ((((objBuffer[object + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0) {
						lineWidth1 = objBuffer[object + GBWideExtent];
					} else {
						lineWidth1 = 0;
					}
					if (((objBuffer[object + GBEndY]) + lineWidth1) < (workBuffer[GWFillMinY])) {
						goto l3;
					}
					if ((((objBuffer[object + GEXValue]) - lineWidth1) >= (workBuffer[GWFillMaxX])) && (((objBuffer[object + GBEndX]) - lineWidth1) >= (workBuffer[GWFillMaxX]))) {
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
		object += objBuffer[object + GEObjectLength];
	}
}

static sqInt currentYGet(void) {
	return workBuffer[GWCurrentY];
}

static sqInt currentYPut(sqInt value) {
	return workBuffer[GWCurrentY] = value;
}

static sqInt currentZGet(void) {
	return workBuffer[GWCurrentZ];
}

static sqInt currentZPut(sqInt value) {
	return workBuffer[GWCurrentZ] = value;
}

static sqInt destOffsetXGet(void) {
	return workBuffer[GWDestOffsetX];
}

static sqInt destOffsetXPut(sqInt value) {
	return workBuffer[GWDestOffsetX] = value;
}

static sqInt destOffsetYGet(void) {
	return workBuffer[GWDestOffsetY];
}

static sqInt destOffsetYPut(sqInt value) {
	return workBuffer[GWDestOffsetY] = value;
}


/*	Display the span buffer at the current scan line. */

static sqInt displaySpanBufferAt(sqInt y) {
    sqInt targetX1;
    sqInt targetY;
    sqInt targetX0;

	targetX0 = ((usqInt) (workBuffer[GWSpanStart])) >> (workBuffer[GWAAShift]);
	if (targetX0 < (workBuffer[GWClipMinX])) {
		targetX0 = workBuffer[GWClipMinX];
	}
	targetX1 = ((usqInt) (((workBuffer[GWSpanEnd]) + (workBuffer[GWAALevel])) - 1)) >> (workBuffer[GWAAShift]);
	if (targetX1 > (workBuffer[GWClipMaxX])) {
		targetX1 = workBuffer[GWClipMaxX];
	}
	targetY = ((usqInt) y) >> (workBuffer[GWAAShift]);
	if ((targetY < (workBuffer[GWClipMinY])) || ((targetY >= (workBuffer[GWClipMaxY])) || ((targetX1 < (workBuffer[GWClipMinX])) || (targetX0 >= (workBuffer[GWClipMaxX]))))) {
		return 0;
	}
	copyBitsFromtoat(targetX0, targetX1, targetY);
}


/*	Draw the given edge starting from leftX with the edge's fill.
	Return the end value of the drawing operation. */

static sqInt drawWideEdgefrom(sqInt edge, sqInt leftX) {
    sqInt lineWidth;
    sqInt rightX;
    sqInt fill;
    sqInt type;

	type = ((usqInt) ((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask)) >> 1;
	dispatchedValue = edge;
	switch (type) {
	case 0:
	case 1:
		errorWrongIndex();
		break;
	case 2:
		dispatchReturnValue = objBuffer[dispatchedValue + GLWideWidth];
		break;
	case 3:
		dispatchReturnValue = objBuffer[dispatchedValue + GBWideWidth];
		break;
	}
	lineWidth = dispatchReturnValue;
	switch (type) {
	case 0:
	case 1:
		errorWrongIndex();
		break;
	case 2:
		dispatchReturnValue = objBuffer[dispatchedValue + GLWideFill];
		break;
	case 3:
		dispatchReturnValue = objBuffer[dispatchedValue + GBWideFill];
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

static sqInt edgeFillsInvalidate(sqInt edge) {
	return objBuffer[edge + GEObjectType] = (((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask) | GEEdgeFillsInvalid);
}

static sqInt edgeFillsValidate(sqInt edge) {
	return objBuffer[edge + GEObjectType] = (((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask) & (~GEEdgeFillsInvalid));
}

static sqInt edgeLeftFillOf(sqInt edge) {
	return objBuffer[edge + GEFillIndexLeft];
}

static sqInt edgeLeftFillOfput(sqInt edge, sqInt value) {
	return objBuffer[edge + GEFillIndexLeft] = value;
}

static sqInt edgeNumLinesOf(sqInt edge) {
	return objBuffer[edge + GENumLines];
}

static sqInt edgeNumLinesOfput(sqInt edge, sqInt value) {
	return objBuffer[edge + GENumLines] = value;
}

static sqInt edgeRightFillOf(sqInt edge) {
	return objBuffer[edge + GEFillIndexRight];
}

static sqInt edgeRightFillOfput(sqInt edge, sqInt value) {
	return objBuffer[edge + GEFillIndexRight] = value;
}

static float * edgeTransform(void) {
	return ((float *) (workBuffer + GWEdgeTransform));
}


/*	Return the edge type (e.g., witout the wide edge flag) */

static sqInt edgeTypeOf(sqInt edge) {
	return ((usqInt) ((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask)) >> 1;
}

static sqInt edgeXValueOf(sqInt edge) {
	return objBuffer[edge + GEXValue];
}

static sqInt edgeXValueOfput(sqInt edge, sqInt value) {
	return objBuffer[edge + GEXValue] = value;
}

static sqInt edgeYValueOf(sqInt edge) {
	return objBuffer[edge + GEYValue];
}

static sqInt edgeYValueOfput(sqInt edge, sqInt value) {
	return objBuffer[edge + GEYValue] = value;
}

static sqInt edgeZValueOf(sqInt edge) {
	return objBuffer[edge + GEZValue];
}

static sqInt edgeZValueOfput(sqInt edge, sqInt value) {
	return objBuffer[edge + GEZValue] = value;
}


/*	Ignore dispatch errors when translating to C
	(since we have no entry point for #error in the VM proxy) */

static sqInt errorWrongIndex(void) {
	;
}


/*	Estimate the length of the vector described by deltaX and deltaY.
	This method may be extremely inaccurate - use it only
	if you know exactly that this doesn't matter. Otherwise
	use #accurateLengthOf:width: */

static sqInt estimatedLengthOfwith(sqInt deltaX, sqInt deltaY) {
    sqInt absDy;
    sqInt absDx;

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
		return absDx + (((sqInt) absDy >> 1));
	} else {
		return absDy + (((sqInt) absDx >> 1));
	}
}


/*	Fill the span buffer from leftX to rightX with the given fill. */

static sqInt fillAllFromto(sqInt leftX, sqInt rightX) {
    sqInt startX;
    sqInt stopX;
    sqInt fill;
    sqInt someIntegerValue;
    sqInt someIntegerValue1;

	/* begin topFill */
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		fill = 0;
		goto l5;
	} else {
		fill = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
		goto l5;
	}
l5:	/* end topFill */;
	startX = leftX;
	/* begin topRightX */
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		stopX = 999999999;
		goto l3;
	} else {
		stopX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)];
		goto l3;
	}
l3:	/* end topRightX */;
	while (stopX < rightX) {
		/* begin makeUnsignedFrom: */
		/* begin topFill */
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			someIntegerValue = 0;
			goto l4;
		} else {
			someIntegerValue = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
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
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			goto l1;
		}
		while ((topRightX()) <= stopX) {
			hideFilldepth(topFill(), topDepth());
			if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
				goto l1;
			}
		}
	l1:	/* end quickRemoveInvalidFillsAt: */;
		startX = stopX;
		/* begin topRightX */
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			stopX = 999999999;
			goto l2;
		} else {
			stopX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)];
			goto l2;
		}
	l2:	/* end topRightX */;
	}
	/* begin makeUnsignedFrom: */
	/* begin topFill */
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		someIntegerValue1 = 0;
		goto l6;
	} else {
		someIntegerValue1 = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
		goto l6;
	}
l6:	/* end topFill */;
	fill = someIntegerValue1;
	if (!(fill == 0)) {
		return fillSpanfromto(fill, startX, rightX);
	}
	return 0;
}

static sqInt fillBitmapSpan(void) {
	return fillBitmapSpanfromtoat(workBuffer[GWLastExportedFill], workBuffer[GWLastExportedLeftX], workBuffer[GWLastExportedRightX], workBuffer[GWCurrentY]);
}


/*	Fill the span buffer between leftEdge and rightEdge using the given bits.
	Note: We always start from zero - this avoids using huge bitmap buffers if the bitmap is to be displayed at the very far right hand side and also gives us a chance of using certain bitmaps (e.g., those with depth 32) directly. */

static sqInt fillBitmapSpanfromto(int * bits, sqInt leftX, sqInt rightX) {
    sqInt colorShift;
    sqInt x1;
    sqInt fillValue;
    sqInt x;
    sqInt bitX;
    sqInt x0;
    sqInt baseShift;
    sqInt colorMask;

	x0 = leftX;
	x1 = rightX;

	/* Hack for pre-increment */

	bitX = -1;
	if ((workBuffer[GWAALevel]) == 1) {
		while (x0 < x1) {
			fillValue = (((int *) bits))[bitX += 1];
			spanBuffer[x0] = fillValue;
			x0 += 1;
		}
	} else {
		colorMask = workBuffer[GWAAColorMask];
		colorShift = workBuffer[GWAAColorShift];
		baseShift = workBuffer[GWAAShift];
		while (x0 < x1) {
			x = ((usqInt) x0) >> baseShift;
			fillValue = (((int *) bits))[bitX += 1];
			fillValue = ((usqInt) (fillValue & colorMask)) >> colorShift;
			spanBuffer[x] = ((spanBuffer[x]) + fillValue);
			x0 += 1;
		}
	}
	if (x1 > (workBuffer[GWSpanEnd])) {
		workBuffer[GWSpanEnd] = x1;
	}
	if (x1 > (workBuffer[GWSpanEndAA])) {
		workBuffer[GWSpanEndAA] = x1;
	}
}

static sqInt fillBitmapSpanfromtoat(sqInt bmFill, sqInt leftX, sqInt rightX, sqInt yValue) {
    sqInt dtX;
    sqInt x1;
    int * bits;
    sqInt fillValue;
    sqInt ds;
    sqInt x;
    sqInt deltaX;
    sqInt bmHeight;
    sqInt yp;
    sqInt tileFlag;
    sqInt xp;
    sqInt dt;
    sqInt deltaY;
    sqInt bmWidth;
    sqInt dsX;
    sqInt newDelta;
    sqInt newDelta1;
    sqInt bmDepth;
    sqInt a;
    sqInt cMask;
    sqInt bmRaster;
    sqInt g;
    sqInt b;
    sqInt value;
    sqInt rShift;
    sqInt r;

	if (!((workBuffer[GWAALevel]) == 1)) {
		return fillBitmapSpanAAfromtoat(bmFill, leftX, rightX, yValue);
	}
	bits = loadBitsFrom(bmFill);
	if (bits == null) {
		return null;
	}
	bmWidth = objBuffer[bmFill + GBBitmapWidth];
	bmHeight = objBuffer[bmFill + GBBitmapHeight];
	tileFlag = (objBuffer[bmFill + GBTileFlag]) == 1;
	deltaX = leftX - (objBuffer[bmFill + GFOriginX]);
	deltaY = yValue - (objBuffer[bmFill + GFOriginY]);
	dsX = objBuffer[bmFill + GFDirectionX];
	dtX = objBuffer[bmFill + GFNormalX];
	ds = (deltaX * dsX) + (deltaY * (objBuffer[bmFill + GFDirectionY]));
	dt = (deltaX * dtX) + (deltaY * (objBuffer[bmFill + GFNormalY]));
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
		xp = ((sqInt) ds >> 16);
		yp = ((sqInt) dt >> 16);
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
			bmDepth = objBuffer[bmFill + GBBitmapDepth];
			bmRaster = objBuffer[bmFill + GBBitmapRaster];
			if (bmDepth == 32) {
				value = (((int*) bits))[(bmRaster * yp) + xp];
				if ((value != 0) && ((value & 4278190080U) == 0)) {
					value = value | 4278190080U;
				}
				fillValue = uncheckedTransformColor(value);
				goto l3;
			}
			rShift = (rShiftTable())[bmDepth];
			value = (((int*) bits))[(bmRaster * yp) + (((usqInt) xp) >> rShift)];
			cMask = (1 << bmDepth) - 1;
			rShift = (32 - bmDepth) - ((xp & ((1 << rShift) - 1)) * bmDepth);
			value = (((usqInt) value) >> rShift) & cMask;
			if (bmDepth == 16) {
				if (!(value == 0)) {
					b = (value & 31) << 3;
					b += ((usqInt) b) >> 5;
					g = ((((usqInt) value) >> 5) & 31) << 3;
					g += ((usqInt) g) >> 5;
					r = ((((usqInt) value) >> 10) & 31) << 3;
					r += ((usqInt) r) >> 5;
					a = 255;
					value = ((b + (g << 8)) + (r << 16)) + (a << 24);
				}
			} else {
				if ((objBuffer[bmFill + GBColormapSize]) == 0) {
					value = 0;
				} else {
					value = ((objBuffer + bmFill) + GBColormapOffset)[value];
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

static sqInt fillBitmapSpanAAfromtoat(sqInt bmFill, sqInt leftX, sqInt rightX, sqInt yValue) {
    sqInt cShift;
    sqInt dtX;
    sqInt firstPixel;
    int * bits;
    sqInt fillValue;
    sqInt cMask;
    sqInt ds;
    sqInt x;
    sqInt deltaX;
    sqInt bmHeight;
    sqInt idx;
    sqInt yp;
    sqInt tileFlag;
    sqInt xp;
    sqInt lastPixel;
    sqInt dt;
    sqInt deltaY;
    sqInt bmWidth;
    sqInt baseShift;
    sqInt dsX;
    sqInt aaLevel;
    sqInt newDelta;
    sqInt newDelta1;
    sqInt newDelta2;
    sqInt newDelta3;
    sqInt newDelta4;
    sqInt newDelta5;
    sqInt firstPixel1;
    sqInt bmDepth;
    sqInt a;
    sqInt cMask1;
    sqInt bmRaster;
    sqInt g;
    sqInt b;
    sqInt value;
    sqInt rShift;
    sqInt r;
    sqInt bmDepth1;
    sqInt a1;
    sqInt cMask2;
    sqInt bmRaster1;
    sqInt g1;
    sqInt b1;
    sqInt value1;
    sqInt rShift1;
    sqInt r1;
    sqInt bmDepth2;
    sqInt a2;
    sqInt cMask3;
    sqInt bmRaster2;
    sqInt g2;
    sqInt b2;
    sqInt value2;
    sqInt rShift2;
    sqInt r2;

	bits = loadBitsFrom(bmFill);
	if (bits == null) {
		return null;
	}
	bmWidth = objBuffer[bmFill + GBBitmapWidth];
	bmHeight = objBuffer[bmFill + GBBitmapHeight];
	tileFlag = (objBuffer[bmFill + GBTileFlag]) == 1;
	deltaX = leftX - (objBuffer[bmFill + GFOriginX]);
	deltaY = yValue - (objBuffer[bmFill + GFOriginY]);
	dsX = objBuffer[bmFill + GFDirectionX];
	dtX = objBuffer[bmFill + GFNormalX];
	ds = (deltaX * dsX) + (deltaY * (objBuffer[bmFill + GFDirectionY]));
	dt = (deltaX * dtX) + (deltaY * (objBuffer[bmFill + GFNormalY]));
	aaLevel = workBuffer[GWAALevel];
	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[GWAALevel])) - 1) & (~((workBuffer[GWAALevel]) - 1));
	if (firstPixel1 > rightX) {
		firstPixel = rightX;
		goto l7;
	} else {
		firstPixel = firstPixel1;
		goto l7;
	}
l7:	/* end aaFirstPixelFrom:to: */;
	lastPixel = (rightX - 1) & (~((workBuffer[GWAALevel]) - 1));
	baseShift = workBuffer[GWAAShift];
	cMask = workBuffer[GWAAColorMask];
	cShift = workBuffer[GWAAColorShift];
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
		xp = ((sqInt) ds >> 16);
		yp = ((sqInt) dt >> 16);
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
			bmDepth = objBuffer[bmFill + GBBitmapDepth];
			bmRaster = objBuffer[bmFill + GBBitmapRaster];
			if (bmDepth == 32) {
				value = (((int*) bits))[(bmRaster * yp) + xp];
				if ((value != 0) && ((value & 4278190080U) == 0)) {
					value = value | 4278190080U;
				}
				fillValue = uncheckedTransformColor(value);
				goto l8;
			}
			rShift = (rShiftTable())[bmDepth];
			value = (((int*) bits))[(bmRaster * yp) + (((usqInt) xp) >> rShift)];
			cMask1 = (1 << bmDepth) - 1;
			rShift = (32 - bmDepth) - ((xp & ((1 << rShift) - 1)) * bmDepth);
			value = (((usqInt) value) >> rShift) & cMask1;
			if (bmDepth == 16) {
				if (!(value == 0)) {
					b = (value & 31) << 3;
					b += ((usqInt) b) >> 5;
					g = ((((usqInt) value) >> 5) & 31) << 3;
					g += ((usqInt) g) >> 5;
					r = ((((usqInt) value) >> 10) & 31) << 3;
					r += ((usqInt) r) >> 5;
					a = 255;
					value = ((b + (g << 8)) + (r << 16)) + (a << 24);
				}
			} else {
				if ((objBuffer[bmFill + GBColormapSize]) == 0) {
					value = 0;
				} else {
					value = ((objBuffer + bmFill) + GBColormapOffset)[value];
				}
			}
			fillValue = uncheckedTransformColor(value);
		l8:	/* end bitmapValue:bits:atX:y: */;
			fillValue = ((usqInt) (fillValue & cMask)) >> cShift;
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + fillValue);
		}
		ds += dsX;
		dt += dtX;
		x += 1;
	}
	cMask = (((usqInt) (workBuffer[GWAAColorMask])) >> (workBuffer[GWAAShift])) | 4042322160U;
	cShift = workBuffer[GWAAShift];
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
		xp = ((sqInt) ds >> 16);
		yp = ((sqInt) dt >> 16);
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
			bmDepth1 = objBuffer[bmFill + GBBitmapDepth];
			bmRaster1 = objBuffer[bmFill + GBBitmapRaster];
			if (bmDepth1 == 32) {
				value1 = (((int*) bits))[(bmRaster1 * yp) + xp];
				if ((value1 != 0) && ((value1 & 4278190080U) == 0)) {
					value1 = value1 | 4278190080U;
				}
				fillValue = uncheckedTransformColor(value1);
				goto l9;
			}
			rShift1 = (rShiftTable())[bmDepth1];
			value1 = (((int*) bits))[(bmRaster1 * yp) + (((usqInt) xp) >> rShift1)];
			cMask2 = (1 << bmDepth1) - 1;
			rShift1 = (32 - bmDepth1) - ((xp & ((1 << rShift1) - 1)) * bmDepth1);
			value1 = (((usqInt) value1) >> rShift1) & cMask2;
			if (bmDepth1 == 16) {
				if (!(value1 == 0)) {
					b1 = (value1 & 31) << 3;
					b1 += ((usqInt) b1) >> 5;
					g1 = ((((usqInt) value1) >> 5) & 31) << 3;
					g1 += ((usqInt) g1) >> 5;
					r1 = ((((usqInt) value1) >> 10) & 31) << 3;
					r1 += ((usqInt) r1) >> 5;
					a1 = 255;
					value1 = ((b1 + (g1 << 8)) + (r1 << 16)) + (a1 << 24);
				}
			} else {
				if ((objBuffer[bmFill + GBColormapSize]) == 0) {
					value1 = 0;
				} else {
					value1 = ((objBuffer + bmFill) + GBColormapOffset)[value1];
				}
			}
			fillValue = uncheckedTransformColor(value1);
		l9:	/* end bitmapValue:bits:atX:y: */;
			fillValue = ((usqInt) (fillValue & cMask)) >> cShift;
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + fillValue);
		}
		ds += dsX << cShift;
		dt += dtX << cShift;
		x += aaLevel;
	}
	cMask = workBuffer[GWAAColorMask];
	cShift = workBuffer[GWAAColorShift];
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
		xp = ((sqInt) ds >> 16);
		yp = ((sqInt) dt >> 16);
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
			bmDepth2 = objBuffer[bmFill + GBBitmapDepth];
			bmRaster2 = objBuffer[bmFill + GBBitmapRaster];
			if (bmDepth2 == 32) {
				value2 = (((int*) bits))[(bmRaster2 * yp) + xp];
				if ((value2 != 0) && ((value2 & 4278190080U) == 0)) {
					value2 = value2 | 4278190080U;
				}
				fillValue = uncheckedTransformColor(value2);
				goto l10;
			}
			rShift2 = (rShiftTable())[bmDepth2];
			value2 = (((int*) bits))[(bmRaster2 * yp) + (((usqInt) xp) >> rShift2)];
			cMask3 = (1 << bmDepth2) - 1;
			rShift2 = (32 - bmDepth2) - ((xp & ((1 << rShift2) - 1)) * bmDepth2);
			value2 = (((usqInt) value2) >> rShift2) & cMask3;
			if (bmDepth2 == 16) {
				if (!(value2 == 0)) {
					b2 = (value2 & 31) << 3;
					b2 += ((usqInt) b2) >> 5;
					g2 = ((((usqInt) value2) >> 5) & 31) << 3;
					g2 += ((usqInt) g2) >> 5;
					r2 = ((((usqInt) value2) >> 10) & 31) << 3;
					r2 += ((usqInt) r2) >> 5;
					a2 = 255;
					value2 = ((b2 + (g2 << 8)) + (r2 << 16)) + (a2 << 24);
				}
			} else {
				if ((objBuffer[bmFill + GBColormapSize]) == 0) {
					value2 = 0;
				} else {
					value2 = ((objBuffer + bmFill) + GBColormapOffset)[value2];
				}
			}
			fillValue = uncheckedTransformColor(value2);
		l10:	/* end bitmapValue:bits:atX:y: */;
			fillValue = ((usqInt) (fillValue & cMask)) >> cShift;
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + fillValue);
		}
		ds += dsX;
		dt += dtX;
		x += 1;
	}
}


/*	Fill the span buffer between leftEdge and rightEdge with the given pixel value. */

static sqInt fillColorSpanfromto(sqInt pixelValue32, sqInt leftX, sqInt rightX) {
    sqInt x1;
    sqInt x0;

	if (!((workBuffer[GWAALevel]) == 1)) {
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

static sqInt fillColorSpanAAx0x1(sqInt pixelValue32, sqInt leftX, sqInt rightX) {
    sqInt firstPixel;
    sqInt x;
    sqInt idx;
    sqInt pv32;
    sqInt lastPixel;
    sqInt baseShift;
    sqInt colorMask;
    sqInt aaLevel;
    sqInt firstPixel1;

	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[GWAALevel])) - 1) & (~((workBuffer[GWAALevel]) - 1));
	if (firstPixel1 > rightX) {
		firstPixel = rightX;
		goto l1;
	} else {
		firstPixel = firstPixel1;
		goto l1;
	}
l1:	/* end aaFirstPixelFrom:to: */;
	lastPixel = (rightX - 1) & (~((workBuffer[GWAALevel]) - 1));
	aaLevel = workBuffer[GWAALevel];
	baseShift = workBuffer[GWAAShift];

	/* Part a: Deal with the first n sub-pixels */

	x = leftX;
	if (x < firstPixel) {
		pv32 = ((usqInt) (pixelValue32 & (workBuffer[GWAAColorMask]))) >> (workBuffer[GWAAColorShift]);
		while (x < firstPixel) {
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + pv32);
			x += 1;
		}
	}
	if (x < lastPixel) {
		colorMask = (((usqInt) (workBuffer[GWAAColorMask])) >> (workBuffer[GWAAShift])) | 4042322160U;
		pv32 = ((usqInt) (pixelValue32 & colorMask)) >> (workBuffer[GWAAShift]);
		while (x < lastPixel) {
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + pv32);
			x += aaLevel;
		}
	}
	if (x < rightX) {
		pv32 = ((usqInt) (pixelValue32 & (workBuffer[GWAAColorMask]))) >> (workBuffer[GWAAColorShift]);
		while (x < rightX) {
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + pv32);
			x += 1;
		}
	}
}

static sqInt fillDirectionXOf(sqInt fill) {
	return objBuffer[fill + GFDirectionX];
}

static sqInt fillDirectionXOfput(sqInt fill, sqInt value) {
	return objBuffer[fill + GFDirectionX] = value;
}

static sqInt fillDirectionYOf(sqInt fill) {
	return objBuffer[fill + GFDirectionY];
}

static sqInt fillDirectionYOfput(sqInt fill, sqInt value) {
	return objBuffer[fill + GFDirectionY] = value;
}

static sqInt fillLinearGradient(void) {
	return fillLinearGradientfromtoat(workBuffer[GWLastExportedFill], workBuffer[GWLastExportedLeftX], workBuffer[GWLastExportedRightX], workBuffer[GWCurrentY]);
}


/*	Draw a linear gradient fill. */

static sqInt fillLinearGradientfromtoat(sqInt fill, sqInt leftX, sqInt rightX, sqInt yValue) {
    sqInt x1;
    sqInt ds;
    sqInt x;
    sqInt rampIndex;
    sqInt rampSize;
    sqInt x0;
    int * ramp;
    sqInt dsX;
    sqInt x11;
    sqInt x01;
    sqInt x12;
    sqInt x02;

	ramp = (objBuffer + fill) + GFRampOffset;
	rampSize = objBuffer[fill + GFRampLength];
	dsX = objBuffer[fill + GFDirectionX];
	ds = ((leftX - (objBuffer[fill + GFOriginX])) * dsX) + ((yValue - (objBuffer[fill + GFOriginY])) * (objBuffer[fill + GFDirectionY]));
	x = x0 = leftX;

	/* Note: The inner loop has been divided into three parts for speed */
	/* Part one: Fill everything outside the left boundary */

	x1 = rightX;
	while ((((rampIndex = ((sqInt) ds >> 16)) < 0) || (rampIndex >= rampSize)) && (x < x1)) {
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
		if (!((workBuffer[GWAALevel]) == 1)) {
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
	if ((workBuffer[GWAALevel]) == 1) {
		while ((((rampIndex = ((sqInt) ds >> 16)) < rampSize) && (rampIndex >= 0)) && (x < x1)) {
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
		if (!((workBuffer[GWAALevel]) == 1)) {
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

static sqInt fillLinearGradientAArampdsdsXfromto(sqInt fill, int * ramp, sqInt deltaS, sqInt dsX, sqInt leftX, sqInt rightX) {
    sqInt aaLevel;
    sqInt firstPixel;
    sqInt colorShift;
    sqInt ds;
    sqInt x;
    sqInt idx;
    sqInt rampIndex;
    sqInt lastPixel;
    sqInt rampSize;
    sqInt rampValue;
    sqInt baseShift;
    sqInt colorMask;
    sqInt firstPixel1;

	aaLevel = workBuffer[GWAALevel];
	baseShift = workBuffer[GWAAShift];
	rampSize = objBuffer[fill + GFRampLength];
	ds = deltaS;
	x = leftX;
	rampIndex = ((sqInt) ds >> 16);
	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[GWAALevel])) - 1) & (~((workBuffer[GWAALevel]) - 1));
	if (firstPixel1 > rightX) {
		firstPixel = rightX;
		goto l1;
	} else {
		firstPixel = firstPixel1;
		goto l1;
	}
l1:	/* end aaFirstPixelFrom:to: */;

	/* Deal with the first n sub-pixels */

	lastPixel = (rightX - 1) & (~((workBuffer[GWAALevel]) - 1));
	colorMask = workBuffer[GWAAColorMask];
	colorShift = workBuffer[GWAAColorShift];
	while ((x < firstPixel) && ((rampIndex < rampSize) && (rampIndex >= 0))) {
		rampValue = (((int *) ramp))[rampIndex];

		/* Copy as many pixels as possible */

		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while ((x < firstPixel) && ((((sqInt) ds >> 16)) == rampIndex)) {
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + rampValue);
			x += 1;
			ds += dsX;
		}
		rampIndex = ((sqInt) ds >> 16);
	}
	colorMask = (((usqInt) (workBuffer[GWAAColorMask])) >> (workBuffer[GWAAShift])) | 4042322160U;
	colorShift = workBuffer[GWAAShift];
	while ((x < lastPixel) && ((rampIndex < rampSize) && (rampIndex >= 0))) {
		rampValue = (((int *) ramp))[rampIndex];

		/* Copy as many pixels as possible */

		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while ((x < lastPixel) && ((((sqInt) ds >> 16)) == rampIndex)) {
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + rampValue);
			x += aaLevel;
			ds += dsX << colorShift;
		}
		rampIndex = ((sqInt) ds >> 16);
	}
	colorMask = workBuffer[GWAAColorMask];
	colorShift = workBuffer[GWAAColorShift];
	while ((x < rightX) && ((rampIndex < rampSize) && (rampIndex >= 0))) {
		rampValue = (((int *) ramp))[rampIndex];

		/* Copy as many pixels as possible */

		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while ((x < rightX) && ((((sqInt) ds >> 16)) == rampIndex)) {
			idx = ((usqInt) x) >> baseShift;
			spanBuffer[idx] = ((spanBuffer[idx]) + rampValue);
			x += 1;
			ds += dsX;
		}
		rampIndex = ((sqInt) ds >> 16);
	}
	return x;
}

static sqInt fillMaxXGet(void) {
	return workBuffer[GWFillMaxX];
}

static sqInt fillMaxXPut(sqInt value) {
	return workBuffer[GWFillMaxX] = value;
}

static sqInt fillMaxYGet(void) {
	return workBuffer[GWFillMaxY];
}

static sqInt fillMaxYPut(sqInt value) {
	return workBuffer[GWFillMaxY] = value;
}

static sqInt fillMinXGet(void) {
	return workBuffer[GWFillMinX];
}

static sqInt fillMinXPut(sqInt value) {
	return workBuffer[GWFillMinX] = value;
}

static sqInt fillMinYGet(void) {
	return workBuffer[GWFillMinY];
}

static sqInt fillMinYPut(sqInt value) {
	return workBuffer[GWFillMinY] = value;
}

static sqInt fillNormalXOf(sqInt fill) {
	return objBuffer[fill + GFNormalX];
}

static sqInt fillNormalXOfput(sqInt fill, sqInt value) {
	return objBuffer[fill + GFNormalX] = value;
}

static sqInt fillNormalYOf(sqInt fill) {
	return objBuffer[fill + GFNormalY];
}

static sqInt fillNormalYOfput(sqInt fill, sqInt value) {
	return objBuffer[fill + GFNormalY] = value;
}

static sqInt fillOffsetXGet(void) {
	return workBuffer[GWFillOffsetX];
}

static sqInt fillOffsetXPut(sqInt value) {
	return workBuffer[GWFillOffsetX] = value;
}

static sqInt fillOffsetYGet(void) {
	return workBuffer[GWFillOffsetY];
}

static sqInt fillOffsetYPut(sqInt value) {
	return workBuffer[GWFillOffsetY] = value;
}

static sqInt fillOriginXOf(sqInt fill) {
	return objBuffer[fill + GFOriginX];
}

static sqInt fillOriginXOfput(sqInt fill, sqInt value) {
	return objBuffer[fill + GFOriginX] = value;
}

static sqInt fillOriginYOf(sqInt fill) {
	return objBuffer[fill + GFOriginY];
}

static sqInt fillOriginYOfput(sqInt fill, sqInt value) {
	return objBuffer[fill + GFOriginY] = value;
}


/*	Part 2a) Compute the decreasing part of the ramp */

static sqInt fillRadialDecreasingrampdeltaSTdsXdtXfromto(sqInt fill, sqInt ramp, sqInt deltaST, sqInt dsX, sqInt dtX, sqInt leftX, sqInt rightX) {
    sqInt x1;
    sqInt ds;
    sqInt x;
    sqInt rampIndex;
    sqInt dt;
    sqInt length2;
    sqInt rampValue;
    sqInt nextLength;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	rampIndex = accurateLengthOfwith(((sqInt) ds >> 16), ((sqInt) dt >> 16));
	rampValue = (((int *) ramp))[rampIndex];
	length2 = (rampIndex - 1) * (rampIndex - 1);
	x = leftX;
	x1 = rightX;
	if (x1 > (objBuffer[fill + GFOriginX])) {
		x1 = objBuffer[fill + GFOriginX];
	}
	while (x < x1) {
		while ((x < x1) && ((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) >= length2)) {
			spanBuffer[x] = rampValue;
			x += 1;
			ds += dsX;
			dt += dtX;
		}
		nextLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
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

static sqInt fillRadialDecreasingAArampdeltaSTdsXdtXfromto(sqInt fill, int * ramp,  int * deltaST, sqInt dsX, sqInt dtX, sqInt leftX, sqInt rightX) {
    sqInt colorShift;
    sqInt baseShift;
    sqInt x1;
    sqInt firstPixel;
    sqInt ds;
    sqInt x;
    sqInt index;
    sqInt rampIndex;
    sqInt lastPixel;
    sqInt dt;
    sqInt length2;
    sqInt rampValue;
    sqInt nextLength;
    sqInt aaLevel;
    sqInt colorMask;
    sqInt firstPixel1;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	aaLevel = workBuffer[GWAALevel];
	baseShift = workBuffer[GWAAShift];
	rampIndex = accurateLengthOfwith(((sqInt) ds >> 16), ((sqInt) dt >> 16));
	length2 = (rampIndex - 1) * (rampIndex - 1);
	x = leftX;
	x1 = objBuffer[fill + GFOriginX];
	if (x1 > rightX) {
		x1 = rightX;
	}
	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[GWAALevel])) - 1) & (~((workBuffer[GWAALevel]) - 1));
	if (firstPixel1 > x1) {
		firstPixel = x1;
		goto l1;
	} else {
		firstPixel = firstPixel1;
		goto l1;
	}
l1:	/* end aaFirstPixelFrom:to: */;

	/* Deal with the first n sub-pixels */

	lastPixel = (x1 - 1) & (~((workBuffer[GWAALevel]) - 1));
	if (x < firstPixel) {
		colorMask = workBuffer[GWAAColorMask];
		colorShift = workBuffer[GWAAColorShift];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while (x < firstPixel) {
			while ((x < firstPixel) && ((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) >= length2)) {
				index = ((usqInt) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += 1;
				ds += dsX;
				dt += dtX;
			}
			nextLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
			while (nextLength < length2) {
				rampIndex -= 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
				length2 = (rampIndex - 1) * (rampIndex - 1);
			}
		}
	}
	if (x < lastPixel) {
		colorMask = (((usqInt) (workBuffer[GWAAColorMask])) >> (workBuffer[GWAAShift])) | 4042322160U;
		colorShift = workBuffer[GWAAShift];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while (x < lastPixel) {
			while ((x < lastPixel) && ((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) >= length2)) {
				index = ((usqInt) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += aaLevel;
				ds += dsX << colorShift;
				dt += dtX << colorShift;
			}
			nextLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
			while (nextLength < length2) {
				rampIndex -= 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
				length2 = (rampIndex - 1) * (rampIndex - 1);
			}
		}
	}
	if (x < x1) {
		colorMask = workBuffer[GWAAColorMask];
		colorShift = workBuffer[GWAAColorShift];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while (x < x1) {
			while ((x < x1) && ((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) >= length2)) {
				index = ((usqInt) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += 1;
				ds += dsX;
				dt += dtX;
			}
			nextLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
			while (nextLength < length2) {
				rampIndex -= 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
				length2 = (rampIndex - 1) * (rampIndex - 1);
			}
		}
	}
	(((int *) deltaST))[0] = ds;
	(((int *) deltaST))[1] = dt;
	return x;
}

static sqInt fillRadialGradient(void) {
	return fillRadialGradientfromtoat(workBuffer[GWLastExportedFill], workBuffer[GWLastExportedLeftX], workBuffer[GWLastExportedRightX], workBuffer[GWCurrentY]);
}


/*	Draw a radial gradient fill. */

static sqInt fillRadialGradientfromtoat(sqInt fill, sqInt leftX, sqInt rightX, sqInt yValue) {
    int * deltaST;
    sqInt dtX;
    sqInt x1;
    sqInt ds;
    sqInt x;
    sqInt deltaX;
    sqInt dt;
    sqInt deltaY;
    sqInt rampSize;
    sqInt length2;
    int * ramp;
    sqInt dsX;
    sqInt x11;
    sqInt x0;
    sqInt x12;
    sqInt ds1;
    sqInt x2;
    sqInt rampIndex;
    sqInt dt1;
    sqInt length21;
    sqInt rampValue;
    sqInt nextLength;
    sqInt x13;
    sqInt lastLength;
    sqInt ds2;
    sqInt x3;
    sqInt rampIndex1;
    sqInt dt2;
    sqInt rampSize1;
    sqInt length22;
    sqInt rampValue1;
    sqInt nextLength1;
    sqInt x14;
    sqInt x01;

	ramp = (objBuffer + fill) + GFRampOffset;
	rampSize = objBuffer[fill + GFRampLength];
	deltaX = leftX - (objBuffer[fill + GFOriginX]);
	deltaY = yValue - (objBuffer[fill + GFOriginY]);
	dsX = objBuffer[fill + GFDirectionX];
	dtX = objBuffer[fill + GFNormalX];
	ds = (deltaX * dsX) + (deltaY * (objBuffer[fill + GFDirectionY]));
	dt = (deltaX * dtX) + (deltaY * (objBuffer[fill + GFNormalY]));
	x = leftX;

	/* Note: The inner loop has been divided into three parts for speed */
	/* Part one: Fill everything outside the left boundary */

	x1 = rightX;

	/* This is the upper bound */

	length2 = (rampSize - 1) * (rampSize - 1);
	while (((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) >= length2) && (x < x1)) {
		x += 1;
		ds += dsX;
		dt += dtX;
	}
	if (x > leftX) {
		/* begin fillColorSpan:from:to: */
		if (!((workBuffer[GWAALevel]) == 1)) {
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
	deltaST = ((int *) (workBuffer + GWPoint1));
	deltaST[0] = ds;
	deltaST[1] = dt;
	if (x < (objBuffer[fill + GFOriginX])) {
		if ((workBuffer[GWAALevel]) == 1) {
			/* begin fillRadialDecreasing:ramp:deltaST:dsX:dtX:from:to: */
			ds1 = (((int*) deltaST))[0];
			dt1 = (((int*) deltaST))[1];
			rampIndex = accurateLengthOfwith(((sqInt) ds1 >> 16), ((sqInt) dt1 >> 16));
			rampValue = (((int *) ramp))[rampIndex];
			length21 = (rampIndex - 1) * (rampIndex - 1);
			x2 = x;
			x12 = x1;
			if (x12 > (objBuffer[fill + GFOriginX])) {
				x12 = objBuffer[fill + GFOriginX];
			}
			while (x2 < x12) {
				while ((x2 < x12) && ((((((sqInt) ds1 >> 16)) * (((sqInt) ds1 >> 16))) + ((((sqInt) dt1 >> 16)) * (((sqInt) dt1 >> 16)))) >= length21)) {
					spanBuffer[x2] = rampValue;
					x2 += 1;
					ds1 += dsX;
					dt1 += dtX;
				}
				nextLength = ((((sqInt) ds1 >> 16)) * (((sqInt) ds1 >> 16))) + ((((sqInt) dt1 >> 16)) * (((sqInt) dt1 >> 16)));
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
		if ((workBuffer[GWAALevel]) == 1) {
			/* begin fillRadialIncreasing:ramp:deltaST:dsX:dtX:from:to: */
			ds2 = (((int*) deltaST))[0];
			dt2 = (((int*) deltaST))[1];
			rampIndex1 = accurateLengthOfwith(((sqInt) ds2 >> 16), ((sqInt) dt2 >> 16));
			rampValue1 = (((int *) ramp))[rampIndex1];
			rampSize1 = objBuffer[fill + GFRampLength];
			length22 = (rampSize1 - 1) * (rampSize1 - 1);
			nextLength1 = (rampIndex1 + 1) * (rampIndex1 + 1);
			lastLength = ((((sqInt) ds2 >> 16)) * (((sqInt) ds2 >> 16))) + ((((sqInt) dt2 >> 16)) * (((sqInt) dt2 >> 16)));
			x3 = x;
			x13 = x1;
			while ((x3 < x13) && (lastLength < length22)) {
				while ((x3 < x13) && ((((((sqInt) ds2 >> 16)) * (((sqInt) ds2 >> 16))) + ((((sqInt) dt2 >> 16)) * (((sqInt) dt2 >> 16)))) <= nextLength1)) {
					spanBuffer[x3] = rampValue1;
					x3 += 1;
					ds2 += dsX;
					dt2 += dtX;
				}
				lastLength = ((((sqInt) ds2 >> 16)) * (((sqInt) ds2 >> 16))) + ((((sqInt) dt2 >> 16)) * (((sqInt) dt2 >> 16)));
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
		if (!((workBuffer[GWAALevel]) == 1)) {
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

static sqInt fillRadialIncreasingrampdeltaSTdsXdtXfromto(sqInt fill, sqInt ramp, sqInt deltaST, sqInt dsX, sqInt dtX, sqInt leftX, sqInt rightX) {
    sqInt x1;
    sqInt lastLength;
    sqInt ds;
    sqInt x;
    sqInt rampIndex;
    sqInt dt;
    sqInt rampSize;
    sqInt length2;
    sqInt rampValue;
    sqInt nextLength;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	rampIndex = accurateLengthOfwith(((sqInt) ds >> 16), ((sqInt) dt >> 16));
	rampValue = (((int *) ramp))[rampIndex];
	rampSize = objBuffer[fill + GFRampLength];

	/* This is the upper bound */

	length2 = (rampSize - 1) * (rampSize - 1);
	nextLength = (rampIndex + 1) * (rampIndex + 1);
	lastLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
	x = leftX;
	x1 = rightX;
	while ((x < x1) && (lastLength < length2)) {
		while ((x < x1) && ((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) <= nextLength)) {
			spanBuffer[x] = rampValue;
			x += 1;
			ds += dsX;
			dt += dtX;
		}
		lastLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
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

static sqInt fillRadialIncreasingAArampdeltaSTdsXdtXfromto(sqInt fill, int * ramp,  int * deltaST, sqInt dsX, sqInt dtX, sqInt leftX, sqInt rightX) {
    sqInt colorShift;
    sqInt baseShift;
    sqInt lastLength;
    sqInt firstPixel;
    sqInt ds;
    sqInt x;
    sqInt index;
    sqInt rampIndex;
    sqInt lastPixel;
    sqInt dt;
    sqInt rampSize;
    sqInt length2;
    sqInt rampValue;
    sqInt nextLength;
    sqInt aaLevel;
    sqInt colorMask;
    sqInt firstPixel1;

	ds = (((int*) deltaST))[0];
	dt = (((int*) deltaST))[1];
	aaLevel = workBuffer[GWAALevel];
	baseShift = workBuffer[GWAAShift];
	rampIndex = accurateLengthOfwith(((sqInt) ds >> 16), ((sqInt) dt >> 16));
	rampSize = objBuffer[fill + GFRampLength];

	/* This is the upper bound */

	length2 = (rampSize - 1) * (rampSize - 1);
	nextLength = (rampIndex + 1) * (rampIndex + 1);
	lastLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
	x = leftX;
	/* begin aaFirstPixelFrom:to: */
	firstPixel1 = ((leftX + (workBuffer[GWAALevel])) - 1) & (~((workBuffer[GWAALevel]) - 1));
	if (firstPixel1 > rightX) {
		firstPixel = rightX;
		goto l1;
	} else {
		firstPixel = firstPixel1;
		goto l1;
	}
l1:	/* end aaFirstPixelFrom:to: */;

	/* Deal with the first n subPixels */

	lastPixel = (rightX - 1) & (~((workBuffer[GWAALevel]) - 1));
	if ((x < firstPixel) && (lastLength < length2)) {
		colorMask = workBuffer[GWAAColorMask];
		colorShift = workBuffer[GWAAColorShift];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while ((x < firstPixel) && (lastLength < length2)) {
			while ((x < firstPixel) && ((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) <= nextLength)) {
				index = ((usqInt) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += 1;
				ds += dsX;
				dt += dtX;
			}
			lastLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
			while (lastLength > nextLength) {
				rampIndex += 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
				nextLength = (rampIndex + 1) * (rampIndex + 1);
			}
		}
	}
	if ((x < lastPixel) && (lastLength < length2)) {
		colorMask = (((usqInt) (workBuffer[GWAAColorMask])) >> (workBuffer[GWAAShift])) | 4042322160U;
		colorShift = workBuffer[GWAAShift];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while ((x < lastPixel) && (lastLength < length2)) {
			while ((x < lastPixel) && ((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) <= nextLength)) {
				index = ((usqInt) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += aaLevel;
				ds += dsX << colorShift;
				dt += dtX << colorShift;
			}
			lastLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
			while (lastLength > nextLength) {
				rampIndex += 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
				nextLength = (rampIndex + 1) * (rampIndex + 1);
			}
		}
	}
	if ((x < rightX) && (lastLength < length2)) {
		colorMask = workBuffer[GWAAColorMask];
		colorShift = workBuffer[GWAAColorShift];
		rampValue = (((int *) ramp))[rampIndex];
		rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
		while ((x < rightX) && (lastLength < length2)) {
			while ((x < rightX) && ((((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)))) <= nextLength)) {
				index = ((usqInt) x) >> baseShift;
				spanBuffer[index] = ((spanBuffer[index]) + rampValue);
				x += 1;
				ds += dsX;
				dt += dtX;
			}
			lastLength = ((((sqInt) ds >> 16)) * (((sqInt) ds >> 16))) + ((((sqInt) dt >> 16)) * (((sqInt) dt >> 16)));
			while (lastLength > nextLength) {
				rampIndex += 1;
				rampValue = (((int *) ramp))[rampIndex];
				rampValue = ((usqInt) (rampValue & colorMask)) >> colorShift;
				nextLength = (rampIndex + 1) * (rampIndex + 1);
			}
		}
	}
	(((int *) deltaST))[0] = ds;
	(((int *) deltaST))[1] = dt;
	return x;
}


/*	Return true if fillEntry1 should be drawn before fillEntry2 */

static sqInt fillSortsbefore(sqInt fillEntry1, sqInt fillEntry2) {
    sqInt diff;

	diff = (workBuffer[(workBuffer[GWBufferTop]) + (fillEntry1 + 1)]) - (workBuffer[(workBuffer[GWBufferTop]) + (fillEntry2 + 1)]);
	if (!(diff == 0)) {
		return diff > 0;
	}
	return (((unsigned) (workBuffer[(workBuffer[GWBufferTop]) + fillEntry1]))) < (((unsigned) (workBuffer[(workBuffer[GWBufferTop]) + fillEntry2])));
}


/*	Fill the span buffer from leftX to rightX with the given fill.
	Clip before performing any operations. Return true if the fill must
	be handled by some Smalltalk code. */

static sqInt fillSpanfromto(unsigned int fill, sqInt leftX, sqInt rightX) {
    sqInt x1;
    sqInt x0;
    sqInt type;
    sqInt x11;
    sqInt x01;

	if (fill == 0) {
		return 0;
	}
	if (leftX < (workBuffer[GWSpanEndAA])) {
		x0 = workBuffer[GWSpanEndAA];
	} else {
		x0 = leftX;
	}
	if (rightX > ((workBuffer[GWSpanSize]) << (workBuffer[GWAAShift]))) {
		x1 = (workBuffer[GWSpanSize]) << (workBuffer[GWAAShift]);
	} else {
		x1 = rightX;
	}
	if (x0 < (workBuffer[GWFillMinX])) {
		x0 = workBuffer[GWFillMinX];
	}
	if (x1 > (workBuffer[GWFillMaxX])) {
		x1 = workBuffer[GWFillMaxX];
	}
	if (x0 < (workBuffer[GWSpanStart])) {
		workBuffer[GWSpanStart] = x0;
	}
	if (x1 > (workBuffer[GWSpanEnd])) {
		workBuffer[GWSpanEnd] = x1;
	}
	if (x1 > (workBuffer[GWSpanEndAA])) {
		workBuffer[GWSpanEndAA] = x1;
	}
	if (x0 >= x1) {
		return 0;
	}
	if ((fill & 4278190080U) != 0) {
		/* begin fillColorSpan:from:to: */
		if (!((workBuffer[GWAALevel]) == 1)) {
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
		workBuffer[GWLastExportedFill] = fill;
		workBuffer[GWLastExportedLeftX] = x0;
		workBuffer[GWLastExportedRightX] = x1;
		type = ((usqInt) (((objBuffer[fill + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveFillMask)) >> 8;
		if (type <= 1) {
			return 1;
		}
		switch (type) {
		case 0:
		case 1:
			errorWrongIndex();
			break;
		case 2:
			fillLinearGradientfromtoat(workBuffer[GWLastExportedFill], workBuffer[GWLastExportedLeftX], workBuffer[GWLastExportedRightX], workBuffer[GWCurrentY]);
			break;
		case 3:
			fillRadialGradientfromtoat(workBuffer[GWLastExportedFill], workBuffer[GWLastExportedLeftX], workBuffer[GWLastExportedRightX], workBuffer[GWCurrentY]);
			break;
		case 4:
		case 5:
			fillBitmapSpanfromtoat(workBuffer[GWLastExportedFill], workBuffer[GWLastExportedLeftX], workBuffer[GWLastExportedRightX], workBuffer[GWCurrentY]);
			break;
		}
	}
	return 0;
}

static sqInt fillTypeOf(sqInt fill) {
	return ((usqInt) (((objBuffer[fill + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveFillMask)) >> 8;
}

static sqInt findNextAETEdgeFrom(sqInt leftEdge) {
    sqInt rightEdge;
    sqInt depth;

	depth = objBuffer[leftEdge + GEZValue];
	while ((workBuffer[GWAETStart]) < (workBuffer[GWAETUsed])) {
		rightEdge = aetBuffer[workBuffer[GWAETStart]];
		if ((objBuffer[rightEdge + GEZValue]) >= depth) {
			return rightEdge;
		}
		workBuffer[GWAETStart] = ((workBuffer[GWAETStart]) + 1);
	}
	return null;
}


/*	Check the global edge table for any entries that cannot be handled by the engine itself.
	If there are any, return true. Otherwise, initialize the the edge and add it to the AET */

static sqInt findNextExternalEntryFromGET(void) {
    sqInt yValue;
    sqInt edge;
    sqInt type;


	/* As long as we have entries in the GET */

	yValue = workBuffer[GWCurrentY];
	while ((workBuffer[GWGETStart]) < (workBuffer[GWGETUsed])) {
		edge = getBuffer[workBuffer[GWGETStart]];
		if ((objBuffer[edge + GEYValue]) > yValue) {
			return 0;
		}
		type = (objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask;
		if ((type & GEPrimitiveWideMask) == GEPrimitiveEdge) {
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
			stepToFirstLineInat(getBuffer[workBuffer[GWGETStart]], workBuffer[GWCurrentY]);
			break;
		case 5:
			stepToFirstWideLineInat(getBuffer[workBuffer[GWGETStart]], workBuffer[GWCurrentY]);
			break;
		case 6:
			stepToFirstBezierInat(getBuffer[workBuffer[GWGETStart]], workBuffer[GWCurrentY]);
			break;
		case 7:
			stepToFirstWideBezierInat(getBuffer[workBuffer[GWGETStart]], workBuffer[GWCurrentY]);
			break;
		}
		insertEdgeIntoAET(edge);
		workBuffer[GWGETStart] = ((workBuffer[GWGETStart]) + 1);
	}
	return 0;
}


/*	Scan the active edge table. If there is any fill that cannot be handled by the engine itself,  return true. Otherwise handle the fills and return false. */
/*	self currentYGet >= 680 ifTrue:[
self printAET.
self halt.
]. */

static sqInt findNextExternalFillFromAET(void) {
    sqInt rightEdge;
    sqInt leftX;
    sqInt rightX;
    sqInt leftEdge;
    sqInt startX;
    sqInt stopX;
    sqInt fill;
    sqInt someIntegerValue;
    sqInt someIntegerValue1;
    sqInt rightX1;
    sqInt startX1;
    sqInt stopX1;
    sqInt fill1;
    sqInt someIntegerValue2;
    sqInt someIntegerValue11;

	leftX = rightX = workBuffer[GWFillMaxX];
	while ((workBuffer[GWAETStart]) < (workBuffer[GWAETUsed])) {

		/* TODO: We should check if leftX from last operation 
			is  greater than leftX from next edge.
			Currently, we rely here on spanEndAA
			from the span buffer fill. */

		leftEdge = rightEdge = aetBuffer[workBuffer[GWAETStart]];
		leftX = rightX = objBuffer[leftEdge + GEXValue];
		if (leftX >= (workBuffer[GWFillMaxX])) {
			return 0;
		}
		/* begin quickRemoveInvalidFillsAt: */
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			goto l3;
		}
		while ((topRightX()) <= leftX) {
			hideFilldepth(topFill(), topDepth());
			if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
				goto l3;
			}
		}
	l3:	/* end quickRemoveInvalidFillsAt: */;
		if ((((objBuffer[leftEdge + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0) {
			toggleWideFillOf(leftEdge);
		}
		if (((objBuffer[leftEdge + GEObjectType]) & GEEdgeFillsInvalid) == 0) {
			toggleFillsOf(leftEdge);
			if (engineStopped) {
				return 0;
			}
		}
		workBuffer[GWAETStart] = ((workBuffer[GWAETStart]) + 1);
		if ((workBuffer[GWAETStart]) < (workBuffer[GWAETUsed])) {
			rightEdge = aetBuffer[workBuffer[GWAETStart]];
			rightX = objBuffer[rightEdge + GEXValue];
			if (rightX >= (workBuffer[GWFillMinX])) {
				/* begin fillAllFrom:to: */
				/* begin topFill */
				if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
					fill = 0;
					goto l8;
				} else {
					fill = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
					goto l8;
				}
			l8:	/* end topFill */;
				startX = leftX;
				/* begin topRightX */
				if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
					stopX = 999999999;
					goto l9;
				} else {
					stopX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)];
					goto l9;
				}
			l9:	/* end topRightX */;
				while (stopX < rightX) {
					/* begin makeUnsignedFrom: */
					/* begin topFill */
					if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
						someIntegerValue = 0;
						goto l6;
					} else {
						someIntegerValue = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
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
					if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
						goto l1;
					}
					while ((topRightX()) <= stopX) {
						hideFilldepth(topFill(), topDepth());
						if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
							goto l1;
						}
					}
				l1:	/* end quickRemoveInvalidFillsAt: */;
					startX = stopX;
					/* begin topRightX */
					if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
						stopX = 999999999;
						goto l7;
					} else {
						stopX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)];
						goto l7;
					}
				l7:	/* end topRightX */;
				}
				/* begin makeUnsignedFrom: */
				/* begin topFill */
				if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
					someIntegerValue1 = 0;
					goto l10;
				} else {
					someIntegerValue1 = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
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
	if (rightX < (workBuffer[GWFillMaxX])) {
		/* begin fillAllFrom:to: */
		rightX1 = workBuffer[GWFillMaxX];
		/* begin topFill */
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			fill1 = 0;
			goto l13;
		} else {
			fill1 = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
			goto l13;
		}
	l13:	/* end topFill */;
		startX1 = rightX;
		/* begin topRightX */
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			stopX1 = 999999999;
			goto l14;
		} else {
			stopX1 = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)];
			goto l14;
		}
	l14:	/* end topRightX */;
		while (stopX1 < rightX1) {
			/* begin makeUnsignedFrom: */
			/* begin topFill */
			if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
				someIntegerValue2 = 0;
				goto l11;
			} else {
				someIntegerValue2 = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
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
			if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
				goto l4;
			}
			while ((topRightX()) <= stopX1) {
				hideFilldepth(topFill(), topDepth());
				if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
					goto l4;
				}
			}
		l4:	/* end quickRemoveInvalidFillsAt: */;
			startX1 = stopX1;
			/* begin topRightX */
			if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
				stopX1 = 999999999;
				goto l12;
			} else {
				stopX1 = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)];
				goto l12;
			}
		l12:	/* end topRightX */;
		}
		/* begin makeUnsignedFrom: */
		/* begin topFill */
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			someIntegerValue11 = 0;
			goto l15;
		} else {
			someIntegerValue11 = workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
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

static sqInt findNextExternalUpdateFromAET(void) {
    sqInt edge;
    sqInt count;
    sqInt type;

	while ((workBuffer[GWAETStart]) < (workBuffer[GWAETUsed])) {
		edge = aetBuffer[workBuffer[GWAETStart]];
		count = (objBuffer[edge + GENumLines]) - 1;
		if (count == 0) {
			removeFirstAETEntry();
		} else {
			objBuffer[edge + GENumLines] = count;
			type = (objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask;
			if ((type & GEPrimitiveWideMask) == GEPrimitiveEdge) {
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
				stepToNextLineInat(aetBuffer[workBuffer[GWAETStart]], workBuffer[GWCurrentY]);
				break;
			case 5:
				stepToNextWideLineInat(aetBuffer[workBuffer[GWAETStart]], workBuffer[GWCurrentY]);
				break;
			case 6:
				stepToNextBezierInat(aetBuffer[workBuffer[GWAETStart]], workBuffer[GWCurrentY]);
				break;
			case 7:
				stepToNextWideBezier();
				break;
			}
			resortFirstAETEntry();
			workBuffer[GWAETStart] = ((workBuffer[GWAETStart]) + 1);
		}
	}
	return 0;
}

static sqInt findStackFilldepth(sqInt fillIndex, sqInt depth) {
    sqInt index;

	index = 0;
	while ((index < ((workBuffer[GWSize]) - (workBuffer[GWBufferTop]))) && (((workBuffer[(workBuffer[GWBufferTop]) + index]) != fillIndex) || ((workBuffer[(workBuffer[GWBufferTop]) + (index + 1)]) != depth))) {
		index += 3;
	}
	if (index >= ((workBuffer[GWSize]) - (workBuffer[GWBufferTop]))) {
		return -1;
	} else {
		return index;
	}
}


/*	Return true if processing is finished */

static sqInt finishedProcessing(void) {
	return (workBuffer[GWState]) == GEStateCompleted;
}

static sqInt firstPointListGet(void) {
	return workBuffer[GWPointListFirst];
}

static sqInt firstPointListPut(sqInt value) {
	return workBuffer[GWPointListFirst] = value;
}

static sqInt freeStackFillEntry(void) {
	/* begin wbStackPop: */
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) + 3);
}


/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine * getInterpreter(void) {
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}


/*	Return true if the edge at index i should sort before the edge at index j. */

static sqInt getSortsbefore(sqInt edge1, sqInt edge2) {
    sqInt diff;

	if (edge1 == edge2) {
		return 1;
	}
	diff = (objBuffer[edge1 + GEYValue]) - (objBuffer[edge2 + GEYValue]);
	if (!(diff == 0)) {
		return diff < 0;
	}
	diff = (objBuffer[edge1 + GEXValue]) - (objBuffer[edge2 + GEXValue]);
	return diff < 0;
}

static sqInt getStartGet(void) {
	return workBuffer[GWGETStart];
}

static sqInt getStartPut(sqInt value) {
	return workBuffer[GWGETStart] = value;
}

static sqInt getUsedGet(void) {
	return workBuffer[GWGETUsed];
}

static sqInt getUsedPut(sqInt value) {
	return workBuffer[GWGETUsed] = value;
}

static sqInt gradientRampLengthOf(sqInt fill) {
	return objBuffer[fill + GFRampLength];
}

static sqInt gradientRampLengthOfput(sqInt fill, sqInt value) {
	return objBuffer[fill + GFRampLength] = value;
}

static int * gradientRampOf(sqInt fill) {
	return (objBuffer + fill) + GFRampOffset;
}

static sqInt halt(void) {
	;
}

static sqInt hasColorTransform(void) {
	return (workBuffer[GWHasColorTransform]) != 0;
}

static sqInt hasColorTransformGet(void) {
	return workBuffer[GWHasColorTransform];
}

static sqInt hasColorTransformPut(sqInt value) {
	return workBuffer[GWHasColorTransform] = value;
}

static sqInt hasEdgeTransform(void) {
	return (workBuffer[GWHasEdgeTransform]) != 0;
}

static sqInt hasEdgeTransformGet(void) {
	return workBuffer[GWHasEdgeTransform];
}

static sqInt hasEdgeTransformPut(sqInt value) {
	return workBuffer[GWHasEdgeTransform] = value;
}


/*	Make the fill style with the given index invisible */

static sqInt hideFilldepth(sqInt fillIndex, sqInt depth) {
    sqInt index;
    sqInt newTop;
    sqInt newTopIndex;
    sqInt newRightX;
    sqInt newDepth;

	index = findStackFilldepth(fillIndex, depth);
	if (index == -1) {
		return 0;
	}
	if (index == 0) {
		/* begin freeStackFillEntry */
		/* begin wbStackPop: */
		workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) + 3);
		return 1;
	}
	workBuffer[(workBuffer[GWBufferTop]) + index] = (workBuffer[(workBuffer[GWBufferTop]) + 0]);
	workBuffer[(workBuffer[GWBufferTop]) + (index + 1)] = (workBuffer[(workBuffer[GWBufferTop]) + (0 + 1)]);
	workBuffer[(workBuffer[GWBufferTop]) + (index + 2)] = (workBuffer[(workBuffer[GWBufferTop]) + (0 + 2)]);
	/* begin freeStackFillEntry */
	/* begin wbStackPop: */
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) + 3);
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) <= 3) {
		return 1;
	}
	newTopIndex = 0;
	index = 3;
	while (index < ((workBuffer[GWSize]) - (workBuffer[GWBufferTop]))) {
		if (fillSortsbefore(index, newTopIndex)) {
			newTopIndex = index;
		}
		index += 3;
	}
	if ((newTopIndex + 3) == ((workBuffer[GWSize]) - (workBuffer[GWBufferTop]))) {
		return 1;
	}
	newTop = workBuffer[(workBuffer[GWBufferTop]) + newTopIndex];
	workBuffer[(workBuffer[GWBufferTop]) + newTopIndex] = (workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)]);
	workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)] = newTop;
	newDepth = workBuffer[(workBuffer[GWBufferTop]) + (newTopIndex + 1)];
	workBuffer[(workBuffer[GWBufferTop]) + (newTopIndex + 1)] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 1)]);
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 1)] = newDepth;
	newRightX = workBuffer[(workBuffer[GWBufferTop]) + (newTopIndex + 2)];
	workBuffer[(workBuffer[GWBufferTop]) + (newTopIndex + 2)] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)]);
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)] = newRightX;
	return 1;
}

static sqInt incrementPointby(int * point, sqInt delta) {
	point[0] = ((point[0]) + delta);
	point[1] = ((point[1]) + delta);
}

static sqInt incrementStatby(sqInt statIndex, sqInt value) {
	return workBuffer[statIndex] = ((workBuffer[statIndex]) + value);
}


/*	Find insertion point for the given edge in the AET */

static sqInt indexForInsertingIntoAET(sqInt edge) {
    sqInt initialX;
    sqInt index;

	initialX = objBuffer[edge + GEXValue];
	index = 0;
	while ((index < (workBuffer[GWAETUsed])) && ((objBuffer[(aetBuffer[index]) + GEXValue]) < initialX)) {
		index += 1;
	}
	while ((index < (workBuffer[GWAETUsed])) && (((objBuffer[(aetBuffer[index]) + GEXValue]) == initialX) && (getSortsbefore(aetBuffer[index], edge)))) {
		index += 1;
	}
	return index;
}

static sqInt initColorTransform(void) {
    float * transform;

	transform = ((float *) (workBuffer + GWColorTransform));
	transform[0] = (((float) 1.0));
	transform[1] = (((float) 0.0));
	transform[2] = (((float) 1.0));
	transform[3] = (((float) 0.0));
	transform[4] = (((float) 1.0));
	transform[5] = (((float) 0.0));
	transform[6] = (((float) 1.0));
	transform[7] = (((float) 0.0));
	workBuffer[GWHasColorTransform] = 0;
}

static sqInt initEdgeTransform(void) {
    float * transform;

	transform = ((float *) (workBuffer + GWEdgeTransform));
	transform[0] = (((float) 1.0));
	transform[1] = (((float) 0.0));
	transform[2] = (((float) 0.0));
	transform[3] = (((float) 0.0));
	transform[4] = (((float) 1.0));
	transform[5] = (((float) 0.0));
	workBuffer[GWHasEdgeTransform] = 0;
}

EXPORT(sqInt) initialiseModule(void) {
	loadBBFn = interpreterProxy->ioLoadFunctionFrom("loadBitBltFrom", bbPluginName);
	copyBitsFn = interpreterProxy->ioLoadFunctionFrom("copyBitsFromtoat", bbPluginName);
	return (loadBBFn != 0) && (copyBitsFn != 0);
}


/*	Initialization stuff that needs to be done before any processing can take place. */

static sqInt initializeGETProcessing(void) {
	setAALevel(workBuffer[GWAALevel]);
	if ((workBuffer[GWClipMinX]) < 0) {
		workBuffer[GWClipMinX] = 0;
	}
	if ((workBuffer[GWClipMaxX]) > (workBuffer[GWSpanSize])) {
		workBuffer[GWClipMaxX] = (workBuffer[GWSpanSize]);
	}
	workBuffer[GWFillMinX] = ((workBuffer[GWClipMinX]) << (workBuffer[GWAAShift]));
	workBuffer[GWFillMinY] = ((workBuffer[GWClipMinY]) << (workBuffer[GWAAShift]));
	workBuffer[GWFillMaxX] = ((workBuffer[GWClipMaxX]) << (workBuffer[GWAAShift]));
	workBuffer[GWFillMaxY] = ((workBuffer[GWClipMaxY]) << (workBuffer[GWAAShift]));
	workBuffer[GWGETUsed] = 0;
	workBuffer[GWAETUsed] = 0;
	getBuffer = objBuffer + objUsed;

	/* Create the global edge table */

	aetBuffer = objBuffer + objUsed;
	createGlobalEdgeTable();
	if (engineStopped) {
		return null;
	}
	if ((workBuffer[GWGETUsed]) == 0) {
		workBuffer[GWCurrentY] = (workBuffer[GWFillMaxY]);
		return 0;
	}
	/* begin sortGlobalEdgeTable */
	quickSortGlobalEdgeTablefromto(getBuffer, 0, (workBuffer[GWGETUsed]) - 1);
	workBuffer[GWCurrentY] = (objBuffer[(getBuffer[0]) + GEYValue]);
	if ((workBuffer[GWCurrentY]) < (workBuffer[GWFillMinY])) {
		workBuffer[GWCurrentY] = (workBuffer[GWFillMinY]);
	}
	workBuffer[GWSpanStart] = 0;
	workBuffer[GWSpanEnd] = (((workBuffer[GWSpanSize]) << (workBuffer[GWAAShift])) - 1);
	clearSpanBuffer();
}


/*	Insert the edge with the given index from the global edge table into the active edge table.
	The edge has already been stepped to the initial yValue -- thus remainingLines and rasterX
	are both set. */

static sqInt insertEdgeIntoAET(sqInt edge) {
    sqInt index;

	if ((objBuffer[edge + GENumLines]) <= 0) {
		return null;
	}

	/* And insert edge */

	index = indexForInsertingIntoAET(edge);
	insertToAETbeforeIndex(edge, index);
}


/*	Insert the given edge into the AET. */

static sqInt insertToAETbeforeIndex(sqInt edge, sqInt index) {
    sqInt i;

	if (!(needAvailableSpace(1))) {
		return null;
	}
	i = (workBuffer[GWAETUsed]) - 1;
	while (!(i < index)) {
		aetBuffer[i + 1] = (aetBuffer[i]);
		i -= 1;
	}
	aetBuffer[index] = edge;
	workBuffer[GWAETUsed] = ((workBuffer[GWAETUsed]) + 1);
}

static sqInt isBezier(sqInt bezier) {
	return (((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWideMask) == GEPrimitiveBezier;
}

static sqInt isEdge(sqInt edge) {
    sqInt type;

	type = (objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask;
	if (type > GEPrimitiveEdgeMask) {
		return 0;
	}
	return (((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveEdgeMask) != 0;
}

static sqInt isFill(sqInt fill) {
	return ((fill & 4278190080U) != 0) || ((((objBuffer[fill + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveFillMask) != 0);
}

static sqInt isFillColor(sqInt fill) {
	return (fill & 4278190080U) != 0;
}

static sqInt isFillOkay(sqInt fill) {
	return (fill == 0) || (((fill & 4278190080U) != 0) || (((fill >= 0) && (fill < objUsed)) && (((fill & 4278190080U) != 0) || ((((objBuffer[fill + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveFillMask) != 0))));
}

static sqInt isLine(sqInt line) {
	return (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWideMask) == GEPrimitiveLine;
}

static sqInt isObject(sqInt obj) {
	return (obj >= 0) && (obj < objUsed);
}

static sqInt isRealFill(sqInt fill) {
	return (((objBuffer[fill + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveFillMask) != 0;
}

static sqInt isStackEntry(sqInt entry) {
	return (entry >= (workBuffer[GWBufferTop])) && (entry < (workBuffer[GWSize]));
}

static sqInt isStackIndex(sqInt index) {
	return (index >= 0) && (index < ((workBuffer[GWSize]) - (workBuffer[GWBufferTop])));
}

static sqInt isWide(sqInt object) {
	return (((objBuffer[object + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0;
}

static sqInt isWideBezier(sqInt bezier) {
	return ((((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWideMask) == GEPrimitiveBezier) && ((((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0);
}

static sqInt isWideLine(sqInt line) {
	return ((((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWideMask) == GEPrimitiveLine) && ((((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0);
}

static sqInt lastExportedEdgeGet(void) {
	return workBuffer[GWLastExportedEdge];
}

static sqInt lastExportedEdgePut(sqInt value) {
	return workBuffer[GWLastExportedEdge] = value;
}

static sqInt lastExportedFillGet(void) {
	return workBuffer[GWLastExportedFill];
}

static sqInt lastExportedFillPut(sqInt value) {
	return workBuffer[GWLastExportedFill] = value;
}

static sqInt lastExportedLeftXGet(void) {
	return workBuffer[GWLastExportedLeftX];
}

static sqInt lastExportedLeftXPut(sqInt value) {
	return workBuffer[GWLastExportedLeftX] = value;
}

static sqInt lastExportedRightXGet(void) {
	return workBuffer[GWLastExportedRightX];
}

static sqInt lastExportedRightXPut(sqInt value) {
	return workBuffer[GWLastExportedRightX] = value;
}

static sqInt lineEndXOf(sqInt line) {
	return objBuffer[line + GLEndX];
}

static sqInt lineEndXOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLEndX] = value;
}

static sqInt lineEndYOf(sqInt line) {
	return objBuffer[line + GLEndY];
}

static sqInt lineEndYOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLEndY] = value;
}

static sqInt lineErrorAdjDownOf(sqInt line) {
	return objBuffer[line + GLErrorAdjDown];
}

static sqInt lineErrorAdjDownOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLErrorAdjDown] = value;
}

static sqInt lineErrorAdjUpOf(sqInt line) {
	return objBuffer[line + GLErrorAdjUp];
}

static sqInt lineErrorAdjUpOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLErrorAdjUp] = value;
}

static sqInt lineErrorOf(sqInt line) {
	return objBuffer[line + GLError];
}

static sqInt lineErrorOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLError] = value;
}

static sqInt lineXDirectionOf(sqInt line) {
	return objBuffer[line + GLXDirection];
}

static sqInt lineXDirectionOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLXDirection] = value;
}

static sqInt lineXIncrementOf(sqInt line) {
	return objBuffer[line + GLXIncrement];
}

static sqInt lineXIncrementOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLXIncrement] = value;
}

static sqInt lineYDirectionOf(sqInt line) {
	return objBuffer[line + GLYDirection];
}

static sqInt lineYDirectionOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLYDirection] = value;
}


/*	Load and subdivide the bezier curve from point1/point2/point3.
	If wideFlag is set then make sure the curve is monoton in X. */

static sqInt loadAndSubdivideBezierFromviatoisWide(int * point1, int * point2, int * point3, sqInt wideFlag) {
    sqInt index2;
    sqInt index;
    sqInt bz1;
    sqInt index1;
    sqInt bz2;

	/* begin allocateBezierStackEntry */
	/* begin wbStackPush: */
	if (!(needAvailableSpace(6))) {
		goto l1;
	}
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) - 6);
l1:	/* end wbStackPush: */;
	bz1 = (workBuffer[GWSize]) - (workBuffer[GWBufferTop]);
	if (engineStopped) {
		return 0;
	}
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - bz1) + 0)] = (point1[0]);
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - bz1) + 1)] = (point1[1]);
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - bz1) + 2)] = (point2[0]);
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - bz1) + 3)] = (point2[1]);
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - bz1) + 4)] = (point3[0]);
	workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - bz1) + 5)] = (point3[1]);
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

static sqInt loadArrayPolygonnPointsfilllineWidthlineFill(sqInt points, sqInt nPoints, sqInt fillIndex, sqInt lineWidth, sqInt lineFill) {
    sqInt x1;
    sqInt i;
    sqInt y1;
    sqInt x0;
    sqInt y0;

	loadPointfrom(((int *) (workBuffer + GWPoint1)), interpreterProxy->fetchPointerofObject(0, points));
	if (interpreterProxy->failed()) {
		return null;
	}
	x0 = (((int *) (workBuffer + GWPoint1)))[0];
	y0 = (((int *) (workBuffer + GWPoint1)))[1];
	for (i = 1; i <= (nPoints - 1); i += 1) {
		loadPointfrom(((int *) (workBuffer + GWPoint1)), interpreterProxy->fetchPointerofObject(i, points));
		if (interpreterProxy->failed()) {
			return null;
		}
		x1 = (((int *) (workBuffer + GWPoint1)))[0];
		y1 = (((int *) (workBuffer + GWPoint1)))[1];
		(((int *) (workBuffer + GWPoint1)))[0] = x0;
		(((int *) (workBuffer + GWPoint1)))[1] = y0;
		(((int *) (workBuffer + GWPoint2)))[0] = x1;
		(((int *) (workBuffer + GWPoint2)))[1] = y1;
		/* begin transformPoints: */
		if (2 > 0) {
			transformPoint(((int *) (workBuffer + GWPoint1)));
		}
		if (2 > 1) {
			transformPoint(((int *) (workBuffer + GWPoint2)));
		}
		if (2 > 2) {
			transformPoint(((int *) (workBuffer + GWPoint3)));
		}
		if (2 > 3) {
			transformPoint(((int *) (workBuffer + GWPoint4)));
		}
		loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), lineFill, fillIndex, 0);
		if (engineStopped) {
			return null;
		}
		x0 = x1;
		y0 = y1;
	}
}

static sqInt loadArrayShapenSegmentsfilllineWidthlineFill(sqInt points, sqInt nSegments, sqInt fillIndex, sqInt lineWidth, sqInt lineFill) {
    sqInt pointOop;
    sqInt x1;
    sqInt i;
    sqInt y1;
    sqInt x2;
    sqInt y2;
    sqInt x0;
    sqInt segs;
    sqInt y0;

	for (i = 0; i <= (nSegments - 1); i += 1) {
		pointOop = interpreterProxy->fetchPointerofObject(i * 3, points);
		loadPointfrom(((int *) (workBuffer + GWPoint1)), pointOop);
		pointOop = interpreterProxy->fetchPointerofObject((i * 3) + 1, points);
		loadPointfrom(((int *) (workBuffer + GWPoint2)), pointOop);
		pointOop = interpreterProxy->fetchPointerofObject((i * 3) + 2, points);
		loadPointfrom(((int *) (workBuffer + GWPoint3)), pointOop);
		if (interpreterProxy->failed()) {
			return null;
		}
		/* begin transformPoints: */
		if (3 > 0) {
			transformPoint(((int *) (workBuffer + GWPoint1)));
		}
		if (3 > 1) {
			transformPoint(((int *) (workBuffer + GWPoint2)));
		}
		if (3 > 2) {
			transformPoint(((int *) (workBuffer + GWPoint3)));
		}
		if (3 > 3) {
			transformPoint(((int *) (workBuffer + GWPoint4)));
		}
		x0 = (((int *) (workBuffer + GWPoint1)))[0];
		y0 = (((int *) (workBuffer + GWPoint1)))[1];
		x1 = (((int *) (workBuffer + GWPoint2)))[0];
		y1 = (((int *) (workBuffer + GWPoint2)))[1];
		x2 = (((int *) (workBuffer + GWPoint3)))[0];

		/* Check if we can use a line */

		y2 = (((int *) (workBuffer + GWPoint3)))[1];
		if (((x0 == y0) && (x1 == y1)) || ((x1 == x2) && (y1 == y2))) {
			loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint3)), lineFill, fillIndex, 0);
		} else {
			segs = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), (lineWidth != 0) && (lineFill != 0));
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

static sqInt loadArrayTransformFromintolength(sqInt transformOop, float * destPtr, sqInt n) {
    sqInt i;
    sqInt value;

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

static sqInt loadBeziersegmentleftFillrightFilloffset(sqInt bezier, sqInt index, sqInt leftFillIndex, sqInt rightFillIndex, sqInt yOffset) {
	if ((workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)]) >= (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)])) {
		objBuffer[bezier + GEXValue] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 0)]);
		objBuffer[bezier + GEYValue] = ((workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)]) - yOffset);
		objBuffer[bezier + GBViaX] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)]);
		objBuffer[bezier + GBViaY] = ((workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)]) - yOffset);
		objBuffer[bezier + GBEndX] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)]);
		objBuffer[bezier + GBEndY] = ((workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)]) - yOffset);
	} else {
		objBuffer[bezier + GEXValue] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)]);
		objBuffer[bezier + GEYValue] = ((workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)]) - yOffset);
		objBuffer[bezier + GBViaX] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)]);
		objBuffer[bezier + GBViaY] = ((workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)]) - yOffset);
		objBuffer[bezier + GBEndX] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 0)]);
		objBuffer[bezier + GBEndY] = ((workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)]) - yOffset);
	}
	objBuffer[bezier + GEZValue] = (workBuffer[GWCurrentZ]);
	objBuffer[bezier + GEFillIndexLeft] = leftFillIndex;
	objBuffer[bezier + GEFillIndexRight] = rightFillIndex;
}

static sqInt loadBitBltFrom(sqInt bbObj) {
	if (loadBBFn == 0) {
		if (!(initialiseModule())) {
			return 0;
		}
	}
	return ((sqInt (*)(sqInt))loadBBFn)(bbObj);
}


/*	Load the bitmap fill. */

static sqInt loadBitmapFillcolormaptilefromalongnormalxIndex(sqInt formOop, sqInt cmOop, sqInt tileFlag, int * point1, int * point2, int * point3, sqInt xIndex) {
    sqInt bmDepth;
    sqInt ppw;
    sqInt bmFill;
    sqInt bmRaster;
    sqInt bmHeight;
    int * cmBits;
    sqInt bmBits;
    sqInt bmWidth;
    sqInt bmBitsSize;
    sqInt cmSize;

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
	objBuffer[bmFill + GBBitmapWidth] = bmWidth;
	objBuffer[bmFill + GBBitmapHeight] = bmHeight;
	objBuffer[bmFill + GBBitmapDepth] = bmDepth;
	objBuffer[bmFill + GBBitmapRaster] = bmRaster;
	objBuffer[bmFill + GBBitmapSize] = bmBitsSize;
	objBuffer[bmFill + GBTileFlag] = tileFlag;
	objBuffer[bmFill + GEObjectIndex] = xIndex;
	loadFillOrientationfromalongnormalwidthheight(bmFill, point1, point2, point3, bmWidth, bmHeight);
	return bmFill;
}


/*	Note: Assumes that the contents of formArray has been checked before */

static int * loadBitsFrom(sqInt bmFill) {
    sqInt formOop;
    sqInt xIndex;
    sqInt bitsOop;
    sqInt bitsLen;

	xIndex = objBuffer[bmFill + GEObjectIndex];
	if (xIndex > (interpreterProxy->slotSizeOf(formArray))) {
		return null;
	}
	formOop = interpreterProxy->fetchPointerofObject(xIndex, formArray);
	bitsOop = interpreterProxy->fetchPointerofObject(0, formOop);
	bitsLen = interpreterProxy->slotSizeOf(bitsOop);
	if (!(bitsLen == (objBuffer[bmFill + GBBitmapSize]))) {
		return null;
	}
	return interpreterProxy->firstIndexableField(bitsOop);
}


/*	Load a 2x3 transformation matrix from the given oop.
	Return true if the matrix is not nil, false otherwise */

static sqInt loadColorTransformFrom(sqInt transformOop) {
    sqInt okay;
    float * transform;

	transform = ((float *) (workBuffer + GWColorTransform));
	workBuffer[GWHasColorTransform] = 0;
	okay = loadTransformFromintolength(transformOop, transform, 8);
	if (!(okay)) {
		return 0;
	}
	workBuffer[GWHasColorTransform] = 1;
	transform[1] = ((transform[1]) * (((float) 256.0)));
	transform[3] = ((transform[3]) * (((float) 256.0)));
	transform[5] = ((transform[5]) * (((float) 256.0)));
	transform[7] = ((transform[7]) * (((float) 256.0)));
	return okay;
}


/*	Load the compressed segment identified by segment index */

static sqInt loadCompressedSegmentfromshortleftFillrightFilllineWidthlineColor(sqInt segmentIndex, sqInt points, sqInt pointsShort, sqInt leftFill, sqInt rightFill, sqInt lineWidth, sqInt lineFill) {
    sqInt x1;
    sqInt y1;
    sqInt index;
    sqInt x2;
    sqInt y2;
    sqInt x0;
    sqInt segs;
    sqInt y0;

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
		(((int *) (workBuffer + GWPoint1)))[0] = x0;
		(((int *) (workBuffer + GWPoint1)))[1] = y0;
		(((int *) (workBuffer + GWPoint2)))[0] = x2;
		(((int *) (workBuffer + GWPoint2)))[1] = y2;
		/* begin transformPoints: */
		if (2 > 0) {
			transformPoint(((int *) (workBuffer + GWPoint1)));
		}
		if (2 > 1) {
			transformPoint(((int *) (workBuffer + GWPoint2)));
		}
		if (2 > 2) {
			transformPoint(((int *) (workBuffer + GWPoint3)));
		}
		if (2 > 3) {
			transformPoint(((int *) (workBuffer + GWPoint4)));
		}
		return loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), lineFill, leftFill, rightFill);
	}
	(((int *) (workBuffer + GWPoint1)))[0] = x0;
	(((int *) (workBuffer + GWPoint1)))[1] = y0;
	(((int *) (workBuffer + GWPoint2)))[0] = x1;
	(((int *) (workBuffer + GWPoint2)))[1] = y1;
	(((int *) (workBuffer + GWPoint3)))[0] = x2;
	(((int *) (workBuffer + GWPoint3)))[1] = y2;
	/* begin transformPoints: */
	if (3 > 0) {
		transformPoint(((int *) (workBuffer + GWPoint1)));
	}
	if (3 > 1) {
		transformPoint(((int *) (workBuffer + GWPoint2)));
	}
	if (3 > 2) {
		transformPoint(((int *) (workBuffer + GWPoint3)));
	}
	if (3 > 3) {
		transformPoint(((int *) (workBuffer + GWPoint4)));
	}
	segs = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), (lineWidth != 0) && (lineFill != 0));
	if (engineStopped) {
		return null;
	}
	loadWideBezierlineFillleftFillrightFilln(lineWidth, lineFill, leftFill, rightFill, segs);
}


/*	Load a compressed shape into the engine.
		WARNING: THIS METHOD NEEDS THE FULL FRAME SIZE!!!!
	 */

static sqInt loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(int * points, sqInt nSegments, int * leftFills, int * rightFills, int * lineWidths, int * lineFills, int * fillIndexList, sqInt pointsShort) {
    sqInt widthLength;
    sqInt lineFillLength;
    sqInt rightRun;
    sqInt rightValue;
    sqInt i;
    sqInt leftValue;
    sqInt leftLength;
    sqInt lineFillRun;
    sqInt leftRun;
    sqInt widthValue;
    sqInt lineFillValue;
    sqInt widthRun;
    sqInt rightLength;
    sqInt x1;
    sqInt y1;
    sqInt index;
    sqInt x2;
    sqInt y2;
    sqInt x0;
    sqInt segs;
    sqInt y0;

	if (nSegments == 0) {
		return 0;
	}
	leftRun = rightRun = widthRun = lineFillRun = -1;
	leftLength = rightLength = widthLength = lineFillLength = 1;
	leftValue = rightValue = widthValue = lineFillValue = 0;
	for (i = 1; i <= nSegments; i += 1) {
		if ((leftLength -= 1) <= 0) {
			leftRun += 1;
			leftLength = ((usqInt) ((((int *) leftFills))[leftRun]) >> 16);
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
			rightLength = ((usqInt) ((((int *) rightFills))[rightRun]) >> 16);
			rightValue = ((((int *) rightFills))[rightRun]) & 65535;
			if (!(rightValue == 0)) {
				rightValue = fillIndexList[rightValue - 1];
				rightValue = transformColor(rightValue);
			}
		}
		if ((widthLength -= 1) <= 0) {
			widthRun += 1;
			widthLength = ((usqInt) ((((int *) lineWidths))[widthRun]) >> 16);
			widthValue = ((((int *) lineWidths))[widthRun]) & 65535;
			if (!(widthValue == 0)) {
				widthValue = transformWidth(widthValue);
			}
		}
		if ((lineFillLength -= 1) <= 0) {
			lineFillRun += 1;
			lineFillLength = ((usqInt) ((((int *) lineFills))[lineFillRun]) >> 16);
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
			(((int *) (workBuffer + GWPoint1)))[0] = x0;
			(((int *) (workBuffer + GWPoint1)))[1] = y0;
			(((int *) (workBuffer + GWPoint2)))[0] = x2;
			(((int *) (workBuffer + GWPoint2)))[1] = y2;
			/* begin transformPoints: */
			if (2 > 0) {
				transformPoint(((int *) (workBuffer + GWPoint1)));
			}
			if (2 > 1) {
				transformPoint(((int *) (workBuffer + GWPoint2)));
			}
			if (2 > 2) {
				transformPoint(((int *) (workBuffer + GWPoint3)));
			}
			if (2 > 3) {
				transformPoint(((int *) (workBuffer + GWPoint4)));
			}
			loadWideLinefromtolineFillleftFillrightFill(widthValue, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), lineFillValue, leftValue, rightValue);
			goto l1;
		}
		(((int *) (workBuffer + GWPoint1)))[0] = x0;
		(((int *) (workBuffer + GWPoint1)))[1] = y0;
		(((int *) (workBuffer + GWPoint2)))[0] = x1;
		(((int *) (workBuffer + GWPoint2)))[1] = y1;
		(((int *) (workBuffer + GWPoint3)))[0] = x2;
		(((int *) (workBuffer + GWPoint3)))[1] = y2;
		/* begin transformPoints: */
		if (3 > 0) {
			transformPoint(((int *) (workBuffer + GWPoint1)));
		}
		if (3 > 1) {
			transformPoint(((int *) (workBuffer + GWPoint2)));
		}
		if (3 > 2) {
			transformPoint(((int *) (workBuffer + GWPoint3)));
		}
		if (3 > 3) {
			transformPoint(((int *) (workBuffer + GWPoint4)));
		}
		segs = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), (widthValue != 0) && (lineFillValue != 0));
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

static sqInt loadEdgeStateFrom(sqInt edgeOop) {
    sqInt edge;
    sqInt value;
    sqInt value1;
    sqInt value2;
    sqInt value3;

	edge = workBuffer[GWLastExportedEdge];
	if ((interpreterProxy->slotSizeOf(edgeOop)) < ETBalloonEdgeDataSize) {
		return interpreterProxy->primitiveFail();
	}
	/* begin edgeXValueOf:put: */
	value = interpreterProxy->fetchIntegerofObject(ETXValueIndex, edgeOop);
	objBuffer[edge + GEXValue] = value;
	/* begin edgeYValueOf:put: */
	value2 = interpreterProxy->fetchIntegerofObject(ETYValueIndex, edgeOop);
	objBuffer[edge + GEYValue] = value2;
	/* begin edgeZValueOf:put: */
	value3 = interpreterProxy->fetchIntegerofObject(ETZValueIndex, edgeOop);
	objBuffer[edge + GEZValue] = value3;
	/* begin edgeNumLinesOf:put: */
	value1 = interpreterProxy->fetchIntegerofObject(ETLinesIndex, edgeOop);
	objBuffer[edge + GENumLines] = value1;
	return edge;
}


/*	Load a 2x3 transformation matrix from the given oop.
	Return true if the matrix is not nil, false otherwise */

static sqInt loadEdgeTransformFrom(sqInt transformOop) {
    sqInt okay;
    float * transform;

	workBuffer[GWHasEdgeTransform] = 0;
	transform = ((float *) (workBuffer + GWEdgeTransform));
	okay = loadTransformFromintolength(transformOop, transform, 6);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(okay)) {
		return 0;
	}
	workBuffer[GWHasEdgeTransform] = 1;
	transform[2] = (((float) ((transform[2]) + (((double) (workBuffer[GWDestOffsetX]) )))));
	transform[5] = (((float) ((transform[5]) + (((double) (workBuffer[GWDestOffsetY]) )))));
	return 1;
}


/*	Transform the points */

static sqInt loadFillOrientationfromalongnormalwidthheight(sqInt fill, int * point1, int * point2, int * point3, sqInt fillWidth, sqInt fillHeight) {
    sqInt dsLength2;
    sqInt dtX;
    sqInt nrmX;
    sqInt dsY;
    sqInt dtY;
    sqInt dirX;
    sqInt nrmY;
    sqInt dtLength2;
    sqInt dirY;
    sqInt dsX;

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
		dsX = ((sqInt) ((((((double) dirX )) * (((double) fillWidth ))) * 65536.0) / (((double) dsLength2 ))) );
		dsY = ((sqInt) ((((((double) dirY )) * (((double) fillWidth ))) * 65536.0) / (((double) dsLength2 ))) );
	} else {
		dsX = 0;
		dsY = 0;
	}
	dtLength2 = (nrmX * nrmX) + (nrmY * nrmY);
	if (dtLength2 > 0) {
		dtX = ((sqInt) ((((((double) nrmX )) * (((double) fillHeight ))) * 65536.0) / (((double) dtLength2 ))) );
		dtY = ((sqInt) ((((((double) nrmY )) * (((double) fillHeight ))) * 65536.0) / (((double) dtLength2 ))) );
	} else {
		dtX = 0;
		dtY = 0;
	}
	objBuffer[fill + GFOriginX] = (point1[0]);
	objBuffer[fill + GFOriginY] = (point1[1]);
	objBuffer[fill + GFDirectionX] = dsX;
	objBuffer[fill + GFDirectionY] = dsY;
	objBuffer[fill + GFNormalX] = dtX;
	objBuffer[fill + GFNormalY] = dtY;
}


/*	Check all the forms from arrayOop. */

static sqInt loadFormsFrom(sqInt arrayOop) {
    sqInt bmDepth;
    sqInt ppw;
    sqInt bmRaster;
    sqInt i;
    sqInt bmHeight;
    sqInt bmBits;
    sqInt formOop;
    sqInt bmWidth;
    sqInt bmBitsSize;

	if (!(interpreterProxy->isArray(arrayOop))) {
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

static sqInt loadGradientFillfromalongnormalisRadial(sqInt rampOop, int * point1, int * point2, int * point3, sqInt isRadial) {
    sqInt rampWidth;
    sqInt fill;

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

static sqInt loadLinefromtooffsetleftFillrightFill(sqInt line, int * point1, int * point2, sqInt yOffset, sqInt leftFill, sqInt rightFill) {
    int * p1;
    sqInt yDir;
    int * p2;

	if ((point1[1]) <= (point2[1])) {
		p1 = point1;
		p2 = point2;
		yDir = 1;
	} else {
		p1 = point2;
		p2 = point1;
		yDir = -1;
	}
	objBuffer[line + GEXValue] = (p1[0]);
	objBuffer[line + GEYValue] = ((p1[1]) - yOffset);
	objBuffer[line + GEZValue] = (workBuffer[GWCurrentZ]);
	objBuffer[line + GEFillIndexLeft] = leftFill;
	objBuffer[line + GEFillIndexRight] = rightFill;
	objBuffer[line + GLEndX] = (p2[0]);
	objBuffer[line + GLEndY] = ((p2[1]) - yOffset);
	objBuffer[line + GLYDirection] = yDir;
}


/*	Load a rectangular oval currently defined by point1/point2 */

static sqInt loadOvallineFillleftFillrightFill(sqInt lineWidth, sqInt lineFill, sqInt leftFill, sqInt rightFill) {
    sqInt cx;
    sqInt i;
    sqInt cy;
    sqInt h;
    sqInt w;
    sqInt nSegments;

	w = ((sqInt) (((((int *) (workBuffer + GWPoint2)))[0]) - ((((int *) (workBuffer + GWPoint1)))[0])) >> 1);
	h = ((sqInt) (((((int *) (workBuffer + GWPoint2)))[1]) - ((((int *) (workBuffer + GWPoint1)))[1])) >> 1);
	cx = ((sqInt) (((((int *) (workBuffer + GWPoint2)))[0]) + ((((int *) (workBuffer + GWPoint1)))[0])) >> 1);
	cy = ((sqInt) (((((int *) (workBuffer + GWPoint2)))[1]) + ((((int *) (workBuffer + GWPoint1)))[1])) >> 1);
	for (i = 0; i <= 15; i += 1) {
		loadOvalSegmentwhcxcy(i, w, h, cx, cy);
		/* begin transformPoints: */
		if (3 > 0) {
			transformPoint(((int *) (workBuffer + GWPoint1)));
		}
		if (3 > 1) {
			transformPoint(((int *) (workBuffer + GWPoint2)));
		}
		if (3 > 2) {
			transformPoint(((int *) (workBuffer + GWPoint3)));
		}
		if (3 > 3) {
			transformPoint(((int *) (workBuffer + GWPoint4)));
		}
		nSegments = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), (lineWidth != 0) && (lineFill != 0));
		if (engineStopped) {
			return null;
		}
		loadWideBezierlineFillleftFillrightFilln(lineWidth, lineFill, leftFill, rightFill, nSegments);
		if (engineStopped) {
			return null;
		}
	}
}

static sqInt loadOvalSegmentwhcxcy(sqInt seg, sqInt w, sqInt h, sqInt cx, sqInt cy) {
    sqInt x1;
    sqInt y1;
    sqInt x2;
    sqInt y2;
    sqInt x0;
    sqInt y0;

	x0 = ((sqInt) ((((circleCosTable())[(seg * 2) + 0]) * (((double) w ))) + cx) );
	y0 = ((sqInt) ((((circleSinTable())[(seg * 2) + 0]) * (((double) h ))) + cy) );
	(((int *) (workBuffer + GWPoint1)))[0] = x0;
	(((int *) (workBuffer + GWPoint1)))[1] = y0;
	x2 = ((sqInt) ((((circleCosTable())[(seg * 2) + 2]) * (((double) w ))) + cx) );
	y2 = ((sqInt) ((((circleSinTable())[(seg * 2) + 2]) * (((double) h ))) + cy) );
	(((int *) (workBuffer + GWPoint3)))[0] = x2;
	(((int *) (workBuffer + GWPoint3)))[1] = y2;
	x1 = ((sqInt) ((((circleCosTable())[(seg * 2) + 1]) * (((double) w ))) + cx) );

	/* NOTE: The intermediate point is the point ON the curve
	and not yet the control point (which is OFF the curve) */

	y1 = ((sqInt) ((((circleSinTable())[(seg * 2) + 1]) * (((double) h ))) + cy) );
	x1 = (x1 * 2) - (((sqInt) (x0 + x2) >> 1));
	y1 = (y1 * 2) - (((sqInt) (y0 + y2) >> 1));
	(((int *) (workBuffer + GWPoint2)))[0] = x1;
	(((int *) (workBuffer + GWPoint2)))[1] = y1;
}


/*	Load the contents of pointOop into pointArray */

static sqInt loadPointfrom(int * pointArray, sqInt pointOop) {
    sqInt value;

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
		pointArray[0] = (((sqInt) (interpreterProxy->floatValueOf(value)) ));
	}
	value = interpreterProxy->fetchPointerofObject(1, pointOop);
	if (!(((value & 1)) || (interpreterProxy->isFloatObject(value)))) {
		return interpreterProxy->primitiveFail();
	}
	if ((value & 1)) {
		pointArray[1] = ((value >> 1));
	} else {
		pointArray[1] = (((sqInt) (interpreterProxy->floatValueOf(value)) ));
	}
}


/*	Load the int value from the given index in intArray */

static sqInt loadPointIntAtfrom(sqInt index, sqInt intArray) {
	return (((int *) intArray))[index];
}


/*	Load the short value from the given index in shortArray */

static short loadPointShortAtfrom(sqInt index, sqInt shortArray) {
	return (((short *) shortArray))[index];
}

static sqInt loadPolygonnPointsfilllineWidthlineFillpointsShort(int * points, sqInt nPoints, sqInt fillIndex, sqInt lineWidth, sqInt lineFill, sqInt isShort) {
    sqInt x1;
    sqInt i;
    sqInt y1;
    sqInt x0;
    sqInt y0;

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
		(((int *) (workBuffer + GWPoint1)))[0] = x0;
		(((int *) (workBuffer + GWPoint1)))[1] = y0;
		(((int *) (workBuffer + GWPoint2)))[0] = x1;
		(((int *) (workBuffer + GWPoint2)))[1] = y1;
		/* begin transformPoints: */
		if (2 > 0) {
			transformPoint(((int *) (workBuffer + GWPoint1)));
		}
		if (2 > 1) {
			transformPoint(((int *) (workBuffer + GWPoint2)));
		}
		if (2 > 2) {
			transformPoint(((int *) (workBuffer + GWPoint3)));
		}
		if (2 > 3) {
			transformPoint(((int *) (workBuffer + GWPoint4)));
		}
		loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), lineFill, fillIndex, 0);
		if (engineStopped) {
			return null;
		}
		x0 = x1;
		y0 = y1;
	}
}


/*	Load a rectangle currently defined by point1-point4 */

static sqInt loadRectanglelineFillleftFillrightFill(sqInt lineWidth, sqInt lineFill, sqInt leftFill, sqInt rightFill) {
	loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), lineFill, leftFill, rightFill);
	loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), lineFill, leftFill, rightFill);
	loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint3)), ((int *) (workBuffer + GWPoint4)), lineFill, leftFill, rightFill);
	loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint4)), ((int *) (workBuffer + GWPoint1)), lineFill, leftFill, rightFill);
}


/*	Load the entire state from the interpreter for the rendering primitives */

static sqInt loadRenderingState(void) {
    sqInt edgeOop;
    sqInt state;
    sqInt fillOop;

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
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(BESpanIndex, engine)))) {
		return 0;
	}
	if (!(loadBitBltFrom(interpreterProxy->fetchPointerofObject(BEBitBltIndex, engine)))) {
		return 0;
	}
	if (!(loadFormsFrom(interpreterProxy->fetchPointerofObject(BEFormsIndex, engine)))) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(edgeOop)) < ETBalloonEdgeDataSize) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(fillOop)) < FTBalloonFillDataSize) {
		return 0;
	}
	state = workBuffer[GWState];
	if ((state == GEStateWaitingForEdge) || ((state == GEStateWaitingForFill) || (state == GEStateWaitingChange))) {
		return 0;
	}
	return 1;
}

static sqInt loadShapenSegmentsfilllineWidthlineFillpointsShort(int * points, sqInt nSegments, sqInt fillIndex, sqInt lineWidth, sqInt lineFill, sqInt pointsShort) {
    sqInt i;
    sqInt x1;
    sqInt y1;
    sqInt index;
    sqInt x2;
    sqInt y2;
    sqInt x0;
    sqInt segs;
    sqInt y0;

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
			(((int *) (workBuffer + GWPoint1)))[0] = x0;
			(((int *) (workBuffer + GWPoint1)))[1] = y0;
			(((int *) (workBuffer + GWPoint2)))[0] = x2;
			(((int *) (workBuffer + GWPoint2)))[1] = y2;
			/* begin transformPoints: */
			if (2 > 0) {
				transformPoint(((int *) (workBuffer + GWPoint1)));
			}
			if (2 > 1) {
				transformPoint(((int *) (workBuffer + GWPoint2)));
			}
			if (2 > 2) {
				transformPoint(((int *) (workBuffer + GWPoint3)));
			}
			if (2 > 3) {
				transformPoint(((int *) (workBuffer + GWPoint4)));
			}
			loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), lineFill, fillIndex, 0);
			goto l1;
		}
		(((int *) (workBuffer + GWPoint1)))[0] = x0;
		(((int *) (workBuffer + GWPoint1)))[1] = y0;
		(((int *) (workBuffer + GWPoint2)))[0] = x1;
		(((int *) (workBuffer + GWPoint2)))[1] = y1;
		(((int *) (workBuffer + GWPoint3)))[0] = x2;
		(((int *) (workBuffer + GWPoint3)))[1] = y2;
		/* begin transformPoints: */
		if (3 > 0) {
			transformPoint(((int *) (workBuffer + GWPoint1)));
		}
		if (3 > 1) {
			transformPoint(((int *) (workBuffer + GWPoint2)));
		}
		if (3 > 2) {
			transformPoint(((int *) (workBuffer + GWPoint3)));
		}
		if (3 > 3) {
			transformPoint(((int *) (workBuffer + GWPoint4)));
		}
		segs = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), (lineWidth != 0) && (lineFill != 0));
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

static sqInt loadSpanBufferFrom(sqInt spanOop) {
    sqInt value;

	if (!((interpreterProxy->fetchClassOf(spanOop)) == (interpreterProxy->classBitmap()))) {
		return 0;
	}

	/* Leave last entry unused to avoid complications */

	spanBuffer = interpreterProxy->firstIndexableField(spanOop);
	/* begin spanSizePut: */
	value = (interpreterProxy->slotSizeOf(spanOop)) - 1;
	workBuffer[GWSpanSize] = value;
	return 1;
}


/*	Load a transformation from transformOop into the float array
	defined by destPtr. The transformation is assumed to be either
	an array or a FloatArray of length n. */

static sqInt loadTransformFromintolength(sqInt transformOop, float * destPtr, sqInt n) {
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

static sqInt loadWideBezierlineFillleftFillrightFilln(sqInt lineWidth, sqInt lineFill, sqInt leftFill, sqInt rightFill, sqInt nSegments) {
    sqInt index;
    sqInt wide;
    sqInt offset;
    sqInt bezier;
    sqInt bezier1;
    sqInt bezier2;

	if ((lineWidth == 0) || (lineFill == 0)) {
		wide = 0;
		offset = 0;
	} else {
		wide = 1;
		offset = ((sqInt) lineWidth >> 1);
	}
	index = nSegments * 6;
	while (index > 0) {
		if (wide) {
			/* begin allocateWideBezier */
			if (!(allocateObjEntry(GBWideSize))) {
				bezier = 0;
				goto l2;
			}
			bezier2 = objUsed;
			objUsed = bezier2 + GBWideSize;
			objBuffer[bezier2 + GEObjectType] = GEPrimitiveWideBezier;
			objBuffer[bezier2 + GEObjectIndex] = 0;
			objBuffer[bezier2 + GEObjectLength] = GBWideSize;
			bezier = bezier2;
		l2:	/* end allocateWideBezier */;
		} else {
			/* begin allocateBezier */
			if (!(allocateObjEntry(GBBaseSize))) {
				bezier = 0;
				goto l1;
			}
			bezier1 = objUsed;
			objUsed = bezier1 + GBBaseSize;
			objBuffer[bezier1 + GEObjectType] = GEPrimitiveBezier;
			objBuffer[bezier1 + GEObjectIndex] = 0;
			objBuffer[bezier1 + GEObjectLength] = GBBaseSize;
			bezier = bezier1;
		l1:	/* end allocateBezier */;
		}
		if (engineStopped) {
			return 0;
		}
		loadBeziersegmentleftFillrightFilloffset(bezier, index, leftFill, rightFill, offset);
		if (wide) {
			objBuffer[bezier + GBWideFill] = lineFill;
			objBuffer[bezier + GBWideWidth] = lineWidth;
			objBuffer[bezier + GBWideExtent] = lineWidth;
		}
		index -= 6;
	}
	/* begin wbStackClear */
	workBuffer[GWBufferTop] = (workBuffer[GWSize]);
}


/*	Load a (possibly wide) line defined by the points p1 and p2 */

static sqInt loadWideLinefromtolineFillleftFillrightFill(sqInt lineWidth, int * p1, int * p2, sqInt lineFill, sqInt leftFill, sqInt rightFill) {
    sqInt line;
    sqInt offset;
    sqInt line1;
    sqInt line2;

	if ((lineWidth == 0) || (lineFill == 0)) {
		/* begin allocateLine */
		if (!(allocateObjEntry(GLBaseSize))) {
			line = 0;
			goto l1;
		}
		line1 = objUsed;
		objUsed = line1 + GLBaseSize;
		objBuffer[line1 + GEObjectType] = GEPrimitiveLine;
		objBuffer[line1 + GEObjectIndex] = 0;
		objBuffer[line1 + GEObjectLength] = GLBaseSize;
		line = line1;
	l1:	/* end allocateLine */;
		offset = 0;
	} else {
		/* begin allocateWideLine */
		if (!(allocateObjEntry(GLWideSize))) {
			line = 0;
			goto l2;
		}
		line2 = objUsed;
		objUsed = line2 + GLWideSize;
		objBuffer[line2 + GEObjectType] = GEPrimitiveWideLine;
		objBuffer[line2 + GEObjectIndex] = 0;
		objBuffer[line2 + GEObjectLength] = GLWideSize;
		line = line2;
	l2:	/* end allocateWideLine */;
		offset = ((sqInt) lineWidth >> 1);
	}
	if (engineStopped) {
		return 0;
	}
	loadLinefromtooffsetleftFillrightFill(line, p1, p2, offset, leftFill, rightFill);
	if ((((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0) {
		objBuffer[line + GLWideFill] = lineFill;
		objBuffer[line + GLWideWidth] = lineWidth;
		objBuffer[line + GLWideExtent] = lineWidth;
	}
}


/*	Load a float array transformation from the given oop */

static sqInt loadWordTransformFromintolength(sqInt transformOop, float * destPtr, sqInt n) {
    sqInt i;
    float * srcPtr;

	srcPtr = ((float *) (interpreterProxy->firstIndexableField(transformOop)));
	for (i = 0; i <= (n - 1); i += 1) {
		destPtr[i] = (srcPtr[i]);
	}
}


/*	Load the working buffer from the given oop */

static sqInt loadWorkBufferFrom(sqInt wbOop) {
	if ((wbOop & 1)) {
		return 0;
	}
	if (!(interpreterProxy->isWords(wbOop))) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(wbOop)) < GWMinimalSize) {
		return 0;
	}
	/* begin workBufferPut: */
	workBuffer = interpreterProxy->firstIndexableField(wbOop);
	if (!((workBuffer[GWMagicIndex]) == GWMagicNumber)) {
		return 0;
	}
	if (!((workBuffer[GWSize]) == (interpreterProxy->slotSizeOf(wbOop)))) {
		return 0;
	}
	if (!((workBuffer[GWObjStart]) == GWHeaderSize)) {
		return 0;
	}
	objBuffer = workBuffer + (workBuffer[GWObjStart]);
	getBuffer = objBuffer + (workBuffer[GWObjUsed]);

	/* Make sure we don't exceed the work buffer */

	aetBuffer = getBuffer + (workBuffer[GWGETUsed]);
	if ((((GWHeaderSize + (workBuffer[GWObjUsed])) + (workBuffer[GWGETUsed])) + (workBuffer[GWAETUsed])) > (workBuffer[GWSize])) {
		return 0;
	}
	return 1;
}

static sqInt magicNumberGet(void) {
	return workBuffer[GWMagicIndex];
}

static sqInt magicNumberPut(sqInt value) {
	return workBuffer[GWMagicIndex] = value;
}

static sqInt makeRectFromPoints(void) {
	(((int *) (workBuffer + GWPoint2)))[0] = ((((int *) (workBuffer + GWPoint3)))[0]);
	(((int *) (workBuffer + GWPoint2)))[1] = ((((int *) (workBuffer + GWPoint1)))[1]);
	(((int *) (workBuffer + GWPoint4)))[0] = ((((int *) (workBuffer + GWPoint1)))[0]);
	(((int *) (workBuffer + GWPoint4)))[1] = ((((int *) (workBuffer + GWPoint3)))[1]);
}

static sqInt makeUnsignedFrom(sqInt someIntegerValue) {
	return someIntegerValue;
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

EXPORT(sqInt) moduleUnloaded(char * aModuleName) {
	if ((strcmp(aModuleName, bbPluginName)) == 0) {
		loadBBFn = 0;
		copyBitsFn = 0;
	}
}


/*	The entry at index is not in the right position of the AET. 
	Move it to the left until the position is okay. */

static sqInt moveAETEntryFromedgex(sqInt index, sqInt edge, sqInt xValue) {
    sqInt newIndex;

	newIndex = index;
	while ((newIndex > 0) && ((objBuffer[(aetBuffer[newIndex - 1]) + GEXValue]) > xValue)) {
		aetBuffer[newIndex] = (aetBuffer[newIndex - 1]);
		newIndex -= 1;
	}
	aetBuffer[newIndex] = edge;
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Check if we have n slots available */

static sqInt needAvailableSpace(sqInt nSlots) {
	if (((((GWHeaderSize + objUsed) + (workBuffer[GWGETUsed])) + (workBuffer[GWAETUsed])) + nSlots) > (workBuffer[GWBufferTop])) {
		/* begin stopBecauseOf: */
		workBuffer[GWStopReason] = GErrorNoMoreSpace;
		engineStopped = 1;
		return 0;
	}
	return 1;
}

static sqInt needsFlush(void) {
	return (workBuffer[GWNeedsFlush]) != 0;
}

static sqInt needsFlushGet(void) {
	return workBuffer[GWNeedsFlush];
}

static sqInt needsFlushPut(sqInt value) {
	return workBuffer[GWNeedsFlush] = value;
}

static sqInt objat(sqInt object, sqInt index) {
	return objBuffer[object + index];
}

static sqInt objatput(sqInt object, sqInt index, sqInt value) {
	return objBuffer[object + index] = value;
}

static sqInt objStartGet(void) {
	return workBuffer[GWObjStart];
}

static sqInt objStartPut(sqInt value) {
	return workBuffer[GWObjStart] = value;
}

static sqInt objUsedGet(void) {
	return workBuffer[GWObjUsed];
}

static sqInt objUsedPut(sqInt value) {
	return workBuffer[GWObjUsed] = value;
}

static sqInt objectHeaderOf(sqInt obj) {
	return objBuffer[obj + GEObjectType];
}

static sqInt objectIndexOf(sqInt obj) {
	return objBuffer[obj + GEObjectIndex];
}

static sqInt objectIndexOfput(sqInt obj, sqInt value) {
	return objBuffer[obj + GEObjectIndex] = value;
}

static sqInt objectLengthOf(sqInt obj) {
	return objBuffer[obj + GEObjectLength];
}

static sqInt objectLengthOfput(sqInt obj, sqInt value) {
	return objBuffer[obj + GEObjectLength] = value;
}

static sqInt objectTypeOf(sqInt obj) {
	return (objBuffer[obj + GEObjectType]) & GEPrimitiveTypeMask;
}

static sqInt objectTypeOfput(sqInt obj, sqInt value) {
	return objBuffer[obj + GEObjectType] = value;
}


/*	Common function so that we don't compute that wrong in any place
	and can easily find all the places where we deal with one-pixel offsets. */

static sqInt offsetFromWidth(sqInt lineWidth) {
	return ((sqInt) lineWidth >> 1);
}

static int * point1Get(void) {
	return ((int *) (workBuffer + GWPoint1));
}

static int * point2Get(void) {
	return ((int *) (workBuffer + GWPoint2));
}

static int * point3Get(void) {
	return ((int *) (workBuffer + GWPoint3));
}

static int * point4Get(void) {
	return ((int *) (workBuffer + GWPoint4));
}


/*	We have just blitted a scan line to the screen.
	Do whatever seems to be a good idea here. */
/*	Note: In the future we may check the time needed for this scan line and interrupt processing to give the Smalltalk code a chance to run at a certain time. */

static sqInt postDisplayAction(void) {
	if (((workBuffer[GWGETStart]) >= (workBuffer[GWGETUsed])) && ((workBuffer[GWAETUsed]) == 0)) {
		workBuffer[GWState] = GEStateCompleted;
	}
	if ((workBuffer[GWCurrentY]) >= (workBuffer[GWFillMaxY])) {
		workBuffer[GWState] = GEStateCompleted;
	}
}

EXPORT(sqInt) primitiveAbortProcessing(void) {
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
	workBuffer[GWState] = GEStateCompleted;
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
}


/*	Note: No need to load either bitBlt or spanBuffer */

EXPORT(sqInt) primitiveAddActiveEdgeEntry(void) {
    sqInt edgeOop;
    sqInt edge;
    sqInt value;

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
	if (!(quickLoadEngineFromrequiredState(engine, GEStateWaitingForEdge))) {
		return interpreterProxy->primitiveFail();
	}
	edge = loadEdgeStateFrom(edgeOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(needAvailableSpace(1))) {
		return interpreterProxy->primitiveFail();
	}
	if ((objBuffer[edge + GENumLines]) > 0) {
		insertEdgeIntoAET(edge);
	}
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	workBuffer[GWState] = GEStateAddingFromGET;
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(1);
	if (doProfileStats) {
		workBuffer[GWCountAddAETEntry] = ((workBuffer[GWCountAddAETEntry]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[GWTimeAddAETEntry] = ((workBuffer[GWTimeAddAETEntry]) + value);
	}
}

EXPORT(sqInt) primitiveAddBezier(void) {
    sqInt rightFill;
    sqInt viaOop;
    sqInt startOop;
    sqInt leftFill;
    sqInt nSegments;
    sqInt endOop;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((isFillOkay(leftFill)) && (isFillOkay(rightFill)))) {
		return interpreterProxy->primitiveFail();
	}
	if ((leftFill == rightFill) && 0) {
		return interpreterProxy->pop(6);
	}
	loadPointfrom(((int *) (workBuffer + GWPoint1)), startOop);
	loadPointfrom(((int *) (workBuffer + GWPoint2)), viaOop);
	loadPointfrom(((int *) (workBuffer + GWPoint3)), endOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	/* begin transformPoints: */
	if (3 > 0) {
		transformPoint(((int *) (workBuffer + GWPoint1)));
	}
	if (3 > 1) {
		transformPoint(((int *) (workBuffer + GWPoint2)));
	}
	if (3 > 2) {
		transformPoint(((int *) (workBuffer + GWPoint3)));
	}
	if (3 > 3) {
		transformPoint(((int *) (workBuffer + GWPoint4)));
	}
	nSegments = loadAndSubdivideBezierFromviatoisWide(((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), 0);
	/* begin needAvailableSpace: */
	if (((((GWHeaderSize + objUsed) + (workBuffer[GWGETUsed])) + (workBuffer[GWAETUsed])) + (nSegments * GBBaseSize)) > (workBuffer[GWBufferTop])) {
		/* begin stopBecauseOf: */
		workBuffer[GWStopReason] = GErrorNoMoreSpace;
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
		workBuffer[GWBufferTop] = (workBuffer[GWSize]);
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(5);
	}
}

EXPORT(sqInt) primitiveAddBezierShape(void) {
    sqInt lineWidth;
    sqInt length;
    sqInt points;
    sqInt segSize;
    sqInt lineFill;
    sqInt isArray;
    sqInt nSegments;
    sqInt fillIndex;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), GEStateUnlocked))) {
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
		if (!(interpreterProxy->isArray(points))) {
			return interpreterProxy->primitiveFail();
		}
		if (!(length == (nSegments * 3))) {
			return interpreterProxy->primitiveFail();
		}
		isArray = 1;
	}
	if ((lineWidth == 0) || (lineFill == 0)) {
		segSize = GLBaseSize;
	} else {
		segSize = GLWideSize;
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
		workBuffer[GWNeedsFlush] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(5);
	}
}

EXPORT(sqInt) primitiveAddBitmapFill(void) {
    sqInt cmOop;
    sqInt dirOop;
    sqInt originOop;
    sqInt tileFlag;
    sqInt formOop;
    sqInt fill;
    sqInt xIndex;
    sqInt nrmOop;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(7), GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + GWPoint1)), originOop);
	loadPointfrom(((int *) (workBuffer + GWPoint2)), dirOop);
	loadPointfrom(((int *) (workBuffer + GWPoint3)), nrmOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	fill = loadBitmapFillcolormaptilefromalongnormalxIndex(formOop, cmOop, tileFlag, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), xIndex - 1);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(8);
		interpreterProxy->push(interpreterProxy->positive32BitIntegerFor(fill));
	}
}

EXPORT(sqInt) primitiveAddCompressedShape(void) {
    sqInt leftFills;
    sqInt fillIndexList;
    sqInt lineWidths;
    sqInt points;
    sqInt rightFills;
    sqInt nSegments;
    sqInt pointsShort;
    sqInt lineFills;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(7), GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(checkCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexList(points, nSegments, leftFills, rightFills, lineWidths, lineFills, fillIndexList))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(needAvailableSpace((((GBBaseSize < GLBaseSize) ? GLBaseSize : GBBaseSize)) * nSegments))) {
		return interpreterProxy->primitiveFail();
	}

	/* Then actually load the compressed shape */

	pointsShort = (interpreterProxy->slotSizeOf(points)) == (nSegments * 3);
	loadCompressedShapesegmentsleftFillsrightFillslineWidthslineFillsfillIndexListpointShort(interpreterProxy->firstIndexableField(points), nSegments, interpreterProxy->firstIndexableField(leftFills), interpreterProxy->firstIndexableField(rightFills), interpreterProxy->firstIndexableField(lineWidths), interpreterProxy->firstIndexableField(lineFills), interpreterProxy->firstIndexableField(fillIndexList), pointsShort);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		workBuffer[GWNeedsFlush] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(7);
	}
}

EXPORT(sqInt) primitiveAddGradientFill(void) {
    sqInt dirOop;
    sqInt originOop;
    sqInt rampOop;
    sqInt fill;
    sqInt isRadial;
    sqInt nrmOop;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + GWPoint1)), originOop);
	loadPointfrom(((int *) (workBuffer + GWPoint2)), dirOop);
	loadPointfrom(((int *) (workBuffer + GWPoint3)), nrmOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	fill = loadGradientFillfromalongnormalisRadial(rampOop, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), isRadial);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(6);
		interpreterProxy->push(interpreterProxy->positive32BitIntegerFor(fill));
	}
}

EXPORT(sqInt) primitiveAddLine(void) {
    sqInt rightFill;
    sqInt startOop;
    sqInt leftFill;
    sqInt endOop;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(4), GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((isFillOkay(leftFill)) && (isFillOkay(rightFill)))) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + GWPoint1)), startOop);
	loadPointfrom(((int *) (workBuffer + GWPoint2)), endOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	/* begin transformPoints: */
	if (2 > 0) {
		transformPoint(((int *) (workBuffer + GWPoint1)));
	}
	if (2 > 1) {
		transformPoint(((int *) (workBuffer + GWPoint2)));
	}
	if (2 > 2) {
		transformPoint(((int *) (workBuffer + GWPoint3)));
	}
	if (2 > 3) {
		transformPoint(((int *) (workBuffer + GWPoint4)));
	}
	leftFill = transformColor(leftFill);
	rightFill = transformColor(rightFill);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	loadWideLinefromtolineFillleftFillrightFill(0, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), 0, leftFill, rightFill);
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(4);
	}
}

EXPORT(sqInt) primitiveAddOval(void) {
    sqInt startOop;
    sqInt borderIndex;
    sqInt borderWidth;
    sqInt fillIndex;
    sqInt endOop;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), GEStateUnlocked))) {
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
	if (!(needAvailableSpace(16 * GBBaseSize))) {
		return interpreterProxy->primitiveFail();
	}
	if ((borderWidth > 0) && (borderIndex != 0)) {
		borderWidth = transformWidth(borderWidth);
	} else {
		borderWidth = 0;
	}
	loadPointfrom(((int *) (workBuffer + GWPoint1)), startOop);
	loadPointfrom(((int *) (workBuffer + GWPoint2)), endOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	loadOvallineFillleftFillrightFill(borderWidth, borderIndex, 0, fillIndex);
	if (engineStopped) {
		/* begin wbStackClear */
		workBuffer[GWBufferTop] = (workBuffer[GWSize]);
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		workBuffer[GWNeedsFlush] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(5);
	}
}

EXPORT(sqInt) primitiveAddPolygon(void) {
    sqInt lineWidth;
    sqInt length;
    sqInt points;
    sqInt segSize;
    sqInt lineFill;
    sqInt isArray;
    sqInt nPoints;
    sqInt fillIndex;
    sqInt x1;
    sqInt i;
    sqInt y1;
    sqInt x0;
    sqInt y0;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), GEStateUnlocked))) {
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
		if (!(interpreterProxy->isArray(points))) {
			return interpreterProxy->primitiveFail();
		}
		if (!(length == nPoints)) {
			return interpreterProxy->primitiveFail();
		}
		isArray = 1;
	}
	if ((lineWidth == 0) || (lineFill == 0)) {
		segSize = GLBaseSize;
	} else {
		segSize = GLWideSize;
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
		loadPointfrom(((int *) (workBuffer + GWPoint1)), interpreterProxy->fetchPointerofObject(0, points));
		if (interpreterProxy->failed()) {
			goto l1;
		}
		x0 = (((int *) (workBuffer + GWPoint1)))[0];
		y0 = (((int *) (workBuffer + GWPoint1)))[1];
		for (i = 1; i <= (nPoints - 1); i += 1) {
			loadPointfrom(((int *) (workBuffer + GWPoint1)), interpreterProxy->fetchPointerofObject(i, points));
			if (interpreterProxy->failed()) {
				goto l1;
			}
			x1 = (((int *) (workBuffer + GWPoint1)))[0];
			y1 = (((int *) (workBuffer + GWPoint1)))[1];
			(((int *) (workBuffer + GWPoint1)))[0] = x0;
			(((int *) (workBuffer + GWPoint1)))[1] = y0;
			(((int *) (workBuffer + GWPoint2)))[0] = x1;
			(((int *) (workBuffer + GWPoint2)))[1] = y1;
			/* begin transformPoints: */
			if (2 > 0) {
				transformPoint(((int *) (workBuffer + GWPoint1)));
			}
			if (2 > 1) {
				transformPoint(((int *) (workBuffer + GWPoint2)));
			}
			if (2 > 2) {
				transformPoint(((int *) (workBuffer + GWPoint3)));
			}
			if (2 > 3) {
				transformPoint(((int *) (workBuffer + GWPoint4)));
			}
			loadWideLinefromtolineFillleftFillrightFill(lineWidth, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), lineFill, fillIndex, 0);
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
		workBuffer[GWNeedsFlush] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(5);
	}
}

EXPORT(sqInt) primitiveAddRect(void) {
    sqInt startOop;
    sqInt borderIndex;
    sqInt borderWidth;
    sqInt fillIndex;
    sqInt endOop;

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
	if (!(quickLoadEngineFromrequiredState(interpreterProxy->stackObjectValue(5), GEStateUnlocked))) {
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
	if (!(needAvailableSpace(4 * GLBaseSize))) {
		return interpreterProxy->primitiveFail();
	}
	if ((borderWidth > 0) && (borderIndex != 0)) {
		borderWidth = transformWidth(borderWidth);
	} else {
		borderWidth = 0;
	}
	loadPointfrom(((int *) (workBuffer + GWPoint1)), startOop);
	loadPointfrom(((int *) (workBuffer + GWPoint3)), endOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	(((int *) (workBuffer + GWPoint2)))[0] = ((((int *) (workBuffer + GWPoint3)))[0]);
	(((int *) (workBuffer + GWPoint2)))[1] = ((((int *) (workBuffer + GWPoint1)))[1]);
	(((int *) (workBuffer + GWPoint4)))[0] = ((((int *) (workBuffer + GWPoint1)))[0]);
	(((int *) (workBuffer + GWPoint4)))[1] = ((((int *) (workBuffer + GWPoint3)))[1]);
	/* begin transformPoints: */
	if (4 > 0) {
		transformPoint(((int *) (workBuffer + GWPoint1)));
	}
	if (4 > 1) {
		transformPoint(((int *) (workBuffer + GWPoint2)));
	}
	if (4 > 2) {
		transformPoint(((int *) (workBuffer + GWPoint3)));
	}
	if (4 > 3) {
		transformPoint(((int *) (workBuffer + GWPoint4)));
	}
	/* begin loadRectangle:lineFill:leftFill:rightFill: */
	loadWideLinefromtolineFillleftFillrightFill(borderWidth, ((int *) (workBuffer + GWPoint1)), ((int *) (workBuffer + GWPoint2)), borderIndex, 0, fillIndex);
	loadWideLinefromtolineFillleftFillrightFill(borderWidth, ((int *) (workBuffer + GWPoint2)), ((int *) (workBuffer + GWPoint3)), borderIndex, 0, fillIndex);
	loadWideLinefromtolineFillleftFillrightFill(borderWidth, ((int *) (workBuffer + GWPoint3)), ((int *) (workBuffer + GWPoint4)), borderIndex, 0, fillIndex);
	loadWideLinefromtolineFillleftFillrightFill(borderWidth, ((int *) (workBuffer + GWPoint4)), ((int *) (workBuffer + GWPoint1)), borderIndex, 0, fillIndex);
	if (!(interpreterProxy->failed())) {
		workBuffer[GWNeedsFlush] = 1;
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(5);
	}
}


/*	Note: No need to load either bitBlt or spanBuffer */

EXPORT(sqInt) primitiveChangedActiveEdgeEntry(void) {
    sqInt edgeOop;
    sqInt edge;
    sqInt value;

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
	if (!(quickLoadEngineFromrequiredState(engine, GEStateWaitingChange))) {
		return interpreterProxy->primitiveFail();
	}
	edge = loadEdgeStateFrom(edgeOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	if ((objBuffer[edge + GENumLines]) == 0) {
		removeFirstAETEntry();
	} else {
		resortFirstAETEntry();
		workBuffer[GWAETStart] = ((workBuffer[GWAETStart]) + 1);
	}
	workBuffer[GWState] = GEStateUpdateEdges;
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(1);
	if (doProfileStats) {
		workBuffer[GWCountChangeAETEntry] = ((workBuffer[GWCountChangeAETEntry]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[GWTimeChangeAETEntry] = ((workBuffer[GWTimeChangeAETEntry]) + value);
	}
}

EXPORT(sqInt) primitiveCopyBuffer(void) {
    sqInt buf1;
    int *  dst;
    sqInt i;
    sqInt buf2;
    int *  src;
    sqInt diff;

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
	for (i = 0; i <= ((workBuffer[GWBufferTop]) - 1); i += 1) {
		dst[i] = (src[i]);
	}
	dst[GWBufferTop] = ((workBuffer[GWBufferTop]) + diff);
	dst[GWSize] = ((workBuffer[GWSize]) + diff);
	src += workBuffer[GWBufferTop];
	dst = (dst + (workBuffer[GWBufferTop])) + diff;
	for (i = 0; i <= (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 1); i += 1) {
		dst[i] = (src[i]);
	}
	if (!(loadWorkBufferFrom(buf2))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(2);
}


/*	Note: Must load bitBlt and spanBuffer */

EXPORT(sqInt) primitiveDisplaySpanBuffer(void) {
    sqInt value;

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
	if (!(quickLoadEngineFromrequiredState(engine, GEStateBlitBuffer))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(BESpanIndex, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadBitBltFrom(interpreterProxy->fetchPointerofObject(BEBitBltIndex, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (((workBuffer[GWCurrentY]) & (workBuffer[GWAAScanMask])) == (workBuffer[GWAAScanMask])) {
		displaySpanBufferAt(workBuffer[GWCurrentY]);
		postDisplayAction();
	}
	if (!((workBuffer[GWState]) == GEStateCompleted)) {
		workBuffer[GWAETStart] = 0;
		workBuffer[GWCurrentY] = ((workBuffer[GWCurrentY]) + 1);
		workBuffer[GWState] = GEStateUpdateEdges;
	}
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	if (doProfileStats) {
		workBuffer[GWCountDisplaySpan] = ((workBuffer[GWCountDisplaySpan]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[GWTimeDisplaySpan] = ((workBuffer[GWTimeDisplaySpan]) + value);
	}
}


/*	Turn on/off profiling. Return the old value of the flag. */

EXPORT(sqInt) primitiveDoProfileStats(void) {
    sqInt newValue;
    sqInt oldValue;

	oldValue = doProfileStats;
	newValue = interpreterProxy->stackObjectValue(0);
	newValue = interpreterProxy->booleanValueOf(newValue);
	if (!(interpreterProxy->failed())) {
		doProfileStats = newValue;
		interpreterProxy->pop(2);
		interpreterProxy->pushBool(oldValue);
	}
}

EXPORT(sqInt) primitiveFinishedProcessing(void) {
    sqInt finished;
    sqInt value;

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
	finished = (workBuffer[GWState]) == GEStateCompleted;
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(finished);
	if (doProfileStats) {
		workBuffer[GWCountFinishTest] = ((workBuffer[GWCountFinishTest]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[GWTimeFinishTest] = ((workBuffer[GWTimeFinishTest]) + value);
	}
}

EXPORT(sqInt) primitiveGetAALevel(void) {
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
	interpreterProxy->pushInteger(workBuffer[GWAALevel]);
}

EXPORT(sqInt) primitiveGetBezierStats(void) {
    sqInt statOop;
    int * stats;

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
	stats[0] = ((stats[0]) + (workBuffer[GWBezierMonotonSubdivisions]));
	stats[1] = ((stats[1]) + (workBuffer[GWBezierHeightSubdivisions]));
	stats[2] = ((stats[2]) + (workBuffer[GWBezierOverflowSubdivisions]));
	stats[3] = ((stats[3]) + (workBuffer[GWBezierLineConversions]));
	interpreterProxy->pop(1);
}

EXPORT(sqInt) primitiveGetClipRect(void) {
    sqInt rectOop;
    sqInt pointOop;

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
	pointOop = interpreterProxy->makePointwithxValueyValue(workBuffer[GWClipMinX], workBuffer[GWClipMinY]);
	rectOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, rectOop, pointOop);
	interpreterProxy->pushRemappableOop(rectOop);
	pointOop = interpreterProxy->makePointwithxValueyValue(workBuffer[GWClipMaxX], workBuffer[GWClipMaxY]);
	rectOop = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(1, rectOop, pointOop);
	interpreterProxy->pop(2);
	interpreterProxy->push(rectOop);
}

EXPORT(sqInt) primitiveGetCounts(void) {
    sqInt statOop;
    int * stats;

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
	stats[0] = ((stats[0]) + (workBuffer[GWCountInitializing]));
	stats[1] = ((stats[1]) + (workBuffer[GWCountFinishTest]));
	stats[2] = ((stats[2]) + (workBuffer[GWCountNextGETEntry]));
	stats[3] = ((stats[3]) + (workBuffer[GWCountAddAETEntry]));
	stats[4] = ((stats[4]) + (workBuffer[GWCountNextFillEntry]));
	stats[5] = ((stats[5]) + (workBuffer[GWCountMergeFill]));
	stats[6] = ((stats[6]) + (workBuffer[GWCountDisplaySpan]));
	stats[7] = ((stats[7]) + (workBuffer[GWCountNextAETEntry]));
	stats[8] = ((stats[8]) + (workBuffer[GWCountChangeAETEntry]));
	interpreterProxy->pop(1);
}

EXPORT(sqInt) primitiveGetDepth(void) {
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
	interpreterProxy->pushInteger(workBuffer[GWCurrentZ]);
}


/*	Return the reason why the last operation failed. */

EXPORT(sqInt) primitiveGetFailureReason(void) {
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
	if ((interpreterProxy->slotSizeOf(engine)) < BEBalloonEngineSize) {
		return 0;
	}
	if (!(loadWorkBufferFrom(interpreterProxy->fetchPointerofObject(BEWorkBufferIndex, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushInteger(workBuffer[GWStopReason]);
}

EXPORT(sqInt) primitiveGetOffset(void) {
    sqInt pointOop;

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
	pointOop = interpreterProxy->makePointwithxValueyValue(workBuffer[GWDestOffsetX], workBuffer[GWDestOffsetY]);
	interpreterProxy->pop(1);
	interpreterProxy->push(pointOop);
}

EXPORT(sqInt) primitiveGetTimes(void) {
    sqInt statOop;
    int * stats;

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
	stats[0] = ((stats[0]) + (workBuffer[GWTimeInitializing]));
	stats[1] = ((stats[1]) + (workBuffer[GWTimeFinishTest]));
	stats[2] = ((stats[2]) + (workBuffer[GWTimeNextGETEntry]));
	stats[3] = ((stats[3]) + (workBuffer[GWTimeAddAETEntry]));
	stats[4] = ((stats[4]) + (workBuffer[GWTimeNextFillEntry]));
	stats[5] = ((stats[5]) + (workBuffer[GWTimeMergeFill]));
	stats[6] = ((stats[6]) + (workBuffer[GWTimeDisplaySpan]));
	stats[7] = ((stats[7]) + (workBuffer[GWTimeNextAETEntry]));
	stats[8] = ((stats[8]) + (workBuffer[GWTimeChangeAETEntry]));
	interpreterProxy->pop(1);
}

EXPORT(sqInt) primitiveInitializeBuffer(void) {
    sqInt size;
    sqInt wbOop;

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
	if ((size = interpreterProxy->slotSizeOf(wbOop)) < GWMinimalSize) {
		return interpreterProxy->primitiveFail();
	}
	/* begin workBufferPut: */
	workBuffer = interpreterProxy->firstIndexableField(wbOop);
	objBuffer = workBuffer + GWHeaderSize;
	workBuffer[GWMagicIndex] = GWMagicNumber;
	workBuffer[GWSize] = size;
	workBuffer[GWBufferTop] = size;
	workBuffer[GWState] = GEStateUnlocked;
	workBuffer[GWObjStart] = GWHeaderSize;
	workBuffer[GWObjUsed] = 4;
	objBuffer[0 + GEObjectType] = GEPrimitiveFill;
	objBuffer[0 + GEObjectLength] = 4;
	objBuffer[0 + GEObjectIndex] = 0;
	workBuffer[GWGETStart] = 0;
	workBuffer[GWGETUsed] = 0;
	workBuffer[GWAETStart] = 0;
	workBuffer[GWAETUsed] = 0;
	workBuffer[GWStopReason] = 0;
	workBuffer[GWNeedsFlush] = 0;
	workBuffer[GWClipMinX] = 0;
	workBuffer[GWClipMaxX] = 0;
	workBuffer[GWClipMinY] = 0;
	workBuffer[GWClipMaxY] = 0;
	workBuffer[GWCurrentZ] = 0;
	resetGraphicsEngineStats();
	initEdgeTransform();
	initColorTransform();
	interpreterProxy->pop(2);
	interpreterProxy->push(wbOop);
}


/*	Note: No need to load bitBlt but must load spanBuffer */

EXPORT(sqInt) primitiveInitializeProcessing(void) {
    sqInt value;

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
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(BESpanIndex, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	initializeGETProcessing();
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	workBuffer[GWState] = GEStateAddingFromGET;
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
	}
	if (doProfileStats) {
		workBuffer[GWCountInitializing] = ((workBuffer[GWCountInitializing]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[GWTimeInitializing] = ((workBuffer[GWTimeInitializing]) + value);
	}
}


/*	Note: No need to load bitBlt but must load spanBuffer */

EXPORT(sqInt) primitiveMergeFillFrom(void) {
    sqInt fillOop;
    sqInt value;
    sqInt bitsOop;
    sqInt value1;

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
	if (!(quickLoadEngineFromrequiredState(engine, GEStateWaitingForFill))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(BESpanIndex, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->fetchClassOf(bitsOop)) == (interpreterProxy->classBitmap()))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(fillOop)) < FTBalloonFillDataSize) {
		return interpreterProxy->primitiveFail();
	}
	value = interpreterProxy->fetchIntegerofObject(FTIndexIndex, fillOop);
	if (!((objBuffer[(workBuffer[GWLastExportedFill]) + GEObjectIndex]) == value)) {
		return interpreterProxy->primitiveFail();
	}
	value = interpreterProxy->fetchIntegerofObject(FTMinXIndex, fillOop);
	if (!((workBuffer[GWLastExportedLeftX]) == value)) {
		return interpreterProxy->primitiveFail();
	}
	value = interpreterProxy->fetchIntegerofObject(FTMaxXIndex, fillOop);
	if (!((workBuffer[GWLastExportedRightX]) == value)) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(bitsOop)) < ((workBuffer[GWLastExportedRightX]) - (workBuffer[GWLastExportedLeftX]))) {
		return interpreterProxy->primitiveFail();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	fillBitmapSpanfromto(interpreterProxy->firstIndexableField(bitsOop), workBuffer[GWLastExportedLeftX], workBuffer[GWLastExportedRightX]);
	workBuffer[GWState] = GEStateScanningAET;
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(2);
	if (doProfileStats) {
		workBuffer[GWCountMergeFill] = ((workBuffer[GWCountMergeFill]) + 1);
		/* begin incrementStat:by: */
		value1 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[GWTimeMergeFill] = ((workBuffer[GWTimeMergeFill]) + value1);
	}
}

EXPORT(sqInt) primitiveNeedsFlush(void) {
    sqInt needFlush;

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
	needFlush = (workBuffer[GWNeedsFlush]) != 0;
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(needFlush);
}

EXPORT(sqInt) primitiveNeedsFlushPut(void) {
    sqInt needFlush;

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
		workBuffer[GWNeedsFlush] = 1;
	} else {
		workBuffer[GWNeedsFlush] = 0;
	}
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(1);
}


/*	Note: No need to load either bitBlt or spanBuffer */

EXPORT(sqInt) primitiveNextActiveEdgeEntry(void) {
    sqInt edgeOop;
    sqInt edge;
    sqInt hasEdge;
    sqInt value;

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
	if (!(quickLoadEngineFromrequiredStateor(engine, GEStateUpdateEdges, GEStateCompleted))) {
		return interpreterProxy->primitiveFail();
	}
	hasEdge = 0;
	if (!((workBuffer[GWState]) == GEStateCompleted)) {
		hasEdge = findNextExternalUpdateFromAET();
		if (hasEdge) {
			edge = aetBuffer[workBuffer[GWAETStart]];
			storeEdgeStateFrominto(edge, edgeOop);
			workBuffer[GWState] = GEStateWaitingChange;
		} else {
			workBuffer[GWState] = GEStateAddingFromGET;
		}
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(2);
	interpreterProxy->pushBool(!hasEdge);
	if (doProfileStats) {
		workBuffer[GWCountNextAETEntry] = ((workBuffer[GWCountNextAETEntry]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[GWTimeNextAETEntry] = ((workBuffer[GWTimeNextAETEntry]) + value);
	}
}


/*	Note: No need to load bitBlt but must load spanBuffer */

EXPORT(sqInt) primitiveNextFillEntry(void) {
    sqInt fillOop;
    sqInt hasFill;
    sqInt value;

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
	if (!(quickLoadEngineFromrequiredState(engine, GEStateScanningAET))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadSpanBufferFrom(interpreterProxy->fetchPointerofObject(BESpanIndex, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(loadFormsFrom(interpreterProxy->fetchPointerofObject(BEFormsIndex, engine)))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((workBuffer[GWClearSpanBuffer]) == 0)) {
		if (((workBuffer[GWCurrentY]) & (workBuffer[GWAAScanMask])) == 0) {
			clearSpanBuffer();
		}
		workBuffer[GWClearSpanBuffer] = 0;
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
			workBuffer[GWState] = GEStateWaitingForFill;
		} else {
			/* begin wbStackClear */
			workBuffer[GWBufferTop] = (workBuffer[GWSize]);
			workBuffer[GWSpanEndAA] = 0;
			workBuffer[GWState] = GEStateBlitBuffer;
		}
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(2);
		interpreterProxy->pushBool(!hasFill);
		if (doProfileStats) {
			workBuffer[GWCountNextFillEntry] = ((workBuffer[GWCountNextFillEntry]) + 1);
			/* begin incrementStat:by: */
			value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeNextFillEntry] = ((workBuffer[GWTimeNextFillEntry]) + value);
		}
	}
}


/*	Note: No need to load either bitBlt or spanBuffer */

EXPORT(sqInt) primitiveNextGlobalEdgeEntry(void) {
    sqInt edgeOop;
    sqInt edge;
    sqInt hasEdge;
    sqInt value;

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
	if (!(quickLoadEngineFromrequiredState(engine, GEStateAddingFromGET))) {
		return interpreterProxy->primitiveFail();
	}
	hasEdge = findNextExternalEntryFromGET();
	if (hasEdge) {
		edge = getBuffer[workBuffer[GWGETStart]];
		storeEdgeStateFrominto(edge, edgeOop);
		workBuffer[GWGETStart] = ((workBuffer[GWGETStart]) + 1);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	if (hasEdge) {
		workBuffer[GWState] = GEStateWaitingForEdge;
	} else {
		workBuffer[GWState] = GEStateScanningAET;
		workBuffer[GWClearSpanBuffer] = 1;
		workBuffer[GWAETStart] = 0;
		/* begin wbStackClear */
		workBuffer[GWBufferTop] = (workBuffer[GWSize]);
	}
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(2);
	interpreterProxy->pushBool(!hasEdge);
	if (doProfileStats) {
		workBuffer[GWCountNextGETEntry] = ((workBuffer[GWCountNextGETEntry]) + 1);
		/* begin incrementStat:by: */
		value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
		workBuffer[GWTimeNextGETEntry] = ((workBuffer[GWTimeNextGETEntry]) + value);
	}
}

EXPORT(sqInt) primitiveRegisterExternalEdge(void) {
    sqInt initialX;
    sqInt index;
    sqInt initialY;
    sqInt edge;
    sqInt initialZ;
    sqInt leftFillIndex;
    sqInt rightFillIndex;
    sqInt value;
    sqInt value1;

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
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(allocateObjEntry(GEBaseEdgeSize))) {
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

	objUsed = edge + GEBaseEdgeSize;
	objBuffer[edge + GEObjectType] = GEPrimitiveEdge;
	objBuffer[edge + GEObjectLength] = GEBaseEdgeSize;
	objBuffer[edge + GEObjectIndex] = index;
	objBuffer[edge + GEXValue] = initialX;
	objBuffer[edge + GEYValue] = initialY;
	objBuffer[edge + GEZValue] = initialZ;
	/* begin edgeLeftFillOf:put: */
	value = transformColor(leftFillIndex);
	objBuffer[edge + GEFillIndexLeft] = value;
	/* begin edgeRightFillOf:put: */
	value1 = transformColor(rightFillIndex);
	objBuffer[edge + GEFillIndexRight] = value1;
	if (engineStopped) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(6);
	}
}

EXPORT(sqInt) primitiveRegisterExternalFill(void) {
    sqInt fill;
    sqInt index;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	index = interpreterProxy->stackIntegerValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	fill = 0;
	while (fill == 0) {
		if (!(allocateObjEntry(GEBaseEdgeSize))) {
			return interpreterProxy->primitiveFail();
		}
		fill = objUsed;

		/* Install type and length */

		objUsed = fill + GEBaseFillSize;
		objBuffer[fill + GEObjectType] = GEPrimitiveFill;
		objBuffer[fill + GEObjectLength] = GEBaseFillSize;
		objBuffer[fill + GEObjectIndex] = index;
	}
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(2);
		interpreterProxy->pushInteger(fill);
	}
}


/*	Start/Proceed rendering the entire image */

EXPORT(sqInt) primitiveRenderImage(void) {
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

EXPORT(sqInt) primitiveRenderScanline(void) {
	if (!(loadRenderingState())) {
		return interpreterProxy->primitiveFail();
	}
	proceedRenderingScanline();
	storeRenderingState();
}

EXPORT(sqInt) primitiveSetAALevel(void) {
    sqInt level;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	level = interpreterProxy->stackIntegerValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	setAALevel(level);
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(1);
}


/*	Primitive. Set the BitBlt plugin to use. */

EXPORT(sqInt) primitiveSetBitBltPlugin(void) {
    char * ptr;
    sqInt length;
    sqInt i;
    sqInt pluginName;
    sqInt needReload;


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

EXPORT(sqInt) primitiveSetClipRect(void) {
    sqInt rectOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	rectOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isPointers(rectOop))) {
		return interpreterProxy->primitiveFail();
	}
	if ((interpreterProxy->slotSizeOf(rectOop)) < 2) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + GWPoint1)), interpreterProxy->fetchPointerofObject(0, rectOop));
	loadPointfrom(((int *) (workBuffer + GWPoint2)), interpreterProxy->fetchPointerofObject(1, rectOop));
	if (!(interpreterProxy->failed())) {
		workBuffer[GWClipMinX] = ((((int *) (workBuffer + GWPoint1)))[0]);
		workBuffer[GWClipMinY] = ((((int *) (workBuffer + GWPoint1)))[1]);
		workBuffer[GWClipMaxX] = ((((int *) (workBuffer + GWPoint2)))[0]);
		workBuffer[GWClipMaxY] = ((((int *) (workBuffer + GWPoint2)))[1]);
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(1);
	}
}

EXPORT(sqInt) primitiveSetColorTransform(void) {
    sqInt transformOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	transformOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	loadColorTransformFrom(transformOop);
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(1);
	}
}

EXPORT(sqInt) primitiveSetDepth(void) {
    sqInt depth;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	depth = interpreterProxy->stackIntegerValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	workBuffer[GWCurrentZ] = depth;
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(1);
	}
}

EXPORT(sqInt) primitiveSetEdgeTransform(void) {
    sqInt transformOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	transformOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	loadEdgeTransformFrom(transformOop);
	if (!(interpreterProxy->failed())) {
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(1);
	}
}

EXPORT(sqInt) primitiveSetOffset(void) {
    sqInt pointOop;

	if (!((interpreterProxy->methodArgumentCount()) == 1)) {
		return interpreterProxy->primitiveFail();
	}
	pointOop = interpreterProxy->stackObjectValue(0);
	engine = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(quickLoadEngineFromrequiredState(engine, GEStateUnlocked))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->fetchClassOf(pointOop)) == (interpreterProxy->classPoint()))) {
		return interpreterProxy->primitiveFail();
	}
	loadPointfrom(((int *) (workBuffer + GWPoint1)), pointOop);
	if (!(interpreterProxy->failed())) {
		workBuffer[GWDestOffsetX] = ((((int *) (workBuffer + GWPoint1)))[0]);
		workBuffer[GWDestOffsetY] = ((((int *) (workBuffer + GWPoint1)))[1]);
		/* begin storeEngineStateInto: */
		workBuffer[GWObjUsed] = objUsed;
		interpreterProxy->pop(1);
	}
}


/*	This is the main rendering entry */

static sqInt proceedRenderingImage(void) {
    sqInt external;
    sqInt value;
    sqInt value1;
    sqInt value2;
    sqInt value3;

	while (!((workBuffer[GWState]) == GEStateCompleted)) {
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		external = findNextExternalEntryFromGET();
		if (doProfileStats) {
			workBuffer[GWCountNextGETEntry] = ((workBuffer[GWCountNextGETEntry]) + 1);
			/* begin incrementStat:by: */
			value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeNextGETEntry] = ((workBuffer[GWTimeNextGETEntry]) + value);
		}
		if (engineStopped) {
			return workBuffer[GWState] = GEStateAddingFromGET;
		}
		if (external) {
			workBuffer[GWState] = GEStateWaitingForEdge;
			/* begin stopBecauseOf: */
			workBuffer[GWStopReason] = GErrorGETEntry;
			engineStopped = 1;
			return null;
		}
		workBuffer[GWAETStart] = 0;
		/* begin wbStackClear */
		workBuffer[GWBufferTop] = (workBuffer[GWSize]);
		workBuffer[GWClearSpanBuffer] = 1;
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		if (((workBuffer[GWClearSpanBuffer]) != 0) && (((workBuffer[GWCurrentY]) & (workBuffer[GWAAScanMask])) == 0)) {
			clearSpanBuffer();
		}
		workBuffer[GWClearSpanBuffer] = 0;
		external = findNextExternalFillFromAET();
		if (doProfileStats) {
			workBuffer[GWCountNextFillEntry] = ((workBuffer[GWCountNextFillEntry]) + 1);
			/* begin incrementStat:by: */
			value1 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeNextFillEntry] = ((workBuffer[GWTimeNextFillEntry]) + value1);
		}
		if (engineStopped) {
			return workBuffer[GWState] = GEStateScanningAET;
		}
		if (external) {
			workBuffer[GWState] = GEStateWaitingForFill;
			/* begin stopBecauseOf: */
			workBuffer[GWStopReason] = GErrorFillEntry;
			engineStopped = 1;
			return null;
		}
		/* begin wbStackClear */
		workBuffer[GWBufferTop] = (workBuffer[GWSize]);
		workBuffer[GWSpanEndAA] = 0;
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		if (((workBuffer[GWCurrentY]) & (workBuffer[GWAAScanMask])) == (workBuffer[GWAAScanMask])) {
			displaySpanBufferAt(workBuffer[GWCurrentY]);
			postDisplayAction();
		}
		if (doProfileStats) {
			workBuffer[GWCountDisplaySpan] = ((workBuffer[GWCountDisplaySpan]) + 1);
			/* begin incrementStat:by: */
			value2 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeDisplaySpan] = ((workBuffer[GWTimeDisplaySpan]) + value2);
		}
		if (engineStopped) {
			return workBuffer[GWState] = GEStateBlitBuffer;
		}
		if ((workBuffer[GWState]) == GEStateCompleted) {
			return 0;
		}
		workBuffer[GWAETStart] = 0;
		workBuffer[GWCurrentY] = ((workBuffer[GWCurrentY]) + 1);
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		external = findNextExternalUpdateFromAET();
		if (doProfileStats) {
			workBuffer[GWCountNextAETEntry] = ((workBuffer[GWCountNextAETEntry]) + 1);
			/* begin incrementStat:by: */
			value3 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeNextAETEntry] = ((workBuffer[GWTimeNextAETEntry]) + value3);
		}
		if (engineStopped) {
			return workBuffer[GWState] = GEStateUpdateEdges;
		}
		if (external) {
			workBuffer[GWState] = GEStateWaitingChange;
			/* begin stopBecauseOf: */
			workBuffer[GWStopReason] = GErrorAETEntry;
			engineStopped = 1;
			return null;
		}
	}
}


/*	Proceed rendering the current scan line.
	This method may be called after some Smalltalk code has been executed inbetween. */
/*	This is the main rendering entry */

static sqInt proceedRenderingScanline(void) {
    sqInt state;
    sqInt external;
    sqInt value;
    sqInt value1;
    sqInt value2;
    sqInt value3;

	state = workBuffer[GWState];
	if (state == GEStateUnlocked) {
		initializeGETProcessing();
		if (engineStopped) {
			return 0;
		}
		state = GEStateAddingFromGET;
	}
	if (state == GEStateAddingFromGET) {
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		external = findNextExternalEntryFromGET();
		if (doProfileStats) {
			workBuffer[GWCountNextGETEntry] = ((workBuffer[GWCountNextGETEntry]) + 1);
			/* begin incrementStat:by: */
			value = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeNextGETEntry] = ((workBuffer[GWTimeNextGETEntry]) + value);
		}
		if (engineStopped) {
			return workBuffer[GWState] = GEStateAddingFromGET;
		}
		if (external) {
			workBuffer[GWState] = GEStateWaitingForEdge;
			/* begin stopBecauseOf: */
			workBuffer[GWStopReason] = GErrorGETEntry;
			engineStopped = 1;
			return null;
		}
		workBuffer[GWAETStart] = 0;
		/* begin wbStackClear */
		workBuffer[GWBufferTop] = (workBuffer[GWSize]);
		workBuffer[GWClearSpanBuffer] = 1;
		state = GEStateScanningAET;
	}
	if (state == GEStateScanningAET) {
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		if (((workBuffer[GWClearSpanBuffer]) != 0) && (((workBuffer[GWCurrentY]) & (workBuffer[GWAAScanMask])) == 0)) {
			clearSpanBuffer();
		}
		workBuffer[GWClearSpanBuffer] = 0;
		external = findNextExternalFillFromAET();
		if (doProfileStats) {
			workBuffer[GWCountNextFillEntry] = ((workBuffer[GWCountNextFillEntry]) + 1);
			/* begin incrementStat:by: */
			value1 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeNextFillEntry] = ((workBuffer[GWTimeNextFillEntry]) + value1);
		}
		if (engineStopped) {
			return workBuffer[GWState] = GEStateScanningAET;
		}
		if (external) {
			workBuffer[GWState] = GEStateWaitingForFill;
			/* begin stopBecauseOf: */
			workBuffer[GWStopReason] = GErrorFillEntry;
			engineStopped = 1;
			return null;
		}
		state = GEStateBlitBuffer;
		/* begin wbStackClear */
		workBuffer[GWBufferTop] = (workBuffer[GWSize]);
		workBuffer[GWSpanEndAA] = 0;
	}
	if (state == GEStateBlitBuffer) {
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		if (((workBuffer[GWCurrentY]) & (workBuffer[GWAAScanMask])) == (workBuffer[GWAAScanMask])) {
			displaySpanBufferAt(workBuffer[GWCurrentY]);
			postDisplayAction();
		}
		if (doProfileStats) {
			workBuffer[GWCountDisplaySpan] = ((workBuffer[GWCountDisplaySpan]) + 1);
			/* begin incrementStat:by: */
			value2 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeDisplaySpan] = ((workBuffer[GWTimeDisplaySpan]) + value2);
		}
		if (engineStopped) {
			return workBuffer[GWState] = GEStateBlitBuffer;
		}
		if ((workBuffer[GWState]) == GEStateCompleted) {
			return 0;
		}
		state = GEStateUpdateEdges;
		workBuffer[GWAETStart] = 0;
		workBuffer[GWCurrentY] = ((workBuffer[GWCurrentY]) + 1);
	}
	if (state == GEStateUpdateEdges) {
		if (doProfileStats) {
			geProfileTime = interpreterProxy->ioMicroMSecs();
		}
		external = findNextExternalUpdateFromAET();
		if (doProfileStats) {
			workBuffer[GWCountNextAETEntry] = ((workBuffer[GWCountNextAETEntry]) + 1);
			/* begin incrementStat:by: */
			value3 = (interpreterProxy->ioMicroMSecs()) - geProfileTime;
			workBuffer[GWTimeNextAETEntry] = ((workBuffer[GWTimeNextAETEntry]) + value3);
		}
		if (engineStopped) {
			return workBuffer[GWState] = GEStateUpdateEdges;
		}
		if (external) {
			workBuffer[GWState] = GEStateWaitingChange;
			/* begin stopBecauseOf: */
			workBuffer[GWStopReason] = GErrorAETEntry;
			engineStopped = 1;
			return null;
		}
		workBuffer[GWState] = GEStateAddingFromGET;
	}
}


/*	Load the minimal required state from the engineOop, e.g., just the work buffer. */

static sqInt quickLoadEngineFrom(sqInt engineOop) {
	if (interpreterProxy->failed()) {
		return 0;
	}
	if ((engineOop & 1)) {
		return 0;
	}
	if (!(interpreterProxy->isPointers(engineOop))) {
		return 0;
	}
	if ((interpreterProxy->slotSizeOf(engineOop)) < BEBalloonEngineSize) {
		return 0;
	}
	engine = engineOop;
	if (!(loadWorkBufferFrom(interpreterProxy->fetchPointerofObject(BEWorkBufferIndex, engineOop)))) {
		return 0;
	}
	workBuffer[GWStopReason] = 0;
	objUsed = workBuffer[GWObjUsed];
	engineStopped = 0;
	return 1;
}

static sqInt quickLoadEngineFromrequiredState(sqInt oop, sqInt requiredState) {
	if (!(quickLoadEngineFrom(oop))) {
		return 0;
	}
	if ((workBuffer[GWState]) == requiredState) {
		return 1;
	}
	workBuffer[GWStopReason] = GErrorBadState;
	return 0;
}

static sqInt quickLoadEngineFromrequiredStateor(sqInt oop, sqInt requiredState, sqInt alternativeState) {
	if (!(quickLoadEngineFrom(oop))) {
		return 0;
	}
	if ((workBuffer[GWState]) == requiredState) {
		return 1;
	}
	if ((workBuffer[GWState]) == alternativeState) {
		return 1;
	}
	workBuffer[GWStopReason] = GErrorBadState;
	return 0;
}


/*	Remove any top fills if they have become invalid. */

static sqInt quickRemoveInvalidFillsAt(sqInt leftX) {
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		return null;
	}
	while ((topRightX()) <= leftX) {
		hideFilldepth(topFill(), topDepth());
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			return null;
		}
	}
}


/*	Sort elements i through j of self to be nondescending according to
	sortBlock. */
/*	Note: The original loop has been heavily re-written for C translation */

static sqInt quickSortGlobalEdgeTablefromto(int * array, sqInt i, sqInt j) {
    sqInt k;
    sqInt again;
    sqInt tt;
    sqInt di;
    sqInt n;
    sqInt l;
    sqInt dj;
    sqInt before;
    sqInt dij;
    sqInt ij;
    sqInt tmp;

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

	ij = ((sqInt) (i + j) >> 1);

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

static sqInt removeFirstAETEntry(void) {
    sqInt index;

	index = workBuffer[GWAETStart];
	workBuffer[GWAETUsed] = ((workBuffer[GWAETUsed]) - 1);
	while (index < (workBuffer[GWAETUsed])) {
		aetBuffer[index] = (aetBuffer[index + 1]);
		index += 1;
	}
}

static sqInt repeatValuemax(sqInt delta, sqInt maxValue) {
    sqInt newDelta;

	newDelta = delta;
	while (newDelta < 0) {
		newDelta += maxValue;
	}
	while (newDelta >= maxValue) {
		newDelta -= maxValue;
	}
	return newDelta;
}

static sqInt resetGraphicsEngineStats(void) {
	workBuffer[GWTimeInitializing] = 0;
	workBuffer[GWTimeFinishTest] = 0;
	workBuffer[GWTimeNextGETEntry] = 0;
	workBuffer[GWTimeAddAETEntry] = 0;
	workBuffer[GWTimeNextFillEntry] = 0;
	workBuffer[GWTimeMergeFill] = 0;
	workBuffer[GWTimeDisplaySpan] = 0;
	workBuffer[GWTimeNextAETEntry] = 0;
	workBuffer[GWTimeChangeAETEntry] = 0;
	workBuffer[GWCountInitializing] = 0;
	workBuffer[GWCountFinishTest] = 0;
	workBuffer[GWCountNextGETEntry] = 0;
	workBuffer[GWCountAddAETEntry] = 0;
	workBuffer[GWCountNextFillEntry] = 0;
	workBuffer[GWCountMergeFill] = 0;
	workBuffer[GWCountDisplaySpan] = 0;
	workBuffer[GWCountNextAETEntry] = 0;
	workBuffer[GWCountChangeAETEntry] = 0;
	workBuffer[GWBezierMonotonSubdivisions] = 0;
	workBuffer[GWBezierHeightSubdivisions] = 0;
	workBuffer[GWBezierOverflowSubdivisions] = 0;
	workBuffer[GWBezierLineConversions] = 0;
}

static sqInt resortFirstAETEntry(void) {
    sqInt leftEdge;
    sqInt edge;
    sqInt xValue;

	if ((workBuffer[GWAETStart]) == 0) {
		return null;
	}
	edge = aetBuffer[workBuffer[GWAETStart]];
	xValue = objBuffer[edge + GEXValue];
	leftEdge = aetBuffer[(workBuffer[GWAETStart]) - 1];
	if ((objBuffer[leftEdge + GEXValue]) <= xValue) {
		return null;
	}
	moveAETEntryFromedgex(workBuffer[GWAETStart], edge, xValue);
}

static sqInt returnWideBezierFill(void) {
	return dispatchReturnValue = objBuffer[dispatchedValue + GBWideFill];
}

static sqInt returnWideBezierWidth(void) {
	return dispatchReturnValue = objBuffer[dispatchedValue + GBWideWidth];
}


/*	Return the fill of the (wide) line - this method is called from a case. */

static sqInt returnWideLineFill(void) {
	return dispatchReturnValue = objBuffer[dispatchedValue + GLWideFill];
}


/*	Return the width of the (wide) line - this method is called from a case. */

static sqInt returnWideLineWidth(void) {
	return dispatchReturnValue = objBuffer[dispatchedValue + GLWideWidth];
}


/*	Set the anti-aliasing level. Three levels are supported:
		1 - No antialiasing
		2 - 2x2 unweighted anti-aliasing
		4 - 4x4 unweighted anti-aliasing.
	 */

static sqInt setAALevel(sqInt level) {
    sqInt aaLevel;

	if (level >= 4) {
		aaLevel = 4;
	}
	if ((level >= 2) && (level < 4)) {
		aaLevel = 2;
	}
	if (level < 2) {
		aaLevel = 1;
	}
	workBuffer[GWAALevel] = aaLevel;
	if (aaLevel == 1) {
		workBuffer[GWAAShift] = 0;
		workBuffer[GWAAColorMask] = 4294967295U;
		workBuffer[GWAAScanMask] = 0;
	}
	if (aaLevel == 2) {
		workBuffer[GWAAShift] = 1;
		workBuffer[GWAAColorMask] = 4244438268U;
		workBuffer[GWAAScanMask] = 1;
	}
	if (aaLevel == 4) {
		workBuffer[GWAAShift] = 2;
		workBuffer[GWAAColorMask] = 4042322160U;
		workBuffer[GWAAScanMask] = 3;
	}
	workBuffer[GWAAColorShift] = ((workBuffer[GWAAShift]) * 2);
	workBuffer[GWAAHalfPixel] = (workBuffer[GWAAShift]);
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter) {
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}


/*	Return the run-length value from the given ShortRunArray. */

static sqInt shortRunLengthAtfrom(sqInt i, sqInt runArray) {
	return ((usqInt) ((((int *) runArray))[i]) >> 16);
}


/*	Return the run-length value from the given ShortRunArray.
	Note: We don't need any coercion to short/int here, since
	we deal basically only with unsigned values. */

static sqInt shortRunValueAtfrom(sqInt i, sqInt runArray) {
	return ((((int *) runArray))[i]) & 65535;
}

static sqInt showFilldepthrightX(sqInt fillIndex, sqInt depth, sqInt rightX) {
	if (!(wbStackPush(3))) {
		return null;
	}
	workBuffer[(workBuffer[GWBufferTop]) + 0] = fillIndex;
	workBuffer[(workBuffer[GWBufferTop]) + (0 + 1)] = depth;
	workBuffer[(workBuffer[GWBufferTop]) + (0 + 2)] = rightX;
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 3) {
		return null;
	}
	if (fillSortsbefore(0, ((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)) {
		workBuffer[(workBuffer[GWBufferTop]) + 0] = (workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)]);
		workBuffer[(workBuffer[GWBufferTop]) + (0 + 1)] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 1)]);
		workBuffer[(workBuffer[GWBufferTop]) + (0 + 2)] = (workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)]);
		workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)] = fillIndex;
		workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 1)] = depth;
		workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)] = rightX;
	}
}

static int * smallSqrtTable(void) {
    static int theTable[32] = 
	{0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6};

	return theTable;
}


/*	Sort the entire global edge table */

static sqInt sortGlobalEdgeTable(void) {
	quickSortGlobalEdgeTablefromto(getBuffer, 0, (workBuffer[GWGETUsed]) - 1);
}

static sqInt spanEndAAGet(void) {
	return workBuffer[GWSpanEndAA];
}

static sqInt spanEndAAPut(sqInt value) {
	return workBuffer[GWSpanEndAA] = value;
}

static sqInt spanEndGet(void) {
	return workBuffer[GWSpanEnd];
}

static sqInt spanEndPut(sqInt value) {
	return workBuffer[GWSpanEnd] = value;
}

static sqInt spanSizeGet(void) {
	return workBuffer[GWSpanSize];
}

static sqInt spanSizePut(sqInt value) {
	return workBuffer[GWSpanSize] = value;
}

static sqInt spanStartGet(void) {
	return workBuffer[GWSpanStart];
}

static sqInt spanStartPut(sqInt value) {
	return workBuffer[GWSpanStart] = value;
}

static sqInt squaredLengthOfwith(sqInt deltaX, sqInt deltaY) {
	return (deltaX * deltaX) + (deltaY * deltaY);
}

static sqInt stackFillDepth(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + (index + 1)];
}

static sqInt stackFillDepthput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + (index + 1)] = value;
}

static sqInt stackFillEntryLength(void) {
	return 3;
}

static sqInt stackFillRightX(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + (index + 2)];
}

static sqInt stackFillRightXput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + (index + 2)] = value;
}

static sqInt stackFillSize(void) {
	return (workBuffer[GWSize]) - (workBuffer[GWBufferTop]);
}

static sqInt stackFillValue(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + index];
}

static sqInt stackFillValueput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + index] = value;
}

static sqInt stateGet(void) {
	return workBuffer[GWState];
}

static sqInt statePut(sqInt value) {
	return workBuffer[GWState] = value;
}


/*	Initialize the current entry in the GET by stepping to the current scan line */

static sqInt stepToFirstBezier(void) {
	return stepToFirstBezierInat(getBuffer[workBuffer[GWGETStart]], workBuffer[GWCurrentY]);
}


/*	Initialize the bezier at yValue.
	TODO: Check if reducing maxSteps from 2*deltaY to deltaY 
		brings a *significant* performance improvement.
		In theory this should make for double step performance
		but will cost in quality. Might be that the AA stuff will
		compensate for this - but I'm not really sure. */

static sqInt stepToFirstBezierInat(sqInt bezier, sqInt yValue) {
    sqInt fwY1;
    sqInt fwDDx;
    sqInt fwX1;
    sqInt endX;
    int * updateData;
    sqInt viaY;
    sqInt fwDy;
    sqInt fwY2;
    sqInt scaledStepSize;
    sqInt startX;
    sqInt fwDDy;
    sqInt fwX2;
    sqInt endY;
    sqInt deltaY;
    sqInt maxSteps;
    sqInt squaredStepSize;
    sqInt startY;
    sqInt viaX;
    sqInt fwDx;
    sqInt xValue;
    sqInt fwDy1;
    sqInt lastX;
    sqInt minY;
    sqInt lastY;
    sqInt fwDx1;
    sqInt word2;
    sqInt word1;

	if ((!((((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0)) && (yValue >= (objBuffer[bezier + GBEndY]))) {
		return objBuffer[bezier + GENumLines] = 0;
	}
	startX = objBuffer[bezier + GEXValue];
	startY = objBuffer[bezier + GEYValue];
	viaX = objBuffer[bezier + GBViaX];
	viaY = objBuffer[bezier + GBViaY];
	endX = objBuffer[bezier + GBEndX];
	endY = objBuffer[bezier + GBEndY];

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
	word2 = (((usqInt) scaledStepSize >> 16)) & 255;
	squaredStepSize = ((usqInt) (((((usqInt) (((unsigned) (word1 * word1))) >> 16)) + ((word1 * word2) * 2)) + (((usqInt) (word2 * word2) << 16))) >> 8);
	fwDx = fwX1 * scaledStepSize;
	fwDDx = (fwX2 * squaredStepSize) * 2;
	fwDx += ((sqInt) fwDDx >> 1);
	fwDy = fwY1 * scaledStepSize;
	fwDDy = (fwY2 * squaredStepSize) * 2;

	/* Store the values */

	fwDy += ((sqInt) fwDDy >> 1);
	objBuffer[bezier + GENumLines] = deltaY;
	updateData = (objBuffer + bezier) + GBUpdateData;
	updateData[GBUpdateX] = (startX * 256);
	updateData[GBUpdateY] = (startY * 256);
	updateData[GBUpdateDX] = fwDx;
	updateData[GBUpdateDY] = fwDy;
	updateData[GBUpdateDDX] = fwDDx;
	updateData[GBUpdateDDY] = fwDDy;
	if (!((startY = objBuffer[bezier + GEYValue]) == yValue)) {
		/* begin stepToNextBezierIn:at: */
		/* begin stepToNextBezierForward:at: */
		lastX = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateX];
		lastY = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateY];
		fwDx1 = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDX];
		fwDy1 = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDY];
		minY = yValue * 256;
		while ((minY > lastY) && (fwDy1 >= 0)) {
			lastX += ((sqInt) (fwDx1 + 32768) >> 16);
			lastY += ((sqInt) (fwDy1 + 32768) >> 16);
			fwDx1 += (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDDX];
			fwDy1 += (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDDY];
		}
		(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateX] = lastX;
		(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateY] = lastY;
		(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDX] = fwDx1;
		(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDY] = fwDy1;
		xValue = ((sqInt) lastX >> 8);
		objBuffer[bezier + GEXValue] = xValue;
		objBuffer[bezier + GENumLines] = (deltaY - (yValue - startY));
	}
}


/*	Initialize the current entry in the GET by stepping to the current scan line */

static sqInt stepToFirstLine(void) {
	return stepToFirstLineInat(getBuffer[workBuffer[GWGETStart]], workBuffer[GWCurrentY]);
}


/*	Initialize the line at yValue */

static sqInt stepToFirstLineInat(sqInt line, sqInt yValue) {
    sqInt xInc;
    sqInt xDir;
    sqInt error;
    sqInt i;
    sqInt deltaX;
    sqInt errorAdjUp;
    sqInt deltaY;
    sqInt startY;
    sqInt widthX;
    sqInt err;
    sqInt x;

	if ((!((((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & GEPrimitiveWide) != 0)) && (yValue >= (objBuffer[line + GLEndY]))) {
		return objBuffer[line + GENumLines] = 0;
	}
	deltaX = (objBuffer[line + GLEndX]) - (objBuffer[line + GEXValue]);

	/* Check if edge goes left to right */

	deltaY = (objBuffer[line + GLEndY]) - (objBuffer[line + GEYValue]);
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
	objBuffer[line + GENumLines] = deltaY;
	objBuffer[line + GLXDirection] = xDir;
	objBuffer[line + GLXIncrement] = xInc;
	objBuffer[line + GLError] = error;
	objBuffer[line + GLErrorAdjUp] = errorAdjUp;
	objBuffer[line + GLErrorAdjDown] = deltaY;
	if (!((startY = objBuffer[line + GEYValue]) == yValue)) {
		for (i = startY; i <= (yValue - 1); i += 1) {
			/* begin stepToNextLineIn:at: */
			x = (objBuffer[line + GEXValue]) + (objBuffer[line + GLXIncrement]);
			err = (objBuffer[line + GLError]) + (objBuffer[line + GLErrorAdjUp]);
			if (err > 0) {
				x += objBuffer[line + GLXDirection];
				err -= objBuffer[line + GLErrorAdjDown];
			}
			objBuffer[line + GLError] = err;
			objBuffer[line + GEXValue] = x;
		}
		objBuffer[line + GENumLines] = (deltaY - (yValue - startY));
	}
}


/*	Initialize the current entry in the GET by stepping to the current scan line */

static sqInt stepToFirstWideBezier(void) {
	return stepToFirstWideBezierInat(getBuffer[workBuffer[GWGETStart]], workBuffer[GWCurrentY]);
}


/*	Initialize the bezier at yValue */

static sqInt stepToFirstWideBezierInat(sqInt bezier, sqInt yValue) {
    sqInt yEntry;
    sqInt lineOffset;
    sqInt lineWidth;
    sqInt endX;
    sqInt xDir;
    sqInt i;
    sqInt nLines;
    sqInt yExit;
    sqInt startY;

	lineWidth = objBuffer[bezier + GBWideExtent];

	/* Compute the incremental values of the bezier */

	lineOffset = ((sqInt) lineWidth >> 1);
	endX = objBuffer[bezier + GBEndX];
	startY = objBuffer[bezier + GEYValue];
	stepToFirstBezierInat(bezier, startY);

	/* Copy the incremental update data */

	nLines = objBuffer[bezier + GENumLines];
	for (i = 0; i <= 5; i += 1) {
		((objBuffer + bezier) + GBWideUpdateData)[i] = (((objBuffer + bezier) + GBUpdateData)[i]);
	}
	xDir = ((objBuffer + bezier) + GBUpdateData)[GBUpdateDX];
	if (xDir == 0) {
		((objBuffer + bezier) + GBUpdateData)[GBUpdateDDX];
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
		((objBuffer + bezier) + GBUpdateData)[GBUpdateX] = ((objBuffer[bezier + GBFinalX]) * 256);
	}
	objBuffer[bezier + GENumLines] = (nLines + lineWidth);

	/* turned on at lineOffset */

	yEntry = 0;

	/* turned off at zero */

	yExit = (0 - nLines) - lineOffset;
	objBuffer[bezier + GBWideEntry] = yEntry;
	objBuffer[bezier + GBWideExit] = yExit;
	if ((yEntry >= lineOffset) && (yExit < 0)) {
		objBuffer[bezier + GEObjectType] = (((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) & (~GEEdgeFillsInvalid));
	} else {
		objBuffer[bezier + GEObjectType] = (((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) | GEEdgeFillsInvalid);
	}
	computeFinalWideBezierValueswidth(bezier, lineWidth);
	if (!(startY == yValue)) {
		for (i = startY; i <= (yValue - 1); i += 1) {
			stepToNextWideBezierInat(bezier, i);
		}
		objBuffer[bezier + GENumLines] = ((objBuffer[bezier + GENumLines]) - (yValue - startY));
	}
}


/*	Initialize the current entry in the GET by stepping to the current scan line */

static sqInt stepToFirstWideLine(void) {
	return stepToFirstWideLineInat(getBuffer[workBuffer[GWGETStart]], workBuffer[GWCurrentY]);
}


/*	Initialize the wide line at yValue. */

static sqInt stepToFirstWideLineInat(sqInt line, sqInt yValue) {
    sqInt yEntry;
    sqInt lineOffset;
    sqInt lineWidth;
    sqInt xDir;
    sqInt i;
    sqInt nLines;
    sqInt startX;
    sqInt yExit;
    sqInt startY;
    sqInt yEntry1;
    sqInt lineOffset1;
    sqInt lineWidth1;
    sqInt lastX;
    sqInt yExit1;
    sqInt nextX;
    sqInt err;
    sqInt x;

	lineWidth = objBuffer[line + GLWideExtent];

	/* Compute the incremental values of the line */

	lineOffset = ((sqInt) lineWidth >> 1);
	startX = objBuffer[line + GEXValue];
	startY = objBuffer[line + GEYValue];
	stepToFirstLineInat(line, startY);
	nLines = objBuffer[line + GENumLines];

	/* Adjust the line to start at the correct X position */

	xDir = objBuffer[line + GLXDirection];
	objBuffer[line + GEXValue] = (startX - lineOffset);
	objBuffer[line + GENumLines] = (nLines + lineWidth);
	if (xDir > 0) {
		objBuffer[line + GLWideWidth] = ((objBuffer[line + GLXIncrement]) + lineWidth);
	} else {
		objBuffer[line + GLWideWidth] = (lineWidth - (objBuffer[line + GLXIncrement]));
		objBuffer[line + GEXValue] = ((objBuffer[line + GEXValue]) + (objBuffer[line + GLXIncrement]));
	}

	/* turned on at lineOffset */

	yEntry = 0;

	/* turned off at zero */

	yExit = (0 - nLines) - lineOffset;
	objBuffer[line + GLWideEntry] = yEntry;
	objBuffer[line + GLWideExit] = yExit;
	if ((yEntry >= lineOffset) && (yExit < 0)) {
		objBuffer[line + GEObjectType] = (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & (~GEEdgeFillsInvalid));
	} else {
		objBuffer[line + GEObjectType] = (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) | GEEdgeFillsInvalid);
	}
	if (!(startY == yValue)) {
		for (i = startY; i <= (yValue - 1); i += 1) {
			/* begin stepToNextWideLineIn:at: */
			yEntry1 = (objBuffer[line + GLWideEntry]) + 1;
			yExit1 = (objBuffer[line + GLWideExit]) + 1;
			objBuffer[line + GLWideEntry] = yEntry1;
			objBuffer[line + GLWideExit] = yExit1;
			lineWidth1 = objBuffer[line + GLWideExtent];
			lineOffset1 = ((sqInt) lineWidth1 >> 1);
			if (yEntry1 >= lineOffset1) {
				objBuffer[line + GEObjectType] = (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & (~GEEdgeFillsInvalid));
			}
			if (yExit1 >= 0) {
				objBuffer[line + GEObjectType] = (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) | GEEdgeFillsInvalid);
			}
			lastX = objBuffer[line + GEXValue];
			/* begin stepToNextLineIn:at: */
			x = (objBuffer[line + GEXValue]) + (objBuffer[line + GLXIncrement]);
			err = (objBuffer[line + GLError]) + (objBuffer[line + GLErrorAdjUp]);
			if (err > 0) {
				x += objBuffer[line + GLXDirection];
				err -= objBuffer[line + GLErrorAdjDown];
			}
			objBuffer[line + GLError] = err;
			objBuffer[line + GEXValue] = x;
			nextX = objBuffer[line + GEXValue];
			if ((yEntry1 <= lineWidth1) || ((yExit1 + lineOffset1) >= 0)) {
				adjustWideLineafterSteppingFromto(line, lastX, nextX);
			}
		}
		objBuffer[line + GENumLines] = ((objBuffer[line + GENumLines]) - (yValue - startY));
	}
}


/*	Process the current entry in the AET by stepping to the next scan line */

static sqInt stepToNextBezier(void) {
    sqInt xValue;
    sqInt fwDy;
    sqInt lastX;
    sqInt minY;
    sqInt lastY;
    sqInt fwDx;

	/* begin stepToNextBezierIn:at: */
	/* begin stepToNextBezierForward:at: */
	lastX = (((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateX];
	lastY = (((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateY];
	fwDx = (((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateDX];
	fwDy = (((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateDY];
	minY = (workBuffer[GWCurrentY]) * 256;
	while ((minY > lastY) && (fwDy >= 0)) {
		lastX += ((sqInt) (fwDx + 32768) >> 16);
		lastY += ((sqInt) (fwDy + 32768) >> 16);
		fwDx += (((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateDDX];
		fwDy += (((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateDDY];
	}
	(((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateX] = lastX;
	(((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateY] = lastY;
	(((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateDX] = fwDx;
	(((int*) ((objBuffer + (aetBuffer[workBuffer[GWAETStart]])) + GBUpdateData)))[GBUpdateDY] = fwDy;
	xValue = ((sqInt) lastX >> 8);
	objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GEXValue] = xValue;
	return null;
}


/*	Incrementally step to the next scan line in the given bezier update data.
	Note: This method has been written so that inlining works, e.g.,
		not declaring updateData as 'int*' but casting it on every use. */

static sqInt stepToNextBezierForwardat(sqInt updateData, sqInt yValue) {
    sqInt fwDy;
    sqInt lastX;
    sqInt minY;
    sqInt lastY;
    sqInt fwDx;

	lastX = (((int*) updateData))[GBUpdateX];
	lastY = (((int*) updateData))[GBUpdateY];
	fwDx = (((int*) updateData))[GBUpdateDX];
	fwDy = (((int*) updateData))[GBUpdateDY];

	/* Step as long as we haven't yet reached minY and also
	as long as fwDy is greater than zero thus stepping down.
	Note: The test for fwDy should not be necessary in theory
		but is a good insurance in practice. */

	minY = yValue * 256;
	while ((minY > lastY) && (fwDy >= 0)) {
		lastX += ((sqInt) (fwDx + 32768) >> 16);
		lastY += ((sqInt) (fwDy + 32768) >> 16);
		fwDx += (((int*) updateData))[GBUpdateDDX];
		fwDy += (((int*) updateData))[GBUpdateDDY];
	}
	(((int*) updateData))[GBUpdateX] = lastX;
	(((int*) updateData))[GBUpdateY] = lastY;
	(((int*) updateData))[GBUpdateDX] = fwDx;
	(((int*) updateData))[GBUpdateDY] = fwDy;
	return ((sqInt) lastX >> 8);
}


/*	Incrementally step to the next scan line in the given bezier */

static sqInt stepToNextBezierInat(sqInt bezier, sqInt yValue) {
    sqInt xValue;
    sqInt fwDy;
    sqInt lastX;
    sqInt minY;
    sqInt lastY;
    sqInt fwDx;

	/* begin stepToNextBezierForward:at: */
	lastX = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateX];
	lastY = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateY];
	fwDx = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDX];
	fwDy = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDY];
	minY = yValue * 256;
	while ((minY > lastY) && (fwDy >= 0)) {
		lastX += ((sqInt) (fwDx + 32768) >> 16);
		lastY += ((sqInt) (fwDy + 32768) >> 16);
		fwDx += (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDDX];
		fwDy += (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDDY];
	}
	(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateX] = lastX;
	(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateY] = lastY;
	(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDX] = fwDx;
	(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDY] = fwDy;
	xValue = ((sqInt) lastX >> 8);
	objBuffer[bezier + GEXValue] = xValue;
}


/*	Process the current entry in the AET by stepping to the next scan line */

static sqInt stepToNextLine(void) {
    sqInt err;
    sqInt x;

	/* begin stepToNextLineIn:at: */
	x = (objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GEXValue]) + (objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GLXIncrement]);
	err = (objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GLError]) + (objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GLErrorAdjUp]);
	if (err > 0) {
		x += objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GLXDirection];
		err -= objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GLErrorAdjDown];
	}
	objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GLError] = err;
	objBuffer[(aetBuffer[workBuffer[GWAETStart]]) + GEXValue] = x;
	return null;
}


/*	Incrementally step to the next scan line in the given line */

static sqInt stepToNextLineInat(sqInt line, sqInt yValue) {
    sqInt err;
    sqInt x;

	x = (objBuffer[line + GEXValue]) + (objBuffer[line + GLXIncrement]);
	err = (objBuffer[line + GLError]) + (objBuffer[line + GLErrorAdjUp]);
	if (err > 0) {
		x += objBuffer[line + GLXDirection];
		err -= objBuffer[line + GLErrorAdjDown];
	}
	objBuffer[line + GLError] = err;
	objBuffer[line + GEXValue] = x;
}


/*	Initialize the current entry in the GET by stepping to the current scan line */

static sqInt stepToNextWideBezier(void) {
	stepToNextWideBezierInat(aetBuffer[workBuffer[GWAETStart]], workBuffer[GWCurrentY]);
}


/*	Incrementally step to the next scan line in the given wide bezier */

static sqInt stepToNextWideBezierInat(sqInt bezier, sqInt yValue) {
    sqInt yEntry;
    sqInt lineOffset;
    sqInt lineWidth;
    sqInt yExit;
    sqInt fwDy;
    sqInt lastX;
    sqInt minY;
    sqInt lastY;
    sqInt fwDx;
    sqInt fwDy1;
    sqInt lastX1;
    sqInt minY1;
    sqInt lastY1;
    sqInt fwDx1;

	lineWidth = objBuffer[bezier + GBWideExtent];
	lineOffset = ((sqInt) lineWidth >> 1);
	yEntry = (objBuffer[bezier + GBWideEntry]) + 1;
	yExit = (objBuffer[bezier + GBWideExit]) + 1;
	objBuffer[bezier + GBWideEntry] = yEntry;
	objBuffer[bezier + GBWideExit] = yExit;
	if (yEntry >= lineOffset) {
		objBuffer[bezier + GEObjectType] = (((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) & (~GEEdgeFillsInvalid));
	}
	if (yExit >= 0) {
		objBuffer[bezier + GEObjectType] = (((objBuffer[bezier + GEObjectType]) & GEPrimitiveTypeMask) | GEEdgeFillsInvalid);
	}
	if ((yExit + lineOffset) < 0) {
		/* begin stepToNextBezierForward:at: */
		lastX = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateX];
		lastY = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateY];
		fwDx = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDX];
		fwDy = (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDY];
		minY = yValue * 256;
		while ((minY > lastY) && (fwDy >= 0)) {
			lastX += ((sqInt) (fwDx + 32768) >> 16);
			lastY += ((sqInt) (fwDy + 32768) >> 16);
			fwDx += (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDDX];
			fwDy += (((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDDY];
		}
		(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateX] = lastX;
		(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateY] = lastY;
		(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDX] = fwDx;
		(((int*) ((objBuffer + bezier) + GBUpdateData)))[GBUpdateDY] = fwDy;
		((sqInt) lastX >> 8);
	} else {
		((objBuffer + bezier) + GBUpdateData)[GBUpdateX] = ((objBuffer[bezier + GBFinalX]) * 256);
	}
	/* begin stepToNextBezierForward:at: */
	lastX1 = (((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateX];
	lastY1 = (((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateY];
	fwDx1 = (((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateDX];
	fwDy1 = (((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateDY];
	minY1 = yValue * 256;
	while ((minY1 > lastY1) && (fwDy1 >= 0)) {
		lastX1 += ((sqInt) (fwDx1 + 32768) >> 16);
		lastY1 += ((sqInt) (fwDy1 + 32768) >> 16);
		fwDx1 += (((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateDDX];
		fwDy1 += (((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateDDY];
	}
	(((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateX] = lastX1;
	(((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateY] = lastY1;
	(((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateDX] = fwDx1;
	(((int*) ((objBuffer + bezier) + GBWideUpdateData)))[GBUpdateDY] = fwDy1;
	((sqInt) lastX1 >> 8);
	computeFinalWideBezierValueswidth(bezier, lineWidth);
}


/*	Process the current entry in the AET by stepping to the next scan line */

static sqInt stepToNextWideLine(void) {
    sqInt line;
    sqInt yValue;
    sqInt yEntry;
    sqInt lineOffset;
    sqInt lineWidth;
    sqInt lastX;
    sqInt yExit;
    sqInt nextX;
    sqInt err;
    sqInt x;

	/* begin stepToNextWideLineIn:at: */
	line = aetBuffer[workBuffer[GWAETStart]];
	yValue = workBuffer[GWCurrentY];
	yEntry = (objBuffer[line + GLWideEntry]) + 1;
	yExit = (objBuffer[line + GLWideExit]) + 1;
	objBuffer[line + GLWideEntry] = yEntry;
	objBuffer[line + GLWideExit] = yExit;
	lineWidth = objBuffer[line + GLWideExtent];
	lineOffset = ((sqInt) lineWidth >> 1);
	if (yEntry >= lineOffset) {
		objBuffer[line + GEObjectType] = (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & (~GEEdgeFillsInvalid));
	}
	if (yExit >= 0) {
		objBuffer[line + GEObjectType] = (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) | GEEdgeFillsInvalid);
	}
	lastX = objBuffer[line + GEXValue];
	/* begin stepToNextLineIn:at: */
	x = (objBuffer[line + GEXValue]) + (objBuffer[line + GLXIncrement]);
	err = (objBuffer[line + GLError]) + (objBuffer[line + GLErrorAdjUp]);
	if (err > 0) {
		x += objBuffer[line + GLXDirection];
		err -= objBuffer[line + GLErrorAdjDown];
	}
	objBuffer[line + GLError] = err;
	objBuffer[line + GEXValue] = x;
	nextX = objBuffer[line + GEXValue];
	if ((yEntry <= lineWidth) || ((yExit + lineOffset) >= 0)) {
		adjustWideLineafterSteppingFromto(line, lastX, nextX);
	}
	return null;
}


/*	Incrementally step to the next scan line in the given wide line */

static sqInt stepToNextWideLineInat(sqInt line, sqInt yValue) {
    sqInt yEntry;
    sqInt lineOffset;
    sqInt lineWidth;
    sqInt lastX;
    sqInt yExit;
    sqInt nextX;
    sqInt err;
    sqInt x;

	yEntry = (objBuffer[line + GLWideEntry]) + 1;
	yExit = (objBuffer[line + GLWideExit]) + 1;
	objBuffer[line + GLWideEntry] = yEntry;
	objBuffer[line + GLWideExit] = yExit;
	lineWidth = objBuffer[line + GLWideExtent];
	lineOffset = ((sqInt) lineWidth >> 1);
	if (yEntry >= lineOffset) {
		objBuffer[line + GEObjectType] = (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) & (~GEEdgeFillsInvalid));
	}
	if (yExit >= 0) {
		objBuffer[line + GEObjectType] = (((objBuffer[line + GEObjectType]) & GEPrimitiveTypeMask) | GEEdgeFillsInvalid);
	}
	lastX = objBuffer[line + GEXValue];
	/* begin stepToNextLineIn:at: */
	x = (objBuffer[line + GEXValue]) + (objBuffer[line + GLXIncrement]);
	err = (objBuffer[line + GLError]) + (objBuffer[line + GLErrorAdjUp]);
	if (err > 0) {
		x += objBuffer[line + GLXDirection];
		err -= objBuffer[line + GLErrorAdjDown];
	}
	objBuffer[line + GLError] = err;
	objBuffer[line + GEXValue] = x;

	/* Check for special start/end adjustments */

	nextX = objBuffer[line + GEXValue];
	if ((yEntry <= lineWidth) || ((yExit + lineOffset) >= 0)) {
		adjustWideLineafterSteppingFromto(line, lastX, nextX);
	}
}

static sqInt stopBecauseOf(sqInt stopReason) {
	workBuffer[GWStopReason] = stopReason;
	engineStopped = 1;
}

static sqInt stopReasonGet(void) {
	return workBuffer[GWStopReason];
}

static sqInt stopReasonPut(sqInt value) {
	return workBuffer[GWStopReason] = value;
}

static sqInt storeEdgeStateFrominto(sqInt edge, sqInt edgeOop) {
	if ((interpreterProxy->slotSizeOf(edgeOop)) < ETBalloonEdgeDataSize) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->storeIntegerofObjectwithValue(ETIndexIndex, edgeOop, objBuffer[edge + GEObjectIndex]);
	interpreterProxy->storeIntegerofObjectwithValue(ETXValueIndex, edgeOop, objBuffer[edge + GEXValue]);
	interpreterProxy->storeIntegerofObjectwithValue(ETYValueIndex, edgeOop, workBuffer[GWCurrentY]);
	interpreterProxy->storeIntegerofObjectwithValue(ETZValueIndex, edgeOop, objBuffer[edge + GEZValue]);
	interpreterProxy->storeIntegerofObjectwithValue(ETLinesIndex, edgeOop, objBuffer[edge + GENumLines]);
	workBuffer[GWLastExportedEdge] = edge;
}

static sqInt storeEngineStateInto(sqInt oop) {
	workBuffer[GWObjUsed] = objUsed;
}

static sqInt storeFillStateInto(sqInt fillOop) {
    sqInt leftX;
    sqInt rightX;
    sqInt fillIndex;

	fillIndex = workBuffer[GWLastExportedFill];
	leftX = workBuffer[GWLastExportedLeftX];
	rightX = workBuffer[GWLastExportedRightX];
	if ((interpreterProxy->slotSizeOf(fillOop)) < FTBalloonFillDataSize) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->storeIntegerofObjectwithValue(FTIndexIndex, fillOop, objBuffer[fillIndex + GEObjectIndex]);
	interpreterProxy->storeIntegerofObjectwithValue(FTMinXIndex, fillOop, leftX);
	interpreterProxy->storeIntegerofObjectwithValue(FTMaxXIndex, fillOop, rightX);
	interpreterProxy->storeIntegerofObjectwithValue(FTYValueIndex, fillOop, workBuffer[GWCurrentY]);
}

static sqInt storeRenderingState(void) {
    sqInt edgeOop;
    sqInt fillOop;
    sqInt reason;
    sqInt edge;

	if (interpreterProxy->failed()) {
		return null;
	}
	if (engineStopped) {
		/* begin storeStopStateIntoEdge:fill: */
		edgeOop = interpreterProxy->stackObjectValue(1);
		fillOop = interpreterProxy->stackObjectValue(0);
		reason = workBuffer[GWStopReason];
		if (reason == GErrorGETEntry) {
			edge = getBuffer[workBuffer[GWGETStart]];
			storeEdgeStateFrominto(edge, edgeOop);
			workBuffer[GWGETStart] = ((workBuffer[GWGETStart]) + 1);
		}
		if (reason == GErrorFillEntry) {
			storeFillStateInto(fillOop);
		}
		if (reason == GErrorAETEntry) {
			edge = aetBuffer[workBuffer[GWAETStart]];
			storeEdgeStateFrominto(edge, edgeOop);
		}
	}
	/* begin storeEngineStateInto: */
	workBuffer[GWObjUsed] = objUsed;
	interpreterProxy->pop(3);
	interpreterProxy->pushInteger(workBuffer[GWStopReason]);
}

static sqInt storeStopStateIntoEdgefill(sqInt edgeOop, sqInt fillOop) {
    sqInt reason;
    sqInt edge;

	reason = workBuffer[GWStopReason];
	if (reason == GErrorGETEntry) {
		edge = getBuffer[workBuffer[GWGETStart]];
		storeEdgeStateFrominto(edge, edgeOop);
		workBuffer[GWGETStart] = ((workBuffer[GWGETStart]) + 1);
	}
	if (reason == GErrorFillEntry) {
		storeFillStateInto(fillOop);
	}
	if (reason == GErrorAETEntry) {
		edge = aetBuffer[workBuffer[GWAETStart]];
		storeEdgeStateFrominto(edge, edgeOop);
	}
}


/*	Subdivide the given bezier curve if necessary */

static sqInt subdivideBezier(sqInt index) {
    sqInt endX;
    sqInt deltaX;
    sqInt startX;
    sqInt endY;
    sqInt deltaY;
    sqInt startY;

	startY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)];

	/* If the receiver is horizontal, don't do anything */

	endY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)];
	if (endY == startY) {
		return index;
	}
	deltaY = endY - startY;
	if (deltaY < 0) {
		deltaY = 0 - deltaY;
	}
	if (deltaY > 255) {
		workBuffer[GWBezierHeightSubdivisions] = ((workBuffer[GWBezierHeightSubdivisions]) + 1);
		return computeBezierSplitAtHalf(index);
	}
	startX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 0)];
	endX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)];
	deltaX = endX - startX;
	if (deltaX < 0) {
		deltaX = 0 - deltaX;
	}
	if ((deltaY * 32) < deltaX) {
		workBuffer[GWBezierOverflowSubdivisions] = ((workBuffer[GWBezierOverflowSubdivisions]) + 1);
		return computeBezierSplitAtHalf(index);
	}
	return index;
}


/*	Recursively subdivide the curve on the bezier stack. */

static sqInt subdivideBezierFrom(sqInt index) {
    sqInt index2;
    sqInt otherIndex;
    sqInt index1;

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

static sqInt subdivideToBeMonotoninX(sqInt base, sqInt doTestX) {
    sqInt base2;
    sqInt index2;
    sqInt index1;

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

static sqInt subdivideToBeMonotonInX(sqInt index) {
    sqInt num;
    sqInt endX;
    sqInt dx1;
    sqInt startX;
    sqInt denom;
    sqInt dx2;
    sqInt viaX;

	startX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 0)];
	viaX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 2)];
	endX = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 4)];
	dx1 = viaX - startX;
	dx2 = endX - viaX;
	if ((dx1 * dx2) >= 0) {
		return index;
	}
	workBuffer[GWBezierMonotonSubdivisions] = ((workBuffer[GWBezierMonotonSubdivisions]) + 1);
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

static sqInt subdivideToBeMonotonInY(sqInt index) {
    sqInt num;
    sqInt viaY;
    sqInt endY;
    sqInt dy1;
    sqInt denom;
    sqInt startY;
    sqInt dy2;

	startY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 1)];
	viaY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 3)];
	endY = workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - index) + 5)];
	dy1 = viaY - startY;
	dy2 = endY - viaY;
	if ((dy1 * dy2) >= 0) {
		return index;
	}
	workBuffer[GWBezierMonotonSubdivisions] = ((workBuffer[GWBezierMonotonSubdivisions]) + 1);
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

static sqInt toggleFilldepthrightX(sqInt fillIndex, sqInt depth, sqInt rightX) {
    sqInt hidden;

	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		if (wbStackPush(3)) {
			workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)] = fillIndex;
			workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 1)] = depth;
			workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)] = rightX;
		}
	} else {
		hidden = hideFilldepth(fillIndex, depth);
		if (!(hidden)) {
			showFilldepthrightX(fillIndex, depth, rightX);
		}
	}
}

static sqInt toggleFillsOf(sqInt edge) {
    sqInt fillIndex;
    sqInt depth;
    sqInt leftX;

	if (!(needAvailableSpace(3 * 2))) {
		return null;
	}
	depth = (objBuffer[edge + GEZValue]) << 1;
	fillIndex = objBuffer[edge + GEFillIndexLeft];
	if (!(fillIndex == 0)) {
		toggleFilldepthrightX(fillIndex, depth, 999999999);
	}
	fillIndex = objBuffer[edge + GEFillIndexRight];
	if (!(fillIndex == 0)) {
		toggleFilldepthrightX(fillIndex, depth, 999999999);
	}
	/* begin quickRemoveInvalidFillsAt: */
	leftX = objBuffer[edge + GEXValue];
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		goto l1;
	}
	while ((topRightX()) <= leftX) {
		hideFilldepth(topFill(), topDepth());
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			goto l1;
		}
	}
l1:	/* end quickRemoveInvalidFillsAt: */;
}

static sqInt toggleWideFillOf(sqInt edge) {
    sqInt lineWidth;
    sqInt index;
    sqInt rightX;
    sqInt depth;
    sqInt fill;
    sqInt type;
    sqInt leftX;

	type = ((usqInt) ((objBuffer[edge + GEObjectType]) & GEPrimitiveTypeMask)) >> 1;
	dispatchedValue = edge;
	switch (type) {
	case 0:
	case 1:
		errorWrongIndex();
		break;
	case 2:
		dispatchReturnValue = objBuffer[dispatchedValue + GLWideWidth];
		break;
	case 3:
		dispatchReturnValue = objBuffer[dispatchedValue + GBWideWidth];
		break;
	}
	lineWidth = dispatchReturnValue;
	switch (type) {
	case 0:
	case 1:
		errorWrongIndex();
		break;
	case 2:
		dispatchReturnValue = objBuffer[dispatchedValue + GLWideFill];
		break;
	case 3:
		dispatchReturnValue = objBuffer[dispatchedValue + GBWideFill];
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

	depth = ((objBuffer[edge + GEZValue]) << 1) + 1;
	rightX = (objBuffer[edge + GEXValue]) + lineWidth;
	index = findStackFilldepth(fill, depth);
	if (index == -1) {
		showFilldepthrightX(fill, depth, rightX);
	} else {
		if ((workBuffer[(workBuffer[GWBufferTop]) + (index + 2)]) < rightX) {
			workBuffer[(workBuffer[GWBufferTop]) + (index + 2)] = rightX;
		}
	}
	/* begin quickRemoveInvalidFillsAt: */
	leftX = objBuffer[edge + GEXValue];
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		goto l1;
	}
	while ((topRightX()) <= leftX) {
		hideFilldepth(topFill(), topDepth());
		if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
			goto l1;
		}
	}
l1:	/* end quickRemoveInvalidFillsAt: */;
}

static sqInt topDepth(void) {
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		return -1;
	} else {
		return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 1)];
	}
}

static sqInt topFill(void) {
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		return 0;
	} else {
		return workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
	}
}

static sqInt topFillDepth(void) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 1)];
}

static sqInt topFillDepthPut(sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 1)] = value;
}

static sqInt topFillRightX(void) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)];
}

static sqInt topFillRightXPut(sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)] = value;
}

static sqInt topFillValue(void) {
	return workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)];
}

static sqInt topFillValuePut(sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3)] = value;
}

static sqInt topRightX(void) {
	if (((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) == 0) {
		return 999999999;
	} else {
		return workBuffer[(workBuffer[GWBufferTop]) + ((((workBuffer[GWSize]) - (workBuffer[GWBufferTop])) - 3) + 2)];
	}
}

static sqInt transformColor(sqInt fillIndex) {
    sqInt a;
    float * transform;
    sqInt b;
    sqInt g;
    double  alphaScale;
    sqInt r;

	if (!((fillIndex == 0) || ((fillIndex & 4278190080U) != 0))) {
		return fillIndex;
	}
	b = fillIndex & 255;
	g = (((usqInt) fillIndex) >> 8) & 255;
	r = (((usqInt) fillIndex) >> 16) & 255;
	a = (((usqInt) fillIndex) >> 24) & 255;
	if ((workBuffer[GWHasColorTransform]) != 0) {
		transform = ((float *) (workBuffer + GWColorTransform));
		alphaScale = ((a * (transform[6])) + (transform[7])) / a;
		r = ((sqInt) (((r * (transform[0])) + (transform[1])) * alphaScale) );
		g = ((sqInt) (((g * (transform[2])) + (transform[3])) * alphaScale) );
		b = ((sqInt) (((b * (transform[4])) + (transform[5])) * alphaScale) );
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
	if ((a < 255) && ((workBuffer[GWNeedsFlush]) != 0)) {
		/* begin stopBecauseOf: */
		workBuffer[GWStopReason] = GErrorNeedFlush;
		engineStopped = 1;
	}
	return ((b + (g << 8)) + (r << 16)) + (a << 24);
}


/*	Transform the given point. If haveMatrix is true then use the current transformation. */

static sqInt transformPoint(int * point) {
	if ((workBuffer[GWHasEdgeTransform]) != 0) {
		/* begin transformPoint:into: */
		transformPointXyinto(((double) ((((int *) point))[0]) ), ((double) ((((int *) point))[1]) ), ((int *) point));
	} else {
		point[0] = (((point[0]) + (workBuffer[GWDestOffsetX])) * (workBuffer[GWAALevel]));
		point[1] = (((point[1]) + (workBuffer[GWDestOffsetY])) * (workBuffer[GWAALevel]));
	}
}


/*	Transform srcPoint into dstPoint by using the currently loaded matrix */
/*	Note: This method has been rewritten so that inlining works (e.g., removing
	the declarations and adding argument coercions at the appropriate points) */

static sqInt transformPointinto(sqInt srcPoint, sqInt dstPoint) {
	transformPointXyinto(((double) ((((int *) srcPoint))[0]) ), ((double) ((((int *) srcPoint))[1]) ), ((int *) dstPoint));
}


/*	Transform srcPoint into dstPoint by using the currently loaded matrix */
/*	Note: This should be rewritten so that inlining works (e.g., removing
	the declarations and adding argument coercions at the appropriate points) */

static sqInt transformPointXyinto(double  xValue, double  yValue, int * dstPoint) {
    sqInt x;
    float * transform;
    sqInt y;

	transform = ((float *) (workBuffer + GWEdgeTransform));
	x = ((sqInt) (((((transform[0]) * xValue) + ((transform[1]) * yValue)) + (transform[2])) * (((double) (workBuffer[GWAALevel]) ))) );
	y = ((sqInt) (((((transform[3]) * xValue) + ((transform[4]) * yValue)) + (transform[5])) * (((double) (workBuffer[GWAALevel]) ))) );
	dstPoint[0] = x;
	dstPoint[1] = y;
}


/*	Transform n (n=1,2,3) points.
	If haveMatrix is true then the matrix contains the actual transformation. */

static sqInt transformPoints(sqInt n) {
	if (n > 0) {
		transformPoint(((int *) (workBuffer + GWPoint1)));
	}
	if (n > 1) {
		transformPoint(((int *) (workBuffer + GWPoint2)));
	}
	if (n > 2) {
		transformPoint(((int *) (workBuffer + GWPoint3)));
	}
	if (n > 3) {
		transformPoint(((int *) (workBuffer + GWPoint4)));
	}
}


/*	Transform the given width */

static sqInt transformWidth(sqInt w) {
    sqInt dstWidth;
    double  deltaX;
    double  deltaY;
    sqInt dstWidth2;

	if (w == 0) {
		return 0;
	}
	(((int *) (workBuffer + GWPoint1)))[0] = 0;
	(((int *) (workBuffer + GWPoint1)))[1] = 0;
	(((int *) (workBuffer + GWPoint2)))[0] = (w * 256);
	(((int *) (workBuffer + GWPoint2)))[1] = 0;
	(((int *) (workBuffer + GWPoint3)))[0] = 0;
	(((int *) (workBuffer + GWPoint3)))[1] = (w * 256);
	/* begin transformPoints: */
	if (3 > 0) {
		transformPoint(((int *) (workBuffer + GWPoint1)));
	}
	if (3 > 1) {
		transformPoint(((int *) (workBuffer + GWPoint2)));
	}
	if (3 > 2) {
		transformPoint(((int *) (workBuffer + GWPoint3)));
	}
	if (3 > 3) {
		transformPoint(((int *) (workBuffer + GWPoint4)));
	}
	deltaX = ((double) (((((int *) (workBuffer + GWPoint2)))[0]) - ((((int *) (workBuffer + GWPoint1)))[0])) );
	deltaY = ((double) (((((int *) (workBuffer + GWPoint2)))[1]) - ((((int *) (workBuffer + GWPoint1)))[1])) );
	dstWidth = ((sqInt) ((((sqInt) (sqrt((deltaX * deltaX) + (deltaY * deltaY))) )) + 128) >> 8);
	deltaX = ((double) (((((int *) (workBuffer + GWPoint3)))[0]) - ((((int *) (workBuffer + GWPoint1)))[0])) );
	deltaY = ((double) (((((int *) (workBuffer + GWPoint3)))[1]) - ((((int *) (workBuffer + GWPoint1)))[1])) );
	dstWidth2 = ((sqInt) ((((sqInt) (sqrt((deltaX * deltaX) + (deltaY * deltaY))) )) + 128) >> 8);
	if (dstWidth2 < dstWidth) {
		dstWidth = dstWidth2;
	}
	if (dstWidth == 0) {
		return 1;
	} else {
		return dstWidth;
	}
}

static sqInt uncheckedTransformColor(sqInt fillIndex) {
    sqInt a;
    float * transform;
    sqInt b;
    sqInt g;
    sqInt r;

	if (!((workBuffer[GWHasColorTransform]) != 0)) {
		return fillIndex;
	}
	b = fillIndex & 255;
	g = (((usqInt) fillIndex) >> 8) & 255;
	r = (((usqInt) fillIndex) >> 16) & 255;
	a = (((usqInt) fillIndex) >> 24) & 255;
	transform = ((float *) (workBuffer + GWColorTransform));
	r = ((sqInt) ((r * (transform[0])) + (transform[1])) );
	g = ((sqInt) ((g * (transform[2])) + (transform[3])) );
	b = ((sqInt) ((b * (transform[4])) + (transform[5])) );
	a = ((sqInt) ((a * (transform[6])) + (transform[7])) );
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

static sqInt wbSizeGet(void) {
	return workBuffer[GWSize];
}

static sqInt wbSizePut(sqInt value) {
	return workBuffer[GWSize] = value;
}

static sqInt wbStackClear(void) {
	workBuffer[GWBufferTop] = (workBuffer[GWSize]);
}

static sqInt wbStackPop(sqInt nItems) {
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) + nItems);
}

static sqInt wbStackPush(sqInt nItems) {
	if (!(needAvailableSpace(nItems))) {
		return 0;
	}
	workBuffer[GWBufferTop] = ((workBuffer[GWBufferTop]) - nItems);
	return 1;
}

static sqInt wbStackSize(void) {
	return (workBuffer[GWSize]) - (workBuffer[GWBufferTop]);
}

static sqInt wbStackValue(sqInt index) {
	return workBuffer[(workBuffer[GWBufferTop]) + index];
}

static sqInt wbStackValueput(sqInt index, sqInt value) {
	return workBuffer[(workBuffer[GWBufferTop]) + index] = value;
}

static sqInt wbTopGet(void) {
	return workBuffer[GWBufferTop];
}

static sqInt wbTopPut(sqInt value) {
	return workBuffer[GWBufferTop] = value;
}

static sqInt wideBezierEntryOf(sqInt line) {
	return objBuffer[line + GBWideEntry];
}

static sqInt wideBezierEntryOfput(sqInt line, sqInt value) {
	return objBuffer[line + GBWideEntry] = value;
}

static sqInt wideBezierExitOf(sqInt line) {
	return objBuffer[line + GBWideExit];
}

static sqInt wideBezierExitOfput(sqInt line, sqInt value) {
	return objBuffer[line + GBWideExit] = value;
}

static sqInt wideBezierExtentOf(sqInt bezier) {
	return objBuffer[bezier + GBWideExtent];
}

static sqInt wideBezierExtentOfput(sqInt bezier, sqInt value) {
	return objBuffer[bezier + GBWideExtent] = value;
}

static sqInt wideBezierFillOf(sqInt bezier) {
	return objBuffer[bezier + GBWideFill];
}

static sqInt wideBezierFillOfput(sqInt bezier, sqInt value) {
	return objBuffer[bezier + GBWideFill] = value;
}

static int * wideBezierUpdateDataOf(sqInt bezier) {
	return (objBuffer + bezier) + GBWideUpdateData;
}

static sqInt wideBezierWidthOf(sqInt line) {
	return objBuffer[line + GBWideWidth];
}

static sqInt wideBezierWidthOfput(sqInt line, sqInt value) {
	return objBuffer[line + GBWideWidth] = value;
}

static sqInt wideLineEntryOf(sqInt line) {
	return objBuffer[line + GLWideEntry];
}

static sqInt wideLineEntryOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLWideEntry] = value;
}

static sqInt wideLineExitOf(sqInt line) {
	return objBuffer[line + GLWideExit];
}

static sqInt wideLineExitOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLWideExit] = value;
}

static sqInt wideLineExtentOf(sqInt line) {
	return objBuffer[line + GLWideExtent];
}

static sqInt wideLineExtentOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLWideExtent] = value;
}

static sqInt wideLineFillOf(sqInt line) {
	return objBuffer[line + GLWideFill];
}

static sqInt wideLineFillOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLWideFill] = value;
}

static sqInt wideLineWidthOf(sqInt line) {
	return objBuffer[line + GLWideWidth];
}

static sqInt wideLineWidthOfput(sqInt line, sqInt value) {
	return objBuffer[line + GLWideWidth] = value;
}

static sqInt workBufferPut(sqInt wbOop) {
	workBuffer = interpreterProxy->firstIndexableField(wbOop);
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* B2DPlugin_exports[][3] = {
	{"B2DPlugin", "primitiveMergeFillFrom", (void*)primitiveMergeFillFrom},
	{"B2DPlugin", "primitiveAbortProcessing", (void*)primitiveAbortProcessing},
	{"B2DPlugin", "setInterpreter", (void*)setInterpreter},
	{"B2DPlugin", "primitiveGetClipRect", (void*)primitiveGetClipRect},
	{"B2DPlugin", "primitiveRenderImage", (void*)primitiveRenderImage},
	{"B2DPlugin", "primitiveGetBezierStats", (void*)primitiveGetBezierStats},
	{"B2DPlugin", "primitiveDisplaySpanBuffer", (void*)primitiveDisplaySpanBuffer},
	{"B2DPlugin", "primitiveAddGradientFill", (void*)primitiveAddGradientFill},
	{"B2DPlugin", "primitiveSetOffset", (void*)primitiveSetOffset},
	{"B2DPlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"B2DPlugin", "initialiseModule", (void*)initialiseModule},
	{"B2DPlugin", "primitiveRenderScanline", (void*)primitiveRenderScanline},
	{"B2DPlugin", "primitiveRegisterExternalFill", (void*)primitiveRegisterExternalFill},
	{"B2DPlugin", "primitiveGetFailureReason", (void*)primitiveGetFailureReason},
	{"B2DPlugin", "primitiveCopyBuffer", (void*)primitiveCopyBuffer},
	{"B2DPlugin", "primitiveInitializeProcessing", (void*)primitiveInitializeProcessing},
	{"B2DPlugin", "primitiveNextGlobalEdgeEntry", (void*)primitiveNextGlobalEdgeEntry},
	{"B2DPlugin", "primitiveNextActiveEdgeEntry", (void*)primitiveNextActiveEdgeEntry},
	{"B2DPlugin", "primitiveAddRect", (void*)primitiveAddRect},
	{"B2DPlugin", "primitiveSetBitBltPlugin", (void*)primitiveSetBitBltPlugin},
	{"B2DPlugin", "primitiveAddCompressedShape", (void*)primitiveAddCompressedShape},
	{"B2DPlugin", "primitiveSetAALevel", (void*)primitiveSetAALevel},
	{"B2DPlugin", "primitiveGetTimes", (void*)primitiveGetTimes},
	{"B2DPlugin", "primitiveNeedsFlushPut", (void*)primitiveNeedsFlushPut},
	{"B2DPlugin", "primitiveGetAALevel", (void*)primitiveGetAALevel},
	{"B2DPlugin", "primitiveSetColorTransform", (void*)primitiveSetColorTransform},
	{"B2DPlugin", "primitiveAddBitmapFill", (void*)primitiveAddBitmapFill},
	{"B2DPlugin", "primitiveAddPolygon", (void*)primitiveAddPolygon},
	{"B2DPlugin", "getModuleName", (void*)getModuleName},
	{"B2DPlugin", "primitiveSetClipRect", (void*)primitiveSetClipRect},
	{"B2DPlugin", "primitiveDoProfileStats", (void*)primitiveDoProfileStats},
	{"B2DPlugin", "primitiveInitializeBuffer", (void*)primitiveInitializeBuffer},
	{"B2DPlugin", "primitiveFinishedProcessing", (void*)primitiveFinishedProcessing},
	{"B2DPlugin", "primitiveNextFillEntry", (void*)primitiveNextFillEntry},
	{"B2DPlugin", "primitiveGetOffset", (void*)primitiveGetOffset},
	{"B2DPlugin", "primitiveAddOval", (void*)primitiveAddOval},
	{"B2DPlugin", "primitiveGetDepth", (void*)primitiveGetDepth},
	{"B2DPlugin", "primitiveAddLine", (void*)primitiveAddLine},
	{"B2DPlugin", "primitiveAddBezier", (void*)primitiveAddBezier},
	{"B2DPlugin", "primitiveGetCounts", (void*)primitiveGetCounts},
	{"B2DPlugin", "primitiveSetEdgeTransform", (void*)primitiveSetEdgeTransform},
	{"B2DPlugin", "primitiveAddBezierShape", (void*)primitiveAddBezierShape},
	{"B2DPlugin", "primitiveChangedActiveEdgeEntry", (void*)primitiveChangedActiveEdgeEntry},
	{"B2DPlugin", "primitiveRegisterExternalEdge", (void*)primitiveRegisterExternalEdge},
	{"B2DPlugin", "primitiveSetDepth", (void*)primitiveSetDepth},
	{"B2DPlugin", "primitiveAddActiveEdgeEntry", (void*)primitiveAddActiveEdgeEntry},
	{"B2DPlugin", "primitiveNeedsFlush", (void*)primitiveNeedsFlush},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */


