#include <stdio.h>

int side[100005];
char name[100005][15];

int main(){
	int m,n,i,now=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d%s",side+i,name[i]);
	for(i=0;i<m;i++){
		int a,s;
		scanf("%d%d",&a,&s);
		if(a^side[now])now=(now+s)%n;
		else now=(now-s+n)%n;
	}
	printf("%s\n",name[now]);
	return 0;
}


