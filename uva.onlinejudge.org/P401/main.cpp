#include<bits/stdc++.h>

char a[1000],len;
char from[]="AEHIJLMOSTUVWXYZ12358";
char to[]  ="A3HILJMO2TUVWXY51SEZ8";

bool ispal(void){
	int i=0,j=len-1;
	while(i<j){
		if(a[i]!=a[j])return false;
		i++;j--;
	}return true;
}

bool ismir(void){
	int i=0,j=len-1;
	while(i<j){
		char* p=strchr(from,a[i]);
		if(p==NULL)return false;
		int dis=(p-from)/sizeof(char);

		if(a[j]!=to[dis])return false;
		i++;j--;
	}
	if(i==j) if(strchr(from,a[i])==NULL)return false;
	return true;
}

int main(){
	while(~scanf("%s",a)){
		len=strlen(a);
		int ISPAL=ispal(),ISMIR=ismir();
		printf("%s -- ",a);
		if(ISPAL && ISMIR)printf("is a mirrored palindrome");
		if(ISPAL && !ISMIR)printf("is a regular palindrome");
		if(!ISPAL && ISMIR)printf("is a mirrored string");
		if(!ISPAL && !ISMIR)printf("is not a palindrome");
		printf(".\n\n");
	}
	return 0;
}
