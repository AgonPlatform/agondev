#ifndef TEST_MOS_H
#define TEST_MOS_H
#include <stddef.h>
#include <stdint.h>
unsigned char mos_editline(char *, unsigned int, unsigned char);
size_t mos_fread(unsigned char, char *, size_t);
int mos_feof(unsigned char);
#endif
