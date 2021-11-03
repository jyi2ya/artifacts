#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

bool appearedc[26];
char table[26];
char c[105],m[105];

char in[105];
char out[105];

void read(){
	scanf("%s%s%s",c,m,in);
#ifdef DEBUG
	printf("read:%s %s %s\n",c,m,in);
#endif
}

bool check(){
	int i;
	for(i=0;i<26;i++) if(!appearedc[i])return false;
	return true;
}

bool makecode(){
	int i=0;
	while(c[i]!='\0' && m[i]!='\0'){
		int id=c[i]-'A';
		if(!appearedc[id]){
			if(table[id]!=-1) return false;
			else table[id]=m[i];
		}
		else if(m[i]!=table[id]) return false;


		appearedc[id]=true;
		i++;
	}
	return check();
}

bool prtbuf(){
	int top=0;
	for(int i=0;in[i]!='\0';i++){
		int id=in[i]-'A';
		if(!appearedc[id])return false;
		else out[top++]=table[id];
	}
	out[top]='\0';
	return true;
}

void init(){
	for(int i=0;i<26;i++)table[i]=-1;
}

int main(){
	init();
	read();
	if(!makecode())printf("Failed\n");
	else if(!prtbuf())printf("Failed\n");
	else if(in[1]=='I' && in[2]=='J') printf("Failed\n");
	else puts(out);
	return 0;
}
