#include <stdio.h>

int T;
char buf[105];
int exp[5]={10,20,30,40,50};

void read(void){
	scanf("%*d%s",buf);
}
int level(int exp){
	if(exp<50)  return 0;
	if(exp<150) return 1;
	if(exp<250) return 2;
	if(exp<350) return 3;
	if(exp<450) return 4;
	if(exp<550) return 5;
	if(exp<650) return 6;
	if(exp<750) return 7;
	return 8;
}

int main(void){
	scanf("%d",&T);
	while(T--){
		read();
		int days=0,i=0,ex=0;
		while(buf[i]!='\0'){
			if(buf[i]=='1'){
				ex+=exp[days];
				days++;
			}else if(buf[i]=='0'){
				days=0;
			}
			if(days==5) days=0;
			i++;
		}
		printf("%d\n",level(ex));
	}
	return 0;
}
