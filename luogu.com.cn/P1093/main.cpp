#include<cstdio>
#include<cstdlib>
using namespace std;

typedef struct {
	int Chinese,Math,English,Number;
}student;

student a[305];
int n;

int cmp(const void* a,const void* b){
	student *p=(student*)a,*q=(student*)b;
	int tota=p->Chinese+p->Math+p->English,totb=q->Chinese+q->Math+q->English;
	if(tota!=totb)return totb-tota;
	if(p->Chinese!=q->Chinese)return q->Chinese-p->Chinese;
	return p->Number-q->Number;
}

int main(){
	scanf("%d",&n);

	int i;
	for(i=1;i<=n;i++){
		a[i].Number=i;
		scanf("%d%d%d",&(a[i].Chinese),&(a[i].Math),&(a[i].English));
	}

	qsort(a+1,n,sizeof(student),cmp);

	for(i=1;i<=5;i++) printf("%d %d\n",a[i].Number,a[i].Chinese+a[i].Math+a[i].English);
	return 0;
}
