/*
 * 求长为 n ，删去任意一个连续子串都得不到串 s 的小写字母串的个数。
 *
 * 考虑求出 “可以通过删除一个子串得到 s ” 的串的个数。一个串满足以上条件，一定是
 * 把 s 从某处断开，向断点插入若干字符。设 n 串长为 ln ， s 串长为 ls 。插入的字
 * 符数为 ln - ls 。方案数为 26^(ln - ls) 。但是可能会出现重复。例如当 s =
 * "abcabc" ， ln = 7 时，断开 s 为 "abc" ， "abc" 并插入 "a" 与 断开 s 为
 * "abca" ， "bc" 并插入 "a" 得到的串是一样的，都是 "abcaabc" 。所以我们人为规定
 * 插入的串的首字母不等于 s 串中插入点的下一个字母，就可以避免重复计算。
 *
 * 加入这个规定后，一个插入点的方案数为 25 * 26^(ln - ls - 1) ， s 上共有 ls
 * 个位置可以这样插入字串，最右端的位置因为不存在 “插入点的下一个字母” ，所以有
 * 26^(ln - ls) 种方案。总数为 ls * 25 * 26^(ln - ls - 1) + 26^(ln - ls) 。
 *
 * 需要特判 ln = ls 的情况。此时总数为 1 （总不可能算个 26^(-1) 出来吧……）。
 *
 * 最终答案需要用 26^ln 减一下。
 */

#include <stdio.h>
#include <string.h>

#define MOD (998244353LL)

long long llpow(long long a, long long x)
{
	long long r = 1;
	while (x) {
		if (x & 1)
			r = r * a % MOD;
		a = a * a % MOD;
		x /= 2;
	}
	return r;
}

int main(void)
{
	long long ln;
	long long ls;
	static char buf[1000009];

#ifndef ONLINE_JUDGE
	freopen("magic.in", "r", stdin);
#ifndef DEBUG
	freopen("magic.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%lld%s", &ln, buf);
	ls = strlen(buf);
	if (ln == ls)
		printf("%lld\n", (llpow(26, ln) - 1 + MOD) % MOD);
	else
		printf("%lld\n",
		       ((llpow(26, ln) -
			 (ls * 25 * llpow(26, ln - ls - 1) % MOD +
			  llpow(26, ln - ls))) % MOD + MOD) % MOD);
	return 0;
}
