/*

  silcpubkey.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2005 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

/****h* silccore/SILC Public Key Payload
 *
 * DESCRIPTION
 *
 * Implementation of the Public Key Payload.  Public Key Payload is used to
 * deliver different types of public keys and certificates in the SILC
 * protocol.
 *
 ***/

#ifndef SILCPUBKEY_H
#define SILCPUBKEY_H

/****f* silccore/SilcPubKeyAPI/silc_public_key_payload_encode
 *
 * SYNOPSIS
 *
 *    SilcBool silc_public_key_payload_encode(SilcPublicKey public_key);
 *
 * DESCRIPTION
 *
 *    Encodes the Public Key Payload from the public key indicated by
 *    `public_key'.  Returns the allocated and encoded payload buffer,
 *    or NULL on error.
 *
 ***/
SilcBuffer silc_public_key_payload_encode(SilcPublicKey public_key);

/****f* silccore/SilcPubKeyAPI/silc_public_key_payload_decode
 *
 * SYNOPSIS
 *
 *    SilcBool silc_public_key_payload_decode(unsigned char *data,
 *                                            SilcUInt32 data_len,
 *                                            SilcPublicKey *public_key);
 *
 * DESCRIPTION
 *
 *    Decodes Public Key Payload from `data' of `data_len' bytes in length
 *    data buffer into `public_key' pointer.  Returns FALSE if the payload
 *    cannot be decoded.
 *
 ***/
SilcBool silc_public_key_payload_decode(unsigned char *data,
					SilcUInt32 data_len,
					SilcPublicKey *public_key);

#endif /* SILCPUBKEY_H */
