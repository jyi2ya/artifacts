#include <stdio.h>

int day[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(void){
	int y,m;
	scanf("%d%d",&y,&m);
	if(y%400==0 || (y%100!=0 && y%4==0)) day[2]=29;
	printf("%d\n",day[m]);
	return 0;
}
