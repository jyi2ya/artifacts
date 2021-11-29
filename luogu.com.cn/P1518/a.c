#if 0
name="a"
gcc -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>
#include <string.h>

char orig[19][19];

struct ctx {
	char map[19][19];
	int fx, fy, fdx, fdy;
	int cx, cy, cdx, cdy;
};

struct ctx map1, map2;

void update_map(struct ctx *x)
{
	x->map[x->fy][x->fx] = '.';
	x->map[x->cy][x->cx] = '.';
#define is_legal(yy, xx) ((yy) >= 0 && (yy) < 10 && (xx) >= 0 && (xx) < 10 && x->map[yy][xx] != '*')
#define update(l) \
	if (is_legal(x-> l ## y + x-> l ## dy, x-> l ## x + x-> l ## dx)) \
	x-> l ## y += x-> l ## dy, x-> l ## x += x-> l ## dx; \
	else { \
		int yy = x-> l ## dy, xx = x-> l ## dx; \
		x-> l ## dy = (yy != 0 ? 0 : xx == -1 ? -1 : 1); \
		x-> l ## dx = (xx != 0 ? 0 : yy == -1 ? 1 : -1); \
	}
	update(f);
	update(c);
	x->map[x->fy][x->fx] = 'F';
	x->map[x->cy][x->cx] = 'C';
}

int main(void)
{
	int i, j;
	int cnt1 = 0, cnt2 = 0;

	for (i = 0; i < 10; ++i)
		scanf("%s", orig[i]);
	memcpy(map1.map, orig, sizeof(orig));
	for (i = 0; i < 10; ++i)
		for (j = 0; j < 10; ++j) {
			if (map1.map[i][j] == 'F')
				map1.fy = i, map1.fx = j;
			if (map1.map[i][j] == 'C')
				map1.cy = i, map1.cx = j;
		}
	map1.fdy = map1.cdy = -1;
	map1.fdx = map1.cdx = 0;
	memcpy(&map2, &map1, sizeof(map1));

	do {
		++cnt1;

		update_map(&map1);
		if (map1.cy == map1.fy && map1.cx == map1.fx) {
			printf("%d\n", cnt1);
			return 0;
		}

		++cnt2;
		update_map(&map2);
		if (map2.cy == map2.fy && map2.cx == map2.fx) {
			printf("%d\n", cnt2);
			return 0;
		}

		++cnt2;
		update_map(&map2);
		if (map2.cy == map2.fy && map2.cx == map2.fx) {
			printf("%d\n", cnt2);
			return 0;
		}

		/*
	   int system(const char *str);
	   system("sleep 0");
	   system("clear");
	   puts("======");
	   for (i = 0; i < 10; ++i) {
	   for (j = 0; j < 10; ++j)
	   putchar(map1.map[i][j]);
	   putchar('\n');
	   }
	   printf("(%d %d), (%d %d)\n", map1.fdy, map1.fdx, map1.cdy, map1.cdx);
	   */

	} while (memcmp(&map1, &map2, sizeof(map2)) != 0);

	puts("0");

	return 0;
}
