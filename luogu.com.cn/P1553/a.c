#include <stdio.h>

char stack[30],buf[30];
int stp=0,btp=0;

void push(char* stack,int* top,int x){
	stack[(*top)++]=x;
#ifdef DEBUG
	printf("PUSH,top=%d\n",*top);
#endif
}
int pop(char* stack,int* top){
#ifdef DEBUG
	printf("POP,top=%d\n",*top);
#endif
	return stack[--(*top)];
}

void prt(void){
#ifdef DEBUG
	printf("PRT,stp=%d,btp=%d\n",stp,btp);
#endif
	if(stp<=0);
	else{		
		char ch,first=1;
		while(stp>0){
			ch=pop(stack,&stp);
			if(ch=='0'&&first);
			else {
				first=0;
				push(buf,&btp,ch);
			}
		}
		first=1;
		while(btp>0){
			ch=pop(buf,&btp);
			if(ch=='0'&&first);
			else {
				first=0;
				push(stack,&stp,ch);
			}
		}
		if(stp==0)putchar('0');
		else while(stp>0)putchar(pop(stack,&stp));
	}
}

int main(void){
	int ch;
	while((ch=getchar())!=EOF){
		if(ch<='9' && ch>='0')push(stack,&stp,ch);
		else{
			prt();putchar(ch);
		}
	}
	prt();
	return 0;
}
