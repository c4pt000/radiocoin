
# RADIOACTIVE!! had to reset block 0 for peer to peer communication, 05-30-2021


* 05-31-2021 3pm
* for deploying docker ready image (requires docker)
```
yum install qemu-img caja xorg-* mesa-* -y

sudo dnf -y install dnf-plugins-core
 sudo dnf config-manager \
    --add-repo \
    https://download.docker.com/linux/fedora/docker-ce.repo


 sudo dnf install docker-ce docker-ce-cli containerd.io

systemctl start docker

systemctl enable docker (for starting docker at system startup)
```

```
yum install vim-common xorg-* mesa-* caja -y

wget https://raw.githubusercontent.com/c4pt000/radioCOIN/main/docker-RADIOCOIN

chmod +x docker-RADIOCOIN

mkdir -p /opt/radiocoin

docker-RADIOCOIN
```

a proper "reindex" to sync

run "with or without bootstrap.dat" in .radiocoin folder as bootstrap.dat

(and or check "debug.log" in .radiocoin ->          cat .radiocoin/debug.log   )

```
radiocoin-qt -reindex &
```
wait literally 2 or 3 minutes
close radiocoin-qt from the menu or force quit
then reopen 

```
radiocoin-qt &
```


```
same DOGE block reward design but for radiocoin (random between 0-1,000,000 RADC)

Block 1 — 100,000: 0-1,000,000 radiocoin(RADC)
Block 100,001 — 200,000: 0-500,000 radiocoin(RADC)
Block 200,001 — 300,000: 0-250,000 radiocoin(RADC)
Block 300,001 — 400,000: 0-125,000 radiocoin(RADC)
Block 400,001 — 500,000: 0-62,500 radiocoin(RADC)
Block 500,001 — 600,000: 0-31,250 radiocoin(RADC)

after network reaches 600,000 blocks on the entire network 10,000 RADC coins per 1 block reward
Block 600,001+: 10,000 radiocoin(RADC)

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



basic bootstrap to help push sync?
```
killall radiocoind
                                   where "root" is user
place bootstrap.CURRENT.dat -> /root/.radiocoin/bootstrap.dat
wget https://github.com/c4pt000/radioCOIN/raw/main/bootstrap.CURRENT.dat

radiocoind -reindex
radiocoin-cli getinfo
```
rejecting DOGE coin peers but using the dogecoin dns peers alongside of radiocoin peer transmissions
```
2021-05-31 06:06:27 receive version message: /Shibetoshi:1.14.3/: version 70015, blocks=3751589, us=45.56.81.243:39818, peer=24
2021-05-31 06:06:28 ERROR: AcceptBlockHeader: prev block not found
2021-05-31 06:06:28 Misbehaving: 64.98.101.27:22556 peer=24 (0 -> 10)
2021-05-31 06:06:28 ERROR: invalid header received
2021-05-31 06:06:28 ProcessMessages(headers, 162003 bytes) FAILED peer=24
```

# changes to GUI with QT,

the way the client displayed unconfirmed blocks before with a block not being "matured" to a full 30 or 31 network confirms
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/Immature-blocks-changed-unconfirmed.png)

changes to the GUI to display unconfirmed blocks waiting for 31 confirms as "Unconfirmed"
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/Unconfirmed-new.png)

05-31-2021 6am
```
made a change in src/chainparams.cpp from non standard 22556 to 9333

using 9333 with 22556 in src/chainparams.cpp during compile created some kind of port problem even when forcing port=9333 (instead of using default 22556)

with fresh compile
chainparams.cpp is now 9333 by default instead of dogecoin (22556)        (9333 litcoin port , 9332 litecoin-rpc)


packages in https://github.com/c4pt000/radioCOIN/releases/tag/experimental are still using default port 22556 for radiocoind mainnet
```

macOS
https://imgur.com/gallery/OfCyvXm

https://raw.githubusercontent.com/c4pt000/radioCOIN/main/block0-log-peer-to-peer.txt
https://raw.githubusercontent.com/c4pt000/radioCOIN/main/PEERinfo-getpeerinfo.txt      notice some peers allowing inbound peer to peer communication for sync

** STILL A WIP (android app / ios soon)

** rewrapping and building dns seeds to allow peers intercommunication to transmit updates to sync headers 11pm

* https://github.com/c4pt000/radioCOIN/raw/main/bootstrap-216.dat
```
rename to bootstrap.dat "current blockchain snapshot" early network at block 216

-> /home/user/.radiocoin/bootstrap.dat               -reindex then wait 10 seconds then shutdown and reopen without -reindex
```

#  June 1st as promised ? network seems semi-functional?

# WIP** (aiming to get bugs out for this to be a June 1st~31st coin?) <- sync issues between broadcast nodes



05-30-2021
```
STILL A WIP, having trouble syncing between remote nodes and two local test clients between linux and macos without bootstrap.dat

difficulty is low as with any starting network/fork as more blocks are mined with an interest in mining blocks the network "difficulty" will go up in value making it more difficult to mine blocks, after 600,000 blocks are mined the block reward will reduce from a random amount between 1->1,000,000 down to 10,000 coins per block (after block number 600,000 is mined) this model of radiocoin is the same network design as DOGECOIN just redesigned in terms of a different theme and anthem with different purpose,
```

* 05-29-2021 sync issues just built 8 nodes as a starting point check updated radiocoin.conf
```
place bootstrap -> /root/.radiocoin/
where /home/user/.radiocoin
is your directory
early 140 block boostrap for nodes
restart radiocoind or radiocoin-qt to load boostrap.dat

https://github.com/c4pt000/radioCOIN/raw/main/bootstrap.dat

where root is the current user 
```
```
cd /root/.radiocoin
wget https://github.com/c4pt000/radioCOIN/raw/main/bootstrap.dat
killall radiocoind
radiocoind -daemon -reindex   or radiocoin-qt -reindex &
radiocoin-cli getinfo
radiocoin-cli generate 1                 # to generate 1 block


to generate directly to a remote or local address (when confirmed by other blocks it is available after 31 mined blocks)
radiocoin-cli generatetoaddress 1 "to an address"              
```

# RADIOACTIVE!!   ** STILL A WIP (android app / ios soon)

macOS,fedora/rhel, debian/ubuntu 

![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/ACTIVE-radio.png)

still a work in progress, trying to mint block 0 so the network can propegate,
made changes for DOGE, instead of litecoin source, added paper-wallet back, fixed the "about"


same DOGE block reward design but for radiocoin (random between 0-1,000,000 RADC
```
Block 1 — 100,000: 0-1,000,000 radiocoin(RADC)
Block 100,001 — 200,000: 0-500,000 radiocoin(RADC)
Block 200,001 — 300,000: 0-250,000 radiocoin(RADC)
Block 300,001 — 400,000: 0-125,000 radiocoin(RADC)
Block 400,001 — 500,000: 0-62,500 radiocoin(RADC)
Block 500,001 — 600,000: 0-31,250 radiocoin(RADC)
Block 600,001+: 10,000 radiocoin(RADC)
```
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/block-reward-2.png)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/block-reward.png)



```
https://raw.githubusercontent.com/c4pt000/radioCOIN/main/radiocoin.conf
```
```
fedora/rhel

wget https://github.com/c4pt000/radioCOIN/releases/download/experimental/radiocoin-2.2.5_current_dns_exp-2.x86_64.rpm
or for debian based systems

wget https://github.com/c4pt000/radioCOIN/releases/download/experimental/radiocoin_2.2.5-current-dns-exp-1_amd64.deb


macOS

install and to (reindex) -> wget https://github.com/c4pt000/radioCOIN/releases/download/experimental/RadioCoin-Qt.dmg







--------------------------
cp -rf bootstrap.dat && radiocoin.conf -> (where c4pt is *YOUR* user account) 

cd /Users/c4pt/Library/Application\ Support/RadioCoin/

wget https://github.com/c4pt000/radioCOIN/blob/main/bootstrap.dat

edit radiocoin.conf (a unique rpcuser a unique rpcpassword)
wget https://raw.githubusercontent.com/c4pt000/radioCOIN/main/radiocoin.conf

ls -lah
bootstrap.dat 
radiocoin.conf


cd /Applications/RadioCoin-Qt.app/Contents/MacOS

./RadioCoin-Qt -reindex &

to check debug.log (where c4pt is your user account)
cat /Users/c4pt/Library/Application\ Support/RadioCoin/debug.log

then quit RadioCoin-Qt and restart if stuck with indexing

./RadioCoin-Qt &           or run the app directly from the Dock


```
```
{
  "version": 1140300,
  "protocolversion": 70015,
  "walletversion": 130000,
  "balance": 0.00000000,
  "blocks": 0,
  "timeoffset": 0,
  "connections": 8,
  "proxy": "",
  "difficulty": 0.000244140625,
  "testnet": false,
  "keypoololdest": 1622318528,
  "keypoolsize": 100,
  "paytxfee": 0.00000000,
  "relayfee": 1.00000000,
  "errors": ""
}
```

  yum install radiocoin-2.1.1_exp-2.x86_64.rpm -y
  

# RADIOCOIN POOL
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/RADIOCOIN-POOL.png)

```
"chain": "main",
  "blocks": 0,
  "headers": 0,
  "bestblockhash": "000002e2e76fef07722c875e9a68b1ce32bd2964e2df8ce70d9d31ab263f5fd2",
  "difficulty": 0.000244140625,
  "mediantime": 1622171724,
  "verificationprogress": 1.330529405468109e-08,
  "initialblockdownload": true,
  "chainwork": "0000000000000000000000000000000000000000000000000000000000100010",
  "size_on_disk": 486,
  "pruned": false,
```

```
mkdir anodes

radiocoind -listen -upnp=1 -bind=127.0.0.1 -datadir=./anodes -addnode=172.104.72.150 -addnode=162.216.17.71 -addnode=127.0.0.1 -deprecatedrpc=generate -rpcpassword=radio -rpcuser=coin -rpcport=9334 -port=9335 --daemon --server
 
alias node1="radiocoin-cli -rpcpassword=radio -rpcuser=coin -rpcport=9334"

 node1 getblockhash 0 
 node1 getblock 000008f3108b9b62492a71ff55f58f90678baf0ddeb75d11480f9355df6d1204 false
 
 010000000000000000000000000000000000000000000000000000000000000000000000f5247939a78482b7824f5f359ce35e78773216d4355b098b69fdfaed0b0df9d24c60b060f0ff0f1e714901000101000000010000000000000000000000000000000000000000000000000000000000000000ffffffff1e04f0ff0f1e010416526164696f436f696e206d757369632077616c6c6574ffffffff010058850c02000000434104770ee175cb5530e95cd615c061738719116d871ad9fcc9292ea6b0d396f7d270c12f351ff674b030299b537e9fa062511ac67b8bfc4d68cfcc2fd86158e0e6b3ac00000000


which becomes as an 80-byte header
010000000000000000000000000000000000000000000000000000000000000000000000f5247939a78482b7824f5f359ce35e78773216d4355b098b69fdfaed0b0df9d24c60b060f0ff0f1e71490100

mine block 0
cpp_miner mine 010000000000000000000000000000000000000000000000000000000000000000000000f5247939a78482b7824f5f359ce35e78773216d4355b098b69fdfaed0b0df9d24c60b060f0ff0f1e71490100 -v
Verbosity enabled.  Level is 1
target: 00000ffff0000000000000000000000000000000000000000000000000000000
block header: 010000000000000000000000000000000000000000000000000000000000000000000000f5247939a78482b7824f5f359ce35e78773216d4355b098b69fdfaed0b0df9d24c60b060f0ff0f1e71490100
nonce: 0x00014971
block hash: 000008f3108b9b62492a71ff55f58f90678baf0ddeb75d11480f9355df6d1204










https://jbaczuk.github.io/blockchain_fundamentals/2-Fundamentals/2.5-Mining.html

for lower powLimit 
----------------------
./sha256.py  010000000000000000000000000000000000000000000000000000000000000000000000f5247939a78482b7824f5f359ce35e78773216d4355b098b69fdfaed0b0df9d24c60b060f0ff0f1e714901000101000000010000000000000000000000000000000000000000000000000000000000000000ffffffff1e04f0ff0f1e010416526164696f436f696e206d757369632077616c6c6574ffffffff010058850c02000000434104770ee175cb5530e95cd615c061738719116d871ad9fcc9292ea6b0d396f7d270c12f351ff674b030299b537e9fa062511ac67b8bfc4d68cfcc2fd86158e0e6b3ac00000000


01cab59e0cea7ad08927afccb8a4bdf5a5e3946b135bc4e9024b3239e99e7f36

python2 reverse.endian.py 01cab59e0cea7ad08927afccb8a4bdf5a5e3946b135bc4e9024b3239e99e7f36

367f9ee939324b02e9c45b136b94e3a5f5bda4b8ccaf2789d07aea0c9eb5ca01

find bits of block 0 header
---------------------------
node1 getblock 000008f3108b9b62492a71ff55f58f90678baf0ddeb75d11480f9355df6d1204
{
  "hash": "000008f3108b9b62492a71ff55f58f90678baf0ddeb75d11480f9355df6d1204",
  "confirmations": 1,
  "strippedsize": 238,
  "size": 238,
  "weight": 952,
  "height": 0,
  "version": 1,
  "versionHex": "00000001",
  "merkleroot": "d2f90d0bedfafd698b095b35d4163277785ee39c355f4f82b78284a7397924f5",
  "tx": [
    "d2f90d0bedfafd698b095b35d4163277785ee39c355f4f82b78284a7397924f5"
  ],
  "time": 1622171724,
  "mediantime": 1622171724,
  "nonce": 84337,
  "bits": "1e0ffff0",
  "difficulty": 0.000244140625,
  "chainwork": "0000000000000000000000000000000000000000000000000000000000100010"
}


  "bits": "1e0ffff0",

python2 reverse.endian.py 1e0ffff0
f0ff0f1e

```


  
  or from source
  ```
  sh autogen.sh 
./configure --prefix=/usr --with-incompatible-bdb
make -j24
make -j24 install
checkinstall --install=no --exclude=/sys/fs/selinux
alien --scripts --to-rpm *.deb 
```
 
  ![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/PAPER-WALLET.png)
  ![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/radiocoin-current.png)
  
  # MAINnet
  ```
  
  radiocoin-qt -listen -upnp=1 -bind=127.0.0.1 -addnode=172.104.72.150 -addnode=162.216.17.71 -addnode=127.0.0.1 -deprecatedrpc=generate -rpcpassword=radio -rpcuser=coin --daemon 
  
 radiocoind -listen -upnp=1 -bind=127.0.0.1 -datadir=./nodes -addnode=172.104.72.150 -addnode=162.216.17.71 -addnode=127.0.0.1 -deprecatedrpc=generate -rpcpassword=radio -rpcuser=coin -rpcport=9334 -port=9335 --daemon --server


  
  alias node1="radiocoin-cli -rpcpassword=radio -rpcuser=coin -rpcport=9334"
  node1 addnode "162.216.17.71:9334" "add"
  node1 addnode "127.0.0.1:9334" "add"
  node1 addnode "172.104.72.150:9334" "add"
  node1 getblockchaininfo
node1 generate 1
node1 getbalance

```
  
  
 ```
[root@localhost /]# node1 getbalance
2600.00000000
```





sample conf for running a node (not for an RPC connection)
/root/.radiocoin/radiocoin.conf 
----------------------------
```
https://raw.githubusercontent.com/c4pt000/radioCOIN/main/radiocoin.conf

```



# testing frontend through REGtest
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/mined-minted.png)
```
radiocoind -regtest -port=1111 -datadir=./ -rpcport=1234 -deprecatedrpc=generate --daemon
radiocoin-qt -regtest -port=2222 -datadir=./newreg -rpcport=5467 -deprecatedrpc=generate --daemon
```


 

todo: -> done current block "158"
https://stackoverflow.com/questions/47828172/encountering-readblockfromdisk-errors-in-block-header-at-cblockdiskposnfile-0/48606397#48606397

https://bitcoin.stackexchange.com/questions/67060/error-readblockfromdisk-errors-in-block-header-at-cblockdiskposnfile-0-npos

https://medium.com/@kay.odenthal_25114/create-a-private-bitcoin-network-with-simulated-mining-b35f5b03e534





todo: mine block 0 -> done
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

# radioCOIN (needs nodes testing at block 0 genesis block might be configured wrong) -> done now at block "158"

# to help the music industry secure money from the loss of recordable music and mp3 leaks, and to control noisy car radios with fees for playing the volume too loud at odd hours

requires requires boost-1.75


fix 3 network assert for chainparams.cpp from first run generated (asserts) with code placed back into chainparams.cpp
<br>
https://www.youtube.com/watch?v=U-IIKVaEhrA

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

# first crude design (of redesigning the "DOGECOIN" paper wallet then I decided it could be better since its a paper wallet for which is supposed to be used for -money- )

![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/src/qt/res/icons/paper_wallet.png.front.png)


# current paper wallet for "radioCOIN"

# used the back of a real 2 dollar bill to design the paper wallet art
  *  (a closer look reveals a 1980s boombox on the floor near the front desk)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/src/qt/res/icons/paper_wallet.png.back.png)




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

radioCOIN (needs nodes testing at block 0 genesis block might be configured wrong)
to help the music industry secure money from the loss of recordable music and mp3 leaks, and to control noisy car radios with fees for playing the volume too loud at odd hours

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
