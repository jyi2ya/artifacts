#include <stdio.h>
#include <string.h>

long long F[1000009];

void init_single(void)
{
	memset(F, 0, sizeof(F));
}

int solve_single(int A, int B, int d)
{
	int i, j;

	if (A < B) {
		int t = A;
		A = B;
		B = t;
	}

	for (i = A; i >= 1; --i) {
		F[i] = (long long)(A / i) * (B / i);
		for (j = i + i; j <= A; j += i)
			F[i] -= F[j];
	}
	
	printf("%lld\n", F[d]);

	return 0;
}

int main(void)
{
	int A, B, d;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	while (scanf("%d%d%d", &A, &B, &d) != EOF) {
		init_single();
		solve_single(A, B, d);
	}

	return 0;
}
