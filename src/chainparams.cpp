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
        // BIP34 is never enforced in Dogecoin v2 blocks, so we enforce from v3
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256S("0xe6906d8891d54ff856937090a55b7c8a18b51a18d2b5f41cc1f281ec3c9663cb");
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

        // By default assume that the signatures in ancestors of this block are valid.
//        consensus.defaultAssumeValid = uint256S("0x77e3f4a4bcb4a2c15e8015525e3d15b466f6c022f6ca82698f329edef7d9777e"); // 2,510,150
        consensus.defaultAssumeValid = uint256S("0xe6906d8891d54ff856937090a55b7c8a18b51a18d2b5f41cc1f281ec3c9663cb");

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
        pchMessageStart[0] = 0xc0;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xc0;
        pchMessageStart[3] = 0xc0;
        vAlertPubKey = ParseHex("04770ee175cb5530e95cd615c061738719116d871ad9fcc9292ea6b0d396f7d270c12f351ff674b030299b537e9fa062511ac67b8bfc4d68cfcc2fd86158e0e6b3");
        nDefaultPort = 9333;
        nPruneAfterHeight = 100000;

//        genesis = CreateGenesisBlock(1386325540, 99943, 0x1e0ffff0, 1, 88 * COIN);

genesis = CreateGenesisBlock(1622171724, 84337, 0x1e0ffff0, 1, 88 * COIN);

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




        consensus.hashGenesisBlock = genesis.GetHash();
        digishieldConsensus.hashGenesisBlock = consensus.hashGenesisBlock;
        auxpowConsensus.hashGenesisBlock = consensus.hashGenesisBlock;


/*main_nonce: 84337
 main_time: 1622171724
 main_hash: 000008f3108b9b62492a71ff55f58f90678baf0ddeb75d11480f9355df6d1204
 main_merklehash: d2f90d0bedfafd698b095b35d4163277785ee39c355f4f82b78284a7397924f5
*/

        assert(consensus.hashGenesisBlock == uint256S("0x000008f3108b9b62492a71ff55f58f90678baf0ddeb75d11480f9355df6d1204"));
        assert(genesis.hashMerkleRoot == uint256S("0x0d2f90d0bedfafd698b095b35d4163277785ee39c355f4f82b78284a7397924f5"));

        // Note that of those with the service bits flag, most only support a subset of possible options
        vSeeds.push_back(CDNSSeedData("multidoge.org", "seed.multidoge.org", true));
        vSeeds.push_back(CDNSSeedData("multidoge.org", "seed2.multidoge.org"));

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
//            boost::assign::map_list_of

/*
	 (	0, uint256S("0x000008f3108b9b62492a71ff55f58f90678baf0ddeb75d11480f9355df6d1204"))
	 (	1, uint256S("0xe6906d8891d54ff856937090a55b7c8a18b51a18d2b5f41cc1f281ec3c9663cb"))
	 (	2, uint256S("0xb08893ba69843c3424f928d2b50212f6872d10f610af9a3b8e2e0e2e87afba0c"))
	 (	3, uint256S("0x116f306b8dbbe6a0cb0b13333a1f64943d3e035864c1b1cbfeff211db8df0b70"))
	 (	4, uint256S("0x30b802974077db766d45fbb17e847b22aa8ece0ddda7e70b255d331fc6b832ed"))
	 (	5, uint256S("0x1fb281d19ebc88da50871ba1a839a7988aa6a76b493ae3eae595db405d4c70bb"))
	 (	6, uint256S("0x56971426c2e8608d0af3a9c478b254fd56051d57f76c801bb95e46e01bbc069c"))
	 (	7, uint256S("0x08a954a70382f8665dc0dde8c687ae6095bc5df89308d555820078cec5ceccc5"))
	 (	8, uint256S("0xfe24ae89daa7b72ee4cc830ce54ff3e3aeaa6492465702b3cdb36529d884fc7e"))
	 (	9, uint256S("0x710f6149dcf16b80dbe3d3d3e1b8c489e71135b550ee41f83533f515ec3127ff"))
 	 (	10, uint256S("0x59aab7790c779bec2f0aa106184bcfb5ce92ee3f9c9782e718494a426d565dd7"))
	 (	11, uint256S("0x638e6794bb8ef09cc9b7403f02fc60a8c09237ae10a7afe49428bd3b86a858a5"))
	 (	12, uint256S("0x0397fe4b96052d023a8d23dc9a1cd134ceda95292bacc1abf5b8f8e7bc33c432"))
	 (	13, uint256S("0x249fc8a8712f86e849cee14dd407056d20a0126202d31cc4ee82454ce0bd2658"))
	 (	14, uint256S("0x2f512a77a949557ce15e35f31421d619a3317b4622d286f02dbf239e3e7cdcd4"))
	 (	15, uint256S("0x2f2826a0ad3431db98d846f05c1ef106ed81aac6415d7041ba4b4116cbde6a4e"))
	 (	16, uint256S("0x0f3b51970fcaa7fc1a40bc8692ac845ab73ca8275d14e28b0d3e532ef0fc75e9"))
	 (	17, uint256S("0xbeab2af7ba5079308a9af05d796d5fbd66b2e3bb86f28d1af08adf7d4119bb17"))
	 (	18, uint256S("0x9ac69c43bd90f9753ba60e1d80745013d323200bb58f40ef95fb5fc68b7ccbea"))
	 (	19, uint256S("0xc73a5e71f6a9831b7cd89834fc37fdda0ea8e2d8d2ad25da6cb49b7a77e30838"))
	 (	20, uint256S("0x249291be987ae49595beefbbbf6e89044586d70f3cb9b139b145dbc53eb58e64"))
	 (	21, uint256S("0xae20b7ae5afee8302ddaa07e7f475f340ae54ab073309a068ce6d5d39b8ad6d8"))
	 (	22, uint256S("0xf7eb091b7dfbf5a31c9e39c1b6448963c0d3ede3a7e21c25605bba706727c8b4"))
	 (	23, uint256S("0x1a40d8a722a11d3d17a0814f8865104773838bc53b8347be38d0e02507d660c0"))
	 (	24, uint256S("0x3c9e768a7c4e21de9fbb8e2ecd1e1a990d1e60bcda5139b4651c0e27181267d8"))
	 (	25, uint256S("0x05a41fe6ec27fe30709f44d26458f4296bd1b2725e6d77e3db8c05938a0c2062"))
	 (	26, uint256S("0x29f3f1b68aa95e5f1b43a9266541a137f1badbedd25dca0a2c11b26edc1ded0f"))
	 (	27, uint256S("0x0b69ab5da28b77e660bda602fadb8b78658f6f0920fd24820ff928b19fd77523"))
	 (	28, uint256S("0x77d234866ad02d63c34c171131197203899b48552878f206b1d33cb53040c998"))
	 (	29, uint256S("0x14c08ce7694dfa773bdce94f0c246020443a952cf091a97c65b7954a7a39d6d6"))
	 (	30, uint256S("0x736198c0db7db2d5f88b3621441355705ccf4cb4ae59d45da5259b93a1e80a39"))
	 (	31, uint256S("0x8217b5db9aefa730dd3516b3deaabff2320779cf054d976cedf3e161f6f39574"))
	 (	32, uint256S("0x78ffe7575a60bd5a3a097d12710f243d9356d661c62a65e20a812b278aabe4bb"))
	 (	33, uint256S("0xa7f7e15d231fc778035dcce07c540ead17fe39227c859eeb7cf93f990d53f4c6"))
*/
        };

        chainTxData = ChainTxData{
            // Data as of block 954c7c66dee51f0a3fb1edb26200b735f5275fe54d9505c76ebd2bcabac36f1e (height 3606083).
            // Tx estimate based on average of year 2021 (~40k transactions per day)
            1613217680, // * UNIX timestamp of last checkpoint block
            71035468,   // * total number of transactions between genesis and last checkpoint
                        //   (the tx=... number in the SetBestChain debug.log lines)
            0.46        // * estimated number of transactions per second after checkpoint
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
        // BIP34 is never enforced in Dogecoin v2 blocks, so we enforce from v3
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

        // Deployment of BIP68, BIP112, and BIP113.
        // XXX: BIP heights and hashes all need to be updated to Dogecoin values
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1456790400; // March 1st, 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1493596800; // May 1st, 2017

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1462060800; // May 1st 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 0; // Disabled

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00000000000000000000000000000000000000000000000000001030d1382ade");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x000003cc12eab2850a7617e26bc1c145f647624c9e60cdbdb9e779a883b0e5b1");

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

//        genesis = CreateGenesisBlock(1391503289, 997879, 0x1e0ffff0, 1, 88 * COIN);
        genesis = CreateGenesisBlock(1486949366, 618865, 0x1e0ffff0, 1, 50 * COIN);

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

        };

        chainTxData = ChainTxData{
            // Data as of block a113c41c00934f940a41f99d18b2ad9aefd183a4b7fe80527e1e6c12779bd024 (height 3062910)
            1613217942, // * UNIX timestamp of last checkpoint block
            4186373,    // * total number of transactions between genesis and last checkpoint
            0.05        // * estimated number of transactions per second after that timestamp
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

        // Dogecoin parameters
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
            ( 0, uint256S("0x3d2160a3b5dc4a9d62e7e66a295f70313ac808440ef7400d6c0772171ce973a5"))
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

