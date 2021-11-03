#include <stdio.h>

int p[50000],q[50000],top=0;

int main(){
	int i,ch,w=0,l=0,w21=0,l21=0;
	while((ch=getchar())!='E'){
		if(ch=='W'){
			w21++;w++;
			if(w>=11 && w-l>=2){
				printf("%d:%d\n",w,l);
				w=0;l=0;
			}
			if(w21>=21 && w21-l21>=2){
				p[top]=w21;q[top]=l21;top++;
				w21=0;l21=0;
			}
		}else if(ch=='L'){
			l21++;l++;
			if(l>=11 && l-w>=2){
				printf("%d:%d\n",w,l);
				w=0;l=0;
			}
			if(l21>=21 && l21-w21>=2){
				p[top]=w21;q[top]=l21;top++;
				w21=0;l21=0;
			}
		}
	}
	printf("%d:%d\n",w,l);

	putchar('\n');

	for(i=0;i<top;i++) printf("%d:%d\n",p[i],q[i]);
	printf("%d:%d\n",w21,l21);
	return 0;
}
