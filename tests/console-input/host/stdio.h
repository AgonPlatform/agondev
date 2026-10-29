/* Minimal host ABI for testing the production input sources with MOS mocks. */
#ifndef TEST_STDIO_H
#define TEST_STDIO_H
#include <stddef.h>
#include <stdarg.h>
typedef size_t rsize_t;
typedef struct {
    unsigned char fhandle, eof, err, text_mode, unget_char, has_unget_char;
} FILE;
extern FILE stdin[1], stdout[1], stderr[1];
#define EOF (-1)
#define FOPEN_MAX 8
#define FH_STDIN 128
#define FH_STDOUT 129
#define FH_STDERR 130
FILE *fopen(const char *, const char *);
FILE *freopen(const char *, const char *, FILE *);
int fclose(FILE *);
int fgetc(FILE *);
int getchar(void);
int putchar(int);
int putch(int);
int ungetc(int, FILE *);
int fflush(FILE *);
int ferror(FILE *);
void clearerr(FILE *);
char *fgets(char *, int, FILE *);
char *gets_s(char *, rsize_t);
size_t fread(void *, size_t, size_t, FILE *);
int scanf(const char *, ...);
int fscanf(FILE *, const char *, ...);
#endif
