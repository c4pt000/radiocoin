#!/bin/sh

yum update -y
yum groupinstall "C Development Tools and Libraries" -y

# skip for just the qt desktop binary
yum install --exclude=*nvidia* mesa* xorg* caja -y

yum install git-core libdb-cxx-devel libdb-cxx openssl-devel \
libevent-devel cppzmq-devel qrencode-devel qt5-qtbase-devel \
protobuf-devel boost-* boost-devel miniupnpc-devel \
diffutils qt-devel qt4-devel wget qt5-lin* alien dpkg qt5-qtbase -y
