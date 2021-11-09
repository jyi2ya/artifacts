#include <stdio.h>
#include <string.h>

typedef unsigned long long LL;

LL a[127][127],ans=0;
LL dp[127][127];
int m,n;

void read(void);
void solve(int);
LL max(LL,LL);

int main(){
	read();
	int i;
	for(i=0;i<n;++i){
		solve(i);
		ans+=dp[0][m-1];
	}
	printf("%llu\n",ans);
	return 0;
}

void solve(int now){
	int l,r;
	for(l=m-1;l>=0;--l){
		for(r=l;r<m;++r){
			LL time=l+m-r;
			if(r){
				/*
				LL tmp1,tmp2,eax,ebx;

				tmp1=dp[l+1][r];
				eax=a[now][l];

				ebx=1<<time;

				eax*=ebx;

				tmp1+=eax;

				tmp2=dp[l][r-1];
				eax=a[now][r];

				ebx=1<<time;
				eax*=ebx;

				tmp2+=eax;

				dp[l][r]=max(tmp1,tmp2);
				*/
				dp[l][r]=max(dp[l+1][r]+a[now][l]*(1<<(time)),dp[l][r-1]+a[now][r]*(1<<(time)));
			}
			else dp[l][r]=dp[l+1][r]+a[now][l]*(1<<(time));
		}
#ifdef DEBUG
	for(int l=0;l<m;++l){
		for(int r=0;r<m;++r) printf("%lld ",dp[l][r]);
		putchar('\n');
	}
	putchar('\n');
#endif
	}
}

void read(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%llu",a[i]+j);
}
LL max(LL a,LL b){
	if(a>b) return a;
	return b;
}
