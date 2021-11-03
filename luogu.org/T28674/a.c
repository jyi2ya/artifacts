#include <stdio.h>
#include <stdlib.h>

/*buf size*/
#define BUF_MAX 10000
#define MEM_MAX 10000

char* p;

/*if it got "[",read a loop*/
char* readbuf(void){
	char* buf=(char*)malloc(BUF_MAX*sizeof(char));
	int ch,top=1;buf[0]='[';
	while((ch=getchar())!=']') buf[top++]=ch;
	buf[top]='\0';
	return buf;
}

void solvebuf(char* buf);
int explain(char ch);

int explain(char ch){
	if(ch==' ' || ch=='\n' || ch=='\r')return 1;
	switch(ch){
		case '>':{++p;break;}
		case '<':{--p;break;}
		case '+':{++(*p);break;}
		case '-':{--(*p);break;}
		case '.':{putchar(*p);break;}
		case '[':{
				 char* buf=readbuf();
				 while(*p)solvebuf(buf);
				 free(buf);
				 break;
			 }
		default:break;
	}
	return 1;
}

void solvebuf(char* buf){
	int now=1;
	while(buf[now]!='\0') explain(buf[now++]);
}

int main(void){
	p=(char*)malloc(MEM_MAX*sizeof(char));

	int ch;
	while((ch=getchar())!=EOF) explain(ch);
	putchar('\n');
	free(p);
	return 0;
}
