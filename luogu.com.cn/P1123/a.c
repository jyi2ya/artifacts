#include <stdio.h>
#include <string.h>

int N,M;
int a[9][9],cannot[9][9];

void read(void);
long long dfs(int x,int y);
void edit(int x,int y,int add);

int main(void)
{
	int T;
#ifdef DEBUG
	freopen("in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		long long ans=0,ret;
		int i,j;
		read();
		for(i=0;i<N;++i)
			for(j=0;j<M;++j){
				ret=dfs(i,j);
				if(ret > ans) ans=ret;
			}
		printf("%lld\n",ans);
	}
	return 0;
}

long long dfs(int x,int y)
{
	long long ans=0,ret;
	int i,j;

	if(cannot[x][y]) return 0;

	edit(x,y,+1);
	for(i=y;i<M;++i) {
		ret=dfs(x,i);
		if(ret+a[x][y] > ans) ans=ret+a[x][y];
	}
	for(i=x+1;i<N;++i)
		for(j=0;j<M;++j){
			ret=dfs(i,j);
			if(ret+a[x][y] > ans) ans=ret+a[x][y];
		}
	edit(x,y,-1);

	return ans;
}

void edit(int x,int y,int add)
{
	if(x-1>=0){
		if(y-1>=0) cannot[x-1][y-1]+=add;
		cannot[x-1][y]+=add;
		cannot[x-1][y+1]+=add;
	}
	if(y-1>=0) cannot[x][y-1]+=add;
	cannot[x][y]+=add;
	cannot[x][y+1]+=add;
	if(y-1>=0) cannot[x+1][y-1]+=add;
	cannot[x+1][y]+=add;
	cannot[x+1][y+1]+=add;
}

void read(void)
{
	int i,j;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;++i) 
		for(j=0;j<M;++j)
			scanf("%d",a[i]+j);
}
