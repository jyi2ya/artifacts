#include <stdio.h>

int statu[10000000];

int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		double a;
		int t;
		int j;
		scanf("%lf%d", &a, &t);
		for (j = 1; j <= t; ++j)
			statu[(int)(j * a)] ^= 1;
	}
	for (i = 1; i < sizeof(statu) / sizeof(int); ++i)
		if (statu[i]) {
			printf("%d\n", i);
			break;
		}
	return 0;
}
