#include <stdio.h>

char stack[100];
int top=0;

void push(int x){
	stack[top++]=x;
}

int pop(void){
	return stack[--top];
}

int main(void){
	int ch,minus=0;
	while((ch=getchar())!=EOF){
		if(ch=='-')minus=1;
		else if('0'<=ch && ch<='9')push(ch);
		else ;
	}
	if(minus)putchar('-');
	while((ch=pop())=='0');putchar(ch);
	while(top>0)putchar(pop());
	putchar('\n');
	return 0;
}
