#!/bin/sh

file="$1"
tmp="$(mktemp)"

{
    printf '#ifdef __cplusplus\n'
    printf 'extern "C" {\n'
    printf '#endif\n\n'

    cat "$file"

    printf '\n#ifdef __cplusplus\n'
    printf '}\n'
    printf '#endif\n'
} > "$tmp"

mv "$tmp" "$file"
