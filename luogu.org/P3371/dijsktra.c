#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100009
#define INF 0x7fffffff
#define DELETED 0x7fffffff

struct edge{
	int to,w;
	struct edge* next;
};
typedef struct edge edge;
edge graph[MAX];
edge* newedge(void);
void addedge(int from,int to,int w);

typedef struct{
	int id,d;
}heapnode;
heapnode heap[MAX];
int heaptop;
void insheap(int id,int d);
heapnode* topheap(void);
void delheap(void);
int isempty(void);
void swap(heapnode* a,heapnode* b);

void prtheap(void);
void prtgraph(void);

void read(void);
void init(void);

int d[MAX],done[MAX]; /* distance , vis */
int N,M,S;

int main(void)
{
	int i;
	init();
	read();
	d[S]=0;
	insheap(S,0);
	while(!isempty()){
		edge* i;
		int now=topheap()->id; delheap();
		if(done[now]) continue;
		done[now]=1;
		for(i=graph[now].next;i!=NULL;i=i->next){
			if(d[i->to] > d[now] + i->w){
				d[i->to] = d[now]+i->w;
				insheap(i->to, d[i->to]);
			}
		}
	}
	for(i=1;i<=N;++i) printf("%d ",d[i]);
	putchar('\n');
	return 0;
}

void read(void)
{
	int i;
	scanf("%d%d%d",&N,&M,&S);
	for(i=0;i<M;++i){
		int F,G,W;
		scanf("%d%d%d",&F,&G,&W);
		addedge(F,G,W);
	}
}
void init(void)
{
	int i;
	for(i=0;i<MAX;++i) d[i]=INF;
	memset(done,0,sizeof(done));
	heaptop=1;
}

void addedge(int from,int to,int w)
{
	edge* now=newedge();
	now->to=to;
	now->w=w;
	now->next=graph[from].next;
	graph[from].next=now;
}
edge* newedge(void)
{
	edge* r=(edge*)malloc(sizeof(edge));
	r->next=NULL;
	return r;
}

void swap(heapnode* a,heapnode* b)
{
	int id,d;
	id=a->id;    d=a->d;
	a->id=b->id; a->d=b->d;
	b->id=id;    b->d=d;
}
void insheap(int id,int d)
{
	int now=heaptop;
	heap[heaptop].id=id;
	heap[heaptop].d=d;
	while(((heap[now].d < heap[now>>1].d)||(heap[now>>1].d==DELETED)) && now>1){
		swap(heap+now, heap+(now>>1));
		now>>=1;
	}
	++heaptop;
}
heapnode* topheap(void)
{
	return heap+1;
}
void delheap(void)
{
	int now=1;
	heap[1].d=DELETED;
	while((now<<1)<heaptop){
		if((heap[(now<<1)+1].d < heap[now<<1].d) && ((now<<1)+1<heaptop)){
			swap(heap+(now<<1)+1,heap+now);
			now=(now<<1)+1;
		} else {
			swap(heap+(now<<1),heap+now);
			now<<=1;
		}
	}
	--heaptop;
	while(heap[heaptop].d==DELETED) --heaptop;
	++heaptop;
}
int isempty(void)
{
	return heaptop==1;
}

void prtgraph(void)
{
	int i;
	puts("graph");
	for(i=1;i<=N;++i) {
		edge* now;
		printf("%d :",i);
		for(now=graph[i].next;now!=NULL;now=now->next)
			printf("%d(%d) ",now->to,now->w);
		putchar('\n');
	}
}

void prtheap(void)
{
	int i;
	puts("heap:");
	for(i=1;i<heaptop;++i) printf("%d ",heap[i].d);
	putchar('\n');
}
