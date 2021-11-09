#include <stdio.h>

#define MAX 500009

int c[MAX],n,m;

int prefix(int x);
int lowbit(int x);
int query(int x);
void update(int x,int deltax);
void modifi(int l,int r,int deltax);

int main(void)
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i) {
		int x;
		scanf("%d",&x);
		c[i]=x-prefix(i-lowbit(i));
	}
	while(m--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			update(x,k);
			update(y+1,-k);
		}else {
			int x;
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}

void update(int x,int deltax)
{
	while(x<=n){
		c[x]+=deltax;
		x+=lowbit(x);
	}
}

int prefix(int x)
{
	int ans=0;
	while(x){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

int lowbit(int x)
{
	return x&(~x+1);
}

int query(int x)
{
	int ans=0;
	while(x){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
