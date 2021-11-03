#include <stdio.h>

#define MAX 109

int dp[209][209][109]; /* money,time,kth */
int money[209],time[209],M,T,n;

int min(int ,int );

int main(void){
	int i,j,k;
	setvbuf(stdout,NULL,_IONBF,0);
	scanf("%d%d%d",&n,&M,&T);
	for(i=0;i<n;++i) scanf("%d%d",money+i,time+i);
	for(i=0;i<=M;++i){
		for(j=0;j<=T;++j){
			for(k=n-1;k>=0;--k){
				if(i<money[k] || j<time[k]){
					dp[i][j][k]=dp[i][j][k+1];
				}else {
					dp[i][j][k]=min(dp[i-money[k]][j-time[k]][k+1]+1,dp[i][j][k+1]);
				}
			}
		}
	}
	printf("%d\n",dp[M][T][0]);
	return 0;
}

int min(int a,int b)
{
	if(a>b) return a;
	return b;
}
