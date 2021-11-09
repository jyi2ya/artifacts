#include <stdio.h>

long long pow(long long b,long long p,long long k);

int main(void){
	long long b,p,k;
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld\n",b,p,k,pow(b,p,k)%k);
	return 0;
}

long long pow(long long b,long long p,long long k){
	long long ans=1;
	while(p){
		if(p&1) ans*=b;
		ans%=k;
		b*=b;
		b%=k;
		p>>=1;
	}
	return ans;
}
