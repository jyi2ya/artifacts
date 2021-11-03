#include <stdio.h>
#include <string.h>

int C[10009];
typedef struct edge {
	int t, n;
} edge;
edge G[500009];
int Gtop = 10003;
int s[2];

void addedge(int f, int t)
{
	G[Gtop].t = t, G[Gtop].n = G[f].n, G[f].n = Gtop++;
}

int dfs(int p, int c)
{
	int i;
	if (C[p] >= 0)
		return C[p] == c;
	C[p] = c;
	++s[c];
	for (i = G[p].n; i; i = G[i].n)
		if (!dfs(G[i].t, c ^ 1))
			return 0;
	return 1;
}

int main(void)
{
	int i, n, m, u, v, a;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	memset(C, -1, sizeof(C));

	a = 0;
	for (i = 1; i <= n; ++i)
		if (C[i] < 0) {
			s[0] = 0, s[1] = 0;
			if (!dfs(i, 0)) {
				puts("Impossible");
				return 0;
			}
			if (s[0] < s[1])
				a += s[0];
			else
				a += s[1];
		}

	printf("%d\n", a);

	return 0;
}
