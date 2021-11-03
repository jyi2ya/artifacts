#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int G[255][255], D[255], vis[255][255], tp, n;
char B[266 * 255];

void dfs(int p)
{
	int i;
#ifdef DEBUG
	printf("%c", p);
#endif
	for (i = 0; i < 255; ++i)
		if (G[p][i] && !vis[p][i]) {
			vis[p][i] = 1;
			vis[i][p] = 1;
			dfs(i);
		}
	B[tp++] = p;
}

int main(void)
{
	int i, cnt = 0, s;
	char buf[4];
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", buf);
		++D[(int)buf[0]];
		++D[(int)buf[1]];
		G[(int)buf[0]][(int)buf[1]] = 1;
		G[(int)buf[1]][(int)buf[0]] = 1;
	}
	for (i = 0; i < 255; ++i)
		if (D[i] & 1)
			++cnt;
	if (cnt != 0 && cnt != 2) {
		puts("No Solution");
		return 0;
	}
	if (cnt == 0)
		for (s = 0; D[s] == 0; ++s);
	else
		for (s = 0; (D[s] & 1) == 0; ++s);
	dfs(s);
#ifdef DEBUG
	putchar('\n');
#endif
	while (tp--)
		putchar(B[tp]);
	putchar('\n');
	return 0;
}
