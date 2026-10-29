#include <stdio.h>
#include <string.h>

int main(void)
{
    int first, second;
    char line[80];
    printf("Console line-input test\n");
    printf("Press Shift alone, then enter 12 34 (edit before Return): ");
    if (scanf("%d", &first) != 1 || scanf("%d", &second) != 1 ||
        first != 12 || second != 34 || getchar() != '\n')
        return 1;
    printf("Enter abcdef: ");
    if (getchar() != 'a' || fgets(line, sizeof line, stdin) == NULL ||
        strcmp(line, "bcdef\n"))
        return 2;
    printf("Enter discard: ");
    if (getchar() != 'd') return 3;
    fflush(stdin);
    printf("Enter fresh (previous suffix must be discarded): ");
    if (fgets(line, sizeof line, stdin) == NULL || strcmp(line, "fresh\n"))
        return 4;
    printf("Press Escape: ");
    if (getchar() != EOF || !feof(stdin)) return 5;
    clearerr(stdin);
    printf("Enter ok: ");
    if (gets_s(line, sizeof line) == NULL || strcmp(line, "ok")) return 6;
    printf("PASS\n");
    return 0;
}
