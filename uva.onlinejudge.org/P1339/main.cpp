#include <cstdio>
#include <cstring>
#include <algorithm>

char s1[1023],s2[1023];
int num1[27],num2[27];

void count(void){
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	for(int i=0;s1[i]!='\0';++i) ++num1[s1[i]-'A'];
	for(int i=0;s2[i]!='\0';++i) ++num2[s2[i]-'A'];
	std::sort(num1,num1+26);
	std::sort(num2,num2+26);
}

int main(void){
	while(scanf("%s%s",s1,s2)==2){
		count();
		bool ok=true;
		for(int i=0;i<26;i++) 
			if(num1[i]!=num2[i])
				ok=false;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
