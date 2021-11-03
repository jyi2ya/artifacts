#define true (1)
#define false (0)
typedef int bool;
#define inline static

/*
ID:lindong6
PROG:palsquare
LANG:C++
*/

#include <stdio.h>

char buf[1000];
int base,top=0;

void change(int base,int a){
	top=0;
	while(a>0){
		buf[top]=a%base<10?a%base+'0':a%base-10+'A';
		a/=base;
		top++;
	}
	buf[top]='\0';
}

bool isPal(){
	int i=0,j=top-1;
	while(i<j){
		if(buf[i]!=buf[j]) return false;
		i++;j--;
	}return true;
}

void outnum(int base,int a){
	char buf[1000];
	int top=0;
	while(a>0){
		buf[top]=a%base<10?a%base+'0':a%base-10+'A';
		a/=base;
		top++;
	}
	for(int i=top-1;i>=0;i--) putchar(buf[i]);
	putchar(' ');
}

int main(){
	scanf("%d",&base);
	for(int i=1;i<300;i++){
		int square=i*i;
		change(base,square);
		if(isPal()){
			outnum(base,i);
			for(int j=top-1;j>=0;j--) putchar(buf[j]);
			putchar('\n');
		}
	}
	return 0;
}
