#include <stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(void)
{
	int n;
	int l, r, m;
	static char buf[1000009];
	static char ex[2000009];
	static int len[2000009];
	static int ok[256];
	int top = 0;
	long long ans = 0;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	ok['`'] = '`';
	ok['1'] = '0';
	ok['0'] = '1';

	scanf("%d", &n);
	scanf("%s", buf);
	ex[top++] = '`';
	for (i = 0; i < n; ++i) {
		ex[top++] = buf[i];
		ex[top++] = '`';
	}
	ex[top] = '\0';

	r = 1;
	m = 1;
	len[0] = 1;
	for (i = 2; i < top; i += 2) {
		l = (i >= r ? 1 : min(len[m * 2 - i], r - i));
		while (i - l >= 0 && ex[i - l] == ok[(int)ex[i + l]])
			++l;
		len[i] = l;
		if (i + l > r) {
			r = i + l;
			m = i;
		}
	}

	for (i = 0; i < top; i += 2)
		ans += len[i] / 2;

	printf("%lld\n", ans);
	return 0;
}
