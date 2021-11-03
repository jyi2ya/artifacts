#include <stdio.h>

int val[1000009];

int blk_qry(int l, int r, int c)
{
	int i;
	int ans = -1;
	for (i = l; i <= r; ++i)
		if (ans < val[i] && val[i] < c)
			ans = val[i];
	return ans;
}

void blk_add(int l, int r, int c)
{
	int i;
	for (i = l; i <= r; ++i)
		val[i] += c;
}

int main(void)
{
	int n;
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	for (j = 0; j < n; ++j) {
		int op, l, r, c;
		scanf("%d%d%d%d", &op, &l, &r, &c);
		if (op == 0)
			blk_add(l, r, c);
		else
			printf("%d\n", blk_qry(l, r, c));
	}
	return 0;
}
