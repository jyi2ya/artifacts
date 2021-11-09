#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n;
char word[107][59],buf[65535];

void read(void){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		int j;
		scanf("%s",word[i]+1);
		word[i][0]=' ';
		for(j=0;word[i][j]!='\0';++j) word[i][j]=tolower(word[i][j]);
		word[i][j]=' ';
		word[i][j+1]='\0';
	}
}

int main(void){
	int ans=0;
	read();
	while('v'){
		int i=1,ch;
		buf[0]=' ';
		while((ch=getchar())!='.'){
			if(ch==EOF) goto end;
			if(ch=='\n') continue;
			if(ch==',') ch=' ';
			buf[i++]=tolower(ch);
		}
		buf[i]=' ';
		buf[i+1]='\0';
		for(i=0;i<n;++i) if(strstr(buf,word[i])!=NULL) ++ans;
	}
end:
	printf("%d\n",ans);
	return 0;
}
