#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main(void)
{
	int p, q;
	int a[300009];
	register int i;
	int tot;

	scanf("%d%d", &p, &q);
	for (i = 0; i < p; ++i)
		scanf("%d", a + i);
	qsort(a, p, sizeof(int), cmp);
	tot = p;

	while (q--) {
		int op, n;
		scanf("%d%d", &op, &n);

		if (op == 1) {
			printf("%d\n", a[tot - n]);
		} else {
			register int l = 0, r = tot, m;
			while (l < r) {
				m = (l + r) >> 1;
				if (n < a[m])
					r = m;
				else
					l = m + 1;
			}
			memmove(a + l + 1, a + l, sizeof(int) * (tot - l));
			a[l] = n;
			++tot;
		}
	}

	return 0;
}
