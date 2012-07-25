#
#  Makefile.am
#
#  Author: Pekka Riikonen <priikone@silcnet.org>
#
#  Copyright (C) 2006 Pekka Riikonen
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

bin_PROGRAMS = 	test_silcclient

test_silcclient_SOURCES = test_silcclient.c

LIBS = $(SILC_COMMON_LIBS)
LDADD = -L.. -L../.. -lsilc -lsilcclient

include $(top_srcdir)/Makefile.defines.in
