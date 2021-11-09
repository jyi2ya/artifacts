#include <stdio.h>

int C[105],B[105],A[105];
int dp[1005][1005];

int max(int a,int b){return a>b?a:b;}

int main(void){
	int M,X,N;
	scanf("%d%d%d",&N,&M,&X);
	for(int i=0;i<N;i++) scanf("%d%d%d",A+i,B+i,C+i);
	for(int i=0;i<N;i++){
		for(int j=M;j>=0;j--)
			for(int k=X;k>=0;k--){
				if(j<B[i] || k<C[i]) dp[j][k]=dp[j][k];
				else dp[j][k]=max(dp[j][k],dp[j-B[i]][k-C[i]]+A[i]);
			}
	}
	printf("%d\n",dp[M][X]);
	return 0;
}
