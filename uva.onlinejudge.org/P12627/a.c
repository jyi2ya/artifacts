#include <stdio.h>

int ans[32];
unsigned long long solve(int k, int a, int b);
void putull(unsigned long long x);
void pretreat(void);

int main(void)
{
	int T, i;
	pretreat();
	scanf("%d", &T);
	for (i = 1; i <= T; ++i) {
		int k, a, b;
		scanf("%d%d%d", &k, &a, &b);
		printf("Case %d: ", i);
		putull(solve(k, a, b));
		putchar('\n');
	}
	return 0;
}

void putull(unsigned long long x)
{
	char buf[64], *top = buf;
	if (x == 0) putchar('0');
	while (x) {
		*top++ = x % 10 + '0';
		x /= 10;
	}
	while (top != buf) putchar(*--top);
}

unsigned long long solve(int k, int a, int b)
{
	int mid = 1 << (k - 1);
	if (a == 1 && b == (1 << k)) return ans[k];
	if (k == 0) return 1;
	if (mid >= a) {
		if (b <= mid) {
			return solve(k - 1, a, b) * 2;
		} else {
			return 
				solve(k - 1, a, mid) * 2 +
				solve(k - 1, 1, b - mid);
		}
	} else {
		return
			solve(k - 1, a - mid, b - mid);
	}
	return 0;
}

void pretreat(void)
{
	int i;
	ans[0] = 1;
	for (i = 1; i < 32; ++i) ans[i] = ans[i - 1] * 3;
}
