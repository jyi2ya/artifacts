/*
 * 之前已经做了那么些题目了，这个题应该可以自己想出来。
 *
 * 题意
 * ====
 * 有 N+1 个珠子，连成一个环。一个居中，N 个分布在周围。每个周围的珠子要和中间的
 * 珠子连一条边，周围的珠子相邻的两个之间连一条边。总共 2n 条边。所有边的端点不
 * 能同色，可以旋转。给珠子染上最多 K 种颜色，问有多少本质不同的染色方案。模
 * 1000000007
 *
 * 题解
 * ====
 * 有 k 种颜色，而中间的又不能和周围的同色，所以可以枚举中间珠子的颜色，然后原
 * 问题转化为：
 * 有一个长为 N 的环，给环染最多 K 种颜色。环上同色的珠子不能相邻。环可以旋转，
 * 问本质不同的方案数。
 *
 * 想到了以前做过的一个相似的题目。那个题目给定了哪些颜色不能相邻。但是那个题目
 * 颜色只有 10 ，可以做矩阵快速幂做掉。这个题目 K 有 1e9 ，应该要一些变化。
 *
 * 考虑最祼的项链，当旋转 i 时循环节个数为 gcd(i, n) ，大小为 n / gcd(i, n)。把
 * 每一个循环节拿出一个珠子，形成一个序列。这个序列长度为 gcd(i, n) 。这个序列的
 * 染色方案数就是旋转 i 时不动点的数目。
 * 尝试在可以相邻的颜色间连边。因为序列的首和『尾的下一个』必须为同色，序列的染
 * 色方案数实际上也相当于 sum_(i=1)^K (i 到 i 走 gcd(i, n) 步的方案数)
 *
 * 问题又转化为：
 * N 个点的图，任意两个不同的点间均连有一条无向边。求从 i 到 i 走 L 步的方案数。
 *
 * 就是邻接矩阵的幂的意义。
 * 0 1 1 1 1 1 1 ...
 * 1 0 1 1 1 1 1 ...
 * 1 1 0 1 1 1 1 ...
 * 1 1 1 0 1 1 1 ...
 * 1 1 1 1 0 1 1 ...
 * 1 1 1 1 1 0 1 ...
 * 1 1 1 1 1 1 0 ...
 * ...
 * （意思是说我要对一个 1e9 x 1e9 的矩阵快速幂咯（bushi）？）
 * 
 * （下面好像又不会分析了）
 *
 * 啊哈题解换了个思路，想式子更加方便。
 * https://www.cnblogs.com/DrunBee/archive/2012/09/14/2684935.html
 *
 * 题解把这个序列直接看成环，令 f(n) 为合法序列数。
 * f(1) = k
 * f(2) = k * (k - 1)
 * f(n) =
 * f(n-1) * (k-2) （原来就是合法序列，插入一个后仍为合法序列）
 * + f(n-2) * (k-1) （原来为长度为 n-1 的非法序列，插入一个后变成合法序列）
 *
 * 然后矩阵优化（破音）！！！
 * 用 [[k-2, 1], [k-1, 0]] 来进行优化。
 *
 * 整理一下思路。
 * 方案数 =
 *   sum_(i=1)^k sum_(j=1)^n ([[k-3, 1], [k-2, 0]]^(gcd(n, j)))_(00)
 * = k * sum_(i=1)^n ([[k-3, 1], [k-2, 0]]^(gcd(n, i)))_(00)
 * = k * sum_(d|n) phi(n/d) ([[k-3, 1], [k-2, 0]]^d)_(00)
 */

#include <stdio.h>
#include <string.h>

#define MOD 1000000007

#define PMAX 1000000
int prime[PMAX];
int is_not_prime[PMAX];

void exgcd(long long a, long long b, long long *x, long long *y)
{
	if (b) {
		exgcd(b, a % b, y, x);
		*y -= (a / b) * *x;
	} else {
		*x = 1;
		*y = 0;
	}
}

long long inv(long long a)
{
	long long x, y;
	exgcd(a, MOD, &x, &y);
	return (x + MOD) % MOD;
}

typedef long long mtx[2][2];

void mtx_prt(mtx x)
{
	printf(
			"mtx = {\n"
			"\t{ %lld, %lld },\n"
			"\t{ %lld, %lld }\n"
			"}\n", x[0][0], x[0][1], x[1][0], x[1][1]);
}

void mtx_mul(mtx c, mtx a, mtx b)
{
	int i, j, k;
	mtx ans = {
		{ 0, 0 },
		{ 0, 0 }
	};
	for (i = 0; i < 2; ++i)
		for (j = 0; j < 2; ++j)
			for (k = 0; k < 2; ++k)
				ans[i][j] = (ans[i][j] +
						a[i][k] * b[k][j] % MOD) % MOD;
	memcpy(c, ans, sizeof(mtx));
}

void mtx_pow(mtx c, mtx a, int b)
{
	mtx ans = {
		{ 1, 0 },
		{ 0, 1 }
	};
	mtx base;
	memcpy(base, a, sizeof(mtx));

	while (b) {
		if (b & 1)
			mtx_mul(ans, ans, base); 
		mtx_mul(base, base, base);
		b /= 2;
	}

	memcpy(c, ans, sizeof(mtx));
}

int phi(int x)
{
	int ans = x;
	int i;
	for (i = 0; prime[i] * prime[i] <= x; ++i)
		if (x % prime[i] == 0) {
			ans -= ans / prime[i];
			while (x % prime[i] == 0)
				x /= prime[i];
		}
	if (x > 1)
		ans -= ans / x;
	return ans;
}

long long magic(int k, int d)
{
	mtx G = {
		{ k - 2, 1 },
		{ k - 1, 0 }
	};

	if (d == 1)
		return 0LL;
	if (d == 2)
		return (long long)k * (k - 1) % MOD;
	if (d == 3)
		return (long long)k * (k - 1) % MOD * (k - 2) % MOD;

	mtx_pow(G, G, d - 3);

	return (G[0][0] * k % MOD * (k - 1) % MOD * (k - 2) % MOD
		+ G[1][0] * k % MOD * (k - 1) % MOD) % MOD;
}

void solve_single(int n, int k)
{
	/* k * sum_(d|n) phi(n/d) ([[k-2, 1], [k-1, 0]]^d)_(00) */
	int d;
	long long ans = 0;

	for (d = 1; d * d < n; ++d)
		if (n % d == 0) {
			ans = (ans + phi(d) * magic(k - 1, n / d) % MOD) % MOD;
			ans = (ans + phi(n / d) * magic(k - 1, d) % MOD) % MOD;
		}

	if (d * d == n)
		ans = (ans + phi(d) * magic(k - 1, d) % MOD) % MOD;

	printf("%lld\n", ans * inv(n) % MOD * k % MOD);
}

void global_init(void)
{
	int i, j, k = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	for (i = 2; i < PMAX; ++i)
		if (!is_not_prime[i]) {
			prime[k++] = i;
			for (j = i + i; j < PMAX; j += i)
				is_not_prime[j] = 1;
		}
}

int main(void)
{
	int a, b;
	global_init();
	while (scanf("%d%d", &a, &b) != EOF)
		solve_single(a, b);
	return 0;
}
