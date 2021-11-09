#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

#define MAX 1000007

bool isprim[MAX];
int prime[MAX],number[MAX],n,m;

void init(void);
void read(void);

int main(void){
	init();
	read();
	while(n--){
		int l,r,ans;
		scanf("%d%d",&l,&r);
		if(l<1 || r>m) {
			puts("Crossing the line");
			continue;
		}
		ans=number[r]-number[l];
		if(isprim[l]) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}

void init(void){
	int i,primtop=0;
	for(i=0;i<MAX;++i) isprim[i]=true;
	isprim[0]=false;
	isprim[1]=false;
	for(i=2;i<MAX;++i){
		int j;
		if(isprim[i]) prime[primtop++]=i;
		for(j=0;j<primtop && i*prime[j]<MAX;++j){
			isprim[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
	for(i=1;i<MAX;++i) {
		if(isprim[i]) number[i]=number[i-1]+1;
		else number[i]=number[i-1];
	}
}

void read(void){
	scanf("%d%d",&n,&m);
}
