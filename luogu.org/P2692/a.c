#include <stdio.h>

int line[5005],col[5005];

int main(void){
	int N,M,B,G;
	scanf("%d%d%d%d",&N,&M,&B,&G);
	for(int i=0;i<B;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=x;i<=y;i++) line[i]=1;
	}
	for(int i=0;i<G;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=x;i<=y;i++) col[i]=1;
	}
	int lines=0;
	for(int i=1;i<=N;i++) if(line[i]) lines++;
	int cols=0;
	for(int i=1;i<=M;i++) if(col[i]) cols++;
	printf("%d\n",lines*M+cols*N-lines*cols);
	return 0;
}
