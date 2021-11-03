#include <stdio.h>
#include <limits.h>

int max(int a,int b){return a>b?a:b;}
int main(void){
	int N;
	scanf("%d",&N);
	int last=INT_MIN/2,ans=INT_MIN;
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		last=max(last+a,a);
		if(last>ans) ans=last;
	}
	printf("%d\n",ans);
	return 0;
}
