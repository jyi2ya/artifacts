#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_NUM 10
#define MAX_TEST_DATA 10
#define MAX_STR_LEN 30

int main(int argc, char* argv[])
{
	int T;
	srand(atoi(argv[1]));
	T = rand() % MAX_TEST_DATA;
	while (T--) {
		int n = rand() * 2 % MAX_STR_NUM;

		printf("%d\n", n);
		while (n--) {
			int len = rand() % MAX_STR_LEN + 1;
			while (len--) putchar(rand() % 26 + 'A');
			putchar('\n');
		}
	}
	puts("0");
	return 0;
}
