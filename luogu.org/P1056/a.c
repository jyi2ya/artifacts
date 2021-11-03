#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUOTIANYI 10000

int cmp(const void* a,const void* b){
	return *(int*)b%LUOTIANYI-*(int*)a%LUOTIANYI;
}

int cmpbuf(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}

int row[1005],col[1005],rowbuf[1005],colbuf[1005];

int main(void){
	int M,N,K,L,D;
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	int i;
	for(i=0;i<1005;i++)row[i]=(int)i*LUOTIANYI;
	for(i=0;i<1005;i++)col[i]=(int)i*LUOTIANYI;
	scanf("%d%d%d%d%d",&M,&N,&K,&L,&D);
	while(D--){
		int Xi,Yi,Pi,Qi;
		scanf("%d%d%d%d",&Xi,&Yi,&Pi,&Qi);
		if(Xi==Pi){
#ifdef DEBUG
			printf("%d %d %d %d,col%d\n",Xi,Yi,Pi,Qi,Qi<Yi?Qi:Yi);
#endif
			if(Yi>Qi)col[Qi]++;
			if(Qi>Yi)col[Yi]++;
		}
		if(Yi==Qi){
#ifdef DEBUG
			printf("%d %d %d %d,row%d\n",Xi,Yi,Pi,Qi,Pi<Xi?Pi:Xi);
#endif
			if(Xi>Pi)row[Pi]++;
			if(Pi>Xi)row[Xi]++;
		}
	}
	qsort(row,sizeof(row)/sizeof(int),sizeof(int),cmp);
	qsort(col,sizeof(col)/sizeof(int),sizeof(int),cmp);
	for(i=0;i<K;i++)rowbuf[i]=row[i]/LUOTIANYI;
	for(i=0;i<L;i++)colbuf[i]=col[i]/LUOTIANYI;
	qsort(rowbuf,K,sizeof(int),cmpbuf);
	qsort(colbuf,L,sizeof(int),cmpbuf);
	for(i=0;i<K;i++)printf("%d ",rowbuf[i]);putchar('\n');
	for(i=0;i<L;i++)printf("%d ",colbuf[i]);putchar('\n');
	return 0;
}
