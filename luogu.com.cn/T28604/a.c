#include <stdio.h>

int main(void){
	char* first="You believe it's so easy? I've told you xiaoxiao did 5 times,you foolish!";
	while(*first!='\0') {
		putchar(*first);
		first++;
	}
	return 0;
}
