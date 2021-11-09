#include <stdio.h>

typedef struct sgtree {
	long long sum;
	long long delta;
} sgtree;

void add(int l, int r, long long delta);
long long query(int l, int r);

sgtree tree[400009];
int N, M;

int main(void)
{
	int i;

	scanf("%d%d", &N, &M);
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
			printf("%lld\n", query(l, r));
		}
	}
	return 0;
}

void pushdown(int current, int l, int r)
{
	int mid = l + (r - l) / 2;
	tree[current * 2].delta += tree[current].delta;
	tree[current * 2 + 1].delta += tree[current].delta;
	tree[current * 2].sum += tree[current].delta * (mid - l + 1);
	tree[current * 2 + 1].sum += tree[current].delta * (r - mid);
	tree[current].delta = 0;
}

void maintain(int current, int l, int r)
{
	tree[current].sum = tree[current * 2].sum + tree[current * 2 + 1].sum;
}

int query_l, query_r;
long long query_recursive(int current, int l, int r)
{
	long long ans = 0;
	if (query_l <= l && r <= query_r) {
		ans += tree[current].sum;
	} else {
		int mid = l + (r - l) / 2;
		pushdown(current, l, r);
		if (query_l <= mid)
			ans += query_recursive(current * 2, l, mid);
		if (mid < query_r)
			ans += query_recursive(current * 2 + 1, mid + 1, r);
	}
	return ans;
}
long long query(int l, int r)
{
	query_l = l;
	query_r = r;
	return query_recursive(1, 1, N);
}

int add_l, add_r;
long long add_delta;
void add_recursive(int current, int l, int r)
{
	if (add_l <= l && r <= add_r) {
		tree[current].delta += add_delta;
		tree[current].sum += add_delta * (r - l + 1);
	} else {
		int mid = l + (r - l) / 2;
		pushdown(current, l, r);
		if (add_l <= mid)
			add_recursive(current * 2, l, mid);
		if (mid < add_r)
			add_recursive(current * 2 + 1, mid + 1, r);
		maintain(current, l, r);
	}
}

void add(int l, int r, long long delta)
{
	add_l = l;
	add_r = r;
	add_delta = delta;
	add_recursive(1, 1, N);
}
