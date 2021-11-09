#include <stdio.h>
#include <string.h>
#include <math.h>

int isprim(long x){
	if(x<=1)return 0;
	if(x==2)return 1;
	long i;long max=(long)sqrt((double)x)+1;
	if(x%2==0)return 0;
	for(i=3;i<=max;i+=2)if(x%i==0)return 0;
	return 1;
}

int iscycle(long x){
	char buf[20];
	long i;
	sprintf(buf,"%ld",x);
	int len=strlen(buf);
	for(i=0;i<=len;i++)if(buf[i]!=buf[len-i])return 0;
	return 1;
}

int main(void){
	long i,a,b;
	scanf("%ld%ld",&a,&b);
	for(i=a;i<=b;i+=2)if(iscycle(i))if(isprim(i))printf("%ld\n",i);
	return 0;
}
