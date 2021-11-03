#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>
#include <string.h>

char DNA[105];
int len;

bool less(int a,int b){
	int i;
	for(i=0;i<len;i++){
		int A=(a+i)%len,B=(b+i)%len;
		if(DNA[A]!=DNA[B]) return DNA[A]<DNA[B];
	}
	return 0;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",DNA);
		len=strlen(DNA);int min=0;
		for(int i=0;i<len;i++) if(less(i,min)) min=i;
		for(int i=0;i<len;i++) putchar(DNA[(i+min)%len]);
		putchar('\n');
	}
	return 0;
}
