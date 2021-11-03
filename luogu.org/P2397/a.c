#include <stdio.h>

int main(void)
{
	int a,num=1,n;
	scanf("%d%d",&n,&a);
	--n;
	while(n--){
		int b;
		scanf("%d",&b);
		if(b==a) ++num;
		else --num;
		if(num==0){
			a=b;
			++num;
		}
	}
	printf("%d\n",a);
	return 0;
}
