#include <stdio.h>

float price[10]={0,3,2.5,4.1,10.2};

int main(void){
	int i;
	puts(
			"[1] apples\n"
			"[2] pears\n"
			"[3] oranges\n"
			"[4] grapes\n"
			"[0] Exit"
	    );
	scanf("%d",&i);
	if(i){
		if(i<5) printf("price=%.1f\n",price[i]);
		else puts("price=0");
	}
	return 0;
}
