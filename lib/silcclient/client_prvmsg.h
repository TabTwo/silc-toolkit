/*

  client_prvmsg.h

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

#ifndef CLIENT_PRVMSG_H
#define CLIENT_PRVMSG_H

SILC_FSM_STATE(silc_client_private_message);
SILC_FSM_STATE(silc_client_private_message_error);
SILC_FSM_STATE(silc_client_private_message_key);

#endif /* CLIENT_PRVMSG_H */
