#include <stdio.h>

int a[505];
int dp[45005];

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int H,N;
	scanf("%d%d",&H,&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N;i++){
		for(int j=H;j>=0;j--){
			if(j-a[i]<0) dp[j]=dp[j];
			else dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		}
#ifdef DEBUG
		printf("dp[]:");
		for(int i=0;i<=H;i++) printf("%d ",dp[i]);
		putchar('\n');
#endif
	}
	printf("%d\n",dp[H]);
	return 0;
}
