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
CFLAGS=-target ez80-none-elf -O1 -Wa,-march=ez80+full -I ./release/include
OUTFLAG=-o 
LINKERFLAGS= -T linker.conf --oformat binary -o 
ARFLAGS=rcs
ASMFLAGS= -march=ez80+full -I./release/include/

.DEFAULT_GOAL := all

# LIBC LIBRARY
LIBC_SRCDIR=./src/lib/libc
LIBC_OBJDIR=$(OBJTOPDIR)/lib/libc
LIBC_ASMSRCS=$(wildcard $(LIBC_SRCDIR)/*.src)
LIBC_CSRCS=$(wildcard $(LIBC_SRCDIR)/*.c)
LIBC_ASMOBJS=$(patsubst $(LIBC_SRCDIR)/%.src, $(LIBC_OBJDIR)/%.o, $(LIBC_ASMSRCS))
LIBC_COBJS=$(patsubst $(LIBC_SRCDIR)/%.c, $(LIBC_OBJDIR)/%.o, $(LIBC_CSRCS))
LIBC_OBJS=$(LIBC_ASMOBJS) $(LIBC_COBJS)
LIBC=$(LIBDIRECTORY)/libc.a

# CRT LIBRARY
CRT_SRCDIR=./src/lib/crt
CRT_OBJDIR=$(OBJTOPDIR)/lib/crt
CRT_ASMSRCS=$(wildcard $(CRT_SRCDIR)/*.src)
CRT_CSRCS=$(wildcard $(CRT_SRCDIR)/*.c)
CRT_ASMOBJS=$(patsubst $(CRT_SRCDIR)/%.src, $(CRT_OBJDIR)/%.o, $(CRT_ASMSRCS))
CRT_COBJS=$(patsubst $(CRT_SRCDIR)/%.c, $(CRT_OBJDIR)/%.o, $(CRT_CSRCS))
CRT_OBJS=$(CRT_ASMOBJS) $(CRT_COBJS)
CRT=$(LIBDIRECTORY)/libcrt.a

# AGON LIBRARY
AGON_SRCDIR=./src/lib/agon
AGON_OBJDIR=$(OBJTOPDIR)/lib/agon
AGON_ASMSRCS=$(wildcard $(AGON_SRCDIR)/*.src)
AGON_CSRCS=$(wildcard $(AGON_SRCDIR)/*.c)
AGON_ASMOBJS=$(patsubst $(AGON_SRCDIR)/%.src, $(AGON_OBJDIR)/%.o, $(AGON_ASMSRCS))
AGON_COBJS=$(patsubst $(AGON_SRCDIR)/%.c, $(AGON_OBJDIR)/%.o, $(AGON_CSRCS))
AGON_OBJS=$(AGON_ASMOBJS) $(AGON_COBJS)
AGON=$(LIBDIRECTORY)/libagon.a

# FP LIBRARY
FP_SRCDIR=./src/lib/fp
FP_OBJDIR=$(OBJTOPDIR)/lib/fp
FP_ASMSRCS=$(wildcard $(FP_SRCDIR)/*.src)
FP_CSRCS=$(wildcard $(FP_SRCDIR)/*.c)
FP_ASMOBJS=$(patsubst $(FP_SRCDIR)/%.src, $(FP_OBJDIR)/%.o, $(FP_ASMSRCS))
FP_COBJS=$(patsubst $(FP_SRCDIR)/%.c, $(FP_OBJDIR)/%.o, $(FP_CSRCS))
FP_OBJS=$(FP_ASMOBJS) $(FP_COBJS)
FP=$(LIBDIRECTORY)/libfp.a

# Default rule
libs: libc crt agon fp
all: $(RELEASEBINDIR) libs
	@echo [ Copying binaries to release/bin ]
	$(shell cp ./llvm-build/ez80-none-elf/bin/clang ./release/bin/ez80-none-elf-clang)
	$(shell strip ./release/bin/ez80-none-elf-clang)
	$(shell cp ./llvm-build/ez80-none-elf/bin/ez80-none-elf-as ./release/bin/)
	$(shell strip ./release/bin/ez80-none-elf-as)
	$(shell cp ./llvm-build/ez80-none-elf/bin/ez80-none-elf-ld ./release/bin/)
	$(shell strip ./release/bin/ez80-none-elf-as)

	@echo [ Making agondev tools ]
	$(shell cd src/tools/agondev-setname;make clean;make;cp bin/* ../../../release/bin;make clean)
	$(shell cd src/tools/agondev-config;make clean;make;cp bin/* ../../../release/bin;make clean)

	@echo [ Creating TAR binary for release ]
	@rm -rf $(TARGETDIR)
	@mkdir $(TARGETDIR)
	@cp -R $(RELEASEDIR)/ $(TARGETDIR)/
	@tar -zcvf agondev-$(OS_NAME)_$(ARCH).tar.gz $(TARGETDIR) > /dev/null
	@rm -rf $(TARGETDIR)
	@echo [ Done ]
# Targets
libc: $(OBJTOPDIR) $(LIBC_OBJDIR) $(LIBDIRECTORY) $(LIBC_OBJS) $(LIBC)
crt: $(OBJTOPDIR) $(CRT_OBJDIR) $(LIBDIRECTORY) $(CRT_OBJS) $(CRT)
agon: $(OBJTOPDIR) $(RELEASEDIR) $(AGON_OBJDIR) $(LIBDIRECTORY) $(AGON_OBJS) $(AGON)
fp: $(OBJTOPDIR) $(FP_OBJDIR) $(LIBDIRECTORY) $(FP_OBJS) $(FP)

# Link and ranlib the libc library
$(LIBC):$(LIBC_OBJS)
	@echo [ Creating LIBC library ]
	$(AR) $(ARFLAGS) $(LIBC) $(LIBC_OBJS)
# Assemble each .src file into .o file
$(LIBC_OBJDIR)/%.o: $(LIBC_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(LIBC_OBJDIR)/%.o: $(LIBC_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the crt library
$(CRT):$(CRT_OBJS)
	@echo [ Creating CRT library ]
	$(AR) $(ARFLAGS) $(CRT) $(CRT_OBJS)
# Assemble each .src file into .o file
$(CRT_OBJDIR)/%.o: $(CRT_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(CRT_OBJDIR)/%.o: $(CRT_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the agon library
$(AGON):$(AGON_OBJS)
	@echo [ Creating AGON library ]
	$(AR) $(ARFLAGS) $(AGON) $(AGON_OBJS)
# Assemble each .src file into .o file
$(AGON_OBJDIR)/%.o: $(AGON_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(AGON_OBJDIR)/%.o: $(AGON_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

# Link and ranlib the fp library
$(FP):$(FP_OBJS)
	@echo [ Creating FP library ]
	$(AR) $(ARFLAGS) $(FP) $(FP_OBJS)
# Assemble each .src file into .o file
$(FP_OBJDIR)/%.o: $(FP_SRCDIR)/%.src
	$(ASM) $(ASMFLAGS) $< -o $@
# Compile each .c file into .o file
$(FP_OBJDIR)/%.o: $(FP_SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJTOPDIR):
	mkdir -p $(OBJTOPDIR)
	mkdir -p $(OBJTOPDIR)/lib
	mkdir -p $(OBJTOPDIR)/lib/libc
	mkdir -p $(OBJTOPDIR)/lib/crt
	mkdir -p $(OBJTOPDIR)/lib/agon
	mkdir -p $(OBJTOPDIR)/lib/fp

$(RELEASEBINDIR):
	mkdir -p $(RELEASEBINDIR)

$(LIBDIRECTORY): $(RELEASEDIR)
	mkdir -p $(RELEASEDIR)/lib

$(LIBC_OBJDIR):
	mkdir -p $(LIBC_OBJDIR)
$(AGON_OBJDIR):
	mkdir -p $(AGON_OBJDIR)
$(CRT_OBJDIR):
	mkdir -p $(CRT_OBJDIR)
$(FP_OBJDIR):
	mkdir -p $(FP_OBJDIR)
clean:
	@$(RM) -r $(OBJTOPDIR)
	@$(RM) -rf $(RELEASEBINDIR)
	@$(RM) -rf $(LIBDIRECTORY)
	@$(RM) -rf $(TARGETDIR)
