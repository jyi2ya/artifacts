#include <stdio.h>

#define MOD 100003

#define NO  -1
#define YES 0

int a[1005][1005],N,M;

void read(){
	scanf("%d%d",&N,&M);
	while(M--){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=NO;
	}
}

int main(){
	read();
	for(int i=N;i>0;i--)
		for(int j=N;j>0;j--)
			if(a[i][j]==NO) a[i][j]=0;
			else {
				if(i==N && j==N) a[i][j]=1;
				else if(i==N) a[i][j]=a[i][j+1]%MOD;
				else if(j==N) a[i][j]=a[i+1][j]%MOD;
				else a[i][j]=(a[i+1][j]+a[i][j+1])%MOD;
			}
#ifdef DEBUG
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) printf("%d ",a[i][j]);
		putchar('\n');
	}
#endif
	printf("%d\n",a[1][1]);
	return 0;
}
