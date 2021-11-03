#include <stdio.h>
#include <ctype.h>

#define getll() ({\
		long long ans;int ch,over=1;\
		while(!isdigit(ch=getchar()) && ch!='-');\
		if(ch=='-') over=0;\
		else ans=ch-'0';\
		while(isdigit(ch=getchar())) ans=ans*10+ch-'0';\
		if(!over) ans=-ans;\
		ans;\
})
#define outll(a) ({\
		int cnt=20;\
		while(cnt!=0 && a/cnt == 0) cnt--;\
		while(--cnt>0){\
		putchar(a/cnt%10+'0');\
		}\
})\

int main(void){
	long long n=getll(),ans=0;
	while(n--) ans+=getll();
	printf("%lld\n",ans);
	return 0;
}
