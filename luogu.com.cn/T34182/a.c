#include <stdio.h>
#include <string.h>

int a[37],used[37],n;

void dfs(int maxd,int now);
void prt(void);

int main(void){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",a+i);
	for(i=1;i<=n;++i){
		memset(used,0,sizeof(used));
		dfs(i,0);
	}
	printf("%d\n",(1<<n)-1);
	return 0;
}

void dfs(int maxd,int now){
	int i;
	if(maxd==0){
		prt();
		return;
	}
	for(i=now;i<n;++i) {
		if(used[i]) continue;
		used[i]=1;
		dfs(maxd-1,i);
		used[i]=0;
	}
}

void prt(void){
	int i;
	for(i=0;i<n;++i)
		if(used[i])
			printf("%d ",a[i]);
	putchar('\n');
}
