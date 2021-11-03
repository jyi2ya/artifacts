#include <stdio.h>
#include <stdlib.h>

int U[1009];

void u_ini(void)
{
	int i;
	for (i = 1; i < 1009; ++i)
		U[i] = i;
}

int u_fnd(int x)
{
	return U[x] == x ? x : (U[x] = u_fnd(U[x]));
}

int u_qry(int u, int v)
{
	return u_fnd(u) == u_fnd(v);
}

void u_mgr(int u, int v)
{
	U[u_fnd(u)] = u_fnd(v);
}

struct E {
	int u, v, w;
} E[1000009];
int top, ans;

int cmp(const void *a, const void *b)
{
	return ((struct E *)a)->w - ((struct E *)b)->w;
}

int main(void)
{
	int i;
	int n, m;
	int cnt = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[top].u = u;
		E[top].v = v;
		E[top].w = w;
		++top;
	}
	qsort(E, top, sizeof(*E), cmp);
	u_ini();
	for (i = 0; i < top; ++i)
		if (!u_qry(E[i].u, E[i].v)) {
			++cnt;
			if (E[i].w > ans)
				ans = E[i].w;
			u_mgr(E[i].u, E[i].v);
		}
	printf("%d %d\n", cnt, ans);
	return 0;
}
