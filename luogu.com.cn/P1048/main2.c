#include <stdio.h>

int med[105],tim[105],dp[1005];

int max(int a,int b){
#ifdef DEBUG
	printf("max:%d,%d\n",a,b);
#endif
       	return a>b?a:b;
}

int main(void){
	int T,M;
	scanf("%d%d",&T,&M);
	for(int i=0;i<M;i++) scanf("%d%d",tim+i,med+i);
#ifdef DEBUG
	printf("T=%d,M=%d\n",T,M);
#endif
	for(int i=0;i<M;i++){
		for(int j=T;j>=0;j--){
			if(j<tim[i]) dp[j]=dp[j];
			else dp[j]=max(dp[j],dp[j-tim[i]]+med[i]);
		}
	}
	printf("%d\n",dp[T]);
	return 0;
}
