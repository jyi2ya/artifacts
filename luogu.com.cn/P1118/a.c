#include <stdio.h>
#include <string.h>

int n,sum,now[20];
int trg[19][19],used[20];

void init(void);
int dfs(int pos,int nowsum);

int main(void){
	scanf("%d%d",&n,&sum);
	init();
	if(dfs(0,0)){
		int i;
		for(i=0;i<n;++i) printf("%d ",now[i]);
		putchar('\n');
	}
	return 0;
}

int dfs(int pos,int nowsum)
{
	int i;
	if(nowsum>sum) return 0;
	if(nowsum==sum && pos==n) return 1;
	if(pos==n) return 0;
	for(i=1;i<=n;++i)
		if(!used[i]){
			now[pos]=i;
			used[i]=1;
			if(dfs(pos+1,nowsum+i*trg[n][pos+1])) return 1;
			used[i]=0;
		}
	return 0;
}


void init(void)
{
	int i,j;
	trg[1][1]=1;
	for(i=2;i<19;++i){
		trg[i][1]=1;
		for(j=2;j<=i;++j)
			trg[i][j]=trg[i-1][j]+trg[i-1][j-1];
	}
}
