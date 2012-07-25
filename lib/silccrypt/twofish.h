/*

  twofish.h

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

#ifndef TWOFISH_H
#define TWOFISH_H

/*
 * SILC Crypto API for Twofish
 */

SILC_CIPHER_API_SET_KEY(twofish_cbc);
SILC_CIPHER_API_SET_IV(twofish_cbc);
SILC_CIPHER_API_CONTEXT_LEN(twofish_cbc);
SILC_CIPHER_API_ENCRYPT(twofish_cbc);
SILC_CIPHER_API_DECRYPT(twofish_cbc);

#endif
