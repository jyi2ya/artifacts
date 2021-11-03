#include <stdio.h>
#include <string.h>

char str[100];
char buf[100];
char sub[100];

int main(){
	int n;
	scanf("%d",&n);
	while(n-- && scanf("%s",str)==1){
		int len=strlen(str),sublen;
		for(sublen=1;sublen<len;sublen++){
			if(len%sublen!=0) continue;

			buf[0]='\0';
			strncpy(sub,str,sublen);
			sub[sublen]='\0';

			for(int i=0;i<len/sublen;i++) strcat(buf,sub);

			if(!strcmp(str,buf)) break;
		}
		printf("%d\n",sublen);
		if(n) putchar('\n');
	}
	return 0;
}
