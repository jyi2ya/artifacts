#include <stdio.h>
#include <string.h>

long long min(long long a, long long b)
{
	return a < b ? a : b;
}

int main(void)
{
	static long long f[64][64][64];
	static long long d[64][64];
	long long i, j, k, l;
	long long n, m;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%lld%lld", &n, &m);
	while (m--) {
		long long u, v;
		scanf("%lld%lld", &u, &v);
		f[u][v][0] = 1;
	}
	
	for (i = 0; i < 64; ++i)
		for (j = 1; j <= n; ++j)
			for (k = 1; k <= n; ++k)
				for (l = 1; l <= n; ++l)
					if (f[j][l][i - 1] && f[l][k][i - 1])
						f[j][k][i] = 1;
	memset(d, 0x3f, sizeof(d));
	for (i = 1; i <= n; ++i)
		d[i][i] = 0;
	for (i = 0; i < 64; ++i)
		for (j = 1; j <= n; ++j)
			for (k = 1; k <= n; ++k)
				if (f[j][k][i])
					d[j][k] = 1;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			for (k = 1; k <= n; ++k)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	printf("%lld\n", d[1][n]);
	return 0;
}
