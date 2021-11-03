#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bgint {
	int a[128], top;
} bgint;

int N, K;
char a[64];
int ins[16];

bgint ans, now;

bgint* mul(bgint *a, bgint *b);
bgint* init(bgint *x);
bgint* int2bg(bgint *dest, int src);
int cmp(bgint *a, bgint *b);
void prt(bgint *x);

bgint *str2bg(bgint *dest, char *s);

void bbsort(void);
void newans(void);
void getnow(void);

int main(void)
{
	int i, MAX_CYCLE = 1000000;
	srand(0x66ccff);
	scanf("%d%d%s", &N, &K, a);
	init(&ans);
	while (MAX_CYCLE--) {
		newans();
		getnow();
	}
	prt(&ans);
	putchar('\n');
	return 0;
}

bgint *str2bg(bgint *dest, char *s)
{
	int i;
	init(dest);
	--dest -> top;

	for (i = 0; s[i] != '\0'; ++i);
	--i;

	while (i >= 0)
		dest -> a[dest -> top++] = s[i--] - '0';

	return dest;
}

void prt(bgint *x)
{
	int i;
	for (i = x -> top - 1; i >= 0; --i) printf("%d", x -> a[i]);
}

bgint* init(bgint *x)
{
	memset(x -> a, 0, sizeof(int) * 128);
	x -> top = 1;
	return x;
}

bgint* mul(bgint *a, bgint *b)
{
	int i, j;
	bgint tmp;
	init(&tmp);
	for (i = 0; i < a -> top; ++i)
		for (j = 0; j < b -> top; ++j)
			tmp.a[i + j] += a -> a[i] * b -> a[j];
	tmp.top = a -> top + b -> top + 5;
	for (i = 0; i < tmp.top; ++i)
		if (tmp.a[i] > 9) {
			tmp.a[i + 1] += tmp.a[i] / 10;
			tmp.a[i] %= 10;
		}
	while (tmp.a[tmp.top] == 0) --tmp.top;
	++tmp.top;
	memcpy(a, &tmp, sizeof(bgint));
	return a;
}

bgint* int2bg(bgint *dest, int src)
{
	--dest -> top;
	while (src) {
		dest -> a[dest -> top++] = src % 10;
		src /= 10;
	}
	return dest;
}

int cmp(bgint *a, bgint *b)
{
	if (a -> top != b -> top) {
		return a -> top - b -> top;
	} else {
		int i;
		for (i = a -> top - 1; i >= 0; --i)
			if (a -> a[i] != b -> a[i])
				return a -> a[i] - b -> a[i];
	}
	return 0;
}

void bbsort(void)
{
	int i, ok = 0;
	while (!ok) {
		ok = 1;
		for (i = 0; i < K - 1; ++i)
			if (ins[i] > ins[i + 1]) {
				int t = ins[i];
				ins[i] = ins[i + 1];
				ins[i + 1] = t;
				ok = 0;
			}
	}
}

void newans(void)
{
	int i;
	/* 0 1 2 3 4 5 6 */
	/* 1 2 3 1 */
	ins[0] = rand() % (N - K) + 1;
	for (i = 1; i < K; ++i)
		ins[i] = ins[i - 1] + 1 +
			rand() % (N - ins[i - 1] - (K - i));
}

void getnow(void)
{
	int i, t;
	bgint tmp;

	t = a[ins[0]];
	a[ins[0]] = '\0';
	str2bg(&now, a);
	a[ins[0]] = t;

	for (i = 0; i < K; ++i) {
		int t = a[ins[i + 1]];
		a[ins[i + 1]] = '\0';
		str2bg(&tmp, a + ins[i]);
		a[ins[i + 1]] = t;

		mul(&now, &tmp);
	}
	if (cmp(&now, &ans) > 0)
		memcpy(&ans, &now, sizeof(bgint));
}

