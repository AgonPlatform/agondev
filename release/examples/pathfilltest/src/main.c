#include <agon/vdp_vdu.h>

int main(void) {
  vdp_clear_screen();
  vdp_set_pixel_coordinates();

  int path[] = {0,0,639,0,639,479,539,479,539,100,320,100,320,200,220,200,220,100,50,100,50,50,0,50,0,0};
  vdp_fill_path(path, sizeof(path));
  return 0; 
}
