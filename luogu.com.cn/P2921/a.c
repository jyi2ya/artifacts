#include <stdio.h>
#include <string.h>

int nxt[100009];
int n;
int vis[100009];
int to_circle[100009];
int is_circle[100009];
int not_circle[100009];

int dfs_circle(int p)
{
	int ret;
	if (not_circle[p] || is_circle[p])
		return 0;

	if (vis[p]) {
		int cnt = 0;
		int i;
		++vis[p];
		i = p;
		do {
			++cnt;
			i = nxt[i];
		} while (i != p);
		return is_circle[p] = cnt;
	}

	++vis[p];
	ret = dfs_circle(nxt[p]);
	--vis[p];

	if (vis[p]) {
		is_circle[p] = ret;
		return 0;
	}

	if (ret)
		return is_circle[p] = ret;

	not_circle[p] = 1;
	return 0;
}

int find_circle(int p)
{
	if (is_circle[p])
		return is_circle[p];
	if (to_circle[p])
		return to_circle[p];
	return to_circle[p] = find_circle(nxt[p]) + 1;
}

int main(void)
{
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", nxt + i);

#ifdef DEBUG
	for (i = 1; i <= n; ++i)
		printf("%d ", nxt[i]);
	putchar('\n');
#endif

	for (i = 1; i <= n; ++i) {
		dfs_circle(i);
		if (is_circle[i]) {
#ifdef DEBUG
			puts("circle");
#endif
			printf("%d\n", is_circle[i]);
		} else {
#ifdef DEBUG
			puts("nocircle");
#endif
			printf("%d\n", find_circle(i));
		}
	}

	return 0;
}
