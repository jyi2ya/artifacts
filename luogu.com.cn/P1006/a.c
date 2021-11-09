#include <stdio.h>

int m,n,a[55][55];
int dp[55][55][55][55];

void read(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++) 
			scanf("%d",&a[i][j]);
#ifdef DEBUG
	for(int i=0;i<=m+1;i++){
		for(int j=0;j<=n+1;j++) printf("%3d ",a[i][j]);
		putchar('\n');
	}
#endif
}

int max(int a,int b,int c,int d){
	if(a<b)a=b;
	if(a<c)a=c;
	if(a<d)a=d;
	return a;
}

int main(){
	read();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int p=1;p<=m;p++)
				for(int q=1;q<=n;q++){
					if(i==p && j==q) dp[i][j][p][q]=max(\
							dp[i-1][j][p-1][q],\
							dp[i][j-1][p-1][q],\
							dp[i-1][j][p][q-1],\
							dp[i][j-1][p][q-1])\
						       +a[i][j];
					else dp[i][j][p][q]=max(\
							dp[i-1][j][p-1][q],\
							dp[i][j-1][p-1][q],\
							dp[i-1][j][p][q-1],\
							dp[i][j-1][p][q-1])\
						       +a[i][j]+a[p][q];
				}
	printf("%d\n",dp[m][n][m][n]);
	return 0;
}
