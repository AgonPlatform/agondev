#define NANOPRINTF_IMPLEMENTATION
#include <stdio.h>
#include <stdarg.h>
#include "nanoprintf.h"

static void npf_putc_std(int c, void *ctx) {
  (void)ctx;
  putchar(c);
}

static void npf_fputc_std(int c, void *ctx) {
  fputc(c, (FILE *)ctx);
}

int vprintf(const char *format, va_list vlist) {
  return npf_vpprintf(npf_putc_std, NULL, format, vlist);
}

int printf(const char *format, ...) {
  va_list va;
  va_start(va, format);
  const int rv = vprintf(format, va);
  va_end(va);
  return rv;
}

int fprintf(FILE *stream, const char *format, ...) {
  va_list va;
  va_start(va, format);
  const int rv = vfprintf(stream, format, va);
  va_end(va);
  return rv;
}

int vfprintf(FILE *stream, const char *format, va_list vlist) {
  return npf_vpprintf(npf_fputc_std, (void *)stream, format, vlist);
}

int vsprintf(char *buffer, const char *format, va_list vlist) {
  return npf_vsnprintf(buffer, (size_t)INT_MAX, format, vlist);
}

int vsnprintf(char* buffer, size_t count, const char *__restrict format, va_list va) {
  return npf_vsnprintf(buffer, count, format, va);
}

int sprintf(char *buffer, const char *format, ...) {
  va_list va;
  va_start(va, format);
  const int ret = npf_vsnprintf(buffer, (size_t)INT_MAX, format, va);
  va_end(va);
  return ret;
}

int snprintf(char *buffer, size_t bufsz, const char *format, ...) {
  va_list va;
  va_start(va, format);
  const int rv = npf_vsnprintf(buffer, bufsz, format, va);
  va_end(va);
  return rv;
}

