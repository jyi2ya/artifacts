#include <stdio.h>

int coin[105];

int main(){
	int N;
	scanf("%d",&N);
	printf("%d\n",N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(j!=i) coin[j]=coin[j]==1?0:1;
			printf("%d",coin[j]);
		}
		putchar('\n');
	}
	return 0;
}
