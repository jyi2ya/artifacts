#include <stdio.h>
#include <string.h>

#define MAXS ((int)1e5 + 9)

char str[MAXS];
char buf[MAXS << 2];
int R[MAXS << 2];
int pre[MAXS << 2];
int suf[MAXS << 2];

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main(void)
{
	int i;
	int ans = 0;
	int l, m, r;
	int len;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%s", str);

	len = strlen(str);

	buf[0] = '~';
	for (i = 0; i < len; ++i) {
		buf[(i << 1) + 1] = str[i];
		buf[(i << 1) + 2] = '`';
	}
	buf[(len << 1) + 1] = '\0';
	len = len << 1 | 1;

	R[0] = 0;
	m = 0;
	r = 0;

	for (i = 1; i < len; ++i) {
		for (
				l = (i <= r) ? min(r - i, R[m * 2 - i]) : 1;
				i - l >= 0 && buf[i - l] == buf[i + l];
				++l
		    );
		R[i] = l;
		if (i + l > r) {
			r = i + l;
			m = i;
		}
		pre[i + l - 1] = max(pre[i + l - 1], (l << 1) - 1);
		suf[i - l + 1] = max(suf[i - l + 1], (l << 1) - 1);
	}

	for (i = len - 1; i >= 0; --i)
		pre[i] = max(pre[i], pre[i + 1] - 2);

	for (i = 0; i < len; ++i)
		suf[i] = max(suf[i], suf[i - 1] - 2);

	for (i = 2; i < len - 1; i += 2) {
		int cache = (pre[i - 1] + 1) / 2 + (suf[i + 1] + 1) / 2;
		ans = max(ans, cache);
	}

	printf("%d\n", ans);
	return 0;
}
