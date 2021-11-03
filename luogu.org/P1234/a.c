#include <stdio.h>

char matrix[1049][1049];
int n, m;

int main(void)
{
	int i, j, ans = 0;
	scanf("%d%d", &n, &m);
	for (i = 10; i < n + 10; ++i)
		scanf("%s", matrix[i] + 10);
	for (i = 10; i < n + 10; ++i)
		for (j = 10; j < m + 10; ++j)
			if (matrix[i][j] == 'h') {
				if (
						matrix[i - 1][j] == 'e' &&
						matrix[i - 2][j] == 'h' &&
						matrix[i - 3][j] == 'e'
				   ) ++ans;
				if (
						matrix[i + 1][j] == 'e' &&
						matrix[i + 2][j] == 'h' &&
						matrix[i + 3][j] == 'e'
				   ) ++ans;
				if (
						matrix[i][j - 1] == 'e' &&
						matrix[i][j - 2] == 'h' &&
						matrix[i][j - 3] == 'e'
				   ) ++ans;
				if (
						matrix[i][j + 1] == 'e' &&
						matrix[i][j + 2] == 'h' &&
						matrix[i][j + 3] == 'e'
				   ) ++ans;
			}
	printf("%d\n", ans);
	return 0;
}
