#include <stdio.h>

long stack[105];
long* top=stack;

#define PUSH(i) *(++top)=(i)
#define POP() *(top--)

int main(void){
	long i;
	while(scanf("%ld",&i) == 1) PUSH(i);
	POP();
	while(top != stack)printf("%ld ",POP());
	return 0;
}
