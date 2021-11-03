#include <stdio.h>
#include <string.h>

int N, K;
int value[109], ans[109], anslen;

int dfs(int pos, int last);

int main(void)
{
	int i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &K);
	dfs(1, 1);
	for (i = 1; i <= K; ++i)
		printf("%d ", ans[i]);
	printf("\nMAX=%d\n", anslen);
	return 0;
}

int ok[100009];
int check(int num)
{
	int i, j;

	ok[0] = 0;
	for (i = 1; i <= value[num] * N; ++i)
		ok[i] = 100009;

	for (i = 1; i <= num; ++i)
		for (j = value[i]; j <= value[num] * N; ++j)
			if (ok[j - value[i]] + 1 < ok[j])
				ok[j] = ok[j - value[i]] + 1;
	for (i = 1; i <= value[num] * N; ++i)
		if (ok[i] > N)
			return i - 1;

	return value[num] * N;
}

int dfs(int pos, int last)
{
	int i, nowlength;
	if (pos == K + 1) {
		if (last > anslen) {
			memcpy(ans, value, sizeof(value));
			anslen = last;
		}
		return 0;
	}
	for (i = value[pos - 1] + 1; i <= last + 1; ++i) {
		value[pos] = i;
		nowlength = check(pos);
		dfs(pos + 1, nowlength);
	}
	return 0;
}
