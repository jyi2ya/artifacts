#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200007

typedef struct{
	int id,score,level;
}member;

member win[MAX],lose[MAX],list[MAX];
int N,N2,R,Q;

int cmp(const void* a,const void* b);

int main(void)
{
	int i;
	scanf("%d%d%d",&N,&R,&Q);
	N2=N*2;
	for(i=0;i<N2;++i) scanf("%d",&list[i].score);
	for(i=0;i<N2;++i) scanf("%d",&list[i].level);
	for(i=0;i<N2;++i) list[i].id=i+1;
	qsort(list,N2,sizeof(member),cmp);

	while(R--){
		int i,j,top=0;
		for(i=0;i<N2;i+=2){
			if(list[i].level > list[i+1].level) {
				++list[i].score;
				win[top].id=list[i].id;
				win[top].score=list[i].score;
				win[top].level=list[i].level;
				/* memcpy(win+top,list+i,sizeof(member)); */
				lose[top].id=list[i+1].id;
				lose[top].score=list[i+1].score;
				lose[top].level=list[i+1].level;
				/* memcpy(lose+top,list+i+1,sizeof(member)); */
			} else {
				++list[i+1].score;
				win[top].id=list[i+1].id;
				win[top].score=list[i+1].score;
				win[top].level=list[i+1].level;
				/* memcpy(win+top,list+i+1,sizeof(member)); */
				lose[top].id=list[i].id;
				lose[top].score=list[i].score;
				lose[top].level=list[i].level;
				/* memcpy(lose+top,list+i,sizeof(member)); */
			}
			++top;
		}

		i=0;j=0;top=0;
		while(i<N || j<N){
			if(i<N && (j>=N || cmp(win+i,lose+j) < 0)) {
				list[top].id=win[i].id;
				list[top].score=win[i].score;
				list[top].level=win[i].level;
				/* memcpy(list+top,win+i,sizeof(member)); */
				++top; ++i;
			}
			if(j<N && (i>=N || cmp(lose+j,win+i) < 0)) {
				list[top].id=lose[j].id;
				list[top].score=lose[j].score;
				list[top].level=lose[j].level;
				/* memcpy(list+top,lose+j,sizeof(member)); */
				++top; ++j;
			}
		}
	}
	printf("%d\n",list[Q-1].id);
	return 0;
}

int cmp(const void* a,const void* b)
{
	const member* p=a,*q=b;
	if(p->score==q->score) return p->id-q->id;
	return q->score-p->score;
}
