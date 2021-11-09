#include <stdio.h>
#define LL long long

LL solve(LL x,LL y){
	LL ans=0;
	while(x!=0 && y!=0){
		if(x<y) {LL a=x;x=y;y=a;}
		ans+=(x/y)*y*4;LL a=y;y=x%y;x=a;
	}
	return ans;
}

int main(){
	LL x,y;
	scanf("%lld%lld",&x,&y);
	printf("%lld\n",solve(x,y));
	return 0;
}
