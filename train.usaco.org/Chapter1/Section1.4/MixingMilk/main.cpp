/*
ID:lindong6
PROG:milk
LANG:C++
*/

#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 5005

typedef struct {
	int milk,price;
}farmer;
farmer a[MAX];

int cmp(farmer a,farmer b){
	return a.price<b.price;
}

int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++) scanf("%d%d",&a[i].price,&a[i].milk);
	sort(a,a+M,cmp);

	int now=0,tot=0;
	for(int i=0;i<M;i++){
		if(now+a[i].milk<=N){
			now+=a[i].milk;
			tot+=a[i].milk*a[i].price;
		}else {
			tot+=(N-now)*a[i].price;
			break;
		}
	}
	printf("%d\n",tot);
	return 0;
}
