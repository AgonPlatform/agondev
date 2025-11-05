#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern volatile SYSVAR *sys_vars;

// Shared command variables
VDU_A_B_CMD_n vdu_sprite_select = { 23, 27, 4, 0 };
VDU_A_B_CMD vdu_sprite_clear = { 23, 27, 5 };
VDU_A_B_CMD_n vdu_sprite_add_bitmap = { 23, 27, 6, 0 };
VDU_A_B_CMD_n vdu_sprite_activate = { 23, 27, 7, 0 };
VDU_ADV_CMD_W    vdu_adv_write_block  = { 23, 0, 0xA0, 0xFA00, 0, 0 };
VDU_ADV_CMD      vdu_adv_call_buffer  = { 23, 0, 0xA0, 0xFA00, 1 };
VDU_ADV_CMD_B_W_W vdu_adv_call_conditional = { 23, 0, 0xA0, 0xFA00, 6, 0, 0, 0 };
VDU_ADV_CMD_WW   vdu_adv_jump_offset  = { 23, 0, 0xA0, 0xFA00, 9, 0 };
VDU_ADV_CMD_WW_W vdu_adv_jump_offset_block = { 23, 0, 0xA0, 0xFA00, 9, 0, 0 };
VDU_AUDIO_CMD_B_W vdu_audio_b_w = { 23, 0, 0x85, 0, 0, 0, 0 };
VDU_AUDIO_CMD_B_W_W vdu_audio_b_w_w = { 23, 0, 0x85, 0, 0, 0, 0, 0 };
VDU_AUDIO_CMD vdu_audio = { 23, 0, 0x85, 0, 0 };
VDU_AUDIO_CMD_W vdu_audio_w = { 23, 0, 0x85, 0, 0, 0 };
VDU_AUDIO_CMD_B_WW vdu_audio_b_ww = { 23, 0, 0x85, 0, 0, 0, 0 };
VDU_AUDIO_CMD_B_W_WW vdu_audio_b_w_ww = { 23, 0, 0x85, 0, 0, 0, 0, 0 };
VDU_AUDIO_CMD_WW vdu_audio_ww = { 23, 0, 0x85, 0, 0, 0 };
VDU_AUDIO_CMD_B_B vdu_audio_b_b = { 23, 0, 0x85, 0, 0, 0, 0 };
VDU_AUDIO_CMD_B vdu_audio_b = { 23, 0, 0x85, 0, 0, 0 };