
#define	SHA1_OUTPUT_LEN	20

typedef unsigned long long timestamp_t;

timestamp_t timestamp(void);

void	report(char * name, unsigned char * res, timestamp_t usecs);

