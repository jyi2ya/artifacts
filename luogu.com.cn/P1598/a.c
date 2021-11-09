#include <stdio.h>
#include <string.h>

int a[128];

int max(int* a,int size){
	int s=a[0],i;
	for(i='A';i<='Z';i++)if(a[i]>s)s=a[i];
	return s;
}

int r(int now){
	int i,right=0;
	for(i='A';i<='Z';i++)if(a[i]>=now)right=i;
	return right;
}

int main(void){
	memset(a,0,sizeof(a));
	int ch,top;
	while((ch=getchar())!=EOF)a[ch]++;
	for(top=max(a,128);top>0;top--){
		int right=r(top),i;
		for(i='A';i<right;i++){
			putchar((a[i]>=top)?'*':' ');
			putchar(' ');
		}
		putchar((a[right]>=top)?'*':' ');
		putchar('\n');
	}
	int i;
#ifdef DEBUG
	for(i='A';i<='Z';i++)printf("%d ",a[i]);putchar('\n');
#endif
	for(i='A';i<'Z';i++)printf("%c ",i);
	printf("Z\n");
	return 0;
}
