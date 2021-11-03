#include <stdio.h>

int find_not_same(int x);
int no_solution(void);
int max(int a, int b);

char a[109], b[109];

int main(void)
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--) {
		int i, cnt = 0, ans;
		scanf("%s%s", a, b);
		if (no_solution()) {
			ans = -1;
		} else {
			int cnta = 0, cntb = 0, cntq = 0;
			for (i = 0; a[i] != '\0'; ++i) {
				if (a[i] == '1' && b[i] == '0') ++cnta;
				if (a[i] == '0' && b[i] == '1') ++cntb;
				if (a[i] == '?') ++cntq;
			}
			ans = max(cnta, cntb) + cntq;
		}
		printf("Case %d: %d\n", ++cases, ans);
	}
	return 0;
}

int no_solution(void)
{
	int cnta = 0, cntb = 0, i;
	for (i = 0; a[i] != '\0'; ++i) {
		if (a[i] == '1') ++cnta;
		if (b[i] == '1') ++cntb;
	}
	if (cnta > cntb) return 1;
	return 0;
}

int find_not_same(int x)
{
	int i;
	for (i = 0; a[i] != '\0'; ++i)
		if (a[i] != b[i] && a[i] != '?' && a[i] != x)
			return i;
	return -1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
