#include <stdio.h>

int line_sum[5005],line[5005];
int col_sum[5005],col[5005];

int main(void){
	int N,M,G,B;
	scanf("%d%d%d%d",&N,&M,&G,&B);
	for(int i=0;i<B;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		line_sum[x]++;
		line_sum[y+1]--;
	}
	for(int i=0;i<G;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		col_sum[x]++;
		col_sum[y+1]--;
	}
	int lines=0;
	for(int i=1;i<=N;i++){
		line[i]=line[i-1]+line_sum[i];
		if(line[i]) lines++;
	}
	int cols=0;
	for(int i=1;i<=M;i++){
		col[i]=col[i-1]+col_sum[i];
		if(col[i]) cols++;
	}
	printf("%d\n",lines*M+cols*N-lines*cols);
	return 0;
}
