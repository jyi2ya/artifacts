#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

#define t true
#define f false

bool num[10][3]={\
	{t,f,t},\
	{f,f,f},\
	{t,t,t},\
	{t,t,t},\
	{f,t,f},\
	{t,t,t},\
	{t,t,t},\
	{t,f,f},\
	{t,t,t},\
	{t,t,t}\
};

bool n[10][2][2]={\
	{{t,t},{t,t}},\
	{{f,t},{f,t}},\
	{{f,t},{t,f}},\
	{{f,t},{f,t}},\
	{{t,t},{f,t}},\
	{{t,f},{f,t}},\
	{{t,f},{t,t}},\
	{{f,t},{f,t}},\
	{{t,t},{t,t}},\
	{{t,t},{f,t}}\
};

int main(){
	int size,top=0,buf[100],ch;
	scanf("%d",&size);
	while(getchar()!='\n');
	while((ch=getchar())<='9' && ch>='0') buf[top++]=ch-'0';

#ifdef DEBUG
	printf("read Done:%d\n",size);
	for(int i=0;i<top;i++) printf("%d ",buf[i]);
	putchar('\n');
#endif

	for(int i=0;i<top;i++){
		putchar(' ');
	       	for(int j=0;j<size;j++) putchar(num[buf[i]][0]?'-':' ');
		putchar(' ');
		putchar(' ');
	}/*Line 1*/
	putchar('\n');

	for(int j=0;j<size;j++){
		for(int i=0;i<top;i++){
			putchar(n[buf[i]][0][0]?'|':' ');
			for(int k=0;k<size;k++) putchar(' ');
			putchar(n[buf[i]][0][1]?'|':' ');
			putchar(' ');
		}
		putchar('\n');
	}
	
	for(int i=0;i<top;i++){
		putchar(' ');
	       	for(int j=0;j<size;j++) putchar(num[buf[i]][1]?'-':' ');
		putchar(' ');
		putchar(' ');
	}/*Line 4*/
	putchar('\n');

	for(int j=0;j<size;j++){
		for(int i=0;i<top;i++){
			putchar(n[buf[i]][1][0]?'|':' ');
			for(int k=0;k<size;k++) putchar(' ');
			putchar(n[buf[i]][1][1]?'|':' ');
			putchar(' ');
		}
		putchar('\n');
	}

	for(int i=0;i<top;i++){
		putchar(' ');
	       	for(int j=0;j<size;j++) putchar(num[buf[i]][2]?'-':' ');
		putchar(' ');
		putchar(' ');
	}/*Line 4*/
	putchar('\n');

	return 0;
}
