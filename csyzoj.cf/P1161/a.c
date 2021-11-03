#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

struct {
	struct {
		int edg;
		int vis;
		int fa, son;
		int dis, low, dpt;
	} V[50009];
	struct {
		int dst, nxt;
	} E[100009];
	int Ec;
	int vis_cnt;
	int n;
} G;

struct info {
	int pos, dis, low;
};

struct {
	struct info N[100009];
	int top, siz;
} H;

void h_init(void)
{
	H.top = 1;
	H.siz = 0;
}

int h_better(int u, int v)
{
	return H.N[u].dis > H.N[v].dis || 
		(H.N[u].dis == H.N[v].dis && H.N[u].low < H.N[v].low);
}

void h_swap(int u, int v)
{
	H.N[0] = H.N[u];
	H.N[u] = H.N[v];
	H.N[v] = H.N[0];
}

int h_empty(void)
{
	return H.siz == 0;
}

void h_push(int pos, int dis, int low)
{
	int p = H.top;
	H.N[p].pos = pos;
	H.N[p].dis = dis;
	H.N[p].low = low;
	++H.top;
	++H.siz;
	while (p > 1) {
		int n = p >> 1;
		if (h_better(p, n))
			h_swap(p, n);
		else
			break;
		p = n;
	}
}

struct info h_top(void)
{
	return H.N[1];
}

void h_pop(void)
{
	int p = 1;
	--H.top;
	--H.siz;
	H.N[1] = H.N[H.top];
	while ((p << 1) < H.top) {
		int n = p << 1;
		if (h_better(n + 1, n))
			++n;
		if (h_better(n, p))
			h_swap(n, p);
		else
			break;
		p = n;
	}
}

void g_clear_vis(void)
{
	++G.vis_cnt;
}

int g_vis(int x)
{
	return G.V[x].vis == G.vis_cnt;
}

void g_init(int n)
{
	G.Ec = 1;
	G.n = n;
	h_init();
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.V[u].edg;
	G.V[u].edg = G.Ec++;
}

void g_add2(int u, int v)
{
	g_add(u, v);
	g_add(v, u);
}

void g_scan_info(int cur)
{
	int i;

	G.V[cur].vis = G.vis_cnt;
	G.V[cur].son = cur;
	G.V[cur].dis = 1;
	G.V[cur].low = cur;

	for (i = G.V[cur].edg; i; i = G.E[i].nxt) {
		int d = G.E[i].dst;
		if (!g_vis(d)) {
			G.V[d].dpt = G.V[cur].dpt + 1;
			G.V[d].fa = cur;
			g_scan_info(d);
			if (G.V[d].dis + 1 > G.V[cur].dis ||
				(G.V[d].dis + 1 == G.V[cur].dis &&
				 G.V[d].low < G.V[cur].low)) {
				G.V[cur].son = d;
				G.V[cur].dis = G.V[d].dis + 1;
				G.V[cur].low = G.V[d].low;
			}
		}
	}
}

void g_print(void)
{
	int i, j;
	for (i = 1; i <= G.n; ++i) {
		printf("%d: ", i);
		for (j = G.V[i].edg; j; j = G.E[j].nxt)
			printf("%d ", G.E[j].dst);
		putchar('\n');
	}
}

void g_push_new_to_heap(int u)
{
	int i;
	for (i = G.V[u].edg; i; i = G.E[i].nxt)
		if (!g_vis(G.E[i].dst)) {
			int d = G.E[i].dst;
			h_push(d, G.V[d].dis, G.V[d].low);
		}
}

void g_mark_path(int u, int v)
{
	while (G.V[u].dpt != G.V[v].dpt) {
		if (G.V[u].dpt < G.V[v].dpt)
			swap(&u, &v);
		if (!g_vis(u)) {
			G.V[u].vis = G.vis_cnt;
			g_push_new_to_heap(u);
		}
		u = G.V[u].fa;
	}
	while (u != v) {
		if (!g_vis(v)) {
			G.V[v].vis = G.vis_cnt;
			g_push_new_to_heap(v);
		}
		v = G.V[v].fa;
		if (!g_vis(u)) {
			G.V[u].vis = G.vis_cnt;
			g_push_new_to_heap(u);
		}
		u = G.V[u].fa;
	}
	if (!g_vis(u)) {
		G.V[u].vis = G.vis_cnt;
		g_push_new_to_heap(u);
	}
}

int main(void)
{
	int n, k;
	int i;
	int cnt = 0;

#ifndef ONLINE_JUDGE
	freopen("apple.in", "r", stdin);
#ifndef DEBUG
	freopen("apple.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d%d", &n, &k);
	g_init(n);
	++k;
	for (i = 2; i <= n; ++i) {
		int t;
		scanf("%d", &t);
		++t;
		g_add2(i, t);
	}
	g_clear_vis();
	g_scan_info(k);

	g_clear_vis();

	printf("%d\n", k - 1);
	g_mark_path(k, k);
	cnt = 1;
	while (cnt < n) {
		struct info info;
		int match = 0;
		do {
			info = h_top();
			h_pop();
		} while (g_vis(info.pos));
		match = info.pos;
		cnt += G.V[match].dis;
		while (G.V[match].son != match)
			match = G.V[match].son;
		printf("%d\n", match - 1);
		g_mark_path(k, match);
		k = match;
	}
	return 0;
}
