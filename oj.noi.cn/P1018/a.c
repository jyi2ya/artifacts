#include <stdio.h>

int main(void){
	double a;
	scanf("%lf",&a);
	if(a<=0.5) puts("3");
	else printf("%d\n",(int)((a-0.4)/0.2+3));
	return 0;
}
