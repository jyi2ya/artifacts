#include <stdio.h>

int main(){
	int ch,top=0;
	while((ch=getchar())!='@'){
		if(ch=='(') top++;
		if(ch==')') top--;
		if(top<0) break;
	}
	if(top==0) puts("YES");
	else puts("NO");
	return 0;
}
