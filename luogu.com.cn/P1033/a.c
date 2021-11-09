#include <stdio.h>
#include <math.h>

#define DIFF 1e-5

double H, S1, V, L, K, t, r;
int n, i, ans = 0;

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lf%lf%lf%lf%lf%d", &H, &S1, &V, &L, &K, &n);
	for (i = 0; i < n; ++i) {
		t = sqrt((H - K) * 2.0 / 10.0);
		r = i + V * t;
		if (S1 - DIFF <= r && r <= S1 + L + DIFF) {
			++ans;
		} else {
			t = (S1 - i) / V;
			r = 0.5 * 10.0 * t * t;
			if (H - K - DIFF <= r && r <= H + DIFF)
				++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
