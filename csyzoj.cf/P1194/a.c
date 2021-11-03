#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

struct info {
	char *str;
} info[1000009];

int pos[1000009], id[1000009], want[1000009];

int cmp(const void *a, const void *b)
{
	return strcmp(info[*(int *)a].str, info[*(int *)b].str);
}

struct {
	int a, b;
} O[1000009];
int Oc = 0;

int main(void)
{
	int i;
	int n;
	static char buf[20000009], *ptr = buf;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", ptr);
		info[i].str = ptr;
		pos[i] = id[i] = want[i] = i;
		ptr += strlen(info[i].str) + 1;
	}
	qsort(want, n, sizeof(*want), cmp);
	for (i = 0; i < n; ++i)
		if (id[i] != want[i]) {
			O[Oc].a = i + 1;
			O[Oc].b = pos[want[i]] + 1;
			++Oc;
			swap(&pos[id[i]], &pos[want[i]]);
			swap(&id[i], &id[pos[id[i]]]);
		}

	printf("%d\n", Oc);
	for (i = 0; i < Oc; ++i)
		printf("%d %d\n", O[i].a, O[i].b);
	/*
	for (i = 0; i < n; ++i)
		printf("%s\n", info[want[i]].str);
		*/
	return 0;
}
