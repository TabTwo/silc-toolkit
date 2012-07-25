/*

  silcstream.c

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

#include "silc.h"

typedef struct {
  SilcStreamOps *ops;
} *SilcStreamHeader;

int silc_stream_read(SilcStream stream, unsigned char *buf,
		     SilcUInt32 buf_len)
{
  SilcStreamHeader h = stream;
  return h->ops->read(stream, buf, buf_len);
}

int silc_stream_write(SilcStream stream, const unsigned char *data,
		      SilcUInt32 data_len)
{
  SilcStreamHeader h = stream;
  return h->ops->write(stream, data, data_len);
}

SilcBool silc_stream_close(SilcStream stream)
{
  SilcStreamHeader h = stream;
  return h->ops->close(stream);
}

void silc_stream_destroy(SilcStream stream)
{
  SilcStreamHeader h = stream;
  h->ops->destroy(stream);
}

SilcBool silc_stream_set_notifier(SilcStream stream, SilcSchedule schedule,
				  SilcStreamNotifier notifier, void *context)
{
  SilcStreamHeader h = stream;
  return h->ops->notifier(stream, schedule, notifier, context);
}

SilcSchedule silc_stream_get_schedule(SilcStream stream)
{
  SilcStreamHeader h = stream;
  return h->ops->get_schedule(stream);
}
