/* sqConfig.h -- platform identification and configuration */

#if defined(__MWERKS__) && !defined(macintosh)
  /* CodeWarrior 8 neglects to define "macintosh" */
# define macintosh
#endif

#if defined(WIN32) || defined(_WIN32) || defined(Win32)
  /* Some compilers use different win32 definitions.
     Define WIN32 so we have only to check for one symbol. */
# if !defined(WIN32)
#  define WIN32
# endif
#endif

#if defined(macintosh)
# if defined(SQ_CONFIG_DONE)
#   error configuration conflict
# endif
# define SQ_CONFIG_DONE
#endif

#if defined(ACORN)
# if defined(SQ_CONFIG_DONE)
#   error configuration conflict
# endif
# define USE_CLOCK_MSECS
# define LITTLE_ENDIAN_BITBLT
# define SQ_CONFIG_DONE
#endif

#if defined(WIN32)
# if defined(SQ_CONFIG_DONE)
#   error configuration conflict
# endif
# if defined(_M_IX86) || defined(X86)
  /* x86 systems */
#  define DOUBLE_WORD_ALIGNMENT
#  define DOUBLE_WORD_ORDER
  /* Note: We include a generic sqWin32.h to override some settings */
#  include "sqWin32.h"
#  define SQ_CONFIG_DONE
# elif defined(_WIN32_WCE)
#  include "sqWin32.h"
#  define SQ_CONFIG_DONE
# else
#  error unsupported win32 processor type (alpha?!)
# endif
#endif


/* This file has been superseded by autoconf for Unix variants. */

#if defined(HAVE_CONFIG_H)
# include "sqUnixConfig.h"
# define SQ_CONFIG_DONE
#endif


#if !defined(SQ_CONFIG_DONE)
# error test for, and describe, your architecture here.
#endif



/* Thank you http://comments.gmane.org/gmane.comp.lang.smalltalk.squeak.general/57333 !*/
#undef  DOUBLE_WORD_ALIGNMENT
#define  DOUBLE_WORD_ORDER

