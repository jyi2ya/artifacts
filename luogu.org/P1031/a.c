#include <stdio.h>
int a[105];

int main(){
	int n,i,sum=0,average,times=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		sum+=a[i];
	}
	average=sum/n;
	for(i=0;i<n;i++){
		if(a[i]==average)continue;
		if(i+1!=n)a[i+1]+=a[i]-average;
		times++;
	}
	printf("%d\n",times);
	return 0;
}


