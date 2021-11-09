#include <cstdio>
#include <algorithm>

int cow[100000];

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	char buf[100];
	for(int i=0;i<n;i++){
		scanf("%d%s",cow+i,buf);
		if(buf[0]=='n') cow[i]=0;
	}
	std::sort(cow,cow+n);
	int tot=0,now=n-1,ans=0;
	while(tot<m) {
		tot+=cow[now];
		now--;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
