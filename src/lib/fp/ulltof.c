#include <limits.h>
#include <math.h>
#include <stdint.h>

float ulltof(unsigned long long x)
{
    uint8_t exponent = x ? __builtin_clzll(x) : ULLONG_WIDTH;
    if (exponent >= ULLONG_WIDTH - ULONG_WIDTH) return (unsigned long)x;
    exponent = ULLONG_WIDTH - ULONG_WIDTH - exponent;
    return ldexpf((unsigned long)(x >> exponent), exponent);
}
