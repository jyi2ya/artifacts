#include <stdio.h>

int min(int a, int b);
int max(int a, int b);

int N, M, s[1009], j[1009];

int main(void)
{
	while (scanf("%d%d", &N, &M) == 2) {
		int i, sum, a, b, limit = (N + M + 1) * 10;
		for (i = 0; i < N; ++i) {
			scanf("%d", s + i);
			--s[i];
		}
		for (i = 0; i < M; ++i) {
			scanf("%d", j + i);
			--j[i];
		}

		a = 0x7f7f7f7f, b = 0x7f7f7f7f;
		for (sum = 2; sum <= limit; ++sum) {
			int mx = -0x7f7f7f7f, mn = 0x7f7f7f7f;

			for (i = 0; i < N; ++i)
				mx = max(s[i] % sum, mx);
			for (i = 0; i < M; ++i)
				mn = min(j[i] % sum, mn);

			if (mx < mn && mx + 1 < a) {
				a = mx + 1;
				b = sum - mx - 1;
			}
		}

		if (a != 0x7f7f7f7f)
			printf("%d %d\n", a, b);
		else
			puts("NO");
	}
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
