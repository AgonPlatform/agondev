# AGON dev C/C++ toolchain
## Status
Early access Alpha: things will break.

The toolchain is currently compiled for Linux only.

I'm not ready to accept issues or PRs at this time. Contact me at [Discord](https://discord.gg/A7rY9AcF) to discuss
## Purpose
To assemble a C/C++ toolchain, based on modern, open-source software that can be ported to many platforms
## Installation
- Download and extract the release.gz file from the releases tab, to a path <b>without any space</b>, e.g. /home/user/agondev
- Extend the PATH environment variable to point to agondev/bin. Example:

``` 
export PATH=/<insert path to agondev>/bin:$PATH
```

## Toolchain components
- Clang 15.0 C/C++ compiler, emitting ez80 code, forked from (https://github.com/CE-Programming/llvm-project) and patched to output GNU-AS compatible assembly syntax
- GNU AS assembler, compiled to accept ez80 syntax and output ez80-none-elf objects
- GNU LD linker, compiled to link ez80-none-elf objects
- A significant portion of code from the [AgDev](https://github.com/pcawte/AgDev) toolchain, which is an extension of the [CEDev](https://ce-programming.github.io/toolchain/index.html) toolchain to target the Agon platform

## Compiling programs
Check out the provided example programs, which have a slightly different top-level Makefile with options that are similar to what AgDev provides.

All source files need to be placed under a project's <b>./src</b> directory.

.c / .cpp / .s / .asm / .src sources will be compiled / assembled directly to an ELF-formatted object file in <b>./obj</b>

The linker will link all objects together with the provided libaries (libc / agon / fp / crt) and create a binary in <b>./bin</b>

## Makefile options
The following options can be set in the user's project Makefile:
- RAM_START - sets the load/start address of the compiled program. This option will default to 0x040000
- RAM_SIZE - sets the amount of memory available to the program. This option will default to 0x070000. The init routine will set the stackpointer to RAM_START + RAM_END
- LDHAS_ARG_PROCESSING - if set to 0, this will make use of simple commandline processing of program arguments. If set to 1, this will make use of additional code to process redirection and quoting.
- LDHAS_EXIT_HANDLER - set this to 1, to print out an error text based on the program's exit code, before returning to MOS. MOS interprets anything non-zero a file-error. If your program prints it's own error messages upon exit, set this option to 0. 

## Build toolchain from source
1) clone this repo
2) Run the make_llvmtools.sh shell script. This isn't robust, but should do the trick. You need the essentials for compiling and making stuff, e.g. using apt-get install build-essential, but also ninja. This is a hefty build that takes a long time and a lot of memory. About 30min on my AMD 4650, taking up 14-15GB of memory. When it finishes, all binary tools are in the ./bin folder
3) Perform a 'make clean;make all' to build the Agon libraries

## Known limits
- My LLVM fork (https://github.com/envenomator/llvm-project) it set up to never output the special 'JQ' meta mnemonic, that a back-end assembler can translate to either 'JR' or 'JP' depending on the distance. Any potential 'JQ' emits are always translated to 'JP', as the GNU Assembler doesn't support 'JQ'. I haven't seen any 'JQ' being emitted in any of my test; it may be that it's behaviour has changed somewhere in the past, however I'd like to make sure it never poses a problem with a GNU Assembler back-end. I do see that the LLVM compiler emits both 'JR' and 'JP' mnemonics where appropriate.

## Unknown limits
unknown_limits = INFINITE - known_limits;
