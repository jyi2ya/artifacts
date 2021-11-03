#include <stdio.h>

int k;
unsigned long long used;

#define test(pos)    ((used>>(pos))&0x1)
#define setzero(pos) (used&=(~(1<<(pos))))
#define setone(pos)  (used|=(1<<(pos)))
#define init()       (used=0xffffffffffffffff)

int ok(int m);
int ulllog(unsigned long long x);

int main(void){
	int i=0;
	scanf("%d",&k);
	while(++i) if(ok(i)) break;
	printf("%d\n",i);
	return 0;
}

int ok(int m){
	int pos=0,cnt=0;
	init();
	pos=0;
	while('v'){
		int i,newpos;
		for(i=1;i<m;++i) {
			setzero(pos);
			newpos = ulllog((used>>pos)&(~(used>>pos)+1)) + pos;
			if(newpos>=(k<<1)) newpos=ulllog((used)&(~used+1));
			setone(pos);

			pos=newpos;
		}
		setzero(pos);
		if(pos<k) return 0;
		++cnt;
		if(cnt==k) return 1;

		pos+=ulllog((used>>pos)&(~(used>>pos)+1));
		if(pos>=(k<<1)) pos=ulllog((used)&(~used+1));
	}
	return 1;
}

int ulllog(unsigned long long m)
{
	if(m<=0x1) return 0;
	if(m<=0x2) return 1;
	if(m<=0x4) return 2;
	if(m<=0x8) return 3;
	if(m<=0x10) return 4;
	if(m<=0x20) return 5;
	if(m<=0x40) return 6;
	if(m<=0x80) return 7;
	if(m<=0x100) return 8;
	if(m<=0x200) return 9;
	if(m<=0x400) return 10;
	if(m<=0x800) return 11;
	if(m<=0x100) return 12;
	if(m<=0x2000) return 13;
	if(m<=0x4000) return 14;
	if(m<=0x8000) return 15;
	if(m<=0x10000) return 16;
	if(m<=0x20000) return 17;
	if(m<=0x40000) return 18;
	if(m<=0x80000) return 19;
	if(m<=0x100000) return 20;
	if(m<=0x200000) return 21;
	if(m<=0x400000) return 22;
	if(m<=0x800000) return 23;
	if(m<=0x1000000) return 24;
	if(m<=0x2000000) return 25;
	if(m<=0x4000000) return 26;
	if(m<=0x8000000) return 27;
	if(m<=0x10000000) return 28;
	if(m<=0x20000000) return 29;
	if(m<=0x40000000) return 30;
	if(m<=0x80000000) return 31;
	if(m<=0x100000000) return 32;
	if(m<=0x200000000) return 33;
	if(m<=0x400000000) return 34;
	if(m<=0x800000000) return 35;
	if(m<=0x1000000000) return 36;
	if(m<=0x2000000000) return 37;
	if(m<=0x4000000000) return 38;
	if(m<=0x8000000000) return 39;
	if(m<=0x10000000000) return 40;
	if(m<=0x20000000000) return 41;
	if(m<=0x40000000000) return 42;
	if(m<=0x80000000000) return 43;
	if(m<=0x100000000000) return 44;
	if(m<=0x200000000000) return 45;
	if(m<=0x400000000000) return 46;
	if(m<=0x800000000000) return 47;
	if(m<=0x1000000000000) return 48;
	if(m<=0x2000000000000) return 49;
	if(m<=0x4000000000000) return 50;
	if(m<=0x8000000000000) return 51;
	if(m<=0x10000000000000) return 52;
	if(m<=0x20000000000000) return 53;
	if(m<=0x40000000000000) return 54;
	if(m<=0x80000000000000) return 55;
	if(m<=0x100000000000000) return 56;
	if(m<=0x200000000000000) return 57;
	if(m<=0x400000000000000) return 58;
	if(m<=0x800000000000000) return 59;
	if(m<=0x1000000000000000) return 60;
	if(m<=0x2000000000000000) return 61;
	if(m<=0x4000000000000000) return 62;
	if(m<=0x8000000000000000) return 63;
	return 64;
}
