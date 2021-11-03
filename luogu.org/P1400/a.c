#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000009
#define MAX 600009

int cmp(const void*,const void*);

int lb(int a,int start);
int ub(int a,int start);

int arr[MAX],N,D;

int main(void)
{
	int i;
	long long ans=1;
	scanf("%d%d",&N,&D);
	for(i=0;i<N;++i) scanf("%d",arr+i);
	qsort(arr,N,sizeof(int),cmp);
	for(i=0;i<N;++i){
		ans*=(ub(arr[i]+D,i+1)-lb(arr[i],i+1)+1);
		ans%=MOD;
	}
	printf("%lld\n",ans);
	return 0;
}

int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}

int lb(int a,int start)
{
	int l=start,r=N;
	while(l<r){
		int mid=l+(r-l)/2;
		if(arr[mid]>=a) r=mid;
		else l=mid+1;
	}
	return l;
}
int ub(int a,int start)
{
	int l=start,r=N;
	while(l<r){
		int mid=l+(r-l)/2;
		if(arr[mid]<=a) l=mid+1;
		else r=mid;
	}
	return l;
}
