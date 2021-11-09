#include <stdio.h>

#define EPS 1e-6

double coe[20],l,r;
int N;

double fastpow(double a,int time);
double f(double x);

int main(void){
	int i;
	scanf("%d%lf%lf",&N,&l,&r);
	for(i=0;i<N;++i) scanf("%lf",coe+i);
	while(r-l>EPS){
		double mid=(l+r)/2,left=f(mid-EPS),right=f(mid+EPS);
		if(left>right) r=mid;
		else l=mid;
	}
	printf("%.5f\n",l);
	return 0;
}

double f(double x){
	int i;
	double ans=0;
	for(i=N;i>=0;--i)
		ans+=fastpow(x,i)*coe[N-i];
	return ans;
}

double fastpow(double a,int time){
	double ans=1;
	while(time){
		if(time&1) ans*=a;
		a*=a;
		time>>=1;
	}
	return ans;
}
