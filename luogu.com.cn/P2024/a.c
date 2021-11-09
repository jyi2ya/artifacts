#include <stdio.h>
#include <string.h>

int ufs[150009];

int ufs_find(int i)
{
	return (ufs[i] == i ? i : (ufs[i] = ufs_find(ufs[i])));
}

int ufs_cnctd(int a, int b)
{
	return ufs_find(a) == ufs_find(b);
}

void ufs_cnct(int a, int b)
{
	ufs[ufs_find(a)] = ufs_find(b);
}

int main(void)
{
	int i;
	int n, m;
	int cnt = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n * 3; ++i)
		ufs[i] = i;

	while (m--) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);
		if (a > n || b > n || a < 1 || b < 1) {
			++cnt;
			continue;
		}
		if (op == 1) {
			if (ufs_cnctd(a, b))
				continue;
			if (ufs_cnctd(a + n, b) || ufs_cnctd(a, b + n)) {
				++cnt;
				continue;
			}
			ufs_cnct(a, b);
			ufs_cnct(a + n, b + n);
			ufs_cnct(a + n + n, b + n + n);
		} else {
			if (ufs_cnctd(a, b) || ufs_cnctd(a, b + n)) {
				++cnt;
				continue;
			}
			ufs_cnct(a + n, b);
			ufs_cnct(a + n + n, b + n);
			ufs_cnct(a, b + n + n);
		}
	}

	printf("%d\n", cnt);

#ifdef DEBUG
	fclose(stdin);
#endif
	return 0;
}
