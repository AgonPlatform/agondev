# MacOS Installation

Terminal-based (command-line) installation steps
## 1 - Install XCode
```
xcode-select --install
```
## 2 - Install Homebrew
Follow [the Homebrew installation guide](https://brew.sh/)

## 3 - Install required packages
Install packages required for building projects and installing the Agondev toolchain
```
brew install texinfo zlib wget
```
## 4 - Download the Agondev release package.
The latest stable release can be downloaded with:
```
wget https://github.com/AgonPlatform/agondev/releases/latest/download/agondev-darwin_arm64.tar.gz

```
The nightly release can be downloaded with:
```
wget https://github.com/AgonPlatform/agondev/releases/download/nightly/agondev-darwin_arm64.tar.gz
```
## 5 - Unpack the release package
```
tar xvfz agondev-darwin_arm64.tar.gz -C ~
```
The release is now available in the your $HOME/agondev folder

## 6 - Approve binaries
you need to explicitly approve all downloaded binaries under the ~/agondev/bin directory. I have supplied the following script to handle this for you.

Change to the agondev release directory
```
cd ~/agondev
```
And run the script with
```
./macos_remove_quarantine.sh
```
## 7 - Set the PATH
To set the PATH to the Agondev binaries at (zsh) shell startup and activate it immediately, use
```
echo "export PATH=\"$HOME/agondev/bin:\$PATH\"" >> ~/.zshrc && source ~/.zshrc
```
## 8 - Building Hello_world
Try making the hello_world program in the examples folder
```
cd ~/agondev/examples/hello_world
```
```
make
```
This should make 'hello.bin' in the 'bin' folder, which you can copy over to your Agon. 
