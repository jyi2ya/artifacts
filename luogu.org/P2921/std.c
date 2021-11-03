#include <stdio.h>
#include <string.h>

int nxt[100009];
int n;
int vis[100009];

int main(void)
{
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", nxt + i);

	for (i = 1; i <= n; ++i) {
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		for (j = i; !vis[j]; j = nxt[j]) {
			++cnt;
			vis[j] = 1;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
