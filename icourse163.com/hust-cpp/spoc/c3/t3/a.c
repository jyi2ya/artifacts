#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>

int main(void)
{
	double x;

	scanf("%lf", &x);
	if (x < 1000) {
		printf("税率r=0%%,奖金值n=%.2f,实际所得奖金s=%.2f\n", x, x);
	} else if (x < 3000) {
		printf("税率r=3%%,奖金值n=%.2f,实际所得奖金s=%.2f\n", x, x * (1 - 0.03));
	} else if (x < 5000) {
		printf("税率r=5%%,奖金值n=%.2f,实际所得奖金s=%.2f\n", x, x * (1 - 0.05));
	} else if (x < 10000) {
		printf("税率r=7%%,奖金值n=%.2f,实际所得奖金s=%.2f\n", x, x * (1 - 0.07));
	} else {
		printf("税率r=10%%,奖金值n=%.2f,实际所得奖金s=%.2f\n", x, x * (1 - 0.1));
	}
	return 0;
}
