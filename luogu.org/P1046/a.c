#include <stdio.h>

int apples[10];

int main(void){
	int h,caught=0;
	{
		int i;
		for(i=0;i<10;i++) scanf("%d",apples+i);
	}
	scanf("%d",&h);
	h+=30;
	{
		int i;
		for(i=0;i<10;i++) if(apples[i]<=h) caught++;
	}
	printf("%d",caught);
	return 0;
}
