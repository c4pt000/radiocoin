// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
 // file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "consensus/merkle.h"

#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

#include "chainparamsseeds.h"


#include <stdio.h>
#include <inttypes.h>
#include <cinttypes>
#include <arith_uint256.h>



static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
//    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vin[0].scriptSig = CScript() << 504365040 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1386325540, nBits=0x1e0ffff0, nNonce=99943, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{

 const char* pszTimestamp = "RadioCoin music wallet";
    const CScript genesisOutputScript = CScript() << ParseHex("04770ee175cb5530e95cd615c061738719116d871ad9fcc9292ea6b0d396f7d270c12f351ff674b030299b537e9fa062511ac67b8bfc4d68cfcc2fd86158e0e6b3") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);

}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
private:
    Consensus::Params digishieldConsensus;
    Consensus::Params auxpowConsensus;
public:
    CMainParams() {
        strNetworkID = "main";

        // Blocks 0 - 144999 are conventional difficulty calculation
        consensus.nSubsidyHalvingInterval = 100000;
        consensus.nMajorityEnforceBlockUpgrade = 1500;
        consensus.nMajorityRejectBlockOutdated = 1900;
        consensus.nMajorityWindow = 2000;
        // BIP34 is never enforced in RadioCoin v2 blocks, so we enforce from v3

//start at 0 not 1
        consensus.BIP34Height = 1;
//        consensus.BIP34Hash = uint256S("0x000006ac2bd84266d6064bc8c47a222b9c68eb25c70aa6f13320fc7ed7f9e996");
        consensus.BIP34Hash = uint256S("");
        consensus.BIP65Height = 0; // 34cd2cbba4ba366f47e5aa0db5f02c19eba2adf679ceb6653ac003bdc9a0ef1f - first v4 block after the last v3 block
        consensus.BIP66Height = 0; // 80d1364201e5df97e696c03bdd24dc885e8617b9de51e453c10a4f629b1e797a - this is the last block that could be v2, 1900 blocks past the last v2 block
        consensus.powLimit = uint256S("0x00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // ~uint256(0) >> 20;
        consensus.nPowTargetTimespan =  4 * 60 * 60; // 4 hours
//4 * 60 * 60; // pre-digishield: 4 hours
        consensus.nPowTargetSpacing =  60; // 1 minute
        consensus.fDigishieldDifficultyCalculation = false;
//        consensus.nCoinbaseMaturity = 30;  // set block the number of confirms it takes until a block is available as a regular balance
        consensus.nCoinbaseMaturity = 10;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowAllowDigishieldMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 9576; // 95% of 10,080
        consensus.nMinerConfirmationWindow = 10080; // 60 * 24 * 7 = 10,080 blocks, or one week





	consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

        // Deployment of BIP68, BIP112, and BIP113.
        // XXX: BIP heights and hashes all need to be updated to Dogecoin values
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1462060800; // May 1st, 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1493596800; // May 1st, 2017

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1479168000; // November 15th, 2016.
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 0; // Disabled

















        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x000000000000000000000000000000000000000000000141a39e783aad4f660f");
//        consensus.nMinimumChainWork = uint256S("");

        // By default assume that the signatures in ancestors of this block are valid. height 2050
        consensus.defaultAssumeValid = uint256S("");
//        consensus.defaultAssumeValid = uint256S("0x21375c7c6003a1caa5763e2e20cdc1948479ebec5f3d32086b14553a5ea406d4");

        // AuxPoW parameters
        consensus.nAuxpowChainId = 0x0062; // 98 - Josh Wise!
        consensus.fStrictChainId = true;
        consensus.fAllowLegacyBlocks = true;
        consensus.nHeightEffective = 0;

        // Blocks 145000 - 371336 are Digishield without AuxPoW
        digishieldConsensus = consensus;
        digishieldConsensus.nHeightEffective = 145000;
        digishieldConsensus.fSimplifiedRewards = true;
        digishieldConsensus.fDigishieldDifficultyCalculation = true;
        digishieldConsensus.nPowTargetTimespan = 60; // post-digishield: 1 minute
        digishieldConsensus.nCoinbaseMaturity = 240;

        // Blocks 371337+ are AuxPoW
        auxpowConsensus = digishieldConsensus;
        auxpowConsensus.nHeightEffective = 371337;
        auxpowConsensus.fAllowLegacyBlocks = false;

        // Assemble the binary search tree of consensus parameters
        pConsensusRoot = &digishieldConsensus;
        digishieldConsensus.pLeft = &consensus;
        digishieldConsensus.pRight = &auxpowConsensus;

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
	    
	    
//changes for peer to peer annouce to connect to sync based on bitcoin-core
//	    pchMessageStart[4] = { 0xf9, 0xbe, 0xb4, 0xd9 }; originally 0xc0

        pchMessageStart[0] = 0xd1;
        pchMessageStart[1] = 0xd1;
        pchMessageStart[2] = 0xd1;
        pchMessageStart[3] = 0xd1;
        vAlertPubKey = ParseHex("04770ee175cb5530e95cd615c061738719116d871ad9fcc9292ea6b0d396f7d270c12f351ff674b030299b537e9fa062511ac67b8bfc4d68cfcc2fd86158e0e6b3");
			       //04d4da7a5dae4db797d9b0644d57a5cd50e05a70f36091cd62e2fc41c98ded06340be5a43a35e185690cd9cde5d72da8f6d065b499b06f51dcfba14aad859f443a");
        nDefaultPort = 9332;
        nPruneAfterHeight = 100000;

        genesis = CreateGenesisBlock(1622171724, 84337, 0x1e0ffff0, 1, 50 * COIN);

	consensus.hashGenesisBlock = uint256S("0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        if (true && (genesis.GetHash() != consensus.hashGenesisBlock)) {
            std::cout << std::string("Begin calculating Mainnet Genesis Block:\n");
            arith_uint256 hashTarget = arith_uint256().SetCompact(genesis.nBits);
            uint256 hash;
            genesis.nNonce = 0;
            while (UintToArith256(genesis.GetHash()) > hashTarget) {
                ++genesis.nNonce;
                if (genesis.nNonce == 0) {
                    std::cout << std::string("NONCE WRAPPED, incrementing time:\n");
                    ++genesis.nTime;
                }
                if (genesis.nNonce % 1000 == 0) {
                    std::cout << strNetworkID << " nonce: " << genesis.nNonce << " time: " << genesis.nTime << " hash: " << genesis.GetHash().ToString().c_str() << "\n";
                }
            }

            printf(" Mainnet ---\n");
            std::cout << std::string(" main_nonce: ") << ("%" PRIu32, genesis.nNonce) << std::endl;
            std::cout << std::string(" main_time: ") << ("%" PRIu32, genesis.nTime) << std::endl;
            std::cout << std::string(" main_hash: ") << ("%" PRIu32, genesis.GetHash().ToString().c_str()) << std::endl;
            std::cout << std::string(" main_merklehash: ") << ("%" PRIu32, genesis.hashMerkleRoot.ToString().c_str()) << std::endl;
            printf("min Main nBit:  %08x\n", consensus.powLimit);
            std::cout << std::string("Finished calculating Mainnet Genesis Block for SED replacement of current assertion and values:") << std::endl;



        }
/*
 Mainnet ---
 main_nonce: 84337
 main_time: 1622171724
 main_hash: 000008f3108b9b62492a71ff55f58f90678baf0ddeb75d11480f9355df6d1204
 main_merklehash: d2f90d0bedfafd698b095b35d4163277785ee39c355f4f82b78284a7397924f5


//
//Mainnet ---
// main_nonce: 264509
// main_time: 1386325540
// main_hash: 00000938a63f20223e77c074dad13eada7ab9525c067e15f7570a76a779b4832
// main_merklehash: 5b2a3f53f605d62c53e62932dac6925e3d74afa5a4b459745c36d42d0ed26a69

//Mainnet ---
// main_nonce: 597316
// main_time: 1622171724
// main_hash: 000002e2e76fef07722c875e9a68b1ce32bd2964e2df8ce70d9d31ab263f5fd2
// main_merklehash: 8382a18d469d405c1aa030c2329cc6f619ae1e1532fee7340809391e637e5336

Mainnet ---
 main_nonce: 1871680
 main_time: 1622171724
 main_hash: 000006ac2bd84266d6064bc8c47a222b9c68eb25c70aa6f13320fc7ed7f9e996
 main_merklehash: f5efeb1987356784c051c50cf4cfead7ff76c4a74189cda6c2fdbc6e8a1e2142
*/


        consensus.hashGenesisBlock = genesis.GetHash();
        digishieldConsensus.hashGenesisBlock = consensus.hashGenesisBlock;
        auxpowConsensus.hashGenesisBlock = consensus.hashGenesisBlock;


        assert(consensus.hashGenesisBlock == uint256S("0x000006ac2bd84266d6064bc8c47a222b9c68eb25c70aa6f13320fc7ed7f9e996"));
        assert(genesis.hashMerkleRoot == uint256S("0xf5efeb1987356784c051c50cf4cfead7ff76c4a74189cda6c2fdbc6e8a1e2142"));


/*
	  vSeeds.emplace_back("seed.bitcoin.sipa.be"); // Pieter Wuille, only supports x1, x5, x9, and xd
        vSeeds.emplace_back("dnsseed.bluematt.me"); // Matt Corallo, only supports x9
        vSeeds.emplace_back("dnsseed.bitcoin.dashjr.org"); // Luke Dashjr
        vSeeds.emplace_back("seed.bitcoinstats.com"); // Christian Decker, supports x1 - xf
        vSeeds.emplace_back("seed.bitcoin.jonasschnelli.ch"); // Jonas Schnelli, only supports x1, x5, x9, and xd
        vSeeds.emplace_back("seed.btc.petertodd.org"); // Peter Todd, only supports x1, x5, x9, and xd
        vSeeds.emplace_back("seed.bitcoin.sprovoost.nl"); // Sjors Provoost
        vSeeds.emplace_back("dnsseed.emzy.de"); // Stephan Oeste
        vSeeds.emplace_back("seed.bitcoin.wiz.biz"); // Ja
	    
        // Note that of those with the service bits flag, most only support a subset of possible options
      //  vSeeds.push_back(CDNSSeedData("multidoge.org", "seed.multidoge.org", true));
       // vSeeds.push_back(CDNSSeedData("multidoge.org", "seed2.multidoge.org"));
*/


        // Note that of those with the service bits flag, most only support a subset of possible options
vSeeds.push_back(CDNSSeedData("radioblockchain.info", "seed-ns1.radioblockchain.info", true));
vSeeds.push_back(CDNSSeedData("radioblockchain.info", "seed-ns2.radioblockchain.info" ));
vSeeds.push_back(CDNSSeedData("radioblockchain.info", "seed-ns3.radioblockchain.info" ));

//        vSeeds.push_back(CDNSSeedData("multidoge.org", "seed.multidoge.org", true));
//        vSeeds.push_back(CDNSSeedData("multidoge.org", "seed2.multidoge.org"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,60);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,22);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,158);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0xfa)(0xca)(0xfd).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0xfa)(0xc3)(0x98).convert_to_container<std::vector<unsigned char> >();

        //TODO: fix this for dogecoin -- plddr
        //vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));
        vFixedSeeds.clear();

        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;



        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
        (       0, uint256S("0x000006ac2bd84266d6064bc8c47a222b9c68eb25c70aa6f13320fc7ed7f9e996"))
//	(     100, uint256S("0x584bf2cb14709a7095e080f37b96b6292052be0556646d75a1883adadc671cda"))
//	(     1000, uint256S("0xd8df3b7e5b2d38062dec4343ecaaf76c90dc63e89339701fa8a4d5d100d03311"))
//	(     2000, uint256S("0x359f4ebec2d24a82dcb9b0038123b00686fc3c83ec08c6003292cf6a1b255cc9"))
//	(     2050, uint256S("0x21375c7c6003a1caa5763e2e20cdc1948479ebec5f3d32086b14553a5ea406d4"))
     };



        chainTxData = ChainTxData{
            // Data as of block 954c7c66dee51f0a3fb1edb26200b735f5275fe54d9505c76ebd2bcabac36f1e (height 3606083).
            // Tx estimate based on average of year 2021 (~40k transactions per day)
//            1622171724, // * UNIX timestamp of last checkpoint block
  //          140,   // * total number of transactions between genesis and last checkpoint
                        //   (the tx=... number in the SetBestChain debug.log lines)
    //        0.46        // * estimated number of transactions per second after checkpoint
        };
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
private:
    Consensus::Params digishieldConsensus;
    Consensus::Params auxpowConsensus;
    Consensus::Params minDifficultyConsensus;
public:
    CTestNetParams() {
        strNetworkID = "test";

        // Blocks 0 - 144999 are pre-Digishield
        consensus.nHeightEffective = 0;
        consensus.nPowTargetTimespan = 4 * 60 * 60; // pre-digishield: 4 hours
        consensus.fDigishieldDifficultyCalculation = false;
        consensus.nCoinbaseMaturity = 30;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowAllowDigishieldMinDifficultyBlocks = false;
        consensus.nSubsidyHalvingInterval = 100000;
        consensus.nMajorityEnforceBlockUpgrade = 501;
        consensus.nMajorityRejectBlockOutdated = 750;
        consensus.nMajorityWindow = 1000;
        // BIP34 is never enforced in RadioCoin v2 blocks, so we enforce from v3
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256S("0x000003cc12eab2850a7617e26bc1c145f647624c9e60cdbdb9e779a883b0e5b1");
        consensus.BIP65Height = 0; // 955bd496d23790aba1ecfacb722b089a6ae7ddabaedf7d8fb0878f48308a71f9
        consensus.BIP66Height = 0; // 21b8b97dcdb94caa67c7f8f6dbf22e61e0cfe0e46e1fff3528b22864659e9b38 - this is the last block that could be v2, 1900 blocks past the last v2 block
        consensus.powLimit = uint256S("0x00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // ~uint256(0) >> 20;
        consensus.nPowTargetTimespan = 4 * 60 * 60; // pre-digishield: 4 hours
        consensus.nPowTargetSpacing = 60; // 1 minute
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 2880; // 2 days (note this is significantly lower than Bitcoin standard)
        consensus.nMinerConfirmationWindow = 10080; // 60 * 24 * 7 = 10,080 blocks, or one week
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;

         consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
         consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

//        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE; // January 1, 2008
//        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT; // December 31, 2008

        // Deployment of BIP68, BIP112, and BIP113.
        // XXX: BIP heights and hashes all need to be updated to RadioCoin values
//        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
//        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1456790400; // March 1st, 2016
//        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1493596800; // May 1st, 2017

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
//        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
 //       consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1462060800; // May 1st 2016
 //       consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 0; // Disabled

        // The best chain should have at least this much work.
   //     consensus.nMinimumChainWork = uint256S("0x00000000000000000000000000000000000000000000000000001030d1382ade");
       consensus.nMinimumChainWork = uint256S("");

        // By default assume that the signatures in ancestors of this block are valid.
//        consensus.defaultAssumeValid = uint256S("0x6943eaeaba98dc7d09f7e73398daccb4abcabb18b66c8c875e52b07638d93951"); // 900,000
        consensus.defaultAssumeValid = uint256S(""); // 900,000

        // AuxPoW parameters
        consensus.nAuxpowChainId = 0x0062; // 98 - Josh Wise!
        consensus.fStrictChainId = false;
        consensus.nHeightEffective = 0;
        consensus.fAllowLegacyBlocks = true;

        // Blocks 145000 - 157499 are Digishield without minimum difficulty on all blocks
        digishieldConsensus = consensus;
        digishieldConsensus.nHeightEffective = 145000;
        digishieldConsensus.nPowTargetTimespan = 60; // post-digishield: 1 minute
        digishieldConsensus.fDigishieldDifficultyCalculation = true;
        digishieldConsensus.fSimplifiedRewards = true;
        digishieldConsensus.fPowAllowMinDifficultyBlocks = false;
        digishieldConsensus.nCoinbaseMaturity = 240;

        // Blocks 157500 - 158099 are Digishield with minimum difficulty on all blocks
        minDifficultyConsensus = digishieldConsensus;
        minDifficultyConsensus.nHeightEffective = 157500;
        minDifficultyConsensus.fPowAllowDigishieldMinDifficultyBlocks = true;
        minDifficultyConsensus.fPowAllowMinDifficultyBlocks = true;

        // Enable AuxPoW at 158100
        auxpowConsensus = minDifficultyConsensus;
        auxpowConsensus.nHeightEffective = 158100;
        auxpowConsensus.fPowAllowDigishieldMinDifficultyBlocks = true;
        auxpowConsensus.fAllowLegacyBlocks = false;

        // Assemble the binary search tree of parameters
        pConsensusRoot = &digishieldConsensus;
        digishieldConsensus.pLeft = &consensus;
        digishieldConsensus.pRight = &minDifficultyConsensus;
        minDifficultyConsensus.pRight = &auxpowConsensus;

        pchMessageStart[0] = 0xfc;
        pchMessageStart[1] = 0xc1;
        pchMessageStart[2] = 0xb7;
        pchMessageStart[3] = 0xdc;
        vAlertPubKey = ParseHex("04770ee175cb5530e95cd615c061738719116d871ad9fcc9292ea6b0d396f7d270c12f351ff674b030299b537e9fa062511ac67b8bfc4d68cfcc2fd86158e0e6b3");
        nDefaultPort = 9888;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1486949366, 618865, 0x1e0ffff0, 1, 50 * COIN);

        consensus.hashGenesisBlock = uint256S("0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        if (true && (genesis.GetHash() != consensus.hashGenesisBlock)) {
            std::cout << std::string("Begin calculating Testnet Genesis Block:\n");
            arith_uint256 hashTarget = arith_uint256().SetCompact(genesis.nBits);
            uint256 hash;
            genesis.nNonce = 0;
            while (UintToArith256(genesis.GetHash()) > hashTarget) {
                ++genesis.nNonce;
                if (genesis.nNonce == 0) {
                    std::cout << std::string("NONCE WRAPPED, incrementing time:\n");
                    ++genesis.nTime;
                }
                if (genesis.nNonce % 1000 == 0) {
                    std::cout << strNetworkID << " nonce: " << genesis.nNonce << " time: " << genesis.nTime << " hash: " << genesis.GetHash().ToString().c_str() << "\n";
                }
            }

            printf(" Testnet ---\n");
            std::cout << std::string(" Test_nonce: ") << ("%" PRIu32, genesis.nNonce) << std::endl;
            std::cout << std::string(" Test_time: ") << ("%" PRIu32, genesis.nTime) << std::endl;
            std::cout << std::string(" Test_hash: ") << ("%" PRIu32, genesis.GetHash().ToString().c_str()) << std::endl;
            std::cout << std::string(" Test_merklehash: ") << ("%" PRIu32, genesis.hashMerkleRoot.ToString().c_str()) << std::endl;
            printf("min Test nBit:  %08x\n", consensus.powLimit);
            std::cout << std::string("Finished calculating Testnet Genesis Block for SED replacement of current assertion and values:") << std::endl;

        }
/*
// Testnet ---
// Test_nonce: 107679
// Test_time: 1391503289
// Test_hash: 00000777d0d45ec8471b583777bc5676766fe03e0c70257d5d4b827157f9f1bc
// Test_merklehash: 5b2a3f53f605d62c53e62932dac6925e3d74afa5a4b459745c36d42d0ed26a69

// Testnet ---
// Test_nonce: 279865
// Test_time: 1486949366
// Test_hash: 000000b8a7e8b9e0a4d87d8d170054ab699ecf206381ee21628861d11e4c9e39
// Test_merklehash: 8382a18d469d405c1aa030c2329cc6f619ae1e1532fee7340809391e637e5336

Testnet ---
 Test_nonce: 618865
 Test_time: 1486949366
 Test_hash: 000003cc12eab2850a7617e26bc1c145f647624c9e60cdbdb9e779a883b0e5b1
 Test_merklehash: f5efeb1987356784c051c50cf4cfead7ff76c4a74189cda6c2fdbc6e8a1e2142
*/

        consensus.hashGenesisBlock = genesis.GetHash();
        digishieldConsensus.hashGenesisBlock = consensus.hashGenesisBlock;
        minDifficultyConsensus.hashGenesisBlock = consensus.hashGenesisBlock;
        auxpowConsensus.hashGenesisBlock = consensus.hashGenesisBlock;
        assert(consensus.hashGenesisBlock == uint256S("0x000003cc12eab2850a7617e26bc1c145f647624c9e60cdbdb9e779a883b0e5b1"));
        assert(genesis.hashMerkleRoot == uint256S("0xf5efeb1987356784c051c50cf4cfead7ff76c4a74189cda6c2fdbc6e8a1e2142"));

	 vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
        vSeeds.push_back(CDNSSeedData("jrn.me.uk", "testseed.jrn.me.uk"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,113); // 0x71
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196); // 0xc4
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,241); // 0xf1
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xcf).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        //TODO: fix this for dogecoin -- plddr
        //vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));



        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;

        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
            ( 0, uint256S("0x000003cc12eab2850a7617e26bc1c145f647624c9e60cdbdb9e779a883b0e5b1"))
/*            ( 483173, uint256S("0xa804201ca0aceb7e937ef7a3c613a9b7589245b10cc095148c4ce4965b0b73b5"))
            ( 591117, uint256S("0x5f6b93b2c28cedf32467d900369b8be6700f0649388a7dbfd3ebd4a01b1ffad8"))
            ( 658924, uint256S("0xed6c8324d9a77195ee080f225a0fca6346495e08ded99bcda47a8eea5a8a620b"))
            ( 703635, uint256S("0x839fa54617adcd582d53030a37455c14a87a806f6615aa8213f13e196230ff7f"))
            ( 1000000, uint256S("0x1fe4d44ea4d1edb031f52f0d7c635db8190dc871a190654c41d2450086b8ef0e"))
            ( 1202214, uint256S("0xa2179767a87ee4e95944703976fee63578ec04fa3ac2fc1c9c2c83587d096977"))
            ( 1250000, uint256S("0xb46affb421872ca8efa30366b09694e2f9bf077f7258213be14adb05a9f41883"))
            ( 1500000, uint256S("0x0caa041b47b4d18a4f44bdc05cef1a96d5196ce7b2e32ad3e4eb9ba505144917"))
            ( 1750000, uint256S("0x8042462366d854ad39b8b95ed2ca12e89a526ceee5a90042d55ebb24d5aab7e9"))
            ( 2000000, uint256S("0xd6acde73e1b42fc17f29dcc76f63946d378ae1bd4eafab44d801a25be784103c"))
            ( 2250000, uint256S("0xc4342ae6d9a522a02e5607411df1b00e9329563ef844a758d762d601d42c86dc"))
            ( 2500000, uint256S("0x3a66ec4933fbb348c9b1889aaf2f732fe429fd9a8f74fee6895eae061ac897e2"))
            ( 2750000, uint256S("0x473ea9f625d59f534ffcc9738ffc58f7b7b1e0e993078614f5484a9505885563"))
          ( 3062910, uint256S("0x113c41c00934f940a41f99d18b2ad9aefd183a4b7fe80527e1e6c12779bd0246"))
*/
        };

        chainTxData = ChainTxData{
            // Data as of block a113c41c00934f940a41f99d18b2ad9aefd183a4b7fe80527e1e6c12779bd024 (height 3062910)
  //          1486949366, // * UNIX timestamp of last checkpoint block
    //        4186373,    // * total number of transactions between genesis and last checkpoint
      //      0.05        // * estimated number of transactions per second after that timestamp
        };

    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
private:
    Consensus::Params digishieldConsensus;
    Consensus::Params auxpowConsensus;
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.nMajorityEnforceBlockUpgrade = 750;
        consensus.nMajorityRejectBlockOutdated = 950;
        consensus.nMajorityWindow = 1000;
        consensus.BIP34Height = 100000000; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests)
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1351; // BIP65 activated on regtest (Used in rpc activation tests)
        consensus.BIP66Height = 1251; // BIP66 activated on regtest (Used in rpc activation tests)
        consensus.powLimit = uint256S("0x7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // ~uint256(0) >> 1;
        consensus.nPowTargetTimespan = 4 * 60 * 60; // pre-digishield: 4 hours
        consensus.nPowTargetSpacing = 1; // regtest: 1 second blocks
        consensus.fDigishieldDifficultyCalculation = false;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 540; // 75% for testchains
        consensus.nMinerConfirmationWindow = 720; // Faster than normal for regtest (2,520 instead of 10,080)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 999999999999ULL;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        // AuxPow parameters
        consensus.nAuxpowChainId = 0x0062; // 98 - Josh Wise!
        consensus.fStrictChainId = true;
        consensus.fAllowLegacyBlocks = true;

        // RadioCoin parameters
        consensus.fSimplifiedRewards = true;
        consensus.nCoinbaseMaturity = 60; // For easier testability in RPC tests

        digishieldConsensus = consensus;
        digishieldConsensus.nHeightEffective = 10;
        digishieldConsensus.nPowTargetTimespan = 1; // regtest: also retarget every second in digishield mode, for conformity
        digishieldConsensus.fDigishieldDifficultyCalculation = true;

        auxpowConsensus = digishieldConsensus;
        auxpowConsensus.fAllowLegacyBlocks = false;
        auxpowConsensus.nHeightEffective = 20;

        // Assemble the binary search tree of parameters
        digishieldConsensus.pLeft = &consensus;
        digishieldConsensus.pRight = &auxpowConsensus;
        pConsensusRoot = &digishieldConsensus;

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nDefaultPort = 18444;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1296688602, 0, 0x207fffff, 1, 50 * COIN);
   
       consensus.hashGenesisBlock = uint256S("0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        if (true && (genesis.GetHash() != consensus.hashGenesisBlock)) {
            std::cout << std::string("Begin calculating RegTestnet Genesis Block:\n");
            arith_uint256 hashTarget = arith_uint256().SetCompact(genesis.nBits);
            uint256 hash;
            genesis.nNonce = 0;
            while (UintToArith256(genesis.GetHash()) > hashTarget) {
                ++genesis.nNonce;
                if (genesis.nNonce == 0) {
                    std::cout << std::string("NONCE WRAPPED, incrementing time:\n");
                    ++genesis.nTime;
                }
                if (genesis.nNonce % 1000 == 0) {
                    std::cout << strNetworkID << " nonce: " << genesis.nNonce << " time: " << genesis.nTime << " hash: " << genesis.GetHash().ToString().c_str() << "\n";
                }
            }

            printf(" RegTestnet ---\n");
            std::cout << std::string(" RegTest_nonce: ") << ("%" PRIu32, genesis.nNonce) << std::endl;
            std::cout << std::string(" RegTest_time: ") << ("%" PRIu32, genesis.nTime) << std::endl;
            std::cout << std::string(" RegTest_hash: ") << ("%" PRIu32, genesis.GetHash().ToString().c_str()) << std::endl;
            std::cout << std::string(" RegTest_merklehash: ") << ("%" PRIu32, genesis.hashMerkleRoot.ToString().c_str()) << std::endl;
            printf("min RegTest nBit:  %08x\n", consensus.powLimit);
            std::cout << std::string("Finished calculating RegTestnet Genesis Block for SED replacement of current assertion and values:") << std::endl;



        }
/*
//RegTestnet ---
// RegTest_nonce: 2
// RegTest_time: 1296688602
// RegTest_hash: 3d2160a3b5dc4a9d62e7e66a295f70313ac808440ef7400d6c0772171ce973a5
// RegTest_merklehash: 5b2a3f53f605d62c53e62932dac6925e3d74afa5a4b459745c36d42d0ed26a69


//RegTestnet ---
// RegTest_nonce: 0
// RegTest_time: 1296688602
// RegTest_hash: 6d803069503326bf4c6815ae358cf8d8fed066b98121faba489c7c9916565e70
// RegTest_merklehash: 8382a18d469d405c1aa030c2329cc6f619ae1e1532fee7340809391e637e5336

RegTestnet ---
 RegTest_nonce: 0
 RegTest_time: 1296688602
 RegTest_hash: 7153e976e8d84aa80f3db3b061a6ad8428167b0908b70137a6a8354176f0d2f7
 RegTest_merklehash: d2f90d0bedfafd698b095b35d4163277785ee39c355f4f82b78284a7397924f5

RegTestnet ---
 RegTest_nonce: 0
 RegTest_time: 1296688602
 RegTest_hash: 0e079c7714e501a1a75d6da25c613e60a9a6fbe6b4599d0a9d4f6a248e28e3b3
 RegTest_merklehash: f5efeb1987356784c051c50cf4cfead7ff76c4a74189cda6c2fdbc6e8a1e2142

*/

     consensus.hashGenesisBlock = genesis.GetHash();
        digishieldConsensus.hashGenesisBlock = consensus.hashGenesisBlock;
        auxpowConsensus.hashGenesisBlock = consensus.hashGenesisBlock;
        assert(consensus.hashGenesisBlock == uint256S("0x0e079c7714e501a1a75d6da25c613e60a9a6fbe6b4599d0a9d4f6a248e28e3b3"));
        assert(genesis.hashMerkleRoot == uint256S("0xf5efeb1987356784c051c50cf4cfead7ff76c4a74189cda6c2fdbc6e8a1e2142"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;

        checkpointData = (CCheckpointData){
            boost::assign::map_list_of
//            ( 0, uint256S("0x3d2160a3b5dc4a9d62e7e66a295f70313ac808440ef7400d6c0772171ce973a5"))
            ( 0, uint256S(""))
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);  // 0x6f
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);  // 0xc4
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);  // 0xef
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
    }

    void UpdateBIP9Parameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
    {
        consensus.vDeployments[d].nStartTime = nStartTime;
        consensus.vDeployments[d].nTimeout = nTimeout;
    }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = 0;

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

const Consensus::Params *Consensus::Params::GetConsensus(uint32_t nTargetHeight) const {
    if (nTargetHeight < this -> nHeightEffective && this -> pLeft != NULL) {
        return this -> pLeft -> GetConsensus(nTargetHeight);
    } else if (nTargetHeight > this -> nHeightEffective && this -> pRight != NULL) {
        const Consensus::Params *pCandidate = this -> pRight -> GetConsensus(nTargetHeight);
        if (pCandidate->nHeightEffective <= nTargetHeight) {
            return pCandidate;
        }
    }

    // No better match below the target height
    return this;
}

CChainParams& Params(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
            return mainParams;
    else if (chain == CBaseChainParams::TESTNET)
            return testNetParams;
    else if (chain == CBaseChainParams::REGTEST)
            return regTestParams;
    else
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

void UpdateRegtestBIP9Parameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    regTestParams.UpdateBIP9Parameters(d, nStartTime, nTimeout);
}
