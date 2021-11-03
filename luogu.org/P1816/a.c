#include <stdio.h>
#include <ctype.h>

int seq[100009], blk[1009], blk_size = 100;

int readint(void);

int main(void)
{
	int m, n, i, l, r, ans;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; ++i)
		scanf("%d", seq + i);
	for (i = 0; i < 1009; ++i)
		blk[i] = 0x7f7f7f7f;
	for (i = 0; i < m; ++i)
		if (seq[i] < blk[i / blk_size])
			blk[i / blk_size] = seq[i];

	while (n--) {
		ans = 0x7f7f7f7f;
		scanf("%d%d", &l, &r);
		--l, --r;
		for (; l % blk_size && l <= r; ++l)
			if (seq[l] < ans)
				ans = seq[l];
		for (; l + blk_size <= r; l += blk_size)
			if (blk[l / blk_size] < ans)
				ans = blk[l / blk_size];
		for (; r >= l; --r)
			if (seq[r] < ans)
				ans = seq[r];
		printf("%d ", ans);
	}

	putchar('\n');
	return 0;
}

int readint(void)
{
	int ans = 0, ch;
	while (!isdigit(ch = getchar()));
	ans = ch - '0';
	while (isdigit(ch = getchar()))
		ans = ans * 10 + ch - '0';
	ungetc(ch, stdin);
	return ans;
}
