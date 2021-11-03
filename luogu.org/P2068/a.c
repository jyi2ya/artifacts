#include <stdio.h>

long long seq[100009];

int main(void)
{
	int i, N, W;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &W);
	while (W--) {
		int l, r;
		char op[3];
		scanf("%s%d%d", op, &l, &r);
		if (op[0] == 'x') {
			seq[l] += r;
		} else {
			int ans= 0;
			for (i = l; i <= r; ++i)
				ans += seq[i];
			printf("%d\n", ans);
		}
	}
	return 0;
}
