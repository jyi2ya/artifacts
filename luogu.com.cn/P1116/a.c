#include <stdio.h>

#define MAX 10007

int a[MAX],N;

int main(void){
	int i,j,ans=0,sorted=0;
	scanf("%d",&N);
	for(i=0;i<N;++i) scanf("%d",a+i);
	while(!sorted){
		sorted=1;
		for(i=0;i<N-1;++i)
			if(a[i]>a[i+1]){
				int tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;

				++ans;
				sorted=0;
			}
	}
	printf("%d\n",ans);
	return 0;
}
