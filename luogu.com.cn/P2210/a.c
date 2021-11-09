#include <stdio.h>
#include <stdlib.h>

void read(void);

int frd[19][3],N,list[19],pos[19];

int getcost(void);
void getpos(void);
void rdsf(void);

int main(void)
{
	int ans=0x7f7f7f7f,cost,i,cnt;
	read();
	srand(0x66ccff);
	for(cnt=0;cnt<1100;++cnt){
		rdsf();
		getpos();
		cost=getcost();
		int ok=0;
		while(!ok){
			int lastcost=cost;
			ok=1;
			for(i=1;i<N;++i){
				int t=list[i];list[i]=list[i+1];list[i+1]=t;
				int newcost;
				getpos();
				newcost=getcost();
				if(newcost>lastcost){
					t=list[i];list[i]=list[i+1];list[i+1]=t;
					getpos();
				} else if(newcost==lastcost){
					;
				} else {
					cost=newcost;
					ok=0;
				}
			}
		}
		if(cost<ans) ans=cost;
	}
	printf("%d\n",ans);
	return 0;
}

void getpos(void)
{
	int i;
	for(i=1;i<=N;++i) pos[list[i]]=i;
}

int getcost(void)
{
	int i,ans=0;
	for(i=1;i<=N;++i)
		ans+=
			abs(pos[i]-pos[frd[i][0]])+
			abs(pos[i]-pos[frd[i][1]])+
			abs(pos[i]-pos[frd[i][2]]);
	return ans/2;
}

void rdsf(void)
{
	int i,max=N/2;
	for(i=0;i<max;++i){
		int a=rand()%N+1,b=rand()%N+1;
		int t=list[a];list[a]=list[b];list[b]=t;
	}
}

void read(void)
{
	int i;
	scanf("%d",&N);
	for(i=1;i<=N;++i) scanf("%d%d%d",frd[i],frd[i]+1,frd[i]+2);
	for(i=1;i<=N;++i) list[i]=i;
}
