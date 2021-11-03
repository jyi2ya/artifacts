#include <stdio.h>

int pow(unsigned long long,unsigned long long);

int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",pow(a,b));
	return 0;
}

int pow(unsigned long long a,unsigned long long b){
	unsigned long long ans=1;
	while(b){
		if(b&1) ans*=a;
		ans%=10;
		a*=a;
		a%=10;
		b>>=1;
	}
	return ans%10;
}
