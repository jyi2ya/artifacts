#include <stdio.h>

#define MOD 10001

int T, x[20009];

int judge(int a, int b);

int main(void)
{
	int a, b, i;
	scanf("%d", &T);
	for (i = 1; i <= T * 2; i += 2) scanf("%d", x + i);
	for (a = 0; a <= 10001; ++a)
		for (b = 0; b <= 10001; ++b)
			if (judge(a, b)) goto OK;
OK:
	for (i = 2; i <= T * 2; i += 2) printf("%d\n", x[i]);
	return 0;
}

int judge(int a, int b)
{
	int i;
	for (i = 2; i <= T * 2; ++i) {
		if (i & 1) {
			int n = (a * x[i - 1] + b) % MOD;
			if (x[i] != n) return 0;
		} else {
			x[i] = (a * x[i - 1] + b) % MOD;
		}
	}
	return 1;
}
