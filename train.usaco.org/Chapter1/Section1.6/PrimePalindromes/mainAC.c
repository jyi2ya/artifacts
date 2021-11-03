/*
ID:lindong6
PROG:pprime
LANG:C
*/

#include <stdio.h>
#include <math.h>

int isprim(int x){
	int max=sqrt(x)+10;
	if(x<=1)return 0;
	if(x==2)return 1;
	int i;
	if(x%2==0)return 0;
	for(i=3;i<x&&i<max;i+=2)if(x%i==0)return 0;
	return 1;
}

int iscycle(int x){
	int y=x,num=0;
	while (y!=0){
		num=num*10+y%10;
		y/=10;
	} 
	if (num==x) return 1;
	else return 0;
}

int main(void){
	int i,a,b;
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	scanf("%d%d",&a,&b);
#ifdef DEBUG
		printf("a=%d,b=%d,i=%d\n",a,b,i);
#endif
	if(a>b){
		i=a;a=b;b=i;
	} 
#ifdef DEBUG
		printf("a=%d,b=%d,i=%d\n",a,b,i);
#endif
	for(i=a;i<=b;i++){
		if(1000<=i && i <=9999)continue;
		if(100000<=i && i<=999999)continue;
		if(i>=10000000)break;
		if(iscycle(i))
			if(isprim(i))
				printf("%d\n",i);
	}
	return 0;
}
