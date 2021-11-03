#include <stdio.h>
#include <string.h>

int val[200009];

int main(void)
{
	int n;
	int i;
	int tot;
	scanf("%d", &n);
	tot = n;
	for (i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	while (n--) {
		int op, l, r, c;
		scanf("%d%d%d%d", &op, &l, &r, &c);
		if (op == 0) {
			++tot;
			memmove(val + l + 1, val + l, sizeof(int) * (tot - l));
			val[l] = r;
		} else {
			printf("%d\n", val[r]);
		}
	}
	return 0;
}
