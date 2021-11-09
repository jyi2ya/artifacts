#include <stdio.h>

#define bs_set(bs, pos) (bs[pos >> 6] |= (1ULL << (pos & 077)))
#define bs_clr(bs, pos) (bs[pos >> 6] &= ~(1ULL << (pos & 077)))
#define bs_tst(bs, pos) ((bs[pos >> 6] >> (pos & 077)) & 1)
#define bs_xor(dst, sr1, sr2, len) do { \
		unsigned long long ii; \
		for (ii = 0; (ii << 6) < (unsigned long long)(len); ++ii) \
			dst[ii] = sr1[ii] ^ sr2[ii]; \
	} while (0)

int main(void)
{
	register int i, j;
	static unsigned long long bs_b[2009][2009];
	static unsigned long long *bs[2009];
	register unsigned long long *t;
	register int first = -1;
	int n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i)
		bs[i] = bs_b[i];
	for (i = 0; i < m; ++i)  {
		while (getchar() != '\n');
		for (j = 0; j < n; ++j) {
			if (getchar() - '0')
				bs_set(bs[i], j);
			else
				bs_clr(bs[i], j);
		}
		getchar();
		if (getchar() - '0')
			bs_set(bs[i], n);
		else
			bs_clr(bs[i], n);
	}
	for (i = 0; i < n; ++i) {
		for (j = i; j < m; ++j)
			if (bs_tst(bs[j], i))
				break;
		if (j == m) {
			puts("Cannot Determine");
			return 0;
		}
		if (j > first)
			first = j;
		t = bs[i];
		bs[i] = bs[j];
		bs[j] = t;
		for (j = 0; j < m; ++j) {
			if (j == i || bs_tst(bs[j], i) == 0)
				continue;
			bs_xor(bs[j], bs[j], bs[i], n + 1);
		}
	}
	printf("%d\n", first + 1);
	for (i = 0; i < n; ++i)
		puts(bs_tst(bs[i], n) ? "?y7M#" : "Earth");
	return 0;
}
