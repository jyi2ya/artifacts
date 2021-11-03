#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

#define MAX 30005

int res[MAX],ans[MAX],restop,anstop,begin,a,b;

int find(int a){
	for(int i=0;i<restop;++i) if(res[i]==a) return i;
	return -1;
}
int work(){
	while(true){
		if(res[restop-1]==0) return 1;
		res[restop]=(res[restop-1]*10)%b;
		ans[anstop++]=(res[restop-1]*10)/b;
		if((begin=find(res[restop]))!=-1) break;
		restop++;
	}
	return 0;
}


int main(){
	while(scanf("%d%d",&a,&b)==2){
		anstop=0;
		restop=0;
		printf("%d/%d = %d",a,b,a/b);
		res[restop++]=a%b;
		int NoCyc=work();
		if(anstop!=0)putchar('.');
		if(NoCyc){
			for(int i=0;i<anstop;i++){
				printf("%d",ans[i]);
			}
			printf("(0)");
			printf("\n   1 = number of digits in repeating cycle");
		}else{
			if(anstop && anstop<50 ){
				for(int i=0;i<anstop;i++){
					if(i==begin)putchar('(');
					printf("%d",ans[i]);
				}
				putchar(')');
			}
			if(anstop>=50){
				for(int i=0;i<50;i++){
					if(i==begin)putchar('(');
					printf("%d",ans[i]);
				}
				printf("...)");
			}
			printf("\n   %d = number of digits in repeating cycle",restop-begin);
		}
		putchar('\n');
		putchar('\n');
	}
	return 0;
}
