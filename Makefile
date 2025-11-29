.DEFAULT_GOAL := all
MAKEFLAGS += --no-print-directory

### Environment
OS_NAME := $(shell uname -s | tr 'A-Z' 'a-z')
ARCH    := $(shell uname -m | tr 'A-Z' 'a-z')
EZ80ARCH := ez80-none-elf

### Directories
SRC_DIR         := ./src/lib
BUILD_DIR       := ./build/lib
RELEASE_DIR     := ./release
RELEASE_LIB_DIR := $(RELEASE_DIR)/lib
RELEASE_INC_DIR := $(RELEASE_DIR)/include
TOOL_DIR        := $(RELEASE_DIR)/bin
TAR_DIR         := ./agondev

### Tools
CC :=$(TOOL_DIR)/$(EZ80ARCH)-clang
AS :=$(TOOL_DIR)/$(EZ80ARCH)-as
AR :=$(TOOL_DIR)/$(EZ80ARCH)-ar

### Arguments
CCFLAGS := -target $(EZ80ARCH) -Oz -Wa,-march=ez80+full -I $(RELEASE_INC_DIR)
ARFLAGS := rcs
ASFLAGS := -march=ez80+full -I $(RELEASE_INC_DIR)

### Sources
C_SRCS   := $(shell find $(SRC_DIR) -type f -name '*.c'   | sed 's|^$(SRC_DIR)/||')
ASM_SRCS := $(shell find $(SRC_DIR) -type f -name '*.asm' | sed 's|^$(SRC_DIR)/||')
SRC_SRCS := $(shell find $(SRC_DIR) -type f -name '*.src' | sed 's|^$(SRC_DIR)/||')

### Objects to build - convert source paths → object file paths
OBJS := \
    $(addprefix $(BUILD_DIR)/,$(C_SRCS:.c=.o)) \
    $(addprefix $(BUILD_DIR)/,$(ASM_SRCS:.asm=.o)) \
    $(addprefix $(BUILD_DIR)/,$(SRC_SRCS:.src=.o))

# AGON LIBRARY to build
LIBAGON := $(RELEASE_LIB_DIR)/libagon.a

# Release tarball to build
RELEASE := agondev-$(OS_NAME)_$(ARCH).tar.gz

# Default rule
all: $(RELEASE)
	@echo [ Done ]

$(RELEASE): $(RELEASE_DIR) $(LIBAGON)
	@$(RM) -r $(TAR_DIR)
	@mkdir -p $(TAR_DIR)
	@cp -R $(RELEASE_DIR)/* $(TAR_DIR)/
	@echo [ Creating TAR binary for release ]
	@tar -zcvf $(RELEASE) $(TAR_DIR) > /dev/null 2>&1
	@$(RM) -r $(TAR_DIR)
 
# Ranlib all library objects into single AGON library
$(LIBAGON): $(OBJS) $(RELEASE_LIB_DIR)
	@echo [ Creating AGON library ]
	@$(RM) -f $(LIBAGON)
	$(AR) $(ARFLAGS) $(LIBAGON) $(OBJS)

# Rule for compiling all C files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -c $< -o $@
# Rule for assembling all .src files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.src
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) $< -o $@
# Rule for assembling all .asm files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) $< -o $@

$(RELEASE_LIB_DIR): $(RELEASE_DIR)
	@mkdir -p $(RELEASE_DIR)/lib

clean:
	@$(RM) -r $(BUILD_DIR)
	@$(RM) -rf $(RELEASE_LIB_DIR)
