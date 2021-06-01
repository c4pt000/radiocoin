#!/bin/bash
echo "requires ubuntu:20.* or docker with ubuntu:20.* as a build environment, the script will pause for 10 seconds, i'll dream in bogomips how great virtualized environments can be,"
sleep 10s
#mkdir /opt/winradio
#or from docker run -it -d -v /opt/winradio:/opt/winradio ubuntu:20.10
#docker exec -it <docker_random_hash_> bash
#as root

apt-get update && apt-get install git-core build-essential nano sudo -y

#cd /opt/winradio
#git clone https://github.com/c4pt000/radioCOIN
#cd radioCOIN
#then as always install more of the general dependencies:

#as root:

 apt-get update && apt-get upgrade && apt-get install apt aptitude apt-file wget nano build-essential git-core build-essential libtool autotools-dev automake pkg-config bsdmainutils curl git sudo nsis g++-mingw-w64-x86-64 protobuf* -y
 apt-get install *mingw* g++-mingw-w64-x86-64 mingw-w64-x86-64-dev -y

#Then build using: (windows x86_64 64bit .exe binaries)

cd depends
make HOST=x86_64-w64-mingw32
cd ..
./autogen.sh 				# not required when building from tarball
CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --prefix=/usr
make -j200    #(where 200 is cpu core count)
sleep 2s
echo "whats a cyberpunk thriller without money for radios anyway?"
