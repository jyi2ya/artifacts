#include <stdio.h>

int main(void){
	double x;
	scanf("%lf",&x);
	if(x<5) printf("%.3f\n",x+2.5);
	else if(x<10) printf("%.3f",2-1.5*(x-3)*(x-3));
	else if(x<20) printf("%.3f",x/2-1.5);
	return 0;
}
