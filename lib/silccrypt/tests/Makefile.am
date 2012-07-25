#
#  Makefile.am
#
#  Author: Pekka Riikonen <priikone@silcnet.org>
#
#  Copyright (C) 2002 - 2003 Pekka Riikonen
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

bin_PROGRAMS = 	test_sha1 	\
		test_sha256	\
		test_md5	\
		test_hmacsha1	\
		test_hmacsha256	\
		test_hmacmd5	\
		test_aes	\
		test_twofish	\
		test_silcpkcs

test_sha1_SOURCES = test_sha1.c
test_sha256_SOURCES = test_sha256.c
test_md5_SOURCES = test_md5.c
test_hmacsha1_SOURCES = test_hmacsha1.c
test_hmacsha256_SOURCES = test_hmacsha256.c
test_hmacmd5_SOURCES = test_hmacmd5.c

test_aes_SOURCES = test_aes.c
test_twofish_SOURCES = test_aes.c

test_silcpkcs_SOURCES = test_silcpkcs.c

LIBS = $(SILC_COMMON_LIBS)
LDADD = -L.. -L../.. -lsilc

include $(top_srcdir)/Makefile.defines.in
