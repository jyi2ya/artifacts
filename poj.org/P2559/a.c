#include <stdio.h>

long long max(long long a, long long b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n;

	while (scanf("%d", &n) == 1 && n) {
		static long long v[100009];
		static int l[100009], r[100009];
		static int s[100009];
		long long a = 0;
		int i;
		int t;

		for (i = 1; i <= n; ++i)
			scanf("%lld", &v[i]);

		t = 1;
		for (i = 1; i <= n; ++i) {
			while (t > 1 && v[i] <= v[s[t - 1]])
				--t;
			l[i] = (t == 1 ? 1 : s[t - 1] + 1);
			s[t++] = i;
		}
		t = 1;
		for (i = n; i >= 1; --i) {
			while (t > 1 && v[i] <= v[s[t - 1]])
				--t;
			r[i] = (t == 1 ? n : s[t - 1] - 1);
			s[t++] = i;
		}

		for (i = 1; i <= n; ++i)
			a = max(a, v[i] * (r[i] - l[i] + 1));

		printf("%lld\n", a);
	}

	return 0;
}
