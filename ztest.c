
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <fcntl.h>
#include <unistd.h>

#include "types.h"

void test_coreutils_1(char *buf, size_t size);
void test_coreutils_3(char *buf, size_t size);
void test_haskell(char *buf, size_t size);
void test_nayuki(char *buf, size_t size);
void test_openssl_1(char *buf, size_t size);
void test_openssl_3(char *buf, size_t size);
void test_openssl_biomem(char *buf, size_t size);
void test_openssl_biofile(char * fname);
void test_sph(char *buf, size_t size);

timestamp_t
timestamp()
{
    struct timeval	now;
    gettimeofday(&now, NULL);
    return (timestamp_t) now.tv_sec * 1000000 + now.tv_usec;
}

void
report(char * name, unsigned char * res, timestamp_t usecs)
{
    printf("%llu\t", usecs);
    for (int i = 0; i < SHA1_OUTPUT_LEN; i++)
	printf("%02x", res[i]);
    printf("\t%s\n", name);
}

void
test_func(char * fname, size_t fsize, void (*func)(char *, size_t))
{
    int fd = open(fname, O_RDONLY);    
    char *	buf = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE, fd, 0);
    madvise(buf, fsize, MADV_SEQUENTIAL);
    func(buf, fsize);
    close(fd);
}

int
main(int argc, char ** argv)
{
    if (argc == 1) {
	fprintf(stderr, "Usage: %s <filename>\n", *argv);
	exit(1);
    }
    struct stat	argstat;
    stat(*++argv, &argstat);

#define	TEST_FUNC(f)	test_func(*argv, argstat.st_size, f)

    TEST_FUNC(test_coreutils_1);
    TEST_FUNC(test_coreutils_3);
    TEST_FUNC(test_nayuki);
    TEST_FUNC(test_openssl_1);
    TEST_FUNC(test_openssl_3);
    // TEST_FUNC(test_openssl_biomem);
    TEST_FUNC(test_sph);
    TEST_FUNC(test_haskell);

    // test_openssl_biofile(*argv);

    exit(0);
}

