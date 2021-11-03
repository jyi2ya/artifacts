#include<cstdio>
#include<algorithm>
#define MAX 1005

typedef struct{
	int num,time;
}member;
member a[MAX];

int cmp(member a,member b){
	return a.time<b.time;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].time);
		a[i].num=i;
	}
	std::sort(a,a+n,cmp);

	double tot=0;
	for(int i=0;i<n;i++){
		printf("%d ",a[i].num+1);
		tot+=(n-i-1)*(a[i].time);
#ifdef DEBUG
		printf("a[i].time=%d,num=%d,tot=%d\n",a[i].time,n-i,tot);
#endif
	}
	printf("\n%.2f\n",tot/n);
	return 0;
}
