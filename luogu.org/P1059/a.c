#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}

int del(int* a,int n){
	int now=*a,i,num=0;
	for(i=0;i<n;){
		i++;
		while(a[i]==now && i<n){
			a[i]=0;
			i++;	
		}
		now=a[i];
		num++;
	}
	return num;
}

int a[105];

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",a+i);
	qsort(a,n,sizeof(int),cmp);
	printf("%d\n",del(a,n));
	for(i=0;i<n;i++)if(a[i]!=0)printf("%d ",a[i]);
	return 0;
}

