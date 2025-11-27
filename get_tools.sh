#!/bin/bash

# Immediately stop on any error
set -e

#Repository
REPO=https://api.github.com/repos/AgonPlatform/agondev

#Environment
OS_NAME="$(uname -s | tr 'A-Z' 'a-z')"
ARCH="$(uname -m | tr 'A-Z' 'a-z')"

#Directories
RELEASE_BIN_DIR=./release/bin
DOWNLOAD=./download
ASSET="agondev-${OS_NAME}_${ARCH}.tar.gz"

#Check tools
if ! command -v curl &> /dev/null
then
    echo "Error: curl is not installed or not in PATH."
    exit 1
fi
if ! command -v jq &> /dev/null
then
    echo "Error: jq is not installed or not in PATH."
    exit 1
fi

echo [ Downloading $ASSET ]

mkdir -p $DOWNLOAD
cd $DOWNLOAD
curl -s $REPO/releases/latest \
  | jq -r --arg name "$ASSET" '.assets[] | select(.name==$name) | .browser_download_url' \
  | xargs -n 1 curl -LO

if [ ! -f "$ASSET" ]; then
    echo "Error: '$ASSET' does not exist in the latest release" >&2
    exit 1
fi

echo [ Unpacking tools ]
tar xf $ASSET
cd ..
rm -rf ./release/bin
echo [ Copying tools to release ]
cp -R $DOWNLOAD/agondev/bin $RELEASE_BIN_DIR
echo [ Done ]
