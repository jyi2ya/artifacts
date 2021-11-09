#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[20],num=0,top=0;
int prime[20000],prmtop=0;

int isprim(int x){
	if(x<=1)return 0;
	if(x==2)return 1;
	int i;int max=(int)sqrt((double)x)+1;
	if(x%2==0)return 0;
	for(i=3;i<=max;i+=2)if(x%i==0)return 0;
	return 1;
}

int solve(int begin,int end,int k,int sum){
#ifdef DEBUG
	printf("     begin=%d,end=%d,k=%d,sum=%d\n",begin,end,k,sum);
#endif
	if(end-begin+1<k)return 0;
	if(k==1){
		int i;
		for(i=begin;i<=end;i++){
#ifdef DEBUG
			printf("     %d\n",sum+a[i]);
#endif
			if(isprim(sum+a[i]))num++;
		}
		return 1;
	}else{
		int i;
		for(i=begin+1;i<=end;i++)solve(i,end,k-1,sum+a[i-1]);
	}
}

int main(void){
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		top++;
	}
#ifdef DEBUG
	for(i=0;i<top;i++)printf("%d ",a[i]);
	putchar('\n');
#endif
	solve(0,top-1,k,0);
	printf("%d\n",num);
	return 0;
}
