# RADIOACTIVE !!



<br>
for RADIOCOIN-electrum https://github.com/c4pt000/electrum-radiocoin
<br>
for DOGECOIN-electrum https://github.com/c4pt000/electrum-dogecoin
<br>



# fedora 34

```
yum groupinstall "C Development Tools and Libraries" -y

wget https://raw.githubusercontent.com/rpmsphere/x86_64/master/c/checkinstall-1.6.2-1.x86_64.rpm
yum install checkinstall-1.6.2-1.x86_64.rpm -y


yum install git-core libdb-cxx-devel libdb-cxx openssl-devel 
libevent-devel cppzmq-devel qrencode-devel qt5-qtbase-devel.x86_64 
protobuf-devel boost-* boost-devel miniupnpc-devel.x86_64 
diffutils qt-devel qt4-devel wget qt5-lin* alien dpkg -y

sh autogen.sh
 ./configure --with-incompatible-bdb --prefix=/usr --enable-sse2
make -j24 (or number of cores for -j)

then either checkinstall here for rpms

checkinstall --install=no --exclude=/sys/fs/selinux
alien --scripts --to-rpm (the-debian-package.here.deb)

then make -j24 install for local install to /usr
```
# Android

# free version
send to send fixed with android
<br>
desktop wallet QR still works as before with this app 
<br>
(paper wallet sweep is still not working **WIP)
<br>
https://github.com/c4pt000/radiocoin/releases/download/android-send-to-send-qr-fixed/RadioCoin-Android-signed.apk

# paid version $1.00 (support my work to help with server costs, beer and cigarettes, living needs, more crypto development)

https://play.google.com/store/apps/details?id=org.apache.cordova.radiocoin.wallet

<img src="https://raw.githubusercontent.com/c4pt000/radiocoin/master/Screenshot_20210926-082345-228.png" alt="https://play.google.com/store/apps/details?id=org.apache.cordova.radiocoin.wallet" width="450"/>

