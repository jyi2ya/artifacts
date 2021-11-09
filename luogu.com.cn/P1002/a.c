#include <stdio.h>
#include <string.h>

long long a[25][25];
int hx,hy,m,n;

int ok(int j,int i){
	if((j==hx+1) && (i==hy+2||i==hy-2))return 0;
	if((j==hx+2) && (i==hy+1||i==hy-1))return 0;
	if((j==hx-1) && (i==hy+2||i==hy-2))return 0;
	if((j==hx-2) && (i==hy+1||i==hy-1))return 0;
	if(j==hx && i==hy)return 0;
	return 1;
}

#ifdef DEBUG
void outa(void){
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++) printf("%lld ",a[i][j]);
		putchar('\n');
	}
}
#endif

int main(){
	int i,j;
	scanf("%d%d%d%d",&m,&n,&hx,&hy);

	for(i=0;i<=m;i++) {
		if(ok(i,n)) a[i][n]=1;
		else a[i][n]=0;
	}
	for(i=0;i<=n;i++){
		if(ok(m,i)) a[m][i]=1;
		else a[m][i]=0;
	}
	for(j=n-1;j>=0;j--){
		for(i=m-1;i>=0;i--) {
			if(ok(i,j)) a[i][j]=a[i+1][j]+a[i][j+1];
			else {
#ifdef DEBUG
				printf("A control Point (%d,%d)\n",i,j);
#endif
				a[i][j]=0;
			}
		}
	}
#ifdef DEBUG
	printf("Map:\n");
	outa();
#endif
	printf("%lld\n",a[0][0]);
	return 0;
}
