#include <stdio.h>
#include <stdlib.h>

#define MAX 1000009

int a[MAX],que[MAX];

int main(void)
{
	int N,M,i,bot=0,top=0;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;++i){
		int windowbegin=i-M+1;
		scanf("%d",a+i);
		while(a[que[top-1]]>a[i] && top>bot) --top;
		que[top++]=i;
		while(que[bot]<windowbegin && bot<top) ++bot;
		if(windowbegin>=0) printf("%d\n",a[que[bot]]);
	}
	return 0;
}
