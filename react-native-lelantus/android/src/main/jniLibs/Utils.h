#ifndef ORG_FIRO_LELANTUS_UTILS_H
#define ORG_FIRO_LELANTUS_UTILS_H

#include "liblelantus/include/lelantus.h"

#define LELANTUS_TX_TPAYLOAD 47

static const int PUBLIC_COIN_LENGTH = 34;
static const int MINT_SCRIPT_LENGTH = 165;
static const int SPEND_SCRIPT_LENGTH = 165;

struct LelantusEntry {
	bool isUsed;
	int height;
	int anonymitySetId;
	int64_t amount;
	uint32_t index;
};

char const hexArray[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
						   'e', 'f'};

unsigned char *hex2bin(const char *str);

const char *bin2hex(const unsigned char *bytes, int size);

const char *bin2hex(const char *bytes, int size);

const char *bin2hex(std::vector<unsigned char> bytes, int size);

const char *CreateMintScript(
		uint64_t value,
		const char *keydata,
		int32_t index,
		const char *seedID
);

const char *GetPublicCoin(
		uint64_t value,
		const char *keydata,
		int32_t index
);

uint64_t EstimateFee(
		uint64_t spendAmount,
		bool subtractFeeFromAmount,
		const char *keydata,
		std::list<LelantusEntry> coins,
		uint64_t &changeToMint
);

uint32_t GetMintKeyPath(
		uint64_t value,
		const char *keydata,
		int32_t index
);

const char *CreateJMintScript(
		uint64_t value,
		const char *keydata,
		int32_t index,
		const char *seedID,
		const char *AESkeydata);

const char *CreateJoinSplitScript(
		const char *txHash,
		uint64_t spendAmount,
		bool subtractFeeFromAmount,
		const char *keydata,
		uint32_t index,
		std::list<LelantusEntry> coins
);

#endif //ORG_FIRO_LELANTUS_UTILS_H
