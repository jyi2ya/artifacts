#include<cstdio>

unsigned int a;

void read(){
	scanf("%u",&a);
}

void solve(int x){
	unsigned int i=1;
	int bits=1;
	while((i<<bits)<(1<<31)){
		while(!(x&i<<bits)) bits++;
		printf("2(");
		solve(bits);
		printf(")");



int main(){
	read();
	solve(a);
	return 0;
}
