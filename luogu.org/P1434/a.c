#include <stdio.h>

void read(void);
int dfs(int i,int j);

int r,c;
int a[109][109];
int ans[109][109];

int main(void)
{
	int i,j,finalans=0;
#ifdef DEBUG
	freopen("in","r",stdin);
#endif
	read();
	for(i=0;i<r;++i)
		for(j=0;j<c;++j){
			ans[i][j]=dfs(i,j);
			if(finalans < ans[i][j]) finalans=ans[i][j];
		}
	printf("%d\n",finalans);
	return 0;
}

int dfs(int i,int j)
{
	int max=0,ret=0;
	if(i>=r || j>=c || i<0 || j<0) return 0;
	if(ans[i][j]) return ans[i][j];

	if(a[i][j+1] > a[i][j]) ret=dfs(i,j+1);
	if(ret>max) max=ret;
	if(a[i][j-1] > a[i][j]) ret=dfs(i,j-1);
	if(ret>max) max=ret;
	if(a[i+1][j] > a[i][j]) ret=dfs(i+1,j);
	if(ret>max) max=ret;
	if(a[i-1][j] > a[i][j]) ret=dfs(i-1,j);
	if(ret>max) max=ret;

	return ans[i][j]=max+1;
}

void read(void)
{
	int i,j;
	scanf("%d%d",&r,&c);
	for(i=0;i<r;++i)
		for(j=0;j<c;++j)
			scanf("%d",a[i]+j);
}
