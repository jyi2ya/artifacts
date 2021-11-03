#include <stdio.h>

#define H_SIZE 1000009
#define H_NUM 10
struct {
	struct {
		int siz, fir;
		short nxt[H_NUM];
		struct {
			long long key;
			double val;
		} N[H_NUM];
	} N[H_SIZE];
} H;

int main(void)
{
	printf("%ld\n", sizeof(H) / 1000 / 1000);
	return 0;
}
