#include <stdio.h>
#include <string.h>

int main(void)
{
	static int C[5009][5009];
	static int num[5009][5009];
	int i, j;
	int t, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &t, &k);
	C[0][0] = 1;
	for (i = 1; i < 5009; ++i) {
		C[i][0] = 1;
		for (j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
	}
	for (i = 0; i < 5009; ++i)
		for (j = 0; j < 5009; ++j)
			num[i][j] =
				(i ? num[i - 1][j] : 0) +
				(j ? num[i][j - 1] : 0) -
				(i && j ? num[i - 1][j - 1] : 0) +
				(j <= i && C[i][j] == 0 ? 1 : 0);
	while (t--) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", num[u][v]);
	}
	return 0;
}
