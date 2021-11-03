#include <stdio.h>

int main(void)
{
	int q;

#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
#ifndef DEBUG
	freopen("a.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		printf("%d\n",
				n == 0 ? 0 :
				n == 1 ? 0 :
				n == 2 ? 0 :
				n == 3 ? 0 :
				n == 5 ? 0 :
				n == 7 ? 0 :
				n == 11 ? 0 :
				1
		      );
	}
	return 0;
}

/*
#include <stdlib.h>
#include <string.h>
void test(void)
{
	int i, j, k;
#define MAX 10000
	static int prime[MAX];
	static int is_prime[MAX];
	static int can_gen[MAX];
	int ptop = 0;
	memset(is_prime, 0xff, sizeof(is_prime));
	for (i = 2; i < MAX; ++i)
		if (is_prime[i]) {
			prime[ptop++] = i;
			for (j = i * i; j < MAX; j += i)
				is_prime[j] = 0;
		}
	for (i = 0; i < ptop; ++i)
		for (j = 0; j < ptop; ++j)
			if (prime[i] * prime[j] < MAX)
				can_gen[prime[i] * prime[j]] = 1;
	for (k = 0; k < 100; ++k)
	for (i = 0; i < MAX; ++i)
		for (j = 0; j < MAX; ++j)
			if (i + j < MAX)
				can_gen[i + j] |= can_gen[i] & can_gen[j];
	for (i = 0; i < MAX; ++i)
		if (!can_gen[i])
			printf("cant: %d\n", i);
#undef MAX
}
*/
