#include <stdio.h>
#include <stdlib.h>

int U[1000009];

int u_fnd(int x)
{
	return U[x] == x ? x : (U[x] = u_fnd(U[x]));
}

struct E {
	int u, v;
};

int cmp(const void *a, const void *b)
{
	return ((struct E *)a)->u - ((struct E *)b)->u;
}

int main(void)
{
	int n, m, k;
	int i, j;
	static int head[1000009];
	static int val[1000009];
	static int die[1000009];
	static int ans[1000009];
	static struct E E[2000009];
	int Etop = 0;
	int siz = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[Etop].u = u;
		E[Etop++].v = v;
		E[Etop].u = v;
		E[Etop++].v = u;
	}
	qsort(E, Etop, sizeof(*E), cmp);
	for (i = 0; i < n; ++i)
		head[i] = Etop;
	for (i = 0; i < Etop; ++i)
		if (head[E[i].u] > i)
			head[E[i].u] = i;

	scanf("%d", &k);
	for (i = 0; i < k; ++i) {
		scanf("%d", &val[i]);
		die[val[i]] = 1;
	}

	siz = 0;
	for (i = 0; i < n; ++i)
		if (!die[i]) {
			U[i] = i;
			++siz;
		}

	for (i = 0; i < Etop; ++i)
		if (!die[E[i].u] && !die[E[i].v])
			if (u_fnd(E[i].u) != u_fnd(E[i].v)) {
				--siz;
				U[u_fnd(E[i].u)] = u_fnd(E[i].v);
			}

	for (i = k - 1; i >= 0; --i) {
		ans[i] = siz;
		die[val[i]] = 0;
		U[val[i]] = val[i];
		++siz;
		for (j = head[val[i]]; E[j].u == val[i]; ++j)
			if (!die[E[j].v])
				if (u_fnd(E[j].u) != u_fnd(E[j].v)) {
					U[u_fnd(E[j].u)] = u_fnd(E[j].v);
					--siz;
				}
	}

	printf("%d\n", siz);
	for (i = 0; i < k; ++i)
		printf("%d\n", ans[i]);

	return 0;
}
