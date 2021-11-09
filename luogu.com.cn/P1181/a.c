#include <stdio.h>

int main(){
	int ans=1,now=0,N,M;
	scanf("%d%d",&N,&M);
	while(N--){
		int a;
		scanf("%d",&a);
		if(now+a <= M)now+=a;
		else {
			now=a;
			ans++;
		}
#ifdef DEBUG
		printf("ans=%d,now=%d\n",ans,now);
#endif
	}
	printf("%d\n",ans);
	return 0;
}
