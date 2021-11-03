#include <stdio.h>
#include <string.h>

char stack[100];
int top=0;

void push(int x){
	stack[top++]=x;
}
int pop(void){
	return stack[--top];
}

void prt(void){
#ifdef DEBUG
	printf("PRT,top=%d\n",top);
#endif
	if(top<=0);
	else{
		char buf[100];
		int tp=0;
		long long n;
		while(top>=0)buf[tp++]=pop();
		buf[tp]='\0';
		sscanf(buf,"%lld",&n);
		printf("%lld",n);
	}
}

int main(void){
	int ch;
	while((ch=getchar())!=EOF){
		if(ch<='9' && ch>='0')push(ch);
		else{
			prt();putchar(ch);
		}
	}
	prt();
	return 0;
}

