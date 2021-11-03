#include <stdio.h>
int city[15][15];

int main(void){
	for(int i=0;i<3;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int a=x1;a<x2;a++)
			for(int b=y1;b<y2;b++)
				city[a][b]=1;
	}
	int tot=0;
	for(int i=1;i<11;i++){
		for(int j=1;j<11;j++){
			if(city[i][j]!=1) tot++;
		}
	}
	if(tot==0) printf("xiaowang will die\n");
	else printf("%d\n",tot);
	return 0;
}
