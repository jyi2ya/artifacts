#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int cc(void){
	int a=rand()%4;
	switch(a){
		case 0:return 'C';
		case 1:return 'H';
		case 2:return 'O';
		case 3:return 'N';
		default:return 'O';
	}
	return 'H';
}

int main(void){
	srand(time(NULL));
	int data=rand()%100;
	printf("%d\n",data);
	while(data--){
		do{
			putchar(cc());
			int num=rand()%25;
			if(num<=1);
			else printf("%d",num);
		} while(rand()%4!=0);
		putchar('\n');
	}
	return 0;
}
