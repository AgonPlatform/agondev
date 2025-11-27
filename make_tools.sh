#!/bin/bash

BUILD_LLVM=yes
BUILD_BINUTILS=yes
BUILD_AGONTOOLS=yes
BUILD_HEXLOADSEND=yes

# Immediately stop on any error
set -e

#Directories
INSTALLDIR=$(pwd)/llvm-build/ez80-none-elf
LVMDIR=llvm-project
RELEASE_BIN_DIR=./release/bin

#Versions
BINUTILS=binutils-2.45

# Prepare release directory
mkdir -p $RELEASE_BIN_DIR

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
if ! command -v python3 &> /dev/null
then
    echo "Error: python3 is not installed or not in PATH."
    exit 1
fi

# Build LLVM
if [ "${BUILD_LLVM}" == "yes" ]; then
  echo "[ Building LLVM ]"
  pushd . >/dev/null
  if [ ! -d "$LVMDIR" ]; then
    git clone --branch z80-as --depth 1 https://github.com/envenomator/llvm-project.git
  else
    echo "[ Skip cloning $LVMDIR ]"
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
  # Copy to release directory
  cp llvm-build/ez80-none-elf/bin/clang $RELEASE_BIN_DIR/ez80-none-elf-clang
  echo "[ Done building LLVM ]"
else
  echo "[ Configured to skip LLVM build ]"
fi

# Build BINUTILS
if [ "${BUILD_BINUTILS}" == "yes" ]; then
  echo "[ Building $BINUTILS ]"
  pushd . >/dev/null
  rm -rf $BINUTILS
  if [ ! -f "$BINUTILS.tar.gz" ]; then #skip downloading if already in place
    echo "[ Downloading $BINUTILS ]"
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
    echo "[ Error building $BINUTILS ]"
  else
    echo "[ Done building $BINUTILS ]"
  fi
  popd >/dev/null
  # Copy to release directory
  cp llvm-build/ez80-none-elf/bin/ez80-none-elf-* $RELEASE_BIN_DIR
else
  echo "[ Configured to skip BINUTILS build ]"
fi

# Build Agon tools
if [ "${BUILD_AGONTOOLS}" == "yes" ]; then
  echo "[ Building agondev-setname ]"
  pushd . >/dev/null
  cd src/tools/agondev-setname
  make clean;make
  popd >/dev/null
  echo "[ Done building agondev-setname ]"
  echo "[ Building agondev-config ]"
  pushd . >/dev/null
  cd src/tools/agondev-config
  make clean;make
  popd >/dev/null
  echo "[ Done building agondev-config ]"
  # Copy to release directory
  cp src/tools/agondev-setname/bin/* $RELEASE_BIN_DIR
  cp src/tools/agondev-config/bin/* $RELEASE_BIN_DIR
else
  echo "[ Configured to skip building Agon tools ]"
fi

if [ "${BUILD_HEXLOADSEND}" == "yes" ]; then
  echo "[ Building hexload send binary ]"
  python3 -m venv venv
  source venv/bin/activate
  pip install pyserial crcmod intelhex
  pip install pyinstaller
  pyinstaller -F ./scripts/hexload-send.py
  deactivate
  echo "[ Done building hexload send binary ]"
  # Copy to release directory
  cp ./dist/hexload-send* $RELEASE_BIN_DIR
else
  echo "[ Configured to skip building Hexload send ]"
fi
echo "[ Make tools done ]"
