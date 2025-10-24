#!/bin/bash

BUILD_LLVM=yes
BUILD_BINUTILS=yes

#Directories
INSTALLDIR=$(pwd)/llvm-build/ez80-none-elf
LVMDIR=llvm-project

#Versions
BINUTILS=binutils-2.45

#Check tools
if ! command -v make &> /dev/null
then
    echo "Error: make is not installed or not in PATH."
    exit 1
fi
if ! command -v cmake &> /dev/null
then
    echo "Error: cmake is not installed or not in PATH."
    exit 1
fi
if ! command -v ninja &> /dev/null
then
    echo "Error: ninja is not installed or not in PATH."
    exit 1
fi
if ! command -v git &> /dev/null
then
    echo "Error: git is not installed or not in PATH."
    exit 1
fi
if ! command -v curl &> /dev/null
then
    echo "Error: curl is not installed or not in PATH."
    exit 1
fi

# Build LLVM
if [ "${BUILD_LLVM}" == "yes" ]; then
  pushd . >/dev/null
  if [ ! -d "$LVMDIR" ]; then
    git clone --branch z80-as --depth 1 https://github.com/envenomator/llvm-project.git
  else
    echo "Skip cloning $LVMDIR"
  fi
  cd $LVMDIR
  mkdir -p build
  cd build
  # Create make files
  cmake ../llvm -GNinja -DLLVM_ENABLE_PROJECTS="clang" \
      -DCMAKE_INSTALL_PREFIX=$INSTALLDIR \
      -DCMAKE_BUILD_TYPE=Release \
      -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=Z80 \
      -DLLVM_TARGETS_TO_BUILD= \
      -DLLVM_DEFAULT_TARGET_TRIPLE=ez80-none-elf
  # Build and install Clang 15 with ez80 support
  ninja install
  popd >/dev/null
else
  echo Configured to skip LLVM build
fi

# Build BINUTILS
if [ "${BUILD_BINUTILS}" == "yes" ]; then
  pushd . >/dev/null
  rm -rf $BINUTILS
  if [ ! -f "$BINUTILS.tar.gz" ]; then #skip downloading if already in place
    echo "Downloading $BINUTILS"
    curl -LO https://ftp.gnu.org/gnu/binutils/$BINUTILS.tar.gz
  fi
  echo Unpacking $BINUTILS
  tar xf $BINUTILS.tar.gz
  cd $BINUTILS
  # Detect if CC is Apple Clang and get major version, skip if using gcc.
  APPLE_CLANG_MAJOR=$(cc --version 2>&1 | grep -i "Apple clang" | cut -f 4 -d " " | cut -f 1 -d ".")
  if [ -n "$APPLE_CLANG_MAJOR" ]; then
    if [ "$APPLE_CLANG_MAJOR" -gt 16 ]; then
      echo Apple clang 17+ detected - using system zlib
      rm -rf zlib
    fi
  fi

  ./configure --target=z80-none-elf --program-prefix=ez80-none-elf- --prefix=$INSTALLDIR \
    && make -j4 \
    && make install
  if [ ! -f "$INSTALLDIR/bin/ez80-none-elf-ld" ]; then
    echo "Error compiling $BINUTILS"
  else
    echo "Done compiling $BINUTILS"
  fi
  popd >/dev/null
else
  echo Configured to skip BINUTILS build
fi
