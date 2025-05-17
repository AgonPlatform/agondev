# AGON dev C/C++ toolchain
## Status
Early access Alpha: things will break.

The toolchain is currently compiled for Linux (x86_64 / arm64) and MacOS (arm64) only.

I'm not ready to accept issues or PRs at this time. Contact me at [Discord](https://discord.gg/nfGrhdTf6z) to discuss
## Purpose
To assemble a C/C++ toolchain, based on modern, open-source software that can be ported to many platforms
## Installation
- Download the agondev-<platform_architecture>.tar.gz file from the releases tab, to a path <b>without any space</b>, e.g. /home/user/steve
- Extract the file with

``` 
tar xfvz agondev-<platform_architecture>.tar.gz
```

- Extend the PATH environment variable to point to agondev/bin. Example:

``` 
export PATH=/<insert path to agondev>/bin:$PATH
```

## Project structure
A minimum project consists of a Makefile and at least a single source file in the 'src' subdirectory:
``` 
project/
│
├── Makefile
└── src/
    └── main.c
```
---

The toolchain expects the following project structure:

``` 
project/
│
├── Makefile
├── src/
│   │   project source files, e.g.
│   ├── main.c
│   └── module.asm
├── lib/
│   │   Optional directory with static libraries the
│   │   project requires, e.g.
│   ├── libtest.a
│   └── libsecret.a
├── obj/
│   │   objects created by the compiler / assembler
│   │   this directory will be created automatically
│   ├── main.o
│   └── module.o
└── bin/
    │   the compiled program is placed here
    │   this directory will be created automatically
    └── program.bin
```

## Compiling programs
Change directory to the root of your project, compile and link your program with the following command:

``` 
make
```

The same command is required to compile any changes to the source file(s).

Clean up the entire build and compile everything from scratch with the following command:
``` 
make clean; make
```

- The 'Makefile' in the root directory of each project provides the required logic to build the project.
- All source files need to be placed under a project's <b><project_dir>/src</b> directory.

- .c / .cpp / .s / .asm / .src sources will be compiled / assembled directly to an ELF-formatted object file in <b><project_dir>/obj</b>

- The linker will link all objects together with the provided libaries (libc / agon / fp / crt) and create a binary in <b><project_dir>/bin</b>

Check out the provided example programs, which have a slightly different top-level Makefile with options that are similar to what AgDev provides.

## Minimal project Makefile
Open your favorite editor, enter the following text and save it as 'Makefile' in your project's root directory:

``` 
NAME=program
include $(shell agondev-config --makefile)
``` 

After successful compilation of your program, this example Makefile creates a 'program.bin' file in the <b><project_dir>/bin</b> directory.

## Makefile options
The following options can be set in the user's project Makefile:
- NAME - sets the name of the project
- RAM_START - sets the load/start address of the compiled program. This option will default to 0x040000
- RAM_SIZE - sets the amount of memory available to the program. This option will default to 0x070000. The init routine will set the stackpointer to RAM_START + RAM_SIZE
- LDHAS_ARG_PROCESSING - by default set to 0, this will make use of simple commandline processing of program arguments. If set to 1, this will make use of additional code to process redirection and quoting.
- LDHAS_EXIT_HANDLER - by default set to 0. Set this to 1 to print out an error text based on the program's exit code, before returning to MOS. 
- LIBS - sets flags to link with user-supplied static libraries in the <project_dir>/lib directory. For example: the link with the 'secret' library file 'libsecret.a', set LIBS=-lsecret. Multiple libraries can be listed for linking, for example LIBS=-lsecret -ltest

## Creating static libraries
Create a separate project for each library, with all the required source files that go into it, and set the NAME option in the Makefile to the required <b>library basename</b>

Create a library with the following command:
``` 
make lib
``` 

If for example the library basename is 'example', the library will be compiled to <b><project_dir>/bin/libexample.a</b>

The compiled library must be manually copied to another project's lib directory for inclusion there. Don't forget to set the LIBS Makefile option in the latter project, e.g. LIBS=-lexample

## Build toolchain from source
1) clone this repo
2) Run the make_llvmtools.sh shell script. This isn't robust, but should do the trick. You need the essentials for compiling and making stuff, e.g. using apt-get install build-essential, but also ninja. This is a hefty build that takes a long time and a lot of memory. About 30min on my AMD 4650, taking up 14-15GB of memory. When it finishes, all binary tools are in the ./release/bin folder
3) Perform a 'make clean;make all' to build the Agon libraries

## Toolchain components
- Clang 15.0 C/C++ compiler, emitting ez80 code, forked from (https://github.com/CE-Programming/llvm-project) and patched to output GNU-AS compatible assembly syntax
- GNU AS assembler, compiled to accept ez80 syntax and output ez80-none-elf objects
- GNU LD linker, compiled to link ez80-none-elf objects
- A significant portion of code from the [AgDev](https://github.com/pcawte/AgDev) toolchain, which is an extension of the [CEDev](https://ce-programming.github.io/toolchain/index.html) toolchain to target the Agon platform

## Known limits
- My LLVM fork (https://github.com/envenomator/llvm-project) it set up to never output the special 'JQ' meta mnemonic, that a back-end assembler can translate to either 'JR' or 'JP' depending on the distance. Any potential 'JQ' emits are always translated to 'JP', as the GNU Assembler doesn't support 'JQ'. I haven't seen any 'JQ' being emitted in any of my test; it may be that it's behaviour has changed somewhere in the past, however I'd like to make sure it never poses a problem with a GNU Assembler back-end. I do see that the LLVM compiler emits both 'JR' and 'JP' mnemonics where appropriate.

