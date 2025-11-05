#include <math.h>

double exp2(double x)
{
    return expf(x * (float)M_LOG2E);
}

float exp2f(float) __attribute__((alias("exp2")));
