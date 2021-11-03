#include <stdio.h>
#include <stdlib.h>

#define EMAX (1000009)
#define NMAX (500009)
#define MMAX (500009)

typedef struct range {
	int l, r, i;
} range;
range R[MMAX];
int A[NMAX], S[NMAX], N, M, F[NMAX], P[NMAX], V[EMAX];

int cmp(const void *a, const void *b);

int main(void)
{
	int i, j, l, r, p;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
		scanf("%d", S + i);
	for (i = 1; i <= N; ++i) {
		P[i] = V[S[i]];
		V[S[i]] = i;
	}
	scanf("%d", &M);
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &R[i].l, &R[i].r);
		R[i].i = i;
	}
	qsort(R, M, sizeof(range), cmp);

	p = 0;
	for (i = 1; i <= N; ++i) {
		if (P[i])
			for (j = P[i]; j <= N; j += (j & (-j)))
				--F[j];
		for (j = i; j <= N; j += (j & (-j)))
			++F[j];
		while (p < M && R[p].r == i) {
			l = 0;
			for (j = R[p].l - 1; j; j -= (j & (-j)))
				l += F[j];
			r = 0;
			for (j = i; j; j -= (j & (-j)))
				r += F[j];
			A[R[p].i] = r - l;
			++p;
		}
	}

	for (i = 0; i < M; ++i)
		printf("%d\n", A[i]);

	return 0;
}

int cmp(const void *a, const void *b)
{
	return ((range*)a)->r - ((range*)b)->r;
}
