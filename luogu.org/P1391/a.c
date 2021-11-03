#include <stdio.h>
#include <string.h>

int main(void)
{
	register int i, j;
	int ans = 0x7f7f7f7f;
	int n;
	register unsigned int mask;

	int mt[20][20];
	int tmp[20][20];

	memset(mt, 0, sizeof(mt));
	memset(tmp, 0, sizeof(tmp));

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			scanf("%d", mt[i] + j);

	for (mask = 0; mask < (1 << n); ++mask) {
		int cnt = 0;
		for (i = 1; i <= n; ++i) {
			tmp[1][i] = (mask >> (i - 1)) & 1;
			if (tmp[1][i] == 0 && mt[1][i] == 1)
				goto NXTLOOP;
		}
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j)
				if ((tmp[i - 1][j] + tmp[i][j - 1] +
							tmp[i][j + 1]) & 1) {
					tmp[i + 1][j] = 1;
				} else {
					tmp[i + 1][j] = 0;
					if (mt[i + 1][j] == 1)
						goto NXTLOOP;
				}
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j)
				if (tmp[i][j] != mt[i][j])
					++cnt;
		if (ans > cnt)
			ans = cnt;
NXTLOOP:
		;
	}

	if (ans == 0x7f7f7f7f)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}
