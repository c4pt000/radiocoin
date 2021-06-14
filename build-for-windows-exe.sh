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


echo "DONT FORGET TO CHANGE COMPILER BOTH MINGW-GCC AND MINGW-G++ TO POSIX SINCE WINDOWS DOESNT REALLY SUPPORT MUTEX WITH SPINLOCKS"
echo "
update-alternatives --config x86_64-w64-mingw32-g++
There are 2 choices for the alternative x86_64-w64-mingw32-g++ (providing /usr/bin/x86_64-w64-mingw32-g++).

  Selection    Path                                   Priority   Status
------------------------------------------------------------
  0            /usr/bin/x86_64-w64-mingw32-g++-win32   60        auto mode
* 1            /usr/bin/x86_64-w64-mingw32-g++-posix   30        manual mode
  2            /usr/bin/x86_64-w64-mingw32-g++-win32   60        manual mode

Press <enter> to keep the current choice[*], or type selection number: 



update-alternatives --config x86_64-w64-mingw32-gcc
There are 2 choices for the alternative x86_64-w64-mingw32-gcc (providing /usr/bin/x86_64-w64-mingw32-gcc).

  Selection    Path                                   Priority   Status
------------------------------------------------------------
  0            /usr/bin/x86_64-w64-mingw32-gcc-win32   60        auto mode
* 1            /usr/bin/x86_64-w64-mingw32-gcc-posix   30        manual mode
  2            /usr/bin/x86_64-w64-mingw32-gcc-win32   60        manual mode

Press <enter> to keep the current choice[*], or type selection number: 


"

make -j200    				#(where 200 is cpu core count)
sleep 2s
echo "whats a cyberpunk thriller without money for radios anyway?"

