#include<bits/stdc++.h>

char a[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){
	int ch;
	while((ch=getchar())!=EOF){
		if(ch==' '||ch=='\n') putchar(ch);
		else{
			int i;
			for(i=0;a[i]!='\0';i++)
				if(a[i]==ch)break;
			if(a[i]!='\0')putchar(a[i-1]);
		}
	}
	return 0;
}
