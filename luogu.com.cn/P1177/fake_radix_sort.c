#include <stdio.h>

int tmp[256][100009], top[256];
unsigned int a[100009];

int main(void)
{
	int n;
	register int i, j, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%u", a + i);

	for (i = 0; i < 4; ++i) {
		int t = 0;

		for (j = 0; j < n; ++j) {
			int x = (a[j] >> (i << 3)) & 0xff;
			tmp[x][top[x]++] = a[j];
		}

		for (j = 0; j < 256; ++j) {
			for (k = 0; k < top[j]; ++k)
				a[t++] = tmp[j][k];
			top[j] = 0;
		}
	}

	for (j = 0; j < n; ++j)
		printf("%u ", a[j]);
	putchar('\n');
	return 0;
}
