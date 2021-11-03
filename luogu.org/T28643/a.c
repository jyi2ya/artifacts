#include <stdio.h>

int T[105],RP[105],Fun[105];
int dp[1005][1005];

int max(int a,int b){return a>b?a:b;}

int main(void){
	int m,n,R,P,low;
	scanf("%d%d%d%d%d",&m,&n,&R,&P,&low);
	R+=P*m;
	for(int i=0;i<n;i++) scanf("%*s%d%d%d",Fun+i,T+i,RP+i);
	for(int i=0;i<n;i++){
		for(int j=R;j>=0;j--)
			for(int k=m;k>=0;k--){
				if(j<RP[i] || k<T[i]) dp[j][k]=dp[j][k];
				else dp[j][k]=max(dp[j][k],dp[j-RP[i]][k-T[i]]+Fun[i]);
			}
	}
	printf("%d\n",dp[R][m]);
	return 0;
}
