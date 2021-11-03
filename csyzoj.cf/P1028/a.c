#include <stdio.h>
#ifndef DEBUG
#define Z(x)
#define NDEBUG
#else
#define Z(x) printf x
#endif
#include <assert.h>

#define MOD (998244353LL)

struct {
	struct {
		long long add, mul, sum;
		int l, r;
	} N[10000009];
	int n;
	int Nc;
	int ans;
	int vis[200009];
} S;

int s_alc(void)
{
	S.N[S.Nc].add = 0;
	S.N[S.Nc].mul = 1;
	S.N[S.Nc].sum = 0;
	S.N[S.Nc].l = 0;
	S.N[S.Nc].r = 0;
	return S.Nc++;
}

void s_ini(int n)
{
	int i;
	S.Nc = 0;
	s_alc();
	S.n = n;
	S.ans = s_alc();
	for (i = 1; i <= n; ++i)
		S.vis[i] = s_alc();
}

void s_pd(int rt, int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		if (S.N[rt].l == 0)
			S.N[rt].l = s_alc();
		if (S.N[rt].r == 0)
			S.N[rt].r = s_alc();

		S.N[S.N[rt].l].mul = S.N[S.N[rt].l].mul * S.N[rt].mul % MOD;
		S.N[S.N[rt].l].add = S.N[S.N[rt].l].add * S.N[rt].mul % MOD;
		S.N[S.N[rt].l].sum = S.N[S.N[rt].l].sum * S.N[rt].mul % MOD;
		S.N[S.N[rt].r].mul = S.N[S.N[rt].r].mul * S.N[rt].mul % MOD;
		S.N[S.N[rt].r].add = S.N[S.N[rt].r].add * S.N[rt].mul % MOD;
		S.N[S.N[rt].r].sum = S.N[S.N[rt].r].sum * S.N[rt].mul % MOD;
		S.N[rt].mul = 1;

		S.N[S.N[rt].l].add = (S.N[S.N[rt].l].add + S.N[rt].add) % MOD;
		S.N[S.N[rt].l].sum = (S.N[S.N[rt].l].sum +
				S.N[rt].add * (m - l + 1) % MOD) % MOD;

		S.N[S.N[rt].r].add = (S.N[S.N[rt].r].add + S.N[rt].add) % MOD;
		S.N[S.N[rt].r].sum = (S.N[S.N[rt].r].sum +
				S.N[rt].add * (r - m) % MOD) % MOD;
		S.N[rt].add = 0;
	}
}

void s_mt(int rt, int l, int r)
{
	if (l < r)
		S.N[rt].sum = (S.N[S.N[rt].l].sum + S.N[S.N[rt].r].sum) % MOD;
}

void s_add(int rt, int l, int r, int ll, int rr, long long x)
{
	assert(rt != 0);
	s_pd(rt, l, r);
	Z(("%s: %d %d %d %d %d %lld\n", __func__, rt, l, r, ll, rr, x));
	if (ll <= l && r <= rr) {
		S.N[rt].sum = (S.N[rt].sum + x * (r - l + 1) % MOD) % MOD;
		S.N[rt].add = (S.N[rt].add + x) % MOD;
	} else {
		int m = l + (r - l) / 2;
		if (ll <= m)
			s_add(S.N[rt].l, l, m, ll, rr, x);
		if (m < rr)
			s_add(S.N[rt].r, m + 1, r, ll, rr, x);
		s_mt(rt, l, r);
	}
}

void s_mul(int rt, int l, int r, int ll, int rr, long long x)
{
	assert(rt != 0);
	s_pd(rt, l, r);
	Z(("%s: %d %d %d %d %d %lld\n", __func__, rt, l, r, ll, rr, x));
	if (ll <= l && r <= rr) {
		Z(("hit\n"));
		S.N[rt].sum = S.N[rt].sum * x % MOD;
		S.N[rt].mul = S.N[rt].mul * x % MOD;
	} else {
		int m = l + (r - l) / 2;
		if (ll <= m)
			s_mul(S.N[rt].l, l, m, ll, rr, x);
		if (m < rr)
			s_mul(S.N[rt].r, m + 1, r, ll, rr, x);
		s_mt(rt, l, r);
	}
}

long long s_qry(int rt, int l, int r, int ll, int rr)
{
	long long ans = 0;
	int m;
	assert(rt != 0);
	Z(("%s: %d %d %d %d %d\n", __func__, rt, l, r, ll, rr));
	if (ll <= l && r <= rr) {
		Z(("hit: %lld\n", S.N[rt].sum));
		return S.N[rt].sum;
	}
	s_pd(rt, l, r);
	m = l + (r - l) / 2;
	s_pd(rt, l, r);
	if (ll <= m)
		ans = s_qry(S.N[rt].l, l, m, ll, rr);
	if (m < rr)
		ans = (ans + s_qry(S.N[rt].r, m + 1, r, ll, rr)) % MOD;
	return ans;
}

void s_gao(int rt, int l, int r, int ll, int rr)
{
	int m = l + (r - l) / 2;
	Z(("%s: %d %d %d %d %d\n", __func__, rt, l, r, ll, rr));
	assert(rt != 0);
	s_pd(rt, l, r);
	if (ll <= l && r <= rr) {
		Z(("hit: %d %d\n", l, r));
		if (S.N[rt].sum == r - l + 1) {
			Z(("all added\n"));
			s_mul(S.ans, 1, S.n, l, r, 2);
		} else if (S.N[rt].sum == 0) {
			Z(("no added\n"));
			s_add(S.ans, 1, S.n, l, r, 1);
			S.N[rt].sum = (S.N[rt].sum + (r - l + 1) % MOD) % MOD;
			S.N[rt].add = (S.N[rt].add + 1) % MOD;
		} else {
			Z(("process recursive\n"));
			s_gao(S.N[rt].l, l, m, ll, rr);
			s_gao(S.N[rt].r, m + 1, r, ll, rr);
		}
	} else {
		if (ll <= m)
			s_gao(S.N[rt].l, l, m, ll, rr);
		if (m < rr)
			s_gao(S.N[rt].r, m + 1, r, ll, rr);
		s_mt(rt, l, r);
	}
}

long long l_qry(int l, int r)
{
	Z(("l_qry: %d %d\n", l, r));
	return s_qry(S.ans, 1, S.n, l, r);
}

void l_add(int l, int r, int x)
{
	Z(("l_add: %d %d %d\n", l, r, x));
	s_gao(S.vis[x], 1, S.n, l, r);
}

int main(void)
{
	int n, m;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	s_ini(n);
	while (m--) {
		int opt;
		scanf("%d", &opt);
		if (opt == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l_add(l, r, x);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", l_qry(l, r));
		}
	}
	return 0;
}
