/*
 * 如果 a + b - 1 > n ，肯定无解。因为最长上升序列和最长下降序列最多只会公用一
 * 个元素。
 *
 * 当 a + b - 1 < n 时，可以先生成一个长为 a 的上升序列。
 * 如果之后有数大于这个序列的最后一项，该数肯定可以与此序列共同组成长为
 * a + 1 的上升序列，不符合题目要求。因此这个数列应该是 { n - a + 1, n - a + 2, 
 * ..., n } ，可以保证之后的数对这个数列无影响。
 * 接下来应该生成一个下降序列。考虑到前面的上升序列的每一项都大于下降序列的第一
 * 项，这个下降序列的长度应该为 b - 1 。为了保证后面的数对此序列无影响，这个数
 * 列应该是 { b - 1, b - 2, b - 3, ... , 1 } 。
 * 接下来交替生成上升，下降序列，生成到最后一项就赢了。如果中途某一个过程中发现
 * 没有数可取，则说明无解。
 */
#include <stdio.h>

int imin(int a, int b)
{
	return a < b ? a : b;
}

int imax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int T;
#ifndef ONLINE_JUDGE
	freopen("seq.in", "r", stdin);
#ifndef DEBUG
	freopen("seq.out", "w", stdout);
#endif
#endif
	scanf("%d", &T);
	while (T--) {
		int n, a, b;
		int i;
		int top = 0;
		int max, min;
		static int ans[200009];

		scanf("%d%d%d", &n, &a, &b);

		if (a + b - 1 > n) {
			puts("No");
			continue;
		}

		max = n;
		min = 1;

		for (; ; ) {
			if (a == 0)
				break;
			for (i = imax(1, min + a - max); i <= a; ++i)
				ans[top++] = max - a + i;
			max -= a;
			--b;

			if (b == 0)
				break;
			for (i = imin(b - 1, max - min); i >= 0; --i)
				ans[top++] = i + min;
			min += b;
			--a;

			if (top > n)
				break;
		}

		if (top < n) {
			puts("No");
			continue;
		}

		puts("Yes");
#ifndef TEST_Y_N
		for (i = 0; i < n; ++i)
			printf("%d ", ans[i]);
		putchar('\n');
#endif
	}

	return 0;
}
