#include <stdio.h>

int statu[109][109], score[109], N;

int main(void)
{
	int i, j, win = 1, W = 0, D = 0, L = 0;
	scanf("%d", &N);
	while (getchar() != '\n');
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j)
			statu[i][j] = getchar();
		while (getchar() != '\n');
	}
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j) {
			if (statu[i][j] == 'W')
				score[i] += 2;
			else if (statu[i][j] == 'D')
				score[i] += 1;
		}
	for (i = 1; i <= N; ++i)
		if (score[i] > score[win])
			win = i;
	for (j = 1; j <= N; ++j) {
		if (statu[win][j] == 'W')
			++W;
		if (statu[win][j] == 'D')
			++D;
		if (statu[win][j] == 'L')
			++L;
	}
	printf("%d %d %d %d %d\n", win, score[win], W, D, L);
	return 0;
}
