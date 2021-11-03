#include <stdio.h>

int main(void)
{
	char buf[2000];
	int yes = 0, no = 0;
	while (scanf("%s", buf) == 1) {
		if (buf[0] == 'y')
			++yes;
		else
			++no;
	}
	if (yes > no)
		printf("yes");
	else
		printf("no");
	return 0;
}
