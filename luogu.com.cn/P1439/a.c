#include <stdio.h>

int main(void)
{
	static int a[1000009];
	static int b[1000009];
	static int p[1000009];
	static int v[1000009];
	int top = 0;
	int n;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	for (i = 1; i <= n; ++i)
		p[b[i]] = i;
	for (i = 1; i <= n; ++i)
		a[i] = p[a[i]];
	for (i = 1; i <= n; ++i) {
		int l = 0, r = top, m;
		while (l < r) {
			m = l + (r - l) / 2;
			if (v[m] < a[i])
				l = m + 1;
			else
				r = m;
		}
		if (l == top)
			v[top++] = a[i];
		else if (v[l] > a[i])
			v[l] = a[i];
	}
	printf("%d\n", top);
	return 0;
}
