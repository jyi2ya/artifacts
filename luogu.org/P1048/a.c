#include <stdio.h>

int T,M;
int time[105],val[105];
int a[10000][105];

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	scanf("%d%d",&T,&M);
	for(int i=0;i<M;i++)scanf("%d%d",time+i,val+i);

	for(int i=M-1;i>=0;i--)
		for(int t=0;t<=T;t++){
			if(time[i]>t)a[t][i]=a[t][i+1];
			else a[t][i]=max(a[t-time[i]][i+1]+val[i],a[t][i+1]);
#ifdef DEBUG
			printf("a[%d][%d]=%d\n",t,i,a[t][i]);
#endif
		}
	printf("%d\n",a[T][0]);
	return 0;
}
