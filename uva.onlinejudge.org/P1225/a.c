#include <stdio.h>
#include <string.h>

int main(void){
	int x;
	scanf("%d",&x);
	while(x--){
		char buf[6];
		int i,t,n;
		int times[10];
		memset(times,0,sizeof(times));

		scanf("%d",&n);
		for(i=1;i<=n;i++){
			sprintf(buf,"%d",i);
			for(t=0 ; buf[t]!='\0'&& t<=5 ;t++)
				times[buf[t] - '0'] ++;
		}

		printf("%d %d %d %d %d %d %d %d %d %d\n",times[0],times[1],times[2],times[3],times[4],times[5],times[6],times[7],times[8],times[9]);
	}
	return 0;
}





