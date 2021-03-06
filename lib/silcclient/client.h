/*

  client.h

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

#ifndef CLIENT_H
#define CLIENT_H

#ifndef SILCCLIENT_H
#error "Do not include this header directly"
#endif

/* Forward declarations */
typedef struct SilcClientStruct *SilcClient;
typedef struct SilcClientConnectionStruct *SilcClientConnection;
typedef struct SilcClientEntryStruct *SilcClientEntry;
typedef struct SilcChannelEntryStruct *SilcChannelEntry;
typedef struct SilcServerEntryStruct *SilcServerEntry;

typedef struct SilcClientKeyAgreementStruct *SilcClientKeyAgreement;
typedef struct SilcClientFtpSessionStruct *SilcClientFtpSession;
typedef struct SilcClientCommandReplyContextStruct
                                           *SilcClientCommandReplyContext;
typedef struct SilcChannelUserStruct *SilcChannelUser;
typedef struct SilcClientInternalStruct *SilcClientInternal;
typedef struct SilcClientConnectionInternalStruct
     *SilcClientConnectionInternal;
typedef struct SilcChannelPrivateKeyStruct *SilcChannelPrivateKey;

/* Internal client entry context */
typedef struct SilcClientEntryInternalStruct {
  void *prv_waiter;		/* Private message packet waiter */
  SilcRwLock lock;		/* Read/write lock */
  SilcCipher send_key;		/* Private message key for sending */
  SilcCipher receive_key;	/* Private message key for receiving */
  SilcHmac hmac_send;		/* Private mesage key HMAC for sending */
  SilcHmac hmac_receive;	/* Private mesage key HMAC for receiving */
  unsigned char *key;		/* Valid if application provided the key */
  SilcUInt32 key_len;		/* Key data length */
  SilcClientKeyAgreement ke;	/* Current key agreement context or NULL */

  SilcAtomic32 refcnt;		/* Reference counter */
  SilcAtomic32 deleted;	        /* Flag indicating whether the client object is
				   already scheduled for deletion */
  SilcUInt16 resolve_cmd_ident;	/* Command identifier when resolving */

  /* Flags */
  unsigned int valid       : 1;	/* FALSE if this entry is not valid.  Entry
				   without nickname is not valid. */
  unsigned int generated   : 1; /* TRUE if library generated `key' */
  unsigned int prv_resp    : 1; /* TRUE if we are responder when using
				   private message keys. */
} SilcClientEntryInternal;

/* Internal channel entry context */
typedef struct SilcChannelEntryInternalStruct {
  SilcRwLock lock;		             /* Read/write lock */

  /* SilcChannelEntry status information */
  SilcDList old_channel_keys;
  SilcDList old_hmacs;

  /* Channel private keys */
  SilcDList private_keys;		     /* List of private keys or NULL */
  SilcChannelPrivateKey curr_key;	     /* Current private key */

  /* Channel keys */
  SilcCipher send_key;                       /* The channel key */
  SilcCipher receive_key;                    /* The channel key */
  SilcHmac hmac;			     /* Current HMAC */
  unsigned char iv[SILC_CIPHER_MAX_IV_SIZE]; /* Current IV */

  SilcAtomic32 refcnt;		             /* Reference counter */
  SilcAtomic32 deleted;                      /* Flag indicating whether the
						channel object is already
						scheduled for deletion */
  SilcUInt16 resolve_cmd_ident;		     /* Channel information resolving
						identifier. This is used when
						resolving users, and other
						stuff that relates to the
						channel. Not used for the
						channel resolving itself. */
} SilcChannelEntryInternal;

/* Internal server entry context */
typedef struct SilcServerEntryInternalStruct {
  SilcRwLock lock;		             /* Read/write lock */
  SilcUInt16 resolve_cmd_ident;		     /* Resolving identifier */
  SilcAtomic32 refcnt;		             /* Reference counter */
  SilcAtomic32 deleted;	                     /* Flag indicating whether the
						server object is already
						scheduled for deletion. */
} SilcServerEntryInternal;

#endif /* CLIENT_H */
