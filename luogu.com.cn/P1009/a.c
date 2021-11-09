#include<stdio.h>
#include<string.h>

typedef struct{
	int a[1000],len;
}bigint;

bigint answer,buf;

int intlen(bigint* a){
	int i=999;
	while(a->a[i]==0 && i>0)i--;
	if(i<=0)return 1;
	return i+1;
}

void copy(bigint* dest,bigint* src){
	for(int i=0;i<src->len;i++) dest[i]=src[i];
}

void out(bigint* a){
	for(int i=a->len-1;i>=0;i--) printf("%d",a->a[i]);
}

void add(bigint* dest,bigint* src){
#ifdef DEBUG
	printf("dest:");out(dest);printf(" src:");out(src);putchar('\n');
#endif
	int len=dest->len>src->len?dest->len:src->len;
	for(int i=0;i<len;i++){
		dest->a[i]+=src->a[i];
		dest->a[i+1]+=dest->a[i]/10;
		dest->a[i]%=10;
	}
	dest->len=intlen(dest);
#ifdef DEBUG
	printf("add,");out(dest);putchar('\n');
#endif
}

void mul(bigint* dest,int x){
	if(x==0){
		memset(dest->a,0,sizeof(dest->a));
		return;
	}
	for(int i=0;i<dest->len;i++) dest->a[i]*=x;
	for(int i=0;i<1000;i++){
		dest->a[i+1]+=dest->a[i]/10;
		dest->a[i]%=10;
	}
	dest->len=intlen(dest);
}

/*int cmp(bigint* a,bigint* b){
	if(a->len!=b->len){
		if(a->len>b->len)return 1;
		if(a->len<b->len)return -1;
	}else{
		int i;
		for(i=0;i<a->len;i++){
			if(a->a[i]>b->a[i])return 1;
			if(a->a[i]<b->a[i])return -1;
		}
		if(i==a->len)return 0;
	}
	return 0;
}*/


void fac(bigint* a,int x){
	memset(a->a,0,sizeof(a->a));
	a->a[0]=1;a->len=1;
	for(int i=1;i<=x;i++) mul(a,i);
#ifdef DEBUG
	printf("fac:");out(a);putchar('\n');
#endif
}

int main(){
	int n;
	scanf("%d",&n);
	answer.a[0]=0;answer.len=1;
	for(int i=1;i<=n;i++){
		fac(&buf,i);
		add(&answer,&buf);
	}
	out(&answer);
	putchar('\n');
	return 0;
}

