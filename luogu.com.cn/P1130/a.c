#include <stdio.h>

typedef long long int ll;

ll dp[2005][2005],a[2005][2005];

ll min(ll,ll);

int main(void){
	int N,M,i,j;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;++i)
		for(j=0;j<N;++j)
			scanf("%lld",a[i]+j);
	for(i=N;i>=0;--i)
		for(j=M-1;j>=0;--j)
			dp[j][i]=min(dp[(j+1)%M][i+1]+a[j][i],dp[j][i+1]+a[j][i]);
#ifdef DEBUG
	for(i=0;i<M;++i){
		for(j=0;j<N;++j) printf("%2lld ",dp[i][j]);
		putchar('\n');
	}
#endif
	ll ans=dp[0][0];
	for(i=1;i<M;++i) if(dp[i][0]<ans) ans=dp[i][0];
	printf("%lld\n",ans);
	return 0;
}

ll min(ll a,ll b){
	if(a>b) return b;
	return a;
}
