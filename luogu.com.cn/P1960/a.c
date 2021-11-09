#include <stdio.h>
#include <stdlib.h>

#define MAX 5009

struct edge{
	int to;
	struct edge* next;
};
typedef struct edge edge;

edge graph[MAX];
int vis[MAX],out[MAX],N,M,top=1,topo[MAX],x;

edge* newedge(int to);
void addedge(int from,int to);
void read(void);
void dfs(int now);

int main(void)
{
	int i;
	read();
	for(i=1;i<=N;++i) dfs(i);
	for(i=N;i>=1;--i) printf("%d\n",topo[i]);
	printf("%d\n",x);
	return 0;
}

void dfs(int now)
{
	if(vis[now]==1) return;
	else{
		edge* i;
		int tot=0;
		vis[now]=-1;
		for(i=graph[now].next;i!=NULL;i=i->next){
			if(!out[i->to]) ++tot;
			dfs(i->to);
		}
		if(tot>1) x=1;
		vis[now]=1;
		topo[top++]=now;
	}
}


void read(void)
{
	int i;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(a,b);
		++out[a];
	}
}

edge* newedge(int to)
{
	edge* r=(edge*)malloc(sizeof(edge));
	r->to=to;
	r->next=NULL;
	return r;
}

void addedge(int from,int to)
{
	edge* n=newedge(to);
	n->next=graph[from].next;
	graph[from].next=n;
}
