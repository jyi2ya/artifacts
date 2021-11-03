#include <stdio.h>
#include <ctype.h>

int FromMode,ToMode;

int tonum(int ch){
	int ans;
	if(ch<='9' && ch>='0')ans=ch-'0';
	if(ch<='Z' && ch>='A')ans=ch-'A'+10;
	if(ch<='z' && ch>='a')ans=ch-'a'+10;
	return ans;
}
char toch(int num){
	char ans;
	if(num<=9 && num>=0)ans=num+'0';
	if(num<=18 && num >=10)ans=num+'A'-10;
	return ans;
}
int read(){
	int a=0,ch;
	while(getchar()!='\n');
	while(isalnum(ch=getchar())) a=a*FromMode+tonum(ch);
	return a;
}

int main(){
	scanf("%d",&FromMode);
	int a=read();
	scanf("%d",&ToMode);
#ifdef DEBUG
	printf("a=%d TOMOD=%d\n",a,ToMode);
#endif
	char buf[1000];
	int top=0;
	while(a>0){
		buf[top++]=toch(a%ToMode);
		a/=ToMode;
#ifdef DEBUG
		printf("a=%d\n",a);
#endif
	}
	while(top>0)putchar(buf[--top]);
	putchar('\n');
	return 0;
}
