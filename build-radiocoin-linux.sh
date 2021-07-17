sh autogen.sh
 ./configure --with-incompatible-bdb --prefix=/usr --enable-sse2
make -j24
make -j24 install
