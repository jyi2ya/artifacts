#include<stdio.h>

int main(void){
	int k,n=0;
	scanf("%d",&k);
	double Sn;
	for(Sn=0; Sn<=k; ++n,Sn+=1.0/n);
		//printf("     -----k=%d,n=%d,1/n=%f,Sn=%f,K=%d\n",k,n,1.0/(float)n,Sn,k);
	printf("%d",n);
	return 0;
}
