#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int cut[2][109], top[2], min[2] = {0x7fffffff, 0x7fffffff};

int main(void)
{
	int i, X, Y, Z, N, j;

	scanf("%d%d%d%d", &X, &Y, &Z, &N);
	cut[0][top[0]++] = 0;
	cut[1][top[1]++] = 0;

	for (i = 0; i < N; ++i) {
		int d, x;
		scanf("%d%d", &d, &x);
		cut[d][top[d]++] = x;
	}
	cut[0][top[0]++] = X;
	cut[1][top[1]++] = Y;
	qsort(cut[0], top[0], sizeof(int), cmp);
	qsort(cut[1], top[1], sizeof(int), cmp);
	for (j = 0; j < 2; ++j)
		for (i = 1; i < top[j]; ++i)
			if (cut[j][i] - cut[j][i - 1] < min[j])
				min[j] = cut[j][i] - cut[j][i - 1];
	printf("%d", min[0] * min[1] * Z);
	return 0;
}
