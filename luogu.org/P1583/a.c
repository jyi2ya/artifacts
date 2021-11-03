#include <stdio.h>
#include <stdlib.h>

#define BASE 100000

int n,k,E[11],W[20005];

void read(){
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=10;i++) scanf("%d",E+i);
	for(i=1;i<=n;i++){
		scanf("%d",W+i);
		W[i]=W[i]*BASE+i;
		/*W[i]%BASE=i*/
	}
}

int cmp(const void* a,const void* b){
	 int p=*(int*)a/BASE,q=*(int*)b/BASE;
	 if(p==q)return *(int*)a%BASE-*(int*)b%BASE;
	 else return q-p;
}

int main(){
	read();

	qsort(W+1,n,sizeof(int),cmp);

	for(int i=1;i<=n;i++) W[i]+=E[(i-1)%10+1]*BASE;
	qsort(W+1,n,sizeof(int),cmp);

	for(int i=1;i<=k;i++) printf("%d ",W[i]%BASE);
	putchar('\n');
	return 0;
}
