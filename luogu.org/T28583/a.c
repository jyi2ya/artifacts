#include <stdio.h>

int main(void){
	int tot=100;
	for(int i=0;i<3;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		tot-=x*y;
	}
	printf("%d\n",tot);
	return 0;
}
