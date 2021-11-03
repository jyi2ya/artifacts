#include<algorithm>
#include<cstdio>

int a[200005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	std::sort(a,a+n);
	int i=0,num=0,now=a[0];
	while(i<=n){
		if(a[i]==now) num++;
		else {
			printf("%d %d\n",now,num);
			num=1;now=a[i];
		}
		i++;
	}
	return 0;
}
