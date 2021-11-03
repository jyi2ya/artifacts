#include <stdio.h>

struct {
	struct {
		int edg, in, out;
		long long U, C;
	} N[1000009];
	struct {
		int dst, nxt;
		long long wei;
	} E[2000009];
	int Ec;
} G;

void g_ini(void)
{
	G.Ec = 1;
}

void g_add(int u, int v, long long w)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].wei = w;
	G.E[G.Ec].nxt = G.N[u].edg;
	++G.N[v].in;
	++G.N[u].out;
	G.N[u].edg = G.Ec++;
}

struct {
	int v[1000009];
	int in[1000009];
	int top, bot;
} Q;

void q_ini(void)
{
	Q.top = Q.bot = 0;
}

void q_psh(int x)
{
	Q.in[x] = 1;
	Q.v[Q.top++] = x;
	if (Q.top == 1000009)
		Q.top = 0;
}

int q_pop(void)
{
	int r = Q.v[Q.bot++];
	Q.in[r] = 0;
	if (Q.bot == 1000009)
		Q.bot = 0;
	return r;
}

int q_ept(void)
{
	return Q.top == Q.bot;
}

int t_vis[1000009];
int t_arr[1000009];
int t_top;
void tpsort(int cur)
{
	int i;
	if (t_vis[cur])
		return ;
	t_vis[cur] = 1;
	for (i = G.N[cur].edg; i; i = G.E[i].nxt)
		tpsort(G.E[i].dst);
	t_arr[--t_top] = cur;
}

int main(void)
{
	int n, m;
	int i;
	int isnul = 1;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%lld%lld", &G.N[i].C, &G.N[i].U);
	g_ini();
	for (i = 0; i < m; ++i) {
		int u, v;
		long long w;
		scanf("%d%d%lld", &u, &v, &w);
		g_add(u, v, w);
	}

	t_top = n;
	for (i = 1; i <= n; ++i)
		if (G.N[i].in == 0) {
			G.N[i].C += G.N[i].U;
			tpsort(i);
		}
	for (i = 0; i < n; ++i) {
		int j;
		int cur = t_arr[i];
		G.N[cur].C -= G.N[cur].U;
		if (G.N[cur].C > 0)
			for (j = G.N[cur].edg; j; j = G.E[j].nxt)
				G.N[G.E[j].dst].C += G.E[j].wei * G.N[cur].C;
	}
	for (i = 1; i <= n; ++i)
		if (G.N[i].C > 0 && G.N[i].out == 0) {
			isnul = 0;
			printf("%d %lld\n", i, G.N[i].C);
		}
	if (isnul)
		puts("NULL");
	return 0;
}
