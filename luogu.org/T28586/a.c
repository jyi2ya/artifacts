#include <stdio.h>

int main(void){
    int a,b,c;
    scanf("%d",&a);
    c=300/a+1;    	
    if(a>=300) putchar('1');
    else {      
        if(a<=0) putchar('0');
        else{
                if(c>=18) puts("18");
    	        else printf("%d\n",c);
        }
    	return 0;
    }
}
