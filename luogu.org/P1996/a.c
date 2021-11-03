#include <stdio.h>

#define IN 0
#define OUT 1

int n,m,a[105],out=0,now=0;

int main(){
	scanf("%d%d",&n,&m);
	while(out<n){
		int cnt=0;
		while(cnt<m){
			now=(now+1)%n;
			if(a[now]==IN) cnt++;
		}
		a[now]=OUT;
		printf("%d ",now==0?n:now);
		out++;
	}
	putchar('\n');
	return 0;
}
