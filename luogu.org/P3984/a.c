#include <stdio.h>

int main(void){
	int N,T;
	scanf("%d%d",&N,&T);
	int now,tot=0;
	scanf("%d",&now);
	for(int i=1;i<N;i++){
		int next;
		scanf("%d",&next);
		if(next-now<T){
			tot+=next-now;
		       	now=next;
		}else {
			tot+=T;
			now=next;
		}
	}
	printf("%d\n",tot+T);
	return 0;
}
