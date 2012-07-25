/*

  silcnet_i.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2005 - 2006 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCNET_I_H
#define SILCNET_I_H

#ifndef SILCNET_H
#error "Do not include this header directly"
#endif

/* Net listener context */
struct SilcNetListenerStruct {
  SilcSchedule schedule;
  SilcNetCallback callback;
  void *context;
  SilcSocket *socks;
  unsigned int socks_count   : 30;
  unsigned int require_fqdn  : 1;
  unsigned int lookup        : 1;
};

#endif /* SILCNET_I_H */
