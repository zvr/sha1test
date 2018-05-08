PROG = sha1test
TESTFILE = /tmp/bigfile

CC = gcc
CFLAGS = -Ofast -march=native
LIBS = -lcrypto

HEADER = types.h
TEMPLATE = template_3funcs.c

OBJS = \
	t_coreutils.o \
	t_haskell.o \
	t_nayuki.o \
	t_openssl.o \
	t_sph.o \
	ztest.o \
	$(EMPTY)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $? $(LIBS)

test: $(PROG) $(TESTFILE)
	cat $(TESTFILE) > /dev/null
	./$(PROG) $(TESTFILE)

clean:
	-$(RM) $(OBJS)

t_coreutils.o: t_coreutils.c coreutils.c $(HEADER) $(TEMPLATE)
t_haskell.o: t_haskell.c haskell.c $(HEADER) $(TEMPLATE)
t_nayuki.o: t_nayuki.c nayuki.c $(HEADER)
t_openssl.o: t_openssl.c $(HEADER) $(TEMPLATE)
t_sph.o: t_sph.c sph.c $(HEADER) $(TEMPLATE)
ztest.o: ztest.c $(HEADER)

