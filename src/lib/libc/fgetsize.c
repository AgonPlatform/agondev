#include <stdio.h>
#include <agon/mos.h>
#include <stdint.h>

unsigned int fgetsize(FILE *file) {

    if(file == NULL) return 0;

    unsigned char fhandle = file->fhandle;
    FIL *fileobject = mos_getfil(fhandle);
    return (fileobject->obj).objsize;
}
