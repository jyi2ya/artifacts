#include <stdio.h>

int a[2007],N;
int dp[2007][2007];

int dfs(int ,int,int);
void read(void);
int max(int,int);

int main(void){
	read();
	int l,r;
	for(l=N-1;l>=0;--l)
		for(r=l;r<N;++r){
#ifdef DEBUG
			printf("N-l+R==%d\n",N-r+l);
#endif
			dp[l][r]=max(dp[l+1][r]+a[l]*(N-r+l),dp[l][r-1]+a[r]*(N-r+l));
		}
	printf("%d\n",dp[0][N-1]);
}

/*
int dfs(int l,int r,int time){
	if(dp[l][r]) return dp[l][r];
	if(l==r) return a[l]*time;
	dp[l][r]=max(dfs(l+1,r,time+1)+a[l]*time, dfs(l,r-1,time+1)+a[r]*time);
	return dp[l][r];
}
*/

void read(void){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;++i) scanf("%d",a+i);
}

int max(int a,int b){
	if(a>b) return a;
	return b;
}
