#include <stdio.h>
#define MAX 100000

char s1[MAX],s2[MAX];

int main(){
	while(scanf("%s%s",s1,s2)==2){
		int p1=0,p2=0;
		while(s1[p1]!='\0' && s2[p2]!='\0'){
			if(s1[p1]==s2[p2]) p1++;
			p2++;
		}
		if(s1[p1]=='\0') printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
