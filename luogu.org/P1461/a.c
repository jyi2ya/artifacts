/*
ID:lindong6
PROG:hamming
LANG:C
*/

#include <stdio.h>

typedef unsigned int uint;

int hamming(uint a, uint b);
int dfs(int pos, uint last);
void read(void);
void prtseq(void);

int N, B, D;
uint num[100];

int main(void)
{
	register int i;

	read();
	for (num[0] = 0; num[0] < (1 << B); ++num[0])
		if (dfs(1, num[0]))
			break;
	for (i = 0; i < N; ++i) {
		if ((i + 1) % 10 == 0 && i != N - 1) {
			printf("%u\n", num[i]);
		} else if (i == N - 1) {
			printf("%u", num[i]);
		} else {
			printf("%u ", num[i]);
		}
	}
	putchar('\n');
	return 0;
}

int dfs(int pos, uint last)
{
	if (pos == N)
		return 1;
	for (++last; last < (1 << B); ++last) {
		int i, nextloop = 0;
		for (i = 0; i < pos; ++i)
			if (hamming(last, num[i]) < D) {
				nextloop = 1;
				break;
			}
		if (nextloop)
			continue;
		num[pos] = last;
		if (dfs(pos + 1, last))
			return 1;
		num[pos] = 0x66ccff;
	}
	return 0;
}

void read(void)
{
	scanf("%d%d%d", &N, &B, &D);
}

int hamming(uint a, uint b)
{
	register int i;
	int ans = 0;
	for (i = 0; i < B; ++i)
		if (((a >> i) & 1) != ((b >> i) & 1))
			++ans;
	return ans;
}

void prtseq(void)
{
	register int i;
	for (i = 0; i < N; ++i)
		printf("%u ", num[i]);
	putchar('\n');
}
