#include <stdio.h>

long long val[10000009];

int main(){
	int n, m;
	int i;
	int l, r;
	long long x, y;
	long long xx, mx;
	scanf("%d%d", &n, &m);
	while (m--) {
		long long d;
		scanf("%d%d%lld%lld", &l, &r, &x, &y);
		d= (y - x) / (r - l);
		val[l] += x;
		val[l + 1] += d - x;
		val[r + 1] -= d + y;
		val[r + 2] += y;
	}

	x = 0;
	y = 0;
	xx = 0;
	mx = 0;
	for (i = 1; i <= n; ++i) {
		x += val[i];
		y += x;
		xx ^= y;
		if (y > mx)
			mx = y;
	}
	printf("%lld %lld\n", xx, mx);
	return 0;
}
