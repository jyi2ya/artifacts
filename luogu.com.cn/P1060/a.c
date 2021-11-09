#include <stdio.h>

int var[30],size[30];
int a[30][30005];

void read(int m){
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		var[i]=a*b;
		size[i]=a;
	}
}

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	read(m);
	for(int i=m-1;i>=0;i--)
		for(int j=0;j<n;j++){
			if(size[i]>j) a[i][j]=a[i+1][j];
			else a[i][j]=max(a[i+1][j-size[i]]+var[i],a[i+1][j]);
#ifdef DEBUG
			printf("a[%d][%d]=%d\n",i,j,a[i][j]);
#endif
		}
	printf("%d\n",a[0][n-1]);
	return 0;
}
