/*
 * 如果后手刚开始时手里没有两王则先手输。
 * 否则后手输。
 *
 * 草什么破题，吓到我了。
 */

#include <stdio.h>
#include <string.h>

void solve(void)
{
	int i;
	int cnt = 0;
	char use[109];
	int len;
	scanf("%s", use);
	len = strlen(use);
	for (i = 0; i < 6; ++i)
		scanf("%*s");
	for (i = 0; i < 6; ++i) {
		char buf[10];
		scanf("%s", buf);
		if (buf[1] == 'J')
			++cnt;
	}
	for (i = 0; i < len * 4 + 2 - 12; ++i)
		scanf("%*s");
	scanf("%*s");

	if (cnt == 2)
		puts("laohu");
	else
		puts("dasuan");
}

int main(void)
{
	int T;

#ifndef ONLINE_JUDGE
	freopen("joker.in", "r", stdin);
#ifndef DEBUG
	freopen("joker.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
