#include <stdio.h>
#include <string.h>

#define MAX 1007

int dfs(int x,int y,int now); /* now==1 || now==0 */
int update(int x,int y,int now,int a);

int maze[MAX][MAX],vis[MAX][MAX],ans[MAX][MAX],n,m;

int main(void)
{
	int i,j;
	scanf("%d%d",&n,&m);
	while(getchar()!='\n');
	for(i=0;i<n;++i){
		for(j=0;j<n;++j) maze[i][j]=getchar()-'0';
		while(getchar()!='\n');
	}
	for(i=0;i<n;++i)
		for(j=0;j<n;++j){
			if(ans[i][j]) continue;
			else update(i,j,maze[i][j],dfs(i,j,maze[i][j]));
		}
	for(i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		printf("%d\n",ans[x][y]);
	}
	return 0;
}

int dfs(int x,int y,int now)
{
	if(x<0 || x>=n || y<0 || y>=n) return 0;
	if(vis[x][y]) return 0;
	if(maze[x][y]!= now) return 0;
	vis[x][y]=1;

	return dfs(x+1,y,!now)+dfs(x-1,y,!now)+dfs(x,y+1,!now)+dfs(x,y-1,!now)+1;
}

int update(int x,int y,int now,int a)
{
	if(x<0 || x>=n || y<0 || y>=n) return 0;
	if(ans[x][y]) return 0;
	if(maze[x][y] != now) return 0;
	ans[x][y]=a;

	update(x+1,y,!now,a);
	update(x-1,y,!now,a);
	update(x,y+1,!now,a);
	update(x,y-1,!now,a);
}
