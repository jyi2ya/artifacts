#include <stdio.h>

int main(void){
	int n;
	char ch;
	scanf("%d\n",&n);
	while(n--){
		int sum=0,num=0;
		while((ch=getchar())!='\n'){
			if(ch=='O'){
				++num;sum+=num;
			}
			if(ch=='X')num=0;
		}
		printf("%d\n",sum);
	}
	return 0;
}
