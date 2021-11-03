#include <stdio.h>
#include <stdlib.h>

int hash(const char *str);
int cmp(const void *a, const void *b);

int hsh[100009];
char buf[200009];

int main(void)
{
	int N, a = 1, i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%s", buf);
		hsh[i] = hash(buf);
	}
	qsort(hsh, N, sizeof(int), cmp);
	for (i = 1; i < N; ++i)
		if (hsh[i] != hsh[i - 1])
			++a;
	printf("%d\n", a);
	return 0;
}

int hash(const char *str)
{
	unsigned int a = 5381;
	while (*str != '\0')
		a = a * 33 + *str++;
	return a & 0x7fffffff;
}

int cmp(const void *a, const void *b)
{
	return (*(int*)a) - (*(int*)b);
}
