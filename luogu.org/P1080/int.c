#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x,y;
	long long product;
}people;

int n,kingx,kingy;
people a[1009];

void read(void);
int sortcmp(const void* a,const void* b);

int main(void){
	int i;
	unsigned long long nowproduct,ans=0;
	read();
	nowproduct=kingx;
	for(i=0;i<n;++i){
		if(nowproduct/a[i].y > ans) ans=nowproduct/a[i].y;
		nowproduct*=a[i].x;
	}
	printf("%llu\n",ans);
}

int sortcmp(const void* a,const void* b)
{
	return (*(people*)a).product-(*(people*)b).product;
}

void read(void)
{
	int i;
	scanf("%d",&n);
	scanf("%d%d",&kingx,&kingy);
	for(i=0;i<n;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].product=a[i].x*a[i].y;
	}
	qsort(a,n,sizeof(people),sortcmp);
}
