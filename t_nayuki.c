
#include	"nayuki.c"

#include "types.h"

void
test_nayuki(char * buf, size_t size)
{
    uint32_t hash[5];

    timestamp_t t0 = timestamp();

    sha1_hash(buf, size, hash);

    timestamp_t t1 = timestamp();

    unsigned char	o[SHA1_OUTPUT_LEN];
    memcpy(o, hash, SHA1_OUTPUT_LEN);

    report("nayuki", o, t1-t0);
}

