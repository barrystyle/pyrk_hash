#include <stdint.h>
#include <stdlib.h>
#include <openssl/sha.h>

void sha256d_hash(input, output)
{
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, 80);
    SHA256_Final(output, &sha256);
    SHA256_Update(&sha256, output, 32);
    SHA256_Final(output, &sha256);
}
    
