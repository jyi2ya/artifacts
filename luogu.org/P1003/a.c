#include <stdio.h>

int a[10005],b[10005],g[10005],k[10005];
int top=0;

int readint(void){
	int i;scanf("%d",&i);return i;
}

int main(void){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[top]=readint();
		b[top]=readint();
		g[top]=readint();
		k[top]=readint();
		top++;
	}
	int x,y;
	scanf("%d%d",&x,&y);
	while(top+1>=0){
	       if(a[top]<=x && a[top]+g[top]>=x && b[top]<=y && b[top]+k[top]>=y)break;
	       top--;
	}
	printf("%d\n",top+1);
	return 0;
}
