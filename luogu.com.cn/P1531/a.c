#include <stdio.h>

int N, M;

int seq[200009];

int main(void)
{
	int i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; ++i)
		scanf("%d", seq + i);
	while (M--) {
		char op[3];
		int l, r, ans = 0;
		scanf("%s%d%d", op, &l, &r);
		if (op[0] == 'Q') {
			for (i = l; i <= r; ++i)
				if (seq[i] > ans)
					ans = seq[i];
			printf("%d\n", ans);
		} else {
			if (seq[l] < r)
				seq[l] = r;
		}
	}
	return 0;
}
