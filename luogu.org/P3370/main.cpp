#include <cstdio>
#include <algorithm>
#include <cstring>

#define MOD 212370440130137957ll

char buf[5000];
unsigned long long has[10023];

unsigned long long hash(char* str);

int main(void){
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;++i) {
		scanf("%s",buf);
		has[i]=hash(buf);
	}
	std::sort(has,has+n);
	for(i=1;i<n;++i) 
		if(has[i-1]!=has[i])
			++ ans;
	printf("%d\n",ans+1);
	return 0;
}

unsigned long long hash(char* str){
	const int base=131;
	unsigned int lenth=strlen(str),i;
	unsigned long long ans=0;
	for(i=0;i<lenth;++i) ans=(ans*base+str[i])%MOD+19260817;
	return ans;
}
