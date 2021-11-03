#include <stdio.h>
#include <ctype.h>

int origin, base;

void read(void);

int ans[10000009], top = 0;

int main(void)
{
	register int i;
	int origin_back;
	read();
	origin_back = origin;
	while (origin) {
		ans[top++] = (origin % base);
		if (ans[top - 1] < 0) {
			ans[top - 1] -= base;
			origin += base;
		}
		origin /= base;
	}
	printf("%d=", origin_back);
	for (i = top - 1; i >= 0; --i)
		printf("%c", isdigit(ans[i] + '0') ? ans[i] + '0' : ans[i] - 10 + 'A');
	printf("(base%d)\n", base);
	return 0;
}

void read(void)
{
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%d%d", &origin, &base);
}

int fastpow(int a, int b)
{
	int aans = 1;
	while (b) {
		if (b & 1)
			aans *= a;
		a *= 2;
		b /= 2;
	}
	return aans;
}
