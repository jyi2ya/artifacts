#include <stdio.h>

int main(void){
	int n;
	while(scanf("%d",&n)==1){
		int i,a,b,c,d,first=1,prefix=32;/* ip: a.b.c.d */
		unsigned int ip,ans=0xffffffff,mostoffset;
		for(i=0;i<n;++i) {
			int j;
			scanf("%d",&a);
			getchar();
			scanf("%d",&b);
			getchar();
			scanf("%d",&c);
			getchar();
			scanf("%d",&d);
			ip=(a<<24)+(b<<16)+(c<<8)+d;
			if(first){
				mostoffset=ip;
				first=0;
				continue;
			}
			for(j=31;j>=0;--j)
				if( (((ip>>j)&1)!=((mostoffset>>j)&1) ) && ((ans>>j)&1))
					break;
			if(j < prefix){
				prefix=j;
				mostoffset=ip;
			}
			for(;j>=0;--j) ans&=~(1<<j);
		}
		mostoffset&=ans;
		printf("%d.%d.%d.%d\n%d.%d.%d.%d\n",(mostoffset>>24)&0xff,(mostoffset>>16)&0xff,(mostoffset>>8)&0xff,(mostoffset)&0xff,(ans>>24)&0xff,(ans>>16)&0xff,(ans>>8)&0xff,(ans)&0xff);
	}
	return 0;
}
