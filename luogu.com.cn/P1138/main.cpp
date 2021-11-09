#include<cstdio>
#include<algorithm>

int a[30005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	std::sort(a,a+n);
	int* max=std::unique(a,a+n);

	if(a+k>=max)printf("NO RESULT\n");
	else printf("%d\n",a[k-1]); 

	return 0;
}
