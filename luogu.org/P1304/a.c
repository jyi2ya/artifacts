#include <stdio.h>

#define MAX 10005
#define YES 0
#define NO  1

int prime[MAX],a[MAX],num=0;

void prim(){
	a[0]=NO;
	a[1]=NO;
	for(int i=2;i<MAX;i++){
		if(a[i]==YES) prime[num++]=i;
		for(int j=0;j<num && i*prime[j]<MAX;j++){
			a[prime[j]*i]=NO;
			if(i%prime[j]==0) break;
		}
	}
}


int main(){
	prim();
	int n;
	scanf("%d",&n);
	for(int i=4;i<=n;i+=2){
		int j;
		for(j=0;j<num;j++) if(a[i-prime[j]]==YES) break;
		printf("%d=%d+%d\n",i,prime[j],i-prime[j]);
	}
	return 0;
}
