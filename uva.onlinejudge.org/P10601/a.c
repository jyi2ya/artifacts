/*
 * 设正方体的六个面分别为 L, R, U, D, F, B
 * 一个正方体旋转有 6 种方式，固定 L-R, U-D 或 F-B，旋转顺时针或逆时针。
 * 其他方式可以通过这 6 种方式组合得到。
 *
 * 12 根木棒，6 种颜色相当于
 * 有 6 种颜色，可用颜色数量的分别为 c_1, c_2 ... c_6, sum_(i=1)^6 c_i = 12
 *
 * 设旋转为置换 f (f in F) ，f 下的不动点（不变的着色方案） 数目为 C(f) 。
 * s = 1/|G| sum_(i=1)^|G| C(f_i)
 *
 * 这个题目看了题解。
 * 以下思路来自 https://blog.csdn.net/acm_cxlove/article/details/7866192
 */

#include <stdio.h>

long long C[15][15];

long long magic(const int *a, int group_size)
{
	int i;
	int group_cnt = 0;
	long long ans = 1;
	for (i = 1; i < 7; ++i) {
		if (a[i] % group_size == 0)
			group_cnt += a[i] / group_size;
		else
			return 0;
	}
	for (i = 1; i < 7; ++i) {
		ans *= C[group_cnt][a[i] / group_size];
		group_cnt -= a[i] / group_size;
	}
	return ans;
}

int main(void)
{
	int T;
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	for (i = 0; i < 15; ++i)
		C[i][0] = C[i][i] = 1;
	for (i = 1; i < 15; ++i)
		for (j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];

	scanf("%d", &T);

	while (T--) {
		int col[7];
		long long ans = 0;

		for (i = 0; i < (int)(sizeof(col) / sizeof(col[0])); ++i)
			col[i] = 0;

		for (i = 0; i < 12; ++i) {
			int t;
			scanf("%d", &t);
			++col[t];
		}

		ans = 
			magic(col, 1) +

			magic(col, 3) * 8 +

			magic(col, 4) * 6 +
			magic(col, 2) * 3;

		for (i = 1; i < 7; ++i)
			for (j = 1; j < 7; ++j) {
				if (col[j] < 1 || col[i] < 1)
					continue;
				--col[i];
				--col[j];
				ans += magic(col, 2) * 6;
				++col[i];
				++col[j];
			}

		printf("%lld\n", ans / 24);
	}

	return 0;
}
