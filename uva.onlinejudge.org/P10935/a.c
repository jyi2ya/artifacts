#include <stdio.h>

/* function */
void push(int x);
int pop(void);
int size(void);
void init(int n);
/* end */

/* constant */
#define MAX 1000009
/* end */

/* global */
int que[MAX],top=0,bot=-1;
/* end */

int main(void)
{
	int n;
	while(scanf("%d",&n)==1 && n){
		int first=1;
		init(n);
		printf("Discarded cards:");
		while(size()!=1){
			if(!first) putchar(','); else first=0;
			printf(" %d",pop());
			push(pop());
		}
		printf("\nRemaining card: %d\n",pop());
	}
	return 0;
}

void init(int n)
{
	int i;
	for(i=1;i<=n;++i) push(i);
}

void push(int x)
{
	que[top++]=x;
}

int pop(void)
{
	return que[++bot];
}

int size(void)
{
	return top-bot-1;
}
