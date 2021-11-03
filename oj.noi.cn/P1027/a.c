#include <stdio.h>
#include <ctype.h>

int main(void){
	int tot=0,ch;
	while(isdigit(ch=getchar())) tot+=ch-'0';
	printf("%d\n",tot);
	return 0;
}
