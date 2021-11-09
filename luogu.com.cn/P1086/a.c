#include <stdio.h>
#include <stdlib.h>

int N,M,T;

typedef struct{
	int x,y,num;
}coord;

coord field[410];

int abs(int x){
	return x>0?x:-x;
}

int cmp(const void* a,const void* b){
	return ((coord*)b)->num-((coord*)a)->num;
}

void read(void){
	scanf("%d%d%d",&M,&N,&T);
	for(int j=0;j<M;j++)
		for(int i=0;i<N;i++){
			coord* now=field+N*j+i;
			now->x=i+1;now->y=j+1;
			scanf("%d",&(now->num));
		}
}

int dis(coord* a,coord* b){
	return abs(a->x-b->x)+abs(a->y-b->y);
}

int main(){
	read();

	qsort(field,M*N,sizeof(coord),cmp);

	int time=field[0].y+1,tot=field[0].num;
	if(time*2-1>T){
		printf("0\n");
		return 0;
	}

	int i=1;
	while(time+1+dis(field+i-1,field+i)+field[i].y<=T && i<M*N){
		time=time+dis(field+i-1,field+i)+1;
		tot+=field[i].num;
		i++;
#ifdef DEBUG
		printf("i=%d,time=%d,tot=%d\n",i,time,tot);
#endif
	}
	printf("%d\n",tot);
	return 0;
}
