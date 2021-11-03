#include <stdio.h>
#include <stdlib.h>

int N, L, S;
char buf[30009][209];
struct hsh {
	unsigned long long p;
	unsigned long long s;
};
struct hsh hsh[30009][209];
struct hsh tmp[30009];

int cmp(const void *a, const void *b)
{
	struct hsh *p1 = (struct hsh*)a;
	struct hsh *p2 = (struct hsh*)b;
	if (p1->p == p2->p)
		return (p1->s < p2->s) ? (-1) : (1);
	return (p1->p < p2->p) ? (-1) : (1);
}

int main(void)
{
	int i, j, k;
	long long ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d", &N, &L, &S);

	for (i = 0; i < N; ++i)
		scanf("%s", buf[i] + 1);

	for (i = 0; i < N; ++i) {
		for (j = 1; j <= L; ++j)
			hsh[i][j].p = hsh[i][j - 1].p * 131 + buf[i][j];
		for (j = L; j >= 1; --j)
			hsh[i][j].s = hsh[i][j + 1].s * 131 + buf[i][j];
	}

	for (k = 1; k <= L; ++k) {
		for (i = 0; i < N; ++i) {
			tmp[i].p = hsh[i][k - 1].p;
			tmp[i].s = hsh[i][k + 1].s;
		}
		qsort(tmp, N, sizeof(tmp[0]), cmp);
		j = 0;
		for (i = 0; i < N; i = j) {
			while (
					j < N && 
					tmp[i].p == tmp[j].p &&
					tmp[i].s == tmp[j].s
			      )
				++j;
			ans += (long long)(j - i) * (long long)(j - i - 1) / 2LL;
		}

	}

	printf("%lld\n", ans);
	return 0;
}
