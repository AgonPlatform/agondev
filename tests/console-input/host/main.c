#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "console_input.h"

FILE stdin[1] = {{FH_STDIN}}, stdout[1] = {{FH_STDOUT}}, stderr[1] = {{FH_STDERR}};
static const char *input;
static unsigned int edits, echoes, endkey = 13;
static const unsigned char *disk;
static size_t disk_left;

unsigned char mos_editline(char *s, unsigned int n, unsigned char clear)
{
    assert(clear == 1 && n == 255);
    assert(strlen(input) < n);
    strcpy(s, input);
    ++edits;
    return endkey;
}
int putch(int c) { assert(c == '\r' || c == '\n'); ++echoes; return c; }
int putchar(int c) { (void)c; assert(0); return c; } /* no duplicate echo */
int getchar(void) { return fgetc(stdin); } /* target assembly wrapper */
size_t mos_fread(unsigned char h, char *s, size_t n)
{
    assert(h == 1);
    if (n > disk_left) n = disk_left;
    memcpy(s, disk, n); disk += n; disk_left -= n;
    return n;
}
FILE *fopen(const char *path, const char *mode)
{
    static FILE file;
    (void)mode;
    if (!strcmp(path, "missing")) return NULL;
    memset(&file, 0, sizeof file); file.fhandle = 1;
    return &file;
}
int fclose(FILE *f) { (void)f; assert(0); return EOF; }
int mos_feof(unsigned char h) { assert(h == 1); return disk_left == 0; }
static void reset(const char *s)
{
    __console_discard();
    memset(stdin, 0, sizeof *stdin);
    stdin->fhandle = FH_STDIN;
    input = s; endkey = 13; edits = echoes = 0;
}
int main(void)
{
    char s[256]; int a, b;
    reset("123");
    assert(getchar() == '1');
    assert(fgetc(stdin) == '2');
    assert(fgets(s, sizeof s, stdin) == s && !strcmp(s, "3\n"));
    assert(edits == 1 && echoes == 2);

    reset("12 34");
    assert(scanf("%d", &a) == 1 && a == 12);
    assert(getchar() == ' '); /* lookahead survives scanf */
    assert(fscanf(stdin, "%d", &b) == 1 && b == 34);
    assert(getchar() == '\n' && edits == 1);

    reset("bad"); a = 99;
    assert(scanf("%d", &a) == 0 && a == 99);
    assert(getchar() == 'b'); /* failed conversion preserves offending byte */
    assert(fflush(stdin) == 0);
    input = "42";
    assert(scanf("%d", &a) == 1 && a == 42);
    assert(fflush(stdin) == 0);
    input = "";
    assert(getchar() == '\n');

    reset("abcd");
    assert(getchar() == 'a');
    assert(ungetc(0, stdin) == 0);
    assert(getchar() == 0 && getchar() == 'b');
    assert(ungetc('X', stdin) == 'X');
    assert(fflush(NULL) == 0); /* output-only flush leaves input alone */
    assert(getchar() == 'X' && getchar() == 'c');
    assert(fflush(stdin) == 0);
    input = "new";
    assert(fread(s, 1, 4, stdin) == 4 && !memcmp(s, "new\n", 4));

    reset("discard on Escape"); endkey = 27;
    assert(getchar() == EOF && stdin->eof && edits == 1);
    assert(getchar() == EOF && edits == 1);
    assert(gets_s(s, sizeof s) == NULL);
    clearerr(stdin); endkey = 13; input = "ok";
    assert(gets_s(s, sizeof s) == s && !strcmp(s, "ok"));

    reset("too long");
    assert(gets_s(s, 3) == NULL && !strcmp(s, "to"));
    input = "ok";
    assert(gets_s(s, sizeof s) == s && !strcmp(s, "ok"));
    assert(gets_s(NULL, 3) == NULL && gets_s(s, 0) == NULL);

    memset(s, '7', 254); s[254] = 0;
    reset(s);
    for (a = 0; a < 254; ++a) assert(getchar() == '7');
    assert(getchar() == '\n' && edits == 1);

    /* Redirect stdin after leaving an unread console suffix. */
    reset("leftover"); assert(getchar() == 'l');
    assert(freopen("file", "rb", stdin) == stdin);
    { static const unsigned char bytes[] = {'A', 0, '\r', '\n', 'B'};
      disk = bytes; disk_left = sizeof bytes;
      assert(getchar() == 'A' && getchar() == 0);
      assert(getchar() == '\r' && getchar() == '\n' && getchar() == 'B');
      assert(getchar() == EOF && stdin->eof && edits == 1);
    }
    /* freopen discarded the old console suffix, including on open failure. */
    stdin->fhandle = FH_STDIN; clearerr(stdin); input = "fresh";
    assert(getchar() == 'f');
    assert(freopen("missing", "r", stdin) == NULL);
    input = "next";
    assert(getchar() == 'n');
    return 0;
}
