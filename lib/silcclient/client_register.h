/*

  client_register.h

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

#ifndef CLIENT_REGISTER_H
#define CLIENT_REGISTER_H

SILC_FSM_STATE(silc_client_new_id);
SILC_FSM_STATE(silc_client_st_register);
SILC_FSM_STATE(silc_client_st_register_complete);
SILC_FSM_STATE(silc_client_st_register_error);
SILC_FSM_STATE(silc_client_st_resume);
SILC_FSM_STATE(silc_client_st_resume_resolve_channels);
SILC_FSM_STATE(silc_client_st_resume_resolve_cmodes);
SILC_FSM_STATE(silc_client_st_resume_completed);
SILC_FSM_STATE(silc_client_st_resume_error);

SilcBuffer silc_client_get_detach_data(SilcClient client,
				       SilcClientConnection conn);

#endif /* CLIENT_REGISTER_H */
