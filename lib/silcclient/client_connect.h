/*

  client_connect.h

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

#ifndef CLIENT_CONNECT_H
#define CLIENT_CONNECT_H

SILC_FSM_STATE(silc_client_connect_auth_request);
SILC_FSM_STATE(silc_client_st_connect);
SILC_FSM_STATE(silc_client_st_connect_set_stream);
SILC_FSM_STATE(silc_client_st_connect_key_exchange);
SILC_FSM_STATE(silc_client_st_connect_setup_udp);
SILC_FSM_STATE(silc_client_st_connect_auth_resolve);
SILC_FSM_STATE(silc_client_st_connect_auth_data);
SILC_FSM_STATE(silc_client_st_connect_auth_start);
SILC_FSM_STATE(silc_client_st_connected);
SILC_FSM_STATE(silc_client_st_connect_error);
SILC_FSM_STATE(silc_client_st_rekey);

SILC_TASK_CALLBACK(silc_client_connect_timeout);
SILC_TASK_CALLBACK(silc_client_rekey_timer);

#endif /* CLIENT_CONNECT_H */
