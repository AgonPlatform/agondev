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

int vprintf(const char *format, va_list vlist)
{
  return npf_vpprintf(npf_putc_std, NULL, format, vlist);
}

int printf(char const *format, ...) {
  va_list val;
  va_start(val, format);
  int const rv = vprintf(format, val);
  va_end(val);
  return rv;
}

int fprintf(FILE *stream, char const *format, ...) {
  va_list val;
  va_start(val, format);
  int const rv = vfprintf(stream, format, val);
  va_end(val);
  return rv;
}

int vfprintf(FILE *stream, const char *format, va_list vlist)
{
  return npf_vpprintf(npf_fputc_std, (void *)stream, format, vlist);
}
/*
int vsnprintf(char * NPF_RESTRICT buffer, size_t bufsz, char const * NPF_RESTRICT format, va_list vlist) {
  npf_bufputc_ctx_t bufputc_ctx;
  bufputc_ctx.dst = buffer;
  bufputc_ctx.len = bufsz;
  bufputc_ctx.cur = 0;

  npf_putc const pc = buffer ? npf_bufputc : npf_bufputc_nop;
  int const n = npf_vpprintf(pc, &bufputc_ctx, format, vlist);

  if (buffer && bufsz) {
#ifdef NANOPRINTF_SNPRINTF_SAFE_EMPTY_STRING_ON_OVERFLOW
    buffer[(n < 0 || (unsigned)n >= bufsz) ? 0 : n] = '\0';
#else
    buffer[n < 0 ? 0 : NPF_MIN((unsigned)n, bufsz - 1)] = '\0';
#endif
  }

  return n;
}
*/
int vsnprintf(char* buffer, size_t count, const char *__restrict format, va_list va) {
  return npf_vsnprintf(buffer, count, format, va);
}

int snprintf(char *buffer, size_t bufsz, const char *format, ...) {
  va_list val;
  va_start(val, format);
  int const rv = npf_vsnprintf(buffer, bufsz, format, val);
  va_end(val);
  return rv;
}

int vsprintf(char *buffer, const char *format, va_list vlist)
{
  return npf_vsnprintf(buffer, (size_t)INT_MAX, format, vlist);
}

int sprintf(char *buffer, const char *format, ...)
{
  va_list va;
  va_start(va, format);
  const int ret = npf_vsnprintf(buffer, (size_t)INT_MAX, format, va);
  va_end(va);
  return ret;
}

