#include <stdio.h>

char buf[100009];

int max(int x1, int x2)
{
	return x1 > x2 ? x1 : x2;
}

int is_palin(int l, int r)
{
	while (l < r) {
		if (buf[l] != buf[r])
			return 0;
		++l;
		--r;
	}
	return 1;
}

int main(void)
{
	int i, j, k;
	int ans = 0;

	freopen("in", "r", stdin);

	scanf("%s", buf);

	for (i = 0; buf[i]; ++i)
		for (j = i; buf[j]; ++j)
			for (k = j + 1; buf[k]; ++k)
				if (is_palin(i, j) && is_palin(j + 1, k))
					ans = max(ans, k - i + 1);

	printf("%d\n", ans);

	return 0;
}
