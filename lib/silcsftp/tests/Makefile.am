#
#  Makefile.am
#
#  Author: Pekka Riikonen <priikone@silcnet.org>
#
#  Copyright (C) 2001 Pekka Riikonen
#
#  The contents of this file are subject to one of the Licenses specified 
#  in the COPYING file;  You may not use this file except in compliance 
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  information.
#

AUTOMAKE_OPTIONS = 1.0 no-dependencies foreign

bin_PROGRAMS = sftp_client sftp_server 
sftp_server_SOURCES = sftp_server.c
sftp_client_SOURCES = sftp_client.c

LIBS = $(SILC_COMMON_LIBS)
LDADD = -L.. -L../.. -lsilc

include $(top_srcdir)/Makefile.defines.in
