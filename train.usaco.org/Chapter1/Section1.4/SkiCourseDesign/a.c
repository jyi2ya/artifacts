/*
ID:lindong6
PROG:skidesign
LANG:C
*/

#include <stdio.h>
#include <limits.h>

void read(void);
int min(int a, int b);

int a[1009], N;

int main(void)
{
	int low, high, final_ans = INT_MAX;

	read();
	for (low = 0; low < 100; ++low) {
		int local_ans = 0;
		register int i;

		high = low + 17;
		for (i = 0; i < N; ++i)
			if (a[i] < low || a[i] > high)
				local_ans += min(
						(a[i] - low) * (a[i] - low),
						(a[i] - high) * (a[i] - high)
						);
		final_ans = min(final_ans, local_ans);
	}

	printf("%d\n", final_ans);
	return 0;
}

void read(void)
{
	register int i;

	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);

	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", a + i);
}

int min(int p, int q)
{
	return p > q ? q : p;
}
