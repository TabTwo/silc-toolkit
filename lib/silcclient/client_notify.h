/*

  client_notify.h

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

#ifndef CLIENT_NOTIFY_H
#define CLIENT_NOTIFY_H

SILC_FSM_STATE(silc_client_notify);
SILC_FSM_STATE(silc_client_notify_processed);
SILC_FSM_STATE(silc_client_notify_wait);
SILC_FSM_STATE(silc_client_notify_none);
SILC_FSM_STATE(silc_client_notify_invite);
SILC_FSM_STATE(silc_client_notify_join);
SILC_FSM_STATE(silc_client_notify_leave);
SILC_FSM_STATE(silc_client_notify_signoff);
SILC_FSM_STATE(silc_client_notify_topic_set);
SILC_FSM_STATE(silc_client_notify_nick_change);
SILC_FSM_STATE(silc_client_notify_cmode_change);
SILC_FSM_STATE(silc_client_notify_cumode_change);
SILC_FSM_STATE(silc_client_notify_motd);
SILC_FSM_STATE(silc_client_notify_channel_change);
SILC_FSM_STATE(silc_client_notify_kicked);
SILC_FSM_STATE(silc_client_notify_killed);
SILC_FSM_STATE(silc_client_notify_server_signoff);
SILC_FSM_STATE(silc_client_notify_error);
SILC_FSM_STATE(silc_client_notify_watch);

#endif /* CLIENT_NOTIFY_H */
