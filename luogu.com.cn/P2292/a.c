#include <stdio.h>
#include <string.h>
#include <limits.h>

int f[1024 * 1024];

struct {
	struct {
		int is_end;
		int trans[26];
	} N[10000009];
	int Nc;
	int rt;
} T;

void t_ini(void)
{
	T.rt = 0;
	T.Nc = 1;
}

int t_new(void)
{
	return T.Nc++;
}

void t_ins(int *c, char *str)
{
	for (; ; ) {
		if (*c == 0)
			*c = t_new();
		if (*str == '\0') {
			T.N[*c].is_end = 1;
			break;
		}
		c = &T.N[*c].trans[*str - 'a'];
		++str;
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

char buf[1 * 1024 * 1024];

int main(void)
{
	int n, m;
	int i, j;
	int mxlen;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	t_ini();
	while (n--) {
		int len;
		scanf("%s", buf);
		len = strlen(buf);
		if (len > mxlen)
			mxlen = len;
		t_ins(&T.rt, buf);
	}
	while (m--) {
		int c;
		scanf("%s", buf);
		memset(f, 0, sizeof(f));
		c = T.rt;
		for (i = 0; i == 0 || buf[i - 1] != '\0'; ++i) {
			if (c == 0)
				break;
			if (T.N[c].is_end)
				f[i - 1] = 1;
			c = T.N[c].trans[buf[i] - 'a'];
		}
		for (j = 1; buf[j - 1] != '\0'; ++j)
			if (f[j - 1]) {
				c = T.rt;
				for (i = j; buf[i - 1] != '\0'; ++i) {
					if (c == 0)
						break;
					if (T.N[c].is_end)
						f[i - 1] = 1;
					c = T.N[c].trans[buf[i] - 'a'];
				}
			}
		for (j = strlen(buf) - 1; j >= 0; --j)
			if (f[j])
				break;
		printf("%d\n", j + 1);
	}
	return 0;
}
