#include <stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);
	while (T--) {
		int n;
		int nim = 0;
		int flag = 0;
		int i;
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			int t;
			scanf("%d", &t);
			if (t > 1)
				++flag;
			nim ^= t;
		}
		if (flag == 0) {
			puts(nim ? "Brother" : "John");
		} else {
			if (flag == 1) {
				puts("John");
			} else {
				puts(nim ? "John" : "Brother");
			}
		}
	}
	return 0;
}
