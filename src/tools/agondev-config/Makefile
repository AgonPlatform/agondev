CC = gcc
CFLAGS=-g -Wall -O3 -std=c99 -DNDEBUG -DAGONDEV_VERSION="\"1.0\"" -c
LFLAGS=-g -Wall
OUTFLAG=-o

ifeq ($(OS),Windows_NT)
  TARGET ?= agondev-config.exe
  STRIP = strip --strip-all "$1"
else
  TARGET ?= agondev-config
  ifeq ($(shell uname -s),Darwin)
    STRIP = strip "$1"
    CFLAGS += -D_DARWIN_C_SOURCE -mmacosx-version-min=10.13
    LDFLAGS += -mmacosx-version-min=10.13
  else
    STRIP = strip --strip-all "$1"
    CFLAGS += -D_XOPEN_SOURCE=500 -static
    LDFLAGS += -static
    LIBRARIES += dl
  endif
endif

BINDIR = ./bin
OBJDIR = ./obj
SRCDIR = ./src
DEPDIR = ./src/deps
SOURCES= $(wildcard $(SRCDIR)/*.c)
OBJECTS= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

all: $(BINDIR)/$(TARGET)

release: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS) $(BINDIR)
	@$(CC) $(LFLAGS) $(OBJECTS) $(OUTFLAG) $@
	@$(call STRIP,$@)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(OBJDIR)
	@$(CC) $< $(CFLAGS) -I $(SRCDIR) -o $@

$(BINDIR):
	@mkdir -p $(BINDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@$(RM) -r $(BINDIR) $(OBJDIR)

.PHONY: all release test clean
