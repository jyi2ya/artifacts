#include <stdio.h>
#include <ctype.h>

#define MOD (10000)

int read_a_number(void)
{
	int ch;
	int ans = 0;
	while (isdigit(ch = getchar()) && ch != EOF)
		ans = (ans * 10 + ch - '0') % MOD;
	ungetc(ch, stdin);
	return ans;
}

int main(void)
{
	int ans = 0;
	int ch;
	for (; ; ) {
		int nu = read_a_number();
		ch = getchar();
		if (ch == EOF)
			break;
		if (ch == '*') {
			int tans = 1;
			do {
				tans = tans * nu % MOD;
				nu = read_a_number();
				ch = getchar();
			} while (ch == '*');
			tans = tans * nu % MOD;
			ans = (ans + tans) % MOD;
			if (ch == EOF)
				break;
		} else {
			ans = (ans + nu) % MOD;
		}
	}
	printf("%d\n", ans);
	return 0;
}
