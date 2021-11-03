#include <stdio.h>

int main(void)
{
	int N, A, B, i;
	scanf("%d%d%d", &N, &A, &B);
	for (i = A; i <= B; ++i)
		printf("%0*d\n", N, i);
	return 0;
}
