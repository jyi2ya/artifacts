#include <stdio.h>

int main(void)
{
	int n;
	int a, b, c;
	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);
	printf("%d %d %d\n",
			n / (a + b + c) * a,
			n / (a + b + c) * b,
			n / (a + b + c) * c);
	return 0;
}
