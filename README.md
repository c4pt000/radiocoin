WIP** (3 days+)
 
* BIP34 has been reset to 0 block
radiocoind 
```
 yum install libdb-cxx-devel-5.3.28-46.fc34.x86_64 miniupnpc-devel-2.2.2-1.fc34.x86_64 zeromq-devel-4.3.4-1.fc34.x86_64 boost*-y
```

sample conf
/root/.radiocoin/radiocoinconf set accordingly
----------------------------
```
rpcuser=YOURrpcUSER
rpcpassword=YOURrpcPASS
rpcport=9332
port=9333
addnode=162.216.17.71
listen=1
upnp=1
daemon=1

```



# testing frontend through REGtest
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/mined-minted.png)
```
radiocoind -regtest -port=1111 -datadir=./ -rpcport=1234 -deprecatedrpc=generate --daemon
radiocoin-qt -regtest -port=2222 -datadir=./newreg -rpcport=5467 -deprecatedrpc=generate --daemon
```
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>


# regtest
```
 radiocoind -regtest -port=1111 -datadir=./ -rpcport=1234 -deprecatedrpc=generate --daemon
 radiocoind -regtest -port=2222 -datadir=./newreg -rpcport=5467 -deprecatedrpc=generate --daemon
 
alias node1="radiocoin-cli -regtest -datadir=./ -rpcport=1234"
alias node2="radiocoin-cli -regtest -datadir=./newreg -rpcport=5467"


 
 
 Call a RPC-Method on both nodes to check that they’re up and running:

node1 getblockchaininfo
node2 getblockchaininfo



Introduce the nodes to each other and mine some blocks
Register node2 as peer on node1:


node1 addnode "127.0.0.1:2222" "add"


Mine the genesis block on node1:


node1 generate 1


Check account balance:


node1 getbalance


node1 generate 1
[
  "5c684e70cd96928bdf01820a0a60ecdc38d53bd02bea4d7804a632f97f0b7ba3"
]
[root@localhost /]# node1 getbalance
2600.00000000


 
```
todo:
https://stackoverflow.com/questions/47828172/encountering-readblockfromdisk-errors-in-block-header-at-cblockdiskposnfile-0/48606397#48606397

https://bitcoin.stackexchange.com/questions/67060/error-readblockfromdisk-errors-in-block-header-at-cblockdiskposnfile-0-npos


# MAIN
```
mkdir anode
mkdir bnode
radiocoind -listen -noconnect -bind=127.0.0.1 -addnode=127.0.0.1 -port=1111 -datadir=./anode -rpcport=1234  -deprecatedrpc=generate --daemon
radiocoind -listen -noconnect -bind=127.0.0.1 -addnode=127.0.0.1 -port=2222 -datadir=./bnode -rpcport=5467  -deprecatedrpc=generate --daemon



alias node1="radiocoin-cli -datadir=./anode -rpcport=1234"
alias node2="radiocoin-cli -datadir=./bnode -rpcport=5467"


Call a RPC-Method on both nodes to check that they’re up and running:

node1 getblockchaininfo
node2 getblockchaininfo

              Introduce the nodes to each other and mine some blocks
              Register node2 as peer on node1:


node1 addnode "127.0.0.1:2222" "add"


Mine the genesis block on node1:


node1 generate 1


Check account balance:

node1 getbalance

node1 generate 1

[
  "5c684e70cd96928bdf01820a0a60ecdc38d53bd02bea4d7804a632f97f0b7ba3"
]

[root@localhost /]# node1 getbalance
2600.00000000
```

```
#!/bin/bash

radiocoind -listen -addnode=45.33.72.145 -addnode=172.104.97.114 -server -bind=127.0.0.1 &
```
https://medium.com/@kay.odenthal_25114/create-a-private-bitcoin-network-with-simulated-mining-b35f5b03e534





todo: mine block 0 
https://github.com/c4pt000/cpp_miner
```
$ cpp_miner mine <blockHeader 80B-hex> OR <version 4B-hex> <hashPrevBlock 32B-hex> <merkleRoot 32B-hex> <time 4B-hex> <nBits 4B-hex> <nonce 4B-hex>
$ cpp_miner genesisgen <pubkey 65B-hex> "<coinbase-message 91B-string>" <value 8B-decimal> <time 4B-hex> <nBits 4B-hex> <nonce 4B-hex>



 cpp_miner mine 

<blockHeader 80B-hex> OR <version 4B-hex> <hashPrevBlock 32B-hex> <merkleRoot 32B-hex> <time 4B-hex> <nBits 4B-hex> <nonce 4B-hex>


genesis = CreateGenesisBlock(1621321415, 0x00000003, 545259519, 1, 1000000000 * COIN);
const char* pszTimestamp = "in music we trust";

04c671ae19bc3a3acf1bfec3930653029cf9fc5681376ea12e8593b76dbe8d85d611f09b4190c219f8ac38999a5ad0c431d70b72d21744513db6e2304b94d25bad

hash->("0x4f014ebd57f5d6342f8dfa723e08d3401f92a83464fc66a0ef732325659d756a")
merkle->	("0x7528171112285616586b9702910b8474013da81d2d37776ff56c881f45126b95")


 ParseHex("04c671ae19bc3a3acf1bfec3930653029cf9fc5681376ea12e8593b76dbe8d85d611f09b4190c219f8ac38999a5ad0c431d70b72d21744513db6e2304b94d25bad") << OP_CHECKSIG;



cpp_miner mine 	0x00000003  0x4f014ebd57f5d6342f8dfa723e08d3401f92a83464fc66a0ef732325659d756a 0x7528171112285616586b9702910b8474013da81d2d37776ff56c881f45126b95 1621321415 1000000000 545259519
```

# radioCOIN (needs nodes testing at block 0 genesis block might be configured wrong)

# to help the music industry secure money from the loss of recordable music and mp3 leaks, and to control noisy car radios with fees for playing the volume too loud at odd hours

requires requires boost-1.75

cat /root/.radiocoin/debug.log
```
2021-05-21T05:57:47Z LoadBlockIndexDB: last block file = 0
2021-05-21T05:57:47Z LoadBlockIndexDB: last block file info: CBlockFileInfo(blocks=0, size=0, heights=0...0, time=1970-01-01...1970-01-01)
```
```
2021-05-21T05:57:47Z 
2021-05-21T05:57:47Z RadioCoin Core version v0.18.1.0-e4beaa4-dirty (release build)
2021-05-21T05:57:47Z Assuming ancestors of block b34a457c601ef8ce3294116e3296078797be7ded1b0d12515395db9ab5e93ab8 have valid signatures.
2021-05-21T05:57:47Z Setting nMinimumChainWork=0000000000000000000000000000000000000000000002ee655bf00bf13b4cca
2021-05-21T05:57:47Z Using the 'sse4(1way),sse41(4way),avx2(8way)' SHA256 implementation
2021-05-21T05:57:47Z Using RdRand as an additional entropy source
2021-05-21T05:57:47Z Default data directory /root/.radiocoin
2021-05-21T05:57:47Z Using data directory /root/.radiocoin
2021-05-21T05:57:47Z Config file: /root/.radiocoin/radiocoin.conf (not found, skipping)
2021-05-21T05:57:47Z Using at most 125 automatic connections (1024 file descriptors available)
2021-05-21T05:57:47Z Using 16 MiB out of 32/2 requested for signature cache, able to store 524288 elements
2021-05-21T05:57:47Z Using 16 MiB out of 32/2 requested for script execution cache, able to store 524288 elements
2021-05-21T05:57:47Z Using 16 threads for script verification
2021-05-21T05:57:47Z scheduler thread start
2021-05-21T05:57:47Z Using wallet directory /root/.radiocoin/wallets
2021-05-21T05:57:47Z init message: Verifying wallet(s)...
2021-05-21T05:57:47Z Using BerkeleyDB version Berkeley DB 5.3.28: (September  9, 2013)
2021-05-21T05:57:47Z Using wallet /root/.radiocoin/wallets
2021-05-21T05:57:47Z BerkeleyEnvironment::Open: LogDir=/root/.radiocoin/wallets/database ErrorFile=/root/.radiocoin/wallets/db.log
2021-05-21T05:57:47Z init message: Loading banlist...
2021-05-21T05:57:47Z ERROR: DeserializeFileDB: Failed to open file /root/.radiocoin/banlist.dat
2021-05-21T05:57:47Z Invalid or missing banlist.dat; recreating
2021-05-21T05:57:47Z Cache configuration:
2021-05-21T05:57:47Z * Using 2.0 MiB for block index database
2021-05-21T05:57:47Z * Using 8.0 MiB for chain state database
2021-05-21T05:57:47Z * Using 440.0 MiB for in-memory UTXO set (plus up to 286.1 MiB of unused mempool space)
2021-05-21T05:57:47Z init message: Loading block index...
2021-05-21T05:57:47Z Opening LevelDB in /root/.radiocoin/blocks/index
2021-05-21T05:57:47Z Opened LevelDB successfully
2021-05-21T05:57:47Z Using obfuscation key for /root/.radiocoin/blocks/index: 0000000000000000
2021-05-21T05:57:47Z LoadBlockIndexDB: last block file = 0
2021-05-21T05:57:47Z LoadBlockIndexDB: last block file info: CBlockFileInfo(blocks=0, size=0, heights=0...0, time=1970-01-01...1970-01-01)
2021-05-21T05:57:47Z Checking all blk files are present...
2021-05-21T05:57:47Z Initializing databases...
2021-05-21T05:57:47Z Pre-allocating up to position 0x1000000 in blk00000.dat
2021-05-21T05:57:47Z Opening LevelDB in /root/.radiocoin/chainstate
2021-05-21T05:57:47Z Opened LevelDB successfully
2021-05-21T05:57:47Z Wrote new obfuscate key for /root/.radiocoin/chainstate: 59cf85edd5d4ab5d
2021-05-21T05:57:47Z Using obfuscation key for /root/.radiocoin/chainstate: 59cf85edd5d4ab5d
2021-05-21T05:57:47Z init message: Rewinding blocks...
2021-05-21T05:57:47Z  block index             245ms
2021-05-21T05:57:47Z init message: Loading wallet...
2021-05-21T05:57:47Z BerkeleyEnvironment::Open: LogDir=/root/.radiocoin/wallets/database ErrorFile=/root/.radiocoin/wallets/db.log
2021-05-21T05:57:48Z [default wallet] nFileVersion = 180100
2021-05-21T05:57:48Z [default wallet] Keys: 0 plaintext, 0 encrypted, 0 w/ metadata, 0 total. Unknown wallet records: 0
2021-05-21T05:57:48Z [default wallet] Performing wallet upgrade to 169900
2021-05-21T05:57:49Z [default wallet] keypool added 2000 keys (1000 internal), size=2000 (1000 internal)
2021-05-21T05:57:49Z [default wallet] Wallet completed loading in            1859ms
2021-05-21T05:57:49Z [default wallet] setKeyPool.size() = 2000
2021-05-21T05:57:49Z [default wallet] mapWallet.size() = 0
2021-05-21T05:57:49Z [default wallet] mapAddressBook.size() = 0
2021-05-21T05:57:49Z ERROR: ReadBlockFromDisk: Errors in block header at CDiskBlockPos(nFile=0, nPos=8)
2021-05-21T05:57:49Z *** Failed to read block
2021-05-21T05:57:49Z Error: Error: A fatal internal error occurred, see debug.log for details
```

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
 
  optional to make deb package and or rpm package
  -----------------------------------------------
  checkinstall --install=no --exclude=/sys/fs/selinux
  alien --scripts --to-rpm radio*.deb

  
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
