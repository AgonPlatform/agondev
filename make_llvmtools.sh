#!/usr/bin/bash

INSTALLDIR=$(pwd)/llvm-build/ez80-none-elf
LVMDIR=llvm-project

BINUTILS=binutils-2.43

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

if [ ! -f "$INSTALLDIR/bin/ez80-none-elf-ld" ]; then
  echo "Downloading BINUTILS"
  pushd . >/dev/null
  curl -LO https://ftp.gnu.org/gnu/binutils/$BINUTILS.tar.gz
  tar xf $BINUTILS.tar.gz
  cd $BINUTILS \
      && ./configure --target=z80-none-elf --program-prefix=ez80-none-elf- --prefix=$INSTALLDIR \
      && make -j4 \
      && make install
  if [ ! -f "$INSTALLDIR/bin/ez80-none-elf-ld" ]; then
    echo "Error compiling BINUTILS"
  fi
  popd >/dev/null
else
   echo "BINUTILS in place" 
fi
echo "Cleaning up"
rm -f $BINUTILS.tar.gz
rm -rf $BINUTILS
