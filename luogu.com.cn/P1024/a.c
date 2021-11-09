#include <stdio.h>

#define EPS 0.001

double a,b,c,d;

double f(double);
void bsearch(int);
int equ(double,double);

int main(void){
	int i;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(i=-101;i<101;++i) bsearch(i);
	putchar('\n');
	return 0;
}

double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}

int equ(double a,double b){
	double diff=a-b,eps=0.001;
	return -eps<=diff && diff<=eps;
}

void bsearch(int i){
	double l=i,r=i+1;
	if(!f(l)){
		printf("%.2f ",l);
	}else if(f(l)*f(r) < 0){
		while(r-l>EPS){
			double mid=(l+r)/2;
			if(f(mid)*f(l)<=0) r=mid;
			else l=mid;
		}
		printf("%.2f ",r);
	}
}
