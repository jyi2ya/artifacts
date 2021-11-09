#include <stdio.h>

char buf[10];
int used[10],n;

void dfs(int x){
	if(x==n){
		for(int i=0;i<n;i++){
			printf("%5d",buf[i]);
		}
		putchar('\n');
		return ;
	}
	for(int i=1;i<=n;i++) if(!used[i]){
		used[i]=1;
		buf[x]=i;
		dfs(x+1);
		used[i]=0;
	}
}

int main(){
	scanf("%d",&n);
	dfs(0);
	return 0;
}
