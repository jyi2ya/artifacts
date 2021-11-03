#include <stdio.h>
#include <string.h>
#include <ctype.h>

void RC(char* buf){
	int R,C,cnt,outtop=0;
	char out[1024];
	memset(out,0,sizeof(out));
	sscanf(buf+1,"%d",&R);
	for(cnt=1;isdigit(buf[cnt]);cnt++);
	sscanf(buf+cnt+1,"%d",&C);
	while(C){
#ifdef DEBUG
		printf("DEBUG:C=%d\n",C);
#endif
		out[outtop++]=(C%26);
		if(C%26==0) C--;
		C/=26;
	}
	while(outtop--) putchar((out[outtop]+25)%26+'A');
	printf("%d\n",R);
}
void alnum(char* buf){
	int i=0;
	int C=0,R=0;
	while(isalpha(buf[i])){
		C=C*26+buf[i]-'A'+1;
		i++;
	}
	sscanf(buf+i,"%d",&R);
	printf("R%dC%d\n",R,C);
}

int main(void){
	int n;
	scanf("%d",&n);
	while(getchar()!='\n');
	while(n--){
		char buf[1024];
		fgets(buf,1024,stdin);
		if(buf[0]=='R' && strchr(buf,'C') && isdigit(buf[1])) RC(buf);
		else alnum(buf);
	}
	return 0;
}
