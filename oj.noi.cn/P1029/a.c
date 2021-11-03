#include <stdio.h>
#include <ctype.h>

int main(void){
	int ch;
	while((ch=getchar())!='\n' && ch!=EOF){
		if(isupper(ch)) ch=(ch-'A'+3+26)%26+'A';
		if(islower(ch)) ch=(ch-'a'+3+26)%26+'a';
		putchar(ch);
	}
	putchar('\n');
	return 0;
}
