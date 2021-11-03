#include <stdio.h>

int row[10000],order[10000],used[10000];
int N,M,K;

#ifdef DEBUG
void outroll(){
	printf("row:");
	for(int i=1;i<=N;i++) printf("%d ",row[i]);
	putchar('\n');
}
#endif

int find(int last,int x){
	for(int i=last;i<M;i++) if(order[i]==x) return i;
	return 0;
}

int main(){
#ifndef DEBUG
	freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
#endif

	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++) scanf("%d",order+i);
	for(int i=0;i<K;i++){
		int c,p;
		scanf("%d%d",&c,&p);
		row[p]=c;
		used[find(0,c)]=1;
	}
#ifdef DEBUG
	outroll();
#endif

	int RowNow=1,OrderLast=0,Last=-1;
	for(int i=0;i<K;i++){
		int now=RowNow;
		while(row[now]==0)now++;

		RowNow=now+1;

		int now2=find(OrderLast,row[now]);

		if(now2==0){
			Last=row[now];
			continue;
		}


		for(int j=now2-1;j>=OrderLast;){
			now--;
			if(row[now] && used[j])continue;
			else if(order[j]!=Last && !used[j]){
				used[j]=1;
				row[now]=order[j];
			}
			j--;
		}
		OrderLast=now2;
		Last=row[now];
#ifdef DEBUG
		outroll();
#endif
	}
	int now=N+1;
	for(int j=M-1;j>=OrderLast;){
		now--;
		if(row[now] && used[j])continue;
		else if(order[j]!=Last && !used[j])row[now]=order[j];
		j--;
	}
#ifdef DEBUG
	outroll();
#endif
	int i;
	for(i=1;i<=M;i++) if(row[i]==0 || row[i]==1)break;
	printf("%d\n",i);
	return 0;
}
