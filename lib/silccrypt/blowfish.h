/*

  blowfish.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2006 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef BLOWFISH_H
#define BLOWFISH_H

/*
 * SILC Crypto API for Blowfish
 */

SILC_CIPHER_API_SET_KEY(blowfish_cbc);
SILC_CIPHER_API_SET_IV(blowfish_cbc);
SILC_CIPHER_API_CONTEXT_LEN(blowfish_cbc);
SILC_CIPHER_API_ENCRYPT(blowfish_cbc);
SILC_CIPHER_API_DECRYPT(blowfish_cbc);

#endif
