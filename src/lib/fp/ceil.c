/************************************************************************/
/*									*/
/*			Copyright (C) 2000-2008 Zilog, Inc.		*/
/*									*/
/************************************************************************/
#include <math.h>

double ceil(double d)
{
	return(-floor(-d));
}

float ceilf(float) __attribute__((alias("ceil")));
