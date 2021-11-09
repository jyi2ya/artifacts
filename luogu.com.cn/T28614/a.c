#include <stdio.h>

char a[10][10];

int main(void){
	for(int i=3;i>=1;i--){
		for(int j=1;j<=3;j++) a[j][i]=getchar();
		getchar();
	}
	int x,y;
	scanf("%d%d",&x,&y);
	a[x][y]='O';
	for(int i=1;i<=3;i++) {
		int num=0;
		for(int j=1;j<=3;j++) if(a[i][j]=='O') num++;
		if(num==2) for(int j=1;j<=3;j++) if(a[i][j]!='O' && a[i][j]!='X') {
			printf("%d %d\n",i,j);
			return 0;
		}
	}
	for(int j=1;j<=3;j++) {
		int num=0;
		for(int i=1;i<=3;i++) if(a[i][j]=='O') num++;
		if(num==2) for(int i=1;i<=3;i++) if(a[i][j]!='O' && a[i][j]!='X') {
			printf("%d %d\n",i,j);
			return 0;
		}
	}
	int num=0;
	for(int i=1;i<=3;i++) if(a[i][i]=='O') num++;
	if(num==2) for(int i=1;i<=3;i++) if(a[i][i]!='O' && a[i][i]!='X') {
		printf("%d %d\n",i,i);
		return 0;
	}
	num=0;
	for(int i=1;i<=3;i++) if(a[i][3-i+1]=='O') num++;
	if(num==2) for(int i=1;i<=3;i++) if(a[i][3-i+1]!='O' && a[i][3-i+1]!='X') {
		printf("%d %d\n",i,i);
		return 0;
	}
	printf("free!\n");
	return 0;
}
