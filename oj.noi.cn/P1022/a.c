#include <stdio.h>

int main(void){
	int n,tot=0,i;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		int a;
		scanf("%d",&a);
		tot+=a;
	}
	printf("%.2f\n",(double)tot/n);
	return 0;
}
