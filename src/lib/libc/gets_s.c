/* Read one logical line; MOS already handles console editing and echo. */
#include <stdio.h>
#include <stdlib.h>

char *gets_s(char *__restrict str, rsize_t n)
{
    rsize_t used = 0;
    int c, overflow = 0;

    if (str == NULL || n == 0)
        return NULL;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (c == '\x03' && stdin->fhandle == FH_STDIN)
            exit(EXIT_FAILURE);
        if (used < n - 1)
            str[used++] = (char)c;
        else
            overflow = 1;
    }
    str[used] = '\0';
    if (overflow || (c == EOF && (used == 0 || ferror(stdin))))
        return NULL;
    return str;
}
