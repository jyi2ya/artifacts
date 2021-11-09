#include <stdio.h>

int n[105];

void DBGoutn(int i){
	int j;
	printf("     -----n[]:");
	for(j=0;j<i;j++)printf("%d ",n[j]);
	putchar('\n');
}

int main(void)
{
	int fish;
	scanf("%d",&fish);
	{
		int i;
		for(i=0;i<fish;i++) scanf("%d",n+i);
		//DBGoutn(fish);
	}
	{
		int i;
		for(i=0;i<fish;i++){
			int j,cute_TwT_=0;
			for(j=0;j<i;j++)
				if(n[j]<n[i])cute_TwT_++;
			printf("%d ",cute_TwT_);
		}
	}
	return 0;
}
