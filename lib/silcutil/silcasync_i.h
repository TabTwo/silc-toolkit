/*

  silcasync_i.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2005 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCASYNC_I_H
#define SILCASYNC_I_H

#ifndef SILCASYNC_H
#error "Do not include this header directly"
#endif

/* Async operation context */
struct SilcAsyncOperationObject {
  SilcAsyncOperationAbort abort_cb;
  SilcAsyncOperationPause pause_cb;
  void *context;
  unsigned int allocated  : 1;
};

#endif /* SILCASYNC_I_H */
