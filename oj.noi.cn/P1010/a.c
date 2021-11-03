#include <stdio.h>

int main(void){
	int a;
	scanf("%d",&a);

	if(a>30) puts("Fail");
	else if(20<a && a<=30) printf("%.2f\n",(a-20)*0.7+10*0.75+10*0.8+0.2);
	else if(10<a && a<=20) printf("%.2f\n",(a-10)*0.75+10*0.8+0.2);
	else printf("%.2f\n",a*0.8+0.2);

	return 0;
}
