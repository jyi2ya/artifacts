#include <stdio.h>
#include <string.h>

char s1[1023],s2[1023];

int main(void){
	int round;
	while(scanf("%d",&round)==1 && round!=-1){
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));

		scanf("%s%s",s1,s2);

		int hp=7;
		int win=1;
		for(int i=0;s2[i]!='\0';++i){
			int find=0;
			for(int j=0;s1[j]!='\0';++j) 
				if(s1[j]==s2[i]){
					find=1;
					s1[j]='@';
				}
			if(!find) --hp;
		}
		for(int i=0;s1[i]!='\0';++i) 
			if(s1[i]!='@') 
				win=0;

		printf("Round %d\n",round);
		if(hp<1) puts("You lose.");
		else if(!win) puts("You chickened out.");
		else puts("You win.");
	}
	return 0;
}
