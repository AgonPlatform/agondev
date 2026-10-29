/* fgetc
   -----

The C library function int fgetc(FILE *stream) gets the next character (an unsigned char) from
the specified stream and advances the position indicator for the stream.
*/

#include <stdio.h>
#include <agon/mos.h>
#include "console_input.h"

/*
 * Read one physical byte without losing the distinction between a valid
 * NUL byte, end-of-file, and a non-EOF read failure.
 *
 * Return values:
 *   1  one byte was read and stored in *value
 *   0  physical end-of-file
 *  -1  read error
 */
static int read_physical_byte(FILE *stream, unsigned char *value)
{
    if (mos_fread(stream->fhandle, (char *)value, 1) == 1)
        return 1;

    return mos_feof(stream->fhandle) ? 0 : -1;
}

int fgetc(FILE *stream)
{
    unsigned char value;
    int status;

    if (stream == NULL || stream == stdout || stream == stderr)
        return EOF;

    /* Logical pushback has priority over the physical MOS file position. */
    if (stream->has_unget_char)
    {
        stream->has_unget_char = 0;
        stream->eof = 0;
        return (unsigned char)stream->unget_char;
    }

    if (stream->fhandle == FH_STDIN)
        return __console_getc(stream);

    status = read_physical_byte(stream, &value);
    if (status <= 0)
    {
        if (status == 0)
            stream->eof = 1;
        else
            stream->err = 1;

        return EOF;
    }

    if (stream->text_mode && value == '\r')
    {
        unsigned char next;

        status = read_physical_byte(stream, &next);

        if (status == 1)
        {
            if (next == '\n')
                return '\n';

            /* Lone CR: preserve the look-ahead byte for the next read. */
            stream->unget_char = next;
            stream->has_unget_char = 1;
            return '\r';
        }

        /* The CR itself was read successfully and must still be returned. */
        if (status < 0)
            stream->err = 1;

        return '\r';
    }

    return value;
}
