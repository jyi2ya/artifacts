#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100009

struct edge{
	int to,w;
	struct edge* next;
};
typedef struct edge edge;


edge* newedge(int to,int w);
void addedge(int from,edge* to);
void prtgraph(void);

edge* graph[MAX];

typedef struct{
	int to,w;
}heapnode;
heapnode heap[MAX];
int heaptop=1,heapsize=0;
void insheap(int x,int w);
void delheap(void);
heapnode* topheap(void);
int isheapempty(void);
void testheap(void);

void read(void);

int N,M,S;
int ans[MAX],done[MAX];

int main(void)
{
	int i;
	read();
	memset(ans,0x7f,sizeof(ans));
	insheap(S,0);
	while(!isheapempty()){
		heapnode* now=topheap();
		edge* i;
		if(done[now->to]){
			delheap();
			continue;
		}
		done[now->to]=1;
		ans[now->to]=now->w;
		for(i=graph[now->to];i!=NULL;i=i->next)
			if(ans[i->to]>ans[now->to]+i->w){
				ans[i->to]=ans[now->to]+i->w;
				insheap(i->to,ans[i->to]);
			}
		delheap();
	}
	for(i=1;i<=N;++i) printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}

void read(void)
{
	int i;
	scanf("%d%d%d",&N,&M,&S);
	for(i=0;i<M;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,newedge(v,w));
	}
}

/* heap {{{ */
void insheap(int to,int w)
{
	int now=heaptop;
	heap[heaptop].to=to;
	heap[heaptop].w=w;
	++heaptop;
	while(now>1){
		int cmp=now/2;
		if(heap[cmp].w>heap[now].w) {
			int t;
			t=heap[now].to; heap[now].to=heap[cmp].to; heap[cmp].to=t;
			t=heap[now].w; heap[now].w=heap[cmp].w; heap[cmp].w=t;
		}else{
			break;
		}
		now=cmp;
	}
	++heapsize;
}

void delheap(void)
{
	int now=1;
	heap[now].w=0x7f7f7f7f;
	while(now<<1 < heaptop){
		int cmp=now<<1;
		if(cmp+1<heaptop && heap[cmp+1].w<heap[cmp].w) ++cmp;
		heap[now].w=heap[cmp].w; heap[now].to=heap[cmp].to;
		heap[cmp].w=0x7f7f7f7f;
		now=cmp;
	}
	--heaptop;
	while(heap[heaptop].w==0x7f7f7f7f) --heaptop;
	++heaptop;
	--heapsize;
}

heapnode* topheap(void)
{
	return heap+1;
}

int isheapempty(void)
{
	return heapsize==0;
}

void testheap(void)
{
	int i;
	for(i=1;i<10;++i) insheap(0,i);
	for(i=20;i>0;--i) insheap(0,i);
	while(!isheapempty()){
		printf("%d ",topheap()->w);
		delheap();
	}
	putchar('\n');
	exit(EXIT_SUCCESS);
}
/* }}} */
/* list {{{ */
void addedge(int from,edge* to)
{
	if(graph[from]==NULL){
		graph[from]=to;
	} else {
		to->next=graph[from]->next;
		graph[from]->next=to;
	}
}

edge* newedge(int to,int w)
{
	edge* r=(edge*)malloc(sizeof(edge));
	r->next=NULL;
	r->to=to;
	r->w=w;
	return r;
}

void prtgraph(void)
{
	int i;
	for(i=1;i<=N;++i){
		edge* j;
		printf("%d:",i);
		for(j=graph[i];j!=NULL;j=j->next)
			printf("%d(%d) ",j->to,j->w);
		putchar('\n');
	}
}
/* }}} */
