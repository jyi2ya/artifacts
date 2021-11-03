#include <stdio.h>
#include <string.h>
#include <math.h>

#define WIDTH 100009
#define BASE 10000000
#define FORMAT "%07d"

int P[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
	61, 67, 71, 73, 79, 83, 89, 97 };

int T[100], C[100], D;
double A;
int E[WIDTH], Etop;
double L[sizeof(P) / sizeof(int)];

void dfs(int p, int n, double a);

int main(void)
{
	int n, i, j, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);

	for (i = 0; i < sizeof(P) / sizeof(int); ++i)
		L[i] = log(P[i]);

	A = 100000000000000;
	dfs(0, n, 1);

	E[0] = 1;
	Etop = 1;
	for (i = 0; i < D; ++i) {
		--T[i];
		for (j = 0; j < T[i]; ++j) {
			for (k = 0; k < Etop; ++k)
				E[k] *= P[i];
			for (k = 0; k < Etop; ++k)
				if (E[k] >= BASE) {
					E[k + 1] += E[k] / BASE;
					E[k] %= BASE;
				}
			while (E[Etop]) {
				E[Etop + 1] += E[Etop] / BASE;
				E[Etop++] %= BASE;
			}
		}
	}

	if (Etop == 0) {
		putchar('0');
	} else {
		printf("%d", E[Etop - 1]);
		for (i = Etop - 2; i >= 0; --i)
			printf(FORMAT, E[i]);
	}

	putchar('\n');
	return 0;
}

void dfs(int p, int n, double a)
{
	int i;

	if (p >= 16 || a > A)
		return;

	if (n == 1) {
		if (a < A) {
			A = a;
			D = p;
			memcpy(T, C, sizeof(C));
		}
		return;
	}

	for (i = 1; i * i <= n; ++i)
		if (n % i == 0) {
			if (i != 1) {
				C[p] = i;
				dfs(p + 1, n / i, a + (i - 1) * L[p]);
			}
			if (i * i != n) {
				C[p] = n / i;
				dfs(p + 1, i, a + (n / i - 1) * L[p]);
			}
			C[p] = 0;
		}
}
