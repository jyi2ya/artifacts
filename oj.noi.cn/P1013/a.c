#include <stdio.h>

int main(void){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==b && b==c) puts("Equilateral");
	else if(a*a+b*b==c*c || c*c+b*b==a*a || a*a+c*c==b*b) puts("Right");
	else if(a+b<c || a+c<b || b+c<a) puts("NO");
	else puts("General");
	return 0;
}
