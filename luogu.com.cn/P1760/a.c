#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>
#include <string.h>

#define MAX 10000
#define BASE 10000

int a[MAX],lenth=1;

void mul(){
	for(int i=0;i<lenth;i++) a[i]<<=1;
	for(int i=0;i<lenth;i++)
		if(a[i]>BASE){
			a[i+1]+=a[i]/BASE;
			a[i]%=BASE;
		}
	while(a[lenth]>0) lenth++;
}

int main(){
	int n;
	scanf("%d",&n);
	a[0]=1;
	while(n--) mul();
	a[0]-=1;
	bool first=true;
	for(int i=lenth-1;i>=0;i--)
		if(first){
			first=false;printf("%d",a[i]);
		}else printf("%04d",a[i]);
	putchar('\n');
	return 0;
}
