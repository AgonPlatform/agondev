.DEFAULT_GOAL := all

### Environment
OS_NAME != uname -s | tr 'A-Z' 'a-z'
ARCH    != uname -m | tr 'A-Z' 'a-z'
EZ80ARCH := ez80-none-elf

### Directories
SRC_DIR         := ./src
SRC_LIB_DIR     := $(SRC_DIR)/lib
BUILD_DIR       := ./build_lib
RELEASE_DIR     := ./release
RELEASE_BIN_DIR := $(RELEASE_DIR)/bin
RELEASE_LIB_DIR := $(RELEASE_DIR)/lib
RELEASE_INC_DIR := $(RELEASE_DIR)/include
TOOL_DIR        := ./llvm-build/$(EZ80ARCH)/bin
SCRIPT_DIR      := ./scripts
TARGET_DIR      := ./agondev

### Tools
CC :=$(TOOL_DIR)/clang
AS :=$(TOOL_DIR)/$(EZ80ARCH)-as
AR :=$(TOOL_DIR)/$(EZ80ARCH)-ar

### Arguments
CCFLAGS := -target $(EZ80ARCH) -Oz -Wa,-march=ez80+full -I $(RELEASE_INC_DIR)
ARFLAGS := rcs
ASFLAGS := -march=ez80+full -I $(RELEASE_INC_DIR)

### Sources
C_SRCS   := $(shell find $(SRC_LIB_DIR) -type f -name '*.c'   | sed 's|^$(SRC_LIB_DIR)/||')
ASM_SRCS := $(shell find $(SRC_LIB_DIR) -type f -name '*.asm' | sed 's|^$(SRC_LIB_DIR)/||')
SRC_SRCS := $(shell find $(SRC_LIB_DIR) -type f -name '*.src' | sed 's|^$(SRC_LIB_DIR)/||')

### Objects to build - convert source paths → object file paths
OBJS := \
    $(addprefix $(BUILD_DIR)/,$(C_SRCS:.c=.o)) \
    $(addprefix $(BUILD_DIR)/,$(ASM_SRCS:.asm=.o)) \
    $(addprefix $(BUILD_DIR)/,$(SRC_SRCS:.src=.o))

# AGON LIBRARY to build
LIBAGON := $(BUILD_DIR)/libagon.a

# Agon tools to build, using subproject makefile
AGONDEV_SETNAME := $(SRC_DIR)/tools/agondev-setname
AGONDEV_CONFIG  := $(SRC_DIR)/tools/agondev-config

# Default rule
all: $(RELEASE_BIN_DIR) $(LIBAGON) agondev-setname agondev-config
	@echo [ Copying binaries to $(RELEASE_BIN_DIR) ]
	@cp $(TOOL_DIR)/$(EZ80ARCH)-* $(RELEASE_BIN_DIR)
	@strip $(RELEASE_BIN_DIR)/$(EZ80ARCH)-*
	@cp $(TOOL_DIR)/clang $(RELEASE_BIN_DIR)/$(EZ80ARCH)-clang
	@strip $(RELEASE_BIN_DIR)/$(EZ80ARCH)-clang
	@cp ./dist/hexload-send $(RELEASE_BIN_DIR) 
	@cp $(AGONDEV_SETNAME)/bin/* $(RELEASE_BIN_DIR)/
	@cp $(AGONDEV_CONFIG)/bin/* $(RELEASE_BIN_DIR)/
 
	@echo [ Copying Agon library to $(RELEASE_LIB_DIR) ]
	@cp $(LIBAGON) $(RELEASE_LIB_DIR)

	@echo [ Creating TAR binary for release ]
	@$(RM) -rf $(TARGET_DIR)
	@mkdir $(TARGET_DIR)
	@cp -R $(RELEASE_DIR)/* $(TARGET_DIR)/
	@tar -zcvf agondev-$(OS_NAME)_$(ARCH).tar.gz $(TARGET_DIR) > /dev/null 2>&1
	@$(RM) -rf $(TARGET_DIR)
	@echo [ Done ]

# Ranlib all library objects into single AGON library
$(LIBAGON): $(OBJS) $(RELEASE_LIB_DIR)
	@echo [ Creating AGON library ]
	@$(RM) -f $(LIBAGON)
	$(AR) $(ARFLAGS) $(LIBAGON) $(OBJS)

agondev-setname:
	@echo "[Building $@ ]"
	@$(MAKE) -C $(AGONDEV_SETNAME)
agondev-config:
	@echo "[Building $@ ]"
	@$(MAKE) -C $(AGONDEV_CONFIG)

# Rule for compiling all C files
$(BUILD_DIR)/%.o: $(SRC_LIB_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -c $< -o $@
# Rule for assembling all .src files
$(BUILD_DIR)/%.o: $(SRC_LIB_DIR)/%.src
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) $< -o $@
# Rule for assembling all .asm files
$(BUILD_DIR)/%.o: $(SRC_LIB_DIR)/%.asm
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) $< -o $@

$(RELEASE_BIN_DIR):
	@mkdir -p $(RELEASE_BIN_DIR)

$(RELEASE_LIB_DIR): $(RELEASE_DIR)
	@mkdir -p $(RELEASE_DIR)/lib

clean:
	@$(RM) -r $(BUILD_DIR)
	@$(RM) -rf $(RELEASE_BIN_DIR)
	@$(RM) -rf $(RELEASE_LIB_DIR)
	@$(RM) -rf $(TARGET_DIR)
	@$(MAKE) -C $(AGONDEV_SETNAME) clean
	@$(MAKE) -C $(AGONDEV_CONFIG) clean
