#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char buf[200009][20];
long long suf[200009];
int nxt[200009];

long long llmax(long long a, long long b)
{
	return a > b ? a : b;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int i;
		int n;
		int las;
		long long sum;
		long long ans;
		scanf("%d", &n);
		for (i = 0; i < 2 * n - 1; ++i) {
			scanf("%s", buf[i]);
			suf[i] = 0;
		}
		suf[2 * n + 1] = 0;
		suf[2 * n] = 0;
		for (i = 2 * n - 2; i >= 0; i -= 2)
			suf[i] = suf[i + 2] + atoll(buf[i]);
		las = -1;
		for (i = 2; i < 2 * n - 1; i += 2)
			if (buf[i - 1][0] == '-') {
				if (las >= 0)
					nxt[las] = i;
				las = i;
			}
		if (las >= 0)
			nxt[las] = 2 * n;
		sum = 0;
		ans = LLONG_MIN;
		for (i = 0; i < 2 * n - 1; i += 2) {
			if (i > 0 && buf[i - 1][0] == '-') {
				ans = llmax(ans,
					sum - (suf[i] - suf[nxt[i]]) + suf[nxt[i]]);
				sum -= atoll(buf[i]);
			} else {
				sum += atoll(buf[i]);
			}
		}
		ans = llmax(ans, sum);
		printf("%lld\n", ans);
	}
	return 0;
}
