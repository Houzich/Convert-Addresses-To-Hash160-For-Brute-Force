/**
  ******************************************************************************
  * @author		Anton Houzich
  * @version	V1.2.0
  * @date		16-April-2023
  * @mail		houzich_anton@mail.ru
  * discussion  https://t.me/BRUTE_FORCE_CRYPTO_WALLET
  ******************************************************************************
  */
#pragma once


#define SIZE_HASH160_FRAME					(20ULL)
#define SIZE32_HASH160_FRAME			    (20ULL / 4ULL)

#define ADDRESS_BITCOIN_LEGACY				(0)
#define ADDRESS_BITCOIN_SEGWIT				(1)
#define ADDRESS_BITCOIN_NATIVE_SEGWIT		(2)
#define ADDRESS_ETHEREUM					(3)

//#define USE_REVERSE_32


/* Four of six logical functions used in SHA-384 and SHA-512: */
#define REVERSE32_FOR_HASH(w,x)	{ \
	uint32_t tmp = (w); \
	tmp = (tmp >> 16) | (tmp << 16); \
	(x) = ((tmp & 0xff00ff00UL) >> 8) | ((tmp & 0x00ff00ffUL) << 8); \
}
#define REVERSE64_FOR_HASH(w,x)	{ \
	uint64_t tmp = (w); \
	tmp = (tmp >> 32) | (tmp << 32); \
	tmp = ((tmp & 0xff00ff00ff00ff00UL) >> 8) | \
	      ((tmp & 0x00ff00ff00ff00ffUL) << 8); \
	(x) = ((tmp & 0xffff0000ffff0000UL) >> 16) | \
	      ((tmp & 0x0000ffff0000ffffUL) << 16); \
}