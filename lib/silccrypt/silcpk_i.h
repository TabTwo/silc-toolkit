/*

  silcpk_i.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2005, 2007 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCPK_I_H
#define SILCPK_I_H

/* Public and private key file headers */
#define SILC_PKCS_PUBLIC_KEYFILE_BEGIN "-----BEGIN SILC PUBLIC KEY-----\n"
#define SILC_PKCS_PUBLIC_KEYFILE_END "\n-----END SILC PUBLIC KEY-----\n"
#define SILC_PKCS_PRIVATE_KEYFILE_BEGIN "-----BEGIN SILC PRIVATE KEY-----\n"
#define SILC_PKCS_PRIVATE_KEYFILE_END "\n-----END SILC PRIVATE KEY-----\n"

const SilcPKCSAlgorithm *silc_pkcs_silc_get_algorithm(void *public_key);
SilcBool silc_pkcs_silc_import_public_key_file(unsigned char *filedata,
					       SilcUInt32 filedata_len,
					       SilcPKCSFileEncoding encoding,
					       void **ret_public_key);
int silc_pkcs_silc_import_public_key(unsigned char *key,
				     SilcUInt32 key_len,
				     void **ret_public_key);
unsigned char *
silc_pkcs_silc_export_public_key_file(void *public_key,
				      SilcPKCSFileEncoding encoding,
				      SilcUInt32 *ret_len);
unsigned char *silc_pkcs_silc_export_public_key(void *public_key,
						SilcUInt32 *ret_len);
SilcUInt32 silc_pkcs_silc_public_key_bitlen(void *public_key);
void *silc_pkcs_silc_public_key_copy(void *public_key);
SilcBool silc_pkcs_silc_public_key_compare(void *key1, void *key2);
void silc_pkcs_silc_public_key_free(void *public_key);
SilcBool silc_pkcs_silc_import_private_key_file(unsigned char *filedata,
						SilcUInt32 filedata_len,
						const char *passphrase,
						SilcUInt32 passphrase_len,
						SilcPKCSFileEncoding encoding,
						void **ret_private_key);
int silc_pkcs_silc_import_private_key(unsigned char *key,
				      SilcUInt32 key_len,
				      void **ret_private_key);
unsigned char *
silc_pkcs_silc_export_private_key_file(void *private_key,
				       const char *passphrase,
				       SilcUInt32 passphrase_len,
				       SilcPKCSFileEncoding encoding,
				       SilcRng rng,
				       SilcUInt32 *ret_len);
unsigned char *silc_pkcs_silc_export_private_key(void *private_key,
						 SilcUInt32 *ret_len);
SilcUInt32 silc_pkcs_silc_private_key_bitlen(void *private_key);
void silc_pkcs_silc_private_key_free(void *private_key);
SilcBool silc_pkcs_silc_encrypt(void *public_key,
				unsigned char *src,
				SilcUInt32 src_len,
				unsigned char *dst,
				SilcUInt32 dst_size,
				SilcUInt32 *ret_dst_len,
				SilcRng rng);
SilcBool silc_pkcs_silc_decrypt(void *private_key,
				unsigned char *src,
				SilcUInt32 src_len,
				unsigned char *dst,
				SilcUInt32 dst_size,
				SilcUInt32 *ret_dst_len);
SilcBool silc_pkcs_silc_sign(void *private_key,
			     unsigned char *src,
			     SilcUInt32 src_len,
			     unsigned char *signature,
			     SilcUInt32 signature_size,
			     SilcUInt32 *ret_signature_len,
			     SilcBool compute_hash,
			     SilcHash hash);
SilcBool silc_pkcs_silc_verify(void *public_key,
			       unsigned char *signature,
			       SilcUInt32 signature_len,
			       unsigned char *data,
			       SilcUInt32 data_len,
			       SilcHash hash);

#endif /* SILCPK_I_H */
