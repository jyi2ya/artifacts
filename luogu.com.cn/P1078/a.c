#include <stdio.h>
#include <stdlib.h>

#define INF 0x7f7f7f7f

int country_num, culture_num, road_num, start_point, end_point;
int dist[109][109];
int opinion[109][109], culture[109], road[109][109];
int vis_country[109], vis_culture[109];
int ans = INF;

void read(void);
void init(void);
void dfs(int pos, int nowans);
int min(int orz, int sto);

int main(void)
{
	read();
	init();

	vis_country[start_point] = 1;
	vis_culture[culture[start_point]] = 1;
	dfs(start_point, 0);

	if (ans == INF)
		ans = -1;

	printf("%d\n", ans);
	return 0;
}

void init(void)
{
	register int i, j, k;
	srand(0x66ccff);
	for (i = 1; i <= country_num; ++i)
		for (j = 1; j <= country_num; ++j)
			if (opinion[culture[i]][culture[j]] == 1)
				road[j][i] = 0;

	for (i = 1; i <= country_num; ++i)
		for (j = 1; j <= country_num; ++j) {
			if (road[i][j])
				dist[i][j] = road[i][j];
			else
				dist[i][j] = 1000009;
		}

	for (i = 1; i <= country_num; ++i)
		for (j = 1; j <= country_num; ++j)
			for (k = 1; k <= country_num; ++k)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int check_opinion(int next_culture)
{
	register int i;
	for (i = 1; i <= culture_num; ++i)
		if (vis_culture[i] && opinion[next_culture][i] == 1)
			return 1;
	return 0;
}

void dfs(int pos, int nowans)
{
	register int i;
	int mid = rand() % country_num + 1;

	if (pos == end_point)
		ans = min(ans, nowans);

	if (nowans >= ans || dist[pos][end_point] + nowans >= ans)
		return;

	for (i = mid + 1; i <= country_num; ++i)
		if (
				i != pos &&
				road[pos][i] && 
				!vis_country[i] &&
				!vis_culture[culture[i]] &&
				check_opinion(culture[i]) == 0 &&
				dist[i][end_point] + nowans < ans
		   ) {
			vis_country[i] = 1;
			vis_culture[culture[i]] = 1;

			dfs(i, nowans + road[pos][i]);

			vis_country[i] = 0;
			vis_culture[culture[i]] = 0;
		}
	for (i = mid; i >= 1; --i)
		if (
				i != pos &&
				road[pos][i] && 
				!vis_country[i] &&
				!vis_culture[culture[i]] &&
				check_opinion(culture[i]) == 0 &&
				dist[i][end_point] + nowans < ans
		   ) {
			vis_country[i] = 1;
			vis_culture[culture[i]] = 1;

			dfs(i, nowans + road[pos][i]);

			vis_country[i] = 0;
			vis_culture[culture[i]] = 0;
		}
}

#include <ctype.h>

int getint(void)
{
	register int aans = 0, ch;
	while (!isdigit(ch = getchar()));
	aans = ch - '0';
	while (isdigit(ch = getchar()))
		aans = aans * 10 + ch - '0';
	ungetc(ch, stdin);
	return aans;
}

void read(void)
{
	register int i, j;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	country_num = getint();
	culture_num = getint();
	road_num = getint();
	start_point = getint();
	end_point = getint();
	for (i = 1; i <= country_num; ++i)
		culture[i] = getint();
	for (i = 1; i <= culture_num; ++i)
		for (j = 1; j <= culture_num; ++j)
			opinion[i][j] = getint();
	for (i = 0; i < road_num; ++i) {
		register int u, v, d;
		u = getint();
		v = getint();
		d = getint();
		road[u][v] = d;
		road[v][u] = d;
	}
}

inline int min(int orz, int sto)
{
	return orz < sto ? orz : sto;
}
