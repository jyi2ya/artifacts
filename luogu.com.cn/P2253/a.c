#include <stdio.h>

int seq[20009], N, M;

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &M);
	while (M--) {
		int op, ans, cnt, i;

		scanf("%d", &op);
		seq[op] ^= 1;

		ans = 1, cnt = 1;
		for (i = 2; i <= N; ++i) {
			if (seq[i] == (seq[i - 1] ^ 1)) {
				++cnt;
			} else {
				cnt = 1;
			}
			if (cnt > ans)
				ans = cnt;
		}

		printf("%d\n", ans);
	}
	return 0;
}
