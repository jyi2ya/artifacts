#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int x,y;
	long long product;
}people;

typedef struct{
	int x[100000],top;
}bgint;

int n,kingx,kingy;
people a[1009];
bgint ans,eax,nowproduct,tmp;

void read(void);
int sortcmp(const void* a,const void* b);

void bgprt(bgint* a);
bgint* bginit(bgint* a);
bgint* bgmov(bgint* dest,bgint* src);
bgint* bgmul(bgint* dest,int a);
bgint* bgdiv(bgint* dest,int a);
int bgcmp(bgint* a,bgint* b);

int main(void)
{
	int i;
	read();
	nowproduct.x[0]=1;
	nowproduct.top=1;

	bgmul(&nowproduct,kingx);
	for(i=0;i<n;++i){
		bgmov(&tmp,&nowproduct);
		bgdiv(&tmp,a[i].y);
		if(bgcmp(&tmp,&ans) >0) bgmov(&ans,&tmp);
		bgmul(&nowproduct,a[i].x);
	}
	bgprt(&ans);
	return 0;
}

void bgprt(bgint* a)
{
	int i=a->top;
	while(a->x[i]==0 && i>=0) --i;
	if(i<0) printf("0");
	while(i>=0) printf("%d",a->x[i--]);
	putchar('\n');
}

int bgcmp(bgint* a,bgint* b)
{
	int i;
	if(a->top > b->top) return 1;
	if(a->top < b->top) return -1;
	for(i=a->top-1;i>=0;--i)
		if(a->x[i] != b->x[i])
			return a->x[i]-b->x[i];
	return 0;
}

bgint* bginit(bgint* a)
{
	memset(a->x,0,100000*sizeof(int));
	a->top=1;
	return a;
}

bgint* bgmov(bgint* dest,bgint* src)
{
	memcpy(dest->x,src->x,100000*sizeof(int));
	dest->top=src->top;
	return dest;
}

bgint* bgmul(bgint* dest,int a)
{
	int i;
	for(i=0;i<dest->top;++i) dest->x[i]*=a;
	dest->top+=100;
	for(i=0;i<dest->top;++i){
		dest->x[i+1]+=dest->x[i]/10;
		dest->x[i]%=10;
	}
	while(!dest->x[dest->top]) --dest->top;
	++dest->top;
	return dest;
}

bgint* bgdiv(bgint* dest,int a)
{
	int sum=0,i;
	for(i=dest->top-1;i>=0;--i){
		sum*=10;
		sum+=dest->x[i];
		dest->x[i]=sum/a;
		sum%=a;
	}
	dest->top+=100;
	for(i=0;i<dest->top;++i){
		dest->x[i+1]+=dest->x[i]/10;
		dest->x[i]%=10;
	}
	while(!dest->x[dest->top]) --dest->top;
	++dest->top;
	return dest;
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
