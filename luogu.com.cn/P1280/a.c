#include <stdio.h>
#include <stdlib.h>

typedef struct task_t {
	int s, e;
} task_t;
int N, K;
task_t T[10009];
int nxt[10009];
int V[10009], M[10009];

int cmp(const void *a, const void *b);
int max(int a, int b);
int dfs(int p);

int main(void)
{
	int i, p, t;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &K);
	for (i = 1; i <= K; ++i) {
		scanf("%d%d", &p, &t);
		T[i].s = p, T[i].e = p + t - 1;
	}
	qsort(T + 1, K, sizeof(task_t), cmp);
	++K;
	T[0].s = 0, T[0].e = 0;
	T[K].s = N + 1, T[K].e = 0x7f7f7f7f;

	for (i = 0; i < K; ++i)
		for (nxt[i] = i; nxt[i] < K && T[nxt[i]].s <= T[i].e; ++nxt[i])
			;

	printf("%d\n", dfs(0));
	return 0;
}

int dfs(int p)
{
	int a = 0, i;
	if (V[p])
		a = M[p];
	else if (p == K)
		a = 0;
	else
		for (i = p; i < K && T[i].s == T[p].s; ++i)
			a = max(a, dfs(nxt[i]) + T[nxt[i]].s - T[i].e - 1);
	V[p] = 1, M[p] = a;
	return a;
}

int cmp(const void *a, const void *b)
{
	task_t *p = (task_t*)a, *q = (task_t*)b;
	return (p->s == q->s) ? (p->e - q->e) : (p->s - q->s);
}

int max(int a, int b)
{
	return a > b ? a : b;
}
