#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	while (n >= 10) {
		int t = 0;
		while (n) {
			t += n % 10;
			n /= 10;
		}
		n = t;
	}
	printf("%d\n", n);
	return 0;
}
