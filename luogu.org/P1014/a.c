#include <stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
#ifdef DEBUG
	int a;
	for(a=1;a<=100;a++){
		n=a;
#endif
	int i=0,j=0,ijsum=2,quit=0;

	while(quit!=1){
		for(i=ijsum-1;i>=1;i--){
			j=ijsum-i;
			n--;
			if(n==0){
				quit=1;
				break;
			}
		}
		ijsum++;
		if(quit)break;
		for(i=1;i<ijsum;i++){
			j=ijsum-i;
			n--;
			if(n==0){
				quit=1;
				break;
			}
		}
		ijsum++;
	}
	printf("%d/%d\n",i,j);
#ifdef DEBUG
	}
#endif
	return 0;
}
