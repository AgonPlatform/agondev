/* fflush
   ------

Output streams are unbuffered. As an agondev extension, flushing console
input discards the unread edited line and pushback, without reading more keys.
Regular-file input retains the existing pushback-discard behavior.
*/

#include <stdio.h>
#include "console_input.h"

int fflush(FILE *stream)
{
    /* fflush(NULL) means all output streams; none are buffered here. */
    if (stream == NULL)
        return 0;

    if (stream->fhandle == FH_STDIN)
        __console_discard();

    stream->unget_char = 0;
    stream->has_unget_char = 0;
    return 0;
}
