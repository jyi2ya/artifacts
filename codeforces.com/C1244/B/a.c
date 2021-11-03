#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int T;
	static char avl[1009];
	scanf("%d", &T);
	while (T--) {
		int n;
		int ans1, ans2;
		int i;
		scanf("%d%s", &n, avl);
		for (i = n - 1; i >= 0; --i)
			if (avl[i] == '1')
				break;
		ans1 = max(n, (i + 1) * 2);
		for (i = 0; i < n; ++i)
			if (avl[i] == '1')
				break;
		ans2 = max(n, (n - i) * 2);
		printf("%d\n", max(ans1, ans2));
	}
	return 0;
}
