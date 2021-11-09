#include<cstdio>
#include<algorithm>

int a[30005];

int main(){
	int w,n;
	scanf("%d%d",&w,&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	std::sort(a,a+n);
	int i=0,j=n-1,ans=0;
	while(i<=j){
		if(a[i]+a[j]<=w){
			i++;j--;
		}else j--;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
