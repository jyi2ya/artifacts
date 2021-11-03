#include <stdio.h>

typedef struct item_t {
	int v, p, n;
	int av[3], ap[3];
} item_t;
#define MAXM (60)

item_t A[69];

int max(int a, int b);
int dfs(int p, int v);
int M;
int V[69][32009], mem[69][32009];

int main(void)
{
	int i, N, v, p, q;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; ++i) {
		scanf("%d%d%d", &v, &p, &q);
		if (q) {
			A[q].av[A[q].n] = v;
			A[q].ap[A[q].n] = p;
			++A[q].n;
		} else {
			A[i].v = v;
			A[i].p = p;
		}
	}

	printf("%d\n", dfs(1, N));
	return 0;
}

int dfs(int p, int v)
{
	int la = 0;
	if (p > M)
		return 0;

	if (V[p][v])
		return mem[p][v];

	la = max(la, dfs(p + 1, v));
	if (v >= A[p].v)
		la = max(la, dfs(p + 1, v - A[p].v) + A[p].v * A[p].p);
	if (A[p].n >= 1 && v >= A[p].v + A[p].av[0])
		la = max(la, dfs(p + 1, v - A[p].v - A[p].av[0]) +
				A[p].v * A[p].p + A[p].av[0] * A[p].ap[0]);
	if (A[p].n >= 2 && v >= A[p].v + A[p].av[1])
		la = max(la, dfs(p + 1, v - A[p].v - A[p].av[1]) +
				A[p].v * A[p].p + A[p].av[1] * A[p].ap[1]);
	if (A[p].n >= 2 && v >= A[p].v + A[p].av[1] + A[p].av[0])
		la = max(la, dfs(p + 1, v - A[p].v - A[p].av[1] - A[p].av[0]) +
				A[p].v * A[p].p + A[p].av[1] * A[p].ap[1] + A[p].av[0] * A[p].ap[0]);

	V[p][v] = 1, mem[p][v] = la;
	return la;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
