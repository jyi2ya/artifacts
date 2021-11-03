#include <stdio.h>

int main(void){
	int n;
	while(scanf("%d",&n)==1 && n!=0){
		if(n&1) puts("Bob");
		else puts("Alice");
	}
	return 0;
}
