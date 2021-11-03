#include <stdio.h>
#include <ctype.h>

int know[1005][1005];
int N,M,Q;

#define getint() ({\
		int ch,ans;\
		while(!isdigit(ch=getchar()));\
		ans=ch-'0';\
		while(isdigit((ch=getchar()))) ans=ans*10+ch-'0';\
		ans;\
		})

int main(void){
	N=getint();M=getint();Q=getint();
	for(int i=0;i<M;i++){
		int x=getint(),y=getint();
		know[x][y]=1;
		know[y][x]=1;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) 
			if(know[i][j]) 
				for(int k=1;k<=N;k++)
					if(know[j][k]) {
						know[i][k]=1;
						know[k][i]=1;
					}
	}
	for(int i=0;i<Q;i++){
		int x=getint(),y=getint();
		if(know[x][y]) puts("Y");
		else puts("N");
	}
	return 0;
}
