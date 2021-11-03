#include <stdio.h>

int gcd(int ,int);

int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	if(gcd(a,b)==1) puts("Yes");
	else puts("No");
	return 0;
}

int gcd(int a,int b){
	while(b){
		int tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
