#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>
#include <string.h>

char word[25][100],first,buf[2500];
int n,used[25],best=0;

void read(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",word[i]);
	while(getchar()!='\n');
	first=getchar();
#ifdef DEBUG
	printf("read:%d\n",n);
	for(int i=0;i<n;i++) printf("%s\n",word[i]);
	putchar(first);putchar('\n');
#endif
}

void dfs(){
#ifdef DEBUG
	printf("buf=%s\n",buf);
	printf("used:");
	for(int i=0;i<n;i++) printf("used[%d]=%d ",i,used[i]);
	putchar('\n');
#endif
	int len=strlen(buf);
	if(len>best)best=len;
	for(int i=0;i<n;i++){
		if(used[i]==2) continue;
		int max=0;
		for(int k=1;k<=len;k++){
			bool no=false;
			int a=len-k,b=0;
			while(b<k){
				if(buf[a]!=word[i][b]){
					no=true;
					break;
				}
				b++;a++;
			}
			if(!no){ max=k;break;}
		}
		if(max==0)continue;
		used[i]++;
		buf[len-max]='\0';
		strcat(buf,word[i]);
		dfs();
		buf[len+max]='\0';
		used[i]--;
	}
}

int main(){
	read();
	for(int i=0;i<n;i++)
		if(word[i][0]==first){
			used[i]++;
			strcpy(buf,word[i]);
			dfs();
		}
	printf("%d\n",best);
	return 0;
}
