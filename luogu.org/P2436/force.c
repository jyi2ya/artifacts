#include <stdio.h>

int min(int a, int b);
int max(int a, int b);

int N, M, s[1009], j[1009];

int main(void)
{
	while (scanf("%d%d", &N, &M) == 2) {
		int i, a, b;
		for (i = 0; i < N; ++i) {
			scanf("%d", s + i);
			--s[i];
		}
		for (i = 0; i < N; ++i) {
			scanf("%d", i + j);
			--j[i];
		}
		for (a = 1; a < (N + M) * 11; ++a)
			for (b = 1; b < (N + M) * 11; ++b) {
				int ok = 1;
				for (i = 0; i < N; ++i)
					if (s[i] % (a + b) >= a) {
						ok = 0;
						break;
					}
				if (!ok)
					continue;
				for (i = 0; i < M; ++i)
					if (j[i] % (a + b) < a) {
						ok = 0;
						break;
					}
				if (ok)
					goto OK;
			}
		puts("NO");
		continue;
OK:
		printf("%d %d\n", a, b);
	}
	return 0;
}
