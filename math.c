#include "math.h"

/* derived from /netlib/fdlibm */

/* @(#)s_atan.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* atan(x)
 * Method
 *   1. Reduce x to positive by atan(x) = -atan(-x).
 *   2. According to the integer k=4t+0.25 chopped, t=x, the argument
 *      is further reduced to one of the following intervals and the
 *      arctangent of t is evaluated by the corresponding formula:
 *
 *      [0,7/16]      atan(x) = t-t^3*(a1+t^2*(a2+...(a10+t^2*a11)...)
 *      [7/16,11/16]  atan(x) = atan(1/2) + atan( (t-0.5)/(1+t/2) )
 *      [11/16.19/16] atan(x) = atan( 1 ) + atan( (t-1)/(1+t) )
 *      [19/16,39/16] atan(x) = atan(3/2) + atan( (t-1.5)/(1+1.5t) )
 *      [39/16,INF]   atan(x) = atan(INF) + atan( -1/t )
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following
 * constants. The decimal values may be used, provided that the
 * compiler will convert from decimal to binary accurately enough
 * to produce the hexadecimal values shown.
 */

#define	PIO2	1.570796326794896619231e0
#define	PI	(PIO2+PIO2)

#ifdef __LITTLE_ENDIAN
#define __HI(x) *(1+(int*)&x)
#define __LO(x) *(int*)&x
#define __HIp(x) *(1+(int*)x)
#define __LOp(x) *(int*)x
#else
#define __HI(x) *(int*)&x
#define __LO(x) *(1+(int*)&x)
#define __HIp(x) *(int*)x
#define __LOp(x) *(1+(int*)x)
#endif


static const double atanhi[] = {
  4.63647609000806093515e-01, /* atan(0.5)hi 0x3FDDAC67, 0x0561BB4F */
  7.85398163397448278999e-01, /* atan(1.0)hi 0x3FE921FB, 0x54442D18 */
  9.82793723247329054082e-01, /* atan(1.5)hi 0x3FEF730B, 0xD281F69B */
  1.57079632679489655800e+00, /* atan(inf)hi 0x3FF921FB, 0x54442D18 */
};

static const double atanlo[] = {
  2.26987774529616870924e-17, /* atan(0.5)lo 0x3C7A2B7F, 0x222F65E2 */
  3.06161699786838301793e-17, /* atan(1.0)lo 0x3C81A626, 0x33145C07 */
  1.39033110312309984516e-17, /* atan(1.5)lo 0x3C700788, 0x7AF0CBBD */
  6.12323399573676603587e-17, /* atan(inf)lo 0x3C91A626, 0x33145C07 */
};

static const double aT[] = {
  3.33333333333329318027e-01, /* 0x3FD55555, 0x5555550D */
 -1.99999999998764832476e-01, /* 0xBFC99999, 0x9998EBC4 */
  1.42857142725034663711e-01, /* 0x3FC24924, 0x920083FF */
 -1.11111104054623557880e-01, /* 0xBFBC71C6, 0xFE231671 */
  9.09088713343650656196e-02, /* 0x3FB745CD, 0xC54C206E */
 -7.69187620504482999495e-02, /* 0xBFB3B0F2, 0xAF749A6D */
  6.66107313738753120669e-02, /* 0x3FB10D66, 0xA0D03D51 */
 -5.83357013379057348645e-02, /* 0xBFADDE2D, 0x52DEFD9A */
  4.97687799461593236017e-02, /* 0x3FA97B4B, 0x24760DEB */
 -3.65315727442169155270e-02, /* 0xBFA2B444, 0x2C6A6C2F */
  1.62858201153657823623e-02, /* 0x3F90AD3A, 0xE322DA11 */
};

	static const double
one   = 1.0,
Huge   = 1.0e300;

	double atan(double x)
{
	double w,s1,s2,z;
	int ix,hx,id;

	hx = __HI(x);
	ix = hx&0x7fffffff;
	if(ix>=0x44100000) {	/* if |x| >= 2^66 */
	    if(ix>0x7ff00000||
		(ix==0x7ff00000&&(__LO(x)!=0)))
		return x+x;		/* NaN */
	    if(hx>0) return  atanhi[3]+atanlo[3];
	    else     return -atanhi[3]-atanlo[3];
	} if (ix < 0x3fdc0000) {	/* |x| < 0.4375 */
	    if (ix < 0x3e200000) {	/* |x| < 2^-29 */
		if(Huge+x>one) return x;	/* raise inexact */
	    }
	    id = -1;
	} else {
	x = fabs(x);
	if (ix < 0x3ff30000) {		/* |x| < 1.1875 */
	    if (ix < 0x3fe60000) {	/* 7/16 <=|x|<11/16 */
		id = 0; x = (2.0*x-one)/(2.0+x);
	    } else {			/* 11/16<=|x|< 19/16 */
		id = 1; x  = (x-one)/(x+one);
	    }
	} else {
	    if (ix < 0x40038000) {	/* |x| < 2.4375 */
		id = 2; x  = (x-1.5)/(one+1.5*x);
	    } else {			/* 2.4375 <= |x| < 2^66 */
		id = 3; x  = -1.0/x;
	    }
	}}
    /* end of argument reduction */
	z = x*x;
	w = z*z;
    /* break sum from i=0 to 10 aT[i]z**(i+1) into odd and even poly */
	s1 = z*(aT[0]+w*(aT[2]+w*(aT[4]+w*(aT[6]+w*(aT[8]+w*aT[10])))));
	s2 = w*(aT[1]+w*(aT[3]+w*(aT[5]+w*(aT[7]+w*aT[9]))));
	if (id<0) return x - x*(s1+s2);
	else {
	    z = atanhi[id] - ((x*(s1+s2) - atanlo[id]) - x);
	    return (hx<0)? -z:z;
	}
}

#define	p0  .2080384346694663001443843411e7
#define	p1  .3028697169744036299076048876e5
#define	p2  .6061485330061080841615584556e2
#define	q0  .6002720360238832528230907598e7
#define	q1  .3277251518082914423057964422e6
#define	q2  .1749287689093076403844945335e4
#define	log2e  1.4426950408889634073599247
#define	sqrt2  1.4142135623730950488016887
#define	maxf  10000

double
exp(double arg)
{
	double fract, temp1, temp2, xsq;
	int ent;

	if(arg == 0)
		return 1;
	if(arg < -maxf)
		return 0;
	if(arg > maxf)
		return Inf(1);
	arg *= log2e;
	ent = floor(arg);
	fract = (arg-ent) - 0.5;
	xsq = fract*fract;
	temp1 = ((p2*xsq+p1)*xsq+p0)*fract;
	temp2 = ((xsq+q2)*xsq+q1)*xsq + q0;
	return ldexp(sqrt2*(temp2+temp1)/(temp2-temp1), ent);
}

#define	MASK	0x7ffL
#define	SHIFT	20
#define	BIAS	1022L

typedef	union
{
	double	d;
	struct
	{
		long	ls;
		long	ms;
	};
} Cheat;

double
frexp(double d, int *ep)
{
	Cheat x;

	if(d == 0) {
		*ep = 0;
		return 0;
	}
	x.d = d;
	*ep = ((x.ms >> SHIFT) & MASK) - BIAS;
	x.ms &= ~(MASK << SHIFT);
	x.ms |= BIAS << SHIFT;
	return x.d;
}

double
ldexp(double d, int e)
{
	Cheat x;

	if(d == 0)
		return 0;
	x.d = d;
	e += (x.ms >> SHIFT) & MASK;
	if(e <= 0)
		return 0;	/* underflow */
	if(e >= MASK){		/* overflow */
		if(d < 0)
			return Inf(-1);
		return Inf(1);
	}
	x.ms &= ~(MASK << SHIFT);
	x.ms |= (long)e << SHIFT;
	return x.d;
}

double
modf(double d, double *ip)
{
	Cheat x;
	int e;

	if(d < 1) {
		if(d < 0) {
			x.d = modf(-d, ip);
			*ip = -*ip;
			return -x.d;
		}
		*ip = 0;
		return d;
	}
	x.d = d;
	e = ((x.ms >> SHIFT) & MASK) - BIAS;
	if(e <= SHIFT+1) {
		x.ms &= ~(0x1fffffL >> e);
		x.ls = 0;
	} else
	if(e <= SHIFT+33)
		x.ls &= ~(0x7fffffffL >> (e-SHIFT-2));
	*ip = x.d;
	return d - x.d;
}

#undef	p0
#undef	p1
#undef	p2
#undef	q0
#undef	q1
#undef	q2

#define	log2    0.693147180559945309e0
#define	ln10o1  .4342944819032518276511
#define	sqrto2  0.707106781186547524e0
#define	p0      -.240139179559210510e2
#define	p1      0.309572928215376501e2
#define	p2      -.963769093377840513e1
#define	p3      0.421087371217979714e0
#define	q0      -.120069589779605255e2
#define	q1      0.194809660700889731e2
#define	q2      -.891110902798312337e1

double
log(double arg)
{
	double x, z, zsq, temp;
	int exp;

	if(arg <= 0)
		return NaN();
	x = frexp(arg, &exp);
	while(x < 0.5) {
		x *= 2;
		exp--;
	}
	if(x < sqrto2) {
		x *= 2;
		exp--;
	}

	z = (x-1) / (x+1);
	zsq = z*z;

	temp = ((p3*zsq + p2)*zsq + p1)*zsq + p0;
	temp = temp/(((zsq + q2)*zsq + q1)*zsq + q0);
	temp = temp*z + exp*log2;
	return temp;
}

double
log10(double arg)
{

	if(arg <= 0)
		return NaN();
	return log(arg) * ln10o1;
}

#undef	p0
#undef	p1
#undef	p2
#undef	p3
#undef	q0
#undef	q1
#undef	q2

#define p0      .1357884097877375669092680e8
#define p1     -.4942908100902844161158627e7
#define p2      .4401030535375266501944918e6
#define p3     -.1384727249982452873054457e5
#define p4      .1459688406665768722226959e3
#define q0      .8644558652922534429915149e7
#define q1      .4081792252343299749395779e6
#define q2      .9463096101538208180571257e4
#define q3      .1326534908786136358911494e3

static
double
sinus(double arg, int quad)
{
	double e, f, ysq, x, y, temp1, temp2;
	int k;

	x = arg;
	if(x < 0) {
		x = -x;
		quad += 2;
	}
	x *= 1/PIO2;	/* underflow? */
	if(x > 32764) {
		y = modf(x, &e);
		e += quad;
		modf(0.25*e, &f);
		quad = e - 4*f;
	} else {
		k = x;
		y = x - k;
		quad += k;
		quad &= 3;
	}
	if(quad & 1)
		y = 1-y;
	if(quad > 1)
		y = -y;

	ysq = y*y;
	temp1 = ((((p4*ysq+p3)*ysq+p2)*ysq+p1)*ysq+p0)*y;
	temp2 = ((((ysq+q3)*ysq+q2)*ysq+q1)*ysq+q0);
	return temp1/temp2;
}

double
cos(double arg)
{
	if(arg < 0)
		arg = -arg;
	return sinus(arg, 1);
}

double
sin(double arg)
{
	return sinus(arg, 0);
}

double
sqrt(double arg)
{
	double x, temp;
	int exp, i;

	if(arg <= 0) {
		if(arg < 0)
			return NaN();
		return 0;
	}
	if(isInf(arg, 1))
		return arg;
	x = frexp(arg, &exp);
	while(x < 0.5) {
		x *= 2;
		exp--;
	}
	/*
	 * NOTE
	 * this wont work on 1's comp
	 */
	if(exp & 1) {
		x *= 2;
		exp--;
	}
	temp = 0.5 * (1.0+x);

	while(exp > 60) {
		temp *= (1L<<30);
		exp -= 60;
	}
	while(exp < -60) {
		temp /= (1L<<30);
		exp += 60;
	}
	if(exp >= 0)
		temp *= 1L << (exp/2);
	else
		temp /= 1L << (-exp/2);
	for(i=0; i<=4; i++)
		temp = 0.5*(temp + arg/temp);
	return temp;
}

double
floor(double d)
{
	double fract;

	if(d < 0) {
		fract = modf(-d, &d);
		if(fract != 0.0)
			d += 1;
		d = -d;
	} else
		modf(d, &d);
	return d;
}

double
ceil(double d)
{
	return -floor(-d);
}

double fabs(double x)
{
	__HI(x) &= 0x7fffffff;
        return x;
}

#define	NANEXP	(2047<<20)
#define	NANMASK	(2047<<20)
#define	NANSIGN	(1<<31)

double
NaN(void)
{
	union
	{
		double	d;
		long	x[2];
	} a;

	a.x[1] = NANEXP;
	a.x[0] = 1;
	return a.d;
}

int
isNaN(double d)
{
	union
	{
		double	d;
		long	x[2];
	} a;

	a.d = d;
	if((a.x[1] & NANMASK) != NANEXP)
		return 0;
	return !isInf(d, 0);
}

double
Inf(int sign)
{
	union
	{
		double	d;
		long	x[2];
	} a;

	a.x[1] = NANEXP;
	a.x[0] = 0;
	if(sign < 0)
		a.x[1] |= NANSIGN;
	return a.d;
}

int
isInf(double d, int sign)
{
	union
	{
		double	d;
		long	x[2];
	} a;

	a.d = d;
	if(a.x[0] != 0)
		return 0;
	if(a.x[1] == NANEXP)
		return sign >= 0;
	if(a.x[1] == (NANEXP|NANSIGN))
		return sign <= 0;
	return 0;
}

int
abs(int a)
{
	if(a < 0)
		return -a;
	return a;
}
