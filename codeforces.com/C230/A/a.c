#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x,y;
}dragon;

dragon a[1007];
int s,n;

int cmp(const void* a,const void* b);

int main(void){
	int i;
	scanf("%d%d",&s,&n);
	for(i=0;i<n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	qsort(a,n,sizeof(dragon),cmp);
	for(i=0;i<n;++i){
		if(s<=a[i].x){
		       	puts("NO");
			return 0;
		}
		s+=a[i].y;
	}
	puts("YES");
	return 0;
}

int cmp(const void* a,const void* b){
	return (*(dragon*)a).x - (*(dragon*)b).x;
}
