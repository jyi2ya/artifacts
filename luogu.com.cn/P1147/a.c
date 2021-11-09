#include <stdio.h>

int main(){
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int tot=0,j;
		for(j=i;tot<M;j++) tot+=j;
		if(tot==M)printf("%d %d\n",i,j-1);
	}
	return 0;
}
