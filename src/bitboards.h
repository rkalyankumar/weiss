// bitboards.h

#pragma once

#include "types.h"


#define SETBIT(bb, sq) ((bb) |= SquareBB[(sq)])
#define CLRBIT(bb, sq) ((bb) ^= SquareBB[(sq)])


enum {
    fileABB = 0x0101010101010101,
    fileBBB = 0x0202020202020202,
    fileCBB = 0x0404040404040404,
    fileDBB = 0x0808080808080808,
    fileEBB = 0x1010101010101010,
    fileFBB = 0x2020202020202020,
    fileGBB = 0x4040404040404040,
    fileHBB = 0x8080808080808080,

    rank1BB = 0xFF,
    rank2BB = 0xFF00,
    rank3BB = 0xFF0000,
    rank4BB = 0xFF000000,
    rank5BB = 0xFF00000000,
    rank6BB = 0xFF0000000000,
    rank7BB = 0xFF000000000000,
    rank8BB = 0xFF00000000000000,
};

// Used for checking legality of castling
static const Bitboard bitB1C1D1 = (1ULL << B1) | (1ULL << C1) | (1ULL << D1);
static const Bitboard bitB8C8D8 = (1ULL << B8) | (1ULL << C8) | (1ULL << D8);
static const Bitboard bitF1G1   = (1ULL << F1) | (1ULL << G1);
static const Bitboard bitF8G8   = (1ULL << F8) | (1ULL << G8);


extern Bitboard SquareBB[64];

extern const Bitboard fileBB[8];
extern const Bitboard rankBB[8];

// void PrintBB(const Bitboard bb);

// Population count/Hamming weight
INLINE int PopCount(const Bitboard bb) {

    return __builtin_popcountll(bb);
}

// Returns the index of the least significant bit
INLINE int Lsb(const Bitboard bb) {

    assert(bb);
    return __builtin_ctzll(bb);
}

// Returns the index of the least significant bit and unsets it
INLINE int PopLsb(Bitboard *bb) {

    int lsb = Lsb(*bb);
    *bb &= (*bb - 1);

    return lsb;
}