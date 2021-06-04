#!/bin/bash
echo "requires mingw32 ubuntu:20.10 as a build environment, the script will pause for 10 seconds, i'll dream in bogomips how great virtualized environments can be,"
sleep 10s
#mkdir /opt/winradio

#Then build using: (windows x86_64 64bit .exe binaries)


apt-get update -y 
apt-get install build-essential *mingw* aclocal automake libtool curl libdb* \
libboost* libssl-dev qt5-* -y


cd depends
make HOST=x86_64-w64-mingw32
cd ..
./autogen.sh 				# not required when building from tarball
CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --with-incompatible-bdb --prefix=/usr --enable-sse2
make -j200    				#(where 200 is cpu core count)
sleep 2s
echo "whats a cyberpunk thriller without money for radios anyway?"

