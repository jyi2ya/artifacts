#include <stdio.h>
#include <stdlib.h>

/* type */
struct node{
	int x,y,hour;
	struct node* next;
};
typedef struct node node;
/* end */

/* function */
/* queue */
void init(void);
node* newnode(void);
void push(node* x);
node* top(void);
void del(void);
int isempty(void);
/* end */

int isok(node* x);
/* end */

/* global */
int N,M,A,B,i;
node* head,*tail;
int vis[507][507],leaderx[250007],leadery[250007];
/* end */

/* constant */
#define LEADER -2
/* end */

int main(void)
{
	init();
	scanf("%d%d%d%d",&N,&M,&A,&B);
	for(i=0;i<A;++i) {
		int x,y;
		scanf("%d%d",&y,&x);
		--x;--y;
		node* now=newnode();
		now->x=x;now->y=y;now->hour=1;
		push(now);
	}
	for(i=0;i<B;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		leaderx[i]=x;
		leadery[i]=y;
	}
	while(!isempty()){
		node* now=top(),*nnode;
		int i,j;
		nnode=newnode();
		nnode->x = now->x+1;
		nnode->y = now->y;
		nnode->hour = now->hour+1;
		if(isok(nnode)) push(nnode);
		else free(nnode);
		
		nnode=newnode();
		nnode->x = now->x-1;
		nnode->y = now->y;
		nnode->hour = now->hour+1;
		if(isok(nnode)) push(nnode);
		else free(nnode);

		nnode=newnode();
		nnode->x = now->x;
		nnode->y = now->y+1;
		nnode->hour = now->hour+1;
		if(isok(nnode)) push(nnode);
		else free(nnode);

		nnode=newnode();
		nnode->x = now->x;
		nnode->y = now->y-1;
		nnode->hour = now->hour+1;
		if(isok(nnode)) push(nnode);
		else free(nnode);

		del();
	}
	for(i=0;i<B;++i) printf("%d\n",vis[leaderx[i]][leadery[i]]-1);
	return 0;
}

int isok(node* x)
{
	return x->x<M && x->x>=0 && x->y<=N && x->y>=0 && !vis[x->y][x->x];
}

void init(void)
{
	head=newnode();
	tail=head;
}

node* newnode(void)
{
	node* ret=(node*)malloc(sizeof(node));
	ret->x=0;
	ret->y=0;
	ret->hour=0;
	ret->next=NULL;
}

void push(node* now)
{
	vis[now->y][now->x]=now->hour;
	tail->next=now;
	tail=now;
}

node* top(void)
{
	return head->next;
}

void del(void)
{
	node* d=head->next;
	head->next=d->next;
	free(d);
}

int isempty(void)
{
	return head->next==NULL;
}
