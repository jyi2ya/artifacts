#include <stdio.h>
#include <ctype.h>

int main(){
	char ch=getchar();
	puts(islower(ch)?"ch is a lower":"ch isn't a lower");
	puts(isdigit(ch)?"ch is a digit":"ch isn't a digit");
	puts(isupper(ch)?"ch is a upper":"ch isn't a upper");
	return 0;
}
