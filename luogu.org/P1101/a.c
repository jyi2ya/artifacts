#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

char a[105][105];
bool show[105][105];
char s[]="yizhong";
int n,len=6;

int x,y;

bool search(int iadd,int jadd,int now){
	if(now==len)return true;

	if(a[x][y]!=s[now]) return false;

	if(y>=n || x>=n || x<0 || y<0)return false;

	x+=iadd;y+=jadd;
	if(search(iadd,jadd,now+1)){
		show[x][y]=true;
		x-=iadd;y-=jadd;
		return true;
	}

	return false;
}

void scan(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			x=i;y=j;
			if(search(-1,-1,0))show[x][y]=true;
			x=i;y=j;
			if(search(-1,0,0))show[x][y]=true;
			x=i;y=j;
			if(search(-1,1,0))show[x][y]=true;
			x=i;y=j;
			if(search(0,-1,0))show[x][y]=true;
			x=i;y=j;
			if(search(0,1,0))show[x][y]=true;
			x=i;y=j;
			if(search(1,-1,0))show[x][y]=true;
			x=i;y=j;
			if(search(1,0,0))show[x][y]=true;
			x=i;y=j;
			if(search(1,1,0))show[x][y]=true;
		}
}

void read(){
	scanf("%d",&n);
	while(getchar()!='\n');
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) a[i][j]=getchar();
		while(getchar()!='\n');
	}
}

int main(){
	read();
	scan();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) putchar(show[i][j]==true?a[i][j]:'*');
		putchar('\n');
	}
	return 0;
}

