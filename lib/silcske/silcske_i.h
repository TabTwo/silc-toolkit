/*

  silcske_i.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2005 - 2008 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCSKE_I_H
#define SILCSKE_I_H

/* Packet retry counter and timer defines for UDP transport. */
#define SILC_SKE_RETRY_COUNT   4          /* Max packet retry count */
#define SILC_SKE_RETRY_MUL     2          /* Retry timer interval growth */
#define SILC_SKE_RETRY_RAND    2          /* Randomizer, timeout += rnd % 2 */
#define SILC_SKE_RETRY_MIN     1	  /* Min retry timeout, seconds */

/* Length of cookie in Start Payload */
#define SILC_SKE_COOKIE_LEN 16

/* SKE context */
struct SilcSKEStruct {
  SilcPacketStream stream;
  SilcRng rng;
  SilcSKR repository;
  SilcSKECallbacks callbacks;
  void *user_data;
  SilcSKEStatus status;

  /* Negotiated Security properties.  May be NULL in case of error. */
  SilcSKESecurityProperties prop;

  /* Key Exchange payloads filled during key negotiation with
     remote data. Responder may save local data here as well. */
  SilcSKEStartPayload start_payload;
  SilcSKEKEPayload ke1_payload;
  SilcSKEKEPayload ke2_payload;

  /* Temporary copy of the KE Start Payload used in the
     HASH computation. */
  SilcBuffer start_payload_copy;

  /* Random number x, 1 < x < q. This is the secret exponent
     used in Diffie Hellman computations. */
  SilcMPInt *x;

  /* The secret shared key */
  SilcMPInt *KEY;

  /* The hash value HASH of the key exchange */
  unsigned char *hash;
  SilcUInt32 hash_len;

  char *version;		      /* Local version */
  char *remote_version;		      /* Remote version */

  SilcPublicKey public_key;
  SilcPrivateKey private_key;
  SilcSKEPKType pk_type;
  SilcPacket packet;
  SilcSKESecurityPropertyFlag flags;
  SilcSKEKeyMaterial keymat;
  SilcSKERekeyMaterial rekey;
  SilcSchedule schedule;
  SilcFSMStruct fsm;
  SilcAsyncOperationStruct op;
  SilcUInt16 session_port;

  /* Packet retransmission */
  SilcUInt16 retry_timer;
  SilcUInt16 retry_count;
  struct SilcSKEPacketRetransmission {
    SilcPacketType type;
    SilcPacketFlags flags;
    unsigned char *data;
    SilcUInt32 data_len;
  } retrans;

  SilcUInt16 timeout;		      /* SKE timeout */
  SilcUInt16 refcnt;		      /* Reference counter */

  unsigned int aborted          : 1;  /* Set when SKE aborted */
  unsigned int responder        : 1;  /* Set when we are responder side */
  unsigned int rekeying         : 1;  /* Set when rekeying */
  unsigned int failure_notified : 1;  /* Set to indicate that we already called
					 the failure notify routine */
};

#endif /* SILCSKE_I_H */
