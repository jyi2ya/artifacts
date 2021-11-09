#include <stdio.h>

int main(void){
	int x,y,tot=0,ch;
	scanf("%d%d",&x,&y);
	while((ch=getchar())!=EOF)
		if(ch=='*') tot++;
	if(tot==0) printf("xiaowangcai!\n");
	else if(tot<=6000) printf("%d\n",tot);
	else printf("6000\n");
	return 0;
}
