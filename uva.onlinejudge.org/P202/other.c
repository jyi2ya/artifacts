#include <stdio.h>  
#include <string.h>  
int figure[3003],yu[3003];  
int main(void)  
{  
	int a,b;  
	while(scanf("%d %d",&a,&b)==2&&b)  
	{  
		memset(figure,0,sizeof(figure));  
		memset(yu,0,sizeof(yu));  
		figure[0]=a/b;  
		yu[0]=a%b;  
		figure[1]=yu[0]*10/b;  
		yu[1]=yu[0]*10%b;  
		int n=0,m=0;  
		for(int i=2;;i++)  
		{  
			figure[i]=yu[i-1]*10/b;  
			yu[i]=yu[i-1]*10%b;  
			for(int k=1;k<i;k++)  
			{  
				if(figure[i]==figure[k]&&yu[i]==yu[k]) {m=i;n=k;break;}  
			}  
			if(n) break;  
		}  
		printf("%d/%d = %d.",a,b,figure[0]);  
		for(int i=1;i<n&&i<=50;i++)  
			printf("%d",figure[i]);  
		printf("(");  
		for(int j=n;j<m&&j<=50;j++)  
			printf("%d",figure[j]);  
		if(m>50) printf("...");  
		printf(")\n   %d = number of digits in repeating cycle\n\n",m-n);  
	}  
	return 0;  
}  
