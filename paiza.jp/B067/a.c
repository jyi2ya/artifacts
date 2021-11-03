#include <stdio.h>
#include <stdlib.h>

int vis[1009];

struct task {
	int id;
	int begin;
	int end;
};

int main(void)
{
	int n;

	scanf("%d", &n);
	while (n--) {
		int t, b, e;
		int i;
		scanf("%d%d%d", &t, &b, &e);
		for (i = b; i <= e; ++i)
			if (!vis[i]) {
				vis[i] = 1;
				--t;
				if (t == 0)
					break;
			}
		if (t != 0) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
