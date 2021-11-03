#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 407

struct node{
	int x,y,step;
	struct node* next;
};
typedef struct node node;

node *head,*tail;
int vis[MAX][MAX],n,m;

void init(void);
node* newnode(void);
void addnode(int x,int y,int step);

void add(node* n);
node* top(void);
void del(void);
int isempty(void);

int main(void)
{
	int x,y;
	init();
	scanf("%d%d%d%d",&n,&m,&y,&x);
	--x;--y;
	addnode(x,y,0);
	while(!isempty()){
		node* now=top();
		if(now->x >= m || now->y >=n
				|| now->x <0 ||now->y <0
				|| vis[now->y][now->x] != -1){
			del();
			continue;
		}

		vis[now->y][now->x]=now->step;

		addnode(now->x+1,now->y+2,now->step+1);
		addnode(now->x+1,now->y-2,now->step+1);
		addnode(now->x-1,now->y+2,now->step+1);
		addnode(now->x-1,now->y-2,now->step+1);
		addnode(now->x+2,now->y+1,now->step+1);
		addnode(now->x+2,now->y-1,now->step+1);
		addnode(now->x-2,now->y+1,now->step+1);
		addnode(now->x-2,now->y-1,now->step+1);

		del();
	}
	for(x=0;x<n;++x){
		for(y=0;y<m;++y) printf("%-5d",vis[x][y]);
		putchar('\n');
	}
	return 0;
}

void addnode(int x,int y,int step)
{
	node* a=newnode();
	a->x=x;a->y=y;a->step=step;
	add(a);
}

void init(void)
{
	memset(vis,-1,sizeof(vis));
	head=newnode();
	tail=head;
}

node* newnode(void)
{
	node* r=(node*)malloc(sizeof(node));
	r->x=0;
	r->y=0;
	r->step=0;
	r->next=NULL;
	return r;
}

void add(node* n)
{
	tail->next=n;
	tail=n;
}

node* top(void)
{
	return head->next;
}

void del(void)
{
	node* d=top();
	head->next=d->next;
	free(d);
}

int isempty(void)
{
	return head->next==NULL;
}
