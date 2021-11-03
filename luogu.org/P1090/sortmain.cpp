#include<cstdio>
#include<algorithm>
using namespace std;

int a[100000];

int main(){
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=1;i<n;i++){
		sort(a,a+n);
		a[i]+=a[i-1];
		ans+=a[i];
#ifdef DEBUG
		printf("ans=%lld\n",ans);
#endif
	}
	printf("%lld\n",ans);
	return 0;
}
