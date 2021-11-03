#include<cstdio>
#include<algorithm>
using namespace std;

int a[200005];
int N,C;
long long ans=0;

int Find(int x){
	if(!binary_search(a,a+N,x))return 0; 
	return upper_bound(a,a+N,x)-lower_bound(a,a+N,x);
}

int main(){
	scanf("%d%d",&N,&C);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	sort(a,a+N);
	for(int i=0;i<N;i++) ans+=Find(C+a[i]);
	printf("%lld\n",ans);
	return 0;
}
