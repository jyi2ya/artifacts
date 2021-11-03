#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define readvar(var) \
	do { \
		int rv_ch, rv_lt0 = 0; \
		*(var) = 0; \
		while (!isdigit(rv_ch = getchar()) && rv_ch != '-'); \
		if (rv_ch == '-') \
			rv_lt0 = 1; \
		else \
			*(var) = rv_ch - '0'; \
		while (isdigit(rv_ch = getchar())) \
			*(var) = *(var) * 10 + rv_ch - '0'; \
		ungetc(rv_ch, stdin); \
		if (rv_lt0) \
			*(var) = -*(var); \
	} while (0)

int min(int a, int b)
{
	return a < b ? a : b;
}

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int L, S, T, M, A[119], F[5000009], D[5000009];

int main(void)
{
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	readvar(&L);
	readvar(&S); readvar(&T); readvar(&M); 

	A[0] = 0;
	for (i = 0; i < M; ++i)
		readvar(A + i);
	qsort(A, M, sizeof(int), cmp);
	for (i = 1; i < M; ++i)
		while (A[i] - A[i - 1] > 2520)
			for (j = i; j < M; ++j)
				A[j] -= 2520;
	for (i = 0; i < M; ++i)
		D[A[i]] = 1;

	for (i = 5000000; i >= 0; --i) {
		if (i >= L)
			F[i] = 0;
		else
			F[i] = 0x7f7f7f7f;

		for (j = S; j <= T; ++j)
			F[i] = min(F[i], F[i + j]);

		F[i] += D[i];
	}

	printf("%d\n", F[0]);
	return 0;
}
