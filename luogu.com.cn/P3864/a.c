#define true (1)
#define false (0)
typedef int bool;
#define inline static

/*
ID:lindong6
PROG:namenum
LANG:C++
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lenth;

int len(char* a){
	int i=0;
	while(a[i]!='\0')i++;
	return i;
}

int cmp(const void* a,const void* b){
	return strcmp((char*)a,(char*)b);
}

char buf[15];
char key[10][4]={"000","000","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
int num[15];
char dic[5000][15];
int dicnum=0;

bool dfs(int now){
	if(now==lenth){
		buf[now]='\0';
		if(bsearch(&buf,dic,dicnum,sizeof(buf),cmp)!=NULL) {
			printf("%s\n",buf);
			return true;
		}else return false;
	}
	bool find=false;
	for(int i=0;i<3;i++){
		buf[now]=key[num[now]][i];
		if(dfs(now+1))find=true;
	}
	return find;
}

int main(){
	scanf("%s",buf);lenth=len(buf);
	while(scanf("%s",dic[dicnum])==1)
		dicnum++;
	for(int i=0;i<lenth;i++)num[i]=buf[i]-'0';

	if(!dfs(0))printf("NONE\n");
	return 0;
}
