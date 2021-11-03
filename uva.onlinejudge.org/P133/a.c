#include <stdio.h>

#ifdef DEBUG
void out(unsigned int a){
	int i=32;
	while(--i) printf("%d",(a>>i)&0x00000001);
	printf("%d\n",a&0x00000001);
}
#endif

int main(void){
	unsigned int n,k,m;
	while(scanf("%u%u%u",&n,&k,&m)==3 && !(n==0 && m==0 && k==0)){
		unsigned int que=0x7fffffff,A=1,B=n;
		while(que>>(31-n)){
#ifdef DEBUG
			out(que);
#endif
			unsigned int cnt=0;
			while('v'){
				if(que>>(31-A) & 0x00000001) 
					if(++cnt == k) 
						break;
				++A;
				if(A>n) A=1;
			}
			cnt=0;
			while('v'){
				if(que>>(31-B) & 0x00000001)
					if(++cnt == m)
						break;
				--B;
				if(B==0) B=n;
			}
			que &= ~(0x00000001 <<(31-A));
			que &= ~(0x00000001 <<(31-B));
			if(A!=B) printf("%3d",A);
			printf("%3d,",B);
		}
		putchar('\n');
	}
	return 0;
}

