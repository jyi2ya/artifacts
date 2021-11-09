#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int lines=rand()%5000;
	while(lines--){
		int num=rand()%25;
		while(num--) putchar(rand()&1?'W':'L');
		putchar('\n');
	}
	putchar('E');
	return 0;
}
