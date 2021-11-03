#include <stdio.h>

struct {
	struct {
		int edg, dpt, fa, vis;
	} N[1000009];
	struct {
		int dst, nxt;
	} E[2000009];
	int Ec;
} T;

void t_init(void)
{
	T.Ec = 1;
}

void t_add(int u, int v)
{
	T.E[T.Ec].dst = v;
	T.E[T.Ec].nxt = T.N[u].edg;
	T.N[u].edg = T.Ec++;
}

void t_add2(int u, int v)
{
	t_add(u, v);
	t_add(v, u);
}

void t_get_ans(int rt)
{
	int i;
	if (T.N[rt].vis)
		return ;
	T.N[rt].vis = 1;
	if (T.N[rt].dpt & 1)
		printf("%d ", rt);
	for (i = T.N[rt].edg; i; i = T.E[i].nxt) {
		int d = T.E[i].dst;
		if (d != T.N[rt].fa) {
			T.N[d].fa = rt;
			T.N[d].dpt = T.N[rt].dpt + 1;
			t_get_ans(d);
		}
	}
	if (T.N[rt].dpt & 1 ^ 1)
		printf("%d ", rt);
}

int main(void)
{
	int n;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &n);
	t_init();
	for (i = 0; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		t_add2(u, v);
	}

	puts("Yes");
	T.N[1].dpt = 1;
	t_get_ans(1);
	putchar('\n');

	return 0;
}
