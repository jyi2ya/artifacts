#include <stdio.h>

int a[35][35],n;

void read(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d",a[i]+j);
			if(a[i][j]==0)a[i][j]=2;
		}
#ifdef DEBUG
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) printf("%d ",a[i][j]);
		putchar('\n');
	}
#endif
}

void dfs(int x,int y){
	if(a[x][y]==1 || a[x][y]==0 || x<0 || y<0 || x>=n || y>=n) return;
	a[x][y]=0;
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
}

int main(){
	read();
	for(int i=0;i<n;i++) dfs(0,i);
	for(int i=0;i<n;i++) dfs(i,0);
	for(int i=0;i<n;i++) dfs(n-1,i);
	for(int i=0;i<n;i++) dfs(i,n-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) printf("%d ",a[i][j]);
		putchar('\n');
	}
	return 0;
}
