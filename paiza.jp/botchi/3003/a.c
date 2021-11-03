#include <stdio.h>

int main(void)
{
	int N, a = 0, b = 0;
	scanf("%d", &N);
	while (N--) {
		char p[3], q[3];
		scanf("%s%s", &p, &q);
		if (p[0] != q[0]) {
			if (p[0] == 'g' && q[0] == 'c')
				++a;
			if (p[0] == 'g' && q[0] == 'p')
				++b;
			if (p[0] == 'c' && q[0] == 'g')
				++b;
			if (p[0] == 'c' && q[0] == 'p')
				++a;
			if (p[0] == 'p' && q[0] == 'g')
				++a;
			if (p[0] == 'p' && q[0] == 'c')
				++b;
		}
	}
	printf("%d\n%d\n", a, b);
	return 0;
}
