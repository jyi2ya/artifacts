#include <stdio.h>

struct edge {
	int t;
	struct edge *n;
};
struct edge Epool[20009], *Etop = Epool;
struct edge *G[10009];

void add_edge(int f, int t)
{
	Etop->t = t;
	Etop->n = G[f];
	G[f] = Etop++;
}

int ans = 0;

int dfs(int pos, int fa)
{
	int len1 = 0, len2 = 0, len;
	struct edge *i;
	for (i = G[pos]; i; i = i->n)
		if (i->t != fa) {
			len = dfs(i->t, pos);
			if (len > len1) {
				len2 = len1;
				len1 = len;
			} else if (len > len2) {
				len2 = len;
			}
		}

	if (len2 + len1 + 1 > ans)
		ans = len2 + len1 + 1;

	return len1 + 1;
}

int main(void)
{
	int n;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}

	dfs(1, 0);

	printf("%d\n", ans - 1);
	return 0;
}
