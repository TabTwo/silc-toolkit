/*

  silchttpphp.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2006 - 2007 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

/****h* silchttp/SILC HTTP PHP Translator
 *
 * DESCRIPTION
 *
 * PHP translator for SILC HTTP Server, enabling PHP support for the pages
 * served through the SILC HTTP Server interface (silchttpserver.h).
 * The PHP must be installed in the system and must be in the execution
 * path for the interface to work.
 *
 ***/

#ifndef SILCHTTPPHP_H
#define SILCHTTPPHP_H

/****f* silchttp/SilcHTTPServer/silc_http_php
 *
 * SYNOPSIS
 *
 *    SilcBuffer silc_http_php(char *php_data);
 *
 * DESCRIPTION
 *
 *    Executes the PHP code contained in the buffer `php_data' and returns
 *    the result in the allocated SilcBuffer or NULL on error.  The caller
 *    must free the returned buffer.
 *
 ***/
SilcBuffer silc_http_php(char *php_data);

/****f* silchttp/SilcHTTPServer/silc_http_php_file
 *
 * SYNOPSIS
 *
 *    SilcBuffer silc_http_php_file(const char *filepath);
 *
 * DESCRIPTION
 *
 *    Reads the PHP contents from the file indicated by the `filepath' and
 *    executes the PHP code and returns the result in the allocated
 *    SilcBuffer or NULL on error.  The caller must free the returned buffer.
 *
 ***/
SilcBuffer silc_http_php_file(const char *filename);

#endif /* SILCHTTPPHP_H */
