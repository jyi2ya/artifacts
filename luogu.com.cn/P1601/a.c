#include <stdio.h>

char a[1000],b[1000],ans[10000],buf[1000];
int buftop=0,sizea,sizeb;

void read(char* dest){
	buftop=0;
	int ch;
	while((ch=getchar())>'9' || ch<'0');
	buf[buftop++]=ch-'0';
	while((ch=getchar())<='9' && ch>='0'){
		buf[buftop++]=ch-'0';
	}
	int i,j;
#ifdef DEBUG
	printf("     REVERSING\n");
#endif
	for(i=0;i<buftop;i++){
		j=buftop-i-1;
		dest[i]=buf[j];
		dest[j]=buf[i];
	}
#ifdef DEBUG
	for(i=0;i<buftop;i++)printf("%d",dest[i]);
	putchar('\n');
#endif

}

int main(){
	read(a);sizea=buftop;
	read(b);sizeb=buftop;
	int i,max=sizea>sizeb?sizea:sizeb;
	for(i=0;i<max;i++){
		ans[i]+=a[i]+b[i];
		if(ans[i]>=10){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	}
	sscanf(ans,"%d",&i);
	i=max+3;while(ans[i]==0 && i>=0)i--;
	if(i<=0)printf("0\n");
	else {
		for(;i>=0;i--)printf("%d",ans[i]);
		putchar('\n');
	}
	return 0;
}
