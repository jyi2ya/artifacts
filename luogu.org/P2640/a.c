#include <stdio.h>

int isprim[10005];
int prim[10005],top=0;

void init(void){
	for(int i=0;i<10005;i++) isprim[i]=1;
	isprim[0]=isprim[1]=0;
	for(int i=2;i<10005;i++){
		if(isprim[i]) prim[top++]=i;
		for(int j=0;j<top && i*prim[j]<10005;j++){
			isprim[i*prim[j]]=0;
			if(i%prim[j]==0) break;
		}
	}
}

int main(void){
	init();
	int n,k;
	int noans=1;
	scanf("%d%d",&n,&k);
	for(int i=0;i<top && prim[i]+k<=n;i++){
		if(isprim[prim[i]+k]) {
			noans=0;
			printf("%d %d\n",prim[i],prim[i]+k);
		}
	}
	if(noans) printf("empty\n");
	return 0;
}
