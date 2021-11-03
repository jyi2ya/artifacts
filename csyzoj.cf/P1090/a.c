#include <stdio.h>

#define MOD 998244353

long long llinv(long long a)
{
	long long r = 1;
	long long x = MOD - 2;
	while (x) {
		if (x & 1)
			r = r * a % MOD;
		a = a * a % MOD;
		x /= 2;
	}
	return r;
}

int fa[100009];

struct {
	struct {
		int dpt, fa, edg;
	} N[100009];
	struct {
		int dst, nxt;
	} E[200009];
	int Ec;
} G;

void g_ini(void)
{
	G.Ec = 1;
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_add2(int u, int v)
{
	g_add(u, v);
	g_add(v, u);
}

int cnt[100009];
void g_dfs(int rt)
{
	int i;
	++cnt[G.N[rt].dpt];
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa) {
			G.N[G.E[i].dst].fa = rt;
			G.N[G.E[i].dst].dpt = G.N[rt].dpt + 1;
			g_dfs(G.E[i].dst);
		}
}

int ufs[100009];

int u_fnd(int x)
{
	return ufs[x] == x ? x : (ufs[x] = u_fnd(ufs[x]));
}

int u_qry(int u, int v)
{
	return u_fnd(u) == u_fnd(v);
}

void u_mgr(int u, int v)
{
	ufs[u_fnd(u)] = u_fnd(v);
}

int main(void)
{
	int i;
	int n;
	long long magic = 1;
	long long prob = 1;
	long long ans = 0;

#ifndef ONLINE_JUDGE
	freopen("treasure.in", "r", stdin);
#ifndef DEBUG
	freopen("treasure.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif


	scanf("%d", &n);

	for (i = 0; i <= n; ++i)
		ufs[i] = i;

	for (i = 1; i <= n; ++i) {
		scanf("%d", &fa[i]);
		if (fa[i] == -1)
			fa[i] = 0;
		u_mgr(fa[i], i);
	}

	g_ini();
	for (i = 1; i <= n; ++i)
		if (u_qry(i, 0))
			g_add2(i, fa[i]);

	g_dfs(0);
	
	for (i = 1; i <= n && cnt[i]; ++i) {
		magic = magic * (n - i + 1) % MOD * llinv(i) % MOD;
		ans = (ans + magic * llinv(prob) % MOD * cnt[i] % MOD) % MOD;
		prob = prob * (n - i) % MOD;
	}

	printf("%lld\n", ans * llinv(n) % MOD);

	return 0;
}
