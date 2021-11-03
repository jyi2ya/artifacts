#include <stdio.h>

/* global */
char s[57];
int u[11][11],k,num[11],ans[1007],top=1;
/* end */

/* function */
void mul(int x);
void floyd(int n);
/* end */

int main(void)
{
	int i;
	scanf("%s%d",s,&k);
	for(i=0;i<k;++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		u[a][b]=1;
	}
	floyd(10);
	for(i=0;i<10;++i){
		int j;
		for(j=0;j<10;++j)
			if(u[i][j]) ++num[i];
	}
	ans[0]=1;
	for(i=0;s[i]!='\0';++i) mul(num[s[i]-'0']);
	for(i=top-1;i>=0;--i) printf("%d",ans[i]);
	putchar('\n');
	return 0;
}

void floyd(int n)
{
	int i,j,k;
	for(i=0;i<10;++i) u[i][i]=1;
	for(k=0;k<n;++k)
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				u[i][j]=(u[i][j]||(u[i][k] && u[k][j]));
	/* 
	for(i=0;i<10;++i){
		for(j=0;j<10;++j) putchar(u[i][j]+'0');
		putchar('\n');
	}
	*/
}

void mul(int x)
{
	int i,j;
	for(i=0;i<top;++i) ans[i]*=x;
	for(i=0;i<top;++i)
		if(ans[i]>9){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	while(ans[top]) ++top;
}
