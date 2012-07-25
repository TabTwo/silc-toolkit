/*

  client_channel.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2006 - 2007 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef CLIENT_CHANNEL_H
#define CLIENT_CHANNEL_H

SILC_FSM_STATE(silc_client_channel_message);
SILC_FSM_STATE(silc_client_channel_message_error);
SILC_FSM_STATE(silc_client_channel_key);

SilcBool silc_client_save_channel_key(SilcClient client,
				      SilcClientConnection conn,
				      SilcBuffer key_payload,
				      SilcChannelEntry channel);
SilcChannelUser silc_client_on_channel(SilcChannelEntry channel,
				       SilcClientEntry client_entry);
SilcBool silc_client_add_to_channel(SilcClient client,
				    SilcClientConnection conn,
				    SilcChannelEntry channel,
				    SilcClientEntry client_entry,
				    SilcUInt32 cumode);
SilcBool silc_client_remove_from_channel(SilcClient client,
					 SilcClientConnection conn,
					 SilcChannelEntry channel,
					 SilcClientEntry client_entry);
void silc_client_remove_from_channels(SilcClient client,
				      SilcClientConnection conn,
				      SilcClientEntry client_entry);
void silc_client_empty_channel(SilcClient client,
			       SilcClientConnection conn,
			       SilcChannelEntry channel);
SilcBool silc_client_channel_save_public_keys(SilcChannelEntry channel,
					      unsigned char *chpk_list,
					      SilcUInt32 chpk_list_len,
					      SilcBool remove_all);

#endif /* CLIENT_CHANNEL_H */
