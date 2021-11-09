#include <stdio.h>
#include <math.h>

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

double dis(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	int N,M,K,T,ans=0;
	scanf("%d%d%d%d",&N,&M,&K,&T);
	while(K--){
		int x,y;
		scanf("%d%d",&x,&y);
		int minx=max(1,x-T),maxx=min(N,x+T);
		int miny=max(1,y-T),maxy=min(M,y+T);
#ifdef DEBUG
		printf("minx=%d,miny=%d,maxx=%d,maxy=%d\n",minx,miny,maxx,maxy);
#endif
		int sum=0;
		for(int i=minx;i<=maxx;i++)
			for(int j=miny;j<=maxy;j++)
				if(dis(i,j,x,y)<=T) sum++;
		if(sum>ans) ans=sum;
	}
	printf("%d\n",ans);
	return 0;
}
