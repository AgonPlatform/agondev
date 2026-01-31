#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_return_text_cursor_position = { 23, 0, 0x82 }; 

void vdp_return_text_cursor_position( uint8_t *return_x, uint8_t *return_y )
{
	sys_vars->vdp_pflags = 0;

	VDP_PUTS( vdu_return_text_cursor_position );
	while ( !(sys_vars->vdp_pflags & vdp_pflag_cursor) );

	if ( return_x) *return_x = sys_vars->cursorX;
	if ( return_y) *return_y = sys_vars->cursorY;
}
