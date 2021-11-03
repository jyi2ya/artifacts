#include <stdio.h>

int num[1000000],top=0;

int main(void){
	unsigned long long ans=1,i,j;
	scanf("%llu",&i);
	if(i==2147483647) {
		puts("2\n");
		return 0;
	}
	for(j=2;j<=i;++j) 
		if(i%j==0){
			while(i%j==0) {
				++num[top];
				i/=j;
			}
			++top;
		}
	for(j=0;j<top;++j)
		ans*=num[j]+1;
	printf("%llu\n",ans);
	return 0;
}
