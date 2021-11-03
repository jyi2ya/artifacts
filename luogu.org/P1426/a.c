#include <stdio.h>

int main(void){
	double s,x,now=0.0,speed=7.0;
	scanf("%lf%lf,",&s,&x);
	double begin=s-x;
	while(now<=begin){
#ifdef DEBUG
		printf("%f %f\n",now,speed);
#endif
		now+=speed;
		speed*=0.98;
	}
	now+=speed;
#ifdef DEBUG
	printf("now=%f,s+x=%f\n",now,s+x);
#endif
	if(now<=s+x)printf("y\n");
	else printf("n\n");
	return 0;
}

