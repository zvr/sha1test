#include	"coreutils.c"

#include "types.h"

void
test_coreutils_3(char * buf, size_t size)
{

#define	template_NAME		"coreutils"
#define	template_CONTEXT	struct sha1_ctx
#define	template_INIT(c)	sha1_init_ctx(c)
#define	template_UPDATE(c,b,l)	sha1_process_bytes(b, l, c)
#define template_FINAL(c,o)	sha1_finish_ctx(c,o)

#include	"template_3funcs.c"

}

void
test_coreutils_1(char * buf, size_t size)
{
    unsigned char	o[SHA1_OUTPUT_LEN];

    timestamp_t t0 = timestamp();

    sha1_buffer(buf, size, o);

    timestamp_t t1 = timestamp();

    report("coreutils sha1_buffer()", o, t1-t0);
}

