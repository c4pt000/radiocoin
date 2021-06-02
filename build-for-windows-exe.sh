#!/bin/bash
echo "requires mingw32 as a build environment, the script will pause for 10 seconds, i'll dream in bogomips how great virtualized environments can be,"
sleep 10s
#mkdir /opt/winradio
#or from docker run -it -d -v /opt/winradio:/opt/winradio ubuntu:20.10
#docker exec -it <docker_random_hash_> bash
#as root

#for ubuntu:
#apt-get update && apt-get install git-core build-essential nano sudo -y
#as root:
# apt-get update && apt-get upgrade && apt-get install apt aptitude apt-file wget nano build-essential git-core build-essential libtool autotools-dev automake pkg-config bsdmainutils curl git sudo nsis g++-mingw-w64-x86-64 protobuf* -y
# apt-get install *mingw* g++-mingw-w64-x86-64 mingw-w64-x86-64-dev -y

#or from docker run -it -d -v /opt/winradio:/opt/winradio fedora:34

  yum groupinstall "C Development Tools and Libraries" -y
 
  yum install git-core libdb-cxx-devel libdb-cxx openssl-devel libevent-devel cppzmq-devel qrencode-devel \
  qt5-qtbase-devel.x86_64 qt5-linguist-5.15.2-5.fc34.x86_64 \
  boost-devel miniupnpc-devel.x86_64 diffutils \
  qt-devel qt4-devel wget nano sudo wget *mingw* protobuf* \
  glibc-headers-x86-2.33-8.fc34.noarch libdb-cxx-devel libdb-cxx \
   boost-* openssl-devel libevent-devel -y



#cd /opt/winradio
#git clone https://github.com/c4pt000/radioCOIN
#cd radioCOIN
#then as always install more of the general dependencies:


#Then build using: (windows x86_64 64bit .exe binaries)

cd depends
make HOST=x86_64-w64-mingw32
cd ..
./autogen.sh 				# not required when building from tarball
CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --with-incompatible-bdb --prefix=/usr --enable-sse2
make -j200    				#(where 200 is cpu core count)
sleep 2s
echo "whats a cyberpunk thriller without money for radios anyway?"

# fedora build for linux + mingw32 windows64 build
