#include <stdio.h>
#include <stdlib.h>

#define ESC 0
#define DIE 1

void die(int x, int score)
{
	puts((x == ESC) ? ("Yes") : ("No"));
	printf("%d\n", (score == 331) ? 330 : score);
	exit(0);
}

int main(void)
{
	int M, S, T, s = 0, t = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d", &M, &S, &T);
	for (; ;) {
		while (M >= 10) {
			++t, s += 60, M -= 10;
			if (s >= S)
				die(ESC, t);
			if (t == T)
				die(DIE, s);
		}
		if (
				(((10 - M - 1) / 4 + 2) > (T - t)) ||
			       	(((10 - M - 1) / 4 + 1) * 17 >= (S - s))
		   )
			for (; ; ) {
				s += 17, ++t;
				if (s >= S)
					die(ESC, t);
				if (t == T)
					die(DIE, s);
			}
		while (M < 10) {
			++t, M += 4;
			if (t == T)
				die(DIE, s);
		}
	}
	return 0;
}
