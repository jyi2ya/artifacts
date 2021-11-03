#include <stdio.h>

#define MOD 1000000007LL

int main(void)
{
	int T;
	long long L, R, i, t, a;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &T);
	while (T--) {
		a = 0;
		scanf("%lld%lld", &L, &R);
		for (i = L; i <= R; ++i) {
			t = i;
			while (t) {
				a = (a + t % 10) % MOD;
				t /= 10;
			}
		}
		printf("%lld\n", a);
	}
	return 0;
}
