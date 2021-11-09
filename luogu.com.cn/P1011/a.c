#include <stdio.h>

int feb(int x){
	if(x==1)return 1;
	if(x==2)return 1;
	return feb(x-1)+feb(x-2);
}

int sum(int x){
	int ans=0;
	for(int i=1;i<=x;i++) ans+=feb(i);
	return ans;
}

int main(){
	int a,n,m,x;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	int k=(m-(feb(n-3)+1)*a)/sum(n-4);
#ifdef DEBUG
	printf("k=%d,a=%d\n",k,a);
#endif
	printf("%d\n",(feb(x-2)+1)*a+sum(x-3)*k);
	return 0;
}

