#include <stdio.h>
#include <stdlib.h>

int a[410];

int cmp(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}

int main(void){
	int M,N;
	scanf("%d%d%*d",&M,&N);
	for(int i=0;i<M*N;i++) scanf("%d",a+i);
	qsort(a,N*M,sizeof(int),cmp);
	for(int i=0;i<M*N;i++) printf("%d ",a[i]);
	return 0;
}
