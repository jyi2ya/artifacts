#include <stdio.h>
#include <math.h>

int n, m;
unsigned long long seq[100009];
unsigned long long sum[1009], mx[1009], block_size = 109;

unsigned long long query_max(int l, int r);
unsigned long long query_sum(int l, int r);
void root(int l, int r);
unsigned long long max(unsigned long long a, unsigned long long b);

void print_statu(void);

int main(void)
{
	int i;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%llu", seq + i);
	for (i = 0; i < n; ++i) {
		sum[i / block_size] += seq[i];
		mx[i / block_size] = max(mx[i / block_size], seq[i]);
	}

	scanf("%d", &m);
	while (m--) {
		int op, l, r;
		print_statu();
		scanf("%d%d%d", &op, &l, &r);
		--l, --r;
		if (l > r) {
			int t = l;
			l = r;
			r = t;
		}

		if (op == 0 && (query_max(l, r) > 1))
			root(l, r);
		else if (op == 1)
			printf("%llu\n", query_sum(l, r));
	}
	return 0;
}

unsigned long long query_sum(int l, int r)
{
	unsigned long long ans = 0;
#ifdef DEBUG
	printf("qsum:%d, %d\n", l, r);
#endif
	for (; l <= r && l % block_size; ++l)
		ans += seq[l];
	for (; l + block_size <= r; l += block_size)
		ans += sum[l / block_size];
	for (; r >= l; --r)
		ans += seq[r];
	return ans;
}

unsigned long long query_max(int l, int r)
{
	unsigned long long ans = 0;
	for (; l <= r && l % block_size; ++l)
		ans = max(ans, seq[l]);
	for (; l + block_size <= r; l += block_size)
		ans = max(ans, mx[l / block_size]);
	for (; r >= l; --r)
		ans = max(ans, seq[r]);
	return ans;
}

void root(int l, int r)
{
	int i;
#ifdef DEBUG
	printf("qroot:%d, %d\n", l, r);
#endif
	for (i = l; i <= r; ++i)
		seq[i] = sqrt((double)seq[i]);
	for (i = l; i <= r; ++i) {
		sum[i / block_size] = 0;
		mx[i / block_size] = 0;
	}
	for (; l % block_size && l >= 0; --l);
	for (++r; r < n && r % block_size; ++r);
	for (i = l; i < r; ++i) {
		sum[i / block_size] += seq[i];
		mx[i / block_size] = max(mx[i / block_size], seq[i]);
	}
}

unsigned long long max(unsigned long long a, unsigned long long b)
{
	return a > b ? a : b;
}

void print_statu(void)
{
#ifdef DEBUG
	int i;
	for (i = 0; i < n; ++i)
		printf("%2d ", i);
	putchar('\n');
	for (i = 0; i < n; ++i)
		printf("%2llu ", seq[i]);
	putchar('\n');
	for (i = 0; i < n; ++i)
		printf("%2llu ", sum[i / block_size]);
	putchar('\n');
	for (i = 0; i < n; ++i)
		printf("%2llu ", mx[i / block_size]);
	putchar('\n');
#endif
}
