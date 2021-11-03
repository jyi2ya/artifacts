#include <stdio.h>

int main(void){
	int n,star,space;
	scanf("%d",&n);
	space=n-1;
	star=1;
	while(n--){
		int i;
		for(i=0;i<space;++i) putchar(' ');
		for(i=0;i<star;++i) putchar('*');
		putchar('\n');
		--space;
		star+=2;
	}
	return 0;
}
