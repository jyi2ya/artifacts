#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int a[1000009],top=1;

void ins(void);
void show(void);
void pop(void);

void swap(int* a,int* b);

int main(void)
{
	int n,op;
	scanf("%d",&n);
	while(scanf("%d",&op) && n--){
		switch(op){
			case 1:{ins();  break;}
			case 2:{show(); break;}
			case 3:{pop();  break;}
			default:break;
		}
	}
	return 0;
}

void swap(int* a,int* b) { int tmp=*a;*a=*b;*b=tmp; }

void ins(void)
{
	int in,now=top;
	scanf("%d",&in);
	a[now]=in;
	while(now>0){
		int cmp=(now&1)?(now-1)>>1:now>>1;
		if(a[now]<a[cmp]) swap(a+now,a+cmp);
		now=cmp;
	}
	++top;
}

void show(void)
{
	printf("%d\n",a[1]);
}

void pop(void)
{
	int now=1;
	a[1]=INF;
	while('v'){
		int cmp=now<<1;
		if(cmp>=top) break;
		if((now<<1)+1 < top) 
			if(a[now<<1]>a[(now<<1)+1])
			       	cmp=(now<<1)+1;
		swap(a+now,a+cmp);
		now=cmp;
	}
}
