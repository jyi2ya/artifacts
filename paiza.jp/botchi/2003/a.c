#include <stdio.h>

int main(void)
{
	int H, W, N, x = 0, y = 0;
	scanf("%d%d%d", &H, &W, &N);
	while (N--) {
		char op[3];
		scanf("%s", op);
		if (op[0] == 'U') {
			++y;
		} else if (op[0] == 'D') {
			--y;
		} else if (op[0] == 'L') {
			--x;
		} else if (op[0] == 'R') {
			++x;
		}
		if (x < 0 || y < 0 || x >= W || y >= H) {
			printf("invalid");
			return 0;
		}
	}
	printf("valid");
	return 0;
}
