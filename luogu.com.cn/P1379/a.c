#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

#define MAX 1000000

char que[MAX][3][3];
char goal[3][3]={1,2,3,8,0,4,7,6,5};
int top=2,bot=0,last[MAX];
bool used[9][9][9][9][9][9][9][9][9];

bool got(char a[3][3]){
	if(used[a[0][0]][a[0][1]][a[0][2]][a[1][0]][a[1][1]][a[1][2]][a[2][0]][a[2][1]][a[2][2]])return true;
	used[a[0][0]][a[0][1]][a[0][2]][a[1][0]][a[1][1]][a[1][2]][a[2][0]][a[2][1]][a[2][2]]=true;
	return false;
}
void cpy(char dest[3][3],char src[3][3]){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			dest[i][j]=src[i][j];
}

bool check(char a[3][3]){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a[i][j]!=goal[i][j])return false;
	return true;
}

#ifdef DEBUG
void out(char a[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++) printf("%d",a[i][j]);
		putchar('\n');
	}
}
#endif

int main(){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			que[1][i][j]=getchar()-'0';
	while(top-bot-1){
		bot++;
#ifdef DEBUG
		printf("bot=%d,top=%d\n",bot,top);
		out(que[bot]);
		putchar('\n');
#endif
		if(got(que[bot]))continue;
		if(check(que[bot]))break;
		int x,y;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(que[bot][i][j]==0){x=i;y=j;}
		if(x+1<3){
			cpy(que[top],que[bot]);
			que[top][x][y]=que[top][x+1][y];
			que[top][x+1][y]=0;
			last[top]=bot;
			top++;
		}
		if(x-1>=0){
			cpy(que[top],que[bot]);
			que[top][x][y]=que[top][x-1][y];
			que[top][x-1][y]=0;
			last[top]=bot;
			top++;
		}
		if(y+1<3){
			cpy(que[top],que[bot]);
			que[top][x][y]=que[top][x][y+1];
			que[top][x][y+1]=0;
			last[top]=bot;
			top++;
		}
		if(y-1>=0){
			cpy(que[top],que[bot]);
			que[top][x][y]=que[top][x][y-1];
			que[top][x][y-1]=0;
			last[top]=bot;
			top++;
		}
	}
	int cnt=0;
	while(bot!=1){cnt++;bot=last[bot];}
	printf("%d\n",cnt);
	return 0;
}
