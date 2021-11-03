#define true (1)
#define false (0)
typedef int bool;
#define inline static

/*
ID:lindong6
PROG:dualpal
LANG:C++
*/

#include <stdio.h>

char buf[1000];
int top=0;

void change(int base,int num){
	top=0;
	while(num>0){
		int a=num%base;
		a+='0';
		buf[top++]=a;
		num/=base;
	}
}

bool isPal(){
	int i=0,j=top-1;
	while(i<j){
		if(buf[i]!=buf[j])return false;
		i++;j--;
	}return true;
}

int main(){
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int N,S;
	scanf("%d%d",&N,&S);
	for(int i=S+1;N;i++){
		int ok=0;
		for(int base=2;base<=10;base++) {
			change(base,i);
			if(isPal())ok++;
		}
		if(ok>=2){
			printf("%d\n",i);
			N--;
		}
	}
	return 0;
}
