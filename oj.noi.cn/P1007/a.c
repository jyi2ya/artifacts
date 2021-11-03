#include <stdio.h>

int main(void){
	double a,b;
	int k;
	scanf("%lf%lf",&a,&b);
	for(k=0;b*k<=a;++k);
	printf("%.2f\n",a-b*(k-1));
	return 0;
}
