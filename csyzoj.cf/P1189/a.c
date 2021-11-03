#include <stdio.h>
#include <stdlib.h>
#ifndef DEBUG
#define NDEBUG
#endif
#include <assert.h>
#define Z(x) printf x

void awsl(void)
{
	puts("-1");
	exit(0);
}

long long D[1000009], P[1000009];
long long N, T;

/* （一种植物） */

int next_cost_less_equal_current_can_reach[1000009];
int find_next_cost_less_equal_current_can_reach(long long cur)
{
	register int i;
	register long long acc = D[cur];
	for (i = cur + 1; i <= N && acc <= T; acc += D[i], ++i)
		if (P[i] < P[cur])
			return i;
	return -1;
}

/* （一种植物） */

int min_cost_can_reach[1000009];

int find_min_cost_can_reach(int cur)
{
	return min_cost_can_reach[cur];
}

long long dist_prefix[1000009];
/* 显然，这是一个单调雀跃，top 处大 bot 处小。 */
struct {
	int val;
	int pos;
} Q[1000009];
int Qtop, Qbot;

long long get_dist(long long src, long long dst)
{
	if (src >= dst)
		return 0;
	if (src == 0)
		return dist_prefix[dst - 1];
	return dist_prefix[dst - 1] - dist_prefix[src - 1];
}

void ThereIsMoreThanOneWayToDoIt_timtowtdi(void)
{
	int i;
	dist_prefix[0] = D[0];
	for (i = 1; i <= N; ++i)
		dist_prefix[i] = dist_prefix[i - 1] + D[i];

	Qtop = Qbot = 0;
	Q[Qtop].val = P[N];
	Q[Qtop++].pos = N;
	for (i = N - 1; i >= 0; --i) {
		while (Qbot < Qtop && get_dist(i, Q[Qbot].pos) > T)
			++Qbot;
		if (Qtop == Qbot)
			awsl();
		min_cost_can_reach[i] = Q[Qbot].pos;
		while (Qtop > Qbot && P[i] <= Q[Qtop - 1].val)
			--Qtop;
		Q[Qtop].val = P[i];
		Q[Qtop++].pos = i;
	}
}

int main(void)
{
	register int pos;
	register int res;
	register long long ans = 0;
	register int i;

#ifndef ONLINE_JUDGE
	freopen("wayhome.in", "r", stdin);
#ifndef DEBUG
	freopen("wayhome.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%lld%lld", &N, &T);
	for (i = 0; i < N; ++i)
		scanf("%lld%lld", &D[i], &P[i]);
	ThereIsMoreThanOneWayToDoIt_timtowtdi();
	P[N] = 0;
	pos = 0;
	res = 0;
	while (pos < N) {
		long long next;
		next = find_next_cost_less_equal_current_can_reach(pos);
		if (next < 0) {
			next = find_min_cost_can_reach(pos);
			if (next < 0) {
				awsl();
			} else {
				long long dist = get_dist(pos, next);
				ans += P[pos] * (T - res);
				res = T - dist;
				pos = next;
			}
		} else {
			long long dist = get_dist(pos, next);
			if (res >= dist) {
				res -= dist;
				pos = next;
			} else {
				ans += P[pos] * (dist - res);
				res = 0;
				pos = next;
			}
		}
		assert(ans >= 0);
	}

	assert(res == 0);

	printf("%lld\n", ans);
	return 0;
}
