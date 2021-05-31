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
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256S("0x6ff76c115d06e45829e93992958c1284c9ba051e7ac8d4b9eb5b690380f87a89");
        consensus.BIP65Height = 1; // 34cd2cbba4ba366f47e5aa0db5f02c19eba2adf679ceb6653ac003bdc9a0ef1f - first v4 block after the last v3 block
        consensus.BIP66Height = 1; // 80d1364201e5df97e696c03bdd24dc885e8617b9de51e453c10a4f629b1e797a - this is the last block that could be v2, 1900 blocks past the last v2 block
        consensus.powLimit = uint256S("0x00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // ~uint256(0) >> 20;
        consensus.nPowTargetTimespan = 4 * 60 * 60; // pre-digishield: 4 hours
        consensus.nPowTargetSpacing = 60; // 1 minute
        consensus.fDigishieldDifficultyCalculation = false;
        consensus.nCoinbaseMaturity = 30;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowAllowDigishieldMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 9576; // 95% of 10,080
        consensus.nMinerConfirmationWindow = 10080; // 60 * 24 * 7 = 10,080 blocks, or one week
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;

	 consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
         consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008


//        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE; // January 1, 2008
//        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT; // December 31, 2008

        // Deployment of BIP68, BIP112, and BIP113.
        // XXX: BIP heights and hashes all need to be updated to RadioCoin values
//        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
//        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1622171724;
//        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 0; // May 1st, 2017

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
//        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
//        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 0; // November 15th, 2016.
//        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 0; // Disabled

        // The best chain should have at least this much work.
//        consensus.nMinimumChainWork = uint256S("0x000000000000000000000000000000000000000000000141a39e783aad4f660f");
        consensus.nMinimumChainWork = uint256S("");

        // By default assume that the signatures in ancestors of this block are valid. height 1
        consensus.defaultAssumeValid = uint256S("");
//        consensus.defaultAssumeValid = uint256S("0x77e3f4a4bcb4a2c15e8015525e3d15b466f6c022f6ca82698f329edef7d9777e"); // 2,510,150

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
	    //pchMessageStart[4] = { 0xf9, 0xbe, 0xb4, 0xd9 };

        pchMessageStart[0] = 0xc0;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xc0;
        pchMessageStart[3] = 0xc0;
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

        // Note that of those with the service bits flag, most only support a subset of possible options
        vSeeds.push_back(CDNSSeedData("multidoge.org", "seed.multidoge.org", true));
        vSeeds.push_back(CDNSSeedData("multidoge.org", "seed2.multidoge.org"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,60);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,22);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,158);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0xfa)(0xca)(0xfd).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0xfa)(0xc3)(0x98).convert_to_container<std::vector<unsigned char> >();

        //TODO: fix this for radiocoin -- plddr
        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));
        
      //vFixedSeeds.clear();

        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;

        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
        (       0, uint256S("0x000006ac2bd84266d6064bc8c47a222b9c68eb25c70aa6f13320fc7ed7f9e996"))
	(       1, uint256S("0x6ff76c115d06e45829e93992958c1284c9ba051e7ac8d4b9eb5b690380f87a89"))
	(       2, uint256S("0xd65b177f956ad951d2e337877690a9fe35628c9711d47c444c6e62f00c8cf529"))
	(       3, uint256S("0xb6d2b7c73789cf72b583d318a5009b64aa712f8b4949acaa6403576bc0c6f31c"))
	(       4, uint256S("0xec4e2b74e51b536c95207db6542d315d2ccdb3369b3923db26f3397ec80ab0ab"))
	(       5, uint256S("0xc423286ae685c835d720d6d0dbe4bb927cf13b48814126304724a5401f38bb0e"))
	(       6, uint256S("0x586c18324d3f98e4bfff219a5e0ec1e8e688592b9f5d07de38595b6e335cbaa0"))
	(       7, uint256S("0x744dfc5c64d31dadde18fa5984ec5c551759810d8b09ab65cf6a480b2f0f7844"))
	(       8, uint256S("0x5ce09acd0eab313c2833fc8be69261bf3fc335cad47fa58d84a0dd5fba308160"))
 	(       9, uint256S("0x4093fbb6aba1bcf88e0c9ff3fe407f4f4da660c6f567b136576f48e3e6ef1342"))
	(       10, uint256S("0xc536d01a129e5bfb978d3cceb5f8445e5862c3ecada6dfb8bd6508872f139e05"))
	(       11, uint256S("0xac2ac72b4f9acf565fa1a0f1e3081b9e575ee542368dbbea579b8dfe2175d843"))
	(       12, uint256S("0xdbb8af1418321f9e3815dd82a2ad86e8cd7f8e62f8c814abad89ec37acc2b3b9"))
	(       13, uint256S("0xf57384a8160a5b8a65945d8eed880d8536fe3cd9a472a22883e9e1f9fe9d6931"))
	(       14, uint256S("0x77823656c1dd7525c5a8233350e63954c445a75d47c119d1aac17d4436e99c93"))
	(       15, uint256S("0xe27ea4df9b040ff9f1f45de0b759a79136cce761c6fb396e308566077081044a"))
	(       16, uint256S("0xec033b40cf6fe2f8804028c9f5633ba339a5bed2837162972854a5432701ed8f"))
	(       17, uint256S("0x787ced77446be9756b8d1cd5b64f06f448e4e09d210f1e02ed6ef8f14810c3a0"))
	(       18, uint256S("0x644abdb7e5ec459d9a473aa4a4a2def224efa04b457d2f0c5ed6664e9abaa0d9"))
	(       19, uint256S("0x76871d8f1fb05b3dcfe8353df01a4a8269ee559b49c88048c39c06ff5792ac8d"))
	(       20, uint256S("0x8e5aa0b8fc8f6f4d1193e115e989ada81aed0f35a54c36c1423ebd0c3163186a"))
	(       21, uint256S("0x75238477750cde09f434417b0df70499c4aab196df471986b8f2902d758dc0bd"))
	(       22, uint256S("0xcf22241f47964b083cfb4bc5f8db41e93c7675b9b7967ea8ecc96635703fa230"))
	(       23, uint256S("0xdf2d0730b71c046f45d996303cd837bce3cabb26e044233299df3de12f011d21"))
	(       24, uint256S("0xad7cfdbb4f56e1cd7b6c1bc8985105e59db88d6ae3474706abed6209d3561935"))
	(       25, uint256S("0xcd0bc2f9fa491bda7ef67f9599aa4a02fe89c7f4ffc0134977b3d2f2b30e1d6e"))
	(       26, uint256S("0xeca24458434d847e1def476b28c9d53fd10408e4c2dd11a2e83233c251b1a770"))
	(       27, uint256S("0xd67c1b6b9129e67d7b0692678af411a4f4f8cbff4d6a93c9071e2f2738fd817e"))
	(       28, uint256S("0x4542c6f5b03245be6c1e69b1a3182d46565d657342a13679ec208c8f100d6758"))
	(       29, uint256S("0x8ec829a4cff149f50952c2d2b3834e1052b067a0101e2c9477e8dddfda6f7644"))
	(       30, uint256S("0xd10db4b334bc1e859d5b6ff52f48f3f804c7f8c20f97c0318ae317bfabfdbff1"))
	(       31, uint256S("0xe061fdd3e1bb19e3d0bf62bfa058480adb5553b211de12d7399ed1a77d9c3ee0"))
	(       32, uint256S("0xdfa20e6b14b4a4ca29fd572eea68c8568af66b007a363b0f77dfda6a961b1489"))
	(       33, uint256S("0x520a754d337afb3bba6abdd40ae0f94bf2a3a934cbe6adff78d2f6c2db0120a9"))
	(       34, uint256S("0xea90e1b645af985a6b934738f72a575277cef53f21f2a731046dd0daec9424f8"))
	(       35, uint256S("0xf56060da5b13462f61c8789c217ea2ce933a1d6f81e6dbe7ee1035b518726fea"))
	(       36, uint256S("0x535575c4cc6483cbb1db8c6de61da28eaf52c4ed262f448666bf1d83cf6fd39f"))
	(       37, uint256S("0xd0f739667687ee21efebd7c66f7500ad67dcfe6f0c05fe9318b82f257a06579b"))
	(       38, uint256S("0x23685c321c32eb31e7b345e8917f708f32f50ce323fd8154df834b9c3b8d3553"))
	(       39, uint256S("0xb58787c3a587eb63c2317f5dc6c87dd1782a639897060a58bef9543aa5a40f4c"))
	(       40, uint256S("0xb766537c5dd2d5d1f8822a17c18bb323f081af7e3e5c2f575ad6f153f7d3c312"))
	(       41, uint256S("0x977ceb20f6d0163b7491d3cb5c15cacfa2de139564c5b92b701c4df03d0dd5fc"))
	(       42, uint256S("0xd0fb13c06499df89323239b5cebe3ab14a36cd8e7cf2cbebe3584276626a2e69"))
	(       43, uint256S("0x7a9c8b761f12ad63e5ee26707c013739641493e6c4b93e2b0424ae8ca2f49966"))
	(       44, uint256S("0xef9b6d73ef49233b2a5d3621202a2e8dfdd381adf592aafffb9683fac86e7961"))
	(       45, uint256S("0xa36fa944cfe86bb7aa0a996d6a4aa138105291fbcf6cee1642741ebf7045febc"))
	(       46, uint256S("0x9739018c0f6b926d3c4a3194dce0453baa1c3ccb0ccbfe25800d36c31a97bf95"))
	(       47, uint256S("0x32a16ffdfeedae9e9ee5532033b865968e085f5dd313e00fad8ccd3968f07daa"))
	(       48, uint256S("0xe1d144e93c9004f70ea084372d666121a0f4b550a7607f29031618d99492d375"))
	(       49, uint256S("0x6f7e39f88fb7469a85309d5fe837547c29a18d62dfe554ecfc90b1148ee9079f"))
	(       50, uint256S("0xd59d41dc06bde9c6b7f00943240ba0bdff275b6f270900156117c16549d39413"))
	(       51, uint256S("0x7582092b269307d60b68aa80d1ef71a70835143dbc7dcfc6cebbf40b758f97b9"))
	(       52, uint256S("0x3719151956e4c3f9e03a41597b3cad2485b8efb1ccca36574df4e035b518eeaa"))
	(       53, uint256S("0x61c96d2702eb70ccce3136b0b2a1307221ba9c9d9eb6920e79ba2818fce01baf"))
	(       54, uint256S("0x75a70b234b232976cfa50c6abbb45bda6334fe096ea5cdd6ece80eaef5511ed3"))
	(       55, uint256S("0xaad9861bda98e40923a6920da13aa3e9cc3b2478f3e9a8c713a5def9f78fc767"))
	(       56, uint256S("0x7fa3ca12633e6378451c7d02ecfd2475137544bb571052af1586c161990d359f"))
	(       57, uint256S("0x064bf9a9b15c7e14e94dd544ae6e6dbe031c1b089e09fd80b924a873fb117598"))
	(       58, uint256S("0x963577322331ad7628236094b63b90b50dd30b708de18a7da8c7d397bb309285"))
	(       59, uint256S("0x561e49b777b93d6751e73722d7ce4ee1322b968164ef56139f6d16f4445b9d1d"))
	(       60, uint256S("0xf6c3ce5dfa3016c1243d6e638ced4c44044c0c4f6a8410815d30c45f0471960f"))
	(       61, uint256S("0xc9473f1b24eb9dd279d5ea5ac83422669e47d81010efa8b440bfdad6c6d609d4"))
	(       62, uint256S("0x12f3d427bcc3572a11b1dc98de9d58d85ebf5956ee0d5d6e113d297997744e8a"))
	(       63, uint256S("0x92e918cb0b74fa92e0d4705df11f96ed6f164f53d94153421222a758a130637a"))
	(       64, uint256S("0x93561706591ff25085c50cad3d750a971c153bc68bbec3d2d936fc30997a6d6e"))
	(       65, uint256S("0x82db4a7a871959d56c04e2f842a85dd3cb75ea4f4d0c5d7e012bad53848f9e88"))
	(       66, uint256S("0xd323a002fbfed67609e590dc9864b8967db685f99aed8803b2463bf582a86e9c"))
	(       67, uint256S("0x533c2594ec95c61523035c5301f79e879cb4924da0ce52f88a4fd4d906720a48"))
	(       68, uint256S("0x8a0f44cf70002f6e650fe5571f08eadfecc5bdbd8b66154c9e0a7029960bff7c"))
	(       69, uint256S("0x1b345f4e973ff5aa69e255fef0c8188d764c3e84ffa748518c1755d1a9327a9e"))
	(       70, uint256S("0x1cfc2135774d49038866a195815370786c115e4a634eb2ca3a3cce4ab11daf7b"))
	(       71, uint256S("0x19d4e73eb10e9c8db39f7bfabf7c23278ea3384ce266c623d9f1f8dbbc313bd3"))
	(       72, uint256S("0xe1986d536c121ce93d762d41865f2bf75e1409519425db54f8999d2e615a1722"))
	(       73, uint256S("0x4a514897ba46fdcac16e2acc8c53ddd8221b8ad100524513fb837d6535df65c0"))
	(       74, uint256S("0x0af24a7fac911b7fc61b7fe993f4093cbaa20b8ce90e494f3da366ff1641e49d"))
	(       75, uint256S("0x05e79e2cee04a7be0db0d4293d583994be5681b212d8660c496615c2d10c30bd"))
	(       76, uint256S("0x406b61a91d78c2734878b8c1972bf6ef5f0c11db0921fca0cd90b9c36012b68b"))
	(       77, uint256S("0x32dd99df89a2b0e2287627105a834bd58d601439b0e91df56e834bf343167aa1"))
	(       78, uint256S("0x29b7385016246d21c34a7e397a177387a6bb980a06b5c253d167a3aa9e329f05"))
	(       79, uint256S("0xf49d782b689e766ae7226645465bac43ca8cc08cbd442edb539562da367d74b8"))
	(       80, uint256S("0xa3c6fff715284b557d82472f354fe05c679a65f9d3cfead8f691a445191acdee"))
	(       81, uint256S("0xb424e369a0c2258d0ba9f4c905e4ab2244c1444e6ef0ece5c0466d8dde058ee9"))
	(       82, uint256S("0xcb09b764cd5f9052e93ead591ac18d1c2d0d389d015c4eec78a943b416b47ffe"))
	(       83, uint256S("0x408ccfeef00d93bcd6caa80a00c94b1534018967d3e9c02e8ab0d1ec3212fc12"))
	(       84, uint256S("0xc2dfc7e7669a1af855f51e7774a263e870e31e263676578c4440e7e9a6cd2328"))
	(       85, uint256S("0x4cbf682d470f1cb7031d7b2a66b371ff8c69d9a13631dcf08db4ff391cb0d064"))
	(       86, uint256S("0x572ae80bf3ed6f9beb38b250bb2618f54bbe2fcd7f2a271170d23878639364b3"))
	(       87, uint256S("0x7ba12f4e173697a2d28666fd79a957b812b5df66b2d6fa642559d84c9f1d5b53"))
	(       88, uint256S("0x893295e81d7a589b4f66719ab71d39488e67e1807a1ead92ad0ead1871c51e14"))
	(       89, uint256S("0xf7ded0a56069aa740da1a3c282e215b0e20f319f0253d9757559e1688483b8bf"))
	(       90, uint256S("0xe1e9483b31499b4aa38f6ba6fccfc5fbea54d32b30d78de98594ad38b5ca08f5"))
	(       91, uint256S("0xab417613fca72e0278ee55b5ead152f713ab63dd381bf265ef8ae0f9b4582da2"))
	(       92, uint256S("0x52063234daf7b11a5b5e7b977281eb6600e1b053bc54db1f90e4c8816b702c26"))
	(       93, uint256S("0x7a1fe425e35b6aeb71075745a3730750aee4d98bb0d4d828ab4305b180e0580d"))
	(       94, uint256S("0x6f19fc43145ad12074191bc1ab3a5470244ca3b3bc88898490a3e65854b982bf"))
	(       95, uint256S("0xb17667e981bd7495d75b067daa4073d5f70967b2450560a8a6fe75d842d81e9d"))
	(       96, uint256S("0x00034b035a2bb56f07cad2b8d2f0b77d7e8cb0373d10807af9acd62a13aecb11"))
	(       97, uint256S("0x157f36f3d2ec1c2caf9515116d63c824942f23c0d7387aeaf89ae445ba0d1612"))
	(       98, uint256S("0x57a5c2a8bdd37c403e39c0df70ffcf05259d63a16f881587a7989b71eb67214d"))
	(       99, uint256S("0x6fffecde31bc7c25a447ac6e7b13db2c575a98ff8e6fab97d9fc2434405e5dbe"))
	(       100, uint256S("0x90c575f5704fd3d296447be3960c70eae80e9583906a18648bba6095fe2d0566"))
	(       101, uint256S("0xe130262acc84207b3a0b30d94bd51886a030b9ccf8074972cbdc40b1cc705c62"))
	(       102, uint256S("0x556a7b7aa463c042df15f74666d24c7f4e0bf73c83b4638a2fe662a28caac136"))
	(       103, uint256S("0x5bb7e3b3d41aa81f72485fdd395710752710b8149cc48cf250245658d332fb5b"))
	(       104, uint256S("0x89aa73c937e1ef143e885f7e38af04ee9a20f96aa1a21a4797bad86fc6b441c4"))
	(       105, uint256S("0x4fc571883519b027b38dd654fd3b70f9cae2ff2ed84d4a7d69447bf1c2ee85d2"))
	(       106, uint256S("0x44917bcb2aa82a0c9781ea0c13be5fc0fcd8c456ceb1dd815cad75dac5e045c4"))
	(       107, uint256S("0x3513020485e03e76e197a038201b02b500f1c202d3d153c07f3699b1ef2c7a6e"))
	(       108, uint256S("0xf406e0ff833fb0b0c113633994d9db2e13435c320871cd5bc89588fb233097f8"))
	(       109, uint256S("0x39a5854348db9decf2cd0ff1076f0ce79565a0880bc475ba687f1d3f887a377b"))
	(       110, uint256S("0xcce95eb8dc83cec009a9ff7873446b4141005cfe1e4e5894d9a82c1502f7280c"))
	(       111, uint256S("0xd8aa77e39c421fafa0e947210934b20712b1e8a689399aa89eb9c63f8ced47b2"))
	(       112, uint256S("0xa9a921958ad7f9fd7b093c62a69d316dc73698fd43cea600f22c3e97896631ad"))
	(       113, uint256S("0x7c0ef636eb8fb850be4b6ec732bd10e7d2e351525ef069241982b86aa89637cc"))
	(       114, uint256S("0x9a9f9801b017f456a0c4222c61e032658e0e3e03148daef632dbe35f7cb84018"))
	(       115, uint256S("0xc37e4e8e1329873dd375639fd637b6329ceaf1804fe7e3c271f34c3d6b822f95"))
	(       116, uint256S("0x566d8e41099b6c219101734f79e7d29f0cd16cbaae3162349e9b8af630ab4d0b"))
	(       117, uint256S("0xa3569cb90ad1d771b88e9368897f4270c35321f4bc981032258953fce51da38d"))
	(       118, uint256S("0x6dabfc13f7f8474584db4615202c3212e27ed9d45f658dfdaa3aae3e126cf646"))
	(       119, uint256S("0xf08c2aef1e644081e4e043c288e1821faaa4345eaeb903fc16fd3d9063a7f727"))
	(       120, uint256S("0xc2f4fa5dc1add98bc89cea10686e5598405af14a7a6d8569b1b43a841253a840"))
	(       121, uint256S("0x8c6176e100359bb850d48cb4eeb1a84c2cb23ef36162622d7b8d3fb426446c94"))
	(       122, uint256S("0xfc7d60f1a74ad0ef2dc6adad4856a44b2511fbe5527fbe8a37432c38a7c0c0a1"))
	(       123, uint256S("0x2bfc4f57f930bf632f524a7a7da489e6592bde6913e55daf7c8ecff70f000e13"))
	(       124, uint256S("0xbfc1b593c3163be6325f90bdab28c164a94670bfed7012cf376c4554e97f723e"))
	(       125, uint256S("0x6998bfe2aa30196b953c4fb84443117e769aeebbecd147ac2c46258061592b63"))
	(       126, uint256S("0x330cff8e29507c64664954099091248f50763301f9bea6f60c902783b1ade9c8"))
	(       127, uint256S("0x9b75eab9155c7f277d7ab45fcfaaaeb480f795d280164c0f9a037a983a83598f"))
	(       128, uint256S("0x6bcff72611832c914d39e2d4ab8147b5d7898ebd2bab524319d649d2586a1f26"))
	(       129, uint256S("0x6ae172a7e25bec2eed8d34c9ec60bfa33738c6e39b9aaf61db4e36c477750093"))
	(       130, uint256S("0x0114fb21565550866652787442958cf282c47de81a933f7b452bb03b05e8a9b6"))
	(       131, uint256S("0x64a1c44fd84a05e42904d71591fff6923a13a0fb351e0d35b94637a4322caf67"))
	(       132, uint256S("0xd17cbaf94aab9c22cc6b5c387913057d9c640bbc8d6f67c0f5c1057ac5e49109"))
	(       133, uint256S("0x388672a2324cad4982d68b9e95f09c76236c1b44dcc2e137c4fa61e5a8196bf6"))
	(       134, uint256S("0xd17f63098edba4ff5a21b0f1641b0bd2b1afc2a2eaf4471e32e650e5cc66d954"))
	(       135, uint256S("0x17793228be4abb6a3a4ba4c21a93dfa6814872eefb4e3787d8bd0617f289ad85"))
	(       136, uint256S("0xbf454674f3139643d713c4cf690edd79ade54fe0b637215c80525301e07e33b5"))
	(       137, uint256S("0x9cfc5f616cfbf3575fefbfa0910b5c8b9cf260138a8c645548e5fc4aae438284"))
	(       138, uint256S("0x6e9f526528bcbcabf433f72404a811cb0e9e007256d91b881b8f2bd424397a4e"))
	(       139, uint256S("0x466c43e0f42ecf36eeee4d871fc1d759d1a1a07dc905feb489dc535ae6d9b549"))
	(       140, uint256S("0x4140c852c0e5ca6069d2ff812bf2546243701cbb3616954f44e7f518d61d0749"))





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

        //TODO: fix this for radiocoin -- plddr
        //vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));
        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

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
