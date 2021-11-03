#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

struct E {
	ll u, v, w;
} E[500009];

int cmp(const void *a, const void *b)
{
	return ((struct E *)a)->w > ((struct E *)b)->w ? -1 : 1;
}

ll U[10009];

void u_ini(void)
{
	ll i;
	for (i = 1; i < 10009; ++i)
		U[i] = i;
}

ll u_fnd(ll x)
{
	return U[x] == x ? x : (U[x] = u_fnd(U[x]));
}

void u_mgr(ll a, ll b)
{
	U[u_fnd(a)] = u_fnd(b);
}

ll u_qry(ll u, ll v)
{
	return u_fnd(u) == u_fnd(v);
}

struct {
	struct {
		ll edg, dpt;
		struct {
			ll val, dst;
		} jmp[14];
	} N[10009];
	struct {
		ll dst, nxt, val;
	} E[20009];
	ll Ec;
} T;

void t_ini(void)
{
	T.Ec = 1;
}

void t_add(ll u, ll v, ll w)
{
	T.E[T.Ec].dst = v;
	T.E[T.Ec].val = w;
	T.E[T.Ec].nxt = T.N[u].edg;
	T.N[u].edg = T.Ec++;
}

void t_add2(ll u, ll v, ll w)
{
	t_add(u, v, w);
	t_add(v, u, w);
}

void t_info(ll rt)
{
	ll i;
	for (i = 1; i < 14; ++i) {
		T.N[rt].jmp[i].dst = T.N[T.N[rt].jmp[i - 1].dst].jmp[i - 1].dst;
		T.N[rt].jmp[i].val = min(T.N[rt].jmp[i - 1].val,
				T.N[T.N[rt].jmp[i - 1].dst].jmp[i - 1].val);
	}
	for (i = T.N[rt].edg; i; i = T.E[i].nxt)
		if (T.E[i].dst != T.N[rt].jmp[0].dst) {
			T.N[T.E[i].dst].dpt = T.N[rt].dpt + 1;
			T.N[T.E[i].dst].jmp[0].dst = rt;
			T.N[T.E[i].dst].jmp[0].val = T.E[i].val;
			t_info(T.E[i].dst);
		}
}

ll t_qry(ll u, ll v)
{
	ll ans = 0x3f3f3f3f3f3f3f3f;
	ll i;
	if (T.N[u].dpt < T.N[v].dpt) {
		ll t = u;
		u = v;
		v = t;
	}
	for (i = 13; i >= 0; --i)
		if (T.N[T.N[u].jmp[i].dst].dpt >= T.N[v].dpt) {
			ans = min(ans, T.N[u].jmp[i].val);
			u = T.N[u].jmp[i].dst;
		}
	for (i = 13; i >= 0; --i)
		if (T.N[u].jmp[i].dst != T.N[v].jmp[i].dst) {
			ans = min(ans, T.N[u].jmp[i].val);
			ans = min(ans, T.N[v].jmp[i].val);
			u = T.N[u].jmp[i].dst;
			v = T.N[v].jmp[i].dst;
		}
	if (u != v) {
		ans = min(ans, T.N[u].jmp[0].val);
		ans = min(ans, T.N[v].jmp[0].val);
	}
	return ans;
}

int main(void)
{
	ll n, m, q;
	ll i;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%lld%lld", &n, &m);
	for (i = 0; i < m; ++i)
		scanf("%lld%lld%lld", &E[i].u, &E[i].v, &E[i].w);
	qsort(E, m, sizeof(*E), cmp);
	u_ini();
	t_ini();
	for (i = 0; i < m; ++i)
		if (!u_qry(E[i].u, E[i].v)) {
			t_add2(E[i].u, E[i].v, E[i].w);
			u_mgr(E[i].u, E[i].v);
		}

	for (i = 1; i <= n; ++i)
		if (!T.N[i].dpt) {
			T.N[i].jmp[0].dst = 1;
			T.N[i].jmp[0].val = 0x3f3f3f3f3f3f3f3f;
			t_info(i);
		}

	scanf("%lld", &q);
	while (q--) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		if (!u_qry(u, v)) {
			puts("-1");
			continue;
		}
		printf("%lld\n", t_qry(u, v));
	}

	return 0;
}
