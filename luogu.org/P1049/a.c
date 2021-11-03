#include <stdio.h>

int a[20005][35];
int size[100000];

int min(int a,int b){
	return a<b?a:b;
}

void init(int v,int n){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=v;j++)
			a[j][i]=v;
#ifdef DEBUG
	printf("arrey:\n");
	for(int i=0;i<=n;i++){
		for(int j=0;j<=v;j++)
			printf("%d ",a[j][i]);
		putchar('\n');
	}
#endif

}

int main(){
	int v,n;
	scanf("%d%d",&v,&n);
	for(int i=0;i<n;i++) scanf("%d",size+i);
	init(v,n);

	for(int i=n-1;i>=0;i--)
		for(int j=0;j<=v;j++){
			if(j<size[i])a[j][i]=a[j][i+1];
			else a[j][i]=min(a[j-size[i]][i+1]-size[i],a[j][i+1]);
#ifdef DEBUG
			printf("a[%d][%d]=%d\n",j,i,a[j][i]);
#endif
		}
	printf("%d\n",a[v][0]);
	return 0;
}
