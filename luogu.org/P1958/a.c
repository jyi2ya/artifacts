#include <stdio.h>

int dp[20][20];

int main(void){
	int a,b,N;
	scanf("%d%d%d",&a,&b,&N);
	while(N--){
		int x,y;
		scanf("%d%d",&x,&y);
		dp[y][x]=-1;
	}
	for(int i=1;i<=b;i++)
		for(int j=1;j<=a;j++){
			if(i==1 && j==1) dp[i][j]=1;
			else if(dp[i][j]==-1) dp[i][j]=0;
			else dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
#ifdef DEBUG
	for(int i=1;i<=b;i++){
		for(int j=1;j<=a;j++){
			printf("%d ",dp[i][j]);
		}
		putchar('\n');
	}
#endif
	printf("%d\n",dp[b][a]);
	return 0;
}
