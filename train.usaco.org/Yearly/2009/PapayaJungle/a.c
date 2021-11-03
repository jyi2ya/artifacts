#include <stdio.h>

int a[45][45];

int main(void){
	int R,C;
	scanf("%d%d",&R,&C);
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			scanf("%d",a[i]+j);
	int x=1,y=1,tot=0;
	while(!(x==R && y==C)){
#ifdef DEBUG
		printf("x=%d,y=%d\n",y,x);
#endif
		int dx=1,dy=0,max=a[x+dx][y+dy];
		if(a[x-1][y]>max){max=a[x-1][y];dx=-1;dy=0;}
		if(a[x][y-1]>max){max=a[x][y-1];dx=0;dy=-1;}
		if(a[x][y+1]>max){max=a[x][y+1];dx=0;dy=1;}
		tot+=a[x][y];
		a[x][y]=0;
		x+=dx;y+=dy;
	}
	tot+=a[R][C];
	printf("%d\n",tot);
	return 0;
}
