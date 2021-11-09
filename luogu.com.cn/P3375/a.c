#include <stdio.h>
#include <string.h>

char s1[1000009],s2[1000009];
int fail[1000009];
unsigned int len;

void getfail(void);
void getsame(void);

int main(void)
{
	int i;
	scanf("%s%s",s1,s2);
	len=strlen(s2);
	getfail();
	getsame();
	for(i=1;s2[i-1]!='\0';++i) printf("%d ",fail[i]);
	putchar('\n');
	return 0;
}

void getfail(void)
{
	int i,j=0;
	fail[0]=0;
	for(i=1;s2[i]!='\0';++i){
		while(j && s2[i]!=s2[j]) j=fail[j];
		if(s2[i]==s2[j]) ++j;
		fail[i+1]=j;
	}
}

void getsame(void)
{
	int i,j=0;
	for(i=0;s1[i]!='\0';++i){
		while(j && s1[i]!=s2[j]) j=fail[j];
		if(s2[j]==s1[i]) ++j;
		if(s2[j]=='\0') printf("%d\n",i-len+2);
	}
}
