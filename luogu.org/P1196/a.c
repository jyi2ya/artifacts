#include <stdio.h>
#include <stdlib.h>

struct {
	struct {
		int fa, dist;
	} N[30009];
	int siz[30009];
	int n;
} U;

void u_ini(int n)
{
	int i;
	U.n = n;
	for (i = 1; i <= n; ++i) {
		U.N[i].fa = i;
		U.N[i].dist = 0;
	}
	for (i = 1; i <= n; ++i)
		U.siz[i] = 1;
}

int u_fnd(int x)
{
	int f, a;
	if (U.N[x].fa == x)
		return x;
	f = U.N[x].fa;
	a = u_fnd(U.N[x].fa);
	U.N[x].dist += U.N[f].dist;
	return U.N[x].fa = a;
}

/* merge u to v */
void u_mrg(int u, int v)
{
	int fu, fv;
	fu = u_fnd(u);
	fv = u_fnd(v);
	if  (fu == fv)
		return ;
	U.N[fu].dist += U.siz[fv];
	U.N[fu].fa = fv;
	U.siz[fv] += U.siz[fu];
	U.siz[fu] = 0;
}

int u_qry(int u, int v)
{
	int fu, fv;
	fu = u_fnd(u);
	fv = u_fnd(v);
	if (fu != fv)
		return -1;
	return abs(U.N[u].dist - U.N[v].dist) - 1;
}

int main(void)
{
	int T;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	u_ini(30003);
	scanf("%d", &T);
	while (T--) {
		char buf[3];
		int i, j;
		scanf("%s%d%d", buf, &i, &j);
		if (buf[0] == 'M')
			u_mrg(i, j);
		else
			printf("%d\n", u_qry(i, j));
	}

	return 0;
}
