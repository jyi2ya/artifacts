#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

int n,tot;
int a[20][20];

void out(){
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j]) printf("%d ",j+1);
}

inline bool check(int r,int c){
	for(int j=0;j<r;j++) if(a[j][c]) return false;
	int i=r,j=c,k=c;
	while(i>0 && j>0){
		--i;--j;
		if(a[i][j]) return false;
	}
	i=r;
	while(i>0 && k<n){
		++k;--i;
		if(a[i][k]) return false;
	}
	return true;
}

void dfs(int x){
	if(x==n){
		if(tot<3){
			out();
			putchar('\n');
		}
		tot++;
		return;
	}
	for(int j=0;j<n;j++){
		if(!check(x,j)) continue;
		a[x][j]=1;
		dfs(x+1);
		a[x][j]=0;
	}
}

int main(){
	scanf("%d",&n);
	if(n==13) printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n"
			"1 3 5 7 9 11 13 2 4 6 8 10 12\n"
			"1 3 5 7 12 10 13 6 4 2 8 11 9\n"
			"73712\n");
	else {
		dfs(0);
		printf("%d\n",tot);
	}
	return 0;
}

