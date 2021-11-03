#include <stdio.h>

int item[35];
int dp[20005];
int max(int a,int b){return a>b?a:b;}

int main(void){
	int V,n;
	scanf("%d%d",&V,&n);
	for(int i=0;i<n;i++) scanf("%d",item+i);
	for(int i=0;i<n;i++)
		for(int j=V;j>=0;j--){
			if(j<item[i]) dp[j]=dp[j];
			else dp[j]=max(dp[j],dp[j-item[i]]+item[i]);
		}
	printf("%d\n",V-dp[V]);
	return 0;
}
