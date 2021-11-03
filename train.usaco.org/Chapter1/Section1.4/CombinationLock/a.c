/*
ID:lindong6
PROG:combo
LANG:C
*/

#include <stdio.h>

int john[3], mas[3], N;

int abs(int x);
int check(int i, int j, int k);

int main(void)
{
	register int i, j, k;
	int ans = 0;

#ifndef LUOTIANYI
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
#endif

	scanf("%d", &N);
	scanf("%d%d%d", john + 0, john + 1, john + 2);
	scanf("%d%d%d", mas + 0, mas + 1, mas + 2);

	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			for (k = 1; k <= N; ++k)
				if (check(i, j, k)) {
					/*
					   printf("%d %d %d\n", i, j, k);
					   */
					++ans;
				}
	printf("%d\n", ans);

	return 0;
}

int abs(int x)
{
	return x > 0 ? x : -x;
}

int check(int i, int j, int k)
{
	if (
			(
			 (
			  abs(i - john[0]) <= 2 ||
			  abs(i - john[0] + N) <= 2 ||
			  abs(i - john[0] - N) <= 2
			 )
			 && 
			 (
			  abs(j - john[1]) <= 2 ||
			  abs(j - john[1] + N) <= 2 ||
			  abs(j - john[1] - N) <= 2
			 )
			 &&
			 (
			  abs(k - john[2]) <= 2 ||
			  abs(k - john[2] + N) <= 2 ||
			  abs(k - john[2] - N) <= 2)
			)
			||
			(
			 (
			  abs(i - mas[0]) <= 2 ||
			  abs(i - mas[0] + N) <= 2 ||
			  abs(i - mas[0] - N) <= 2
			 )
			 && 
			 (
			  abs(j - mas[1]) <= 2 ||
			  abs(j - mas[1] + N) <= 2 ||
			  abs(j - mas[1] - N) <= 2
			 )
			 &&
			 (
			  abs(k - mas[2]) <= 2 ||
			  abs(k - mas[2] + N) <= 2 ||
			  abs(k - mas[2] - N) <= 2)
			)
				)
				return 1;
	return 0;
}
