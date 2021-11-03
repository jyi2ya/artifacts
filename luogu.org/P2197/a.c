#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n == 1) {
			scanf("%*d");
			puts("Yes");
		} else {
			int nim = 0;
			while (n--) {
				int t;
				scanf("%d", &t);
				nim ^= t;
			}
			puts(nim ? "Yes" : "No");
		}
	}
	return 0;
}
