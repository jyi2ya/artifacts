#include <stdio.h>

int ans[10005][10],top=0;

int main(void){ 
	int a[10],n,i;
	scanf("%d",&n);
	for(a[0]=3;a[0]>=1;a[0]--)
	for(a[1]=3;a[1]>=1;a[1]--)
	for(a[2]=3;a[2]>=1;a[2]--)
	for(a[3]=3;a[3]>=1;a[3]--)
	for(a[4]=3;a[4]>=1;a[4]--)
	for(a[5]=3;a[5]>=1;a[5]--)
	for(a[6]=3;a[6]>=1;a[6]--)
	for(a[7]=3;a[7]>=1;a[7]--)
	for(a[8]=3;a[8]>=1;a[8]--)
	for(a[9]=3;a[9]>=1;a[9]--){
		int sum=0;
		for(i=0;i<10;i++) sum+=a[i];
		if(sum==n){
		       	for(i=0;i<10;i++)ans[top][i]=a[i];
			top++;
		}
	}
	if(top==0)printf("0\n");
	else{
		printf("%d\n",top);
		while(top--){
			for(i=0;i<10;i++)printf("%d ",ans[top][i]);
			putchar('\n');
		}
	}
	return 0;
}
