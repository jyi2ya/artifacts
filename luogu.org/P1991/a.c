#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int U[1009];
int usiz;

void u_ini(int n)
{
	int i;
	usiz = n;
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
	if (u_qry(u, v))
		return ;
	--usiz;
	U[u_fnd(u)] = u_fnd(v);
}

struct E {
	int u, v;
	double w;
} E[1000009];
int top;

int cmp(const void *a, const void *b)
{
	return ((struct E *)a)->w - ((struct E *)b)->w;
}

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int x[1009], y[1009];

int main(void)
{
	int i, j;
	int s, p;
	double ans = 0;
	scanf("%d%d", &s, &p);
	for (i = 0; i < p; ++i)
		scanf("%d%d", &x[i], &y[i]);
	for (i = 0; i < p; ++i)
		for (j = 0; j < p; ++j) {
			E[top].u = i;
			E[top].v = j;
			E[top].w = dist(x[i], y[i], x[j], y[j]);
			++top;
		}
	qsort(E, top, sizeof(*E), cmp);
	u_ini(p);
	for (i = 0; i < top && usiz > s; ++i)
		if (!u_qry(E[i].u, E[i].v)) {
			u_mgr(E[i].u, E[i].v);
			ans = E[i].w;
		}
	printf("%.2f\n", ans);
	return 0;
}
