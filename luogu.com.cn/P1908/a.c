#include <stdio.h>

#define MAX 40007
int a[MAX],tmp[MAX],n;

int msort(int l,int r);

int main(void){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",a+i);
	printf("%d\n",msort(0,n));
	return 0;
}

int msort(int l,int r){
	int ans=0,mid=l+(r-l)/2,i=l,j=mid,tmptop=0;
	if(r-l<=1) return 0;
	ans+=msort(l,mid);
	ans+=msort(mid,r);
	while(i<mid || j<r){
		if((j>=r || a[i] < a[j]) && i<mid){
			tmp[tmptop++]=a[i++];
		}else if(j<r){
			ans+=mid-i;
			tmp[tmptop++]=a[j++];
		}
	}
	for(i=0;i<tmptop;++i) a[l+i]=tmp[i];
	return ans;
}
