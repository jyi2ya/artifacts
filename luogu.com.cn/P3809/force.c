#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S[1000009];
int len;
int cmp(const void *a, const void *b)
{
	return strcmp(S + *(int*)a - 1, S + *(int*)b - 1);
}

int od[1000009];
int main(void)
{
	int i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%s", S);
	for (i = 1; S[i - 1]; ++i)
		od[i] = i;
	len = i - 1;
	qsort(od + 1, len, sizeof(int), cmp);
	for (i = 1; i <= len; ++i)
		printf("%d ", od[i]);
	putchar('\n');
	return 0;
}
