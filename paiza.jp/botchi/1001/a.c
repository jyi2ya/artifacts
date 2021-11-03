#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out < in
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>
#include <string.h>

struct house {
	int h, w, r, c;
	int id;
} house[109];

struct house placed[109];
int placednum;

int H, W, N;

int town[109][109];
int score;

int sol[109][109];
int solscore;

void init(void)
{
	int i;
	scanf("%d%d%d", &H, &W, &N);
	for (i = 0; i < N; ++i) {
		scanf("%d%d%d%d", &house[i].h, &house[i].w,
				&house[i].r, &house[i].c);
		house[i].id = i + 1;
	}
}

void dfs(int id)
{
	int i, j;

	if (id > N) {
		if (score > solscore) {
			solscore = score;
			memcpy(sol, town, sizeof(town));
		}
		return;
	}

	for (i = 0; i <= H - house[id].h; ++i)
		for (j = 0; j <= W - house[id].w; ++j) {
			if (town[i][j] == 0) {
				int fail = 0;
				int ii, jj;
				for (ii = i; !fail && ii < i + house[id].h; ++ii)
					for (jj = j; !fail && jj < j + house[id].w; ++jj)
						if (town[i][j] != 0)
							fail = 1;

				if (!fail) {
					for (ii = i; !fail && ii < i + house[id].h; ++ii)
						for (jj = j; !fail && jj < j + house[id].w; ++jj)
							town[i][j] = id + 1;
				}
			}
		}
}

int main(void)
{
	init();
	return 0;
}
