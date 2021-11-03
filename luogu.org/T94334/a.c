#include <stdio.h>

#define MAX 100000000

#define bitmap_set(ptr, pos) \
	((ptr)[(pos) >> 5] |= (1 << ((pos) & 0x1f)))
#define bitmap_clear(ptr, pos) \
	((ptr)[(pos) >> 5] &= ~(1 << ((pos) & 0x1f)))
#define bitmap_test(ptr, pos) \
	(((ptr)[(pos) >> 5] >> ((pos) & 0x1f)) & 0x1)

unsigned int is_not_prime[(MAX + 31) / 32];
unsigned int prime[5762000];

int main(void)
{
	register int i;
	register unsigned int *top = prime;
	register unsigned int *j;
	register int ans = 0;
	unsigned long long seed, lzk, xzk;

	scanf("%llu%llu%llu", &seed, &lzk, &xzk);

	is_not_prime[2] = 0;
	for (i = 2; i < MAX; ++i) {
		if (!bitmap_test(is_not_prime, i))
			*(top++) = i;
		for (j = prime; j != top && i * *j < MAX; ++j) {
			bitmap_set(is_not_prime, i * *j);
			if (i % *j == 0)
				break;
		}
	}

	for (i = 0; i < 100000; ++i) {
		seed = (seed + lzk) % xzk;
		if (!bitmap_test(is_not_prime, seed))
			++ans;
	}

	printf("%d\n", ans);
	return 0;
}
