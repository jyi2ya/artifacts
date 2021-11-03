#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &T);
	while (T--) {
		int i, j;
		char buf[30];
		int vis[30];
		int per[30];

		memset(per, 0, sizeof(per));
		memset(vis, 0, sizeof(vis));

		scanf("%s", buf);
		for (i = 0; i < 26; ++i)
			buf[i] -= 'A';

		for (i = 0; i < 26; ++i)
			if (!vis[i]) {
				int siz = 0;
				j = i;
				do {
					vis[j] = 1;
					j = buf[j];
					++siz;
				} while (j != i);
				++per[siz];
			}

		for (i = 2; i <= 26; i += 2)
			if (per[i] & 1) {
				puts("No");
				goto FINISH;
			}

		puts("Yes");
FINISH:
		;
	}
	return 0;
}
