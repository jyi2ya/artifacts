#include <stdio.h>

int main(void){
	int a,b,c;
	a=getchar()-'0';
	b=getchar()-'0';
	c=getchar()-'0';

	if(a*100+b*10+c==a*a*a+b*b*b+c*c*c) puts("YES");
	else puts("NO");
	return 0;
}
