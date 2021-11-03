#include <stdio.h>

int pencils;

void swap(int* a,int* b){
	int i=*a;
	*a=*b;
	*b=i;
}

int tot(int num,int pri){
	int i;
	for(i=0;i*num<pencils;i++);
	return i*pri;
}

int main(void){
	int num1,pri1,num2,pri2,num3,pri3;
	int tot1,tot2,tot3;

	//printf("-----scanning\n");
	scanf("%d%d%d%d%d%d%d",&pencils,&num1,&pri1,&num2,&pri2,&num3,&pri3);

	//printf("-----getting total cost\n");
	tot1=tot(num1,pri1);
	tot2=tot(num2,pri2);
	tot3=tot(num3,pri3);

	printf("%d",(((tot1<tot2)?tot1:tot2)<tot3)?((tot1<tot2)?tot1:tot2):tot3);
	return 0;
}
