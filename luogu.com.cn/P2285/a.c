#include <stdio.h>
#include <stdlib.h>

struct mouse {
	int time;
	int x;
	int y;
};

struct {
	struct mouse a[10009];
	int m;
	int mem[10009];
	int vis[10009];
} S;

int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int dfs(int pos)
{
	int ans = 0;
	int i;

	if (S.vis[pos])
		return S.mem[pos];

	for (i = pos + 1; i < S.m; ++i)
		if (
				S.a[i].time - S.a[pos].time >= 
				dist(S.a[i].x, S.a[i].y, S.a[pos].x, S.a[pos].y)
		   )
			ans = max(ans, dfs(i));

	S.vis[pos] = 1;
	return S.mem[pos] = ans + 1;
}

int main_(void)
{
	int n, m;
	int i;
	struct mouse *a = S.a;
	int ans = 0;

	scanf("%d%d", &n, &m);

	S.m = m;
	for (i = 0; i < m; ++i)
		scanf("%d%d%d", &a[i].time, &a[i].x, &a[i].y);
	for (i = 0; i < m; ++i)
		ans = max(ans, dfs(i));
	printf("%d\n", ans);

	return 0;
}

int start_(void)
{
	return main_();
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	start_();

#ifdef DEBUG
	fclose(stdin);
#endif
	
	return 0;
}
