#include <stdio.h>

int main(void){
	int left=1,ch;
	while((ch=getchar())!=EOF){
		if(ch=='"'){
			if(left)printf("``");
			else putchar('"');
			left=!left;
		}
		else putchar(ch);
	}
	return 0;
}
