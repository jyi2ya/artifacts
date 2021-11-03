#include <stdio.h>
#include <ctype.h>

int main(void){
	char buf[100];
	int i=0,j;
	while(isdigit(buf[i]=getchar())) ++i;
	printf("%d\n",i);
	for(j=0;j<i;++j){
		putchar(buf[j]);
		putchar('\n');
	}
	return 0;
}
