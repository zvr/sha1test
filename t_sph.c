
#include	"sph.c"

#include "types.h"

void
test_sph(char * buf, size_t size)
{

#define	template_NAME		"SPHlib"
#define	template_CONTEXT	sph_sha1_context
#define	template_INIT(c)	sph_sha1_init(c)
#define	template_UPDATE(c,b,l)	sph_sha1(c,b,l)
#define template_FINAL(c,o)	sph_sha1_close(c,o)

#include	"template_3funcs.c"

}

