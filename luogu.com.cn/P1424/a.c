#include <stdio.h>

int main(void){
	long n,x;
	long long sum=0;
	scanf("%ld%ld",&x,&n);
	
	{
		long i,weekday=x;
		for(i=0;i<n;i++){
			if(weekday%7 == 0 || weekday%7 == 6);
			else sum+=250;
			weekday++;
		}
	}
			
	printf("%lld",sum);
	return 0;
}
