#include <stdio.h>

int L,N,max=0,min=0;

int main(){
	scanf("%d%d",&L,&N);
	while(N--){
		int i;
		scanf("%d",&i);

		int a=(i>L-i)?i:L-i+1;
		int b=(i<L-i)?i:L-i+1;
		if(a>max)max=a;
		if(b>min)min=b;
	}
	printf("%d %d\n",min,max);
	return 0;
}
