/*
 * 题意
 * ====
 * 现在存储了一个 2^a * 2^b 的矩阵，矩阵在内存中是按行存储的。
 * 现在你想求它的转置。唯一允许的操作是交换两个内存位置的值，求最少需要的次数。
 * 4e5 组询问，每组询问 a + b <= 1e6
 *
 * 前置知识
 * ========
 * 这个题目和矩阵转置有关，但是我并不了解矩阵转置。所以先去查了一些资料。
 * 设矩阵 A 的转置为 B ，则 b_(ij) = a_(ji) 。
 *
 * A = [[a, b, c], [d, e, f]]
 * A^T = [[a, d], [b, e], [c, f]]
 *
 * 解题
 * ====
 * 设一个 2^a 行，2^b 列的矩阵 A 。
 * 矩阵转置，很容易让人联想到置换。如果把矩阵拍扁，可以得到一个序列：
 * P: a_(11), a_(12), ..., a_(1(2^b)), a_(21), ..., a_((2^a)(2^b))
 *
 * 可以发现：
 * 矩阵 A 中 a_(ij) 在 P 上位于 i*2^b+j 。
 * 转置后 p_(i*2^b+j) 到了 p_(j*2^a+i) 。
 *
 * 然后再想，就可以把问题转化一下了：
 * 有一个序列 Q ，把 p_i 置换到 p_((i mod 2^b) * 2^a + (i / 2^b))
 * 求循环节的数量 （用 2^(a+b) 减去就是答案了）。
 * （也就是 brute 函数的做法）
 *
 * 如果要优化的话应该要和进制转换无机结合，再用一些神秘方法统计循环个数。
 *
 * 手玩一下：
 * (i)
 * ((i mod 2^b) * 2^a + (i / 2^b))
 * ((((i mod 2^b) * 2^a + (i / 2^b)) mod 2^b) * 2^a + (((i mod 2^b) * 2^a + (i / 2^b)) / 2^b))
 *
 * 好吧又没有思路了。不过这个题目比上一个题想的多了一些，也算是有一点进步。这是
 * A-I 中除了水题我离正解最近的一个题。
 *
 * 学习题解
 * ========
 *
 *（https://blog.csdn.net/u013534123/article/details/77998405）
 *
 * 题解也手玩了一下（下面是下标的二进制）：
 * 当 a = 1, b = 2 时：
 * 000 001 010 011 100 101 110 111
 * 以下是每一个下标所在的循环节：
 * 000 001 010 011 100 101 110 111
 *     010 100 110 001 011 101
 *     100 001 101 010 110 011
 * 然后题解发现，如果把二进制头尾相连，下标为 i 的目标位置，就是把 i 的二进制向
 * 前移动 b 位。
 * 于是这个题目统计循环节的部分就可以转化为：长为 a+b 的 01 串中，有多少个串是本
 * 质不同的。
 *
 * > 但是，这里又不是像常规Polya一样的。普通的Polya，旋转置换有多个，这里却只能
 * > 有移动b位这一个置换，故burnside引理在这里不能直接对移动b位使用。既然如此，
 * > 我们就得转换一下了，考虑正常的时候，移动b位的循环节个数为gcd(b,a+b)，然后循
 * > 环长度为(a+b)/gcd。再次说一下，这里不能直接用burnside引理计算不动点个数。我
 * > 们要做的，是考虑把每gcd个数字绑在一起，原本移动b位，现在就能够移动任意位。
 * > 那么问题就转换为了，有长度为(a+b)/gcd的一个项链，每个项链可以用2^gcd(每一捆
 * > 里面有gcd个数字，每个数字取0、1)种颜色来染色，问在旋转置换下本质不同的染色
 * > 方案数。此时再按照套路直接用burnside引理计算即可。
 *
 * 这个想法很显然，所以我就不再赘述了。
 *
 * 还有就是好喜欢洛天依啊。
 */

#include <stdio.h>
#include <string.h>

#define MOD 1000003

int vis[1 << 20];

void brute(void)
{
	int T;

	scanf("%d", &T);
	while (T--) {
		unsigned int i, j;
		int a, b;
		int ans = 0;
		int t;

		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &a, &b);

		t = 1 << (a + b);
		ans = t;
		for (i = 0; (int)i < t; ++i)
			if (!vis[i]) {
				j = i;
				do {
					vis[j] = 1;
					j = ((j & ((1 << b) - 1)) << a) +
						(j >> b);
				} while (j != i);
				--ans;
			}

		printf("%d\n", ans);
	}

}

int loop_size(unsigned long long x, int a, int b)
{
	int cnt = 0;
	unsigned long long j = x;
	do {
		++cnt;
		j = ((j & ((1 << b) - 1)) << a) + (j >> b);
	} while (j != x);
	return cnt;
}

long long minv[MOD];
long long mpow[MOD];
long long mphi[MOD];

#define PMAX 1000000
int prime[PMAX];
int is_not_prime[PMAX];
void init(void)
{
	int i, j, k = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	minv[1] = 1;
	for (i = 2; i < MOD; ++i)
		minv[i] = (MOD - MOD / i) * minv[MOD % i] % MOD;

	mpow[0] = 1;
	for (i = 1; i < MOD; ++i)
		mpow[i] = mpow[i - 1] * 2 % MOD;

	mphi[1] = 1;
	for (i = 2; i < PMAX; ++i) {
		if (!is_not_prime[i]) {
			prime[k++] = i;
			mphi[i] = i - 1;
		}
		for (j = 0; j < k && i * prime[j] < MOD; ++j) {
			is_not_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				mphi[i * prime[j]] = mphi[i] * prime[j];
				break;
			} else {
				mphi[i * prime[j]] = mphi[i] * (prime[j] - 1);
			}
		}
	}
}

int igcd(int a, int b)
{
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int polya(int ring_size, int color_num)
{
	int i;
	long long ans = 0;

	for (i = 1; i * i < ring_size; ++i)
		if (ring_size % i == 0) {
			ans = (ans + mpow[color_num * i] *
					mphi[ring_size / i] % MOD) % MOD;
			ans = (ans + mpow[color_num * (ring_size / i)] *
					mphi[i] % MOD) % MOD;
		}

	if (i * i == ring_size)
		ans = (ans + mpow[color_num * i] *
				mphi[i] % MOD) % MOD;

	return ans * minv[ring_size] % MOD;
}

void solve_single(void)
{
	/*
	 * 代码打得文艺一点，又不是在打 acm 。
	 */
	int a, b;
	int new_node_size;
	int new_ring_length;
	int color_num;

	scanf("%d%d", &a, &b);

	if (a == 0 || b == 0) {
		puts("0");
		return;
	}

	new_node_size = igcd(a + b, b);
	new_ring_length = (a + b) / new_node_size;
	color_num = new_node_size;

	printf("%lld\n", (mpow[a + b] - polya(new_ring_length, color_num) + MOD)
			% MOD);
}

void solve(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve_single();
}

int main(void)
{
	init();
	solve();
	return 0;
}
