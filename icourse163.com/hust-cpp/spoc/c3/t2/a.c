#if 0
cc -std=c89 -Wall -Werror -Wshadow -lm -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>
#include <math.h>

#define EPS 1e-6
#define EQU(a, b) (-EPS <= (a) - (b) && (a) - (b) <= EPS)
#define swap(a, b) do { \
	double swap_tmp_apsijvio = a; \
	a = b; \
	b = swap_tmp_apsijvio; \
} while (0)

int main(void)
{
	double a, b, c;
	double s;

	scanf("%lf%lf%lf", &a, &b, &c);
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);

	if (a + b <= c || EQU(a + b, c)) {
		puts("不构成三角形");
		return 0;
	}

	s = (a + b + c) / 2;
	printf("area=%.2f\n", sqrt(s * (s - a) * (s - b) * (s - c)));

	if (EQU(a, b) && EQU(a, c) && EQU(b, c))
		puts("等边三角形");
	else if (EQU(a, b) || EQU(a, c) || EQU(b, c)) {
		if (EQU(a * a + b * b, c * c))
			puts("等腰直角三角形");
		else
			puts("等腰三角形");
	} else if (EQU(a * a + b * b, c * c)) {
		puts("直角三角形");
	} else {
		puts("一般三角形");
	}

	return 0;
}
