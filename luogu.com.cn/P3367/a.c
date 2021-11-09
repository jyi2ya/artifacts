#include <stdio.h>

#define MAX 200007

int fa[MAX];

enum bool {false=0,true=1};

int find(int a);
void merge(int b,int c);

int main(void){
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<MAX;++i) fa[i]=i;
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==2) {
			if(find(b)==find(c)) puts("Y");
			else puts("N");
		}else merge(b,c);
	}
	return 0;
}

int find(int a){
	if(fa[a]==a) return a;
	fa[a]=find(fa[a]);
	return fa[a];
}

void merge(int b, int c){
	fa[find(b)]=fa[find(c)];
}
