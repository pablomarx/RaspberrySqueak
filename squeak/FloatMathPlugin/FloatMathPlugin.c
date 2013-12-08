/* Automatically generated from Squeak on an Array(10 April 2008 1:42:50 pm)
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
#include "FloatMathPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveArcCos(void);
EXPORT(sqInt) primitiveArcCosH(void);
EXPORT(sqInt) primitiveArcSin(void);
EXPORT(sqInt) primitiveArcSinH(void);
EXPORT(sqInt) primitiveArcTan(void);
EXPORT(sqInt) primitiveArcTan2(void);
EXPORT(sqInt) primitiveArcTanH(void);
EXPORT(sqInt) primitiveCos(void);
EXPORT(sqInt) primitiveCosH(void);
EXPORT(sqInt) primitiveExp(void);
EXPORT(sqInt) primitiveFMod(void);
EXPORT(sqInt) primitiveFractionalPart(void);
EXPORT(sqInt) primitiveHypot(void);
EXPORT(sqInt) primitiveLog10(void);
EXPORT(sqInt) primitiveLogN(void);
EXPORT(sqInt) primitiveRaisedToPower(void);
EXPORT(sqInt) primitiveSin(void);
EXPORT(sqInt) primitiveSinH(void);
EXPORT(sqInt) primitiveSqrt(void);
EXPORT(sqInt) primitiveTan(void);
EXPORT(sqInt) primitiveTanH(void);
EXPORT(sqInt) primitiveTimesTwoPower(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"FloatMathPlugin 10 April 2008 (i)"
#else
	"FloatMathPlugin 10 April 2008 (e)"
#endif
;



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

static sqInt halt(void) {
	;
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Computes acos(receiver) */

EXPORT(sqInt) primitiveArcCos(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_acos(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes acosh(receiver) */

EXPORT(sqInt) primitiveArcCosH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_acosh(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes asin(receiver) */

EXPORT(sqInt) primitiveArcSin(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_asin(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes asinh(receiver) */

EXPORT(sqInt) primitiveArcSinH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_asinh(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes atan(receiver) */

EXPORT(sqInt) primitiveArcTan(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_atan(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes atan2(receiver, arg) */

EXPORT(sqInt) primitiveArcTan2(void) {
    double rcvr;
    double result;
    double arg;

	arg = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_atan2(rcvr, arg);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes atanh(receiver) */

EXPORT(sqInt) primitiveArcTanH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_atanh(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes cos(receiver) */

EXPORT(sqInt) primitiveCos(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_cos(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes cosh(receiver) */

EXPORT(sqInt) primitiveCosH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_cosh(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes E raised to the receiver power. */

EXPORT(sqInt) primitiveExp(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_exp(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes receiver \\ arg */

EXPORT(sqInt) primitiveFMod(void) {
    double rcvr;
    double result;
    double arg;

	arg = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_fmod(rcvr, arg);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes receiver \\ 1.0 */

EXPORT(sqInt) primitiveFractionalPart(void) {
    double rcvr;
    double result;
    double trunc;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_modf(rcvr, &trunc);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	hypot(x,y) returns sqrt(x^2+y^2) with error less  than 1 ulps */

EXPORT(sqInt) primitiveHypot(void) {
    double rcvr;
    double result;
    double arg;

	arg = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_hypot(rcvr, arg);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes log10(receiver) */

EXPORT(sqInt) primitiveLog10(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return interpreterProxy->primitiveFail();
	}
	result = __ieee754_log10(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes log(receiver) */

EXPORT(sqInt) primitiveLogN(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return interpreterProxy->primitiveFail();
	}
	result = __ieee754_log(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes receiver**arg */

EXPORT(sqInt) primitiveRaisedToPower(void) {
    double rcvr;
    double result;
    double arg;

	arg = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_pow(rcvr, arg);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes sin(receiver) */

EXPORT(sqInt) primitiveSin(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_sin(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes sinh(receiver) */

EXPORT(sqInt) primitiveSinH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_sinh(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes sqrt(receiver) */

EXPORT(sqInt) primitiveSqrt(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return interpreterProxy->primitiveFail();
	}
	result = __ieee754_sqrt(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes tan(receiver) */

EXPORT(sqInt) primitiveTan(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_tan(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes tanh(receiver) */

EXPORT(sqInt) primitiveTanH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_tanh(rcvr);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
}


/*	Computes E raised to the receiver power. */

EXPORT(sqInt) primitiveTimesTwoPower(void) {
    double rcvr;
    double result;
    sqInt arg;

	arg = interpreterProxy->stackIntegerValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_ldexp(rcvr, arg);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
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


#ifdef SQUEAK_BUILTIN_PLUGIN


void* FloatMathPlugin_exports[][3] = {
	{"FloatMathPlugin", "primitiveFMod", (void*)primitiveFMod},
	{"FloatMathPlugin", "primitiveArcSinH", (void*)primitiveArcSinH},
	{"FloatMathPlugin", "primitiveHypot", (void*)primitiveHypot},
	{"FloatMathPlugin", "primitiveLog10", (void*)primitiveLog10},
	{"FloatMathPlugin", "primitiveArcTan", (void*)primitiveArcTan},
	{"FloatMathPlugin", "setInterpreter", (void*)setInterpreter},
	{"FloatMathPlugin", "primitiveTan", (void*)primitiveTan},
	{"FloatMathPlugin", "primitiveArcCos", (void*)primitiveArcCos},
	{"FloatMathPlugin", "primitiveCos", (void*)primitiveCos},
	{"FloatMathPlugin", "getModuleName", (void*)getModuleName},
	{"FloatMathPlugin", "primitiveSin", (void*)primitiveSin},
	{"FloatMathPlugin", "primitiveTanH", (void*)primitiveTanH},
	{"FloatMathPlugin", "primitiveTimesTwoPower", (void*)primitiveTimesTwoPower},
	{"FloatMathPlugin", "primitiveExp", (void*)primitiveExp},
	{"FloatMathPlugin", "primitiveArcTanH", (void*)primitiveArcTanH},
	{"FloatMathPlugin", "primitiveCosH", (void*)primitiveCosH},
	{"FloatMathPlugin", "primitiveFractionalPart", (void*)primitiveFractionalPart},
	{"FloatMathPlugin", "primitiveArcCosH", (void*)primitiveArcCosH},
	{"FloatMathPlugin", "primitiveArcTan2", (void*)primitiveArcTan2},
	{"FloatMathPlugin", "primitiveSqrt", (void*)primitiveSqrt},
	{"FloatMathPlugin", "primitiveLogN", (void*)primitiveLogN},
	{"FloatMathPlugin", "primitiveRaisedToPower", (void*)primitiveRaisedToPower},
	{"FloatMathPlugin", "primitiveArcSin", (void*)primitiveArcSin},
	{"FloatMathPlugin", "primitiveSinH", (void*)primitiveSinH},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */


