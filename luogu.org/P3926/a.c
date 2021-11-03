#include <stdio.h>

long long a,c,p,q,r,x;
long long work() {
	long long te=c-a,t1=te*p,t2=t1+q;
	if(a<c) {
		if(x<=t1)return a+x/p;
		if(x>t1&&x<=t2)return c;
		if(x>t2)return c+(x-t2)/r;
	}
	if(a>c)
		return a+x/r;
}
int main(void){
	scanf("%lld%lld%lld%lld%lld%lld",&a,&c,&p,&q,&r,&x);
	printf("%lld\n",work());
	return 0;
}
