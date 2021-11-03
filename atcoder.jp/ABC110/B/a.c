#include <stdio.h>

int main(void)
{
	int X, Y, min, max, N, M, i;
	scanf("%d%d%d%d", &N, &M, &X, &Y);
	min = X + 1;
	for (i = 0; i < N; ++i) {
		int x;
		scanf("%d", &x);
		if (x >= min) min = x + 1;
	}
	max = Y;
	for (i = 0; i < M; ++i) {
		int x;
		scanf("%d", &x);
		if (x < max) max = x;
	}

	if (min <= max) puts("No War");
	else puts("War");

	return 0;
}
