#include <stdio.h>
#include <string.h>

char a[100004]; 

int main(void){
	scanf("%s",a);
	int ans=strlen(a);
	while(ans!=1){
		if(ans&1) break;
		int l=ans/2-1;
		int r=l+1;
		while(a[l]==a[r] && l>=0) {
			l--;r++;
		}
		if(l!=-1) break;
		ans/=2;
	}
	printf("%d\n",ans);
	return 0;
}
