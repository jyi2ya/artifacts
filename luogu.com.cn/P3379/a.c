#include <stdio.h>
#include <stdlib.h>

#define MAX 500009

int N,M,S;

struct edge{
	int to;
	struct edge* next;
};
typedef struct edge edge;
edge graph[MAX];
edge* newedge(int to);
void addedge(int from,int to);

int N,M,S;
int fa[MAX],d[MAX],g[32][MAX]; /* father,depth,grand */

void read(void);
void build(int now,int depth);
int intlog(int x);

int main(void)
{
	int i,j;
	read();
	build(S,1);
	while(M--){
		int a,b,key,i;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}

int lca(int a,int b)
{
	int i;
	if(d[a]<d[b]) {int t=a;a=b;b=t;}
	for(i=intlog(d[a]-d[b])+1;i>=0;--i){
		if(d[g[i][a]] >= d[b])
			a=g[i][a];
		if(d[a]==d[b]) break;
	}
	if(a==b) return a;
	for(i=intlog(d[a])+1;i>=0;--i){
		if(g[i][a]!=g[i][b]){
			a=g[i][a];
			b=g[i][b];
		}
		if(fa[a]==fa[b]) break;
	}
	return fa[a];
}

void build(int now,int depth)
{
	edge* i;
	int j;
	d[now]=depth;
	g[0][now]=fa[now];
	for(j=1;(1<<j)<=depth;++j)
		g[j][now]=g[j-1][g[j-1][now]];
	for(i=graph[now].next;i!=NULL;i=i->next){
		if(i->to == fa[now]) continue;
		fa[i->to]=now;
		build(i->to,depth+1);
	}
}

void read(void)
{
	int i;
	scanf("%d%d%d",&N,&M,&S);
	--N;
	for(i=0;i<N;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	/*
	   for(i=1;i<=N;++i){
	   edge* j;
	   printf("%d:",i);
	   for(j=graph[i].next;j!=NULL;j=j->next) 
	   printf("%d ",j->to);
	   putchar('\n');
	   }
	   */
}

void addedge(int from,int to)
{
	edge* n=newedge(to);
	n->next=graph[from].next;
	graph[from].next=n;
}

edge* newedge(int to)
{
	edge* r=(edge*)malloc(sizeof(edge));
	r->to=to;
	r->next=NULL;
	return r;
}

int intlog(int a)
{
	/* return (int)log2(a); */
	if(a<=0x1) return 0;
	if(a<=0x2) return 1;
	if(a<=0x4) return 2;
	if(a<=0x8) return 3;
	if(a<=0x10) return 4;
	if(a<=0x20) return 5;
	if(a<=0x40) return 6;
	if(a<=0x80) return 7;
	if(a<=0x100) return 8;
	if(a<=0x200) return 9;
	if(a<=0x400) return 10;
	if(a<=0x800) return 11;
	if(a<=0x1000) return 12;
	if(a<=0x2000) return 13;
	if(a<=0x4000) return 14;
	if(a<=0x8000) return 15;
	if(a<=0x10000) return 16;
	if(a<=0x20000) return 17;
	if(a<=0x40000) return 18;
	if(a<=0x80000) return 19;
	if(a<=0x100000) return 20;
	if(a<=0x200000) return 21;
	if(a<=0x400000) return 22;
	if(a<=0x800000) return 23;
	if(a<=0x1000000) return 24;
	if(a<=0x2000000) return 25;
	if(a<=0x4000000) return 26;
	if(a<=0x8000000) return 27;
	if(a<=0x10000000) return 28;
	if(a<=0x20000000) return 29;
	if(a<=0x40000000) return 30;
	if(a<=0x80000000) return 31;
	return 32;
}
