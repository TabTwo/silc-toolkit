# Automatically generated by Autodist 1.4 from Makefile.ad.  Do not edit.
# To make changes edit the ./lib/silcmath/Makefile.ad file in the source tree.

# Source: ./lib/silcmath/Makefile.ad
# Generated: Fri Aug  7 10:09:01 EEST 2009 by priikone
# Distribution: Toolkit
# License: distdir/TOOLKIT

#
#  Makefile.ad
#
#  Author: Pekka Riikonen <priikone@silcnet.org>
#
#  Copyright (C) 2000 - 2005 Pekka Riikonen
#
#  The contents of this file are subject to one of the Licenses specified 
#  in the COPYING file;  You may not use this file except in compliance 
#  with the License.
#
#  The software distributed under the License is distributed on an "AS IS"
#  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
#  KIND, either expressed or implied.  See the COPYING file for more
#  information.
#

AUTOMAKE_OPTIONS = 1.0 no-dependencies foreign

noinst_LTLIBRARIES = libsilcmath.la

if SILC_MP_SILCMATH
MP_SOURCE =	mp_tma.c	tma.c

MP_HEADER =	mp_tma.h	tma.h	tma_class.h	tma_superclass.h

AM_CFLAGS = @MATH_CFLAGS@
else
MP_SOURCE = mp_gmp.c
MP_HEADER =
endif

libsilcmath_la_SOURCES =	silcprimegen.c	modinv.c	mpbin.c	$(MP_SOURCE)

include_HEADERS =	mp_gmp.h	$(MP_HEADER)	silcmath.h	silcmp.h

EXTRA_DIST = silcmp.h silcmath.h $(MP_SOURCE) $(MP_HEADER) mp_gmp.c mp_gmp.h

include $(top_srcdir)/Makefile.defines.in

