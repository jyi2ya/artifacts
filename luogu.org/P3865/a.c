#include <stdio.h>

#define MAX 100009

int st[MAX][31];

int max(int,int);
int intlog(int);

int main(void)
{
	int N,M,i,j;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;++i) scanf("%d",st[i]);
	for(j=1;j<31;++j)
		for(i=0;i+((1<<j)-1)<N;++i)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	/* 
	   for(j=0;j<intlog(N);++j){
	   for(i=0;i<N;++i) printf("%d ",st[i][j]);
	   putchar('\n');
	   }
	 */
	for(i=0;i<M;++i){
		int l,r,lg;
		scanf("%d%d",&l,&r);
		--l;--r;
		lg=intlog(r-l+1);
		--lg;
		/* printf("[%d,%d],[%d,%d],lg=%d\n",l,l+(1<<lg),r-(1<<(lg))+1,r,lg); */
		printf("%d\n",max(st[l][lg],st[r-(1<<(lg))+1][lg]));
	}
	return 0;
}

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

int intlog(int a)
{
	if(a<=0x1) return 0;
	if(a<=0x2) return 1;
	if(a<=0x4) return 2;
	if(a<=0x8) return 3;
	if(a<=0x10) return 4;
	if(a<=0x20) return 5;
	if(a<=0x40) return 6;
	if(a<=0x80) return 7;
	if(a<=0x100) return 8;
	if(a<=0x200) return 9;
	if(a<=0x400) return 10;
	if(a<=0x800) return 11;
	if(a<=0x1000) return 12;
	if(a<=0x2000) return 13;
	if(a<=0x4000) return 14;
	if(a<=0x8000) return 15;
	if(a<=0x10000) return 16;
	if(a<=0x20000) return 17;
	if(a<=0x40000) return 18;
	if(a<=0x80000) return 19;
	if(a<=0x100000) return 20;
	if(a<=0x200000) return 21;
	if(a<=0x400000) return 22;
	if(a<=0x800000) return 23;
	if(a<=0x1000000) return 24;
	if(a<=0x2000000) return 25;
	if(a<=0x4000000) return 26;
	if(a<=0x8000000) return 27;
	if(a<=0x10000000) return 28;
	if(a<=0x20000000) return 29;
	if(a<=0x40000000) return 30;
	if(a<=0x80000000) return 31;
	return 32;
}
