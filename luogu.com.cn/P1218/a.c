/*
ID:lindong6
PROG:sprime
LANG:C
*/

#include <stdio.h>
#include <math.h>

void read(void);
int N;

void dfs(int pos, int now);
int isprime(int x);

int main(void)
{
	read();
	dfs(0, 0);
	return 0;
}

void dfs(int pos, int now)
{
	if (isprime(now)) {
		if (pos == N) {
			printf("%d\n", now);
			return;
		}
	} else if (now == 0) {
		;
	} else {
		return ;
	}

	now *= 10;
	dfs(pos + 1, now + 1);
	dfs(pos + 1, now + 2);
	dfs(pos + 1, now + 3);
	dfs(pos + 1, now + 5);
	dfs(pos + 1, now + 7);
	dfs(pos + 1, now + 9);
}

int isprime(int now)
{
	int limit = sqrt(now) + 2;
	register int i;

	if (now == 0 || now == 1)
		return 0;
	if (now == 2)
		return 1;

	for (i = 2; i < limit; ++i)
		if (now % i == 0)
			return 0;
	return 1;
}

void read(void)
{
	scanf("%d", &N);
}
