
#include <openssl/sha.h>

#include "types.h"

void
test_openssl_3(char * buf, size_t size)
{

#define	template_NAME		"OpenSSL SHA1_* funcs"
#define	template_CONTEXT	SHA_CTX
#define	template_INIT(c)	SHA1_Init(c)
#define	template_UPDATE(c,b,l)	SHA1_Update(c,b,l)
#define template_FINAL(c,o)	SHA1_Final(o,c)

#include	"template_3funcs.c"

}

void
test_openssl_1(char * buf, size_t size)
{
    unsigned char	o[SHA_DIGEST_LENGTH];

    timestamp_t t0 = timestamp();

    SHA1(buf, size, o);

    timestamp_t t1 = timestamp();

    report("OpenSSL SHA1()", o, t1-t0);
}


#include <openssl/bio.h>
#include <openssl/evp.h>

void
test_openssl_biomem(char * buf, size_t size)
{
    unsigned char	o[EVP_MAX_MD_SIZE];
    BIO *		mdbio;
    BIO *		membio;

    timestamp_t t0 = timestamp();

    mdbio = BIO_new(BIO_f_md());
    BIO_set_md(mdbio, EVP_sha1());

    membio = BIO_new_mem_buf(buf, size);

    BIO_push(mdbio, membio);

    BIO_gets(mdbio, o, sizeof(o));

    timestamp_t t1 = timestamp();

    report("OpenSSL BIO memory", o, t1-t0);
}


void
test_openssl_biofile(char * fname)
{
    unsigned char	o[EVP_MAX_MD_SIZE];
    BIO *		mdbio;
    BIO *		filebio;

    timestamp_t t0 = timestamp();

    mdbio = BIO_new(BIO_f_md());
    BIO_set_md(mdbio, EVP_sha1());

    filebio = BIO_new_file(fname, "r");

    // BIO_read(filebio, 

    BIO_push(mdbio, filebio);

    BIO_gets(mdbio, o, sizeof(o));

    timestamp_t t1 = timestamp();

    report("OpenSSL BIO file", o, t1-t0);
}

