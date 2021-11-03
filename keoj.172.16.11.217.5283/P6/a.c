/*
 * 来条一言：
 * 所以我决定不再掩饰着我自己，所以我就在这里唱出我的旋律。
 */

#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int calc(int n, int m)
{
	int i;
	long long k;
	long long a = 0;
	if (m == 1)
		return n;
	for (i = 2; i <= n; i += k) {
		k = (long long)min(n - i + 1, max(1, (i - a - 1) / (m - 1)));
		a = (a + k * m) % (i + k - 1);
	}
	return (int)(a + 1);
}

#ifdef DEBUG
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

int more_brute_calc(int n, int m)
{
	int t = n - 1;
	int i = -1;
	static int alive[100009];
	memset(alive, 0xcc, sizeof(alive));
	while (t--) {
		int j;
		for (j = 0; j < m; ++j)
			for (i = (i + 1) % n; !alive[i] ; i = (i + 1) % n);
		alive[i] = 0;
	}
	for (i = 0; i < n; ++i)
		if (alive[i])
			return i + 1;
	return -1;
}

int brute_calc(int n, int m)
{
	int i;
	int a = 0;
	for (i = 2; i <= n; ++i)
		a = (a + m) % i;
	return a + 1;
}

void test_main(void)
{
	int i;
	srand(time(NULL));
	for (i = 1; i <= 100; ++i) {
		int n = 1000000, m = rand() % 100000 + 1;
		assert(brute_calc(n, m) == calc(n, m));
	}
	puts("PASS");
	exit(0);
}
#endif

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", calc(n, m));
	}
	return 0;
}
