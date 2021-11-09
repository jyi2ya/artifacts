#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>
#include <ctype.h>

int num[10000],buf[10000];
int len,MODE;

void out(int* a){
	for(int i=0;i<len;i++) printf("%d ",a[i]);
	putchar('\n');
}

void add(int* dest ,int* src){
	for(int i=0;i<len;i++){
		dest[i]+=src[i];
		dest[i+1]+=(dest[i]/MODE);
		dest[i]%=MODE;
	}
	if(dest[len]>0)len++;
}

int isrevers(int* num){
	int i=len-1,j=0;
	while(i>j){
		if(num[i]!=num[j])return false;
		i--;j++;
	}
	return true;
}

void revers(int* a,int* b){
	int i=len-1,j=0;
	while(i>=0){
		a[i]=b[j];
		i--;j++;
	}
}

void read(int* a){
	scanf("%d",&MODE);
	int ch,i;

	while(!isalnum(ch=getchar()));
	ungetc(ch,stdin);

	for(i=0;isalnum(ch=getchar());i++){
	       	if(isdigit(ch))buf[i]=ch-'0';
		else if(islower(ch))buf[i]=ch-'a'+10;
		else if(isupper(ch))buf[i]=ch-'A'+10;
	}
	len=i;
	revers(a,buf);
#ifdef DEBUG
	out(num);
#endif
}

int main(){
	read(num);
	int i;
	for(i=0;!isrevers(num) && i<=30;i++){
		revers(buf,num);
		add(num,buf);
	}
	if(i>30)printf("Impossible!\n");
	else printf("STEP=%d\n",i);
	return 0;
}
