#include <stdio.h>

int origin[109][109], cmp[19][19], N, M;

int main(void)
{
	int i, j, k, l, first = 1;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			scanf("%d", origin[i] + j);
	scanf("%d", &M);
	for (i = 0; i < M; ++i)
		for (j = 0; j < M; ++j)
			scanf("%d", cmp[i] + j);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			int ok = 1;
			for (k = 0; k < M && i + k < N; ++k)
				for (l = 0; l < M && j + l < N; ++l)
					if (origin[i + k][j + l] != cmp[k][l])
						ok = 0;
			if (k == M && l == M && ok) {
				if (first)
					first = 0;
				else
					putchar('\n');
				printf("%d %d", i, j);
			}
		}
	return 0 ;
}
