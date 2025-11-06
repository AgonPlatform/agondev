#include <agon/vdp.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern char __heapbot;  // Declares the symbol as an external char
extern char __heaptop;  // Declares the symbol as an external char
extern unsigned int _sbrkbase;
void *heap_start = (void *)&__heapbot;
void *heap_end = (void *)&__heaptop;

const int KBblocksize = 16;

int main(void) {
  void *p;

  vdp_clear_screen();
  printf("Requesting %d KB blocks\n\n",(KBblocksize));
  printf("                 old sbrkbase 0x%06X\n", _sbrkbase);
  for(int i = 1; 1 ; i++) { // forever
    p = malloc(KBblocksize*1024); // 32KB request
    if(p == NULL) {
      printf("Malloc error\n");
      return 0;
    }
    unsigned int leftKB = ((unsigned int)heap_end - _sbrkbase)/1024;
    printf("Block 0x%06X - new sbrkbase 0x%06X - heaptop 0x%06X/Req %3dKB/%3d left\n", (unsigned int)(p), _sbrkbase, (unsigned int)heap_end, i * (KBblocksize), leftKB);
  }
  return 0; 
}
