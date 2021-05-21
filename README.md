# radioCOIN

# to help the music industry secure money from the loss of recordable music and mp3 leaks, and to control noisy car radios with fees for playing the volume too loud at odd hours

requires requires boost-1.75

```
optional ->  yum groupinstall "C Development Tools and Libraries" -y
yum install git-core libdb-cxx-devel libdb-cxx openssl-devel libevent-devel java-11-openjdk-devel cppzmq-devel  qrencode-devel qt5-qtbase-devel.x86_64 qt5-linguist-5.15.2-5.fc34.x86_64 protobuf-devel  cargo boost* boost-devel miniupnpc-devel.x86_64 diffutils qt-devel qt4-devel wget -y

wget https://github.com/c4pt000/radioCOIN/releases/download/1.1.0-fedora34-build-environment/radiocoin-1.1.0_fedora34-2.x86_64.rpm
 
for selinux 4kb error
--------------------
cp -rf radiocoin-1.1.0_fedora34-2.x86_64.rpm /
rpm2cpio radiocoin-1.1.0_fedora34-2.x86_64.rpm | cpio -idmv
```
ubuntu 20.10 requires boost-1.75
```

apt-get install libzmq* boost* -y

wget https://boostorg.jfrog.io/artifactory/main/release/1.75.0/source/boost_1_75_0.tar.gz


```
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/src/qt/res/icons/paper_wallet.png.back.png)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/src/qt/res/icons/paper_wallet.png.front.png)
* fedora 34
source build
```
 yum groupinstall "C Development Tools and Libraries" -y
 
 yum install git-core libdb-cxx-devel libdb-cxx openssl-devel libevent-devel java-11-openjdk-devel cppzmq-devel \
 qrencode-devel qt5-qtbase-devel.x86_64 qt5-linguist-5.15.2-5.fc34.x86_64 protobuf-devel opencv-devel.x86_64 \
 opencv-devel-4.5.2-1.fc34.x86_64 cargo boost* boost-devel miniupnpc-devel.x86_64 diffutils qt-devel qt4-devel -y
 
 ./autogen.sh

 ./configure --with-incompatible-bdb --prefix=/usr --enable-sse2
  
  make -j24
  make -j24 install
  
  radiocoin-qt
  or radiocoind      (radiocoin-cli getinfo)
```

RadioCoin Core integration/staging tree
=====================================

[![Build Status](https://travis-ci.org/radiocoin-project/radiocoin.svg?branch=master)](https://travis-ci.org/radiocoin-project/radiocoin)

https://radiocoin.org

What is RadioCoin?
----------------

RadioCoin is an experimental digital currency that enables instant payments to
anyone, anywhere in the world. RadioCoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. RadioCoin Core is the name of open source
software which enables the use of this currency.

For more information, as well as an immediately useable, binary version of
the RadioCoin Core software, see [https://radiocoin.org](https://radiocoin.org).

License
-------

RadioCoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/radiocoin-project/radiocoin/tags) are created
regularly to indicate new official, stable release versions of RadioCoin Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

The developer [mailing list](https://groups.google.com/forum/#!forum/radiocoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer IRC can be found on Freenode at #radiocoin-dev.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and macOS, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

We only accept translation fixes that are submitted through [Bitcoin Core's Transifex page](https://www.transifex.com/projects/p/bitcoin/).
Translations are converted to RadioCoin periodically.

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.
