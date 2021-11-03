#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[107][107];
int N;

int cmp(const void* a,const void* b);

int main(void)
{
	while(scanf("%d",&N)==1){
		int i,j,maxlen=0,len,num_per_line,lines;
		for(i=0;i<N;++i){
		       	scanf("%s",a[i]);
			len=strlen(a[i]);
			if(len+2>maxlen) maxlen=len+2;
		}

		num_per_line=(60-maxlen+2)/maxlen+1;
		lines=(N-1)/num_per_line+1;
		qsort(a,N,sizeof(a[0]),cmp);
		puts("------------------------------------------------------------");
		for(i=0;i<lines;++i){
			for(j=0;j<num_per_line;++j) {
				int idx=j*lines+i;
				if(idx<N) printf("%-*s",maxlen,a[idx]);
			}
			putchar('\n');
		}
	}
	return 0;
}

int cmp(const void* p,const void* q)
{
	return strcmp((char*)p,(char*)q);
}
