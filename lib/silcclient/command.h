/*

  command.h

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

#ifndef COMMAND_H
#define COMMAND_H

SILC_FSM_STATE(silc_client_command);
SILC_FSM_STATE(silc_client_command_whois);
SILC_FSM_STATE(silc_client_command_whowas);
SILC_FSM_STATE(silc_client_command_identify);
SILC_FSM_STATE(silc_client_command_nick);
SILC_FSM_STATE(silc_client_command_list);
SILC_FSM_STATE(silc_client_command_topic);
SILC_FSM_STATE(silc_client_command_invite);
SILC_FSM_STATE(silc_client_command_quit);
SILC_FSM_STATE(silc_client_command_kill);
SILC_FSM_STATE(silc_client_command_info);
SILC_FSM_STATE(silc_client_command_ping);
SILC_FSM_STATE(silc_client_command_oper);
SILC_FSM_STATE(silc_client_command_join);
SILC_FSM_STATE(silc_client_command_motd);
SILC_FSM_STATE(silc_client_command_umode);
SILC_FSM_STATE(silc_client_command_cmode);
SILC_FSM_STATE(silc_client_command_cumode);
SILC_FSM_STATE(silc_client_command_kick);
SILC_FSM_STATE(silc_client_command_ban);
SILC_FSM_STATE(silc_client_command_detach);
SILC_FSM_STATE(silc_client_command_watch);
SILC_FSM_STATE(silc_client_command_silcoper);
SILC_FSM_STATE(silc_client_command_leave);
SILC_FSM_STATE(silc_client_command_users);
SILC_FSM_STATE(silc_client_command_getkey);
SILC_FSM_STATE(silc_client_command_service);

SilcUInt16 silc_client_command_send_argv(SilcClient client,
					 SilcClientConnection conn,
					 SilcCommand command,
					 SilcClientCommandReply reply,
					 void *reply_context,
					 SilcUInt32 argc,
					 unsigned char **argv,
					 SilcUInt32 *argv_lens,
					 SilcUInt32 *argv_types);
void silc_client_commands_register(SilcClient client);
void silc_client_commands_unregister(SilcClient client);
SilcBool silc_client_command_called_dummy(SilcClient client,
					  SilcClientConnection conn,
					  SilcCommand command,
					  SilcStatus status,
					  SilcStatus error,
					  void *context,
					  va_list ap);
void silc_client_command_resolve_dummy(SilcClient client,
				       SilcClientConnection conn,
				       SilcStatus status,
				       SilcDList clients,
				       void *context);

#endif /* COMMAND_H */
