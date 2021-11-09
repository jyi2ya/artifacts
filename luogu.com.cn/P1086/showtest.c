#include <stdio.h>

int main(void){
	int M,N,T;
	scanf("%d%d%d",&M,&N,&T);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			int m;
			scanf("%d",&m);
			printf("%-3d ",m);
		}
		putchar('\n');
	}
	return 0;
}
