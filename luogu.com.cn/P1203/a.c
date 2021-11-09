/*
ID:lindong6
PROG:beads
LANG:C++
*/
#include <stdio.h>
#define LEFT 0
#define RIGHT 1

int num=0,len,att;
char nl[400];

int next(int now,int type){
	if(type==LEFT){
		if((now-1)>=0)return now-1;
		else return len-1;
	}
	if(type==RIGHT){
		if((now+1)<len)return now+1;
		else return 0;
	}
	else return -1;
}

int readwhite(int now,int type){
	now=next(now,type);
	while(nl[now]=='w'){
		if(num>len)break;
		now=next(now,type);
		num++;
	}
	att=nl[now];
	return now;
}

void readchar(int now,int type,int ch){
	now=next(now,type);
	if(type==LEFT)num++;
	while(nl[now]==ch||nl[now]=='w'){
		if(num>len)break;
		now=next(now,type);
		num++;
	}
}

void sum(int broke){
	int now;
	now=readwhite(broke,LEFT);
	readchar(now,LEFT,att);
#ifdef DEBUG
	printf("     -----     -----left:%d ",num);
#endif
	if(nl[broke]=='w'){
		num++;
		now=readwhite(broke,RIGHT);
		readchar(now,RIGHT,att);
	}
	else{
		num++;
		readchar(broke,RIGHT,nl[broke]);
	}
#ifdef DEBUG
	printf("right:%d\n",num);
#endif
}

int main(void){
	scanf("%d\n",&len);
	fgets(nl,360,stdin);
	int broke,max=0;
	for(broke=0;broke<len;broke++){
		num=0;
		sum(broke);
		if(num>max)max=num;
#ifdef DEBUG
		printf("   -----broke:%d,nun:%d,max:%d\n",broke,num,max);
#endif
	}
	if(max>len)max=len;
	printf("%d\n",max);
	return 0;
}
