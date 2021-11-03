/*
 * LuoTianyi is the best!!!
 * 0x66ccff
 * 
 * LuuuoooooooooooooooTiiiiiiiiiiaaaaaaaaaaaaannnnnnnnnYiiiiiiiiiiiii
 * iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
 * iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 200009
#define MOD 10007

void read(void);

long long n,w[MAX],from[MAX],to[MAX];
long long tot[MAX],maxw[MAX],ans_maxw=0,ans_tot=0;

int main(void)
{
	freopen("link.in","r",stdin);
	freopen("link.out","w",stdout);
	read();
	printf("%lld %lld\n",ans_maxw,(ans_tot*2)%MOD);
	return 0;
}

void read(void)
{
	int i;
	scanf("%lld",&n);
	--n;
	for(i=0;i<n;++i) 
		scanf("%lld%lld",from+i,to+i);
	++n;
	for(i=1;i<=n;++i) scanf("%lld",w+i);
	--n;
	for(i=0;i<n;++i){
		if(maxw[from[i]]*w[to[i]] > ans_maxw) ans_maxw=maxw[from[i]]*w[to[i]];
		if(maxw[to[i]]*w[from[i]] > ans_maxw) ans_maxw=maxw[to[i]]*w[from[i]];

		if(w[from[i]] > maxw[to[i]]) maxw[to[i]]=w[from[i]];
		if(w[to[i]] > maxw[from[i]]) maxw[from[i]]=w[to[i]];

		ans_tot+=tot[from[i]]*w[to[i]]; ans_tot%=MOD;
		ans_tot+=tot[to[i]]*w[from[i]]; ans_tot%=MOD;

		tot[from[i]]+=w[to[i]];
		tot[to[i]]+=w[from[i]];

		tot[from[i]]%=MOD;
		tot[to[i]]%=MOD;
	}
	++n;
}
