# RADIOACTIVE !!

# **ignore previous suggestions to use -j24 (even if a person doesnt have 24 cores in their system DO NOT USE THIS it can fill up the available amount of free memory with garbage and break the current compile, even though this does not make sense while using the make command and specifying 24 cores with -j24 you would think the compiler would only select all 8 cores and ignore everything after that since the system only has 4 cores or 8 cores when -j24 is specified.

# I notice that it creates an unseen memory problem when building code on systems with less than 8gb of RAM since it will use up all available memory on a system for unknown reasons

* 09-29-2021 update about previous android version (back in releases to restore first time wallets)

# see releases
```
Android send to send fixed with QR (store version works with android to android and desktop with camera QR codes)

fix-free version from releases only works with desktop QR codes but does not send from android to android (see store version)

store version does not restore wallets made with fix-free version
```

<br>
for RADIOCOIN-electrum https://github.com/c4pt000/electrum-radiocoin
<br>
for DOGECOIN-electrum https://github.com/c4pt000/electrum-dogecoin
<br>

* requires 4GB of memory to build

# fedora 34

```
yum groupinstall "C Development Tools and Libraries" -y

wget https://raw.githubusercontent.com/rpmsphere/x86_64/master/c/checkinstall-1.6.2-1.x86_64.rpm
yum install checkinstall-1.6.2-1.x86_64.rpm -y


yum install git-core libdb-cxx-devel libdb-cxx openssl-devel 
libevent-devel cppzmq-devel qrencode-devel qt5-qtbase-devel.x86_64 
protobuf-devel boost-* boost-devel miniupnpc-devel.x86_64 
diffutils qt-devel qt4-devel wget qt5-lin* alien dpkg -y

cd /root

 wget https://github.com/c4pt000/radiocoin/releases/download/bootstrap-DATADIR-block-117682/radiocoin-snapshot-CURRENT.tar.gz
 tar -xvf radiocoin-snapshot-CURRENT.tar.gz 
 cd /opt
 git clone https://github.com/c4pt000/radiocoin
 cd radiocoin/
 cp -rf radiocoin.conf /root/.radiocoin/radiocoin.conf
 sh autogen.sh
 ./configure --with-incompatible-bdb --prefix=/usr --enable-sse2

make -j4 (or number of cores for -j)

then either checkinstall here for deb package (then alien script for rpms)

checkinstall --install=no --exclude=/sys/fs/selinux
alien --scripts --to-rpm (the-debian-package.here.deb)

then make -j4 install for local install to /usr

radiocoind -reindex
or 
radiocoin-qt -reindex
```

# debian 10
```
 cd /root/
 wget https://github.com/c4pt000/radiocoin/releases/download/bootstrap-DATADIR-block-117682/radiocoin-snapshot-CURRENT.tar.gz
 tar -xvf radiocoin-snapshot-CURRENT.tar.gz 
 apt install aptitude
 cd /opt
 git clone https://github.com/c4pt000/radiocoin
 cd radiocoin/
 sh build-debian-deps.sh 
 cp -rf radiocoin.conf /root/.radiocoin/radiocoin.conf 
 sh autogen.sh 
 ./configure --with-incompatible-bdb --prefix=/usr --enable-sse2
 
 make -j4 (or number of cores for -j)

     then either checkinstall here for deb package (then alien script for rpms)
 
 checkinstall --install=no --exclude=/sys/fs/selinux
 alien --scripts --to-rpm (the-debian-package.here.deb)

     then make -j4 install for local install to /usr
     
     radiocoind -reindex
     or 
     radiocoin-qt -reindex
```

# Android

# paid version $1.00 (support my work to help with server costs, beer and cigarettes, living needs, more crypto development)

https://play.google.com/store/apps/details?id=org.apache.cordova.radiocoin.wallet

<img src="https://raw.githubusercontent.com/c4pt000/radiocoin/master/Screenshot_20210926-082345-228.png" alt="https://play.google.com/store/apps/details?id=org.apache.cordova.radiocoin.wallet" width="450"/>

