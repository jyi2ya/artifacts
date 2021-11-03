#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b);

char buf[1009][39], tmp[39];

int main(void)
{
	int n;
	while (scanf("%d", &n) && n) {
		int i, a, b;
		for (i = 0; i < n; ++i) scanf("%s", buf[i]);
		qsort(buf, n, sizeof(buf[0]), cmp);
		a = n / 2 - 1; b = a + 1;
		for (i = 0; buf[a][i] == buf[b][i] && buf[a][i] != '\0' && buf[b][i] != '\0'; ++i)
			tmp[i] = buf[a][i];
		tmp[i] = '\0';
		if (strcmp(tmp, buf[b]) < 0 && strcmp(tmp, buf[a]) >= 0) goto OK;
		for (; ; ++i) {
			int j;
			for (j = 0; j < 26; ++j) {
				tmp[i] = j + 'A';
				tmp[i + 1] = '\0';
				if (strcmp(tmp, buf[b]) < 0 && strcmp(tmp, buf[a]) >= 0) goto OK;
			}
			tmp[i] = buf[a][i];
		}
OK:
		puts(tmp);
	}
	return 0;
}

int cmp(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}
