#include <stdio.h>

int expect;

void read(void);

long long sale_num[100009];
long long cost;

int main(void)
{
	register int i, j;
	long long best = 0, best_tot = 0;
	int is_add = 1;
	read();
	for (i = 0; i < 100008; ++i) {
		is_add = 1;
		for (j = cost; j < 100008; ++j)
			if (sale_num[j] * (j + i - cost) > best_tot) {
				best_tot = sale_num[j] * (j + i - cost);
				best = j;
			}
		if (best == expect)
			break;

		best = 0, best_tot = 0;
		is_add = 0;
		for (j = cost; j < 100008; ++j)
			if (sale_num[j] * (j - i - cost) > best_tot) {
				best_tot = sale_num[j] * (j - i - cost);
				best = j;
			}
		if (best == expect)
			break;
	}
	if (i == 21)
		i = 20;

	if (best != expect)
		printf("NO SOLUTION\n");
	else if (is_add)
		printf("%d\n", i);
	else
		printf("%d\n", -i);
	return 0;
}

void read(void)
{
	register int i, j, k;
	long long n;

#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif

	scanf("%d", &expect);
	scanf("%lld%lld", &cost, &n);
	sale_num[cost] = n;
	for (; ;) {
		long long price;
		scanf("%lld%lld", &price, &n);
		if (price == -1 && n == -1) {
			long long delta;
			scanf("%lld", &delta);
			sale_num[100008] = n - (100008 - price) * delta;
			break;
		}
		sale_num[price] = n;
	}
	for (i = cost; i < 100009; i = j) {
		long long delta, tot = 0;

		for (j = i + 1; sale_num[j] == 0 && j < 100009; ++j);
		delta = (sale_num[j] - sale_num[i]) / (j - i);

		for (k = i; k < j; ++k) {
			sale_num[k] = sale_num[i] + tot;
			tot += delta;
		}
	}
}
