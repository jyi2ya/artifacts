#include <stdio.h>

typedef long long LL;

int main(void){
	LL n1,n2,i,ans=0;
	scanf("%lld%lld",&n1,&n2);
	for(i=n1;i<=n2;i++)
		if(i%4==0||i%2!=0)ans++;
	printf("%lld\n",ans);
	return 0;
}
