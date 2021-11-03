#include <stdio.h>

int a[101][10005];
int M,N,ans=0;
int n[105];

void read(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",n+i);
}

int dfs(int sum,int now){
#ifdef DEBUG
	printf("sum=%d,now=%d\n",sum,now);
#endif
	if(sum>M || now>N)return 0;
	if(sum==M)return 1;
	if(a[now][sum])return a[now][sum];
	a[now][sum]=dfs(sum+n[now],now+1)+dfs(sum,now+1);
	return a[now][sum];
}

int main(){
	read();
	printf("%d\n",dfs(0,0));
	return 0;
}
