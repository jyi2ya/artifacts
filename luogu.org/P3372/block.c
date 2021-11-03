#include <stdio.h>
#include <math.h>

#define MAX 100009

typedef struct block {
	long long addv, sum;
} block;

int n, block_size;
int N, M;

block b[1000];
long long a[MAX];

void init(int size);
void add(int l, int r, long long addv);
long long sum(int l, int r);

int main(void)
{
	int i;
	scanf("%d%d", &N, &M);
	init(N);
	for (i = 1; i <= N; ++i) {
		long long x;
		scanf("%lld", &x);
		add(i, i, x);
	}
	while (M--) {
		int op, l, r;
		long long delta;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			scanf("%lld", &delta);
			add(l, r, delta);
		} else {
			printf("%lld\n", sum(l, r));
		}
	}
	return 0;
}

long long sum(int l, int r)
{
	long long ans = 0;

	for (; l <= r && l % block_size; ++l)
		ans += a[l] + b[l / block_size].addv;

	for (; l + block_size <= r; l += block_size)
		ans += b[l / block_size].sum;

	for (; r >= l; --r)
		ans += a[r] + b[r / block_size].addv;

	return ans;
}

void add(int l, int r, long long addv)
{
	for (; l <= r && l % block_size; ++l) {
		b[l / block_size].sum += addv;
		a[l] += addv;
	}
	for (; l + block_size <= r; l += block_size) {
		b[l / block_size].sum += block_size * addv;
		b[l / block_size].addv += addv;
	}
	for (; l <= r; ++l) {
		b[l / block_size].sum += addv;
		a[l] += addv;
	}
}

void init(int size)
{
	block_size = sqrt(size);
}
