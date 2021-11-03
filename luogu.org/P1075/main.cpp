#include<cstdio>
#include<cmath>

int main(){
	int n;
	scanf("%d",&n);
	int max=sqrt(n)+1;
	if(n%2==0)printf("%d\n",n/2);
	else {
		int i;
		for(i=3;i<=max;i+=2) if(n%i==0) break;
		printf("%d\n",n/i);
	}
	return 0;
}
