#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007LL

int max(int a, int b)
{
	return a > b ? a : b;
}

long long llpow(long long a, long long x)
{
	long long r = 1;
	while (x) {
		if (x & 1)
			r = r * a % MOD;
		a = a * a % MOD;
		x /= 2;
	}
	return r;
}

struct {
	struct {
		int edg, max, fa;
	} N[1000009];
	struct {
		int dst, nxt;
	} E[2000009];
	int Ec;
	int n;
} G;

void g_ini(int x)
{
	G.n = x;
	G.Ec = 1;
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

int F[1000009];

void f_inc(int p)
{
	if (p)
		for (; p < 1000009; p += p & -p)
			++F[p];
}

void f_dec(int p)
{
	if (p)
		for (; p < 1000009; p += p & -p)
			--F[p];
}

int f_qry(int p)
{
	int ans = 0;
	for (; p > 0; p -= p & -p)
		ans += F[p];
	return ans;
}

long long ans = 1;

void g_dfs(int rt)
{
	int i;
	if (G.N[rt].fa) {
		f_dec(G.N[G.N[rt].fa].max);
		ans = ans * llpow(2, f_qry(rt)) % MOD;
		f_inc(G.N[G.N[rt].fa].max);
	}
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa) {
			G.N[G.E[i].dst].fa = rt;
			f_dec(G.N[rt].max);
			G.N[rt].max = max(G.N[rt].max, G.E[i].dst);
			f_inc(G.N[rt].max);
			g_dfs(G.E[i].dst);
		}
	f_dec(G.N[rt].max);
}

struct E {
	int u, v;
};

int cmp(const void *a, const void *b)
{
	struct E *p = (struct E *)a;
	struct E *q = (struct E *)b;
	return p->u == q->u ? q->v - p->v : p->u - q->u;
}

int main(void)
{
	int i;
	static struct E E[2000009];
	int Ec = 0;
	int n;

#ifndef ONLINE_JUDGE
	freopen("dfs.in", "r", stdin);
#ifndef DEBUG
	freopen("dfs.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d", &n);
	g_ini(n);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[Ec].u = u;
		E[Ec++].v = v;
		E[Ec].u = v;
		E[Ec++].v = u;
	}
	qsort(E, Ec, sizeof(*E), cmp);

	for (i = 0; i < Ec; ++i)
		g_add(E[i].u, E[i].v);

	g_dfs(1);

	printf("%lld\n", ans);
	return 0;
}
