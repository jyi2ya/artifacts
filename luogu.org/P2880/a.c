#include <stdio.h>

int h[50009], min[509], max[509], block_size = 100;
int N, Q;

int main(void)
{
	int i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &Q);
	for (i = 0; i < N; ++i)
		scanf("%d", h + i);
	for (i = 0; i < 509; ++i) {
		max[i] = 0;
		min[i] = 0x7f7f7f7f;
	}
	for (i = 0; i < N; ++i) {
		if (h[i] > max[i / block_size])
			max[i / block_size] = h[i];
		if (h[i] < min[i / block_size])
			min[i / block_size] = h[i];
	}
	while (Q--) {
		int mx = 0, mn = 0x7f7f7f7f, l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		for (; l % block_size && l <= r; ++l) {
			if (h[l] > mx)
				mx = h[l];
			if (h[l] < mn)
				mn = h[l];
		}
		for (; l + block_size <= r; l += block_size) {
			if (max[l / block_size] > mx)
				mx = max[l / block_size];
			if (min[l / block_size] < mn)
				mn = min[l / block_size];
		}
		for (; r >= l; --r) {
			if (h[r] > mx)
				mx = h[r];
			if (h[r] < mn)
				mn = h[r];
		}
		printf("%d\n", mx - mn);
	}
	return 0;
}
