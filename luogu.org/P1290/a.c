#include <stdio.h>

int T;
long long t, M, N;
int win;

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &M, &N);

		if (M < N) {
			t = M;
			M = N;
			N = t;
		}

		win = -1;

		while (N) {
			if (M / N > 1)
				break;
			if (M == N)
				break;
			win = ~win;

			t = M % N;
			M = N;
			N = t;
		}

		if (win == -1)
			puts("Stan wins");
		else
			puts("Ollie wins");
	}
	return 0;
}
