#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MOD 1000000007ULL

typedef long long ll;
typedef long long matrix[109][109];

ll getll(void);
void putll(ll x);

matrix ans, base;
ll n, k;

void mul(matrix* a, matrix *b);
void read(void);
void power(ll index);
void putmatrix(matrix* mtx);

int main(void)
{
	read();
	while (k) {
		if (k & 1) mul(&ans, &base);
		mul(&base, &base);
		k /= 2;
	}
	putmatrix(&ans);
	return 0;
}

void mul(matrix *a, matrix *b)
{
	int i, j, k;
	matrix tmp;
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			for (k = 0; k < n; ++k) {
				tmp[i][j] += (*a)[i][k] * (*b)[k][j] % MOD;
				tmp[i][j] %= MOD;
			}
	memcpy(a, &tmp, sizeof(tmp));
}

void putmatrix(matrix *mtx)
{
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			putll((*mtx)[i][j]);
			putchar(' ');
		}
		putchar('\n');
	}
}
void read(void)
{
	ll i, j;
	n = getll();
	k = getll();
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			base[i][j] = getll();
	for (i = 0; i < n; ++i) ans[i][i] = 1LL;
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

ll getll(void)
{
	ll ans = 0;
	int ch, lt0 = 0;
	while (!isdigit(ch = getchar()) && ch != '-');
	if (ch == '-') lt0 = 1;
	else ans = ch - '0';

	while (isdigit(ch = getchar())) ans = ans * 10 + ch - '0';
	if (lt0) ans = -ans;

	return ans;
}
