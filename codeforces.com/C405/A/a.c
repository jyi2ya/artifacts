#include <stdio.h>

int n,sort[1000];

int main(void){
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		++sort[x];
	}
	for(n=0;n<1000;++n){
		int i;
		for(i=0;i<sort[n];++i)
		       	printf("%d ",n);
	}
	putchar('\n');
	return 0;
}
