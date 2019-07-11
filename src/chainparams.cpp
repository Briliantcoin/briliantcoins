// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */
static Checkpoints::MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        ( 0, uint256("0x04578e13aa752f24c4396823febf8a6762416d6e088010a320e95771c5aa0c42"))
        ( 1000, uint256("0xa62de049949277496487a7cf2d1f2fe8d21acb5e007051ffc5d05015d8abfffa"))
        ( 32000, uint256("0xb5cd6e6b08cddca51593d2f15a4578efbbe4c6ae2d472010a961fe8c2ad7ea64"))
        ( 64000, uint256("0xd444affd0bca745bcb28bffea34f9521a9f4225b202aaccdd7e85c220021992f"))
        ( 68886, uint256("0x09cb7123227f99b175fe40bee596191045bdb78591094de518bc57034c5160ef"))
        ( 68911, uint256("0x3484b1975ce95f8e8ec75b95767d947435855c61a0cfb75197d47141f51d9c05"))
        ( 68912, uint256("0xc1e07231530f16428ae3daad97901d9ad430ec50e2678527cb176331c014abf6"))
        ( 82333, uint256("0x48a63d48372c96432547bd40eb912bc95c990ec44cdf20e05bc1a622f9ac872f"))
        ( 82334, uint256("0x5a2456bf4f18b0257ed294a237f36196485252402a019bd2f7ec2d9222f0c604"))
        ( 96544, uint256("0x0ebc20cc206e119ed53f6f0130badebdaa07d75114e91a8e8911a34cd4b25f0d"))
        ( 96837, uint256("0x05a60a9cff06d177fdc0c63cae9a64bbc776fb7c3ebcf6319dcf61e76e267aba"))
        ( 98000, uint256("0x0fee2b491f069da2865cdecd4cef6e0eafed7882b1bb0e0d89dc8e6e91820c65"))
        ( 99000, uint256("0x0480f1e884cf7495f4fafe4a992e5e1dfc0011293e36181c909dc8dc3b7488e6"))
        ( 110000, uint256("0x06a9bc974358ed5b2c0751723559921d512c85aa6c2da1e73cd4b7091573f613"))
        ( 111401, uint256("0x639dd70470c381d361ea32fe354ab867e28de6b623f91e35c873c07c7dfd9593"))
        ( 111500, uint256("0x9351fe538afe6cf3e880680233732e9f6d579dea6c6ed144362eaf8f1dff4808"))
        ( 120000, uint256("0x7d64c0de4b8f54fe31b5f913c73788a4a84f3e7c390bdf70115e94b8c2497f22"))
        ( 140000, uint256("0x4248dead9734e93cb3582b9a229150d82e336a5c38aff6f7790f6ea86cd2681e"))
        ( 160000, uint256("0xcb9cc825dc3ae201ae6b49db8b576ec435aa051f85ca91eda7300621ce1faa6f"))
        ( 180000, uint256("0x152f175a22a803b1e8ef675827a218ec1bf1cc8ea614ba0a251132489e409f1a"))
        ( 200000, uint256("0x9b3b68c58e36e41efd6a257483b8b38fe2fa81e3f8303ae04c9f5af9b988f03a"))
        ( 210000, uint256("0xfbfa7ad296970e87f501675240de21d5ff419848c29158a579960f98cba839b5"))
        ( 240000, uint256("0x5f583e57c283d7852069d61f8eafcccc0aab94ecfeb0fab540e3a20201559eff"))
        ( 260000, uint256("0xb7680a04d81bcccb4bf6e698bdb73f502b0ab174c53076ddef506ef32c5261fd"))
        ( 280000, uint256("0x47ddb900e7d4b0bd9182d87cae4d94db6f216ba2db66ce938be3edf2e5d934da"))
        ( 300000, uint256("0x2e93e2f919aea103cb586f2a82460848418665b1ebc0c78beca37577f1189540"))
        ( 320000, uint256("0xb083361d5443f2ced71aa49eb19fffb4956b148cb978d4cc7e70f5fe9b2c2ee2"))
        ( 340000, uint256("0x7198fa8c9ac668837676b81f7c39aa12f9f087a798eb3f18807b5152afb517f9"))
        ( 360000, uint256("0x6fe10bed686606c0f74bbf43321146a8f495e34b58d2f2847611b48b068816a4"))
        ( 380000, uint256("0x9a92724b64f3f08ec789b22214f7a4803464fae14bb8eb48e8fcd0e5cb04a9f3"))
        ;
static const Checkpoints::CCheckpointData data = {
        &mapCheckpoints,
        1562239916, // * UNIX timestamp of last checkpoint block d77cb63a40042d73a83142383c7872c123cda7253db1d9c0effc8a029ca857b2
        381591,   // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        1152.0     // * estimated number of transactions per day after checkpoint
    };

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, uint256("0x04578e13aa752f24c4396823febf8a6762416d6e088010a320e95771c5aa0c42"))		
        ( 1000, uint256("0xa62de049949277496487a7cf2d1f2fe8d21acb5e007051ffc5d05015d8abfffa"))
        ( 32000, uint256("0xb5cd6e6b08cddca51593d2f15a4578efbbe4c6ae2d472010a961fe8c2ad7ea64"))
        ( 64000, uint256("0xd444affd0bca745bcb28bffea34f9521a9f4225b202aaccdd7e85c220021992f"))
        ( 68885, uint256("0x3b818d0f9313b3400c8b79365f692733bf3996264b1d593acfd307e08838889f"))
        ;
static const Checkpoints::CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1498286764, // block 64000 - 1497520266,  68885 - 1498286764
        69358,  // 64455 , 69358
        630
    };

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
        boost::assign::map_list_of
        ( 0, uint256("0xa2d875cf8a6aba0718f9224ebda9bc5c97dbce25363ae9b7279aa7cad51e03b8"))
        ;
static const Checkpoints::CCheckpointData dataRegtest = {
        &mapCheckpointsRegtest,
        0,
        0,
        0
    };

class CMainParams : public CChainParams {
public:
    CMainParams() {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
		pchMessageStart[0] = 0xfb;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;
        vAlertPubKey = ParseHex("04ab1877684062954fc451f0d0910f825b599dc07e22260555b679a2848330c749bd96ad79460b1116db20ad50ebf35572aea93be4506011ff42145ca34b859b29");
        nDefaultPort = 8544;
        bnProofOfWorkLimit = ~uint256(0) >> 20;
        nSubsidyHalvingInterval = 210000;
        nProofOfWorkZero = 210000 * 60 * 10; 
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        nTargetTimespanx = 10 * 60; // 10 minutes
        nTargetTimespans = 5 * 60; // 5 minutes
        nTargetSpacing = 2.5 * 60; // 2.5 minutes
        nMaxTipAge = 24 * 60 * 60;

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         * 
         * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
         *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
         *   vMerkleTree: 4a5e1e
         */
        const char* pszTimestamp = "Brilliant day Wednesday, 15-Feb-17 00:00:00 UTC";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = nProofOfWorkZero * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04398760c178db985a4e4c99da16aaea05d438ab5cfd3876db07ebba822ff755a531bcee08a927dd2131571cf75970ae6298f50989b0c51ca9242357cf64e3f265") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1487116800;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 110133;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x04578e13aa752f24c4396823febf8a6762416d6e088010a320e95771c5aa0c42"));
        assert(genesis.hashMerkleRoot == uint256("0x465cb641998e0a58361d48d1f9809857e05e609aa05919466e7a91a72f7bd499"));
		
		vSeeds.push_back(CDNSSeedData("king.odj.ru", "king.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king1.odj.ru", "king1.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king2.odj.ru", "king2.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king3.odj.ru", "king3.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king4.odj.ru", "king4.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king5.odj.ru", "king5.odj.ru"));
		
		vSeeds.push_back(CDNSSeedData("nodea.exip.net", "nodea.exip.net"));
		vSeeds.push_back(CDNSSeedData("nodeb.exip.net", "nodeb.exip.net"));
		vSeeds.push_back(CDNSSeedData("nodec.exip.net", "nodec.exip.net"));
		vSeeds.push_back(CDNSSeedData("nodes.exip.net", "nodes.exip.net"));
		vSeeds.push_back(CDNSSeedData("node1.exip.net", "node1.exip.net"));
		vSeeds.push_back(CDNSSeedData("node2.exip.net", "node2.exip.net"));
		vSeeds.push_back(CDNSSeedData("node3.exip.net", "node3.exip.net"));
		vSeeds.push_back(CDNSSeedData("node4.exip.net", "node4.exip.net"));
		vSeeds.push_back(CDNSSeedData("node5.exip.net", "node5.exip.net"));

		vSeeds.push_back(CDNSSeedData("node.briliantcoin.info", "node.briliantcoin.info"));
		vSeeds.push_back(CDNSSeedData("node1.briliantcoin.info", "node1.briliantcoin.info"));
		vSeeds.push_back(CDNSSeedData("node2.briliantcoin.info", "node2.briliantcoin.info"));
		vSeeds.push_back(CDNSSeedData("node3.briliantcoin.info", "node3.briliantcoin.info"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(0);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
        base58Prefixes[SECRET_KEY] =     list_of(128);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        // Briliantcoin: Mainnet v2 enforced as of block 710k
        nEnforceV2AfterHeight = 710000;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        /*
		*pchMessageStart[0] = 0xfc;
        *pchMessageStart[1] = 0xc1;
        *pchMessageStart[2] = 0xb7;
        *pchMessageStart[3] = 0xdc;
		**/
		pchMessageStart[0] = 0xfb;
		pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;
        vAlertPubKey = ParseHex("04ab1877684062954fc451f0d0910f825b599dc07e22260555b679a2848330c749bd96ad79460b1116db20ad50ebf35572aea93be4506011ff42145ca34b859b29");
        nDefaultPort = 9333;
        bnProofOfWorkLimit = ~uint256(0) >> 20; //empty
        nSubsidyHalvingInterval = 210000; //empty
        nEnforceBlockUpgradeMajority = 750; //51
        nRejectBlockOutdatedMajority = 950; //75
        nToCheckBlockUpgradeMajority = 1000; //100
        nMinerThreads = 0;
        nTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        nTargetTimespanx = 10 * 60; // 10 minutes
        nTargetTimespans = 5 * 60; // 5 minutes
        nTargetSpacing = 2.5 * 60; // 2.5 minutes
        nMaxTipAge = 24 * 60 * 60;
        //nMaxTipAge = 0x7fffffff;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1487116800;
        genesis.nNonce = 110133;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x04578e13aa752f24c4396823febf8a6762416d6e088010a320e95771c5aa0c42"));

        vFixedSeeds.clear();
        vSeeds.clear();

		vSeeds.push_back(CDNSSeedData("king.odj.ru", "king.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king1.odj.ru", "king1.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king2.odj.ru", "king2.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king3.odj.ru", "king3.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king4.odj.ru", "king4.odj.ru"));
		vSeeds.push_back(CDNSSeedData("king5.odj.ru", "king5.odj.ru"));

		vSeeds.push_back(CDNSSeedData("nodea.exip.net", "nodea.exip.net"));
		vSeeds.push_back(CDNSSeedData("nodeb.exip.net", "nodeb.exip.net"));
		vSeeds.push_back(CDNSSeedData("nodec.exip.net", "nodec.exip.net"));
		vSeeds.push_back(CDNSSeedData("nodes.exip.net", "nodes.exip.net"));
		vSeeds.push_back(CDNSSeedData("node1.exip.net", "node1.exip.net"));
		vSeeds.push_back(CDNSSeedData("node2.exip.net", "node2.exip.net"));
		vSeeds.push_back(CDNSSeedData("node3.exip.net", "node3.exip.net"));
		vSeeds.push_back(CDNSSeedData("node4.exip.net", "node4.exip.net"));
		vSeeds.push_back(CDNSSeedData("node5.exip.net", "node5.exip.net"));

		vSeeds.push_back(CDNSSeedData("node.briliantcoin.info", "node.briliantcoin.info"));
		vSeeds.push_back(CDNSSeedData("node1.briliantcoin.info", "node1.briliantcoin.info"));
		vSeeds.push_back(CDNSSeedData("node2.briliantcoin.info", "node2.briliantcoin.info"));
		vSeeds.push_back(CDNSSeedData("node3.briliantcoin.info", "node3.briliantcoin.info"));
		
        base58Prefixes[PUBKEY_ADDRESS] = list_of(48);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
        base58Prefixes[SECRET_KEY] =     list_of(176);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);
		
        //base58Prefixes[PUBKEY_ADDRESS] = list_of(111);
        //base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
        //base58Prefixes[SECRET_KEY]     = list_of(239);
        //base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        //base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false; //true
        fDefaultConsistencyChecks = false;
        fRequireStandard = true; //false
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false; //true

        // Briliantcoin: Testnet v2 enforced as of block 400k
        nEnforceV2AfterHeight = 710000;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 3.5 * 24 * 60 * 60; // 3.5 days
        nTargetTimespanx = 10 * 60; // 10 minutes
        nTargetTimespans = 5 * 60; // 5 minutes
        nTargetSpacing = 2.5 * 60; // 2.5 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nMaxTipAge = 24 * 60 * 60;
        genesis.nTime = 1487116200;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 19444;
        assert(hashGenesisBlock == uint256("0xa2d875cf8a6aba0718f9224ebda9bc5c97dbce25363ae9b7279aa7cad51e03b8"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;

        // Briliantcoin: v2 enforced using Bitcoin's supermajority rule
        nEnforceV2AfterHeight = -1;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams {
public:
    CUnitTestParams() {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 18445;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;

        // Briliantcoin: v2 enforced using Bitcoin's supermajority rule
        nEnforceV2AfterHeight = -1;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const 
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval)  { nSubsidyHalvingInterval=anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority)  { nEnforceBlockUpgradeMajority=anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority)  { nRejectBlockOutdatedMajority=anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority)  { nToCheckBlockUpgradeMajority=anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks)  { fDefaultConsistencyChecks=afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) {  fAllowMinDifficultyBlocks=afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams *pCurrentParams = 0;

CModifiableParams *ModifiableParams()
{
   assert(pCurrentParams);
   assert(pCurrentParams==&unitTestParams);
   return (CModifiableParams*)&unitTestParams;
}

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams &Params(CBaseChainParams::Network network) {
    switch (network) {
        case CBaseChainParams::MAIN:
            return mainParams;
        case CBaseChainParams::TESTNET:
            return testNetParams;
        case CBaseChainParams::REGTEST:
            return regTestParams;
        case CBaseChainParams::UNITTEST:
            return unitTestParams;
        default:
            assert(false && "Unimplemented network");
            return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network) {
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
