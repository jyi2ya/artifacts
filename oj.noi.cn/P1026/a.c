#include <stdio.h>
#include <limits.h>

int main(void){
	int max=INT_MIN,min=INT_MAX,tot=0,i;
	for(i=0;i<10;++i){
		int a;
		scanf("%d",&a);
		tot+=a;
		if(a>max) max=a;
		if(a<min) min=a;
	}
	printf("%.3f\n",(double)(tot-max-min)/8);
	return 0;
}
