/*
ID:lindong6
PROB:milk2
LANG:C++
 */

#include <stdio.h>
#include <string.h>

int N;
int a[1000005],END=0;

void read(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int begin,end;
		scanf("%d%d",&begin,&end);
		if(end>END)END=end;
		memset(a+begin,1,sizeof(int)*(end-begin));
	}
}

int main(){
	read();
	int NoOne_Max=0,Milking_Max=0;
	int i,now=0;
	while(a[now]==0 && now<END)now++;
	while(now<END){
		i=0;
		while(a[now]!=0 && now<END){i++;now++;}
		if(i>Milking_Max)Milking_Max=i;
		i=0;
		while(a[now]==0 && now<END){i++;now++;}
		if(i>NoOne_Max)NoOne_Max=i;
	}
	printf("%d %d\n",Milking_Max,NoOne_Max);
	return 0;
}
