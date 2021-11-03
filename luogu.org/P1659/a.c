#include <stdio.h>

#define MOD 19930726

long long min(long long a, long long b);
long long palindrome(const char *str, long long *manacher);
long long lpow(long long a, long long b);

long long num[5000009], mc[5000009];
char input_str[5000009], buf[5000009];

int main(void)
{
	long long len, ans = 1, i, K, n;

	scanf("%lld%lld%s", &n, &K, input_str);

	len = palindrome(input_str, mc);

	for (i = 0; i < len; ++i)
		if (mc[i] - 1 > 0)
			++num[mc[i] - 1];

	for (i = 1000008; i >= 1; --i) {
		if (i & 1) {
			num[i] += num[i + 2];
			if (num[i] > K) {
				ans = ans * lpow(i, K) % MOD;
				K = 0;
				break;
			} else {
				ans = ans * lpow(i, num[i]) % MOD;
				K -= num[i];
			}
		}
	}

	if (K)
		ans = -1;
	printf("%lld\n", ans);
	return 0;
}

long long lpow(long long a, long long b)
{
	long long ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}

long long palindrome(const char *str, long long *manacher)
{
	long long top = 0, r, i, m, l;

	buf[top++] = '`';
	while (*str) {
		buf[top++] = *str++;
		buf[top++] = '`';
	}
	buf[top++] = '\0';

	m = 0;
	r = 0;
	manacher[0] = 1;

	for (i = 1; buf[i] != '\0'; ++i) {
		for (
				l = (i > r) ? 1 : min(manacher[m * 2 - i], r - i);
				i - l >= 0 && buf[i - l] == buf[i + l];
				++l
		    );
		manacher[i] = l;
		if (i + l > r) {
			r = i + l;
			m = i;
		}
	}
	/*
	   for (i = 0; buf[i] != '\0'; ++i)
	   printf("%d ", manacher[i]);
	   putchar('\n');
	   for (i = 0; buf[i] != '\0'; ++i)
	   printf("%c ", buf[i]);
	   putchar('\n');
	 */
	return i;
}

long long min(long long a, long long b)
{
	return a < b ? a : b;
}
