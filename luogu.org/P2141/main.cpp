#include <cstdio>
#include <algorithm>

int a[105],find[105],top=0;

int main(void){
	int nums,tot=0;
	scanf("%d",&nums);
	for(int i=0;i<nums;i++) scanf("%d",a+i);
	std::sort(a,a+nums);
	for(int i=1;i<nums;i++){
		for(int j=i;j>=0;j--){
			int except=a[i]-a[j];
			if(except==a[i] || except==a[j]) continue;
			if(!std::binary_search(a,a+nums,except)) continue;
			else {
				if(find[top]!=a[i]){
#ifdef DEBUG
					printf("a[i]=%d,a[j]=%d,%d+%d=%d\n",a[i],a[j],a[j],a[i]-a[j],a[i]);
#endif
					find[++top]=a[i];
					tot++;
				}
			}
		}
	}
	printf("%d\n",tot);
	return 0;
}
