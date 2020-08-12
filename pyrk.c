#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "pyrk/yespower/yespower.h"
#include "pyrk/x11/x11.h"
#include "pyrk/scrypt/scrypt.h"
#include "pyrk/sha256/sha256.h"

const bool debug = true;

enum {
    BLOCK_VERSION_DEFAULT        = 2,
    BLOCK_VERSION_ALGO           = (7 << 9),
    BLOCK_VERSION_SCRYPT         = (0 << 9),
    BLOCK_VERSION_SHA256D        = (2 << 9),
    BLOCK_VERSION_X11            = (4 << 9),
    BLOCK_VERSION_YESPOWER       = (6 << 9),
};

void printpow(char* hash)
{
    char debughash[65]={0};
    for (int i=0; i<32; i++)
      sprintf(debughash+(i*2),"%02hhx",hash[i]);
    printf("%s\n", debughash);
}

void pyrk_multialgo(const char* input, char* output)
{
    memset(output,0,32);
    uint32_t nVersion = *(uint32_t*)&input[0];
    uint32_t nSelect = nVersion & BLOCK_VERSION_ALGO;
    printf("%08x ", nSelect);

    switch (nSelect)
    {
        case BLOCK_VERSION_SCRYPT:
            scrypt_1024_1_1_256(input, output);
            if (debug) {
                printf("scrypt ");
                printpow(output);
            }
            return;
        case BLOCK_VERSION_SHA256D:
            sha256d_hash(input, output);
            if (debug) {
                printf("sha256d ");
                printpow(output);
            }
            return;
        case BLOCK_VERSION_X11:
            x11_hash(input, output, 80);
            if (debug) {
                printf("x11 ");
                printpow(output);
            }
            return;
        case BLOCK_VERSION_YESPOWER:
            yespower_hash(input, output);
            if (debug) {
                printf("yespower ");
                printpow(output);
            }
            return;
    }
    //! if none match
    scrypt_1024_1_1_256(input, output);
    if (debug) {
        printf("scrypt ");
        printpow(output);
    }
    return;
}
