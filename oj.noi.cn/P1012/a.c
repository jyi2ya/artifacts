#include <stdio.h>
#include <ctype.h>

int main(void){
	int n;
	scanf("%d",&n);
	if(97<=n%123 && n%123<=122) putchar(tolower(n%123));
	else if(65<=n%91 && n%91<=90) putchar(toupper(n%91));
	else putchar('*');
	putchar('\n');
	return 0;
}
