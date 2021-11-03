#include <stdio.h>

#define pow(x,c) ({\
	long long _x=(x),_c=(c),ans=1;\
	while(_c){\
		if(_c&1) ans*=_x;\
		_x*=_x;\
		_c>>=1;\
	}\
	ans;\
})

int main(void){
	long long x,n;
	scanf("%lld%lld",&x,&n);
	printf("%lld\n",pow(x+1,n));
	return 0;
}
