#include <stdio.h>
#include <stdlib.h>

int level[100005],diff[100005],N,K;

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main(void){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%d",level+i);
	qsort(level, N, sizeof(int), cmp);
	for(int i=1;i<N;i++) diff[i-1]=level[i]-level[i-1];
	qsort(diff, N - 1, sizeof(int), cmp);
	int ans=0;
	for(int i=0;i<K;i++) ans+=diff[i];
	printf("%d\n",ans);
	return 0;
}
