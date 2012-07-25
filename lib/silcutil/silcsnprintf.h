/*

  silcsnprintf.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2007 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

/****h* silcutil/Snprintf
 *
 * DESCRIPTION
 *
 * Platform independent version of snprintf and other similar string
 * formatting routines.
 *
 ***/

#ifndef SILCSNPRINTF_H
#define SILCSNPRINTF_H

/****f* silcutil/SilcSnprintf/silc_snprintf
 *
 * SYNOPSIS
 *
 *    int silc_snprintf(char *str, size_t count, const char *fmt, ...);
 *
 * DESCRIPTION
 *
 *    Outputs string into `str' of maximum of size `count' including the
 *    trailing '\0' according to the `fmt'.  The `fmt' is equivalent to
 *    snprintf(3) and printf(3) formatting.  Returns the number of character
 *    in `str' or negative value on error.
 *
 ***/
int silc_snprintf(char *str, size_t count, const char *fmt, ...);

/****f* silcutil/SilcSnprintf/silc_vsnprintf
 *
 * SYNOPSIS
 *
 *    int silc_vsnprintf(char *str, size_t count, const char *fmt,
 *                       va_list args)
 *
 * DESCRIPTION
 *
 *    Same as silc_snprintf but takes the argument for the formatting from
 *    the `args' variable argument list.
 *
 ***/
int silc_vsnprintf(char *str, size_t count, const char *fmt, va_list args);

/****f* silcutil/SilcSnprintf/silc_asprintf
 *
 * SYNOPSIS
 *
 *    int silc_asprintf(char **ptr, const char *format, ...)
 *
 * DESCRIPTION
 *
 *    Same as silc_snprintf but allocates a string large enough to hold the
 *    output including the trailing '\0'.  The caller must free the `ptr'.
 *
 ***/
int silc_asprintf(char **ptr, const char *format, ...);

/****f* silcutil/SilcSnprintf/silc_vasprintf
 *
 * SYNOPSIS
 *
 *    int silc_vasprintf(char **ptr, const char *format, va_list ap)
 *
 * DESCRIPTION
 *
 *    Same as silc_asprintf but takes the argument from the `ap' variable
 *    argument list.
 *
 ***/
int silc_vasprintf(char **ptr, const char *format, va_list ap);

#endif /* SILCSNPRINTF_H */
