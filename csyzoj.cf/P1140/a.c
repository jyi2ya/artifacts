#include <stdio.h>

int main(void)
{
	int n;
	int i;
	static int seq[1000009];
	static int las[1000009];
	int top = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &seq[n + i]);
	for (i = 0; i < n; ++i)
		seq[i] = seq[n * 2 - i - 1];
	n *= 2;

	for (i = 0; i < n; ++i) {
		int l, r, m;
		l = 0, r = top;
		while (l < r) {
			m = l + (r - l) / 2;
			if (las[m] < seq[i])
				l = m + 1;
			else
				r = m;
		}
		if (l == top)
			las[top++] = seq[i];
		else
			las[l] = seq[i];
	}

	printf("%d\n", top);

	return 0;
}
