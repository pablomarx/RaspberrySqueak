/* Automatically generated from Squeak on #(4 March 2003 4:22:52 am) */

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

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"IntegerPokerPlugin 4 March 2003 (i)"
#else
	"IntegerPokerPlugin 4 March 2003 (e)"
#endif
;

/*** Function Prototypes ***/
static int asCharacter(int anInteger);
static int asInteger(int aChar);
static int cutOffForPositives(void);
#pragma export on
EXPORT(int) getInteger(void);
EXPORT(const char*) getModuleName(void);
#pragma export off
static int halt(void);
static int msg(char *s);
static int negated(int anInteger);
#pragma export on
EXPORT(int) putInteger(void);
EXPORT(int) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off

static int asCharacter(int anInteger) {
	return anInteger;
}

static int asInteger(int aChar) {
	return aChar;
}


/*	return the largest positive integer that we can encode */

static int cutOffForPositives(void) {
	return 1 << 30;
}

EXPORT(int) getInteger(void) {
    int integer;
    int stringOop;
    unsigned char *stringData;
    int locationOop;
    int location;

	stringOop = interpreterProxy->stackValue(1);
	if (!(interpreterProxy->isBytes(stringOop))) {
		interpreterProxy->success(0);
		return null;
	}

	/* decode the location */

	stringData = interpreterProxy->arrayValueOf(stringOop);
	locationOop = interpreterProxy->stackValue(0);
	if (!(interpreterProxy->isIntegerValue(locationOop))) {
		interpreterProxy->success(0);
		return null;
	}
	location = (locationOop >> 1);
	location -= 1;
	if (location < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if ((location + 4) > (interpreterProxy->stSizeOf(stringOop))) {
		interpreterProxy->success(0);
		return null;
	}
	integer = (((int) (stringData[location]) )) << 24;
	integer = ((((int) (stringData[location + 1]) )) << 16) + integer;
	integer = ((((int) (stringData[location + 2]) )) << 8) + integer;

	/* convert it to a negative number, if it's too large */

	integer = (((int) (stringData[location + 3]) )) + integer;
	if (integer > (1 << 30)) {
		integer = (1 << 30) - integer;
	}
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(integer);
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static int halt(void) {
	;
}

static int msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

static int negated(int anInteger) {
	return -1 * anInteger;
}

EXPORT(int) putInteger(void) {
    int integer;
    int stringOop;
    unsigned char *stringData;
    int locationOop;
    int location;
    int integerOop;

	stringOop = interpreterProxy->stackValue(2);
	if (!(interpreterProxy->isBytes(stringOop))) {
		interpreterProxy->success(0);
		return null;
	}

	/* decode the integer to be stored */

	stringData = interpreterProxy->arrayValueOf(stringOop);
	integerOop = interpreterProxy->stackValue(1);
	if (!(interpreterProxy->isIntegerValue(integerOop))) {
		interpreterProxy->success(0);
		return null;
	}

	/* decode the location */

	integer = (integerOop >> 1);
	locationOop = interpreterProxy->stackValue(0);
	if (!(interpreterProxy->isIntegerValue(locationOop))) {
		interpreterProxy->success(0);
		return null;
	}
	location = (locationOop >> 1);
	location -= 1;
	if (location < 0) {
		interpreterProxy->success(0);
		return null;
	}
	if ((location + 4) > (interpreterProxy->stSizeOf(stringOop))) {
		interpreterProxy->success(0);
		return null;
	}
	if (integer > (1 << 30)) {
		interpreterProxy->success(0);
		return null;
	}
	if (integer < (negated(1 << 30))) {
		interpreterProxy->success(0);
		return null;
	}
	if (integer < 0) {
		integer = (1 << 30) - integer;
	}
	stringData[location + 3] = (asCharacter(integer % 256));
	stringData[location + 2] = (asCharacter((((unsigned) integer) >> 8) % 256));
	stringData[location + 1] = (asCharacter((((unsigned) integer) >> 16) % 256));
	stringData[location + 0] = (asCharacter((((unsigned) integer) >> 24) % 256));
	interpreterProxy->pop(2);
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


#ifdef SQUEAK_BUILTIN_PLUGIN


void* IntegerPokerPlugin_exports[][3] = {
	{"IntegerPokerPlugin", "getInteger", (void*)getInteger},
	{"IntegerPokerPlugin", "getModuleName", (void*)getModuleName},
	{"IntegerPokerPlugin", "putInteger", (void*)putInteger},
	{"IntegerPokerPlugin", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

