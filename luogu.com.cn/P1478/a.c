#include <stdio.h>
#include <stdlib.h>

int apples[6000],top=0;

void push(int x){
	apples[top++]=x;
}

int cmp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}

int main(void){
	int n,s,a,b,max=0,heigh;
	scanf("%d%d",&n,&s);
	scanf("%d%d",&a,&b);
	if(n==0)printf("0\n");
	else {
		heigh=a+b;
		while(n--){
			int i,j;
			scanf("%d%d",&i,&j);
			if(i<=heigh)push(j);
		}
		qsort(apples,top,sizeof(int),cmp);
		while(s>=0) s-=apples[max++];
		printf("%d\n",max-1);
		return 0;
	}
}
