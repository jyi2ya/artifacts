#include <stdio.h>
#include <string.h>

int lose[1009], win[1009], use[1009];
int n, x;

int max(int a, int b)
{
	return a > b ? a : b;
}

int mem[1009][1009];

int dfs(int pos, int res)
{
	return mem[pos][res] >= 0 ? mem[pos][res] :
		pos == n ? 0 :
		(mem[pos][res] =
		 max(dfs(pos + 1, res) + (use[pos] == 0 ? win[pos] : lose[pos]),
			 (res >= use[pos] ? dfs(pos + 1, res - use[pos]) + win[pos] : 0)));
}

int main(void)
{
	int i;
	memset(mem, -1, sizeof(mem));
	scanf("%d%d", &n, &x);
	for (i = 0; i < n; ++i)
		scanf("%d%d%d", &lose[i], &win[i], &use[i]);
	printf("%lld\n", 5LL * dfs(0, x));
	return 0;
}
