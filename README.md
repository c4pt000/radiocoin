# RADIOACTIVE !!
* scrypt based off of dogecoin internal design,
  ![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/PAPER-WALLET.png)
  ![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/radiocoin-current.png)
  

* block explorer for radioCOIN


* some stuff here requires docker
https://raw.githubusercontent.com/c4pt000/radioCOIN/main/docker-install.sh

* 06-05-2021 cpu mining seems over for me, only one workstation no beowulf cluster for CPU mining as a node, working out bugs for GPU mining

# http://radioblockchain.info

based off of this modifed code
https://github.com/c4pt000/radiocoin-blockchain-explorer (no address explorer just block, and txID)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/explorer-radiocoinRADC.png)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/block-explorer.png)

```
Detected Reward Type:	POW
						Current Block Height:	2854
						Current Connect Peers:	13
						Current Block Diff:	1946.2848512
						Network Difficulty:	1946.2848266067529
						Network Hash Rate:	945.82 KH
						Stratum Port(s):	3008, 3032, 3256
						Pool Fee Percent:	1.6%
						Block polling every:	1000 ms
```
* pool is active  (must connect with ip using mining program)
# http://104.237.145.126:9555    or run your own (https://github.com/c4pt000/docker-p2pool-radiocoin)
```
docker run --net host -it c4pt/radiopool-current /usr/bin/run-p2pool
```


password is whatever you want,

https://www.geeks3d.com/20091221/how-to-enable-opencl-support-on-nvidia-and-amd-platforms/

https://github.com/ghostlander/AMD-APP-SDK/releases/tag/v2.9.1

# bfgminer binaries linux  https://github.com/c4pt000/bfgminer-5.5.0-patched-scrypt/releases/tag/linux-rpm-debs


# cpuminer binaries linux https://github.com/c4pt000/cpuminer-multi/releases/tag/linux

CUDA only?
# ccminer WINDOWS GPU binaries https://github.com/tpruvot/ccminer/releases
# ccminer LINUX GPU binaries https://github.com/c4pt000/ccminer/releases/tag/linux
CUDA miner for best mine
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/p2pool-RADC.png)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/CUDA-ccminer.png)


![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/cpuminer-working.png)
```
my attempt in 8 hours to forge radiocoin into p2pool
still working out bugs,
 replace --userpass with your receiving address,

 set RSYOURRECEVINGADDRESSVLEQj4T to your wallet receiving address
 docker run -it c4pt/cpuminer-opt cpuminer -a scrypt --url 104.237.145.126:9555 --userpass RSYOURRECEVINGADDRESSVLEQj4T:x -t 24

for DOGEcoin replace with your receving address
ccminer -a scrypt -o stratum+tcp://104.237.145.126:9555 --userpass DMq9mjF2BpWA9EZhMcpMmi6voVXiBMJY9B:x  --no-longpoll


for RADIOcoin replace with your receving address

ccminer -a scrypt -o stratum+tcp://104.237.145.126:9555 --userpass RADCYOURreceivingcpMmi6voVXiBMJY9B:x  --no-longpoll

bfgminer for RADIOcoin replace with your receving address (was segfaulting not from program error but from getting shares via remote network)
bfgminer-5.5.0
---------------------------------------------------------

bfgminer --scrypt -o stratum+tcp://104.237.145.126:9555 --userpass RNshKJXooH2veVijkXGKzLQfBWgpPE7TQN:x  --no-longpoll 


```
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/bfgminer-connect.png)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/connect-.png)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/connection-allow-3008-firewall.png)

for a VPS GPU cluster guide
https://github.com/c4pt000/linode-GPU-bitcoin-dogecoin-RECOVER-wallet.dat-passphrase_or_private_key_decrypt-hashcat



# network is active
06-04-2021
difficulty for mining a block : 0.001177925043022528,
```
┌─[root@fedora]─[~]
└──╼ #radiocoin-cli getinfo
{
  "version": 1140300,
  "protocolversion": 70015,
  "walletversion": 130000,
  "balance": 64760891.00000000,
  "blocks": 1022,
  "timeoffset": -1,
  "connections": 6,
  "proxy": "",
  "difficulty": 0.001177925043022528,
  "testnet": false,
  "keypoololdest": 1622755952,
  "keypoolsize": 100,
  "paytxfee": 0.00000000,
  "relayfee": 1.00000000,
  "errors": ""
}
```
* Update 06-03-2021 loads current block 250 with a complete fresh start

# SYNCS with a complete fresh start
# just requires radiocoin.conf in the datadir
# and version 3.0.0-exp

linux binaries 
and docker-RADIOCOIN works syncs from fresh start

** rebuilding macOS binaries and windows binaries

```
changes to validation.cpp to put back first block 0 check , CheckReadFromDisk,
changes to chainparams.cpp for BIP34 Height 333 block, and BIP34 hash of block 333 and checkpoints added for 0 block and 333 block
radiocoin-cli getblockhash 333

src/validation.cpp

line: 1167

line: 2864
 ```

# RADIOACTIVE!! had to reset block 0 for peer to peer communication, 05-30-2021

might  not be able to send at the same time while running "radiocoin-cli generate 1" or "radiocoin-cli generatetoaddress"

daemon or qt-client probably cant mint and send at the same time

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



```
rejecting DOGE coin peers but using the dogecoin dns peers alongside of radiocoin peer transmissions

radioCOIN runs side by side with dogecoin with dns peers when peers do the pchMessage announce packet and header to intercommunicate, why setup more dns nodes as servers to supply seeds with transmission for packets (using existing dogecoin dns seeds)

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



#  June 1st as promised ? network seems semi-functional?

# WIP** (aiming to get bugs out for this to be a June 1st~31st coin?) <- sync issues between broadcast nodes



05-30-2021
```
STILL A WIP, having trouble syncing between remote nodes and two local test clients between linux and macos without bootstrap.dat

difficulty is low as with any starting network/fork as more blocks are mined with an interest in mining blocks the network "difficulty" will go up in value making it more difficult to mine blocks, after 600,000 blocks are mined the block reward will reduce from a random amount between 1->1,000,000 down to 10,000 coins per block (after block number 600,000 is mined) this model of radiocoin is the same network design as DOGECOIN just redesigned in terms of a different theme and anthem with different purpose,
```

* 05-29-2021 sync issues just built 8 nodes as a starting point check updated radiocoin.conf
```




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





https://jbaczuk.github.io/blockchain_fundamentals/2-Fundamentals/2.5-Mining.html

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
 

 ```
```
  
  
 ```
[root@localhost /]# node1 getbalance
2600.00000000
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
yum install git-core libdb-cxx-devel libdb-cxx openssl-devel libevent-devel java-11-openjdk-devel cppzmq-devel  qrencode-devel qt5-qtbase-devel.x86_64 protobuf-devel boost-* boost-devel miniupnpc-devel.x86_64 diffutils qt-devel qt4-devel wget -y

wget https://github.com/c4pt000/radioCOIN/releases/download/1.1.0-fedora34-build-environment/radiocoin-1.1.0_fedora34-2.x86_64.rpm
 
for selinux 4kb error with checkinstall 
--------------------
checkinstall --install=no --exclude=/sys/fs/selinux
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
  # (a closer look reveals a 1980s boombox on the floor near the front desk)
![s1](https://raw.githubusercontent.com/c4pt000/radioCOIN/main/PAPER-WALLET.png)




* fedora 34
source build

```
 yum groupinstall "C Development Tools and Libraries" -y
 
 yum install git-core libdb-cxx-devel libdb-cxx openssl-devel libevent-devel java-11-openjdk-devel cppzmq-devel \
 qrencode-devel qt5-qtbase-devel.x86_64 protobuf-devel \
 boost-* boost-devel miniupnpc-devel.x86_64 diffutils qt-devel qt4-devel -y
 
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



What is RadioCoin?
----------------

to help the music industry secure money from the loss of recordable music and mp3 leaks, and to control noisy car radios with fees for playing the volume too loud at odd hours

RadioCoin is an experimental digital currency that enables instant payments to
anyone, anywhere in the world. RadioCoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. RadioCoin Core is the name of open source
software which enables the use of this currency.

https://github.com/c4pt000/class-action-sue-black-artists
