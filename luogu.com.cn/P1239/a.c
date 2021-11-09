#include <stdio.h>

int main(void)
{
	int N, num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	scanf("%d", &N);
	while (N) {
		register int a = N--;
		while (a) {
			++num[a % 10];
			a /= 10;
		}
	}
	for (N = 0; N < 10; ++N)
		printf("%d\n", num[N]);
	return 0;
}
