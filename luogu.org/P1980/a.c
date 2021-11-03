#include <stdio.h>

int a[10];

int main(void){
	int n,x;
	scanf("%d%d",&n,&x);
	
	{
		int i;
		for(i=1;i<=n;i++){
			//printf("     -----i=%d\n",i);
			int j;
			for(j=i;j>0;j/=10) a[j%10]++;
		}
	}
	printf("%d",a[x]);
	return 0;
}
