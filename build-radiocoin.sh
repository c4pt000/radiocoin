#!/bin/bash
sh autgen.sh
./configure --with-incompatible-bdb --prefix=/usr --enable-sse2
make -j24 clean
make -j24
make -j24 install
