#include <stdio.h>
#include <stdlib.h>

/* type */
typedef struct {
	double x,y;
}point;
/* end */

/* global */
point a[1007],b[1007];
int N;
/* end */

/* function */
int isok(void);
int cmpup(const void* a,const void* b);
int cmpdown(const void* a,const void* b);
int eqal(double a,double b);
/* end */

int main(void)
{
	int n;
	scanf("%d",&n);
	while(n--){
		int i;
		scanf("%d",&N);
		for(i=0;i<N;++i){
		       	scanf("%lf%lf",&a[i].x,&a[i].y);
			b[i].x=a[i].x;b[i].y=a[i].y;
		}
		if(isok()) puts("YES");
		else puts("NO");
	}
	return 0;
}

int cmpup(const void* a,const void* b)
{
#define p ((point*)a)
#define q ((point*)b)
	if(p->x == q->x) return p->y - q->y;
	return p->x - q->x;
#undef p
#undef q
}

int cmpdown(const void* a,const void* b)
{
#define p ((point*)a)
#define q ((point*)b)
	if(p->x == q->x) return q->y - p->y;
	return p->x - q->x;
#undef p
#undef q
}

int isok(void)
{
	int i,j;
	double mid;

	qsort(a,N,sizeof(point),cmpup);
	qsort(b,N,sizeof(point),cmpdown);

	mid=(a[N-1].x+a[0].x)/2;

	i=0;j=N-1;
	while(i<j){
		if(!eqal(mid-a[i].x,b[j].x-mid) || !eqal(a[i].y,b[j].y)) return 0;
		++i;--j;
	}
	return 1;
}

int eqal(double a,double b)
{
	double diff=a-b;
	if(-1e-6 <= diff && diff <=1e-6) return 1;
	return 0;
}
