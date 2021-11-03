#include <stdio.h>

int main(void){
	int n,i,space,num;
	scanf("%d",&n);
	space=n-1;
	num=1;
	for(i=0;i<n;++i) {
		int j;
		for(j=0;j<space;++j) putchar(' ');
		for(j=1;j<=num;++j) printf("%d",j);
		putchar('\n');
		--space;
		num+=2;
	}
	num-=4;
	space+=2;
	while(num>=1) {
		int j;
		for(j=0;j<space;++j) putchar(' ');
		for(j=1;j<=num;++j) printf("%d",j);
		putchar('\n');
		++space;
		num-=2;
	}
	return 0;
}
