#include <stdio.h>
#include <stdlib.h>

unsigned int elfhash(const char *str);
unsigned int hash_value[12000];

int cmp(const void *a, const void *b)
{
	return *((unsigned int*)a) - *((unsigned int*)b);
}

int main(void)
{
	int i, n, ans = 0;
	char str_buffer[5009];
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", str_buffer);
		hash_value[i] = elfhash(str_buffer);
	}
	qsort(hash_value, n, sizeof(int), cmp);
	for (i = 1; i < n; ++i)
		if (hash_value[i] != hash_value[i - 1])
			++ans;
	printf("%d\n", ans + 1);
	return 0;
}

unsigned int elfhash(const char *str)
{
	unsigned int hash = 0, x;
	while (*str != '\0') {
		hash = (hash << 4) + *str;
		if ((x = hash & 0xf000000)) {
			hash ^= x >> 24;
			hash &= 0x0fffffff;
		}
		++str;
	}
	return hash;
}
