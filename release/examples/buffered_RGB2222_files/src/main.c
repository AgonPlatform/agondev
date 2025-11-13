/*
Example of:
  1) using a buffer to store a large RGBA2222 colour bitmap 
  2) load in chunks from file
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include <agon/timer.h>


const uint8_t  screen_mode = 8;
const uint8_t  RGBA2222_format = 1;

const uint16_t bitmapID = 32;
const uint16_t bitmapWidth = 320;
const uint16_t bitmapHeight = 240;
const uint24_t chunkSize = 1024;

uint24_t lenArray = 0;
uint24_t arrayOffset = 0;
uint24_t maxWhileRange = 0;
uint24_t remainingData  = 0;

char fname[]="boat.RGB2";
char buff[1024];

void printtext(void);
uint24_t findSize(char fname[]);

int main(void) {

  vdp_mode(screen_mode);
  vdp_cursor_enable(false);
  vdp_clear_screen();
  vdp_set_pixel_coordinates();

  vdp_adv_clear_buffer(bitmapID);                         // clear the buffer
  lenArray = findSize(fname);                             // get total number of bytes to read
  FILE *fp = fopen(fname, "r");                           // open the RGBA2222 image file

  maxWhileRange = lenArray - chunkSize;                   // range of while loop
  while(arrayOffset < maxWhileRange){                     // loop round sending 'chunkSize' pieces of array data 
    fread(buff, 1,chunkSize,fp);                          // read chunk of data from file
    vdp_adv_write_block_data(bitmapID, chunkSize, buff);  // send chunk into VDP buffer
    arrayOffset += chunkSize;                             // increase count through data
  }
  remainingData  = lenArray - arrayOffset;                // the leftover array data remaining
  fread(buff, 1,remainingData,fp);                        // read last of the data
  vdp_adv_write_block_data(bitmapID, remainingData, buff);// send last data into VDP buffer

  fclose(fp);                                             // close the file

  vdp_adv_consolidate(bitmapID);                          // consolidate all uploaded chunks into single buffer
  vdp_adv_select_bitmap(bitmapID);                        // select bitmap ID

  vdp_adv_bitmap_from_buffer(bitmapWidth, bitmapHeight, RGBA2222_format);    // make a bitmap

  vdp_plot_bitmap(0,0);                                   // plot the bitmap at 0,0

  printtext();

  // loop here
  while(true) {
    if(vdp_getKeyCode() == 114) {       // Rotate
      vdp_waitKeyUp();
      vdp_adv_select_bitmap(bitmapID);
      
      // rotate the data 
      vdp_adv_reverse_block_data( bitmapID, 0, 0, 0 );
      vdp_plot_bitmap(0,0);
      printtext();
    };  
    
    if(vdp_getKeyCode() == 104) {      // flip H axis
      vdp_waitKeyUp();
      vdp_adv_select_bitmap(bitmapID);    

      // flipping data about H axis.
      vdp_adv_reverse_block_data( bitmapID, 3, bitmapWidth, 0 );    
      vdp_plot_bitmap(0,0);
      printtext();
    };   

    if(vdp_getKeyCode() == 118) {       // flip V axis
      vdp_waitKeyUp();
      vdp_adv_select_bitmap(bitmapID);  

      // flipping data about V axis.
      vdp_adv_reverse_block_data( bitmapID, 4, 0, bitmapWidth );    
      vdp_plot_bitmap(0,0);
      printtext();
    };   

    if(vdp_getKeyCode() == 27) break;   // exit if ESC pressed
  }

  vdp_cls();
  vdp_cursor_enable(true);

  return 0;     // exit to MOS
}


void printtext(void){
  vdp_cursor_tab(0, 0);
  printf("AgonDev Colour File Load");
  vdp_cursor_tab(0, 1);
  printf("Press H or V to flip image, R to rotate");
  vdp_cursor_tab(0, 29);
  printf("Press ESC to exit");
}

uint24_t findSize(char file_name[])
{
    FILE* fp = fopen(file_name, "r");         // opening the file in read mode
    if (fp == NULL) {                         // checking if the file exist or not
        printf("File Not Found!\n");
        return -1;                            // rreturn -1 if not exist
    }
    fseek(fp, 0L, SEEK_END);                  // go to end of file
    uint24_t res = ftell(fp);                 // the size of the file
    fclose(fp);                               // close the file

    return res;                               // return size
}