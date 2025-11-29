#!/bin/bash

# Immediately stop on any error
set -e

echo "[ Cleaning up ]"
rm -f *.tar.gz
rm -f hexload-send.spec
rm -rf build
rm -rf dist
rm -rf download
rm -rf llvm-build
rm -rf llvm-project
rm -rf venv
rm -rf release/bin
rm -rf release/lib
rm -rf agondev
echo "[ Done ]"
