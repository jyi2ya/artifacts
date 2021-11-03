#include <stdio.h>
#define LL long long

int main(){
	LL x,N,ans=0;
	scanf("%lld%lld",&N,&x);
	int last=0;
	while(N--){
		int a;
		scanf("%d",&a);
		if(a+last>x) {
			if(last<x){
				ans+=a+last-x;
				a-=a+last-x;
			}else{
				ans+=a;
				a=0;
				ans+=last-x;
			}
		}
		last=a;
	}
	printf("%lld\n",ans);
}
