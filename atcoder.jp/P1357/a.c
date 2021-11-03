#include <stdio.h>

#define ull unsigned long long

ull pow(ull n,ull p,ull m);
ull mul(ull n,ull p,ull m);

int main(void){
	ull n,p,m;
	scanf("%llu%llu%llu",&n,&m,&p);
	printf("%llu\n",pow(n,p,m));
	return 0;
}

ull pow(ull n,ull p,ull m){
	ull ans=1;
	while(p){
		if(p&1) ans=mul(ans,n,m);
		ans%=m;
		n=mul(n,n,m);
		n%=m;
		p>>=1;
	}
	return ans;
}

ull mul(ull n,ull p,ull m){
	ull ans=0;
	while(p){
		if(p&1) ans+=n;
		ans%=m;
		n<<=1;
		n%=m;
		p>>=1;
	}
	return ans;
}

