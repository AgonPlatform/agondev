# Linux Installation

Assuming Ubuntu Linux for this installation guide.

Terminal-based (command-line) installation steps
## 1 - Update and upgrade your distribution
```
sudo apt-get update && sudo apt-get -y upgrade
```
## 2 - Install the minimal required packages for building projects
```
sudo apt install -y build-essential git make
```
## 3 - Download the Agondev release package.
The latest stable release can be downloaded with:
```
wget https://github.com/AgonPlatform/agondev/releases/latest/download/agondev-linux_x86_64.tar.gz
```
The nightly release can be downloaded with:
```
wget https://github.com/AgonPlatform/agondev/releases/download/nightly/agondev-linux_x86_64.tar.gz
```
## 4 - Unpack the release package
```
tar xvfz agondev-linux_x86_64.tar.gz -C ~
```
The release is now available in the your $HOME/agondev folder

## 5 - Set the PATH
To set the PATH to the Agondev binaries at (bash) shell startup and activate it immediately, use
```
echo "PATH=$HOME/agondev/bin:\$PATH" >> ~/.bashrc && source ~/.bashrc
```
## 6 - Building Hello_world
Try making the hello_world program in the examples folder
```
cd ~/agondev/examples/hello_world
```
```
make
```
This should make 'hello.bin' in the 'bin' folder, which you can copy over to your Agon. 
