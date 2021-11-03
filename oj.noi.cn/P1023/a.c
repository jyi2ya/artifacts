#include <stdio.h>
#include <limits.h>

int main(void){
	int n,max=INT_MIN,min=INT_MAX;
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);
		if(a>max) max=a;
		if(a<min) min=a;
	}
	printf("%d\n",max-min);
	return 0;
}
