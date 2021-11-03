#include <stdio.h>
#include <math.h>

int main(void){
	float a,b,c,s;
	scanf("%f%f%f",&a,&b,&c);
	s = 0.5*(a+b+c);
	//	printf("%f",s);
	printf("%.4f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
	return 0;
}
