#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num,sco;
}member;

int cmp(const void* a,const void* b){
	if(((member*)a)->sco==((member*)b)->sco) 
		return ((member*)a)->num-((member*)b)->num;
	else return ((member*)b)->sco-((member*)a)->sco;
}

member a[5005];

int main(){
	int m,n,i;
	scanf("%d%d",&n,&m);m=(int)(m*1.5);
#ifdef DEBUG
	printf("m=%d\n",m);
#endif
	for(i=0;i<n;i++) scanf("%d%d",&a[i].num,&a[i].sco);

	qsort(a,n,sizeof(member),cmp);

	int score=a[m-1].sco,num=0;
	while(a[num].sco>=score)num++;

	printf("%d %d\n",score,num);
	for(i=0;i<num;i++)printf("%d %d\n",a[i].num,a[i].sco);

	return 0;
}
