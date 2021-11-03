#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	freopen("in","w",stdout);
	srand(time(NULL));
	int max=rand()%50,i;
	for(i=0;i<max;i++) printf("%d/%d\n",rand()%1000,rand()%1000);
	return 0;
}
