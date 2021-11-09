#include <stdio.h>

int gcd(int x,int y){
	if(x%y==0)return y;
	else return gcd(y,x%y);
}

int main(){
	int x,y;
	scanf("%d%d",&x,&y);

	int tot=x*y,ans=0;
	for(int i=x;i<=y;i++) if(tot%i==0 && tot/gcd(i,tot/i) == y && gcd(i,tot/i)==x) ans++;
	printf("%d\n",ans);
	return 0;
}
