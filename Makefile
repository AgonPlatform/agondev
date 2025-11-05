### Environment
OS_NAME = $(shell uname -s | tr A-Z a-z)
ARCH = $(shell uname -m | tr A-Z a-z)

### Directories
OBJTOPDIR=./obj
RELEASEDIR=./release
RELEASEBINDIR=$(RELEASEDIR)/bin
LIBDIRECTORY=$(RELEASEDIR)/lib
TOOLCHAINDIR=./llvm-build
INSTALLDIR=$(TOOLCHAINDIR)/ez80-none-elf
TOOLBINDIR=$(INSTALLDIR)/bin
LLVMSRC=./llvm-project
LLVMBUILDDIR=$(LLVMSRC)/build
SCRIPTDIR=./scripts
TARGETDIR=./agondev

### Tools
CC=$(TOOLBINDIR)/clang
LINKER=$(TOOLBINDIR)/ez80-none-elf-ld
ASM=$(TOOLBINDIR)/ez80-none-elf-as
AR=$(TOOLBINDIR)/ez80-none-elf-ar

### Arguments
CFLAGS=-target ez80-none-elf -Oz -Wa,-march=ez80+full -I ./release/include
OUTFLAG=-o 
LINKERFLAGS= -T linker.conf --oformat binary -o 
ARFLAGS=rcs
ASMFLAGS= -march=ez80+full -I./release/include/

.DEFAULT_GOAL := all

# AGON LIBRARY
AGON=$(LIBDIRECTORY)/libagon.a

# CLANG LIBRARY
CLANG_SRCDIR=./src/lib/libclang
CLANG_OBJDIR=$(OBJTOPDIR)/lib/libclang
CLANG_ASMSRCS=$(wildcard $(CLANG_SRCDIR)/*.src)
CLANG_CSRCS=$(wildcard $(CLANG_SRCDIR)/*.c)
CLANG_ASMOBJS=$(patsubst $(CLANG_SRCDIR)/%.src, $(CLANG_OBJDIR)/%.o, $(CLANG_ASMSRCS))
CLANG_COBJS=$(patsubst $(CLANG_SRCDIR)/%.c, $(CLANG_OBJDIR)/%.o, $(CLANG_CSRCS))
CLANG_OBJS=$(CLANG_ASMOBJS) $(CLANG_COBJS)
CLANG=$(LIBDIRECTORY)/libclang.a

# CRT0 LIBRARY
CRT0_SRCDIR=./src/lib/libcrt0
CRT0_OBJDIR=$(OBJTOPDIR)/lib/libcrt0
CRT0_ASMSRCS=$(wildcard $(CRT0_SRCDIR)/*.src)
CRT0_CSRCS=$(wildcard $(CRT0_SRCDIR)/*.c)
CRT0_ASMOBJS=$(patsubst $(CRT0_SRCDIR)/%.src, $(CRT0_OBJDIR)/%.o, $(CRT0_ASMSRCS))
CRT0_COBJS=$(patsubst $(CRT0_SRCDIR)/%.c, $(CRT0_OBJDIR)/%.o, $(CRT0_CSRCS))
CRT0_OBJS=$(CRT0_ASMOBJS) $(CRT0_COBJS)
CRT0=$(LIBDIRECTORY)/libcrt0.a

# FFS LIBRARY
FFS_SRCDIR=./src/lib/libffs
FFS_OBJDIR=$(OBJTOPDIR)/lib/libffs
FFS_ASMSRCS=$(wildcard $(FFS_SRCDIR)/*.src)
FFS_CSRCS=$(wildcard $(FFS_SRCDIR)/*.c)
FFS_ASMOBJS=$(patsubst $(FFS_SRCDIR)/%.src, $(FFS_OBJDIR)/%.o, $(FFS_ASMSRCS))
FFS_COBJS=$(patsubst $(FFS_SRCDIR)/%.c, $(FFS_OBJDIR)/%.o, $(FFS_CSRCS))
FFS_OBJS=$(FFS_ASMOBJS) $(FFS_COBJS)
FFS=$(LIBDIRECTORY)/libffs.a

# GPIO LIBRARY
GPIO_SRCDIR=./src/lib/libgpio
GPIO_OBJDIR=$(OBJTOPDIR)/lib/libgpio
GPIO_ASMSRCS=$(wildcard $(GPIO_SRCDIR)/*.src)
GPIO_CSRCS=$(wildcard $(GPIO_SRCDIR)/*.c)
GPIO_ASMOBJS=$(patsubst $(GPIO_SRCDIR)/%.src, $(GPIO_OBJDIR)/%.o, $(GPIO_ASMSRCS))
GPIO_COBJS=$(patsubst $(GPIO_SRCDIR)/%.c, $(GPIO_OBJDIR)/%.o, $(GPIO_CSRCS))
GPIO_OBJS=$(GPIO_ASMOBJS) $(GPIO_COBJS)
GPIO=$(LIBDIRECTORY)/libgpio.a

# MATH LIBRARY
MATH_SRCDIR=./src/lib/libm
MATH_OBJDIR=$(OBJTOPDIR)/lib/libm
MATH_ASMSRCS=$(wildcard $(MATH_SRCDIR)/*.src)
MATH_CSRCS=$(wildcard $(MATH_SRCDIR)/*.c)
MATH_ASMOBJS=$(patsubst $(MATH_SRCDIR)/%.src, $(MATH_OBJDIR)/%.o, $(MATH_ASMSRCS))
MATH_COBJS=$(patsubst $(MATH_SRCDIR)/%.c, $(MATH_OBJDIR)/%.o, $(MATH_CSRCS))
MATH_OBJS=$(MATH_ASMOBJS) $(MATH_COBJS)
MATH=$(LIBDIRECTORY)/libm.a

# MOS LIBRARY
MOS_SRCDIR=./src/lib/libmos
MOS_OBJDIR=$(OBJTOPDIR)/lib/libmos
MOS_ASMSRCS=$(wildcard $(MOS_SRCDIR)/*.src)
MOS_CSRCS=$(wildcard $(MOS_SRCDIR)/*.c)
MOS_ASMOBJS=$(patsubst $(MOS_SRCDIR)/%.src, $(MOS_OBJDIR)/%.o, $(MOS_ASMSRCS))
MOS_COBJS=$(patsubst $(MOS_SRCDIR)/%.c, $(MOS_OBJDIR)/%.o, $(MOS_CSRCS))
MOS_OBJS=$(MOS_ASMOBJS) $(MOS_COBJS)
MOS=$(LIBDIRECTORY)/libmos.a

# TIMER LIBRARY
TIMER_SRCDIR=./src/lib/libtimer
TIMER_OBJDIR=$(OBJTOPDIR)/lib/libtimer
TIMER_ASMSRCS=$(wildcard $(TIMER_SRCDIR)/*.src)
TIMER_CSRCS=$(wildcard $(TIMER_SRCDIR)/*.c)
TIMER_ASMOBJS=$(patsubst $(TIMER_SRCDIR)/%.src, $(TIMER_OBJDIR)/%.o, $(TIMER_ASMSRCS))
TIMER_COBJS=$(patsubst $(TIMER_SRCDIR)/%.c, $(TIMER_OBJDIR)/%.o, $(TIMER_CSRCS))
TIMER_OBJS=$(TIMER_ASMOBJS) $(TIMER_COBJS)
TIMER=$(LIBDIRECTORY)/libtimer.a

# VDP LIBRARY
VDP_SRCDIR=./src/lib/libvdp
VDP_OBJDIR=$(OBJTOPDIR)/lib/libvdp
VDP_ASMSRCS=$(wildcard $(VDP_SRCDIR)/*.src)
VDP_CSRCS=$(wildcard $(VDP_SRCDIR)/*.c)
VDP_ASMOBJS=$(patsubst $(VDP_SRCDIR)/%.src, $(VDP_OBJDIR)/%.o, $(VDP_ASMSRCS))
VDP_COBJS=$(patsubst $(VDP_SRCDIR)/%.c, $(VDP_OBJDIR)/%.o, $(VDP_CSRCS))
VDP_OBJS=$(VDP_ASMOBJS) $(VDP_COBJS)
VDP=$(LIBDIRECTORY)/libvdp.a

# LIBC LIBRARY
LIBC_SRCDIR=./src/lib/libc
LIBC_OBJDIR=$(OBJTOPDIR)/lib/libc
LIBC_ASMSRCS=$(wildcard $(LIBC_SRCDIR)/*.src)
LIBC_CSRCS=$(wildcard $(LIBC_SRCDIR)/*.c)
LIBC_ASMOBJS=$(patsubst $(LIBC_SRCDIR)/%.src, $(LIBC_OBJDIR)/%.o, $(LIBC_ASMSRCS))
LIBC_COBJS=$(patsubst $(LIBC_SRCDIR)/%.c, $(LIBC_OBJDIR)/%.o, $(LIBC_CSRCS))
LIBC_OBJS=$(LIBC_ASMOBJS) $(LIBC_COBJS)
LIBC=$(LIBDIRECTORY)/libc.a

# LIBCXX LIBRARY
LIBCXX_SRCDIR=./src/lib/libcxx
LIBCXX_OBJDIR=$(OBJTOPDIR)/lib/libcxx
LIBCXX_ASMSRCS=$(wildcard $(LIBCXX_SRCDIR)/*.src)
LIBCXX_CSRCS=$(wildcard $(LIBCXX_SRCDIR)/*.c)
LIBCXX_ASMOBJS=$(patsubst $(LIBCXX_SRCDIR)/%.src, $(LIBCXX_OBJDIR)/%.o, $(LIBCXX_ASMSRCS))
LIBCXX_COBJS=$(patsubst $(LIBCXX_SRCDIR)/%.c, $(LIBCXX_OBJDIR)/%.o, $(LIBCXX_CSRCS))
LIBCXX_OBJS=$(LIBCXX_ASMOBJS) $(LIBCXX_COBJS)
LIBCXX=$(LIBDIRECTORY)/libcxx.a


# Default rule
libs: libagon libclang libcrt0 libffs libgpio libc libcxx libmath libmos libtimer libvdp
all: $(RELEASEBINDIR) libs
	@echo [ Copying binaries to release/bin ]
	$(shell cp ./llvm-build/ez80-none-elf/bin/ez80-none-elf-* ./release/bin/)
	$(shell strip ./release/bin/*)
	$(shell cp ./llvm-build/ez80-none-elf/bin/clang ./release/bin/ez80-none-elf-clang)
	$(shell strip ./release/bin/ez80-none-elf-clang)
	$(shell cp ./dist/hexload-send ./release/bin/) 

	@echo [ Making agondev tools ]
	$(shell cd src/tools/agondev-setname;make clean;make;cp bin/* ../../../release/bin;make clean)
	$(shell cd src/tools/agondev-config;make clean;make;cp bin/* ../../../release/bin;make clean)

	@echo [ Creating TAR binary for release ]
	@rm -rf $(TARGETDIR)
	@mkdir $(TARGETDIR)
	@cp -R $(RELEASEDIR)/* $(TARGETDIR)/
	@tar -zcvf agondev-$(OS_NAME)_$(ARCH).tar.gz $(TARGETDIR) > /dev/null 2>&1
	@rm -rf $(TARGETDIR)
	@echo [ Done ]
# Targets
libagon: libclang libcrt0 libffs libgpio libc libcxx libmath libmos libtimer libvdp
	@echo [ Creating AGON library ]
	@$(RM) -f $(AGON)
	$(AR) $(ARFLAGS) $(AGON) $(CLANG_OBJS) $(CRT0_OBJS) $(FFS_OBJS) $(GPIO_OBJS) $(LIBC_OBJS) $(LIBCXX_OBJS) $(MATH_OBJS) $(MOS_OBJS) $(TIMER_OBJS) $(VDP_OBJS)
libclang: $(CLANG_OBJDIR) $(LIBDIRECTORY) $(CLANG_OBJS) $(CLANG)
libcrt0: $(CRT0_OBJDIR) $(LIBDIRECTORY) $(CRT0_OBJS) $(CRT0)
libffs: $(FFS_OBJDIR) $(LIBDIRECTORY) $(FFS_OBJS) $(FFS)
libgpio: $(GPIO_OBJDIR) $(LIBDIRECTORY) $(GPIO_OBJS) $(GPIO)
libc: $(LIBC_OBJDIR) $(LIBDIRECTORY) $(LIBC_OBJS) $(LIBC)
libcxx: $(LIBCXX_OBJDIR) $(LIBDIRECTORY) $(LIBCXX_OBJS) $(LIBCXX)
libmath: $(MATH_OBJDIR) $(LIBDIRECTORY) $(MATH_OBJS) $(MATH)
libmos: $(MOS_OBJDIR) $(LIBDIRECTORY) $(MOS_OBJS) $(MOS)
libtimer: $(TIMER_OBJDIR) $(LIBDIRECTORY) $(TIMER_OBJS) $(TIMER)
libvdp: $(VDP_OBJDIR) $(LIBDIRECTORY) $(VDP_OBJS) $(VDP)

# Link and ranlib the libc library
$(LIBC): $(LIBC_OBJS)
	@echo [ Creating LIBC library ]
	@$(RM) -f $(LIBC)
	$(AR) $(ARFLAGS) $(LIBC) $(LIBC_OBJS)
# Assemble each .src file into .o file
$(LIBC_OBJDIR)/%.o: $(LIBC_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBC_OBJDIR)/%.o: $(LIBC_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the clang library
$(CLANG): $(CLANG_OBJS)
	@echo [ Creating CLANG library ]
	@$(RM) -f $(CLANG)
	$(AR) $(ARFLAGS) $(CLANG) $(CLANG_OBJS)
# Assemble each .src file into .o file
$(CLANG_OBJDIR)/%.o: $(CLANG_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(CLANG_OBJDIR)/%.o: $(CLANG_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the crt0 library
$(CRT0): $(CRT0_OBJS)
	@echo [ Creating CRT0 library ]
	@$(RM) -f $(CRT0)
	$(AR) $(ARFLAGS) $(CRT0) $(CRT0_OBJS)
# Assemble each .src file into .o file
$(CRT0_OBJDIR)/%.o: $(CRT0_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(CRT0_OBJDIR)/%.o: $(CRT0_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the ffs library
$(FFS): $(FFS_OBJS)
	@echo [ Creating FFS library ]
	@$(RM) -f $(FFS)
	$(AR) $(ARFLAGS) $(FFS) $(FFS_OBJS)
# Assemble each .src file into .o file
$(FFS_OBJDIR)/%.o: $(FFS_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(FFS_OBJDIR)/%.o: $(FFS_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the gpio library
$(GPIO): $(GPIO_OBJS)
	@echo [ Creating GPIO library ]
	@$(RM) -f $(GPIO)
	$(AR) $(ARFLAGS) $(GPIO) $(GPIO_OBJS)
# Assemble each .src file into .o file
$(GPIO_OBJDIR)/%.o: $(GPIO_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(GPIO_OBJDIR)/%.o: $(GPIO_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the libcxx library
$(LIBCXX): $(LIBCXX_OBJS)
	@echo [ Creating LIBCXX library ]
	@$(RM) -f $(LIBCXX)
	$(AR) $(ARFLAGS) $(LIBCXX) $(LIBCXX_OBJS)
# Assemble each .src file into .o file
$(LIBCXX_OBJDIR)/%.o: $(LIBCXX_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBCXX_OBJDIR)/%.o: $(LIBCXX_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the math library
$(MATH): $(MATH_OBJS)
	@echo [ Creating MATH library ]
	@$(RM) -f $(MATH)
	$(AR) $(ARFLAGS) $(MATH) $(MATH_OBJS)
# Assemble each .src file into .o file
$(MATH_OBJDIR)/%.o: $(MATH_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(MATH_OBJDIR)/%.o: $(MATH_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the mos library
$(MOS): $(MOS_OBJS)
	@echo [ Creating MOS library ]
	@$(RM) -f $(MOS)
	$(AR) $(ARFLAGS) $(MOS) $(MOS_OBJS)
# Assemble each .src file into .o file
$(MOS_OBJDIR)/%.o: $(MOS_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(MOS_OBJDIR)/%.o: $(MOS_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the timer library
$(TIMER): $(TIMER_OBJS)
	@echo [ Creating TIMER library ]
	@$(RM) -f $(TIMER)
	$(AR) $(ARFLAGS) $(TIMER) $(TIMER_OBJS)
# Assemble each .src file into .o file
$(TIMER_OBJDIR)/%.o: $(TIMER_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(TIMER_OBJDIR)/%.o: $(TIMER_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the vdp library
$(VDP): $(VDP_OBJS)
	@echo [ Creating VDP library ]
	@$(RM) -f $(VDP)
	$(AR) $(ARFLAGS) $(VDP) $(VDP_OBJS)
# Assemble each .src file into .o file
$(VDP_OBJDIR)/%.o: $(VDP_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(VDP_OBJDIR)/%.o: $(VDP_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJTOPDIR):
	mkdir -p $(OBJTOPDIR)

$(RELEASEBINDIR):
	mkdir -p $(RELEASEBINDIR)

$(LIBDIRECTORY): $(RELEASEDIR)
	mkdir -p $(RELEASEDIR)/lib

$(CLANG_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(CLANG_OBJDIR)
$(CRT0_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(CRT0_OBJDIR)
$(FFS_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(FFS_OBJDIR)
$(GPIO_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(GPIO_OBJDIR)
$(LIBC_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBC_OBJDIR)
$(LIBCXX_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBCXX_OBJDIR)
$(MATH_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(MATH_OBJDIR)
$(MOS_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(MOS_OBJDIR)
$(TIMER_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(TIMER_OBJDIR)
$(VDP_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(VDP_OBJDIR)
clean:
	@$(RM) -r $(OBJTOPDIR)
	@$(RM) -rf $(RELEASEBINDIR)
	@$(RM) -rf $(LIBDIRECTORY)
	@$(RM) -rf $(TARGETDIR)
