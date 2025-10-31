# Memory layout defaults if not set by the user
RAM_START ?= 0x40000
RAM_SIZE  ?= 0x70000

# verbosity - comment next line to show all output
V = @

# Tool directories
AGONDEV_TOOLCHAIN ?= $(shell agondev-config --prefix)
TOOLBINDIR=$(AGONDEV_TOOLCHAIN)/bin
INCLUDEDIR=$(AGONDEV_TOOLCHAIN)/include
PROJECTINCLUDEDIR=./include
LINKERCONFIG=$(AGONDEV_TOOLCHAIN)/config/linker.conf
LIBDIR=$(AGONDEV_TOOLCHAIN)/lib
PROJECTLIBDIR=./lib

# Architecture
ARCH=ez80+full
TARGET=ez80-none-elf

# Tools and flags
## Compiler
CC=$(TOOLBINDIR)/ez80-none-elf-clang
CFLAGS=-nostdinc -I$(PROJECTINCLUDEDIR) -isystem $(INCLUDEDIR) -target $(TARGET) -DAGONDEV -Oz -Wa,-march=$(ARCH) -fno-threadsafe-statics
CXXFLAGS=$(CFLAGS) -isystem $(INCLUDEDIR)/c++

## Assembler
ASM=$(TOOLBINDIR)/ez80-none-elf-as
ASMFLAGS=-march=$(ARCH)

## Linker
LINKER=$(TOOLBINDIR)/ez80-none-elf-ld
ifeq ($(LDHAS_ARG_PROCESSING),1)
	LINKER_ARG=-defsym=_parse_option=___arg_processing
endif
ifeq ($(LDHAS_EXIT_HANDLER), 1)
    LINKER_EXIT=-defsym=_has_exit_handler=1
else
    LINKER_EXIT=-defsym=_has_exit_handler=0
endif
MEMCONFIG=-defsym=RAM_START=$(RAM_START) -defsym=RAM_SIZE=$(RAM_SIZE)
LINKERFLAGS=$(MEMCONFIG) $(LINKER_ARG) $(LINKER_EXIT) -Map=$(BINDIR)/$(NAME).map -T $(LINKERCONFIG) --oformat binary -o 
LINKERLIBFLAGS=-L$(PROJECTLIBDIR) $(LIBS) -L$(LIBDIR) -\( -l c -l cxx -l agon -l crt -l fp -\) 
SETPROGNAME=$(TOOLBINDIR)/agondev-setname

## Archiver
AR=$(TOOLBINDIR)/ez80-none-elf-ar
ARFLAGS=rcs

# project directories
SRCDIR=src
OBJDIR=obj
BINDIR=bin
# Intermediate linker binary - no program name set yet
LINKBINARY=$(BINDIR)/$(NAME).noname.bin
# Final binary
BINARY=$(BINDIR)/$(NAME).bin
# Final library
LIBRARY=$(BINDIR)/lib$(NAME).a

# Automatically get all object names from sourcefiles
OBJS=$(patsubst $(SRCDIR)/%.asm, $(OBJDIR)/%.o, $(shell find $(SRCDIR) -name '*.asm')) \
     $(patsubst $(SRCDIR)/%.s,   $(OBJDIR)/%.o, $(shell find $(SRCDIR) -name '*.s')) \
     $(patsubst $(SRCDIR)/%.src, $(OBJDIR)/%.o, $(shell find $(SRCDIR) -name '*.src')) \
     $(patsubst $(SRCDIR)/%.c,   $(OBJDIR)/%.o, $(shell find $(SRCDIR) -name '*.c')) \
     $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(shell find $(SRCDIR) -name '*.cpp'))

# Default rule
all: $(BINDIR) $(BINARY)
	@echo [Done]

# Final binary
$(BINARY): $(BINDIR) $(LINKBINARY)
	@echo [Start address $(RAM_START)]
	@echo [Setting name \'$(NAME).bin\' in binary]
	@cp $(LINKBINARY) $(BINARY)
	$(V)$(SETPROGNAME) $(BINARY) >/dev/null

# Temporary 'program.bin' linked binary
$(LINKBINARY): $(BINDIR) $(OBJS)
	@echo [Linking $(LINKBINARY)]
	$(V)$(LINKER) $(LINKERFLAGS)$@ $(OBJS) $(LINKERLIBFLAGS)

# Create a library of all project objects
lib: $(BINDIR) $(LIBRARY)
	@echo [Done]

$(LIBRARY):$(OBJS)
	@echo [Creating library $(LIBRARY)]
	$(V)$(AR) $(ARFLAGS) $(LIBRARY) $(OBJS)

# Compile each .c file into .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo [compiling $<]
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) $< -c -o $@
# Compile each .cpp file into .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo [compiling $<]
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CXXFLAGS) $< -c -o $@
# Assemble each .s file into .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@echo [assembling $<]
	@mkdir -p $(dir $@)
	$(V)$(ASM) $(ASMFLAGS) $< -o $@
# Assemble each .asm file into .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.asm
	@echo [assembling $<]
	@mkdir -p $(dir $@)
	$(V)$(ASM) $(ASMFLAGS) $< -o $@
# Assemble each .src file into .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.src
	@echo [assembling $<]
	@mkdir -p $(dir $@)
	$(V)$(ASM) $(ASMFLAGS) $< -o $@

upload: $(BINDIR) $(BINARY)
ifeq ($(SERIALPORT),)
	@echo [No SERIALPORT in Makefile - autodetect]
	@SERIALPORT=auto
endif
	@echo [Starting hexload-send]
	@hexload-send $(BINARY) $(SERIALPORT) $(BAUDRATE)

# Directories to create
$(BINDIR):
	@mkdir $(BINDIR)

clean:
	@$(RM) -r $(BINDIR) $(OBJDIR) 
