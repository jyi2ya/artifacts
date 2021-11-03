#include <stdio.h>

int main(void){
	int n,a=0,b=0,c=0;
	scanf("%d",&n);
	while(n--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a+=x;b+=y;c+=z;
	}
	printf("%d %d %d %d\n",a,b,c,a+b+c);
	return 0;
}
