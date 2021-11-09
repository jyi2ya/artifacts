#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	char word[20];
	scanf("%s",word);
	int i;
	for(i=0;word[i]!='\0';i++)word[i]=tolower(word[i]);
	while(getchar()!='\n');
	char buf[1000];
	int ch,top=0,first=-1,now=0,times=0;
	while((ch=tolower(getchar()))!=EOF){
		now++;
		if(ch==' '){	
			buf[top]='\0';
#ifdef DEBUG
			printf("%s %s\n",word,buf);
#endif
			if(!strcmp(buf,word)){
				if(first==-1)first=now-strlen(word)-1;
				times++;
			}
			memset(buf,0,sizeof(buf));
			top=0;
		}
		else buf[top++]=ch;
	}
	if(times==0)printf("-1\n");
	else printf("%d %d\n",times,first);
	return 0;
}
