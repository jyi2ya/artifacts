#include <stdio.h>
#include <ctype.h>

#define LL long long

LL buf[10000],*stack=buf+100;
int top=0;

int main(void){
	int ch;
	while((ch=getchar())!='@'){
#ifdef DEBUG
		printf("DEBUG:stack:");
		for(int i=0;i<top;i++) printf("%lld ",stack[i]);
		putchar('\n');
#endif
		if(isdigit(ch)) {
			LL a;
			ungetc(ch,stdin);
			scanf("%lld",&a);
			stack[top++]=a;
		}else{
			LL a=stack[--top],b=stack[--top];
			switch(ch){
				case '+':{stack[top++]=b+a;break;}
				case '-':{stack[top++]=b-a;break;}
				case '*':{stack[top++]=b*a;break;}
				case '/':{stack[top++]=b/a;break;}
				default:{stack[top++]=b;stack[top++]=a;}
			}
		}
	}
	printf("%lld\n",stack[top-1]);
	return 0;
}
