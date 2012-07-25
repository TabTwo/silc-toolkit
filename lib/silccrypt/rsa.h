/*

  rsa.h

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

#ifndef RSA_H
#define RSA_H

/* RSA Public Key */
typedef struct {
  int bits;			/* bits in key */
  SilcMPInt n;			/* modulus */
  SilcMPInt e;			/* public exponent */
} RsaPublicKey;

/* RSA Private Key */
typedef struct {
  int bits;			/* bits in key */
  SilcMPInt n;			/* modulus */
  SilcMPInt e;			/* public exponent */
  SilcMPInt d;			/* private exponent */
  SilcMPInt p;			/* CRT, p */
  SilcMPInt q;			/* CRT, q */
  SilcMPInt dP;			/* CRT, d mod p - 1 */
  SilcMPInt dQ;			/* CRT, d mod q - 1 */
  SilcMPInt qP;			/* CRT, q ^ -1 mod p (aka u, aka qInv) */
} RsaPrivateKey;

SilcBool silc_rsa_generate_keys(SilcUInt32 bits, SilcMPInt *p, SilcMPInt *q,
				void **ret_public_key, void **ret_private_key);
SilcBool silc_rsa_public_operation(RsaPublicKey *key, SilcMPInt *src,
				   SilcMPInt *dst);
SilcBool silc_rsa_private_operation(RsaPrivateKey *key, SilcMPInt *src,
				    SilcMPInt *dst);

#endif /* RSA_H */
