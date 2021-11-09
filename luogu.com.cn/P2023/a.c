#include <stdio.h>

void init(void);
void add(int l, int r, int c, int ml, int mr, long long v);
void mul(int l, int r, int c, int ml, int mr, long long v);
long long query(int l, int r, int c, int ml, int mr);

long long N, M, P;

int main(void)
{
	int i, op;
	long long x, y, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	init();
	scanf("%lld%lld", &N, &P);
	for (i = 1; i <= N; ++i) {
		scanf("%lld", &x);
		add(1, N, 1, i, i, x);
	}
	scanf("%lld", &M);
	while (M--) {
		scanf("%d%lld%lld", &op, &x, &y);
		if (op == 1) {
			scanf("%lld", &k);
			mul(1, N, 1, x, y, k);
		} else if (op == 2) {
			scanf("%lld", &k);
			add(1, N, 1, x, y, k);
		} else {
			printf("%lld\n", query(1, N, 1, x, y) % P);
		}
	}
	return 0;
}

long long tr[400009], addv[400009], mulv[400009];

void init(void)
{
	int i;
	for (i = 0; i < 400009; ++i)
		mulv[i] = 1;
}

void pushdown(int c, int l, int r)
{
	int mid = l + (r - l) / 2;

	mulv[c << 1] = mulv[c << 1] * mulv[c] % P;
	addv[c << 1] = addv[c << 1] * mulv[c] % P;
	tr[c << 1] = tr[c << 1] * mulv[c] % P;

	mulv[c << 1 | 1] = mulv[c << 1 | 1] * mulv[c] % P;
	addv[c << 1 | 1] = addv[c << 1 | 1] * mulv[c] % P;
	tr[c << 1 | 1] = tr[c << 1 | 1] * mulv[c] % P;

	mulv[c] = 1;

	addv[c << 1] = (addv[c << 1] + addv[c]) % P;
	tr[c << 1] = (tr[c << 1] + addv[c] * (mid - l + 1) % P) % P;

	addv[c << 1 | 1] = (addv[c << 1 | 1] + addv[c]) % P;
	tr[c << 1 | 1] = (tr[c << 1 | 1] + addv[c] * (r - mid) % P) % P;

	addv[c] = 0;
}

void add(int l, int r, int c, int ml, int mr, long long v)
{
	if (ml <= l && r <= mr) {
		addv[c] = (addv[c] + v) % P;
		tr[c] = (tr[c] + v * (r - l + 1) % P) % P;
	} else {
		int mid = l + (r - l) / 2;
		pushdown(c, l, r);
		if (ml <= mid)
			add(l, mid, c << 1, ml, mr, v);
		if (mid + 1 <= mr)
			add(mid + 1, r, c << 1 | 1, ml, mr, v);
		tr[c] = (tr[c << 1] + tr[c << 1 | 1]) % P;
	}
}

void mul(int l, int r, int c, int ml, int mr, long long v)
{
	if (l != r)
		pushdown(c, l, r);
	if (ml <= l && r <= mr) {
		mulv[c] = mulv[c] * v % P;
		tr[c] = tr[c] * v % P;
	} else {
		int mid = l + (r - l) / 2;
		if (ml <= mid)
			mul(l, mid, c << 1, ml, mr, v);
		if (mid + 1 <= mr)
			mul(mid + 1, r, c << 1 | 1, ml, mr, v);
		tr[c] = (tr[c << 1] + tr[c << 1 | 1]) % P;
	}
}

long long query(int l, int r, int c, int ml, int mr)
{
	long long ans = 0;
	if (ml <= l && r <= mr) {
		ans = tr[c] % P;
	} else {
		int mid = l + (r - l) / 2;
		pushdown(c, l, r);
		if (ml <= mid)
			ans = (ans + query(l, mid, c << 1, ml, mr)) % P;
		if (mid + 1 <= mr)
			ans = (ans + query(mid + 1, r, c << 1 | 1, ml, mr)) % P;
	}
	return ans % P;
}
