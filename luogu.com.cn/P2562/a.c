#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

char buf[1000];

void T(char* str,int lenth){
	bool full=true;
	for(int i=0;i<lenth;i++) if(str[i]!=*str) full=false;
	if(full){
		if(*str=='1') putchar('B');
		if(*str=='0') putchar('A');
	}else{
		putchar('C');
		T(str,lenth/2);
		T(str+lenth/2,lenth/2);
	}
}

int main(){
	int top=0,ch;
	while((ch=getchar())<='9' && ch>='0') buf[top++]=ch;
	T(buf,top);
	putchar('\n');
	return 0;
}
