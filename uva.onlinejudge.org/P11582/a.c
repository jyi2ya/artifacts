#include <stdio.h>

typedef unsigned long long ull;

ull a, b, n;

int getull(ull *ans);
void putull(ull x);
ull fastpow(ull a, ull b, ull mod);
void init(void);

int ans[500009], *start[1009], top = 0, cycle[1009];

void test_fastpow(void);

int main(void)
{
	int T;
	init();
	scanf("%d", &T);
	while (T--) {
		getull(&a); getull(&b); getull(&n);
		if (a == 0 || n == 1) {
			puts("0");
		} else {
			a = fastpow(a, b, cycle[n]);
			printf("%d\n", start[n][a]);
		}
	}
	return 0;
}

void init(void)
{
	int i, j;
	top = 0;
	for (i = 2; i < 1003; ++i) {
		start[i] = ans + top;
		start[i][0] = 0;
		start[i][1] = 1;
		for (j = 2; ; ++j) {
			start[i][j] = (start[i][j - 1] + start[i][j - 2]) % i;
			if (start[i][j - 1] == 0 && start[i][j] == 1)
				break;
		}
		cycle[i] = j - 1;
		top += cycle[i] + 3;
	}
}

/* fast_pow {{{ */
ull fastpow(ull a, ull b, ull mod)
{
	ull ans = 1;
	a %= mod;
	while (b) {
		if (b & 1) ans = a % mod * ans % mod;
		a = a % mod * a % mod;
		b /= 2;
	}
	return ans % mod;
}
ull slowpow(ull a, ull b, ull mod)
{
	ull ans = 1;
	while (b--) ans = ans * a % mod;
	return ans;
}
#include <time.h>
#include <stdlib.h>
void test_fastpow(void)
{
	int a, b, c, cnt = 0;
	srand(time(NULL));
	do {
		a = rand() % 1000 + 1;
		b = rand() % 1000 + 1;
		c = rand() % 1009 + 1;
		printf("testing: pow: testdata%d, a = %d, b = %d, c = %d\n", cnt, a, b, c);
		++cnt;
	} while (fastpow(a, b, c) == slowpow(a, b, c));
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("slow = %d, fast = %d\n", (int)slowpow(a, b, c), (int)fastpow(a, b, c));
	exit(0);
}
/* }}} */
/* fastio {{{ */
#include <ctype.h>
int getull(ull *ans)
{
	int ch;
	*ans = 0;
	while (!isdigit(ch = getchar()) && ch != EOF) ;
	if (ch == EOF) return 0;
	else *ans = ch -'0';
	while (isdigit(ch = getchar())) *ans = *ans * 10 + ch - '0';
	return 1;
}
void putull(ull x)
{
	char buf[64], *top = buf;
	while (x) {
		*top++ = x % 10 + '0';
		x /= 10;
	}
	while (top != buf) putchar(*--top);
}
/* }}} */
