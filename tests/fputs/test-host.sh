#!/bin/sh
set -eu
cd "$(dirname "$0")"
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT HUP INT TERM

# Keep the host stdio implementation for streams and fputc.
${CC:-cc} -std=c99 -Wall -Wextra -Werror -Dfputs=agon_fputs \
    -c ../../src/lib/libc/fputs.c -o "$tmp/fputs.o"
${CC:-cc} -std=c99 -Wall -Wextra -Werror main.c "$tmp/fputs.o" -o "$tmp/test"
"$tmp/test"
