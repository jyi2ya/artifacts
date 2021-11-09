#include <stdio.h>
#include <stdlib.h>

int head[20004],money[20004];

int cmp(const void *a, const void *b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	return 1;
}

int main(void){
	int n,m,tot=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",head+i);
	for(int i=0;i<m;i++) scanf("%d",money+i);
	qsort(head,n,sizeof(head[0]),cmp);
	qsort(money,m,sizeof(money[0]),cmp);
	int i=0,j=0;
	while(i<n && j<m){
		if(head[i]<=money[j]) {
			tot+=money[j];
			i++;j++;
		}else j++;
	}
	if(i==n) printf("%d\n",tot);
	else printf("you died!\n");
	return 0;
}
