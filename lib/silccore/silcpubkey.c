/*

  silcpubkey.c

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

#include "silc.h"

/* Encodes Public Key Payload for transmitting public keys and certificates. */

SilcBuffer silc_public_key_payload_encode(SilcPublicKey public_key)
{
  SilcBuffer buffer;
  unsigned char *pk;
  SilcUInt32 pk_len;
  SilcPKCSType type;

  if (!public_key)
    return NULL;

  type = silc_pkcs_get_type(public_key);
  pk = silc_pkcs_public_key_encode(public_key, &pk_len);
  if (!pk)
    return NULL;

  buffer = silc_buffer_alloc_size(4 + pk_len);
  if (!buffer) {
    silc_free(pk);
    return NULL;
  }

  if (silc_buffer_format(buffer,
			 SILC_STR_UI_SHORT(pk_len),
			 SILC_STR_UI_SHORT(type),
			 SILC_STR_DATA(pk, pk_len),
			 SILC_STR_END) < 0) {
    silc_buffer_free(buffer);
    silc_free(pk);
    return NULL;
  }

  silc_free(pk);
  return buffer;
}

/* Decodes public key payload and returns allocated public key */

SilcBool silc_public_key_payload_decode(unsigned char *data,
					SilcUInt32 data_len,
					SilcPublicKey *public_key)
{
  SilcBufferStruct buf;
  SilcUInt16 pk_len, pk_type;
  unsigned char *pk;
  int ret;

  if (!public_key)
    return FALSE;

  silc_buffer_set(&buf, data, data_len);
  ret = silc_buffer_unformat(&buf,
			     SILC_STR_ADVANCE,
			     SILC_STR_UI_SHORT(&pk_len),
			     SILC_STR_UI_SHORT(&pk_type),
			     SILC_STR_END);
  if (ret < 0 || pk_len > data_len - 4)
    return FALSE;

  if (pk_type < SILC_PKCS_SILC || pk_type > SILC_PKCS_SPKI)
    return FALSE;

  ret = silc_buffer_unformat(&buf,
			     SILC_STR_DATA(&pk, pk_len),
			     SILC_STR_END);
  if (ret < 0)
    return FALSE;

  return silc_pkcs_public_key_alloc((SilcPKCSType)pk_type,
				    pk, pk_len, public_key);
}
