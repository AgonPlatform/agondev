#include <assert.h>
#include <stdio.h>
#include <string.h>

int agon_fputs(const char *str, FILE *stream);

static void check_output(const char *input)
{
    FILE *stream = tmpfile();
    assert(stream != NULL);
    assert(agon_fputs(input, stream) >= 0);
    assert(fflush(stream) == 0);
    assert(fseek(stream, 0, SEEK_SET) == 0);

    char actual[32];
    size_t size = fread(actual, 1, sizeof(actual), stream);
    assert(!ferror(stream));
    assert(size == strlen(input));
    assert(memcmp(actual, input, size) == 0);
    assert(fclose(stream) == 0);
}

int main(int argc, char **argv)
{
    assert(argc > 0);
    check_output("");
    check_output("Agon");
    check_output("Result file example\n");

    FILE *readonly = fopen(argv[0], "rb");
    assert(readonly != NULL);
    assert(agon_fputs("Agon", readonly) == EOF);
    assert(ferror(readonly));
    assert(fclose(readonly) == 0);

    puts("fputs host tests passed");
    return 0;
}
