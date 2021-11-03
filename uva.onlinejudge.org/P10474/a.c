#include <stdio.h>
#include <string.h>

/* constant */
#define MAX 10007
/* end */

/* function */
void sort(int l,int r);
int search(int a,int n);
void init(void);
/* end */

/* global */
int a[MAX];
/* end */

int main(void)
{
	int cases=0,n,q;
	while(scanf("%d%d",&n,&q)==2 && n && q){
		int i;
		memset(a,0,sizeof(a));

		printf("CASE# %d:\n",++cases);
		for(i=0;i<n;++i) scanf("%d",a+i);

		sort(0,n);
		for(i=0;i<q;++i){
			int x,ans;
			scanf("%d",&x);

			ans=search(x,n);

			if(ans) printf("%d found at %d\n",x,ans);
			else printf("%d not found\n",x);
		}
	}
	return 0;
}

void sort(int l,int r)
{
	int tmp=a[l],i=l,j=r-1;

	if(r-l<=1) return;

	while(i<=j){
		while(a[i]<tmp) ++i;
		while(a[j]>tmp) --j;
		if(i<=j) {
			int t=a[i];
			a[i]=a[j];
			a[j]=t;

			++i;--j;
		}
	}
	sort(l,i);
	sort(i,r);
}

int search(int x,int n)
{
	int l=0,r=n;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(a[mid]>=x) r=mid;
		else l=mid;
	}
	if(a[l]==x) return l+1;
	if(a[r]==x) return r+1;
	return 0;
}

