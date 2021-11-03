#include <stdio.h>
#include <string.h>

#define MAX 1111
int match[10]={6,2,5,5,4,5,6,3,7,6};
int got[1200];

int sum(int x){
	int a=0;
	if(x==0)a+=match[0];
	while(x){
		a+=match[x%10];
		x/=10;
	}
	return a;
}

int solve(int a){
	int i,j,k,num=0;
	for(i=0;i<1200;i++){
		int jmax=1200-i;
		for(j=0;j<jmax;j++){
			k=i+j;
			if(sum(i)+sum(j)+sum(k)==a){
#ifdef DEBUG
				printf("%d+%d=%d,sums:%d+%d+%d=%d\n",i,j,k,sum(i),sum(j),sum(k),a);
#endif
				if(i==j){
					if(!got[i])num++;
				}
				else num++;
			}
		}
	}
	return num;
}

int main(void){
	int i;
	memset(got,0,sizeof(got));
	scanf("%d",&i);
	printf("%d\n",solve(i-4));
	return 0;
}
