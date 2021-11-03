#include <stdio.h>
#include <ctype.h>

char k[105],C[1005];

void read(){
	scanf("%s%s",k,C);
}

int toM(int C,int key){
	int a=toupper(C)-'A';
	int b=toupper(key)-'A';
	int c=a-b;if(c<=0)c+=26;
	if(isupper(C))return c%26+'A';
	return c%26+'a';
}

int main(){
	read();
	int lenofkey=strlen(k);
	for(int p=0;C[p]!='\0';p++) putchar(toM(C[p],k[p%lenofkey]));
	putchar('\n');
	return 0;
}
