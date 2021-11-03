/*
ID:lindong6
PROG:friday
LANG:C++
*/
#include <stdio.h>

int days[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int week[8]={0,0,0,0,0,0,0,0};

int isMore(int year){
	return (year%400==0||(year%4==0&&year%100!=0));
}

int main(){
	int year=1900,mon=1,day=1,weekday=1,N;
	scanf("%d",&N);
	while(year<1900+N){
		days[2]=isMore(year)?29:28;
		while(mon<=12){
			int DAYinMON=days[mon];
			while(day<=DAYinMON){
				if(day==13)week[weekday%7]++;
				day++;weekday++;
			}
			day=1;
			mon++;
		}
		mon=1;
		year++;
	}
	printf("%d %d %d %d %d %d %d\n",week[6],week[0],week[1],week[2],week[3],week[4],week[5]);
	return 0;
}
