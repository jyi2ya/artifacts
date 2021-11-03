#include <cstdio>
#include <algorithm>

#define MAX_NUM 100007

int a[MAX_NUM];

int main(void){
	int N,i,sorted=0,cnt=0;
	scanf("%d",&N);
	for(i=0;i<N;++i) scanf("%d",a+i);
	while(!sorted){
		sorted=1;
		++cnt;
		for(i=0;i<N-2;++i)
			if(a[i+1]<a[i]){
				int tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;

				sorted=0;
			}
#ifdef DEBUG
		for(i=0;i<N;++i) printf("%d ",a[i]);
		printf("sorted:%d\n",sorted);
#endif
	}
	printf("%d\n",cnt);
	return 0;
}
