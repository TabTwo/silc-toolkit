/*

  silcwin32util.c

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2001 - 2007 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/
/* $Id$ */

#include "silc.h"

#define FILETIME_1970 0x019db1ded53e8000
const BYTE DWLEN = sizeof(DWORD) * 8;

/* Return current time in struct timeval. Code ripped from some xntp
   implementation. */

int silc_gettimeofday(struct timeval *tv)
{
  FILETIME ft;
  __int64 usec;

  GetSystemTimeAsFileTime(&ft);
  usec = (__int64) ft.dwHighDateTime << DWLEN | ft.dwLowDateTime;
  usec = (usec - FILETIME_1970) / 10;
  tv->tv_sec  = (long) (usec / 1000000);
  tv->tv_usec = (long) (usec % 1000000);

  return 0;
}

char *silc_get_username(void)
{
  DWORD maxlen = 128;
  char username[128];
  GetUserName(username, &maxlen);
  return strdup(username);
}

char *silc_get_real_name(void)
{
  return silc_get_username();
}

int silc_file_set_nonblock(int fd)
{
  return 0;
}
