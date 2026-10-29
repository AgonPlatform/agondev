/* Internal shared console line state; FILE layout remains unchanged. */
#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H
#include <stdio.h>
int __console_getc(FILE *stream);
void __console_discard(void);
#endif
