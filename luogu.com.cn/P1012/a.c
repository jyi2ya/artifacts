#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[20][1000];
char buf1[2000],buf2[2000];
int n;

int cmp(const void* a,const void* b){
	char *i=(char*)a,*j=(char*)b;

	strcpy(buf1,i);
	strcpy(buf2,j);

	strcat(buf1,j);
	strcat(buf2,i);

#ifdef DEBUG
	printf("a=%s,b=%s,lena=%d,lenb=%d,buf1=%s,buf2=%s\n",i,j,strlen(i),strlen(j),buf1,buf2);
#endif

	return strcmp(buf2,buf1);
}

int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",a[i]);

	qsort(a,n,sizeof(*a),cmp);

#ifdef DEBUG
	for(i=0;i<n;i++) printf("%s ",a[i]);
#endif

	for(i=0;i<n;i++) printf("%s",a[i]);
	putchar('\n');
	return 0;
}
