#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

volatile SYSVAR *vdp_vdu_init( void ) {
	return sys_vars;
}
