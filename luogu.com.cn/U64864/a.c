#include <stdio.h>

#define MAX 10009

int S[MAX];

int main(void)
{
	int i, n, m;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", S + i);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		switch (n) {
			case 1: {
					scanf("%d", &n);
					if (n == 0)
						break;
					printf("%d\n", S[n]);
					break;
				}
			case 2: {
					scanf("%d", &n);
					for (i = MAX - 3; i >= n; --i)
						S[i + 1] = S[i];
					scanf("%d", &n);
					S[i + 1] = n;
					break;
				}
			case 3: {
					scanf("%d", &n);
					for (i = n + 1; i < MAX - 3; ++i)
						S[i - 1] = S[i];
					break;
				}
			default: break;
		}
	}
	return 0;
}
