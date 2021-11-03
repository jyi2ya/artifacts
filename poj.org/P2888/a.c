/*
 * 简要题意：
 * n 个珠子连成一条项链，有 m 种不同颜色，有 k 对颜色不能放在相邻位置。
 * 求本质不同的项链数目（不能翻转），模 9973 输出。
 * n in [1, 10^9], gcd(n, 9973) = 1, m in [1, 10], k in [1, m(m-1)/2]
 *
 * 粗略一看，好像是 Polya 的题。但是题目有限制说『一些特定的颜色不能放在一起』，
 * 这就有一些麻烦。
 *
 * 可以先试试用 Burnside 做。
 *
 * 想了半天没有想到什么头绪，于是看看题解。发现这一个题是 Burnside + 矩阵乘法 +
 * 欧拉函数 …… 怪不得没想到什么东西。
 *
 * 首先是在这个题目中新学到的东西：邻接矩阵的 n 次方的意义。
 *
 * 一个邻接矩阵 A ，其中 a_(ij) 表示 i 走到 j 的方案数。 a_(ij) 为 0 则表示 i 和
 * j 没有边直接相连；a_(ij) 为 1 则表示 i 和 j 有边直接相连。
 *
 * 那么 B = A^k ，b_(ij) 的意义为 i 走 k 步到 j 的方案数（不会证明，是手模的，但
 * 是猜矩阵乘法和 Floyd 那么像应该有什么关系）。
 *
 * 摘抄一下一个博客中的重要段落：
 *
 * from: http://www.cppblog.com/ArefaElvis/archive/2010/10/10/129269.html
 * > 假设一个长度为 L 的序列的合法表示为 a_1, a_2, ……, a_L
 * > 那么 (a_1, a_2)(a_2, a_3) , …… ，(a_(L-1), a_L), (a_L, a_1) 必定都为 1 
 * > 所以令 g_(ai aj) = 1 表示 (a_i, a_j) 为合法对，
 * > g_(ai aj) = 0 表示 (a_i, a_j) 为非法对。
 * > 那么以 a_1 开头的合法序列为 k 个那么必定存在且仅存在 k 个不同的序列
 * > { b_1, b_2, b_3, b_4, ……, b_(L-1) }
 * > 满足 g_(a_1 b_1) * g_(b_1 b_2) * …… g_(b_(L-2) b(L-1)) * g_(b(L-1) a1) = 1 
 * > 这样很显然就是矩阵 G^L 中 g_(a1 a1) 的值。
 *
 * 简而言之：
 * 把『可以放置相邻的珠子』看做一条无向边，那么合法的长为 L 的序列个数为
 * 『从 a_1 走 L 步到 a_1 的方案数』，即『邻接矩阵的 L 次方的 a_(11) 的值』。
 *
 * 众所周知，在项链类题目中转动 i 个珠子时循环节序列个数为 gcd(n, i)，长度为 
 * n / gcd(n, i) 。借助这个博客的思路，可以使用矩阵进行优化。
 *
 * 公式 (Burnside) ：
 *   1/n * sum_(i=1)^n (旋转 i 时合法的不动点个数)
 * = 1/n * sum_(i=1)^n sum_(j=1)^m (以 j 为第一个珠子，长为 gcd(n, i) 的合法序
 *   列个数)
 * = 1/n * sum_(i=1)^n sum_(j=1)^m (G^gcd(n,i))_(jj)
 * = 1/n * sum_(d|n) (sum_(i=1)^n [gcd(i,n) = d]) * (sum_(j=1)^m (G^d)_(jj))
 * = 1/n * sum_(d|n) (sum_(i=1)^n [gcd(i/d,n/d) = 1]) * (sum_(j=1)^m (G^d)_(jj))
 * = 1/n * sum_(d|n) (sum_(i=1)^n/d [gcd(i,n/d) = 1]) * (sum_(j=1)^m (G^d)_(jj))
 * = 1/n * sum_(d|n) phi(n/d) * (sum_(j=1)^m (G^d)_(jj))
 */

#include <stdio.h>
#include <string.h>

#define MOD (9973)

#define PRIME_TABLE_MAX (1000000)
int prime[PRIME_TABLE_MAX];
int is_not_prime[PRIME_TABLE_MAX];

void sieve(void)
{
	int i, j, k = 0;
	for (i = 2; i < PRIME_TABLE_MAX; ++i)
		if (!is_not_prime[i]) {
			prime[k++] = i;
			for (j = i + i; j < PRIME_TABLE_MAX; j += i)
				is_not_prime[i] = 1;
		}
}

int phi(int x)
{
	int ans = x;
	int i;
	for (i = 0; prime[i] * prime[i] <= x; ++i) {
		if (x % prime[i] == 0) {
			ans -= ans / prime[i];
			while (x % prime[i] == 0)
				x /= prime[i];
			if (x == 1)
				break;
		}
	}

	if (x > 1)
		ans -= ans / x;

	return ans % MOD;
}

typedef int mtx[20][20];
int m;

mtx* mtx_mul(mtx *d, mtx *s1, mtx *s2)
{
	mtx t_base, *t = &t_base;
	int i, j, k;
	memset(t, 0, sizeof(mtx));
	for (i = 1; i <= m; ++i)
		for (j = 1; j <= m; ++j) {
			for (k = 1; k <= m; ++k)
				(*t)[i][j] += (*s1)[i][k] * (*s2)[k][j];
			(*t)[i][j] %= MOD;
		}
	return memcpy(d, t, sizeof(mtx));
}

int magic(mtx *G, int d)
{
	mtx t, ans;
	int ians = 0;
	int i;

	memcpy(&t, G, sizeof(mtx));
	memcpy(&ans, G, sizeof(mtx));
	--d;

	if (d < 0)
		d = 0;

	while (d) {
		if (d & 1)
			mtx_mul(&ans, &ans, &t);
		mtx_mul(&t, &t, &t);
		d /= 2;
	}

	for (i = 1; i <= m; ++i)
		ians = (ians + ans[i][i]) % MOD;

	return ians;
}

void exgcd(int a, int b, int *x, int *y)
{
	if (b) {
		exgcd(b, a % b, y, x);
		*y -= (a / b) * *x;
	} else {
		*x = 1;
		*y = 0;
	}
}

int inv(int a)
{
	int x, y;
	exgcd(a, MOD, &x, &y);
	return (x % MOD + MOD) % MOD;
}

int main(void)
{
	int T;

	sieve();

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &T);

	while (T--) {
		int n, k;
		int i, j;
		int ans = 0;
		mtx G;

		scanf("%d%d%d", &n, &m, &k);
		for (i = 1; i <= m; ++i)
			for (j = 1; j <= m; ++j)
				G[i][j] = 1;

		while (k--) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u][v] = G[v][u] = 0;
		}

		/* 1/n * sum_(d|n) phi(n/d) * (sum_(j=1)^m (G^d)_(jj)) */

		for (i = 1; i * i <= n; ++i)
			if (n % i == 0) {
				ans = (ans + phi(n / i) * magic(&G, i) % MOD)
					% MOD;
				if (i * i != n)
					ans = (ans + phi(i) * magic(&G, n / i)
							% MOD) % MOD;
			}

		printf("%d\n", ans * inv(n) % MOD);
	}

	return 0;
}
