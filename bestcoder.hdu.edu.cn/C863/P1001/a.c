#include <stdio.h>
#include <limits.h>

int test[109];

int main(void)
{
/*
	int i, j;
	test[1] = 0;
	for (i = 2; i < 109; ++i) {
		test[i] = INT_MAX;
		for (j = 1; j < i; ++j)
			if (test[j] + (i ^ j) < test[i])
				test[i] = test[j] + (i ^ j);
	}
	for (i = 1; i < 109; ++i)
		printf("%d %d\n", test[i], i ^ 1);
		*/
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", n ^ 1);
	}
	return 0;
}
