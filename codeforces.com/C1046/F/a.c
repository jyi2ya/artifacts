#include <stdio.h>
#include <ctype.h>

#define MAX 200009

typedef long long ll;

ll a[MAX], x, f;
int N;

int readll(ll *ans);
void putll(ll x);

int main(void)
{
	int i;
	ll ans = 0, subpertrans;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) readll(a + i);
	readll(&x); readll(&f);
	subpertrans = x + f;

	for (i = 0; i < N; ++i)
		if (a[i] > x) {
			int res = a[i] - x;
			if (res < 0) {
				ans += f;
			} else {
				ans += (res / subpertrans + 1) * f;
			}
		}
	putll(ans); putchar('\n');
	return 0;
}

int readll(ll *ans)
{
	int ch , lt0 = 0;
	*ans = 0;
	while (!isdigit(ch = getchar()) && ch != '-' && ch != EOF);
	if (ch == EOF) return 0;
	else if (ch == '-') lt0 = 1;
	else *ans = ch - '0';
	while (isdigit(ch = getchar())) *ans = *ans * 10 + ch - '0';
	ungetc(ch, stdin);
	if (lt0) *ans = -*ans;
	return 1;
}

void putll(ll x)
{
	char buf[64], *top = buf;
	if (x == 0) putchar('0');
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	while (x) {
		*top++ = x % 10 + '0';
		x /= 10;
	}
	while (top != buf) putchar(*--top);
}
