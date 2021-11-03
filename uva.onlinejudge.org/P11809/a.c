#include <stdio.h>
#include <math.h>

double ans[50][50];

void init(void){
	for(register unsigned int i=0;i<10;i++)
		for(register unsigned int j=0;j<35;j++){
			ans[i][j]=0;
			for(int p=1;(unsigned int)p<=i+1;p++) ans[i][j]+=pow(2,-p);
			ans[i][j]*=pow(2,(1<<j)-1);
		}
	printf("ans[5][8]=%e\n",ans[5][8]);
}

int main(void){
	init();
	double a;
	while(scanf("%lf",&a)==1 && a!=0e0){
		int ok=0;
		int i,j;
		double EPS=(a/1e5);
		for(i=0;i<10;i++){
			for(j=0;j<35 && !ok;j++){
				double diff=(ans[i][j]-a);
#undef DEBUG
#ifdef DEBUG
				printf("i=%d,j=%d,ans[i][j]=%e,a=%e,EPS=%e,diff=%e\n",i,j,ans[i][j],a,EPS,diff);
#endif
				if(-EPS <=diff && diff <=EPS) {
					ok=1;
					break;
				}
			}
			if(ok) break;
		}
		printf("%d %d\n",i,j);
	}
	return 0;
}
