#include <stdio.h>

int a[13][13],n;
int dp[13][13][13][13];

void read(){
	scanf("%d",&n);
	int x,y,z;
	while(scanf("%d%d%d",&x,&y,&z) && x!=0 && y!=0 && z!=0) a[x][y]=z;
#ifdef DEBUG
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) printf("%3d ",a[i][j]);
		putchar('\n');
	}
#endif
}

int max(int a,int b,int c,int d){
	int max=a;
	if(b>max)max=b;
	if(c>max)max=c;
	if(d>max)max=d;
	return max;
}

int main(){
	read();
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			for(int p=1;p<=n;p++)
				for(int q=1;q<=n;q++){
					if(i==p && j==q) dp[i][j][p][q]=max(dp[i-1][j][p-1][q],dp[i-1][j][p][q-1],dp[i][j-1][p-1][q],dp[i][j-1][p][q-1])+a[p][q];
					else dp[i][j][p][q]=max(dp[i-1][j][p-1][q],dp[i-1][j][p][q-1],dp[i][j-1][p-1][q],dp[i][j-1][p][q-1])+a[i][j]+a[p][q];
#ifdef DEBUG
					printf("f[%d][%d][%d][%d]=%d\n",i,j,p,q,dp[i][j][p][q]);
#endif
				}
	printf("%d\n",dp[n][n][n][n]);
	return 0;
}
