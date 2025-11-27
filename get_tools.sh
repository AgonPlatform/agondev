#!/bin/bash
set -e

# Environment
OS_NAME="$(uname -s | tr 'A-Z' 'a-z')"    # darwin or linux
ARCH="$(uname -m | tr 'A-Z' 'a-z')"       # arm64, x86_64, etc.

ASSET="agondev-${OS_NAME}_${ARCH}.tar.gz"

# Directories
RELEASE_BIN_DIR=./release/bin
DOWNLOAD=./download

mkdir -p "$DOWNLOAD"
cd "$DOWNLOAD"

echo "[ Downloading $ASSET ]"
URL="https://github.com/AgonPlatform/agondev/releases/latest/download/$ASSET"

# Download the asset, following redirects
curl -L -o "$ASSET" "$URL"

echo "[ Unpacking tools ]"
tar xf "$ASSET"
cd ..

rm -rf "$RELEASE_BIN_DIR"
echo "[ Copying tools to release ]"
cp -R "$DOWNLOAD/agondev/bin" "$RELEASE_BIN_DIR"

echo "[ Done ]"

