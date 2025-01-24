#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#define MAXFILENAMELENGTH (0x40 - 4 - 1)

int main(int argc, char **argv) {
    FILE *fp;
    char header[4] = {0};

    if((argc == 1) || (argc > 3)) {
        printf("Usage:\nsetprogname <filename> [prog_name]\n\nsets the MOS programname of the binary the filename or optional prog_name argument\n");
        exit(-1);
    }

   fp = fopen(argv[1], "r+b"); 

   if(!fp) {
       printf("Cannot open %s\n", argv[1]);
       exit(-1);
   }

   int res;
   res = fseek(fp, 0x40, SEEK_SET);
   if(res != 0) {
       printf("Error\n");
       fclose(fp);
       exit(-1);
   }
   res = fread(header, 1, 3, fp);
   if(res != 3) {
       printf("Error reading file\n");
       fclose(fp);
       exit(-1);
   }
   if(strcmp(header, "MOS") != 0) {
       printf("%s has no valid MOS header\nAbort\n", argv[1]);
       fclose(fp);
       exit(-1);
   }
   printf("Valid MOS header found in %s\n", argv[1]);

   fseek(fp, 0x04, SEEK_SET);

   char *filebasename = (argc == 3)?argv[2]:basename(argv[1]);
   if(strlen(filebasename) > MAXFILENAMELENGTH) {
       printf("Programname '%s' doesn't fit MOS header\nAbort\n", filebasename);
       exit(-1);
   }

   printf("Writing '%s' as prog_name\n", filebasename);
   fprintf(fp, "%s", filebasename);
   for(size_t n = 0; n < (MAXFILENAMELENGTH - strlen(filebasename)) + 1; n++) fputc(0, fp);
   fclose(fp);
   exit(0);
}
