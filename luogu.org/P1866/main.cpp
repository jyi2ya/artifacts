#include <cstdio>
#include <algorithm>

typedef long long LL;

const LL MOD=(LL)1e9+7;

LL num[1005];
LL ans[1005];

int main(void){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%lld",num+i);
	std::sort(num,num+N);
	for(int i=0;i<N;i++){
		if(i==0) ans[i]=num[i];
		else ans[i]=((num[i]-i)%MOD*ans[i-1]%MOD)%MOD;
	}
	printf("%lld\n",ans[N-1]);
	return 0;
}
