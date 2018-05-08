#include	"haskell.c"

#include "types.h"

void
test_haskell(char * buf, size_t size)
{

#define	template_NAME		"Haskell"
#define	template_CONTEXT	struct sha1_ctx
#define	template_INIT(c)	hs_cryptohash_sha1_init(c)
#define	template_UPDATE(c,b,l)	hs_cryptohash_sha1_update(c,b,l)
#define template_FINAL(c,o)	hs_cryptohash_sha1_finalize(c,o)

#include	"template_3funcs.c"

}

