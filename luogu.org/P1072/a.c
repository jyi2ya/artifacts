#include <stdio.h>

long long gcd(long long a, long long b);

int main(void)
{
	int n;
	long long a0, a1, b0, b1, ans, x;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	while (n--) {
		scanf("%lld%lld%lld%lld", &a0, &a1, &b0, &b1);
		ans = 0;
		if (a0 % a1 == 0 && b1 % b0 == 0) {
			for (x = 1; x * x <= b1; ++x)
				if (b1 % x == 0) {
					if (x % a1 == 0) {
						if (gcd(x / a1, a0 / a1) == 1 &&
								gcd(b1 / x, b1 / b0) == 1)
							++ans;
					}
					if (x * x != b1 && (b1 / x) % a1 == 0) {
						if (gcd((b1 / x) / a1, a0 / a1) == 1 &&
								gcd(x, b1 / b0) == 1)
							++ans;
					}
				}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

long long gcd(long long a, long long b)
{
	long long t;
	while (b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
