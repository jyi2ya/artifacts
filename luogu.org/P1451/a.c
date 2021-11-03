#include <stdio.h>
#include <string.h>

int a[103][103],ans,vis[103][103],m,n;

void dfs(int i,int j);


int main(void){
	int i,j;
	scanf("%d%d",&m,&n);
	memset(vis,0,sizeof(vis));
	for(i=0;i<m;++i){
		while(getchar()!='\n');
		for(j=0;j<n;++j) a[i][j]=getchar();
	}
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			if(!vis[i][j] && a[i][j]!='0'){
				++ans;
				dfs(i,j);
			}
	printf("%d\n",ans);
	return 0;
}

void dfs(int i,int j){
	if(vis[i][j] || i>=m || i<0 || j>=n || j<0
			|| a[i][j]=='0') return;
	vis[i][j]=1;
	dfs(i+1,j);
	dfs(i,j+1);
	dfs(i-1,j);
	dfs(i,j-1);
}
