#include <stdio.h>
#include <limits.h>
#define MAX 10005

int a[MAX];

int main(){
	int n,tot=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	int first=0;
	for(int i=1;i<n;i++){
		int min1=10004,min2=10004;
		a[10004]=INT_MAX;
		for(int i=first;i<n;i++){
			if(a[i]<a[min1])min1=i;
		}
		for(int i=first;i<n;i++){
			if(i==min1)continue;
			if(a[min1]<=a[i] && a[i]<a[min2])min2=i;
		}
		a[min2]+=a[min1];
		a[min1]=a[first];
		first++;
		tot+=a[min2];
#ifdef DEBUG
		printf("min1=%d,min2=%d,tot=%d\n",min1,min2,tot);
#endif
	}
	printf("%d\n",tot);
	return 0;
}

