#include <stdio.h>

typedef long long ll;

int main(void){
	ll a,b;
	while(scanf("%lld%lld",&a,&b)==2 && (a!=0 && b!=0))
		printf("%lld\n",a+b);
	return 0;
}
