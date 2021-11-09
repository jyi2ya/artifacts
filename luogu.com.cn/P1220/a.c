#include <stdio.h>
#include <string.h>

long long llmin(long long a, long long b)
{
	return a < b ? a : b;
}

long long pos[59], pwr[59];
long long n, c;

long long pwrpre[1009];

long long unit_cost(int l, int r)
{
	return pwrpre[l - 1] + pwrpre[n] - pwrpre[r];
}

long long dist(int l, int r)
{
	return pos[r] - pos[l];
}

long long mem[1009][1009][2];

long long calc(int l, int r, int is_l)
{
	if (mem[l][r][is_l] >= 0)
		return mem[l][r][is_l];

	if (l == r) {
		if (r == c)
			return 0;
		return 0x3f3f3f3f;
	}
	if (is_l)
		return mem[l][r][1] = 
			llmin(calc(l + 1, r, 1) + unit_cost(l + 1, r) *
				dist(l, l + 1), calc(l + 1, r, 0) + 
				unit_cost(l + 1, r) * dist(l, r));
	return mem[l][r][0] = 
		llmin(calc(l, r - 1, 0) + unit_cost(l, r - 1) *
			dist(r - 1, r), calc(l, r - 1, 1) + 
			unit_cost(l, r - 1) * dist(l, r));
}

int main(void)
{
	long long i;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%lld%lld", &n, &c);
	for (i = 1; i <= n; ++i)
		scanf("%lld%lld", &pos[i], &pwr[i]);
	for (i = 1; i <= n; ++i)
		pwrpre[i] = pwrpre[i - 1] + pwr[i];

	memset(mem, -1, sizeof(mem));
	printf("%lld\n", llmin(calc(1, n, 0), calc(1, n, 1)));

	return 0;
}
