#include <stdio.h>
#include <string.h>

int isprime[10000009],prime[700000];

void sieve_prime(int N);

int main(void)
{
	int N,M;
	scanf("%d%d", &N, &M);
	sieve_prime(N);
	while (M--) {
		int x;
		scanf("%d", &x);
		if (isprime[x]) puts("Yes");
		else puts("No");
	}
	return 0;
}

void sieve_prime(int N)
{
	int i, primtop = 0;
	memset(isprime, 0xff, sizeof(isprime));
	isprime[0] = 0;
	isprime[1] = 0;

	for (i = 2; i <= N; ++i) {
		int j;
		if (isprime[i]) prime[primtop++] = i;
		for (j = 0; j < primtop && prime[j] * i <= N; ++j) {
			isprime[i * prime[j]] = 0;
			if (i % prime[j] == 0) break;
		}
	}
}
