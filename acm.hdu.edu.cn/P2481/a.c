#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long MOD;

long long llmul(long long a, long long b)
{
	long long ans = 0;
	a = (a % MOD + MOD) % MOD;
	b = (b % MOD + MOD) % MOD;
	while (b) {
		if (b & 1)
			ans = (ans + a) % MOD;
		a = (a + a) % MOD;
		b /= 2;
	}
	return ans;
}

#define PRIME_LIMIT 1000000
int is_not_prime[PRIME_LIMIT];
int prime[PRIME_LIMIT];
void init(void)
{
	int i, j, k = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	for (i = 2; i < PRIME_LIMIT; ++i)
		if (!is_not_prime[i]) {
			prime[k++] = i;
			for (j = i + i; j < PRIME_LIMIT; j += i)
				is_not_prime[j] = 1;
		}
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

long long magic_correctness_test(int x)
{
	/*
	   T(n) = f(n) + g(n)
	   g(n) = 2 * (f(n) - f(n-1) - 1)
	   f(n) = 3 * f(n-1) - f(n-2)
	   */
	long long f1, f2, f3;
	long long g;
	int i;

	if (x == 1)
		return 1;
	if (x == 2)
		return 5;

	f1 = 3, f2 = 1;
	for (i = 3; i <= x; ++i) {
		f3 = (f1 * 3 - f2) % MOD;
		f2 = f1;
		f1 = f3;
	}
	g = 2 * (f1 - f2 - 1) % MOD;
	return (f1 + g) % MOD;
}

typedef long long mtx[2][2];

void mtx_mul(mtx c, mtx a, mtx b)
{
	int i, j, k;
	mtx r = { { 0, 0 }, { 0, 0 } };
	for (i = 0; i < 2; ++i)
		for (j = 0; j < 2; ++j)
			for (k = 0; k < 2; ++k)
				r[i][j] = (r[i][j] +
						llmul(a[i][k], b[k][j])) % MOD;
	memcpy(c, r, sizeof(mtx));
}

void prt_mtx(mtx x)
{
	int i, j;
	puts("=====");
	printf("%p\n", x);
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 2; ++j)
			printf("%lld ", x[i][j]);
		putchar('\n');
	}
}

long long magic(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 5;

	x -= 2;
	mtx t = {
		{ 3, 1 },
		{ -1, 0 }
	};
	mtx ans = {
		{ 1, 0 },
		{ 0, 1 }
	};

	while (x) {
		if (x & 1)
			mtx_mul(ans, ans, t);
		mtx_mul(t, t, t);
		x /= 2;
	}

	return (
			3 * ans[0][0] +
			ans[1][0] +
			2 * (
				3 * ans[0][0] +
				ans[1][0] -
				3 * ans[0][1] - ans[1][1]
			    ) % MOD
			- 1) % MOD;
}

int main(void)
{
	long long n, m;
	init();
	while (scanf("%lld%lld", &n, &m) != EOF) {
		int d;
		long long ans = 0;
		MOD = n * m;

		for (d = 1; d * d < n; ++d)
			if (n % d == 0) {
				ans = (ans + llmul(phi(n / d), magic(d))) % MOD;
				ans = (ans + llmul(phi(d), magic(n / d))) % MOD;
			}

		if (d * d == n)
			ans = (ans + llmul(phi(d), magic(d))) % MOD;

		printf("%lld\n", (ans / n) % m);
	}

	return 0;
}

/*
 * 题目大意：
 * 你有一个玩具。
 * 有 n + 1 个珠子，一个珠子排在正中间，其他 n 颗珠子成一个正 n 边形环绕在中间的
 * 珠子周围。
 * 周围的 n 个珠子中，相邻的用一条等长的边连接，每个珠子都与中间的珠子连一条边。
 * 在这个规则下，中间的珠子的度数为 n ，周围的珠子度数为 3 ，总共的边数为 2n
 * 现在想要从这个玩具中移除 n 条边，本质不同的移除方案数。
 *
 * 这个题目又是要求本质不同的方案数，很自然地就想到了 Burnside （反正是在做
 * Burnside 的套题不是 Burnside 就奇怪了）。
 *
 * 这个题目很有趣，别的题目都是在染色方案数，这个题目是要求去除 n 条边后成连通块
 * 的方案数。
 * 对于这个题，移除 n 条边，可以相当于给这 n 条边染色为白色；保留 n 条边，可以相
 * 当于给这 n 条边染成黑色。所有的黑色边要相互连通。
 *
 * n + 1 个节点，留下 n 条边，所有点连通，剩下的肯定是一棵树。
 *
 * （我好没用啊又想不下去了。去翻题解了。）
 *
 * 题解来源：http://www.acmsearch.com/article/show/5982
 *
 * > 素数筛选，求解欧拉函数,BurnSide引理,二分模拟乘法,递推的构造,矩阵二分求幂,
 * > 置换群,枚举...总之是一个不错的题目,基本把数论的基本知识全考察了一次.
 * 做这个题可真够赚的。
 *
 * > 如果a,b之间是断开的，如果与a直接相连的为k个(加上a自己)，那么显然这k个要与
 * > 其它的保持连通的，与中心必须有一条边，如果有多条边就形成环了，显然不满足生
 * > 成树。另外n-k为f[n-k]种，我们可以枚举k，则f[n]=sigma(i*f[n-i])  (n-1>=i>=0)
 * >
 * > 如果a,b是连在一起的，如果与a,b相连的为k个(包括a,b)，那么a,b是相邻的在这k个
 * > 位置选择就有k-1种，而这k个与中心相连的选择有k种，剩下的与这部分是分开的，则
 * > 为f[n-k]，所以可以枚举k，最终结果g[n]=sigma(i*(i-1)*f[n-i]) (n-1>=i>=2)
 *
 * 这两段是核心思路，可能是作者水平比较高，写的比较高深。有点不是很好懂。后面就
 * 都是对这两个式子的各种套路优化，相比这个思路就不是很重要了。所以要性感理解一
 * 下这两段话。
 *
 * 设整个图点集为 V ，中间的点为 c，选取外圈上的相邻的点 a 和 b ，b 在 a 的顺时
 * 针方向。
 * 当忽略中间的一个节点和其上连的边，只剩下周围的节点时，
 * 令 f(n) 为外圈有 n 个结点时，a, b 不连通的方案数。
 * 令 g(n) 为外圈有 n 个结点时，a, b 连通的方案数。
 * 令 T(n) 为外圈有 n 个结点时，总方案数。
 *
 * f(n) :
 * 设 a 所在的连通块为 A ，a 必然在连通块的端点处（因为 a 和 b 断开了啊）。
 * A 中有且仅有一个节点与 c 相连（如果多于一个，则存在环，整个图不可能是树，即不
 * 可能连通；如果少于一个，则 A 与 c 不连通）。换不同的结点与 c 相连，可得 A 的
 * 连边方案数为 1*|A| 种。
 * 令 B = C_V A （A 的补集），因为没有对 B 中连通块的限制，所以 B 中点连接的方案
 * 数等于 『外圈有 |B| 个节点时，图中连边的方案数』，也就是 f(|B|) 。
 * 因为整个图可以旋转，所以 A 的方位与方案数无关。只有 A 的大小与方案有关。枚举
 * A 的大小，综合 B 的方案，由乘法原理有：
 * f(n) = sum_(i=1)^n 1*i*f(n-i)
 * 规定 f(0) = 0 。
 *
 * g(n) :
 * 设 a, b 所在的连通块为 A ，a, b 可能在连通块的 k-1 个不同的地方。A 中有且仅有
 * 一个节点与 c 相连。换不同的结点与 c 相连，可得 A 的连边方案数为 (k-1)*|A|种。
 * 令 B = C_V A ，则 B 的方案数上面分析了，是 f(|B|) 种。
 * 一番操作后，得：
 * g(n) = sum_(i=1)^n (i-1)*i*f(n-i)
 *
 * T(n) :
 * 由加法原理：
 * T(n) = f(n) + g(n)
 *
 * 在这里，f()，g() 和 T() 已经出现了。以下是在优化计算的复杂度。
 *
 * 令 s(n) = sum_(i=1)^n f(i)
 * f(n) = sum_(i=1)^n 1*i*f(n-i)
 *   = sum_(i=1)^n i*f(n-i)
 *   = 1*f(n-1) + 2*f(n-2) + 3*f(n-3) + ... + n*f(n-n)
 *   = s(n-1) + 1*f(n-2) + 2*f(n-3) + ... + (n-1)*f(n-n)
 *   = s(n-1) + f(n-1) => s(n) = f(n+1) - f(n)
 *   = s(n-2) + f(n-1) + f(n-1)
 *   = f(n-1) - f(n-2) + f(n-1) + f(n-1)
 *   = 3f(n-1) - f(n-2);
 *
 * TODO 此处存疑。
 * 题解中说 f(0) = 1, f(1) = 1, f(2) = 3, f(3) = 8 ，从 f(3) 开始满足递推式。
 * 但是根据我的理解应该是 f(0) = 0, f(1) = 1, f(2) = 1, f(3) = 3，从 f(4) 开始
 * 满足递推式（肯定是题解错了怎么可能是我错了）。
 *
 * g(n) = sum_(i=1)^n (i-1)*i*f(n-i)
 *   = 1*2*f(n-2) + 2*3*f(n-3) + ... + n*(n-1)*f(n-n)
 * g(n-1) = sum_(i=1)^(n-1) (i-1)*i*f(n-1-i)
 *   = 1*2*f(n-3) + 2*3*f(n-4) + ... + (n-2)*(n-1)*f(n-n)
 * 错位相减（皮一下）
 * g(n) - g(n-1) = 2*f(n-2) + 4*f(n-3) + 6*f(n-4) + ... + 2*(n-1)*f(n-n)
 *   = 2(1*f(n-2) + 2*f(n-3) + ... + (n-1)*f(0)) 发现这里一团就是 f() 的式子！
 *   = 2*f(n-1)
 *
 * 所以
 * g(n) = 2 sum_(i=1)^(n-1) f(i)
 *   = 2(s(n-1) - f(0))
 *   = 2(f(n) - f(n-1) - 1)
 *
 * 发现 f() 的递推式有点可以矩阵优化的意味，所以构造一个矩阵 [[3, 1], [-1, 0]] 
 * 来使用矩阵乘法优化。g() 可以顺路求出。
 *
 * 最后：
 * 使用！Burnside 引理！
 * 『念念叨叨』一个有 n 个点的环旋转 k 个点时循环节的个数为 gcd(n,k)，所有循环节
 * 取出一个元素构成的神秘序列的长度为 gcd(n,k) ，方案数为 T(gcd(n,k)) 。因此答案
 * 为
 *   1/n sum_(i=1)^n T(gcd(n,k))
 * = 1/n sum_(d|n) sum_(i=1)^n [gcd(i,n) = d] * T(d)
 * = 1/n sum_(d|n) sum_(i=1)^(n/d) [gcd(i,n/d) = 1] * T(d)
 * = 1/n sum_(d|n) phi(n/d) * T(d)
 *
 * 然后就是代码实现了。
 */
