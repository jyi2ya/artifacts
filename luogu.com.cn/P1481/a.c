#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[2009][80];
int N;
int ans[2009];

int cmp(const void *a, const void *b);
int max(int a, int b);

int main(void)
{
	int i, j, final = 0;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%s", word[i]);
	qsort(word, N, sizeof(word[0]), cmp);
	ans[0] = 0;
	for (i = 1; i < N; ++i)
		for (j = 0; j < i; ++j)
			if (strncmp(word[i], word[j], strlen(word[j])) == 0)
				ans[i] = max(ans[i], ans[j] + 1);
	for (i = 0; i < N; ++i)
		final = max(final, ans[i]);
	printf("%d\n", final + 1);
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int cmp(const void *a, const void *b)
{
	return (int)strlen((char*)a) - (int)strlen((char*)b);
}
