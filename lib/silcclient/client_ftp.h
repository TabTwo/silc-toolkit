/*

  client_ftp.h

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

#ifndef CLIENT_FTP_H
#define CLIENT_FTP_H

SILC_FSM_STATE(silc_client_ftp);
void silc_client_ftp_free_sessions(SilcClient client);
void silc_client_ftp_session_free_client(SilcClient client,
					 SilcClientEntry client_entry);

#endif /* CLIENT_FTP_H */