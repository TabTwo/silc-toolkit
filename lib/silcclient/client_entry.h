/*

  client_entry.h

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

#ifndef CLIENT_ENTRY_H
#define CLIENT_ENTRY_H

SilcClientEntry silc_client_add_client(SilcClient client,
				       SilcClientConnection conn,
				       char *nickname, char *username,
				       char *userinfo, SilcClientID *id,
				       SilcUInt32 mode);
void silc_client_update_client(SilcClient client,
			       SilcClientConnection conn,
			       SilcClientEntry client_entry,
			       const char *nickname,
			       const char *username,
			       const char *userinfo,
			       SilcUInt32 mode);
SilcBool silc_client_change_nickname(SilcClient client,
				     SilcClientConnection conn,
				     SilcClientEntry client_entry,
				     const char *new_nick,
				     SilcClientID *new_id,
				     const unsigned char *idp,
				     SilcUInt32 idp_len);
void silc_client_del_client_entry(SilcClient client,
				  SilcClientConnection conn,
				  SilcClientEntry client_entry);
SilcBool silc_client_del_client(SilcClient client, SilcClientConnection conn,
				SilcClientEntry client_entry);
SilcClientEntry silc_client_get_client(SilcClient client,
				       SilcClientConnection conn,
				       SilcClientID *client_id);
SilcChannelEntry silc_client_add_channel(SilcClient client,
					 SilcClientConnection conn,
					 const char *channel_name,
					 SilcUInt32 mode,
					 SilcChannelID *channel_id);
SilcBool silc_client_del_channel(SilcClient client, SilcClientConnection conn,
				 SilcChannelEntry channel);
SilcBool silc_client_replace_channel_id(SilcClient client,
					SilcClientConnection conn,
					SilcChannelEntry channel,
					SilcChannelID *new_id);
SilcServerEntry silc_client_add_server(SilcClient client,
				       SilcClientConnection conn,
				       const char *server_name,
				       const char *server_info,
				       SilcServerID *server_id);
void silc_client_update_server(SilcClient client,
			       SilcClientConnection conn,
			       SilcServerEntry server_entry,
			       const char *server_name,
			       const char *server_info);
SilcBool silc_client_del_server(SilcClient client, SilcClientConnection conn,
				SilcServerEntry server);
SilcUInt16 silc_client_get_clients_by_list(SilcClient client,
					   SilcClientConnection conn,
					   SilcUInt32 list_count,
					   SilcBuffer client_id_list,
					   SilcGetClientCallback completion,
					   void *context);

#endif /* CLIENT_ENTRY_H */
