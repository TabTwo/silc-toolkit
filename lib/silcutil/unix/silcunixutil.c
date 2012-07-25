/*

  silcunixutil.c

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2007 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#include "silc.h"

/* Returns the username of the user. If the global variable LOGNAME
   does not exists we will get the name from the password file. */

char *silc_get_username()
{
  char *logname = NULL;

  logname = getenv("LOGNAME");
  if (!logname) {
    logname = getlogin();
    if (!logname) {
      struct passwd *pw;

      pw = getpwuid(getuid());
      if (!pw)
	return strdup("foo");

      logname = pw->pw_name;
    }
  }

  return strdup(logname);
}

/* Returns the real name of ther user. */

char *silc_get_real_name()
{
  char *realname = NULL;
  struct passwd *pw;

  pw = getpwuid(getuid());
  if (!pw)
    return strdup("No Name");

  if (strchr(pw->pw_gecos, ','))
    *strchr(pw->pw_gecos, ',') = 0;

  if (!strlen(pw->pw_gecos))
    return strdup("No Name");

  realname = strdup(pw->pw_gecos);

  return realname;
}

/* Return current time to struct timeval. */

int silc_gettimeofday(struct timeval *p)
{
  return gettimeofday(p, NULL);
}

int silc_file_set_nonblock(int fd)
{
  return fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
}
