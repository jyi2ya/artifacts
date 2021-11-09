#include <stdio.h>
#include <string.h>

#define FULL 0
#define EMPTY 1

int a[10005];

int main(void){
	int L,M,trees=0;
	memset(a,FULL,sizeof(a));
	scanf("%d%d",&L,&M);
	while(M--){
		int i,j;
		scanf("%d%d",&i,&j);
		//printf("     -----New Data,i=%d,j=%d\n",i,j);
		if(i>j) {
			int u=i;i=j;j=u;
			//printf("     -----Sort Complete,i=%d,j=%d\n",i,j);
		}
		{
			//printf("     -----Setting a[u] as empty\n");
			int u;
			for(u=i;u<=j;u++){
				a[u]=EMPTY;
				//printf("     ----------a[%d] seted\n",u);
			}
		}
	}
	{
		int i;
		for(i=0;i<=L;i++)
			if(a[i]==FULL){
				//printf("     -----a[%d] is full\n",i);
				trees++;
			}
	}
	printf("%d",trees);
	return 0;
}
