/****************************************************************************
*   PROJECT: Common include
*   FILE:    sq.h
*   CONTENT: 
*
*   AUTHOR:  
*   ADDRESS: 
*   EMAIL:   
*   RCSID:   $Id: sq.h 931 2004-12-08 01:32:15Z rowledge $
*
*	09/22/04	tim & jmm - add menu and window event types
*	03/26/04	tim - add primitive dispatch macro/typedef
*	11/12/03	nedkonz - float bug fix for gcc 3.3 optimization
*	05/20/03	tim - move browser related macros in front of
*			include of sqPlatformSpecific.h
*	02/26/03	tim change browser plugin support code
*	01/28/02	Tim add macro default for sqFilenameFromStringOpen
*		and sqFTruncate
*	01/22/2002 JMM change off_t to squeakOffsetFileType
*/
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
#define sqImageFileStartLocation(fileRef, fileName, size)  0

/* platform-dependent float conversion macros */
/* Note: Second argument must be a variable name, not an expression! */
/* Note: Floats in image are always in PowerPC word order; change
   these macros to swap words if necessary. This costs no extra and
   obviates sometimes having to word-swap floats when reading an image.
*/
#if defined(DOUBLE_WORD_ALIGNMENT) || defined(DOUBLE_WORD_ORDER)
/* this is to allow strict aliasing assumption in the optimizer */
typedef union { double d; int i[sizeof(double) / sizeof(int)]; } _swapper;
# ifdef DOUBLE_WORD_ORDER
/* word-based copy with swapping for non-PowerPC order */
#   define storeFloatAtfrom(intPointerToFloat, floatVarName) \
	*((int *)(intPointerToFloat) + 0) = ((_swapper *)(&floatVarName))->i[1]; \
	*((int *)(intPointerToFloat) + 1) = ((_swapper *)(&floatVarName))->i[0];
#   define fetchFloatAtinto(intPointerToFloat, floatVarName) \
	((_swapper *)(&floatVarName))->i[1] = *((int *)(intPointerToFloat) + 0); \
	((_swapper *)(&floatVarName))->i[0] = *((int *)(intPointerToFloat) + 1);
# else /*!DOUBLE_WORD_ORDER*/
/* word-based copy for machines with alignment restrictions */
#   define storeFloatAtfrom(intPointerToFloat, floatVarName) \
	*((int *)(intPointerToFloat) + 0) = ((_swapper *)(&floatVarName))->i[0]; \
	*((int *)(intPointerToFloat) + 1) = ((_swapper *)(&floatVarName))->i[1];
#   define fetchFloatAtinto(intPointerToFloat, floatVarName) \
	((_swapper *)(&floatVarName))->i[0] = *((int *)(intPointerToFloat) + 0); \
	((_swapper *)(&floatVarName))->i[1] = *((int *)(intPointerToFloat) + 1);
# endif /*!DOUBLE_WORD_ORDER*/
#else /*!(DOUBLE_WORD_ORDER||DOUBLE_WORD_ALIGNMENT)*/
/* for machines that allow doubles to be on any word boundary */
# define storeFloatAtfrom(i, floatVarName) \
	*((double *) (i)) = (floatVarName);
# define fetchFloatAtinto(i, floatVarName) \
	(floatVarName) = *((double *) (i));
#endif

/* platform-dependent macros for handling object memory */
/* Note: The grow/shrink macros assume that the object memory can be extended
   continuously at its prior end. The garbage collector cannot deal with 'holes'
   in the object memory so the support code needs to reserve the virtual maximum
   of pages that can be allocated beforehand. The amount of 'extra' memory should
   describe the amount of memory that can be allocated from the OS (including swap
   space if the flag is set to true) and must not exceed the prior reserved memory.
   (in other words: don't you dare to report more free space then you can actually allocate).
   The default implementation assumes a fixed size memory allocated at startup.
*/
#define sqAllocateMemory(minHeapSize, desiredHeapSize)   malloc(desiredHeapSize)
#define sqGrowMemoryBy(oldLimit, delta) oldLimit
#define sqShrinkMemoryBy(oldLimit, delta) oldLimit
#define sqMemoryExtraBytesLeft(includingSwap) 0

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
   timing.
   The primary one, ioMSecs(), is used to implement Delay
   and Time millisecondClockValue. The resolution of this clock
   determines the resolution of these basic timing functions. For
   doing real-time control of music and MIDI, a clock with resolution
   down to one millisecond is preferred, but a coarser clock (say,
   1/60th second) can be used in a pinch.
   ioLowResMSecs() is used in a few places (mostly Mac code) where a high
   resoltion clock value is not really important  
   Finally, the
   function ioMicroMSecs() is used only to collect timing statistics
   for the garbage collector and other VM facilities. (The function
   name is meant to suggest that the function is based on a clock
   with microsecond accuracy, even though the times it returns are
   in units of milliseconds.) This clock must have enough precision to
   provide accurate timings, and normally isn't called frequently
   enough to slow down the VM. Thus, it can use a more expensive clock
   that ioMSecs().
   By default, all three clock functions are defined
   here as macros based on the standard C library function clock().
   Any of these macros can be overridden in sqPlatformSpecific.h.
*/

int ioMSecs(void);
int ioLowResMSecs(void);
int ioMicroMSecs(void);

#define ioMSecs()		((1000 * clock()) / CLOCKS_PER_SEC)
#define ioLowResMSecs()	((1000 * clock()) / CLOCKS_PER_SEC)
#define ioMicroMSecs()	((1000 * clock()) / CLOCKS_PER_SEC)

/* filename copy/transform macro. An opportunity to transform the filenames for
   platforms with strange needs, anda simple encapsulation for everyone else
*/
#define sqFilenameFromString(dst, src, num) \
if (1) { \
	int i; \
	for (i = 0; i < num; i++) { \
		dst[i] = *((char *) (src + i)); \
	} \
	dst[num] = 0;\
}

/* macro needed to support MacOS-X file opening problems */
#define sqFilenameFromStringOpen(d,s,n) sqFilenameFromString(d,s,n)

/* macro to provide default null behaviour for ftruncate - a non-ansi call used
   in FilePlugin.
   Over ride in sqPlatformSpecific.h for each platform that implements a file
   truncate. 
*/
#define sqFTruncate(filenum, fileoffset) true

/* old browser plug-in support, maintained for a little while */
#if 1
void plugInForceTimeToReturn(void);
int plugInInit(char *imageName);
int plugInNotifyUser(char *msg);
void plugInSetStartTime(void);
int plugInShutdown(void);
int plugInTimeToReturn(void);
#endif
/* macros to support Mac browser plugin needs without ugly
 * code in Interpreter
 */
#define insufficientMemorySpecifiedError() error("Insufficient memory for this image")
#define insufficientMemoryAvailableError() error("Failed to allocate memory for the heap")
#define unableToReadImageError() error("Read failed or premature end of image file")
#define browserPluginReturnIfNeeded()
#define browserPluginInitialiseIfNeeded()


/* typedef and macro to handle primitive dispatch
 * the primitive table is now a table and we jump direct to the function */
typedef  int (*fptr) (void);
#define dispatchFunctionPointerOnin(index, table)  (((int (*) (void)) ((table)[(index)])) ())
#define dispatchFunctionPointer(fnPtr) ((int (*) (void)) fnPtr) ()     

/* this include file may redefine earlier definitions and macros: */
#include "sqPlatformSpecific.h"

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
int signalSemaphoreWithIndex(int semaIndex);
int success(int);

/* display, mouse, keyboard, time i/o */
int ioBeep(void);
int ioExit(void);
int ioForceDisplayUpdate(void);
int ioFormPrint(
	int bitsAddr, int width, int height, int depth,
	double hScale, double vScale, int landscapeFlag);
int ioSetFullScreen(int fullScreen);
int ioRelinquishProcessorForMicroseconds(int microSeconds);
int ioScreenSize(void);
int ioScreenDepth(void);
int ioSeconds(void);
int ioSetCursor(int cursorBitsIndex, int offsetX, int offsetY);
int ioSetCursorWithMask(int cursorBitsIndex, int cursorMaskIndex, int offsetX, int offsetY);
int ioShowDisplay(
	int dispBitsIndex, int width, int height, int depth,
	int affectedL, int affectedR, int affectedT, int affectedB);

int ioHasDisplayDepth(int depth);
int ioSetDisplayMode(int width, int height, int depth, int fullscreenFlag);

/* Power Management */

int ioDisablePowerManager(int disableIfNonZero);

/* User input recording I:
   In general, either set of input function can be supported,
   depending on the platform. This (first) set is state based
   and should be supported even on platforms that make use
   of the newer event driven API to support older images 
   without event support.
*/
int ioGetButtonState(void);
int ioGetKeystroke(void);
int ioMousePoint(void);
int ioPeekKeystroke(void);
/* Note: In an event driven architecture, ioProcessEvents is obsolete.
   It can be implemented as a no-op since the image will check for
   events in regular intervals. */
int ioProcessEvents(void);


/* User input recording II:
   The following functions and definition can be used on
   platform supporting events directly.
*/
/* types of events */
#define EventTypeNone 0
#define EventTypeMouse 1
#define EventTypeKeyboard 2
#define EventTypeDragDropFiles 3
#define EventTypeMenu 4
#define EventTypeWindow 5

/* keypress state for keyboard events */
#define EventKeyChar 0
#define EventKeyDown 1
#define EventKeyUp 2

/* button definitions */
#define RedButtonBit 4
#define YellowButtonBit 2
#define BlueButtonBit 1

/* modifier definitions */
#define ShiftKeyBit 1
#define CtrlKeyBit 2
#define OptionKeyBit 4
#define CommandKeyBit 8

/* generic input event definition */
typedef struct sqInputEvent {
	int type; /* type of event; either one of EventTypeXXX */
	unsigned int timeStamp; /* time stamp */
     /* the interpretation of the following fields depend on the type of the event */
	int unused1;
	int unused2;
	int unused3;
	int unused4;
	int unused5;
	int windowIndex; /* window index is the SmallInt key used in image to
					  * refer to a host window structure */
} sqInputEvent;

/* mouse input event definition */
typedef struct sqMouseEvent {
	int type; /* EventTypeMouse */
	unsigned int timeStamp; /* time stamp */
	int x; /* mouse position x */
	int y; /* mouse position y */
	int buttons; /* combination of xxxButtonBit */
	int modifiers; /* combination of xxxKeyBit */
	int reserved1; /* reserved for future use */
	int windowIndex;
} sqMouseEvent;

/* keyboard input event definition */
typedef struct sqKeyboardEvent {
	int type; /* EventTypeKeyboard */
	unsigned int timeStamp; /* time stamp */
	int charCode; /* character code in Mac Roman encoding */
	int pressCode; /* press code; any of EventKeyXXX */
	int modifiers; /* combination of xxxKeyBit */
	int reserved1; /* reserved for future use */
	int reserved2; /* reserved for future use */
	int windowIndex;
} sqKeyboardEvent;

/* drop files event definition:
   DragEnter - drag operation from OS entered Squeak window
   DragMove  - drag operation from OS moved within Squeak window
   DragLeave - drag operation from OS left Squeak window
   DragDrop  - drag operation dropped contents onto Squeak.
*/
#define DragEnter 1
#define DragMove  2
#define DragLeave 3
#define DragDrop  4
typedef struct sqDragDropFilesEvent {
	int type; /* EventTypeDropFiles */
	unsigned int timeStamp; /* time stamp */
	int dragType; /* one of the DragXXX constants */
	int x; /* mouse position x */
	int y; /* mouse position y */
	int modifiers; /* combination of xxxKeyBit */
	int numFiles; /* number of files in transaction */
	int windowIndex;
} sqDragDropFilesEvent;

/* menu  event definition */
typedef struct sqMenuEvent {
    int type; /* type of event; EventTypeMenu */
    unsigned int timeStamp; /* time stamp */
     /* the interpretation of the following fields depend on the type  of the event */
    int menu;        /*Platform dependent to indicate which menu was picked */
    int menuItem;   /*Given a menu has 1 to N items this should map to the  menu item number */
    int reserved1; /* reserved for future use */
    int reserved2; /* reserved for future use */
    int reserved3; /* reserved for future use */
    int windowIndex; /* window index is the SmallInt key used in image to
                      * refer to a host window structure */
} sqMenuEvent;

typedef struct sqWindowEvent {
    int type; /* type of event;  EventTypeWindow */
    unsigned int timeStamp; /* time stamp */
     /* the interpretation of the following fields depend on the type  of the event */
    int action;        /*Platform dependent to indicate which menu was picked */
    int value1; /* used for rectangle edges */
    int value2; /* used for rectangle edges */
    int value3; /* used for rectangle edges */
    int value4; /* used for rectangle edges */
    int windowIndex; /* window index is the SmallInt key used in image to
                      * refer to a host window structure */
} sqWindowEvent;
#define WindowEventMetricChange 1 /* size or position of window changed - value1-4 are left/top/right/bottom values */
#define WindowEventClose 2 /* window close icon pressed */
#define WindowEventIconise 3 /* window iconised  or hidden etc */
#define WindowEventActivated 4 /* window made active - some platforms only - do not rely upon this */
#define WindowEventPaint 5 /* window area (in value1-4) needs updating. Some platforms do not need to send this, do not rely on it in image */
#define WindowEventStinks 6 /* this window stinks. */


/* set an asynchronous input semaphore index for events */
int ioSetInputSemaphore(int semaIndex);
/* retrieve the next input event from the OS */
int ioGetNextEvent(sqInputEvent *evt);

/* image file and VM path names */
extern char imageName[];
char *getImageName();
int imageNameGetLength(int sqImageNameIndex, int length);
int imageNamePutLength(int sqImageNameIndex, int length);
int imageNameSize(void);
int vmPathSize(void);
int vmPathGetLength(int sqVMPathIndex, int length);

/* image security traps */
int ioCanRenameImage(void);
int ioCanWriteImage(void);
int ioDisableImageWrite(void);
#ifdef DISABLE_SECURITY
# define ioCanRenameImage() 1
# define ioCanWriteImage() 1
# define ioDisableImageWrite() 1
#endif

/* save/restore */
/* Read the image from the given file starting at the given image offset */
int readImageFromFileHeapSizeStartingAt(sqImageFile f, int desiredHeapSize, squeakFileOffsetType imageOffset);
/* NOTE: The following is obsolete - it is only provided for compatibility */
#define readImageFromFileHeapSize(f, s) readImageFromFileHeapSizeStartingAt(f,s,0)

/* clipboard (cut/copy/paste) */
int clipboardSize(void);
int clipboardReadIntoAt(int count, int byteArrayIndex, int startIndex);
int clipboardWriteFromAt(int count, int byteArrayIndex, int startIndex);



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

/* profiling */
int clearProfile(void);
int dumpProfile(void);
int startProfiling(void);
int stopProfiling(void);

/* system attributes */
int attributeSize(int id);
int getAttributeIntoLength(int id, int byteArrayIndex, int length);

/*** pluggable primitive support ***/
/* NOTE: The following functions are those implemented by sqNamedPrims.c */
int ioLoadExternalFunctionOfLengthFromModuleOfLength(
  int functionNameIndex, int functionNameLength,
  int moduleNameIndex, int moduleNameLength);
int ioUnloadModuleOfLength(int moduleNameIndex, int moduleNameLength);
int ioLoadFunctionFrom(char *functionName, char *pluginName);
int ioShutdownAllModules(void);
int ioUnloadModule(char *);
int ioUnloadModuleOfLength(int moduleNameIndex, int moduleNameLength);
char *ioListBuiltinModule(int moduleIndex);
char *ioListLoadedModule(int moduleIndex);
/* The next two are FFI entries! (implemented in sqNamedPrims.c as well) */
int ioLoadModuleOfLength(int moduleNameIndex, int moduleNameLength);
int ioLoadSymbolOfLengthFromModule(int functionNameIndex, int functionNameLength, int moduleHandle);

/* The next three functions must be implemented by sqXYZExternalPrims.c */
/* ioLoadModule:
	Load a module from disk.
	WARNING: this always loads a *new* module. Don't even attempt to find a loaded one.
	WARNING: never primitiveFail() within, just return 0
*/
int ioLoadModule(char *pluginName);

/* ioFindExternalFunctionIn:
	Find the function with the given name in the moduleHandle.
	WARNING: never primitiveFail() within, just return 0.
*/
int ioFindExternalFunctionIn(char *lookupName, int moduleHandle);

/* ioFreeModule:
	Free the module with the associated handle.
	WARNING: never primitiveFail() within, just return 0.
*/
int ioFreeModule(int moduleHandle);

/* The Squeak version this interpreter was generated from */
extern const char *interpreterVersion;
