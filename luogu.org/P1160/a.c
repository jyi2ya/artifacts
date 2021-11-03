#include <stdio.h>
#include <stdlib.h>

#define MAX 100007

struct node{
	int x;
	struct node* pre,*next;
};
typedef struct node node;

void ins(node* now,node* pre);
void del(node* now);
void init(void);
node* newnode(int x);

node* head,*q[MAX],*tail;

int main(void)
{
	int N,M,i;
	scanf("%d",&N);
	head=newnode(0);
	tail=newnode(0);
	head->next=tail;
	tail->pre=head;
	node* now=newnode(1);
	ins(now,head);
	for(i=2;i<=N;++i){
		int who,type;
		scanf("%d%d",&who,&type);
		now=newnode(i);
		if(type) ins(now,q[who]);
		else ins(now,q[who]->pre);
	}
	scanf("%d",&M);
	for(i=0;i<M;++i){
		int x;
		scanf("%d",&x);
		del(q[x]);
	}
	for(now=head->next;now!=tail;now=now->next)
		printf("%d ",now->x);
	putchar('\n');
	return 0;
}

void ins(node* now,node* pre)
{
	now->next=pre->next;
	now->next->pre=now;
	pre->next=now;
	now->pre=pre;
	q[now->x]=now;
}

void del(node* now)
{
	if(now==NULL) return;
	now->pre->next=now->next;
	now->next->pre=now->pre;
	q[now->x]=NULL;
	free(now);
}

node* newnode(int x)
{
	node* r=(node*)malloc(sizeof(node));
	r->x=x;
	r->pre=NULL;
	r->next=NULL;
}
