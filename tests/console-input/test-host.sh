#!/bin/sh
set -eu
cd "$(dirname "$0")"
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT HUP INT TERM
lib=../../src/lib/libc
# Rename exported stdio symbols so host libc and sanitizers keep their own ABI.
renames=''
for name in stdin stdout stderr fgetc getchar putchar putch ungetc fflush ferror clearerr fgets gets_s fread scanf fscanf fopen freopen fclose; do
    renames="$renames -D$name=agon_$name"
done
${CC:-cc} -std=c99 -fno-builtin -g -fsanitize=address,undefined \
    $renames -Ihost -I"$lib" host/main.c \
    "$lib"/freopen.c "$lib"/console_input.c "$lib"/fgetc.c "$lib"/fflush.c \
    "$lib"/ungetc.c "$lib"/fgets.c "$lib"/gets_s.c "$lib"/fread.c \
    "$lib"/clearerr.c "$lib"/ferror.c "$lib"/scanf.c "$lib"/fscanf.c \
    "$lib"/uscan.c "$lib"/usscan.c -o "$tmp/test"
"$tmp/test"
echo 'Console input host tests passed'
