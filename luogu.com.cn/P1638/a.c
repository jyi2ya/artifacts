#include <stdio.h>

int num[2009], tot = 0, a[1000009], ansl = 0, ansr = 0x7f7f7f7f;

int main(void)
{
	int N, M, i, l, r;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; ++i) scanf("%d", a + i);
	l = 1; r = 1; num[a[1]] = 1; tot = 1;
	while (l < N || r < N) {
		if (tot < M && r < N) {
			++r;
			if (!num[a[r]]) ++tot;
			++num[a[r]];
		} else {
			--num[a[l]];
			if (!num[a[l]]) --tot;
			++l;
		}
		if (tot == M) {
			if (r - l < ansr - ansl) {
				ansr = r;
				ansl = l;
			}
		}
	}
	printf("%d %d\n", ansl, ansr);
	return 0;
}
