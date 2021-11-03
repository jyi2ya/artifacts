#include <stdio.h>

#define MAX 500009

int c[MAX],n,m;

void update(int x,int deltax);
int query(int l,int r);
int prefix(int r);
int lowbit(int x);

void read(void);

int main(void)
{
	int i;
	read();
	for(i=0;i<m;++i){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			update(x,y);
		}else {
			printf("%d\n",query(x,y));
		}
	}
	return 0;
}

void read(void)
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		update(i,x);
	}
}

int lowbit(int x)
{
	return x&(~x+1);
}
int query(int l,int r)
{
	return prefix(r)-prefix(l-1);
}
int prefix(int r)
{
	int ans=0;
	while(r){
		ans+=c[r];
		r-=lowbit(r);
	}
	return ans;
}
void update(int x,int deltax)
{
	while(x<=n){
		c[x]+=deltax;
		x+=lowbit(x);
	}
}
