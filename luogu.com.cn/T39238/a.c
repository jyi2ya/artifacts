#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 11000000
char inputbuf[BUFFER_SIZE],outputbuf[BUFFER_SIZE];
char *ibf=inputbuf,*obf=outputbuf;
int iseof=0;

int getint(void);
void putint(int a);
int judge(int a);

int main(void)
{
	int ans=0;
	fread(inputbuf,BUFFER_SIZE,1,stdin);
	while('v'){
		int a=getint();
		if(iseof) break;
		ans^=a;
	}
	putint(ans);
	fwrite(outputbuf,obf-outputbuf,1,stdout);
	return 0;
}

int judge(int x)
{
	if(x<10) return 1;
	if(x<100) return 2;
	if(x<1000) return 3;
	if(x<10000) return 4;
	if(x<100000) return 5;
	if(x<1000000) return 6;
	if(x<10000000) return 7;
	if(x<100000000) return 8;
	if(x<1000000000) return 9;
	return 10;
}

void putint(int x)
{
	if(x==0){
		*obf++='0';
	} else{
		char* stk;
		if(x<0){
			*obf++='-';
			x=-x;
		}
		stk=(obf+=judge(x));
		while(x){
			int divx=x/10;
			*(--stk)=(x-divx*10+'0');
			x=divx;
		}
	}
	*obf++='\n';
}

int getint(void)
{
	int ans=0,flag=0;
	while(!isdigit(*ibf) && (*ibf)!='-' && (*ibf)!=0) ++ibf;
	if(*ibf == '-'){
		flag=1;
	} else if(*ibf == 0) {
		iseof=1;
		return 0;
	}else {
		ans=*ibf-'0';
	}

	*obf++=*ibf++;
	while(isdigit(*ibf)){
		ans=ans*10+(*ibf)-'0';
		*obf++=*ibf++;
	}
	*obf++='\n';
	if(flag) return -ans;
	return ans;
}
