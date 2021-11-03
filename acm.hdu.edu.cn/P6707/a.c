#include <stdio.h>
#include <string.h>

int val[100009];
int vis[100009];
int buf[100009];

int main(void)
{
	int n, m;
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	for (i = m - 1; i >= 0; --i) {
		int x;
		scanf("%d", &x);
		buf[i] = x;
	}
	for (i = 0; i < m; ++i)
		if (!vis[buf[i]]) {
			printf("%d ", buf[i]);
			vis[buf[i]] = 1;
		}
	for (i = 0; i < n; ++i)
		if (!vis[val[i]]) {
			printf("%d ", val[i]);
		}
	return 0;
}
