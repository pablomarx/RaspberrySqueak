/* Automatically generated from Squeak on (18 October 1999 5:07:59 pm ) */

#include "sq.h"


/* Memory Access Macros */
#define byteAt(i) (*((unsigned char *) (i)))
#define byteAtput(i, val) (*((unsigned char *) (i)) = val)
#define longAt(i) (*((int *) (i)))
#define longAtput(i, val) (*((int *) (i)) = val)

/*** Imported Functions/Variables ***/
extern int stackValue(int);
extern int successFlag;

/* allows accessing Strings in both C and Smalltalk */
#define asciiValue(c) c

/*** Variables ***/

/*** Function Prototypes ***/
int encodeBytesOfinat(int anInt, unsigned char *ba, int i);
int encodeIntinat(int anInt, unsigned char *ba, int i);
int primBitmapcompresstoByteArray(void);
int primBitmapdecompressfromByteArrayat(void);
int primSampledSoundconvert8bitSignedFromto16Bit(void);
int primStringcomparewithcollated(void);
int primStringfindFirstInStringinSetstartingAt(void);
int primStringfindSubstringinstartingAtmatchTable(void);
int primStringindexOfAsciiinStringstartingAt(void);
int primStringtranslatefromtotable(void);

int encodeBytesOfinat(int anInt, unsigned char *ba, int i) {
    int j;

	for (j = 0; j <= 3; j += 1) {
		ba[i + j] = ((((unsigned) anInt) >> ((3 - j) * 8)) & 255);
	}
	return i + 4;
}

int encodeIntinat(int anInt, unsigned char *ba, int i) {
	if (anInt <= 223) {
		ba[i] = anInt;
		return i + 1;
	}
	if (anInt <= 7935) {
		ba[i] = ((((int) anInt >> 8)) + 224);
		ba[i + 1] = (anInt % 256);
		return i + 2;
	}
	ba[i] = 255;
	return encodeBytesOfinat(anInt, ba, i + 1);
}

int primBitmapcompresstoByteArray(void) {
    int rcvr;
    int *bm;
    unsigned char *ba;
    int k;
    int j;
    int i;
    int lowByte;
    int eqBytes;
    int size;
    int word;
    int m;

	rcvr = stackValue(2);
	bm = arrayValueOf(stackValue(1));
	bm -= 1;
	ba = arrayValueOf(stackValue(0));
	ba -= 1;
	if (!(successFlag)) {
		return null;
	}
	size = sizeOfSTArrayFromCPrimitive(bm + 1);
	i = encodeIntinat(size, ba, 1);
	k = 1;
	while (k <= size) {
		word = bm[k];
		lowByte = word & 255;
		eqBytes = (((((unsigned) word) >> 8) & 255) == lowByte) && ((((((unsigned) word) >> 16) & 255) == lowByte) && (((((unsigned) word) >> 24) & 255) == lowByte));
		j = k;
		while ((j < size) && (word == (bm[j + 1]))) {
			j += 1;
		}
		if (j > k) {
			if (eqBytes) {
				i = encodeIntinat((((j - k) + 1) * 4) + 1, ba, i);
				ba[i] = lowByte;
				i += 1;
			} else {
				i = encodeIntinat((((j - k) + 1) * 4) + 2, ba, i);
				i = encodeBytesOfinat(word, ba, i);
			}
			k = j + 1;
		} else {
			if (eqBytes) {
				i = encodeIntinat((1 * 4) + 1, ba, i);
				ba[i] = lowByte;
				i += 1;
				k += 1;
			} else {
				while ((j < size) && ((bm[j]) != (bm[j + 1]))) {
					j += 1;
				}
				if (j == size) {
					j += 1;
				}
				i = encodeIntinat(((j - k) * 4) + 3, ba, i);
				for (m = k; m <= (j - 1); m += 1) {
					i = encodeBytesOfinat(bm[m], ba, i);
				}
				k = j;
			}
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
	pushInteger(i - 1);
	return null;
}

int primBitmapdecompressfromByteArrayat(void) {
    int rcvr;
    int *bm;
    unsigned char *ba;
    int index;
    int k;
    int j;
    int i;
    int anInt;
    int pastEnd;
    int data;
    int end;
    int n;
    int code;
    int m;

	rcvr = stackValue(3);
	bm = arrayValueOf(stackValue(2));
	bm -= 1;
	ba = arrayValueOf(stackValue(1));
	ba -= 1;
	index = checkedIntegerValueOf(stackValue(0));
	if (!(successFlag)) {
		return null;
	}
	i = index;
	end = sizeOfSTArrayFromCPrimitive(ba + 1);
	k = 1;
	pastEnd = (sizeOfSTArrayFromCPrimitive(bm + 1)) + 1;
	while (i <= end) {
		anInt = ba[i];
		i += 1;
		if (!(anInt <= 223)) {
			if (anInt <= 254) {
				anInt = ((anInt - 224) * 256) + (ba[i]);
				i += 1;
			} else {
				anInt = 0;
				for (j = 1; j <= 4; j += 1) {
					anInt = (((unsigned) anInt << 8)) + (ba[i]);
					i += 1;
				}
			}
		}
		n = ((unsigned) anInt) >> 2;
		if ((k + n) > pastEnd) {
			primitiveFail();
			return null;
		}
		code = anInt & 3;
		if (code == 0) {
			null;
		}
		if (code == 1) {
			data = ba[i];
			i += 1;
			data = data | (((unsigned) data << 8));
			data = data | (((unsigned) data << 16));
			for (j = 1; j <= n; j += 1) {
				bm[k] = data;
				k += 1;
			}
		}
		if (code == 2) {
			data = 0;
			for (j = 1; j <= 4; j += 1) {
				data = (((unsigned) data << 8)) | (ba[i]);
				i += 1;
			}
			for (j = 1; j <= n; j += 1) {
				bm[k] = data;
				k += 1;
			}
		}
		if (code == 3) {
			for (m = 1; m <= n; m += 1) {
				data = 0;
				for (j = 1; j <= 4; j += 1) {
					data = (((unsigned) data << 8)) | (ba[i]);
					i += 1;
				}
				bm[k] = data;
				k += 1;
			}
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
}

int primSampledSoundconvert8bitSignedFromto16Bit(void) {
    int rcvr;
    unsigned char *aByteArray;
    unsigned short *aSoundBuffer;
    int i;
    int s;
    int n;

	rcvr = stackValue(2);
	aByteArray = arrayValueOf(stackValue(1));
	aByteArray -= 1;
	aSoundBuffer = arrayValueOf(stackValue(0));
	aSoundBuffer -= 1;
	if (!(successFlag)) {
		return null;
	}
	n = sizeOfSTArrayFromCPrimitive(aByteArray + 1);
	for (i = 1; i <= n; i += 1) {
		s = aByteArray[i];
		if (s > 127) {
			aSoundBuffer[i] = (((unsigned) (s - 256) << 8));
		} else {
			aSoundBuffer[i] = (((unsigned) s << 8));
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(2);
}

int primStringcomparewithcollated(void) {
    int rcvr;
    unsigned char *string1;
    unsigned char *string2;
    unsigned char *order;
    int len1;
    int len2;
    int i;
    int c1;
    int c2;

	rcvr = stackValue(3);
	string1 = arrayValueOf(stackValue(2));
	string1 -= 1;
	string2 = arrayValueOf(stackValue(1));
	string2 -= 1;
	order = arrayValueOf(stackValue(0));
	order -= 1;
	if (!(successFlag)) {
		return null;
	}
	len1 = sizeOfSTArrayFromCPrimitive(string1 + 1);
	len2 = sizeOfSTArrayFromCPrimitive(string2 + 1);
	for (i = 1; i <= (((len1 < len2) ? len1 : len2)); i += 1) {
		c1 = order[(string1[i]) + 1];
		c2 = order[(string2[i]) + 1];
		if (!(c1 == c2)) {
			if (c1 < c2) {
				if (!(successFlag)) {
					return null;
				}
				pop(4);
				pushInteger(1);
				return null;
			} else {
				if (!(successFlag)) {
					return null;
				}
				pop(4);
				pushInteger(3);
				return null;
			}
		}
	}
	if (len1 == len2) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(2);
		return null;
	}
	if (len1 < len2) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(1);
		return null;
	} else {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(3);
		return null;
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
}

int primStringfindFirstInStringinSetstartingAt(void) {
    int rcvr;
    unsigned char *aString;
    char *inclusionMap;
    int start;
    int stringSize;
    int i;

	rcvr = stackValue(3);
	aString = arrayValueOf(stackValue(2));
	aString -= 1;
	inclusionMap = arrayValueOf(stackValue(1));
	inclusionMap -= 1;
	start = checkedIntegerValueOf(stackValue(0));
	if (!(successFlag)) {
		return null;
	}
	if ((sizeOfSTArrayFromCPrimitive(inclusionMap + 1)) != 256) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(0);
		return null;
	}
	i = start;
	stringSize = sizeOfSTArrayFromCPrimitive(aString + 1);
	while ((i <= stringSize) && ((inclusionMap[(asciiValue(aString[i])) + 1]) == 0)) {
		i += 1;
	}
	if (i > stringSize) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(0);
		return null;
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
	pushInteger(i);
	return null;
}

int primStringfindSubstringinstartingAtmatchTable(void) {
    int rcvr;
    unsigned char *key;
    unsigned char *body;
    int start;
    unsigned char *matchTable;
    int startIndex;
    int index;

	rcvr = stackValue(4);
	key = arrayValueOf(stackValue(3));
	key -= 1;
	body = arrayValueOf(stackValue(2));
	body -= 1;
	start = checkedIntegerValueOf(stackValue(1));
	matchTable = arrayValueOf(stackValue(0));
	matchTable -= 1;
	if (!(successFlag)) {
		return null;
	}
	if ((sizeOfSTArrayFromCPrimitive(key + 1)) == 0) {
		if (!(successFlag)) {
			return null;
		}
		pop(5);
		pushInteger(0);
		return null;
	}
	for (startIndex = start; startIndex <= (((sizeOfSTArrayFromCPrimitive(body + 1)) - (sizeOfSTArrayFromCPrimitive(key + 1))) + 1); startIndex += 1) {
		index = 1;
		while ((matchTable[(asciiValue(body[(startIndex + index) - 1])) + 1]) == (matchTable[(asciiValue(key[index])) + 1])) {
			if (index == (sizeOfSTArrayFromCPrimitive(key + 1))) {
				if (!(successFlag)) {
					return null;
				}
				pop(5);
				pushInteger(startIndex);
				return null;
			}
			index += 1;
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(5);
	pushInteger(0);
	return null;
}

int primStringindexOfAsciiinStringstartingAt(void) {
    int rcvr;
    int anInteger;
    unsigned char *aString;
    int start;
    int stringSize;
    int pos;

	rcvr = stackValue(3);
	anInteger = checkedIntegerValueOf(stackValue(2));
	aString = arrayValueOf(stackValue(1));
	aString -= 1;
	start = checkedIntegerValueOf(stackValue(0));
	if (!(successFlag)) {
		return null;
	}
	stringSize = sizeOfSTArrayFromCPrimitive(aString + 1);
	for (pos = start; pos <= stringSize; pos += 1) {
		if ((asciiValue(aString[pos])) == anInteger) {
			if (!(successFlag)) {
				return null;
			}
			pop(4);
			pushInteger(pos);
			return null;
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
	pushInteger(0);
	return null;
}

int primStringtranslatefromtotable(void) {
    int rcvr;
    unsigned char *aString;
    int start;
    int stop;
    unsigned char *table;
    int i;

	rcvr = stackValue(4);
	aString = arrayValueOf(stackValue(3));
	aString -= 1;
	start = checkedIntegerValueOf(stackValue(2));
	stop = checkedIntegerValueOf(stackValue(1));
	table = arrayValueOf(stackValue(0));
	table -= 1;
	if (!(successFlag)) {
		return null;
	}
	for (i = start; i <= stop; i += 1) {
		aString[i] = (table[(asciiValue(aString[i])) + 1]);
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
}
