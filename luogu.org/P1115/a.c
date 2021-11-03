#include <stdio.h>

int sum[200000],minus[200000],ans[200000],n,NoChoice=1,Max=-0xffff;

int max(int* arr,int size){
	int max=0;
	while(size--) if(arr[size]>max)max=arr[size];
	if(arr[0]>max)max=arr[0];
	return max;
}

int main(){
	scanf("%d",&n);
	scanf("%d",sum);
	minus[0]=sum[0]<0?sum[0]:0;
	ans[0]=sum[0]-minus[0];
	int i;
	for(i=1;i<n;i++){
		int j;
		scanf("%d",&j);
		if(j>Max) Max=j;
		sum[i]=sum[i-1]+j;
		if(sum[i-1]+j<minus[i-1])minus[i]=sum[i-1]+j;
		else minus[i]=minus[i-1];
		if(sum[i]!=minus[i])NoChoice=0;
		ans[i]=sum[i]-minus[i];
	}
#ifdef DEBUG
	int a;
	for(a=0;a<n;a++)printf("%-3d:sum=%-3d,minus=%-3d\n",a,sum[a],minus[a]);
#endif
	if(NoChoice)printf("%d\n",Max);
	else printf("%d\n",max(ans,n));
	return 0;
}
