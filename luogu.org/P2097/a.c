#include <stdio.h>

#define MAX 400005
#define NODE_MAX 100005

int list[800005],next[MAX],tail[NODE_MAX],lsttop;
int vis[NODE_MAX];
int n,m;

void add(int a,int b){
	next[tail[a]]=lsttop;
	tail[a]=lsttop;
	list[lsttop++]=b;
}

void read(void){
	scanf("%d%d",&n,&m);
	lsttop=n+1;
	for(int i=0;i<=n;i++){
		tail[i]=i;
	       	list[i]=i;
	}
	for(int i=0;i<m;i++) {
		int p,q;
		scanf("%d%d",&p,&q);

		add(p,q);
		add(q,p);
	}
#ifdef DEBUG
	printf("lsttop=%d\n",lsttop);
	for(int i=1;i<=n;i++) {
		printf("%d:",i);
		int now=i;
		while(list[now]) {
			printf("%d ",list[now]);
			now=next[now];
		}
		putchar('\n');
	}
#endif

}

void dfs(int i){
	if(vis[i]) return ;
	vis[i]=1;
	int now=i;
	while(list[now]){
		dfs(list[now]);
		now=next[now];
	}
}

int main(void){
	read();
	int ans=0;
	for(int i=0;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) {
		if(!vis[i]) ans++;
		dfs(i);
	}
	printf("%d\n",ans);
	return 0;
}
