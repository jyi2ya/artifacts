#include <stdio.h>

int cost[13];
int main(void)
{
	int deposit=0,noenough=0,save=0;
	{
		//printf("getting cost...\n");
		int i;
		for(i=1; i<=12; i++) {
			int a;
			scanf("%d",&a);
			cost[i]=a;
		}
	}
	{
		//printf("doing...\n");
		int i;
		for(i=1; i<=12; i++) {
			save+=300;
			if(save-cost[i] < 0) {
				noenough=-i;
				break;
			} else {
				deposit+=(save-cost[i])/100;
			}
			save-=((save-cost[i])/100)*100;
			save-=cost[i];
			//printf("------month=%d,save=%d,cost=%d,deposit=%d\n",i,save,cost[i],deposit);
		}
	}
	//printf("enough=%d\n",noenough);
	if(noenough)printf("%d",noenough);
	else printf("%d",deposit*120+save);

	return 0;
}
