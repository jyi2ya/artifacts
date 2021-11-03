#include <stdio.h>
#include <string.h>

int prime[10000000],primtop=0;
unsigned char isprim[10000007];

int main(void){
	int i,j,N,M;
	scanf("%d%d",&N,&M);
	memset(isprim,1,sizeof(char)*10000007);
	isprim[0]=0;
	isprim[1]=0;
	for(i=2;i<10000000;++i){
		if(isprim[i]) prime[primtop++]=i;
		for(j=0;j<primtop && i*prime[j]<10000000;++j){
			isprim[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		}
	}
	while(M--){
		int x;
		scanf("%d",&x);
		if(isprim[x]) puts("Yes");
		else puts("No");
	}
	return 0;
}
