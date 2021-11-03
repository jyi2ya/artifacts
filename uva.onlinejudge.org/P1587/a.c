#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int w,h;
}plat;

plat a[6];

int cmp(const void* a,const void* b){
	plat* p=(plat*)a,*q=(plat*)b;
	if(p->w!=q->w)return (p->w)-(q->w);
	else return (p->h)-(q->h);
}

bool read(){
	for(int i=0;i<6;i++){
		int w,h;
		if(scanf("%d%d",&w,&h)!=2)return false;
		if(w<h) {int x=w;w=h;h=x;}
		a[i].w=w;a[i].h=h;
	}
	return true;
}

bool check(){
	/*0,2,4*/
	for(int i=0;i<6;i+=2)if(a[i].w!=a[i+1].w || a[i].h!=a[i+1].h) return false;
	if (a[0].h != a[2].h||a[0].w!=a[4].h||a[2].w!=a[4].w) return false;
	return true;
}

int main(){
	while(read()){
		qsort(a,6,sizeof(plat),cmp);
		if(check()) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
