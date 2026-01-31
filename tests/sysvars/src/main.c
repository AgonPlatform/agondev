#include <stdio.h>
#include <stdint.h>
#include <agon/mos.h>
#include <agon/vdp.h>

int main( void ) {
  vdp_vdu_init();
  uint8_t *sv = mos_sysvars();
  uint8_t *sv2 = (uint8_t *)sys_vars;
  uint8_t code = vdp_return_ascii_code_at_position(0,0);
  printf("Sysvars is at 0x%x / 0x%x\n", (unsigned int)sv, (unsigned int)sv2);
  printf("Code is 0x%x\n", code);
  return 0;
}
