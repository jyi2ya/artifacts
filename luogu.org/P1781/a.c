#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char sco[105];
	int num;
}score;

score a[25];

void read(score* a){
	scanf("%s",a->sco);
}

int cmp(const void* a,const void* b){
	int lena=strlen(((score*)a)->sco),lenb=strlen(((score*)b)->sco);
	if(lena!=lenb){
		if(lena<lenb) return 1;
		if(lena>lenb) return -1;
	}
	return -strcmp(((score*)a)->sco,((score*)b)->sco);
}

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		(a+i)->num=i;
		read(a+i);
	}
	qsort(a+1,n,sizeof(score),cmp);
#ifdef DEBUG
	for(i=1;i<=n;i++)printf("%s %d\n",(a+i)->sco,(a+i)->num);
#endif
	printf("%d\n",(a+1)->num);
	puts((a+1)->sco);

	return 0;
}
