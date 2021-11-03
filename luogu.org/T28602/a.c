#include <stdio.h>
#include <string.h>

int main(void){
	char buf[10];
	int cnt=0;
	while(scanf("%s",buf)==1) {
		if(buf[0]=='Y') {
			scanf("%s",buf);
			if(!strcmp(buf,"wzr12345")) {
				printf("Success\n");
				return 0;
			}else{
				printf("Sorry\n");
				cnt++;
				if(cnt==3) {
					printf("Warning!\n");
					return 0;
				}
			}
		} else {
			return 0;
		}
	}
	return 0;
}
