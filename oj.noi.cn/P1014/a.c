#include <stdio.h>

int main(void){
	int a;
	scanf("%d",&a);
	if(a>=90) puts("Excellent");
	else if(a>=80) puts("Good");
	else if(a>=60) puts("Pass");
	else puts("Fail");
	return 0;
}
