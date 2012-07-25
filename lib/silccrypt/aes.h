/*

  aes.h

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

#ifndef AES_H
#define AES_H

/*
 * SILC Crypto API for AES
 */

SILC_CIPHER_API_SET_KEY(aes_cbc);
SILC_CIPHER_API_SET_IV(aes_cbc);
SILC_CIPHER_API_ENCRYPT(aes_cbc);
SILC_CIPHER_API_DECRYPT(aes_cbc);
SILC_CIPHER_API_CONTEXT_LEN(aes_cbc);
SILC_CIPHER_API_SET_KEY(aes_ctr);
SILC_CIPHER_API_SET_IV(aes_ctr);
SILC_CIPHER_API_ENCRYPT(aes_ctr);
SILC_CIPHER_API_DECRYPT(aes_ctr);
SILC_CIPHER_API_CONTEXT_LEN(aes_ctr);

#endif
