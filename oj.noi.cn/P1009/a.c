#include <stdio.h>

int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a+b<10) puts("water");
	else if(a>b) puts("tree");
	else puts("tea");
	return 0;
}
