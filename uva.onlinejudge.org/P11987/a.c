#include <stdio.h>

#define MAX 200007

int fa[MAX],sum[MAX],num[MAX],n;

int find(int x);
void init(void);
void merge(void);
void add(void);
void show(void);

int main(void)
{
	int cmd;
	while(scanf("%d%d",&n,&cmd)==2){
		init();
		while(cmd--){
			int command;
			scanf("%d",&command);
			switch(command){
				case 1:{merge();break;}
				case 2:{add();break;}
				case 3:{show();break;}
				default:break;
			}
		}
	}
	return 0;
}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void init(void)
{
	int i;
	for(i=0;i<=n;++i){
	       	sum[i+100003]=i;
		num[i+100003]=1;
		fa[i]=i+100003;
		fa[fa[i]]=fa[i];
	}
}

void merge(void)
{
	int p,q;
	scanf("%d%d",&p,&q);
	if(find(p)==find(q)) return;

	sum[find(p)]+=sum[find(q)];
	num[find(p)]+=num[find(q)];

	fa[find(q)]=find(p);
}

void add(void)
{
	int p,q;
	scanf("%d%d",&p,&q);
	if(find(p)==find(q)) return;

	sum[find(p)]-=p;
	--num[find(p)];

	sum[find(q)]+=p;
	++num[find(q)];

	fa[p]=find(q);
}

void show(void)
{
	int n;
	scanf("%d",&n);
	printf("%d %d\n",num[find(n)],sum[find(n)]);
}
