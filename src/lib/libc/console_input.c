/* MOS edits and echoes a whole line before stdio consumes it. */
#include <stdio.h>
#include <string.h>
#include <agon/mos.h>
#include "console_input.h"

/* MOS reserves a byte for NUL; reserve another for the stdio newline. */
static char line[256];
static unsigned int next, used;

void __console_discard(void)
{
    next = used = 0;
}

int __console_getc(FILE *stream)
{
    if (stream->eof)
        return EOF;
    if (next == used)
    {
        __console_discard();
        if (mos_editline(line, sizeof line - 1, 1) == 27)
        {
            putch('\r');
            putch('\n');
            stream->eof = 1;
            return EOF;
        }
        putch('\r');
        putch('\n');
        used = strlen(line);
        line[used++] = '\n';
    }
    return (unsigned char)line[next++];
}
