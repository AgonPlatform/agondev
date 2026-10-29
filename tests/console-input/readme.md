# Line-buffered console input

`getchar`, `fgetc(stdin)`, `scanf`, `fscanf(stdin, ...)`, `fgets`, `gets_s`,
and `fread` share one console line buffer. MOS `mos_editline` handles keyboard
layout, modifiers, cursor movement, deletion, and echo. Characters reach stdio
only after Return; one LF is appended. An empty line therefore supplies LF.
No FILE layout changes are required. `getch` remains raw and immediate.

The console accepts at most 254 characters per edited line. MOS enforces the
limit while editing; this is not an arbitrarily long terminal input queue.
Echo goes to the physical console, including the final CR/LF, even when stdout
is redirected, matching the MOS editor's own echo. EOF and binary NUL bytes
from redirected files retain their file semantics.

Escape cancels the edited line and sets the console stream's EOF indicator.
Further reads return EOF until `clearerr(stdin)` or successful `ungetc` clears
it. Keyboard editing/control keys are interpreted by MOS; in particular Ctrl-C
is no longer intercepted immediately by the former character-at-a-time scanf
and gets_s loops. Use raw `getch` for immediate keyboard interaction. Mixing
raw reads with stdio bypasses any characters still held in the stdio buffer.

As an agondev extension (not portable ISO C), `fflush(stdin)` discards the
unread part of the completed console line and its pushed-back character. It
neither invokes the editor nor drains future keyboard events, and does not
clear EOF/error indicators. `fflush(NULL)` remains output-only. Flushing file
input retains the previous behavior of discarding its pushback character.
`freopen` discards old console input before redirecting stdin. `fclose(stdin)`
still rejects the console stream, so a failed close does not discard input.

Scanf lookahead now goes back to the real input stream between calls. For
example, after `scanf("%d", &n)` reads a number followed by Return, `getchar()`
reads the remaining LF. Use a line read or `fflush(stdin)` when discarding that
remainder is intended. Invalid numeric input remains unread until consumed or
flushed. Existing scanf parsing limitations beyond console buffering are not
addressed here.

## Automated host checks

Run `sh tests/console-input/test-host.sh` from the repository root. This compiles
the production C implementations against a mocked MOS editor and file reader,
with AddressSanitizer and UndefinedBehaviorSanitizer. The host shim substitutes
for the two small target getchar assembly wrappers. It tests mixed input APIs,
lookahead after successful/failed scans, flush behavior, NUL pushback, blank and
maximum-length lines, truncation, Escape, EOF recovery, and file redirection.
The MOS keyboard editor itself needs the interactive check below.

## Interactive check on hardware or emulator

Build the library first with `make release/lib/libagon.a`, then build this test
with `make -C tests/console-input`. Follow the prompts; Shift alone must not
submit a line and editing must finish before any scan returns. The final output
must be PASS. Repeat with a clean test build and `LDHAS_ARG_PROCESSING=1` to
exercise the alternate getchar symbol. Test French keyboard digits using the
configured French layout. The raw `getch` diagnostic should still report Shift
as zero; its behavior deliberately has not changed.
