#include <stdio.h>
#include <string.h>

int ft[1009];

void f_ini(void)
{
	memset(ft, 0, sizeof(ft));
}

void f_ins(int p, int x)
{
	for (; p < 1009; p += (p & (-p)))
		ft[p] += x;
}

int f_qry(int p)
{
	int ans = 0;
	for (; p; p -= (p & (-p)))
		ans += ft[p];
	return ans;
}

int main(void)
{
	int i;
	int n;
	while (scanf("%d", &n) == 1) {
		f_ini();
		for (i = 1; i <= n; ++i) 
			f_ins(i, i);
		printf("%d\n", f_qry(n));
	}
	return 0;
}
