#include <stdio.h>
#include <math.h>

int main(void){
	float R,X,P;
	scanf("%f%f%f",&R,&X,&P);
	printf("%.2f\n",X*pow(((100.0+R)/100.0),P));
	return 0;
}
