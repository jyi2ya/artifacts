#include <stdio.h>
#include <limits.h>

struct point {
	int x, y;
};

struct range {
	int xmin, ymin;
	int xmax, ymax;
};

struct point point[55];
struct range range[5];

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

#define segment_cover(l1, r1, l2, r2) (\
		((l1) <= (l2) && (l2) <= (r1) && (r1) <= (r2)) || \
		((l2) <= (l1) && (l1) <= (r2) && (r2) <= (r1)) \
		)

#define range_cover(p, q) ( \
		segment_cover((p)->xmin, (p)->xmax, (q)->xmin, (q)->xmax) && \
		segment_cover((p)->ymin, (p)->ymax, (q)->ymin, (q)->ymax) \
		)

#define range_area(p) (\
		((p)->xmax == INT_MAX || (p)->ymax == INT_MAX) ? \
		(0) : \
		(((p)->xmax - (p)->xmin) * ((p)->ymax - (p)->ymin)) \
		)

int test_range_cover(int k)
{
	int i, j;
	for (i = 0; i < k; ++i)
		for (j = i + 1; j < k; ++j)
			if (range_cover(&range[i], &range[j]))
				return 1;
	return 0;
}

int check(int k)
{
	int i;
	int ans = 0;
	for (i = 0; i < k; ++i)
		ans += range_area(&range[i]);
	return ans;
}

int gans = 0x3f3f3f3f;
int dfs(int pos, int n, int k)
{
	int i;
	int ans = 0x3f3f3f3f;
	int chk = check(k);
	if (pos == n)
		return chk;
	if (chk >= gans)
		return 0x3f3f3f3f;
	if (test_range_cover(k))
		return 0x3f3f3f3f;
	for (i = 0; i < k; ++i) {
		struct range bac = range[i];
		range[i].xmin = min(range[i].xmin, point[pos].x);
		range[i].xmax = max(range[i].xmax, point[pos].x);
		range[i].ymin = min(range[i].ymin, point[pos].y);
		range[i].ymax = max(range[i].ymax, point[pos].y);
		ans = min(ans, dfs(pos + 1, n, k));
		range[i] = bac;
	}
	gans = min(gans, ans);
	return ans;
}

int main_(void)
{
	int i;
	int n, k;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; ++i)
		scanf("%d%d", &point[i].x, &point[i].y);
	for (i = 0; i < 5; ++i) {
		range[i].xmin = range[i].ymin = INT_MAX;
		range[i].xmax = range[i].ymax = 0;
	}
	printf("%d\n", dfs(0, n, k));
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
