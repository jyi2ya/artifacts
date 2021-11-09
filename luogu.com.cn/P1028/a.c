#include <stdio.h>
int ans=0;

void solve(int i){
#ifdef DEBUG
	printf("     -----ans=%d\n",ans);
#endif
	if(i==0)return;
	else{
		ans++;int k;
		for(k=0;k<=i/2;k++)solve(k);
	}
}

int main(void){
	int i=0;
	while(1){
		solve(i);	
		printf("%d %d\n",i,ans);
		i++;ans=0;
	}
	return 0;
}
