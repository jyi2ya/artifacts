#include <stdio.h>

int main(){
	int n,num,first=1;
	scanf("%d",&n);
	while(scanf("%d",&num)==1){
		if(num==1||num==-1){
			if(n==0){
				if(num==1)printf("+1");
				if(num==-1)printf("-1");
			}
			else{
				if(num==1&&first!=1)putchar('+');
				if(num==-1)putchar('-');
			}
		}
		else{
			if(num==0){
				n--;
				continue;
			}
			if(num>0&&first!=1)putchar('+');
			printf("%d",num);
		}
		if(n!=1&&num!=0&&n!=0){
			printf("x^");
			printf("%d",n);
		}
		if(n==1&&num!=0&&n!=0)putchar('x');
#ifdef DEBUG
		printf("n=%d,num=%d\n",n,num);
#endif
		n--;
		first=0;
	}
	return 0;
}

