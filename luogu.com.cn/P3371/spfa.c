#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct edge{
    int to;
    long long w;
    struct edge* next;
};
typedef struct edge edge;
edge* graph[10009];
void read(void);

typedef struct{
    int pos;
    long long w;
}node;
node que[1000009];
void que_ins(int pos,long long w);
node* que_top(void);
void que_del(void);
int que_empty(void);

int N,M,S;
long long ans[10009];

void init_ans(void);

int main(void)
{
    int i;
    read();
    init_ans();
    que_ins(S,0);
    while(!que_empty()){
        node* now=que_top();
        edge *j;
        if(now->w < ans[now->pos]) ans[now->pos]=now->w;
        for(j=graph[now->pos];j!=NULL;j=j->next)
            if(j->w + now->w < ans[j->to]){
                ans[j->to]=j->w+now->w;
                que_ins(j->to,ans[j->to]);
            }
        que_del();
    }
    for(i=1;i<=N;++i) printf("%lld ",ans[i]);
    putchar('\n');
    return 0;
}

void init_ans(void)
{
    int i;
    for(i=1;i<=N;++i) ans[i]=2147483647;
}

/* queue {{{ */
node *bot=que-1,*top=que,*start=que,*end=que+1000009;

int que_empty(void)
{
    node* n=bot+1;
    if(n==end) n=start;
    return n==top;
}

void que_ins(int pos,long long w)
{
    top->w=w;
    top->pos=pos;
    ++top;
    if(top==end) top=start;
}

node* que_top(void)
{
    return bot+1;
}

void que_del(void)
{
    ++bot;
    if(bot==end) bot=start;
}
/* }}} */

/* graph {{{ */
void addedge(int from,int to,long long w);
edge* newedge(int to,long long w);
void prtgrp(void);

void read(void)
{
    int i;
    scanf("%d%d%d",&N,&M,&S);
    for(i=0;i<M;++i){
        int u,v,w;
           	scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
}

void addedge(int from,int to,long long w)
{
    edge* n=newedge(to,w);
    if(graph[from]==NULL) graph[from]=n;
    else {
        n->next=graph[from]->next;
        graph[from]->next=n;
    }
}

edge edge_pool[1000009],*edge_pool_top=edge_pool;
edge* newedge(int to,long long w)
{
    edge* r=edge_pool_top;
    ++edge_pool_top;
    r->to=to;
    r->w=w;
    r->next=NULL;
    return r;
}

void prtgrp(void)
{
    int i;
    for(i=1;i<=N;++i) {
        edge* j;
        printf("[%d]:",i);
        for(j=graph[i];j!=NULL;j=j->next)
            printf("%d ",j->to);
        putchar('\n');
    }
}
/* }}} */