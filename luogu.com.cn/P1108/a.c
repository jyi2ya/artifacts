#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int F[5009], C[5009], P[5009], N;

int main(void)
{
	int i, j, l, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", P + i);
	
	for (i = 0; i < N; ++i) {
		for (j = 0; j < i; ++j)
			if (P[j] > P[i])
				F[i] = max(F[j], F[i]);
		++F[i];
	}
	l = 0;
	for (i = 0; i < N; ++i)
		l = max(l, F[i]);

	printf("%d ", l);
	for (i = 0; i < N; ++i) {
		if (F[i] == 1)
			C[i] = 1;
		for (j = 0; j < i; ++j) {
			if (F[i] == F[j] + 1 && P[j] > P[i])
				C[i] += C[j];
			if (F[i] == F[j] && P[i] == P[j])
				C[i] = 0;
		}
	}
	k = 0;
	for (i = 0; i < N; ++i)
		if (F[i] == l)
			k += C[i];
	printf("%d\n", k);
	return 0;
}
