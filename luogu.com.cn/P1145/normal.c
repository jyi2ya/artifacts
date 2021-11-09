#include <stdio.h>

int k;
unsigned long long used;

#define test(pos) ((used>>(pos))&1)
#define setzero(pos) (used&=(~(1<<(pos))))
#define init() (used=0xffffffffffffffff)

int ok(int m);

int main(void){
	int i=0;
	scanf("%d",&k);
	while(++i) if(ok(i)) break;
	printf("%d\n",i);
	return 0;
}

int ok(int m){
	int pos=0,killed=0;
	init();
	pos=0;
	while('v'){
		int cnt=0;
		while('v'){
			if(test(pos)) ++cnt;
			if(cnt==m) break;
			++pos;
			if(pos==(k<<1)) pos=0;
		}
		setzero(pos);
		if(pos<k) break;
		++killed;
	}
	if(killed==k) return 1;
	else return 0;
}
