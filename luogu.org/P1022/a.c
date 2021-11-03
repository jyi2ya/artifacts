#include <stdio.h>
#include <string.h>

int main(void){
	int ch,top=0,i,equ_left=1,x;
	char buf[100];
	int changshu=0,xishu=0;
	while((ch=getchar())!=EOF){
		if(ch=='+'||ch=='-'||ch=='\n'){
			buf[top]='\0';
#ifdef DEBUG
			printf("Find a num...%s\n",buf);
#endif
			if(sscanf(buf,"%d",&i)==1){
				if(equ_left) changshu+=i;
				else changshu-=i;
			}
			top=0;
			memset(buf,0,sizeof(buf));
			buf[top++]=ch;
		}else if(ch=='='){
#ifdef DEBUG
			printf("top=%d\n",top);
#endif
#ifdef DEBUG
			printf("Equ found!\nFind a num...%s\n",buf);
#endif
			if(sscanf(buf,"%d",&i)==1){
				if(equ_left) changshu+=i;
				else changshu-=i;
			}
			top=0;
			memset(buf,0,sizeof(buf));
			equ_left=0;
		}
		else if('0'<=ch&&ch<='9'){
			buf[top++]=ch;
		}
		else if('a'<=ch&&ch<='z'){
#ifdef DEBUG
			printf("Find a character!%c,\nFind a num...%s\n",ch,buf);
#endif
			x=ch;
			buf[top]='\0';
			if(sscanf(buf,"%d",&i)==1);
			else i=1;
			if(equ_left) xishu+=i;
			else xishu-=i;
			memset(buf,0,sizeof(buf));
			top=0;
		}
	}
#ifdef DEBUG
	printf("changshu:%d,xishu:%d\n",changshu,xishu);
#endif
	if(changshu==0)printf("%c=0.000\n",x);
	else printf("%c=%.3f\n",x,-(float)changshu/(float)xishu);
	return 0;
}
