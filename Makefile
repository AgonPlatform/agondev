.DEFAULT_GOAL := all

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

# AGON LIBRARY
LIBAGON=$(LIBDIRECTORY)/libagon.a

# CLANG LIBRARY
LIBCLANG_SRCDIR=./src/lib/libclang
LIBCLANG_OBJDIR=$(OBJTOPDIR)/lib/libclang
LIBCLANG_ASMSRCS=$(wildcard $(LIBCLANG_SRCDIR)/*.src)
LIBCLANG_CSRCS=$(wildcard $(LIBCLANG_SRCDIR)/*.c)
LIBCLANG_ASMOBJS=$(patsubst $(LIBCLANG_SRCDIR)/%.src, $(LIBCLANG_OBJDIR)/%.o, $(LIBCLANG_ASMSRCS))
LIBCLANG_COBJS=$(patsubst $(LIBCLANG_SRCDIR)/%.c, $(LIBCLANG_OBJDIR)/%.o, $(LIBCLANG_CSRCS))
LIBCLANG_OBJS=$(LIBCLANG_ASMOBJS) $(LIBCLANG_COBJS)
LIBCLANG=$(LIBDIRECTORY)/libclang.a

# CRT0 LIBRARY
LIBCRT0_SRCDIR=./src/lib/libcrt0
LIBCRT0_OBJDIR=$(OBJTOPDIR)/lib/libcrt0
LIBCRT0_ASMSRCS=$(wildcard $(LIBCRT0_SRCDIR)/*.src)
LIBCRT0_CSRCS=$(wildcard $(LIBCRT0_SRCDIR)/*.c)
LIBCRT0_ASMOBJS=$(patsubst $(LIBCRT0_SRCDIR)/%.src, $(LIBCRT0_OBJDIR)/%.o, $(LIBCRT0_ASMSRCS))
LIBCRT0_COBJS=$(patsubst $(LIBCRT0_SRCDIR)/%.c, $(LIBCRT0_OBJDIR)/%.o, $(LIBCRT0_CSRCS))
LIBCRT0_OBJS=$(LIBCRT0_ASMOBJS) $(LIBCRT0_COBJS)
LIBCRT0=$(LIBDIRECTORY)/libcrt0.a

# GPIO LIBRARY
LIBGPIO_SRCDIR=./src/lib/libgpio
LIBGPIO_OBJDIR=$(OBJTOPDIR)/lib/libgpio
LIBGPIO_ASMSRCS=$(wildcard $(LIBGPIO_SRCDIR)/*.src)
LIBGPIO_CSRCS=$(wildcard $(LIBGPIO_SRCDIR)/*.c)
LIBGPIO_ASMOBJS=$(patsubst $(LIBGPIO_SRCDIR)/%.src, $(LIBGPIO_OBJDIR)/%.o, $(LIBGPIO_ASMSRCS))
LIBGPIO_COBJS=$(patsubst $(LIBGPIO_SRCDIR)/%.c, $(LIBGPIO_OBJDIR)/%.o, $(LIBGPIO_CSRCS))
LIBGPIO_OBJS=$(LIBGPIO_ASMOBJS) $(LIBGPIO_COBJS)
LIBGPIO=$(LIBDIRECTORY)/libgpio.a

# MATH LIBRARY
LIBM_SRCDIR=./src/lib/libm
LIBM_OBJDIR=$(OBJTOPDIR)/lib/libm
LIBM_ASMSRCS=$(wildcard $(LIBM_SRCDIR)/*.src)
LIBM_CSRCS=$(wildcard $(LIBM_SRCDIR)/*.c)
LIBM_ASMOBJS=$(patsubst $(LIBM_SRCDIR)/%.src, $(LIBM_OBJDIR)/%.o, $(LIBM_ASMSRCS))
LIBM_COBJS=$(patsubst $(LIBM_SRCDIR)/%.c, $(LIBM_OBJDIR)/%.o, $(LIBM_CSRCS))
LIBM_OBJS=$(LIBM_ASMOBJS) $(LIBM_COBJS)
LIBM=$(LIBDIRECTORY)/libm.a

# MOS LIBRARY
LIBMOS_SRCDIR=./src/lib/libmos
LIBMOS_OBJDIR=$(OBJTOPDIR)/lib/libmos
LIBMOS_ASMSRCS=$(wildcard $(LIBMOS_SRCDIR)/*.src)
LIBMOS_CSRCS=$(wildcard $(LIBMOS_SRCDIR)/*.c)
LIBMOS_ASMOBJS=$(patsubst $(LIBMOS_SRCDIR)/%.src, $(LIBMOS_OBJDIR)/%.o, $(LIBMOS_ASMSRCS))
LIBMOS_COBJS=$(patsubst $(LIBMOS_SRCDIR)/%.c, $(LIBMOS_OBJDIR)/%.o, $(LIBMOS_CSRCS))
LIBMOS_OBJS=$(LIBMOS_ASMOBJS) $(LIBMOS_COBJS)
LIBMOS=$(LIBDIRECTORY)/libmos.a

# TIMER LIBRARY
LIBTIMER_SRCDIR=./src/lib/libtimer
LIBTIMER_OBJDIR=$(OBJTOPDIR)/lib/libtimer
LIBTIMER_ASMSRCS=$(wildcard $(LIBTIMER_SRCDIR)/*.src)
LIBTIMER_CSRCS=$(wildcard $(LIBTIMER_SRCDIR)/*.c)
LIBTIMER_ASMOBJS=$(patsubst $(LIBTIMER_SRCDIR)/%.src, $(LIBTIMER_OBJDIR)/%.o, $(LIBTIMER_ASMSRCS))
LIBTIMER_COBJS=$(patsubst $(LIBTIMER_SRCDIR)/%.c, $(LIBTIMER_OBJDIR)/%.o, $(LIBTIMER_CSRCS))
LIBTIMER_OBJS=$(LIBTIMER_ASMOBJS) $(LIBTIMER_COBJS)
LIBTIMER=$(LIBDIRECTORY)/libtimer.a

# VDP LIBRARY
LIBVDP_SRCDIR=./src/lib/libvdp
LIBVDP_OBJDIR=$(OBJTOPDIR)/lib/libvdp
LIBVDP_ASMSRCS=$(wildcard $(LIBVDP_SRCDIR)/*.src)
LIBVDP_CSRCS=$(wildcard $(LIBVDP_SRCDIR)/*.c)
LIBVDP_ASMOBJS=$(patsubst $(LIBVDP_SRCDIR)/%.src, $(LIBVDP_OBJDIR)/%.o, $(LIBVDP_ASMSRCS))
LIBVDP_COBJS=$(patsubst $(LIBVDP_SRCDIR)/%.c, $(LIBVDP_OBJDIR)/%.o, $(LIBVDP_CSRCS))
LIBVDP_OBJS=$(LIBVDP_ASMOBJS) $(LIBVDP_COBJS)
LIBVDP=$(LIBDIRECTORY)/libvdp.a

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
all: $(RELEASEBINDIR) $(LIBAGON)
	@echo [ Copying binaries to release/bin ]
	$(shell cp ./llvm-build/ez80-none-elf/bin/ez80-none-elf-* ./release/bin/)
	$(shell strip ./release/bin/ez80-none-elf-*)
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

# Ranlib all library objects into single AGON library
$(LIBAGON): $(LIBCLANG) $(LIBCRT0) $(LIBGPIO) $(LIBC) $(LIBCXX) $(LIBM) $(LIBMOS) $(LIBTIMER) $(LIBVDP)
	@echo [ Creating AGON library ]
	@$(RM) -f $(LIBAGON)
	$(AR) $(ARFLAGS) $(LIBAGON) $(LIBCLANG_OBJS) $(LIBCRT0_OBJS) $(LIBGPIO_OBJS) $(LIBC_OBJS) $(LIBCXX_OBJS) $(LIBM_OBJS) $(LIBMOS_OBJS) $(LIBTIMER_OBJS) $(LIBVDP_OBJS)

# Link and ranlib the libc library
$(LIBC): $(LIBC_OBJDIR) $(LIBDIRECTORY) $(LIBC_OBJS)
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
$(LIBCLANG): $(LIBCLANG_OBJDIR) $(LIBDIRECTORY) $(LIBCLANG_OBJS)
	@echo [ Creating CLANG library ]
	@$(RM) -f $(LIBCLANG)
	$(AR) $(ARFLAGS) $(LIBCLANG) $(LIBCLANG_OBJS)
# Assemble each .src file into .o file
$(LIBCLANG_OBJDIR)/%.o: $(LIBCLANG_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBCLANG_OBJDIR)/%.o: $(LIBCLANG_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the crt0 library
$(LIBCRT0): $(LIBCRT0_OBJDIR) $(LIBDIRECTORY) $(LIBCRT0_OBJS)
	@echo [ Creating CRT0 library ]
	@$(RM) -f $(LIBCRT0)
	$(AR) $(ARFLAGS) $(LIBCRT0) $(LIBCRT0_OBJS)
# Assemble each .src file into .o file
$(LIBCRT0_OBJDIR)/%.o: $(LIBCRT0_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBCRT0_OBJDIR)/%.o: $(LIBCRT0_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the gpio library
$(LIBGPIO): $(LIBGPIO_OBJDIR) $(LIBDIRECTORY) $(LIBGPIO_OBJS)
	@echo [ Creating GPIO library ]
	@$(RM) -f $(LIBGPIO)
	$(AR) $(ARFLAGS) $(LIBGPIO) $(LIBGPIO_OBJS)
# Assemble each .src file into .o file
$(LIBGPIO_OBJDIR)/%.o: $(LIBGPIO_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBGPIO_OBJDIR)/%.o: $(LIBGPIO_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the libcxx library
$(LIBCXX): $(LIBCXX_OBJDIR) $(LIBDIRECTORY) $(LIBCXX_OBJS)
	@echo [ Creating LIBCXX library ]
	@$(RM) -f $(LIBCXX)
	$(AR) $(ARFLAGS) $(LIBCXX) $(LIBCXX_OBJS)
# Assemble each .src file into .o file
$(LIBCXX_OBJDIR)/%.o: $(LIBCXX_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBCXX_OBJDIR)/%.o: $(LIBCXX_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the LIBM library
$(LIBM): $(LIBM_OBJDIR) $(LIBDIRECTORY) $(LIBM_OBJS)
	@echo [ Creating MATH library ]
	@$(RM) -f $(LIBM)
	$(AR) $(ARFLAGS) $(LIBM) $(LIBM_OBJS)
# Assemble each .src file into .o file
$(LIBM_OBJDIR)/%.o: $(LIBM_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBM_OBJDIR)/%.o: $(LIBM_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the mos library
$(LIBMOS): $(LIBMOS_OBJDIR) $(LIBDIRECTORY) $(LIBMOS_OBJS)
	@echo [ Creating MOS library ]
	@$(RM) -f $(LIBMOS)
	$(AR) $(ARFLAGS) $(LIBMOS) $(LIBMOS_OBJS)
# Assemble each .src file into .o file
$(LIBMOS_OBJDIR)/%.o: $(LIBMOS_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBMOS_OBJDIR)/%.o: $(LIBMOS_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the timer library
$(LIBTIMER): $(LIBTIMER_OBJDIR) $(LIBDIRECTORY) $(LIBTIMER_OBJS)
	@echo [ Creating TIMER library ]
	@$(RM) -f $(LIBTIMER)
	$(AR) $(ARFLAGS) $(LIBTIMER) $(LIBTIMER_OBJS)
# Assemble each .src file into .o file
$(LIBTIMER_OBJDIR)/%.o: $(LIBTIMER_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBTIMER_OBJDIR)/%.o: $(LIBTIMER_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the vdp library
$(LIBVDP): $(LIBVDP_OBJDIR) $(LIBDIRECTORY) $(LIBVDP_OBJS)
	@echo [ Creating VDP library ]
	@$(RM) -f $(LIBVDP)
	$(AR) $(ARFLAGS) $(LIBVDP) $(LIBVDP_OBJS)
# Assemble each .src file into .o file
$(LIBVDP_OBJDIR)/%.o: $(LIBVDP_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBVDP_OBJDIR)/%.o: $(LIBVDP_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJTOPDIR):
	mkdir -p $(OBJTOPDIR)

$(RELEASEBINDIR):
	mkdir -p $(RELEASEBINDIR)

$(LIBDIRECTORY): $(RELEASEDIR)
	mkdir -p $(RELEASEDIR)/lib

$(LIBCLANG_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBCLANG_OBJDIR)
$(LIBCRT0_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBCRT0_OBJDIR)
$(LIBGPIO_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBGPIO_OBJDIR)
$(LIBC_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBC_OBJDIR)
$(LIBCXX_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBCXX_OBJDIR)
$(LIBM_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBM_OBJDIR)
$(LIBMOS_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBMOS_OBJDIR)
$(LIBTIMER_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBTIMER_OBJDIR)
$(LIBVDP_OBJDIR): $(OBJ_TOPDIR)
	mkdir -p $(LIBVDP_OBJDIR)
clean:
	@$(RM) -r $(OBJTOPDIR)
	@$(RM) -rf $(RELEASEBINDIR)
	@$(RM) -rf $(LIBDIRECTORY)
	@$(RM) -rf $(TARGETDIR)
