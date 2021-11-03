#include <stdio.h>

int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",((int)(((float)a+(float)b/10)/1.9)));
	return 0;
}
