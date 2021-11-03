#include <stdio.h>
int ans=0;

int put(int apple,int plate){
	if(plate>apple)plate=apple;
	if(plate==1||apple==0){
		ans++;return 1;
	}
	int planow=plate;
	while(planow){
		put(apple-planow,planow);
		planow--;
	}
}
int main(void){
	int a;
	scanf("%d",&a);
	while(a--){
		int m,n;
		scanf("%d%d",&m,&n);
		put(m,n);
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
