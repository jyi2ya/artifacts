#include <stdio.h>
#include <limits.h>

int n, m, h;

long long cro__[3009][3009];
long long *cro_[3009];
long long **cro = cro_ + 4;
long long rcro__[3009][3009];
long long *rcro_[3009];
long long **rcro = rcro_ + 4;
long long mtx__[3009][3009];
long long *mtx_[3009];
long long **mtx = mtx_ + 4;
long long pfx__[3009][3009];
long long *pfx_[3009];
long long **pfx = pfx_ + 4;

/* 丑陋代码 */
long long Seed,a,b,c,MOD;
long long Random() {
	c++;
	Seed=(Seed*a+b*c)%MOD;
	return Seed;
}
int Random_int() {
	int tmp=Random();
	if(Random()&1)tmp*=-1;
	return tmp;
}
void MAKE() {
	scanf("%lld%lld%lld%lld%lld",&Seed,&a,&b,&c,&MOD);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mtx[i][j]=Random_int();
}

int main(void)
{
	int i, j;
	int ty;
	long long ans = INT_MIN;

#ifndef ONLINE_JUDGE
	freopen("rhombus.in", "r", stdin);
#ifndef DEBUG
	freopen("rhombus.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	for (i = 0; i < 3009; ++i) {
		pfx_[i] = pfx__[i] + 4;
		mtx_[i] = mtx__[i] + 4;
		cro_[i] = cro__[i] + 4;
		rcro_[i] = rcro__[i] + 4;
	}

	scanf("%d%d%d%d", &n, &m, &h, &ty);
	if (ty == 0) {
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= m; ++j)
				scanf("%lld", &mtx[i][j]);
	} else {
		MAKE();
	}

	for (i = 0; i <= n + 3; ++i)
		for (j = 0; j <= m + 3; ++j)
			cro[i][j] = cro[i - 1][j - 1] + mtx[i][j];
	for (i = 0; i <= n + 3; ++i)
		for (j = m + 3; j >= 0; --j)
			rcro[i][j] = rcro[i - 1][j + 1] + mtx[i][j];

	for (i = 0; i <= n + 3; ++i)
		for (j = 0; j <= m + 3; ++j)
			pfx[i][j] = pfx[i - 1][j] + cro[i - 1][j - 1] +
				rcro[i - 1][j + 1] + mtx[i][j];


#ifdef DEBUG
	for (i = 0; i <= n; ++i) {
		for (j = 0; j <= m; ++j)
			printf("%lld ", mtx[i][j]);
		putchar('\n');
	}

	putchar('\n');

	for (i = 0; i <= n; ++i) {
		for (j = 0; j <= m; ++j)
			printf("%lld ", pfx[i][j]);
		putchar('\n');
	}

	putchar('\n');

	for (i = 0; i <= n; ++i) {
		for (j = 0; j <= m; ++j)
			printf("%lld ", cro[i][j]);
		putchar('\n');
	}

	putchar('\n');

	for (i = 0; i <= n; ++i) {
		for (j = 0; j <= m; ++j)
			printf("%lld ", rcro[i][j]);
		putchar('\n');
	}
#endif

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j) {
			long long lans = 0;
			if (i - h * 2 + 1 < 0 || j < h || j + h - 1 > m)
				continue;
			lans = pfx[i][j] - pfx[i - h][j - h + 1] -
				pfx[i - h][j + h - 1] +
				pfx[i - h * 2 + 1][j] -
				cro[i - h][j - h] - rcro[i - h][j + h];
			if (lans > ans)
				ans = lans;
		}

	printf("%lld\n", ans);
	return 0;
}
