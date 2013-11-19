/* config.h.  Generated automatically by configure.  */
/* config.h.in -- template for config.h			-*- C -*-
 *
 *   Copyright (C) 1996-2002 Ian Piumarta and other authors/contributors
 *     as listed elsewhere in this file.
 *   All rights reserved.
 *
 *   This file is part of Unix Squeak.
 *
 *   This file is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.
 *
 *   You may use and/or distribute this file ONLY as part of Squeak, under
 *   the terms of the Squeak License as described in `LICENSE' in the base of
 *   this distribution, subject to the following restrictions:
 *
 *   1. The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software.  If you use this software
 *      in a product, an acknowledgment to the original author(s) (and any
 *      other contributors mentioned herein) in the product documentation
 *      would be appreciated but is not required.
 *
 *   2. This notice must not be removed or altered in any source distribution.
 *
 *   Using (or modifying this file for use) in any context other than Squeak
 *   changes these copyright conditions.  Read the file `COPYING' in the
 *   directory `platforms/unix/doc' before proceeding with any such use.
 *
 *   You are not allowed to distribute a modified version of this file
 *   under its original name without explicit permission to do so.  If
 *   you change it, rename it.
 */

/* Author: Ian.Piumarta@INRIA.Fr
 *
 * Last edited: 2002-11-30 16:00:59 by piumarta on calvin.inria.fr
 */

/* typedefs */

/* #undef	size_t */
/* #undef	socklen_t */

#define	squeakInt64 long long

/* architecture */

#define	OS_TYPE "unix"

#define	VM_HOST "armv6l-none-eabi"
#define	VM_HOST_CPU "armv6l"
/* #undef	VM_HOST_VENDOR */
#define	VM_HOST_OS "none-eabi"

#undef	WORDS_BIGENDIAN 
#undef	DOUBLE_WORD_ALIGNMENT 
#define	DOUBLE_WORD_ORDER 1

/* other configured variables */

#define SQ_VERSION "3.4-5170"
#define VM_VERSION "3.4-1"
#define VM_LIBDIR "/usr/local/lib/squeak/3.4-1"
#define VM_MODULE_PREFIX ""
/* #undef VM_DLSYM_PREFIX */
