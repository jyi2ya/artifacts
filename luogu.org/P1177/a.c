#include <stdio.h>

int a[100005];

void sort(int* a,int size){
	if(size<2)return;
	int i=0,j=size-1,temp=a[0x66ccff%size];
	while(i<=j){
		while(a[j]>temp)j--;
		while(a[i]<temp)i++;
		if(i<=j){
			int x=a[i];a[i]=a[j];a[j]=x;
			i++;j--;
		}
	}
	sort(a,j+1);
	sort(a+i,size-i);
}

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",a+i);
	sort(a,n);
	for(i=0;i<n;i++)printf("%d ",a[i]);
	return 0;
}

