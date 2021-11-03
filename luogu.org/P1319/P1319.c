#include <stdio.h>

int main(void)
{
	int n,a,last=0,cnt=0;
	scanf("%d",&n);
	while(scanf("%d",&a)==1){
		int i;
		for(i=0;i<a;++i){
			if(last) putchar('1');
			else putchar('0');
			++cnt;
			if(cnt==n){
				putchar('\n');
				cnt=0;
			}
		}
		last=!last;
	}
	return 0;
}
