#include <stdio.h>

int main(void)
{
	int n;
	int i, j, k;
	static int a[10009];
	static int visa[10009];
	static int b[10009];
	static int visb[10009];

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	for (k = 0; k < n; ++k) {
		int pa = -1, pb = -1;
		for (i = 0; i < n; ++i) {
			if (visa[i])
				continue;
			for (j = 0; j < n; ++j) {
				if (visb[j])
					continue;
				if (pa < 0 || (a[i] ^ b[j]) < (a[pa] ^ b[pb])) {
					pa = i;
					pb = j;
				}
			}
		}
		printf("%d ", a[pa] ^ b[pb]);
		visa[pa] = 1;
		visb[pb] = 1;
	}
	putchar('\n');

	return 0;
}
