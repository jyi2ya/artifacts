#include <stdio.h>

int main(void){
	double x,y;
	scanf("%lf%lf",&x,&y);
	if(-1<=x && x<=1 && -1<=y && y<=1) puts("Yes");
	else puts("No");
	return 0;
}
