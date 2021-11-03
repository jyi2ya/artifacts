#include <stdio.h>
#include <string.h>

void num2roman(int x, char *buf);

int main(void)
{
	int x, i, j;
	int I = 0, V = 0, X = 0, L = 0, C = 0, D = 0, M = 0;
	char buf[256];
	scanf("%d", &x);
	for (i = 1; i <= x; ++i) {
		num2roman(i, buf);
		for (j = 0; buf[j] != '\0'; ++j)
			switch (buf[j]) {
				case 'I' : ++I; break;
				case 'V' : ++V; break;
				case 'X' : ++X; break;
				case 'L' : ++L; break;
				case 'C' : ++C; break;
				case 'D' : ++D; break;
				case 'M' : ++M; break;
				default: break;
			}
	}
	if (I)
		printf("I %d\n", I);
	if (V)
		printf("V %d\n", V);
	if (X)
		printf("X %d\n", X);
	if (L)
		printf("L %d\n", L);
	if (C)
		printf("C %d\n", C);
	if (D)
		printf("D %d\n", D);
	if (M)
		printf("M %d\n", M);
	return 0;
}

void num2roman(int x, char *ans)
{
	ans[0] = '\0';
	if (x >= 1000) { strcat(ans, "M"); x -= 1000; }
	if (x >= 1000) { strcat(ans, "M"); x -= 1000; }
	if (x >= 1000) { strcat(ans, "M"); x -= 1000; }
	if (x >= 900) { strcat(ans, "CM"); x -= 900; }
	if (x >= 500) { strcat(ans, "D"); x -= 500; }
	if (x >= 400) { strcat(ans, "CD"); x -= 400; }
	if (x >= 100) { strcat(ans, "C"); x -= 100; }
	if (x >= 100) { strcat(ans, "C"); x -= 100; }
	if (x >= 100) { strcat(ans, "C"); x -= 100; }
	if (x >= 90) { strcat(ans, "XC"); x -= 90; }
	if (x >= 50) { strcat(ans, "L"); x -= 50; }
	if (x >= 40) { strcat(ans, "XL"); x -= 40; }
	if (x >= 10) { strcat(ans, "X"); x -= 10; }
	if (x >= 10) { strcat(ans, "X"); x -= 10; }
	if (x >= 10) { strcat(ans, "X"); x -= 10; }
	if (x >= 9) { strcat(ans, "IX"); x-= 9; }
	if (x >= 5) { strcat(ans, "V"); x -= 5; }
	if (x >= 4) { strcat(ans, "IV"); x -= 4; }
	if (x >= 1) { strcat(ans, "I"); x -= 1; }
	if (x >= 1) { strcat(ans, "I"); x -= 1; }
	if (x >= 1) { strcat(ans, "I"); x -= 1; }
}
