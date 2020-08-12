import argon2m_hash
from binascii import unhexlify, hexlify

merge_genesis = '0100000000000000000000000000000000000000000000000000000000000000000000001ccca66a44f8bd5545c3164a3a76da50395328c9075633775bc4c8798fd6772b700d215cf0ff0f1eb3791e00'

genesisbin = unhexlify(merge_genesis)

print (hexlify(argon2m_hash.getPoWHash(genesisbin))[::-1])
