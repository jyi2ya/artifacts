#include <stdio.h>

int main(void)
{
	char s[200];
	int i;
	int cnt;
	int ans = 0;

	scanf("%s", s);
	cnt = 1;
	for (i = 1; s[i - 1]; ++i) {
		if (s[i] == s[i - 1]) {
			++cnt;
		} else {
			if (!(cnt & 1))
				++ans;
			cnt = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
