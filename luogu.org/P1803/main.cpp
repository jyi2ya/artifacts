#include<cstdio>
#include<algorithm>

typedef struct{
	int begin,end;
}race;

race a[1000005];
int n;

#ifdef DEBUG
void out(){
	printf("out:\n");
	for(int i=0;i<n;i++) printf("%d %d\n",a[i].begin,a[i].end);
}
#endif


void read(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",&a[i].begin,&a[i].end);
#ifdef DEBUG
	out();
#endif
}

int cmp(race a,race b){
	return a.end<b.end;
}

int main(){
	int ans=0,lastend=0;
	read();
	std::sort(a,a+n,cmp);
#ifdef DEBUG
	out();
#endif
	for(int i=0;i<n;i++)
		if(a[i].begin>=lastend){
		       	ans++;
			lastend=a[i].end;
		}
	printf("%d\n",ans);
	return 0;
}
