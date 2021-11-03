#include <stdio.h>

#define FIR(x) ((x)/100)
#define SEC(x) ((x)/10%10)
#define THI(x) ((x)%10)
#define SUM(X) (FIR(X)+SEC(X)+THI(X))
#define PRO(X) (FIR(X)*SEC(X)*THI(X))

int OK(int i,int j,int k){
	if(SUM(i)+SUM(j)+SUM(k)==45 &&
			PRO(i)*PRO(j)*PRO(k)==362880)return 1;
	return 0;
}

int main(void){
	int i,j,k,A,B,C,ans=0;//A:B:C
	scanf("%d%d%d",&A,&B,&C);
	if(A%2==0&&B%2==0&&C%2==0){
		A/=2;B/=2;C/=2;
	}
	if(A%3==0&&B%3==0&&C%3==0){
		A/=3;B/=3;C/=3;
	}
	for(i=123;i<988;i++){
		for(j=123;j<988;j++){
			if((k=i/A*C)==(j/B*C)){
				if(i%A!=0||j%B!=0||k%C!=0)continue;
				if(OK(i,j,k)){
					ans=1;
					printf("%d %d %d\n",i,j,k);
			}
		}
	}
	}
	if(ans==0)printf("No!!!\n");
	return 0;
}
