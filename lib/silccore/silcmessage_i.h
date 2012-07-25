/*

  silcmessage_i.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2006 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCMESSAGE_I_H
#define SILCMESSAGE_I_H

#ifndef SILCMESSAGE_I_H
#error "Do not include this header directly"
#endif

/* The SILC_MESSAGE_FLAG_SIGNED Payload */
typedef struct SilcMessageSignedPayloadStruct {
  unsigned char *pk_data;
  unsigned char *sign_data;
  SilcUInt16 pk_len;
  SilcUInt16 pk_type;
  SilcUInt16 sign_len;
} *SilcMessageSignedPayload;

/* Message Payload structure. */
struct SilcMessagePayloadObject {
  unsigned char *data;
  unsigned char *pad;
  unsigned char *mac;
  struct SilcMessageSignedPayloadStruct sig;
  SilcMessageFlags flags;
  SilcUInt16 data_len;
  SilcUInt16 pad_len;
  SilcUInt16 iv_len;
  unsigned int allocated  : 1;
};

#endif /* SILCMESSAGE_I_H */
