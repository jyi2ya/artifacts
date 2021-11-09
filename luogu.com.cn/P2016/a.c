#include <stdio.h>
#include <limits.h>

struct edge {
	int dest;
	struct edge *next;
};

struct {
	struct edge *g[1509];
	int fa[1509];
	int mem[1509][2];
	int vis[1509][2];
} S;

void add_edge(int u, int v)
{
	static struct edge pool[6000], *top = pool;
	top->dest = v;
	top->next = S.g[u];
	S.g[u] = top++;
}

void specify_father(int u)
{
	struct edge *i;
	for (i = S.g[u]; i; i = i->next)
		if (i->dest != S.fa[u]) {
			S.fa[i->dest] = u;
			specify_father(i->dest);
		}
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int fill_tree(int root, int is_root_placed)
{
	struct edge *i;
	int ans = 0;

	if (S.vis[root][is_root_placed])
		return S.mem[root][is_root_placed];

	if (is_root_placed) {
		for (i = S.g[root]; i; i = i->next)
			if (i->dest != S.fa[root])
				ans += min(
						fill_tree(i->dest, 0),
						fill_tree(i->dest, 1)
					  );
		++ans;
	} else {
		for (i = S.g[root]; i; i = i->next)
			if (i->dest != S.fa[root])
				ans += fill_tree(i->dest, 1);
	}

	S.vis[root][is_root_placed] = 1;
	return S.mem[root][is_root_placed] = ans;
}

int main_(void)
{
	int n;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		int p, q;
		scanf("%d%d", &p, &q);
		while (q--) {
			int t;
			scanf("%d", &t);
			add_edge(p, t);
			add_edge(t, p);
		}
	}

	S.fa[0] = -1;
	specify_father(0);

	printf("%d\n", min(fill_tree(0, 0), fill_tree(0, 1)));

	return 0;
}

int start_(void)
{
	return main_();
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	start_();

#ifdef DEBUG
	fclose(stdin);
#endif
	
	return 0;
}
