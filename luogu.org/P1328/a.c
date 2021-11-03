#include <stdio.h>

int A[300],B[300];
int win[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};

#ifdef TSTWIN
void testwin(void){
	while(1){
		printf("please enter 1,2...");
		int i,j;
		scanf("%d%d",&i,&j);
		printf("%d\n",win[i][j]);
	}
}
#endif

int main(void){
#ifdef TSTWIN
	testwin();
#endif
	int N,NA,NB,i,a=0,b=0,j=0,k=0;
	scanf("%d%d%d",&N,&NA,&NB);
	for(i=0;i<NA;i++)scanf("%d",A+i);
	for(i=0;i<NB;i++)scanf("%d",B+i);
#ifdef DEBUG
	for(i=0;i<NA;i++)printf("%d ",A[i]);putchar('\n');
	for(i=0;i<NB;i++)printf("%d ",B[i]);putchar('\n');
#endif
	while(N--){
#ifdef DEBUG
		printf("N=%d,a=%d,b=%d,j=%d,k=%d,win[j][k]=%d\n",N,a,b,j,k,win[j][k]);
#endif
		a+=win[A[j]][B[k]];
		b+=win[B[k]][A[j]];
		j=(j==NA-1)?0:j+1;
		k=(k==NB-1)?0:k+1;
	}
	printf("%d %d\n",a,b);
	return 0;
}
