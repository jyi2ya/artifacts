#include <stdio.h>

int buf[100][100];

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int k;
			scanf("%d",&k);
			buf[j][i]=k;
		}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) printf("%d ",buf[i][j]);
		putchar('\n');
	}
	return 0;
}
