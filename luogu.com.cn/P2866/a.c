#include <stdio.h>

int main(void)
{
	int s[80009];
	int t = 0;
	int n;
	long long a = 0;

	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		while (t > 0 && s[t - 1] <= x)
			--t;
		a += t;
		s[t++] = x;
	}
	
	printf("%lld\n", a);
	return 0;
}
