/*

  silcsymbiansocketstream.h

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

#ifndef SILCSYMBIANSOCKETSTREAM_H
#define SILCSYMBIANSOCKETSTREAM_H

#include <e32std.h>
#include <es_sock.h>
#include <in_sock.h>

class SilcSymbianSocketSend;
class SilcSymbianSocketReceive;

/* Symbian Socket context */
typedef struct {
  SilcSymbianSocketSend *send;
  SilcSymbianSocketReceive *receive;
  RSocket *sock;
  RSocketServ *ss;
  SilcSocketStream stream;
  unsigned int eof          : 1;
  unsigned int error        : 1;
  unsigned int would_block  : 1;
} SilcSymbianSocket;

/* Creates symbian socket context.  This will steal the `sock' and `ss'. */
SilcSymbianSocket *silc_create_symbian_socket(RSocket *sock,
					      RSocketServ *ss);

#endif /* SILCSYMBIANSOCKETSTREAM_H */
