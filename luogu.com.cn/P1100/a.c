#include <stdio.h>

int main(void){
	unsigned int a;
	scanf("%u",&a);
	printf("%u\n",(a>>16)+((a&0xffff)<<16));
	return 0;
}
