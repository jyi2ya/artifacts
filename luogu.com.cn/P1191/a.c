#include <stdio.h>

int main(void)
{
	int i, j;
	static int v[1009][1009];
	static int r[1009][1009];
	static int s[1009];
	static long long m[1009];
	int t = 0;
	int n;
	long long a = 0;

	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		while (getchar() != '\n');
		for (j = 1; j <= n; ++j)
			v[i][j] = getchar();
	}
	for (i = 1; i <= n; ++i)
		for (j = n; j >= 1; --j)
			r[i][j] = (v[i][j] == 'B' ? 0 : r[i][j + 1] + 1);
	for (i = 1; i <= n; ++i) {
		t = 1;
		for (j = 1; j <= n; ++j) {
			while (t > 1 && r[s[t - 1]][i] >= r[j][i])
				--t;
			m[j] = m[s[t - 1]] + (j - s[t - 1]) * r[j][i];
			a += m[j];
			s[t++] = j;
		}
	}
	printf("%lld\n", a);
	return 0;
}
