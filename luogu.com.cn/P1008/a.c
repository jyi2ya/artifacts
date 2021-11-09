#include <stdio.h>

int main(void){
	for(int i=123;i<350;i++){
		int j=i*2;
		int k=i*3;
		int mul=1,sum=0;
		for(int a=i;a>0;a/=10) {
			sum+=(a%10);
			mul*=(a%10);
		}
		for(int a=j;a>0;a/=10) {
			sum+=(a%10);
			mul*=(a%10);
		}
		for(int a=k;a>0;a/=10) {
			sum+=(a%10);
			mul*=(a%10);
		}
		if(sum==45 && mul==362880) printf("%d %d %d\n",i,j,k);
	}
	return 0;
}
