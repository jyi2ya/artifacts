#include <stdio.h>
#include <string.h>

int a[100005];

int sum(int i){
	int sum=i;
	sum+=i%10;
	while(i/=10)sum+=i%10;
	return sum;
}

int main(){
	int i,n;
	for(i=0;i<100003;i++){
		int s=sum(i);
#ifdef DEBUG
		printf("s=%d,i=%d\n",s,i);
#endif
	       	if(a[s]==0) a[s]=i;
	}
	scanf("%d",&i);
	while(i--)
		while(scanf("%d",&n)==1) 
			printf("%d\n",a[n]);
	return 0;
}
