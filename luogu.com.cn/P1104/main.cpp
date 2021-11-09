#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct{
	int y,m,d,i;
	char s[100];
}oier;

oier a[105];
int n;

bool cmp(oier a,oier b){
	if(a.y!=b.y)return a.y<b.y;
	if(a.m!=b.m)return a.m<b.m;
	if(a.d!=b.d)return a.d<b.d;
	return a.i>b.i;
}

void read(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%s%d%d%d",a[i].s,&(a[i].y),&(a[i].m),&(a[i].d));
		a[i].i=i;
	}
}

int main(){
	read();
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) printf("%s\n",a[i].s);
	return 0;
}
