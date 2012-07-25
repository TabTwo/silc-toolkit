/*

  client_listener.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2007 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef CLIENT_LISTENER_H
#define CLIENT_LISTENER_H

/* Forward declarations */
typedef struct SilcClientListenerStruct *SilcClientListener;

SilcClientListener
silc_client_listener_add(SilcClient client,
			 SilcSchedule schedule,
			 SilcClientConnectionParams *params,
			 SilcPublicKey public_key,
			 SilcPrivateKey private_key,
			 SilcClientConnectCallback callback,
			 void *context);
void silc_client_listener_free(SilcClientListener listener);
SilcUInt16 silc_client_listener_get_local_port(SilcClientListener listener);

#endif /* CLIENT_LISTENER_H */
