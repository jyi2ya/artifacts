#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_ALPHA 26

int alpha[NUM_OF_ALPHA];

bool isprim(int x){
	if(x==0)return false;
	if(x==1)return false;
	int i;
	for(i=2;i<x;i++) if(x%i==0)return false;
	return true;
}

int cmp(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}

int least(void){
	int i;
	for(i=0;i<26;i++) if(alpha[i]==0)return alpha[i-1];
	return alpha[25];
}

int main(){
	for(int i=0;i<NUM_OF_ALPHA;i++)alpha[i]=0;

	int ch;
	while((ch=getchar())<'a' || ch>'z'); alpha[ch-'a']++;
	while((ch=getchar())>='a' && ch<='z') alpha[ch-'a']++;

	qsort(alpha,NUM_OF_ALPHA,sizeof(int),cmp);

	int diff=alpha[0]-least();

	if(isprim(diff)) printf("Lucky Word\n%d\n",diff);
	else printf("No Answer\n0\n");

	return 0;
}
