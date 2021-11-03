#include <stdio.h>

int main(void){
	long long n,cnt=0;
	scanf("%lld",&n);
	while(n!=1){
		if(n&1) n=n*3+1;
		else n/=2;
		++cnt;
	}
	printf("%lld\n",cnt+1);
	return 0;
}
