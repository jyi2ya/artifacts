#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int n, i;
	srand(atoi(argv[1]));
	n = rand() % 100;
	puts("1");
	printf("%d\n",n);
	for (i = 0; i < n; ++i) {
		int a, b, c, d;
		a = (rand() - RAND_MAX / 2) % 100;
		b = (rand() - RAND_MAX / 2) % 100;
		c = (rand() - RAND_MAX / 2) % 100;
		d = (rand() - RAND_MAX / 2) % 100;
		printf("%d %d %d %d\n",a, b, c, d);
	}
	return 0;
}
