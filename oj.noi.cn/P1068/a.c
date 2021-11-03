/*
 * NOJ 1068 图像旋转翻转变换
 * 2018-11-11
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int a[109][109], tmp[109][109];
int n, m;

void A(void);
void B(void);
void C(void);
void D(void);

int main(void)
{
	int i, j, ch;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			scanf("%d", a[i] + j);
	while (!isalpha(ch = getchar()));
	ungetc(ch, stdin);
	while (isalpha(ch = getchar()))
		switch (ch) {
			case 'A' :
				A();
				break;
			case 'B' :
				B();
				break;
			case 'C' :
				C();
				break;
			case 'D' :
				D();
				break;
			default:
				break;
		}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
	return 0;
}

void A(void)
{
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			tmp[j][n - i - 1] = a[i][j];
	memcpy(a, tmp, sizeof(tmp));
	i = n; n = m; m = i;
}
void B(void)
{
	A();
	A();
	A();
}
void C(void)
{
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			tmp[i][m - j - 1] = a[i][j];
	memcpy(a, tmp, sizeof(tmp));
}
void D(void)
{
	A();
	C();
	B();
}
