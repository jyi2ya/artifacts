#include <stdio.h>

int ok[4009];

int main(void)
{
	int i;
	int T;
	for (i = 0; i < 4009; i += 4)
		ok[i] = 1;
	for (i = 0; i < 4009; i += 100)
		ok[i] = 0;
	for (i = 0; i < 4009; i += 400)
		ok[i] = 1;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		puts(ok[n] ? "Yes" : "No");
	}
	return 0;
}
