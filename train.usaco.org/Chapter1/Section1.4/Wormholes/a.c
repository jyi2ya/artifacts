/*
ID:lindong6
PROG:wormhole
LANG:C
*/

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif
#include <stdio.h>
#include <string.h>
#include <limits.h>

int N;
long long x[14], y[14];
int connect[14] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void read(void);
int try_to_connect(int pos);
int check(void);

int main(void)
{
	read();
	printf("%d\n", try_to_connect(0));
	return 0;
}

int check(void)
{
	register int i, j, k;
#ifdef LUOTIANYI
	for (i = 0; i < N; ++i)
		printf("%d("I64", "I64"): %d("I64", "I64")\n", 
				i, x[i], y[i],
				connect[i], x[connect[i]], y[connect[i]]
		      );
	puts("=====");
#endif
	int vis[14];
	for (i = 0; i < N; ++i) { /* start point */
		memset(vis, 0, sizeof(vis));
		k = i;
#ifdef LUOTIANYI
		printf("run at %d\n", i);
#endif
		for (; ;) {
			int idx = N;

			if (vis[k]) /* circled */
				return 1;
			vis[k] = 1;

			x[N] = LLONG_MAX, y[N] = y[k];

			for (j = 0; j < N; ++j)
				if (
						y[j] == y[k] &&
						x[k] < x[j] &&
						x[j] < x[idx]
				   )
					idx = j;

#ifdef LUOTIANYI
			printf("idx = %d\n", idx);
#endif
			if (idx == N) /* move out */
				break;
			else /* move through a wormhole */
				k = connect[idx];
		}
	}
	return 0;
}

int try_to_connect(int pos)
{
	int ans = 0;
	register int i;

	if (pos == N)
		return check();

	if (connect[pos] != -1)
		return try_to_connect(pos + 1);

	for (i = pos + 1; i < N; ++i)
		if (connect[i] == -1) {
			connect[i] = pos;
			connect[pos] = i;
			ans += try_to_connect(pos + 1);
			connect[i] = -1;
			connect[pos] = -1;
		}

	return ans;
}

void read(void)
{
	register int i;

	freopen("wormhole.in", "r", stdin);
#ifndef LUOTIANYI
	freopen("wormhole.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf(I64 I64, x + i, y + i);
}
