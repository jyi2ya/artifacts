#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cod {
	int x;
	int y;
};

#define dist(p1, p2) (\
		((p1)->x - (p2)->x) * ((p1)->x - (p2)->x) + \
		((p1)->y - (p2)->y) * ((p1)->y - (p2)->y))

struct cod a1, a2;
struct cod shot[100009];
int disttmp2[100009], disttmp1[100009];
int sque[100009], squetop;

int cmp1(const void *p1, const void *p2)
{
	struct cod *c1 = (struct cod*)p1;
	struct cod *c2 = (struct cod*)p2;
	return dist(c1, &a1) - dist(c2, &a1);
}

int main(void)
{
	int n;
	int i;
	int ans = 0x7f7f7f7f;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	
	scanf("%d%d%d%d", &a1.x, &a1.y, &a2.x, &a2.y);
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d%d", &shot[i].x, &shot[i].y);

	qsort(shot, n, sizeof(shot[0]), cmp1);

	for (i = 0; i < n; ++i)
		disttmp2[i] = dist(&shot[i], &a2);
	for (i = 0; i < n; ++i)
		disttmp1[i] = dist(&shot[i], &a1);
	squetop = n;
	sque[squetop] = n;
	for (i = n - 1; i >= 0; --i)
		if (disttmp2[i] >= disttmp2[sque[squetop]])
			sque[--squetop] = i;
	for (i = 0; i < n; ++i) {
		while (sque[squetop] <= i)
			++squetop;
		if (disttmp2[sque[squetop]] + disttmp1[i] < ans)
			ans = disttmp2[sque[squetop]] + disttmp1[i];
	}

	printf("%d\n", ans);
	return 0;
}
