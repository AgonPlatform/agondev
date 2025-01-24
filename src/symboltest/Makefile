# Only testing for complete link without errors, no functional binary
PROJECTNAME=symboltest.bin
ARCHITECTURE=ez80
# Tools and arguments
TOOLDIR=../../llvm-build/ez80-none-elf/bin
CC=$(TOOLDIR)/clang
CFLAGS=-target ez80-none-elf -O1 -Wa,-march=ez80+full -I ../../release/include/
OUTFLAG=-o 
LINKER=$(TOOLDIR)/ez80-none-elf-ld
LINKERFLAGS= -defsym=_has_exit_handler=1 --gc-sections -T ../../release/config/linker.conf --oformat binary -o 
ASM=$(TOOLDIR)/ez80-none-elf-as
ASMFLAGS= -march=ez80+full 

.DEFAULT_GOAL := agon

# project directories
SRCDIR=src
OBJDIR=obj
BINDIR=bin
LIBDIR=../release/lib
LOADERDIR=mosloader
# Automatically get all sourcefiles
ASMSRCS=$(wildcard $(SRCDIR)/*.s)
SRCS=$(wildcard $(SRCDIR)/*.c)
# Automatically get all objects to make from sources
AOBJS=$(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(ASMSRCS))
COBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
OBJS=$(AOBJS) $(COBJS)

CRTOBJS=$(wildcard ../../obj/lib/crt/*.o)
LIBCOBJS=$(wildcard ../../obj/lib/libc/*.o)
AGONOBJS=$(wildcard ../../obj/lib/agon/*.o)
FPOBJS=$(wildcard ../../obj/lib/fp/*.o)

# Target project binary
BIN=$(BINDIR)/$(PROJECTNAME)

UNDEFINED=
# Default rule
all: agon

agon: $(BINDIR) $(OBJDIR) $(BIN)

# Linking all compiled objects into final binary
$(BIN):$(OBJS)
	@echo === Linking
	$(LINKER) -Map=$(BINDIR)/$(PROJECTNAME).map $(LINKERFLAGS)$@ $(CRTOBJS) $(FPOBJS) $(LIBCOBJS) $(AGONOBJS) $(OBJS)

# Compile each .c file into .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo === compiling $<
	$(CC) $(CFLAGS) $< -c -o $@

# Assemble each .s file into .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	$(ASM) $(ASMFLAGS) $< -o $@

$(BINDIR):
	@mkdir $(BINDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@echo Cleaning directories
	@$(RM) -r $(BINDIR) $(OBJDIR) $(RELEASEDIR)
	@$(RM) $(LOADERDIR)/$(PROJECTNAME).bin
