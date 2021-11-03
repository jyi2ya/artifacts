#include <stdio.h>

int stack[0x66ccff],top=0;

int main(void)
{
	int T,ch;
	scanf("%d",&T);
	while(getchar()!='\n');

	while(T--){
		top=0;
		int ok=1;
		while((ch=getchar())!='\n' && ch!=EOF) {
			if(ch=='[' || ch=='(') stack[top++]=ch;
			else{
				if(ch==']') {
					if(top==0 || stack[--top]!='['){
						ok=0;
						while((ch=getchar())!='\n' && ch!=EOF);
						break;
					}else continue;
				}
				if(ch==')'){
					if(top==0 || stack[--top]!='('){
						ok=0;
						while((ch=getchar())!='\n' && ch!=EOF);
						break;
					}else continue;
				}
			}
		}
		if(ok && top==0) puts("Yes");
		else puts("No");
	}
	return 0;
}
