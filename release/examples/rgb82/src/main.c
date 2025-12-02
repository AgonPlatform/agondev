/*
RGBA8888 to RGBA2222 file converter
Richard Turnnidge Nov. 2025

A useful tool for use on your Agon or in the emulator for making smaller RGBA2222 format files.
These are a smaller format for use when loading graphics into your games or applications, but still use all 64 colours available on the Agon.

Opens all files in current working path
Converts from RGBA888 to RGBA2222 format with closest match to Agon palette

Currently very little error checking!
It does check if file is divisble by 4.
It does make sure it is not a hidden file (first char is a .)
Otherwise, assumption is a correct file is used.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <agon/vdp.h>

// for file handling
DIR handle;
FILINFO file;

// some global variables used
char fname[32];
char thisfile[32];
char outputName[64];
char dirpath[256];

// functions in this file
void doExit(void);
void process(char *afile);
uint8_t getMatch(uint8_t aByte);
uint24_t findSize(char file_name[]);

// now the main program
int main(void) {

  vdp_clear_screen();               // clear screen
  printf("RGBA888 to RGBA2222 Converter\n\n");

  // check we can read CWD
  if(ffs_getcwd(dirpath, 256) != 0) {
    printf("Unable to get current directory\r\n");
    return 0;
  }

  // this is only really needed if we add a sub-directory to read from
  if(ffs_dopen(&handle, dirpath) != 0) {
    printf("Unable to open '%s'\r\n", dirpath);
    return 0;
  }

  uint24_t fSize = 0;
  uint8_t fileCount=0;

  while(1) {                                         // read through all entries in directory
    uint8_t result = ffs_dread(&handle, &file); 
    if((result != 0) || (strlen(file.fname) == 0)){
      break;                                         // end of list, so exit
    } 
    strcpy(thisfile, file.fname);                    // get file name
    fSize = findSize(thisfile);                      // get file size to check

    if(file.fattrib & 0x10) {
      printf("Ignore %s folder\r\n", file.fname);    // dir not a file
    }
    else if (thisfile[0] == '.') {
      printf("Invavid file: %s\r\n", thisfile);      // hidden file
    } else if(fSize % 4 != 0){
      printf("Wrong format: %s\r\n", thisfile);      // not divisible by 4, so not valid format
    } else {
      process(thisfile);                             // probably a valid file, so process it
      fileCount++;
    }
  }
  printf("Converted %d files\n", fileCount);         // show number of file converted
  doExit();

}

// -----------------------------------------------------------------------
//
// process files here
//
// -----------------------------------------------------------------------

void process(char *srcFile){

  uint8_t byte1;
  uint8_t byte2;
  uint8_t byte3;
  uint8_t byte4;
  uint8_t bytecount;
  uint8_t mydata;
  uint8_t fBuffer[1];

  printf("Converting: %s  \n", srcFile);
  strcpy(outputName , srcFile);


  for(uint8_t i=0;i<strlen(outputName);i++) {           // strip extension
      if(outputName[i] == '.') {
          outputName[i]='\0';
          break;
      }
  }
  strcat(outputName , ".RGB2");                         // add new extension
    
  FILE *file = fopen( srcFile, "rb" );
  FILE *outfile = fopen( outputName, "wb" );

  while  ( ( fread(fBuffer, 1,1,file ) ) > 0 )
      {

        byte1 = getMatch( fBuffer[0]);            // no shift, either 0, 1, 2 or 3
        
        fread(fBuffer, 1,1,file);
        byte2 = getMatch( fBuffer[0]);
        byte2 = byte2 <<2;                        // shift left 2
        
        fread(fBuffer, 1,1,file );
        byte3 = getMatch( fBuffer[0]);
        byte3 = byte3 <<4;                        // shift left 4
        
        fread(fBuffer, 1,1,file );
        byte4 = getMatch( fBuffer[0]);
        byte4 = byte4 <<6;                        // shift left 6
        
        mydata = byte1 | byte2 | byte3 | byte4;
        fwrite(&mydata, 1,1, outfile);
      }

  fclose( file );
  fclose( outfile );

}

uint8_t getMatch(uint8_t aByte){
    // get closest match for Agon palette - either: 00h, 55h, AAh, FFh
    // take byte and return either 0, 1, 2 or 3
    
    uint8_t returnVal;
    
    if ( aByte <= 42) {
        returnVal = 0;
    } else if ( aByte <= 128) {
        returnVal = 1;
    } else if ( aByte <= 212) {
        returnVal = 2;
    } else {
        returnVal = 3;
    }
    
    return returnVal;
}

// -----------------------------------------------------------------------

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

// -----------------------------------------------------------------------
//
// exit
//
// -----------------------------------------------------------------------

void doExit(void){
  //vdp_clear_screen();
  vdp_cursor_enable(true);
  exit(0);
}

// -----------------------------------------------------------------------
