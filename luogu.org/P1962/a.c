#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL

int main(void)
{
	long long n;
	long long base[1][2] = { {1, 1} }, mul[2][2] = { {1, 1} , {1, 0} },
	     basetmp[1][2], multmp[2][2];
	scanf("%lld", &n);
	--n;
	while (n) {
		register int i, j, k;
		if (n & 1) {
			memset(basetmp, 0, sizeof(basetmp));
			for (i = 0; i < 1; ++i)
				for (j = 0; j < 2; ++j)
					for (k = 0; k < 2; ++k)
						basetmp[i][j] = (basetmp[i][j] + base[i][k] * mul[k][j] % MOD) % MOD;
			memcpy(base, basetmp, sizeof(basetmp));
		}
		memset(multmp, 0, sizeof(multmp));
		for (i = 0; i < 2; ++i)
			for (j = 0; j < 2; ++j)
				for (k = 0; k < 2; ++k)
					multmp[i][j] = (multmp[i][j] + mul[i][k] * mul[k][j] % MOD) % MOD;
		memcpy(mul, multmp, sizeof(multmp));
		n /= 2;
	}
	printf("%lld\n", base[0][1]);
	return 0;
}
