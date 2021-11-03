#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	while (n) {
		int s, y;
		s = n / 2, y = n % 2;
		printf("shang:%d yu:%d\n", s, y);
		n /= 2;
	}
	return 0;
}
