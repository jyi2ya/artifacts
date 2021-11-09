#include <stdio.h>

int N, L, S;
char buf[30009][209];

int is_similar(char *a, char *b)
{
	int i;
	int cnt = 0;
	for (i = 0; a[i]; ++i)
		if (a[i] != b[i])
			++cnt;
	return cnt == 1;
}

int main(void)
{
	int i, j;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d", &N, &L, &S);

	for (i = 0; i < N; ++i)
		scanf("%s", buf[i]);

	for (i = 0; i < N; ++i)
		for (j = i; j < N; ++j)
			if (is_similar(buf[i], buf[j]))
				++ans;

	printf("%d\n", ans);

	return 0;
}
